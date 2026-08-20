#include <MAX30102.h>
#include "MAX30102/driver_max30102.h"
#include "MAX30102/driver_max30102_interface.h"
#include "MAX30102/MAX30102_data.h"
#include "common_data.h"
#include "sensor_events.h"

/* MAX30102 shared data for processing */
volatile uint32_t g_algo_red[ALGO_BUFFER_SIZE];
volatile uint32_t g_algo_ir[ALGO_BUFFER_SIZE];
volatile uint16_t g_algo_count = 0;

/* MAX30102 handle */
max30102_handle_t g_max30102_handle;

/* Raw sample buffers */
static uint32_t gs_raw_red[32];
static uint32_t gs_raw_ir[32];

/* pvParameters contains TaskHandle_t */
void MAX30102_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    uint8_t res;
    uint8_t len;

    /* Main loop */
    while (1)
    {
        if (g_max30102_irq_fired != 0)
        {
            g_max30102_irq_fired = 0;
            max30102_irq_handler(&g_max30102_handle);
        }

        if (g_max30102_fifo_ready != 0) /* Checks for specific flag set by max30102_irq_handler() */
        {
            g_max30102_fifo_ready = 0;

            len = 32;
            res = max30102_read(&g_max30102_handle, gs_raw_red, gs_raw_ir, &len);
            // max30102_interface_debug_print("MAX read: res=%d len=%u\n", res, len);

            if (res == 0)
            {
                // for (uint8_t i = 0; i < len; i++) max30102_interface_debug_print("RED: %lu  IR: %lu\n", gs_raw_red[i], gs_raw_ir[i]);

                /* Keep filling shared buffer for processing */
                for (uint8_t i = 0; i < len && g_algo_count < ALGO_BUFFER_SIZE; i++)
                {
                    g_algo_red[g_algo_count] = gs_raw_red[i];
                    g_algo_ir[g_algo_count]  = gs_raw_ir[i];
                    g_algo_count++;
                }

                /* Hand off to processing when algorithm buffer is full */
                if (g_algo_count >= ALGO_BUFFER_SIZE)
                {
                    g_algo_count = 0;
                    xTaskNotify(g_data_processing_task_handle, SENSOR_NOTIFY_MAX30102, eSetBits);
                }
            }
            else
            {
                max30102_interface_debug_print("max30102: read failed.\n");
            }

        }
        vTaskDelay(1);
    }
}
