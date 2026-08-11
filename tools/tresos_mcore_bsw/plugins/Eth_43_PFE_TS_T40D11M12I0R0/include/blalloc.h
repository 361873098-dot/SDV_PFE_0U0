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
 *  Copyright 2019-2023 NXP
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



#ifndef SRC_BLALLOC_H_
#define SRC_BLALLOC_H_


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

/**
 * @brief   Number of chunks encoded within single byte. Not intended to be modified.
 */
#define BLALLOC_CFG_CHUNKS_IN_BYTE 4U

/**
 * @brief   Block allocator instance status
 */
typedef enum
{
    BL_INVALID = 0,
    BL_DYNAMIC = 10,
    BL_STATIC = 20
} blalloc_status_t;

/**
 * @brief      Block allocator context representation
 */
typedef struct
{
    size_t size;      /* Size */
    size_t chunk_size;/* Size of a memory chunk is 2^this_value */
    size_t start_srch;/* Remember position of the 1st free chunk */
    size_t allocated; /* Sum of all allocated bytes (including those freed and allocated again) */
    size_t requested; /* Sum of all requested bytes to be allocated */
    blalloc_status_t status;   /* Instance status */
    uint8_t *chunkinfo;/* Pointer to free space that follows this struct */
    /* The free space for chunkinfo will be here (if extra size was allocated) */
} blalloc_t;

/**
 * @brief   Static block allocator instance constructor
 * @details Intended to be used to create static block allocator instances. Static instances
 *          shall be initialized and finalized using blalloc_init() and blalloc_fini() calls
 *          instead of dynamic blalloc_create() and blalloc_destroy().
 */
#define BLALLOC_STATIC_INST(__name, __size, __chunk_size) \
static uint8_t blalloc_buf_##__name[((((__size) >> (__chunk_size)) + BLALLOC_CFG_CHUNKS_IN_BYTE - 1U) / BLALLOC_CFG_CHUNKS_IN_BYTE)] = {0U}; \
static blalloc_t __name = \
    { \
        .chunkinfo = blalloc_buf_##__name, \
        .size = (__size), \
        .chunk_size = (__chunk_size) \
    }

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

blalloc_t *blalloc_create(size_t size, size_t chunk_size);
void blalloc_destroy(blalloc_t *ctx);
errno_t blalloc_init(blalloc_t *ctx);
void blalloc_fini(blalloc_t *ctx);
errno_t blalloc_alloc_offs(blalloc_t *ctx, size_t size, size_t align, addr_t *addr);
void blalloc_free_offs_size(blalloc_t *ctx, addr_t offset, size_t size);
void blalloc_free_offs(blalloc_t *ctx, addr_t offset);

#if defined(PFE_CFG_TEXT_STATS)
uint32_t blalloc_get_text_statistics(const blalloc_t *ctx, char_t *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* SRC_BLALLOC_H_ */
