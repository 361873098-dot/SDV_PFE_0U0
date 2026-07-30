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
 * @addtogroup  dxgr_PFE_MINIHIF_DRV
 * @{
 *
 * @file        pfe_minihif_drv.c
 * @brief       The miniHIF driver source file.
 * @details     This is the miniHIF driver with functionality limited to only simple
 *              packet transmission and reception.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "pfe_platform_cfg.h"
#include "oal.h"
#include "hal.h"
#include "pfe_hif_chnl.h"
#include "pfe_platform.h"
#include "pfe_log_if.h"
#include "pfe_cbus.h"
#include "Eth_43_PFE.h"
#include "pfe_minihif_drv.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Check if rings were attached
 * @param[in, out]  hif_drv The driver instance
 */
static errno_t check_rings(pfe_minihif_drv_t *hif_drv)
{
    errno_t ret;

    if(FALSE == hif_drv->rx_ring_created)
    {
        NXP_LOG_ERROR("RX BD ring was not attached\n");
        ret = EFAULT;
    }
    else if(FALSE == hif_drv->rx_ring_created)
    {
        NXP_LOG_ERROR("TX BD ring was not attached\n");
        ret = EFAULT;
    }
    else
    {
        ret = EOK;
    }

    return ret;
}
/**
 * @brief       Enable the phy_if associated with the HIF channel
 * @param[in, out]  hif_drv The driver instance
 */
static errno_t turn_hif_phyif_on_off(pfe_minihif_drv_t *hif_drv, bool_t enable)
{
    const pfe_platform_t *pPlatform;
    pfe_phy_if_t *prHif;
    errno_t ret = EOK;

    /*  Get the physical interface for our HIF channel */
    pPlatform = (const pfe_platform_t *)Eth_43_PFE_GetPlatform();
    prHif = pfe_platform_get_phy_if_by_id(pPlatform, hif_drv->id);
    if(NULL == prHif)
    {
        NXP_LOG_ERROR("Can't get physical interface for the HIF\n");
        ret = EFAULT;
    }
    /* Enable HIF physical interfaces */
    else 
    {
        if(TRUE == enable)
        {
            if(EOK != pfe_phy_if_enable(prHif))
            {
                NXP_LOG_ERROR("Failed to enable physical interface for the HIF\n");
                ret = EFAULT;
            }
        }
        else /* FALSE == enable */
        {
            if(EOK != pfe_phy_if_disable(prHif))
            {
                NXP_LOG_ERROR("Failed to disable physical interface for the HIF\n");
                ret = EFAULT;
            }
        }
    }

    return ret;
}

/**
 * @brief       Create the driver instance
 * @param[in]   hif_drv The driver instance
 * @param[in]   id The HIF ID in range from PFE_PHY_IF_ID_HIF0 to PFE_PHY_IF_ID_HIF3
 * @param[in]   bd_access Shall be FALSE as this implementation does not support datapath API
 * @retval      EOK if success, error code otherwise
 */
errno_t pfe_minihif_drv_create(pfe_minihif_drv_t *hif_drv, pfe_ct_phy_if_id_t id, bool_t bd_access)
{
    errno_t ret;

    if(unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
    {
        if(TRUE == bd_access)
        {
            NXP_LOG_ERROR("This implementation does not support datapath API\n");
            ret = EINVAL;
        }
        else
        {
            if((id < PFE_PHY_IF_ID_HIF0) || (id > PFE_PHY_IF_ID_HIF3))
            {
                NXP_LOG_ERROR("Unsupported HIF channel\n");
                ret = EINVAL;
            }
            else
            {
                hif_drv->id = id;
                hif_drv->rx_ring_created = FALSE;
                hif_drv->tx_ring_created = FALSE;
                hif_drv->init_done = FALSE;
                ret = EOK;
            }
        }
    }
    return ret;
}

/**
 * @brief       Attach ring to the driver instance
 * @param[in]   hif_drv The driver instance
 * @param[in]   is_rx ring is for Tx or Rx
 * @param[in]   bd_base_va Pointer to buffer descriptor base address
 * @param[in]   wb_bd_base_va Pointer to write-back buffer descriptor base address
 * @param[in]   length ring length
 * @retval      EOK if success, error code otherwise
 */
errno_t pfe_minihif_drv_attach_ring(pfe_minihif_drv_t *hif_drv, bool_t is_rx, void *bd_base_va, void *wb_bd_base_va, uint32_t length)
{
    pfe_hif_ring_t *ring;
    errno_t ret;

    if(unlikely((NULL == hif_drv)
              || (NULL == bd_base_va)
              || ((NULL == wb_bd_base_va) && (hif_drv->id != PFE_PHY_IF_ID_HIF_NOCPY))
                )
       )
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
    {
        if(TRUE == is_rx)
        {
            ring = &hif_drv->rx_ring;
        }
        else
        {
            ring = &hif_drv->tx_ring;
        }
        ret = pfe_hif_ring_create_minihif(ring, bd_base_va, wb_bd_base_va, length, is_rx);
        if(likely(EOK == ret))
        {
            if(TRUE == is_rx)
            {
                hif_drv->rx_ring_created = TRUE;
            }
            else
            {
                hif_drv->tx_ring_created = TRUE;
            }
        }
        else
        {
            NXP_LOG_ERROR("Could not create BD ring\n");
        }
    }
    return ret;
}

/**
 * @brief       Initialize the minihif driver
 * @param[in]   hif_drv The driver instance
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_minihif_drv_init(pfe_minihif_drv_t *hif_drv)
{
    errno_t ret;

    if(unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret =  EINVAL;
    }
    else
    {
        /* Check prerequisities */
        if(EOK != check_rings(hif_drv))
        {
            ret = EINVAL;
        }
        else
        {
            PfeDevAssert((uint32_t)hif_drv->id >= (uint32_t)PFE_PHY_IF_ID_HIF0);

            if(EOK != turn_hif_phyif_on_off(hif_drv, FALSE))
            {
                ret = EFAULT;
            }
            /* Create channel*/
            else if(EOK != pfe_hif_chnl_create_minihif  (   &hif_drv->channel, 
                                                            PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + CBUS_HIF_BASE_ADDR, 
                                                            (uint32_t)hif_drv->id - (uint32_t)PFE_PHY_IF_ID_HIF0,
                                                            &hif_drv->rx_ring, 
                                                            &hif_drv->tx_ring
                                                        )
                   )
            {
                NXP_LOG_ERROR("pfe_minihif_drv_init() failed to create minihif channel\n");
                ret = EFAULT;
            }
            else if(EOK != turn_hif_phyif_on_off(hif_drv, TRUE))
            {
                pfe_hif_chnl_destroy_chnl(&hif_drv->channel);
                ret = EFAULT;
            }
            else
            {
                pfe_hif_chnl_rx_disable(&hif_drv->channel);
                pfe_hif_chnl_tx_disable(&hif_drv->channel);
                hif_drv->init_done = TRUE;
                ret = EOK;
            }
        }
    }
    return ret;
}

/**
 * @brief       Enables data reception
 * @param[in]   hif_drv The driver instance
 */
errno_t pfe_minihif_drv_start_rx(pfe_minihif_drv_t *hif_drv)
{
    errno_t ret;

    if(unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if(FALSE == hif_drv->init_done)
    {
        NXP_LOG_ERROR("Minihif not initialized\n");
        ret = EINVAL;
    }
    else
    {
        ret = pfe_hif_chnl_rx_enable(&hif_drv->channel);
    }

    return ret;
}

/**
 * @brief       Enabled data transmission
 * @param[in]   hif_drv The driver instance
 */
errno_t pfe_minihif_drv_start_tx(pfe_minihif_drv_t *hif_drv)
{
    errno_t ret;

    if(unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if(FALSE == hif_drv->init_done)
    {
        NXP_LOG_ERROR("Minihif not initialized\n");
        ret = EINVAL;
    }
    else
    {
        ret = pfe_hif_chnl_tx_enable(&hif_drv->channel);
    }

    return ret;
}

/**
 * @brief       Disable minihif chnl Rx and Tx
 * @param[in]   hif_drv The driver instance
 */
errno_t pfe_minihif_drv_stop(pfe_minihif_drv_t *hif_drv)
{
    errno_t ret;

    if(unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if(FALSE == hif_drv->init_done)
    {
        NXP_LOG_ERROR("Minihif not initialized\n");
        ret = EINVAL;
    }
    else
    {
        pfe_hif_chnl_tx_disable(&hif_drv->channel);
        pfe_hif_chnl_rx_disable(&hif_drv->channel);
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Get HIF ID
 * @param[in]   hif_drv The driver instance
 * @return      Returns HIF channel ID if configured, otherwise PFE_PHY_IF_ID_INVALID is returned
 */
pfe_ct_phy_if_id_t pfe_minihif_get_hif_id(const pfe_minihif_drv_t *hif_drv)
{
    pfe_ct_phy_if_id_t ret;

    if(NULL == hif_drv)
    {
        ret = PFE_PHY_IF_ID_INVALID;
    }
    else if((hif_drv->id < PFE_PHY_IF_ID_HIF0) || (hif_drv->id > PFE_PHY_IF_ID_HIF3))
    {
        ret = PFE_PHY_IF_ID_INVALID;
    }
    else
    {
        ret = hif_drv->id;
    }
    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/** @}*/
