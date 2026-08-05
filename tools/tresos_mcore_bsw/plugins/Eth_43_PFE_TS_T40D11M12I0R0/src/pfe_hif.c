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
#include "pfe_hif.h"
#include "pfe_platform_cfg.h"

struct pfe_hif_tag
{
    pfe_hif_chnl_id_t configured_channels_mask; /* configured channels */
    addr_t cbus_base_va;            /*  CBUS base virtual address */
    pfe_hif_chnl_t channels[HIF_CFG_MAX_CHANNELS];
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
    bool_t disable_master_detect;   /* Shall be Master-detect disabled? */
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_hif_t hif_instance;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static void pfe_hif_destroy_chnl(pfe_hif_t *hif, int32_t count);
static errno_t pfe_hif_create_bind_chnl(pfe_hif_t *hif, pfe_hif_chnl_id_t channels_mask);

#ifdef PFE_CFG_PFE_MASTER

/**
 * @brief       Master HIF ISR
 * @param[in]   hif The HIF instance
 * @return      EOK if interrupt has been processed
 */
errno_t pfe_hif_isr(pfe_hif_t *hif)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Run the low-level ISR to identify and process the interrupt */
        ret = pfe_hif_cfg_isr(hif->cbus_base_va);
    }
    return ret;
}

/**
 * @brief       Mask HIF interrupts
 * @details     Only affects HIF IRQs, not channel IRQs.
 * @param[in]   hif The HIF instance
 */
void pfe_hif_irq_mask(pfe_hif_t *hif)
{
    pfe_hif_cfg_irq_mask(hif->cbus_base_va);
}

/**
 * @brief       Unmask HIF interrupts
 * @details     Only affects HIF IRQs, not channel IRQs.
 * @param[in]   hif The HIF instance
 */
void pfe_hif_irq_unmask(pfe_hif_t *hif)
{
    pfe_hif_cfg_irq_unmask(hif->cbus_base_va);
}
#endif /* PFE_CFG_PFE_MASTER */

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
void pfe_hif_set_master_detect_cfg(pfe_hif_t *hif, bool_t on)
{
    hif->disable_master_detect = (!on);
}

bool_t pfe_hif_get_master_detect_cfg(const pfe_hif_t *hif)
{
    return (!hif->disable_master_detect);
}
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

/**
 * @brief       Destroy created channels with attached rings
 * @param[in]   hif The HIF instance
 * @param[in]   count index of last channel to destroy. e.g value of 2 will destroy channels 2,1,0
 */
static void pfe_hif_destroy_chnl(pfe_hif_t *hif, int32_t count)
{
    int32_t ii = count;
    uint32_t channels_mask = (uint32_t)(1U << ii);
    /*  Destroy all created channels with all attached rings */
    /*  Destroy already created channels including rings if attached */
    for (; ii >= 0; ii--)
    {
        if(0U != ((uint32_t)hif->configured_channels_mask & channels_mask))
        {
            pfe_hif_chnl_destroy(&hif->channels[ii]);
            hif->configured_channels_mask &= ~channels_mask;
        }
        channels_mask >>= 1U;
    }
#ifdef PFE_CFG_PFE_MASTER
    /*  Disable HIF hardware */
    pfe_hif_cfg_fini(hif->cbus_base_va);
#endif /* PFE_CFG_PFE_MASTER */
}

/**
 * @brief       Create and bind hif channel
 * @param[in]   hif The HIF instance
 * @param[in]   channels_mask Bitmask specifying channels to be managed by the instance.
 * @return      EOK if success, otherwise if failed
 */
static errno_t pfe_hif_create_bind_chnl(pfe_hif_t *hif, pfe_hif_chnl_id_t channels_mask)
{
    errno_t ret = EOK;
    int32_t ii;

    for (ii = 0; ii < (int32_t)HIF_CFG_MAX_CHANNELS; ii++)
    {
        if (0U != ((uint32_t)channels_mask & (uint32_t)(0x1U << ii)))
        {
            ret = pfe_hif_chnl_create(&hif->channels[ii], hif->cbus_base_va, (uint32_t)ii, NULL, FALSE);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("Couldn't create channel\n");
                pfe_hif_destroy_chnl(hif, ii);
                break;
            }
            else
            {
                hif->configured_channels_mask |= (uint32_t)(1U << ii);

                /*  Disable both directions */
                pfe_hif_chnl_rx_disable(&hif->channels[ii]);
                pfe_hif_chnl_tx_disable(&hif->channels[ii]);
            }
        }
    }

    return ret;
}

/**
 * @brief       Create new HIF instance
 * @details     Creates and initializes HIF instance
 * @param[in]   cbus_base_va CBUS base virtual address
 * @param[in]   channels_mask Bitmask specifying channels to be managed by the instance.
 * @return      The HIF instance or NULL if failed
 */
pfe_hif_t *pfe_hif_create(addr_t cbus_base_va, pfe_hif_chnl_id_t channels_mask)
{

    pfe_hif_t *hif;
    errno_t    ret = ENOLCK;
#ifdef PFE_CFG_PFE_MASTER
    int32_t    ii = 0;
#endif /* PFE_CFG_PFE_MASTER */

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == cbus_base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        hif = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (0U != ((uint32_t)channels_mask & (~0xFUL)))
        {
            hif = NULL;
        }
        else
        {
            hif = &hif_instance;
            (void)autolibc_memset(hif, 0, sizeof(pfe_hif_t));
            hif->cbus_base_va = cbus_base_va;

#ifdef PFE_CFG_PFE_MASTER
            /*  Do HIF HW initialization */
            ret = pfe_hif_cfg_init(hif->cbus_base_va);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("HIF configuration failed: %d\n", ret);
                pfe_hif_destroy_chnl(hif, ii);
                hif = NULL;
            }
            else
#endif /* PFE_CFG_PFE_MASTER */
            {
                ret = pfe_hif_create_bind_chnl(hif, channels_mask);
                if (EOK != ret)
                {
                    hif = NULL;
                }
            }
        }
    }
    return hif;
}

/**
 * @brief       Get channel instance according to its ID. Return NULL is channel is not configured.
 * @details     The channel ID corresponds with indexing within
 *              the hardware (0, 1, 2 ... HIF_CFG_MAX_CHANNELS-1)
 * @param[in]   hif The HIF instance
 * @param[in]   channel_id The channel ID
 * @return      The HIF channel instance or NULL if failed or does not exists/not configured
 */
pfe_hif_chnl_t *pfe_hif_get_channel(const pfe_hif_t *hif, pfe_hif_chnl_id_t channel_id)
{
    uint32_t ii;
    pfe_hif_chnl_t *entry = NULL_PTR;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Get array index from channel ID */
        if (0U != ((uint32_t)hif->configured_channels_mask & channel_id))
        {
            for (ii = 0; ii < HIF_CFG_MAX_CHANNELS; ii++)
            {
                if (0U != ((uint32_t)channel_id & (uint32_t)(1U << ii)))
                {
                    entry = (pfe_hif_chnl_t *)&(hif->channels[ii]);
                    break;
                }
            }
        }
    }
    return entry;
}

/**
 * @brief       Destroy HIF instance
 * @param[in]   hif The HIF instance
 */
void pfe_hif_destroy(pfe_hif_t *hif)
{
    uint32_t ii;
    uint32_t channels_mask = 1U;

    if (NULL != hif)
    {

#ifdef PFE_CFG_PFE_MASTER
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
        /* Clean Master detect flags for all HIF channels */
        pfe_hif_clear_master_up(hif);
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
        /* Clear timer ownership for all HIF channels */
        pfe_hif_clear_emac_timer_ownership(hif);
#endif /* PFE_CFG_PFE_MASTER */

        for (ii=0U; ii<HIF_CFG_MAX_CHANNELS; ii++)
        {
            if(0U != ((uint32_t)hif->configured_channels_mask & channels_mask))
            {
                pfe_hif_chnl_rx_disable(&hif->channels[ii]);
                pfe_hif_chnl_tx_disable(&hif->channels[ii]);

                pfe_hif_chnl_destroy(&hif->channels[ii]);
                hif->configured_channels_mask &= ~channels_mask;
            }
            channels_mask <<= 1U;
        }

        /*  Finalize the HIF */
        pfe_hif_cfg_fini(hif->cbus_base_va);
    }
}

#ifdef PFE_CFG_PFE_MASTER
#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
/**
 * @brief       Reset master detect flags in all HIF channels
 * @param[in]   hif The HIF instance
 */
void pfe_hif_clear_master_up(const pfe_hif_t *hif)
{
    uint32_t ii;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (ii = 0U; ii < HIF_CFG_MAX_CHANNELS; ii++)
        {
            /* We can't use channel object because we need to set also
            not configured channels */
            (void)pfe_hif_chnl_cfg_set_master_up(hif->cbus_base_va, ii, FALSE);
        }
    }
}

/**
 * @brief       Set master detect flags in all HIF channels
 * @details     Set flag to MASTER_UP and optionally to HIF_OCCUPIED
 * @param[in]   hif The HIF instance
 */
void pfe_hif_set_master_up(const pfe_hif_t *hif)
{
    uint32_t ii;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (ii = 0U; ii < HIF_CFG_MAX_CHANNELS; ii++)
        {
            /* We can't use channel object because we need to set also
           not configured channels */
            if (0U != ((uint32_t)hif->configured_channels_mask & ((uint32_t)1U << ii)))
            {
                (void)pfe_hif_chnl_cfg_set_master_up(hif->cbus_base_va, ii, TRUE);
                (void)pfe_hif_chnl_cfg_set_hif_occupied(hif->cbus_base_va, ii, TRUE);
            }
            else
            {
                (void)pfe_hif_chnl_cfg_set_master_up(hif->cbus_base_va, ii, TRUE);
            }
        }
    }
}
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

/**
 * @brief       Marks that a PFE instance associated with the HIF instance is owner of all EMAC timers
 * @param[in]   hif The HIF instance
 */
void pfe_hif_init_emac_timer_ownership(const pfe_hif_t *hif)
{
    uint32_t chnl_id;
    pfe_ct_phy_if_id_t emac_id;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (chnl_id = 0U; chnl_id < HIF_CFG_MAX_CHANNELS; chnl_id++)
        {
            if (0U != ((uint32_t)hif->configured_channels_mask & ((uint32_t)1U << chnl_id)))
            {
                for (emac_id = PFE_PHY_IF_ID_EMAC0; emac_id <= PFE_PHY_IF_ID_EMAC2; emac_id++)
                {
                    (void)pfe_hif_chnl_cfg_set_emac_timer_ownership(hif->cbus_base_va, chnl_id, emac_id, TRUE);
                }
                break;
            }
        }
    }
}

/**
 * @brief       Clear timer ownership status for the PFE instance associated with the HIF instance
 * @param[in]   hif The HIF instance
 */
void pfe_hif_clear_emac_timer_ownership(const pfe_hif_t *hif)
{
    uint32_t chnl_id;
    pfe_ct_phy_if_id_t emac_id;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (chnl_id = 0U; chnl_id < HIF_CFG_MAX_CHANNELS; chnl_id++)
        {
            if (0U != ((uint32_t)hif->configured_channels_mask & ((uint32_t)1U << chnl_id)))
            {
                for (emac_id = PFE_PHY_IF_ID_EMAC0; emac_id <= PFE_PHY_IF_ID_EMAC2; emac_id++)
                {
                    (void)pfe_hif_chnl_cfg_set_emac_timer_ownership(hif->cbus_base_va, chnl_id, emac_id, FALSE);
                }
                break;
            }
        }
    }
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return HIF runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   hif         The HIF instance
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   size        Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 *
 */
uint32_t pfe_hif_get_text_statistics(const pfe_hif_t *hif, char_t *buf, uint32_t buf_len, uint8_t verb_level)
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
        len += pfe_hif_cfg_get_text_stat(hif->cbus_base_va, buf, buf_len, verb_level);
    }
    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */
#endif /* PFE_CFG_PFE_MASTER */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
