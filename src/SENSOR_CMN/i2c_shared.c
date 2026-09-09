/*
 * i2c_shared.c
 *
 *  Created on: Aug 6, 2026
 *      Author: a5163560
 */

#include "i2c_shared.h"
#include "MAX30102/driver_max30102_interface.h"

/* Reading I2C call back event through i2c_Master callback */
volatile i2c_master_event_t g_i2c_callback_event = I2C_MASTER_EVENT_ABORTED;

/*******************************************************************************************************************//**
 *  @brief      User callback function
 *  @param[in]  p_args
 *  @retval None
 **********************************************************************************************************************/
void i2c_master0_callback(i2c_master_callback_args_t *p_args)
{
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	/* Store I2C transaction status */
    g_i2c_callback_event = p_args->event;

    /* Unblock and check priorities */
    xSemaphoreGiveFromISR(g_i2c_complete_sem, &xHigherPriorityTaskWoken);

    /* Switch to the highest priority task * */
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
