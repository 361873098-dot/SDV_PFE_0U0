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
 *  Copyright 2019-2022 NXP
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

#ifndef PUBLIC_PFE_IDEX_H_
#define PUBLIC_PFE_IDEX_H_

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

#include "pfe_hif_drv.h"
#include "pfe_hif.h"

/**
 * @brief       RPC request callback type
 * @details     To be called when IDEX has received RPC request
 * @warning     Don't block or sleep within the body
 * @param[in]   sender RPC originator identifier
 * @param[in]   id Request identifier
 * @param[in]   buf Pointer to request argument. Can be NULL.
 * @param[in]   buf_len Lenght of request argument. Can be zero.
 * @param[in]   arg Custom argument provided via pfe_idex_init()
 */
typedef void (*pfe_idex_rpc_cbk_t)(pfe_ct_phy_if_id_t sender, uint32_t id, void *buf, uint16_t buf_len, void *arg);
typedef void (*pfe_idex_tx_conf_free_cbk_t)(void *frame);

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

errno_t pfe_idex_init(pfe_hif_drv_t *hif_drv, pfe_ct_phy_if_id_t master, pfe_hif_t *hif, pfe_idex_rpc_cbk_t cbk, void *arg, pfe_idex_tx_conf_free_cbk_t txcf_cbk);
errno_t pfe_idex_rpc(pfe_ct_phy_if_id_t dst_phy, uint32_t id, const void *buf, uint16_t buf_len, void *resp, uint16_t resp_len);
errno_t pfe_idex_master_rpc(uint32_t id, const void *buf, uint16_t buf_len, void *resp, uint16_t resp_len);
errno_t pfe_idex_set_rpc_ret_val(errno_t retval, void *resp, uint16_t resp_len);
void pfe_idex_fini(void);
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
void pfe_idex_ihc_poll(void);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_PFE_IDEX_H_ */
