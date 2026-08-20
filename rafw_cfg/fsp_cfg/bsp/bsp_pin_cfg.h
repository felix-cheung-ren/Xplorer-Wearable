/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_gpio_w.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define ADC_WAKEUP_PIN (BSP_IO_PORT_00_PIN_06)
#define EXT_INTR0_PIN (BSP_IO_PORT_00_PIN_11)
#define EXT_INTR2_PIN (BSP_IO_PORT_00_PIN_12)
#define EXT_INTR1_PIN (BSP_IO_PORT_00_PIN_13)
#define BSP_GPIO_LED_0 (BSP_IO_PORT_01_PIN_00)
#define BSP_GPIO_LED_1 (BSP_IO_PORT_01_PIN_01)
#define BSP_GPIO_LED_2 (BSP_IO_PORT_01_PIN_02)
#define BSP_GPIO_LED_3 (BSP_IO_PORT_01_PIN_03)
#define LED0 (BSP_IO_PORT_01_PIN_14)

extern const ioport_cfg_t g_bsp_pin_cfg; /* RRQ61xxx-EVB */
#if !defined(BSP_MCU_GROUP_RA6W1) //TIN-TODO
extern gpio_w_extended_cfg_t g_bsp_pin_cfg_extd; /* RRQ61xxx-EVB_extd */
#endif

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER
#endif /* BSP_PIN_CFG_H_ */
