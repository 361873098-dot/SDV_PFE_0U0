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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
#include "linked_list.h"
#include "pfe_hif_drv.h"
#include "pfe_hif.h"
#include "pfe_idex.h"
#include "pfe_platform_rpc.h"
#include "pfe_platform_cfg.h"

#define IDEX_IS_NOCPY (4 == PFE_CFG_LOCAL_IF_VALUE)

/**
 * @brief   IDEX request timeout in seconds
 */
#define IDEX_CFG_REQ_TIMEOUT_SEC    1U

/**
 * @brief       IDEX sequence number type
 */
typedef uint32_t pfe_idex_seqnum_t;

ct_assert(sizeof(pfe_idex_seqnum_t) == sizeof(uint32_t));

/**
 * @brief   IDEX Frame types
 */
typedef enum __attribute__((packed))
{
    /*  Request. Frames of this type are expected to be responded
        by a remote instance. Therefore they are not released on TX
        confirmation event but stored in request pool and released
        upon timeout or response is received. */
    IDEX_FRAME_CTRL_REQUEST = 0,
    /*  Response. Released at TX confirmation time. */
    IDEX_FRAME_CTRL_RESPONSE = 1
} pfe_idex_frame_type_t;

ct_assert(sizeof(pfe_idex_frame_type_t) == sizeof(uint8_t));

/**
 * @brief   IDEX Request types
 */
typedef enum __attribute__((packed))
{
    /*  Master discovery. To find out where master is located. Non-blocking. */
    IDEX_MASTER_DISCOVERY = 0U,
    /*  RPC request. Blocking. */
    IDEX_RPC
} pfe_idex_request_type_t;

ct_assert(sizeof(pfe_idex_request_type_t) == sizeof(uint8_t));

/**
 * @brief   IDEX Response types
 */
typedef pfe_idex_request_type_t pfe_idex_response_type_t;

ct_assert(sizeof(pfe_idex_request_type_t) == sizeof(uint8_t));

/**
 * @brief   IDEX Master Discovery Message header
 */
typedef struct __attribute__((packed))
{
    /*  Physical interface ID where master driver is located */
    pfe_ct_phy_if_id_t phy_if_id;
} pfe_idex_msg_master_discovery_t;

ct_assert(sizeof(pfe_idex_msg_master_discovery_t) == sizeof(uint8_t));

/**
 * @brief   IDEX RPC Message header
 */
typedef struct __attribute__((packed))
{
    /*  Custom RPC ID */
    uint32_t rpc_id;
    /*  Return value */
    errno_t rpc_ret;
    /*  Payload length */
    uint16_t plen;
} pfe_idex_msg_rpc_t;

ct_assert(sizeof(errno_t) == sizeof(uint32_t));

/**
 * @brief   IDEX Frame Header
 */
typedef struct __attribute__((packed))
{
    /*  Destination physical interface ID */
    pfe_ct_phy_if_id_t dst_phy_if;
    /*  Type of frame */
    pfe_idex_frame_type_t type;
} pfe_idex_frame_header_t;

ct_assert(sizeof(pfe_idex_frame_header_t) == 2);

/**
 * @brief   IDEX request states
 */
typedef enum __attribute__((packed))
{
    /*  New request which is not active. Can't be destroyed or timed-out. */
    IDEX_REQ_STATE_NEW = 0U,
    /*  Finished request */
    IDEX_REQ_STATE_COMPLETED,
    /*  Invalid request. Will be destroyed be cleanup task. */
    IDEX_REQ_STATE_INVALID = 0xffU,
} pfe_idex_request_state_t;

ct_assert(sizeof(pfe_idex_request_state_t) == sizeof(uint8_t));

/**
 * @brief   IDEX Request Header. Also used as request instance.
 * @details IDEX Request Frame:
 *          +--------------------------------------------------+
 *          |   IDEX Header (pfe_idex_frame_header_t)          |
 *          +--------------------------------------------------+
 *          |   IDEX Request Header (pfe_idex_request_t)       |
 *          +--------------------------------------------------+
 *          |   IDEX Request message (pfe_idex_msg_*_t)        |
 *          +--------------------------------------------------+
 */
typedef struct __attribute__((packed))
{
    /*  Unique sequence number */
    pfe_idex_seqnum_t seqnum;
    /*  Type of message. Specifies format of the payload. */
    pfe_idex_request_type_t type;
    /*  Destination PHY */
    pfe_ct_phy_if_id_t dst_phy_id;
    /*  Request state */
    pfe_idex_request_state_t state;
    /*  Internal linked list hook */
    union { /* Avoids changing struct size between 32/64bit architectures */
        struct __attribute__((packed)) {
            LLIST_t list_entry;
            /*  Internal timeout value */
            uint32_t timeout;
            void *resp_buf;
            uint16_t resp_buf_len;
        } config;
        uint8_t padding[30U];
    } linked;
} pfe_idex_request_t;

ct_assert(sizeof(pfe_idex_request_t) == 37);

/**
 * @brief   IDEX Response Header. Also used as response instance.
 * @details IDEX Response Frame:
 *          +--------------------------------------------------+
 *          |   IDEX Header (pfe_idex_frame_header_t)          |
 *          +--------------------------------------------------+
 *          |   IDEX Response Header (pfe_idex_response_t)     |
 *          +--------------------------------------------------+
 *          |   IDEX Response message (pfe_idex_msg_*_t)       |
 *          +--------------------------------------------------+
 */
typedef struct __attribute__((packed))
{
    /*  Sequence number matching request which the response is dedicated for */
    pfe_idex_seqnum_t seqnum;
    /*  Type of message. Specifies format of the payload. */
    pfe_idex_response_type_t type;
    /*  Payload length in number of bytes */
    uint16_t plen;
} pfe_idex_response_t;

ct_assert(sizeof(pfe_idex_response_t) == 7);

/**
 * @brief   This is IDEX instance representation type
 */
typedef struct
{
    pfe_hif_drv_client_t *ihc_client;   /*  HIF driver IHC client used for communication */
    pfe_ct_phy_if_id_t master_phy_if;   /*  Physical interface ID where master driver is located */
    pfe_idex_seqnum_t req_seq_num;      /*  Current sequence number */
    pfe_idex_tx_conf_free_cbk_t txc_free_cbk;   /*  Callback to release frame buffers on Tx confirmation */
    pfe_idex_rpc_cbk_t rpc_cbk;         /*  Callback to be called in case of RPC requests */
    void *rpc_cbk_arg;                  /*  RPC callback argument */
    pfe_idex_request_t *cur_req;        /*  Current IDEX request */
    pfe_ct_phy_if_id_t cur_req_phy_id;  /*  Physical interface the current request has been received from */
    pfe_hif_t *hif;                     /*  HIF module, for Master-up signaling */
} pfe_idex_t;

/* IMG-EPP.HW_Technical_Reference_Manual_10.pdf page 39 */
#define IMG_EPP_MAX_PACKET_SIZE 1522

/**
 * @brief Type used to create properly sized buffer for pfe_idex_rpc calls
 */
typedef struct __attribute__((packed))
{
    pfe_ct_hif_tx_hdr_t     hif_tx_hdr;
    pfe_idex_frame_header_t frame_header;
    pfe_idex_request_t req;
    pfe_idex_msg_rpc_t msg;     /* IDEX RPC Message header */
    uint8_t arg[IMG_EPP_MAX_PACKET_SIZE - sizeof(pfe_idex_frame_header_t) - sizeof(pfe_idex_request_t) - sizeof(pfe_idex_msg_rpc_t)];
} pfe_idex_request_frame_t;

/**
 * @brief Type used to create properly sized buffer for pfe_idex_set_rpc_ret_val calls
 */
typedef struct __attribute__((packed))
{
    pfe_ct_hif_tx_hdr_t     hif_tx_hdr;
    pfe_idex_frame_header_t frame_header;
    pfe_idex_response_t resp;       /* IDEX Response Header */
    pfe_idex_msg_rpc_t msg_rpc;     /* IDEX RPC Message header */
    uint8_t ret[IMG_EPP_MAX_PACKET_SIZE - sizeof(pfe_idex_frame_header_t) - sizeof(pfe_idex_response_t) - sizeof(pfe_idex_msg_rpc_t)];
} pfe_idex_response_frame_t;

#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/*  Local IDEX instance storage */
static pfe_idex_t pfe_idex = {0};

#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BUF_MEM
#include "Eth_43_PFE_MemMap.h"
pfe_idex_response_frame_t pfe_idex_response_frame;
pfe_idex_request_frame_t pfe_idex_request_frame;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BUF_MEM
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static void pfe_idex_do_rx(pfe_hif_drv_client_t *client, pfe_idex_t *idex);
static void pfe_idex_do_tx_conf(const pfe_hif_drv_client_t *client, const pfe_idex_t *idex);
static errno_t pfe_idex_request_finalize(pfe_idex_seqnum_t seqnum, void *resp_buf, uint16_t resp_len);
static errno_t pfe_idex_send_response(pfe_ct_phy_if_id_t dst_phy, pfe_idex_response_type_t type, pfe_idex_seqnum_t seqnum, uint16_t data_len);
static errno_t pfe_idex_send_frame(pfe_ct_phy_if_id_t dst_phy, pfe_idex_frame_type_t type, const void *data, uint16_t data_len);
/*#ifdef PFE_CFG_PFE_SLAVE*/
static errno_t pfe_idex_request_send(pfe_ct_phy_if_id_t dst_phy, pfe_idex_request_type_t type, uint16_t data_len, void *resp, uint16_t resp_len);
/*#endif PFE_CFG_PFE_SLAVE */
static errno_t pfe_idex_ihc_handler(pfe_hif_drv_client_t *client, void *arg, uint32_t event, uint32_t qno);
static errno_t pfe_idex_set_rpc_cbk(pfe_idex_rpc_cbk_t cbk, void *arg);

/**
 * @brief       IHC client event handler
 * @details     Called by HIF when client-related event happens (packet received, packet
 *              transmitted).
 */
static errno_t pfe_idex_ihc_handler(pfe_hif_drv_client_t *client, void *arg, uint32_t event, uint32_t qno)
{
    errno_t ret;
    (void)arg;
    (void)qno;
    ret = EOK;

    switch (event)
    {
        case EVENT_RX_PKT_IND:
        {
            /*  Run RX routine */
            pfe_idex_do_rx(client, &pfe_idex);
            break;
        }

        case EVENT_TXDONE_IND:
        {
            /*  Run TX routine */
            pfe_idex_do_tx_conf(client, &pfe_idex);
            break;
        }

        case EVENT_RX_OOB:
        {
            /*  Out-of-buffers event. Silently ignored. */
            break;
        }

        default:
        {
            NXP_LOG_ERROR("Unexpected IHC event: 0x%x\n", (uint_t)event);
            ret = EINVAL;
            break;
        }
    }

    return ret;
}

/**
 * @brief       RX processing
 */
static void pfe_idex_do_rx(pfe_hif_drv_client_t *client, pfe_idex_t *idex)
{
    pfe_hif_pkt_t *pkt;
    pfe_idex_frame_header_t *idex_header;
    pfe_idex_request_t *idex_req;
    pfe_idex_response_t *idex_resp;
    errno_t ret;
    pfe_ct_phy_if_id_t i_phy_id;

    while (TRUE)
    {
        /*  Get received packet */
        pkt = pfe_hif_drv_client_receive_pkt(client, 0U);
        if (NULL == pkt)
        {
            /*  No more received packets */
            break;
        }

        /*  Get RX packet payload. Also skip HIF header. TODO: Think about removing the HIF header in HIF driver. */
        idex_header = (pfe_idex_frame_header_t *)((addr_t)pfe_hif_pkt_get_data(pkt) + sizeof(pfe_ct_hif_rx_hdr_t));
        i_phy_id = pfe_hif_pkt_get_ingress_phy_id(pkt);

        switch (idex_header->type)
        {
            case IDEX_FRAME_CTRL_REQUEST:
            {
                /*  Frame is IDEX request */
                idex_req = (pfe_idex_request_t *)((addr_t)idex_header + sizeof(pfe_idex_frame_header_t));

#ifdef IDEX_CFG_VERBOSE
                NXP_LOG_DEBUG("Request %u received\n", (uint_t)oal_ntohl(idex_req->seqnum));
#endif /* IDEX_CFG_VERBOSE */

                switch (idex_req->type)
                {
                    case IDEX_MASTER_DISCOVERY:
                    {
                        if (pfe_hif_pkt_get_data_len(pkt) < (sizeof(pfe_idex_frame_header_t)+sizeof(pfe_idex_msg_master_discovery_t)))
                        {
                            NXP_LOG_ERROR("Invalid payload length\n");
                        }
                        else
                        {
                            NXP_LOG_ERROR("Not implemented\n");
                        }

                        break;
                    }

                    case IDEX_RPC:
                    {
                        pfe_idex_msg_rpc_t *rpc_req = (pfe_idex_msg_rpc_t *)((addr_t)idex_req + sizeof(pfe_idex_request_t));
                        void *rpc_msg_payload_ptr = (void *)((addr_t)rpc_req + sizeof(pfe_idex_msg_rpc_t));

                        if (NULL != idex->rpc_cbk)
                        {
                            /*  Save source interface and current IDEX request reference */
                            idex->cur_req_phy_id = i_phy_id;
                            idex->cur_req = idex_req;

                            /*  Call RPC callback. Response shall be generated inside the callback using the pfe_idex_set_rpc_ret_val(). */
                            idex->rpc_cbk(i_phy_id, oal_ntohl(rpc_req->rpc_id), rpc_msg_payload_ptr, oal_ntohs(rpc_req->plen), idex->rpc_cbk_arg);

                            /*  Invalidate the current interface ID */
                            idex->cur_req_phy_id = PFE_PHY_IF_ID_INVALID;
                            idex->cur_req = NULL;
                        }
                        else
                        {
#ifdef IDEX_CFG_VERBOSE
                            NXP_LOG_DEBUG("RPC callback not found, request %u ignored\n", (uint_t)oal_ntohl(idex_req->seqnum));
#endif /* IDEX_CFG_VERBOSE */
                        }

                        break;
                    }

                    default:
                    {
                        NXP_LOG_WARNING("Unknown IDEX request type received: 0x%x\n", idex_req->type);
                        break;
                    }
                }

                break;
            } /* IDEX_FRAME_CTRL_REQUEST */

            case IDEX_FRAME_CTRL_RESPONSE:
            {
                /*  Frame is IDEX response */

                /*  Get response header */
                idex_resp = (pfe_idex_response_t *)((addr_t)idex_header + sizeof(pfe_idex_frame_header_t));

#ifdef IDEX_CFG_VERBOSE
                NXP_LOG_DEBUG("Response %u received\n", (uint_t)oal_ntohl(idex_resp->seqnum));
#endif /* IDEX_CFG_VERBOSE */

                /*  Matching request found. Check type. */
                switch (idex_resp->type)
                {
                    case IDEX_MASTER_DISCOVERY:
                    {
                        NXP_LOG_ERROR("Not implemented\n");
                        break;
                    }

                    case IDEX_RPC:
                    {
                        void *resp_payload = (void *)((addr_t)idex_resp + sizeof(pfe_idex_response_t));

                        /*  Finalize the associated request */
                        ret = pfe_idex_request_finalize(idex_resp->seqnum, resp_payload, oal_ntohs(idex_resp->plen));
                        if (EOK != ret)
                        {
                            NXP_LOG_ERROR("Can't finalize IDEX request %u: %d\n", (uint_t)oal_ntohl(idex_resp->seqnum), ret);
                        }

                        break;
                    }

                    default:
                    {
                        NXP_LOG_WARNING("Unknown IDEX response type received: 0x%x\n", idex_resp->type);
                        break;
                    }
                }

                break;
            } /* IDEX_FRAME_CTRL_RESPONSE */

            default:
            {
                /*  Unknown frame */
                NXP_LOG_WARNING("Unknown IDEX frame received\n");
                break;
            }
        } /* switch */

        /*  Release the received packet */
        pfe_hif_pkt_free(pkt);
    };
}

/**
 * @brief       TX confirmations processing
 */
static void pfe_idex_do_tx_conf(const pfe_hif_drv_client_t *client, const pfe_idex_t *idex)
{
    const pfe_idex_frame_header_t *idex_header;
    void *ref_ptr;

    while (TRUE)
    {
        /*  Get the transmitted frame reference */
        ref_ptr = pfe_hif_drv_client_receive_tx_conf(client, 0);
        if (NULL == ref_ptr)
        {
            break;
        }

        /*  We know that the reference is just pointer to transmitted
            buffer containing IDEX Header followed by rest of the IDEX
            frame. */
        idex_header = (pfe_idex_frame_header_t *)ref_ptr;
        switch (idex_header->type)
        {
            case IDEX_FRAME_CTRL_REQUEST:
            {
        #ifdef IDEX_CFG_VERBOSE
                pfe_idex_request_t *req_header = (pfe_idex_request_t *)((addr_t)idex_header + sizeof(pfe_idex_frame_header_t));

                NXP_LOG_DEBUG("Request %u transmitted\n", (uint_t)oal_ntohl(req_header->seqnum));
        #endif /* IDEX_CFG_VERBOSE */
        #if (FALSE == IDEX_IS_NOCPY)
                if (NULL != idex->txc_free_cbk)
                {
                    idex->txc_free_cbk(ref_ptr);
                }
        #else
                (void)idex;
        #endif
                break;
            }

            case IDEX_FRAME_CTRL_RESPONSE:
            {
        #ifdef IDEX_CFG_VERBOSE
                pfe_idex_response_t *resp_header = (pfe_idex_response_t *)((addr_t)idex_header + sizeof(pfe_idex_frame_header_t));

                NXP_LOG_DEBUG("Response %u transmitted\n", (uint_t)oal_ntohl(resp_header->seqnum));
        #endif /* IDEX_CFG_VERBOSE */
        #if (FALSE == IDEX_IS_NOCPY)
                if (NULL != idex->txc_free_cbk)
                {
                    idex->txc_free_cbk(ref_ptr);
                }
        #else
                (void)idex;
        #endif
                break;
            }

            default:
            {
                NXP_LOG_ERROR("Unknown IDEX frame transmitted\n");
                break;
            }
        }
    }
}

#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
/**
 * @brief       IHC client polling
 * @details     Called by MainFunction when client-related event happens (packet received, packet
 *              transmitted).
 */
void pfe_idex_ihc_poll(void)
{
    /*  Run TX routine */
    pfe_idex_do_tx_conf(pfe_idex.ihc_client, &pfe_idex);
    /*  Run RX routine */
    pfe_idex_do_rx(pfe_idex.ihc_client, &pfe_idex);

}
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

/**
 * @brief       Find, acknowledge, remove, and dispose request by sequence number
 * @details     1.) Pass response data
 *              2.) Marks request as "completed"
 * @param[in]   seqnum Sequence number identifying the request
 * @param[in]   resp_buf Pointer to response data buffer. If NULL no response is passed.
 * @param[in]   resp_len Number of byte in response buffer
 * @return      EOK if success, error code otherwise
 */
static errno_t pfe_idex_request_finalize(pfe_idex_seqnum_t seqnum, void *resp_buf, uint16_t resp_len)
{
    pfe_idex_request_t *req = &pfe_idex_request_frame.req;
    errno_t ret = EOK;

    (void)seqnum;
    /*  1.) Copy response data to buffer associated with request */
    if ((NULL != resp_buf) && (NULL != req->linked.config.resp_buf))
    {
        if (resp_len <= req->linked.config.resp_buf_len)
        {
            (void)autolibc_memcpy(req->linked.config.resp_buf, resp_buf, resp_len);
            req->linked.config.resp_buf_len = resp_len;
        }
        else
        {
            NXP_LOG_ERROR("Response buffer is too small!\n");
        }
    }

    /*  2.) Mark request as completed */
    req->state = IDEX_REQ_STATE_COMPLETED;

    return ret;
}

/**
 * @brief       Send IDEX response
 * @param[in]   dst_phy Destination physical interface ID
 * @param[in]   type Response type. Should match request type.
 * @param[in]   seqnum Sequence number in network endian. Should match request.
 * @param[in]   data_len Response payload length in number of bytes
 * @return      EOK if success, error code otherwise
 */
static errno_t pfe_idex_send_response(pfe_ct_phy_if_id_t dst_phy, pfe_idex_response_type_t type, pfe_idex_seqnum_t seqnum, uint16_t data_len)
{
    errno_t ret;

    /*  Add seqnum and type */
    pfe_idex_response_frame.resp.seqnum = seqnum;
    pfe_idex_response_frame.resp.type = type;
    pfe_idex_response_frame.resp.plen = oal_htons(data_len);

#ifdef IDEX_CFG_VERBOSE
    NXP_LOG_DEBUG("Sending response %u\n", (uint_t)oal_ntohl(seqnum));
#endif /* IDEX_CFG_VERBOSE */

    /*  Send it out within IDEX frame */
    ret = pfe_idex_send_frame(dst_phy, IDEX_FRAME_CTRL_RESPONSE, &pfe_idex_response_frame.resp, ((uint16_t)sizeof(pfe_idex_response_t) + data_len));
    if (EOK != ret)
    {
        NXP_LOG_ERROR("IDEX response TX failed\n");
    }

    return ret;
}

/**
 * @brief       Create and send IDEX request
 * @details     The call will:
 *              1.) Create request instance
 *              2.) Send the request to destination physical interface
 *              3.) In case of blocking do block until request is processed
 * @param[in]   dst_phy Destination physical interface ID
 * @param[in]   type Request type
 * @param[in]   data_len Request payload length in number of bytes
 * @param[in]   resp Response buffer. If NULL no response data will be provided.
 * @param[in]   resp_len Response buffer length
 * @return      EOK if success, error code otherwise
 */
static errno_t pfe_idex_request_send(pfe_ct_phy_if_id_t dst_phy, pfe_idex_request_type_t type, uint16_t data_len, void *resp, uint16_t resp_len)
{
    pfe_idex_t *        idex = (pfe_idex_t *)&pfe_idex;
    pfe_idex_request_t *req;
    errno_t             ret;
    pfe_idex_seqnum_t   seqnum;
    uint32_t            timeout_us = 1500U * 1000U;
    /*  Wait 1ms */
    const uint32_t timeout_step = 1000U;
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
    pfe_hif_drv_t *hif_drv;
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

    /*  1.) Create the request instance with room for request payload */
    req = &pfe_idex_request_frame.req;

    /*  Only initialize header, payload will be added below */
    (void)autolibc_memset((void *)req, 0, sizeof(pfe_idex_request_t));

    /*  Assign sequence number, type, and destination PHY ID */
    seqnum = oal_htonl(idex->req_seq_num);
    idex->req_seq_num++;
    req->seqnum = seqnum;
    req->type = type;
    req->dst_phy_id = dst_phy;
    req->linked.config.timeout = IDEX_CFG_REQ_TIMEOUT_SEC;
    req->state = IDEX_REQ_STATE_NEW;
    req->linked.config.resp_buf = resp;
    req->linked.config.resp_buf_len = resp_len;

    /*  2.) Send the request */
#ifdef IDEX_CFG_VERBOSE
    NXP_LOG_DEBUG("Sending IDEX request %u\n", (uint_t)oal_ntohl(req->seqnum));
#endif /* IDEX_CFG_VERBOSE */
    ret = pfe_idex_send_frame(dst_phy, IDEX_FRAME_CTRL_REQUEST, req, ((uint16_t)sizeof(pfe_idex_request_t) + data_len));
    if (EOK != ret)
    {
        NXP_LOG_ERROR("IDEX request TX failed\n");
    }
    else
    {
        /*  Request transmitted. Will be released once it is processed. */

        /*  3.) Block until response is received or timeout occurred. RX and
            TX processing is expected to be done asynchronously in
            pfe_idex_ihc_handler(). */
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
        hif_drv = pfe_hif_drv_client_get_drv(idex->ihc_client);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
        for (; timeout_us > 0U; timeout_us -= timeout_step)
        {
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
            pfe_hif_drv_tx_job(hif_drv);
            pfe_hif_drv_rx_job(hif_drv);
            pfe_idex_ihc_poll();
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
            if (IDEX_MASTER_DISCOVERY == type)
            {
                NXP_LOG_ERROR("Not implemented\n");
            }
            else
            {
                /*  This is blocking type. We must wait until the request
                is completed. */
                if (IDEX_REQ_STATE_COMPLETED == req->state)
                {
                    ret = EOK;
                    break;
                }
            }

            /*  Wait a bit */
            if (FALSE == oal_irq_in_atomic())
            {
                oal_time_usleep(timeout_step);
            }
            else
            {
                oal_time_udelay(timeout_step);
            }
        }

        if (0U == timeout_us)
        {
            NXP_LOG_ERROR("IDEX request %u timed-out\n", (uint_t)oal_ntohl(req->seqnum));
#ifdef IDEX_CFG_VERY_VERBOSE
            if (IDEX_REQ_STATE_NEW == req->state)
            {
                NXP_LOG_DEBUG("Request %u not transmitted or not responded\n", (uint_t)oal_ntohl(req->seqnum));
            }
            else
            {
                NXP_LOG_DEBUG("Request %u state is: %d\n", (uint_t)oal_ntohl(req->seqnum), req->state);
            }
#endif /* IDEX_CFG_VERY_VERBOSE */
            ret = ETIMEDOUT;
        }
        else
        {
            /*  Response data is written in 'resp' */
            ;
        }
    }

    return ret;
}

/**
 * @brief       Send IDEX frame
 * @param[in]   dst_phy Destination physical interface ID
 * @param[in]   type Type of frame
 * @param[in]   data Pointer to frame payload
 * @param[in]   data_len Payload length in number of bytes
 * @return      EOK success, error code otherwise
 */
static errno_t pfe_idex_send_frame(pfe_ct_phy_if_id_t dst_phy, pfe_idex_frame_type_t type, const void *data, uint16_t data_len)
{
    pfe_idex_frame_header_t *idex_hdr, *idex_hdr_pa;
    errno_t                  ret;
    pfe_ct_hif_tx_hdr_t *tx_hdr;
    hif_drv_sg_list_t        sg_list = { 0U };
    pfe_hif_drv_t *hif_drv;
    pfe_hif_chnl_t *hif_chnl;
#if (TRUE == IDEX_IS_NOCPY)
    void *payload;
    uint16_t buf_offset;
#endif /* IDEX_IS_NOCPY */

    /*  Get IDEX frame buffer */
    hif_drv = pfe_hif_drv_client_get_drv(pfe_idex.ihc_client);
    if (NULL == hif_drv)
    {
        NXP_LOG_ERROR("Get hif_drv instance associated with the client failed\n");
        ret = ENOENT;
    }
    else
    {
        hif_chnl = pfe_hif_drv_get_chnl(hif_drv);
        if (NULL == hif_chnl)
        {
            NXP_LOG_ERROR("Get channel associated with the hif_drv instance failed\n");
            ret = ENOENT;
        }
        else
        {
#if (TRUE == IDEX_IS_NOCPY)
            idex_hdr = (pfe_idex_frame_header_t *)pfe_hif_chnl_bmu_alloc_buf_va(hif_chnl);
            if (NULL == idex_hdr)
            {
                NXP_LOG_ERROR("Memory allocation failed\n");
                ret = ENOMEM;
            }
            else
            {
                idex_hdr_pa = pfe_hif_chnl_bmu_get_buf_pa(hif_chnl, (addr_t)idex_hdr);
                if (NULL == idex_hdr_pa)
                {
                    NXP_LOG_ERROR("VA to PA conversion failed\n");
                    pfe_hif_chnl_bmu_free_buf(hif_chnl, (addr_t)idex_hdr);
                    ret = ENOMEM;
                }
                else
                {
                    /* Fill the header */
                    idex_hdr->dst_phy_if = dst_phy;
                    idex_hdr->type = type;

                    /* TX buffer for HIF NOCPY is allocated directly from BMU2.
                    The whole IDEX frame needs to fit into it, so the IDEX header and payload are copied into the TX buffer. */
                    buf_offset = pfe_hif_chnl_get_lmem_hdr_size(hif_chnl) + 256U + (uint16_t)sizeof(pfe_ct_hif_tx_hdr_t);
                    (void)autolibc_memcpy((void *)((addr_t)idex_hdr + buf_offset), idex_hdr, sizeof(pfe_idex_frame_header_t));
                    /* Add payload */
                    payload = (void *)((addr_t)idex_hdr + sizeof(pfe_idex_frame_header_t));
                    (void)autolibc_memcpy((void *)((addr_t)payload + buf_offset), data, data_len);
#else
                    /*  Get IDEX frame buffer, see pfe_idex_request_frame_t, pfe_idex_response_frame_t */
                    idex_hdr = (pfe_idex_frame_header_t *)((addr_t)data - sizeof(pfe_idex_frame_header_t));
                
                    /* Fill the header */
                    idex_hdr->dst_phy_if = dst_phy;
                    idex_hdr->type = type;
                
                    /* see pfe_idex_request_frame_t, pfe_idex_response_frame_t */
                    idex_hdr = (pfe_idex_frame_header_t *)((addr_t)idex_hdr - sizeof(pfe_ct_hif_tx_hdr_t));
                    idex_hdr_pa = oal_mm_virt_to_phys_contig(idex_hdr);
                    if (NULL == idex_hdr_pa)
                    {
                        NXP_LOG_ERROR("VA to PA conversion failed\n");
                        ret = ENOMEM;
                    }
                    else
                    {
#endif /* IDEX_IS_NOCPY */

                        /*  Build SG list
                        TODO: The SG list could be used as reference to all buffers and used to
                        release them within TX confirmation task when used as 'ref_ptr' argument of
                        ..._ihc_sg_pkt() instead of idex_hdr. */
                        sg_list.size = 1U;
                        sg_list.dst_phy = dst_phy;
                        sg_list.items[0].data_va = idex_hdr;
                        sg_list.items[0].data_pa = idex_hdr_pa;
                        sg_list.items[0].len = (uint32_t)sizeof(pfe_ct_hif_tx_hdr_t) + (uint32_t)sizeof(pfe_idex_frame_header_t) + (uint32_t)data_len;
    
                        /* Let PFE route the frame as IHC packet with known destination */
                    #if (TRUE == IDEX_IS_NOCPY)
                        tx_hdr = (pfe_ct_hif_tx_hdr_t *)((addr_t)idex_hdr + pfe_hif_chnl_get_lmem_hdr_size(hif_chnl) + 256U);
                        /* TX buffer for HIF NOCPY is allocated directly from BMU2.
                        We need to clear the buffer to avoid unexpected data */
                        (void)autolibc_memset(tx_hdr, 0, sizeof(pfe_ct_hif_tx_hdr_t));
                    #else   
                        tx_hdr = (pfe_ct_hif_tx_hdr_t *)idex_hdr;
                    #endif /* IDEX_IS_NOCPY */
                        tx_hdr->chid = hif_chnl->id;
                        tx_hdr->e_phy_ifs = oal_htonl(1UL << (uint8_t)sg_list.dst_phy);
                        tx_hdr->flags = (pfe_ct_hif_tx_flags_t)(HIF_TX_INJECT|HIF_TX_IHC);
    
                        /*  Send it out */
                        ret = pfe_hif_drv_client_xmit_sg_pkt(pfe_idex.ihc_client, 0U, &sg_list, (void *)idex_hdr);
                        if (EOK != ret)
                        {
                            NXP_LOG_ERROR("IDEX frame TX failed. Err %u\n", ret);
                    #if (TRUE == IDEX_IS_NOCPY)
                            pfe_hif_chnl_bmu_free_buf(hif_chnl, (addr_t)idex_hdr);
                    #endif /* IDEX_IS_NOCPY */
                        }
                        else
                        {
                            /*  Frame transmitted. Will be released once TX confirmation is received. */
                            ;
                        }
#if (TRUE == IDEX_IS_NOCPY)
                    }
                }
#else
            }
#endif /* IDEX_IS_NOCPY */
        }
    }

    return ret;
}

/**
 * @brief       Set IDEX RPC callback
 * @details     The callback will be called at any time when RPC request
 *              will be received.
 * @param[in]   cbk Callback to be called
 * @param[in]   arg Custom argument to be passed to the callback
 * @return      EOK if success, error code otherwise
 */
static errno_t pfe_idex_set_rpc_cbk(pfe_idex_rpc_cbk_t cbk, void *arg)
{
    pfe_idex_t *idex = &pfe_idex;

    idex->rpc_cbk_arg = arg;
    idex->rpc_cbk = cbk;

    return EOK;
}

/**
 * @brief       IDEX initialization routine
 * @details     The callback will be called at any time when RPC request
 *              will be received.
 * @param[in]   hif_drv The HIF driver instance to be used to transport the data
 * @param[in]   master Physical interface via which the master driver can be reached
 * @param[in]   hif The Platform HIF instance
 * @param[in]   cbk Callback to be called
 * @param[in]   arg Custom argument to be passed to the callback
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_idex_init(pfe_hif_drv_t *hif_drv, pfe_ct_phy_if_id_t master, pfe_hif_t *hif,
            pfe_idex_rpc_cbk_t cbk, void *arg, pfe_idex_tx_conf_free_cbk_t txcf_cbk)
{
    pfe_idex_t *idex = &pfe_idex;
    errno_t     ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if ((NULL == hif_drv) || (NULL == hif))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)autolibc_memset(idex, 0, sizeof(pfe_idex_t));

        idex->req_seq_num = (uint32_t)oal_util_rand();

        /*  Here we don't know even own interface ID... */
        idex->master_phy_if = master;
        idex->cur_req_phy_id = PFE_PHY_IF_ID_INVALID;
        idex->txc_free_cbk = txcf_cbk;

#ifdef PFE_CFG_PFE_MASTER
        NXP_LOG_INFO("IDEX-master @ interface %d\n", master);
#elif defined(PFE_CFG_PFE_SLAVE)
        NXP_LOG_INFO("IDEX-slave\n");
#else
#error Impossible configuration
#endif /* PFE_CFG_PFE_MASTER/PFE_CFG_PFE_SLAVE */

        /*  Register IHC client */
        idex->ihc_client = pfe_hif_drv_ihc_client_register(hif_drv, &pfe_idex_ihc_handler, NULL);
        if (NULL == idex->ihc_client)
        {
            NXP_LOG_ERROR("Can't register IHC client\n");
            pfe_idex_fini();
            ret = EFAULT;
        }
        else
        {
            ret = pfe_idex_set_rpc_cbk(cbk, arg);
#ifdef PFE_CFG_PFE_MASTER
            if (EOK == ret)
            {
                idex->hif = hif;
            }
#else
            (void)hif;
#endif /* PFE_CFG_PFE_MASTER */
        }
    }
    return ret;
}

/**
 * @brief       Finalize IDEX module
 */
void pfe_idex_fini(void)
{
    pfe_idex_t *idex = &pfe_idex;

#ifdef PFE_CFG_PFE_MASTER
    if(NULL != idex->hif)
    {
        /* Clear Master detect flags for all HIF channels */
        if (TRUE == pfe_hif_get_master_detect_cfg(idex->hif))
        {
            pfe_hif_clear_master_up(idex->hif);
        }
        idex->hif = NULL;
    }
#endif /* PFE_CFG_PFE_MASTER */

    idex->rpc_cbk = NULL;
    idex->rpc_cbk_arg = NULL;
    idex->txc_free_cbk = NULL;

    if (NULL != idex->ihc_client)
    {
        pfe_hif_drv_client_unregister(idex->ihc_client);
        idex->ihc_client = NULL;
    }
}

/**
 * @brief       Execute RPC against IDEX master. Blocking call.
 * @param[in]   id Request identifier to be passed to remote RPC callback
 * @param[in]   buf Buffer containing RPC argument data
 * @param[in]   buf_len Length of RPC argument data in the buffer
 * @param[in]   resp Response buffer. In case of successful call (EOK) the
 *              response data is written here.
 * @param[in]   resp_len Response buffer length. If response is bigger than this
 *              number of bytes, the buffer will not be written and error code
 *              indicating no memory condition ENOMEM will be returned.
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_idex_master_rpc(uint32_t id, const void *buf, uint16_t buf_len, void *resp, uint16_t resp_len)
{
    const pfe_idex_t *idex = &pfe_idex;

    return pfe_idex_rpc(idex->master_phy_if, id, buf, buf_len, resp, resp_len);
}

/**
 * @brief       Execute RPC. Blocking call.
 * @param[in]   dst_phy Physical interface ID where the request shall be sent
 * @param[in]   id Request identifier to be passed to remote RPC callback
 * @param[in]   buf Buffer containing RPC argument data
 * @param[in]   buf_len Length of RPC argument data in the buffer
 * @param[in]   resp Response buffer. In case of successful call (EOK) the
 *              response data is written here.
 * @param[in]   resp_len Response buffer length. If response is bigger than this
 *              number of bytes, the buffer will not be written and error code
 *              indicating no memory condition ENOMEM will be returned.
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_idex_rpc(pfe_ct_phy_if_id_t dst_phy, uint32_t id, const void *buf, uint16_t buf_len, void *resp, uint16_t resp_len)
{
    errno_t ret;
    const uint16_t resp_buf_size = (uint16_t)sizeof(pfe_idex_msg_rpc_t) + resp_len;
    uint16_t msg_plen;
    void *payload;

    /* clear response frame content */
    (void)autolibc_memset(&pfe_idex_response_frame, 0, sizeof(pfe_idex_response_frame));

    /* start assemble the request frame */
    (void)autolibc_memset(&pfe_idex_request_frame, 0, sizeof(pfe_idex_request_frame));

    pfe_idex_request_frame.msg.rpc_id = oal_htonl(id);
    pfe_idex_request_frame.msg.plen = oal_htons(buf_len);
    pfe_idex_request_frame.msg.rpc_ret = oal_htonl(EOK);

    payload = &pfe_idex_request_frame.arg;
    (void)autolibc_memcpy(payload, buf, buf_len);

    /*  This one is blocking */
    ret = pfe_idex_request_send(dst_phy, IDEX_RPC, (uint16_t)sizeof(pfe_idex_msg_rpc_t) + buf_len, &pfe_idex_response_frame.msg_rpc, resp_buf_size);

    if (EOK != ret)
    {
        /*  Transport error */
        NXP_LOG_ERROR("RPC transport failed: %d\n", ret);
    }
    else
    {
        /*  Get the remote return value from the response */
        /*  Sanity checks */
        if (id != oal_ntohl(pfe_idex_response_frame.msg_rpc.rpc_id))
        {
            NXP_LOG_ERROR("RPC response ID does not match the request\n");
            ret = EINVAL;
        }
        else
        {
            ret = (int32_t)oal_ntohl(pfe_idex_response_frame.msg_rpc.rpc_ret);
            msg_plen = oal_ntohs(pfe_idex_response_frame.msg_rpc.plen);

            /*  Copy RPC response data to caller's buffer */
            if (0U == msg_plen)
            {
#ifdef IDEX_CFG_VERBOSE
                NXP_LOG_DEBUG("RPC response without payload received\n");
#endif /* IDEX_CFG_VERBOSE */
            }
            else if (msg_plen > resp_len) /* if the response is too big */
            {
                NXP_LOG_ERROR("Caller's buffer is too small\n");
                ret = ENOMEM;
            }
            else /* there is response, it is not too big and we have buffer */
            {
                payload = &pfe_idex_response_frame.ret;
                (void)autolibc_memcpy(resp, payload, msg_plen);

#ifdef IDEX_CFG_VERBOSE
                NXP_LOG_DEBUG("%d bytes of RPC response received\n", msg_plen);
#endif /* IDEX_CFG_VERBOSE */
            }
        }
    }

    return ret;
}

/**
 * @brief       Set RPC response
 * @details     Function can ONLY be called within RPC callback (pfe_idex_rpc_cbk_t)
 *              to indicate the execution result.
 * @param[in]   retval Error code to be presented to RPC initiator
 * @param[in]   resp Buffer containing response data to be presented to
 *              the initiator. Can be NULL to return no data.
 * @param[in]   resp_len Size of the response in the buffer. Can be zero.
 * @return      EOK success, error code otherwise
 */
errno_t pfe_idex_set_rpc_ret_val(errno_t retval, void *resp, uint16_t resp_len)
{
    const pfe_idex_t *idex = &pfe_idex;
    pfe_idex_msg_rpc_t *rpc_req;
    void *payload;
    errno_t ret;

    /* start assemble the response frame */
    (void)autolibc_memset(&pfe_idex_response_frame, 0, sizeof(pfe_idex_response_frame));

    rpc_req = (pfe_idex_msg_rpc_t *)((addr_t)idex->cur_req + sizeof(pfe_idex_request_t));

    /*  Construct response message */
    pfe_idex_response_frame.msg_rpc.rpc_id = rpc_req->rpc_id; /* Already in correct endian */
    pfe_idex_response_frame.msg_rpc.plen = oal_htons(resp_len);
    pfe_idex_response_frame.msg_rpc.rpc_ret = oal_htonl(retval);

    payload = &pfe_idex_response_frame.ret;
    (void)autolibc_memcpy(payload, resp, resp_len);

    /*  Send the response */
    ret = pfe_idex_send_response(
                                    idex->cur_req_phy_id,   /* Destination */
                                    idex->cur_req->type,    /* Response type */
                                    idex->cur_req->seqnum,  /* Response sequence number */
                                    ((uint16_t)sizeof(pfe_idex_msg_rpc_t) + resp_len) /* Response payload length */
                                );
    if (EOK != ret)
    {
        NXP_LOG_ERROR("IDEX RPC response failed\n");
    }

    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
