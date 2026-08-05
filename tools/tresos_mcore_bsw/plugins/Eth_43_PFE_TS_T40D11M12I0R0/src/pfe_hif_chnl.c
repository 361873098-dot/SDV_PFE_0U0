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

/**
 * @file        pfe_hif_chnl.c
 * @brief       The HIF channel module source file.
 * @details     This file contains HIF channel-related functionality abstracted using
 *              configurable, HW-specific calls. Each HW platform shall supply its own
 *              pfe_hif_csr.h header implementing the HW-specific parts.
 *
 *              Default Mode
 *              ------------
 *              Default mode allows user to transmit and receive buffers using their
 *              physical addresses. There is no other functionality and only the
 *              default API is sufficient to handle the data-path:
 *                  - pfe_hif_chnl_can_accept_tx_num()
 *                  - pfe_hif_chnl_tx()
 *                  - pfe_hif_chnl_supply_rx_buffer()
 *                  - pfe_hif_chnl_rx()
 *
 *              TX example:
 *              if pfe_hif_chnl_can_accept_tx_num() is TRUE then
 *                pfe_hif_chnl_tx()
 *              endif
 *
 *              RX example:
 *              Supply RX buffers
 *              while pfe_hif_chnl_can_accept_rx_buf() do
 *                pfe_hif_chnl_supply_rx_buf()
 *              endwhile
 *
 *              Receive
 *              while (1)
 *                if pfe_hif_chnl_rx() then
 *                  1 Process the buffer
*                   2 pfe_hif_chnl_supply_rx_buf()
 *                endif
 *              endwhile
 *
 *              RX Buffer Management Mode
 *              -------------------------
 *              In case the PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED is set to TRUE the PFE HIF
 *              channel module provides full RX buffer management functionality. It
 *              creates pool of buffers and transparently populates the RX ring. Instead
 *              of default RX API the extended version is provided:
 *                  - pfe_hif_chnl_rx_va()
 *                  - pfe_hif_chnl_release_buf()
 *
 *              Every buffer received via pfe_hif_chnl_rx_va() must be subsequently
 *              released by the pfe_hif_chnl_release_rx_va(). With the RX management
 *              support also the pfe_hif_chnl_get_meta_size() is available for
 *              sanity check implementation related to size of the pre-allocated
 *              buffer-related meta storage.
 *
 *              TX example: The same as in the Default Mode case.
 *
 *              RX example:
 *              Sanity check
 *              if my metadata size does not match pfe_hif_chnl_get_meta_size()
 *                Throw error
 *              endif
 *
 *              Receive
 *              while (1)
 *                if pfe_hif_chnl_rx_va() then
 *                  1 Use pre-allocated metadata storage to bind custom data with the buffer for better performance
 *                  2 Process the buffer
 *                  3 When finished, call the pfe_hif_chnl_release_buf()
 *                endif
 *              endwhile
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"

#if !defined(PFE_CFG_DETACHED_MINIHIF)
#include "Eth_43_PFE.h"
#include "pfe_cbus.h"
#endif /* PFE_CFG_DETACHED_MINIHIF */

#include "pfe_platform_cfg.h"
#include "pfe_hif_chnl.h"
#include "pfe_hif_ring.h"
#include "pfe_hif_csr.h"

#define DUMMY_TX_BUF_LEN        (64U + sizeof(pfe_ct_hif_tx_hdr_t))
#define DUMMY_RX_BUF_LEN        2048U

/**
 * @brief   The list of HIF channels that are allowed to take FCI timer ownership
 */
typedef enum
{
    HIF_TIMER_OWNER_0,
    HIF_TIMER_OWNER_1,
    HIF_TIMER_OWNER_2,
    HIF_TIMER_OWNER_3,
    HIF_TIMER_OWNER_INVALID
} pfe_timer_owner_hif_id_t;

/**
 * @brief Send dummy frame modes
 * 
 */
typedef enum
{
    DUMMY_FRAME_INVALID = 0U,
    DUMMY_FRAME_IHC_SELF
} send_dummy_frame_mode_t;

#define ETH_43_PFE_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static const pfe_timer_owner_hif_id_t pfe_timer_owner_hif_ids[PFE_PHY_IF_ID_INVALID + 1U] =
{
    [PFE_PHY_IF_ID_HIF0] = HIF_TIMER_OWNER_0,
    [PFE_PHY_IF_ID_HIF1] = HIF_TIMER_OWNER_1,
    [PFE_PHY_IF_ID_HIF2] = HIF_TIMER_OWNER_2,
    [PFE_PHY_IF_ID_HIF3] = HIF_TIMER_OWNER_3,
    [PFE_PHY_IF_ID_INVALID] = HIF_TIMER_OWNER_INVALID
};
#define ETH_43_PFE_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#if !defined(PFE_CFG_DETACHED_MINIHIF)
#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
/* TODO: remove support for multiple HIF channels and put this directly into the pfe_hif_t (not just pointers) */
#ifdef PFE_CFG_HIF_NOCPY_SUPPORT
static pfe_hif_ring_t rx_rings_memory_nocpy;
static pfe_hif_ring_t tx_rings_memory_nocpy;
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
static pfe_hif_ring_t rx_rings_memory[HIF_CFG_MAX_CHANNELS];
static pfe_hif_ring_t tx_rings_memory[HIF_CFG_MAX_CHANNELS];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_DETACHED_MINIHIF */

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
    #if !defined(PFE_CFG_DETACHED_MINIHIF)
        #define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BUF_MEM
        #include "Eth_43_PFE_MemMap.h"
    #endif /* PFE_CFG_DETACHED_MINIHIF */
/* It should be static, but it is not to avoid issues with memory mapping in some compilers */
__attribute__((aligned(8))) uint8_t rx_buf_mem[ETH_43_PFE_MAX_RXBUF_POOLSZ];
__attribute__((aligned(8))) uint8_t dummy_tx_buf[DUMMY_TX_BUF_LEN];
__attribute__((aligned(8))) uint8_t dummy_rx_buf[DUMMY_RX_BUF_LEN];
    #if !defined(PFE_CFG_DETACHED_MINIHIF)
        #define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BUF_MEM
        #include "Eth_43_PFE_MemMap.h"
    #endif /* PFE_CFG_DETACHED_MINIHIF */

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_VAR_CLEARED_8
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

static __attribute__((aligned(4))) uint8_t rx_meta_buf_mem[ETH_43_PFE_MAX_RXBUF_META_POOLSZ];

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_8
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_VAR_CLEARED_8
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

static __attribute__((aligned(4))) uint8_t rx_meta_buf_mem_hifnocpy[ETH_43_PFE_BMU2_BUF_CNT*ETH_43_PFE_META_BUF_SIZE];

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_8
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

#if !defined(PFE_CFG_DETACHED_MINIHIF)
static errno_t pfe_hif_chnl_reset_rx_ring(pfe_hif_chnl_t *chnl) __attribute__((cold));
#if defined(PFE_CFG_PFE_SLAVE)
static void pfe_hif_chnl_reset_tx_ring(pfe_hif_chnl_t *chnl) __attribute__((cold));
#endif /* PFE_CFG_PFE_SLAVE */
static __attribute__((cold)) errno_t pfe_hif_chnl_rx_ring_soft_reset(pfe_hif_chnl_t *chnl, uint32_t ii, void *tx_buf_va);
static __attribute__((cold)) errno_t pfe_hif_chnl_create_cfg(pfe_hif_chnl_t **chnl, const pfe_bmu_t *bmu, bool_t minihif);
static __attribute__((cold)) errno_t pfe_hif_chnl_send_dummy_frame(pfe_hif_chnl_t *chnl, void *tx_buf_va, send_dummy_frame_mode_t mode);
#endif /* PFE_CFG_DETACHED_MINIHIF */

#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
static inline void rx_pool_init(rx_pool_t *pool, const void *memory,const void *meta_memory,
                                uint16_t buf_size, uint16_t buf_num
                               );
static void pfe_hif_chnl_refill_rx_buffers(pfe_hif_chnl_t *chnl) __attribute__((hot));
static inline void *rx_pool_get(rx_pool_t *pool);
static inline void *rx_pool_get_meta_buf(const rx_pool_t *pool, const void *buf_va);
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */

#if !defined(PFE_CFG_DETACHED_MINIHIF)
static errno_t pfe_hif_chnl_init_tx_rx_ring(pfe_hif_chnl_t *chnl);
#endif /* PFE_CFG_DETACHED_MINIHIF */
static inline pfe_timer_owner_hif_id_t pfe_timer_owner_hif_from_phy_id(pfe_ct_phy_if_id_t phy);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/**
 * @brief       Convert interface id to value representing HIF channel that is allowed to take timer ownership
 * @param[in]   phy interface id
 * @return      Timer owner HIF value
 */
static inline pfe_timer_owner_hif_id_t pfe_timer_owner_hif_from_phy_id(pfe_ct_phy_if_id_t phy)
{
    pfe_timer_owner_hif_id_t ret_val = HIF_TIMER_OWNER_INVALID;

    if (PFE_PHY_IF_ID_INVALID >= phy)
    {
        ret_val = pfe_timer_owner_hif_ids[phy];
    }

    return ret_val;
}

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
#if defined(NXP_LOG_ENABLED)

/*
 * @brief   Increment buffer allocation counter
 * @details To monitor how many BMU buffers have been allocated
 *          by a channel instance we need to provide a SW counter.
 */
static void pfe_hif_chnl_alloc_inc(pfe_hif_chnl_t *chnl)
{
    oal_mutex_lock(PFE_CHNL_A_LOCK_MUTEX_00);
    chnl->a_cnt++;
    oal_mutex_unlock(PFE_CHNL_A_LOCK_MUTEX_00);
}

/*
 * @brief   Decrement buffer allocation counter
 * @details To monitor how many BMU buffers have been allocated
 *          by a channel instance we need to provide a SW counter.
 */
static void pfe_hif_chnl_alloc_dec(pfe_hif_chnl_t *chnl)
{
    oal_mutex_lock(PFE_CHNL_A_LOCK_MUTEX_01);
    chnl->a_cnt--;
    oal_mutex_unlock(PFE_CHNL_A_LOCK_MUTEX_01);
}

/*
 * @brief   Get state of allocation counter
 * @details To monitor how many BMU buffers have been allocated
 *          by a channel instance we need to provide a SW counter.
 * @return  Current number of allocated buffers.
 */
static uint32_t pfe_hif_chnl_get_alloc_cnt(pfe_hif_chnl_t *chnl)
{
    uint32_t ret;

    ret = chnl->a_cnt;

    return ret;
}
#endif /* NXP_LOG_ENABLED */
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
static inline void rx_pool_init(rx_pool_t *pool, const void *memory,const void *meta_memory,
                                uint16_t buf_size, uint16_t buf_num
                               )
{
    pool->base_addr = (addr_t)memory;
    pool->meta_base_addr = (addr_t)meta_memory;
    pool->buf_size = buf_size;
    pool->buf_number = buf_num;
    pool->get_idx = 0U;
}

/* This function provides one Rx buffer on each call.
   It should be used to feed buffers to channel during initialization. Then the buffers remain there
   until the channel is destroyed. There is no need to return the buffer to the pool. */
static inline void *rx_pool_get(rx_pool_t *pool)
{
    void *pvBuffer = NULL;

    if (pool->get_idx < pool->buf_number)
    {
        pvBuffer = (void *)(pool->base_addr + ((addr_t)(pool->get_idx) * pool->buf_size));
        pool->get_idx++;
    }
    return pvBuffer;
}

/* Get meta buffer related to Rx buffer  */
static inline void *rx_pool_get_meta_buf(const rx_pool_t *pool, const void *buf_va)
{
    uint32_t index;

    /* Calculate index of provided Rx buffer */
    index = (uint16_t)(((addr_t)buf_va - pool->base_addr) / pool->buf_size);
    /* Calculate address of meta buffer with same index */
    return (void *)(pool->meta_base_addr + (index * ETH_43_PFE_META_BUF_SIZE));
}
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */

#if !defined(PFE_CFG_DETACHED_MINIHIF)
/**
 * @brief       Channel master ISR
 * @param[in]   chnl The channel instance
 * @return      EOK if interrupt has been handled
 */
__attribute__((hot)) errno_t pfe_hif_chnl_isr(pfe_hif_chnl_t *chnl)
{
    errno_t ret;
    pfe_hif_chnl_event_t events;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_00);

        /* Run the low-level ISR to identify and process the interrupt */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            ret = pfe_hif_nocpy_cfg_isr(chnl->cbus_base_va, &events);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            ret = pfe_hif_chnl_cfg_isr(chnl->cbus_base_va, chnl->id, &events);
        }

        oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_00);

        /*  Run callbacks for identified interrupts here */
        if ((uint32_t)HIF_CHNL_EVT_RX_IRQ == ((uint32_t)events & (uint32_t)HIF_CHNL_EVT_RX_IRQ))
        {
            if (NULL != chnl->rx_cbk.cbk)
            {
                chnl->rx_cbk.cbk(chnl->rx_cbk.arg);
            }
            else
            {
                NXP_LOG_DEBUG("Unhandled HIF_CHNL_EVT_RX_IRQ detected\n");
            }
        }

        if ((uint32_t)HIF_CHNL_EVT_TX_IRQ == ((uint32_t)events & (uint32_t)HIF_CHNL_EVT_TX_IRQ))
        {
            if (NULL != chnl->tx_cbk.cbk)
            {
                chnl->tx_cbk.cbk(chnl->tx_cbk.arg);
            }
            else
            {
                NXP_LOG_DEBUG("Unhandled HIF_CHNL_EVT_TX_IRQ detected\n");
            }
        }
    }

    return ret;
}

/**
 * @brief       Mask channel interrupts
 * @param[in]   chnl The channel instance
 */
void pfe_hif_chnl_irq_mask(pfe_hif_chnl_t *chnl)
{
    oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_01);

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
    {
        /* HIF_NOCPY */
        pfe_hif_nocpy_cfg_irq_mask(chnl->cbus_base_va);
    }
    else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    {
        pfe_hif_chnl_cfg_irq_mask(chnl->cbus_base_va, chnl->id);
    }

    oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_01);
}

/**
 * @brief       Unmask channel interrupts
 * @param[in]   chnl The channel instance
 */
void pfe_hif_chnl_irq_unmask(pfe_hif_chnl_t *chnl)
{
    oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_02);
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
    {
        /* HIF_NOCPY */
        pfe_hif_nocpy_cfg_irq_unmask(chnl->cbus_base_va);
    }
    else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    {
        pfe_hif_chnl_cfg_irq_unmask(chnl->cbus_base_va, chnl->id);
    }

    oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_02);
}
#endif /* PFE_CFG_DETACHED_MINIHIF */

#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
/**
 * @brief   Supply fresh RX buffers to the channel
 * @details Function populates channel's RX resource with buffer from internal pool
 */
__attribute__((hot)) static void pfe_hif_chnl_refill_rx_buffers(pfe_hif_chnl_t *chnl)
{
    const void *new_buffer_va;
    const void *new_buffer_pa;
    errno_t ret;
    bool_t flags = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        while (TRUE == pfe_hif_chnl_can_accept_rx_buf(chnl))
        {
            new_buffer_va = rx_pool_get(&(chnl->rx_pool));

            if (likely(NULL != new_buffer_va))
            {
                /*  Get physical address */
                new_buffer_pa = new_buffer_va;
                ret = pfe_hif_chnl_supply_rx_buf(chnl, new_buffer_pa, ETH_43_PFE_CFG_HIF_RX_BUF_SIZE);
                if (unlikely(EOK != ret))
                {
                    NXP_LOG_WARNING("HIF channel did not accept new RX buffer\n");
                    flags =  TRUE;
                }
            }
            else
            {
                /*  No more Rx buffers available, leave remaining BD empty */
                flags =  TRUE;
            }

            if(TRUE == flags)
            {
                break;
            }
        }
    }
}
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */

#if !defined(PFE_CFG_DETACHED_MINIHIF)

/**
 * @brief           Create new HIF channel instance
 * @details         Creates and initializes HIF channel instance
 * @param[inout]    chnl Pointer to channel
 * @param[in]       bmu If set, the channel will use it to allocate RX buffers. It is mandatory
 *                  for HIF NOCPY channel abstraction.
 * @param[in]       minihif If minihif is TRUE, it means that this function is used to configure the HIF channel for the minihif purpose.
 * @return          EOK if success, error code otherwise
 */
static __attribute__((cold)) errno_t pfe_hif_chnl_create_cfg(pfe_hif_chnl_t **chnl, const pfe_bmu_t *bmu, bool_t minihif)
{
    errno_t ret = EOK;

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    /* When PFE_CFG_HIF_NOCPY_SUPPORT is defined and ((*chnl)->id != PFE_HIF_CHNL_NOCPY_ID), it means this HIF channel is used in minihif scenario */
    if ((*chnl)->id >= PFE_HIF_CHNL_NOCPY_ID)
    {
#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
        if (NULL == (*chnl)->bmu)
        {
            NXP_LOG_ERROR("HIF NOCPY channel requires BMU instance\n");
            ret = EINVAL;
        }
        else
        {
            ret = EOK;
        }
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */
       /* HIF_NOCPY does not need per-channel initialization */
    }
    else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    {
#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
        if (NULL != bmu)
        {
            /* This is not supported. SW buffer pool will be used instead. */
            NXP_LOG_WARNING("BMU-based RX buffer pool not supported for standard HIF channels. SW pool will be used instead.\n");
        }
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */

        oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_03);

        ret = pfe_hif_chnl_cfg_init((*chnl)->cbus_base_va, (*chnl)->id);

        if (EOK != ret)
        {
            NXP_LOG_ERROR("HIF channel cfg init failed\n");
        }
        else
        {
            ret = pfe_hif_chnl_init(*chnl, minihif);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("HIF channel init failed\n");
            }
        }
        oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_03);
    }

    return ret;
}

/**
 * @brief           Create new HIF channel instance
 * @details         Creates and initializes HIF channel instance
 * @param[inout]    chnl Pointer to channel
 * @param[in]       cbus_base_va CBUS base virtual address
 * @param[in]       id Channel identifier to bind SW instance to a real HW HIF channel
 * @param[in]       bmu If set, the channel will use it to allocate RX buffers. It is mandatory
 *                  for HIF NOCPY channel abstraction.
 * @param[in]       minihif If minihif is TRUE, it means that this function is used to configure the HIF channel for the minihif purpose.
 * @return          EOK if success, error code otherwise
 */
__attribute__((cold)) errno_t pfe_hif_chnl_create(pfe_hif_chnl_t *chnl, addr_t cbus_base_va, uint32_t id, const pfe_bmu_t *bmu, bool_t minihif)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == cbus_base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if !defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            NXP_LOG_ERROR("HIF NOCPY support is not enabled\n");
            ret = ENODEV;
        }
        else if (id >= HIF_CFG_MAX_CHANNELS)
        {
            NXP_LOG_ERROR("Unsupported channel ID\n");
            ret = ENODEV;
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            if (NULL == chnl)
            {
                ret = EINVAL;
            }
            else
            {
                chnl->cbus_base_va = cbus_base_va;
                chnl->id = id;
                chnl->tx_ring = NULL;
                chnl->rx_ring = NULL;
#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED) && defined(PFE_CFG_HIF_NOCPY_SUPPORT)
                chnl->bmu = bmu;
                (void)autolibc_memset((void*)&chnl->rx_pool, 0, sizeof(rx_pool_t));
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED && PFE_CFG_HIF_NOCPY_SUPPORT */

                ret = pfe_hif_chnl_create_cfg(&chnl, bmu, minihif);
            }
        }
    }

    return ret;
}

/**
 * @brief       Get channel identifier
 * @param[in]   chnl The channel instance
 * @return      The identifier of the channel
 */
__attribute__((pure, cold)) uint32_t pfe_hif_chnl_get_id(const pfe_hif_chnl_t *chnl)
{
    uint32_t chnl_id;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        chnl_id = UINT_MAX; /* Available via oal_types.h */
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        chnl_id = chnl->id;
    }
    return chnl_id;
}

/**
 * @brief       Enable TX
 * @details     Activate the TX ring and enable TX ring interrupts
 * @param[in]   chnl The channel instance
 * @retval      EOK Success
 * @retval      EFAULT TX ring not found
 */
__attribute__((cold)) errno_t pfe_hif_chnl_tx_enable(pfe_hif_chnl_t *chnl)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (NULL == chnl->tx_ring)
        {
            NXP_LOG_ERROR("Can't enable TX: TX ring not set\n");
            ret = EFAULT;
        }
        else
        {
            oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_04);

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
            {
                /* HIF_NOCPY */
                pfe_hif_nocpy_cfg_tx_enable(chnl->cbus_base_va);
            }
            else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
            {
                /* HIF */
                pfe_hif_chnl_cfg_tx_enable(chnl->cbus_base_va, chnl->id);
            }

            oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_04);
            ret = EOK;
        }
    }
    return ret;
}

/**
 * @brief       Disable TX
 * @details     De-activate the TX ring and disable TX ring interrupts. All buffers
 *              previously committed for transmission via pfe_hif_chnl_tx() are marked
 *              as "transmitted" and related TX confirmations can be retrieved via
 *              pfe_hif_chnl_get_tx_conf().
 * @param[in]   chnl The channel instance
 */
__attribute__((cold)) void pfe_hif_chnl_tx_disable(pfe_hif_chnl_t *chnl)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_05);

        /* Stop data transmission */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            pfe_hif_nocpy_cfg_tx_disable(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            /* HIF */
            pfe_hif_chnl_cfg_tx_disable(chnl->cbus_base_va, chnl->id);
        }

        oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_05);
    }
}

/**
 * @brief       Enable RX
 * @details     Activate the RX ring and enable RX ring interrupts
 * @param[in]   chnl The channel instance
 * @retval      EOK Success
 * @retval      EFAULT RX ring not found
 */
__attribute__((cold)) errno_t pfe_hif_chnl_rx_enable(pfe_hif_chnl_t *chnl)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (NULL == chnl->rx_ring)
        {
            NXP_LOG_ERROR("Can't enable RX: RX ring not set\n");
            ret = EFAULT;
        }
        else
        {
            oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_06);

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
            {
                /* HIF_NOCPY */
                pfe_hif_nocpy_cfg_rx_enable(chnl->cbus_base_va);
            }
            else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
            {
                /* HIF */
                pfe_hif_chnl_cfg_rx_enable(chnl->cbus_base_va, chnl->id);
            }

            oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_06);
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief       Disable RX
 * @details     De-activate the RX ring
 * @param[in]   chnl The channel instance
 * @note        Must not be preempted by pfe_hif_chnl_supply_rx_buf()
 */
__attribute__((cold)) void pfe_hif_chnl_rx_disable(pfe_hif_chnl_t *chnl)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_07);

        /* Stop data reception */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            pfe_hif_nocpy_cfg_rx_disable(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            /* HIF */
            pfe_hif_chnl_cfg_rx_disable(chnl->cbus_base_va, chnl->id);
        }

        oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_07);
    }
}

/**
 * @brief       Trigger RX DMA
 * @details     One can trigger the HW to start processing of the RX ring.
 *              This is needed when the RX ring is modified after the
 *              pfe_hif_chnl_supply_rx_buf() call(s).
 * @param[in]   chnl The channel instance
 */
__attribute__((hot)) void pfe_hif_chnl_rx_dma_start(const pfe_hif_chnl_t *chnl)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* No resource protection here, DMA trigger is atomic. */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            pfe_hif_nocpy_cfg_rx_dma_start(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            /* HIF */
            pfe_hif_chnl_cfg_rx_dma_start(chnl->cbus_base_va, chnl->id);
        }
    }
}

/**
 * @brief       Trigger TX DMA
 * @details     Trigger the HW to start processing of the TX ring. Needed
 *              after TX ring is modified after the pfe_hif_chnl_tx() call(s).
 * @param[in]   chnl The channel instance
 */
__attribute__((hot)) void pfe_hif_chnl_tx_dma_start(const pfe_hif_chnl_t *chnl)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* No resource protection here. DMA trigger is atomic. */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            pfe_hif_nocpy_cfg_tx_dma_start(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            /* HIF */
            pfe_hif_chnl_cfg_tx_dma_start(chnl->cbus_base_va, chnl->id);
        }
    }
}

/**
 * @brief       Attach event callback
 * @param[in]   chnl The channel instance
 * @param[in]   event Event triggering the handler
 * @param[in]   isr The ISR
 * @param[in]   arg The ISR argument
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_hif_chnl_set_event_cbk(pfe_hif_chnl_t *chnl, pfe_hif_chnl_event_t event, pfe_hif_chnl_cbk_t cbk, void *arg)
{
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (HIF_CHNL_EVT_TX_IRQ == event)
        {
            /*  TX callback */
            chnl->tx_cbk.arg = arg;
            chnl->tx_cbk.cbk = cbk;
        }
        else if (HIF_CHNL_EVT_RX_IRQ == event)
        {
            /*  RX callback */
            chnl->rx_cbk.arg = arg;
            chnl->rx_cbk.cbk = cbk;
        }
        else if (HIF_CHNL_EVT_RX_OOB == event)
        {
            /*  Out of RX buffers event handler */
            chnl->rx_oob_cbk.arg = arg;
            chnl->rx_oob_cbk.cbk = cbk;
        }
        else
        {
            /*  More events need to be supported here */
            ret = EINVAL;
        }
    }

    return ret;
}

/**
 * @brief       Disable RX interrupt
 * @param[in]   chnl The channel instance
 * @return      EOK if success, error code otherwise
 */
__attribute__((hot)) void pfe_hif_chnl_rx_irq_mask(pfe_hif_chnl_t *chnl)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_08);

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            pfe_hif_nocpy_cfg_rx_irq_mask(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            pfe_hif_chnl_cfg_rx_irq_mask(chnl->cbus_base_va, chnl->id);
        }

        oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_08);
    }
}

/**
 * @brief       Enable RX interrupt
 * @param[in]   chnl The channel instance
 * @return      EOK if success, error code otherwise
 */
__attribute__((hot)) void pfe_hif_chnl_rx_irq_unmask(pfe_hif_chnl_t *chnl)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_09);
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            pfe_hif_nocpy_cfg_rx_irq_unmask(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            pfe_hif_chnl_cfg_rx_irq_unmask(chnl->cbus_base_va, chnl->id);
        }

        oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_09);
    }
}

/**
 * @brief       Disable TX interrupt
 * @param[in]   chnl The channel instance
 * @return      EOK if success, error code otherwise
 */
__attribute__((hot)) void pfe_hif_chnl_tx_irq_mask(pfe_hif_chnl_t *chnl)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_10);

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            pfe_hif_nocpy_cfg_tx_irq_mask(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            pfe_hif_chnl_cfg_tx_irq_mask(chnl->cbus_base_va, chnl->id);
        }

        oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_10);
    }
}

/**
 * @brief       Enable TX interrupt
 * @param[in]   chnl The channel instance
 * @return      EOK if success, error code otherwise
 */
__attribute__((hot)) void pfe_hif_chnl_tx_irq_unmask(pfe_hif_chnl_t *chnl)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_11);
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            pfe_hif_nocpy_cfg_tx_irq_unmask(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            pfe_hif_chnl_cfg_tx_irq_unmask(chnl->cbus_base_va, chnl->id);
        }

        oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_11);
    }
}
#endif /* PFE_CFG_DETACHED_MINIHIF */

/**
 * @brief       Get TX confirmation status
 * @details     After pfe_hif_chnl_tx() call the HIF channel will transmit the
 *              supplied buffer. Once the transmission has been done a TX confirmation
 *              is generated. This function can be used to query the channel whether
 *              some new TX confirmations have been generated and are ready to be
 *              processed.
 * @param[in]   chnl The channel instance
 * @return      TRUE if channel got new TX confirmation, FALSE otherwise
 */
__attribute__((pure, hot)) bool_t pfe_hif_chnl_has_tx_conf(const pfe_hif_chnl_t *chnl)
{
    bool_t has_tx_conf;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        has_tx_conf = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        has_tx_conf = (0U == pfe_hif_ring_get_fill_level(chnl->tx_ring)) ? FALSE : TRUE;
    }
    return has_tx_conf;
}

/**
 * @brief       Query if new RX buffer can be supplied
 * @param       chnl The channel instance
 * @return      TRUE if RX resource can accept new buffer
 */
__attribute__((pure, hot)) bool_t pfe_hif_chnl_can_accept_rx_buf(const pfe_hif_chnl_t *chnl)
{
    bool_t accept_rx;
    uint32_t fill_level;
    uint32_t ring_len;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        accept_rx = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  A single entry must remain unused within the ring
            because HIF expects that. */
        fill_level = pfe_hif_ring_get_fill_level(chnl->rx_ring);
        ring_len = pfe_hif_ring_get_len(chnl->rx_ring);

        accept_rx = ( fill_level < ( ring_len - 1U));
    }
    return accept_rx;
}

/**
 * @brief       Check if channel can accept number of TX requests
 * @param[in]   chnl The channel instance
 * @param[in]   num Number of TX requests
 * @retval      TRUE Channel can accept 'num' TX requests (buffers)
 * @retval      FALSE Not enough space in TX FIFO
 */
__attribute__((pure, hot)) bool_t pfe_hif_chnl_can_accept_tx_num(const pfe_hif_chnl_t *chnl, uint16_t num)
{
    bool_t accept_tx;
    uint32_t fill_level;
    uint32_t ring_len;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        accept_tx  = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  A single entry must remain unused within the ring because HIF expects that. */
        fill_level = pfe_hif_ring_get_fill_level(chnl->tx_ring);
        ring_len = pfe_hif_ring_get_len(chnl->tx_ring);

        accept_tx = ((ring_len - 1U - fill_level) >= num);
    }
    return accept_tx;
}

/**
 * @brief       Check if the TX FIFO is empty
 * @param[in]   chnl The channel instance
 * @retval      TRUE TX FIFO is empty
 * @retval      FALSE TX FIFO contains entries waiting for transmission
 */
__attribute__((pure, hot)) bool_t pfe_hif_chnl_tx_fifo_empty(const pfe_hif_chnl_t *chnl)
{
    bool_t is_empty;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        is_empty = TRUE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        is_empty = (0U == pfe_hif_ring_get_fill_level(chnl->tx_ring));
    }
    return is_empty;
}

/**
 * @brief       Get the RX FIFO depth
 * @param[in]   chnl The channel instance
 * @return      Size of the RX FIFO in number of entries
 */
__attribute__((pure, cold)) uint32_t pfe_hif_chnl_get_rx_fifo_depth(const pfe_hif_chnl_t *chnl)
{
    uint32_t rx_fifo_depth;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        rx_fifo_depth = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        rx_fifo_depth = pfe_hif_ring_get_len(chnl->rx_ring);
    }
    return rx_fifo_depth;
}

/**
 * @brief       Get the TX FIFO depth
 * @param[in]   chnl The channel instance
 * @return      Size of the TX FIFO in number of entries
 */
__attribute__((pure, cold)) uint32_t pfe_hif_chnl_get_tx_fifo_depth(const pfe_hif_chnl_t *chnl)
{
    uint32_t tx_fifo_depth;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        tx_fifo_depth = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        tx_fifo_depth = pfe_hif_ring_get_len(chnl->tx_ring);
    }
    return tx_fifo_depth;
}

/**
 * @brief       Request transmission of a buffer
 * @note        The TX resource availability shall be checked before this function
 *              is called using the pfe_hif_chnl_can_accept_tx_buf() call.
 * @note        Function is __NOT__ reentrant
 * @param[in]   chnl The channel instance
 * @param[in]   buf_pa Physical address of the buffer to be transmitted
 * @param[in]   buf_va Virtual address of the buffer to be transmitted
 * @param[in]   len Length of the buffer in bytes
 * @param[in]   lifm The last-in-frame indicator. Complete packet can consist
 *                   of multiple buffers. The last one shall be marked with
 *                   lifm=TRUE.
 * @retval      EOK Success
 * @retval      ENOSPC TX queue is full
 * @retval      EIO Internal error
 */
__attribute__((hot)) errno_t pfe_hif_chnl_tx(const pfe_hif_chnl_t *chnl, const void *buf_pa, const void *buf_va, uint32_t len, bool_t lifm)
{
    errno_t ret = EOK;
    uint32_t lmem_header_size;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == chnl) || (NULL == buf_pa) || (NULL == buf_va)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if (TRUE == HAL_HANDLE_CACHE)
        /*  Flush cache over the buffer */
        oal_mm_cache_flush(buf_va, buf_pa, len);
#endif /* HAL_HANDLE_CACHE */

        (void)buf_va;
        lmem_header_size = pfe_hif_chnl_get_lmem_hdr_size(chnl);
        /*  Enqueue the buffer into TX ring */
        ret = pfe_hif_ring_enqueue_buf(chnl->tx_ring, buf_pa, len, lmem_header_size, lifm);

#if !defined(PFE_CFG_DETACHED_MINIHIF)
        if (TRUE == lifm)
        {
            /*  Trigger the DMA */
            pfe_hif_chnl_tx_dma_start(chnl);
        }
#endif /* PFE_CFG_DETACHED_MINIHIF */
    }

    return ret;
}

/**
 * @brief       Get TX confirmation
 * @details     Each frame transmitted via pfe_hif_chnl_tx() will produce exactly
 *              one TX confirmation which can be retrieved by this function.
 * @param[in]   chnl The channel instance
 * @retval      EOK Next frame has been transmitted
 * @retval      EAGAIN No pending confirmations
 */
__attribute__((hot)) errno_t pfe_hif_chnl_get_tx_conf(pfe_hif_chnl_t *chnl)
{
    bool_t lifm;
    errno_t ret = EAGAIN;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Get all transmitted chunks but only the last-in-frame
            will be reported as TX confirmation. */
        while (EOK == pfe_hif_ring_dequeue_plain(chnl->tx_ring, &lifm))
        {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
#if defined(NXP_LOG_ENABLED)
            if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
            {
                /* Decrement BMU allocations counter. It is here because we expect that
                   the PFE HW just released a TX buffer previously allocated from BMU
                   pool within the pfe_hif_chnl_tx(). */
                pfe_hif_chnl_alloc_dec(chnl);
            }
#endif /* NXP_LOG_ENABLED */
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

            if (TRUE == lifm)
            {
                ret = EOK;
                break;
            }
        }
    }
    return ret;
}

#if (FALSE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
/**
 * @brief       Receive a buffer
 * @details     When channel has received some data into RX buffer then this
 *              function will retrieve it.
 * @note        The RX resource availability shall be checked before this function
 *              is called using the pfe_hif_chnl_can_accept_rx_buf() call.
 * @param[in]   chnl The channel instance
 * @param[out]  buf_pa Pointer to memory where pointer to the received data shall
 *                     be written (physical address, as seen by host)
 * @param[out]  len Pointer to memory where length in bytes of the received
 *                  data shall be written
 * @param[out]  lifm Pointer to memory where the last-in-frame flag shall be
 *                   written
 * @retval      EOK Buffer received
 * @retval      EAGAIN No more data to receive right now
 */
__attribute__((hot)) errno_t pfe_hif_chnl_rx(pfe_hif_chnl_t *chnl, void **buf_pa, uint32_t *len, bool_t *lifm)
{
    errno_t err;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == chnl) || (NULL == buf_pa) || (NULL == len) || (NULL == lifm) || (NULL == chnl->rx_ring)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        err = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {

        err = pfe_hif_ring_dequeue_buf(chnl->rx_ring, buf_pa, len, lifm);

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
#if defined(NXP_LOG_ENABLED)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* Increment BMU allocations counter. We have not allocated a buffer from BMU
               directly but the HW did that and then provided us the buffer. Therefore we
               need to properly handle it (release it once it has been processed). So we
               are counting it as allocated buffer here... */
            pfe_hif_chnl_alloc_inc(chnl);
        }
#endif /* NXP_LOG_ENABLED */
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

        /*  Check if ring has enough RX buffers */
        if (unlikely(0U == pfe_hif_ring_get_fill_level(chnl->rx_ring)))
        {
            /*  Out of RX buffers */
            if (likely(NULL != chnl->rx_oob_cbk.cbk))
            {
                chnl->rx_oob_cbk.cbk(chnl->rx_oob_cbk.arg);
            }
        }
    }

    return err;
}
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */
#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)

/**
 * @brief       Receive a buffer (virtual address)
 * @details     When channel has received some data into RX buffer then this
 *              function will retrieve it.
 * @note        The RX resource availability shall be checked before this function
 *              is called using the pfe_hif_chnl_can_accept_rx_buf() call.
 * @param[in]   chnl The channel instance
 * @param[out]  buf_va Pointer to memory where pointer to the received data shall
 *                     be written (virtual address, as seen by host)
 * @param[out]  len Pointer to memory where length in bytes of the received
 *                  data shall be written
 * @param[out]  lifm Pointer to memory where the last-in-frame flag shall be
 *                   written
 * @param[out]  meta Pointer to memory where pointer to pre-allocated memory
 *                   associated with the returned buffer shall be stored. Size
 *                   of the memory can be obtained by the pfe_hif_chnl_get_meta_size().
 * @retval      EOK Buffer received
 * @retval      EAGAIN No more data to receive right now
 * @retval      ENOMEM Out of memory
 */
__attribute__((hot)) errno_t pfe_hif_chnl_rx_va(pfe_hif_chnl_t *chnl, void **buf_va, uint32_t *len, bool_t *lifm, void **meta)
{
    errno_t ret;
    void *buf_pa;
    pfe_ct_hif_rx_hdr_t *hif_hdr_ptr = NULL;
    uint32_t vlan_header;
    uint32_t flags_map[4] = {HIF_RX_HIF0_VLAN, HIF_RX_HIF1_VLAN, HIF_RX_HIF2_VLAN, HIF_RX_HIF3_VLAN};

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    const pfe_ct_post_cls_hdr_t *pcls_hdr = NULL;
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == chnl) || (NULL == buf_va) || (NULL == len) || (NULL == lifm) || (NULL == meta)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_hif_ring_dequeue_buf(chnl->rx_ring, &buf_pa, len, lifm);
        if (EOK == ret)
        {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
            {
                /* HIF NOCPY */

                /* Addresses coming from the ring are physical addresses of buffers provided by BMU. The
                   buffer contains so called post-classification header the PFE classifier is internally
                   using as well as specific HIF header. Headers start from buffer offset 0x0 and we shall
                   strip-off the post-classification header here since upper layers do not know about such
                   thing. The space can be (and will be) used as the buffer-specific metadata storage. */
                *buf_va = pfe_bmu_get_va(chnl->bmu, (addr_t)buf_pa);
#if defined(PFE_CFG_NULL_ARG_CHECK)
                if (unlikely(NULL == *buf_va))
                {
                    NXP_LOG_DEBUG("Fatal: BMU converted p0x%lx to v0x0\n", (uint32_t)(addr_t)buf_pa);
                }
                else
#endif /* PFE_CFG_NULL_ARG_CHECK */
                {
                    /* Get pointer to the pre-allocated memory location where
                       a buffer-related metadata can be stored. */
                    *meta = &rx_meta_buf_mem_hifnocpy[(((addr_t)*buf_va / PFE_CFG_BMU2_BUF_SIZE) % ETH_43_PFE_BMU2_BUF_CNT)*ETH_43_PFE_META_BUF_SIZE];

                    /* Get post-classification header to get data offset */
                    pcls_hdr = (pfe_ct_post_cls_hdr_t *)*buf_va;

                    /* Skip the post-classification header to gain space for metadata storage.
                       The pfe_hif_chnl_release_buf() must be aware of this adjustment before
                       it will attempt to release buffer back to BMU hardware pool. This will
                       ensure the caller will receive also the HIF TX header but can reuse it
                        for custom purposes (see the pfe_hif_chnl_get_meta_size()). */
                    *buf_va = (void *)((addr_t)*buf_va + pcls_hdr->reserved[0]);

#if (TRUE == HAL_HANDLE_CACHE)
                    /* Invalidate cache over the buffer */
                    oal_mm_cache_inval(*buf_va, buf_pa, *len);
#endif /* HAL_HANDLE_CACHE */

#if defined(NXP_LOG_ENABLED)
                    /* Increment BMU allocations counter. We have not allocated a buffer from BMU
                       directly but the HW did that and then provided us the buffer. Therefore we
                       need to properly handle it (release it once it has been processed). So we
                       are counting this reception as allocated buffer here... */
                    pfe_hif_chnl_alloc_inc(chnl);
#endif /* NXP_LOG_ENABLED */
                }
            }
            else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
            {
                /* Return virtual address */
                *buf_va = buf_pa;

                hif_hdr_ptr = (pfe_ct_hif_rx_hdr_t *) *buf_va;
                /* Check if pkt is tagged */
                if(chnl->id < HIF_CFG_MAX_CHANNELS)
                {
                    if ((oal_ntohl(hif_hdr_ptr->flags) & (flags_map[chnl->id])) != (uint32_t)0)
                    {
                        /* On HIF hw is adding the vlan tag at 12 byte offset from the beggining
                            of the buffer. Copy the vlan header to the right position at offset 12
                            of the pkt witch is after the hif rx header. */
                        vlan_header = hif_hdr_ptr->rx_timestamp_s;
                        (void)autolibc_memmove(((uint8_t *)*buf_va) + (2U * MAC_ADDRESS_SIZE), ((uint8_t *)*buf_va) + (sizeof(pfe_ct_hif_rx_hdr_t)), (2U * MAC_ADDRESS_SIZE) + (sizeof(vlan_header)));
                        (void)autolibc_memcpy(((uint8_t *)*buf_va) + (sizeof(pfe_ct_hif_rx_hdr_t)) + (2U * MAC_ADDRESS_SIZE), &vlan_header, sizeof(vlan_header));
                    }
                }
                else
                {
                    NXP_LOG_ERROR("Channel id exceeds max channel\n");
                    ret = EINVAL;
                }
#if (TRUE == HAL_HANDLE_CACHE)
                /* Invalidate cache over the received data area */
                oal_mm_cache_inval(*buf_va, buf_pa, *len);
#endif /* HAL_HANDLE_CACHE */

                /* Return pointer to the pre-allocated memory location where
                   a buffer-related metadata can be stored. */
                *meta = rx_pool_get_meta_buf(&chnl->rx_pool, *buf_va);
            }
        }

        /* Check if ring has enough RX buffers */
        if (0U == pfe_hif_ring_get_fill_level(chnl->rx_ring))
        {
            /* Out of RX buffers */
            if (NULL != chnl->rx_oob_cbk.cbk)
            {
                chnl->rx_oob_cbk.cbk(chnl->rx_oob_cbk.arg);
            }
        }
    }

    return ret;
}

/**
 * @brief       Get size of metadata storage returned by the pfe_hif_chnl_rx_va()
 * @details     When driver is willing to use the pre-allocated storage associated
 *              with every RX buffer it must not write more data than is the
 *              pre-allocated block size. To ensure that, it shall call this API
 *              to get maximum number of bytes which can be written to the 'meta'
 *              memory location returned by the pfe_hif_chnl_rx_va().
 * @param[in]   chnl The channel instance
 * @return      Size of the metadata storage pointed by the 'meta' arugument of
 *              the pfe_hif_chnl_rx_va().
 */
__attribute__((cold)) uint32_t pfe_hif_chnl_get_meta_size(const pfe_hif_chnl_t *chnl)
{
    uint32_t meta_size;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        meta_size = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF NOCPY */

            /* In case of HIF NOCPY we're using whole RX packet header headroom
               for metadata storage. The headroom includes post-classification
               header and the HIF header. Both can be overwritten by custom data. */
            meta_size = sizeof(pfe_ct_post_cls_hdr_t) + sizeof(pfe_ct_hif_rx_hdr_t);
        }
        else
#elif !defined(PFE_CFG_NULL_ARG_CHECK)
        (void)chnl;
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            meta_size = ETH_43_PFE_META_BUF_SIZE;
        }
    }

    return meta_size;
}

/**
 * @brief       Release a channel provided buffer
 * @param[in]   chnl The channel instance
 * @param[in]   buf_va Pointer to buffer to be released (virtual)
 * @retval      EOK if success, error code otherwise
 */
__attribute__((hot)) errno_t pfe_hif_chnl_release_buf(pfe_hif_chnl_t *chnl, const void *buf_va)
{
    addr_t buf_pa;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF NOCPY */

            /* Get physical address */
            buf_pa = (addr_t)pfe_bmu_get_pa(chnl->bmu, (addr_t)buf_va);

            /* Apply the correction due to post-classification header skip done
               during the buffer reception. */
            buf_pa = buf_pa - sizeof(pfe_ct_post_cls_hdr_t);

            /* Release the buffer to BMU pool. Resource protection is embedded. */
            pfe_bmu_free_buf(chnl->bmu, buf_pa);

#if defined(NXP_LOG_ENABLED)
            /* Decrement BMU allocations counter */
            pfe_hif_chnl_alloc_dec(chnl);
#endif /* NXP_LOG_ENABLED */

            ret = EOK;
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            buf_pa = (addr_t)buf_va;

            if (unlikely(NULL == (void *)buf_pa))
            {
                NXP_LOG_ERROR("VA->PA conversion failed, origin buffer VA: v0x%p\n", buf_va);
            }

#if (TRUE == HAL_HANDLE_CACHE)
            /* Without this flush the invalidation does not properly work. Recycled buffers
               are not properly invalidated when this line is missing. */
            oal_mm_cache_flush(buf_va, (void *)buf_pa, ETH_43_PFE_CFG_HIF_RX_BUF_SIZE);
#endif /* HAL_HANDLE_CACHE */

            /* Release the buffer to ring */
            oal_mutex_lock(PFE_CHNL_RX_LOCK_MUTEX);
            ret = pfe_hif_ring_enqueue_buf(chnl->rx_ring, (void *)buf_pa, ETH_43_PFE_CFG_HIF_RX_BUF_SIZE, 0U, TRUE);
            oal_mutex_unlock(PFE_CHNL_RX_LOCK_MUTEX);
        }
    }

    return ret;
}
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */

/**
 * @brief       Supply RX buffer to be used for data reception
 * @param[in]   chnl The channel instance
 * @param[in]   buf_pa The RX buffer to be supplied (physical address, as seen
 *                     by host
 * @param[in]   size Size of the supplied buffer in bytes
 * @return      EOK Success
 * @note        Must not be preempted by pfe_hif_chnl_rx_disable()
 */
__attribute__((hot)) errno_t pfe_hif_chnl_supply_rx_buf(const pfe_hif_chnl_t *chnl, const void *buf_pa, uint32_t size)
{
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == chnl) || (NULL == buf_pa)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            (void)chnl;
            (void)buf_pa;
            (void)size;
            /* There is nothing to supply to HIF NOCPY */
            ret = EINVAL;
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            ret = pfe_hif_ring_enqueue_buf(chnl->rx_ring, buf_pa, size, 0U, TRUE);
            if (unlikely(EOK != ret))
            {
                NXP_LOG_WARNING("pfe_hif_ring_enqueue_buf() failed: %d\n", ret);
            }
        }
    }

    return ret;
}

/**
 * @brief       Assign RX BD ring
 * @details     Configure RX buffer descriptor ring address of the channel.
 *              This binds channel with a RX BD ring.
 * @param[in]   chnl The channel instance
 * @retval      EOK Success
 * @retval      EFAULT Invalid ring instance
 */
__attribute__((cold)) errno_t pfe_hif_chnl_bind_rx_ring(pfe_hif_chnl_t *chnl)
{
    pfe_hif_ring_t *ring = chnl->rx_ring;
    const void *rx_ring_pa, *wb_tbl_pa;
    errno_t ret;
#if !defined(PFE_CFG_DETACHED_MINIHIF)
    uint32_t wb_tbl_len = 0U;
#endif /*PFE_CFG_DETACHED_MINIHIF*/

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == chnl)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        rx_ring_pa = pfe_hif_ring_get_base_pa(ring);
        wb_tbl_pa = pfe_hif_ring_get_wb_tbl_pa(ring);

        if (NULL == rx_ring_pa)
        {
            NXP_LOG_ERROR("RX ring physical address is NULL\n");
            ret = EFAULT;
        }
        else
        {
            /* Access HW only if CBUS address was provided */
#if !defined(PFE_CFG_DETACHED_MINIHIF)
            if(NULL_ADDR != chnl->cbus_base_va)
            {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
                if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
                {
                    (void)wb_tbl_pa;
                    (void)wb_tbl_len;
                    /* HIF_NOCPY */
                    pfe_hif_nocpy_cfg_set_rx_bd_ring_addr(chnl->cbus_base_va, rx_ring_pa);
                }
                else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
                {
                    /* HIF */
                    pfe_hif_chnl_cfg_set_rx_bd_ring_addr(chnl->cbus_base_va, chnl->id, rx_ring_pa);
                    if (NULL != wb_tbl_pa)
                    {
                        wb_tbl_len = pfe_hif_ring_get_wb_tbl_len(ring);
                        pfe_hif_chnl_cfg_set_rx_wb_table(chnl->cbus_base_va, chnl->id, wb_tbl_pa, wb_tbl_len);
                    }
                }
            }
#else
            (void)wb_tbl_pa;
#endif /*PFE_CFG_DETACHED_MINIHIF*/

            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief       Assign TX BD ring
 * @details     Configure TX buffer descriptor ring address of the channel.
 *              This binds channel with a TX BD ring.
 * @param[in]   chnl The channel instance
 * @retval      EOK Success
 * @retval      EFAULT Invalid ring instance
 */
__attribute__((cold)) errno_t pfe_hif_chnl_bind_tx_ring(pfe_hif_chnl_t *chnl)
{
    pfe_hif_ring_t *ring = chnl->tx_ring;
    const void *tx_ring_pa;
    const void *wb_tbl_pa;
    errno_t ret;
#if !defined(PFE_CFG_DETACHED_MINIHIF)
    uint32_t wb_tbl_len = 0U;
#endif /*PFE_CFG_DETACHED_MINIHIF*/

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == chnl)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        tx_ring_pa = pfe_hif_ring_get_base_pa(ring);
        wb_tbl_pa = pfe_hif_ring_get_wb_tbl_pa(ring);

        if (NULL == tx_ring_pa)
        {
            NXP_LOG_ERROR("TX ring physical address is NULL\n");
            ret = EFAULT;
        }
        else
        {
            /* Access HW only if CBUS address was provided */
#if !defined(PFE_CFG_DETACHED_MINIHIF)
            if(NULL_ADDR != chnl->cbus_base_va)
            {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
                if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
                {
                    (void)wb_tbl_pa;
                    (void)wb_tbl_len;
                    /* HIF_NOCPY */
                    pfe_hif_nocpy_cfg_set_tx_bd_ring_addr(chnl->cbus_base_va, tx_ring_pa);
                }
                else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
                {
                    /* HIF */
                    pfe_hif_chnl_cfg_set_tx_bd_ring_addr(chnl->cbus_base_va, chnl->id, tx_ring_pa);

                    if (NULL != wb_tbl_pa)
                    {
                        wb_tbl_len = pfe_hif_ring_get_wb_tbl_len(ring);
                        pfe_hif_chnl_cfg_set_tx_wb_table(chnl->cbus_base_va, chnl->id, wb_tbl_pa, wb_tbl_len);
                    }
                }
            }
#else
            (void)wb_tbl_pa;
#endif /*PFE_CFG_DETACHED_MINIHIF*/

            ret = EOK;
        }
    }

    return ret;
}

#if !defined(PFE_CFG_DETACHED_MINIHIF)
/**
 * @brief       Initialize a channel
 * @details     Function prepares the HIF channel according to user-supplied parameters.
 *              This includes allocation of resources and configuration of the hardware.
 *              Routine must be called before RX or TX functionality is enabled.
 * @param[in]   chnl The channel instance
 * @return      EOK Success
 */
static errno_t pfe_hif_chnl_init_tx_rx_ring(pfe_hif_chnl_t *chnl)
{
    errno_t ret = EOK;
    bool_t bNocpy = FALSE;

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
    {
        if (PFE_HIF_CHNL_NOCPY_ID == chnl->id)
        {
            bNocpy = TRUE;
        }
    }
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

    ret = pfe_hif_ring_create(chnl->rx_ring, PFE_HIF_RX_RING_CFG_LENGTH, TRUE, bNocpy);
    if (EOK != ret)
    {
        NXP_LOG_ERROR("Couldn't create RX BD ring\n");
        /*  Destroy unattached rings */
        (void)pfe_hif_ring_destroy(chnl->rx_ring);
        ret = EFAULT;
    }
    else
    {
        ret = pfe_hif_ring_create(chnl->tx_ring, PFE_HIF_TX_RING_CFG_LENGTH, FALSE, bNocpy);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Couldn't create TX BD ring\n");
            /*  Destroy unattached rings */
            (void)pfe_hif_ring_destroy(chnl->rx_ring);
            (void)pfe_hif_ring_destroy(chnl->tx_ring);
            ret = EFAULT;
        }
        else
        {
            /* Required by Misra */
        }
    }

    return ret;
}
#endif /* PFE_CFG_DETACHED_MINIHIF */

#if defined(PFE_CFG_PFE_SLAVE)

/**
 * @brief       Inspect channel state
 * @details     Function reads channel HW registers to detect current channel state
 * @param[in]   chnl The channel instance
 * @return      EOK     Channel is clean
 * @return      EAGAIN  Channel has valid set-up for ungraceful reset
 * @return      EINVAL  Channel is in unrecorevable state
 */
static __attribute__((cold)) errno_t pfe_hif_chnl_inspect_hw_state(pfe_hif_chnl_t *chnl)
{
    errno_t ret;
    uint32_t rx_ring_addr;
    uint32_t rx_wb_ring_addr;
    uint32_t tx_ring_addr;
    uint32_t tx_wb_ring_addr;
    uint32_t rx_ring_len;
    uint32_t tx_ring_len;

    /* Stop the channel */
    pfe_hif_chnl_cfg_rx_disable(chnl->cbus_base_va, chnl->id);
    pfe_hif_chnl_cfg_tx_disable(chnl->cbus_base_va, chnl->id);
    pfe_hif_chnl_cfg_rx_dma_stop(chnl->cbus_base_va, chnl->id);
    pfe_hif_chnl_cfg_tx_dma_stop(chnl->cbus_base_va, chnl->id);

    /* Detect graceful start (all channel registers are zeroed) */
    rx_ring_addr = pfe_hif_chnl_cfg_get_rx_bd_ring_addr(chnl->cbus_base_va, chnl->id);
    rx_wb_ring_addr = pfe_hif_chnl_cfg_get_rx_wb_table_addr(chnl->cbus_base_va, chnl->id);
    tx_ring_addr = pfe_hif_chnl_cfg_get_tx_bd_ring_addr(chnl->cbus_base_va, chnl->id);
    tx_wb_ring_addr = pfe_hif_chnl_cfg_get_tx_wb_table_addr(chnl->cbus_base_va, chnl->id);
    if ((0U == rx_ring_addr) && (0U == rx_wb_ring_addr) && (0U == tx_ring_addr) && (0U == tx_wb_ring_addr))
    {
        NXP_LOG_INFO("HIF%u is in clean state\n", (uint_t)chnl->id);
        ret = EOK;
    }
    else if ((0U == rx_ring_addr) || (0U == rx_wb_ring_addr) || (0U == tx_ring_addr) || (0U == tx_wb_ring_addr))
    {
        NXP_LOG_ERROR("HIF%u has incomplete set-up. Ungraceful reset cannot be provided.\n", (uint_t)chnl->id);
        ret = EINVAL;
    }
    else
    {
        /* Channel state verification continues: verify rings sizes */
        rx_ring_len = pfe_hif_chnl_cfg_get_rx_wb_table_len(chnl->cbus_base_va, chnl->id);
        tx_ring_len = pfe_hif_chnl_cfg_get_tx_wb_table_len(chnl->cbus_base_va, chnl->id);
        if ((pfe_hif_ring_get_len(chnl->rx_ring) != rx_ring_len) || (pfe_hif_ring_get_len(chnl->tx_ring) != tx_ring_len))
        {
            NXP_LOG_ERROR("HIF%u ring sizes differ from default. Ungraceful reset cannot be used\n", (uint_t)chnl->id);
            ret = EINVAL;
        }
        else
        {
            NXP_LOG_DEBUG("HIF%u has valid set-up: RX: BD p0x%08x WB p0x%08x len %u, TX: BD p0x%08x WB p0x%08x len %u\n", (uint_t)chnl->id, (uint_t)rx_ring_addr, (uint_t)rx_wb_ring_addr, (uint_t)rx_ring_len, (uint_t)tx_ring_addr, (uint_t)tx_wb_ring_addr, (uint_t)tx_ring_len);
            ret = EAGAIN;
        }
    }

    return ret;
}
#endif /* PFE_CFG_PFE_SLAVE */

/**
 * @brief       Validate BDR set-up
 * @details     Function reads channel HW registers and compares the set-up of BD rings
 * @param[in]   chnl The channel instance
 * @return      TRUE if new allocated BD rings occupy the same memory regions as were
 *              left in channel registers
 */
static __attribute__((cold)) bool_t pfe_hif_chnl_validate_bdr_setup(pfe_hif_chnl_t *chnl)
{
    bool_t ret = TRUE;
    uint32_t rx_ring_addr;
    uint32_t rx_wb_ring_addr;
    uint32_t tx_ring_addr;
    uint32_t tx_wb_ring_addr;

    rx_ring_addr = pfe_hif_chnl_cfg_get_rx_bd_ring_addr(chnl->cbus_base_va, chnl->id);
    rx_wb_ring_addr = pfe_hif_chnl_cfg_get_rx_wb_table_addr(chnl->cbus_base_va, chnl->id);
    tx_ring_addr = pfe_hif_chnl_cfg_get_tx_bd_ring_addr(chnl->cbus_base_va, chnl->id);
    tx_wb_ring_addr = pfe_hif_chnl_cfg_get_tx_wb_table_addr(chnl->cbus_base_va, chnl->id);

    if (rx_ring_addr != (uint32_t)(addr_t)pfe_hif_ring_get_base_pa(chnl->rx_ring))
    {
        NXP_LOG_ERROR("HIF%u ungraceful reset check: RX BD addr differs\n", (uint_t)chnl->id);
        ret = FALSE;
    }
    else if (rx_wb_ring_addr != (uint32_t)(addr_t)pfe_hif_ring_get_wb_tbl_pa(chnl->rx_ring))
    {
        NXP_LOG_ERROR("HIF%u ungraceful reset check: RX WB addr differs\n", (uint_t)chnl->id);
        ret = FALSE;
    }
    else if (tx_ring_addr != (uint32_t)(addr_t)pfe_hif_ring_get_base_pa(chnl->tx_ring))
    {
        NXP_LOG_ERROR("HIF%u ungraceful reset check: TX BD addr differs\n", (uint_t)chnl->id);
        ret = FALSE;
    }
    else if (tx_wb_ring_addr != (uint32_t)(addr_t)pfe_hif_ring_get_wb_tbl_pa(chnl->tx_ring))
    {
        NXP_LOG_ERROR("HIF%u ungraceful reset check: TX WB addr differs\n", (uint_t)chnl->id);
        ret = FALSE;
    }
    else
    {
        ;   /*Avoid MISRA Rule 15.7*/
    }
    NXP_LOG_INFO("HIF%u ungraceful check: hw/memory setup passed\n", (uint_t)chnl->id);

    return ret;
}

static __attribute__((cold)) errno_t pfe_hif_chnl_find_tx(pfe_hif_chnl_t * chnl)
{
    uint32_t ring_idx;
    uint32_t ring_len;
    uint32_t tx_idx = 0U;
    errno_t ret = ENOENT;

    ring_len = pfe_hif_ring_get_len(chnl->tx_ring);

    (void)pfe_hif_chnl_tx_enable(chnl);

    for (ring_idx = 0U; ring_idx < ring_len; ring_idx++)
    {
        /* Send invalid packet(s) (to be dropped on Class) */
        ret = pfe_hif_chnl_send_dummy_frame(chnl, (void *) dummy_tx_buf, DUMMY_FRAME_INVALID);
        if (EOK != ret) 
        {
            NXP_LOG_ERROR("Can't send frame\n");
            break;
        }

        /* Wait */
        oal_time_usleep(500U);

        /* Find valid WB entry. It indicates the current position of TX ring */
        ret = pfe_hif_ring_find_wb_entry(chnl->tx_ring, TRUE, &tx_idx);
        if (EOK == ret)
        {
            NXP_LOG_DEBUG("TX index found for HIF%u: %u\n", (uint_t)chnl->id, (uint_t)tx_idx);
            break;
        }

        /* The index was not here, so invalidate current BD */
        pfe_hif_ring_invalidate_direct(chnl->tx_ring, ring_idx);
    }

    if (ENOENT == ret)
    {
        NXP_LOG_ERROR("TX index not found for HIF%u.\n", (uint_t)chnl->id);
    }
    else if (EOK == ret)
    {
        pfe_hif_ring_invalidate_direct(chnl->tx_ring, tx_idx);
        (void)pfe_hif_ring_force_index(chnl->tx_ring, tx_idx + 1U);
    }
    else
    {
        ;   /*Avoid MISRA Rule 15.7*/
    }

    pfe_hif_chnl_tx_disable(chnl);

    return ret;
}

static __attribute__((cold)) errno_t pfe_hif_chnl_find_rx(pfe_hif_chnl_t * chnl)
{
    uint32_t ring_idx;
    uint32_t ring_len;
    uint32_t rx_idx = 0U;
    uint32_t rx_bdp_fifo_empty_timeout = 0U;
    void *buf_va;
    void *buf_pa;
    errno_t ret = EOK;

    ring_len = pfe_hif_ring_get_len(chnl->rx_ring);

    if (TRUE == pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty(chnl->cbus_base_va, chnl->id))
    {
        /* To fit in RX hunter method we used (which is based on cached BD(s))
        * provide one BD and let BDP cache it.
        * We need two steps to cover the whole buffer, first with even BDs
        * and then switch to odd BDs in case of no success.
        */

        /* Alloc one frame buffer */
        buf_va = (void *)(&dummy_rx_buf);
        buf_pa = buf_va;    /* PA == VA */

        for (ring_idx = 0U; ring_idx < ring_len; ring_idx++)
        {
            ret = pfe_hif_chnl_supply_rx_buf(chnl, buf_pa, sizeof(dummy_rx_buf));
            if (EOK != ret)
            {
                NXP_LOG_ERROR("Can't provide dummy RX buffer\n");
                break;
            }
        }

        if(EOK == ret)
        {
            /* First step: even BDs */
            for (ring_idx = 1U; ring_idx < ring_len; ring_idx += 2U)
            {
                pfe_hif_ring_invalidate_direct(chnl->rx_ring, ring_idx);
            }

            /* Instruct BDP to fetch BD */
            (void)pfe_hif_chnl_rx_enable(chnl);
            pfe_hif_chnl_rx_dma_start(chnl);

            oal_time_usleep(500U);

            pfe_hif_chnl_rx_disable(chnl);

            if (TRUE == pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty(chnl->cbus_base_va, chnl->id))
            {
                /* Second step: odd BDs (in case when even BDs try was not sucessful */
                (void)pfe_hif_ring_force_index(chnl->rx_ring, 0U);

                for (ring_idx = 0U; ring_idx < ring_len; ring_idx += 2U)
                {
                    /* Invalidate odd BD */
                    pfe_hif_ring_invalidate_direct(chnl->rx_ring, ring_idx);
                    /* Revalidate back even BD */
                    pfe_hif_ring_revalidate_direct(chnl->rx_ring, ring_idx + 1U);
                }

                /* Instruct BDP to fetch BD */
                (void)pfe_hif_chnl_rx_enable(chnl);
                pfe_hif_chnl_rx_dma_start(chnl);

                oal_time_usleep(500U);

                pfe_hif_chnl_rx_disable(chnl);

                if (TRUE == pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty(chnl->cbus_base_va, chnl->id))
                {
                    /* Something got wrong */
                    NXP_LOG_ERROR("HIF%u is not able to cache BD\n", (uint_t)chnl->id);
                    ret = EINVAL;
                }
            }

            if(EOK == ret)
            {
                (void)pfe_hif_ring_force_index(chnl->rx_ring, 0U);
                /* Clean ring */
                for (ring_idx = 0U; ring_idx < ring_len; ring_idx++)
                {
                    pfe_hif_ring_invalidate_direct(chnl->rx_ring, ring_idx);
                }
            }
        }
    }

    if(EOK == ret)
    {
        /* Requires clean RX ring, with default WB BD control words (value: 0x200) */
        /* Start RX DMA */
        (void)pfe_hif_chnl_tx_enable(chnl);
        (void)pfe_hif_chnl_rx_enable(chnl);

        /* Empty cached BDs first */
        while(FALSE == pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty(chnl->cbus_base_va, chnl->id))
        {
            /* Could not empty BDP fifo - most likely due to ERR051211 workaround */
            if((rx_bdp_fifo_empty_timeout ++) >= ring_len)
            {
                NXP_LOG_ERROR("HIF%u couldn\'t empty BDP FIFO\n", (uint_t)chnl->id);
                ret = ETIMEDOUT;
                break;
            }

            /* Send dummy packet to self HIF channel */
            ret = pfe_hif_chnl_send_dummy_frame(chnl, (void *) dummy_tx_buf, DUMMY_FRAME_IHC_SELF);
            if (EOK != ret)
            {
                break;
            }

                    /* Wait */
                    oal_time_usleep(500U);

            /* Do TX confirmations */
            ret = pfe_hif_chnl_get_tx_conf(chnl);
            if (EOK != ret)
            {
                NXP_LOG_ERROR("Can't get TX confirmation\n");
                break;
            }
        }

        if(EOK == ret)
        {
            /* Find invalid WB entry. It indicates the current (stop) position of RX ring
            * NOTE: it can also wrap around.
            */
            if (EOK != pfe_hif_ring_find_wb_entry(chnl->rx_ring, FALSE, &rx_idx))
            {
                /* Something got wrong */
                NXP_LOG_ERROR("HIF%u is not able to find correct WB entry\n", (uint_t)chnl->id);
                ret = EINVAL;
            }
            else
            {
                NXP_LOG_DEBUG("Found RX index: %u\n", (uint_t)rx_idx);
                (void)pfe_hif_ring_force_index(chnl->rx_ring, rx_idx);
            }
        }
    }

    pfe_hif_chnl_tx_disable(chnl);
    pfe_hif_chnl_rx_disable(chnl);

    return ret;
}

static __attribute__((cold)) errno_t pfe_hif_chnl_rx_to_head(pfe_hif_chnl_t * chnl)
{
    uint32_t ring_item_idx;
    uint32_t ring_len;
    void *buf_va = NULL_PTR;
    void *buf_pa;
    bool_t lifm;
    errno_t ret = EOK;

    /* Alloc one frame buffer */
    buf_va = (void *)(&dummy_rx_buf);
    buf_pa = buf_va;    /* PA == VA */

    ring_len = pfe_hif_ring_get_len(chnl->rx_ring);

    /* Start RX DMA */
    (void)pfe_hif_chnl_tx_enable(chnl);
    (void)pfe_hif_chnl_rx_enable(chnl);

    ring_item_idx = 0U;
    while ((FALSE == pfe_hif_ring_is_on_head(chnl->rx_ring)) && (ring_len > ring_item_idx))
    {
        /* Fill one buffer only */
        ret = pfe_hif_chnl_supply_rx_buf(chnl, buf_pa, sizeof(dummy_rx_buf));
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Can't provide dummy RX buffer\n");
            break;
        }
        pfe_hif_chnl_rx_dma_start(chnl);

        /* Send dummy packet to self HIF channel */
        ret = pfe_hif_chnl_send_dummy_frame(chnl, (void *) dummy_tx_buf, DUMMY_FRAME_IHC_SELF);
        if (EOK != ret)
        {
            break;
        }

        /* Wait */
        oal_time_usleep(500U);

        /* Do TX confirmations */
        ret = pfe_hif_chnl_get_tx_conf(chnl);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Can't provide dummy RX buffer\n");
            break;
        }

        /* Do plain RX */
        ret = pfe_hif_ring_dequeue_plain(chnl->rx_ring, &lifm);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Can't get RX buffer dequeued\n");
            break;
        }

        ring_item_idx++;
    }

    if(EOK == ret)
    {
        if (ring_len <= ring_item_idx)
        {
            NXP_LOG_ERROR("Can't reach RX ring head\n");
            ret = EINVAL;
        }
        for (ring_item_idx = 0U; ring_item_idx < ring_len; ring_item_idx++)
        {
            pfe_hif_ring_invalidate_direct(chnl->rx_ring, ring_item_idx);
        }
    }

    pfe_hif_chnl_tx_disable(chnl);
    pfe_hif_chnl_rx_disable(chnl);

    return ret;
}

static __attribute__((cold)) errno_t pfe_hif_chnl_tx_to_head(pfe_hif_chnl_t * chnl)
{
    uint32_t ring_idx;
    uint32_t ring_len;
    errno_t ret = EOK;

    ring_len = pfe_hif_ring_get_len(chnl->tx_ring);

    pfe_hif_chnl_rx_disable(chnl);
    (void)pfe_hif_chnl_tx_enable(chnl); /* Start TX DMA */

    ring_idx = 0U;
    while (FALSE == pfe_hif_ring_is_on_head(chnl->tx_ring) && (ring_len > ring_idx))
    {
        /* Send invalid packet (to be dropped on Class) */
        ret = pfe_hif_chnl_send_dummy_frame(chnl, (void *) dummy_tx_buf, DUMMY_FRAME_INVALID);
        if (EOK != ret)
        {
            break;
        }

        /* Wait */
        oal_time_usleep(500U);

        /* Do TX confirmations */
        ret = pfe_hif_chnl_get_tx_conf(chnl);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Can't read TX confirmation\n");
            break;
        }

        ring_idx++;
    }

    if(EOK == ret)
    {
        if (ring_len <= ring_idx)
        {
            NXP_LOG_ERROR("Can't reach TX ring head\n");
            ret = EINVAL;
        }
    }

    pfe_hif_chnl_tx_disable(chnl);

    for (ring_idx = 0U; ring_idx < ring_len; ring_idx++)
    {
        pfe_hif_ring_invalidate_direct(chnl->tx_ring, ring_idx);
    }

    return ret;
}

static __attribute__((cold)) errno_t pfe_hif_chnl_ungraceful_reset(pfe_hif_chnl_t * chnl)
{
    errno_t ret;

    /* Find TX index first */
    ret = pfe_hif_chnl_find_tx(chnl);
    if (EOK == ret)
    {
        NXP_LOG_INFO("HIF%u ungraceful reset: stage 1 (tx finder) passed\n", (uint_t)chnl->id);
        
        /* Next find RX index */
        ret = pfe_hif_chnl_find_rx(chnl);
    }
    
    if (EOK == ret)
    {
        NXP_LOG_INFO("HIF%u ungraceful reset: stage 2 (rx finder) passed\n", (uint_t)chnl->id);

        /* Move to RX head first */
        ret = pfe_hif_chnl_rx_to_head(chnl);
    }
    
    if (EOK == ret)
    {
        NXP_LOG_INFO("HIF%u ungraceful reset: stage 3 (rx to head) passed\n", (uint_t)chnl->id);

        /* Next move to TX index */
        ret = pfe_hif_chnl_tx_to_head(chnl);
    }
    
    if (EOK == ret)
    {
        NXP_LOG_INFO("HIF%u ungraceful reset: stage 4 (tx to head) passed\n", (uint_t)chnl->id);
        NXP_LOG_INFO("HIF%u ungraceful reset: finished\n", (uint_t)chnl->id);
    }

    return ret;
}

/**
 * @brief       Initialize a channel
 * @details     Function prepares the HIF channel according to user-supplied parameters.
 *              This includes allocation of resources and configuration of the hardware.
 *              Routine must be called before RX or TX functionality is enabled.
 * @param[in]   chnl The channel instance
 * @param[in]   minihif If minihif is TRUE, it means that this function is used to configure the HIF channel for the minihif purpose.
 * @return      EOK Success
 */
__attribute__((cold)) errno_t pfe_hif_chnl_init(pfe_hif_chnl_t *chnl, bool_t minihif)
{
    errno_t ret = EOK;
    errno_t hw_status = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            if (NULL == chnl->bmu)
            {
                NXP_LOG_ERROR("Channel requires BMU instance\n");
                ret = EFAULT;
            }
            else
            {
                chnl->tx_ring = &tx_rings_memory_nocpy;
                chnl->rx_ring = &rx_rings_memory_nocpy;
                ret = pfe_hif_chnl_init_tx_rx_ring(chnl);
                if(EOK == ret)
                {
                    /* HIF NOCPY does not need external RX buffers */
                    rx_pool_init(&(chnl->rx_pool), NULL_PTR, &rx_meta_buf_mem_hifnocpy[0U], 0U, 0U);
                }
            }
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
#if !defined(PFE_CFG_DETACHED_MINIHIF)
            /* When the HIF channel is used for minihif purpose (TRUE == minihif), we won't allocate and attach TX and RX rings here.
            TX and RX rings will be allocated and attached by pfe_hif_chnl_set_tx_rx_ring() function after that. */
            if (FALSE == minihif)
            {
                if(chnl->id < HIF_CFG_MAX_CHANNELS)
                {
                    chnl->tx_ring = &tx_rings_memory[chnl->id];
                    chnl->rx_ring = &rx_rings_memory[chnl->id];

                    ret = pfe_hif_chnl_init_tx_rx_ring(chnl);
                    if(EOK == ret)
                    {
                        /* Initialize RX buffer pool. */
                        NXP_LOG_INFO("Initializing RX buffer pool. Depth: %u; Buffer Size: %d; Cache Line Size: %d\n",
                                    (uint_t)pfe_hif_chnl_get_rx_fifo_depth(chnl), ETH_43_PFE_CFG_HIF_RX_BUF_SIZE, HAL_CACHE_LINE_SIZE);

                        rx_pool_init( &(chnl->rx_pool),
                                    &rx_buf_mem[0U],
                                    &rx_meta_buf_mem[0U],
                                    ETH_43_PFE_CFG_HIF_RX_BUF_SIZE,
                                    ETH_43_PFE_CFG_HIF_RX_BUF_NUM
                                    );
                    }
                }
                else
                {
                    NXP_LOG_ERROR("Channel id exceeds max channel\n");
                    ret = EINVAL;
                }
            }
#endif /* PFE_CFG_DETACHED_MINIHIF */
        }

#if defined(PFE_CFG_PFE_SLAVE)
        if((EOK == ret) && (FALSE == minihif))
        {
            /* Slave: Check the HIF channel state */
            hw_status = pfe_hif_chnl_inspect_hw_state(chnl);
        }
        if (EINVAL == hw_status)
        {
            NXP_LOG_ERROR("HIF channel HW state not valid\n");
            ret = EFAULT;
        }
#endif

        /* NOTE: until now the new allocated BDRs must not be set to the channel HW */
        if (EAGAIN == hw_status)
        {
            /* Slave only way supporting ungraceful HIF reset */
            if (FALSE == pfe_hif_chnl_validate_bdr_setup(chnl))
            {
                NXP_LOG_ERROR("BDR setup not valid\n");
                ret = EFAULT;
            }
            else if (EOK != pfe_hif_chnl_ungraceful_reset(chnl))
            {
                /* Process ungraceful HIF reset procedure */
                NXP_LOG_ERROR("Could not perform ungraceful reset\n");
                ret = EFAULT;
            }
            /* Required by MISRA*/
            else
            {
                ;   /*Avoid MISRA Rule 15.7*/
            }
        }

        /* Bind BD rings to the channels. Skip for minihif.  */
        if((FALSE == minihif) && (EOK == ret))
        {
            /* Populate the RX ring */
            pfe_hif_chnl_refill_rx_buffers(chnl);

            /*  Bind TX BD ring to channel */
            if (EOK != pfe_hif_chnl_bind_tx_ring(chnl))
            {
                /*  Destroy unattached rings */
                (void)pfe_hif_ring_destroy(chnl->tx_ring);
                ret = EFAULT;
            }
            /*  Bind RX BD ring to channel */
            else if (EOK != pfe_hif_chnl_bind_rx_ring(chnl))
            {
                /*  Destroy unattached rings */
                (void)pfe_hif_ring_destroy(chnl->tx_ring);
                (void)pfe_hif_ring_destroy(chnl->rx_ring);
                ret = EFAULT;
            }
            /* Required by MISRA*/
            else
            {
                ;   /*Avoid MISRA Rule 15.7*/
            }

        }
    }

    (void)minihif;

    return ret;
}

#if !defined(PFE_CFG_DETACHED_MINIHIF)
/**
 * @brief       Get the RX BD processor state
 * @param[in]   chnl The channel instance
 * @return      TRUE if the BDP is active, FALSE otherwise
 */
__attribute__((hot)) bool_t pfe_hif_chnl_is_rx_dma_active(const pfe_hif_chnl_t *chnl)
{
    bool_t is_rx_active;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        is_rx_active = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* No protection here. Getting DMA status is atomic. */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            is_rx_active = pfe_hif_nocpy_cfg_is_rx_dma_active(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            /* HIF */
            is_rx_active = pfe_hif_chnl_cfg_is_rx_dma_active(chnl->cbus_base_va, chnl->id);
        }
    }

    return is_rx_active;
}

/**
 * @brief       Get the TX BD processor state
 * @param[in]   chnl The channel instance
 * @return      TRUE if the BDP is active, FALSE otherwise
 */
__attribute__((hot)) bool_t pfe_hif_chnl_is_tx_dma_active(const pfe_hif_chnl_t *chnl)
{
    bool_t is_tx_active;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        is_tx_active = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* No protection here. Getting DMA status is atomic. */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            is_tx_active = pfe_hif_nocpy_cfg_is_tx_dma_active(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            /* HIF */
            is_tx_active = pfe_hif_chnl_cfg_is_tx_dma_active(chnl->cbus_base_va, chnl->id);
        }
    }

    return is_tx_active;
}

/**
 * @brief       Send dummy pkt to self Hif channel
 * @param[in]   chnl The channel instance
 * @param[in]   tx_buf_va Tx buffer virtual address
 * @param[in]   mode Dummy frame send mode
 */
static __attribute__((cold)) errno_t pfe_hif_chnl_send_dummy_frame(pfe_hif_chnl_t *chnl, void *tx_buf_va, send_dummy_frame_mode_t mode)
{
    const void *tx_buf_pa;
    pfe_ct_hif_tx_hdr_t *tx_hdr;
    errno_t ret = EOK;

    tx_buf_pa = tx_buf_va;
    tx_hdr = (pfe_ct_hif_tx_hdr_t *)tx_buf_va;

    switch (mode)
    {
        case DUMMY_FRAME_INVALID:
            /* send invalid frame */
            tx_hdr->e_phy_ifs = 0U;
            tx_hdr->flags = (pfe_ct_hif_tx_flags_t) 0U;
            break;

        case DUMMY_FRAME_IHC_SELF:
            /* send IHC frame to self channel */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
            {
                tx_hdr->e_phy_ifs = oal_htonl((uint32_t)1U << PFE_PHY_IF_ID_HIF_NOCPY);
            }
            else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
            {
                tx_hdr->e_phy_ifs = oal_htonl((uint32_t)1U << ((uint8_t)PFE_PHY_IF_ID_HIF0 + (uint8_t)chnl->id));
            }
            tx_hdr->flags = (pfe_ct_hif_tx_flags_t)(HIF_TX_INJECT|HIF_TX_IHC);
            tx_hdr->chid = (uint8_t)chnl->id;
            break;

        default:
            break;
    }

    /*  Send dummy packet to self HIF channel */
    if (EOK != pfe_hif_chnl_tx(chnl, tx_buf_pa, tx_buf_va, DUMMY_TX_BUF_LEN, TRUE))
    {
        NXP_LOG_ERROR("Dummy frame TX failed\n");
    }

    return ret;
}

/**
 * @brief       Reset the rx ring by flush the RX BDP FIFO and set the current receive address to the original.
 * @param[in]   chnl The channel instance
 * @param[in]   ii The counter number of entry
 * @param[in]   tx_buf_va Tx buffer virtual address
 * @return      EOK if success, error code otherwise
 */
static __attribute__((cold)) errno_t pfe_hif_chnl_rx_ring_soft_reset(pfe_hif_chnl_t *chnl, uint32_t ii, void *tx_buf_va)
{
    errno_t ret = EOK;
    void *rx_buf_va = NULL;
    void *buf_pa;
    uint32_t count;
    uint32_t len;
    bool_t lifm;

    rx_buf_va = (void *)(&dummy_rx_buf);
    count = ii;
    /* Flush the RX BDP FIFO */
    while (FALSE == pfe_hif_chnl_cfg_is_rx_bdp_fifo_empty(chnl->cbus_base_va, chnl->id))
    {
        if (0U == pfe_hif_ring_get_fill_level(chnl->rx_ring))
        {
            /*  Provide single RX buffer */
            if (EOK != pfe_hif_chnl_supply_rx_buf(chnl, rx_buf_va, DUMMY_RX_BUF_LEN))
            {
                NXP_LOG_ERROR("Can't provide dummy RX buffer\n");
            }
        }
        (void)pfe_hif_chnl_send_dummy_frame(chnl, tx_buf_va, DUMMY_FRAME_IHC_SELF);

        /*  Wait */
        oal_time_usleep(500U);

        /*  Do TX confirmations */
        while (EOK != pfe_hif_chnl_get_tx_conf(chnl))
        {
            oal_time_usleep(100U);
        }

        /*  Do plain RX */
        while (EOK == pfe_hif_ring_dequeue_buf(chnl->rx_ring, &buf_pa, &len, &lifm))
        {
            ;
        }


        /* Decrement timeout counter */
        if (count > 0U)
        {
            count--;
        }
        else
        {
            NXP_LOG_ERROR("RX BD ring flush timed-out\n");
            ret = ETIMEDOUT;
            break;
        }
    }

#if defined(PFE_CFG_PFE_SLAVE)
    /* For Slave mode, need to transmit some more dummy frames to reset the RX ring pointer to the beginning position (see AAVB-3704).
       For Master mode, don't need transmit some more dummy frames to reset the RX ring pointer to the beginning position because there
       will be a PFE HW reset done in Master driver when re-init. So the issue in (AAVB-3704) doesn't happen with Master mode. */
    if (EOK == ret)
    {
        count = ii;
        /* When a slave driver instance requires reset, the associated HIF channel remembers rx/tx ring pointers.
           So when the driver is shut down and started again, the driver and HW ring pointers are different (driver
           points to first entry in the rings while hardware points to entry given by the previous state), We need
           to reset the current receivetion ring address to the origin to synchronize the ring pointer between hardware and software */
        while (chnl->rx_ring->bd_read.rd_bd != chnl->rx_ring->base_va)
        {
            if (0U == pfe_hif_ring_get_fill_level(chnl->rx_ring))
            {
                /*  Provide single RX buffer */
                if (EOK != pfe_hif_chnl_supply_rx_buf(chnl, rx_buf_va, DUMMY_RX_BUF_LEN))
                {
                    NXP_LOG_ERROR("Can't provide dummy RX buffer\n");
                }
            }
            (void)pfe_hif_chnl_send_dummy_frame(chnl, tx_buf_va, DUMMY_FRAME_IHC_SELF);

            /*  Wait */
            oal_time_usleep(500U);

            /*  Do TX confirmations */
            while (EOK == pfe_hif_chnl_get_tx_conf(chnl))
            {
                oal_time_usleep(100U);
            }

            /*  Do plain RX */
            while (EOK == pfe_hif_ring_dequeue_buf(chnl->rx_ring, &buf_pa, &len, &lifm))
            {
                ;
            }

            /* Decrement timeout counter */
            if (count > 0U)
            {
                count--;
            }
            else
            {
                NXP_LOG_ERROR("RX BD ring reset timed-out\n");
                ret = ETIMEDOUT;
                break;
            }
        }
    }
#endif /* PFE_CFG_PFE_SLAVE */

    if(EOK != ret)
    {
        /* Drain all in case when flush process has somehow failed */
        while (EOK == pfe_hif_ring_drain_buf(chnl->rx_ring, &buf_pa))
        {
            ;
        }
    }

    return ret;
}
/**
 * @brief       Flush RX BDP buffer and Reset the current receivetion ring address to the origin
 * @details     When channel is stopped the fetched BDs are remaining in internal
 *              buffer and don't get flushed once channel is re-enabled. This
 *              causes memory corruption when channel driver is stopped and then
 *              started with other BD rings because HIF is missing possibility
 *              to reset particular channels separately without affecting the
 *              other channels.
 *              When a slave driver instance requires reset, the associated HIF
 *              channel remembers rx/tx ring pointers. So when the driver is shut
 *              down and started again, the driver and HW ring pointers are different 
 *              (driver points to first entry in the rings while hardware points
 *              to entry given by the previous state), We need to reset the current
 *              receivetion ring address to the origin to synchronize the ring pointer
 *              between hardware and software
 * @param[in]   chnl The channel instance
 * @return      EOK if success, error code otherwise
 */
static __attribute__((cold)) errno_t pfe_hif_chnl_reset_rx_ring(pfe_hif_chnl_t *chnl)
{
    void *tx_buf_va = NULL;
    uint32_t ii;
    errno_t ret = EOK;

    tx_buf_va = (void *)(&dummy_tx_buf);

    /*  Activate the channel */
    (void)pfe_hif_chnl_rx_enable(chnl);
    (void)pfe_hif_chnl_tx_enable(chnl);

    /*  Get maximum number of tries */
    ii = pfe_hif_ring_get_len(chnl->rx_ring);

    /*  Try to flush the internal BD FIFO and reset the current receivetion ring address to the origin by software. */
    ret = pfe_hif_chnl_rx_ring_soft_reset(chnl, ii, tx_buf_va);

    /*  Deactivate the channel */
    (void)pfe_hif_chnl_rx_disable(chnl);
    (void)pfe_hif_chnl_tx_disable(chnl);

    return ret;
}

/**
 * @brief       Destroy HIF channel instance
 * @param[in]   chnl The channel instance
 */
static __attribute__((cold)) void pfe_hif_chnl_destroy_chnl(pfe_hif_chnl_t *chnl)
{
    /*  Disable and finalize the channel */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
    {
        /* HIF NOCPY will do the finalization */
    }
    else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    {
        oal_mutex_lock(PFE_CHNL_LOCK_MUTEX_12);

        pfe_hif_chnl_cfg_fini(chnl->cbus_base_va, chnl->id);

        oal_mutex_unlock(PFE_CHNL_LOCK_MUTEX_12);
    }
}

static __attribute__((cold)) void pfe_hif_chnl_destroy_rings(pfe_hif_chnl_t *chnl)
{
    /*  Disable the HIF channel BDP/DMA */
    pfe_hif_chnl_rx_disable(chnl);
    pfe_hif_chnl_tx_disable(chnl);

    /*  Destroy rings */
    if (NULL != chnl->rx_ring)
    {
        (void)pfe_hif_ring_destroy(chnl->rx_ring);
        chnl->rx_ring = NULL;
    }

    if (NULL != chnl->tx_ring)
    {
        if (TRUE != pfe_hif_chnl_cfg_is_tx_bdp_fifo_empty(chnl->cbus_base_va, chnl->id))
        {
            NXP_LOG_WARNING("HIF channel TX FIFO is not empty\n");
        }

        (void)pfe_hif_ring_destroy(chnl->tx_ring);
        chnl->tx_ring = NULL;
    }

    pfe_hif_chnl_destroy_chnl(chnl);
}

static __attribute__((cold)) void pfe_hif_chnl_destroy_inval_rx_ring(pfe_hif_chnl_t *chnl)
{
#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
    void *buf_pa = NULL;
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */

#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
    /*  Drain RX buffers (the ones enqueued in RX ring) */
    while (EOK == pfe_hif_ring_drain_buf(chnl->rx_ring, &buf_pa))
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /*  HIF NOCPY buffers are provided by BMU so return them to BMU */
            pfe_bmu_free_buf(chnl->bmu, (addr_t)buf_pa);
        }
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    }

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
#if defined(NXP_LOG_ENABLED)
    if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
    {
        /* Sanity check to verify if the HIF RX ring and the upper SW layers
           have properly returned all RX and TX buffers back to the BMU. We're
           using the allocations counter here to determine delta between number
           of allocated buffers (either TX buffers we have directly allocated
           or received buffers which have been allocated by the PFE HW) and
           number of released buffers. */
        if (0U != pfe_hif_chnl_get_alloc_cnt(chnl))
        {
            NXP_LOG_WARNING("Some buffers not returned to the BMU\n");
        }
        else
        {
            NXP_LOG_INFO("All buffers returned to the BMU\n");
        }
    }
#endif /* NXP_LOG_ENABLED */
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */

    /* Invalidate the RX ring */
    pfe_hif_ring_invalidate(chnl->rx_ring);

    /* Here the ring should be empty. Execute HIF channel BDP shutdown (a.k.a. Graceful reset)
       procedure to ensure that channel will not keep any content in internal buffers. */
    if (EOK != pfe_hif_chnl_reset_rx_ring(chnl))
    {
        NXP_LOG_ERROR("FATAL: Could not flush RX BD FIFO\n");
    }
}

#if defined(PFE_CFG_PFE_SLAVE)
/**
 * @brief       Reset the current transmission ring address to the origin
 * @details     When a slave driver instance requires reset, the associated HIF
 *              channel remembers rx/tx ring pointers. So when the driver is shut
 *              down and started again, the driver and HW ring pointers are different 
 *              (driver points to first entry in the rings while hardware points
 *              to entry given by the previous state), We need to reset the current
 *              transmission ring address to the origin to synchronize the ring pointer
 *              between hardware and software
 * @param[in]   chnl The channel instance
 * @return      EOK if success, error code otherwise
 */

static __attribute__((cold)) void pfe_hif_chnl_reset_tx_ring(pfe_hif_chnl_t *chnl)
{
    void *tx_buf_va = NULL;
    uint32_t count;

    tx_buf_va = (void *)(&dummy_tx_buf);
    
    /*  Activate the tx channel */
    (void)pfe_hif_chnl_tx_enable(chnl);

    /*  Get maximum number of tries */
    count = pfe_hif_ring_get_len(chnl->tx_ring);

    while (chnl->tx_ring->bd_read.rd_bd != chnl->tx_ring->base_va)
    {
        /*  Send dummy packet to self HIF channel */
        pfe_hif_chnl_send_dummy_frame(chnl, tx_buf_va, DUMMY_FRAME_INVALID);

        /*  Wait */
        oal_time_usleep(500U);

        /*  Do TX confirmations */
        while (EOK == pfe_hif_chnl_get_tx_conf(chnl))
        {
            oal_time_usleep(100U);
        }
        /*  Decrement timeout counter */
        if (count > 0U)
        {
            count--;
        }
        else
        {
            NXP_LOG_ERROR("TX BD ring reset timed-out\n");
            break;
        }
    }

    /*  Deactivate the tx channel */
    (void)pfe_hif_chnl_tx_disable(chnl);
}
#endif /* PFE_CFG_PFE_SLAVE */

/**
 * @brief       Destroy HIF channel instance
 * @param[in]   chnl The channel instance
 */
__attribute__((cold)) void pfe_hif_chnl_destroy(pfe_hif_chnl_t *chnl)
{
    if (NULL != chnl)
    {
        /*  Disable channel interrupts */
        pfe_hif_chnl_irq_mask(chnl);
        pfe_hif_chnl_rx_irq_mask(chnl);
        pfe_hif_chnl_tx_irq_mask(chnl);

        /*  Uninstall callbacks */
        chnl->rx_cbk.cbk = NULL;
        chnl->tx_cbk.cbk = NULL;
        chnl->rx_oob_cbk.cbk = NULL;

        if (NULL != chnl->rx_ring)
        {
            pfe_hif_chnl_destroy_inval_rx_ring(chnl);
        }

#if defined(PFE_CFG_PFE_SLAVE)
        /* For Slave mode, neen to call pfe_hif_chnl_reset_tx_ring() to reset the TX ring pointer to the beginning position (see AAVB-3704).
           For Master mode, don't need to call pfe_hif_chnl_reset_tx_ring() because there will be a PFE HW reset done in Master driver when re-init.
           So the issue in (AAVB-3704) doesn't happen with Master mode. */
        if (NULL != chnl->tx_ring)
        {
            pfe_hif_chnl_reset_tx_ring(chnl);
        }

        /* Clear channel registers to signalize graceful shutdown */
        pfe_hif_chnl_cfg_set_rx_bd_ring_addr(chnl->cbus_base_va, chnl->id, (void *)0LU);
        pfe_hif_chnl_cfg_set_rx_wb_table(chnl->cbus_base_va, chnl->id, (void *)0LU, 0U);
        pfe_hif_chnl_cfg_set_tx_bd_ring_addr(chnl->cbus_base_va, chnl->id, (void *)0LU);
        pfe_hif_chnl_cfg_set_tx_wb_table(chnl->cbus_base_va, chnl->id, (void *)0LU, 0U);
#endif /* PFE_CFG_PFE_SLAVE */

        pfe_hif_chnl_destroy_rings(chnl);
    }
}
#endif /* PFE_CFG_DETACHED_MINIHIF */

/**
 * @brief       Dump of SW client channel rings
 * @details     Dumps particular ring
 * @param[in]   chnl The client channel instance
 * @param[in]   dump_rx True if RX ring has to be dumped
 * @param[in]   dump_tx True if TX ring has to be dumped
 */
__attribute__((cold)) void pfe_hif_chnl_dump_ring(const pfe_hif_chnl_t *chnl, bool_t dump_rx, bool_t dump_tx)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if(dump_rx)
        {
            pfe_hif_ring_dump(chnl->rx_ring, "RX");
        }

        if(dump_tx)
        {
            pfe_hif_ring_dump(chnl->tx_ring, "TX");
        }
    }
}

#if !defined(PFE_CFG_DETACHED_MINIHIF)

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return HIF channel runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   chnl        The channel instance
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   buf_len     Buffer length
 * @param[in]   verb_level  Verbosity level, number of data written to the buffer
 * @return      Number of bytes written to the buffe
 */
__attribute__((cold)) uint32_t pfe_hif_chnl_get_text_statistics(const pfe_hif_chnl_t *chnl, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            len += pfe_hif_nocpy_chnl_cfg_get_text_stat(chnl->cbus_base_va, buf, buf_len, verb_level);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            /* HIF */
            len += pfe_hif_chnl_cfg_get_text_stat(chnl->cbus_base_va, chnl->id, buf, buf_len, verb_level);
        }
    }

    return len;
}

#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Get number of transmitted packets (from PFE to HOST)
 * @param[in]   emac The channel instance
 * @return      Number of transmitted packets
 */
uint32_t pfe_hif_chnl_get_tx_cnt(const pfe_hif_chnl_t *chnl)
{
    uint32_t tx_cnt;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        tx_cnt = 0xffffffffU;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            tx_cnt = pfe_hif_nocpy_cfg_get_tx_cnt(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            tx_cnt = pfe_hif_chnl_cfg_get_tx_cnt(chnl->cbus_base_va, chnl->id);
        }
    }

    return tx_cnt;
}

/**
 * @brief       Get number of received packets (from HOST to PFE)
 * @param[in]   emac The channel instance
 * @return      Number of received packets
 */
uint32_t pfe_hif_chnl_get_rx_cnt(const pfe_hif_chnl_t *chnl)
{
    uint32_t rx_cnt;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        rx_cnt = 0xffffffffU;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            /* HIF_NOCPY */
            rx_cnt = pfe_hif_nocpy_cfg_get_rx_cnt(chnl->cbus_base_va);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            rx_cnt = pfe_hif_chnl_cfg_get_rx_cnt(chnl->cbus_base_va, chnl->id);
        }
    }

    return rx_cnt;
}
#endif /* PFE_CFG_DETACHED_MINIHIF */

/**
 * @brief       Check if TX ring in  HIF channel contains less than watermark-specified
 *              number of free entries
  @param[in]    chnl        The channel instance
 * @return      TRUE if ring contains less than watermark-specified number
 *              of free entries
 */
bool_t pfe_hif_chnl_tx_fifo_is_below_wm(const pfe_hif_chnl_t *chnl)
{
    bool_t is_below_wm;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        is_below_wm = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        is_below_wm =  pfe_hif_ring_is_below_wm(chnl->tx_ring);
    }
    return is_below_wm;
}

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief       Allocate buffer via BMU
 * @param[in]   chnl The channel instance
 * @return      Allocated buffer pointer (virtual)
 */
__attribute__((hot)) void *pfe_hif_chnl_bmu_alloc_buf_va(pfe_hif_chnl_t *chnl)
{
    void *tx_buf_pa;
    void *ret = NULL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        tx_buf_pa = pfe_bmu_alloc_buf(chnl->bmu);
        if (unlikely(NULL == tx_buf_pa))
        {
            NXP_LOG_ERROR("BMU can't allocate TX buffer\n");
            ret = NULL;
        }
        else
        {
#if defined(NXP_LOG_ENABLED)
            /*  Increment BMU allocations counter */
            pfe_hif_chnl_alloc_inc(chnl);
#endif /* NXP_LOG_ENABLED */

            /*  Get VA */
            ret = (void *) pfe_bmu_get_va(chnl->bmu, (addr_t)tx_buf_pa);
        }
    }
    return ret;
}

/**
 * @brief       Convert virtual buffer address to physical one
 * @param[in]   chnl The channel instance
 * @param[in]   va The address to be converted
 * @return      Associated virtual address or NULL if failed
 */
__attribute__((hot)) void *pfe_hif_chnl_bmu_get_buf_pa(const pfe_hif_chnl_t *chnl, addr_t va)
{
    void *ReVal;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ReVal = NULL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    ReVal = (void *) pfe_bmu_get_pa(chnl->bmu, (addr_t)va);
    return ReVal;
}

/**
 * @brief       Free buffer via BMU
 * @param[in]   chnl The channel instance
 * @param[in]   va Pointer (virtual) to the buffer to be freed.
 * @note        Thread safe
 */
__attribute__((hot)) void pfe_hif_chnl_bmu_free_buf(pfe_hif_chnl_t *chnl, addr_t va)
{
    void *tx_buf_pa;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        tx_buf_pa = (void *)pfe_bmu_get_pa(chnl->bmu, (addr_t)va);

        pfe_bmu_free_buf(chnl->bmu, (addr_t)tx_buf_pa);

#if defined(NXP_LOG_ENABLED)
        /*  Decrement BMU allocations counter */
        pfe_hif_chnl_alloc_dec(chnl);
#endif /* NXP_LOG_ENABLED */
    }
}
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/**
 * @brief       Set the value of LMEM Header size used by the HW
 * @param[in]   chnl The channel instance
 * @param[in]   lmem_header_size The size of LMEM Header
 */
void pfe_hif_chnl_set_lmem_hdr_size(pfe_hif_chnl_t *chnl, uint16_t lmem_header_size)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    chnl->lmem_header_size = lmem_header_size;
#else
    (void)lmem_header_size;
    (void)chnl;
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
}

/**
 * @brief       Get the value of LMEM Header size used by the HW
 * @param[in]   chnl The channel instance
 * @return      The size of LMEM Header
 * @warning     Function shall be used only for HIF_NOCPY channels
 */
uint16_t pfe_hif_chnl_get_lmem_hdr_size(const pfe_hif_chnl_t *chnl)
{
    uint16_t lmem_header_size = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == chnl))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
        {
            lmem_header_size = chnl->lmem_header_size;
        }
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    (void)chnl;

    return lmem_header_size;
}

/**
 * @brief       Marks that a PFE instance associated with the current HIF channel is owner of an EMAC timer
 * @param[in]   local_chnl Base address of HIF register space (virtual)
 * @param[in]   hif_id The HIF ID that would take timer ownership
 * @param[in]   emac The EMAC id
 * @param[in]   value The value of EMAC timer ownership for the PFE instance associated to current HIF channel. TRUE - owner, FALSE - not owner
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_hif_chnl_set_emac_timer_ownership(addr_t cbus_base_va, pfe_ct_phy_if_id_t hif_id, pfe_ct_phy_if_id_t emac, bool_t value)
{
    errno_t ret = EOK;

    if (PFE_PHY_IF_ID_HIF_NOCPY == hif_id)
    {
        ret = pfe_hif_nocpy_cfg_set_emac_timer_ownership(emac, value);
        (void)cbus_base_va;
        (void)hif_id;
    }
    else
    {
        ret = pfe_hif_chnl_cfg_set_emac_timer_ownership(cbus_base_va, pfe_timer_owner_hif_from_phy_id(hif_id), emac, value);
    }
 
    return ret;
}

/**
 * @brief       Get EMAC timer ownership status for PFE instance associated to the current HIF channel
 * @param[in]   cbus_base_va Base address of HIF register space (virtual)
 * @param[in]   hif_id The HIF ID that would get timer ownership status
 * @param[in]   emac The EMAC id
 * @return      TRUE if PFE instance associated with the current HIF channel is timer owner of specified EMAC, FALSE otherwise
 */
bool_t pfe_hif_chnl_get_emac_timer_ownership(addr_t cbus_base_va, pfe_ct_phy_if_id_t hif_id, pfe_ct_phy_if_id_t emac)
{
    bool_t is_owner = FALSE;

    if (PFE_PHY_IF_ID_HIF_NOCPY == hif_id)
    {
        is_owner = pfe_hif_nocpy_cfg_get_emac_timer_ownership(emac);
        (void)cbus_base_va;
        (void)hif_id;
    }
    else
    {
        is_owner = pfe_hif_chnl_cfg_get_emac_timer_ownership(cbus_base_va, pfe_timer_owner_hif_from_phy_id(hif_id), emac);
    }

    return is_owner;
}

/**
 * @brief       Get HW status for HIF channel
 * @param[in]   chnl The channel instance
 * @return      TRUE if the channel registers are in reset state, FALSE otherwise
 */
bool_t pfe_hif_chnl_is_hw_reset_state(pfe_hif_chnl_t *chnl)
{
    bool_t bRet = FALSE;
    uint32_t rx_ring_addr;
    uint32_t tx_ring_addr;

    /* Stop the channel */
    pfe_hif_chnl_rx_disable(chnl);
    pfe_hif_chnl_tx_disable(chnl);

    /* Detect graceful start (all channel registers are zeroed) */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    if (chnl->id >= PFE_HIF_CHNL_NOCPY_ID)
    {
        rx_ring_addr = pfe_hif_nocpy_cfg_get_rx_bd_ring_addr(chnl->cbus_base_va);
        tx_ring_addr = pfe_hif_nocpy_cfg_get_tx_bd_ring_addr(chnl->cbus_base_va);
    }
    else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    {
        rx_ring_addr = pfe_hif_chnl_cfg_get_rx_bd_ring_addr(chnl->cbus_base_va, chnl->id);
        tx_ring_addr = pfe_hif_chnl_cfg_get_tx_bd_ring_addr(chnl->cbus_base_va, chnl->id);     
    }

    if ((0U == rx_ring_addr) && (0U == tx_ring_addr))
    {
        NXP_LOG_INFO("HIF%u is in clean state\n", (uint_t)chnl->id);
        bRet = TRUE;
    }
    return bRet;
}

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */
