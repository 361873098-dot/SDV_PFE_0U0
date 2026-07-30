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

#ifndef SRC_fifo_H_
#define SRC_fifo_H_

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
#include "oal_util.h"

struct __attribute__((aligned(HAL_CACHE_LINE_SIZE))) fifo_tag
{
    uint32_t read;
    uint32_t write;
    uint32_t depth;
    uint32_t depth_mask;
    bool_t protected;
    void **data;
};

typedef volatile struct fifo_tag fifo_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static inline errno_t fifo_put(fifo_t *const fifo, void *const ptr)
{
    uint32_t fill_level;
    errno_t err;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == fifo))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        err = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        fill_level = (fifo->write - fifo->read);

        if (likely(fill_level < fifo->depth))
        {
            fifo->data[fifo->write & fifo->depth_mask] = ptr;

            /*  Ensure that entry contains correct data */
            hal_wmb();

            fifo->write++;

            err = EOK;
        }
        else
        {
            /*  Overflow */
            err = EOVERFLOW;
        }
    }

    return err;
}

static inline void * fifo_get(fifo_t * const fifo)
{
    void *ret = NULL;
    uint32_t fill_level;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == fifo))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        fill_level = (fifo->write - fifo->read);

        if (likely(fill_level > 0U))
        {
            ret = fifo->data[fifo->read & fifo->depth_mask];
            fifo->read++;
        }
    }

    return (void *)ret;
}

fifo_t * fifo_create(const uint32_t depth, fifo_t *fifo, void **data) __attribute__((cold));
void fifo_destroy(fifo_t *fifo) __attribute__((cold));
void fifo_clear(fifo_t *const fifo) __attribute__((cold));
void * fifo_peek(const fifo_t * const fifo, uint32_t num) __attribute__((hot));
errno_t fifo_get_fill_level(const fifo_t *const fifo, uint32_t *fill_level) __attribute__((hot));
errno_t fifo_get_free_space(const fifo_t *const fifo, uint32_t *free_space) __attribute__((hot));

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* SRC_fifo_H_ */
