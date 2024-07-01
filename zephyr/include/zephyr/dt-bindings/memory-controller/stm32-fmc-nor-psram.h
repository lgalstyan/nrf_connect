/*
 * Copyright (c) 2022 Georgij Cernysiov
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_MEMORY_CONTROLLER_STM32_FMC_SRAM_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_MEMORY_CONTROLLER_STM32_FMC_SRAM_H_

/* Data Address Bus Multiplexing */
#define STM32_FMC_DATA_ADDRESS_MUX_DISABLE         0x00000000UL
#define STM32_FMC_DATA_ADDRESS_MUX_ENABLE          0x00000002UL

/* Memory Type */
#define STM32_FMC_MEMORY_TYPE_SRAM                 0x00000000UL
#define STM32_FMC_MEMORY_TYPE_PSRAM                0x00000004UL
#define STM32_FMC_MEMORY_TYPE_NOR                  0x00000008UL

/* NORSRAM Data Width */
#define STM32_FMC_NORSRAM_MEM_BUS_WIDTH_8          0x00000000UL
#define STM32_FMC_NORSRAM_MEM_BUS_WIDTH_16         0x00000010UL
#define STM32_FMC_NORSRAM_MEM_BUS_WIDTH_32         0x00000020UL

/* Burst Access Mode */
#define STM32_FMC_BURST_ACCESS_MODE_DISABLE        0x00000000UL
#define STM32_FMC_BURST_ACCESS_MODE_ENABLE         0x00000100UL

/* Wait Signal Polarity */
#define STM32_FMC_WAIT_SIGNAL_POLARITY_LOW         0x00000000UL
#define STM32_FMC_WAIT_SIGNAL_POLARITY_HIGH        0x00000200UL

/* Wait Timing */
#define STM32_FMC_WAIT_TIMING_BEFORE_WS            0x00000000UL
#define STM32_FMC_WAIT_TIMING_DURING_WS            0x00000800UL

/* Write Operation */
#define STM32_FMC_WRITE_OPERATION_DISABLE          0x00000000UL
#define STM32_FMC_WRITE_OPERATION_ENABLE           0x00001000UL

/* Wait Signal */
#define STM32_FMC_WAIT_SIGNAL_DISABLE              0x00000000UL
#define STM32_FMC_WAIT_SIGNAL_ENABLE               0x00002000UL

/* Extended Mode */
#define STM32_FMC_EXTENDED_MODE_DISABLE            0x00000000UL
#define STM32_FMC_EXTENDED_MODE_ENABLE             0x00004000UL

/* Asynchronous Wait */
#define STM32_FMC_ASYNCHRONOUS_WAIT_DISABLE        0x00000000UL
#define STM32_FMC_ASYNCHRONOUS_WAIT_ENABLE         0x00008000UL

/* Write Burst */
#define STM32_FMC_WRITE_BURST_DISABLE              0x00000000UL
#define STM32_FMC_WRITE_BURST_ENABLE               0x00080000UL

/* Continuous Clock */
#define STM32_FMC_CONTINUOUS_CLOCK_SYNC_ONLY       0x00000000UL
#define STM32_FMC_CONTINUOUS_CLOCK_SYNC_ASYNC      0x00100000UL

/* Write FIFO */
/* Not every SoC can disable FIFO, refer to reference manual */
#define STM32_FMC_WRITE_FIFO_DISABLE               0x00200000UL
#define STM32_FMC_WRITE_FIFO_ENABLE                0x00000000UL

/* Page Size */
#define STM32_FMC_PAGE_SIZE_NONE                   0x00000000UL
#define STM32_FMC_PAGE_SIZE_128                    0x00010000UL
#define STM32_FMC_PAGE_SIZE_256                    0x00020000UL
#define STM32_FMC_PAGE_SIZE_512                    0x00030000UL
#define STM32_FMC_PAGE_SIZE_1024                   0x00040000UL

/* Access Mode */
#define STM32_FMC_ACCESS_MODE_A                    0x00000000UL
#define STM32_FMC_ACCESS_MODE_B                    0x10000000UL
#define STM32_FMC_ACCESS_MODE_C                    0x20000000UL
#define STM32_FMC_ACCESS_MODE_D                    0x30000000UL

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_MEMORY_CONTROLLER_STM32_FMC_SRAM_H_ */
