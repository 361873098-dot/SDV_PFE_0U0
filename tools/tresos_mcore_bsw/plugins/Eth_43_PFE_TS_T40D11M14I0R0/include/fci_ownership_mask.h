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
 *  Copyright 2022 NXP
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
 * @file        fci_ownership_mask.h
 * @brief       The FCI ownership permission mask
 */

#ifndef PUBLIC_FCI_OWNERSHIP_MASK_H_
#define PUBLIC_FCI_OWNERSHIP_MASK_H_

#include "pfe_ct.h"

/**
 * @brief   The bitmask list of HIF channels that are allowed to take FCI ownership
 */
typedef enum
{
    FCI_OWNER_HIF_INVALID = 0U,
    FCI_OWNER_HIF_0 = (1U << 0U),
    FCI_OWNER_HIF_1 = (1U << 1U),
    FCI_OWNER_HIF_2 = (1U << 2U),
    FCI_OWNER_HIF_3 = (1U << 3U),
    FCI_OWNER_HIF_NOCPY = (1U << 4U)
} pfe_fci_owner_hif_id_t;

static const pfe_fci_owner_hif_id_t pfe_fci_owner_hif_ids[PFE_PHY_IF_ID_INVALID + 1U] =
{
    [PFE_PHY_IF_ID_HIF_NOCPY] = FCI_OWNER_HIF_NOCPY,
    [PFE_PHY_IF_ID_HIF0] = FCI_OWNER_HIF_0,
    [PFE_PHY_IF_ID_HIF1] = FCI_OWNER_HIF_1,
    [PFE_PHY_IF_ID_HIF2] = FCI_OWNER_HIF_2,
    [PFE_PHY_IF_ID_HIF3] = FCI_OWNER_HIF_3,
    [PFE_PHY_IF_ID_INVALID] = FCI_OWNER_HIF_INVALID
};

/**
 * @brief       Convert interface id to bitmask value representing HIF channel that is allowed to take FCI ownership
 * @param[in]   phy interface id
 * @return      FCI owner HIF permission bitmask value
 */
static inline pfe_fci_owner_hif_id_t pfe_fci_owner_hif_from_phy_id(pfe_ct_phy_if_id_t phy)
{
    pfe_fci_owner_hif_id_t ret_val = FCI_OWNER_HIF_INVALID;

    if (PFE_PHY_IF_ID_INVALID >= phy)
    {
        ret_val = pfe_fci_owner_hif_ids[phy];
    }

    return ret_val;
}

#endif /* PUBLIC_FCI_OWNERSHIP_MASK_H_ */
