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
 * @brief       The attached minihif driver
 * @details     This implementation, when called, configures a HIF channel to be
 *              used by a detached minihif driver to transmit and receive through
 *              PFE.
 * @addtogroup  dxgr_PFE_MINIHIF_DRV
 * @{
 *
 * @file        pfe_hif_drv.h
 * @brief       The HIF driver header file.
 * @details     This is the attached minihif driver API.
 *
 */

#ifndef PFE_MINIHIF_DRV_H
#define PFE_MINIHIF_DRV_H


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

#include "pfe_cfg.h"
#include "pfe_platform_cfg.h"
#include "pfe_ct.h"
#include "oal.h"
#include "pfe_phy_if.h"
#include "pfe_hif_chnl.h"
#include "pfe_hif_ring.h"

/**
 * @brief   miniHIF driver instance representation - not to be accessed directly by user
 */
typedef struct
{
    pfe_ct_phy_if_id_t id;
    pfe_hif_chnl_t channel;
    pfe_hif_ring_t rx_ring;
    pfe_hif_ring_t tx_ring;
    bool_t rx_ring_created;
    bool_t tx_ring_created;
    bool_t init_done;
}pfe_minihif_drv_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

extern errno_t pfe_minihif_drv_create(pfe_minihif_drv_t *hif_drv, pfe_ct_phy_if_id_t id, bool_t bd_access);
extern errno_t pfe_minihif_drv_attach_ring(pfe_minihif_drv_t *hif_drv, bool_t is_rx, void *bd_base_va, void *wb_bd_base_va, uint32_t length);
extern errno_t pfe_minihif_drv_init(pfe_minihif_drv_t *hif_drv);
extern errno_t pfe_minihif_drv_start_rx(pfe_minihif_drv_t *hif_drv);
extern errno_t pfe_minihif_drv_start_tx(pfe_minihif_drv_t *hif_drv);
extern pfe_ct_phy_if_id_t pfe_minihif_get_hif_id(const pfe_minihif_drv_t *hif_drv);
extern errno_t pfe_minihif_drv_stop(pfe_minihif_drv_t *hif_drv);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_MINIHIF_DRV_H */
