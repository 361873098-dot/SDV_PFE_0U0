/* =========================================================================
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
 *  Copyright 2019-2024 NXP
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
    #if (PFE_SRC_VERSION_CHECK != 43140440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43140440
#endif

#define PFE_CFG_TARGET_OS_AUTOSAR
#define PFE_CFG_TARGET_ARCH_armv7le

/*  PFE_CFG_PFE_MASTER || PFE_CFG_PFE_SLAVE */
#define PFE_CFG_PFE_MASTER
/*  PFE_CFG_BUILD_PROFILE_DEBUG || PFE_CFG_BUILD_PROFILE_RELEASE */
#define PFE_CFG_BUILD_PROFILE_RELEASE

/**
 * @brief   RX buffer management
 * @details When TRUE then RX buffer management is embedded so caller layer
 *          does not need to care about it. FALSE disables the feature.
 */
#define PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED TRUE

/* Enables/Disables the HIF interrupt */
#define PFE_CFG_HIF_IRQ_ENABLED       TRUE

/* Enables/Disables the BMU interrupt */
#define PFE_CFG_BMU_IRQ_ENABLED        TRUE


#define PFE_CFG_MC_HIF
#define PFE_CFG_MULTI_INSTANCE_SUPPORT
#define PFE_CFG_MASTER_IF               (PFE_PHY_IF_ID_HIF0)
/* FCI Ownership */
#define PFE_CFG_HIF1_OWNERSHIP
#define PFE_CFG_HIF2_OWNERSHIP
#define PFE_CFG_HIF3_OWNERSHIP

#define PFE_CFG_ERR051211_WORKAROUND_ENABLE
#define PFE_CFG_FCI_ENABLE
#define PFE_CFG_L2BRIDGE_ENABLE
#define PFE_CFG_RTABLE_ENABLE
#define PFE_CFG_RT_HASH_SIZE            64U
#define PFE_CFG_RT_COLLISION_SIZE       64U
#define PFE_CFG_CONN_STATS_SIZE         20U
#define PFE_CFG_FLEX_PARSER_AND_FILTER

#define PFE_CFG_CLASS_FW_FEATURES_COUNT 22UL

#define PFE_CFG_BD_MEM  "bd_mem"     /* Used for buffer descriptors and tx headers (nocache) */
#define PFE_CFG_RX_MEM  "rx_buf_mem" /* Rx buffers (nocache) */
#define PFE_CFG_TX_MEM  "tx_buf_mem" /* Tx buffers (nocache) */

#define PFE_CFG_IEEE1588_SUPPORT
/*Input clock frequency for the IEEE1588 timestamping unit (EMAC)*/
#define PFE_CFG_IEEE1588_I_CLK_HZ   200000000U
/*Output clock to be used to drive the IEEE1588 system time counter*/
#define PFE_CFG_IEEE1588_EMAC0_O_CLK_HZ 100000000U
#define PFE_CFG_IEEE1588_EMAC1_O_CLK_HZ 100000000U
#define PFE_CFG_IEEE1588_EMAC2_O_CLK_HZ 100000000U

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
#define FCI_MAX_TABLES 1U
/* FCI maximum number of rule instances */
#define PFE_CFG_FCI_FP_MAX_RULES 20U
/* Maximum number of MAC entries per interface */
#define PFE_CFG_MAC_DB_ENTRIES_MAX 8U
/* Maximum length of logical interface name (including \0 termination character). Must be greater than one. */
#define PFE_CFG_LOG_IF_NAME_LENGTH_MAX 16U
/* maximum number of mirrors in PFE */
#define PFE_CFG_MIRRORS_MAX 8U
/* maximum number of L2BR domains */
#define PFE_CFG_L2BR_DOMAINS_MAX 64U
/* enable using L2BR static entries */
#define PFE_CFG_L2BR_STATICS_ENABLE
/* maximum number of L2BR static entries */
#define PFE_CFG_L2BR_STATICS_MAX 16U
#endif /*PFE_CFG_H*/
