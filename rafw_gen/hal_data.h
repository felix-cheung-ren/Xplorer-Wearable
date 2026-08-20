/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_i2c_master_w.h"
#include "r_i2c_master_api.h"
#include "r_uart_w.h"
#include "r_uart_api.h"
#include "../ra/fsp/src/rm_comms_lock/rm_comms_lock.h"
#include "rm_comms_uart_w.h"
#include "rm_comms_api.h"
#include "r_rtc_w.h"
#include "rm_wifi.h"
FSP_HEADER
/* I2C Master on I2C Instance. */
extern const i2c_master_instance_t g_i2c_master0;

/** Access the I2C Master instance using these structures when calling API functions directly (::p_api is not used). */
extern i2c_master_w_instance_ctrl_t g_i2c_master0_ctrl;
extern const i2c_master_cfg_t g_i2c_master0_cfg;

#ifndef i2c_master0_callback
void i2c_master0_callback(i2c_master_callback_args_t *p_args);
#endif
/** UART_W Instance. */
extern const uart_instance_t g_uart0;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern uart_w_instance_ctrl_t g_uart0_ctrl;
extern const uart_cfg_t g_uart0_cfg;
extern const uart_w_extended_cfg_t g_uart0_cfg_extend;

#ifndef NULL
void NULL(uart_callback_args_t *p_args);
#endif
/* UART Communication Device */
extern const rm_comms_instance_t g_comms_stdio_w;
extern rm_comms_uart_w_instance_ctrl_t g_comms_stdio_w_ctrl;
extern rm_comms_cfg_t g_comms_stdio_w_cfg;

#ifndef NULL
void NULL(rm_comms_callback_args_t *p_args);
#endif

/** Access the Watchdog Service instance using these structures when calling API functions directly (::p_api is not used). */
extern const wifi_cfg_t g_wifi_cfg;
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
