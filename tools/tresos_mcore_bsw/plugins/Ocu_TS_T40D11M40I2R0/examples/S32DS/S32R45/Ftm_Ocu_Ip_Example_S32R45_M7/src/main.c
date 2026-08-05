/*==================================================================================================
*   (c) Copyright 2020 - 2021 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftm_Ocu_Ip.h"
#include "Ftm_Ocu_Ip_Irq.h"
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "Siul2_Port_Ip.h"
#include "Siul2_Dio_Ip.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define clockConfig &Mcu_aClockConfigPB[0]
#define FTM_1       (1U)
#define CHANNEL_0   (0U)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/



/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* Global flag updated in irq */
static volatile boolean toggleLed = FALSE;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/**
* @brief    Ftm notification periodically called by the configured channel
* @details  Used to blink a led
*/
void OcuChannel_0_notification(void);
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/**
* @brief    Ftm notification periodically called by the configured channel
* @details  Used to blink a led
*/
void OcuChannel_0_notification()
{
    static uint16 count = 0U;

    if(++count >= 300U)
    {
        toggleLed = TRUE;
        count = 0;
    }
}
#endif

/**
* @brief        Main function of the example
* @details      Initializez the used drivers and uses the Ocu
*               and Dio drivers to toggle a LED periodically
*/

int main(void)
{
    /* Write your code here */
    Clock_Ip_Init(clockConfig);
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0,g_pin_mux_InitConfigArr0);

    /* set FTM 1 interupt */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);

    /* init channel Ftm_Ocu*/
    Ftm_Ocu_Ip_Init(&Ftm_Ocu_Ip_ModuleCfgPB_VS_0);

    /* Start channel and enable interrupt */
    Ftm_Ocu_Ip_StartChannel(FTM_1,CHANNEL_0);
    Ftm_Ocu_Ip_EnableNotification(FTM_1,CHANNEL_0);

    while (1)
    {
        /* Toggle the LED when the Ocu notification is called */
        if (TRUE == toggleLed)
        {
            toggleLed = FALSE;
            Siul2_Dio_Ip_TogglePins(LED_PORT, (1<<LED_PIN));
        }
    }
}

/** @} */

