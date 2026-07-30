/*
*   (c) Copyright 2021-2023 NXP
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
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Stm_Ip.h"
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "Siul2_Dio_Ip.h"
#include "Siul2_Port_Ip.h"
#include "I2c_Ip.h"
#include "CDD_Pmic.h"
#include "Wdg_VR5510_VR55XX.h"
#include "Wdg_43_VR5510_Ip_PBcfg.h"
#include "Mcal.h"
#include "check_example.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* STM instance used - 0 */
#define STM_INST 0U
/* STM channel used - 0 */
#define CH_0     0U
/* STM timeout period - equivalent to 1 s */
#define STM_PERIOD 800000
/* Clock configuration structure for Init*/
#define clockConfig &Mcu_aClockConfigPB[0]
/* I2C instance used - 4 */
#define I2C4_MASTER   4U
/* Delay time */
#define DELAY_TIME    20U
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
volatile uint32 interruptOccurred = 0U;
volatile uint32 timeTrigger = 0U;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        STM notification called by the configured channel periodically
*/
void WDG_VR5510_Callback(void)
{
    interruptOccurred++;
    Wdg_VR5510_VR55XX_Trigger(WDG_43_VR5510_DEVICE);
    /* Update value of next period */
    Stm_Ip_ChangeNextTimeoutValue(STM_INST, CH_0, timeTrigger);
}

/**
* @brief        Main function of the example
* @details      Initialize the used drivers and generate a STM interrupt,
*               if the interrupt is generated interrupt notification is disabled and
*               the channel is stopped.
*/
int main (void)
{
    Std_ReturnType eInternalStatus;
    Wdg_VR55xx_PmicStateType deviceState;
    boolean exampleState = FALSE;
    /* Initialize clock module */
    Clock_Ip_Init(clockConfig);

    /* Setup pins */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Register interrupt */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);
    IntCtrl_Ip_InstallHandler(STM0_IRQn, STM_0_ISR, NULL_PTR);
    IntCtrl_Ip_EnableIrq(STM0_IRQn);

    Stm_Ip_Init(STM_INST, &STM_0_InitConfig_PB);
    Stm_Ip_InitChannel(STM_INST, STM_0_CH_0);
    Stm_Ip_EnableChannel(STM_INST, CH_0);

    OsIf_Init(NULL_PTR);
    /* Init I2C master device */
    I2c_Ip_MasterInit(I2C4_MASTER, &I2c_IICMasterChannel0);
    /* Initialize Pmic driver */
    Pmic_Init(NULL_PTR);
    /* Initialize Wdg_vr5510 driver */
    eInternalStatus = Wdg_VR5510_VR55XX_Init(&Wdg_VR5510_SlowModeSettings, WDG_43_VR5510_DEVICE);
    if (eInternalStatus == (Std_ReturnType)E_OK)
    {
        /* Start timer to trigger watchdog */
        timeTrigger = Wdg_VR5510_SlowModeSettings.u32TimerValue;
        Stm_Ip_StartCounting(STM_INST, CH_0, timeTrigger);
        /* Make sure that interrupt occur */
        while (interruptOccurred == 0U){};
        /* Initialize VR5510 device */
        eInternalStatus = Pmic_InitDevice(PmicConf_PmicDevice_PmicDevice_0);

        if (eInternalStatus == (Std_ReturnType)E_OK)
        {
            /* Switch to Fast mode */
            eInternalStatus = Wdg_VR5510_VR55XX_SetMode(&Wdg_VR5510_FastModeSettings, WDG_43_VR5510_DEVICE);
            if ((Std_ReturnType)E_OK == eInternalStatus)
            {
                /* Update timeTrigger for next period */
                timeTrigger = Wdg_VR5510_FastModeSettings.u32TimerValue;
                /* Clear interruptOccurred variable for waiting 20 times trigger window */
                interruptOccurred = 0U;
                while (interruptOccurred < DELAY_TIME){};
                /* Switch to Off mode */
                eInternalStatus = Wdg_VR5510_VR55XX_SetMode(&Wdg_VR5510_OffModeSettings, WDG_43_VR5510_DEVICE);
                if ((Std_ReturnType)E_OK == eInternalStatus)
                {
                    /* Stop STM timer */
                    Stm_Ip_StopTimer(STM_INST);
                    timeTrigger = 0U;
                    /* Check device state */
                    deviceState = Wdg_VR5510_VR55XX_PmicState(WDG_43_VR5510_DEVICE);
                    if (deviceState == FS_STATES_FSM_STATES_NORMAL_FS)
                    {
                        exampleState |= TRUE;
                    }
                }
            }
        }
    }
    Exit_Example(exampleState);

    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */
