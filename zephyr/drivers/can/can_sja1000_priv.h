/*
 * Copyright (c) 2022 Henrik Brix Andersen <henrik@brixandersen.dk>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_CAN_SJA1000_PRIV_H_
#define ZEPHYR_DRIVERS_CAN_SJA1000_PRIV_H_

#include <zephyr/sys/util.h>

/* SJA1000 register "CAN addresses", PeliCAN mode */
#define CAN_SJA1000_MOD			     (0U)
#define CAN_SJA1000_CMR			     (1U)
#define CAN_SJA1000_SR			     (2U)
#define CAN_SJA1000_IR			     (3U)
#define CAN_SJA1000_IER			     (4U)
#define CAN_SJA1000_BTR0		     (6U)
#define CAN_SJA1000_BTR1		     (7U)
#define CAN_SJA1000_OCR			     (8U)
#define CAN_SJA1000_ALC			     (11U)
#define CAN_SJA1000_ECC			     (12U)
#define CAN_SJA1000_EWLR		     (13U)
#define CAN_SJA1000_RXERR		     (14U)
#define CAN_SJA1000_TXERR		     (15U)

/* Reset Mode access (acceptance codes/masks) */
#define CAN_SJA1000_ACR0		     (16U)
#define CAN_SJA1000_ACR1		     (17U)
#define CAN_SJA1000_ACR2		     (18U)
#define CAN_SJA1000_ACR3		     (19U)
#define CAN_SJA1000_AMR0		     (20U)
#define CAN_SJA1000_AMR1		     (21U)
#define CAN_SJA1000_AMR2		     (22U)
#define CAN_SJA1000_AMR3		     (23U)

/* Operation Mode access (RX/TX SFF/EFF frame) */
#define CAN_SJA1000_FRAME_INFO		     (16U)
#define CAN_SJA1000_XFF_ID1		     (17U)
#define CAN_SJA1000_XFF_ID2		     (18U)
#define CAN_SJA1000_EFF_ID3		     (19U)
#define CAN_SJA1000_EFF_ID4		     (20U)
#define CAN_SJA1000_SFF_DATA		     (19U)
#define CAN_SJA1000_EFF_DATA		     (21U)

#define CAN_SJA1000_RMC			     (29U)
#define CAN_SJA1000_RBSA		     (30U)
#define CAN_SJA1000_CDR			     (31U)

/* Mode register (MOD) bits */
#define CAN_SJA1000_MOD_RM		     BIT(0)
#define CAN_SJA1000_MOD_LOM		     BIT(1)
#define CAN_SJA1000_MOD_STM		     BIT(2)
#define CAN_SJA1000_MOD_AFM		     BIT(3)
#define CAN_SJA1000_MOD_SM		     BIT(4)

/* Command Register (CMR) bits */
#define CAN_SJA1000_CMR_TR		     BIT(0)
#define CAN_SJA1000_CMR_AT		     BIT(1)
#define CAN_SJA1000_CMR_RRB		     BIT(2)
#define CAN_SJA1000_CMR_CDO		     BIT(3)
#define CAN_SJA1000_CMR_SRR		     BIT(4)

/* Status Register (SR) bits */
#define CAN_SJA1000_SR_RBS		     BIT(0)
#define CAN_SJA1000_SR_DOS		     BIT(1)
#define CAN_SJA1000_SR_TBS		     BIT(2)
#define CAN_SJA1000_SR_TCS		     BIT(3)
#define CAN_SJA1000_SR_RS		     BIT(4)
#define CAN_SJA1000_SR_TS		     BIT(5)
#define CAN_SJA1000_SR_ES		     BIT(6)
#define CAN_SJA1000_SR_BS		     BIT(7)

/* Interrupt Register (IR) bits */
#define CAN_SJA1000_IR_RI		     BIT(0)
#define CAN_SJA1000_IR_TI		     BIT(1)
#define CAN_SJA1000_IR_EI		     BIT(2)
#define CAN_SJA1000_IR_DOI		     BIT(3)
#define CAN_SJA1000_IR_WUI		     BIT(4)
#define CAN_SJA1000_IR_EPI		     BIT(5)
#define CAN_SJA1000_IR_ALI		     BIT(6)
#define CAN_SJA1000_IR_BEI		     BIT(7)

/* Interrupt Enable Register (IER) bits */
#define CAN_SJA1000_IER_RIE		     BIT(0)
#define CAN_SJA1000_IER_TIE		     BIT(1)
#define CAN_SJA1000_IER_EIE		     BIT(2)
#define CAN_SJA1000_IER_DOIE		     BIT(3)
#define CAN_SJA1000_IER_WUIE		     BIT(4)
#define CAN_SJA1000_IER_EPIE		     BIT(5)
#define CAN_SJA1000_IER_ALIE		     BIT(6)
#define CAN_SJA1000_IER_BEIE		     BIT(7)

/* Bus Timing Register 0 (BTR0) bits */
#define CAN_SJA1000_BTR0_BRP_MASK	     GENMASK(5, 0)
#define CAN_SJA1000_BTR0_SJW_MASK	     GENMASK(7, 6)

#define CAN_SJA1000_BTR0_BRP_PREP(brp)	     FIELD_PREP(CAN_SJA1000_BTR0_BRP_MASK, brp)
#define CAN_SJA1000_BTR0_SJW_PREP(sjw)	     FIELD_PREP(CAN_SJA1000_BTR0_SJW_MASK, sjw)

/* Bus Timing Register 1 (BTR1) bits */
#define CAN_SJA1000_BTR1_TSEG1_MASK	     GENMASK(3, 0)
#define CAN_SJA1000_BTR1_TSEG2_MASK	     GENMASK(6, 4)
#define CAN_SJA1000_BTR1_SAM		     BIT(7)

#define CAN_SJA1000_BTR1_TSEG1_PREP(tseg1)   FIELD_PREP(CAN_SJA1000_BTR1_TSEG1_MASK, tseg1)
#define CAN_SJA1000_BTR1_TSEG2_PREP(tseg2)   FIELD_PREP(CAN_SJA1000_BTR1_TSEG2_MASK, tseg2)

/* Error Code Capture register (ECC) bits */
#define CAN_SJA1000_ECC_SEG_MASK	     GENMASK(4, 0)
#define CAN_SJA1000_ECC_DIR		     BIT(5)
#define CAN_SJA1000_ECC_ERRC_MASK	     GENMASK(7, 6)

#define CAN_SJA1000_ECC_ERRC_BIT_ERROR	     FIELD_PREP(CAN_SJA1000_ECC_ERRC_MASK, 0U)
#define CAN_SJA1000_ECC_ERRC_FORM_ERROR	     FIELD_PREP(CAN_SJA1000_ECC_ERRC_MASK, 1U)
#define CAN_SJA1000_ECC_ERRC_STUFF_ERROR     FIELD_PREP(CAN_SJA1000_ECC_ERRC_MASK, 2U)
#define CAN_SJA1000_ECC_ERRC_OTHER_ERROR     FIELD_PREP(CAN_SJA1000_ECC_ERRC_MASK, 3U)

/* RX/TX SFF/EFF Frame Information bits */
#define CAN_SJA1000_FRAME_INFO_DLC_MASK	     GENMASK(3, 0)
#define CAN_SJA1000_FRAME_INFO_RTR	     BIT(6)
#define CAN_SJA1000_FRAME_INFO_FF	     BIT(7)

#define CAN_SJA1000_FRAME_INFO_DLC_PREP(dlc) FIELD_PREP(CAN_SJA1000_FRAME_INFO_DLC_MASK, dlc)
#define CAN_SJA1000_FRAME_INFO_DLC_GET(info) FIELD_GET(CAN_SJA1000_FRAME_INFO_DLC_MASK, info)

#endif /* ZEPHYR_DRIVERS_CAN_SJA1000_PRIV_H_ */
