#define DEBUG 0
#define XMIT_PROF 0

#include <stdio.h>
#include "ISPI.h"
#include <io.h>
#include <system.h>
#include <time.h>
#include <altera_avalon_pio_regs.h>
#include <sys/alt_timestamp.h>

volatile alt_u16 interrupt_data;
volatile char interrupted = 0;



int main()
{
	init_spi_isr();

	IOWR_ALTERA_AVALON_PIO_DATA(CPU_EX_FLAG_BASE, 0xFF);

	int i = 0;
	for (i = 0; i < 2010; i = i + 1)
	{
		__asm__("NOP");
	}
	IOWR_ALTERA_AVALON_PIO_DATA(CPU_EX_FLAG_BASE, 0x00);

	while(!interrupted) { ; }

	printf("Received Data: %i\n", interrupt_data);
	interrupt_data = 0;


	return 0;
}

void spi_isr(void* context, alt_u32 id) {

	interrupt_data = IORD_32DIRECT(SPI_0_BASE, 0);
	IOWR_32DIRECT(SPI_0_BASE, 2, 0);
	IOWR_ALTERA_AVALON_SPI_CONTROL( SPI_0_BASE, ALTERA_AVALON_SPI_CONTROL_SSO_MSK | ALTERA_AVALON_SPI_CONTROL_IRRDY_MSK );

}


