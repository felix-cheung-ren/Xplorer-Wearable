#include "Display.h"
#include "GC9A01/lvgl/src/misc/lv_log.h"
#include "GC9A01/lv_port_disp.h"
#include "GC9A01/lvgl/examples/anim/lv_example_anim.h"
#include "UTILS/common_utils.h"
#include "ui/ui.h"
#include "SENSOR_CMN/sensor_events.h"
#include "lwip/apps/sntp.h"

#define CURRENT_YEAR        (2026)

static uint32_t lv_tick_get_ms(void)
{
	return (uint32_t)pdTICKS_TO_MS(xTaskGetTickCount());
}

static void lv_log_print(lv_log_level_t level, const char *buf)
{
    FSP_PARAMETER_NOT_USED(level);
    APP_PRINT("%s", buf);
}

TaskHandle_t g_display_task_handle;

/* Display entry function */
/* pvParameters contains TaskHandle_t */
void Display_entry(void *pvParameters) {
	FSP_PARAMETER_NOT_USED(pvParameters);
	fsp_err_t err;

	g_display_task_handle = xTaskGetCurrentTaskHandle();

	/* Wait for display to initialize */
	ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

	lv_init();

	/* Enable in lv_conf.h if logging needed */
	lv_log_register_print_cb(lv_log_print);

	lv_tick_set_cb(lv_tick_get_ms);

	lv_port_disp_init();

	ui_init();

	lv_arc_set_range(ui_ArcSpO2, 0, 100);
	lv_arc_set_range(ui_ArcHeartRate, 0, 140);

	while (1) {
		lv_timer_handler();

		rtc_time_t current_time;
		rtc_ctrl_t *p_rtc_ctrl = R_RTC_W_GetCtrl();
		R_RTC_W_CalendarTimeGet(p_rtc_ctrl, &current_time);
		lv_label_set_text_fmt(ui_LabelHours, "%02d", current_time.tm_hour);
		lv_label_set_text_fmt(ui_LabelMinutes, "%02d", current_time.tm_min);

		lv_label_set_text_fmt(ui_LabelHeartRate, "%ld bpm", g_heart_rate);
		lv_label_set_text_fmt(ui_LabelSpO2, "%d.%d%%", (int)g_spo2, (int)(g_spo2 * 10) % 10);
		lv_label_set_text_fmt(ui_LabelSteps, "%d steps", g_step_count);
		lv_arc_set_value(ui_ArcSpO2, (int32_t)g_spo2);
		lv_arc_set_value(ui_ArcHeartRate, (int32_t)g_heart_rate);

		vTaskDelay(pdMS_TO_TICKS(50));
	}
}
