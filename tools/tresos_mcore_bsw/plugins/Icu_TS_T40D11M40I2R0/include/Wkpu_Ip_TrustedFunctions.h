/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm Siul2 Wkpu
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

#ifndef WKPU_IP_TRUSTEDFUNCTIONS_H
#define WKPU_IP_TRUSTEDFUNCTIONS_H

/**
 *     @file
 *
 *     @addtogroup wkpu_icu_ip WKPU IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Wkpu_Ip_Defines.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WKPU_IP_TRUSTEDFUNCTIONS_VENDOR_ID                    43
#define WKPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION     4
#define WKPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION     4
#define WKPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION  0
#define WKPU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION             4
#define WKPU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION             0
#define WKPU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Define header file are of the same vendor */
#if (WKPU_IP_TRUSTEDFUNCTIONS_VENDOR_ID != WKPU_IP_DEFINES_VENDOR_ID)
    #error "Wkpu_Ip_TrustedFunctions.h and Wkpu_Ip_Defines.h have different vendor IDs"
#endif
/* Check if this header  file and Define header file are of the same AutoSar version */
#if ((WKPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION  != WKPU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (WKPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION  != WKPU_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (WKPU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION   != WKPU_IP_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wkpu_Ip_TrustedFunctions.h and Wkpu_Ip_Defines.h are different"
#endif
/* Check if source file and Define header file are of the same Software version */
#if ((WKPU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION  != WKPU_IP_DEFINES_SW_MAJOR_VERSION) || \
     (WKPU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION  != WKPU_IP_DEFINES_SW_MINOR_VERSION) || \
     (WKPU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION  != WKPU_IP_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wkpu_Ip_TrustedFunctions.h and Wkpu_Ip_Defines.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      Wkpu_Ip_SetUserAccessAllowed
 * @details    This function is called externally by OS Application
 * @param[in]  GprBaseAddr - The base address of GPR module.
 */
#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)
    #if (defined(WKPU_IP_SUPPORT_PULL_CONTROL) && (WKPU_IP_SUPPORT_PULL_CONTROL == STD_ON))
        #if (STD_ON == WKPU_IP_ENABLE_USER_MODE_SUPPORT)
            extern void Wkpu_Ip_SetUserAccessAllowed(uint32 GprBaseAddr);
        #endif
    #endif
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* WKPU_IP_TRUSTEDFUNCTIONS_H */

