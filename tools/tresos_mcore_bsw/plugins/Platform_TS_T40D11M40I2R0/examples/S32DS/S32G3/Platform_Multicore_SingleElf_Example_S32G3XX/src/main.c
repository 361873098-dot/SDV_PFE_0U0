/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : 
* Dependencies : none
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 4.0.2
* Build Version : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
* Copyright 2020-2023 NXP Semiconductors.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

/* Including necessary configuration files. */
#include "Mcal.h"
#include "Mcu.h"
#include "Platform.h"
#include "Gpt.h"
#include "Port.h"
#include "Dio.h"
/* Macro definition */
#define CORE_M7_0 4U
#define CORE_M7_1 5U
volatile int exit_code = 0;
/* User includes */

#define BASENXP_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#include "BaseNXP_MemMap.h"
volatile boolean initComplete = FALSE;
#define BASENXP_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#include "BaseNXP_MemMap.h"

void Gpt_Stm0_Notification(void)
{
    Dio_FlipChannel(DioConf_DioChannel_DioChannel_1);
}

void Gpt_Pit0_Notification(void)
{
    Dio_FlipChannel(DioConf_DioChannel_DioChannel_0);
}

void main_core0(void)
{
    Platform_Init(NULL_PTR);
    Port_Init(NULL_PTR);
    initComplete = TRUE;
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_LOW);
    Gpt_Init(&Gpt_Config_EcucPartition_4);
    Gpt_EnableNotification(0);
    /* Blink led PTA6 (BLUE LED) with frequency 1Hz:
     * f(ModuleClk) = f(PIT0) = f(XBAR_DIV3_CLK) = 100Mhz
     * ticks = ((1s / (1/f(ModuleClk))) / 2) - 1 = 50*10^6 - 1 ==> 0x2FA F07F
     * */
    Gpt_StartTimer(0, 0x2FAF07F);    /* Generate notification 1Hz */
    while(1);
}

void main_core1(void)
{
    while(!initComplete);
    Platform_Init(NULL_PTR);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_1, STD_LOW);
    Gpt_Init(&Gpt_Config_EcucPartition_5);
    Gpt_EnableNotification(1);
    /* Blink led PTA7 (RED LED) with frequency 1Hz:
     * f(ModuleClk) = f(STM0) = f(XBAR_DIV3_CLK) = 100Mhz
     * ticks = ((1s / (1/f(ModuleClk))) / 2) - 1 = 50*10^6 - 1 ==> 0x2FA F07F
     * */
    Gpt_StartTimer(1, 0x2FAF07F);    /* Generate notification 1Hz */
    while(1);
}

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    uint8 coreId = OsIf_GetCoreID();
    if(CORE_M7_0 == coreId)
    {
        Mcu_Init(&Mcu_Config);
        Mcu_InitClock(McuClockSettingConfig_0);
        Mcu_DistributePllClock();
        Mcu_SetMode(McuModeSettingConf_0);

        main_core0();
    }
    else /* CORE_M7_1 == coreId */
    {
        main_core1();
    }

    for(;;)
    {
        if(exit_code != 0)
        {
            break;
        }
    }
    return exit_code;
}

/** @} */
