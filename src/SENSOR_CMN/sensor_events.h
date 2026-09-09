/*
 * sensor_events.h
 *
 *  Created on: Aug 7, 2026
 *      Author: a5163560
 */

#ifndef SENSOR_EVENTS_H_
#define SENSOR_EVENTS_H_

#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"

#define SENSOR_NOTIFY_MAX30102    (1UL << 0)
#define SENSOR_NOTIFY_LSM6DSV     (1UL << 1)

extern TaskHandle_t g_data_processing_task_handle;

extern volatile int32_t g_heart_rate;
extern volatile float g_spo2;
extern volatile float g_ratio;
extern volatile float g_correl;

extern volatile int16_t g_step_count;
extern volatile int16_t g_fall_count;
extern volatile float g_quaternions[4];

#endif /* SENSOR_EVENTS_H_ */
