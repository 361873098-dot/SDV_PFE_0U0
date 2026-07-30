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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"
#include "oal_mm.h"
#include "oal_sync.h"
#include "hal.h"
#include "fifo.h"

#define is_power_of_2(n) ((n) && !((n) & ((n) - 1U)))

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

__attribute__((hot)) errno_t fifo_get_fill_level(const fifo_t *const fifo, uint32_t *fill_level)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == fifo) || (NULL == fill_level)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        *fill_level = (fifo->write - fifo->read);
        ret = EOK;
    }
    return ret;
}

__attribute__((hot)) errno_t fifo_get_free_space(const fifo_t *const fifo, uint32_t *free_space)
{
    uint32_t ret = 0U;
    errno_t err;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == fifo) || (NULL == free_space)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        err = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        err = fifo_get_fill_level(fifo, &ret);
        *free_space = fifo->depth - ret;
    }
    return err;
}

__attribute__((cold)) fifo_t * fifo_create(const uint32_t depth, fifo_t *fifo, void **data)
{
    fifo_t *tmp_fifo = fifo;

    if (!is_power_of_2(depth) || (depth > 0x7FFFFFFFU))
    {
        tmp_fifo = NULL;
    }
    else
    {
        tmp_fifo->read = 0U;
        tmp_fifo->write = 0U;
        tmp_fifo->depth = depth;
        tmp_fifo->depth_mask = depth - 1U;

        tmp_fifo->data = data;
        if (unlikely(NULL == tmp_fifo->data))
        {
            tmp_fifo = NULL;
        }
    }

    return tmp_fifo;
}

__attribute__((cold)) void fifo_destroy(fifo_t *fifo)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == fifo))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        fifo->read = 0U;
        fifo->write = 0U;
        fifo->depth = 0U;
        fifo->depth_mask = 0U;
        fifo->protected = FALSE;
        fifo->data = NULL;
    }
}

__attribute__((cold)) void fifo_clear(fifo_t *const fifo)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == fifo))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    if (NULL != fifo)
    {
        fifo->read = 0U;
        fifo->write = fifo->depth;
    }
}

__attribute__((hot)) void * fifo_peek(const fifo_t * const fifo, uint32_t num)
{
    volatile void *ret = NULL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == fifo))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (likely(num < fifo->depth))
        {
            ret = fifo->data[num];
        }
    }
    return (void *)ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
