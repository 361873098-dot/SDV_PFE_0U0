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
 *  Copyright 2017-2023 NXP
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

#ifndef FCI_H_
#define FCI_H_

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

#include "oal.h"
#include "pfe_emac.h" /* pfe_mac_addr_t */
#include "pfe_rtable.h" /* pfe_rtable_t, pfe_rtable_dst_if_t */
#include "pfe_l2br.h" /* pfe_l2br_t */
#include "pfe_class.h" /* pfe_class_t */
#include "pfe_if_db.h"
#include "pfe_tmu.h"    /* pfe_tmu_t */
#include "fci_msg.h"

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
#include "fci_ownership_mask.h"
#endif /* #ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT */

/**
 * @brief   Information passed into the fci_init() function
 * @note    For future use
 */
typedef struct
{
    pfe_rtable_t *rtable;   /* The routing table object */
    pfe_l2br_t *l2_bridge;  /* The L2 bridge instance */
    pfe_class_t *class;     /* The classifier instance */
    pfe_if_db_t *phy_if_db; /* Pointer to platform driver phy_if DB */
    pfe_if_db_t *log_if_db; /* Pointer to platform driver log_if DB */
    pfe_tmu_t *tmu;         /* Pointer to platform driver tmu */
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    pfe_fci_owner_hif_id_t hif_fci_owner_chnls_mask;    /* Bit mask representing allowed FCI ownership */
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
} fci_init_info_t;

/**
 * @brief   FCI instance type
 */
typedef struct fci_tag fci_t;

typedef struct
{
    uint32_t stats;
} pfe_fp_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Send message to all FCI clients
 * @param[in]   msg Pointer to the buffer containing payload to be sent
 * @param[in]   rep Pointer to buffer where reply data shall be stored
 * @return      EOK if success, error code otherwise
 */
errno_t fci_core_client_send_broadcast(fci_msg_t *msg, fci_msg_t *rep);

errno_t fci_init(fci_init_info_t *info, const char_t *const identifier);
void fci_fini(void);

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_fp_get_text_statistics(pfe_fp_t *temp, char_t *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

errno_t fci_process_ipc_message(fci_msg_t *msg, fci_msg_t *rep_msg);    /* This is here because FCI proxy RPC calls need it. */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* FCI_H_ */
