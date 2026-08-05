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

/**
 * @addtogroup  dxgr_OAL_IRQ
 * @{
 *
 * @file        oal_irq_autosar.c
 * @brief       The oal_irq module source file (AUTOSAR OS).
 * @details     This file contains AUTOSAR OS specific irq implementation.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "Std_Types.h"
#include "oal.h"
#include "hal.h"
#include "oal_irq.h"

/* LOCAL MACROS */
#define MAX_HANDLER_CNT 6U

/* TYPEDEFS */
/**
 * @brief   The IRQ instance representation
 */
struct oal_irq_tag
{
    int32_t id;
    bool_t created;
    oal_irq_flags_t flags;
    oal_irq_handler_t handler[MAX_HANDLER_CNT];
    void *data[MAX_HANDLER_CNT];
};

#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/* LOCAL VARIABLES */
static oal_irq_t irq_pool[Eth_43_PFE_IRQ_COUNT] = {0};

#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/* GLOBAL FUNCTIONS */
void oal_irq_common_handler(oal_irq_idx_t idx)
{
    uint32_t ctr;

    for(ctr=0U; ctr<MAX_HANDLER_CNT; ctr++)
    {
        if(NULL != irq_pool[idx].handler[ctr])
        {
            (void)irq_pool[idx].handler[ctr](irq_pool[idx].data[ctr]);
        }
    }
}

/* Not reentrant for same id */
oal_irq_t * oal_irq_create(int32_t id, oal_irq_flags_t flags, const char_t *name)
{
    oal_irq_t *ret_val = NULL;
    uint32_t idx = (uint32_t)find_irq_idx_from_id(id);

    (void)name;
    if((idx < (uint32_t)Eth_43_PFE_IRQ_COUNT) && (FALSE == irq_pool[idx].created))
    {
        irq_pool[idx].created = TRUE;

        /*  TODO for threaded mode: allocate a task with an event here to run the worker in */

        irq_pool[idx].id = id;
        irq_pool[idx].flags = flags;
        ret_val = &irq_pool[idx];
    }
    return ret_val;
}

errno_t oal_irq_add_handler(oal_irq_t *irq, oal_irq_handler_t handler, void *data, oal_irq_isr_handle_t *handle)
{
    errno_t ret_val = ENOMEM;
    uint32_t ctr;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == irq) || (NULL == handler)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret_val = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Find unused handler entry */
        for(ctr=0U; ctr<MAX_HANDLER_CNT; ctr++)
        {
            if(NULL == irq->handler[ctr])
            {
                if(NULL != handle)
                {
                    *handle = ctr;
                }
                irq->handler[ctr] = handler;
                irq->data[ctr] = data;
                ret_val = EOK;
                break;
            }
        }
    }
    return ret_val;
}

errno_t oal_irq_del_handler(oal_irq_t *irq, oal_irq_isr_handle_t handle)
{
    errno_t ret_val = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == irq) || (handle >= MAX_HANDLER_CNT)))
    {
        NXP_LOG_ERROR("Invalid argument received\n");
        ret_val = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        irq->handler[handle] = NULL;
        irq->data[handle] = NULL;
    }
    return ret_val;
}

void oal_irq_destroy(oal_irq_t *irq)
{   /* Not possible in AUTOSAR OS */
    uint32_t ctr;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == irq))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        irq->created = FALSE;
        /* Remove all handlers */
        for(ctr=0U; ctr<MAX_HANDLER_CNT; ctr++)
        {
            irq->handler[ctr] = NULL;
            irq->data[ctr] = NULL;
        }
        irq->flags = (oal_irq_flags_t)0U;
    }
}

int32_t oal_irq_get_id(const oal_irq_t *irq)
{
    int32_t retval;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == irq))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        retval = -1;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        retval = irq->id;
    }
    return retval;
}

bool_t oal_irq_in_atomic(void)
{
    return FALSE;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/** @}*/
