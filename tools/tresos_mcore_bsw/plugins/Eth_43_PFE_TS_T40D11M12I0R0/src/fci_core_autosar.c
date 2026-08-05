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

/**
 * @addtogroup  dxgr_FCI
 * @{
 *
 * @file        fci_core_autosar.c
 * @brief       The AUTOSAR-specific FCI core component. Full description can be
 *              found within the fci_core.h.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

/*==============================================================================
                                INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==============================================================================*/
#include "pfe_cfg.h"
#include "oal.h"
#include "fci.h"
#include "fci_internal.h"
#include "fci_core.h"
#include "fifo.h"

#ifdef PFE_CFG_FCI_ENABLE

/*==============================================================================
                  LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==============================================================================*/
typedef struct
{
    fci_msg_t items[FCI_CFG_MSG_FIFO_DEPTH];
    uint8_t read;
    uint8_t write;
    uint8_t len;
} fci_msg_mng_t;

/*
 *  AUTOSAR-specific FCI client representation type (fci_core_client_t)
 */
struct fci_core_client_tag
{
    fci_msg_mng_t *msg_fifo;
    bool_t initialized;

    /*
     * This should be a generic endpoint identifier applicable for linux/qnx/asr/...
     */
};

/*
 *  AUTOSAR-specific FCI core representation type (fci_core_t)
 */
struct fci_core_tag
{
    fci_core_client_t client;
};

typedef struct
{
    fifo_t instance;
    __attribute__((aligned(HAL_CACHE_LINE_SIZE))) void *data[FCI_CFG_MSG_FIFO_DEPTH];
} fci_fifo_t;

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/*==============================================================================
                               LOCAL VARIABLES
==============================================================================*/
/* FCI FIFO */
static fci_msg_mng_t fci_msg_fifo;
/* FCI core type singleton */
static fci_core_t fci_core;

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/*==============================================================================
                           LOCAL FUNCTION PROTOTYPES
==============================================================================*/
static errno_t fci_core_msg_fifo_put(fci_msg_mng_t *msg_fifo, fci_msg_t *msg);
static errno_t fci_core_msg_fifo_get(fci_msg_mng_t *msg_fifo, fci_msg_t *msg);

/*==============================================================================
                                LOCAL FUNCTIONS
==============================================================================*/
/**
 * @brief       Put FCI message to client message fifo
 *
 * @param[in]   msg_fifo Pointer to FCI client message fifo
 * @param[in]   msg Pointer to FCI client message
 * @returns     EOK if suceeded, EOVERFLOW otherwise
 */
static errno_t fci_core_msg_fifo_put(fci_msg_mng_t *msg_fifo, fci_msg_t *msg)
{
    errno_t ret = EOVERFLOW;

    oal_mutex_lock(PFE_FCI_FIFO_MUTEX_00);

    if (msg_fifo->len < FCI_CFG_MSG_FIFO_DEPTH)
    {
        (void)autolibc_memcpy(&(msg_fifo->items[msg_fifo->write]), msg, sizeof(fci_msg_t));
        msg_fifo->len++;
        msg_fifo->write++;
        if(msg_fifo->write >= FCI_CFG_MSG_FIFO_DEPTH)
        {
            msg_fifo->write = 0U;
        }
        ret = EOK;
    }

    oal_mutex_unlock(PFE_FCI_FIFO_MUTEX_00);

    return ret;
}

/**
 * @brief       Get FCI message from FCI client message fifo
 *
 * @param[in]   msg_fifo Pointer to FCI client message fifo
 * @param[in]   msg Pointer to FCI client message
 * @returns     EOK if suceeded, ENOENT otherwise
 */
static errno_t fci_core_msg_fifo_get(fci_msg_mng_t *msg_fifo, fci_msg_t *msg)
{
    errno_t ret = ENOENT;

    oal_mutex_lock(PFE_FCI_FIFO_MUTEX_01);

    if (0U != msg_fifo->len)
    {
        (void)autolibc_memcpy(msg, &(msg_fifo->items[msg_fifo->read]), sizeof(fci_msg_t));
        msg_fifo->len--;
        msg_fifo->read++;
        if(msg_fifo->read >= FCI_CFG_MSG_FIFO_DEPTH)
        {
            msg_fifo->read = 0U;
        }
        ret = EOK;
    }

    oal_mutex_unlock(PFE_FCI_FIFO_MUTEX_01);

    return ret;
}

/*==============================================================================
                                GLOBAL FUNCTIONS
==============================================================================*/
/*
     Create FCI core instance
*/
errno_t fci_core_init(const char_t *const id)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == id))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#else
    (void)id;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if(context.core != NULL)
        {
            NXP_LOG_ERROR("FCI_CORE has already been initialized\n");
            ret = EINVAL;
        }
        else
        {
            (void)autolibc_memset(&fci_core, 0, sizeof(fci_core_t));

            fci_core.client.msg_fifo = &fci_msg_fifo;
            (void)autolibc_memset(fci_core.client.msg_fifo, 0, sizeof(fci_msg_mng_t));
            fci_core.client.initialized = TRUE;

            context.core = &fci_core;
            ret = EOK;
        }
    }

    return ret;
}

/*
     Destroy FCI core
*/
void fci_core_fini(void)
{
    fci_core_t *core = (fci_core_t *)context.core;
    fci_msg_t msg;
    errno_t ret;

    (void)autolibc_memset(&msg, 0, sizeof(msg));
    msg.type = FCI_MSG_CMD;
    msg.msg_cmd.code = FPP_CMD_ENDPOINT_SHUTDOWN;

    if (NULL != core)
    {
        ret = fci_core_client_send_broadcast(&msg, NULL);
        /*  Notify listeners */
        if (EOK != ret)
        {
            NXP_LOG_ERROR("fci_core_client_send_broadcast() failed: %d\n", ret);
        }

        (void)autolibc_memset(fci_core.client.msg_fifo, 0, sizeof(fci_msg_mng_t));
        fci_core.client.initialized = FALSE;
        core = NULL;
    }
}

/*
    Send message to the FCI core
*/
errno_t fci_core_send(fci_msg_t *msg, fci_msg_t *rep)
{
    (void)msg;
    (void)rep;
    fci_core_t *core = (fci_core_t *)context.core;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == core))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if (unlikely(FALSE == context.fci_initialized))
    {
        NXP_LOG_ERROR("Context not initialized\n");
        ret = EPERM;
    }
    else
#else
    (void)core;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        NXP_LOG_ERROR("fci_core_send should not be used within MCAL implementation\n");
        ret = EINVAL;
    }
    return ret;
}

/*
    Send message to FCI client
*/
errno_t fci_core_client_send(fci_core_client_t *client, fci_msg_t *msg, fci_msg_t *rep)
{
    errno_t err;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == client))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        err = EINVAL;
    }
    else
#else
    (void)client;
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* This function is not needed in MCAL implementation */
        (void)msg;
        (void)rep;
        err = EOK;
    }

    return err;
}

/*
    Send asynchronous message to all registered FCI clients
*/
errno_t fci_core_client_send_broadcast(fci_msg_t *msg, fci_msg_t *rep)
{
    fci_core_t *core = (fci_core_t *)context.core;
    errno_t err = EEXIST;
    (void)rep;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == core))
    {
        NXP_LOG_RAW_ERROR("NULL argument received\n");
        err = EINVAL;
    }
    else if (unlikely(FALSE == context.fci_initialized))
    {
        NXP_LOG_RAW_ERROR("Context not initialized\n");
        err = EPERM;
    }
    else
#else
    /*  this function could be called from a callback even after the FCI module was destroyed */
    if (unlikely(NULL == core))
    {
        NXP_LOG_RAW_ERROR("NULL argument received\n");
        err = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        msg->type = FCI_MSG_CORE_CLIENT_BROADCAST; /* message type is changed back to FCI_MSG_CMD in core thread */

        if (TRUE == core->client.initialized)
        {
            err = fci_core_msg_fifo_put(core->client.msg_fifo, msg);
            if (unlikely(EOK != err))
            {
                NXP_LOG_WARNING("FCI client messages storage is full, no further messages will be stored.\n");
            }
        }
        else
        {
            NXP_LOG_RAW_ERROR("FCI core client has not been initialized yet\n");
        }
    }

    return err;
}

/*
    Get a message from the FIFO (called by the FCI client)
    Returns NULL when the FIFO is empty, an error code on error
    or the message from the FIFO.
*/
errno_t fci_core_client_get_msg(fci_msg_t *msg)
{
    fci_core_t *core = (fci_core_t *)context.core;
    errno_t ret = ENOENT;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == core))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else if (unlikely(FALSE == context.fci_initialized))
    {
        NXP_LOG_ERROR("Context not initialized\n");
        ret = EPERM;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (TRUE == core->client.initialized)
        {
            ret = fci_core_msg_fifo_get(core->client.msg_fifo, msg);
        }
        else
        {
            NXP_LOG_RAW_ERROR("FCI core client has not been initialized yet\n");
        }
    }

    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_FCI_ENABLE */
/** @}*/
