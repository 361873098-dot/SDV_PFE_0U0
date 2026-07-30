/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "Std_Types.h"


#define SCB_CCSIDR_NUMSETS_SHIFT            13U
#define SCB_CCSIDR_NUMSETS_MASK       (0x7FFFUL << 13U)

#define SCB_CCSIDR_ASSOCIATIVITY_SHIFT       3U        
#define SCB_CCSIDR_ASSOCIATIVITY_MASK   (0x3FFUL << 3U)

#define SCB_DCISW_SET_SHIFT                   5U
#define SCB_DCISW_SET_MASK                 (0x1FFUL << 5U)

#define SCB_DCISW_WAY_SHIFT                  30U      
#define SCB_DCISW_WAY_MASK                  (3UL << 30U)
   
#define SCB_CCR_DC_SHIFT                      16U                            
#define SCB_CCR_DC_MASK                     (1UL << 16U)
    
#define SCB_CCR_IC_SHIFT                      17U                            
#define SCB_CCR_IC_MASK                     (1UL << 17U)

#define SCB_DCCISW_SET_SHIFT                  5U                             
#define SCB_DCCISW_SET_MASK                 (0x1FFUL << 5U)

#define SCB_DCCISW_WAY_SHIFT                 30U                             
#define SCB_DCCISW_WAY_MASK                 (3UL << 30U)    

/* Cache Size ID Register Macros */
#define CCSIDR_WAYS(x)     (((x) & SCB_CCSIDR_ASSOCIATIVITY_MASK) >> SCB_CCSIDR_ASSOCIATIVITY_SHIFT)
#define CCSIDR_SETS(x)     (((x) & SCB_CCSIDR_NUMSETS_MASK) >> SCB_CCSIDR_NUMSETS_SHIFT)

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
/* 
 * @brief Early platform initialization for interrupts, cache and core MPU
 * @param: None
 * 
 * @return: None
 */

void SystemInit(void);

/* 
 * @brief Default IRQ handler
 * @param: None
 * 
 * @return: None
 */
void default_interrupt_routine(void);

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
/* 
 * @brief Switch to user mode and return the value passed by u32returnValue
 * @param: [in] u8SwitchToSupervisor - if 0, the function will return the value without switching to user mode,
 *                                     if 1, the function will go to user mode before returning the value
 * @param: [in] u32returnValue       - value to be returned
 * 
 * @return: u32returnValue
 */
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue);

/* 
 * @brief Switch to supervisor mode
 * @param: None
 * 
 * @return: operation result, 1 if switch was done, 0 if the CPU was already in supervisor mode or in handler mode
 */
uint32 Sys_GoToSupervisor(void);

/* 
 * @brief Switch to user mode
 * @param: None
 * 
 * @return: 0
 */
uint32 Sys_GoToUser(void);

/* 
 * @brief Sys_SuspendInterrupts
 * @param: None
 * 
 * @return: none
 */
void Sys_SuspendInterrupts(void);
void Sys_ResumeInterrupts(void);

#endif

/* 
 * @brief Get the hardware id of the currently executing core
 * @param: None
 * 
 * @return: coreId
 */
uint8 Sys_GetCoreID(void);


/* 
 * @brief SystemWfiConfig : Implement errata ERR051149
 * @param: None
 * 
 * @return: none
 */

#if defined(ERR_CORTEX_M7_E051149) || defined(ERR_CORTEX_M7_E051166)
void SystemWfiConfig(void);
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_H */
