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
/***********************************************************************************************************************
*  local type definitions (STRUCT, TYPEDEF, ...)
***********************************************************************************************************************/
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
    for ( ;; )
    {
        OS_TASKCOUNT_INC_CTR(M7_Core0_1ms);
        /*  Add user application code here  */


        vTaskDelay(pdMS_TO_TICKS(1));
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

    for ( ;; )
    {
        OS_TASKCOUNT_INC_CTR(M7_Core0_5ms);
        /*  Add user application code here  */

        vTaskDelay(pdMS_TO_TICKS(5));
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
    (void)pvParameters;
    for ( ;; )
        {
            OS_TASKCOUNT_INC_CTR(M7_Core0_10ms);
            /*  Add user application code here  */

            vTaskDelay(pdMS_TO_TICKS(10));
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
    for ( ;; )
    {
        OS_TASKCOUNT_INC_CTR(M7_Core0_100ms);
        /*  Add user application code here  */


        vTaskDelay(pdMS_TO_TICKS(100));
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
    for( ;; )
    {
        OS_TASKCOUNT_INC_CTR(M7_Core0_1000ms);
        /*  Add user application code here  */

        //llce_dummy();
//         Eth_43_PFE_MainFunction();
//         SampleAppTask2();
        vTaskDelay(pdMS_TO_TICKS(1000));
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
    xTaskCreate((TaskFunction_t)task_m7_core0_1ms, "task_m7_core0_1ms", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, NULL );
    xTaskCreate((TaskFunction_t)task_m7_core0_5ms, "task_m7_core0_5ms", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+2, NULL );
    xTaskCreate((TaskFunction_t)task_m7_core0_10ms, "task_m7_core0_10ms", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+3, NULL );
    xTaskCreate((TaskFunction_t)task_m7_core0_100ms, "task_m7_core0_100ms", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+4, NULL );
    xTaskCreate((TaskFunction_t)task_m7_core0_1000ms, "task_m7_core0_1000ms", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+5, NULL );
    vTaskStartScheduler();
}