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

#ifndef PUBLIC_PFE_HIF_RING_H_
#define PUBLIC_PFE_HIF_RING_H_

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

#include "hal.h"

/**
 * @brief   The BD as seen by HIF
 * @details Properly pack to form the structure as expected by HIF.
 * @note    Don't use the 'aligned' attribute here since behavior
 *          is implementation-specific (due to the bitfields). Still
 *          applies that BD shall be aligned to 64-bits and in
 *          ideal case to cache line size.
 * @warning Do not touch the structure (even types) unless you know
 *          what you're doing.
 */
typedef struct __attribute__((packed))
{
    volatile uint16_t seqnum; /* Not used */
    union
    {
        volatile uint16_t ctrl;
        struct
        {
            volatile uint16_t pkt_int_en    : 1; /* LSB */
            volatile uint16_t cbd_int_en    : 1;
            volatile uint16_t lifm          : 1;
            volatile uint16_t last_bd       : 1;
            volatile uint16_t dir           : 1;
            volatile uint16_t reserved      : 10;
            volatile uint16_t desc_en       : 1; /* MSB */
        } info;
    } control;
    volatile uint16_t buflen;
    union
    {
        volatile uint16_t rsvd;
        volatile uint16_t status;   /* Due to backwards compatibility */
    } check;
    volatile uint32_t data;
    volatile uint32_t next;
} pfe_hif_bd_t;

/**
 * @brief   The write-back BD as seen by HIF
 * @note    Don't use the 'aligned' attribute here since behavior
 *          is implementation-specific (due to the bitfields). Still
 *          applies that BD shall be aligned to 64-bits and in
 *          ideal case to cache line size.
 * @warning Do not touch the structure (even types) unless you know
 *          what you're doing.
 */
typedef struct __attribute__((packed))
{
    union
    {
        struct
        {
            volatile uint32_t ctrl: 11;
            volatile uint32_t rsvd: 21;
        } ctrl;

        struct
        {
            volatile uint32_t reserved      : 4;
            volatile uint32_t cbd_int_en    : 1;
            volatile uint32_t pkt_int_en    : 1;
            volatile uint32_t lifm          : 1;
            volatile uint32_t last_bd       : 1;
            volatile uint32_t dir           : 1;
            volatile uint32_t desc_en       : 1;
            volatile uint32_t reserved1     : 1;
            volatile uint32_t reserved2     : 21;
        } info;
    } control;

    volatile uint16_t buflen;
    volatile uint16_t seqnum;
} pfe_hif_wb_bd_t;

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
/**
 * @brief   The BD as seen by HIF NOCPY
 * @details Properly pack to form the structure as expected by HIF NOCPY.
 * @note    Don't use the 'aligned' attribute here since behavior
 *          is implementation-specific (due to the bitfields). Still
 *          applies that BD shall be aligned to 64-bits and in
 *          ideal case to cache line size.
 * @warning Do not touch the structure (even types) unless you know
 *          what you're doing.
 */
typedef struct __attribute__((packed))
{
    struct
    {
        union
        {
            volatile uint16_t rx_reserved;
            volatile uint16_t tx_buflen;
        } w0;

        union
        {
            volatile uint16_t ctrl;
            struct
            {
                volatile uint16_t cbd_int_en    : 1;
                volatile uint16_t pkt_int_en    : 1;
                volatile uint16_t lifm          : 1;
                volatile uint16_t last_bd       : 1;    /*  Not used */
                volatile uint16_t dir           : 1;
                volatile uint16_t lmem_cpy      : 1;
                volatile uint16_t reserved1     : 2;
                volatile uint16_t pkt_xfer      : 1;
                volatile uint16_t reserved2     : 6;
                volatile uint16_t desc_en       : 1;
            } info;
        } w1;
    } control;

    struct
    {
        union
        {
            volatile uint16_t rx_buflen;
            volatile uint16_t tx_lmem_buflen;
        } w0;

        union
        {
            volatile uint16_t rx_portno;
            struct
            {
                uint16_t dst_buf_offset : 7;
                uint16_t src_buf_offset : 9;
            } tx;
        } w1;
    } status;

    volatile uint32_t data;
    volatile uint32_t next;
} pfe_hif_nocpy_bd_t;
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */

/**
 * @brief   The BD ring structure
 * @note    The attribute 'aligned' is here just to ensure proper alignment
 *          when instance will be created automatically without dynamic memory
 *          allocation.
 */
typedef struct __attribute__((aligned (HAL_CACHE_LINE_SIZE), packed))
{
    /*  Put often used data from beginning to improve cache locality */

    /*  Every 'enqueue' and 'dequeue' access */
    void *base_va;              /*  Ring base address (virtual) */
    void *wb_tbl_base_va;       /*  Write-back table base address (virtual) */
    uint32_t length;            /*  Length of the ring (number of buffer descriptors) */

    /*  Every 'enqueue' access */
    uint32_t write_idx;         /*  BD index to be written */
    union                       /* Pointer to BD to be written */
    {
        pfe_hif_bd_t *wr_bd;
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        pfe_hif_nocpy_bd_t *wr_bd_nocpy;
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    } bd_write;

#if (TRUE == HAL_HANDLE_CACHE)
    union                       /*  Pointer to BD to be written (PA). Only due to CACHE_* macros in QNX... */
    {
        pfe_hif_bd_t *wr_bd_pa;
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        pfe_hif_nocpy_bd_t *wr_bd_nocpy_pa;
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    };
#endif /* HAL_HANDLE_CACHE */
    pfe_hif_wb_bd_t *wr_wb_bd;  /*  Pointer to WB BD to be written */
    bool_t is_rx;               /*  If TRUE then ring is RX ring */

    /*  Every 'dequeue' access */
    uint32_t read_idx;          /*  BD index to be read */
    union                       /*  Pointer to BD to be read */
    {
        pfe_hif_bd_t *rd_bd;
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
        pfe_hif_nocpy_bd_t *rd_bd_nocpy;
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
    }bd_read;

    pfe_hif_wb_bd_t *rd_wb_bd;  /*  Pointer to WB BD to be read */
    bool_t heavy_data_mark;     /*  To enable getting size of heavily accessed data */

    /*  Initialization time only */
    void *base_pa;              /*  Ring base address (physical) */
    void *wb_tbl_base_pa;       /*  Write-back table base address (physical) */
} pfe_hif_ring_t;

#if !defined(PFE_CFG_DETACHED_MINIHIF)
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"


__attribute__((cold)) errno_t pfe_hif_ring_create(pfe_hif_ring_t *ring, uint32_t length, bool_t rx, bool_t nocpy);
#endif /*PFE_CFG_DETACHED_MINIHIF*/

__attribute__((cold)) errno_t pfe_hif_ring_attach(pfe_hif_ring_t *ring, void *ring_va, void *wb_ring_va, uint32_t length, bool_t is_rx, bool_t nocpy, bool_t init_bd);
uint32_t pfe_hif_ring_get_len(const pfe_hif_ring_t *ring) __attribute__((pure, hot));
errno_t pfe_hif_ring_destroy(pfe_hif_ring_t *ring) __attribute__((cold));
void *pfe_hif_ring_get_base_pa(const pfe_hif_ring_t *ring) __attribute__((pure, cold));
void *pfe_hif_ring_get_wb_tbl_pa(const pfe_hif_ring_t *ring) __attribute__((pure, cold));
uint32_t pfe_hif_ring_get_wb_tbl_len(const pfe_hif_ring_t *ring) __attribute__((pure, cold));
errno_t pfe_hif_ring_enqueue_buf(pfe_hif_ring_t *ring, const void *buf_pa, uint32_t length, uint32_t lmem_header_size, bool_t lifm) __attribute__((hot));
errno_t pfe_hif_ring_dequeue_buf(pfe_hif_ring_t *ring, void **buf_pa, uint32_t *length, bool_t *lifm) __attribute__((hot));
errno_t pfe_hif_ring_dequeue_plain(pfe_hif_ring_t *ring, bool_t *lifm) __attribute__((hot));
errno_t pfe_hif_ring_drain_buf(pfe_hif_ring_t *ring, void **buf_pa) __attribute__((cold));
bool_t pfe_hif_ring_is_below_wm(const pfe_hif_ring_t *ring) __attribute__((pure, hot));
void pfe_hif_ring_invalidate(const pfe_hif_ring_t *ring) __attribute__((cold));
uint32_t pfe_hif_ring_get_fill_level(const pfe_hif_ring_t *ring) __attribute__((pure, hot));
void pfe_hif_ring_dump(const pfe_hif_ring_t *ring, const char_t *name) __attribute__((cold));
bool_t pfe_hif_ring_is_on_head(const pfe_hif_ring_t *ring);
errno_t pfe_hif_ring_find_wb_entry(pfe_hif_ring_t *ring, bool_t valid, uint32_t *index);
void pfe_hif_ring_invalidate_direct(const pfe_hif_ring_t *ring, uint32_t index);
void pfe_hif_ring_revalidate_direct(const pfe_hif_ring_t *ring, uint32_t index);
errno_t pfe_hif_ring_force_index(pfe_hif_ring_t *ring, uint32_t index);
bool_t pfe_hif_ring_rd_wb_bd_enabled(const pfe_hif_ring_t *ring);

#if !defined(PFE_CFG_DETACHED_MINIHIF)
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /*PFE_CFG_DETACHED_MINIHIF*/

#endif /* PUBLIC_PFE_HIF_RING_H_ */
