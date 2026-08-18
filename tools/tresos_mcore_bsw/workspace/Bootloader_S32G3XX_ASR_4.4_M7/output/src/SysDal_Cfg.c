/**
*   @file           SysDal_Cfg.c
*   @version        23.02.0
*
*   @brief          Integration Framework - SysDal Abstraction Layer component
*   @details        This file implements the SysDal interface to application layer.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "SysDal.h"
#include "Mcu.h"
/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
#define SYSDAL_CFG_VENDOR_ID_C                       43

#define SYSDAL_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define SYSDAL_CFG_AR_RELEASE_MINOR_VERSION_C        4
#define SYSDAL_CFG_AR_RELEASE_REVISION_VERSION_C     0

#define SYSDAL_CFG_SW_MAJOR_VERSION_C                23
#define SYSDAL_CFG_SW_MINOR_VERSION_C                02
#define SYSDAL_CFG_SW_PATCH_VERSION_C                0
#include "Port.h"
#include "Mcl.h"
#include "SysDal_Rtm.h"
#include "Gpt.h"
#include "Qspi_Ip.h"

#include "sys_init.h"
extern ISR (PIT_0_ISR);
extern const Port_ConfigType Port_Config;
extern const Mcl_ConfigType Mcl_Config;
extern const Gpt_ConfigType Gpt_Config;

FUNC(void, SYSDAL_APP_CODE)SysDal_SetAllProgrammableInterrupts(void)
{
    sys_disableAllInterrupts();
    sys_registerIsrHandler(53, & PIT_0_ISR);
    sys_enableIsrSource(53, 0x8);
    sys_enableAllInterrupts();
}

FUNC(void, SYSDAL_APP_CODE) SysDal_DisableInterruptSources(void)
{
    sys_disableIsrSource(53);
}


/**
@brief      SysDal_InitBlockStartUp - Function used for initialising the system before starting 
            the clocks.
@details    Shall be used to init module that will not be deinitialised when go to sleep

@return     None
*/
FUNC (void, SYSDAL_APP_CODE)SysDal_InitBlockStartUp(void)
{
}

/**
@brief      SysDal_InitBlockZero - Function used for initialising the system
@details    Shall be used to init module that will not be deinitialised when go to sleep

@return     None
*/
FUNC (void, SYSDAL_APP_CODE)SysDal_InitBlockZero(void)
{
    SysDal_Wait(2000);
}

/**
@brief      SysDal_InitBlockOne - Function used for initialising the system
@details    Shall be used to init module that will be deinitialised when go to sleep
            Shall be used to invoke callouts used for System initialisation

@return     None
*/
FUNC (void, SYSDAL_APP_CODE)SysDal_InitBlockOne(void)
{
    Port_Init(&Port_Config);
    Mcl_Init(&Mcl_Config);
    SysDal_Rtm_Init();
    Gpt_Init(&Gpt_Config);
}

/**
@brief      SysDal_McuPlatformInitSeq - Function used to call the MCU platform initialization functions
@details    Shall be used on power up.

@return     None
*/
FUNC (void, SYSDAL_APP_CODE)SysDal_McuPlatformInitSeq(void)
{
    Mcu_Init(&Mcu_Config);

    Mcu_SetMode((Mcu_ModeType) SYSDAL_RUN_MODE);

    Mcu_InitClock(McuClockSettingConfig_0);
#if(MCU_NO_PLL==STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
    /* wait until all enabled PLLs are locked */
    }
    /* switch system clock tree to PLL */
    Mcu_DistributePllClock();
#endif/*MCU_NO_PLL == STD_OFF*/
}

/**
@brief      SysDal_DeinitBlockOne - Function used for deinitialising the system
@details    Shall be used to deinit module when go to sleep
            Shall be used to invoke callouts used for setting the configured low power mode

@return     None
*/
FUNC (void, SYSDAL_APP_CODE)SysDal_DeinitBlockOne(void)
{
    SysDal_Rtm_DeInit();
    Mcl_DeInit();
    Qspi_Ip_ControllerDeinit(0);
    Gpt_DeInit();
}

void INTAPP_PREHOOK_TASK(void)
{
}


#ifdef IFWK_USE_WDG
#if (ENABLE_WDG_EXPIRE_TEST == STD_ON)
FUNC (void, SYSDAL_APP_CODE) WdgExpire_Callback(void)
{
    #ifdef SYSDAL_STARTUP_MSG_CHANNEL
    ComDal_WriteData(SYSDAL_STARTUP_MSG_CHANNEL, "WatchDog EVENT!", 13U);
    #endif
    SysDal_Wdg_SetMode(WDGIF_SLOW_MODE,WDG_IPW_INSTANCE0);
}
#endif

FUNC(void, SYSDAL_APP_CODE) SysDal_Wdg_SetTriggerCondition(uint16 TimeOut)
{
    Wdg_ChannelSetTriggerCondition(TimeOut,WDG_IPW_INSTANCE0);
}

#endif

const SysDal_ConfigType SysDal_Config=
{
    &SysDal_InitBlockStartUp,
    &SysDal_InitBlockZero,
    &SysDal_InitBlockOne,
    &SysDal_SetAllProgrammableInterrupts
,
    &SysDal_DisableInterruptSources
,
    &SysDal_DeinitBlockOne,
#if (SYSDAL_LOW_POWER_MODE == STD_ON)
    &SysDal_SetWakeupEvents,
    &SysDal_ClearWakeupEvents
#endif
};

#ifdef __cplusplus
}
#endif
