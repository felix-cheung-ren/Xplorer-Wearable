#include "Data_Processing.h"
#include "MAX30102/driver_max30102_interface.h"
#include "MAX30102/algorithm_by_RF.h"
#include "MAX30102/MAX30102_data.h"
#include "LSM6DSV320X/lsm6dsv320x_reg_interface.h"
#include "sensor_events.h"
#include <math.h>

/* Globals to be passed into JSON */
volatile float g_spo2 = 0.0f, g_ratio = 0.0f, g_correl = 0.0f;
volatile int32_t g_heart_rate = 0;

volatile int16_t g_step_count = 0;
volatile int16_t g_fall_count = 0;

/* Handle used to notify this task */
TaskHandle_t g_data_processing_task_handle;

/* Data_Processing entry function */
/* pvParameters contains TaskHandle_t */
void Data_Processing_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    int32_t err;

    g_data_processing_task_handle = xTaskGetCurrentTaskHandle();

    /* Wait a bit for server setup */
    vTaskDelay(pdMS_TO_TICKS(10000));

    /* Unified open for the I2C bus */
    err = R_I2C_MASTER_W_Open(&g_i2c_master0_ctrl, &g_i2c_master0_cfg);
    if (err != FSP_SUCCESS) { max30102_interface_debug_print("I2C open failed: 0x%x\n"); while (1); }
    else { max30102_interface_debug_print("I2C open successful\n"); }

    /* Initialize max30102 here */
    max30102_interface_init();
    max30102_interface_debug_print("max30102: initialized.\n");

    /* Initialize lsm6dsv320x here */
    lsm6dsv320x_interface_init();
    max30102_interface_debug_print("lsm6dsv320x: initialized.\n");

    /* MAX30102 */
    float spo2, ratio, correl;
    int32_t heart_rate; int8_t spo2_valid, hr_valid;

    /* LSM6DSV320X */
    uint16_t step_count;

    while (1)
    {
        uint32_t notifications;
        xTaskNotifyWait(0, UINT32_MAX, &notifications, portMAX_DELAY);

        if (notifications & SENSOR_NOTIFY_MAX30102) /* Run once max algorithm buffer is ready/full */
        {
            rf_heart_rate_and_oxygen_saturation(
                (uint32_t *)g_algo_ir,
                BUFFER_SIZE,
                (uint32_t *)g_algo_red,
                &spo2, &spo2_valid,
                &heart_rate, &hr_valid,
                &ratio, &correl);
            if (hr_valid && spo2_valid)
            {
                max30102_interface_debug_print("HR: %d BPM  SpO2: %d.%d%%  Ratio: %d.%03d  Correl: %d.%03d\n",
                    (int)heart_rate,
                    (int)spo2, (int)(spo2 * 10) % 10,
                    (int)ratio, (int)(ratio * 1000) % 1000,
                    (int)correl, (int)(correl * 1000) % 1000);

                g_spo2 = spo2;
				g_heart_rate = heart_rate;
				g_ratio = ratio;
				g_correl = correl;
            }
            else
                max30102_interface_debug_print("Processing: invalid signal\n");
        }
        else if (notifications & SENSOR_NOTIFY_LSM6DSV) /* Run once event from lsm int1 is registered */
        {
            lsm6dsv320x_all_sources_t sources = {0};
            lsm6dsv320x_all_sources_get(&dev_ctx, &sources);

            if (sources.step_detector)
            {
                err = lsm6dsv320x_stpcnt_steps_get(&dev_ctx, &step_count);
                if (err != 0) { max30102_interface_debug_print("get step count failed\n"); while(1); }
                g_step_count = step_count;
                max30102_interface_debug_print("Steps: %d\n", (int)step_count);
            }
            if (sources.free_fall)
            {
            	g_fall_count++;
                max30102_interface_debug_print("FREEFALL DETECTED\n");
            }
        }
    }
}

