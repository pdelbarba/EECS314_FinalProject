#ifndef TERASIC_INCLUDES_H_
#define TERASIC_INCLUDES_H_

#include <stdio.h>
//#include <stdlib.h> // malloc, free
//#include <string.h>
//#include <stddef.h>
#include <unistd.h>  // usleep (unix standard?)
//#include "sys/alt_flash.h"
//#include "sys/alt_flash_types.h"
#include "io.h"
#include "alt_types.h"  // alt_u32
#include "altera_avalon_pio_regs.h" //IOWR_ALTERA_AVALON_PIO_DATA
//#include "sys/alt_irq.h"  // interrupt
//#include "sys/alt_alarm.h" // time tick function (alt_nticks(), alt_ticks_per_second())
//#include "sys/alt_timestamp.h"
//#include "sys/alt_stdio.h"
#include "system.h"
#include <fcntl.h>
//#include "debug.h"

#define DEBUG_DUMP  /*printf */ 


typedef int bool;
#define TRUE    1
#define FALSE   0

#endif /*TERASIC_INCLUDES_H_*/
