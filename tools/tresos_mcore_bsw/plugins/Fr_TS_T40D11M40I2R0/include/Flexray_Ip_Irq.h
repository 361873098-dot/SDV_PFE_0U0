/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXRAY
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
/**
*   @file Flexray_Ip_Irq.h
*
*   @brief Flexray Ip Irq Header File
*   @details Flexray Ip Irq Header File contains the APIs and structures exported by Flexray Driver
*   @implements Flexray_Ip_Irq.h_Artifact
*
*   @addtogroup Flexray
*   @{
*/

#ifndef FLEXRAY_IP_IRQ_H
#define FLEXRAY_IP_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include"Flexray_Ip.h"
#include "OsIf.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */

#define FLEXRAY_IP_IRQ_MODULE_ID                        81
#define FLEXRAY_IP_IRQ_VENDOR_ID                        43
#define FLEXRAY_IP_IRQ_AR_RELEASE_MAJOR_VERSION         4
#define FLEXRAY_IP_IRQ_AR_RELEASE_MINOR_VERSION         4
#define FLEXRAY_IP_IRQ_AR_RELEASE_REVISION_VERSION      0
#define FLEXRAY_IP_IRQ_SW_MAJOR_VERSION                 4
#define FLEXRAY_IP_IRQ_SW_MINOR_VERSION                 0
#define FLEXRAY_IP_IRQ_SW_PATCH_VERSION                 2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexray_Ip.h header file are of the same vendor */
#if(FLEXRAY_IP_IRQ_VENDOR_ID != FLEXRAY_IP_VENDOR_ID)
    #error "Flexray_Ip_Irq.h and Flexray_Ip.h have different Vendor IDs"
#endif
/* Check if current file and Flexray_Ip.h header file are of the same Autosar version */
#if((FLEXRAY_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != FLEXRAY_IP_AR_RELEASE_MAJOR_VERSION) || \
    (FLEXRAY_IP_IRQ_AR_RELEASE_MINOR_VERSION    != FLEXRAY_IP_AR_RELEASE_MINOR_VERSION) || \
    (FLEXRAY_IP_IRQ_AR_RELEASE_REVISION_VERSION != FLEXRAY_IP_AR_RELEASE_REVISION_VERSION))
    #error "Software Version Numbers of Flexray_Ip_Irq.h and Flexray_Ip.h are different"
#endif
/* Check if current file and Flexray_Ip.h header file are of the same software version */
#if((FLEXRAY_IP_IRQ_SW_MAJOR_VERSION != FLEXRAY_IP_SW_MAJOR_VERSION) || \
    (FLEXRAY_IP_IRQ_SW_MINOR_VERSION != FLEXRAY_IP_SW_MINOR_VERSION) || \
    (FLEXRAY_IP_IRQ_SW_PATCH_VERSION != FLEXRAY_IP_SW_PATCH_VERSION))
    #error "Autosar Version Numbers of Flexray_Ip_Irq.h and Flexray_Ip.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if((FLEXRAY_IP_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (FLEXRAY_IP_IRQ_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Flexray_Ip_Irq.h and OsIf.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION
==================================================================================================*/

/*==================================================================================================
*                                   FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"

#ifndef FLEXRAY_AUTOSAR_MODE_USED
void Flexray_Ip_TxIrq(uint8 instNum);
void Flexray_Ip_RxIrq(uint8 instNum);
void Flexray_Ip_PrIrq(uint8 instNum);
void Flexray_Ip_ChiIrq(uint8 instNum);
void Flexray_Ip_WupIrq(uint8 instNum);
void Flexray_Ip_FAFAIrq(uint8 instNum);
void Flexray_Ip_FAFBIrq(uint8 instNum);
#endif

#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
/*==================================================================================================
*                                   GLOBAL FUNCTION
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* FLEXRAY_IP_IRQ_H */
/** @} */

