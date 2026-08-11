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
 *  Copyright 2019-2024 NXP
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

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "pfe_cfg.h"
#include "oal.h"

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
#include "linked_list.h"
#include "pfe_hif_drv.h"
#include "pfe_hif.h"
#include "pfe_idex.h"
#include "pfe_platform_rpc.h"
#include "pfe_platform_cfg.h"

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define IDEX_IS_NOCPY (4 == PFE_CFG_LOCAL_IF_VALUE)
/**
 * @brief Maximum HIF clients to handle in IDEX server
 */
#define IDEX_MAX_CLIENTS    (4)
/**
 * @brief Enable debug diagnostic messages from IDEX
 */
/* #define IDEX_CFG_VERBOSE */
/**
 * @brief RESET request/response RPC_ID for IDEX 2.0
    Using for synchronization of sequence number and for IDEX version negotiation
 */
#define IDEX_RESET_RPC_ID   (0xFFFFFFFFU)

/**
 * @brief    IDEX request timeout in milliseconds between resending [DID-AAVBR-980m-MCAL]
 */
#ifndef PFE_CFG_IDEX_RESEND_DELAY_MS
#define PFE_CFG_IDEX_RESEND_DELAY_MS   (100U)
#endif

/**
 * @brief   IDEX request maximum retry count
 */
#ifndef PFE_CFG_IDEX_RESEND_COUNT
#define PFE_CFG_IDEX_RESEND_COUNT   (40U)
#endif

/**
 * @brief TODO: The cast macros below shall be replaced by it's safer variant - cyber-security topic.
 * 
*/
#define UNSAFE_CAST_INT_TO_UINT8(value) ((uint8_t)(value))
#define UNSAFE_CAST_INT_TO_UINT16(value) ((uint16_t)(value))
#define UNSAFE_CAST_INT_TO_UINT32(value) ((uint32_t)(value))

/**
 * @brief Add A, B and mask integer overflow after add math operation
 */
#define ADDU32_WRAP(A, B) (uint32_t)(((uint64_t)(A) + (uint64_t)(B)) & UINT32_MAX)

/**
 * @brief Useful in the interrupt mode to qualify certain data as volatile
 */
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
#define USE_VOLATILE    volatile
#else
#define USE_VOLATILE
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
 * @brief       IDEX sequence number type
 */
typedef uint32_t pfe_idex_seqnum_t;

ct_assert(sizeof(pfe_idex_seqnum_t) == sizeof(uint32_t));

/**
 * @brief        IDEX version number for features improvement
 */
typedef enum __attribute__((packed))
{
    IDEX_VERSION_1 = 1U,
    IDEX_VERSION_2 = 2U
} pfe_idex_version_t;

ct_assert(sizeof(pfe_idex_version_t) == sizeof(uint8_t));

/**
 * @brief   IDEX Frame types
 */
typedef enum __attribute__((packed))
{
    /**
     * @brief Request. Frames of this type are expected to be responded by a remote instance
     */
    IDEX_FRAME_CTRL_REQUEST = 0U,
    /**
     * @brief Response. Contains information about remote result
     */
    IDEX_FRAME_CTRL_RESPONSE = 1U,
    /*  Dummy/invalid frame, not intended to be processed when received */
    IDEX_FRAME_CTRL_DUMMY = 100
} pfe_idex_frame_type_t;

ct_assert(sizeof(pfe_idex_frame_type_t) == sizeof(uint8_t));

/**
 * @brief   IDEX Request message types
 */
typedef enum __attribute__((packed))
{
    /**
     * @brief Master discovery message. Not used or implemented
     */
    IDEX_MASTER_DISCOVERY = 0U,
    /**
     * @brief RPC request for calling RPC function
     */
    IDEX_RPC = 1U
} pfe_idex_request_type_t;

ct_assert(sizeof(pfe_idex_request_type_t) == sizeof(uint8_t));

/**
 * @brief   IDEX Response types
 */
typedef pfe_idex_request_type_t pfe_idex_response_type_t;

ct_assert(sizeof(pfe_idex_response_type_t) == sizeof(uint8_t));
/**
 * @brief   RESET Request/Response for IDEX 2.0
 */
typedef struct __attribute__((packed))
{
    /* Reset seq number to this value */
    pfe_idex_seqnum_t seqnum;
    /* Version of IDEX for backward and forward compatibility */
    pfe_idex_version_t version;
} pfe_idex_msg_reset_t;

ct_assert(sizeof(pfe_idex_msg_reset_t) == (sizeof(uint32_t) + sizeof(uint8_t)));

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
    /*    Request committed for transmission. Can be timed-out. */
    IDEX_REQ_STATE_COMMITTED,
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
    USE_VOLATILE pfe_idex_request_state_t state;
    /*    Padding only to keep compatibility, not used */
    uint8_t padding[30U];
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
 * @brief    This is IDEX Client structure for Master to save information about Slave
 */
typedef struct
{
    pfe_idex_seqnum_t seqnum;      /*    Current sequence number [DID-AAVBR-980c-MCAL] */
    pfe_idex_version_t version;    /*    IDEX version, for backward compatibility */
    pfe_ct_phy_if_id_t phy_id;     /*    Physical interface of the client */
    pfe_idex_response_t *response; /*    Last IDEX response for resending in case of same seqnum */
    pfe_idex_msg_rpc_t rpc_msg;    /*    Current IDEX RPC message request */
} pfe_remote_client_t;

/**
 * @brief    This is IDEX Server structure for Client to save information about Master
 */
typedef struct
{
    pfe_idex_seqnum_t seqnum;    /*    Current sequence number [DID-AAVBR-980c-MCAL] */
    pfe_idex_version_t version;  /*    IDEX version, for backward compatibility */
    pfe_ct_phy_if_id_t phy_id;   /*    Physical interface of the server */
    pfe_idex_request_t *request; /*    Current IDEX request */
    pfe_idex_msg_rpc_t *rpc_msg; /*    Current IDEX RPC message response */
} pfe_remote_server_t;

/**
 * @brief   This is IDEX instance representation type
 */
typedef struct
{
    pfe_hif_drv_client_t *ihc_client;              /*  HIF driver IHC client used for communication [DID-AAVBR-980b-MCAL] */
    pfe_idex_tx_conf_free_cbk_t txc_free_cbk;      /*  Callback to release frame buffers on Tx confirmation */
    pfe_idex_rpc_cbk_t rpc_cbk;                    /*  Callback to be called in case of RPC requests */
    void *rpc_cbk_arg;                             /*  RPC callback argument */
    pfe_hif_t *hif;                                /*  HIF module, for Master-up signaling */
    bool_t is_server;                              /*  IDEX is acting as server when TRUE    */
    bool_t is_up;                                  /*  TRUE if HIF connection is UP */
    struct
    {
        pfe_remote_server_t server;                    /*  Client has Server information */
        pfe_remote_client_t clients[IDEX_MAX_CLIENTS]; /*  Server has information about every client */
    } remote;
    oal_mutex_t rpc_req_lock;                      /*  Requests mutex blocking communication */
    bool_t rpc_req_lock_init;                      /*  Flag indicating that mutex is initialized */
    /**
     * @brief Free running statistics counters - can be exposed in future. Reset during pfe_idex_init()
     */
    struct {
        uint32_t rx_count;
        uint32_t rx_aliens;
        uint32_t rx_dups;
        uint32_t rx_unknowns;
        uint32_t rx_fails;
        uint32_t tx_count;
        uint32_t tx_retries;
        uint32_t tx_max_retries;
        uint32_t tx_skips;
    } stats;
} pfe_idex_t;

/* IMG-EPP.HW_Technical_Reference_Manual_10.pdf page 39 */
#define IMG_EPP_MAX_PACKET_SIZE 1522

/**
 * @brief Type used to create properly sized buffer for pfe_idex_rpc calls
 */
typedef struct __attribute__((packed))
{
    pfe_ct_hif_tx_hdr_t hif_tx_hdr;
    pfe_idex_frame_header_t frame_header;
    pfe_idex_request_t req;
    pfe_idex_msg_rpc_t msg; /* IDEX RPC Message header */
    uint8_t arg[IMG_EPP_MAX_PACKET_SIZE - sizeof(pfe_idex_frame_header_t) - sizeof(pfe_idex_request_t) - sizeof(pfe_idex_msg_rpc_t)];
} pfe_idex_request_frame_t;

/**
 * @brief Type used to create properly sized buffer for pfe_idex_set_rpc_ret_val calls
 */
typedef struct __attribute__((packed))
{
    pfe_ct_hif_tx_hdr_t hif_tx_hdr;
    pfe_idex_frame_header_t frame_header;
    pfe_idex_response_t resp;   /* IDEX Response Header */
    pfe_idex_msg_rpc_t msg_rpc; /* IDEX RPC Message header */
    uint8_t ret[IMG_EPP_MAX_PACKET_SIZE - sizeof(pfe_idex_frame_header_t) - sizeof(pfe_idex_response_t) - sizeof(pfe_idex_msg_rpc_t)];
} pfe_idex_response_frame_t;

typedef struct __attribute__((packed))
{
    pfe_ct_hif_tx_hdr_t hif_tx_hdr;
    pfe_idex_frame_header_t frame_header;
    uint8_t dummy_data[64U - sizeof(pfe_idex_frame_header_t)];  /* Dummy frame payload has to have certain minimum length, see: AAVB-9118 */
} pfe_idex_dummy_frame_t;

/*==================================================================================================
*                                     GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/
#define ETH_43_PFE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/*  Local IDEX instance storage */
static pfe_idex_t pfe_idex = { 0U };

/**
 * @brief Current client that is waiting for response
 */
static pfe_remote_client_t *idex_current_client;

#define ETH_43_PFE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED_BUF_MEM
#include "Eth_43_PFE_MemMap.h"
pfe_idex_response_frame_t pfe_idex_response_frame;
pfe_idex_request_frame_t pfe_idex_request_frame;
pfe_idex_dummy_frame_t pfe_idex_dummy_frame;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_BUF_MEM
#include "Eth_43_PFE_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static void pfe_idex_do_rx(pfe_hif_drv_client_t *client, pfe_idex_t *idex);
static errno_t pfe_idex_send_response(pfe_ct_phy_if_id_t dst_phy, pfe_idex_response_type_t type, pfe_idex_seqnum_t seqnum, uint16_t data_len);
static errno_t pfe_idex_send_frame(pfe_ct_phy_if_id_t dst_phy, pfe_idex_frame_type_t type, const void *data, uint16_t data_len);
static errno_t pfe_idex_request_send(pfe_ct_phy_if_id_t dst_phy, pfe_idex_request_type_t type, const uint32_t resend_count, uint16_t data_len);
static errno_t pfe_idex_ihc_handler(pfe_hif_drv_client_t *client, void *arg, uint32_t event, uint32_t qno);
static errno_t pfe_idex_set_rpc_cbk(pfe_idex_rpc_cbk_t cbk, void *arg);
static errno_t pfe_idex_prep_tx_header_xmit(pfe_idex_frame_header_t *idex_hdr, hif_drv_sg_list_t sg_list, pfe_hif_chnl_t *hif_chnl);
static errno_t check_time_out(uint32_t *timeout_ms, bool_t *end_sending, pfe_idex_request_t *request);
#ifdef PFE_CFG_PFE_MASTER
static bool_t get_client_index(pfe_ct_phy_if_id_t i_phy_id, uint32_t * const p_client_index);
static errno_t set_idex_sequence_number(pfe_remote_client_t *client, pfe_idex_seqnum_t seqnum, bool_t *break_switch);
static void process_idex_request(pfe_idex_t *idex, pfe_idex_frame_header_t *idex_header, pfe_ct_phy_if_id_t i_phy_id, const pfe_hif_pkt_t *const pkt);
#endif /* PFE_CFG_PFE_MASTER */
#ifdef PFE_CFG_PFE_SLAVE
static void process_idex_response(pfe_idex_frame_header_t *idex_header, pfe_hif_pkt_t *const p_pkt, pfe_ct_phy_if_id_t i_phy_id);
#endif /* PFE_CFG_PFE_SLAVE */

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       IHC client event handler
 * @details     Called by HIF when client-related event happens (packet received, packet
 *              transmitted).
 * @note        Invoked from interrupt context.
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

        default:
        {
            NXP_LOG_WARNING("Unexpected IHC event: 0x%x\n", (uint_t)event);
            ret = EINVAL;
            break;
        }
    }

    return ret;
}

#ifdef PFE_CFG_PFE_MASTER
/**
 * @brief           Get the client index object.
 * @param[in]       i_phy_id client phy ID
 * @param[out]      p_client_index client integer ID starting at 0
 * @return          TRUE on success
 */
static bool_t get_client_index(pfe_ct_phy_if_id_t i_phy_id, uint32_t * const p_client_index)
{
    bool_t ret = TRUE;

    if ((i_phy_id >= PFE_PHY_IF_ID_HIF0) && (i_phy_id <= PFE_PHY_IF_ID_HIF3))
    {
        *p_client_index = UNSAFE_CAST_INT_TO_UINT32((uint32_t)i_phy_id - (uint32_t)PFE_PHY_IF_ID_HIF0);
    }
    else
    {
        ret = FALSE;
    }
    return ret;
}
#endif /* PFE_CFG_PFE_MASTER */

#ifdef PFE_CFG_PFE_MASTER


/**
 * @brief       helper function for IDEX request processing to check idex sequence number.
 */
static errno_t set_idex_sequence_number(pfe_remote_client_t *client, pfe_idex_seqnum_t seqnum, bool_t *break_switch)
{
    errno_t ret = EOK;

    *break_switch = FALSE;

    /*In IDEX 2.0 check sequence number */
    if (client->version >= IDEX_VERSION_2)
    {
        /* Duplicated request received, only resend last response */
        if (client->seqnum == seqnum)
        {
            NXP_LOG_DEBUG("IDEX Duplicated RPC request seqnum=%u, resp_len=%u, phy_id=%u\n",
                        (uint_t)seqnum, (uint16_t)oal_ntohs(client->response->plen), client->phy_id);
            pfe_idex.stats.rx_dups = ADDU32_WRAP(pfe_idex.stats.rx_dups, 1U);
            if (client->response != NULL_PTR)
            {
                /* Response should be still present in pfe_idex_response_frame - no need to reload */
                /*    Send it out within IDEX frame */
                ret = pfe_idex_send_frame(client->phy_id, IDEX_FRAME_CTRL_RESPONSE, client->response,
                                        ((uint16_t)sizeof(pfe_idex_response_t) + (uint16_t)oal_ntohs(client->response->plen)));
                if (EOK != ret)
                {
                    NXP_LOG_WARNING("IDEX resending response TX failed\n");
                }
            }
            *break_switch = TRUE;
        }
        /*    New sequence number received, should be +1. Continue processing */
        else if ((client->seqnum + 1U) == seqnum)
        {
            client->seqnum = seqnum;
        }
        /* Wrong sequence number received */
        else
        {
            NXP_LOG_WARNING("Wrong sequence number %u\n", (uint_t)seqnum);
            pfe_idex.stats.rx_fails = ADDU32_WRAP(pfe_idex.stats.rx_fails, 1U);
            *break_switch = TRUE;
        }
    }
    else
    {
        client->seqnum = seqnum;
    }

    return ret;
}

/**
 * @brief       IDEX request processing.
 * @note        In interrupt mode invoked from interrupt context. Main context otherwise.
 */
static void process_idex_request(pfe_idex_t *idex, pfe_idex_frame_header_t *idex_header, pfe_ct_phy_if_id_t i_phy_id, const pfe_hif_pkt_t *const pkt)
{
    pfe_remote_client_t *   client;
    pfe_idex_request_t *    idex_req;
    uint32_t                client_index = 0U;
    errno_t                 ret = EOK;
    pfe_idex_msg_rpc_t *    rpc_req = NULL_PTR;
    uint32_t                rpc_id = 0U;
    void *                  rpc_msg_payload_ptr = NULL_PTR;
    pfe_idex_msg_reset_t *  reset_req = NULL_PTR;

    if(FALSE == get_client_index(i_phy_id, &client_index))
    {
        NXP_LOG_ERROR("Invalid HIF ID: %u\n", (uint_t) i_phy_id);
        ret = EINVAL;
    }

    if(EOK == ret)
    {
        /*  Frame is IDEX request */
        idex_req = (pfe_idex_request_t *)((addr_t)idex_header + sizeof(pfe_idex_frame_header_t));
        pfe_idex_seqnum_t seqnum = (pfe_idex_seqnum_t)oal_ntohl(idex_req->seqnum);

        client = &idex->remote.clients[client_index];
        client->phy_id = i_phy_id;

        /*    Save current IDEX client reference to global pointer */
        idex_current_client = client;

        switch (idex_req->type)
        {
        /*    IDEX_RPC REQUEST received from client    */
        case IDEX_RPC:
        {
            if (pfe_hif_pkt_get_data_len(pkt) < (sizeof(pfe_ct_hif_rx_hdr_t) + sizeof(pfe_idex_frame_header_t) + sizeof(pfe_idex_request_t) + sizeof(pfe_idex_msg_rpc_t)))
            {
                NXP_LOG_WARNING("Invalid RPC request message length\n");
                pfe_idex.stats.rx_fails = ADDU32_WRAP(pfe_idex.stats.rx_fails, 1U);
                break;
            }

            rpc_req = (pfe_idex_msg_rpc_t *)((addr_t)idex_req + sizeof(pfe_idex_request_t));
            rpc_id = (uint32_t)oal_ntohl(rpc_req->rpc_id);
            rpc_msg_payload_ptr = (void *)((addr_t)rpc_req + sizeof(pfe_idex_msg_rpc_t));

            /*    IDEX_RESET REQUEST received. Used for seqnumber and version synchronization [DID-AAVBR-980p-MCAL] */
            if (IDEX_RESET_RPC_ID == rpc_id)
            {
                reset_req = (pfe_idex_msg_reset_t *)rpc_msg_payload_ptr;
                client->seqnum = (pfe_idex_seqnum_t)oal_ntohl(reset_req->seqnum); /*[DID-AAVBR-980p1-MCAL] */
                client->version = reset_req->version;                             /*[DID-AAVBR-980p2-MCAL] */
    #ifdef IDEX_CFG_VERBOSE
                NXP_LOG_INFO("IDEX: RESET Request received: seqnum=%u, version=%u, phy_id=%u\n",
                            (uint_t)client->seqnum, client->version, i_phy_id);
    #endif /* IDEX_CFG_VERBOSE */

                /*    Send response with same data to acknowledge server version */
                (void)autolibc_memcpy(&pfe_idex_response_frame.msg_rpc, rpc_req, sizeof(pfe_idex_msg_rpc_t) + sizeof(pfe_idex_msg_reset_t));
                ret = pfe_idex_send_response(client->phy_id, IDEX_RPC, seqnum, sizeof(pfe_idex_msg_rpc_t) + sizeof(pfe_idex_msg_reset_t));
                if (ret != EOK)
                {
                    NXP_LOG_WARNING("Problem to send RESET response\n");
                }

                break;
            } /* IDEX_RESET */

    #ifdef IDEX_CFG_VERBOSE
            NXP_LOG_INFO("IDEX: RPC Request received: cmd=%u, plen=%u, seqnum=%u, phy_id=%u\n",
                        rpc_id, (uint16_t)oal_ntohs(rpc_req->plen), (uint_t)oal_ntohl(idex_req->seqnum), i_phy_id);
    #endif /* IDEX_CFG_VERBOSE */

            {
                bool_t break_switch = FALSE;
                /*set sequence number*/
                ret = set_idex_sequence_number(client, seqnum, &break_switch);
                if(TRUE == break_switch)
                {
                    break;
                }
            }

            if (NULL_PTR != idex->rpc_cbk)
            {
                /*    Save RPC message for later response generation    */
                (void)autolibc_memcpy(&client->rpc_msg, rpc_req, sizeof(pfe_idex_msg_rpc_t));

                /*  Call RPC callback. Response shall be generated inside the callback using the pfe_idex_set_rpc_ret_val(). */
                idex->rpc_cbk(i_phy_id, rpc_id, rpc_msg_payload_ptr, (uint16_t)oal_ntohs(rpc_req->plen), idex->rpc_cbk_arg);
            }
            else
            {
    #ifdef IDEX_CFG_VERBOSE
                NXP_LOG_WARNING("RPC callback not found, request seqnum=%u ignored\n", (uint_t)oal_ntohl(idex_req->seqnum));
    #endif /* IDEX_CFG_VERBOSE */
            }

            break;
        } /* case IDEX_RPC */

        default:
        { /* Invalid request [DID-AAVBR-980t-MCAL] */
            NXP_LOG_WARNING("Unknown IDEX request type received: 0x%x\n", idex_req->type);
            pfe_idex.stats.rx_unknowns = ADDU32_WRAP(pfe_idex.stats.rx_unknowns, 1U);
            break;
        }
        }
    } /* if EOK == ret */
}
#endif /* PFE_CFG_PFE_MASTER */

#ifdef PFE_CFG_PFE_SLAVE
/**
 * @brief       IDEX response processing.
 * @note        This can be called even if slave's timeout waiting period for response from the master expires. In other
 *              words the slave can receive a delayed response from the master.
 *              In interrupt mode invoked from interrupt context. Main context otherwise..
 */
static void process_idex_response(pfe_idex_frame_header_t *idex_header, pfe_hif_pkt_t *const p_pkt, pfe_ct_phy_if_id_t i_phy_id)
{
    pfe_idex_response_t *   idex_resp;
    pfe_remote_server_t *   server = (pfe_remote_server_t *)&pfe_idex.remote.server;

#ifndef IDEX_CFG_VERBOSE
    (void)i_phy_id;
#endif

    /*  Get response header */
    idex_resp = (pfe_idex_response_t *)((addr_t)idex_header + sizeof(pfe_idex_frame_header_t));

    switch (idex_resp->type)
    {
    /* IDEX_RPC RESPONSE */
    case IDEX_RPC:
    {
        if (pfe_hif_pkt_get_data_len(p_pkt) < (sizeof(pfe_ct_hif_rx_hdr_t) + sizeof(pfe_idex_frame_header_t) + sizeof(pfe_idex_response_t) + sizeof(pfe_idex_msg_rpc_t)))
        {
            NXP_LOG_WARNING("Invalid RPC response message length\n");
            break;
        }

        /*    Response on RCP request. Finalize the associated request message */
        pfe_idex_msg_rpc_t *rpc_msg = server->rpc_msg;
        pfe_idex_msg_rpc_t *rpc_resp = (pfe_idex_msg_rpc_t *)((addr_t)idex_resp + sizeof(pfe_idex_response_t));

        pfe_idex_seqnum_t seqnum = (uint32_t)oal_ntohl(idex_resp->seqnum);
        uint16_t payload_length = (uint16_t)oal_ntohs(rpc_resp->plen);

#ifdef IDEX_CFG_VERBOSE
        NXP_LOG_INFO("IDEX: RPC Response received: cmd=%u, return=%u, plen=%u, seqnum=%u, phy_id=%u",
                     (uint32_t)oal_ntohl(rpc_resp->rpc_id), (uint32_t)oal_ntohl(rpc_resp->rpc_ret), payload_length, (uint_t)seqnum, i_phy_id);
#endif /* IDEX_CFG_VERBOSE */

        /*    Sequence number in response must be the same as in request [DID-AAVBR-980c-MCAL] */
        if (server->version >= IDEX_VERSION_2)
        {
            if(seqnum != server->seqnum)
            {   /* We've most likely got an old response - a new one might come soon so don't fail here. */
                NXP_LOG_WARNING("IDEX: Wrong sequence number in RPC response: %u!=%u\n", (uint_t)seqnum, (uint_t)server->seqnum);
                break;
            }
        }

        /*    If there is waiting RPC request buffer, copy data to it and continue */
        if (NULL_PTR != rpc_msg)
        {
            /*    In rpc_msg->plen is temporarily saved buffer length */
            if (payload_length <= rpc_msg->plen)
            {
                /*    Copy payload */
                (void)autolibc_memcpy((void *)((addr_t)rpc_msg + sizeof(pfe_idex_msg_rpc_t)),
                                      (void *)((addr_t)rpc_resp + sizeof(pfe_idex_msg_rpc_t)), payload_length);
                rpc_msg->rpc_id = (uint32_t)oal_ntohl(rpc_resp->rpc_id);
                rpc_msg->rpc_ret = (uint32_t)oal_ntohl(rpc_resp->rpc_ret);
                rpc_msg->plen = payload_length;

                if(NULL_PTR != server->request)
                { /* At this moment slave's request could already timeouted and could be set to null. */
                    server->request->state = IDEX_REQ_STATE_COMPLETED;
                }
            }
            else
            {
                /* Don't send response if there is no room for required payload */
                NXP_LOG_ERROR("RPC Response buffer is too small! %u < %u\n", payload_length, rpc_msg->plen);
                if(NULL_PTR != server->request)
                { /* At this moment slave's request could already timeouted and could be set to null. */
                    server->request->state = IDEX_REQ_STATE_INVALID;
                    break;
                }
            }
        }
        break;
    } /* case IDEX_RPC RESPONSE */

    default:
    {
        NXP_LOG_WARNING("Unknown IDEX frame received %u\n", idex_header->type);
        break;
    }
    }
}
#endif /* PFE_CFG_PFE_SLAVE */

/**
 * @brief       RX processing.
 * @note        In interrupt mode invoked from interrupt context. Main context otherwise.
 */
static void pfe_idex_do_rx(pfe_hif_drv_client_t *hif_client, pfe_idex_t *idex)
{
    pfe_hif_pkt_t *             pkt;
    pfe_idex_frame_header_t *   idex_header;
    pfe_ct_phy_if_id_t          i_phy_id;

#ifdef PFE_CFG_PFE_SLAVE
    (void) idex;
#endif

    while (TRUE)
    {
        /*  Get received packet */
        pkt = pfe_hif_drv_client_receive_pkt(hif_client, 0U);
        if (NULL_PTR == pkt)
        {
            /*  No more received packets */
            break;
        }

        pfe_idex.stats.rx_count = ADDU32_WRAP(pfe_idex.stats.rx_count, 1U);

        /*  Get RX packet payload. Also skip HIF header. */
        idex_header = (pfe_idex_frame_header_t *)((addr_t)pfe_hif_pkt_get_data(pkt) + sizeof(pfe_ct_hif_rx_hdr_t));
        i_phy_id = pfe_hif_pkt_get_ingress_phy_id(pkt);

        /*    HIF is not suitable for IDEX    */
        if (((i_phy_id < PFE_PHY_IF_ID_HIF0) || (i_phy_id > PFE_PHY_IF_ID_HIF3)) && (i_phy_id != PFE_PHY_IF_ID_HIF_NOCPY))
        {
#ifdef PFE_CFG_PFE_SLAVE
            if (i_phy_id != pfe_idex.remote.server.phy_id)
#endif /* PFE_CFG_PFE_SLAVE */
            {
                NXP_LOG_WARNING("Received packet from invalid HIF number for IDEX - %d\n", i_phy_id);
                pfe_idex.stats.rx_aliens = ADDU32_WRAP(pfe_idex.stats.rx_aliens, 1U);
                break;
            }
        }

        switch (idex_header->type)
        {
#ifdef PFE_CFG_PFE_MASTER
        /* IDEX    REQUEST    */
        case IDEX_FRAME_CTRL_REQUEST:
        {
            /*  Received frame is IDEX request from client */
            process_idex_request(idex, idex_header, i_phy_id, pkt);
            break;
        } /* IDEX_FRAME_CTRL_REQUEST */
#else
        /*    IDEX RESPONSE    */
        case IDEX_FRAME_CTRL_RESPONSE:
        {
            /*  Frame is IDEX response */
            process_idex_response(idex_header, pkt, i_phy_id);
            break;
        } /* IDEX_FRAME_CTRL_RESPONSE */
#endif  /* PFE_CFG_PFE_MASTER/SLAVE */
        default:
        {
            /*  Unknown frame */
            NXP_LOG_WARNING("Unknown IDEX frame ctrl type 0x%x received\n", (uint_t)idex_header->type);
            break;
        }
        } /* switch */

        /*  Release the received packet */
        pfe_hif_pkt_free(pkt);
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
    /*  Run RX routine */
    pfe_idex_do_rx(pfe_idex.ihc_client, &pfe_idex);
}
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

/**
 * @brief       Send a dummy IDEX frame of constant length to specified dst_phy.
 * @param[in]   dst_phy Destination physical interface ID of client
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_idex_send_dummy_frame(pfe_ct_phy_if_id_t dst_phy)
{
    return pfe_idex_send_frame(dst_phy, IDEX_FRAME_CTRL_DUMMY, &pfe_idex_dummy_frame.dummy_data, sizeof(pfe_idex_dummy_frame.dummy_data));
}

/**
 * @param[in]   type Response type. Should match request type.
 * @param[in]   seqnum Sequence number in network endian. Should match request.
 * @param[in]   data_len Response payload length in number of bytes
 * @return      EOK if success, error code otherwise
 * @note        In interrupt mode invoked from interrupt context. Main context otherwise.
 */
static errno_t pfe_idex_send_response(pfe_ct_phy_if_id_t dst_phy, pfe_idex_response_type_t type, pfe_idex_seqnum_t seqnum, uint16_t data_len)
{
    pfe_idex_response_t *resp;
    errno_t ret;
    /*    If there is response in buffer from old request, clean it */
    if (NULL_PTR != idex_current_client->response)
    {
        *idex_current_client->response = (pfe_idex_response_t){0U};

        /*    Release the response instance */
        idex_current_client->response = NULL_PTR;
    }

    /*    Create the response buffer with room for request payload */
    resp = &pfe_idex_response_frame.resp;
    *resp = (pfe_idex_response_t){0U};

    /*    Add seqnum and type */
    resp->seqnum = (uint32_t)oal_htonl(seqnum);
    resp->type = type;
    resp->plen = (uint16_t)oal_htons(data_len);

#ifdef IDEX_CFG_VERBOSE
    NXP_LOG_DEBUG("Sending response seqnum=%u\n", (uint_t)seqnum);
#endif /* IDEX_CFG_VERBOSE */

    /*  Send it out within IDEX frame */
    ret = pfe_idex_send_frame(dst_phy, IDEX_FRAME_CTRL_RESPONSE, resp, UNSAFE_CAST_INT_TO_UINT16((uint16_t)sizeof(pfe_idex_response_t) + data_len));
    if (EOK != ret)
    {
        NXP_LOG_WARNING("IDEX response TX failed\n");
    }
    else
    {
        pfe_idex.stats.tx_count = ADDU32_WRAP(pfe_idex.stats.tx_count, 1U);
    }

    /*    Save response in case of not successful delivery */
    idex_current_client->response = resp;

    return ret;
}

/**
 * @brief        Helper function to pfe_idex_request_send
 */
static errno_t check_time_out(uint32_t *timeout_ms, bool_t *end_sending, pfe_idex_request_t *request)
{
    errno_t ret = EOK;
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
    pfe_hif_drv_t *hif_drv;

/*  Block until response is received or timeout occurred. RX and
    TX processing is expected to be done asynchronously in pfe_idex_ihc_handler(). */
    hif_drv = pfe_hif_drv_client_get_drv(pfe_idex.ihc_client);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

    /*    Wait 1 ms between every check */
    for (*timeout_ms = PFE_CFG_IDEX_RESEND_DELAY_MS; *timeout_ms > 0U; *timeout_ms -= 1U)
    {
#if (FALSE == PFE_CFG_HIF_IRQ_ENABLED)
        pfe_hif_drv_tx_job(hif_drv);
        pfe_hif_drv_rx_job(hif_drv);
        pfe_idex_ihc_poll();
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

        /*    Check the status of request */
        if (IDEX_REQ_STATE_COMPLETED == request->state)
        {
            /* Request successfully completed, we should increment counter and stop sending [DID-AAVBR-980e-MCAL] */
            ret = EOK;
            *end_sending = TRUE;
            break;
        }
        else if (IDEX_REQ_STATE_INVALID == request->state)
        {
            /* Request failed */
            ret = EFAULT;
            *end_sending = TRUE;
            break;
        }
        else
        {
            /*    Wait 1ms */
            if (FALSE == oal_irq_in_atomic())
            {
                oal_time_msleep(1U);
            }
            else
            {
                oal_time_mdelay(1U);
            }
        }
    }

    return ret;
}

/**
 * @brief        Create, send IDEX request and wait for response
 * @details        THIS IS BLOCKING FUNCTION! [DID-AAVBR-980d-MCAL]
 *                 Slave will create IDEX request and send it to Master
 *                 Function is waiting for response with Pooling mode on request status
 * @param[in]   dst_phy Destination physical interface ID
 * @param[in]   type Request type
 * @param[in]   data_len Request payload length in number of bytes
 * @return      EOK if success, error code otherwise
 * @note        Invoked from the main context.
 */
static errno_t pfe_idex_request_send(pfe_ct_phy_if_id_t dst_phy, pfe_idex_request_type_t type, const uint32_t resend_count, uint16_t data_len)
{
    pfe_remote_server_t *   server = (pfe_remote_server_t *)&pfe_idex.remote.server;
    uint32_t                timeout_ms = PFE_CFG_IDEX_RESEND_DELAY_MS;
    uint32_t                sending_counter;
    pfe_idex_request_t *    request;
    errno_t                 ret;
    bool_t                  end_sending = FALSE;

    /*    Create the request instance with room for request payload */
    request = &pfe_idex_request_frame.req;

    /*    Only initialize header, payload will be added below */
    *request = (pfe_idex_request_t){0U};

    /*    Assign sequence number, type, and destination PHY ID */
    request->seqnum = (uint32_t)oal_htonl(server->seqnum);
    request->type = type;
    request->dst_phy_id = dst_phy;
    request->state = IDEX_REQ_STATE_NEW;
    /*    Payload is already present in pfe_idex_request_frame.arg */
    server->request = request;
    /*    Mark request as commited and start sending */
    request->state = IDEX_REQ_STATE_COMMITTED;
    /*    Sending request. Try to send configured number of times     */
    for (sending_counter = 0U; sending_counter < resend_count; sending_counter++)
    {
        /*    Request transmitted. Will be released once it is processed. */
        ret = pfe_idex_send_frame(dst_phy, IDEX_FRAME_CTRL_REQUEST, request, UNSAFE_CAST_INT_TO_UINT16((uint16_t)sizeof(pfe_idex_request_t) + data_len));

        if (EOK != ret)
        {
            /*    Sending of request failed. Should return ERROR */
            NXP_LOG_ERROR("IDEX request TX failed\n");
            break;
        }
        pfe_idex.stats.tx_count = ADDU32_WRAP(pfe_idex.stats.tx_count, 1U);

        ret = check_time_out(&timeout_ms, &end_sending, request);
        if (TRUE == end_sending)
        {
            break;
        }


        NXP_LOG_DEBUG("IDEX RESENDING REQUEST seqnum=%u counter=%u state=%u", (uint_t)server->seqnum, (uint_t)(sending_counter + 1U), (uint_t)request->state);
        /*    IDEX protocol stats */
        pfe_idex.stats.tx_retries = ADDU32_WRAP(pfe_idex.stats.tx_retries, 1U);
        pfe_idex.stats.tx_max_retries = ((pfe_idex.stats.tx_max_retries < (sending_counter + 1U)) ? ADDU32_WRAP(sending_counter, 1U) : pfe_idex.stats.tx_max_retries);
    }

    if (EOK == ret)
    {
        /*    Sending was not successful, timeout occurred [DID-AAVBR-980h-MCAL] */
        if ((0U == timeout_ms) || (resend_count == sending_counter))
        {
            NXP_LOG_WARNING("IDEX request %u timed-out, retransmitted %u times\n", (uint_t)oal_ntohl(request->seqnum), sending_counter);
            ret = ETIMEDOUT;
        }

        /*    End of sending, increment seqnum */
        server->seqnum += 1U;
        *request = (pfe_idex_request_t){0U};       
        server->request = NULL_PTR;

        /* The slave has finished here, but still there can be an unexpected response from master */
    }
    else
    {
        /* Send was unsuccessful, mark connection down */
        pfe_idex_down();
    }
    
    return ret;
}

static errno_t pfe_idex_prep_tx_header_xmit(pfe_idex_frame_header_t *idex_hdr, hif_drv_sg_list_t sg_list, pfe_hif_chnl_t *hif_chnl)
{
    errno_t                 ret = EINVAL;
    pfe_ct_hif_tx_hdr_t *   tx_hdr;

    /* Let PFE route the frame as IHC packet with known destination */
#if (TRUE == IDEX_IS_NOCPY)
    tx_hdr = (pfe_ct_hif_tx_hdr_t *)((addr_t)idex_hdr + pfe_hif_chnl_get_lmem_hdr_size(hif_chnl) + 256U);
    /* TX buffer for HIF NOCPY is allocated directly from BMU2.
    We need to clear the buffer to avoid unexpected data */
    (void)autolibc_memset(tx_hdr, 0U, sizeof(pfe_ct_hif_tx_hdr_t));
#else
    tx_hdr = (pfe_ct_hif_tx_hdr_t *)idex_hdr;
#endif /* IDEX_IS_NOCPY */
    tx_hdr->chid = UNSAFE_CAST_INT_TO_UINT8(hif_chnl->id);
    tx_hdr->e_phy_ifs = oal_htonl(1UL << (uint8_t)sg_list.dst_phy);
    tx_hdr->flags = (pfe_ct_hif_tx_flags_t)(UNSAFE_CAST_INT_TO_UINT32(HIF_TX_INJECT | HIF_TX_IHC));

    /*  Send it out [DID-AAVBR-980b-MCAL] */
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
    return ret;
}
/**
 * @brief       Send IDEX frame to HIF using IHC. If IDEX is down, then no frame will be sent through the channel.
 * @param[in]   dst_phy Destination physical interface ID
 * @param[in]   type Type of frame
 * @param[in]   data Pointer to frame payload
 * @param[in]   data_len Payload length in number of bytes
 * @return      EOK success, error code otherwise
 * @note        Invoked from interrupt/main context.
 */
static errno_t pfe_idex_send_frame(pfe_ct_phy_if_id_t dst_phy, pfe_idex_frame_type_t type, const void *data, uint16_t data_len)
{
    pfe_idex_frame_header_t *   idex_hdr;
    pfe_idex_frame_header_t *   idex_hdr_pa;
    errno_t                     ret = EOK;
    hif_drv_sg_list_t           sg_list = {0U};
    pfe_hif_drv_t *             hif_drv;
    pfe_hif_chnl_t *            hif_chnl;
#if (TRUE == IDEX_IS_NOCPY)
    void *payload;
    uint16_t buf_offset;
#endif /* IDEX_IS_NOCPY */

    if (FALSE == pfe_idex.is_up)
    {
        pfe_idex.stats.tx_skips = ADDU32_WRAP(pfe_idex.stats.tx_skips, 1U);
        ret = EINVAL;
    }

    /*  Get IDEX frame buffer */
    hif_drv = pfe_hif_drv_client_get_drv(pfe_idex.ihc_client);
    if ((EOK == ret) && (NULL_PTR == hif_drv))  /* EOK check here to not further increase HIS level metrics */
    {
        NXP_LOG_ERROR("Get hif_drv instance associated with the client failed\n");
        ret = ENOENT;
    }
    else if(EOK == ret)                         /* EOK check here to not further increase HIS level metrics */
    {
        hif_chnl = pfe_hif_drv_get_chnl(hif_drv);
        if (NULL_PTR == hif_chnl)
        {
            NXP_LOG_ERROR("Get channel associated with the hif_drv instance failed\n");
            ret = ENOENT;
        }
        else
        {
#if (TRUE == IDEX_IS_NOCPY)
            idex_hdr = (pfe_idex_frame_header_t *)pfe_hif_chnl_bmu_alloc_buf_va(hif_chnl);
            if (NULL_PTR == idex_hdr)
            {
                NXP_LOG_ERROR("Memory allocation failed\n");
                ret = ENOMEM;
            }
            else
            {
                idex_hdr_pa = pfe_hif_chnl_bmu_get_buf_pa(hif_chnl, (addr_t)idex_hdr);
                if (NULL_PTR == idex_hdr_pa)
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
            if (NULL_PTR == idex_hdr_pa)
            {
                NXP_LOG_ERROR("VA to PA conversion failed\n");
                ret = ENOMEM;
            }
            else
            {
#endif /* IDEX_IS_NOCPY */

                    /*  Build SG list */
                    sg_list.size = 1U;
                    sg_list.dst_phy = dst_phy;
                    sg_list.items[0].data_va = idex_hdr;
                    sg_list.items[0].data_pa = idex_hdr_pa;
                    sg_list.items[0].len = (uint32_t)sizeof(pfe_ct_hif_tx_hdr_t) + (uint32_t)sizeof(pfe_idex_frame_header_t) + (uint32_t)data_len;

                    ret = pfe_idex_prep_tx_header_xmit(idex_hdr, sg_list, hif_chnl);

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
 * @param[in]   txcf_cbk Set to NULL, is ignored
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_idex_init(pfe_hif_drv_t *hif_drv, pfe_ct_phy_if_id_t master, pfe_hif_t *hif,
                      pfe_idex_rpc_cbk_t cbk, void *arg, pfe_idex_tx_conf_free_cbk_t txcf_cbk)
{
    pfe_idex_t *    idex = &pfe_idex;
    errno_t         ret = EOK;

    (void)master; /* To prevent unused variable warning when logging is off */

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if ((NULL_PTR == hif_drv) || (NULL_PTR == hif))
    {
        NXP_LOG_ERROR("NULL_PTR argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        (void)autolibc_memset(idex, 0U, sizeof(pfe_idex_t));
        (void)autolibc_memset(&pfe_idex_dummy_frame, 0, sizeof(pfe_idex_dummy_frame));

#ifdef PFE_CFG_PFE_MASTER
        /*    IDEX is in Server mode */
        NXP_LOG_INFO("IDEX-master @ interface %d\n", master);
        idex->is_server = TRUE;
        idex->hif = hif;
#elif defined(PFE_CFG_PFE_SLAVE)
        /* IDEX is Client    */
        NXP_LOG_INFO("IDEX-slave @ master-interface %d\n", master);
        idex->is_server = FALSE;
        /*    Set init seqnum to 0    */
        idex->remote.server.seqnum = 0U;
        idex->remote.server.phy_id = master;
        idex->remote.server.version = IDEX_VERSION_1;

        /* Not used argument variable */
        (void)hif;
#else
#error Impossible configuration
#endif /* PFE_CFG_PFE_MASTER/PFE_CFG_PFE_SLAVE */

        idex->txc_free_cbk = txcf_cbk;
        idex->rpc_req_lock_init = TRUE;

        /*    Register IHC client */
        idex->ihc_client = pfe_hif_drv_ihc_client_register(hif_drv, &pfe_idex_ihc_handler, NULL_PTR);

        if (NULL_PTR == idex->ihc_client)
        {
            NXP_LOG_ERROR("Can't register IHC client\n");
            pfe_idex_fini();
            ret = EFAULT;
        }

        if (EOK == ret)
        {
            ret = pfe_idex_set_rpc_cbk(cbk, arg);
        }

        if (EOK == ret)
        {
            idex->is_up = TRUE;
#if defined(PFE_CFG_PFE_SLAVE)
            /*    Send RESET request message to server [DID-AAVBR-980f-MCAL] */
            pfe_idex_msg_reset_t rst_msg;
            rst_msg.seqnum = (uint32_t)oal_htonl(idex->remote.server.seqnum);
            rst_msg.version = IDEX_VERSION_2;

#ifdef IDEX_CFG_VERBOSE
            NXP_LOG_INFO("IDEX: RESET Request sending: seqnum=%u, version=%u, phy_id=%u\n",
                         (uint_t)idex->remote.server.seqnum, rst_msg.version, master);

#endif /* IDEX_CFG_VERBOSE */
            /*    Sending RESET request. This is blocking communication    */
            ret = pfe_idex_rpc(master, IDEX_RESET_RPC_ID, &rst_msg, sizeof(pfe_idex_msg_reset_t), &rst_msg, sizeof(pfe_idex_msg_reset_t));
            if (EOK != ret)
            {
                /* IDEX Reset was not successful. Client will use Legacy configuration [DID-AAVBR-980g-MCAL] */
                NXP_LOG_INFO("IDEX: RESET Request not successful [%d]. Server is probably using old version of IDEX\n", ret);
                ret = EOK;
            }
            else
            {
                idex->remote.server.version = rst_msg.version;
#ifdef IDEX_CFG_VERBOSE
                NXP_LOG_INFO("IDEX: RESET Response received: seqnum=%u, version=%u\n",
                             (uint_t)idex->remote.server.seqnum, rst_msg.version);
#endif /* IDEX_CFG_VERBOSE */
            }

            if (IDEX_VERSION_2 == idex->remote.server.version)
            {
                NXP_LOG_INFO("IDEX: v2 protocol used, Resend:count=%u,delay=%ums\n", PFE_CFG_IDEX_RESEND_COUNT, PFE_CFG_IDEX_RESEND_DELAY_MS);
            }
#endif /* PFE_CFG_PFE_MASTER/PFE_CFG_PFE_SLAVE */
        }
    } /* PFE_CFG_NULL_ARG_CHECK */

    return ret;
}

/**
 * @brief       Finalize IDEX module
 */
void pfe_idex_fini(void)
{
    pfe_idex_t *idex = &pfe_idex;

    idex->is_up = FALSE;

#ifdef PFE_CFG_PFE_MASTER
    pfe_hif_clear_master_up(idex->hif);
    idex->hif = NULL_PTR;
#endif /* PFE_CFG_PFE_MASTER */

    idex->rpc_cbk = NULL_PTR;
    idex->rpc_cbk_arg = NULL_PTR;
    idex->txc_free_cbk = NULL_PTR;

    if (NULL_PTR != idex->ihc_client)
    {
        pfe_hif_drv_client_unregister(idex->ihc_client);
        idex->ihc_client = NULL_PTR;
    }

    /*    Free IDEX Server buffer for every client response */
    if (TRUE == idex->is_server)
    {
        for (uint8_t i = 0; i < IDEX_MAX_CLIENTS; i++)
        {
            if (NULL_PTR != idex->remote.clients[i].response)
            {
                *idex->remote.clients[i].response = (pfe_idex_response_t){0U};
                idex->remote.clients[i].response = NULL_PTR;
            }
        }
    }

    idex->rpc_req_lock_init = FALSE;
}

/**
 * @brief       Execute RPC against IDEX master. Blocking call. [DID-AAVBR-980a-MCAL]
 * @param[in]   id Request identifier to be passed to remote RPC callback
 * @param[in]   buf Buffer containing RPC argument data
 * @param[in]   buf_len Length of RPC argument data in the buffer
 * @param[in]   resp Response buffer. In case of successful call (EOK) the
 *              response data is written here.
 * @param[in]   resp_len Response buffer length. If response is bigger than this
 *              number of bytes, the buffer will not be written and error code
 *              indicating no memory condition ENOMEM will be returned.
 * @return      EOK if success, error code otherwise
 * @note        Invoked from the main context.
 */
errno_t pfe_idex_master_rpc(uint32_t id, const void *buf, uint16_t buf_len, void *resp, uint16_t resp_len)
{
    const pfe_idex_t *idex = &pfe_idex;
    errno_t ret = EPERM;

    /* RPC message can be sent to Master only from IDEX client */
    if (idex->is_server == FALSE)
    {
        ret = pfe_idex_rpc(idex->remote.server.phy_id, id, buf, buf_len, resp, resp_len);
    }

    return ret;
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
    errno_t         ret = EOK;
    const uint16_t  request_buf_size = UNSAFE_CAST_INT_TO_UINT16((uint16_t)sizeof(pfe_idex_msg_rpc_t) + buf_len);
    const uint16_t  response_buf_size = UNSAFE_CAST_INT_TO_UINT16((uint16_t)sizeof(pfe_idex_msg_rpc_t) + resp_len);
    void *          payload;
    /*    If we have version 2 or RESET message, try to resend multiple times    */
    const uint32_t  resend_count = (((pfe_idex.remote.server.version >= IDEX_VERSION_2) || (id == IDEX_RESET_RPC_ID)) ? PFE_CFG_IDEX_RESEND_COUNT : 1U);

    if(((request_buf_size + sizeof(pfe_idex_frame_header_t) + sizeof(pfe_idex_request_t)) > IMG_EPP_MAX_PACKET_SIZE)
        || ((response_buf_size + sizeof(pfe_idex_frame_header_t) + sizeof(pfe_idex_request_t)) > IMG_EPP_MAX_PACKET_SIZE)
      )
    {
        NXP_LOG_ERROR("Buffers too big for request/response transport\n");
        ret = ENOMEM;
    }

    if(EOK == ret)
    {
        /* clear response frame content */
        (void)autolibc_memset(&pfe_idex_response_frame.msg_rpc, 0U, response_buf_size);

        /* start assemble the request frame */
        (void)autolibc_memset(&pfe_idex_request_frame.msg, 0U, request_buf_size);

        /*    Allocate memory for request and also response */
        pfe_idex_msg_rpc_t *msg_req = &pfe_idex_request_frame.msg;
        pfe_idex_msg_rpc_t *msg_resp = &pfe_idex_response_frame.msg_rpc;

        msg_req->rpc_id = (uint32_t)oal_htonl(id);
        msg_req->plen = (uint16_t)oal_htons(buf_len);
        msg_req->rpc_ret = (uint32_t)oal_htonl(EOK);

        /*    Set buffer for expected RPC response */
        msg_resp->plen = resp_len;
        pfe_idex.remote.server.rpc_msg = msg_resp;

        /*    Copy data to payload of request message */
        payload = (void *)((addr_t)msg_req + sizeof(pfe_idex_msg_rpc_t));
        (void)autolibc_memcpy(payload, buf, buf_len);

#ifdef IDEX_CFG_VERBOSE
        NXP_LOG_INFO("IDEX: RPC Request sending: cmd=%u, seqnum=%u, phy_id=%u, size:%u\n",
                    (uint_t)id, pfe_idex.remote.server.seqnum, dst_phy, buf_len);

#endif /* IDEX_CFG_VERBOSE */

        /*    This is a BLOCKING function */
        ret = pfe_idex_request_send(dst_phy, IDEX_RPC, resend_count, request_buf_size);
        if (EOK != ret)
        {
            /*    Transport error [DID-AAVBR-980k-MCAL] */
            NXP_LOG_ERROR("RPC transport failed: %d\n", ret);
        }
        else
        {
            /*    Sanity checks */
            if (id != msg_resp->rpc_id)
            {
                NXP_LOG_WARNING("RPC response ID does not match the request %u != %u\n", msg_resp->rpc_id, id);
                ret = EINVAL;
            }
            else
            {
                /*    Check the remote return value from the response */
                ret = msg_resp->rpc_ret;

                /*    Copy RPC response data to caller's buffer [DID-AAVBR-980i-MCAL] */
                if (0U == msg_resp->plen)
                {
#ifdef IDEX_CFG_VERBOSE
                    NXP_LOG_DEBUG("RPC response without payload received\n");
#endif /* IDEX_CFG_VERBOSE */
                }
                else if (msg_resp->plen > resp_len) /* if the response is too big */
                {
                    NXP_LOG_ERROR("Caller's buffer is too small\n");
                    ret = ENOMEM;
                }
                else /* there is response, it is not too big and we have buffer */
                {
                    payload = (void *)((addr_t)msg_resp + sizeof(pfe_idex_msg_rpc_t));
                    (void)autolibc_memcpy(resp, payload, msg_resp->plen);

#ifdef IDEX_CFG_VERBOSE
                    NXP_LOG_DEBUG("%d bytes of RPC response received\n", msg_resp->plen);
#endif /* IDEX_CFG_VERBOSE */
                }
            }
        }

        pfe_idex.remote.server.rpc_msg = NULL_PTR;
    }

    return ret;
}

/**
 * @brief       Set RPC response
 * @details     Function can ONLY be called within RPC callback (pfe_idex_rpc_cbk_t)
 *              to indicate the execution result.
 * @param[in]   retval Error code to be presented to RPC initiator
 * @param[in]   resp Buffer containing response data to be presented to
 *              the initiator. Can be NULL_PTR to return no data.
 * @param[in]   resp_len Size of the response in the buffer. Can be zero.
 * @return      EOK success, error code otherwise
 */
errno_t pfe_idex_set_rpc_ret_val(errno_t retval, void *resp, uint16_t resp_len)
{
    pfe_remote_client_t *   client = idex_current_client;
    pfe_idex_msg_rpc_t *    rpc_resp;
    void *                  payload;
    errno_t                 ret;

    rpc_resp = &pfe_idex_response_frame.msg_rpc;

    /* start assemble the response frame */
    (void)autolibc_memset(&pfe_idex_response_frame, 0U, sizeof(pfe_idex_response_frame));

    /*  Construct response message */
    rpc_resp->rpc_id = client->rpc_msg.rpc_id; /* Already in correct endian */
    rpc_resp->plen = oal_htons(resp_len);
    rpc_resp->rpc_ret = oal_htonl(retval);

    payload = (void *)((addr_t)rpc_resp + sizeof(pfe_idex_msg_rpc_t));
    (void)autolibc_memcpy(payload, resp, resp_len);

#ifdef IDEX_CFG_VERBOSE
    NXP_LOG_INFO("IDEX: RPC Response sending: cmd=%u, seqnum=%u, resp_len=%u, retval=%u\n",
                 (uint_t)oal_ntohl(rpc_resp->rpc_id), (uint_t)client->seqnum, resp_len, retval);
#endif /* IDEX_CFG_VERBOSE */

    /*  Send the response */
    ret = pfe_idex_send_response(
        client->phy_id,                                                          /* Destination */
        IDEX_RPC,                                                                /* Response type */
        client->seqnum,                                                          /* Response sequence number */
        UNSAFE_CAST_INT_TO_UINT16((uint16_t)sizeof(pfe_idex_msg_rpc_t) + resp_len) /* Response payload length */
    );
    if (EOK != ret)
    {
        NXP_LOG_ERROR("IDEX RPC response failed\n");
    }

    return ret;
}

/**
* @brief    Mark IDEX communication channel as DOWN
*/
void pfe_idex_down(void)
{
    pfe_idex.is_up = FALSE;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
