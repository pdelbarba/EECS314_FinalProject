#ifndef ISPI_H
#define ISPI_H

#include <sys/alt_irq.h>
#include <system.h>
#include <altera_avalon_spi.h>
#include <altera_avalon_spi_regs.h>

#define SPI_WRITE(LEN, BUF) alt_avalon_spi_command(SPI_0_BASE, 0, (LEN), (BUF), 0, 0, 0)
#define SPI_READ(LEN, BUF) alt_avalon_spi_command(SPI_0_BASE, 0, 0, 0, (LEN), (BUF), 0)



void init_spi_isr(void);
void spi_isr(void*, alt_u32);

void init_spi_isr(void) {
	IOWR_ALTERA_AVALON_SPI_CONTROL( SPI_0_BASE, ALTERA_AVALON_SPI_CONTROL_SSO_MSK | ALTERA_AVALON_SPI_CONTROL_IRRDY_MSK );
	alt_irq_register( SPI_0_IRQ, (void *)NULL, spi_isr);
	int i = 0;
	for(i = 0; i < 500; i = i + 1)
		__asm__("nop");
}

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


void direct_spi()
{
  int i;
  unsigned short tx_data = 0;
  unsigned short get_data = 0;
  int reg_file_addr = 0;
  unsigned char reg_file_data = 0;

     tx_data = 0xAC;//(((short)i << 8) & 0xFF00) + (0x00FF & (short)i);
     spi_tx_char(tx_data, SPI_0_BASE);

//     if ((IORD_16DIRECT(SPI_0_BASE, 2) & ALTERA_AVALON_SPI_STATUS_ROE_MSK))
//         printf("slave data overrun\n");

//    get_data = IORD_16DIRECT(SPI_0_BASE, 0);
//    printf("Received: %x\n", get_data);



}
#endif /*ISPI.h*/
