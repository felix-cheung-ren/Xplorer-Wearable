/*
 * lsm6dsv320x_reg_interface.h
 *
 *  Created on: Aug 5, 2026
 *      Author: a5163560
 */

#ifndef LSM6DSV320X_LSM6DSV320X_REG_INTERFACE_H_
#define LSM6DSV320X_LSM6DSV320X_REG_INTERFACE_H_

#include "hal_data.h"
#include "lsm6dsv320x_reg.h"

extern stmdev_ctx_t dev_ctx;

void lsm6dsv320x_interface_init(void);

int32_t lsm6dsv320x_stpcnt_init(void);

int32_t lsm6dsv320x_free_fall_init(void);

int32_t lsm6dsv320x_sflp_init(void);

/* This is a helper function used directly and only to respond to webpage requests */
extern int32_t lsm6dsv320x_sflp_get(void);

/**
 * @brief  Write generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to write
 * @param  bufp      pointer to data to write in register reg
 * @param  len       number of consecutive register to write
 *
 */
int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len);

/**
 * @brief  Read generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to read
 * @param  bufp      pointer to buffer that store the data read
 * @param  len       number of consecutive register to read
 *
 */
int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);

/**
 * @brief  platform specific delay (platform dependent)
 *
 * @param  ms        delay in ms
 */
void platform_delay(uint32_t ms);



#endif /* LSM6DSV320X_LSM6DSV320X_REG_INTERFACE_H_ */
