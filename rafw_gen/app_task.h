/* generated thread header file - do not edit */
#ifndef APP_TASK_H_
#define APP_TASK_H_
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void app_task_entry(void * pvParameters);
                #else
extern void app_task_entry(void *pvParameters);
#endif
FSP_HEADER
FSP_FOOTER
#endif /* APP_TASK_H_ */
