/*
 * Copyright (c) 2023 Trackunit Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_SENSOR_BMI323_BMI323_H_
#define ZEPHYR_DRIVERS_SENSOR_BMI323_BMI323_H_

#include <zephyr/sys/util.h>
#include <zephyr/types.h>

#define IMU_BOSCH_BMI323_REG_ACC_DATA_X (0x03)
#define IMU_BOSCH_BMI323_REG_ACC_DATA_Y (0x04)
#define IMU_BOSCH_BMI323_REG_ACC_DATA_Z (0x05)

#define IMU_BOSCH_BMI323_REG_GYRO_DATA_X (0x06)
#define IMU_BOSCH_BMI323_REG_GYRO_DATA_Y (0x07)
#define IMU_BOSCH_BMI323_REG_GYRO_DATA_Z (0x08)

#define IMU_BOSCH_BMI323_REG_TEMP_DATA (0x09)

#define IMU_BOSCH_BMI323_REG_FEATURE_IO0 (0x10)

#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_X_EN_OFFSET  (0x03)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_X_EN_SIZE    (0x01)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_X_EN_VAL_DIS (0x00)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_X_EN_VAL_EN  (0x01)

#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_Y_EN_OFFSET  (0x04)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_Y_EN_SIZE    (0x01)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_Y_EN_VAL_DIS (0x00)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_Y_EN_VAL_EN  (0x01)

#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_Z_EN_OFFSET  (0x05)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_Z_EN_SIZE    (0x01)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_Z_EN_VAL_DIS (0x00)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO0_MOTION_Z_EN_VAL_EN  (0x01)

#define IMU_BOSCH_BMI323_REG_FEATURE_IO2 (0x12)

#define IMU_BOSCH_BMI323_REG_FEATURE_IO_STATUS (0x14)

#define IMU_BOSCH_BMI323_REG_FEATURE_IO_STATUS_STATUS_OFFSET  (0x00)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO_STATUS_STATUS_SIZE    (0x01)
#define IMU_BOSCH_BMI323_REG_FEATURE_IO_STATUS_STATUS_VAL_SET (0x01)

#define IMU_BOSCH_BMI323_REG_INT_STATUS_INT1 (0x0D)
#define IMU_BOSCH_BMI323_REG_INT_STATUS_INT2 (0x0E)

#define IMU_BOSCH_BMI323_REG_ACC_CONF (0x20)

#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_OFFSET	(0x00)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_SIZE		(0x04)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ0P78125 (0x01)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ1P5625	(0x02)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ3P125	(0x03)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ6P25	(0x04)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ12P5	(0x05)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ25	(0x06)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ50	(0x07)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ100	(0x08)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ200	(0x09)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ400	(0x0A)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ800	(0x0B)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ1600	(0x0C)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ3200	(0x0D)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_ODR_VAL_HZ6400	(0x0E)

#define IMU_BOSCH_BMI323_REG_ACC_CONF_RANGE_OFFSET  (0x04)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_RANGE_SIZE    (0x03)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_RANGE_VAL_G2  (0x00)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_RANGE_VAL_G4  (0x01)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_RANGE_VAL_G8  (0x02)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_RANGE_VAL_G16 (0x03)

#define IMU_BOSCH_BMI323_REG_ACC_CONF_MODE_OFFSET   (0x0C)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_MODE_SIZE	    (0x03)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_MODE_VAL_DIS  (0x00)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_MODE_VAL_LPWR (0x04)
#define IMU_BOSCH_BMI323_REG_ACC_CONF_MODE_VAL_HPWR (0x07)

#define IMU_BOSCH_BMI323_REG_GYRO_CONF (0x21)

#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_OFFSET	 (0x00)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_SIZE		 (0x04)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ0P78125 (0x01)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ1P5625	 (0x02)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ3P125	 (0x03)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ6P25	 (0x04)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ12P5	 (0x05)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ25	 (0x06)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ50	 (0x07)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ100	 (0x08)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ200	 (0x09)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ400	 (0x0A)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ800	 (0x0B)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ1600	 (0x0C)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ3200	 (0x0D)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_ODR_VAL_HZ6400	 (0x0E)

#define IMU_BOSCH_BMI323_REG_GYRO_CONF_RANGE_OFFSET	 (0x04)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_RANGE_SIZE	 (0x03)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_RANGE_VAL_DPS125	 (0x00)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_RANGE_VAL_DPS250	 (0x01)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_RANGE_VAL_DPS500	 (0x02)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_RANGE_VAL_DPS1000 (0x03)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_RANGE_VAL_DPS2000 (0x04)

#define IMU_BOSCH_BMI323_REG_GYRO_CONF_MODE_OFFSET   (0x0C)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_MODE_SIZE     (0x03)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_MODE_VAL_DIS  (0x00)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_MODE_VAL_LPWR (0x04)
#define IMU_BOSCH_BMI323_REG_GYRO_CONF_MODE_VAL_HPWR (0x07)

#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL (0x38)

#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_LVL_OFFSET	(0x00)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_LVL_SIZE		(0x01)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_LVL_VAL_ACT_LOW	(0x00)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_LVL_VAL_ACT_HIGH	(0x01)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_OD_OFFSET		(0x01)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_OD_SIZE		(0x01)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_OD_VAL_PUSH_PULL	(0x00)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_OD_VAL_OPEN_DRAIN (0x01)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_OUTPUT_EN_OFFSET	(0x02)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_OUTPUT_EN_SIZE	(0x01)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_OUTPUT_EN_VAL_DIS (0x00)
#define IMU_BOSCH_BMI323_REG_IO_INT_CTRL_INT1_OUTPUT_EN_VAL_EN	(0x01)

#define IMU_BOSCH_BMI323_REG_INT_CONF (0x39)

#define IMU_BOSCH_BMI323_REG_INT_CONF_INT_LATCH_OFFSET		(0x01)
#define IMU_BOSCH_BMI323_REG_INT_CONF_INT_LATCH_SIZE		(0x01)
#define IMU_BOSCH_BMI323_REG_INT_CONF_INT_LATCH_VAL_NON_LATCHED (0x00)
#define IMU_BOSCH_BMI323_REG_INT_CONF_INT_LATCH_VAL_LATCHED	(0x01)

#define IMU_BOSCH_BMI323_REG_INT_MAP1 (0x3A)

#define IMU_BOSCH_BMI323_REG_INT_MAP1_MOTION_OUT_OFFSET	  (0x02)
#define IMU_BOSCH_BMI323_REG_INT_MAP1_MOTION_OUT_SIZE	  (0x02)
#define IMU_BOSCH_BMI323_REG_INT_MAP1_MOTION_OUT_VAL_DIS  (0x00)
#define IMU_BOSCH_BMI323_REG_INT_MAP1_MOTION_OUT_VAL_INT1 (0x01)
#define IMU_BOSCH_BMI323_REG_INT_MAP1_MOTION_OUT_VAL_INT2 (0x02)

#define IMU_BOSCH_BMI323_REG_INT_MAP2 (0x3B)

#define IMU_BOSCH_BMI323_REG_INT_MAP2_ACC_DRDY_INT_OFFSET   (0x0A)
#define IMU_BOSCH_BMI323_REG_INT_MAP2_ACC_DRDY_INT_SIZE	    (0x02)
#define IMU_BOSCH_BMI323_REG_INT_MAP2_ACC_DRDY_INT_VAL_DIS  (0x00)
#define IMU_BOSCH_BMI323_REG_INT_MAP2_ACC_DRDY_INT_VAL_INT1 (0x01)
#define IMU_BOSCH_BMI323_REG_INT_MAP2_ACC_DRDY_INT_VAL_INT2 (0x02)

#define IMU_BOSCH_BMI323_REG_FEATURE_CTRL (0x40)

#define IMU_BOSCH_BMI323_REG_FEATURE_CTRL_ENABLE_OFFSET	 (0x00)
#define IMU_BOSCH_BMI323_REG_FEATURE_CTRL_ENABLE_SIZE	 (0x01)
#define IMU_BOSCH_BMI323_REG_FEATURE_CTRL_ENABLE_VAL_DIS (0x00)
#define IMU_BOSCH_BMI323_REG_FEATURE_CTRL_ENABLE_VAL_EN	 (0x01)

#define IMU_BOSCH_BMI323_REG_CMD		    (0x7E)
#define IMU_BOSCH_BMI323_REG_CMD_CMD_OFFSET	    (0x00)
#define IMU_BOSCH_BMI323_REG_CMD_CMD_SIZE	    (0x10)
#define IMU_BOSCH_BMI323_REG_CMD_CMD_VAL_SOFT_RESET (0xDEAF)

#define IMU_BOSCH_BMI323_REG_MASK(reg, field)                                                      \
	(BIT_MASK(IMU_BOSCH_BMI323_REG_##reg##_##field##_SIZE)                                     \
	 << IMU_BOSCH_BMI323_REG_##reg##_##field##_OFFSET)

#define IMU_BOSCH_BMI323_REG_VALUE(reg, field, val)                                                \
	(IMU_BOSCH_BMI323_REG_##reg##_##field##_VAL_##val                                          \
	 << IMU_BOSCH_BMI323_REG_##reg##_##field##_OFFSET)

#define IMU_BOSCH_BMI323_REG_VALUE_GET_FIELD(reg_value, reg, field)                                \
	((reg_value >> IMU_BOSCH_BMI323_REG_##reg##_##field##_OFFSET) &                            \
	 BIT_MASK(IMU_BOSCH_BMI323_REG_##reg##_##field##_SIZE))

struct bosch_bmi323_bus_api {
	/* Read up to multiple words from the BMI323 */
	int (*read_words)(const void *context, uint8_t offset, uint16_t *words,
			  uint16_t words_count);

	/* Write up to multiple words to the BLI323 */
	int (*write_words)(const void *context, uint8_t offset, uint16_t *words,
			   uint16_t words_count);

	/* Initialize the bus */
	int (*init)(const void *context);
};

struct bosch_bmi323_bus {
	const void *context;
	const struct bosch_bmi323_bus_api *api;
};

#endif /* ZEPHYR_DRIVERS_SENSOR_BMI323_BMI323_H_ */
