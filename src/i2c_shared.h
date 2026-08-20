/*
 * i2c_shared.h
 *
 *  Created on: Aug 5, 2026
 *      Author: a5163560
 */

#ifndef I2C_SHARED_H_
#define I2C_SHARED_H_

#include "hal_data.h"

/* Needed for FSP's nonblocking read/write */

#define I2C_TRANSACTION_BUSY_DELAY 500

extern volatile i2c_master_event_t g_i2c_callback_event;

void i2c_master0_callback(i2c_master_callback_args_t *p_args);

#endif /* I2C_SHARED_H_ */
