/**
*   @file       Eth_43_PFE_PBcfg.c
*   @implements Eth_43_PFE_PBcfg.c_Artifact
*
*   @brief   AUTOSAR Eth_43_PFE driver Post-Build configuration file
*   @details File containing the configuration for the Ethernet driver
*   @note    This file was generated on 2026-08-18.
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
    #include "EthTrcv.h"
#endif

#if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    #include "EthSwt.h"
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
/*******************************************************************************
* Multiple configurations
*******************************************************************************/

static const Eth_43_PFE_SchedulerInputInfoCfgType Eth_43_PFE_InputInfo_PBConfigEthCtrlConfig_0_EthCtrlConfigScheduler_0[] =
{
    {
        0U,
        0U,
        IS_FIFO,
        0U
    },
    {
        1U,
        0U,
        IS_FIFO,
        1U
    } 
};


static const Eth_43_PFE_SchedulerCfgType Eth_43_PFE_Scheduler_PBConfigEthCtrlConfig_0[] =
{
    {
        ((boolean)TRUE),
        SCHED_ALGO_RR,
        RATE_MODE_PACKET_RATE,
        2U,
        Eth_43_PFE_InputInfo_PBConfigEthCtrlConfig_0_EthCtrlConfigScheduler_0
    } 
};

#define ETH_43_PFE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
/*
* @brief HIF driver per controller client static FIFO definitions
*/
static Pfe_Hif_Drv_Client_FIFOs_EthConfigSet_EthCtrlConfig_0_t Pfe_Hif_Drv_Client_FIFOs_EthConfigSet_EthCtrlConfig_0;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static const Eth_43_PFE_EgressTxCfgType Eth_43_PFE_Egress_PBConfigEthCtrlConfig_0[] =
{
    {
        Pfe_Hif_Drv_Client_FIFOs_EthConfigSet_EthCtrlConfig_0.tx_conf_fifo,
        Pfe_Hif_Drv_Client_FIFOs_EthConfigSet_EthCtrlConfig_0.tx_conf_fifo_data,
        (uint16)1522U,
        (uint16)1544U,
        (uint16)2U
    },
    {
        Pfe_Hif_Drv_Client_FIFOs_EthConfigSet_EthCtrlConfig_0.tx_conf_fifo,
        Pfe_Hif_Drv_Client_FIFOs_EthConfigSet_EthCtrlConfig_0.tx_conf_fifo_data,
        (uint16)1522U,
        (uint16)1544U,
        (uint16)2U
    } 
};

static const Eth_43_PFE_IngressCfgType Eth_43_PFE_Ingress_PBConfigEthCtrlConfig_0[] =
{
    {
        Pfe_Hif_Drv_Client_FIFOs_EthConfigSet_EthCtrlConfig_0.rx_fifo,
        Pfe_Hif_Drv_Client_FIFOs_EthConfigSet_EthCtrlConfig_0.rx_fifo_data,
        (uint16)1522U,
        (uint16)4U
    } 
};

static const Eth_43_PFE_EmacCfg PfeEthConfigSet_EMAC[] =
{
    {
        EMAC_MODE_INVALID,
        EMAC_SPEED_INVALID,
        EMAC_DUPLEX_INVALID,
        {31, 31, 31, 31, 31, 31, 31, 31}
    },
    {
        EMAC_MODE_SGMII,
        EMAC_SPEED_1000_MBPS,
        EMAC_DUPLEX_FULL,
        {31, 31, 31, 31, 31, 31, 31, 31}
    },
    {
        EMAC_MODE_RGMII,
        EMAC_SPEED_1000_MBPS,
        EMAC_DUPLEX_FULL,
        {31, 31, 31, 31, 31, 31, 31, 31}
    }
};

/**
* @var Specified for EthCtrlConfig: MODULE-CONFIGURATION
* @par Memory usage:
*/
  static const Eth_43_PFE_CtrlCfgType PfeEthConfigSet_EthCtrlConfig_0 =
{
    {0xd8, 0xcb, 0x8a, 0xa3, 0x7d, 0xca }, /**< MAC address */
    PFE_PHY_IF_ID_EMAC0, /**< Port to be attached to the controller */
    PFE_CTRL_TYPE_EMAC, /**< Type of the controller */
    ((boolean)FALSE), /**< Promiscuous mode disabled */
    ((boolean)FALSE), /**< Loopback on EMAC is disabled */
    ((boolean)FALSE),/**< Controller will accept only management traffic from EMAC */
    EMAC_MODE_SGMII,
    EMAC_SPEED_1000_MBPS,
    EMAC_DUPLEX_FULL,
    0U,  /**< Instance ID of the controller within the EthIf module context */
    Eth_43_PFE_Egress_PBConfigEthCtrlConfig_0,
    Eth_43_PFE_Ingress_PBConfigEthCtrlConfig_0,
    2U,
    2U,
    4U,
    {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
    Eth_43_PFE_Scheduler_PBConfigEthCtrlConfig_0,
    1U,
    NULL_PTR,
    0U
    #if STD_ON == ETH_43_PFE_DEM_EVENT_DETECT
    ,{(uint32)STD_ON,DemConf_DemEventParameter_ETH_E_ACCESS },
    {(uint32)STD_ON,DemConf_DemEventParameter_ETH_E_RX_FRAMES_LOST },
    {(uint32)STD_ON,DemConf_DemEventParameter_ETH_E_CRC },
    {(uint32)STD_ON,DemConf_DemEventParameter_ETH_E_UNDERSIZEFRAME },
    {(uint32)STD_ON,DemConf_DemEventParameter_ETH_E_OVERSIZEFRAME },
    {(uint32)STD_ON,DemConf_DemEventParameter_ETH_E_ALIGNMENT },
    {(uint32)STD_ON,DemConf_DemEventParameter_ETH_E_SINGLECOLLISION },
    {(uint32)STD_ON,DemConf_DemEventParameter_ETH_E_MULTIPLECOLLISION },
    {(uint32)STD_ON,DemConf_DemEventParameter_ETH_E_LATECOLLISION }
    #endif
    #if (STD_ON == ETH_43_PFE_CTRLENABLE_MII)
    ,{
        &EthTrcv_ReadMiiIndication,
        &EthTrcv_WriteMiiIndication
    }
    #endif
    #if (STD_ON == ETH_43_PFE_SWT_MANAGEMENT_SUPPORT_API)
    ,{
        &EthSwt_EthTxAdaptBufferLength,
        &EthSwt_EthTxPrepareFrame,
        &EthSwt_EthTxProcessFrame,
        &EthSwt_EthTxFinishedIndication,
        &EthSwt_EthRxProcessFrame,
        &EthSwt_EthRxFinishedIndication
    }
    #endif
};

/**
* @var Hif configuration - independent from controller
* @par Memory usage:
*/
static const Eth_43_PFE_HifCfgType PfeHifEthConfigSet =
{
    /* Common HIF (HIF0) */
    .u16RxBDNum = 81U,
    .u16TxBDNum = 9U,
    .u16RxBufNum = 80U,
    .u16RxBufSize = 1544U
};

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

const Eth_43_PFE_ConfigType Eth_43_PFE_Config = 
{
    {
        &PfeEthConfigSet_EthCtrlConfig_0
    },
    &PfeHifEthConfigSet,
    PfeEthConfigSet_EMAC
};

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
