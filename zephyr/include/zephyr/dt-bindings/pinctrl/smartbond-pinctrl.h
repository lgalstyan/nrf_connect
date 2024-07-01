/*
 * Copyright (c) 2022, Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_SMARTBOND_PINCTRL_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_SMARTBOND_PINCTRL_H_

/** Definitions of pin functions */
#define SMARTBOND_FUNC_GPIO		0
#define SMARTBOND_FUNC_UART_RX		1
#define SMARTBOND_FUNC_UART_TX		2
#define SMARTBOND_FUNC_UART2_RX		3
#define SMARTBOND_FUNC_UART2_TX		4
#define SMARTBOND_FUNC_UART2_CTSN	5
#define SMARTBOND_FUNC_UART2_RTSN	6
#define SMARTBOND_FUNC_UART3_RX		7
#define SMARTBOND_FUNC_UART3_TX		8
#define SMARTBOND_FUNC_UART3_CTSN	9
#define SMARTBOND_FUNC_UART3_RTSN	10
#define SMARTBOND_FUNC_ISO_CLK		11
#define SMARTBOND_FUNC_ISO_DATA		12
#define SMARTBOND_FUNC_SPI_DI		13
#define SMARTBOND_FUNC_SPI_DO		14
#define SMARTBOND_FUNC_SPI_CLK		15
#define SMARTBOND_FUNC_SPI_EN		16
#define SMARTBOND_FUNC_SPI2_DI		17
#define SMARTBOND_FUNC_SPI2_DO		18
#define SMARTBOND_FUNC_SPI2_CLK		19
#define SMARTBOND_FUNC_SPI2_EN		20
#define SMARTBOND_FUNC_I2C_SCL		21
#define SMARTBOND_FUNC_I2C_SDA		22
#define SMARTBOND_FUNC_I2C2_SCL		23
#define SMARTBOND_FUNC_I2C2_SDA		24
#define SMARTBOND_FUNC_USB_SOF		25
#define SMARTBOND_FUNC_ADC		26
#define SMARTBOND_FUNC_USB		27
#define SMARTBOND_FUNC_PCM_DI		28
#define SMARTBOND_FUNC_PCM_DO		29
#define SMARTBOND_FUNC_PCM_FSC		30
#define SMARTBOND_FUNC_PCM_CLK		31
#define SMARTBOND_FUNC_PDM_DATA		32
#define SMARTBOND_FUNC_PDM_CLK		33
#define SMARTBOND_FUNC_COEX_EXT_ACT	34
#define SMARTBOND_FUNC_COEX_SMART_ACT	35
#define SMARTBOND_FUNC_COEX_SMART_PRI	36
#define SMARTBOND_FUNC_PORT0_DCF	37
#define SMARTBOND_FUNC_PORT1_DCF	38
#define SMARTBOND_FUNC_PORT2_DCF	39
#define SMARTBOND_FUNC_PORT3_DCF	40
#define SMARTBOND_FUNC_PORT4_DCF	41
#define SMARTBOND_FUNC_CLOCK		42
#define SMARTBOND_FUNC_PG		43
#define SMARTBOND_FUNC_LCD		44
#define SMARTBOND_FUNC_LCD_SPI_DC	45
#define SMARTBOND_FUNC_LCD_SPI_DO	46
#define SMARTBOND_FUNC_LCD_SPI_CLK	47
#define SMARTBOND_FUNC_LCD_SPI_EN	48
#define SMARTBOND_FUNC_TIM_PWM		49
#define SMARTBOND_FUNC_TIM2_PWM		50
#define SMARTBOND_FUNC_TIM_1SHOT	51
#define SMARTBOND_FUNC_TIM2_1SHOT	52
#define SMARTBOND_FUNC_TIM3_PWM		53
#define SMARTBOND_FUNC_TIM4_PWM		54

/** Definitions of bit positions and bit masks in pinmux */
#define SMARTBOND_PINMUX_PIN_POS	0
#define SMARTBOND_PINMUX_PIN_MASK	0x1f
#define SMARTBOND_PINMUX_PORT_POS	5
#define SMARTBOND_PINMUX_PORT_MASK	0x01
#define SMARTBOND_PINMUX_FUNC_POS	6
#define SMARTBOND_PINMUX_FUNC_MASK	0xff

/** Utility macro to create pinmux */
#define SMARTBOND_PINMUX(func, port, pin)				\
	(((SMARTBOND_FUNC_ ## func) << SMARTBOND_PINMUX_FUNC_POS) |	\
	 ((port) << SMARTBOND_PINMUX_PORT_POS) |			\
	 (pin) << SMARTBOND_PINMUX_PIN_POS)

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_SMARTBOND_PINCTRL_H_ */
