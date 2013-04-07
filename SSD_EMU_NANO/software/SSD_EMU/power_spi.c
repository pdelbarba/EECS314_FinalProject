#include "terasic_includes.h"
#include "power_spi.h"


#define SPI_SCK(x)    IOWR_ALTERA_AVALON_PIO_DATA(CSENSE_SCK_BASE,x)
#define SPI_FO(x)     IOWR_ALTERA_AVALON_PIO_DATA(CSENSE_ADC_FO_BASE,x)  
#define SPI_CS_N(s,x) IOWR_ALTERA_AVALON_PIO_DATA(CSENSE_CS_N_BASE,(x==1)?0x03:((s==0)?0x02:0x01))  
#define SPI_SDI(x)    IOWR_ALTERA_AVALON_PIO_DATA(CSENSE_SDI_BASE,x)
#define SPI_SDO       (IORD_ALTERA_AVALON_PIO_DATA(CSENSE_SDO_BASE) & 0x01)
#define SPI_DELAY     usleep(15)  // based on 50MHZ of CPU clock


// Note. SCK: typical 19.2KHZ (53 ms)
bool POWER_SPI_RW(alt_u8 IcIndex, alt_u8 NextChannel, bool bEN, bool bSIGN, bool bSGL, alt_u32 *pValue)
{
    bool bSuccess;
    alt_u8 Config8;
    alt_u32 Value32=0, Mask32;
    int i, nWait = 0, nZeroCnt;
    const int nMaxWait = 1000000;
    
    //
    Config8 = 0x80; 
    Config8 |= (bEN)?0x20:0x00;
    Config8 |= (bSGL)?0x10:0x00;
    Config8 |= (bSIGN)?0x08:0x00;
    Config8 |= NextChannel & 0x07; // channel
    
    SPI_FO(0); // use internal conversion clock
    SPI_SCK(0);  // set low to active extenal serial clock mode.
    SPI_CS_N(IcIndex, 0);  // chip select: active
    SPI_DELAY;
    
    // wait for converion end (when conversion done, SPI_SDO is low)
    while(SPI_SDO && nWait < nMaxWait){
        nWait++;
    }
    
    if (SPI_SDO){
        SPI_CS_N(IcIndex, 1);  // chip select: inactive
//        printf("Timeout \r\n");
        return FALSE;
    }
    
    for(i=0;i<2;i++) // send config bits 7:6,
    // ignore EOC/ and DMY bits
    {
        SPI_SDI((Config8 & 0x80)?1:0);//sdi=nextch.7; // put data on pin
        Config8 <<= 1; //nextch = rl(nextch); // get next config bit ready
        Value32 <<= 1;//result_0 = rl(result_0);// get ready to load lsb
        Value32 |= SPI_SDO;//result_0.0 = sdo; // load lsb
        
        SPI_SCK(1);//sck=1; // clock high
        SPI_DELAY;
        SPI_SCK(0);//sck=0; // clock low
        SPI_DELAY;
    }
    
    for(i=0;i<8;i++) // send config, read byte 3
    {
        SPI_SDI((Config8 & 0x80)?1:0);//sdi=nextch.7; // put data on pin
        Config8 <<= 1; //nextch = rl(nextch); // get next config bit ready
        
        Value32 <<= 1; //result_3 = rl(result_3);// get ready to load lsb
        Value32 |= SPI_SDO; //result_3.0 = sdo; // load lsb
        
        SPI_SCK(1);//sck=1; // clock high
        SPI_DELAY;
        SPI_SCK(0);//sck=0; // clock low
        SPI_DELAY;
    }
    
    for(i=0;i<8;i++) // read byte 2
    {
        Value32 <<= 1; //result_2 = rl(result_2);// get ready to load lsb
        Value32 |= SPI_SDO; //result_2.0 = sdo; // load lsb
        
        SPI_SCK(1);//sck=1; // clock high
        SPI_DELAY;
        SPI_SCK(0);//sck=0; // clock low
        SPI_DELAY;
    }
    
    for(i=0;i<8;i++) // read byte 1
    {
        Value32 <<= 1; //result_1 = rl(result_1);// get ready to load lsb
        Value32 |= SPI_SDO;//result_1.0 = sdo; // load lsb
        
        SPI_SCK(1);//sck=1; // clock high
        SPI_DELAY;
        SPI_SCK(0);//sck=0; // clock low
        SPI_DELAY;
    }
    
    for(i=0;i<6;i++) // read byte 0
    {
        Value32 <<= 1;//result_0 = rl(result_0);// get ready to load lsb
        Value32 |= SPI_SDO;//result_0.0 = sdo; // load lsb
        
        SPI_SCK(1);//sck=1; // clock high
        SPI_DELAY;
        SPI_SCK(0);//sck=0; // clock low
        SPI_DELAY;
    }
    SPI_SCK(1);
    SPI_DELAY;
    SPI_CS_N(IcIndex, 1);  // chip select: inactive
    
    // check parity
    nZeroCnt = 0;
    Mask32 = 0x01;
    for(i=0;i<32;i++){
        if ((Value32 & Mask32) == 0x00){
            nZeroCnt++;
        }
        Mask32 <<= 1;
    }
    bSuccess = (nZeroCnt&0x01)?FALSE:TRUE;
    if (!bSuccess){
//        printf("Parity Check Error \r\n");
        return FALSE;
    }        
    
    
    *pValue = Value32;
    
    return bSuccess;
}

bool POWER_Read(alt_u32 szVol[POWER_PORT_NUM]){
    bool bSuccess = TRUE;
    int i,c, nPortIndex=0;
    int szPortNum[] = {POWER_DEVICE0_PORT_NUM, POWER_DEVICE1_PORT_NUM};
    alt_u32 Value32;
    alt_u8 NextChannel,Channel, HEAD, SIGN, SGL, PARITY;
    const bool bEN=TRUE; // alwasy update next conversion channel
    const bool bSIGN=TRUE; // VolDrop = CH1-CH0
    const bool bSGL=FALSE; // GSGL=FALSE: Diff
    for(c=0;c<POWER_DEVICE_NUM && bSuccess;c = c + 1){
        NextChannel = 0;
        bSuccess = POWER_SPI_RW(c, NextChannel, bEN, bSIGN, bSGL, &szVol[0]); // set conversion channel: 0
        for(i=0;i<szPortNum[c] && bSuccess;i = i + 1){
            NextChannel = i + 1;
            bSuccess = POWER_SPI_RW(c, NextChannel, bEN, bSIGN, bSGL, &Value32);
            if (bSuccess){
                HEAD = (Value32 >> 30) & 0x03;
                Channel = (Value32 >> 1) & 0x07;
                SIGN = (Value32 >> 4 ) & 0x01;
                SGL = (Value32 >> 5 ) & 0x01;
                PARITY = Value32 & 0x01;
                if (HEAD != 0){
                    printf("[%d]Unexpected HEAD\r\n",i);
                    bSuccess = FALSE;
                }else if (Channel != i){
                    printf("[%d]Unexpected Channel. Expected:%d, Read:%d\r\n", i, i, Channel);
                    bSuccess = FALSE;
                }else if (SIGN ^ bSIGN){
                    printf("[%d]Unexpected SIGN\r\n",i);
                    bSuccess = FALSE;
                }else if (SGL ^ SGL){
                    printf("[%d]Unexpected SGL\r\n",i);
                    bSuccess = FALSE;
                }
                if (bSuccess)
                    szVol[nPortIndex++] = Value32; //(Value32 >> 6) & 0xFFFFFF; // 24 bits
            }else{
                printf("SPI Read Error\r\n");
            }
        } // for i
    } // for c
    return bSuccess;
 }
int tick = 0;
void reset_power_tick()
{
	tick = 0;
}
void measure_power()
 {
	//*************************************
	// POWER VARIABLES

	bool bSuccess;
	int tick = 0;
	const float fRef = 5.0; // 5.0V

	float fVolDrop, fCurrent, fPower, fVol, fEnergy;

	alt_u32 szVol[POWER_PORT_NUM];
	alt_u32 SIG, MSB, RESULT;
	float szRes[] = { 0.003, 0.003, 0.003, 0.003, 0.003, 0.003, 0.003, 0.003,
			0.003, 0.003, 0.003, 0.003 };
	float szRefVol[] =
			{ 0.9, 0.9, 3.0, 0.9, 1.8, 2.5, 1.8, 2.5, 1.1, 1.4, 3.3, 2.5 };
	char szName[][64] = { "VCCD_PLL", "VCC0P9", "GPIO_VCCIOPD", "VCCHIP",
			"VCC1P8_34R", "HSMA_VCCIO", "VCC1P8_78R", "VCCA_PLL", "VCCL_GXB",
			"VCCH_GXB", "VCC3P3_HSMC", "HSMB_VCCIO", };

	bSuccess = POWER_Read(szVol);
	if (bSuccess) {
		//for(i=0;i<POWER_PORT_NUM && bSuccess;i++){
		int i = 1;
		SIG = (szVol[i] >> 29) & 0x01;
		MSB = (szVol[i] >> 28) & 0x01;
		RESULT = (szVol[i] >> 6) & 0x3FFFFF; // 22 bits
		if (MSB == 0)
			fVolDrop = (float) (RESULT) / (float) 0x400000;
		else
			fVolDrop = 0.0; //always be positive in schematic // -(float)(0x400000-RESULT)/(float)0x400000;
		if (SIG && MSB) {
			fVol = fRef * 0.5;
			printf("[%s:%06XH,Over]\r\n  VolDrop:%f(V)\r\n", szName[i],
					(int) szVol[i], fVol);
		} else if (SIG && !MSB) {
			fVol = fRef * 0.5 * fVolDrop;
			fCurrent = (fVolDrop / szRes[i]);
			fPower = (szRefVol[i] * fCurrent);
			fVolDrop = fVolDrop * 1000 * 1000;
			fCurrent = fCurrent * 1000 * 1000;
			fPower = fPower * 1000 * 1000;
			//printf("[%s:%06XH,Pos]  VolDrop:%f(V), Current:%f(A), Power:%f(W)\n", szName[i], (int)szVol[i], fVolDrop, fCurrent, fPower);
			// for energy assuming samples are 1 second apart, exactly. might need to add a system timer...
			printf("%i\t%i\t%i\t", (int)fVolDrop, (int)fCurrent, (int)fPower);
			//printf("%i\t", (int)fVolDrop);
			//printf("%i\t", (int)fCurrent);
			//printf("%i\t", (int)fPower);
			//printf("\n");
//			printf("%f\t", fEnergy = fEnergy + fPower);

		} else if (!SIG && MSB) {
			fVol = fRef * 0.5 * fVolDrop;
			fCurrent = fVolDrop / szRes[i];
			fPower = szRefVol[i] * fCurrent;
			printf(
					"[%s:%06XH,Neg]\r\n  VolDrop:%f(V), Current:%f(A), Power:%f(W)\r\n",
					szName[i], (int) szVol[i], fVolDrop, fCurrent, fPower);
		} else if (!SIG && !MSB) {
			fVol = -fRef * 0.5;
			printf("[%s:%06XH,Under]\r\n  VolDrop:%f(V)\r\n", szName[i],
					(int) szVol[i], fVol);
		}
	}
}
