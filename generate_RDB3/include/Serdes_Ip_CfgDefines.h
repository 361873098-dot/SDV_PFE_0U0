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
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*   (c) Copyright 2020-2023 NXP
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

#ifndef SERDES_IP_CFGDEFINES_H
#define SERDES_IP_CFGDEFINES_H

/**
*   @file       Serdes_Ip_CfgDefines.h
*
*   @addtogroup Serdes_IPL
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
#include "S32G399A_SERDES_GPR.h"
#include "S32G399A_SERDES_SS.h"
#include "S32G399A_PCIE_EP.h"
#include "S32G399A_PCIE_RC.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IP_CFGDEFINES_VENDOR_ID                     43
#define SERDES_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION      4
#define SERDES_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION      4
#define SERDES_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION   0
#define SERDES_IP_CFGDEFINES_SW_MAJOR_VERSION              4
#define SERDES_IP_CFGDEFINES_SW_MINOR_VERSION              0
#define SERDES_IP_CFGDEFINES_SW_PATCH_VERSION              2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define SERDES_0_XPCS1_2_5G
#define SERDES_1_XPCS1_2_5G
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SERDES_IP_CFGDEFINES_H */
