/**
*   @file       Eth_43_PFE_PBcfg.c
*   @implements Eth_43_PFE_PBcfg.c_Artifact
*
*   @brief   AUTOSAR Eth_43_PFE driver Post-Build configuration file
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
 *      Copyright 2017-2024 NXP
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
#include "pfe_ct.h"
/* ETH001 */
#include "Eth_43_PFE.h"

#if (STD_ON == ETH_43_PFE_CTRLENABLE_MII)
[!NOCODE!]
[!VAR "EthTrcvHeaderTable" = "''"!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
    [!IF "EthVendorSpecific/EthEthTrcvDriverVendorIdAndApiInfix != string(null)"!]
        [!VAR "HeaderName" = "concat('EthTrcv_',EthVendorSpecific/EthEthTrcvDriverVendorIdAndApiInfix)"!]
    [!ELSE!]
        [!VAR "HeaderName" = "'EthTrcv'"!]
    [!ENDIF!]
    [!IF "not(text:contains(text:split($EthTrcvHeaderTable), $HeaderName))"!]
[!CODE!][!//
    #include "[!"$HeaderName"!].h"
[!ENDCODE!]
    [!ENDIF!]
    [!VAR "EthTrcvHeaderTable" = "concat($EthTrcvHeaderTable, ' ', $HeaderName)"!]
[!ENDLOOP!]
[!ENDNOCODE!][!//
#endif

#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
[!NOCODE!]
[!VAR "EthSwtHeaderTable" = "''"!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
    [!IF "EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix != string(null)"!]
        [!VAR "HeaderName" = "concat('EthSwt_',EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix)"!]
    [!ELSE!]
        [!VAR "HeaderName" = "'EthSwt'"!]
    [!ENDIF!]
    [!IF "not(text:contains(text:split($EthSwtHeaderTable), $HeaderName))"!]
[!CODE!][!//
    #include "[!"$HeaderName"!].h"
[!ENDCODE!]
    [!ENDIF!]
    [!VAR "EthSwtHeaderTable" = "concat($EthSwtHeaderTable, ' ', $HeaderName)"!]
[!ENDLOOP!]
[!ENDNOCODE!][!//
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_PFE_VENDOR_ID_C                      43
#define ETH_43_PFE_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_43_PFE_AR_RELEASE_MINOR_VERSION_C       4
#define ETH_43_PFE_AR_RELEASE_REVISION_VERSION_C    0
#define ETH_43_PFE_SW_MAJOR_VERSION_C               1
#define ETH_43_PFE_SW_MINOR_VERSION_C               4
#define ETH_43_PFE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!AUTOSPACING!][!//
[!NOCODE!][!//
[!/*
*************************************
* Error checks of the configuration *
*************************************
*/!]
  [!INCLUDE "Eth_43_PFE_VersionChecks.m"!]
  [!INCLUDE "Eth_43_PFE_Checks.m"!]
  [!INCLUDE "Eth_43_PFE_GetDemParameters.m"!]
  [!INCLUDE "Eth_43_PFE_GetPfeParameters.m"!][!// Macros for calculation of values related to buffers
[!ENDNOCODE!][!//
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
[!MACRO "GetMacLayerType2"!][!//
[!NOCODE!]
    [!VAR "MacLayer" = "string(null)"!]

    [!IF "(node:empty(/EthGeneral/EthVendorSpecific/EthPfeSlaveMode)='false' and ../EthPfeSlaveMode='true') or (node:empty(EthCtrlMacLayerType)='true')"!]
        [!VAR "MacLayer" = "'INVALID'"!]
    [!ELSE!]
        [!IF "substring-after(EthCtrlMacLayerType, 'ETH_MAC_LAYER_TYPE_') = 'XMII'"!]
            [!IF "EthCtrlMacLayerSubType = 'STANDARD'"!]
                [!VAR "MacLayer" = "'MII'"!]
            [!ELSEIF "EthCtrlMacLayerSubType = 'REDUCED'"!]
                [!VAR "MacLayer" = "'RMII'"!]
            [!ENDIF!]
        [!ELSEIF "substring-after(EthCtrlMacLayerType, 'ETH_MAC_LAYER_TYPE_') = 'XGMII'"!]
            [!IF "EthCtrlMacLayerSubType = 'SERIAL'"!]
                [!VAR "MacLayer" = "'SGMII'"!]
            [!ELSEIF "EthCtrlMacLayerSubType = 'REDUCED'"!]
                [!VAR "MacLayer" = "'RGMII'"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$MacLayer = string(null)"!][!ERROR!]Unknown or unsupported media independent interface! ([!"EthCtrlMacLayerSubType"!])[!ENDERROR!][!ENDIF!]
    [!CODE!][!"$MacLayer"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetMacLayerSpeed2"!][!//
[!NOCODE!]
    [!VAR "MacSpeed" = "string(null)"!]

    [!IF "(node:empty(/EthGeneral/EthVendorSpecific/EthPfeSlaveMode)='false' and ../EthPfeSlaveMode='true') or (node:empty(EthCtrlMacLayerSpeed)='true')"!]
        [!VAR "MacSpeed" = "'INVALID'"!]
    [!ELSE!]
        [!IF "substring-after(EthCtrlMacLayerSpeed, 'ETH_MAC_LAYER_SPEED_') = '10M'"!]
            [!VAR "MacSpeed" = "'10_MBPS'"!]
        [!ELSEIF "substring-after(EthCtrlMacLayerSpeed, 'ETH_MAC_LAYER_SPEED_') = '100M'"!]
            [!VAR "MacSpeed" = "'100_MBPS'"!]
        [!ELSEIF "substring-after(EthCtrlMacLayerSpeed, 'ETH_MAC_LAYER_SPEED_') = '1G'"!]
            [!VAR "MacSpeed" = "'1000_MBPS'"!]
        [!ELSEIF "substring-after(EthCtrlMacLayerSpeed, 'ETH_MAC_LAYER_SPEED_') = '2500M'"!]
            [!VAR "MacSpeed" = "'2500_MBPS'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$MacSpeed = string(null)"!][!ERROR!]Unsupported mac speed! ([!"EthCtrlMacLayerSpeed"!])[!ENDERROR!][!ENDIF!]
    [!CODE!][!"$MacSpeed"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//\

[!MACRO "GetMacDuplexMode2"!][!//
[!NOCODE!]
    [!VAR "MacDuplex" = "string(null)"!]

    [!IF "(node:empty(/EthGeneral/EthVendorSpecific/EthPfeSlaveMode)='false' and ../EthPfeSlaveMode='true') or (node:empty(EthDuplexMode)='true')"!]
        [!VAR "MacDuplex" = "'INVALID'"!]
    [!ELSE!]
        [!IF "EthDuplexMode = 'ETH_FULL_DUPLEX'"!]
            [!VAR "MacDuplex" = "'FULL'"!]
        [!ELSEIF "EthDuplexMode = 'ETH_HALF_DUPLEX'"!]
            [!VAR "MacDuplex" = "'HALF'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$MacDuplex = string(null)"!][!ERROR!]Unsupported duplex mode! ([!"EthVendorSpecific/EthDuplexMode"!])[!ENDERROR!][!ENDIF!]
    [!CODE!][!"$MacDuplex"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetMacLayerType"!][!//
[!NOCODE!]
    [!VAR "MacLayer" = "string(null)"!]

    [!IF "(../../../EthGeneral/EthVendorSpecific/EthPfeMultiInstance='true' and ../../../EthGeneral/EthVendorSpecific/EthPfeSlaveMode='true') or (EthVendorSpecific/EthCtrlHwPort!='EMAC0' and EthVendorSpecific/EthCtrlHwPort!='EMAC1' and EthVendorSpecific/EthCtrlHwPort!='EMAC2') or node:empty(EthCtrlMacLayerSubType)"!]
        [!VAR "MacLayer" = "'INVALID'"!]
    [!ELSE!]
        [!IF "substring-after(EthCtrlMacLayerType, 'ETH_MAC_LAYER_TYPE_') = 'XMII'"!]
            [!IF "EthCtrlMacLayerSubType = 'STANDARD'"!]
                [!VAR "MacLayer" = "'MII'"!]
            [!ELSEIF "EthCtrlMacLayerSubType = 'REDUCED'"!]
                [!VAR "MacLayer" = "'RMII'"!]
            [!ENDIF!]
        [!ELSEIF "substring-after(EthCtrlMacLayerType, 'ETH_MAC_LAYER_TYPE_') = 'XGMII'"!]
            [!IF "EthCtrlMacLayerSubType = 'SERIAL'"!]
                [!VAR "MacLayer" = "'SGMII'"!]
            [!ELSEIF "EthCtrlMacLayerSubType = 'REDUCED'"!]
                [!VAR "MacLayer" = "'RGMII'"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$MacLayer = string(null)"!][!ERROR!]Unknown or unsupported media independent interface! ([!"EthCtrlMacLayerSubType"!])[!ENDERROR!][!ENDIF!]
    [!CODE!][!"$MacLayer"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetMacLayerSpeed"!][!//
[!NOCODE!]
    [!VAR "MacSpeed" = "string(null)"!]

    [!IF "node:empty(EthCtrlMacLayerSpeed)"!]
        [!VAR "MacSpeed" = "'INVALID'"!]
    [!ELSE!]
        [!IF "substring-after(EthCtrlMacLayerSpeed, 'ETH_MAC_LAYER_SPEED_') = '10M'"!]
            [!VAR "MacSpeed" = "'10_MBPS'"!]
        [!ELSEIF "substring-after(EthCtrlMacLayerSpeed, 'ETH_MAC_LAYER_SPEED_') = '100M'"!]
            [!VAR "MacSpeed" = "'100_MBPS'"!]
        [!ELSEIF "substring-after(EthCtrlMacLayerSpeed, 'ETH_MAC_LAYER_SPEED_') = '1G'"!]
            [!VAR "MacSpeed" = "'1000_MBPS'"!]
        [!ELSEIF "substring-after(EthCtrlMacLayerSpeed, 'ETH_MAC_LAYER_SPEED_') = '2500M'"!]
            [!VAR "MacSpeed" = "'2500_MBPS'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$MacSpeed = string(null)"!][!ERROR!]Unsupported mac speed! ([!"EthCtrlMacLayerSpeed"!])[!ENDERROR!][!ENDIF!]
    [!CODE!][!"$MacSpeed"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//\

[!MACRO "GetMacDuplexMode"!][!//
[!NOCODE!]
    [!VAR "MacDuplex" = "string(null)"!]

    [!IF "node:empty(EthVendorSpecific/EthDuplexMode)"!]
        [!VAR "MacDuplex" = "'INVALID'"!]
    [!ELSE!]
        [!IF "EthVendorSpecific/EthDuplexMode = 'ETH_FULL_DUPLEX'"!]
            [!VAR "MacDuplex" = "'FULL'"!]
        [!ELSEIF "EthVendorSpecific/EthDuplexMode = 'ETH_HALF_DUPLEX'"!]
            [!VAR "MacDuplex" = "'HALF'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$MacDuplex = string(null)"!][!ERROR!]Unsupported duplex mode! ([!"EthVendorSpecific/EthDuplexMode"!])[!ENDERROR!][!ENDIF!]
    [!CODE!][!"$MacDuplex"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetEthCtrlEgressPrioToFifoIdx"!][!//
[!NOCODE!]
    [!FOR "Priority" = "0" TO "7"!]
        [!VAR "EgressFifoIdx" = "0"!]
        [!LOOP "EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*/EthCtrlConfigEgressFifoPriorityAssignment/*"!]
            [!IF "num:i($Priority) = num:i(.)"!]
                [!VAR "EgressFifoIdx" = "num:i(../../EthCtrlConfigEgressFifoIdx)"!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!CODE!][!"num:i($EgressFifoIdx)"!]U[!IF "$Priority < 7"!], [!ENDIF!][!ENDCODE!]
    [!ENDFOR!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetSchedulerAlgorithm"!][!//
[!NOCODE!]
    [!VAR "SchAlgo" = "string(null)"!]
    [!VAR "NodeValue" = "EthCtrlConfigSchedulerVendorSpecific/EthCtrlConfigSchedulerAlgorithm"!]

    [!IF "$NodeValue = 'SCHED_ALGO_RR'"!]
        [!VAR "SchAlgo" = "'RR'"!]
    [!ELSEIF "$NodeValue = 'SCHED_ALGO_WRR'"!]
        [!VAR "SchAlgo" = "'WRR'"!]
    [!ELSEIF "$NodeValue = 'SCHED_ALGO_DWRR'"!]
        [!VAR "SchAlgo" = "'DWRR'"!]
    [!ELSEIF "$NodeValue = 'SCHED_ALGO_PQ'"!]
        [!VAR "SchAlgo" = "'PQ'"!]
    [!ENDIF!]

    [!IF "$SchAlgo = string(null)"!][!ERROR!]Unknown or unsupported Scheduler Algorithm! ([!"$NodeValue"!])[!ENDERROR!][!ENDIF!]
    [!CODE!][!"$SchAlgo"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetSchedulerRateMode"!][!//
[!NOCODE!]
    [!VAR "SchRateMode" = "string(null)"!]
    [!VAR "NodeValue" = "EthCtrlConfigSchedulerVendorSpecific/EthCtrlConfigSchedulerRateMode"!]

    [!IF "$NodeValue = 'RATE_MODE_PACKET_RATE'"!]
        [!VAR "SchRateMode" = "'PACKET_RATE'"!]
    [!ELSEIF "$NodeValue = 'RATE_MODE_DATA_RATE'"!]
        [!VAR "SchRateMode" = "'DATA_RATE'"!]
    [!ENDIF!]

    [!IF "$SchRateMode = string(null)"!][!ERROR!]Unknown or unsupported Scheduler Rate mode! ([!"$NodeValue"!])[!ENDERROR!][!ENDIF!]
    [!CODE!][!"$SchRateMode"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetSchedulerWeight"!][!//
[!NOCODE!]
    [!VAR "Weight" = "0"!]
    [!VAR "SchAlgo" = "../../EthCtrlConfigSchedulerVendorSpecific/EthCtrlConfigSchedulerAlgorithm"!]
    [!VAR "Bandwidth" = "EthCtrlConfigSchedulerPredecessorVendorSpecific/EthCtrlConfigSchedulerBandwidth"!]

    [!IF "$SchAlgo = 'SCHED_ALGO_RR'"!]
        [!VAR "Weight" = "0"!]
    [!ELSEIF "$SchAlgo = 'SCHED_ALGO_WRR'"!]
        [!VAR "MaxWeightInPackets" = "node:value(../../EthCtrlConfigSchedulerVendorSpecific/EthCtrlConfigTotalPacketsPerCycle)"!]
        [!VAR "Weight" = "round(($Bandwidth div 100) * $MaxWeightInPackets)"!]
    [!ELSEIF "$SchAlgo = 'SCHED_ALGO_DWRR'"!]
        [!VAR "MaxQuantumInBytes" = "node:value(../../EthCtrlConfigSchedulerVendorSpecific/EthCtrlConfigTotalQuantumPerCycle)"!]
        [!VAR "Weight" = "round(($Bandwidth div 100) * $MaxQuantumInBytes)"!]
    [!ELSEIF "$SchAlgo = 'SCHED_ALGO_PQ'"!]
        [!VAR "Weight" = "0"!]
    [!ELSE!]
        [!ERROR!]Unknown or unsupported Scheduler Algorithm! ([!"$SchedulerAlgorithm"!])[!ENDERROR!]
    [!ENDIF!]

    [!VAR "PARAM_WEIGHT" = "num:i($Weight)"!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

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
/*******************************************************************************
* Multiple configurations
*******************************************************************************/
[!AUTOSPACING!]
[!SELECT "EthConfigSet"!][!// Select configuration
[!VAR "ConfigSet" = "as:name(.)"!]
[!LOOP "EthCtrlConfig/*"!] [!// Loop over the controller config
[!VAR "CtrlConfigName" = "name(.)"!]

[!IF "node:exists(EthCtrlConfigEgress/EthCtrlConfigScheduler)"!]
[!LOOP "EthCtrlConfigEgress/EthCtrlConfigScheduler/*"!]
[!VAR "CtrlSchedulerConfigName" = "name(.)"!]
static const Eth_43_PFE_SchedulerInputInfoCfgType Eth_43_PFE_InputInfo_PBConfig[!"$CtrlConfigName"!]_[!"$CtrlSchedulerConfigName"!][] =
{
    [!INDENT "4"!]
    [!VAR "LOOP_COUNT1"="num:i(count(EthCtrlConfigSchedulerPredecessor/*))"!]
    [!VAR "END_COMMA1"="0"!]
    [!LOOP "EthCtrlConfigSchedulerPredecessor/*"!]
    [!VAR "END_COMMA1"="$END_COMMA1 + 1"!]
    {
        [!INDENT "8"!]
        [!"EthCtrlConfigSchedulerPredecessorOrder"!]U,
        [!CALL "GetSchedulerWeight"!]
        [!"$PARAM_WEIGHT"!]U,
        [!IF "node:exists(node:ref(EthCtrlConfigSchedulerPredecessorRef)/EthCtrlConfigEgressFifoIdx)"!]
            IS_FIFO,
            [!"num:i(node:ref(EthCtrlConfigSchedulerPredecessorRef)/EthCtrlConfigEgressFifoIdx)"!]U
        [!ELSEIF "node:exists(node:ref(EthCtrlConfigSchedulerPredecessorRef)/EthCtrlConfigShaperVendorSpecific/EthCtrlConfigShaperIdx)"!]
            IS_SHAPER,
            [!"num:i(node:ref(EthCtrlConfigSchedulerPredecessorRef)/EthCtrlConfigShaperVendorSpecific/EthCtrlConfigShaperIdx)"!]U
        [!ELSE!]
            IS_SHEDULER,
            0U
        [!ENDIF!]
        [!ENDINDENT!]
    }[!IF "$END_COMMA1 < $LOOP_COUNT1"!],[!CR!][!ELSE!][!WS "1"!][!ENDIF!]
    [!ENDLOOP!][!CR!]
    [!ENDINDENT!]
};
[!ENDLOOP!][!CR!]

static const Eth_43_PFE_SchedulerCfgType Eth_43_PFE_Scheduler_PBConfig[!"$CtrlConfigName"!][] =
{
    [!INDENT "4"!]
    [!VAR "LOOP_COUNT1"="num:i(count(EthCtrlConfigEgress/EthCtrlConfigScheduler/*))"!]
    [!VAR "END_COMMA1"="0"!]
    [!LOOP "EthCtrlConfigEgress/EthCtrlConfigScheduler/*"!]
    [!VAR "CtrlSchedulerConfigName" = "name(.)"!]
    [!VAR "END_COMMA1"="$END_COMMA1 + 1"!]
    {
        [!INDENT "8"!]
        [!IF "node:name(node:ref(../../EthCtrlConfigEgressLastSchedulerRef))=node:name(node:current())"!]
            ((boolean)TRUE),
        [!ELSE!]
            ((boolean)FALSE),
        [!ENDIF!]
        SCHED_ALGO_[!CALL "GetSchedulerAlgorithm"!],
        RATE_MODE_[!CALL "GetSchedulerRateMode"!],
        [!"num:i(count(EthCtrlConfigSchedulerPredecessor/*))"!]U,
        Eth_43_PFE_InputInfo_PBConfig[!"$CtrlConfigName"!]_[!"$CtrlSchedulerConfigName"!]
        [!ENDINDENT!]
    }[!IF "$END_COMMA1 < $LOOP_COUNT1"!],[!CR!][!ELSE!][!WS "1"!][!ENDIF!]
    [!ENDLOOP!][!CR!]
    [!ENDINDENT!]
};
[!ENDIF!]

[!IF "(node:exists(EthCtrlConfigEgress/EthCtrlConfigShaper)) and (num:i(count(EthCtrlConfigEgress/EthCtrlConfigShaper/*)) > '0')"!]
static const Eth_43_PFE_ShaperCfgType Eth_43_PFE_Shaper_PBConfig[!"$CtrlConfigName"!][] =
{
    [!INDENT "4"!]
    [!VAR "LOOP_COUNT1"="num:i(count(EthCtrlConfigEgress/EthCtrlConfigShaper/*))"!]
    [!VAR "END_COMMA1"="0"!]
    [!LOOP "EthCtrlConfigEgress/EthCtrlConfigShaper/*"!]
    [!VAR "END_COMMA1"="$END_COMMA1 + 1"!]
    {
        [!INDENT "8"!]
        [!"num:i(EthCtrlConfigShaperVendorSpecific/EthCtrlConfigShaperIdx)"!]U,
        [!"num:i(EthCtrlConfigShaperIdleSlope)"!]U,
        [!"num:i(EthCtrlConfigShaperVendorSpecific/EthCtrlConfigShaperMaxCredit)"!],
        [!"num:i(EthCtrlConfigShaperVendorSpecific/EthCtrlConfigShaperMinCredit)"!],
        [!"num:i(node:ref(EthCtrlConfigShaperPredecessorFifoRef)/EthCtrlConfigEgressFifoIdx)"!]U
        [!ENDINDENT!]
    }[!IF "$END_COMMA1 < $LOOP_COUNT1"!],[!CR!][!ELSE!][!WS "1"!][!ENDIF!]
    [!ENDLOOP!][!CR!]
    [!ENDINDENT!]
};
[!ENDIF!]
#define ETH_43_PFE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
/*
* @brief HIF driver per controller client static FIFO definitions
*/
static Pfe_Hif_Drv_Client_FIFOs_[!"$ConfigSet"!]_[!"$CtrlConfigName"!]_t Pfe_Hif_Drv_Client_FIFOs_[!"$ConfigSet"!]_[!"$CtrlConfigName"!];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static const Eth_43_PFE_EgressTxCfgType Eth_43_PFE_Egress_PBConfig[!"$CtrlConfigName"!][] =
{
    [!INDENT "4"!]
    [!VAR "LOOP_COUNT1"="num:i(count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*))"!]
    [!VAR "END_COMMA1"="0"!]
    [!LOOP "EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*"!]
    [!VAR "END_COMMA1"="$END_COMMA1 + 1"!]
    {
        [!INDENT "8"!]
        Pfe_Hif_Drv_Client_FIFOs_[!"$ConfigSet"!]_[!"$CtrlConfigName"!].tx_conf_fifo,
        Pfe_Hif_Drv_Client_FIFOs_[!"$ConfigSet"!]_[!"$CtrlConfigName"!].tx_conf_fifo_data,
        [!IF "../../../../../../EthGeneral/EthVendorSpecific/EthCommonHif = 'HIF_NOCPY'"!]
            (uint16)1522U,
            (uint16)0U, /* Using BMU buffers instead */
        [!ELSE!]
            (uint16)[!"num:i(EthCtrlConfigEgressFifoBufLenByte)"!]U,
            (uint16)[!"num:i(num:i((EthCtrlConfigEgressFifoBufLenByte + 7 + 16) div 8) * 8)"!]U,
        [!ENDIF!]
        (uint16)[!"num:i(EthCtrlConfigEgressFifoBufTotal)"!]U
        [!ENDINDENT!]
    }[!IF "$END_COMMA1 < $LOOP_COUNT1"!],[!CR!][!ELSE!][!WS "1"!][!ENDIF!]
    [!ENDLOOP!][!CR!]
    [!ENDINDENT!]
};

static const Eth_43_PFE_IngressCfgType Eth_43_PFE_Ingress_PBConfig[!"$CtrlConfigName"!][] =
{
    [!INDENT "4"!]
    [!VAR "LOOP_COUNT1"="num:i(count(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*))"!]
    [!VAR "END_COMMA1"="0"!]
    [!LOOP "node:order(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*, 'node:value(EthCtrlConfigIngressFifoIdx)')"!]
        [!VAR "END_COMMA1"="$END_COMMA1 + 1"!]
        {
            [!INDENT "8"!]
            Pfe_Hif_Drv_Client_FIFOs_[!"$ConfigSet"!]_[!"$CtrlConfigName"!].rx_fifo,
            Pfe_Hif_Drv_Client_FIFOs_[!"$ConfigSet"!]_[!"$CtrlConfigName"!].rx_fifo_data,
            (uint16)[!"num:i(1522)"!]U,[!//1522 for EthCtrlConfigIngressFifoBufLenByte
            (uint16)[!"num:i(EthCtrlConfigIngressFifoBufTotal)"!]U
            [!ENDINDENT!]
        }[!IF "$END_COMMA1 < $LOOP_COUNT1"!],[!CR!][!ELSE!][!WS "1"!][!ENDIF!]
    [!ENDLOOP!][!CR!]
    [!ENDINDENT!]
};
[!ENDLOOP!]
[!ENDSELECT!]

static const Eth_43_PFE_EmacCfg PfeEthConfigSet_EMAC[] =
{
    {
[!SELECT "EthGeneral/EthVendorSpecific/EthEMAC0Config"!]
        EMAC_MODE_[!CALL "GetMacLayerType2"!],
        EMAC_SPEED_[!CALL "GetMacLayerSpeed2"!],
        EMAC_DUPLEX_[!CALL "GetMacDuplexMode2"!],
[!ENDSELECT!]
[!SELECT "EthGeneral/EthVendorSpecific/EthEMAC0Config/EthEMAC0QueueSizes"!]
        {[!"EMAC0Q0Size"!], [!"EMAC0Q1Size"!], [!"EMAC0Q2Size"!], [!"EMAC0Q3Size"!], [!"EMAC0Q4Size"!], [!"EMAC0Q5Size"!], [!"EMAC0Q6Size"!], [!"EMAC0Q7Size"!]}
[!ENDSELECT!]
    },
    {
[!SELECT "EthGeneral/EthVendorSpecific/EthEMAC1Config"!]
        EMAC_MODE_[!CALL "GetMacLayerType2"!],
        EMAC_SPEED_[!CALL "GetMacLayerSpeed2"!],
        EMAC_DUPLEX_[!CALL "GetMacDuplexMode2"!],
[!ENDSELECT!]
[!SELECT "EthGeneral/EthVendorSpecific/EthEMAC1Config/EthEMAC1QueueSizes"!]
        {[!"EMAC1Q0Size"!], [!"EMAC1Q1Size"!], [!"EMAC1Q2Size"!], [!"EMAC1Q3Size"!], [!"EMAC1Q4Size"!], [!"EMAC1Q5Size"!], [!"EMAC1Q6Size"!], [!"EMAC1Q7Size"!]}
[!ENDSELECT!]
    },
    {
[!SELECT "EthGeneral/EthVendorSpecific/EthEMAC2Config"!]
        EMAC_MODE_[!CALL "GetMacLayerType2"!],
        EMAC_SPEED_[!CALL "GetMacLayerSpeed2"!],
        EMAC_DUPLEX_[!CALL "GetMacDuplexMode2"!],
[!ENDSELECT!]
[!SELECT "EthGeneral/EthVendorSpecific/EthEMAC2Config/EthEMAC2QueueSizes"!]
        {[!"EMAC2Q0Size"!], [!"EMAC2Q1Size"!], [!"EMAC2Q2Size"!], [!"EMAC2Q3Size"!], [!"EMAC2Q4Size"!], [!"EMAC2Q5Size"!], [!"EMAC2Q6Size"!], [!"EMAC2Q7Size"!]}
[!ENDSELECT!]
    }
};

/**
* @var Specified for EthCtrlConfig: [!"@name"!]
* @par Memory usage:
*/
[!SELECT "EthConfigSet"!][!// Select configuration
  [!VAR "ConfigSet" = "as:name(.)"!]
  [!LOOP "EthCtrlConfig/*"!]
    [!CALL "GetDemParameters"!]
    [!VAR "CtrlConfigName" = "name(.)"!]
static const Eth_43_PFE_CtrlCfgType Pfe[!"$ConfigSet"!]_[!"$CtrlConfigName"!] =
{
    [!INDENT "4"!]
    [!NOCODE!]
      [!IF "node:exists(EthCtrlPhyAddress)"!]
        [!VAR "MACAddrString"="EthCtrlPhyAddress"!]
        [!VAR "PhysAddress"="concat('0x',text:replaceAll($MACAddrString, ':',''))"!]
        [!VAR "PhysAddress"="num:hextoint($PhysAddress)"!]
      [!ELSE!]
        [!VAR "MACAddrString"="'00:00:00:00:00:00'"!]
        [!VAR "PhysAddress"="0"!]
      [!ENDIF!]
      [!VAR "MACAddr0" = "num:i(num:div($PhysAddress,1099511627776))"!][!//Get first number
      [!VAR "MACAddr1" = "num:i(num:div(num:mod($PhysAddress,1099511627776),4294967296))"!][!//
      [!VAR "MACAddr2" = "num:i(num:div(num:mod($PhysAddress,4294967296),16777216))"!][!//
      [!VAR "MACAddr3" = "num:i(num:div(num:mod($PhysAddress,16777216),65536))"!][!//
      [!VAR "MACAddr4" = "num:i(num:div(num:mod($PhysAddress,65536),256))"!][!//
      [!VAR "MACAddr5" = "num:i(num:mod($PhysAddress,256))"!][!//Get last number
    [!ENDNOCODE!]
    {[!"num:inttohex($MACAddr0,2)"!], [!"num:inttohex($MACAddr1,2)"!], [!"num:inttohex($MACAddr2,2)"!], [!"num:inttohex($MACAddr3,2)"!], [!"num:inttohex($MACAddr4,2)"!], [!"num:inttohex($MACAddr5,2)"!] }, /**< MAC address */
    [!IF "EthVendorSpecific/EthCtrlHwPort = 'EMAC0'"!]
    PFE_PHY_IF_ID_EMAC0, /**< Port to be attached to the controller */
    PFE_CTRL_TYPE_EMAC, /**< Type of the controller */
    [!ENDIF!]
    [!IF "EthVendorSpecific/EthCtrlHwPort = 'EMAC1'"!]
    PFE_PHY_IF_ID_EMAC1, /**< Port to be attached to the controller */
    PFE_CTRL_TYPE_EMAC, /**< Type of the controller */
    [!ENDIF!]
    [!IF "EthVendorSpecific/EthCtrlHwPort = 'EMAC2'"!]
    PFE_PHY_IF_ID_EMAC2, /**< Port to be attached to the controller */
    PFE_CTRL_TYPE_EMAC, /**< Type of the controller */
    [!ENDIF!]
    [!IF "EthVendorSpecific/EthCtrlHwPort = 'AUX'"!]
    PFE_PHY_IF_ID_INVALID, /**< No HW port attached to AUX controller */
    PFE_CTRL_TYPE_AUX, /**< Type of the controller */
    [!ENDIF!]
    [!IF "EthVendorSpecific/EthCtrlHwPort = 'HIF0'"!]
    PFE_PHY_IF_ID_HIF0, /**< Port to be attached to the controller */
    PFE_CTRL_TYPE_HIF, /**< Type of the controller */
    [!ENDIF!]
    [!IF "EthVendorSpecific/EthCtrlHwPort = 'HIF1'"!]
    PFE_PHY_IF_ID_HIF1, /**< Port to be attached to the controller */
    PFE_CTRL_TYPE_HIF, /**< Type of the controller */
    [!ENDIF!]
    [!IF "EthVendorSpecific/EthCtrlHwPort = 'HIF2'"!]
    PFE_PHY_IF_ID_HIF2, /**< Port to be attached to the controller */
    PFE_CTRL_TYPE_HIF, /**< Type of the controller */
    [!ENDIF!]
    [!IF "EthVendorSpecific/EthCtrlHwPort = 'HIF3'"!]
    PFE_PHY_IF_ID_HIF3, /**< Port to be attached to the controller */
    PFE_CTRL_TYPE_HIF, /**< Type of the controller */
    [!ENDIF!]
    [!IF "EthVendorSpecific/EthCtrlHwPort = 'HIF_NOCPY'"!]
    PFE_PHY_IF_ID_HIF_NOCPY, /**< Port to be attached to the controller */
    PFE_CTRL_TYPE_HIF, /**< Type of the controller */
    [!ENDIF!]
    [!IF "EthVendorSpecific/EthPromiscuousEn='true'"!]
    ((boolean)TRUE), /**< Promiscuous mode enabled */
    [!ELSE!]
    ((boolean)FALSE), /**< Promiscuous mode disabled */
    [!ENDIF!]
    [!IF "EthVendorSpecific/EthEmacLoopEn='true'"!]
    ((boolean)TRUE),  /**< Loopback on EMAC is enabled */
    [!ELSE!]
    ((boolean)FALSE), /**< Loopback on EMAC is disabled */
    [!ENDIF!]
    [!IF "EthVendorSpecific/AcceptAllTraffic='true'"!]
    ((boolean)TRUE),  /**< Controller will accept all trafic from EMAC */
    [!ELSE!]
    ((boolean)FALSE), [!IF "EthVendorSpecific/EthCtrlHwPort = 'AUX' or EthVendorSpecific/EthCtrlHwPort = 'HIF0' or EthVendorSpecific/EthCtrlHwPort = 'HIF1' or EthVendorSpecific/EthCtrlHwPort = 'HIF2' or EthVendorSpecific/EthCtrlHwPort = 'HIF3' or EthVendorSpecific/EthCtrlHwPort = 'HIF_NOCPY'"!]/**< Option has no effect for AUX/HIF interface */[!ELSE!]/**< Controller will accept only management traffic from EMAC */[!ENDIF!][!CR!]
    [!ENDIF!]
    EMAC_MODE_[!CALL "GetMacLayerType"!],
    EMAC_SPEED_[!CALL "GetMacLayerSpeed"!],
    EMAC_DUPLEX_[!CALL "GetMacDuplexMode"!],
    [!"EthVendorSpecific/EthCtrlEthIfIdx"!]U,  /**< Instance ID of the controller within the EthIf module context */
    Eth_43_PFE_Egress_PBConfig[!"$CtrlConfigName"!],
    Eth_43_PFE_Ingress_PBConfig[!"$CtrlConfigName"!],
    [!"num:i(count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*))"!]U,
    [!CALL "rx_tx_fifo_depth_per_controller"!][!// output: rx_fifo_buf_num_max tx_fifo_buf_num_max
    [!"num:i($tx_fifo_buf_num_max)"!]U,
    [!"num:i($rx_fifo_buf_num_max)"!]U,
    { [!CALL "GetEthCtrlEgressPrioToFifoIdx"!] },[!CR!]
    [!IF "node:exists(EthCtrlConfigEgress/EthCtrlConfigScheduler)"!]
    Eth_43_PFE_Scheduler_PBConfig[!"$CtrlConfigName"!],
    [!"num:i(count(EthCtrlConfigEgress/EthCtrlConfigScheduler/*))"!]U,
    [!ELSE!]
    NULL_PTR,
    0U,
    [!ENDIF!]
    [!IF "(node:exists(EthCtrlConfigEgress/EthCtrlConfigShaper)) and (num:i(count(EthCtrlConfigEgress/EthCtrlConfigShaper/*)) > '0')"!]
    Eth_43_PFE_Shaper_PBConfig[!"$CtrlConfigName"!],
    [!"num:i(count(EthCtrlConfigEgress/EthCtrlConfigShaper/*))"!]U
    [!ELSE!]
    NULL_PTR,
    0U
    [!ENDIF!]
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    ,{ [!IF "$EthDemEAccessEnabled     = 'true'"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],[!"$EthDemEAccessEventId"!] },
    { [!IF "$EthDemFrameLostEnabled   = 'true'"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],[!"$EthDemFrameLostEventId"!] },
    { [!IF "$EthDemECRCEnabled        = 'true'"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],[!"$EthDemECRCEventId"!] },
    { [!IF "$EthDemEUnderSizeEnabled  = 'true'"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],[!"$EthDemEUnderSizeEventId"!] },
    { [!IF "$EthDemEOverSizeEnabled   = 'true'"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],[!"$EthDemEOverSizeEventId"!] },
    { [!IF "$EthDemEAlignmentEnabled  = 'true'"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],[!"$EthDemEAlignmentEventId"!] },
    { [!IF "$EthDemE1ColEnabled       = 'true'"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],[!"$EthDemE1ColEventId"!] },
    { [!IF "$EthDemEMColEnabled       = 'true'"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],[!"$EthDemEMColEventId"!] },
    { [!IF "$EthDemELColEnabled       = 'true'"!](uint32)STD_ON[!ELSE!](uint32)STD_OFF[!ENDIF!],[!"$EthDemELColEventId"!] }
#endif
#if (STD_ON == ETH_43_PFE_CTRLENABLE_MII)
    ,{
        [!INDENT "8"!]
        &EthTrcv_[!IF "EthVendorSpecific/EthEthTrcvDriverVendorIdAndApiInfix != """!][!"EthVendorSpecific/EthEthTrcvDriverVendorIdAndApiInfix"!]_[!ENDIF!]ReadMiiIndication,
        &EthTrcv_[!IF "EthVendorSpecific/EthEthTrcvDriverVendorIdAndApiInfix != """!][!"EthVendorSpecific/EthEthTrcvDriverVendorIdAndApiInfix"!]_[!ENDIF!]WriteMiiIndication
        [!ENDINDENT!]
    }
#endif
#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    ,{
        [!INDENT "8"!]
        &EthSwt_[!IF "EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxAdaptBufferLength,
        &EthSwt_[!IF "EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxPrepareFrame,
        &EthSwt_[!IF "EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxProcessFrame,
        &EthSwt_[!IF "EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthTxFinishedIndication,
        &EthSwt_[!IF "EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthRxProcessFrame,
        &EthSwt_[!IF "EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix != """!][!"EthVendorSpecific/EthEthSwtDriverVendorIdAndApiInfix"!]_[!ENDIF!]EthRxFinishedIndication
        [!ENDINDENT!]
    }
#endif
    [!ENDINDENT!]
};
  [!ENDLOOP!]

/**
* @var Hif configuration - independent from controller
* @par Memory usage:
*/
static const Eth_43_PFE_HifCfgType PfeHif[!"$ConfigSet"!] =
{
    [!INDENT "4"!][!//
        [!CALL "CalculateRxBufPerHifInConfigset"!][!// output: rx_bd_num, rx_buf_num and rx_buf_size
        [!CALL "CalculateTxBDPerHifInConfigset"!][!// output: tx_bd_num
            /* Common HIF ([!"../EthGeneral/EthVendorSpecific/EthCommonHif"!]) */
            .u16RxBDNum = [!"num:i($rx_bd_num)"!]U,
            .u16TxBDNum = [!"num:i($tx_bd_num)"!]U,
            .u16RxBufNum = [!"num:i($rx_buf_num)"!]U,
            .u16RxBufSize = [!"num:i($rx_buf_size)"!]U
    [!ENDINDENT!][!//4
};
[!ENDSELECT!][!// EthConfigSet

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/**
* @brief         Driver configuration to be passed to Eth_43_PFE_Init function
* @details       This array contains references to all multiple configurations
*                to be used for the Eth driver configuration.
*/

[!SELECT "EthConfigSet"!]
  [!VAR "ConfigSet" = "as:name(.)"!]
  [!INDENT "0"!]
    [!IF "((../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
        [!CODE!]const Eth_43_PFE_ConfigType Eth_43_PFE_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = [!CR!][!ENDCODE!]
    [!ELSE!][!//
        [!CODE!]const Eth_43_PFE_ConfigType Eth_43_PFE_Config = [!CR!][!ENDCODE!]
    [!ENDIF!][!//
    {
        [!INDENT "4"!]
        {
            [!VAR "CtrlNum" = "num:i(count(EthCtrlConfig/*))"!]
            [!FOR "Idx" = "0" TO "num:i($CtrlNum)-1"!]
                [!SELECT "EthCtrlConfig/*"!]
                    [!IF "num:i($Idx) = num:i(./EthCtrlIdx)"!]
                        [!INDENT "8"!]
                        &Pfe[!"$ConfigSet"!]_[!"as:name(.)"!][!IF "$Idx < $CtrlNum - 1"!],[!CR!][!ELSE!][!CR!][!ENDIF!]
                        [!ENDINDENT!]
                    [!ENDIF!]
                [!ENDSELECT!]
            [!ENDFOR!]
        },
        &PfeHif[!"$ConfigSet"!],
        PfeEthConfigSet_EMAC
        [!ENDINDENT!]
    };
  [!ENDINDENT!]
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
