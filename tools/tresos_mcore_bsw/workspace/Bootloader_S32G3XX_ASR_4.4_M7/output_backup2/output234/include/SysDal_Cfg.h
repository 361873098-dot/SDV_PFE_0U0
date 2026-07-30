
/**
*   @file           SysDal_Cfg.h
*   @version        23.02.0
*
*   @brief          AUTOSAR SysDal - SysDal pre configuration file.
*   @details        Pre configuration structure instances
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*/

#ifndef SYSDAL_CFG_H
#define SYSDAL_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
/**
* @file          SysDal_Cfg.h
*/
#define SYSDAL_CFG_VENDOR_ID                           43
#define SYSDAL_CFG_MODULE_ID                           102

#define SYSDAL_CFG_AR_RELEASE_MAJOR_VERSION            4
#define SYSDAL_CFG_AR_RELEASE_MINOR_VERSION            4
#define SYSDAL_CFG_AR_RELEASE_REVISION_VERSION         0

#define SYSDAL_CFG_SW_MAJOR_VERSION                    23
#define SYSDAL_CFG_SW_MINOR_VERSION                    02
#define SYSDAL_CFG_SW_PATCH_VERSION                    0


#define    SYSDAL_SYSTIME                  STD_ON 
#define    SYSDAL_USE_NON_ASR_PERIPHERALS  STD_OFF 
#define    SYSDAL_TASK_SCHEDULING          STD_ON 



#define    ENABLE_WDG_EXPIRE_TEST            (STD_OFF)




#define    SYSDAL_LOW_POWER_MODE  (STD_OFF)
#define    SYSDAL_RUN_MODE        0U 


#define    GPT_SCH_TICKS                       133333U
#define    SYSDAL_SCH_GPT_TIMER_CHANNEL        0U



#define    INTAPP_PREHOOK_TASK_ENABLE                STD_ON 
#define    INTAPP_TASK_1_ENABLE                STD_OFF 
#define    INTAPP_TASK_2_ENABLE                STD_OFF 
#define    INTAPP_TASK_3_ENABLE                STD_OFF 
#define    INTAPP_TASK_4_ENABLE                STD_OFF 
#define    INTAPP_TASK_5_ENABLE                STD_OFF 
#define    INTAPP_TASK_6_ENABLE                STD_OFF 
#define    INTAPP_TASK_7_ENABLE                STD_OFF 
#define    INTAPP_IDLE_TASK_ENABLE                STD_OFF 


extern void INTAPP_PREHOOK_TASK(void); 
#define    INTAPP_CYCLIC_WAKEUP_TASK_ENABLE            (STD_OFF)  

FUNC (void, SYSDAL_APP_CODE)SysDal_McuPlatformInitSeq(void);
FUNC (void, SYSDAL_APP_CODE)SysDal_InitBlockStartUp(void);
FUNC (void, SYSDAL_APP_CODE)SysDal_InitBlockZero(void);
FUNC (void, SYSDAL_APP_CODE)SysDal_InitBlockOne(void);
FUNC (void, SYSDAL_APP_CODE) SysDal_SetAllProgrammableInterrupts(void);
FUNC (void, SYSDAL_APP_CODE) SysDal_DeinitBlockOne(void);
#if (SYSDAL_LOW_POWER_MODE == STD_ON)
FUNC (void, SYSDAL_APP_CODE) SysDal_SetWakeupEvents(void);
FUNC (void, SYSDAL_APP_CODE) SysDal_ClearWakeupEvents(void);
 

#endif


#ifdef __cplusplus
}
#endif

#endif /* SYSDAL_CFG_H */

