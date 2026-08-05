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
 *  Copyright (C) 2007 Mindspeed Technologies, Inc.
 *  Copyright 2017-2023 NXP
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
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "pfe_platform_cfg.h"
#include "fpp.h"
#include "fci_msg.h"
#include "libfci.h"
#include "fci.h"
#include "fci_internal.h"
#include "oal.h"

#ifdef PFE_CFG_FCI_ENABLE

#ifndef EOK
#define EOK 0
#endif

/*
* Debug macros
*/
#define FCILIB_PRINT
#define FCILIB_ERR    1
#define FCILIB_INIT   0
#define FCILIB_OPEN   1
#define FCILIB_CLOSE  1
#define FCILIB_WRITE  0
#define FCILIB_READ   0
#define FCILIB_DUMP   0
#define FCILIB_CATCH  0
#define FCILIB_REG_CB 0

#if (defined(FCILIB_PRINT) && defined(NXP_LOG_ENABLED))
#define FCILIB_PRINTF(type, ...) do {if(type) NXP_LOG_INFO(__VA_ARGS__);} while(0);
#else
#define FCILIB_PRINTF(type, ...) do {} while(0);
#endif

struct fci_hdr
{
    uint16_t fcode;
    uint16_t len;
} __attribute__((packed));

struct fci_client_tag
{
    fci_mcast_groups_t group;
    fci_cb_retval_t (*event_cb)(unsigned short fcode, unsigned short len, unsigned short *payload);
};

typedef struct
{
    const uint16_t *cmd_buf;
    uint16_t cmd_len;
    uint16_t *rep_buf;
    uint16_t *rep_len;
}fci_params;

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static FCI_CLIENT fci_client;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"
static bool_t fci_client_created = FALSE;
#define ETH_43_PFE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static FCI_CLIENT *fci_create_client(fci_mcast_groups_t group);
static int32_t fci_destroy_client(FCI_CLIENT *client);
static int32_t fci_command(FCI_CLIENT *client, uint16_t fcode, fci_params *cmd_rep);

/****************************** PUBLICS FUNCTIONS ********************************/

/**
 * @brief     Create the FCI client
 * @param[in] client_type Type of FCI client
 * @param[in] group       Group of FCI client
 * @retval    NULL if client not created
 * @retval    non NULL pointer to created FCI client
 * @note      Only one client of identical type can be created !
 */
FCI_CLIENT *fci_open(fci_client_type_t client_type, fci_mcast_groups_t group)
{
    FCI_CLIENT *new_client = NULL_PTR;

    /* Create client according to the requested socket type */
    switch(client_type)
    {
        case FCI_CLIENT_DEFAULT:
        {
            FCILIB_PRINTF(FCILIB_OPEN, "fci_open:%d client type FCILIB_FF_CLIENT with group %d\n", __LINE__, group);
            new_client = fci_create_client(group);
            break;
        }

        default:
        {
            FCILIB_PRINTF(FCILIB_ERR, "LIB_FCI: fci_open():%d client type %d not supported\n", __LINE__, client_type);
            new_client = NULL;
        }

        break;
    }

    /* Unique ID used to identify this client */
    return new_client;
}

/*==================================================================================================*/
int fci_register_cb(FCI_CLIENT *client, fci_cb_retval_t (*event_cb)(unsigned short fcode, unsigned short len, unsigned short *payload))
{
    int32_t ret = -EINVAL;

    FCILIB_PRINTF(FCILIB_REG_CB, "fci_register_cb()\n")
    if (client != NULL)
    {
        client->event_cb = event_cb;
        if (NULL != event_cb)
        {
            context.is_some_client = TRUE;
            fci_hm_send_events();
        }
        else
        {
            context.is_some_client = FALSE;
        }
        ret = EOK;
    }

    return ret;
}

/*==================================================================================================*/
int fci_close(FCI_CLIENT *client)
{
    int32_t rc;
    int32_t ret = 0;

    FCILIB_PRINTF(FCILIB_CLOSE, "fci_close()\n");

    /* Unregister FCI client */
    if (client == NULL)
    {
        ret = -1;
    }
    else
    {
        rc = fci_register_cb(client, NULL);
        if(EOK != rc)
        {
            FCILIB_PRINTF(FCILIB_ERR, "fci_close: fci_register_cb failed with %d!\n", (int_t)rc);
        }
        rc = fci_destroy_client(client);
        if (rc < 0)
        {
            FCILIB_PRINTF(FCILIB_ERR, "fci_close: fci_destroy_client failed !\n");
            ret = rc;
        }
    }
    return ret;
}

/*==================================================================================================*/
int fci_cmd(FCI_CLIENT *client, unsigned short fcode, unsigned short *cmd_buf, unsigned short cmd_len, unsigned short *rep_buf, unsigned short *rep_len)
{
    FCILIB_PRINTF(FCILIB_WRITE, "fci_cmd: send fcode %#x length %d\n", fcode, cmd_len);

    fci_params cmd_rep = { .cmd_buf = cmd_buf, .cmd_len = cmd_len, .rep_buf = rep_buf, .rep_len = rep_len};
    return fci_command(client, fcode, &cmd_rep);
}

/*==================================================================================================*/
int fci_write(FCI_CLIENT *client, unsigned short fcode, unsigned short cmd_len, unsigned short *cmd_buf)
{
    FCILIB_PRINTF(FCILIB_WRITE, "fci_write: send fcode %#x length %d\n", fcode, cmd_len);

    fci_params cmd_rep = { .cmd_buf = cmd_buf, .cmd_len = cmd_len, .rep_buf = NULL, .rep_len = NULL};
    return fci_command(client, fcode, &cmd_rep);
}

/*==================================================================================================*/
int fci_query(FCI_CLIENT *client, unsigned short fcode, unsigned short cmd_len, unsigned short *cmd_buf, unsigned short *rep_len, unsigned short *rep_buf)
{
    FCILIB_PRINTF(FCILIB_WRITE, "fci_query: send fcode %#x length %d\n", fcode, cmd_len);

    fci_params cmd_rep = { .cmd_buf = cmd_buf, .cmd_len = cmd_len, .rep_buf = rep_buf, .rep_len = rep_len};
    return fci_command(client, fcode, &cmd_rep);
}

/*==================================================================================================*/
int fci_catch(FCI_CLIENT *client)
{
    fci_msg_t msg;
    int32_t ret = EOK;
    bool_t shall_quit = FALSE;
    fci_cb_retval_t cb_ret;

    while (FALSE == shall_quit)
    {
        /* Read message from kernel */
        ret = fci_core_client_get_msg(&msg);
        if (EOK != ret)
        {
            if (ENOENT == ret)
            {
                ret = EOK;
            }
            else
            {
                FCILIB_PRINTF(FCILIB_ERR, "fci_core_client_get_msg() failed: %d\n", (int_t)ret);
            }
            shall_quit = TRUE;
        }
        else
        {
            /* Message */
            FCILIB_PRINTF(FCILIB_CATCH," Received message payload: %s\n",(char*)msg.msg_cmd.payload);
            if ((FCI_MSG_CMD == msg.type) || (FCI_MSG_CORE_CLIENT_BROADCAST == msg.type))
            {
                /* Call registered callback */
                if (NULL != client->event_cb)
                {
                    cb_ret = client->event_cb((unsigned short)msg.msg_cmd.code,
                                              (unsigned short)msg.msg_cmd.length,
                                              (unsigned short *)msg.msg_cmd.payload);

                    if (FCI_CB_CONTINUE == cb_ret)
                    {
                        /* Continue */
                        ;
                    }
                    else
                    {
                        /* Terminate */
                        shall_quit = TRUE;
                    }
                }
            }
            else
            {
                FCILIB_PRINTF(FCILIB_ERR, "Unknown message received (type = 0x%x)\n", msg.type);
            }
        }
    }

    return ret;
}

/**
 * @brief       fci_fd: Not supported yet
 * @param[in]   client FCI client instance to be used
 * @return      Always -1 (failure) because the function is not supported.
 * @warning     Function shall not be used.
 */
int fci_fd(FCI_CLIENT *client)
{
    (void)*client;
    FCILIB_PRINTF(FCILIB_ERR, "LIBFCI: fci_fd() not implemented\n");
    return -1;
}

/****************************** PRIVATE FUNCTIONS ********************************/
static int32_t fci_command(FCI_CLIENT *client, uint16_t fcode, fci_params *cmd_rep)
{
    fci_msg_t msg;
    fci_msg_t reply_msg;
    int32_t cmd_ret = EOK;
    int32_t ret;

    /* Make sure fci client is registered*/
    if (client == NULL)
    {
        FCILIB_PRINTF(FCILIB_ERR, "LIBFCI: Client is unregistered\n");
        ret = EINVAL;
    }
    else
    {
        (void)autolibc_memset(&msg, 0, sizeof(msg));
        (void)autolibc_memset(&reply_msg, 0, sizeof(reply_msg));

        msg.type = FCI_MSG_CMD;
        msg.msg_cmd.code = fcode;

        if (cmd_rep->cmd_len > 0U)
        {
            msg.msg_cmd.length = cmd_rep->cmd_len;
            (void)autolibc_memcpy(&msg.msg_cmd.payload, cmd_rep->cmd_buf, cmd_rep->cmd_len);
        }

        /* Local sender identification */
        msg.msg_cmd.sender = (uint32_t)PFE_CFG_LOCAL_IF;

        cmd_ret = fci_process_ipc_message(&msg, &reply_msg);

        if(cmd_ret != EOK)
        {
            /*  Command failure */
            FCILIB_PRINTF(FCILIB_ERR, "LIBFCI: Command failed with %d\n", (int_t)cmd_ret);
            ret = cmd_ret;
        }
        else
        {
            /*  Success, pass reply data (if any) and its length to user */
            if ((NULL != cmd_rep->rep_buf) && (NULL != cmd_rep->rep_len) && (4U <= reply_msg.msg_cmd.length))
            {
#if (TRUE == FCI_CFG_FORCE_LEGACY_API)
                (void)autolibc_memcpy(cmd_rep->rep_buf, reply_msg.msg_cmd.payload, reply_msg.msg_cmd.length);
                *cmd_rep->rep_len = reply_msg.msg_cmd.length;
#else
                (void)autolibc_memcpy(cmd_rep->rep_buf, (reply_msg.msg_cmd.payload + 4U), reply_msg.msg_cmd.length - 4U);
                *cmd_rep->rep_len = (uint16_t)(reply_msg.msg_cmd.length) - 4U;
#endif /* FCI_CFG_FORCE_LEGACY_API */
            }
            (void)autolibc_memcpy(&cmd_ret, reply_msg.msg_cmd.payload, sizeof(uint16_t));

            ret = cmd_ret;
        }
    }
    return ret;
}

/*==================================================================================================*/
static FCI_CLIENT *fci_create_client(fci_mcast_groups_t group)
{
    FCI_CLIENT *client;

    if (TRUE == fci_client_created)
    {
        FCILIB_PRINTF(FCILIB_ERR, "LIBFCI: fci_create_client() fci client already created\n");
        client = NULL_PTR;
    }
    else
    {
        fci_client_created = TRUE;
        fci_client.group = group;
        client = &fci_client;
    }

    return client;
}

/*==================================================================================================*/
static int32_t fci_destroy_client(FCI_CLIENT *client)
{
    (void)client;

    FCILIB_PRINTF(FCILIB_CLOSE, "fci_destroy_client()\n");
    if (TRUE == fci_client_created)
    {
        fci_client_created = FALSE;
        (void)autolibc_memset(&fci_client, 0, sizeof(fci_client));
    }

    return 0;
}
/*==================================================================================================*/

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_FCI_ENABLE */
