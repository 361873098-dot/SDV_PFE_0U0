/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SERDES_SS
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

#ifndef SERDES_IPW_PBCFG_H
#define SERDES_IPW_PBCFG_H

/**
*   @file
*   @internal
*   @addtogroup Serdes
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Serdes_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IPW_PBCFG_VENDOR_ID                     43
#define SERDES_IPW_PBCFG_MODULE_ID                     255
#define SERDES_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define SERDES_IPW_PBCFG_AR_RELEASE_MINOR_VERSION      4
#define SERDES_IPW_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define SERDES_IPW_PBCFG_SW_MAJOR_VERSION              4
#define SERDES_IPW_PBCFG_SW_MINOR_VERSION              0
#define SERDES_IPW_PBCFG_SW_PATCH_VERSION              2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Serdes_Ipw_Types.h file are of the same vendor */
#if (SERDES_IPW_PBCFG_VENDOR_ID  != SERDES_IPW_TYPES_VENDOR_ID)
    #error "Serdes_Ipw_Types.h and Serdes_Ipw_PBCfg.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ipw_Types.h file are of the same Autosar version */
#if ((SERDES_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION    != SERDES_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IPW_PBCFG_AR_RELEASE_MINOR_VERSION    != SERDES_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IPW_PBCFG_AR_RELEASE_REVISION_VERSION != SERDES_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ipw_PBCfg.h and Serdes_Ipw_Types.h are different"
#endif
/* Check if current file and Serdes_Ipw_Types.h file are of the same Software version */
#if ((SERDES_IPW_PBCFG_SW_MAJOR_VERSION != SERDES_IPW_TYPES_SW_MAJOR_VERSION) || \
     (SERDES_IPW_PBCFG_SW_MINOR_VERSION != SERDES_IPW_TYPES_SW_MINOR_VERSION) || \
     (SERDES_IPW_PBCFG_SW_PATCH_VERSION != SERDES_IPW_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Serdes_Ipw_PBCfg.h and Serdes_Ipw_Types.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

#define SERDES_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"


extern const Serdes_Ipw_HwChannelConfigType Serdes_Ipw_ChannelConfig0;

#define SERDES_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Serdes_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* #ifndef SERDES_IPW_PBCFG_H */
