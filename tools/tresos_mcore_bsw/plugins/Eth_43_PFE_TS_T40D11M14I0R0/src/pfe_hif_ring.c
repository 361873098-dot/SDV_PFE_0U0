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
 *  Copyright 2018-2024 NXP
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
 * @file        pfe_hif_ring.c
 * @brief       The HIF BD ring driver.
 * @details     This is the HW BD ring interface providing basic manipulation
 *              possibilities for HIF's RX and TX buffer descriptor rings.
 *              Each ring is treated as a single instance therefore module can
 *              be used to handle HIF with multiple channels (RX/TX ring pairs).
 *
 * @note        BD and WB BD rings are non-cached entities.
 *
 * @warning     No concurrency prevention is implemented here. User shall
 *              therefore ensure correct protection of ring instance manipulation
 *              at application level.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"

#include "pfe_platform_cfg.h"
#include "pfe_platform.h"
#include "pfe_cbus.h"
#include "pfe_hif_ring.h"

/* LOCAL VARIABLES */

/* Minimum is 8, 16 avoids complications with 4K boundary */
#define BD_ALIGNMENT ((16U > HAL_CACHE_LINE_SIZE) ? 16U : HAL_CACHE_LINE_SIZE)

/* Memory for buffer descriptors. Should be DMA safe, contiguous, and 64-bit aligned. */
/* Arrays should be static but are not to avoid memmap issues with some compilers */
#ifdef PFE_CFG_HIF_NOCPY_SUPPORT
    /* GCC attribute 'section' only works for a variable. So, we need to add below macro for all variables */
    /* RX BD ring */
    #define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
    __attribute__((aligned(BD_ALIGNMENT))) pfe_hif_nocpy_bd_t arRxBdRing[ETH_43_PFE_MAX_RXBD_CNT];
    #define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
    /* TX BD ring */
    #define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
    __attribute__((aligned(BD_ALIGNMENT))) pfe_hif_nocpy_bd_t arTxBdRing[ETH_43_PFE_MAX_TXBD_CNT];
    #define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
#else
    /* RX BD ring */
    #define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
    __attribute__((aligned(BD_ALIGNMENT))) pfe_hif_bd_t    arRxBdRing[ETH_43_PFE_MAX_RXBD_CNT];
    #define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
    /* RX Write-back BD ring */
    #define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
    __attribute__((aligned(BD_ALIGNMENT))) pfe_hif_wb_bd_t arRxBdWbRing[ETH_43_PFE_MAX_RXBD_CNT];
    #define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
    /* TX BD ring */
    #define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
    __attribute__((aligned(BD_ALIGNMENT))) pfe_hif_bd_t    arTxBdRing[ETH_43_PFE_MAX_TXBD_CNT];
    #define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
    /* TX Write-back BD ring */
    #define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
    __attribute__((aligned(BD_ALIGNMENT))) pfe_hif_wb_bd_t arTxBdWbRing[ETH_43_PFE_MAX_TXBD_CNT];
    #define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BD_MEM
    #include "Eth_43_PFE_MemMap.h"
#endif

/* LOCAL FUNCTION PROTOTYPES */

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

/* Following functions needed for both MCAL and minihif */
__attribute__((hot)) static inline void inc_read_index(pfe_hif_ring_t *ring);
__attribute__((hot)) static inline void inc_write_index(pfe_hif_ring_t *ring);
__attribute__((cold)) static errno_t pfe_hif_ring_init_ring_std(pfe_hif_ring_t *ring, void *ring_va, void *wb_ring_va, uint32_t length, bool_t is_rx);
__attribute__((cold)) static errno_t pfe_hif_ring_create_std(pfe_hif_ring_t *ring, void *ring_va, void *wb_ring_va, uint32_t length, bool_t rx);
__attribute__((hot)) static inline errno_t pfe_hif_ring_enqueue_buf_std(pfe_hif_ring_t *ring, const void *buf_pa, uint32_t length, bool_t lifm);
__attribute__((hot)) static inline errno_t pfe_hif_ring_dequeue_plain_std(pfe_hif_ring_t *ring, bool_t *lifm);
__attribute__((cold)) static void pfe_hif_ring_invalidate_std(const pfe_hif_ring_t *ring);
__attribute__((cold)) static void pfe_hif_ring_init_bd_std(const pfe_hif_ring_t *ring);
/* Following functions needed only for MCAL */
#if !defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    __attribute__((hot)) static inline errno_t pfe_hif_ring_dequeue_buf_std(pfe_hif_ring_t *ring, void **buf_pa, uint32_t *length, bool_t *lifm);
    __attribute__((hot)) static inline void dec_write_index_std(pfe_hif_ring_t *ring);
#else /* defined PFE_CFG_HIF_NOCPY_SUPPORT */
    __attribute__((cold)) static errno_t pfe_hif_ring_create_nocpy(pfe_hif_ring_t *ring, void *ring_va, uint32_t length, bool_t rx);
    __attribute__((cold)) static errno_t pfe_hif_ring_init_ring_nocpy(pfe_hif_ring_t *ring, void *ring_va, uint32_t length, bool_t is_rx);
    __attribute__((hot)) static inline errno_t pfe_hif_ring_enqueue_buf_nocpy(pfe_hif_ring_t *ring, const void *buf_pa, uint32_t length, uint32_t lmem_header_size, bool_t lifm);
    __attribute__((hot)) static inline errno_t pfe_hif_ring_dequeue_buf_nocpy(pfe_hif_ring_t *ring, void **buf_pa, uint32_t *length, bool_t *lifm);
    __attribute__((hot)) static inline errno_t pfe_hif_ring_dequeue_plain_nocpy(pfe_hif_ring_t *ring, bool_t *lifm);
    __attribute__((cold)) static void pfe_hif_ring_invalidate_nocpy(const pfe_hif_ring_t *ring);
    __attribute__((cold)) static void pfe_hif_ring_init_bd_nocpy(const pfe_hif_ring_t *ring);
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/*==================================================================================================*/
__attribute__((hot)) static inline void inc_write_index(pfe_hif_ring_t *ring)
{
    uint32_t idx = ring->write_idx + 1U;

    /* idx >= (2U * ring->length */
    if (idx >= (ring->length << 1U))
    {
        idx = 0U;
    }
    ring->write_idx = idx;
    if (idx >= ring->length)
    {
        idx -= ring->length;
    }

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    if(TRUE == ring->nocpy)
    {
        ring->bd_write.wr_bd_nocpy = &((pfe_hif_nocpy_bd_t *)ring->base_va)[idx];
    }
    else
#endif
    {
        ring->bd_write.wr_bd = &((pfe_hif_bd_t *)ring->base_va)[idx];
        ring->wr_wb_bd = &((pfe_hif_wb_bd_t *)ring->wb_tbl_base_va)[idx];
    }
}

/*==================================================================================================*/
#if !defined(PFE_CFG_HIF_NOCPY_SUPPORT)
__attribute__((hot)) static inline void dec_write_index_std(pfe_hif_ring_t *ring)
{
    uint32_t idx = ring->write_idx;

    if (0U == idx)
    {
        PfeDevAssert(ring->length > 0);
        idx = (2U * ring->length) - 1U;
    }
    else
    {/*decrement index if it's not already 0*/
        idx--;
    }
    ring->write_idx = idx;
    if (idx >= ring->length)
    {
        idx -= ring->length;
    }

    ring->bd_write.wr_bd = &((pfe_hif_bd_t *)ring->base_va)[idx];
    ring->wr_wb_bd = &((pfe_hif_wb_bd_t *)ring->wb_tbl_base_va)[idx];
}
#endif /* !PFE_CFG_HIF_NOCPY_SUPPORT */

/*==================================================================================================*/
__attribute__((hot)) static inline void inc_read_index(pfe_hif_ring_t *ring)
{
    uint32_t idx = ring->read_idx + 1U;

    /* idx >= (2U * ring->length */
    if (idx >= (ring->length << 1U))
    {
        idx = 0U;
    }
    ring->read_idx = idx;
    if (idx >= ring->length)
    {
        idx -= ring->length;
    }
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    if(TRUE == ring->nocpy)
    {
        ring->bd_read.rd_bd_nocpy = &((pfe_hif_nocpy_bd_t *)ring->base_va)[idx];
    }
    else
#endif
    {
        ring->bd_read.rd_bd = &((pfe_hif_bd_t *)ring->base_va)[idx];
        ring->rd_wb_bd = &((pfe_hif_wb_bd_t *)ring->wb_tbl_base_va)[idx];
    }
}

/**
 * @brief       Get fill level
 * @param[in]   ring The ring instance
 * @return      Number of occupied entries within the ring
 * @note        Must not be preempted by: pfe_hif_ring_destroy()
 */
__attribute__((pure, hot)) uint32_t pfe_hif_ring_get_fill_level(const pfe_hif_ring_t *ring)
{
    uint32_t fill_level;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        fill_level = UINT32_MAX;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        /*  In case of HIF NOCPY, the HW does not use external RX buffers but internal
            BMU-provided buffers. Thus the RX ring fill level can't be other value
            than zero. */

        if (TRUE == ring->is_rx)
        {
            fill_level = 0U;
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            if (ring->read_idx <= ring->write_idx)
            {
                fill_level = ring->write_idx - ring->read_idx;
            }
            else
            {
                fill_level = (2U * ring->length) - (ring->read_idx - ring->write_idx);
            }
        }
    }
    return fill_level;
}

/**
 * @brief       Get physical address of the start of the ring
 * @param[in]   ring The ring instance
 * @return      Pointer to the beginning address of the ring
 * @note        Must not be preempted by: pfe_hif_ring_destroy()
 */
__attribute__((pure, cold)) void *pfe_hif_ring_get_base_pa(const pfe_hif_ring_t *ring)
{
    void *base_pa = NULL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        base_pa = ring->base_pa;
    }
    return base_pa;
}

/**
 * @brief       Get physical address of the write-back table
 * @param[in]   ring The ring instance
 * @return      Pointer to the table
 * @note        Must not be preempted by: pfe_hif_ring_destroy()
 */
__attribute__((pure, cold)) void *pfe_hif_ring_get_wb_tbl_pa(const pfe_hif_ring_t *ring)
{
    void *wb_tbl_pa = NULL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        wb_tbl_pa = ring->wb_tbl_base_pa;
    }
    return wb_tbl_pa;
}

/**
 * @brief       Get length of the write-back table
 * @param[in]   ring The ring instance
 * @return      Length of the table in number of entries. Only valid when
 *              pfe_hif_ring_get_wb_tbl_pa() is not NULL.
 * @note        Must not be preempted by: pfe_hif_ring_destroy()
 */
__attribute__((pure, cold)) uint32_t pfe_hif_ring_get_wb_tbl_len(const pfe_hif_ring_t *ring)
{
    uint32_t wb_tbl_len;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        wb_tbl_len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        wb_tbl_len = ring->length;
    }
    return wb_tbl_len;
}

/**
 * @brief        Invalidate the explicit entry in the ring
 * @param[in]    ring The ring instance
 * @param[in]    index The position in the ring
 */
__attribute__((cold)) void pfe_hif_ring_invalidate_direct(const pfe_hif_ring_t *ring, uint32_t index)
{
    /* Clear BD enable flag */
    (&((pfe_hif_bd_t *)ring->base_va)[index])->control.info.desc_en = 0U;

    /* Reset the write-back descriptor */
    (&((pfe_hif_wb_bd_t *)ring->wb_tbl_base_va)[index])->seqnum = 0xffffU;
    (&((pfe_hif_wb_bd_t *)ring->wb_tbl_base_va)[index])->control.info.desc_en = 1U;
}

/**
 * @brief        Revalidate the explicit entry in the ring
 * @param[in]    ring The ring instance
 * @param[in]    index The position in the ring
 * @note        It is expected that BD has valid set-up
 */
__attribute__((cold)) void pfe_hif_ring_revalidate_direct(const pfe_hif_ring_t *ring, uint32_t index)
{
        /* Set BD enable flag */
        (&((pfe_hif_bd_t *)ring->base_va)[index])->control.info.desc_en = 1U;

        /* Set the write-back descriptor */
        (&((pfe_hif_wb_bd_t *)ring->wb_tbl_base_va)[index])->control.info.desc_en = 0U;
}

/**
 * @brief        Set ring to explicit position
 * @param[in]    ring The ring instance
 * @param[in]    index The new position of the ring
 * @return        0 if OK
 */
__attribute__((cold)) errno_t pfe_hif_ring_force_index(pfe_hif_ring_t *ring, uint32_t index)
{
    uint32_t offset;
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    offset = index % ring->length;

    ring->read_idx = offset;
    ring->bd_read.rd_bd = &((pfe_hif_bd_t *)(uint32_t)ring->base_va)[ring->read_idx];
    ring->rd_wb_bd = &((pfe_hif_wb_bd_t *)ring->wb_tbl_base_va)[ring->read_idx];

    ring->write_idx = offset;
    ring->bd_write.wr_bd = ring->bd_read.rd_bd;
    ring->wr_wb_bd = ring->rd_wb_bd;

    return ret;
}

/**
 * @brief        Search for valid entry in WB ring
 * @param[in]    ring The ring instance
 * @param[in]    valid TRUE if searhing for valid entry, FALSE otherwise
 * @param[out]    index The position of found entry in the ring
 * @return        TRUE if found
 * @note        Requires invalidated all entries before search
 */
__attribute__((cold)) errno_t pfe_hif_ring_find_wb_entry(pfe_hif_ring_t *ring, bool_t valid, uint32_t *index)
{
    pfe_hif_wb_bd_t *wb;
    bool_t flag = FALSE;
    uint32_t ring_idx;
    errno_t ret = ENOENT;

    for (ring_idx = 0U; ring_idx < ring->length; ring_idx++)
    {
        wb = &(((pfe_hif_wb_bd_t *)ring->wb_tbl_base_pa)[ring_idx]);

        /* valid entry: WB BD must be DISABLED. The entry was processed by HW */
        if (TRUE == valid)
        {
            if (0U == (wb->control.info.desc_en))
            {
                *index = ring_idx;
                ret = EOK;
                break;
            }
        }

        /* invalid entry: WB BD must be ENABLED. The entry was not touched by HW
         *           For invalid search we need to detect first valid entry
         *           and only then search for invalid. Reason: Invalid search
         *           is used on RX ring, which can contain multiple (cached)
         *           entries.
         */
        if (FALSE == valid)
        {
            if ((TRUE == flag) && (0U != (wb->control.info.desc_en)))
            {
                *index = ring_idx;
                ret = EOK;
                break;
            }
            if ((FALSE == flag) && (0U == (wb->control.info.desc_en)))
            {
                /* Found first valid entry, now we can find invalid one */
                flag = TRUE;
            }
        }
    }

    return ret;
}

/**
 * @brief        Check if the ring is on the head
 * @param[in]    ring The ring instance
 * @return        TRUE if the ring is on the head
 * @note        Must not be preempted by: pfe_hif_ring_destroy()
 */
__attribute__((pure, hot)) bool_t pfe_hif_ring_is_on_head(const pfe_hif_ring_t *ring)
{
    bool_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = (ring->rd_wb_bd == ring->wb_tbl_base_va);
    }
    return ret;
}

/**
 * @brief       Get length of the ring
 * @param[in]   ring The ring instance
 * @return      Ring length in number of entries
 * @note        Must not be preempted by: pfe_hif_ring_destroy()
 */
__attribute__((pure, hot)) uint32_t pfe_hif_ring_get_len(const pfe_hif_ring_t *ring)
{
    uint32_t ring_len = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ring_len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ring_len = ring->length;
    }
    return ring_len;
}

/**
 * @brief       Add buffer to the ring
 * @details     Add buffer at current write position within the ring and increment
 *              the write index. If the current position is already occupied by an
 *              enabled buffer the call will fail.
 * @param[in]   ring The ring instance
 * @param[in]   buf_pa Physical address of buffer to be enqueued
 * @param[in]   length Length of the buffer
 * @param[in]   lmem_header_size Size of the LMEM Header, require for HIF_NOCPY
 * @param[in]   lifm TRUE means that the buffer is last buffer of a frame (last-in-frame)
 * @retval      EOK Success
 * @retval      EIO The slot is already occupied
 * @retval      EPERM Ring is locked and does not accept enqueue requests
 * @note        Must not be preempted by: pfe_hif_ring_destroy()
 */
__attribute__((hot)) errno_t pfe_hif_ring_enqueue_buf(pfe_hif_ring_t *ring, const void *buf_pa, uint32_t length, uint32_t lmem_header_size, bool_t lifm)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if(TRUE == ring->nocpy)
        {
            ret = pfe_hif_ring_enqueue_buf_nocpy(ring, buf_pa, length, lmem_header_size, lifm);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            (void)lmem_header_size;
            ret = pfe_hif_ring_enqueue_buf_std(ring, buf_pa, length, lifm);
        }
    }
    return ret;
}

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief       The HIF NOCPY variant
 * @param[in]   buf_pa This must be BMU2 allocated physical address
 */
__attribute__((hot)) static inline errno_t pfe_hif_ring_enqueue_buf_nocpy(pfe_hif_ring_t *ring, const void *buf_pa, uint32_t length, uint32_t lmem_header_size, bool_t lifm)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == ring) || (NULL == buf_pa)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (unlikely(ring->is_rx))
        {
            NXP_LOG_ERROR("There is nothing to enqueue into RX ring in case of HIF NOCPY\n");
            ret = EPERM;
        }
        else
        {
            /*  Write the HW BD. Always write all control word bits since
                 the HIF NOCPY is clearing the flags once BD is processed... */
            ring->bd_write.wr_bd_nocpy->data = (uint32_t)((addr_t)(PFE_CFG_MEMORY_PHYS_TO_PFE(buf_pa)) & 0xffffffffU);
            ring->bd_write.wr_bd_nocpy->control.w0.tx_buflen = (uint16_t)length;
            /* Fill the rest of the LMEM buffer by packet data (copy useful data after the LMEM header) */
            ring->bd_write.wr_bd_nocpy->status.w0.tx_lmem_buflen =
                        (uint16_t)(((PFE_CFG_LMEM_BUF_SIZE - lmem_header_size) < length)
                                  ? (PFE_CFG_LMEM_BUF_SIZE - lmem_header_size)
                                  : length);
            ring->bd_write.wr_bd_nocpy->status.w1.tx.dst_buf_offset = (uint16_t)lmem_header_size;
            ring->bd_write.wr_bd_nocpy->status.w1.tx.src_buf_offset = (uint16_t)(256U + lmem_header_size);
            /* Request the LMEM copy mode */
            ring->bd_write.wr_bd_nocpy->control.w1.info.lmem_cpy = 1U;
            ring->bd_write.wr_bd_nocpy->control.w1.info.pkt_xfer = 1U;

            if (lifm)
            {
                ring->bd_write.wr_bd_nocpy->control.w1.info.lifm = 1U;
            }
            else
            {
                ring->bd_write.wr_bd_nocpy->control.w1.info.lifm = 0U;
            }

            /*  Write the BD 'enable' bit */
            ring->bd_write.wr_bd_nocpy->control.w1.info.desc_en = 1U;
            /*  Increment the write pointer */
            inc_write_index(ring);
            ret = EOK;
        }
    }

    return ret;
}
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/**
 * @brief       The "standard" HIF variant
 */
__attribute__((hot)) static inline errno_t pfe_hif_ring_enqueue_buf_std(pfe_hif_ring_t *ring, const void *buf_pa, uint32_t length, bool_t lifm)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == ring) || (NULL == buf_pa)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (unlikely(0U != ring->bd_write.wr_bd->control.info.desc_en))
        {
            NXP_LOG_ERROR("Can't insert buffer since the BD entry is already used\n");
            ret = EIO;
        }
        else
        {
            /*  Write the HW BD */
            ring->bd_write.wr_bd->data = (uint32_t)((addr_t)PFE_CFG_MEMORY_PHYS_TO_PFE(buf_pa) & 0xffffffffU);
            ring->bd_write.wr_bd->buflen = (uint16_t)(length & (uint32_t)UINT16_MAX);
            ring->bd_write.wr_bd->check.status = 0U;

            if (lifm)
            {
                ring->bd_write.wr_bd->control.info.lifm = 1U;
            }
            else
            {
                ring->bd_write.wr_bd->control.info.lifm = 0U;
            }

#ifdef EQ_DQ_RX_DEBUG
            if (ring->is_rx)
            {
                NXP_LOG_INFO("EQ: IDX:%02d, BD@p0x%p, WB@p0x%p, BUF@p0x%p\n",
                    (ring->write_idx % ring->length),
                    (void *)((addr_t)ring->wr_bd - ((addr_t)ring->base_va - (addr_t)ring->base_pa)),
                    (void *)((addr_t)ring->wr_wb_bd - ((addr_t)ring->wb_tbl_base_va - (addr_t)ring->wb_tbl_base_pa)),
                    (void *)buf_pa);
            }
#endif /* EQ_DQ_RX_DEBUG */

            /*  Write the BD 'enable' bit */
            ring->wr_wb_bd->control.info.desc_en = 1U;
            hal_wmb();
            ring->bd_write.wr_bd->control.info.desc_en = 1U;

            /*  Increment the write pointer */
            inc_write_index(ring);
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief       Dequeue buffer form the ring
 * @details     Remove next buffer from the ring and increment the read index. If the
 *              buffer is empty then the call fails and no operation is performed.
 * @param[in]   ring The ring instance
 * @param[out]  buf_pa Pointer where pointer to the dequeued buffer shall be written
 * @param[out]  length Pointer where length of the buffer shall be written
 * @param[out]  lifm Pointer where last-in-frame information shall be written
 * @retval      EOK Buffer dequeued
 * @retval      EAGAIN Current BD is busy
 * @note        Must not be preempted by: pfe_hif_ring_destroy()
 */
__attribute__((hot)) errno_t pfe_hif_ring_dequeue_buf(pfe_hif_ring_t *ring, void **buf_pa, uint32_t *length, bool_t *lifm)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        ret = pfe_hif_ring_dequeue_buf_nocpy(ring, buf_pa, length, lifm);
#else
        ret = pfe_hif_ring_dequeue_buf_std(ring, buf_pa, length, lifm);
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    }
    return ret;
}

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief       The HIF NOCPY variant
 */
__attribute__((hot)) static inline errno_t pfe_hif_ring_dequeue_buf_nocpy(pfe_hif_ring_t *ring, void **buf_pa, uint32_t *length, bool_t *lifm)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == ring) || (NULL == buf_pa) || (NULL == length) || (NULL == lifm)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (0U != ring->bd_read.rd_bd_nocpy->control.w1.info.pkt_xfer)
        {
            ret = EAGAIN;
        }
        else
        {
            *buf_pa = (void *)(addr_t)PFE_CFG_MEMORY_PFE_TO_PHYS(ring->bd_read.rd_bd_nocpy->data);

            if (ring->is_rx)
            {
                *length = ring->bd_read.rd_bd_nocpy->status.w0.rx_buflen;
            }
            else
            {
                *length = ring->bd_read.rd_bd_nocpy->control.w0.tx_buflen;
            }

            *lifm = (0U != ring->bd_read.rd_bd_nocpy->control.w1.info.lifm);

            /*  Re-enable the descriptor so HIF can write another RX buffer there */
            ring->bd_read.rd_bd_nocpy->control.w1.info.pkt_xfer = 1U;
            ring->bd_read.rd_bd_nocpy->control.w1.info.desc_en = 1U;
            /*  Must clear also lifm flag to prepare BD for next use */
            ring->bd_read.rd_bd_nocpy->control.w1.info.lifm = 0U;

            /*  Increment the read pointer */
            inc_read_index(ring);
            ret = EOK;
        }
    }

    return ret;
}
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

#if !defined(PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief       The "standard" HIF variant
 */
__attribute__((hot)) static inline errno_t pfe_hif_ring_dequeue_buf_std(pfe_hif_ring_t *ring, void **buf_pa, uint32_t *length, bool_t *lifm)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == ring) || (NULL == buf_pa) || (NULL == length) || (NULL == lifm)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if ((0U == ring->bd_read.rd_bd->control.info.desc_en) || (0U != ring->rd_wb_bd->control.info.desc_en))
        {
            ret = EAGAIN;
        }
        else /* 1 == ring->rd_bd->desc_en && 0 == ring->rd_wb_bd->desc_en */
        {
            /*  Reset BD and WB BD enable flag. It is ensured that the current BD will not be reused
                again until desc_en is reset since sequence number will become not sequential and
                thus the BD is not valid. */
            ring->bd_read.rd_bd->control.info.desc_en = 0U;
            ring->rd_wb_bd->control.info.desc_en = 1U;
            hal_wmb();

            *buf_pa = (void *)(addr_t)PFE_CFG_MEMORY_PFE_TO_PHYS(ring->bd_read.rd_bd->data);

#ifdef EQ_DQ_RX_DEBUG
            if (ring->is_rx)
            {
                NXP_LOG_INFO("DQ: IDX:%02d, BD@p0x%p, WB@p0x%p, BUF@p0x%p\n",
                    (ring->read_idx % ring->length),
                    (void *)((addr_t)ring->rd_bd - ((addr_t)ring->base_va - (addr_t)ring->base_pa)),
                    (void *)((addr_t)ring->rd_wb_bd - ((addr_t)ring->wb_tbl_base_va - (addr_t)ring->wb_tbl_base_pa)),
                    (void *)*buf_pa);
            }
#endif /* EQ_DQ_RX_DEBUG */

            *length = ring->rd_wb_bd->buflen;
            *lifm = (0U != ring->rd_wb_bd->control.info.lifm);
            /*  Increment the read pointer */
            inc_read_index(ring);
            ret = EOK;
        }
    }
    return ret;
}
#endif /* !PFE_CFG_HIF_NOCPY_SUPPORT */

/**
 * @brief       Dequeue buffer from the ring without response
 * @details     Remove next buffer from the ring and increment the read index. If the
 *              buffer is empty then the call fails and no operation is performed. Can
 *              be used to receive TX confirmations.
 * @param[in]   ring The ring instance
 * @param[out]  lifm Pointer where last-in-frame information shall be written
 * @param[out]  len Number of transmitted bytes
 * @retval      EOK Buffer dequeued
 * @retval      EAGAIN Current BD is busy
 * @note        Must not be preempted by: pfe_hif_ring_destroy()
 */
__attribute__((hot)) errno_t pfe_hif_ring_dequeue_plain(pfe_hif_ring_t *ring, bool_t *lifm)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if(TRUE == ring->nocpy)
        {
            ret = pfe_hif_ring_dequeue_plain_nocpy(ring, lifm);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            ret = pfe_hif_ring_dequeue_plain_std(ring, lifm);
        }
    }
    return ret;
}

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief       The HIF NOCPY variant
 */
__attribute__((hot)) static errno_t pfe_hif_ring_dequeue_plain_nocpy(pfe_hif_ring_t *ring, bool_t *lifm)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (1U == ring->bd_read.rd_bd_nocpy->control.w1.info.pkt_xfer)
        {
            /*  Nothing to dequeue */
            ret = EAGAIN;
        }
        else
        {
            /*
                Return the LIFM flag

                 HIF NOCPY TX BDP will always overwrite the BD so the LIFM
                flag will be set to zero (very smart...). It must be ensured
                that the HIF NOCPY ring will be used in the one-frame=one-BD
                manner.
            */
            *lifm = TRUE;

            /*  Clear the 'TX done' flag */
            ring->bd_read.rd_bd_nocpy->control.w1.info.pkt_xfer = 1U;
            ring->bd_read.rd_bd_nocpy->control.w1.info.desc_en = 0U;

            /*  Increment the read pointer */
            inc_read_index(ring);
            ret = EOK;
        }
    }

    return ret;
}
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/**
 * @brief       The "standard" HIF variant
 */
__attribute__((hot)) static inline errno_t pfe_hif_ring_dequeue_plain_std(pfe_hif_ring_t *ring, bool_t *lifm)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if ((0U == ring->bd_read.rd_bd->control.info.desc_en) || (0U != ring->rd_wb_bd->control.info.desc_en))
        {
            ret = EAGAIN;
        }
        else
        {
            /*  Return LIFM */
            *lifm = (0U != ring->bd_read.rd_bd->control.info.lifm);

            /*  Reset BD and WB BD enable flag. It is ensured that the current BD will not be reused
                again until desc_en is reset since sequence number will become not sequential and
                thus the BD is not valid. */
            ring->bd_read.rd_bd->control.info.desc_en = 0U;
            ring->rd_wb_bd->control.info.desc_en = 1U;
            hal_wmb();

            /*  Increment the read pointer */
            inc_read_index(ring);
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief       Drain buffer from ring
 * @details     This call dequeues previously enqueued buffer from a ring regardless it
 *              has been processed by the HW or not. Function is intended to properly
 *              shut-down the ring in terms of possibility to retrieve all currently
 *              enqueued entries.
 * @param[in]   ring The ring instance
 * @param[out]  buf_pa buf_pa Pointer where pointer to the dequeued buffer shall be written
 * @retval      EOK Buffer has been dequeued
 * @retval      ENOENT No more buffers in the ring
 */
__attribute__((cold)) errno_t pfe_hif_ring_drain_buf(pfe_hif_ring_t *ring, void **buf_pa)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == ring) || (NULL == buf_pa)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (ring->is_rx)
        {
            bool_t lifm;

            /*  In this case we will do dequeue without enable until the ring is empty. This
                will ensure that application can drain RX buffers and return all BMU
                buffers back to the HW pool. */
            *buf_pa = (void *)PFE_CFG_MEMORY_PFE_TO_PHYS(ring->bd_read.rd_bd_nocpy->data);
            if (EOK == pfe_hif_ring_dequeue_plain_nocpy(ring, &lifm))
            {
                ret = EOK;
            }
            else
            {
                ret = ENOENT;
            }
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            if (0U != pfe_hif_ring_get_fill_level(ring))
            {
                /*  In case of RX ring this will return enqueued RX buffer. In
                    case of TX ring the enqueued TX buffer will be returned. */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
                *buf_pa = (void *)PFE_CFG_MEMORY_PFE_TO_PHYS(ring->bd_read.rd_bd_nocpy->data);
                ring->bd_read.rd_bd_nocpy->control.w1.info.desc_en = 0U;
                inc_read_index(ring);
#else /* PFE_CFG_HIF_NOCPY_SUPPORT */
                /*  Draining introduces sequence number corruption. Every enqueued
                    BD increments sequence number in SW and every processed BD
                    increments it in HW. In case when non-processed BDs are dequeued
                    the new ones will be enqueued with sequence number not matching
                    the current HW one. We need to adjust the SW value when draining
                    non-processed BDs. */
                if (0U != ring->wr_wb_bd->control.info.desc_en)
                {
                    /*  This BD has not been processed yet. Revert the enqueue. */
                    *buf_pa = (void *)PFE_CFG_MEMORY_PFE_TO_PHYS(ring->bd_write.wr_bd->data);
                    ring->bd_write.wr_bd->control.info.desc_en = 0U;
                    ring->wr_wb_bd->control.info.desc_en = 1U;
                    dec_write_index_std(ring);
                }
                else
                {
                    /*  Processed BD. Do standard dequeue. */
                    *buf_pa = (void *)PFE_CFG_MEMORY_PFE_TO_PHYS(ring->bd_read.rd_bd->data);
                    ring->bd_read.rd_bd->control.info.desc_en = 0U;
                    ring->rd_wb_bd->control.info.desc_en = 1U;
                    inc_read_index(ring);
                }
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
                ret = EOK;
            }
            else
            {
                ret = ENOENT;
            }
        }
    }
    return ret;
}

/**
 * @brief       Invalidate the ring
 * @details     Disable all buffer descriptors in the ring
 * @param[in]   ring The ring instance
 * @note        Must not be preempted by: pfe_hif_ring_enqueue_buf(), pfe_hif_ring_destroy()
 */
__attribute__((cold)) void pfe_hif_ring_invalidate(const pfe_hif_ring_t *ring)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if(TRUE == ring->nocpy)
        {
            pfe_hif_ring_invalidate_nocpy(ring);
        }
        else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
        {
            pfe_hif_ring_invalidate_std(ring);
        }
    }
}

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief       The HIF NOCPY variant
 */
__attribute__((cold)) static void pfe_hif_ring_invalidate_nocpy(const pfe_hif_ring_t *ring)
{
    uint32_t ii;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (ii=0U; ii < ring->length; ii++)
        {
            /*  Zero-out the EN flag */
            (((pfe_hif_nocpy_bd_t *)ring->base_va)[ii]).control.w1.info.desc_en = 0U;
        }
    }
}
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/**
 * @brief       The "standard" HIF variant
 */
__attribute__((cold)) static void pfe_hif_ring_invalidate_std(const pfe_hif_ring_t *ring)
{
    uint32_t ii;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (ii=0U; ii<ring->length; ii++)
        {
            /*  Zero-out the EN flag */
            (((pfe_hif_bd_t *)ring->base_va)[ii]).control.info.desc_en = 0U;

            /*  Reset the write-back descriptor */
            (((pfe_hif_wb_bd_t *)ring->wb_tbl_base_va)[ii]).control.info.desc_en = 1U;
        }
    }
}

/**
 * @brief       Dump of HW rings
 * @details     Dumps particular ring
 * @param[in]   ring The ring instance
 * @param[in]   name The ring name
 * @note        Must not be preempted by: pfe_hif_ring_enqueue_buf(), pfe_hif_ring_destroy()
 */
__attribute__((cold)) void pfe_hif_ring_dump(const pfe_hif_ring_t *ring, const char_t *name)
{
#ifdef NXP_LOG_ENABLED
    uint32_t ii;
    const char_t *idx_str;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == ring) || (NULL == name)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        NXP_LOG_INFO("Ring %s: len %u\n", name, (uint_t)ring->length);
        NXP_LOG_INFO("  Type: %s\n", ring->is_rx ? "RX" : "TX");
        NXP_LOG_INFO("  Index w/r: %u/%u (%u/%u)\n", (uint_t)(ring->write_idx % ring->length), (uint_t)(ring->read_idx % ring->length), (uint_t)ring->write_idx, (uint_t)ring->read_idx);

        /* BD ring */
        for (ii=0U; ii < ring->length; ii++)
        {
            pfe_hif_bd_t *bd = &(((pfe_hif_bd_t *)ring->base_va)[ii]);

            if (0U == ii)
            {
                NXP_LOG_INFO("  BD va/pa v0x%p/p0x%p\n", ring->base_va, ring->base_pa);
                NXP_LOG_INFO("    pa:      idx: bufl:ctrl: status :  data  :  next :seqn\n");
            }

            if ((ring->write_idx % ring->length) == ii)
            {
                idx_str = "<-- WR";
            }
            else if ((ring->read_idx % ring->length) == ii)
            {
                idx_str = "<-- RD";
            }
            else
            {
                idx_str = "";
            }

            NXP_LOG_INFO("    p0x%p%5u: %04x:%04x:%08x:%08x:%08x%s\n",(void *)&((pfe_hif_bd_t *)ring->base_pa)[ii], (uint_t)ii, bd->buflen, bd->control.ctrl, bd->check.status, (uint_t)PFE_CFG_MEMORY_PFE_TO_PHYS(bd->data), (uint_t)bd->next, idx_str);
        }

        /* WB ring */
#if !defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        for (ii=0U; ii < ring->length; ii++)
        {
            pfe_hif_wb_bd_t *wb = &(((pfe_hif_wb_bd_t *)ring->wb_tbl_base_va)[ii]);

            if (0U == ii)
            {
                NXP_LOG_INFO("  WB va/pa v0x%p/p0x%p\n", ring->wb_tbl_base_va, ring->wb_tbl_base_pa);
                NXP_LOG_INFO("    pa:      idx:  ctl: rsvd :bufl:seqn\n");
            }

            if ((ring->read_idx % ring->length) == ii)
            {
                idx_str = "<-- RD";
            }
            else
            {
                idx_str = "";
            }

            NXP_LOG_INFO("    p0x%p%5u: %04x:%06x:%04x%s\n", (void *)&((pfe_hif_wb_bd_t *)ring->wb_tbl_base_pa)[ii], (uint_t)ii, wb->control.ctrl.ctrl,  wb->control.ctrl.rsvd, wb->buflen, idx_str);
        }
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    }
#else
        (void) name; (void) ring;/* Not used in this implementation */
#endif /* NXP_LOG_ENABLED */
}

/**
 * @brief          Create new PFE buffer descriptor ring using dedicated MCAL memory and MCAL channel type
 * @param[inout]   ring Pointer to BD ring
 * @param[in]      length Ring length
 * @param[in]      rx If TRUE the ring is RX, if FALSE the the ring is TX
 * @return         EOK if success, error code otherwise
 * @note           Must not be preempted by any of the remaining API functions
 */
__attribute__((cold)) errno_t pfe_hif_ring_create_mcal(pfe_hif_ring_t *ring, uint32_t length, bool_t rx)
{
    errno_t ret_val;
    void *ring_va = NULL;
#if !defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    void *wb_ring_va;
#endif

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret_val = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Assign static memory for buffer descriptors (and write-back descriptors) */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        if (TRUE == rx)
        {
            if (likely(length <= ETH_43_PFE_MAX_RXBD_CNT))
            {
                ring_va = (void *)&arRxBdRing;
            }
        }
        else
        {
            if (likely(length <= ETH_43_PFE_MAX_TXBD_CNT))
            {
                ring_va = (void *)&arTxBdRing;
            }
        }
#else
        if (TRUE == rx)
        {
            if (likely(length <= ETH_43_PFE_MAX_RXBD_CNT))
            {
                ring_va = (void *)&arRxBdRing;
                wb_ring_va = (void *)&arRxBdWbRing;
            }
        }
        else
        {
            if (likely(length <= ETH_43_PFE_MAX_TXBD_CNT))
            {
                ring_va = (void *)&arTxBdRing;
                wb_ring_va = (void *)&arTxBdWbRing;
            }
        }
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

        if(NULL == ring_va)
        {
            NXP_LOG_ERROR("%s BD memory is too small\n", ((TRUE == rx) ? "Rx" : "Tx"));
            ret_val = EINVAL;
        }
        else
        {
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            ret_val = pfe_hif_ring_create_nocpy(ring, ring_va, length, rx);
#else
            ret_val = pfe_hif_ring_create_std(ring, ring_va, wb_ring_va, length, rx);
#endif
        }
    }

    return ret_val;
}

/**
 * @brief          Create new PFE buffer descriptor ring using provided memory pointers
 * @param[inout]   ring Pointer to BD ring
 * @param[in]      ring_va Pointer to BD ring memory
 * @param[in]      wb_ring_va Pointer to WB_BD ring memory
 * @param[in]      length Ring length
 * @param[in]      rx If TRUE the ring is RX, if FALSE the the ring is TX
 * @return         EOK if success, error code otherwise
 * @note           Must not be preempted by any of the remaining API functions
 */
__attribute__((cold)) errno_t pfe_hif_ring_create_minihif(pfe_hif_ring_t *ring, void *ring_va, void *wb_ring_va, uint32_t length, bool_t rx)
{
    errno_t ret_val;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == ring) || (NULL == ring_va) || (NULL == wb_ring_va)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret_val = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret_val = pfe_hif_ring_create_std(ring, ring_va, wb_ring_va, length, rx);
    }

    return ret_val;
}

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief       The HIF NOCPY variant
 * @note        Used only for MCAL
 */
__attribute__((cold)) static errno_t pfe_hif_ring_create_nocpy(pfe_hif_ring_t *ring, void *ring_va, uint32_t length, bool_t rx)
{
    errno_t ret_val = EINVAL;

    /*  Initialize ring structure, includes some checks */
    ret_val = pfe_hif_ring_init_ring_nocpy(ring, ring_va, length, rx);

    if (EOK != ret_val)
    {
        NXP_LOG_ERROR("Can't attach ring\n");
    }
    else
    {
        /*  Initialize the values in buffer descriptors */
        pfe_hif_ring_init_bd_nocpy(ring);

        NXP_LOG_DEBUG("%s ring created. %u entries.\nBD @ p0x%p/v0x%p.\n",
                        (ring->is_rx) ? "RX" : "TX",
                        (uint_t)ring->length,
                        (void *)ring->base_pa,
                        (void *)ring->base_va);
    }
    return ret_val;
}
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/**
 * @brief       The "standard" HIF variant
 * @note        Used both for MCAL and for minihif.
 */
__attribute__((cold)) static errno_t pfe_hif_ring_create_std(pfe_hif_ring_t *ring, void *ring_va, void *wb_ring_va, uint32_t length, bool_t rx)
{
    errno_t ret_val = EINVAL;

    PfeDevAssert((SIZE_MAX / sizeof(pfe_hif_bd_t)) >= length);
    (void)autolibc_memset(ring_va, 0, (length * sizeof(pfe_hif_bd_t)));
    (void)autolibc_memset(wb_ring_va, 0, (length * sizeof(pfe_hif_wb_bd_t)));

    /*  Initialize ring structure, includes some checks */
    ret_val = pfe_hif_ring_init_ring_std(ring, ring_va, wb_ring_va, length, rx);

    if (EOK != ret_val)
    {
        NXP_LOG_ERROR("Can't init ring\n");
    }
    else
    {
        /*  Initialize the values in buffer descriptors */
        pfe_hif_ring_init_bd_std(ring);

        NXP_LOG_DEBUG("%s ring created. %u entries.\nBD @ p0x%p/v0x%p.\nWB @ p0x%p/v0x%p.\n",
                        (ring->is_rx) ? "RX" : "TX",
                        (uint_t)ring->length,
                        (void *)ring->base_pa,
                        (void *)ring->base_va,
                        (void *)ring->wb_tbl_base_pa,
                        (void *)ring->wb_tbl_base_va);
    }
    return ret_val;
}

/**
 * @brief       The "standard" HIF variant
 */
__attribute__((cold)) static errno_t pfe_hif_ring_init_ring_std(pfe_hif_ring_t *ring, void *ring_va, void *wb_ring_va, uint32_t length, bool_t is_rx)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == ring_va) || (NULL == wb_ring_va)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* It shall be ensured that a single BD does not split across 4k boundary, minimum alignment is 8 */
        if (0U != ((addr_t)ring_va % sizeof(pfe_hif_bd_t)))
        {
            NXP_LOG_ERROR("Buffer descriptors are not aligned\n");
            ret = EINVAL;
        }
        else if (0U != ((addr_t)wb_ring_va % sizeof(pfe_hif_wb_bd_t)))
        {
            NXP_LOG_ERROR("Write-back descriptors are not aligned\n");
            ret = EINVAL;
        }
        else
        {

            /*  Just a debug check */
            if (((addr_t)&ring->heavy_data_mark - (addr_t)ring) > HAL_CACHE_LINE_SIZE)
            {
                NXP_LOG_DEBUG("Suboptimal: Data split between two cache lines\n");
            }

            (void)autolibc_memset(ring, 0, sizeof(pfe_hif_ring_t));
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            ring->nocpy = FALSE;
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
            ring->base_va = ring_va;
            ring->base_pa = oal_mm_virt_to_phys_contig(ring->base_va);
            ring->wb_tbl_base_va = wb_ring_va;
            ring->wb_tbl_base_pa = oal_mm_virt_to_phys_contig(ring->wb_tbl_base_va);
            ring->length = length;
            ring->write_idx = 0U;
            ring->read_idx = 0U;
            ring->is_rx = is_rx;
            ring->bd_read.rd_bd = (pfe_hif_bd_t *)ring->base_va;
            ring->bd_write.wr_bd = (pfe_hif_bd_t *)ring->base_va;

            ring->rd_wb_bd = (pfe_hif_wb_bd_t *)ring->wb_tbl_base_va;
            ring->wr_wb_bd = (pfe_hif_wb_bd_t *)ring->wb_tbl_base_va;
            ret = EOK;
        }
    }

    return ret;
}
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief       The nocopy HIF variant
 */
__attribute__((cold)) static errno_t pfe_hif_ring_init_ring_nocpy(pfe_hif_ring_t *ring, void *ring_va, uint32_t length, bool_t is_rx)
{
    void *ring_pa = ring_va;
    uint32_t ring_size = length * sizeof(pfe_hif_nocpy_bd_t);
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == ring_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* It shall be ensured that a single BD does not split across 4k boundary, minimum alignment is 8 */
        if (0U != ((addr_t)ring_pa % sizeof(pfe_hif_nocpy_bd_t)))
        {
            NXP_LOG_ERROR("Buffer descriptors are not aligned\n");
            ret = EINVAL;
        }
        else
        {
            /*  S32G HIFNCPY AXI MASTER can only access range 0x00000000 - 0xbfffffff */
            if (unlikely((((addr_t)ring_pa) + ring_size) >= (addr_t)0xBFFFFFFFU))
            {
                NXP_LOG_WARNING("Descriptor ring memory not in required range: starts @ p0x%p\n", ring_pa);
            }

            /*  Just a debug check */
            if (((addr_t)&ring->heavy_data_mark - (addr_t)ring) > HAL_CACHE_LINE_SIZE)
            {
                NXP_LOG_DEBUG("Suboptimal: Data split between two cache lines\n");
            }

            (void)autolibc_memset(ring, 0, sizeof(pfe_hif_ring_t));
            ring->nocpy = TRUE;
            ring->base_va = ring_va;
            ring->base_pa = ring_pa;
            ring->wb_tbl_base_va = NULL;
            ring->wb_tbl_base_pa = NULL;
            ring->length = length;
            ring->write_idx = 0U;
            ring->read_idx = 0U;
            ring->is_rx = is_rx;
            ring->bd_read.rd_bd_nocpy = (pfe_hif_nocpy_bd_t *)ring->base_va;
            ring->bd_write.wr_bd_nocpy = (pfe_hif_nocpy_bd_t *)ring->base_va;
            ring->rd_wb_bd = NULL;
            ret = EOK;
        }
    }

    return ret;
}
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/**
 * @brief       Initialize the values in "standard" buffer descriptors
 */
__attribute__((cold)) static void pfe_hif_ring_init_bd_std(const pfe_hif_ring_t *ring)
{
    pfe_hif_bd_t *hw_desc_va;
    const pfe_hif_bd_t *hw_desc_pa;
    pfe_hif_wb_bd_t *wb_bd_va;
    uint32_t ii;

    /*  Initialize descriptors */
    PfeDevAssert((UINT32_MAX / sizeof(pfe_hif_bd_t)) >= ring->length);
    (void)autolibc_memset(ring->base_va, 0, ring->length * sizeof(pfe_hif_bd_t));

    /*  Chain the buffer descriptors */
    hw_desc_va = (pfe_hif_bd_t *)ring->base_va;
    hw_desc_pa = (pfe_hif_bd_t *)ring->base_pa;

    for (ii=0; ii < ring->length; ii++)
    {
        if (TRUE == ring->is_rx)
        {
            /*  Mark BD as RX */
            hw_desc_va[ii].control.info.dir = 1U;
        }

        /*  Enable BD interrupt */
        hw_desc_va[ii].control.info.cbd_int_en = 1U;
        hw_desc_va[ii].next = (uint32_t)((addr_t)PFE_CFG_MEMORY_PHYS_TO_PFE(&hw_desc_pa[ii + 1U]) & 0xffffffffU);
    }

    /*  Chain last one with the first one */
    hw_desc_va[ii-1U].next = (uint32_t)((addr_t)PFE_CFG_MEMORY_PHYS_TO_PFE(&hw_desc_pa[0]) & 0xffffffffU);
    hw_desc_va[ii-1U].control.info.last_bd = 1U;

    /*  Initialize write-back descriptors */
    (void)autolibc_memset(ring->wb_tbl_base_va, 0, ring->length * sizeof(pfe_hif_wb_bd_t));

    wb_bd_va = (pfe_hif_wb_bd_t *)ring->wb_tbl_base_va;
    for (ii=0U; ii<ring->length; ii++)
    {
        /*  Initialize WB BD descriptor enable flag. Once descriptor is processed,
            the PFE HW will clear it. */
        wb_bd_va->control.info.desc_en = 1U;
        wb_bd_va++;
    }

    /*  Flush the cache */
    oal_mm_cache_flush(ring->wb_tbl_base_va, ring->wb_tbl_base_pa, ring->length * sizeof(pfe_hif_wb_bd_t));

    /*  Invalidate the cache over the first descriptor so next attempt to access
         it (enqueue/dequeue) will result in a cache miss. Further descriptors are
        treated using the prefetch approach. */
    oal_mm_cache_inval(ring->base_va, ring->base_pa, sizeof(pfe_hif_wb_bd_t));
}

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief       Initialize the values in nocopy buffer descriptors
 */
__attribute__((cold)) static void pfe_hif_ring_init_bd_nocpy(const pfe_hif_ring_t *ring)
{
    pfe_hif_nocpy_bd_t *hw_desc_va;
    const pfe_hif_nocpy_bd_t *hw_desc_pa;
    uint32_t ii;

    /*  Initialize memory */
    (void)autolibc_memset(ring->base_pa, 0, ring->length * sizeof(pfe_hif_nocpy_bd_t));

    /*  Chain the buffer descriptors */
    hw_desc_va = (pfe_hif_nocpy_bd_t *)ring->base_pa;
    hw_desc_pa = (pfe_hif_nocpy_bd_t *)ring->base_pa;

    for (ii=0; ii < ring->length; ii++)
    {
        if (TRUE == ring->is_rx)
        {
            /*  Mark BD as RX */
            hw_desc_va[ii].control.w1.info.dir = 0U;
            /*  Enable the descriptor */
            hw_desc_va[ii].control.w1.info.desc_en = 1U;
            hw_desc_va[ii].control.w1.info.pkt_xfer = 1U;
        }
        else
        {
            hw_desc_va[ii].control.w1.info.dir = 1U;
            hw_desc_va[ii].control.w1.info.desc_en = 0U;
            hw_desc_va[ii].control.w1.info.pkt_xfer = 1U;
        }

        /*  Enable BD interrupt */
        hw_desc_va[ii].control.w1.info.cbd_int_en = 1U;

        hw_desc_va[ii].next = (uint32_t)((addr_t)(&hw_desc_pa[ii + 1U]) & 0xffffffffU);
    }

    /*  Chain last one with the first one */
    hw_desc_va[ii-1U].next = (uint32_t)((addr_t)(&hw_desc_pa[0]) & 0xffffffffU);
    hw_desc_va[ii-1U].control.w1.info.last_bd = 1U;
}
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/**
 * @brief       Destroy BD ring
 * @param[in]   ring The ring instance
 * @note        Must not be preempted by any of the remaining API functions
 */
__attribute__((cold)) errno_t pfe_hif_ring_destroy(pfe_hif_ring_t *ring)
{
    if ((NULL != ring) && (NULL != ring->base_va))
    {
        pfe_hif_ring_invalidate(ring);
        ring->base_va = NULL;
        ring->wb_tbl_base_va = NULL;
    }

    return EOK;
}

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */
