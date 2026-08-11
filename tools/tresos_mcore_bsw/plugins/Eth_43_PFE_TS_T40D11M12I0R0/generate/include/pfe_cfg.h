/* =========================================================================
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
 *  Copyright 2019-2023 NXP
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
 * ========================================================================= */
[!NOCODE!][!//
  [!INCLUDE "Eth_43_PFE_GetPfeParameters.m"!][!// Macros for hif interrupt
[!ENDNOCODE!][!//
/**
 *  @file     pfe_cfg.h
 *  @brief    PFE driver configuration file
 *  @details  This file needs to be included in all PFE sources before any other.
 *            PFE include. It contains macros specifying: target hardware, target OS,
 *            enabled features, and highlevel driver configuration.
 */
#ifndef PFE_CFG_H
#define PFE_CFG_H

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

#define PFE_CFG_TARGET_OS_AUTOSAR
#define PFE_CFG_TARGET_ARCH_armv7le

/*  PFE_CFG_PFE_MASTER || PFE_CFG_PFE_SLAVE */
[!IF "EthGeneral/EthVendorSpecific/EthPfeMultiInstance = 'true' and EthGeneral/EthVendorSpecific/EthPfeSlaveMode = 'true'"!][!//
#define PFE_CFG_PFE_SLAVE
[!IF "node:exists(EthGeneral/EthVendorSpecific/EthSlaveHifMasterUpTimeout)"!][!//
#define PFE_CFG_SLAVE_HIF_MASTER_UP_TMOUT          ((uint32)([!"num:i(EthGeneral/EthVendorSpecific/EthSlaveHifMasterUpTimeout)"!]U))
[!ELSE!][!//
#define PFE_CFG_SLAVE_HIF_MASTER_UP_TMOUT          ((uint32)0U)
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/SlaveReadStatCounterOfEmacDirectly = 'true'"!][!//
#define PFE_CFG_SLAVE_READ_EMAC_STAT_CNT_DIRECT    TRUE
[!ELSE!][!//
#define PFE_CFG_SLAVE_READ_EMAC_STAT_CNT_DIRECT    FALSE
[!ENDIF!][!//
[!ELSE!][!//
#define PFE_CFG_PFE_MASTER
[!ENDIF!][!//
/*  PFE_CFG_BUILD_PROFILE_DEBUG || PFE_CFG_BUILD_PROFILE_RELEASE */
#define PFE_CFG_BUILD_PROFILE_RELEASE

/**
 * @brief   RX buffer management
 * @details When TRUE then RX buffer management is embedded so caller layer
 *          does not need to care about it. FALSE disables the feature.
 */
#define PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED TRUE

/* Enables/Disables the HIF interrupt */
[!IF "$HifInterruptEnabled = 'true'"!][!//
#define PFE_CFG_HIF_IRQ_ENABLED       TRUE
[!ELSE!][!//
#define PFE_CFG_HIF_IRQ_ENABLED       FALSE
[!ENDIF!][!//

/* Enables/Disables the BMU interrupt */
#define PFE_CFG_BMU_IRQ_ENABLED       [!WS!][!IF "EthGeneral/EthVendorSpecific/EnableBmuInterrupt = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!][!CR!]

#define PFE_CFG_MC_HIF
[!IF "EthGeneral/EthVendorSpecific/EthPfeMultiInstance = 'true'"!][!//
#define PFE_CFG_MULTI_INSTANCE_SUPPORT
#define PFE_CFG_MASTER_IF               (PFE_PHY_IF_ID_[!"EthGeneral/EthVendorSpecific/EthPfeMasterHif"!])
[!ENDIF!][!//
/* FCI Ownership */
[!IF "EthGeneral/EthVendorSpecific/EnableFCIOwnership/PfeEnableFCIownershipHIF0 = 'true'"!][!//
#define PFE_CFG_HIF0_OWNERSHIP
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/EnableFCIOwnership/PfeEnableFCIownershipHIF1 = 'true'"!][!//
#define PFE_CFG_HIF1_OWNERSHIP
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/EnableFCIOwnership/PfeEnableFCIownershipHIF2 = 'true'"!][!//
#define PFE_CFG_HIF2_OWNERSHIP
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/EnableFCIOwnership/PfeEnableFCIownershipHIF3 = 'true'"!][!//
#define PFE_CFG_HIF3_OWNERSHIP
[!ENDIF!][!//

[!IF "EthGeneral/EthVendorSpecific/EnERR051211Workaround = 'true'"!][!//
#define PFE_CFG_ERR051211_WORKAROUND_ENABLE
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/PfeEnableFCI = 'true'"!][!//
#define PFE_CFG_FCI_ENABLE
[!IF "EthGeneral/EthVendorSpecific/EthPfeMultiInstance = 'false' or EthGeneral/EthVendorSpecific/EthPfeSlaveMode = 'false'"!][!//
[!IF "EthGeneral/EthVendorSpecific/PfeEnableBridge = 'true'"!][!//
#define PFE_CFG_L2BRIDGE_ENABLE
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/PfeEnableRouting = 'true'"!][!//
#define PFE_CFG_RTABLE_ENABLE
#define PFE_CFG_RT_HASH_SIZE            [!"EthGeneral/EthVendorSpecific/PfeRtHashSize"!]U
#define PFE_CFG_RT_COLLISION_SIZE       [!"EthGeneral/EthVendorSpecific/PfeRtCollisionSize"!]U
#define PFE_CFG_CONN_STATS_SIZE         [!"EthGeneral/EthVendorSpecific/PfeConnStatsSize"!]U
[!ENDIF!][!//
#define PFE_CFG_FLEX_PARSER_AND_FILTER
[!ENDIF!][!//
[!ELSE!][!//
#define PFE_CFG_CONN_STATS_SIZE         0U
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/EthCommonHif = 'HIF_NOCPY'"!][!//
#define PFE_CFG_HIF_NOCPY_SUPPORT
[!ENDIF!][!//

#define PFE_CFG_CLASS_FW_FEATURES_COUNT [!"num:i(EthGeneral/EthVendorSpecific/MaxNumFwFeaturesSupported)"!]UL

#define PFE_CFG_BD_MEM  "bd_mem"     /* Used for buffer descriptors and tx headers (nocache) */
#define PFE_CFG_RX_MEM  "rx_buf_mem" /* Rx buffers (nocache) */
#define PFE_CFG_TX_MEM  "tx_buf_mem" /* Tx buffers (nocache) */

[!IF "EthGeneral/EthGlobalTimeSupport = 'true'"!][!//
#define PFE_CFG_IEEE1588_SUPPORT
[!IF "EthGeneral/EthVendorSpecific/EthPfeMultiInstance = 'false' or EthGeneral/EthVendorSpecific/EthPfeSlaveMode = 'false'"!][!//
/*Input clock frequency for the IEEE1588 timestamping unit (EMAC)*/
#define PFE_CFG_IEEE1588_I_CLK_HZ   200000000U
/*Output clock to be used to drive the IEEE1588 system time counter*/
[!IF "EthGeneral/EthVendorSpecific/EthEMAC0Config/IEEE1588ClockAttachedToGMAC = 'true'"!][!//
#define PFE_CFG_IEEE1588_EMAC0_O_CLK_HZ 0U  /* Internal timestamping clock disabled, using external (attached to GMAC) */
[!ELSE!][!//
#define PFE_CFG_IEEE1588_EMAC0_O_CLK_HZ [!"num:i(EthGeneral/EthVendorSpecific/EthEMAC0Config/IEEE1588ClockOutputFrequencyHz)"!]U
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/EthEMAC1Config/IEEE1588ClockAttachedToEMAC0 = 'true'"!][!//
#define PFE_CFG_IEEE1588_EMAC1_O_CLK_HZ 0U  /* Internal timestamping clock disabled, using external (attached to EMAC0) */
[!ELSE!][!//
#define PFE_CFG_IEEE1588_EMAC1_O_CLK_HZ [!"num:i(EthGeneral/EthVendorSpecific/EthEMAC1Config/IEEE1588ClockOutputFrequencyHz)"!]U
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/EthEMAC2Config/IEEE1588ClockAttachedToEMAC0 = 'true'"!][!//
#define PFE_CFG_IEEE1588_EMAC2_O_CLK_HZ 0U  /* Internal timestamping clock disabled, using external (attached to EMAC0) */
[!ELSE!][!//
#define PFE_CFG_IEEE1588_EMAC2_O_CLK_HZ [!"num:i(EthGeneral/EthVendorSpecific/EthEMAC2Config/IEEE1588ClockOutputFrequencyHz)"!]U
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/EthEMAC0Config/EnablePpsOutput = 'true'"!][!//

#define PFE_CFG_EMAC0_PPS0_ENABLE
#define PFE_CFG_EMAC0_PPS0_PERIOD_TICKS [!"num:i(num:i(EthGeneral/EthVendorSpecific/EthEMAC0Config/PpsOutputPeriod)-1)"!]U
#define PFE_CFG_EMAC0_PPS0_PULSE_TICKS [!"num:i(num:i(EthGeneral/EthVendorSpecific/EthEMAC0Config/PpsOutputPulseWidth)-1)"!]U
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//

#if 0 /* These define will be used in the future */
#define PFE_CFG_HIF_SEQNUM_CHECK
#define PFE_CFG_NULL_ARG_CHECK
#define PFE_CFG_GET_ALL_ERRORS
#define PFE_CFG_CSUM_ALL_FRAMES
#define PFE_CFG_PARANOID_IRQ
#endif

#define PFE_S32G3_VERSION 0x00000101U

/******************************************************************************
*   PFE MEMORY SPACE RESERVATION FOR DEDICATED PURPOSE
******************************************************************************/

/* FCI maximum number of table instances */
#define FCI_MAX_TABLES [!"EthGeneral/EthVendorSpecific/PfeFciMaximumFpTableNumber"!]U
/* FCI maximum number of rule instances */
#define PFE_CFG_FCI_FP_MAX_RULES [!"EthGeneral/EthVendorSpecific/PfeFciMaximumFpRuleNumber"!]U
/* Maximum number of MAC entries per interface */
#define PFE_CFG_MAC_DB_ENTRIES_MAX [!"EthGeneral/EthVendorSpecific/PfeCfgMacDbEntriesMax"!]U
/* Maximum length of logical interface name (including \0 termination character). Must be greater than one. */
#define PFE_CFG_LOG_IF_NAME_LENGTH_MAX [!"EthGeneral/EthVendorSpecific/PfeLogIfNameLengthMax"!]U
/* maximum number of mirrors in PFE */
#define PFE_CFG_MIRRORS_MAX [!"EthGeneral/EthVendorSpecific/PfeMirrorsMax"!]U
[!IF "EthGeneral/EthVendorSpecific/PfeEnableBridge = 'true'"!][!//
/* maximum number of L2BR domains */
#define PFE_CFG_L2BR_DOMAINS_MAX [!"EthGeneral/EthVendorSpecific/PfeL2brDomainsMax"!]U
/* enable using L2BR static entries */
[!IF "EthGeneral/EthVendorSpecific/PfeL2brStaticsEnable = 'true'"!][!//
#define PFE_CFG_L2BR_STATICS_ENABLE
/* maximum number of L2BR static entries */
#define PFE_CFG_L2BR_STATICS_MAX [!"EthGeneral/EthVendorSpecific/PfeL2brStaticsMax"!]U
[!ENDIF!][!//
[!ENDIF!][!//
#endif /*PFE_CFG_H*/
