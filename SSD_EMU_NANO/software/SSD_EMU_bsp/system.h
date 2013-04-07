/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'proto1'
 * SOPC Builder design path: C:/Users/Robert/Documents/MBC/OFFCHIP/SSD_EMU/proto1.sopcinfo
 *
 * Generated: Sun Nov 18 15:47:33 EST 2012
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x4040820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1b
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x4020020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 1
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1b
#define ALT_CPU_NAME "nios2_qsys_0"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x4020000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x4040820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1b
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x4020020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 1
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1b
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x4020000


/*
 * Custom instruction macros
 *
 */

#define ALT_CI_MBC_CONTROLLER_0(A,B) __builtin_custom_inii(ALT_CI_MBC_CONTROLLER_0_N,(A),(B))
#define ALT_CI_MBC_CONTROLLER_0_N 0x0
#define ALT_CI_MBC_MEM_CFG_0(A,B) __builtin_custom_inii(ALT_CI_MBC_MEM_CFG_0_N,(A),(B))
#define ALT_CI_MBC_MEM_CFG_0_N 0x1


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_GENERIC_TRISTATE_CONTROLLER
#define __ALTERA_NIOS2_QSYS
#define __MBC_CONTROLLER
#define __MBC_MEM_CFG


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Stratix IV"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x40410e0
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x40410e0
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x40410e0
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "proto1"


/*
 * cfi_flash_0 configuration
 *
 */

#define ALT_MODULE_CLASS_cfi_flash_0 altera_generic_tristate_controller
#define CFI_FLASH_0_BASE 0x0
#define CFI_FLASH_0_HOLD_VALUE 20
#define CFI_FLASH_0_IRQ -1
#define CFI_FLASH_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CFI_FLASH_0_NAME "/dev/cfi_flash_0"
#define CFI_FLASH_0_SETUP_VALUE 25
#define CFI_FLASH_0_SIZE 33554432u
#define CFI_FLASH_0_SPAN 67108864
#define CFI_FLASH_0_TIMING_UNITS "ns"
#define CFI_FLASH_0_TYPE "altera_generic_tristate_controller"
#define CFI_FLASH_0_WAIT_VALUE 100


/*
 * cpu_ex_flag configuration
 *
 */

#define ALT_MODULE_CLASS_cpu_ex_flag altera_avalon_pio
#define CPU_EX_FLAG_BASE 0x40410d0
#define CPU_EX_FLAG_BIT_CLEARING_EDGE_REGISTER 0
#define CPU_EX_FLAG_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CPU_EX_FLAG_CAPTURE 0
#define CPU_EX_FLAG_DATA_WIDTH 1
#define CPU_EX_FLAG_DO_TEST_BENCH_WIRING 0
#define CPU_EX_FLAG_DRIVEN_SIM_VALUE 0x0
#define CPU_EX_FLAG_EDGE_TYPE "NONE"
#define CPU_EX_FLAG_FREQ 50000000u
#define CPU_EX_FLAG_HAS_IN 0
#define CPU_EX_FLAG_HAS_OUT 1
#define CPU_EX_FLAG_HAS_TRI 0
#define CPU_EX_FLAG_IRQ -1
#define CPU_EX_FLAG_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CPU_EX_FLAG_IRQ_TYPE "NONE"
#define CPU_EX_FLAG_NAME "/dev/cpu_ex_flag"
#define CPU_EX_FLAG_RESET_VALUE 0x0
#define CPU_EX_FLAG_SPAN 16
#define CPU_EX_FLAG_TYPE "altera_avalon_pio"


/*
 * csense_adc_fo configuration
 *
 */

#define ALT_MODULE_CLASS_csense_adc_fo altera_avalon_pio
#define CSENSE_ADC_FO_BASE 0x4041080
#define CSENSE_ADC_FO_BIT_CLEARING_EDGE_REGISTER 0
#define CSENSE_ADC_FO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CSENSE_ADC_FO_CAPTURE 0
#define CSENSE_ADC_FO_DATA_WIDTH 1
#define CSENSE_ADC_FO_DO_TEST_BENCH_WIRING 0
#define CSENSE_ADC_FO_DRIVEN_SIM_VALUE 0x0
#define CSENSE_ADC_FO_EDGE_TYPE "NONE"
#define CSENSE_ADC_FO_FREQ 50000000u
#define CSENSE_ADC_FO_HAS_IN 0
#define CSENSE_ADC_FO_HAS_OUT 1
#define CSENSE_ADC_FO_HAS_TRI 0
#define CSENSE_ADC_FO_IRQ -1
#define CSENSE_ADC_FO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CSENSE_ADC_FO_IRQ_TYPE "NONE"
#define CSENSE_ADC_FO_NAME "/dev/csense_adc_fo"
#define CSENSE_ADC_FO_RESET_VALUE 0x0
#define CSENSE_ADC_FO_SPAN 16
#define CSENSE_ADC_FO_TYPE "altera_avalon_pio"


/*
 * csense_cs_n configuration
 *
 */

#define ALT_MODULE_CLASS_csense_cs_n altera_avalon_pio
#define CSENSE_CS_N_BASE 0x4041090
#define CSENSE_CS_N_BIT_CLEARING_EDGE_REGISTER 0
#define CSENSE_CS_N_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CSENSE_CS_N_CAPTURE 0
#define CSENSE_CS_N_DATA_WIDTH 2
#define CSENSE_CS_N_DO_TEST_BENCH_WIRING 0
#define CSENSE_CS_N_DRIVEN_SIM_VALUE 0x0
#define CSENSE_CS_N_EDGE_TYPE "NONE"
#define CSENSE_CS_N_FREQ 50000000u
#define CSENSE_CS_N_HAS_IN 0
#define CSENSE_CS_N_HAS_OUT 1
#define CSENSE_CS_N_HAS_TRI 0
#define CSENSE_CS_N_IRQ -1
#define CSENSE_CS_N_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CSENSE_CS_N_IRQ_TYPE "NONE"
#define CSENSE_CS_N_NAME "/dev/csense_cs_n"
#define CSENSE_CS_N_RESET_VALUE 0x0
#define CSENSE_CS_N_SPAN 16
#define CSENSE_CS_N_TYPE "altera_avalon_pio"


/*
 * csense_sck configuration
 *
 */

#define ALT_MODULE_CLASS_csense_sck altera_avalon_pio
#define CSENSE_SCK_BASE 0x40410c0
#define CSENSE_SCK_BIT_CLEARING_EDGE_REGISTER 0
#define CSENSE_SCK_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CSENSE_SCK_CAPTURE 0
#define CSENSE_SCK_DATA_WIDTH 1
#define CSENSE_SCK_DO_TEST_BENCH_WIRING 0
#define CSENSE_SCK_DRIVEN_SIM_VALUE 0x0
#define CSENSE_SCK_EDGE_TYPE "NONE"
#define CSENSE_SCK_FREQ 50000000u
#define CSENSE_SCK_HAS_IN 0
#define CSENSE_SCK_HAS_OUT 1
#define CSENSE_SCK_HAS_TRI 0
#define CSENSE_SCK_IRQ -1
#define CSENSE_SCK_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CSENSE_SCK_IRQ_TYPE "NONE"
#define CSENSE_SCK_NAME "/dev/csense_sck"
#define CSENSE_SCK_RESET_VALUE 0x0
#define CSENSE_SCK_SPAN 16
#define CSENSE_SCK_TYPE "altera_avalon_pio"


/*
 * csense_sdi configuration
 *
 */

#define ALT_MODULE_CLASS_csense_sdi altera_avalon_pio
#define CSENSE_SDI_BASE 0x40410a0
#define CSENSE_SDI_BIT_CLEARING_EDGE_REGISTER 0
#define CSENSE_SDI_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CSENSE_SDI_CAPTURE 0
#define CSENSE_SDI_DATA_WIDTH 1
#define CSENSE_SDI_DO_TEST_BENCH_WIRING 0
#define CSENSE_SDI_DRIVEN_SIM_VALUE 0x0
#define CSENSE_SDI_EDGE_TYPE "NONE"
#define CSENSE_SDI_FREQ 50000000u
#define CSENSE_SDI_HAS_IN 0
#define CSENSE_SDI_HAS_OUT 1
#define CSENSE_SDI_HAS_TRI 0
#define CSENSE_SDI_IRQ -1
#define CSENSE_SDI_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CSENSE_SDI_IRQ_TYPE "NONE"
#define CSENSE_SDI_NAME "/dev/csense_sdi"
#define CSENSE_SDI_RESET_VALUE 0x0
#define CSENSE_SDI_SPAN 16
#define CSENSE_SDI_TYPE "altera_avalon_pio"


/*
 * csense_sdo configuration
 *
 */

#define ALT_MODULE_CLASS_csense_sdo altera_avalon_pio
#define CSENSE_SDO_BASE 0x40410b0
#define CSENSE_SDO_BIT_CLEARING_EDGE_REGISTER 0
#define CSENSE_SDO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CSENSE_SDO_CAPTURE 0
#define CSENSE_SDO_DATA_WIDTH 1
#define CSENSE_SDO_DO_TEST_BENCH_WIRING 0
#define CSENSE_SDO_DRIVEN_SIM_VALUE 0x0
#define CSENSE_SDO_EDGE_TYPE "NONE"
#define CSENSE_SDO_FREQ 50000000u
#define CSENSE_SDO_HAS_IN 1
#define CSENSE_SDO_HAS_OUT 0
#define CSENSE_SDO_HAS_TRI 0
#define CSENSE_SDO_IRQ -1
#define CSENSE_SDO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CSENSE_SDO_IRQ_TYPE "NONE"
#define CSENSE_SDO_NAME "/dev/csense_sdo"
#define CSENSE_SDO_RESET_VALUE 0x0
#define CSENSE_SDO_SPAN 16
#define CSENSE_SDO_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK TIMESTAMP_TIMER_1


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x40410e0
#define JTAG_UART_0_IRQ 8
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * mbc_addr_bus configuration
 *
 */

#define ALT_MODULE_CLASS_mbc_addr_bus altera_avalon_pio
#define MBC_ADDR_BUS_BASE 0x4041060
#define MBC_ADDR_BUS_BIT_CLEARING_EDGE_REGISTER 0
#define MBC_ADDR_BUS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define MBC_ADDR_BUS_CAPTURE 0
#define MBC_ADDR_BUS_DATA_WIDTH 5
#define MBC_ADDR_BUS_DO_TEST_BENCH_WIRING 0
#define MBC_ADDR_BUS_DRIVEN_SIM_VALUE 0x0
#define MBC_ADDR_BUS_EDGE_TYPE "NONE"
#define MBC_ADDR_BUS_FREQ 50000000u
#define MBC_ADDR_BUS_HAS_IN 0
#define MBC_ADDR_BUS_HAS_OUT 1
#define MBC_ADDR_BUS_HAS_TRI 0
#define MBC_ADDR_BUS_IRQ -1
#define MBC_ADDR_BUS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MBC_ADDR_BUS_IRQ_TYPE "NONE"
#define MBC_ADDR_BUS_NAME "/dev/mbc_addr_bus"
#define MBC_ADDR_BUS_RESET_VALUE 0x0
#define MBC_ADDR_BUS_SPAN 16
#define MBC_ADDR_BUS_TYPE "altera_avalon_pio"


/*
 * mbc_data_bus configuration
 *
 */

#define ALT_MODULE_CLASS_mbc_data_bus altera_avalon_pio
#define MBC_DATA_BUS_BASE 0x4041070
#define MBC_DATA_BUS_BIT_CLEARING_EDGE_REGISTER 0
#define MBC_DATA_BUS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define MBC_DATA_BUS_CAPTURE 0
#define MBC_DATA_BUS_DATA_WIDTH 8
#define MBC_DATA_BUS_DO_TEST_BENCH_WIRING 0
#define MBC_DATA_BUS_DRIVEN_SIM_VALUE 0x0
#define MBC_DATA_BUS_EDGE_TYPE "NONE"
#define MBC_DATA_BUS_FREQ 50000000u
#define MBC_DATA_BUS_HAS_IN 1
#define MBC_DATA_BUS_HAS_OUT 0
#define MBC_DATA_BUS_HAS_TRI 0
#define MBC_DATA_BUS_IRQ -1
#define MBC_DATA_BUS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MBC_DATA_BUS_IRQ_TYPE "NONE"
#define MBC_DATA_BUS_NAME "/dev/mbc_data_bus"
#define MBC_DATA_BUS_RESET_VALUE 0x0
#define MBC_DATA_BUS_SPAN 16
#define MBC_DATA_BUS_TYPE "altera_avalon_pio"


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 1
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x4020000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "Automatic"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "MAIN"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "Auto"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 1
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 98304u
#define ONCHIP_MEMORY2_0_SPAN 98304
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * spi_0 configuration
 *
 */

#define ALT_MODULE_CLASS_spi_0 altera_avalon_spi
#define SPI_0_BASE 0x4041020
#define SPI_0_CLOCKMULT 1
#define SPI_0_CLOCKPHASE 0
#define SPI_0_CLOCKPOLARITY 0
#define SPI_0_CLOCKUNITS "Hz"
#define SPI_0_DATABITS 32
#define SPI_0_DATAWIDTH 32
#define SPI_0_DELAYMULT "1.0E-9"
#define SPI_0_DELAYUNITS "ns"
#define SPI_0_EXTRADELAY 0
#define SPI_0_INSERT_SYNC 0
#define SPI_0_IRQ 2
#define SPI_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI_0_ISMASTER 1
#define SPI_0_LSBFIRST 0
#define SPI_0_NAME "/dev/spi_0"
#define SPI_0_NUMSLAVES 1
#define SPI_0_PREFIX "spi_"
#define SPI_0_SPAN 32
#define SPI_0_SYNC_REG_DEPTH 2
#define SPI_0_TARGETCLOCK 128000u
#define SPI_0_TARGETSSDELAY "0.0"
#define SPI_0_TYPE "altera_avalon_spi"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x40410e8
#define SYSID_QSYS_0_ID 0
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1353270030
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x4041000
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000u
#define TIMER_0_IRQ 0
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999ull
#define TIMER_0_MULT 0.0010
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000u
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"


/*
 * timestamp_timer_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timestamp_timer_1 altera_avalon_timer
#define TIMESTAMP_TIMER_1_ALWAYS_RUN 0
#define TIMESTAMP_TIMER_1_BASE 0x4041040
#define TIMESTAMP_TIMER_1_COUNTER_SIZE 32
#define TIMESTAMP_TIMER_1_FIXED_PERIOD 0
#define TIMESTAMP_TIMER_1_FREQ 50000000u
#define TIMESTAMP_TIMER_1_IRQ -1
#define TIMESTAMP_TIMER_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TIMESTAMP_TIMER_1_LOAD_VALUE 49999ull
#define TIMESTAMP_TIMER_1_MULT 0.0010
#define TIMESTAMP_TIMER_1_NAME "/dev/timestamp_timer_1"
#define TIMESTAMP_TIMER_1_PERIOD 1
#define TIMESTAMP_TIMER_1_PERIOD_UNITS "ms"
#define TIMESTAMP_TIMER_1_RESET_OUTPUT 0
#define TIMESTAMP_TIMER_1_SNAPSHOT 1
#define TIMESTAMP_TIMER_1_SPAN 32
#define TIMESTAMP_TIMER_1_TICKS_PER_SEC 1000u
#define TIMESTAMP_TIMER_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMESTAMP_TIMER_1_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
