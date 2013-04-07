#define PROFILING	0
#define PRINT_SCHED_TBL_FROM_FLASH 0
#define PRINT_LUT_FROM_FLASH	0
#define	 PRINT_FLASH_INFO 0
#define	 RC_LUT 1
#define RC_SCH 1
#define RUN_CPU_TESTS 1
#define RUN_CPU_ENERGY_TESTS 0
#define SPI_TEST 0

#include "main.h"
#include "aes.h"
#include "terasic_includes.h"
#include "power_spi.h"

	//*****************
	// profiling vars
	//*****************
	alt_u32 t_init;
	alt_u32 t_fl_open, 		t_fl_open_begin, 	t_fl_open_end;
	alt_u32 t_fl_rd_kids,	t_fl_rd_kids_begin,	t_fl_rd_kids_end;
	alt_u32 t_fl_rd_kh, 	t_fl_rd_kh_begin, 	t_fl_rd_kh_end;
	alt_u32 t_hdr_parse, 	t_hdr_parse_begin, 	t_hdr_parse_end;
	alt_u32 t_sch_rd,		t_sch_rd_begin,		t_sch_rd_end;
	alt_u32 t_lut_rd,		t_lut_rd_begin,		t_lut_rd_end;
	alt_u32 t_sch_cfg,		t_sch_cfg_begin,	t_sch_cfg_end;
	alt_u32 t_lut_cfg,		t_lut_cfg_begin,	t_lut_cfg_end;
	alt_u32 t_mbc_cfg, 		t_mbc_cfg_begin, 	t_mbc_cfg_end;
	alt_u32 t_mbc_run,		t_mbc_run_begin,	t_mbc_run_end;
	alt_u32 t_spi_xmit,		t_spi_xmit_begin,	t_spi_xmit_end;

#if RUN_CPU_TESTS
	alt_u32 t_fir_run,		t_fir_run_begin,	t_fir_run_end;
	alt_u32 t_aes_run,		t_aes_run_begin,	t_aes_run_end;
	alt_u32 t_ci_run,		t_ci_run_begin,		t_ci_run_end;
	alt_u32 t_des_run,		t_des_run_begin,	t_des_run_end;
#endif

	alt_u32 overhead, o0, o1;
	//*****************


	alt_u8 mbc_header[MBC_HEADER_SIZE];


//*************************************

#if RUN_CPU_TESTS

	volatile char b [] = {12, 14, 14, 12, 8, 14, 8, 12};
	volatile char g [] = {15, 15, 14, 13, 12, 12, 12, 13};
	volatile char r [] = {11, 12, 10, 12, 11, 12, 14, 14};
int ci_testbench() {
	int numPx = 108;
	int i, j, sumR = 0, sumG = 0, sumB = 0;
	int temp = 0, result = 0;
	sumB = sumG = sumR = 0;
	t_ci_run_begin = alt_timestamp();
	EX_BEGIN();
	for (i = 0; i < numPx; i = i + 1) {
		sumB = sumB + b[i];
		sumG = sumG + g[i];
		sumR = sumR + r[i];
	}
	sumB = sumB / numPx;
	sumG = ((sumG / numPx) << 8);
	sumR = ((sumR / numPx) << 16);
	temp = sumR + sumB + sumG;
	EX_END();
	sumB = sumG = sumR = 0;

	for (i = 0; i < numPx; i = i + 1) {
		sumB = sumB + b[i];
		sumG = sumG + g[i];
		sumR = sumR + r[i];
	}
	sumB = sumB / numPx;
	sumG = ((sumG / numPx) << 8);
	sumR = ((sumR / numPx) << 16);
	temp = sumR + sumB + sumG;
	sumB = sumG = sumR = 0;

	for (i = 0; i < numPx; i = i + 1) {
		sumB = sumB + b[i];
		sumG = sumG + g[i];
		sumR = sumR + r[i];
	}
	sumB = sumB / numPx;
	sumG = ((sumG / numPx) << 8);
	sumR = ((sumR / numPx) << 16);
	temp = sumR + sumB + sumG;

	t_ci_run_end = alt_timestamp();
	t_ci_run = (t_ci_run_end - t_ci_run_begin) / 3;
#if RUN_CPU_TESTS & ~RUN_CPU_ENERGY_TESTS
	printf("CI: %08x\n", temp);
#endif
	return t_ci_run;
}


volatile unsigned char key[KEY_128] = "uber strong key!";
volatile unsigned char ptext[16] = "Attack at dawn!";
volatile unsigned char decptext[16];
volatile unsigned char ctext[16];
int aes_testbench() {
	aes_ctx_t *ctx;

	init_aes();
	ctx = aes_alloc_ctx(key, sizeof(key));
	if (!ctx) {
		return;
	}
	t_aes_run_begin = alt_timestamp();
	EX_BEGIN();
	aes_encrypt(ctx, ptext, ctext);
	EX_END();
	aes_encrypt(ctx, ptext, ctext);
	aes_encrypt(ctx, ptext, ctext);
	t_aes_run_end = alt_timestamp();
	t_aes_run = (t_aes_run_end - t_aes_run_begin) / 3;
	aes_free_ctx(ctx);
#if RUN_CPU_TESTS & ~RUN_CPU_ENERGY_TESTS
	int i = 0;
	printf("AES: ");
	for(i = 0; i < 16; i = i + 1)
		printf("%02x ", ctext[i]);
	printf("\n");
#endif
	return t_aes_run;
}

//*****//
/* FIR */
//*****//
volatile char sum0[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
volatile int co0[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0X0B, 0X0C, 0X0D, 0X0F };
volatile int in0[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,	0x0A, 0X0B, 0X0C, 0X0D, 0X0F };
alt_u32 fir_testbench() {

	int i, j;
	int N = 16;
	t_fir_run_begin = alt_timestamp();
	EX_BEGIN();
	sum0[0] = sum0[0] * in0[0];
	for (i = 1; i < N; i++) {
		sum0[i] = sum0[i - 1] + co0[i] * in0[i];
	}
	EX_END();
	for(i = 0; i < 16; i = i + 1)
			sum0[i] = 0;
	sum0[0] = sum0[0] * in0[0];
	for (i = 1; i < N; i++) {
		sum0[i] = sum0[i - 1] + co0[i] * in0[i];
	}
	for(i = 0; i < 16; i = i + 1)
		sum0[i] = 0;

	sum0[0] = sum0[0] * in0[0];
	for (i = 1; i < N; i++) {
		sum0[i] = sum0[i - 1] + co0[i] * in0[i];
	}

	t_fir_run_end = alt_timestamp();
	t_fir_run = (t_fir_run_end - t_fir_run_begin) / 3;
#if RUN_CPU_TESTS & ~RUN_CPU_ENERGY_TESTS
	printf("FIR: ");
	for(i = 0; i < 16; i = i + 1)
		printf("%02x ", sum0[i]);
	printf("\n");
#endif
	return t_fir_run;
}

volatile unsigned char dst[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
volatile unsigned char key2[8] = { 0x5B, 0x5A, 0x57, 0x67, 0x6A, 0x56, 0x67, 0X6E };
volatile unsigned char src[8] = { 0x67, 0x5A, 0x69, 0x67, 0x5E, 0x5A, 0x6B, 0x5A };
int des_testbench(){
	t_des_run_begin = alt_timestamp();
	EX_BEGIN();
	auth_DEShash(dst, key2, src);
	EX_END();
	auth_DEShash(dst, key2, src);
	auth_DEShash(dst, key2, src);
	t_des_run_end = alt_timestamp();
	t_des_run = (t_des_run_end - t_des_run_begin) / 3;
#if RUN_CPU_TESTS & ~RUN_CPU_ENERGY_TESTS
	printf("DES: ");
	int i;
	for(i = 0; i < 8; i = i + 1)
		printf("%02x ", dst[i]);
	printf("\n");
#endif
	return t_des_run;
}
#endif

int mbc_testbench(){
	t_mbc_run_begin = alt_timestamp();
	EX_BEGIN();
	MBC_START();
	EX_END();
	t_mbc_run_end = alt_timestamp();
	t_mbc_run = (t_mbc_run_end - t_mbc_run_begin);
	return t_mbc_run;
}

alt_u8 len = 0x04;
alt_u8 data[] = {0xAA, 0xAA, 0xAA, 0xAA};
int spi_pow_testbench() {
	/*spi_tx_char(data[0], SPI_0_BASE);
	spi_tx_char(data[1], SPI_0_BASE);
	spi_tx_char(data[2], SPI_0_BASE);
	spi_tx_char(data[3], SPI_0_BASE);*/
	t_spi_xmit_begin = alt_timestamp();
	SPI_WRITE(len, data);
	t_spi_xmit_end = alt_timestamp();
	t_spi_xmit = (t_spi_xmit_end - t_spi_xmit_begin);
	return t_spi_xmit;

}

int main()
{
	alt_flash_fd * fl_dev;

	alt_u32 sched_tbl_size;
	alt_u32 lut_size;

	alt_timestamp_start();
	t_init = alt_timestamp();
	int oCnt;
	for(oCnt = 0; oCnt < 20; oCnt = oCnt + 1)
	{
		o0 = alt_timestamp();
		o1 = alt_timestamp();
		overhead = overhead + (o1 - o0);
	}
	overhead = overhead / 20;

#if SPI_TEST
	int spi = 0;
	int res_spi = 0;
	for(spi = 0; spi < 25; spi = spi + 1)
	{
		printf("%i\t", spi);
		res_spi = spi_pow_testbench();
		measure_power();
		printf("%i\n", res_spi);
		alt_timestamp_start();
	}
	res_spi = 0;
	spi = 0;
	for(spi = 0; spi < 25; spi = spi + 1)
	{
		printf("%i\t", spi);
		measure_power();
		alt_u32 t0 = alt_timestamp();
		alt_u32 t1 = alt_timestamp();
		printf("%i\n", t1-t0);
		alt_timestamp_start();
	}

#endif

#if RUN_CPU_TESTS
	volatile alt_u32 res_fir, res_des, res_aes, res_ci;

	//res_aes = aes_testbench();
	//res_ci = ci_testbench();
	//res_des = des_testbench();
	res_fir = fir_testbench();


	printf("\nTimestamp Driver Overhead Cycles: %i\n\n", overhead);
	//printf("AES CYCLES: %i\n", t_aes_run - overhead);
	//printf("CI CYCLES: %i\n", t_ci_run - overhead);
	//printf("DES CYCLES: %i\n", t_des_run - overhead);
	printf("FIR CYCLES: %i\n", t_fir_run - overhead);
#endif


	alt_timestamp();
	//
	// init code here
	//

	//**************
	//	OPEN FLASH
	t_fl_open_begin = alt_timestamp();
	fl_dev = alt_flash_open_dev(CFI_FLASH_0_NAME);
	t_fl_open_end = alt_timestamp();
	t_fl_open = t_fl_open_end - t_fl_open_begin;
	//
	//**************

	if (fl_dev != NULL)
	{
		//**************
		//	READ FLASH (Kernel Header)
		alt_read_flash(fl_dev, HEADER_START_ADDR, mbc_header, MBC_HEADER_SIZE);
		//
		//**************

		//**************
		//	PARSE HEADER
		t_hdr_parse_begin = alt_timestamp();
		sched_tbl_size = mbc_header[10];
		sched_tbl_size = sched_tbl_size << 8;
		sched_tbl_size = sched_tbl_size | mbc_header[11];
		lut_size = mbc_header[13];
		lut_size = lut_size << 8;
		lut_size = lut_size | mbc_header[14];
		lut_size = lut_size << 8;
		lut_size = lut_size | mbc_header[15];
		char kernel_name[9];
		int k = 0;
		for(k = 0; k < 8; k = k + 1){
			kernel_name[k] = mbc_header[k];
		}
		kernel_name[8] = '\0';
		t_hdr_parse_end = alt_timestamp();
		t_hdr_parse = t_hdr_parse_end - t_hdr_parse_begin;
		//
		//**************

		printf("\n***BEGIN CONFIG INFO***\n\n");
		printf("KERNEL NAME: \t%s\n", kernel_name);
		printf("MAHA TARGET: \t0x%02x\n", mbc_header[8]);
		printf("SCHED TABLE SIZE: \t0x%02x\n", sched_tbl_size);
		printf("MLBS CONFIGURED: \t0x%02x\n", mbc_header[12]);
		printf("LUT SIZE: \t\t0x%02x\n", lut_size);
		printf("\n***END CONFIG INFO***\n");

#if RC_SCH
		//**************
		//	READ SCHED -- sched immediately follows header
		alt_u32 sched_offset = HEADER_START_ADDR + MBC_HEADER_SIZE;
		alt_u32 num_instr = sched_tbl_size / 4;
		alt_u32 sched_buf[num_instr]; // sched tbl stored in bytes, but we want 32b vals
		t_sch_rd_begin = alt_timestamp();
		alt_read_flash(fl_dev, sched_offset, sched_buf, sched_tbl_size);
		t_sch_rd_end = alt_timestamp();
		t_sch_rd = t_sch_rd_end - t_sch_rd_begin;

#if PRINT_SCHED_TBL_FROM_FLASH
		int cnt = 0;
		for(cnt = 0; cnt < num_instr; cnt = cnt + 1)
		{
			printf("%i:\t%08x\n", cnt, sched_buf[cnt]);
			csleep(1000);
		}
#endif

		//**************
		//	WRITE SCHED
		int addr = 0;
		int temp = 0;
		for(addr = 0; addr < num_instr; addr = addr + 1)
		{
			t_sch_cfg_begin = alt_timestamp();
			temp = addr | SCH_CFG;
			MBC_CFG_MEM(temp, sched_buf[addr]);
			t_sch_cfg_end = alt_timestamp();
			t_sch_cfg = t_sch_cfg + (t_sch_cfg_end - t_sch_cfg_begin);
			//csleep(50);
		}
#endif

#if RC_LUT
		//**************
		//	READ LUT - LUT follows sched tbl in memory
		alt_u32 lut_offset = sched_offset + sched_tbl_size;
		alt_u32 lut_entries_read = 0;
		alt_u32 num_lut_words = 1 + (lut_size / 4);
		// LUT buffer may well exceed max buffer size for on_chip mem
		// limited to FL_MAX_BUF_SIZE.
		alt_u32 lut_buf_size = 0;
		if(lut_size > FL_MAX_BUF_SIZE)
			lut_buf_size = FL_MAX_BUF_SIZE;
		else
			lut_buf_size = lut_size;

		// this should be 1 if lut_size < FL_MAX_BUF_SIZE otherwise basically ceiling function.
		alt_u32 fl_reads = 1 + (lut_size / FL_MAX_BUF_SIZE);
		alt_u8 lut_buf[lut_buf_size];
		int cRead = 0;
		int lut_entry = 0;
		for (cRead = 0; cRead < fl_reads; cRead = cRead + 1)
		{
			// read from lut_offset
			t_lut_rd_begin = alt_timestamp();
			alt_read_flash(fl_dev, lut_offset, lut_buf, lut_buf_size);
			t_lut_rd_end = alt_timestamp();
			t_lut_rd = t_lut_rd + (t_lut_rd_end - t_lut_rd_begin); // increment total time

#if PRINT_LUT_FROM_FLASH
			// just do this once for testing
			if(cRead == 0)
			{
				int j = 0;
				for(j = 0; j < 32; j = j + 1)	// just print first 32 values
				{
					printf("%i: \t%02x\n", j, lut_buf[j]);
					csleep(1000);
				}
			}
#endif
			// configure LUT memory with buffered data
			// on all but the last loop the # entries to write = lut_buf_size
			// on last loop there will be variable # entries to write (between 1 and lut_buf_size - 1)
			if(cRead == fl_reads - 1)
				lut_entries_read = (lut_size % lut_buf_size);
			else
				lut_entries_read = lut_buf_size;
			alt_u32 addr;
			for(lut_entry = 0; lut_entry < lut_entries_read; lut_entry = lut_entry + 1)
			{
				addr = ((cRead * lut_buf_size) + lut_entry) | LUT_CFG;
				t_lut_cfg_begin = alt_timestamp();
				MBC_CFG_MEM(addr, lut_buf[lut_entry]);
				t_lut_cfg_end = alt_timestamp();
				t_lut_cfg = t_lut_cfg + (t_lut_cfg_end - t_lut_cfg_begin);
			}

			// increment offset
			lut_offset = lut_offset + lut_buf_size;
		}
#endif
		// everything should be configured by now, so run the kernel(s)
#if !RUN_CPU_ENERGY_TESTS
		alt_u32 res_mbc;
		printf("MBC\n");
		int m = 0;
		for(m = 0; m < 1; m = m + 1)
		{
			printf("%i:\t", m);
			res_mbc = mbc_testbench();
		//	measure_power();
			printf("\t%i\n", res_mbc - overhead);
			alt_timestamp_start();
		}
#endif

	} else {
		printf("\n***Flash access NOT successful!***\n");
	}


#if PROFILING
	print_times();
#endif

  return 0;
}

#if PROFILING
void print_times()
{
	printf("\n***RUN TIMES (cycles)***\n");
	printf("System Init:  \t%i\n", t_init);
	printf("Open Fl Dev:  \t%i\n", t_fl_open);
	printf("Read Fl Dev:  \t%i\n", t_fl_rd_kh);
	printf("Parse Header: \t%i\n", t_hdr_parse);
	printf("Read Sched:   \t%i\n", t_sch_rd);
	printf("Sched Conf:   \t%i\n", t_sch_cfg);
	printf("Read LUT:     \t%i\n", t_lut_rd);
	printf("LUT Conf:     \t%i\n", t_lut_cfg);
	printf("Program MBC:  \t%i\n", (t_sch_rd + t_sch_cfg + t_lut_rd + t_lut_cfg));
	printf("Run Kernel:   \t%i\n", t_mbc_run);
	printf("\n************************\n");
}
#endif

void csleep(alt_u32 cycles)
{
	alt_u32 t_start = alt_timestamp();
	alt_u32 t_target = t_start + cycles;
	while (alt_timestamp() < t_target)
		__asm__("nop");
}
