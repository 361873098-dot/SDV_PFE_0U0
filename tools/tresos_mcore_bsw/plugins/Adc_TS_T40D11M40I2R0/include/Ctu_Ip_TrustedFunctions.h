/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
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

#ifndef CTU_IP_TRUSTEDFUNCTIONS_H
#define CTU_IP_TRUSTEDFUNCTIONS_H

/**
*   @file
*
*   @addtogroup ctu_ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ctu_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CTU_IP_VENDOR_ID_TRUSTEDFUNCTIONS                      43
#define CTU_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS       4
#define CTU_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS       4
#define CTU_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS    0
#define CTU_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS               4
#define CTU_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS               0
#define CTU_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS               2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Ctu_Ip_TrustedFunctions.h file and Ctu_Ip_CfgDefines.h file are of the same vendor */
#if (CTU_IP_VENDOR_ID_TRUSTEDFUNCTIONS != CTU_IP_VENDOR_ID_CFGDEFINES)
    #error "Ctu_Ip_TrustedFunctions.h and Ctu_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Ctu_Ip_TrustedFunctions.h file and Ctu_Ip_CfgDefines.h file are of the same Autosar version */
#if ((CTU_IP_AR_RELEASE_MAJOR_VERSION_TRUSTEDFUNCTIONS != CTU_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (CTU_IP_AR_RELEASE_MINOR_VERSION_TRUSTEDFUNCTIONS != CTU_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (CTU_IP_AR_RELEASE_REVISION_VERSION_TRUSTEDFUNCTIONS != CTU_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES) \
    )
    #error "AutoSar Version Numbers of Ctu_Ip_TrustedFunctions.h and Ctu_Ip_CfgDefines.h are different"
#endif

/* Check if Ctu_Ip_TrustedFunctions.h file and Ctu_Ip_CfgDefines.h file are of the same Software version */
#if ((CTU_IP_SW_MAJOR_VERSION_TRUSTEDFUNCTIONS != CTU_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (CTU_IP_SW_MINOR_VERSION_TRUSTEDFUNCTIONS != CTU_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (CTU_IP_SW_PATCH_VERSION_TRUSTEDFUNCTIONS != CTU_IP_SW_PATCH_VERSION_CFGDEFINES) \
    )
  #error "Software Version Numbers of Ctu_Ip_TrustedFunctions.h and Ctu_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT)
/**
* @brief        Sets the UAA bit in REG_PROT to make the instance accessible in user mode
* @details      Sets the UAA bit in REG_PROT to make the instance accessible in user mode
*
* @param[in]    CtuBasePtr       Peripheral CTU base pointer. (Eg: IP_CTU getting from Base header files)
* @retval       none
*
* @pre          The user mode is enabled
*
*/
extern void Ctu_Ip_SetUserAccessAllowed(const CTU_Type * const CtuBasePtr);

/**
* @brief        Clears the UAA bit in REG_PROT to make the instance inaccessible in user mode.
* @details      Clears the UAA bit in REG_PROT to make the instance inaccessible in user mode.
*
* @param[in]    CtuBasePtr       Peripheral CTU base pointer. (Eg: IP_CTU getting from Base header files)
* @retval       none
*
* @pre          The user mode is enabled
*
*/
extern void Ctu_Ip_ClrUserAccessAllowed(const CTU_Type * const CtuBasePtr);

#endif /* (STD_ON == CTU_IP_ENABLE_USER_MODE_SUPPORT) */

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CTU_IP_TRUSTEDFUNCTIONS_H */
