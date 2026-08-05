/**
*   @file    Can_43_LLCE_Cfg.c
*   @version 1.0.7
*
*   @brief   AUTOSAR Can_43_LLCE - module interface
*   @details Configuration Structures for PreCompile.
*
*   @addtogroup CAN_LLCE
*   @{
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

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_43_LLCE.h"
#include "Can_43_LLCE_IPW.h"

/**
* @file           Can_43_LLCE_Cfg.c
*/

[!AUTOSPACING!]

[!NOCODE!][!//
[!INCLUDE "Can_43_LLCE_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_43_LLCE_VENDOR_ID_PCCFG_C                   43
#define CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PCCFG_C     4
#define CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PCCFG_C     4
#define CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PCCFG_C  0
#define CAN_SW_MAJOR_VERSION_PCCFG_C             1
#define CAN_SW_MINOR_VERSION_PCCFG_C             0
#define CAN_SW_PATCH_VERSION_PCCFG_C             7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Can configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_PCCFG_C != CAN_43_LLCE_VENDOR_ID)
#error "Can_43_LLCE.h and Can_43_LLCE_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PCCFG_C != CAN_43_LLCE_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_43_LLCE_Cfg.c and Can_43_LLCE.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PCCFG_C != CAN_43_LLCE_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PCCFG_C != CAN_43_LLCE_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PCCFG_C != CAN_43_LLCE_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_43_LLCE_Cfg.c and Can_43_LLCE.h are different"
#endif

/* Check if current file and Can_IPW configuration header file are of the same vendor */
#if (CAN_43_LLCE_VENDOR_ID_PCCFG_C  != CAN_IPW_VENDOR_ID_H)
#error "Can_43_LLCE.h and Can_43_LLCE_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_43_LLCE_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_LLCE_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_LLCE_AR_RELEASE_REVISION_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_43_LLCE_Cfg.c and Can_43_LLCE.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PCCFG_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_PCCFG_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_PCCFG_C != CAN_IPW_SW_PATCH_VERSION_H))
       #error "Software Version Numbers of Can_43_LLCE_Cfg.c and Can_43_LLCE.h are different"
#endif


/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Can_43_LLCE_MemMap.h"


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
[!NOCODE!] [!/* This section is for global variables, local to this file */!]
    [!/*
    Sync-seg = is the segment that is used to synchronise the nodes on the bus. A bit edge (if there is a data change) is expected during this segment.
    Prop-Seg = is a period of time that is used to compensate for physical delay times within the network.
    Phase-seg1 = is a buffer segment that may be lengthened during resynchronisation to compensate for oscillator drift and positive phase differences between the oscillators of the transmitting and receiving node(s).
    Phase-seg2 = is a buffer segment that may be shortened during resynchronisation (described below) to compensate for negative phase errors and oscillator drift.

    The Sample point is always at the end of Phase-seg1 and is the time at which the bus level is read and interpreted as the value of the current bit.
    Whether transmitting or receiving, all nodes on a single CAN bus must have the same nominal bit time. Bit time is programmable at each node on a CAN Bus and is a function
        of the period of the oscillator local to each node, the value that is user-programmed into a Baud Rate Prescaler (BRP) register in the controller at each node, and the programmed number of time quanta per bit.
    When any node receives a data frame or a remote frame, it is necessary for the receiver to synchronise with the transmitter.
        1. The first is hard synchronisation and occurs at Start-of-Frame (SOF).
        2. For subsequent bits in any received frame, if a bit edge does not occur in the Sync-seg segment of bit time, resynchronisation is automatically invoked and will shorten or lengthen the current bit time depending
            on where the edge occurs. The maximum amount by which the bit time is lengthened or shortened is determined by a user-programmable number of time quanta known as the Synchronisation Jump Width (SJW).
    */!]
[!ENDNOCODE!]

/*==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Can_43_LLCE_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
