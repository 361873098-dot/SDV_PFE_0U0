/**
*   @internal
*   @file    Lin_Llce.h
*   @version 1.0.7
*
*   @brief   AUTOSAR Lin_llce - LLD module interface.
*   @details Low Level Driver header file for IPV = Llce.
*
*   @addtogroup LIN_LLCE
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc.
*   Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
*   accordance with the applicable license terms.
*   By expressly accepting such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to comply with and are bound
*   by, such license terms.  If you do not agree to be bound by the applicable license terms, then you
*   may not retain, install, activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef LIN_LLCE_H
#define LIN_LLCE_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_Llce.h
*/
#define LIN_LLCE_VENDOR_ID                    43
#define LIN_LLCE_AR_RELEASE_MAJOR_VERSION     4
#define LIN_LLCE_AR_RELEASE_MINOR_VERSION     4
#define LIN_LLCE_AR_RELEASE_REVISION_VERSION  0
#define LIN_LLCE_SW_MAJOR_VERSION             1
#define LIN_LLCE_SW_MINOR_VERSION             0
#define LIN_LLCE_SW_PATCH_VERSION             7
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define LIN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

extern const Lin_43_LLCE_ConfigType * Lin_43_LLCE_pxConfigPtr;

#define LIN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

#define LIN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

extern const Lin_43_LLCE_ChannelConfigType * Lin_43_LLCE_pChannelConfigPtr[LIN_43_LLCE_HW_MAX_MODULES];

#define LIN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Lin_43_LLCE_MemMap.h"

#define LIN_43_LLCE_START_SEC_VAR_INIT_8
#include "Lin_43_LLCE_MemMap.h"

/* LIN driver status variable.*/
extern uint8 Lin_u8LinDrvStatus;

#define LIN_43_LLCE_STOP_SEC_VAR_INIT_8
#include "Lin_43_LLCE_MemMap.h"

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_43_LLCE_START_SEC_CODE
#include "Lin_43_LLCE_MemMap.h"

Std_ReturnType Lin_Llce_CheckWakeup(const uint8 u8Channel);
void Lin_Llce_Init(void);

#if (LIN_43_LLCE_MASTER_NODE_USED == STD_ON)
    Lin_StatusType Lin_Llce_HardwareGetStatus(const uint8 u8Channel, uint8 ** pu8LinSduPtr);
    Std_ReturnType Lin_Llce_SendFrame(const uint8 u8Channel, const Lin_PduType * pPduInfoPtr);
    Std_ReturnType Lin_Llce_GoToSleep(const uint8 u8Channel);
#endif /* #if LIN_43_LLCE_MASTER_NODE_USED == STD_ON */

Std_ReturnType Lin_Llce_GoToSleepInternal(const uint8 u8Channel);
Std_ReturnType Lin_Llce_WakeUp(const uint8 u8Channel);
Std_ReturnType Lin_Llce_WakeupInternal(const uint8 u8Channel);

void Lin_Llce_ProcessCmdFromLlce(const uint8 u8HwCtrl);

#define LIN_43_LLCE_STOP_SEC_CODE
#include "Lin_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_LLCE_H */
