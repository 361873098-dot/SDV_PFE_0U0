/**
*   @file    CanIf_CanTrcv.h
*   @version 1.0.1
*
*   @brief   AUTOSAR CanIf - CanIf CanTrcv module interface
*   @details AUTOSAR CanIf CanTrcv module interface.- Stub Version
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup CANIF_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.8.0
*   Build Version        : S32K3_RTD_0_8_0_D2207_ASR_REL_4_4_REV_0000_20220729
*
*   (c) Copyright 2020 - 2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
ifdef(`M4_SRC_KEEP_REVISION_HISTORY', `dnl - DO NOT modify this M4 line!
Revision History:
                             Modification     Tracking
Author (core ID)              Date D/M/Y       Number     Description of Changes
---------------------------   ----------    ------------  ------------------------------------------
Marius Rotaru (rtrm001)            20/06/2011    ENGR00143892  File creation for ASR4.0
---------------------------   ----------    ------------  ------------------------------------------
Subramanya Naik (b37356)       13/11/2012    ENGR00230881  [CANIF] CanIf_ControllerModeType defined in wrong header file
---------------------------   ----------    ------------  ------------------------------------------
Chethan N (b43030)       25/03/2013    ENGR00254461  [CANIF] CanIf_CancelTxConfirmation has wrong number of arguments
---------------------------   ----------    ------------  ------------------------------------------
Chethan N (b43030)       07/08/2013    ENGR00274061  [CANIF] MRD2.0 requirement MR-010, change of demo code disclaimer in file header
---------------------------   ----------    ------------  ------------------------------------------
HongNgo   (nxf40662)          30/03/2020    AMNG-7748     update checking version autosar
',)dnl - DO NOT modify this M4 line!
==================================================================================================*/
#ifndef CANIF_CANTRCV_H
#define CANIF_CANTRCV_H

#ifdef  __cplusplus
extern "C"
{
#endif
#include "CanIf_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_CANTRCV_VENDOR_ID                         43
#define CANIF_CANTRCV_MODULE_ID                         60
#define CANIF_CANTRCV_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_CANTRCV_AR_RELEASE_MINOR_VERSION          7
#define CANIF_CANTRCV_AR_RELEASE_REVISION_VERSION       0
#define CANIF_CANTRCV_SW_MAJOR_VERSION                  0
#define CANIF_CANTRCV_SW_MINOR_VERSION                  8
#define CANIF_CANTRCV_SW_PATCH_VERSION                  0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanIf_Types.h header file are of the same vendor */
#if (CANIF_CANTRCV_VENDOR_ID != CANIF_TYPES_VENDOR_ID)
#error "CanIf_CanTrcv.h and CanIf_Types.h have different vendor ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same Autosar version */
#if ((CANIF_CANTRCV_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_CANTRCV_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_CANTRCV_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanIf_CanTrcv.h and CanIf_Types.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

void CanIf_TrcvModeIndication(uint8 Transceiver, CanTrcv_TrcvModeType TransceiverMode);
void CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId);
void CanIf_ConfirmPnAvailability(uint8 TransceiverId);
void CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId);

#ifdef __cplusplus
}
#endif

#endif                          /* CANIF_CANTRCV_H */

/** @} */
