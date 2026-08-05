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
 *  <<< PFE Restricted Software >>>
 *
 * ========================================================================= */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"

#include "pfe_cbus.h"
#include "pfe_hif_nocpy.h"
#include "pfe_platform_cfg.h"
#include "pfe_hif_chnl.h"

struct pfe_hif_nocpy_tag
{
    addr_t base_va;                     /*  CBUS base virtual address */
    pfe_hif_chnl_t *channel;            /*  Associated channel instance */
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
static pfe_hif_chnl_t hif_chnl_memory;
#endif
static pfe_hif_nocpy_t hif_nocpy_instance;

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
static void pfe_hif_nocpy_free(pfe_hif_nocpy_t *hif);
static errno_t pfe_hif_nocpy_create_chnl(pfe_hif_nocpy_t *hif, const pfe_bmu_t *bmu, uint16_t lmem_header_size);

/**
 * @brief       Free HIF_NOCPY instance
 * @param[in]   hif hif instance
 */
static void pfe_hif_nocpy_free(pfe_hif_nocpy_t *hif)
{
    if (NULL != hif->channel)
    {
        pfe_hif_chnl_destroy(hif->channel);
        hif->channel = NULL;
    }

    pfe_hif_nocpy_cfg_fini(hif->base_va);
}

/**
 * @brief       Create new HIF_NOCPY channel
 * @param[in]   hif HIF_NOCPY instance
 * @param[in]   bmu BMU providing buffers for HIF NOCPY operation
 * @return      The HIF_NOCPY instance or NULL if failed
 */
static errno_t pfe_hif_nocpy_create_chnl(pfe_hif_nocpy_t *hif, const pfe_bmu_t *bmu, uint16_t lmem_header_size)
{
    errno_t ret;

    ret = pfe_hif_chnl_create(&hif_chnl_memory, hif->base_va, PFE_HIF_CHNL_NOCPY_ID, bmu, FALSE);
    if (EOK != ret)
    {
        NXP_LOG_ERROR("Can't create HIF_NOCPY channel instance\n");
        pfe_hif_nocpy_free(hif);
    }
    else
    {
        hif->channel = &hif_chnl_memory;
        pfe_hif_chnl_set_lmem_hdr_size(hif->channel, lmem_header_size);
        /*  Initialize the channel */
        ret = pfe_hif_chnl_init(hif->channel, FALSE);
        if(EOK != ret)
        {
            pfe_hif_nocpy_free(hif);
        }
        else
        {
            /* Disable both directions */
            pfe_hif_chnl_rx_disable(hif->channel);
            pfe_hif_chnl_tx_disable(hif->channel);
        }
    }

    return ret;
}
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/**
 * @brief       Create new HIF_NOCPY instance
 * @details     Creates and initializes HIF_NOCPY instance
 * @param[in]   base_va HIF_NOCPY base virtual address
 * @param[in]   bmu BMU providing buffers for HIF NOCPY operation
 * @param[in]   lmem_header_size
 * @return      The HIF_NOCPY instance or NULL if failed
 */
pfe_hif_nocpy_t *pfe_hif_nocpy_create(addr_t base_va, const pfe_bmu_t *bmu, uint16_t lmem_header_size)
{
    pfe_hif_nocpy_t *hif;
    errno_t          ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_ADDR == base_va) || (NULL == bmu)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        hif = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        hif = &hif_nocpy_instance;
        (void)autolibc_memset(hif, 0, sizeof(pfe_hif_nocpy_t));
        hif->base_va = base_va;
        hif->channel = NULL_PTR;

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)  /* Enable only if HIF_NOCPY is used */
        ret = pfe_hif_nocpy_cfg_init(hif->base_va);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("HIF_NOCPY configuration failed: %d\n", ret);
            pfe_hif_nocpy_free(hif);
            hif = NULL;
        }
        else
        {
            ret = pfe_hif_nocpy_create_chnl(hif, bmu, lmem_header_size);
            if (EOK != ret)
            {
                hif = NULL;
            }
        }
#else
        (void) bmu;
        (void) lmem_header_size;
        (void) ret;
#endif
    }

    return hif;
}

/**
 * @brief       Get channel instance according to its ID
 * @param[in]   hif The HIF instance
 * @param[in]   channel_id The channel ID. Currently only PFE_HIF_CHNL_NOCPY_ID is supported.
 * @return      The HIF channel instance or NULL if failed
 */
pfe_hif_chnl_t *pfe_hif_nocpy_get_channel(const pfe_hif_nocpy_t *hif, uint32_t channel_id)
{
    pfe_hif_chnl_t *hif_nocpy_chnl;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        hif_nocpy_chnl = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (channel_id != PFE_HIF_CHNL_NOCPY_ID)
        {
            hif_nocpy_chnl = NULL;
        }
        else
        {
            hif_nocpy_chnl = hif->channel;
        }
    }
    return hif_nocpy_chnl;
}

/**
 * @brief       Destroy HIF_NOCPY instance
 * @param[in]   hif The HIF_NOCPY instance
 */
void pfe_hif_nocpy_destroy(pfe_hif_nocpy_t *hif)
{
    if (NULL != hif)
    {
        if (NULL != hif->channel)
        {
            pfe_hif_chnl_rx_disable(hif->channel);
            pfe_hif_chnl_tx_disable(hif->channel);
            pfe_hif_chnl_destroy(hif->channel);
            hif->channel = NULL;
        }

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT) /* Enabled only if the local HIF is HIF_NOCPY */
        pfe_hif_nocpy_cfg_fini(hif->base_va);
        pfe_hif_nocpy_clear_emac_timer_ownership(hif);
#endif
    }
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return HIF_NOCPY runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   hif         The HIF_NOCPY instance
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   buf_len         Buffer length
 * @param[in]   verb_level  Verbosity level, number of data written to the buffer
 * @return      Number of bytes written to the buffer
 */
uint32_t pfe_hif_nocpy_get_text_statistics(const pfe_hif_nocpy_t *hif, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        len += pfe_hif_nocpy_cfg_get_text_stat(hif->base_va, buf, buf_len, verb_level);
    }
    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Marks that a PFE instance associated with the HIF_NOCPY is owner of all EMAC timers
 * @param[in]   hif The HIF_NOCPY instance
 */
void pfe_hif_nocpy_init_emac_timer_ownership(const pfe_hif_nocpy_t *hif)
{
    pfe_ct_phy_if_id_t emac_id;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (emac_id = PFE_PHY_IF_ID_EMAC0; emac_id <= PFE_PHY_IF_ID_EMAC2; emac_id++)
        {
            (void)pfe_hif_nocpy_cfg_set_emac_timer_ownership(emac_id, TRUE);
        }
        (void)hif;
    }
}
/**
 * @brief       Clear timer ownership status for the PFE instance associated with the HIF_NOCPY
 * @param[in]   hif The HIF_NOCPY instance
 */
void pfe_hif_nocpy_clear_emac_timer_ownership(const pfe_hif_nocpy_t *hif)
{
    pfe_ct_phy_if_id_t emac_id;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (emac_id = PFE_PHY_IF_ID_EMAC0; emac_id <= PFE_PHY_IF_ID_EMAC2; emac_id++)
        {
            (void)pfe_hif_nocpy_cfg_set_emac_timer_ownership(emac_id, FALSE);
        }
        (void)hif;
    }
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
