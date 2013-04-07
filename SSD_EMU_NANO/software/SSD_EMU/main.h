/*
 * main.h
 *
 *  Created on: Oct 30, 2012
 *      Author: Robert
 */

#ifndef MAIN_H_
#define MAIN_H_


#include <stdio.h>
#include <system.h>
#include <sys/alt_flash.h>
#include <alt_types.h>
#include <sys/alt_timestamp.h>
#include <altera_avalon_spi.h>
#include <altera_avalon_spi_regs.h>

//Defines
#define FL_HDR_BUF_SIZE		512
#define HEADER_START_ADDR	0x00
#define MBC_HEADER_SIZE		16
#define FL_MAX_BUF_SIZE		8192
#define LUT_CFG 0x00200000
#define SCH_CFG 0x00400000
#define EN_LUT_CFG(A) ((A) | LUT_CFG)
#define EN_SCH_CFG(A) ((A) | SCH_CFG)
#define MBC_INSTR 0x00
#define MBC_START() __builtin_custom_in(MBC_INSTR)
#define MBC_MEM_CFG_INSTR 0x01
#define MBC_CFG_MEM(A,B) __builtin_custom_inii(MBC_MEM_CFG_INSTR,(A),(B))
#define SPI_WRITE(LEN, BUF) alt_avalon_spi_command(SPI_0_BASE, 0, (LEN), (BUF), 0, 0, 0)

#define EX_BEGIN() IOWR_ALTERA_AVALON_PIO_DATA(CPU_EX_FLAG_BASE, 0xFF)
#define EX_END() IOWR_ALTERA_AVALON_PIO_DATA(CPU_EX_FLAG_BASE, 0x00)

//prototypes
void print_times();
void csleep(alt_u32);
void measure_power();

// timestamps
extern	alt_u32 t_init;
extern	alt_u32 t_fl_open, 		t_fl_open_begin, 	t_fl_open_end;
extern	alt_u32 t_fl_rd_kids,	t_fl_rd_kids_begin,	t_fl_rd_kids_end;
extern	alt_u32 t_fl_rd_kh, 	t_fl_rd__kh_begin, 	t_fl_rd_kh_end;
extern	alt_u32 t_hdr_parse, 	t_hdr_parse_begin, 	t_hdr_parse_end;
extern	alt_u32 t_sch_rd,		t_sch_rd_begin,		t_sch_rd_end;
extern	alt_u32 t_lut_rd,		t_lut_rd_begin,		t_lut_rd_end;
extern	alt_u32 t_sch_cfg,		t_sch_cfg_begin,	t_sch_cfg_end;
extern	alt_u32 t_lut_cfg,		t_lut_cfg_begin,	t_lut_cfg_end;
extern	alt_u32 t_mbc_cfg, 		t_mbc_cfg_begin, 	t_mbc_cfg_end;
extern alt_u32 t_mbc_run,		t_mbc_run_begin,	t_mbc_run_end;

void spi_tx_char(short tx_data, long spi_addr)
{
  int ctrlbyte;

/* select spi device #0 */
  IOWR(spi_addr, 5, 1);

/* Assert SS_n */
  ctrlbyte = IORD(spi_addr, 3);
  IOWR(spi_addr, 3, (ctrlbyte | ALTERA_AVALON_SPI_CONTROL_SSO_MSK));

/* Transmit a byte: */
  while (!(IORD(spi_addr, 2) & ALTERA_AVALON_SPI_STATUS_TRDY_MSK));
  IOWR(spi_addr, 1, tx_data);

/* Wait until the last byte is transmitted: */
  while (!(IORD(spi_addr, 2) & ALTERA_AVALON_SPI_STATUS_TMT_MSK));

/* Release SS_n: */
  IOWR(spi_addr, 3, IORD(spi_addr, 3) & ~ALTERA_AVALON_SPI_CONTROL_SSO_MSK );

/* Deselect all spis: */
  IOWR(spi_addr, 5, 0);

}

#endif /* MAIN_H_ */
