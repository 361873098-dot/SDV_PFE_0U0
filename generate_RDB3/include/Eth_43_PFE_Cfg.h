/**
*   @file       Eth_43_PFE_Cfg.h
*   @implements Eth_43_PFE_Cfg.h_Artifact
*
*   @brief   AUTOSAR Eth_43_PFE driver configuration header file
*   @details File containing the configuration for the Ethernet driver
*   @note    This file was generated on 2026-08-13.
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
#ifndef ETH_43_PFE_CFG_H
#define ETH_43_PFE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

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

#include "Det.h"
#include "Dem.h"
#include "Eth_GeneralTypes.h"
#include "Mcal.h"
#include "Soc_Ips.h"
#include "fifo.h"
#include "pfe_emac.h"
#include "pfe_tmu.h"

#include "Eth_43_PFE_VS_0_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_PFE_VENDOR_ID_CFG                    43
#define ETH_43_PFE_MODULE_ID_CFG                    88
#define ETH_43_PFE_AR_RELEASE_MAJOR_VERSION_CFG     4
#define ETH_43_PFE_AR_RELEASE_MINOR_VERSION_CFG     4
#define ETH_43_PFE_AR_RELEASE_REVISION_VERSION_CFG  0
#define ETH_43_PFE_SW_MAJOR_VERSION_CFG             1
#define ETH_43_PFE_SW_MINOR_VERSION_CFG             4
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
    #if ((ETH_43_PFE_AR_RELEASE_MAJOR_VERSION_CFG != DET_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_PFE_AR_RELEASE_MINOR_VERSION_CFG != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_43_PFE_Cfg.h and Det.h are different"
    #endif
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((ETH_43_PFE_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_43_PFE_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_43_PFE_Cfg.h and Dem.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define VARIANT_PRE_COMPILE 0
#define VARIANT_LINK_TIME 1
#define VARIANT_POST_BUILD 2
#define ETH_43_PFE_PRECOMPILE_SUPPORT     (STD_ON)
 /******************************************************************************
 * Diagnostic Event Manager (DEM)
 ******************************************************************************/
 #define ETH_43_PFE_DEM_EVENT_DETECT  (STD_ON)   /*!< Enables Diagnostic Event Manager */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*
* Symbolic names of groups.
*/
#define EthConf_EthCtrlConfigIngressFifo_EthCtrlConfigIngressFifo_0    0

    #define ETH_43_PFE_CFG_ENABLERXINTERRUPT(CtrlIdx)   ((*(Eth_43_PFE_StaticConfig.pController[CtrlIdx])).EnableRxInterrupt)
    #define ETH_43_PFE_CFG_ENABLETXINTERRUPT(CtrlIdx)   ((*(Eth_43_PFE_StaticConfig.pController[CtrlIdx])).EnableTxInterrupt)
    #define ETH_43_PFE_CFG_MDIOSUPPORT(CtrlIdx)         ((*(Eth_43_PFE_StaticConfig.pController[CtrlIdx])).MDIOSupport)
    #define ETH_43_PFE_CFG_MACADDRESS(CtrlIdx)          ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthMACAddress)
    #define ETH_43_PFE_CFG_CTRLIDXINETHIF(CtrlIdx)      ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlEthIfIdx)
    #define ETH_43_PFE_CFG_CTRLPHYIFID(CtrlIdx)         ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlPhyIfID)
    #define ETH_43_PFE_CFG_CTRLTYPE(CtrlIdx)            ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlType)
    #define ETH_43_PFE_CFG_ACCEPTALLTRAFFIC(CtrlIdx)    ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlAcceptAllTraffic)
    #define ETH_43_PFE_CFG_HIF_RXBD_NUM                 (Eth_43_PFE_InternalCfgPtr->pHif->u16RxBDNum)
    #define ETH_43_PFE_CFG_HIF_TXBD_NUM                 (Eth_43_PFE_InternalCfgPtr->pHif->u16TxBDNum)
    #define ETH_43_PFE_CFG_HIF_RX_BUF_NUM               (Eth_43_PFE_InternalCfgPtr->pHif->u16RxBufNum)
    #define ETH_43_PFE_CFG_HIF_RX_BUF_SIZE              (Eth_43_PFE_InternalCfgPtr->pHif->u16RxBufSize)
    #define ETH_43_PFE_CFG_PROMISCUOUS(CtrlIdx)         ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlPromiscuous)
    #define ETH_43_PFE_CFG_EMAC_LOOPBACK(CtrlIdx)       ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlEmacLoop)
    #define ETH_43_PFE_CFG_MIIMODE(CtrlIdx)             ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlMiiType)
    #define ETH_43_PFE_CFG_LINKSPEED(CtrlIdx)           ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlSpeed)
    #define ETH_43_PFE_CFG_LINKDUPLEX(CtrlIdx)          ((*(Eth_43_PFE_InternalCfgPtr->pController[CtrlIdx])).EthCtrlDuplex)
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

#define ETH_43_PFE_CONFIG_EXT \
      ETH_43_PFE_CONFIG_VS_0_PB \

#define RXTX_FIFO_ALIGNED_DEPTH(depth) ((((((uint32)(depth) * 4U) + (HAL_CACHE_LINE_SIZE - 1U)) / HAL_CACHE_LINE_SIZE) * HAL_CACHE_LINE_SIZE) / 4U)

/******************************************************************************
* Features enable/disable switches
******************************************************************************/
/* ETH004_Conf */
#define ETH_43_PFE_VERSION_INFO_API (STD_ON) /*!< Enables Version info function */
/* ETH005_Conf */
#define ETH_43_PFE_VERSION_INFO_API_MACRO (STD_OFF) /*!< Enables Version info function implementation as macro */

    /* This macro can have STD_OFF value only if the controller in all multiple configurations
       does not use the MII API. The value STD_ON means that code is compiled but the MII
       might not be used (API is present because it is needed in another multiple configuration
       but it is not called). */
    /* @requirements SWS_Eth_43_PFE_00012_Conf */
    #define ETH_43_PFE_CTRLENABLE_MII (STD_ON)         /*!< MII handling functions compilation enabled */
    #define ETH_43_PFE_CTRL_USE_45_MDIO_API (STD_ON)
    /* Enables/disables the GlobalTime APIs used amongst others by Global Time Synchronization over Ethernet */
    #define ETH_43_PFE_GLOBALTIME_SUPPORT   (STD_ON)
    /* Enables / Disables switch management support */
    #define ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API  (STD_OFF)
    /* Enables / Disables TX buffer release API */
    #define ETH_43_PFE_RELEASE_TX_BUFFER_API  (STD_ON)

    #define ETH_43_PFE_USE_MULTIPLE_HIFS (STD_OFF)
    #define ETH_43_PFE_COMMON_HIF        PFE_PHY_IF_ID_HIF0
    #define PFE_CFG_LOCAL_IF_VALUE 6U
    #define ETH_43_PFE_USINGHIF0 TRUE
    #define ETH_43_PFE_USINGHIF1 FALSE
    #define ETH_43_PFE_USINGHIF2 FALSE
    #define ETH_43_PFE_USINGHIF3 FALSE
    #define ETH_43_PFE_USINGHIF_NOCPY FALSE
    #define ETH_43_PFE_MULTI_INSTANCE    (STD_ON)
    #define ETH_43_PFE_MASTER_IF         (PFE_PHY_IF_ID_HIF0)
    #define ETH_43_PFE_SLAVE_MODE        (STD_OFF)
    #define ETH_43_PFE_BMU2_BUF_CNT      (256U)

    /*! @brief Enables / Disables Eth_43_PFE_GetClassStats API */
    #define ETH_43_GET_CLASS_STATISTIC_API    (STD_ON)
    /*! @brief Enables / Disables Eth_43_PFE_GetPFEStats API */
    #define ETH_43_GET_PFE_STATISTIC_API    (STD_ON)
    /*! @brief Enables / Disables Eth_GetCounterValues API */
    #define ETH_43_GET_COUNTER_API            (STD_ON)
    /*! @brief Enables / Disables Eth_GetTxStats API */
    #define ETH_43_GET_TXSTATS_API            (STD_ON)
    /*! @brief Enables / Disables Eth_GetRxStats API */
    #define ETH_43_GET_RXSTATS_API            (STD_ON)
    /*! @brief Enables / Disables Eth_GetTxErrorCounterValues API */
    #define ETH_43_GET_TXERROR_COUNTER_API    (STD_ON)

    /*! @brief Enables / Disables hardware offloading for IPv4 checksums */
    #define ETH_43_PFE_ENABLE_OFFLOAD_CSUM_IPV4         (STD_ON)
    /*! @brief Enables / Disables hardware offloading for TCP checksums */
    #define ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP          (STD_ON)
    /*! @brief Enables / Disables hardware offloading for UDP checksums */
    #define ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP          (STD_ON)
    /*! @brief Enables / Disables hardware offloading for ICMP checksums */
    #define ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP         (STD_ON)

    /*! @brief Enables / Disables channel cached BD flush API */
    #define ETH_43_PFE_CHANNEL_BD_FLUSH_API   (STD_ON)
    /*! @brief Max BDP flush loops per a single API call. 0 to disable the limit. */
    #define ETH_43_PFE_CHANNEL_BD_FLUSH_MAX_TICK_COUNT  (0U)
    /*! @brief Timeout value (in loop tournaround count) used to wait for the packet to be received on the slave HIF when BD flush. */
    #define ETH_43_PFE_CHANNEL_BD_FLUSH_TIMEOUT_COUNTER   (200U)

    /*! @brief IDEX request timeout in milliseconds between resending IDEX RPC requests. */
    #define PFE_CFG_IDEX_RESEND_DELAY_MS  (100U)

    /*! @brief IDEX request maximum retry count. */
    #define PFE_CFG_IDEX_RESEND_COUNT  (40U)

    /******************************************************************************
    * Development Error Detection
    ******************************************************************************/
    /* ETH003_Conf */
    #define ETH_43_PFE_DEV_ERROR_DETECT  (STD_ON)      /*!< Enables Development Error Detect feature */

    /******************************************************************************
    * Configuration constants
    ******************************************************************************/
    /* Required Eth buffers alignment, may be different for TX and RX depending on the used IP */
    #define ETH_43_PFE_TX_BUF_ALIGNMENT 8 /* 8 bytes */
    #define ETH_43_PFE_RX_BUF_ALIGNMENT 8 /* 8 bytes */
    /* ETH002_Conf */
    #define ETH_43_PFE_MAXCTRLS_SUPPORTED 3U  /* Number of supported controllers */
    #define ETH_43_PFE_CFG_MAIN_FCN_PERIOD_MS 100U  /* Period of Main function in miliseconds */
    #define ETH_43_PFE_DRIVER_INSTANCE 0U   /* Instance number assigned to the driver */
    #define ETH_43_PFE_NUM_EMAC                    (3U)
    #define ETH_43_PFE_NUM_CONTROLLER_CFG          (1U)
    /* Sizes of memory blocks allocated for TX/RX data buffers and related descriptors */
    #define ETH_43_PFE_MAX_RXFIFO_CONFIG           (1U)
    #define ETH_43_PFE_MAX_TX_PRIO_NUM             (7U)

    /* Used for BD memory allocation: */
    #define ETH_43_PFE_MAX_RXBD_CNT                (81U)
    #define ETH_43_PFE_MAX_TXBD_CNT                (9U)
    /* Used for buffer memory allocation (values are always >= 1 to avoid zero sized arrays): */
    #define ETH_43_PFE_MAX_RXBUF_POOLSZ            (123520U)
    #define ETH_43_PFE_MAX_RXBUF_META_POOLSZ       (2560U)
    #define ETH_43_PFE_MAX_TXBUF_POOLSZ            (6176U)
    /* Fifo/queue configuration */
    #define ETH_43_PFE_MAX_TXFIFO_CNT              (2U)
    #define ETH_43_PFE_MAX_FIFO_TX_BUF_CNT         (2U)
    #define ETH_43_PFE_MAX_CTRL_TX_BUF_CNT         (4U)
    #define ETH_43_PFE_META_BUF_SIZE               (32U)

    /******************************************************************************
    *   PFE FIRMWARE IMAGE LOCATION AND SIZE
    ******************************************************************************/
    #define PFE_CLASS_FW_BINARY pfe_class_fw_binary
    extern const uint8_t PFE_CLASS_FW_BINARY[];

#define ETH_43_PFE_ENABLE_USER_MODE_SUPPORT              (STD_OFF)
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == ETH_43_PFE_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running ETH_43_PFE in user mode, MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
        #endif /* (STD_ON == ETH_43_PFE_ENABLE_USER_MODE_SUPPORT */
#endif /*MCAL_ENABLE_USER_MODE_SUPPORT*/

    /*! @brief Size of buffer for copy .featrues section from fw elf file. */
    #define ETH_43_PFE_FEATURES_SECTION_BUFF_SIZE   (3000U)
    /*! @brief Size of buffer for copy .messages section from fw elf file. */
    #define ETH_43_PFE_MESSAGES_SECTION_BUFF_SIZE   (4000U)
    
    /******************************************************************************
    *   Driver Runtime Dem Error Detection
    ******************************************************************************/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_DRIVER_RUNTIME_ERR_INTERNAL        DemConf_DemEventParameter_ETH_E_DRIVER_RUNTIME_ERR_INTERNAL
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    /******************************************************************************
    *   PFE ECC Dem Error Detection
    ******************************************************************************/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_PFE_ECC_ERR    DemConf_DemEventParameter_ETH_E_PFE_ECC_ERR
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    /******************************************************************************
    *   PFE Watchdog Dem Error Detection
    ******************************************************************************/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_PFE_WDT_ERR    DemConf_DemEventParameter_ETH_E_PFE_WDT_ERR
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    /******************************************************************************
    *   EMAC Dem Error Detection
    ******************************************************************************/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_EMAC0_ECC_UNCORRECTABLE_ERR    DemConf_DemEventParameter_ETH_E_EMAC0_ECC_UNCORRECTABLE_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC0_ECC_ADDRESS_ERR          DemConf_DemEventParameter_ETH_E_EMAC0_ECC_ADDRESS_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC0_PARITY_ERR               DemConf_DemEventParameter_ETH_E_EMAC0_PARITY_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC0_WDT_ERR                  DemConf_DemEventParameter_ETH_E_EMAC0_WDT_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC1_ECC_UNCORRECTABLE_ERR    DemConf_DemEventParameter_ETH_E_EMAC1_ECC_UNCORRECTABLE_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC1_ECC_ADDRESS_ERR          DemConf_DemEventParameter_ETH_E_EMAC1_ECC_ADDRESS_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC1_PARITY_ERR               DemConf_DemEventParameter_ETH_E_EMAC1_PARITY_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC1_WDT_ERR                  DemConf_DemEventParameter_ETH_E_EMAC1_WDT_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC2_ECC_UNCORRECTABLE_ERR    DemConf_DemEventParameter_ETH_E_EMAC2_ECC_UNCORRECTABLE_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC2_ECC_ADDRESS_ERR          DemConf_DemEventParameter_ETH_E_EMAC2_ECC_ADDRESS_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC2_PARITY_ERR               DemConf_DemEventParameter_ETH_E_EMAC2_PARITY_ERR
    #define ETH_43_PFE_CFG_DEM_E_EMAC2_WDT_ERR                  DemConf_DemEventParameter_ETH_E_EMAC2_WDT_ERR
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    /******************************************************************************
    *   Bus Dem Error Detection
    ******************************************************************************/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_BUS_ERR    DemConf_DemEventParameter_ETH_E_BUS_ERR
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    /******************************************************************************
    *   PFE Parity Dem Error Detection
    ******************************************************************************/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_PFE_PARITY_ERR    DemConf_DemEventParameter_ETH_E_PFE_PARITY_ERR
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    /******************************************************************************
    *   Failstop Dem Error Detection
    ******************************************************************************/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_FAIL_STOP_HW_ERR    DemConf_DemEventParameter_ETH_E_FAIL_STOP_HW_ERR
    #define ETH_43_PFE_CFG_DEM_E_FAIL_STOP_FW_ERR    DemConf_DemEventParameter_ETH_E_FAIL_STOP_FW_ERR
    #define ETH_43_PFE_CFG_DEM_E_FAIL_STOP_SW_ERR    DemConf_DemEventParameter_ETH_E_FAIL_STOP_SW_ERR
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    /******************************************************************************
    *   BMU Dem Error Detection
    ******************************************************************************/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_BMU_FULL    DemConf_DemEventParameter_ETH_E_BMU_FULL
    #define ETH_43_PFE_CFG_DEM_E_BMU_ERR     DemConf_DemEventParameter_ETH_E_BMU_ERR
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    /******************************************************************************
    *   PE Dem Error Detection
    ******************************************************************************/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_PE_STALL_ERR        DemConf_DemEventParameter_ETH_E_PE_STALL_ERR
    #define ETH_43_PFE_CFG_DEM_E_PE_EXCEPTION_ERR    DemConf_DemEventParameter_ETH_E_PE_EXCEPTION_ERR
    #define ETH_43_PFE_CFG_DEM_E_PE_FW_ERR           DemConf_DemEventParameter_ETH_E_PE_FW_ERR
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    /******************************************************************************
    *   HIF Dem Error Detection
    ******************************************************************************/
#if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    #define ETH_43_PFE_CFG_DEM_E_HIF_ERR    DemConf_DemEventParameter_ETH_E_HIF_ERR
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef enum
{
    PFE_CTRL_TYPE_AUX,
    PFE_CTRL_TYPE_HIF,
    PFE_CTRL_TYPE_EMAC
} Eth_43_PFE_teCtrlType;

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
    uint8 EthTmuQueueSizes[8]; /**< array of emac queue sizes */
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
    pfe_ct_phy_if_id_t EthCtrlPhyIfID; /**< Port to be attached to the controller */
    Eth_43_PFE_teCtrlType EthCtrlType; /**< Type of the controller (AUX/HIF/EMAC) */
    boolean EthCtrlPromiscuous; /**< Promiscuous mode enabled/disabled */
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
  typedef struct
{
    fifo_t rx_fifo[ETH_43_PFE_MAX_RXFIFO_CONFIG];
    fifo_t tx_conf_fifo[2U];
    void *rx_fifo_data[RXTX_FIFO_ALIGNED_DEPTH(4U) * ETH_43_PFE_MAX_RXFIFO_CONFIG];
    void *tx_conf_fifo_data[RXTX_FIFO_ALIGNED_DEPTH(2U) * 2U];
} Pfe_Hif_Drv_Client_FIFOs_EthConfigSet_EthCtrlConfig_0_t;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define ETH_43_PFE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/* Configuration for parameters which are not variant */
extern const Eth_43_PFE_StaticConfigType Eth_43_PFE_StaticConfig;

 extern const Eth_43_PFE_ConfigType Eth_43_PFE_Config;
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
