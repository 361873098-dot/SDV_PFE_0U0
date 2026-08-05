/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LINFLEXD
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
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

#ifndef LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_H
#define LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Linflexd_Lin_Ip_TrustedFunctions.h
*
*   @addtogroup LINFLEXD_IP
*   @{
*/

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
#include "Linflexd_Lin_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_VENDOR_ID                      43
#define LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION       4
#define LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION       4
#define LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION    0
#define LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION               4
#define LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION               0
#define LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION               2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Linflexd_Lin_Ip_Cfg.h */
#if (LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_VENDOR_ID != LINFLEXD_LIN_IP_CFG_VENDOR_ID)
    #error "Linflexd_Lin_Ip_TrustedFunctions.h and Linflexd_Lin_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Linflexd_Lin_Ip_Cfg header file are of the same Autosar version */
#if ((LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_LIN_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != LINFLEXD_LIN_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != LINFLEXD_LIN_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Linflexd_Lin_Ip_TrustedFunctions.h and Linflexd_Lin_Ip_Cfg.h are different"
#endif
/* Check if current file and Linflexd_Lin_Ip_Cfg header file are of the same Software version */
#if ((LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != LINFLEXD_LIN_IP_CFG_SW_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != LINFLEXD_LIN_IP_CFG_SW_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != LINFLEXD_LIN_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Lin_Ip_TrustedFunctions.h and Linflexd_Lin_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                     STRUCTURES AND OTHERS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
#ifdef LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE
/**
* @brief        Enables LINFLEXD registers writing in User Mode by configuring REG_PROT
*
* @details      Sets the UAA (User Access Allowed) bit of the LINFLEXD IP allowing LINFLEXD registers writing in User Mode
*
* @param        none
* @retval       none
*
* @pre          The user mode is enabled
*
*/
extern void Linflexd_Lin_Ip_SetUserAccess(const uint8 u8Instance);

#endif /* LINFLEXD_LIN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE */
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINFLEXD_LIN_IP_TRUSTEDFUNCTIONS_H */
