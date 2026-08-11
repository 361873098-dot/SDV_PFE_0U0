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
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "pfe_platform_cfg.h"
#include "oal.h"
#include "hal.h"
#include "pfe_hif_chnl.h"
#if !defined(PFE_CFG_DETACHED_MINIHIF)
    #include "pfe_platform.h"
    #include "pfe_log_if.h"
    #include "pfe_cbus.h"
    #include "pfe_hif_csr.h"
    #include "Eth_43_PFE.h"
#endif /* PFE_CFG_DETACHED_MINIHIF */
#include "pfe_minihif_drv.h"

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

/**
 * @brief       Destroy and free all objects created
 * @param[in, out]  hif_drv The driver instance
 * @param[in]   hif_base_offset HIF driver base offset.
 */
static void pfe_minihif_drv_destroy_and_free(pfe_minihif_drv_t *hif_drv, uint32_t hif_base_offset)
{
    /*  Destroy and free all objects created here */
    if(NULL != hif_drv)
    {   /* TODO - this was extracted from pfe_hif_chnl_destroy()
        better use the function, if it can be modified as pfe_hif_chnl_set_rx_ring was */
#if !defined(PFE_CFG_DETACHED_MINIHIF)
        pfe_hif_chnl_cfg_fini(PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + hif_base_offset, (uint32_t)(hif_drv->id - PFE_PHY_IF_ID_HIF0));
#else
    (void)hif_base_offset;
#endif
#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
    /* TODO remove the PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED support if not used in LLCE
       instead just add CT check to make sure PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED is disabled */
        if(NULL != hif_drv->channel.rx_pool)
        {
            bpool_destroy(hif_drv->channel.rx_pool);
        }
#endif
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */
    }
#if !defined(PFE_CFG_DETACHED_MINIHIF)
#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
    /* TODO remove the internal_rx_ring/internal_tx_ring support */
    if(TRUE == hif_drv->internal_rx_ring)
    {
        if(EOK != pfe_hif_ring_destroy(hif_drv->rx_ring))
        {
            NXP_LOG_ERROR("Failed to destroy rx_ring\n");
        }
        hif_drv->internal_rx_ring = FALSE;
    }
    if(TRUE == hif_drv->internal_tx_ring)
    {
        if(EOK != pfe_hif_ring_destroy(hif_drv->tx_ring))
        {
            NXP_LOG_ERROR("Failed to destroy tx_ring\n");
        }
        hif_drv->internal_tx_ring = FALSE;
    }
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */
#endif /*PFE_CFG_DETACHED_MINIHIF*/
}

#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
/**
 * @brief       Initialize Tx header
 * @param[in, out]  hif_drv The driver instance
 */
static errno_t pfe_minihif_drv_init_tx_header(pfe_minihif_drv_t *hif_drv)
{
    uint16_t i;
    errno_t ret;

    if(TRUE == hif_drv->bd_access)
    {
#ifdef HIF_CFG_USE_DYNAMIC_TX_HEADERS
        if(hif_drv->tx_hdr_buf_num != hif_drv->tx_ring_length)
        {
            NXP_LOG_ERROR("Function pfe_minihif_drv_add_tx_hdr_buf_array was not called or it was called with wrong buf_num value\n");
            ret = EFAULT;
        }
        else
#else
        if(hif_drv->tx_hdr_buf_num != 1U)
        {
            NXP_LOG_ERROR("Function pfe_minihif_drv_add_static_tx_hdr_buf was not called or failed\n");
            ret = EFAULT;
        }
        else
#endif /* HIF_CFG_USE_DYNAMIC_TX_HEADERS */
        {
            if(unlikely(NULL == hif_drv->hif_tx_header))
            {
                NXP_LOG_ERROR("Could not alloc static Tx header\n");
                ret = EFAULT;
            }
            else
            {
                for(i = 0U; i < hif_drv->tx_hdr_buf_num; i++)
                {
                    hif_drv->hif_tx_header[i].queue = 0U;
                    hif_drv->hif_tx_header[i].chid = ((uint8_t)hif_drv->id - (uint8_t)PFE_PHY_IF_ID_HIF0);
                    hif_drv->hif_tx_header[i].flags = HIF_TX_NO_FLAG;
                    /* Configure for checksum offload feature */
                    #if (TRUE == PFE_HIF_ENABLE_OFFLOAD_CSUM_IPV4)
                        hif_drv->hif_tx_header[i].flags |= HIF_TX_IP_CSUM;
                    #endif /* PFE_HIF_ENABLE_OFFLOAD_CSUM_IPV4 */
                    #if (TRUE == PFE_HIF_ENABLE_OFFLOAD_CSUM_TCP)
                        hif_drv->hif_tx_header[i].flags |= HIF_TX_TCP_CSUM;
                    #endif /* PFE_HIF_ENABLE_OFFLOAD_CSUM_TCP */
                    #if (TRUE == PFE_HIF_ENABLE_OFFLOAD_CSUM_UDP)
                        hif_drv->hif_tx_header[i].flags |= HIF_TX_UDP_CSUM;
                    #endif /* PFE_HIF_ENABLE_OFFLOAD_CSUM_UDP */
                }
                hif_drv->hif_tx_header_pa = oal_mm_virt_to_phys_contig((void *)hif_drv->hif_tx_header);
                ret = EOK;
            }
        }
    }
    else
    {
        ret = EOK;
    }

    return ret;
}
#endif

#if !defined(PFE_CFG_DETACHED_MINIHIF)
/**
 * @brief       Check if rings were attached, otherwise create default rings
 * @param[in, out]  hif_drv The driver instance
 */
static errno_t pfe_minihif_drv_check_ring_and_enable_hif(pfe_minihif_drv_t *hif_drv)
{
    const pfe_platform_t *pPlatform;
    pfe_phy_if_t *prHif;
    errno_t ret;

    if(NULL == hif_drv->rx_ring.base_va)
    {
        NXP_LOG_ERROR("RX BD ring was not attached\n");
        ret = EFAULT;
    }
    else
    {
        if(NULL == hif_drv->tx_ring.base_va)
        {
            NXP_LOG_ERROR("TX BD ring was not attached\n");
            ret = EFAULT;
        }
        else
        {
            /*  Get the physical interface for our HIF channel */
            pPlatform = (const pfe_platform_t *)Eth_43_PFE_GetPlatform();
            prHif = pfe_platform_get_phy_if_by_id(pPlatform, hif_drv->id);
            if(NULL == prHif)
            {
                NXP_LOG_ERROR("Can't get physical interface for the HIF\n");
                ret = EFAULT;
            }
            /* Enable HIF physical interfaces */
            else if(EOK != pfe_phy_if_enable(prHif))
            {
                NXP_LOG_ERROR("Failed to enable physical interface for the HIF\n");
                ret = EFAULT;
            }
            else
            {
                ret = EOK;
            }
        }
    }

    return ret;
}
#endif /* PFE_CFG_DETACHED_MINIHIF */
/**
 * @brief       Attach ring to channel.
 * @param[in]   hif_drv The driver instance
 * @param[in]   chnl HIF driver channel
 */
/*TODO remove this function, inline its content */
static errno_t pfe_hif_chnl_set_tx_rx_ring(pfe_minihif_drv_t *hif_drv, pfe_hif_chnl_t *chnl)
{
    errno_t ret;

    chnl->rx_ring = &hif_drv->rx_ring;
    chnl->tx_ring = &hif_drv->tx_ring;
    if(EOK != pfe_hif_chnl_bind_rx_ring(chnl))
    {
        NXP_LOG_ERROR("Failed to attach Rx ring\n");
        ret = EFAULT;
    }
    else if(EOK != pfe_hif_chnl_bind_tx_ring(chnl))
    {
        NXP_LOG_ERROR("Failed to attach Tx ring\n");
        ret = EFAULT;
    }
    else
    {
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Attach created ring.
 * @param[in]   ring created ring
 * @param[in]   is_rx ring is for Tx or rx
 * @param[in]   length ring length
 * @param[out]  hif_drv HIF driver.
 */
/*TODO remove this function, inline its content */
static void pfe_minihif_drv_attach_created_ring(pfe_minihif_drv_t *hif_drv, const pfe_hif_ring_t *ring, bool_t is_rx, uint32_t length)
{
    (void)ring;
    if(FALSE == is_rx)
    {
        hif_drv->tx_ring_length = (uint16_t)length;
    }
}

/**
 * @brief       Check param of attach ring to the driver instance
 * @param[in]   hif_drv The driver instance
 * @param[in]   is_rx ring is for Tx or Rx
 * @retval      EOK if success, error code otherwise
 */
static errno_t pfe_minihif_drv_attach_ring_check_param(const pfe_minihif_drv_t *hif_drv, bool_t is_rx)
{
    errno_t ret;

    if( ((TRUE == is_rx) && (NULL != hif_drv->rx_ring.base_va))
      || ((FALSE == is_rx) && (NULL != hif_drv->tx_ring.base_va))
       )
    {
        NXP_LOG_ERROR("Ring already exists\n");
        ret = EINVAL;
    }
    else
    {
        ret = EOK;
    }
    return ret;
}

/**
 * @brief       Create the driver instance
 * @param[in]   hif_drv The driver instance
 * @param[in]   id The HIF ID
 * @param[in]   bd_access Buffer descriptor access permission
 * @retval      EOK if success, error code otherwise
 */
errno_t pfe_minihif_drv_create(pfe_minihif_drv_t *hif_drv, pfe_ct_phy_if_id_t id, bool_t bd_access)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /*PFE_CFG_NULL_ARG_CHECK*/
    {
#ifndef PFE_MINIHIF_BD_ACCESS_SUPPORT
        if(TRUE == bd_access)
        {
            NXP_LOG_ERROR("Requested BD access, but it is not supported in current configuration\n");
            ret = EINVAL;
        }
        else
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */
        {
            if(PFE_PHY_IF_ID_HIF_NOCPY == id)
            {
                NXP_LOG_ERROR("Nocopy support not available\n");
                ret = EINVAL;
            }
            else
            {
                hif_drv->id = id;
                hif_drv->bd_access = bd_access;
                ret = EOK;
            }
        }
    }
    return ret;
}

#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
#ifdef HIF_CFG_USE_DYNAMIC_TX_HEADERS
/**
 * @brief       Add an array of 16 byte buffers for PFE Tx headers (dynamic headers)
 * @details     Dynamic Tx headers allow transmit to multiple interfaces, based on Tx function argument.
 *              Provided memory buffer will be accessed by both host and PFE HIF.
 * @param[in]   hif_drv The driver instance
 * @param[in]   tx_hdr_va Address of memory provided for Tx buffers. Its size must be 16 * buf_num
 * @param[in]   buf_num Number of 16 byte buffers provided
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_minihif_drv_add_tx_hdr_buf_array(pfe_minihif_drv_t *hif_drv, void *tx_hdr_va, uint16_t buf_num)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely((NULL == hif_drv) || (NULL == tx_hdr_va)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /*PFE_CFG_NULL_ARG_CHECK*/
    {

        if((FALSE == hif_drv->bd_access) || (TRUE == hif_drv->init_done) || (0U == buf_num))
        {
            ret = EINVAL;
        }
        else
        {
            hif_drv->hif_tx_header = tx_hdr_va;
            hif_drv->tx_hdr_buf_num = buf_num;
            ret = EOK;
        }
    }
    return ret;
}
#else
/**
 * @brief       Add a 16 byte buffer for single PFE Tx header (static header)
 * @details     Static Tx header can be used only if single interface is used for transmit.
 *              Provided memory buffer will be accessed by both host and PFE HIF.
 *              The buffer shall be aligned to 16
 * @param[in]   hif_drv The driver instance
 * @param[in]   tx_hdr_va Address of static Tx header buffer, which will be used by minihif driver
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_minihif_drv_add_static_tx_hdr_buf(pfe_minihif_drv_t *hif_drv, void *tx_hdr_va)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely((NULL == hif_drv) || (NULL == tx_hdr_va)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /*PFE_CFG_NULL_ARG_CHECK*/
    {
        if((FALSE == hif_drv->bd_access) || (TRUE == hif_drv->init_done))
        {
            ret = EINVAL;
        }
        else
        {
            hif_drv->hif_tx_header = tx_hdr_va;
            hif_drv->tx_hdr_buf_num = 1U;
            ret = EOK;
        }
    }
    return ret;
}
#endif /* HIF_CFG_USE_DYNAMIC_TX_HEADERS */
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */

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

#if defined(PFE_CFG_NULL_ARG_CHECK)
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
#endif /*PFE_CFG_NULL_ARG_CHECK*/
    {
        ret = pfe_minihif_drv_attach_ring_check_param(hif_drv, is_rx);
        if(EOK == ret)
        {
            if(TRUE == is_rx)
            {
                ring = &hif_drv->rx_ring;
            }
            else
            {
                ring = &hif_drv->tx_ring;
            }
            ret = pfe_hif_ring_attach(ring, bd_base_va, wb_bd_base_va, length, is_rx, (PFE_PHY_IF_ID_HIF_NOCPY == hif_drv->id), hif_drv->bd_access);
            if(unlikely(EOK != ret))
            {
                NXP_LOG_ERROR("Could not attach ring\n");
            }
            else
            {
                pfe_minihif_drv_attach_created_ring(hif_drv, (const pfe_hif_ring_t *)ring, is_rx, length);
            }
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
    uint32_t hif_base_offset = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /*PFE_CFG_NULL_ARG_CHECK*/

    /* Check prerequisities - if(detached || !bd_access) */
#if !defined(PFE_CFG_DETACHED_MINIHIF)
    if(FALSE == hif_drv->bd_access)
#endif /* PFE_CFG_DETACHED_MINIHIF */
    {
        if((NULL == hif_drv->rx_ring.base_va) || (NULL == hif_drv->tx_ring.base_va))
        {
            NXP_LOG_ERROR("pfe_minihif_drv_attach_ring() needs to be called for both Rx and Tx ring\n");
            return EINVAL;
        }
    }

#if !defined(PFE_CFG_DETACHED_MINIHIF)
    /* HW init */
    /* Standard HIF: only master driver initializes hif,
       then each driver initializes only its hif channel(s) */
    hif_base_offset = CBUS_HIF_BASE_ADDR;
#endif /*PFE_CFG_DETACHED_MINIHIF*/

#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
    if(EOK != pfe_minihif_drv_init_tx_header(hif_drv))
    {
        pfe_minihif_drv_destroy_and_free(hif_drv, hif_base_offset);
        return EFAULT;
    }
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */

#if !defined(PFE_CFG_DETACHED_MINIHIF)
    /* Create channel*/
    if(EOK != pfe_hif_chnl_create(&hif_drv->channel, PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU + hif_base_offset, (uint32_t)(hif_drv->id - PFE_PHY_IF_ID_HIF0), hif_drv->bmu, TRUE))
    {
        pfe_minihif_drv_destroy_and_free(hif_drv, hif_base_offset);
        return EFAULT;
    }
#endif /* PFE_CFG_DETACHED_MINIHIF */

#if !defined(PFE_CFG_DETACHED_MINIHIF)
    /* Check if rings were attached, otherwise create default rings */
    if(EOK != pfe_minihif_drv_check_ring_and_enable_hif(hif_drv))
    {
        pfe_minihif_drv_destroy_and_free(hif_drv, hif_base_offset);
        return EFAULT;
    }
#endif /*PFE_CFG_DETACHED_MINIHIF*/

    /* Set the rings to the channel */
    /* Attach rings to channel */
    if(EOK != pfe_hif_chnl_set_tx_rx_ring(hif_drv, &hif_drv->channel))
    {
        pfe_minihif_drv_destroy_and_free(hif_drv, hif_base_offset);
        return EFAULT;
    }

#if !defined(PFE_CFG_DETACHED_MINIHIF)
    pfe_hif_chnl_rx_disable(&hif_drv->channel);
    pfe_hif_chnl_tx_disable(&hif_drv->channel);
#endif /*PFE_CFG_DETACHED_MINIHIF*/

    return EOK;
}

/**
 * @brief       Enables data reception
 * @details     Enables Rx on hardware (if HW access was allowed). Enables API (if BD ring access was allowed)
 * @param[in]   hif_drv The driver instance
 */
errno_t pfe_minihif_drv_start_rx(pfe_minihif_drv_t *hif_drv)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if !defined(PFE_CFG_DETACHED_MINIHIF)
        ret = pfe_hif_chnl_rx_enable(&hif_drv->channel);
        if(EOK != ret)
        {
            NXP_LOG_ERROR("Couldn't enable RX\n");
        }
        else
#endif
        {
#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
            if(TRUE == hif_drv->bd_access)
            {
                hif_drv->rx_started = TRUE;
                ret = EOK;
            }
            else
            {
                ret = EPERM;
            }
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */
        }
    }

    return ret;
}

/**
 * @brief       Start traffic at HIF level
 * @details     Data transmission is enabled
 * @param[in]   hif_drv The driver instance
 */
errno_t pfe_minihif_drv_start_tx(pfe_minihif_drv_t *hif_drv)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if !defined(PFE_CFG_DETACHED_MINIHIF)
        ret = pfe_hif_chnl_tx_enable(&hif_drv->channel);
        if(EOK != ret)
        {
            NXP_LOG_ERROR("Couldn't enable TX\n");
        }
        else
#endif
        {
#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
            if(TRUE == hif_drv->bd_access)
            {
                hif_drv->tx_started = TRUE;
                ret = EOK;
            }
            else
            {
                ret = EPERM;
            }
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */
        }
    }

    return ret;
}

#ifdef PFE_MINIHIF_BD_ACCESS_SUPPORT
/**
 * @brief       Transmit SG buffer
 * @details     Function will commit a SG buffer for transmission. The transmission confirmation can be
 *              obtained via pfe_minihif_drv_get_tx_conf(). The order of TX confirmations received via
 *              that call follows order of successful calls to this xmit function. To keep the TX resource
 *              maintained, the pfe_minihif_drv_get_tx_conf() shall be regularly called.
 * @param[in]   hif_drv The driver instance
 * @param[in]   dst Destination interface ID
 * @param[in]   queue TX queue number
 * @param[in]   sg_list Scatter-gather list
 * @param[in]   ref_ptr Reference pointer to be provided within TX confirmation.
 * @return      EOK if success, error code otherwise
 * @note        If HIF_CFG_USE_DYNAMIC_TX_HEADERS option is not enabled, the argument "dst" must always
 *              have the same value. Otherwise race condition may occur and frame can be sent to previous
 *              interface. If multiple interfaces are used for transmission, HIF_CFG_USE_DYNAMIC_TX_HEADERS
 *              shall be defined.
 * @note        The 'ref_ptr' and 'queue' arguments are ignored.
 */
errno_t pfe_minihif_drv_xmit_sg(pfe_minihif_drv_t *hif_drv, pfe_ct_phy_if_id_t dst, uint8_t queue, const pfe_minihif_drv_sg_list_t *sg_list, const void *ref_ptr)
{
    pfe_ct_hif_tx_hdr_t *tx_hdr;
    const void *tx_hdr_pa = NULL;
    errno_t ret;
    uint32_t ii;
#ifdef HIF_CFG_USE_DYNAMIC_TX_HEADERS
    static uint16_t tx_hdr_idx = 0U;
#endif

    (void)ref_ptr;
    (void)queue;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely((NULL == hif_drv) || (NULL == sg_list)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if(unlikely(FALSE == hif_drv->tx_started))
        {
            /*  Transmission is not allowed */
            ret = EPERM;
        }

        /*
            Check if we have enough TX resources. We need one for each SG entry plus
            one for HIF header.
        */
        else if(unlikely(FALSE == pfe_hif_chnl_can_accept_tx_num(&hif_drv->channel, (uint16_t)(sg_list->size + 1U))))
        {
            ret = ENOSPC;
        }
        else
        {
#ifdef HIF_CFG_USE_DYNAMIC_TX_HEADERS
            tx_hdr = &hif_drv->hif_tx_header[tx_hdr_idx];
            tx_hdr_pa = (void *)&((pfe_ct_hif_tx_hdr_t *)(hif_drv->hif_tx_header_pa))[tx_hdr_idx];
            tx_hdr_idx++;
            if(tx_hdr_idx >= hif_drv->tx_hdr_buf_num)
            {
                tx_hdr_idx = 0U;
            }
#else
            tx_hdr = hif_drv->hif_tx_header;
            tx_hdr_pa = hif_drv->hif_tx_header_pa;
#endif /* HIF_CFG_USE_DYNAMIC_TX_HEADERS */

            if(PFE_MINIHIF_PHY_IF_ID_AUX != dst)
            {
                tx_hdr->e_phy_ifs = oal_htonl((uint32_t)1U << (uint32_t)dst);
                tx_hdr->flags |= HIF_TX_INJECT;
            }
            else
            {
                tx_hdr->e_phy_ifs = 0U;
                tx_hdr->flags &= ~HIF_TX_INJECT;
            }

            /*  Enqueue the HIF packet header */
            ret = pfe_hif_chnl_tx(&hif_drv->channel, (const void *)tx_hdr_pa, (void *)tx_hdr, sizeof(pfe_ct_hif_tx_hdr_t), FALSE);

            if(unlikely(EOK != ret))
            {
                /*  Channel did not accept the buffer. Return SW descriptor and fail. */
                NXP_LOG_ERROR("Channel did not accept buffer: %d\n", ret);
                ret = ECANCELED;
            }
            else
            {

                /*  Transmit particular packet buffers */
                for(ii = 0U; ii < sg_list->size; ii++)
                {
                    /*  Transmit the buffer */
                    ret = pfe_hif_chnl_tx(  &hif_drv->channel,
                                            sg_list->items[ii].data_pa,
                                            sg_list->items[ii].data_va,
                                            sg_list->items[ii].len,
                                            ((ii + 1U) >= (uint32_t)sg_list->size));

                    if(unlikely(EOK != ret))
                    {
                        /*  TODO: We need somehow reset the TX BD Ring because HIF header has already been enqueued. */
                        NXP_LOG_ERROR("Fatal error, TX channel will get stuck...\n");
                        ret = ECANCELED;
                        break;
                    }
                    else
                    {
                        /*  TODO: Store the TX frame metadata */
                    }
                }
            }
        }
    }
    return ret;
}

/**
 * @brief           Get TX confirmation
 * @details         Function queries HIF channel for TX confirmations. If new TX confirmation
 *                  is found the reference value provided via _xmit() function is returned.
 * @param[in]       hif_drv The driver instance
 * @param[in,out]   ref_ptr Pointer to memory where reference pointer (from _xmit()) shall
 *                  be written. Can be NULL.
 * @retval          EOK Success
 * @retval          EINVAL Invalid argument
 * @retval          ENOENT No more TX confirmations
 * @retval          EPERM Data access not allowed in current hif_drv instance
 */
errno_t pfe_minihif_drv_get_tx_conf(pfe_minihif_drv_t *hif_drv, void **ref_ptr)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if(unlikely(FALSE == hif_drv->bd_access))
    {
        NXP_LOG_ERROR("No data access in this driver instance\n");
        ret = EPERM;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {

        if(EOK != pfe_hif_chnl_get_tx_conf(&hif_drv->channel))
        {
            ret = ENOENT;
        }
        else
        {
            if(NULL != ref_ptr)
            {
                /*  TODO: Return the ref_ptr here */
                *ref_ptr = NULL;
            }
            ret = EOK;
        }
    }
    return ret;
}

/**
 * @brief           Receive packet
 * @param[in]       hif_drv The driver instance
 * @param[in]       queue Index of queue to receive packet from
 * @param[in,out]   buf Pointer to location where pointer to data buffer shall be written
 * @param[in,out]   len Pointer to location where number of received bytes shall be written
 * @param[in,out]   lifm Pointer to location where information if the packet is last-in-frame shall be written
 * @retval          EOK Success
 * @retval          EINVAL Invalid argument
 * @retval          EAGAIN No received packets
 * @retval          EPERM Not allowed, reception not started yet
 */
errno_t pfe_minihif_drv_get_rx_pkt(pfe_minihif_drv_t *hif_drv, uint8_t queue, void **buf, uint32_t *len, bool_t *lifm)
{
    /*  Not supported yet */
    (void)queue;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely((NULL == hif_drv) || (NULL == buf) || (NULL == len) || (NULL == lifm)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if(unlikely(FALSE == hif_drv->bd_access))
        {
            NXP_LOG_ERROR("No data access in this driver instance\n");
            ret = EPERM;
        }
        else if(likely(hif_drv->rx_started))
        {
#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
            void *metadata; /* Ignoring the value */
            ret = pfe_hif_chnl_rx_va(&hif_drv->channel, buf, len, lifm, &metadata);
#else
            ret = pfe_hif_chnl_rx(&hif_drv->channel, buf, len, lifm);
#endif /*PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED*/
        }
        else
        {
            ret = EPERM;
        }
    }
    return ret;
}

#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
/**
 * @brief       Release RX buffer
 * @param[in]   hif_drv The driver instance
 * @param[in]   buf_va Pointer to buffer needed to release
 * @retval      EOK if success, error code otherwise
 */
errno_t pfe_minihif_drv_release_rx_buf(pfe_minihif_drv_t *hif_drv, void *buf_va)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely((NULL == hif_drv) || (NULL == buf_va)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if(unlikely(FALSE == hif_drv->bd_access))
        {
            NXP_LOG_ERROR("No data access in this driver instance\n");
            ret = EPERM;
        }
        else
        {
            ret = pfe_hif_chnl_release_buf(&hif_drv->channel, buf_va);
            if(unlikely(EOK != ret))
            {
                NXP_LOG_ERROR("Unable to release RX buffer\n");
            }
        }
    }
    return ret;
}
#endif /*PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED*/

/**
 * @brief       Supply RX buffer
 * @param[in]   hif_drv The driver instance
 * @param[in]   buf Pointer to buffer (physical)
 * @param[in]   len Length of the buffer in number of bytes
 * @retval      EOK Success
 * @retval      EINVAL Invalid argument
 * @retval      ENOENT No entry to supply buffer to
 * @retval      EPERM Data access not allowed in current hif_drv instance
 */
errno_t pfe_minihif_drv_supply_rx_buffer(const pfe_minihif_drv_t *hif_drv, const void *buf, uint32_t len)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely((NULL == hif_drv) || (NULL == buf)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if(unlikely(FALSE == hif_drv->bd_access))
        {
            NXP_LOG_ERROR("No data access in this driver instance\n");
            ret = EPERM;
        }
        else if(TRUE == pfe_hif_chnl_can_accept_rx_buf(&hif_drv->channel))
        {
            ret = pfe_hif_chnl_supply_rx_buf(&hif_drv->channel, buf, len);
        }
        else
        {
            ret = ENOENT;
        }
    }
    return ret;

}
#endif /* PFE_MINIHIF_BD_ACCESS_SUPPORT */

/**
 * @brief       Get HIF ID
 * @param[in]   hif_drv The driver instance
 * @retval      HIF ID Success
 * @retval      PFE_PHY_IF_ID_INVALID Invalid argument
 */
pfe_ct_phy_if_id_t pfe_minihif_get_hif_id(const pfe_minihif_drv_t *hif_drv)
{
    pfe_ct_phy_if_id_t ret;

    if(NULL != hif_drv)
    {
        ret = hif_drv->id;
    }
    else
    {
        ret = PFE_PHY_IF_ID_INVALID;
    }
    return ret;
}

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

/** @}*/
