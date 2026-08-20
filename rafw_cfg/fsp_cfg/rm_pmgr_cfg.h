/* generated configuration header file - do not edit */
#ifndef RM_PMGR_CFG_H_
#define RM_PMGR_CFG_H_
#ifdef __cplusplus
extern "C" {
#endif

#define PMGR_MAX_NOTIFIER_ARRAY 5

/**
 * \def PMGR_SSL_DPM_SUPPORT
 *
 * Additional features to support for dpm.
 *
 * Comment this macro to disable support for dpm
 */
#if 1
#define PMGR_SSL_DPM_SUPPORT
#endif

#ifndef dg_configDISABLE_BACKGROUND_FLASH_OPS
#define dg_configDISABLE_BACKGROUND_FLASH_OPS      ( 1 )
#endif
#define dg_configUSE_SLEEP_MGMT_FUNCTION           ( 1 ) // Sleep Management function (with DPM)
#define dg_configUSE_RETENTION_MEM_INFO            ( 1 ) // Print retention memory information

#ifdef __cplusplus
}
#endif
#endif /* RM_PMGR_CFG_H_ */
