/* generated common header file - do not edit */
#ifndef COMMON_DATA_H_
#define COMMON_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "r_ext_irq_w.h"
#include "r_external_irq_api.h"
#include "r_tim_w.h"
#include "r_timer_api.h"
#include "r_adc_w.h"
#include "r_adc_api.h"
#include "r_i2c_master_w.h"
#include "r_i2c_master_api.h"
#include "r_uart_w.h"
#include "r_uart_api.h"
#include "rm_atcmd_w_app.h"
#include "rm_https_w.h"

#include "rm_pmgr_w_instance.h"
#include "r_ospi_w.h"
#include "r_spi_flash_api.h"
#include "rm_block_media_spi_w.h"
#include "rm_littlefs_api.h"
#include "rm_littlefs_flash_w.h"
#include "lfs_util.h"
#include "lfs_util.h"
#include "rm_atcmd_w_core.h"
#include "rm_atcmd_w_api.h"
#include "rm_atcmd_w_app.h"
#include "rm_vee_flash_w.h"
#include "rm_vee_flash_w_cfg.h"
#include "rm_map_persistant_w.h"
#include "r_wdog_w.h"
#include "rm_watchdog_service_w.h"
#include "rm_watchdog_service_api.h"
#include "mbedtls/platform.h"
#include "psa/crypto.h"
#include "psa/crypto_extra.h"
#if BSP_FEATURE_CRYPTO_HAS_CC312
             #include "rm_psa_crypto_w.h"
            #else
#include "rm_psa_crypto.h"
#endif
#include "rm_lwip_w.h"
#include "r_gpio_w.h"
#include "bsp_pin_cfg.h"
FSP_HEADER
/** External IRQ on EXT_IRQ Instance. */
extern const external_irq_instance_t g_external_irq3;

/** Access the EXT_IRQ instance using these structures when calling API functions directly (::p_api is not used). */
extern ext_irq_w_instance_ctrl_t g_external_irq3_ctrl;
extern const external_irq_cfg_t g_external_irq3_cfg;

#ifndef lsm_irq_callback
void lsm_irq_callback(external_irq_callback_args_t *p_args);
#endif
/** External IRQ on EXT_IRQ Instance. */
extern const external_irq_instance_t g_external_irq0;

/** Access the EXT_IRQ instance using these structures when calling API functions directly (::p_api is not used). */
extern ext_irq_w_instance_ctrl_t g_external_irq0_ctrl;
extern const external_irq_cfg_t g_external_irq0_cfg;

#ifndef max30102_irq_callback
void max30102_irq_callback(external_irq_callback_args_t *p_args);
#endif
/** Timer on TIM_W Instance. */
extern const timer_instance_t g_at_gpt;

/** Access the TIM_W instance using these structures when calling API functions directly (::p_api is not used). */
extern tim_w_instance_ctrl_t g_at_gpt_ctrl;
extern const timer_cfg_t g_at_gpt_cfg;

#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
/** ADC on ADC_W Instance. */
extern const adc_instance_t g_at_adc;
extern adc_w_instance_ctrl_t g_at_adc_ctrl;
extern const adc_cfg_t g_at_adc_cfg;
extern const adc_w_scan_cfg_t g_at_adc_channel_cfg;
#ifndef NULL
void NULL(adc_callback_args_t *p_args);
#endif
/* I2C Master on I2C Instance. */
extern const i2c_master_instance_t g_at_i2c;

/** Access the I2C Master instance using these structures when calling API functions directly (::p_api is not used). */
extern i2c_master_w_instance_ctrl_t g_at_i2c_ctrl;
extern const i2c_master_cfg_t g_at_i2c_cfg;

#ifndef NULL
void NULL(i2c_master_callback_args_t *p_args);
#endif
/** UART_W Instance. */
extern const uart_instance_t g_atcmd_uart;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern uart_w_instance_ctrl_t g_atcmd_uart_ctrl;
extern const uart_cfg_t g_atcmd_uart_cfg;
extern const uart_w_extended_cfg_t g_atcmd_uart_cfg_extend;

#ifndef rm_atcmd_transport_uart_w_cb
void rm_atcmd_transport_uart_w_cb(uart_callback_args_t *p_args);
#endif
extern atcmd_transport_uart_w_instance_ctrl_t g_atcmd_transport_ctrl;
extern atcmd_transport_w_cfg_t g_atcmd_transport_cfg;
extern atcmd_transport_w_instance_t g_atcmd_transport;
/** HTTPS Instance. */
extern const https_instance_t g_https_w0;

/** Access the HTTPS instance using these structures when calling API functions directly (::p_api is not used). */
extern https_w_instance_ctrl_t g_https_w0_ctrl;
extern const https_cfg_t g_https_w0_cfg;

#ifndef g_https0_callback
void g_https0_callback(https_callback_args_t *p_args);
#endif

/** External IRQ on EXT_IRQ Instance. */
extern const external_irq_instance_t g_external_irq2;

/** Access the EXT_IRQ instance using these structures when calling API functions directly (::p_api is not used). */
extern ext_irq_w_instance_ctrl_t g_external_irq2_ctrl;
extern const external_irq_cfg_t g_external_irq2_cfg;

#ifndef NULL
void NULL(external_irq_callback_args_t *p_args);
#endif
/** External IRQ on EXT_IRQ Instance. */
extern const external_irq_instance_t g_external_irq1;

/** Access the EXT_IRQ instance using these structures when calling API functions directly (::p_api is not used). */
extern ext_irq_w_instance_ctrl_t g_external_irq1_ctrl;
extern const external_irq_cfg_t g_external_irq1_cfg;

#ifndef srm_wifi_app_gpio_p0_fr_handler
void srm_wifi_app_gpio_p0_fr_handler(external_irq_callback_args_t *p_args);
#endif
extern const pmgr_instance_t g_pmgr_w_ins;
extern pmgr_instance_ctrl_t g_pmgr_w_ctrl;
extern const pmgr_cfg_t g_pmgr_w_cfg;
extern const spi_flash_instance_t g_ospi_lfs;
extern ospi_w_instance_ctrl_t g_ospi_lfs_ctrl;
extern const spi_flash_cfg_t g_ospi_lfs_cfg;
/* Block Media on SPI Instance */
extern rm_block_media_instance_t g_rm_block_media1;

/* Access the Block Media SPI instance using these structures when calling API functions directly (::p_api is not used). */
extern rm_block_media_spi_w_instance_ctrl_t g_rm_block_media1_ctrl;
extern const rm_block_media_cfg_t g_rm_block_media1_cfg;

#ifndef NULL
void NULL(rm_block_media_callback_args_t *p_args);
#endif
/** LittleFS on Flash Instance. */
extern const rm_littlefs_instance_t g_rm_littlefs0;
extern rm_littlefs_flash_w_instance_ctrl_t g_rm_littlefs0_ctrl;
extern const rm_littlefs_cfg_t g_rm_littlefs0_cfg;

extern struct lfs g_rm_littlefs0_lfs;
extern const struct lfs_config g_rm_littlefs0_lfs_cfg;

extern atcmd_w_cfg_t g_at0_cfg;
/* Block Media on SPI Instance */
extern rm_block_media_instance_t g_rm_block_media0;

/* Access the Block Media SPI instance using these structures when calling API functions directly (::p_api is not used). */
extern rm_block_media_spi_w_instance_ctrl_t g_rm_block_media0_ctrl;
extern const rm_block_media_cfg_t g_rm_block_media0_cfg;

#ifndef rm_vee_media_callback
void rm_vee_media_callback(rm_block_media_callback_args_t *p_args);
#endif
extern const rm_vee_instance_t g_vee0;
extern rm_vee_flash_w_instance_ctrl_t g_vee0_ctrl;
extern const rm_vee_cfg_t g_vee0_cfg;

/** Callback used by VEE Instance. */
#ifndef NULL
void NULL(rm_vee_callback_args_t *p_args);
#endif
extern const map_persistant_w_instance_t g_map_persistant_w_instance;
extern map_persistant_w_instance_ctrl_t g_map_persistant_w_ctrl;
extern const map_persistant_w_cfg_t g_map_persistant_w_cfg;
/** WDT on WDOG_W Instance. */
extern const wdt_instance_t g_wdog_w0;

/** Access the WDOG_W instance using these structures when calling API functions directly (::p_api is not used). */
extern wdog_w_instance_ctrl_t g_wdog_w0_ctrl;
extern const wdt_cfg_t g_wdog_w0_cfg;
extern wdog_w_extended_cfg_t g_wdog_w0_cfg_extend;

#ifndef wdt_callback_default
void wdt_callback_default(wdt_callback_args_t *p_args);
#endif
/** Watchdog Service on Watchdog Service Instance. */
extern const watchdog_service_instance_t g_watchdog_service0;

/** Access the Watchdog Service instance using these structures when calling API functions directly (::p_api is not used). */
extern watchdog_service_w_instance_ctrl_t g_watchdog_service0_ctrl;
extern const watchdog_service_cfg_t g_watchdog_service0_cfg;
/** Access the lwIP instance using these structures when calling API functions directly (::p_api is not used). */
extern const lwip_w_cfg_t g_lwip0_cfg;
#define IOPORT_CFG_NAME g_bsp_pin_cfg
#define IOPORT_CFG_OPEN R_GPIO_W_Open
#define IOPORT_CFG_CTRL g_gpio_w_ctrl

/* GPIO_W Instance */
extern const ioport_instance_t g_gpio_w;

/* GPIO_W control structure. */
extern gpio_w_instance_ctrl_t g_gpio_w_ctrl;
extern SemaphoreHandle_t g_i2c_mutex;
extern SemaphoreHandle_t g_i2c_complete_sem;
void g_common_init(void);
FSP_FOOTER
#endif /* COMMON_DATA_H_ */
