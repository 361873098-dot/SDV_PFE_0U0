/*
*   (c) Copyright 2023 NXP
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
#include "Mcal.h"
#include "Mcu.h"
#include "Platform.h"
#include "Gpt.h"
#include "Port.h"
#include "Dio.h"

#if defined(S32G2XX)
#include "S32G274A_MC_ME.h"
#include "S32G274A_MC_RGM.h"
#elif defined(S32G3XX)
#include "S32G399A_MC_ME.h"
#include "S32G399A_MC_RGM.h"
#else 
#include "S32R45_MC_ME.h"
#include "S32R45_MC_RGM.h"
#endif

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define CORE_M7_0 4U
#define CORE_M7_1 5U
#define VALUE_TO_PASS 5
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Platform_MemMap.h"
volatile uint8 CounterCore0 = 0;
volatile uint8 CounterCore1 = 0;
#define PLATFORM_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Platform_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

extern uint32 __INIT_INTERRUPT_START[1U];
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/* User includes */

#define BASENXP_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#include "BaseNXP_MemMap.h"
volatile boolean initComplete = FALSE;
#define BASENXP_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#include "BaseNXP_MemMap.h"


void Gpt_Core0_Notification(void)
{
    CounterCore0++;
    Dio_FlipChannel(DioConf_DioChannel_DioChannel_0);
}

void Gpt_Core1_Notification(void)
{
    CounterCore1++;
    Dio_FlipChannel(DioConf_DioChannel_DioChannel_1);
}

boolean main_core0(void)
{
    uint32 TimeOutCounter = 0;
    boolean ReturnValue = TRUE;

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
    /* XBAR_CLK = 300Mhz -> CLK_core_m7 = 300Mhz
       timeout = 7s -> counter = 7s : (1:300Mhz) = 0x7D2B 7500*/
    TimeOutCounter = (uint32)0x7D2B7500;
    while(!((VALUE_TO_PASS <= CounterCore0) && (VALUE_TO_PASS <= CounterCore1)) && (TimeOutCounter > 0))
    {
        TimeOutCounter--;
    }
    if (TimeOutCounter == 0)
    {
        ReturnValue = FALSE;
    }

    return ReturnValue;
}

void main_core1(void)
{
    while(!initComplete);
    Platform_Init(NULL_PTR);
    Port_Init(NULL_PTR);
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_1, STD_LOW);
    Gpt_Init(&Gpt_Config_EcucPartition_Cinque);
    Gpt_EnableNotification(1);
    /* Blink led PTA7 (RED LED) with frequency 1Hz:
     * f(ModuleClk) = f(STM0) = f(XBAR_DIV3_CLK) = 100Mhz
     * ticks = ((1s / (1/f(ModuleClk))) / 2) - 1 = 50*10^6 - 1 ==> 0x2FA F07F
     * */
    Gpt_StartTimer(1, 0x2FAF07F);    /* Generate notification 1Hz */
    while(1);
}

/* Enable another core to support testing MSI */
void T_EnableCoreCM7_1Privileged(void)
{
    /* Get address of VTABLE */
    uint32 u32VTABLE = (uint32)__INIT_INTERRUPT_START;
    /* Set boot address */
    IP_MC_ME->PRTN0_CORE1_ADDR= u32VTABLE;
    /* Enable core for the core */
    IP_MC_ME->PRTN0_CORE1_PCONF = 1;
    /* Trigger the hardware process for enabling core clock to the Core */
    IP_MC_ME->PRTN0_CORE1_PUPD = 1;
    IP_MC_ME->CTL_KEY = 0x00005AF0;
    IP_MC_ME->CTL_KEY = 0x0000A50F;
    /* Wait for core 1 clock is active */
    while((IP_MC_ME->PRTN0_CORE1_STAT & 0x01) != 0x01);
    /* IP_MC_RGM->PRST_0[0].PRST_0 &= (IP_MC_RGM->PRST_0[0].PRST_0 & 0xFFFFFFFD); */
    IP_MC_RGM->PRST_0[0].PRST_0 &= IP_MC_RGM->PRST_0[0].PRST_0 & 0xFFFFFFFD;
    while((IP_MC_RGM->PSTAT_0[0].PSTAT_0 & 0x2) != 0x0);
}
/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    boolean IsPassed = TRUE;
    uint8 coreId = OsIf_GetCoreID();

    if(CORE_M7_0 == coreId)
    {
        Mcu_Init(&Mcu_Config);
        Mcu_InitClock(McuClockSettingConfig_0);
        Mcu_DistributePllClock();
        Mcu_SetMode(McuModeSettingConf_0);
        T_EnableCoreCM7_1Privileged();
        main_core0(); 
    }
    else /* CORE_M7_1 == coreId*/
    {
        main_core1();
    }
    IsPassed = main_core0();

    Exit_Example(IsPassed);
}

#ifdef __cplusplus
}
#endif

/** @} */
