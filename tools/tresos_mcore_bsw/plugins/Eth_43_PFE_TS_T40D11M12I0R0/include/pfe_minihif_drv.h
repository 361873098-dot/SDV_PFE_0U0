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
 *  This code (or certain portions of it) is released for use under license
 *  from Imagination Technologies Limited.
 *  Copyright (c) 2019 Imagination Technologies Limited
 *  Copyright (c) 2020-2021 Imagination Technologies Limited
 *  Copyright 2018-2023 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *
 *  This file contains sample code only. It is not part of the production code deliverables.
 *
 * ========================================================================= */

/**
 * @defgroup    dxgr_PFE_MINIHIF_DRV miniHIF Driver
 * @brief       The miniHIF driver
 * @details     The miniHIF driver providing way to send and receive traffic.
 *
 * @addtogroup  dxgr_PFE_MINIHIF_DRV
 * @{
 *
 * @file        pfe_hif_drv.h
 * @brief       The HIF driver header file (QNX).
 * @details     This is the HIF driver API.
 *
 */

#ifndef PFE_MINIHIF_DRV_H
#define PFE_MINIHIF_DRV_H


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

#include "pfe_cfg.h"
#include "pfe_platform_cfg.h"
#include "pfe_ct.h"
#include "oal.h"
#if !defined(PFE_CFG_DETACHED_MINIHIF)
#include "pfe_phy_if.h"
#endif /* PFE_CFG_DETACHED_MINIHIF */
#include "pfe_hif_chnl.h"
#include "pfe_hif_ring.h"

#if defined(PFE_CFG_DETACHED_MINIHIF)
    /* FIXME AAVB-2553
       In current implementation, BD access is only supported on the detached minihif driver.
       This limitation shall be removed after support for dynamic Tx headers is implemented. */
    #define PFE_MINIHIF_BD_ACCESS_SUPPORT
#endif /* PFE_CFG_DETACHED_MINIHIF */

#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
/**
 * @brief    Scatter-Gather list length
 * @details  Maximum length of SG list represented by hif_drv_sg_list_t.
 */
#define PFE_MINIHIF_SG_LIST_LENGTH    4U
#define PFE_MINIHIF_PHY_IF_ID_AUX     PFE_PHY_IF_ID_INVALID

typedef struct
{
    uint32_t size;                      /*  Number of valid 'items' entries */

    struct
    {
        void *data_pa;                  /*  Pointer to buffer (PA) */
        void *data_va;                  /*  Pointer to buffer (VA) */
        uint32_t len;                   /*  Buffer length */
    } items[PFE_MINIHIF_SG_LIST_LENGTH];    /*  SG list items */

    /* Internals */
    /* pfe_hif_drv_flags_t flags; */    /*  Flags */ /* TODO */
    pfe_ct_phy_if_id_t dst_phy;         /*  Destination physical interface */
} pfe_minihif_drv_sg_list_t;
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */

/**
 * @brief   miniHIF driver instance representation
 */
typedef struct
{
    pfe_hif_chnl_t channel;
    bool_t rx_started;
    bool_t tx_started;
    bool_t bd_access;
    bool_t is_master;
#if !defined(PFE_CFG_DETACHED_MINIHIF)
    pfe_bmu_t *bmu;
#endif /* PFE_CFG_DETACHED_MINIHIF */
    pfe_ct_phy_if_id_t id;
    bool_t init_done; /*TODO implement also in other functions?*/
    pfe_ct_hif_tx_hdr_t *hif_tx_header; /*  Storage for the common HIF header */
    void *hif_tx_header_pa;             /*  HIF TX header physical address */
    uint16_t tx_hdr_buf_num;
    pfe_hif_ring_t rx_ring;
    pfe_hif_ring_t tx_ring;
    uint16_t tx_ring_length;
#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
    bool_t internal_rx_ring;
    bool_t internal_tx_ring;
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */
}pfe_minihif_drv_t;

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

extern errno_t pfe_minihif_drv_create(pfe_minihif_drv_t *hif_drv, pfe_ct_phy_if_id_t id, bool_t bd_access);
#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
#ifdef HIF_CFG_USE_DYNAMIC_TX_HEADERS
/* Required to call if bd_access is TRUE */
extern errno_t pfe_minihif_drv_add_tx_hdr_buf_array(pfe_minihif_drv_t *hif_drv, void *tx_hdr_va, uint16_t buf_num);
#else
/* Required to call if bd_access is TRUE */
extern errno_t pfe_minihif_drv_add_static_tx_hdr_buf(pfe_minihif_drv_t *hif_drv, void *tx_hdr_va);
#endif /* HIF_CFG_USE_DYNAMIC_TX_HEADERS */
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */
/* If the HW configuration and BD access is done in two different applications, then this function is required to be called for both Rx and Tx ring in both applications with same values. Otherwise use of this function is optional. */
/* In case of hif nocopy use wb_bd_base_va=NULL */
extern errno_t pfe_minihif_drv_attach_ring(pfe_minihif_drv_t *hif_drv, bool_t is_rx, void *bd_base_va, void *wb_bd_base_va, uint32_t length);
/* Checks all inputs, creates all internal structures, initializes HW (if applicable) */
extern errno_t pfe_minihif_drv_init(pfe_minihif_drv_t *hif_drv);
extern errno_t pfe_minihif_drv_start_rx(pfe_minihif_drv_t *hif_drv);
extern errno_t pfe_minihif_drv_start_tx(pfe_minihif_drv_t *hif_drv);
#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
extern errno_t pfe_minihif_drv_xmit_sg(pfe_minihif_drv_t *hif_drv, pfe_ct_phy_if_id_t dst, uint8_t queue, const pfe_minihif_drv_sg_list_t *sg_list, const void *ref_ptr);
extern errno_t pfe_minihif_drv_get_tx_conf(pfe_minihif_drv_t *hif_drv, void **ref_ptr);
extern errno_t pfe_minihif_drv_get_rx_pkt(pfe_minihif_drv_t *hif_drv, uint8_t queue, void **buf, uint32_t *len, bool_t *lifm);
#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
    extern errno_t pfe_minihif_drv_release_rx_buf(pfe_minihif_drv_t *hif_drv, void *buf_va);
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */
extern errno_t pfe_minihif_drv_supply_rx_buffer(const pfe_minihif_drv_t *hif_drv, const void *buf, uint32_t len);
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */
extern pfe_ct_phy_if_id_t pfe_minihif_get_hif_id(const pfe_minihif_drv_t *hif_drv);

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

#endif /* PFE_MINIHIF_DRV_H */
