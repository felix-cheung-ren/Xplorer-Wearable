#include "Display.h"
#include "GC9A01/lvgl/src/misc/lv_log.h"
#include "GC9A01/lv_port_disp.h"
#include "GC9A01/lvgl/examples/anim/lv_example_anim.h"
#include "UTILS/common_utils.h"

static uint32_t lv_tick_get_ms(void)
{
	return (uint32_t)pdTICKS_TO_MS(xTaskGetTickCount());
}

static void lv_log_print(lv_log_level_t level, const char *buf)
{
    FSP_PARAMETER_NOT_USED(level);
    APP_PRINT("%s", buf);
}

/* Display entry function */
/* pvParameters contains TaskHandle_t */
void Display_entry(void *pvParameters) {
	FSP_PARAMETER_NOT_USED(pvParameters);

	fsp_err_t err;

	/* Wait a bit for everything else to startup */
	vTaskDelay(pdMS_TO_TICKS(20000));

	APP_PRINT("lcd thread start\n");

	err = R_SPI_W_Open(&g_spi_w0_ctrl, &g_spi_w0_cfg);
	if (FSP_SUCCESS != err) { APP_PRINT("SPI open for lcd failed"); }

	lv_init();

	lv_log_register_print_cb(lv_log_print);

	lv_tick_set_cb(lv_tick_get_ms);

	lv_port_disp_init();

	lv_example_anim_2();
//	lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x00FF00), 0);

	while (1) {
		lv_timer_handler();
		vTaskDelay(pdMS_TO_TICKS(5));
	}
}
