#include "Data_Processing.h"
#include "MAX30102/driver_max30102_interface.h"
#include "MAX30102/algorithm_by_RF.h"
#include "MAX30102/MAX30102_data.h"
#include "LSM6DSV320X/lsm6dsv320x_reg_interface.h"
#include "SENSOR_CMN/sensor_events.h"
#include "UTILS/common_utils.h"
#include <math.h>
#include "hal_data.h"

/* Globals to be passed into JSON/Display */
volatile float g_spo2 = 0.0f, g_ratio = 0.0f, g_correl = 0.0f;
volatile int32_t g_heart_rate = 0;

volatile int16_t g_step_count = 0;
volatile int16_t g_fall_count = 0;

TaskHandle_t g_data_processing_task_handle;

/* Data_Processing entry function */
/* pvParameters contains TaskHandle_t */
void Data_Processing_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    int32_t err;

    g_data_processing_task_handle = xTaskGetCurrentTaskHandle();

    /* Wait a bit for server */
    vTaskDelay(pdMS_TO_TICKS(10000));

    /* Open I2C bus */
    err = R_I2C_MASTER_W_Open(&g_i2c_master0_ctrl, &g_i2c_master0_cfg);
    if (err != FSP_SUCCESS) { APP_PRINT("I2C open failed"); }

    /* Open SPI bus */
	err = R_SPI_W_Open(&g_spi_w0_ctrl, &g_spi_w0_cfg);
	if (FSP_SUCCESS != err) { APP_PRINT("SPI open for lcd failed"); }

    /* Initialize RTC for clock display */
    rtc_ctrl_t *p_rtc_ctrl = R_RTC_W_GetCtrl();
    long timezone = 0;
    R_RTC_W_CalendarTimeZoneSet(p_rtc_ctrl, &timezone);
    rtc_time_t init_time = {
        .tm_sec  = 0,
        .tm_min  = 0,
        .tm_hour = 12,
        .tm_mday = 1,
        .tm_mon  = 0,
        .tm_year = 126,
        .tm_wday = 5
    };
    R_RTC_W_CalendarTimeSet(p_rtc_ctrl, &init_time);

    /* Initialize max30102 here */
    max30102_interface_init();
    APP_PRINT("max30102: initialized.\n");

    /* Initialize lsm6dsv320x here */
    lsm6dsv320x_interface_init();
    APP_PRINT("lsm6dsv320x: initialized.\n");

    /* Notify display task */
    xTaskNotify(g_display_task_handle, 0, eNoAction);

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
            	APP_PRINT("HR: %d BPM  SpO2: %d.%d%%  Ratio: %d.%03d  Correl: %d.%03d\n",
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
            {
            	APP_PRINT("Processing: no valid signal\n");
            }
        }
        else if (notifications & SENSOR_NOTIFY_LSM6DSV) /* Run once event from lsm int1 is registered */
        {
            lsm6dsv320x_all_sources_t sources = {0};
            lsm6dsv320x_all_sources_get(&dev_ctx, &sources);

            if (sources.step_detector)
            {
                err = lsm6dsv320x_stpcnt_steps_get(&dev_ctx, &step_count);
                if (err != 0) { APP_PRINT("get step count failed\n"); while(1); }
                g_step_count = step_count;
                APP_PRINT("Steps: %d\n", (int)step_count);
            }
            if (sources.free_fall)
            {
            	g_fall_count++;
            	APP_PRINT("FREEFALL DETECTED\n");
            }
        }
    }
}

