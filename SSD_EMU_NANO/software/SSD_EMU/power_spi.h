#ifndef POWER_SPI_H_
#define POWER_SPI_H_

#define POWER_DEVICE0_PORT_NUM  8
#define POWER_DEVICE1_PORT_NUM  4
#define POWER_PORT_NUM     (POWER_DEVICE0_PORT_NUM + POWER_DEVICE1_PORT_NUM)
#define POWER_DEVICE_NUM   2
bool POWER_SPI_RW(alt_u8 IcIndex, alt_u8 NextChannel, bool bEN, bool bSIGN, bool bSGL, alt_u32 *pValue);


#endif /*POWER_SPI_H_*/
