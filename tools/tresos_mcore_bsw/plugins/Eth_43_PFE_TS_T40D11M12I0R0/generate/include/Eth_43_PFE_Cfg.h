/**
*   @file       Eth_43_PFE_Cfg.h
*   @implements Eth_43_PFE_Cfg.h_Artifact
*
*   @brief   AUTOSAR Eth_43_PFE driver configuration header file
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
 *  SW Version           : 1.2.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.2.0_D2307_ASR_REL_4_4_REV_0000_20230728
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
[!AUTOSPACING!]
[!NOCODE!][!//
[!/*
*************************************
* Error checks of the configuration *
*************************************
*/!]
  [!INCLUDE "Eth_43_PFE_Checks.m"!][!// Configuration checks
  [!INCLUDE "Eth_43_PFE_GetDemParameters.m"!][!// Calculates register values from configuration paremeters
  [!INCLUDE "Eth_43_PFE_GetPfeParameters.m"!][!// Macros for calculation of values related to buffers
[!ENDNOCODE!][!//
#ifndef ETH_43_PFE_CFG_H
#define ETH_43_PFE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43120440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43120440
#endif

[!IF "EthGeneral/EthDevErrorDetect = 'true'"!][!//
#include "Det.h"
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#include "Dem.h"
[!ENDIF!][!//
#include "Eth_GeneralTypes.h"
#include "Mcal.h"
#include "Soc_Ips.h"
#include "fifo.h"

[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
#include "Eth_43_PFE_[!"."!]_PBcfg.h"
[!ENDLOOP!][!//
[!ELSE!]
#include "Eth_43_PFE_PBcfg.h"
[!ENDIF!]

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_PFE_VENDOR_ID_CFG                    43
#define ETH_43_PFE_MODULE_ID_CFG                    88
#define ETH_43_PFE_AR_RELEASE_MAJOR_VERSION_CFG     4
#define ETH_43_PFE_AR_RELEASE_MINOR_VERSION_CFG     4
#define ETH_43_PFE_AR_RELEASE_REVISION_VERSION_CFG  0
#define ETH_43_PFE_SW_MAJOR_VERSION_CFG             1
#define ETH_43_PFE_SW_MINOR_VERSION_CFG             2
#define ETH_43_PFE_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and MCAL header file are of the same Autosar version */
    #if ((ETH_43_PFE_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_PFE_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_43_PFE_Cfg.h and Mcal.h are different"
    #endif
    /* Check if current file and Soc_Ips header file are of the same Autosar version */
    #if ((ETH_43_PFE_AR_RELEASE_MAJOR_VERSION_CFG != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_PFE_AR_RELEASE_MINOR_VERSION_CFG != SOC_IPS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_43_PFE_Cfg.h and Soc_Ips.h are different"
    #endif
    /* Check if current file and DET header file are of the same Autosar version */
  [!IF "EthGeneral/EthDevErrorDetect = 'true'"!][!//
    #if ((ETH_43_PFE_AR_RELEASE_MAJOR_VERSION_CFG != DET_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_PFE_AR_RELEASE_MINOR_VERSION_CFG != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_43_PFE_Cfg.h and Det.h are different"
    #endif
  [!ENDIF!][!//
  [!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((ETH_43_PFE_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_PFE_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_43_PFE_Cfg.h and Dem.h are different"
    #endif
  [!ENDIF!][!//
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define VARIANT_PRE_COMPILE 0
#define VARIANT_LINK_TIME 1
#define VARIANT_POST_BUILD 2
[!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild' and (variant:size()<=1))"!][!//
#define ETH_43_PFE_PRECOMPILE_SUPPORT     (STD_ON)
[!ELSE!][!//
#define ETH_43_PFE_PRECOMPILE_SUPPORT     (STD_OFF)
[!ENDIF!][!//
 /******************************************************************************
 * Diagnostic Event Manager (DEM)
 ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
 #define ETH_43_PFE_DEM_EVENT_DETECT  (STD_ON)   /*!< Enables Diagnostic Event Manager */
[!ELSE!][!//
 #define ETH_43_PFE_DEM_EVENT_DETECT  (STD_OFF)  /*!< Enables Diagnostic Event Manager */
[!ENDIF!][!//

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*
* Symbolic names of groups.
*/
[!FOR "x" = "0" TO "count(EthConfigSet/EthCtrlConfig/*/EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*)-1"!][!//
[!LOOP "EthConfigSet/EthCtrlConfig/*/EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*"!][!//
[!IF "$x = EthCtrlConfigIngressFifoIdx"!]
#define EthConf_[!"name(..)"!]_[!"name(.)"!]    [!"EthCtrlConfigIngressFifoIdx"!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]

    #define ETH_43_PFE_CFG_ENABLERXINTERRUPT(CtrlIdx)   ((*(Eth_43_PFE_StaticConfig.pController[CtrlIdx])).EnableRxInterrupt)
    #define ETH_43_PFE_CFG_ENABLETXINTERRUPT(CtrlIdx)   ((*(Eth_43_PFE_StaticConfig.pController[CtrlIdx])).EnableTxInterrupt)
    #define ETH_43_PFE_CFG_MDIOSUPPORT(CtrlIdx)         ((*(Eth_43_PFE_StaticConfig.pController[CtrlIdx])).MDIOSupport)
    #define ETH_43_PFE_CFG_MACADDRESS(CtrlIdx)          ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthMACAddress)
    #define ETH_43_PFE_CFG_CTRLIDXINETHIF(CtrlIdx)      ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlEthIfIdx)
    #define ETH_43_PFE_CFG_CTRLHWPORT(CtrlIdx)          ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlHwPort)
    #define ETH_43_PFE_CFG_PROMISCUOUS(CtrlIdx)         ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlPromiscuous)
    #define ETH_43_PFE_CFG_BROADCAST(CtrlIdx)           ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlBroadcast)
    #define ETH_43_PFE_CFG_EMAC_LOOPBACK(CtrlIdx)       ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlEmacLoop)
    #define ETH_43_PFE_CFG_MIIMODE(CtrlIdx)             ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlMiiType)
    #define ETH_43_PFE_CFG_LINKSPEED(CtrlIdx)           ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlSpeed)
    #define ETH_43_PFE_CFG_LINKDUPLEX(CtrlIdx)          ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlDuplex)
    #define ETH_43_PFE_CFG_ACCEPTALLTRAFFIC(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlAcceptAllTraffic)
    #define ETH_43_PFE_CFG_HIF_RXBD_NUM                 (Eth_43_PFE_InternalCfgPtr->pHif->u16RxBDNum)
    #define ETH_43_PFE_CFG_HIF_TXBD_NUM                 (Eth_43_PFE_InternalCfgPtr->pHif->u16TxBDNum)
    #define ETH_43_PFE_CFG_HIF_RX_BUF_NUM               (Eth_43_PFE_InternalCfgPtr->pHif->u16RxBufNum)
    #define ETH_43_PFE_CFG_HIF_RX_BUF_SIZE              (Eth_43_PFE_InternalCfgPtr->pHif->u16RxBufSize)
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_ACCESS_ENABLED(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).ETH_43_PFE_DEM_E_ACCESS_Cfg.state)
    #define ETH_43_PFE_CFG_DEM_E_ACCESS(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).ETH_43_PFE_DEM_E_ACCESS_Cfg.id)
    #define ETH_43_PFE_CFG_DEM_E_FRAMELOST_ENABLED(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_RX_FRAMES_LOST_Cfg.state)
    #define ETH_43_PFE_CFG_DEM_E_FRAMELOST(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_RX_FRAMES_LOST_Cfg.id)
    #define ETH_43_PFE_CFG_DEM_E_CRC_ENABLED(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_CRC_Cfg.state)
    #define ETH_43_PFE_CFG_DEM_E_CRC(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_CRC_Cfg.id)
    #define ETH_43_PFE_CFG_DEM_E_UNDERSIZE_ENABLED(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_UNDERSIZEFRAME_Cfg.state)
    #define ETH_43_PFE_CFG_DEM_E_UNDERSIZE(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_UNDERSIZEFRAME_Cfg.id)
    #define ETH_43_PFE_CFG_DEM_E_OVERSIZE_ENABLED(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_OVERSIZEFRAME_Cfg.state)
    #define ETH_43_PFE_CFG_DEM_E_OVERSIZE(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_OVERSIZEFRAME_Cfg.id)
    #define ETH_43_PFE_CFG_DEM_E_ALIGN_ENABLED(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_ALIGNMENT_Cfg.state)
    #define ETH_43_PFE_CFG_DEM_E_ALIGN(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_ALIGNMENT_Cfg.id)
    #define ETH_43_PFE_CFG_DEM_E_1COL_ENABLED(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_SINGLECOLLISION_Cfg.state)
    #define ETH_43_PFE_CFG_DEM_E_1COL(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_SINGLECOLLISION_Cfg.id)
    #define ETH_43_PFE_CFG_DEM_E_MCOL_ENABLED(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_MULTIPLECOLLISION_Cfg.state)
    #define ETH_43_PFE_CFG_DEM_E_MCOL(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_MULTIPLECOLLISION_Cfg.id)
    #define ETH_43_PFE_CFG_DEM_E_LCOL_ENABLED(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_LATECOLLISION_Cfg.state)
    #define ETH_43_PFE_CFG_DEM_E_LCOL(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr[0].pController[CtrlIdx])).ETH_43_PFE_E_LATECOLLISION_Cfg.id)
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

#define ETH_43_PFE_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
      ETH_43_PFE_CONFIG_[!"."!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
       ETH_43_PFE_CONFIG_PB
[!ENDIF!]

#define RXTX_FIFO_ALIGNED_DEPTH(depth) ((((((uint32)(depth) * 4U) + (HAL_CACHE_LINE_SIZE - 1U)) / HAL_CACHE_LINE_SIZE) * HAL_CACHE_LINE_SIZE) / 4U)

/******************************************************************************
* Features enable/disable switches
******************************************************************************/
/* ETH004_Conf */
#define ETH_43_PFE_VERSION_INFO_API[!WS!][!IF "EthGeneral/EthVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/*!< Enables Version info function */
/* ETH005_Conf */
#define ETH_43_PFE_VERSION_INFO_API_MACRO[!WS!][!IF "EthGeneral/EthVersionInfoApiMacro = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/*!< Enables Version info function implementation as macro */

[!NOCODE!][!//
  [!/* This code check all multiple configurations whether all code switches
       (AllMiiDisabled)
       have the value equal to false which means that the code can be omitted.
       The code cannot be omitted when a true value is set in at least
       one multiple configuration */!]
  [!/* Set initial value to "can be omitted" */!]
  [!VAR "AllMiiDisabled" = "true()"!]
  [!/* Go through all multiple configurations and change initial value to
       "cannot be omitted" if a true value is found for a parameter */!]
  [!SELECT "EthConfigSet"!][!//
    [!LOOP "EthCtrlConfig/*"!][!//
      [!IF "EthCtrlEnableMii = 'true'"!]
        [!VAR "AllMiiDisabled" = "false()"!]
      [!ENDIF!]
    [!ENDLOOP!]
  [!ENDSELECT!][!//
[!ENDNOCODE!][!//
    /* This macro can have STD_OFF value only if the controller in all multiple configurations
       does not use the MII API. The value STD_ON means that code is compiled but the MII
       might not be used (API is present because it is needed in another multiple configuration
       but it is not called). */
    /* @requirements SWS_Eth_43_PFE_00012_Conf */
[!IF "$AllMiiDisabled = 'true'"!][!//
    #define ETH_43_PFE_CTRLENABLE_MII (STD_OFF)        /*!< MII handling functions compilation disabled */
    #define ETH_43_PFE_CTRL_USE_45_MDIO_API (STD_OFF)
[!ELSE!][!//
    #define ETH_43_PFE_CTRLENABLE_MII (STD_ON)         /*!< MII handling functions compilation enabled */
  [!IF "EthGeneral/EthVendorSpecific/EthEnableClause45API = 'true'"!][!//
    #define ETH_43_PFE_CTRL_USE_45_MDIO_API (STD_ON)
  [!ELSE!][!//
    #define ETH_43_PFE_CTRL_USE_45_MDIO_API (STD_OFF)
  [!ENDIF!][!//
[!ENDIF!][!//
    /* Enables/disables the GlobalTime APIs used amongst others by Global Time Synchronization over Ethernet */
    #define ETH_43_PFE_GLOBALTIME_SUPPORT   ([!IF "EthGeneral/EthGlobalTimeSupport = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    /* Enables / Disables switch management support */
    #define ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API  ([!IF "EthGeneral/EthVendorSpecific/EthSwtManagementSupportApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    /* Enables / Disables TX buffer release API */
    #define ETH_43_PFE_RELEASE_TX_BUFFER_API  ([!IF "EthGeneral/EthVendorSpecific/EthReleaseTxBufferApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

    #define ETH_43_PFE_USE_MULTIPLE_HIFS (STD_OFF)
    #define ETH_43_PFE_COMMON_HIF        PFE_PHY_IF_ID_[!"EthGeneral/EthVendorSpecific/EthCommonHif"!]
    #define PFE_CFG_LOCAL_IF_VALUE       [!WS!][!IF "EthGeneral/EthVendorSpecific/EthCommonHif = 'HIF_NOCPY'"!]4U[!ELSE!][!"num:i(num:i(substring-after(node:value(EthGeneral/EthVendorSpecific/EthCommonHif), 'HIF'))+6)"!]U[!ENDIF!][!CR!]
    #define ETH_43_PFE_USINGHIF0         [!WS!][!IF "EthGeneral/EthVendorSpecific/EthCommonHif = 'HIF0'"!]TRUE[!ELSE!]FALSE[!ENDIF!][!CR!]
    #define ETH_43_PFE_USINGHIF1         [!WS!][!IF "EthGeneral/EthVendorSpecific/EthCommonHif = 'HIF1'"!]TRUE[!ELSE!]FALSE[!ENDIF!][!CR!]
    #define ETH_43_PFE_USINGHIF2         [!WS!][!IF "EthGeneral/EthVendorSpecific/EthCommonHif = 'HIF2'"!]TRUE[!ELSE!]FALSE[!ENDIF!][!CR!]
    #define ETH_43_PFE_USINGHIF3         [!WS!][!IF "EthGeneral/EthVendorSpecific/EthCommonHif = 'HIF3'"!]TRUE[!ELSE!]FALSE[!ENDIF!][!CR!]
    #define ETH_43_PFE_USINGHIF_NOCPY    [!WS!][!IF "EthGeneral/EthVendorSpecific/EthCommonHif = 'HIF_NOCPY'"!]TRUE[!ELSE!]FALSE[!ENDIF!][!CR!]
    [!IF "EthGeneral/EthVendorSpecific/EthPfeMultiInstance = 'false'"!][!//
    #define ETH_43_PFE_MULTI_INSTANCE    (STD_OFF)
    #define ETH_43_PFE_SLAVE_MODE        (STD_OFF)
    #define ETH_43_PFE_BMU2_BUF_CNT      ([!"num:i(EthGeneral/EthVendorSpecific/VarEthBmu2BufCnt)"!]U)
    [!ELSE!][!// EthPfeMultiInstance = 'true'
    #define ETH_43_PFE_MULTI_INSTANCE    (STD_ON)
    #define ETH_43_PFE_MASTER_IF         (PFE_PHY_IF_ID_[!"EthGeneral/EthVendorSpecific/EthPfeMasterHif"!])
        [!IF "EthGeneral/EthVendorSpecific/EthPfeSlaveMode = 'true'"!][!//
    #define ETH_43_PFE_SLAVE_MODE        (STD_ON)
        [!ELSE!][!// EthPfeSlaveMode = 'false'
    #define ETH_43_PFE_SLAVE_MODE        (STD_OFF)
    #define ETH_43_PFE_BMU2_BUF_CNT      ([!"num:i(EthGeneral/EthVendorSpecific/VarEthBmu2BufCnt)"!]U)
        [!ENDIF!][!// EthPfeSlaveMode
    [!ENDIF!][!// EthPfeMultiInstance

    /*! @brief Enables / Disables Eth_43_PFE_GetClassStats API */
    [!IF "node:exists(EthGeneral/EthGetClassStatisticApi)"!][!//
    #define ETH_43_GET_CLASS_STATISTIC_API    ([!IF "EthGeneral/EthGetClassStatisticApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    [!ELSE!][!//
    #define ETH_43_GET_CLASS_STATISTIC_API    (STD_OFF)
    [!ENDIF!][!//
    /*! @brief Enables / Disables Eth_43_PFE_GetPFEStats API */
    [!IF "node:exists(EthGeneral/EthGetPFEStatisticApi)"!][!//
    #define ETH_43_GET_PFE_STATISTIC_API    ([!IF "EthGeneral/EthGetPFEStatisticApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    [!ELSE!][!//
    #define ETH_43_GET_PFE_STATISTIC_API      (STD_OFF)
    [!ENDIF!][!//
    /*! @brief Enables / Disables Eth_GetCounterValues API */
    [!IF "node:exists(EthGeneral/EthGetCounterValuesApi)"!][!//
    #define ETH_43_GET_COUNTER_API            ([!IF "EthGeneral/EthGetCounterValuesApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    [!ELSE!][!//
    #define ETH_43_GET_COUNTER_API            (STD_OFF)
    [!ENDIF!][!//
    /*! @brief Enables / Disables Eth_GetTxStats API */
    [!IF "node:exists(EthGeneral/EthGetTxStatsApi)"!][!//
    #define ETH_43_GET_TXSTATS_API            ([!IF "EthGeneral/EthGetTxStatsApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    [!ELSE!][!//
    #define ETH_43_GET_TXSTATS_API            (STD_OFF)
    [!ENDIF!][!//
    /*! @brief Enables / Disables Eth_GetRxStats API */
    [!IF "node:exists(EthGeneral/EthGetRxStatsApi)"!][!//
    #define ETH_43_GET_RXSTATS_API            ([!IF "EthGeneral/EthGetRxStatsApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    [!ELSE!][!//
    #define ETH_43_GET_RXSTATS_API            (STD_OFF)
    [!ENDIF!][!//
    /*! @brief Enables / Disables Eth_GetTxErrorCounterValues API */
    [!IF "node:exists(EthGeneral/EthGetTxErrorCounterValuesApi)"!][!//
    #define ETH_43_GET_TXERROR_COUNTER_API    ([!IF "EthGeneral/EthGetTxErrorCounterValuesApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    [!ELSE!][!//
    #define ETH_43_GET_TXERROR_COUNTER_API    (STD_OFF)
    [!ENDIF!][!//

    /*! @brief Enables / Disables hardware offloading for IPv4 checksums */
    #define ETH_43_PFE_ENABLE_OFFLOAD_CSUM_IPV4         ([!IF "EthGeneral/EthCtrlOffloading/EthCtrlEnableOffloadChecksumIPv4"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    /*! @brief Enables / Disables hardware offloading for TCP checksums */
    #define ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP          ([!IF "EthGeneral/EthCtrlOffloading/EthCtrlEnableOffloadChecksumTCP"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    /*! @brief Enables / Disables hardware offloading for UDP checksums */
    #define ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP          ([!IF "EthGeneral/EthCtrlOffloading/EthCtrlEnableOffloadChecksumUDP"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    /*! @brief Enables / Disables hardware offloading for ICMP checksums */
    #define ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP         ([!IF "EthGeneral/EthCtrlOffloading/EthCtrlEnableOffloadChecksumICMP"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
    /******************************************************************************
    * Development Error Detection
    ******************************************************************************/
    /* ETH003_Conf */
[!IF "EthGeneral/EthDevErrorDetect = 'true'"!][!//
    #define ETH_43_PFE_DEV_ERROR_DETECT  (STD_ON)      /*!< Enables Development Error Detect feature */
[!ELSE!][!//
    #define ETH_43_PFE_DEV_ERROR_DETECT  (STD_OFF)     /*!< Enables Development Error Detect feature */
[!ENDIF!][!//

    /******************************************************************************
    * Configuration constants
    ******************************************************************************/
    /* Required Eth buffers alignment, may be different for TX and RX depending on the used IP */
    #define ETH_43_PFE_TX_BUF_ALIGNMENT 8 /* 8 bytes */
    #define ETH_43_PFE_RX_BUF_ALIGNMENT 8 /* 8 bytes */
    /* ETH002_Conf */
    #define ETH_43_PFE_MAXCTRLS_SUPPORTED [!"EthGeneral/EthMaxCtrlsSupported"!]U  /* Number of supported controllers */
    [!IF "EthGeneral/EthVendorSpecific/EthPfeMultiInstance = 'true'"!][!//
        [!IF "$HifInterruptEnabled = 'false'"!][!//
            [!IF "(EthGeneral/EthMainFunctionPeriod) > 0.01"!][!//
                [!WARNING!]
                    When using polling mode, period of calling MainFunction should be less than 0.01s for better performance of Master-Slave operation.
                [!ENDWARNING!]
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    #define ETH_43_PFE_CFG_MAIN_FCN_PERIOD_MS [!"num:i(EthGeneral/EthMainFunctionPeriod * 1000.0)"!]U  /* Period of Main function in miliseconds */
    #define ETH_43_PFE_NUM_OF_CONFIGURATIONS 1U /* Number of configurations */ /* FIXME - does not seem right to be always 1 */
    #define ETH_43_PFE_DRIVER_INSTANCE [!"EthGeneral/EthIndex"!]U   /* Instance number assigned to the driver */
    #define ETH_43_PFE_NUM_EMAC                    (3U)
    #define ETH_43_PFE_NUM_CONTROLLER_CFG          ([!"num:i(count(EthConfigSet/EthCtrlConfig/*))"!]U)
    /* Sizes of memory blocks allocated for TX/RX data buffers and related descriptors */
    #define ETH_43_PFE_MAX_RXFIFO_CONFIG           (1U)
    #define ETH_43_PFE_MAX_TX_PRIO_NUM             (7U)

[!CALL "CalculateTotalMaximumTxValues"!][!// output: tx_buf_poolsz_max tx_bd_num_max tx_fifo_num_max tx_fifo_buf_num_max
[!CALL "CalculateTotalMaximumRxValues"!][!// output: rx_buf_poolsz_max rx_meta_buf_poolsz_max rx_bd_num_max
    /* Used for BD memory allocation: */
    #define ETH_43_PFE_MAX_RXBD_CNT                ([!"num:i($rx_bd_num_max)"!]U)
    #define ETH_43_PFE_MAX_TXBD_CNT                ([!"num:i($tx_bd_num_max)"!]U)
    /* Used for buffer memory allocation (values are always >= 1 to avoid zero sized arrays): */
    #define ETH_43_PFE_MAX_RXBUF_POOLSZ            ([!"num:i($rx_buf_poolsz_max)"!]U)
    #define ETH_43_PFE_MAX_RXBUF_META_POOLSZ       ([!"num:i($rx_meta_buf_poolsz_max)"!]U)
    #define ETH_43_PFE_MAX_TXBUF_POOLSZ            ([!"num:i($tx_buf_poolsz_max)"!]U)
    /* Fifo/queue configuration */
    #define ETH_43_PFE_MAX_TXFIFO_CNT              ([!"num:i($tx_fifo_num_max)"!]U)
    #define ETH_43_PFE_MAX_FIFO_TX_BUF_CNT         ([!"num:i($tx_fifo_buf_num_max)"!]U)
    #define ETH_43_PFE_MAX_CTRL_TX_BUF_CNT         ([!"num:i($tx_ctrl_buf_num_max)"!]U)
    #define ETH_43_PFE_META_BUF_SIZE               ([!"num:i($meta_buffer_size)"!]U)

    /******************************************************************************
    *   PFE FIRMWARE IMAGE LOCATION
    ******************************************************************************/
    [!IF "EthGeneral/EthVendorSpecific/EthPfeMultiInstance = 'false' or EthGeneral/EthVendorSpecific/EthPfeSlaveMode = 'false'"!][!// classifier firmware for standalone driver or master driver
    [!IF "EthGeneral/EthVendorSpecific/PfeClassFwLoadFrom = 'PfeClassFwArrayLabel'"!]
    [!CODE!]
    #define PFE_CLASS_FW_BINARY [!"EthGeneral/EthVendorSpecific/PfeClassFwArrayLabel"!]
    extern const uint8_t PFE_CLASS_FW_BINARY[];
    [!ENDCODE!]
    [!ENDIF!]
    [!IF "EthGeneral/EthVendorSpecific/PfeClassFwLoadFrom = 'PfeClassFwMemoryAddress'"!]
    [!CODE!]
    #define PFE_CLASS_FW_BINARY ((const void*)0x[!"EthGeneral/EthVendorSpecific/PfeClassFwMemoryAddress"!])
    [!ENDCODE!]
    [!ENDIF!]
    [!ELSE!][!// no classifier firmware is need for slave driver
    #define PFE_CLASS_FW_BINARY NULL_PTR
    [!ENDIF!]

#define ETH_43_PFE_ENABLE_USER_MODE_SUPPORT              ([!IF "EthGeneral/EthVendorSpecific/EthEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == ETH_43_PFE_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running ETH_43_PFE in user mode, MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
        #endif /* (STD_ON == ETH_43_PFE_ENABLE_USER_MODE_SUPPORT */
#endif /*MCAL_ENABLE_USER_MODE_SUPPORT*/

    /******************************************************************************
    *   Driver Runtime Dem Error Detection
    ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthDriverRuntimeErrorsDemEventParameterRefs/ETH_E_DRIVER_RUNTIME_ERR_IP_READY) and node:refvalid(EthGeneral/EthVendorSpecific/EthDriverRuntimeErrorsDemEventParameterRefs/ETH_E_DRIVER_RUNTIME_ERR_IP_READY)"!]
      [!VAR "EthDemDetectDriverRuntimeErrIpReady" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthDriverRuntimeErrorsDemEventParameterRefs/ETH_E_DRIVER_RUNTIME_ERR_IP_READY)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectDriverRuntimeErrIpReady" ="num:i(1)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthDriverRuntimeErrorsDemEventParameterRefs/ETH_E_DRIVER_RUNTIME_ERR_INTERNAL) and node:refvalid(EthGeneral/EthVendorSpecific/EthDriverRuntimeErrorsDemEventParameterRefs/ETH_E_DRIVER_RUNTIME_ERR_INTERNAL)"!]
      [!VAR "EthDemDetectDriverRuntimeErrInternal" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthDriverRuntimeErrorsDemEventParameterRefs/ETH_E_DRIVER_RUNTIME_ERR_INTERNAL)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectDriverRuntimeErrInternal" ="num:i(2)"!]
    [!ENDIF!]
    [!IF "EthGeneral/EthVendorSpecific/EthPfeMultiInstance = 'true' and EthGeneral/EthVendorSpecific/EthPfeSlaveMode = 'true'"!][!//
    #define ETH_43_PFE_CFG_DEM_E_DRIVER_RUNTIME_ERR_IP_READY        [!"$EthDemDetectDriverRuntimeErrIpReady"!]
    [!ENDIF!][!//
    #define ETH_43_PFE_CFG_DEM_E_DRIVER_RUNTIME_ERR_INTERNAL        [!"$EthDemDetectDriverRuntimeErrInternal"!]
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
[!ENDIF!][!//

    /******************************************************************************
    *   PFE ECC Dem Error Detection
    ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthPfeEccDemEventParameterRefs/ETH_E_PFE_ECC_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthPfeEccDemEventParameterRefs/ETH_E_PFE_ECC_ERR)"!]
      [!VAR "EthDemDetectPfeEccError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthPfeEccDemEventParameterRefs/ETH_E_PFE_ECC_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectPfeEccError" ="num:i(10)"!]
    [!ENDIF!]
    #define ETH_43_PFE_CFG_DEM_E_PFE_ECC_ERR    [!"$EthDemDetectPfeEccError"!]
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
[!ENDIF!][!//

    /******************************************************************************
    *   PFE Watchdog Dem Error Detection
    ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthPfeWdtDemEventParameterRefs/ETH_E_PFE_WDT_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthPfeWdtDemEventParameterRefs/ETH_E_PFE_WDT_ERR)"!]
      [!VAR "EthDemDetectPfeWdtError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthPfeWdtDemEventParameterRefs/ETH_E_PFE_WDT_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectPfeWdtError" ="num:i(20)"!]
    [!ENDIF!]
    #define ETH_43_PFE_CFG_DEM_E_PFE_WDT_ERR    [!"$EthDemDetectPfeWdtError"!]
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
[!ENDIF!][!//

    /******************************************************************************
    *   EMAC Dem Error Detection
    ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_ECC_UNCORRECTABLE_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_ECC_UNCORRECTABLE_ERR)"!]
      [!VAR "EthDemDetectEmac0EccUncorrectableError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_ECC_UNCORRECTABLE_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac0EccUncorrectableError" ="num:i(30)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_ECC_ADDRESS_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_ECC_ADDRESS_ERR)"!]
      [!VAR "EthDemDetectEmac0EccAddressError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_ECC_ADDRESS_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac0EccAddressError" ="num:i(31)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_PARITY_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_PARITY_ERR)"!]
      [!VAR "EthDemDetectEmac0ParityError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_PARITY_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac0ParityError" ="num:i(32)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_WDT_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_WDT_ERR)"!]
      [!VAR "EthDemDetectEmac0WatchdogError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC0_WDT_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac0WatchdogError" ="num:i(33)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_ECC_UNCORRECTABLE_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_ECC_UNCORRECTABLE_ERR)"!]
      [!VAR "EthDemDetectEmac1EccUncorrectableError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_ECC_UNCORRECTABLE_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac1EccUncorrectableError" ="num:i(34)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_ECC_ADDRESS_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_ECC_ADDRESS_ERR)"!]
      [!VAR "EthDemDetectEmac1EccAddressError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_ECC_ADDRESS_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac1EccAddressError" ="num:i(35)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_PARITY_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_PARITY_ERR)"!]
      [!VAR "EthDemDetectEmac1ParityError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_PARITY_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac1ParityError" ="num:i(36)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_WDT_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_WDT_ERR)"!]
      [!VAR "EthDemDetectEmac1WatchdogError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC1_WDT_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac1WatchdogError" ="num:i(37)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_ECC_UNCORRECTABLE_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_ECC_UNCORRECTABLE_ERR)"!]
      [!VAR "EthDemDetectEmac2EccUncorrectableError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_ECC_UNCORRECTABLE_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac2EccUncorrectableError" ="num:i(38)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_ECC_ADDRESS_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_ECC_ADDRESS_ERR)"!]
      [!VAR "EthDemDetectEmac2EccAddressError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_ECC_ADDRESS_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac2EccAddressError" ="num:i(39)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_PARITY_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_PARITY_ERR)"!]
      [!VAR "EthDemDetectEmac2ParityError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_PARITY_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac2ParityError" ="num:i(40)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_WDT_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_WDT_ERR)"!]
      [!VAR "EthDemDetectEmac2WatchdogError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthEmacDemEventParameterRefs/ETH_E_EMAC2_WDT_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectEmac2WatchdogError" ="num:i(41)"!]
    [!ENDIF!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC0_ECC_UNCORRECTABLE_ERR    [!"$EthDemDetectEmac0EccUncorrectableError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC0_ECC_ADDRESS_ERR          [!"$EthDemDetectEmac0EccAddressError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC0_PARITY_ERR               [!"$EthDemDetectEmac0ParityError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC0_WDT_ERR                  [!"$EthDemDetectEmac0WatchdogError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC1_ECC_UNCORRECTABLE_ERR    [!"$EthDemDetectEmac1EccUncorrectableError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC1_ECC_ADDRESS_ERR          [!"$EthDemDetectEmac1EccAddressError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC1_PARITY_ERR               [!"$EthDemDetectEmac1ParityError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC1_WDT_ERR                  [!"$EthDemDetectEmac1WatchdogError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC2_ECC_UNCORRECTABLE_ERR    [!"$EthDemDetectEmac2EccUncorrectableError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC2_ECC_ADDRESS_ERR          [!"$EthDemDetectEmac2EccAddressError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC2_PARITY_ERR               [!"$EthDemDetectEmac2ParityError"!]
    #define ETH_43_PFE_CFG_DEM_E_EMAC2_WDT_ERR                  [!"$EthDemDetectEmac2WatchdogError"!]
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
[!ENDIF!][!//

    /******************************************************************************
    *   Bus Dem Error Detection
    ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthBusDemEventParameterRefs/ETH_E_BUS_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthBusDemEventParameterRefs/ETH_E_BUS_ERR)"!]
      [!VAR "EthDemDetectBusError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthBusDemEventParameterRefs/ETH_E_BUS_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectBusError" ="num:i(50)"!]
    [!ENDIF!]
    #define ETH_43_PFE_CFG_DEM_E_BUS_ERR    [!"$EthDemDetectBusError"!]
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
[!ENDIF!][!//

    /******************************************************************************
    *   PFE Parity Dem Error Detection
    ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthPfeParityDemEventParameterRefs/ETH_E_PFE_PARITY_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthPfeParityDemEventParameterRefs/ETH_E_PFE_PARITY_ERR)"!]
      [!VAR "EthDemDetectPfeParityError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthPfeParityDemEventParameterRefs/ETH_E_PFE_PARITY_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectPfeParityError" ="num:i(60)"!]
    [!ENDIF!]
    #define ETH_43_PFE_CFG_DEM_E_PFE_PARITY_ERR    [!"$EthDemDetectPfeParityError"!]
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
[!ENDIF!][!//

    /******************************************************************************
    *   Failstop Dem Error Detection
    ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthFailStopDemEventParameterRefs/ETH_E_FAIL_STOP_HW_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthFailStopDemEventParameterRefs/ETH_E_FAIL_STOP_HW_ERR)"!]
      [!VAR "EthDemDetectFailStopHwError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthFailStopDemEventParameterRefs/ETH_E_FAIL_STOP_HW_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectFailStopHwError" ="num:i(70)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthFailStopDemEventParameterRefs/ETH_E_FAIL_STOP_FW_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthFailStopDemEventParameterRefs/ETH_E_FAIL_STOP_FW_ERR)"!]
      [!VAR "EthDemDetectFailStopFwError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthFailStopDemEventParameterRefs/ETH_E_FAIL_STOP_FW_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectFailStopFwError" ="num:i(71)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthFailStopDemEventParameterRefs/ETH_E_FAIL_STOP_SW_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthFailStopDemEventParameterRefs/ETH_E_FAIL_STOP_SW_ERR)"!]
      [!VAR "EthDemDetectFailStopSwError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthFailStopDemEventParameterRefs/ETH_E_FAIL_STOP_SW_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectFailStopSwError" ="num:i(72)"!]
    [!ENDIF!]
    #define ETH_43_PFE_CFG_DEM_E_FAIL_STOP_HW_ERR    [!"$EthDemDetectFailStopHwError"!]
    #define ETH_43_PFE_CFG_DEM_E_FAIL_STOP_FW_ERR    [!"$EthDemDetectFailStopFwError"!]
    #define ETH_43_PFE_CFG_DEM_E_FAIL_STOP_SW_ERR    [!"$EthDemDetectFailStopSwError"!]
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
[!ENDIF!][!//

    /******************************************************************************
    *   BMU Dem Error Detection
    ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthBmuDemEventParameterRefs/ETH_E_BMU_FULL) and node:refvalid(EthGeneral/EthVendorSpecific/EthBmuDemEventParameterRefs/ETH_E_BMU_FULL)"!]
      [!VAR "EthDemDetectBmuFull" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthBmuDemEventParameterRefs/ETH_E_BMU_FULL)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectBmuFull" ="num:i(80)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthBmuDemEventParameterRefs/ETH_E_BMU_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthBmuDemEventParameterRefs/ETH_E_BMU_ERR)"!]
      [!VAR "EthDemDetectBmuError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthBmuDemEventParameterRefs/ETH_E_BMU_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectBmuError" ="num:i(81)"!]
    [!ENDIF!]
    #define ETH_43_PFE_CFG_DEM_E_BMU_FULL    [!"$EthDemDetectBmuFull"!]
    #define ETH_43_PFE_CFG_DEM_E_BMU_ERR     [!"$EthDemDetectBmuError"!]
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
[!ENDIF!][!//

    /******************************************************************************
    *   PE Dem Error Detection
    ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthPeDemEventParameterRefs/ETH_E_PE_STALL_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthPeDemEventParameterRefs/ETH_E_PE_STALL_ERR)"!]
      [!VAR "EthDemDetectPestallError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthPeDemEventParameterRefs/ETH_E_PE_STALL_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectPestallError" ="num:i(90)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthPeDemEventParameterRefs/ETH_E_PE_EXCEPTION_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthPeDemEventParameterRefs/ETH_E_PE_EXCEPTION_ERR)"!]
      [!VAR "EthDemDetectPeEceptionError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthPeDemEventParameterRefs/ETH_E_PE_EXCEPTION_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectPeEceptionError" ="num:i(91)"!]
    [!ENDIF!]
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthPeDemEventParameterRefs/ETH_E_PE_FW_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthPeDemEventParameterRefs/ETH_E_PE_FW_ERR)"!]
      [!VAR "EthDemDetectPeFwError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthPeDemEventParameterRefs/ETH_E_PE_FW_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectPeFwError" ="num:i(92)"!]
    [!ENDIF!]
    #define ETH_43_PFE_CFG_DEM_E_PE_STALL_ERR        [!"$EthDemDetectPestallError"!]
    #define ETH_43_PFE_CFG_DEM_E_PE_EXCEPTION_ERR    [!"$EthDemDetectPeEceptionError"!]
    #define ETH_43_PFE_CFG_DEM_E_PE_FW_ERR           [!"$EthDemDetectPeFwError"!]
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
[!ENDIF!][!//

    /******************************************************************************
    *   HIF Dem Error Detection
    ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    [!IF "node:exists(EthGeneral/EthVendorSpecific/EthHifDemEventParameterRefs/ETH_E_HIF_ERR) and node:refvalid(EthGeneral/EthVendorSpecific/EthHifDemEventParameterRefs/ETH_E_HIF_ERR)"!]
      [!VAR "EthDemDetectHifError" ="concat('DemConf_DemEventParameter_',node:ref(EthGeneral/EthVendorSpecific/EthHifDemEventParameterRefs/ETH_E_HIF_ERR)/@name)"!]
    [!ELSE!]
      [!VAR "EthDemDetectHifError" ="num:i(100)"!]
    [!ENDIF!]
    #define ETH_43_PFE_CFG_DEM_E_HIF_ERR    [!"$EthDemDetectHifError"!]
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
[!ENDIF!][!//

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*
* @brief This type is used to store configuration for common HIF
*/
typedef struct
{
    uint16 u16RxBDNum;
    uint16 u16TxBDNum;
    uint16 u16RxBufNum;
    uint16 u16RxBufSize;
} Eth_43_PFE_HifCfgType;

typedef struct
{
    fifo_t *EthCtrlConfigEgressFifo;           /**< Tx FIFO */
    void **EthCtrlConfigEgressFifoData;        /**< Tx FIFO data pool start */
    uint16 EthCtrlConfigEgressFifoBufLenByte;  /**< Length of one Tx buffer */
    uint16 EthCtrlConfigEgressFifoMemLenByte;  /**< Length of one Tx buffer in memory */
    uint16 EthCtrlConfigEgressFifoBufTotal;    /**< Number of Tx buffers */
} Eth_43_PFE_EgressTxCfgType;

typedef struct
{
    fifo_t *EthCtrlConfigIngressFifo;          /**< Rx FIFO */
    void **EthCtrlConfigIngressFifoData;       /**< Rx FIFO data pool start */
    uint16 EthCtrlConfigIngressFifoBufLenByte; /**< Length of one Rx buffer*/
    uint16 EthCtrlConfigIngressFifoBufTotal;   /**< Number of Rx buffers */
} Eth_43_PFE_IngressCfgType;

typedef enum
{
    IS_SHEDULER = 0U,
    IS_SHAPER   = 1U,
    IS_FIFO     = 2U
} Eth_43_PFE_SchedulerInputType;

typedef struct
{
    uint8 u8Input; /**< range: 0-7 correspond to one of 8 inputs of scheduler */
    uint32 u32Weight; /**< Scheduler input weight */
    Eth_43_PFE_SchedulerInputType SchInputType; /**< Scheduler input is scheduler, shaper or fifo */
    uint8 u8InputIdx; /**< Scheduler index/ Shaper index/ Fifo index */
} Eth_43_PFE_SchedulerInputInfoCfgType;

typedef struct
{
    boolean IsLastSch; /*!< This is the last scheduler in topology or not */
    pfe_tmu_sched_algo_t SchAlgo; /*!< Scheduler algorithm */
    pfe_tmu_rate_mode_t SchRateMode; /*!< Scheduler rate mode */
    uint8 SchInputCnt; /*!< The number of inputs assigned to scheduler */
    const Eth_43_PFE_SchedulerInputInfoCfgType *pSchInputInfoCfg; /*!< Store information for inputs of scheduler */
} Eth_43_PFE_SchedulerCfgType;

typedef struct
{
    uint8 u8ShpIdx; /**< range: 0-3 */
    uint32 u32IdleSlope;
    int32_t s32MaxCredit;
    int32_t s32MinCredit;
    uint8 u8FifoIdx; /*!< The index of FIFO connected to shaper */
} Eth_43_PFE_ShaperCfgType;

typedef struct
{
    pfe_emac_mii_mode_t EthCtrlMiiType; /**< Mii type MII/RMII/SGMII/RGMII */
    pfe_emac_speed_t EthCtrlSpeed; /**< Link speed 10/100/1000/2500(if applicable to xmii) */
    pfe_emac_duplex_t EthCtrlDuplex; /**< Duplex mode FULL/HALF */
}Eth_43_PFE_EmacCfg;

#if (STD_ON == ETH_43_PFE_CTRLENABLE_MII)
/**
 * @brief    Type for holding function pointers to the EthTrcv
 * @details  It contains the needed function pointers to EthTrcv functions.
 */
typedef struct
{
    void (*ReadMiiIndicationFunction)(uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 RegVal);
    void (*WriteMiiIndicationFunction)(uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx);

}Eth_43_PFE_EthTrcvFunctionsType;
#endif

#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
/**
 * @brief    Type for holding function pointers to the EthSwt
 * @details  It contains the needed function pointers to EthSwt functions.
 */
typedef struct
{
    void (*TxAdaptBufferLengthFunction)(uint16* LengthPtr);
    Std_ReturnType (*TxPrepareFrameFunction)(uint8 CtrlIdx, Eth_BufIdxType BufIdx, uint8** DataPtr, uint16* LengthPtr);
    Std_ReturnType (*TxProcessFrameFunction)(uint8 CtrlIdx, Eth_BufIdxType BufIdx, uint8** DataPtr, uint16* LengthPtr);
    Std_ReturnType (*TxFinishedIndicationFunction)(uint8 CtrlIdx, Eth_BufIdxType BufIdx);
    Std_ReturnType (*RxProcessFrameFunction)(uint8 CtrlIdx, Eth_BufIdxType BufIdx, uint8** DataPtr, uint16* LengthPtr, boolean* IsMgmtFrameOnlyPtr);
    Std_ReturnType (*RxFinishedIndicationFunction)(uint8 CtrlIdx, Eth_BufIdxType BufIdx);

}Eth_43_PFE_EthSwtFunctionsType;
#endif

/**
* @brief         Type for Ethernet driver configuration values storage.
* @details       This type is used to collect and pass all configuration data
*                of one controller (except those which have only
*                precompile variant) to the Eth driver.
*/
typedef struct
{
    uint8 EthMACAddress[6U];     /**< MAC address */
    char *EthCtrlHwPort; /**< Port to be attached to the controller */
    boolean EthCtrlPromiscuous; /**< Promiscuous mode enabled/disabled */
    boolean EthCtrlBroadcast; /**< Broadcast reception enabled/disabled */
    boolean EthCtrlEmacLoop;  /**< Broadcast reception enabled/disabled */
    boolean EthCtrlAcceptAllTraffic;  /**< Reception of all traffic from associated EMAC enabled/disabled */
    pfe_emac_mii_mode_t EthCtrlMiiType; /**< Mii type MII/RMII/SGMII/RGMII */
    pfe_emac_speed_t EthCtrlSpeed; /**< Link speed 10/100/2500(if applicable to xmii) */
    pfe_emac_duplex_t EthCtrlDuplex; /**< Duplex mode FULL/HALF */
    uint8 EthCtrlEthIfIdx;    /**< Index of the controler in context of EthIf driver */
    const Eth_43_PFE_EgressTxCfgType *pEgressCfg;
    const Eth_43_PFE_IngressCfgType *pIngressCfg;
    uint8 EthCtrlEgressFifoCnt;     /**< Number of egress queues */
    uint16 EthCtrlEgressFifoDepth;  /**< Maximum number of buffers in egress fifo */
    uint16 EthCtrlIngressFifoDepth; /**< Maximum number of buffers in ingress fifo */
    uint8 EthCtrlEgressPrioToFifoIdx[ETH_43_PFE_MAX_TX_PRIO_NUM+1U]; /**< Mapping egress FIFOs to the frame priority */
    const Eth_43_PFE_SchedulerCfgType *pSchCfg;
    uint8 EthCtrlSchedulerCnt; /**< Number of schedulers */
    const Eth_43_PFE_ShaperCfgType *pShpCfg;
    uint8 EthCtrlShaperCnt; /**< Number of shapers */
#if (STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
    Mcal_DemErrorType ETH_43_PFE_DEM_E_ACCESS_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_43_PFE_E_ACCESS and   */
    Mcal_DemErrorType ETH_43_PFE_E_RX_FRAMES_LOST_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_43_PFE_E_ACCESS and   */
    Mcal_DemErrorType ETH_43_PFE_E_CRC_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_43_PFE_E_CRC and   */
    Mcal_DemErrorType ETH_43_PFE_E_UNDERSIZEFRAME_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_43_PFE_E_UNDERSIZEFRAME and   */
    Mcal_DemErrorType ETH_43_PFE_E_OVERSIZEFRAME_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_43_PFE_E_OVERSIZEFRAME and   */
    Mcal_DemErrorType ETH_43_PFE_E_ALIGNMENT_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_43_PFE_E_ALIGNMENT and   */
    Mcal_DemErrorType ETH_43_PFE_E_SINGLECOLLISION_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_43_PFE_E_SINGLECOLLISION and   */
    Mcal_DemErrorType ETH_43_PFE_E_MULTIPLECOLLISION_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_43_PFE_E_MULTIPLECOLLISION and   */
    Mcal_DemErrorType ETH_43_PFE_E_LATECOLLISION_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_43_PFE_E_LATECOLLISION and   */
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
#if (STD_ON == ETH_43_PFE_CTRLENABLE_MII)
    const Eth_43_PFE_EthTrcvFunctionsType Eth_43_PFE_EthTrcvDriverFunctionList;  /**< @brief The structure with pointer functions to the EthTrcv driver functions */
#endif
#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    const Eth_43_PFE_EthSwtFunctionsType Eth_43_PFE_EthSwtDriverFunctionList; /**< @brief The structure with pointer functions to the EthSwt driver functions */
#endif
} Eth_43_PFE_CtrlCfgType;

/**
* @brief         Type for Ethernet driver Static configuration values storage.
* @details       This type is used to collect and pass all configuration data
*                of one controller (except those which have only
*                precompile variant) to the Eth driver.
*/
typedef struct
{
    boolean EnableRxInterrupt;  /**< Enable interrupt requests for frame
                                      reception event */
    boolean EnableTxInterrupt;  /**< Enable interrupt requests for
                                      frame transmission event */
    boolean MDIOSupport;        /**< Support MDIO for current controller */
} Eth_43_PFE_StaticCtrlCfgType;

/*
* @brief This type is used to group all multiple configurations.
*/
typedef struct
{
    const Eth_43_PFE_CtrlCfgType *pController[ETH_43_PFE_MAXCTRLS_SUPPORTED];
    const Eth_43_PFE_HifCfgType *pHif;
    const Eth_43_PFE_EmacCfg *emac;
} Eth_43_PFE_ConfigType;
/*
* @brief This type is used to group Static configuration for all controllers.
*/
typedef struct
{
    const Eth_43_PFE_StaticCtrlCfgType * pController[ETH_43_PFE_MAXCTRLS_SUPPORTED];
} Eth_43_PFE_StaticConfigType;

/*
* @brief HIF driver per controller client static FIFO declarations
*/
[!SELECT "EthConfigSet"!][!// Select configuration
[!VAR "ConfigSet" = "as:name(.)"!]
[!LOOP "EthCtrlConfig/*"!]
[!CALL "GetDemParameters"!]
[!VAR "CtrlConfigName" = "name(.)"!]
typedef struct
{
    fifo_t rx_fifo[ETH_43_PFE_MAX_RXFIFO_CONFIG];
    fifo_t tx_conf_fifo[[!"num:i(count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*))"!]U];
    [!CALL "rx_tx_fifo_depth_per_controller"!][!// output: rx_fifo_buf_num_max tx_fifo_buf_num_max
    void *rx_fifo_data[RXTX_FIFO_ALIGNED_DEPTH([!"num:i($rx_fifo_buf_num_max)"!]U) * ETH_43_PFE_MAX_RXFIFO_CONFIG];
    void *tx_conf_fifo_data[RXTX_FIFO_ALIGNED_DEPTH([!"num:i($tx_fifo_buf_num_max)"!]U) * [!"num:i(count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*))"!]U];
} Pfe_Hif_Drv_Client_FIFOs_[!"$ConfigSet"!]_[!"$CtrlConfigName"!]_t;
[!CR!][!ENDLOOP!]
[!ENDSELECT!]

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define ETH_43_PFE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/* Configuration for parameters which are not variant */
extern const Eth_43_PFE_StaticConfigType Eth_43_PFE_StaticConfig;

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
    [!SELECT "EthConfigSet"!][!// Select configuration
        [!VAR "ConfigSet" = "as:name(.)"!]
        [!VAR "variantIndex"="0"!]
        [!VAR "variantNumber"="variant:size()"!]
        [!LOOP "variant:all()"!]
            [!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild' and (variant:size() <= 1))"!][!//
            [!ELSE!][!//
                [!CODE!][!WS4!]extern const Eth_43_PFE_ConfigType Eth_43_PFE_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];[!CR!][!ENDCODE!][!//
            [!ENDIF!][!//
            [!VAR "variantIndex"="$variantIndex + 1"!]
        [!ENDLOOP!]
    [!ENDSELECT!]
[!ELSE!][!//
    [!CODE!][!WS4!]extern const Eth_43_PFE_ConfigType Eth_43_PFE_Config;[!CR!][!ENDCODE!][!//
[!ENDIF!][!//
#define ETH_43_PFE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ETH_43_PFE_CFG_H */
/** @} */
