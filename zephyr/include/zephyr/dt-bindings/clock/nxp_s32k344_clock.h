/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_CLOCK_NXP_S32K344_CLOCK_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_CLOCK_NXP_S32K344_CLOCK_H_

#define NXP_S32_FIRC_CLK                           1U
#define NXP_S32_FIRC_STANDBY_CLK                   2U
#define NXP_S32_SIRC_CLK                           3U
#define NXP_S32_SIRC_STANDBY_CLK                   4U
#define NXP_S32_FXOSC_CLK                          5U
#define NXP_S32_SXOSC_CLK                          6U
#define NXP_S32_PLL_CLK                            7U
#define NXP_S32_PLL_POSTDIV_CLK                    8U
#define NXP_S32_PLL_PHI0_CLK                       9U
#define NXP_S32_PLL_PHI1_CLK                       10U
#define NXP_S32_EMAC_MII_RX_CLK                    11U
#define NXP_S32_EMAC_MII_RMII_TX_CLK               12U
#define NXP_S32_SCS_CLK                            13U
#define NXP_S32_CORE_CLK                           14U
#define NXP_S32_AIPS_PLAT_CLK                      15U
#define NXP_S32_AIPS_SLOW_CLK                      16U
#define NXP_S32_HSE_CLK                            17U
#define NXP_S32_DCM_CLK                            18U
#define NXP_S32_LBIST_CLK                          19U
#define NXP_S32_QSPI_MEM_CLK                       20U
#define NXP_S32_CLKOUT_RUN_CLK                     21U
#define NXP_S32_ADC0_CLK                           23U
#define NXP_S32_ADC1_CLK                           24U
#define NXP_S32_ADC2_CLK                           25U
#define NXP_S32_BCTU0_CLK                          26U
#define NXP_S32_CLKOUT_STANDBY_CLK                 27U
#define NXP_S32_CMP0_CLK                           28U
#define NXP_S32_CMP1_CLK                           29U
#define NXP_S32_CMP2_CLK                           30U
#define NXP_S32_CRC0_CLK                           31U
#define NXP_S32_DCM0_CLK                           32U
#define NXP_S32_DMAMUX0_CLK                        33U
#define NXP_S32_DMAMUX1_CLK                        34U
#define NXP_S32_EDMA0_CLK                          35U
#define NXP_S32_EDMA0_TCD0_CLK                     36U
#define NXP_S32_EDMA0_TCD1_CLK                     37U
#define NXP_S32_EDMA0_TCD2_CLK                     38U
#define NXP_S32_EDMA0_TCD3_CLK                     39U
#define NXP_S32_EDMA0_TCD4_CLK                     40U
#define NXP_S32_EDMA0_TCD5_CLK                     41U
#define NXP_S32_EDMA0_TCD6_CLK                     42U
#define NXP_S32_EDMA0_TCD7_CLK                     43U
#define NXP_S32_EDMA0_TCD8_CLK                     44U
#define NXP_S32_EDMA0_TCD9_CLK                     45U
#define NXP_S32_EDMA0_TCD10_CLK                    46U
#define NXP_S32_EDMA0_TCD11_CLK                    47U
#define NXP_S32_EDMA0_TCD12_CLK                    48U
#define NXP_S32_EDMA0_TCD13_CLK                    49U
#define NXP_S32_EDMA0_TCD14_CLK                    50U
#define NXP_S32_EDMA0_TCD15_CLK                    51U
#define NXP_S32_EDMA0_TCD16_CLK                    52U
#define NXP_S32_EDMA0_TCD17_CLK                    53U
#define NXP_S32_EDMA0_TCD18_CLK                    54U
#define NXP_S32_EDMA0_TCD19_CLK                    55U
#define NXP_S32_EDMA0_TCD20_CLK                    56U
#define NXP_S32_EDMA0_TCD21_CLK                    57U
#define NXP_S32_EDMA0_TCD22_CLK                    58U
#define NXP_S32_EDMA0_TCD23_CLK                    59U
#define NXP_S32_EDMA0_TCD24_CLK                    60U
#define NXP_S32_EDMA0_TCD25_CLK                    61U
#define NXP_S32_EDMA0_TCD26_CLK                    62U
#define NXP_S32_EDMA0_TCD27_CLK                    63U
#define NXP_S32_EDMA0_TCD28_CLK                    64U
#define NXP_S32_EDMA0_TCD29_CLK                    65U
#define NXP_S32_EDMA0_TCD30_CLK                    66U
#define NXP_S32_EDMA0_TCD31_CLK                    67U
#define NXP_S32_EIM_CLK                            68U
#define NXP_S32_EMAC_RX_CLK                        69U
#define NXP_S32_EMAC0_RX_CLK                       70U
#define NXP_S32_EMAC_TS_CLK                        71U
#define NXP_S32_EMAC0_TS_CLK                       72U
#define NXP_S32_EMAC_TX_CLK                        73U
#define NXP_S32_EMAC0_TX_CLK                       74U
#define NXP_S32_EMIOS0_CLK                         75U
#define NXP_S32_EMIOS1_CLK                         76U
#define NXP_S32_EMIOS2_CLK                         77U
#define NXP_S32_ERM0_CLK                           78U
#define NXP_S32_FLEXCANA_CLK                       79U
#define NXP_S32_FLEXCAN0_CLK                       80U
#define NXP_S32_FLEXCAN1_CLK                       81U
#define NXP_S32_FLEXCAN2_CLK                       82U
#define NXP_S32_FLEXCANB_CLK                       83U
#define NXP_S32_FLEXCAN3_CLK                       84U
#define NXP_S32_FLEXCAN4_CLK                       85U
#define NXP_S32_FLEXCAN5_CLK                       86U
#define NXP_S32_FLEXIO0_CLK                        87U
#define NXP_S32_INTM_CLK                           88U
#define NXP_S32_LCU0_CLK                           89U
#define NXP_S32_LCU1_CLK                           90U
#define NXP_S32_LPI2C0_CLK                         91U
#define NXP_S32_LPI2C1_CLK                         92U
#define NXP_S32_LPSPI0_CLK                         93U
#define NXP_S32_LPSPI1_CLK                         94U
#define NXP_S32_LPSPI2_CLK                         95U
#define NXP_S32_LPSPI3_CLK                         96U
#define NXP_S32_LPSPI4_CLK                         97U
#define NXP_S32_LPSPI5_CLK                         98U
#define NXP_S32_LPUART0_CLK                        99U
#define NXP_S32_LPUART1_CLK                        100U
#define NXP_S32_LPUART2_CLK                        101U
#define NXP_S32_LPUART3_CLK                        102U
#define NXP_S32_LPUART4_CLK                        103U
#define NXP_S32_LPUART5_CLK                        104U
#define NXP_S32_LPUART6_CLK                        105U
#define NXP_S32_LPUART7_CLK                        106U
#define NXP_S32_LPUART8_CLK                        107U
#define NXP_S32_LPUART9_CLK                        108U
#define NXP_S32_LPUART10_CLK                       109U
#define NXP_S32_LPUART11_CLK                       110U
#define NXP_S32_LPUART12_CLK                       111U
#define NXP_S32_LPUART13_CLK                       112U
#define NXP_S32_LPUART14_CLK                       113U
#define NXP_S32_LPUART15_CLK                       114U
#define NXP_S32_MSCM_CLK                           115U
#define NXP_S32_MU2A_CLK                           116U
#define NXP_S32_MU2B_CLK                           117U
#define NXP_S32_PIT0_CLK                           118U
#define NXP_S32_PIT1_CLK                           119U
#define NXP_S32_PIT2_CLK                           120U
#define NXP_S32_QSPI0_CLK                          121U
#define NXP_S32_QSPI0_RAM_CLK                      122U
#define NXP_S32_QSPI0_TX_MEM_CLK                   123U
#define NXP_S32_QSPI_SFCK_CLK                      124U
#define NXP_S32_RTC_CLK                            125U
#define NXP_S32_RTC0_CLK                           126U
#define NXP_S32_SAI0_CLK                           127U
#define NXP_S32_SAI1_CLK                           128U
#define NXP_S32_SEMA42_CLK                         129U
#define NXP_S32_SIUL2_CLK                          130U
#define NXP_S32_STCU0_CLK                          131U
#define NXP_S32_STMA_CLK                           132U
#define NXP_S32_STM0_CLK                           133U
#define NXP_S32_STMB_CLK                           134U
#define NXP_S32_STM1_CLK                           135U
#define NXP_S32_SWT0_CLK                           136U
#define NXP_S32_TEMPSENSE_CLK                      137U
#define NXP_S32_TRACE_CLK                          138U
#define NXP_S32_TRGMUX0_CLK                        139U
#define NXP_S32_TSENSE0_CLK                        140U
#define NXP_S32_WKPU0_CLK                          141U

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_CLOCK_NXP_S32K344_CLOCK_H_ */
