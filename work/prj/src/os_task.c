/********************************************************************************
* COPYRIGHT (C) Vitesco Technologies 2025
* ALL RIGHTS RESERVED.
*
* The reproduction, transmission or use of this document or its
* contents is not permitted without express written authority.
* Offenders will be liable for damages. All rights, including rights
* created by patent grant or registration of a utility model or design,
* are reserved.
*********************************************************************************
*
*  File name:           $Source: os_task.c $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      OS_TASK
*  Specification:
*  Date:                $Date: 2025/12/18  $
*
*  Description:     OS task functions
*
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/


/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "os_taskcount.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "semphr.h"
//#include "llce_dummy.h "

/* lwIP core includes */
#include "lwip/opt.h"

#include "lwip/sys.h"
#include "lwip/timeouts.h"
#include "lwip/debug.h"
#include "lwip/stats.h"
#include "lwip/init.h"
#include "lwip/tcpip.h"
#include "lwip/netif.h"
#include "lwip/api.h"
#include "lwip/arch.h"

#include "lwip/tcp.h"
#include "lwip/udp.h"
#include "lwip/dns.h"
#include "lwip/dhcp.h"
#include "lwip/autoip.h"

/* lwIP netif includes */
#include "lwip/etharp.h"
#include "netif/ethernet.h"
//#include "netifcfg.h"
#include "Eth_43_PFE.h"
#include "sample_app_ethswt_task_2_send_frames.h"
/* include the port-dependent configuration */
//#include "lwipcfg.h"
#include "pwsm.h"
#include "picc_stack.h"
#include "picc_heartbeat.h"
#include "picc_link.h"
#include "picc_main.h"
#include "diag_mgmt.h"
#include "CDD_I2c.h"
#include "CDD_I2c_VS_0_PBcfg.h"
#include "System_Cpuload.h"

#include "HpcCan_Driver.h"
#include "soa_adapter_main.h"
#include "hm.h"
#include "stm_main.h"
#include "Nm.h"
#include "time_sync.h"

/***********************************************************************************************************************
*  local macro definitions
***********************************************************************************************************************/
/** 10ms periodic task stack depth in StackType_t words (320 words = 1280 bytes on Cortex-M7). */
#define OSTASK_10MS_STACK_SIZE             (320U)

#define main_TASK_PRIORITY                ( tskIDLE_PRIORITY + 2 )

/***********************************************************************************************************************
*  local variable definitions (module local variables)
***********************************************************************************************************************/

/***********************************************************************************************************************
 *  Function name    : task_m7_core0_1ms()
 *
 *  Description      : Task function for M7_0 1ms task, increments the task count for M7_0 1ms task
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
void task_m7_core0_1ms(void *pvParameters)
{
    (void)pvParameters;
    TickType_t lastWakeTime = xTaskGetTickCount();

    for ( ;; )
    {
        OS_TASKCOUNT_INC_CTR(M7_Core0_1ms);
        /*  Add user application code here  */

        /* Cyclic lwIP timers check */
        sys_check_timeouts();

      vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(1));
    } 
    
   
}

/***********************************************************************************************************************
 *  Function name    : task_m7_core0_5ms()
 *
 *  Description      : Task function for M7_0 5ms task, increments the task count for M7_0 5ms task
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
void task_m7_core0_5ms(void *pvParameters)
{
    (void)pvParameters;
    TickType_t lastWakeTime = xTaskGetTickCount();

    for ( ;; )
    {
        OS_TASKCOUNT_INC_CTR(M7_Core0_5ms);
        /*  Add user application code here  */

        vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(5));
    }
   
}

/***********************************************************************************************************************
 *  Function name    : task_m7_core0_10ms()
 *
 *  Description      : Task function for M7_0 10ms task, increments the task count for M7_0 10ms task
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
void task_m7_core0_10ms(void *pvParameters)
{
    static uint16 diagUpdateCounter = 0U;
    (void)pvParameters;
    TickType_t lastWakeTime = xTaskGetTickCount();
    for ( ;; )
    {
        OS_TASKCOUNT_INC_CTR(M7_Core0_10ms);
        /* Process CAN first so the SOA getters/notifiers see the newest
         * values, matching the original reference task order. */
        HpcCan_MainFunction_10ms();

        /* Ported periodic task dispatch from original Ostask_main TASK_M0_10MS bucket. */
        PICC_StackProcess();
        PICC_HeartbeatProcess();
        PICC_LinkProcess();
        SoaAdapter_Main();
        Pwsm_Main();
        DiagMgmt_Main();
        Hm_Main();
        Stm_Main();
        TimeSync_Main();

#if (PICC_DIAG_RECORD_ENABLE == 1U)
        PICC_DiagUpdateLinkState();
#endif

    diagUpdateCounter++;
    if (diagUpdateCounter >= (ECUM_DIAG_UPDATE_PERIOD_MS / 10U)) {
        EcuM_Diag_Update();
        diagUpdateCounter = 0U;
    }

        vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(10));
    }

}

/***********************************************************************************************************************
 *  Function name    : task_m7_core0_100ms()
 *
 *  Description      : Task function for M7_0 100ms task, increments the task count for M7_0 100ms task
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
void task_m7_core0_100ms(void *pvParameters)
{
    (void)pvParameters;
    TickType_t lastWakeTime = xTaskGetTickCount();
    for ( ;; )
    {
        OS_TASKCOUNT_INC_CTR(M7_Core0_100ms);
        /*  Add user application code here  */

        vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(100));
    }
}

/***********************************************************************************************************************
 *  Function name    : task_m7_core0_1000ms()
 *
 *  Description      : Task function for M7_0 1000ms task, increments the task count for M7_0 1000ms task
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/   
void task_m7_core0_1000ms(void *pvParameters)
{
    (void)pvParameters;
    TickType_t lastWakeTime = xTaskGetTickCount();
    for( ;; )
    {
        OS_TASKCOUNT_INC_CTR(M7_Core0_1000ms);
        /*  Add user application code here  */

        //llce_dummy();
//         Eth_43_PFE_MainFunction();
//         SampleAppTask2();
        vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(1000));
    }
}   

/***********************************************************************************************************************
 *  Function name    : creat_tasks_m7()
 *
 *  Description      : Creates tasks for M7 core with different periodicities
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
void creat_tasks_m7(void)
{
    BaseType_t taskCreateStatus;

    PICC_PreOS_Init();
    Pwsm_Init();
    Nm_Init();
    DiagMgmt_Init();
    SoaAdapter_Init();
    Hm_Init();
    Stm_Init();
    TimeSync_Init();

    taskCreateStatus = xTaskCreate((TaskFunction_t)task_m7_core0_1ms,
                                   "task_m7_core0_1ms",
                                   configMINIMAL_STACK_SIZE, NULL,
                                   tskIDLE_PRIORITY + 1, NULL);
    if (taskCreateStatus != pdPASS) {
        taskDISABLE_INTERRUPTS();
        while (1) { /* Task creation failed */ }
    }

    taskCreateStatus = xTaskCreate((TaskFunction_t)task_m7_core0_5ms,
                                   "task_m7_core0_5ms",
                                   configMINIMAL_STACK_SIZE, NULL,
                                   tskIDLE_PRIORITY + 2, NULL);
    if (taskCreateStatus != pdPASS) {
        taskDISABLE_INTERRUPTS();
        while (1) { /* Task creation failed */ }
    }

    taskCreateStatus = xTaskCreate((TaskFunction_t)task_m7_core0_10ms,
                                   "task_m7_core0_10ms",
                                   OSTASK_10MS_STACK_SIZE, NULL,
                                   tskIDLE_PRIORITY + 3, NULL);
    if (taskCreateStatus != pdPASS) {
        taskDISABLE_INTERRUPTS();
        while (1) { /* Task creation failed */ }
    }

    taskCreateStatus = xTaskCreate((TaskFunction_t)task_m7_core0_100ms,
                                   "task_m7_core0_100ms",
                                   configMINIMAL_STACK_SIZE, NULL,
                                   tskIDLE_PRIORITY + 4, NULL);
    if (taskCreateStatus != pdPASS) {
        taskDISABLE_INTERRUPTS();
        while (1) { /* Task creation failed */ }
    }

    taskCreateStatus = xTaskCreate((TaskFunction_t)task_m7_core0_1000ms,
                                   "task_m7_core0_1000ms",
                                   configMINIMAL_STACK_SIZE, NULL,
                                   tskIDLE_PRIORITY + 5, NULL);
    if (taskCreateStatus != pdPASS) {
        taskDISABLE_INTERRUPTS();
        while (1) { /* Task creation failed */ }
    }

    /* PICC RX message processing task.
     * The IPCF RX callback PICC_data_mng_rx_cb() (ISR context) pushes every
     * received frame into g_rxQueue. This task is the ONLY consumer of that
     * queue: it drains it and runs PICC_ProcessRxData(), which replies heartbeat
     * Pongs and link CONNECT responses and consumes A-core's Pongs.
     * Without this task the queue fills up (10/10), every further RX hits the
     * xQueueSendFromISR-failed branch (ipc_shm_release_buf + error_count++),
     * no Pong/response is ever sent, and the heartbeat missCount times out ->
     * PICC_LinkGetState() returns DISCONNECTED -> all app links stay
     * DISCONNECTED. (Priority +4 so RX is processed promptly.) */
    taskCreateStatus = xTaskCreate((TaskFunction_t)PICC_Rx_Msg_10ms_Task,
                                   "RxMsgTask",
                                   (unsigned short)(configMINIMAL_STACK_SIZE * 2),
                                   NULL, tskIDLE_PRIORITY + 4, NULL);
    if (taskCreateStatus != pdPASS) {
        taskDISABLE_INTERRUPTS();
        while (1) { /* Task creation failed */ }
    }

    vTaskStartScheduler();
}
