/**
*   @file       Eth_43_PFE_Cfg.c
*   @implements Eth_43_PFE_Cfg.c_Artifact
*
*   @brief   AUTOSAR Eth_43_PFE driver Link-Time configuration file
*   @details File containing the configuration for the Ethernet driver
*   @note    This file was generated on [!"$date"!].
*
*   @addtogroup ETH_43_PFE_DRIVER_CONFIGURATION
*   @{
*/
/*==================================================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.4.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.4.0_D2405_ASR_REL_4_4_REV_0000_20240528
 *
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
 *      Copyright 2017-2023 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *  <<< PFE Restricted Software >>>
 *
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "pfe_cfg.h"
/* ETH001 */
#include "Eth_43_PFE.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_C                      43
#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       4
#define ETH_AR_RELEASE_REVISION_VERSION_C    0
#define ETH_SW_MAJOR_VERSION_C               1
#define ETH_SW_MINOR_VERSION_C               4
#define ETH_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


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

#define ETH_43_PFE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

[!INCLUDE "Eth_43_PFE_GetDemParameters.m"!]
[!AUTOSPACING!][!//
/*******************************************************************************
* Configuration parameters
*******************************************************************************/
[!SELECT "EthConfigSet"!][!// Select configuration
[!LOOP "EthCtrlConfig/*"!] [!// Loop over the controller config
[!VAR "CtrlConfigName" = "as:name(.)"!]
[!VAR "BufCountIndex" = "0"!]
/**
* @var Specified for EthCtrlConfig: [!"@name"!]
* @par Memory usage:
*/
static const Eth_43_PFE_StaticCtrlCfgType Eth_43_PFE_Static[!"$CtrlConfigName"!] =
{
  [!IF "EthCtrlEnableRxInterrupt = 'true'"!][!//
    ((boolean)TRUE),        /**< RX interrupt enabled */
  [!ELSE!][!//
    ((boolean)FALSE),       /**< RX interrupt disabled */
  [!ENDIF!][!//
  [!IF "EthCtrlEnableTxInterrupt = 'true'"!][!//
    ((boolean)TRUE),        /**< TX interrupt enabled */
  [!ELSE!][!//
    ((boolean)FALSE),       /**< TX interrupt disabled */
  [!ENDIF!][!//
    ((boolean)FALSE),       /**< This controller does not support MDIO */
};
  [!VAR "BufCountIndex"="$BufCountIndex+1"!]
[!CR!]
[!ENDLOOP!][!//End loop of controller
[!ENDSELECT!][!//
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/**
* @brief         Driver configuration to be passed to Eth_43_PFE_Init function
* @details       This array contains reference to the Link-Time configuration
*                to be used for the Eth driver configuration.
*/
[!SELECT "EthConfigSet"!][!// Select configuration
const Eth_43_PFE_StaticConfigType Eth_43_PFE_StaticConfig = 
{
    {
[!VAR "NumCtrl" = "count(EthCtrlConfig/*)"!]
[!FOR "Idx" = "0" TO "num:i($NumCtrl)-1"!]
    [!SELECT "EthCtrlConfig/*"!]
        [!IF "num:i($Idx) = num:i(./EthCtrlIdx)"!]
        &Eth_43_PFE_Static[!"as:name(.)"!],
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDFOR!]
    },
};
[!ENDSELECT!]

#define ETH_43_PFE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
