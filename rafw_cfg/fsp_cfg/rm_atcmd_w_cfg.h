/* generated configuration header file - do not edit */
#ifndef RM_ATCMD_W_CFG_H_
#define RM_ATCMD_W_CFG_H_
#ifdef __cplusplus
            extern "C" {
            #endif

#define ATCMD_W_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#define ATCMD_TRANSPORT_UART_W ((1))
#define ATCMD_TRANSPORT_SPI_W ((0))
#define ATCMD_TRANSPORT_SDIO_W ((0))
#define ATCMD_RF_TEST_SUPPORT ((1))
#define ATCMD_P2P_CONFIG      (0)
#define ATCMD_ROAMING_CONFIG  (0)
#ifndef ATCMD_IF_SUPPORT
#define ATCMD_IF_SUPPORT ((1))
#endif
#define ATCMD_ASSUME_MCU_ALWAYS_ON ((0))
#ifndef ATCMD_W_MQTT_EXIST
#if (0 == FSP_NOT_DEFINED)
#define ATCMD_W_MQTT_EXIST (0)
#else
            #define ATCMD_W_MQTT_EXIST (1)
            #endif
#endif /* ATCMD_MQTT_EXIST */
#if ATCMD_TRANSPORT_SPI
            #define SPI_B_CTRL_SKIP_CHECKING_SPI_1_EN (1)
            #define ATCMD_TRANSPORT_SPI_PMOD_SUPPORT (1)
            #endif

#if(1024 == (1024))
#define ATCMD_W_RESP_LEN_MAX (1024)
#elif (4096 == (1024))
            #define ATCMD_W_RESP_LEN_MAX (4096)
            #endif

#if (FSP_NOT_DEFINED != 1)
#define ATCMD_PMGR_SUPPORT_ENABLE (1)
#endif

#if (1 == (1))
#define PMGR_MCUWU_MAX_WAIT (150)
#define PMGR_SLEEP_BLOCK_MAX_WAIT (100)
#endif

#ifdef __cplusplus
            }
            #endif
#endif /* RM_ATCMD_W_CFG_H_ */
