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

/**
 * @addtogroup  dxgr_PFE_HIF_DRV
 * @{
 *
 * @file        pfe_hif_drv.c
 * @brief       The HIF driver source file.
 * @details     This is the HIF driver with following features:
 *                  - Server-Client approach and traffic dispatching. The driver provides
 *                    possibility to register a client which will receive dedicated traffic
 *                    according to client ID assigned to a packet by the classification process
 *                    (firmware).
 *                  - TX confirmation handling. Driver passes the TX confirmation events
 *                    to particular clients once their transmit requests are processed.
 *                  - HIF interrupts handling.
 *
 * @internal
 *
 * Threading model
 * ---------------
 * There are two types of threads involved:
 *
 *  - Client
 *    An external thread running HIF client-related routines. Each HIF client is intended to
 *    run within its own thread. Creation and maintenance of client's threads is not subject
 *    of this HIF driver. The HIF driver can only notify the client using dedicated event
 *    notification mechanism.
 *
 * Resources protection
 * --------------------
 * The HIF driver is using a set of various resources which are being accessed from multiple
 * thread contexts. Here is the list with synchronization information:
 *
 *  - pfe_hif_drv_t.tx_meta
 *    Producer  : Clients
 *    Consumer  : HIF worker
 *    Protection: pfe_hif_drv_t.tx_lock
 *
 *    The common, HIF-owned TX metadata storage. Every transmitted buffer (enqueued to the HW TX
 *    ring) has associated metadata structure within this table. The order of transmitted buffers
 *    and metadata entries is maintained. HIF clients are writing to this table within the xmit
 *    calls. HIF worker is then reading the entries during TX confirmation processing. The table
 *    is thus protected using the pfe_hif_drv_t.tx_lock.
 *
 *  - pfe_hif_drv_client_t.client_tx_queue.tx_conf_fifo
 *    Producer  : HIF worker
 *    Consumer  : Particular Client
 *    Protection: n/a
 *
 *    Client-owned FIFO for TX confirmations. HIF worker is putting data into client's FIFO.
 *    Client is reading the FIFO during TX confirmation processing. This FIFO does not need
 *    resource protections (single producer/single consumer).
 *
 *  - pfe_hif_drv_client_t.client_rx_queue.rx_fifo
 *    Producer  : HIF worker
 *    Consumer  : Particular Client
 *    Protection: n/a
 *
 *    Client-owned FIFO for RX buffers. HIF worker is putting descriptors into client's RX FIFO.
 *    Client is reading the FIFO during RX processing. The FIFO does not need resource protection
 *    (single producer/single consumer).
 *
 *
 * @endinternal
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"

#ifdef PFE_CFG_MC_HIF
#include "hal.h"
#include "pfe_hif.h"
#include "pfe_hif_drv.h"
#include "pfe_platform_cfg.h"

#ifdef PFE_CFG_IEEE1588_SUPPORT
    #define PTP_MSG_SYNC        0U
    #define PTP_MSG_DELAY_REQ   1U
    #define PTP_MSG_PDELAY_REQ  2U
    #define PTP_MSG_PDELAY_RESP 3U
    #include "Eth_PFE_LLD.h"
#endif

#define HIF_CFG_WORKER_SCHEDULE_RX              (100U)
#define HIF_CFG_WORKER_SCHEDULE_TX_MAINTENANCE  (101U)
#define HIF_CFG_WORKER_SHUTDOWN                 (102U)

#define PFE_BUF_SIZE        2048U   /* must be big enough for headroom, pkt size and skb shared info */
#define PFE_PKT_HEADROOM    128U
#define PFE_MIN_PKT_SIZE    64U
#define PFE_PKT_SIZE        (PFE_BUF_SIZE - PFE_PKT_HEADROOM) /* maximum ethernet packet */

/* The length is runtime configurable per queue in MCAL and minihif driver */
#define PFE_CFG_HIF_RING_LENGTH (hif_drv->tx_meta_number)

typedef struct pfe_hif_pkt_tag pfe_hif_tx_meta_t;
typedef struct pfe_hif_pkt_tag pfe_hif_rx_meta_t;

struct __attribute__((packed)) client_rx_queue
{
    fifo_t *rx_fifo;    /* This is the client's RX ring */
    uint32_t size;
    bool_t has_new_data;
};

struct __attribute__((packed)) client_tx_queue
{
    fifo_t *tx_conf_fifo; /* TX confirmation FIFO */
    uint32_t size;
    bool_t has_new_data;
    bool_t has_new_ets_data;
};

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
#define PFE_HIF_DRV_IHC_CLIENT_RX_QUEUES 1U
#define PFE_HIF_DRV_IHC_CLIENT_TX_QUEUES 1U
#define PFE_HIF_DRV_IHC_CLIENT_RX_QUEUE_DEPTH 8U
#define PFE_HIF_DRV_IHC_CLIENT_TX_QUEUE_DEPTH 8U

typedef struct
{
    fifo_t rx_fifo[PFE_HIF_DRV_IHC_CLIENT_RX_QUEUES];
    fifo_t tx_conf_fifo[PFE_HIF_DRV_IHC_CLIENT_TX_QUEUES];
    void *rx_fifo_data[RXTX_FIFO_ALIGNED_DEPTH(PFE_HIF_DRV_IHC_CLIENT_RX_QUEUE_DEPTH) * PFE_HIF_DRV_IHC_CLIENT_RX_QUEUES];
    void *tx_conf_fifo_data[RXTX_FIFO_ALIGNED_DEPTH(PFE_HIF_DRV_IHC_CLIENT_TX_QUEUE_DEPTH) * PFE_HIF_DRV_IHC_CLIENT_TX_QUEUES];
} ihc_client_fifos_t;

/* IHC client FIFOs */
ihc_client_fifos_t ihc_client_fifos;

#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

/* HIF driver singleton */
pfe_hif_drv_t common_hif_drv;

#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief   The HIF driver client instance structure
 */
struct __attribute__((aligned(HAL_CACHE_LINE_SIZE), packed)) pfe_hif_drv_client_tag
{
    uint32_t id_mask;
    pfe_ct_phy_if_id_t phy_if_id;
    uint32_t tx_qn;
    uint32_t rx_qn;
    struct client_tx_queue tx_q[HIF_DRV_CLIENT_QUEUES_MAX];
    struct client_rx_queue rx_q[HIF_DRV_CLIENT_QUEUES_MAX];
    pfe_hif_drv_client_event_handler event_handler;
    pfe_hif_drv_t *hif_drv;
    void *priv;
    bool_t active;
    bool_t promisc;
#ifdef PFE_CFG_IEEE1588_SUPPORT
    /* Storage for PTP timestamps */
    pfe_hif_ptp_ts_db_t __attribute__((aligned(4))) ptpdb;   /* Must be aligned at 4 bytes */
#endif /* PFE_CFG_IEEE1588_SUPPORT */
};

/**
 * @brief   The HIF driver instance structure
 */
struct __attribute__((aligned(HAL_CACHE_LINE_SIZE), packed)) pfe_hif_drv_tag
{
/* Common */
    pfe_hif_chnl_t *channel;            /* The associated HIF channel instance */

    pfe_hif_drv_client_t *cur_client;
    pfe_ct_phy_if_id_t i_phy_if;
    uint8_t qno;
    bool_t started;
    bool_t rx_enabled;                  /* If TRUE then frame reception is allowed */

/* TX and TX confirmation processing */
#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
    oal_job_t tx_job;
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */
    pfe_hif_tx_meta_t tx_meta[ETH_43_PFE_MAX_TXBD_CNT];                   /* Storage of metadata for every transmitted buffer */
    uint32_t tx_meta_rd_idx;
    uint32_t tx_meta_wr_idx;
    uint32_t tx_meta_number;
    bool_t tx_enabled;                                                    /* If TRUE then frame transmission is allowed */
#ifdef HIF_STATS
/* Statistics */
    uint32_t counters[HIF_STATS_MAX_COUNT];
#endif

/* Table of HIF Driver Clients indexed by physical interface (pfe_phy_if_t) ID */
    pfe_hif_drv_client_t clients[HIF_CLIENTS_MAX] __attribute__((aligned(HAL_CACHE_LINE_SIZE)));

    volatile bool_t initialized;    /* If TRUE the HIF has been properly initialized */
};

#define PFE_HIF_DRV_WORKER_IRQ_NAME "pfe:q%d"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/* Channel management */
static errno_t pfe_hif_drv_create_data_channel(pfe_hif_drv_t *hif_drv);
static void pfe_hif_drv_destroy_data_channel(pfe_hif_drv_t *hif_drv);

/* Common static stuff */
static void pfe_hif_drv_chnl_rx_oob_handler(void *arg);
static uint32_t pfe_hif_drv_process_rx(pfe_hif_drv_t *hif_drv, uint32_t budget);
static uint32_t pfe_hif_drv_process_tx(pfe_hif_drv_t *hif_drv, uint32_t budget);
static void hif_client_free_rx_queues(pfe_hif_drv_client_t *client);
static void hif_client_free_tx_queues(pfe_hif_drv_client_t *client);
static pfe_hif_drv_client_t *pfe_hif_drv_client_register_ll(
        pfe_hif_drv_t *hif_drv, pfe_hif_drv_client_t *client, pfe_ct_phy_if_id_t phy_if_id,
        pfe_hif_drv_client_rx_tx_count *client_queue, pfe_hif_drv_client_fifo_queue *client_fifo_queue,
        bool_t promisc, pfe_hif_drv_client_event_handler handler, void *priv);
static void pfe_hif_drv_stop_tx(pfe_hif_drv_t *hif_drv);
static void pfe_hif_drv_stop_rx(pfe_hif_drv_t *hif_drv);

#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
#if (TRUE == HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION)
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
static void pfe_hif_drv_chnl_tx_isr(void *arg);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
#endif /* HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION */
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */
static errno_t hif_client_create_rx_queues(pfe_hif_drv_client_t *client, fifo_t *fifo);
static errno_t hif_client_create_tx_queues(pfe_hif_drv_client_t *client, fifo_t *fifo);

/**
 * @brief   Indicate end of reception
 * @details Re-enable interrupts, trigger DMA, ...
 */
void pfe_hif_drv_client_rx_done(const pfe_hif_drv_client_t *client)
{
    (void)client;
}

/**
 * @brief       Deferred RX job
 */
void pfe_hif_drv_rx_job(void *arg)
{
    pfe_hif_drv_t *hif_drv = (pfe_hif_drv_t *)arg;

    if (likely(TRUE == hif_drv->rx_enabled))
    {
        while (HIF_RX_POLL_BUDGET <= pfe_hif_drv_process_rx(hif_drv, HIF_RX_POLL_BUDGET))
        {
            ;
        }
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
        /* Enable RX interrupt */
        pfe_hif_chnl_rx_irq_unmask(hif_drv->channel);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
        /* Trigger the RX DMA */
        pfe_hif_chnl_rx_dma_start(hif_drv->channel);
    }
}

#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
#if (TRUE == HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION)
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
/**
 * @brief       HIF channel TX ISR
 * @details     Will be called by HIF channel instance when TX event has occurred
 * @note        To see which context the ISR is running in please see the
 *              pfe_hif_chnl module implementation.
 */
static void pfe_hif_drv_chnl_tx_isr(void *arg)
{
    pfe_hif_drv_t *hif_drv = (pfe_hif_drv_t *)arg;

    if (unlikely(EOK != oal_job_run(&hif_drv->tx_job)))
    {
        NXP_LOG_ERROR("TX job trigger failed\n");
    }
}
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
#endif /* HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION */

/**
 * @brief       Deferred TX job
 */
void pfe_hif_drv_tx_job(void *arg)
{
    pfe_hif_drv_t *hif_drv = (pfe_hif_drv_t *)arg;

    if (likely(TRUE == hif_drv->tx_enabled))
    {
        /* Enter critical section */
        oal_mutex_lock(PFE_HIF_DRV_MUTEX_00);

        while (HIF_TX_POLL_BUDGET <= pfe_hif_drv_process_tx(hif_drv, HIF_TX_POLL_BUDGET))
        {
            ;
        }

        /* Leave critical section */
        oal_mutex_unlock(PFE_HIF_DRV_MUTEX_00);
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
#if (TRUE == HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION)
        /* Enable TX interrupt */
        pfe_hif_chnl_tx_irq_unmask(hif_drv->channel);
#endif /* HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION */
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

        /* Trigger the TX DMA */
        pfe_hif_chnl_tx_dma_start(hif_drv->channel);
    }
}
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */

/**
 * @brief   Indicate end of TX confirmation
 * @details Re-enable interrupts, trigger DMA, ...
 */
void pfe_hif_drv_client_tx_done(const pfe_hif_drv_client_t *client)
{
    (void)client;
}

#if defined(PFE_CFG_IEEE1588_SUPPORT)
/**
 * @brief       This function timeouts timestamps in database
 * @details     This function shall be called periodically for each client
 * @param[in]   client Client instance
 */
void pfe_hif_drv_client_ptp_ts_db_tick_iteration(pfe_hif_drv_client_t *client)
{
    if (NULL != client)
    {
        pfe_hif_ptp_ts_db_tick_iteration(&(client->ptpdb));
    }
}
#endif /* PFE_CFG_IEEE1588_SUPPORT */

/**
 * @brief       HIF channel RX out-of-buffers event handler
 * @details     Will be called by HIF channel instance when there are no RX
 *              buffers available to receive data.
 */
static void pfe_hif_drv_chnl_rx_oob_handler(void *arg)
{
    pfe_hif_drv_t *hif_drv = (pfe_hif_drv_t *)arg;
    pfe_hif_drv_client_t *client;
    uint32_t ii;

    /* Notify all registered clients that channel is out of RX buffers. The
       clients can try to release previously received buffers via pfe_hif_pkt_free()
       or potentially deliver new RX buffers via dedicated API. */

    for (ii=0U; ii<HIF_CLIENTS_MAX; ii++)
    {
        if (TRUE == hif_drv->clients[ii].active)
        {
            client = &hif_drv->clients[ii];
            (void)client->event_handler(client, client->priv, EVENT_RX_OOB, 0xffffffffU);
        }
    }
}

static errno_t pfe_hif_drv_create_data_channel(pfe_hif_drv_t *hif_drv)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Sanity check */
        if (sizeof(pfe_hif_rx_meta_t) > pfe_hif_chnl_get_meta_size(hif_drv->channel))
        {
            NXP_LOG_ERROR("Metadata storage size (%u) is less than required (%u)\n", (uint_t)(pfe_hif_chnl_get_meta_size(hif_drv->channel)), (uint_t)sizeof(pfe_hif_rx_meta_t));
            pfe_hif_drv_destroy_data_channel(hif_drv);
            ret = ENOMEM;
        }
        else
        {
            /* Allocate the TX metadata storage and initialize indexes */
            hif_drv->tx_meta_number = pfe_hif_chnl_get_tx_fifo_depth(hif_drv->channel);
            (void)autolibc_memset(hif_drv->tx_meta, 0, sizeof(hif_drv->tx_meta));
            hif_drv->tx_meta_rd_idx = 0U;
            hif_drv->tx_meta_wr_idx = 0U;
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief   Destroy HIF channel and release allocated resources
 * @details Will also release all RX buffers associated with RX ring and confirm
 *          all pending TX frames from the TX ring.
 */
static void pfe_hif_drv_destroy_data_channel(pfe_hif_drv_t *hif_drv)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Disable and invalidate RX and TX */
        pfe_hif_chnl_rx_disable(hif_drv->channel);
        pfe_hif_chnl_tx_disable(hif_drv->channel);
    }
}

/**
 * @brief       The HIF RX ring processing routine
 * @param[in]   hif_drv The HIF driver instance
 * @param[in]   budget Maximum number of frames to process in a single iteration
 * @note        Runs within the RX worker thread context
 * @return      Number of processed frames.
 */
static uint32_t pfe_hif_drv_process_rx(pfe_hif_drv_t *hif_drv, uint32_t budget)
{
    pfe_ct_hif_rx_hdr_t *hif_hdr_ptr;
    uint32_t rx_len, rx_processed = 0U;
    uint32_t flags;
    void *current_buffer_va, *meta_va;
    bool_t lifm;
    pfe_hif_drv_client_t *client;
    pfe_hif_rx_meta_t *rx_metadata;
    errno_t ret;
    uint32_t rx_clients = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        while (rx_processed < budget)
        {
            /* Get RX buffer */
            if (EOK != pfe_hif_chnl_rx_va(hif_drv->channel, &current_buffer_va, &rx_len, &lifm, &meta_va))
            {
                break;
            }

            rx_processed++;
            hif_hdr_ptr = (pfe_ct_hif_rx_hdr_t *)current_buffer_va;

            if (FALSE == hif_drv->started)
            {
                /*
                    This is leading buffer of a frame. Only the leading one
                    contains HIF header data so get it (COPY!) and store it.

                    To maximize resource utilization the HIF header is later
                    used to store buffer-related metadata. DO NOT ACCESS this
                    region after metadata has been written.
                */
                hif_hdr_ptr->flags = (pfe_ct_hif_rx_flags_t)oal_ntohl(hif_hdr_ptr->flags);
                hif_drv->i_phy_if = hif_hdr_ptr->i_phy_if;

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
                if (((uint32_t)hif_hdr_ptr->flags & (uint32_t)HIF_RX_IHC) != 0U)
                {
                    /* IHC client */
                    client = &hif_drv->clients[HIF_CLIENTS_IHC_IDX];
                }
                else
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
                {
                    /* Get client associated with ingress physical interface ID */
                    client = &hif_drv->clients[hif_hdr_ptr->i_phy_if];
                }

                /* Check if standard (or IHC) client exists */
                if (FALSE == client->active)
                {
                    /* Standard client not present. Use the AUX client as fall-back. */
                    client = &hif_drv->clients[HIF_CLIENTS_AUX_IDX];
                }
                else
                {
                    /* Standard client present. Check if it is promiscuous. */
                    if (TRUE == client->promisc)
                    {
                        /* Client is promiscuous so shall accept all traffic */
                        ;
                    }
                    else
                    {
                        /* Client is not promiscuous and shall accept only
                        "management" traffic but only in case, when the
                        AUX client is present. So first check, if the AUX
                        is present. */
                        if (TRUE == hif_drv->clients[HIF_CLIENTS_AUX_IDX].active)
                        {
                            /* AUX client does exist. Check if the frame is "management". */
                            if (0U != ((uint32_t)hif_hdr_ptr->flags
                                            & ((uint32_t)HIF_RX_PTP | (uint32_t)HIF_RX_ETS)))
                            {
                                /* Frame is "management" and will be received by
                                the standard client */
                                ;
                            }
                            else
                            {
                                /* Frame is not "management". Will be received by the
                                AUX client. */
                                client = &hif_drv->clients[HIF_CLIENTS_AUX_IDX];
                            }
                        }
                        else
                        {
                            /* Use the standard client */
                            ;
                        }
                    }
                }

                /* This is valid leading buffer of a frame */
                hif_drv->started = TRUE;
                flags = (uint32_t)HIF_FIRST_BUFFER;

                /* Remember current client */
                hif_drv->cur_client = client;
            }
            else
            {
                client = hif_drv->cur_client;
                flags = 0U;
            }

            if (lifm)
            {
                /* This is last buffer of a frame */
                flags |= (uint32_t)HIF_LAST_BUFFER;
                hif_drv->started = FALSE;
            }

            /* Check if a client determined above is active/present */
            if (unlikely(FALSE == client->active))
            {
                /* Client is not present. Drop the frame. Resource protection is embedded. */
                NXP_LOG_WARNING("Invalid client, dropping packet\n");
                ret = pfe_hif_chnl_release_buf(hif_drv->channel, current_buffer_va);
                if (unlikely(EOK != ret))
                {
                    NXP_LOG_DEBUG("Unable to release RX buffer: %d\n", ret);
                }

                continue;
            }

#ifdef PFE_CFG_DEBUG
            if (unlikely(hif_drv->qno >= client->rx_qn))
            {
                /* Drop the frame. Resource protection is embedded. */
                NXP_LOG_WARNING("Packet with invalid queue ID: %d\n", hif_drv->qno);
                ret = pfe_hif_chnl_release_buf(hif_drv->channel, current_buffer_va);
                {
                    if (unlikely(EOK != ret))
                    {
                        NXP_LOG_ERROR("Unable to release RX buffer\n");
                    }
                }
#ifdef HIF_STATS
                hif_drv->counters[HIF_STATS_RX_FRAME_DROPS]++;
#endif /* HIF_STATS */
                continue;
            }
#endif /* PFE_CFG_DEBUG */

            if (((uint32_t)hif_hdr_ptr->flags & (uint32_t)HIF_RX_ETS) != 0UL)
            {
#ifdef PFE_CFG_IEEE1588_SUPPORT
                const pfe_ct_ets_report_t *etsr =
                        (pfe_ct_ets_report_t *)((addr_t)current_buffer_va
                                + sizeof(pfe_ct_hif_rx_hdr_t));

                /*  Match received TS with a frame in DB. Timestamp values are already in host endian... */
                if (EOK != pfe_hif_ptp_ts_db_push_ts(   &client->ptpdb, FALSE, 
                                                        oal_ntohs(etsr->ref_num) & 0x0FFFU, 
                                                        etsr->ts_sec, etsr->ts_nsec
                                                    )
                )
                {
                    NXP_LOG_ERROR("Got TS for an unknown frame\n");
                }
                else if (NULL != client->event_handler)
                {
                    uint32_t qq;
                    /* Call handlers */
                    for (qq = 0U; qq < HIF_DRV_CLIENT_QUEUES_MAX; qq++)
                    {
                        if (TRUE == client->tx_q[qq].has_new_ets_data)
                        {
                            (void)client->event_handler(client, client->priv, EVENT_ETS, qq);
                            client->tx_q[qq].has_new_ets_data = FALSE;
                        }
                    }
                }
                else
                {
                    ; /* No action required */
                }
#else
#ifdef PFE_CFG_DEBUG
                NXP_LOG_DEBUG("Egress timestamp report received. Will be dropped.\n");
#endif
#endif /* PFE_CFG_IEEE1588_SUPPORT */

                /* Drop the frame. Resource protection is embedded. */
                ret = pfe_hif_chnl_release_buf(hif_drv->channel, current_buffer_va);
                if (unlikely(EOK != ret))
                {
                    NXP_LOG_ERROR("Unable to release RX buffer\n");
                }
#ifdef HIF_STATS
                hif_drv->counters[HIF_STATS_RX_FRAME_DROPS]++;
#endif /* HIF_STATS */

                continue;
            }

#ifdef PFE_CFG_IEEE1588_SUPPORT

            if (((uint32_t)hif_hdr_ptr->flags & (uint32_t)HIF_RX_TS) != 0U)
            {
                if (((uint32_t)hif_hdr_ptr->flags & (uint32_t)HIF_RX_PTP) != 0U)
                {
                    oal_util_ptp_header_t *ptph;
                    uint16_t ref = (uint16_t)(oal_util_get_unique_seqnum32() & 0xffffU);

                    if (EOK == oal_util_parse_ptp((void *)((addr_t)current_buffer_va+sizeof(pfe_ct_hif_rx_hdr_t)),
                            rx_len-sizeof(pfe_ct_hif_rx_hdr_t), &ptph))
                    {
                        /* Only Event messages will be pushed into database */
                        if((ptph->byte1.messageType == PTP_MSG_SYNC) || (ptph->byte1.messageType == PTP_MSG_DELAY_REQ) ||
                            (ptph->byte1.messageType == PTP_MSG_PDELAY_REQ) || (ptph->byte1.messageType == PTP_MSG_PDELAY_RESP))
                        {
                            /* Store the RX frame reference and timestamp into the DB */
                            ret = pfe_hif_ptp_ts_db_push_msg(&client->ptpdb, TRUE, ref, ptph->byte1.messageType,
                                    oal_ntohs(ptph->sourcePortID), oal_ntohs(ptph->sequenceID));
                            if (EOK != ret)
                            {
                                NXP_LOG_ERROR("Could not store received PTP message: %d\n", ret);
                            }
                            else
                            {
                                /*  Timestamp is in little-endian format */
                                ret = pfe_hif_ptp_ts_db_push_ts(&client->ptpdb, TRUE,
                                        ref, hif_hdr_ptr->rx_timestamp_s, hif_hdr_ptr->rx_timestamp_ns);

                                if (EOK == ret)
                                {
#ifdef PFE_CFG_DEBUG
                                    NXP_LOG_DEBUG("New (RX) PTP frame: Type: 0x%x, Port: 0x%x, SeqID: 0x%x, Sec: 0x%x, nSec: 0x%x\n",
                                        ptph->byte1.messageType, oal_ntohs(ptph->sourcePortID), oal_ntohs(ptph->sequenceID),
                                            hif_hdr_ptr->rx_timestamp_s, hif_hdr_ptr->rx_timestamp_ns);
#endif /* PFE_CFG_DEBUG */
                                }
                                else
                                {
                                    NXP_LOG_ERROR("Could not store received timestamp: %d\n", ret);
                                }
                            }
                        }
                    }
                    else
                    {
                        NXP_LOG_ERROR("PTP frame not found\n");
                    }
                }
            }
#endif /* PFE_CFG_IEEE1588_SUPPORT */

            /* Fill the RX metadata */
            rx_metadata = (pfe_hif_rx_meta_t *)meta_va;
            rx_metadata->client = client;
            rx_metadata->data = (addr_t)current_buffer_va;
            rx_metadata->len = rx_len;
            rx_metadata->flags.common = (pfe_hif_drv_common_flags_t)flags;
            rx_metadata->flags.specific.rx_flags = hif_hdr_ptr->flags;
            rx_metadata->q_no = hif_drv->qno;
            rx_metadata->i_phy_if = hif_drv->i_phy_if;

            /* Enqueue the packet into client's RX queue. No resource protection here. */
            ret = fifo_put(client->rx_q[hif_drv->qno].rx_fifo, rx_metadata);
            if (unlikely(EOK != ret))
            {
                /* Drop the frame. Resource protection is embedded. */
                ret = pfe_hif_chnl_release_buf(hif_drv->channel, current_buffer_va);
                {
                    if (unlikely(EOK != ret))
                    {
                        NXP_LOG_ERROR("Unable to release RX buffer\n");
                    }
                }

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
                if (client == &hif_drv->clients[HIF_CLIENTS_IHC_IDX])
                {
                    /* The client is IHC client */
                    NXP_LOG_WARNING("IHC client's RX queue is full. Frame dropped.\n");
                }
                else
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */
                {
                    /* The client is physical interface client */
                    NXP_LOG_WARNING("Client's (%d) RX queue is full. Frame dropped.\n", hif_drv->cur_client->phy_if_id);
                }
#ifdef HIF_STATS
                hif_drv->counters[HIF_STATS_CLIENT_FULL_COUNT]++;
#endif /* HIF_STATS */
                continue;
            }
            else
            {
                /*  Remember that client has a new data */
                rx_clients |= client->id_mask;
            }
        } /* end while */

#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
        /* Notify client(s) about new data */
        uint32_t ii;

        ii=0U;
        while (rx_clients!=0U)
        {
            if ((rx_clients & 0x1U) != 0U)
            {
                /* Get client */
                client = &hif_drv->clients[ii];
                /* Call handler. Queue information not passed. Add if needed. */
                (void)client->event_handler(client, client->priv, EVENT_RX_PKT_IND, 0U);
            }
            ii++;
            rx_clients>>=1;
        }
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
    }
    return rx_processed;
}

static void hif_client_free_rx_queues(pfe_hif_drv_client_t *client)
{
    uint32_t ii;
    struct client_rx_queue *queue;
    pfe_hif_pkt_t *pkt;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == client))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (ii=0U; ii<client->rx_qn; ii++)
        {
            queue = &client->rx_q[ii];
            if (likely(NULL != queue->rx_fifo))
            {
                /* Properly release all remaining Rx buffers */
                pkt = fifo_get(queue->rx_fifo);
                while (NULL != pkt)
                {
                    pfe_hif_pkt_free(pkt);
                    pkt = fifo_get(queue->rx_fifo);
                }

                fifo_destroy(queue->rx_fifo);
                queue->rx_fifo = NULL;
            }
        }
    }
}

static void hif_client_free_tx_queues(pfe_hif_drv_client_t *client)
{
    uint32_t ii;
    uint32_t fill_level;
    struct client_tx_queue *queue;
    errno_t err;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == client))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for (ii=0U; ii<client->tx_qn; ii++)
        {
            queue = &client->tx_q[ii];
            if (likely(NULL != queue->tx_conf_fifo))
            {
                err = fifo_get_fill_level(queue->tx_conf_fifo, &fill_level);
                if (unlikely(EOK != err))
                {
                    NXP_LOG_ERROR("Unable to get fifo fill level: %d\n", err);
                }

                if (0U != fill_level)
                {
                    NXP_LOG_WARNING("Client %d, TX queue %u: Queue is not empty\n", client->phy_if_id, (uint_t)ii);
                }

                fifo_destroy(queue->tx_conf_fifo);
                queue->tx_conf_fifo = NULL;
            }
        }
    }
}

static errno_t hif_client_create_rx_queues(pfe_hif_drv_client_t *client, fifo_t *fifo)
{
    uint32_t ii;
    struct client_rx_queue *queue;
    fifo_t *tmp_fifo = fifo;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == client) || (NULL == fifo)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Initialize RX queues */
        (void)autolibc_memset(client->rx_q, 0, HIF_DRV_CLIENT_QUEUES_MAX * sizeof(struct client_rx_queue));

        /* Create the queues */
        for (ii=0U; ii<client->rx_qn; ii++)
        {
            queue = &client->rx_q[ii];

            /*
                This FIFO is used to store received frames until client processes it.
                HIF is putting data in there by calling 'put()' and client is reading it via 'get()'.
                Since there is only one producer and one consumer the FIFO does not need to be
                protected. See pfe_hif_drv_client_receive_pkt().
            */
            queue->rx_fifo = tmp_fifo;
            queue->size = tmp_fifo->depth;
            tmp_fifo++;
        }
        ret = EOK;
    }

    return ret;
}

static errno_t hif_client_create_tx_queues(pfe_hif_drv_client_t *client, fifo_t *fifo)
{
    uint32_t ii;
    struct client_tx_queue *queue;
    fifo_t *tmp_fifo = fifo;
    errno_t ret = EINVAL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == client) || (NULL == fifo)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Initialize TX queues */
        (void)autolibc_memset(client->tx_q, 0, HIF_DRV_CLIENT_QUEUES_MAX * sizeof(struct client_tx_queue));

        /* Create the queues */
        for (ii=0U; ii<client->tx_qn; ii++)
        {
            queue = &client->tx_q[ii];

            /* Create TX confirmation queues. Does not need to be protected since only HIF
               worker puts data in there and only a single client read it. */
            queue->tx_conf_fifo = tmp_fifo;
            queue->size = tmp_fifo->depth;
            tmp_fifo++;
        }
        ret = EOK;
    }

    return ret;
}

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
/**
 * @brief       Register special IHC client
 * @details     Routine creates new HIF driver client to be used for inter-HIF communication
 * @param[in]   hif_drv The HIF driver instance the client shall be associated with
 * @param[in]   handler Pointer to function to be called to indicate events (data available, ...).
 *                      Mandatory. Can be called from various contexts.
 * @param[in]   priv Private data to be stored within the client instance and passed as handler argument
 * @return      HIF driver client instance or NULL if failed
 */
pfe_hif_drv_client_t *
    pfe_hif_drv_ihc_client_register(
        pfe_hif_drv_t *hif_drv,
        pfe_hif_drv_client_event_handler handler,
        void *priv)
{
    pfe_hif_drv_client_t *client;
    pfe_hif_drv_client_rx_tx_count client_queue;
    pfe_hif_drv_client_fifo_queue client_fifo_queue;

    if (NULL == handler)
    {
        NXP_LOG_ERROR("Event handler is mandatory\n");
        client = NULL;
    }
    else
    {

        /* compile time check if have only one for rx and tx */
        ct_assert(PFE_HIF_DRV_IHC_CLIENT_RX_QUEUES == 1U);
        ct_assert(PFE_HIF_DRV_IHC_CLIENT_TX_QUEUES == 1U);

        client_fifo_queue.rxq_fifo = fifo_create(PFE_HIF_DRV_IHC_CLIENT_TX_QUEUE_DEPTH, ihc_client_fifos.tx_conf_fifo, ihc_client_fifos.tx_conf_fifo_data);
        if (NULL == (client_fifo_queue.rxq_fifo))
        {
            NXP_LOG_ERROR("Can't create RX queues\n");
            client = NULL;
        }
        else
        {
            client_fifo_queue.txq_fifo = fifo_create(PFE_HIF_DRV_IHC_CLIENT_RX_QUEUE_DEPTH, ihc_client_fifos.rx_fifo, ihc_client_fifos.rx_fifo_data);
            if (NULL == (client_fifo_queue.txq_fifo))
            {
                NXP_LOG_ERROR("Can't create TX queues\n");
                client = NULL;
            }
            else
            {
                client = &hif_drv->clients[HIF_CLIENTS_IHC_IDX];    /* Client storage */

                client_queue.txq_num = PFE_HIF_DRV_IHC_CLIENT_TX_QUEUES; /* Number of TX queues */
                client_queue.rxq_num = PFE_HIF_DRV_IHC_CLIENT_RX_QUEUES; /* Number of RX queues */

                client = pfe_hif_drv_client_register_ll(
                        hif_drv,                                    /* HIF driver instance */
                        client,
                        (pfe_ct_phy_if_id_t)HIF_CLIENTS_IHC_IDX,    /* Physical interface ID (invalid here) */
                        &client_queue,                              /* Number of TX/RX queues */
                        &client_fifo_queue,                         /* FIFO for the TX/RX queue */
                        TRUE,                                       /* TRUE if client shall be promiscuous */
                        handler,                                    /* Client's event handler */
                        priv);                                      /* Private data to be passed to handler */

                if (NULL != client)
                {
                    NXP_LOG_INFO("HIF IHC client registered\n");
                }
            }
        }
    }

        return client;
}
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

/**
 * @brief       Register auxiliary client
 * @details     Client will receive all packets not matching any other registered client and
 *              transmission via this client will fully rely on the related physical interface
 *              (HIF channel) configuration, i.e. client will NOT inject traffic.
 * @param[in]   hif_drv The HIF driver instance the client shall be associated with
 * @param[in]   txq_num Number of client's TX queues
 * @param[in]   rxq_num Number of client's RX queues
 * @param[in]   txq_fifo FIFO array for each TX queue
 * @param[in]   rxq_fifo FIFO array for each RX queue
 * @param[in]   handler Pointer to function to be called to indicate events (data available, ...).
 *                      Mandatory. Can be called from various contexts.
 * @param[in]   priv Private data to be stored within the client instance and passed as handler argument
 * @return      HIF driver client instance or NULL if failed
 */
pfe_hif_drv_client_t * pfe_hif_drv_aux_client_register(
    pfe_hif_drv_t *hif_drv,
    pfe_hif_drv_client_rx_tx_count *client_queue,
    pfe_hif_drv_client_fifo_queue  *client_fifo_queue,
    pfe_hif_drv_client_event_handler handler,
    void *priv)
{
    pfe_hif_drv_client_t *client;

    if (NULL == handler)
    {
        NXP_LOG_ERROR("Event handler is mandatory\n");
        client = NULL;
    }
    else
    {
    client = &hif_drv->clients[HIF_CLIENTS_AUX_IDX];    /* Client storage */

    client = pfe_hif_drv_client_register_ll(
            hif_drv,                                    /* HIF driver instance */
            client,                                     /* Client storage */
            (pfe_ct_phy_if_id_t)HIF_CLIENTS_AUX_IDX,    /* Physical interface ID (invalid here) */
            client_queue,                               /* Number of TX/RX queues */
            client_fifo_queue,                          /* FIFO for the TX/RX queue */
            TRUE,                                       /* TRUE if client shall be promiscuous */
            handler,                                    /* Client's event handler */
            priv);                                      /* Private data to be passed to handler */

    if (NULL != client)
    {
        NXP_LOG_INFO("HIF AUX client registered\n");
    }
    }

    return client;
}

/**
 * @brief       This function is used to register a client driver with the HIF driver.
 * @details     Routine creates new HIF driver client, associates it with given physical interface
 *              and adjusts internal HIF dispatching table to properly route ingress packets to
 *              client's queues.
 * @param[in]   hif_drv The HIF driver instance the client shall be associated with
 * @param[in]   phy_if_id Physical interface ID to be handled by the client
 * @param[in]   txq_num Number of client's TX queues
 * @param[in]   rxq_num Number of client's RX queues
 * @param[in]   txq_fifo FIFO array for each TX queue
 * @param[in]   rxq_fifo FIFO array for each RX queue
 * @param[in]   promisc If TRUE then the client will accept all received frames. If FALSE then
 *                      the client will accept only "management" traffic and rest will be delivered
 *                      to AUX, if does exist.
 * @param[in]   handler Pointer to function to be called to indicate events (data available, ...).
 *                      Mandatory. Can be called from various contexts.
 * @param[in]   priv Private data to be stored within the client instance
 *
 * @return      Client instance or NULL if failed
 */
pfe_hif_drv_client_t *
    pfe_hif_drv_client_register(
        pfe_hif_drv_t *hif_drv,
        pfe_ct_phy_if_id_t phy_if_id,
        pfe_hif_drv_client_rx_tx_count *client_queue,
        pfe_hif_drv_client_fifo_queue  *client_fifo_queue,
        bool_t promisc,
        pfe_hif_drv_client_event_handler handler,
        void *priv)
{
    pfe_hif_drv_client_t *client;

    /*
        The HIF driver is using physical interface ID to match ingress packets with clients.
        For this purpose an array is used where particular client instances are stored
        and the HIF driver is addressing them via physical interface IDs received from classifier.
        Size of this array is limited so we only support limited number of clients and limited
        range of logical interface IDs (0 - HIF_CLIENTS_MAX).
     */
    if ((uint8_t)phy_if_id >= HIF_CLIENTS_MAX)
    {
        NXP_LOG_ERROR("Incompatible interface ID requested: %d\n", phy_if_id);
        client = NULL;
    }
    else if (NULL == handler)
    {
        NXP_LOG_ERROR("Event handler is mandatory\n");
        client = NULL;
    }
    else
    {
        client = &hif_drv->clients[phy_if_id];

        client = pfe_hif_drv_client_register_ll(
                hif_drv,    /* HIF driver instance */
                client,     /* Client storage */
                phy_if_id,  /* Physical interface ID */
                client_queue,                   /* Number of TX/RX queues */
                client_fifo_queue,              /* FIFO for the TX/RX queue */
                promisc,    /* TRUE if client shall be promiscuous */
                handler,    /* Client's event handler */
                priv);      /* Private data to be passed to handler */

        if (NULL != client)
        {
            NXP_LOG_INFO("HIF client %d registered\n", phy_if_id);
        }
    }
    return client;
}

/**
 * @brief Register and configure the client
 */
static pfe_hif_drv_client_t *
    pfe_hif_drv_client_register_ll(
        pfe_hif_drv_t *hif_drv,
        pfe_hif_drv_client_t *client,
        pfe_ct_phy_if_id_t phy_if_id,
        pfe_hif_drv_client_rx_tx_count *client_queue,
        pfe_hif_drv_client_fifo_queue  *client_fifo_queue,
        bool_t promisc,
        pfe_hif_drv_client_event_handler handler,
        void *priv)
{
    errno_t err;
    uint32_t txq_num_temp = client_queue->txq_num;
    uint32_t rxq_num_temp = client_queue->rxq_num;
    pfe_hif_drv_client_t *client_tmp = client;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL_PTR == hif_drv) || (NULL_PTR == client_tmp)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        client_tmp = NULL_PTR;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if ((uint8_t)phy_if_id >= HIF_CLIENTS_MAX)
        {
            NXP_LOG_DEBUG("Client ID out of supported range\n");
            client_tmp = NULL_PTR;
        }
        else
        {
            if (FALSE != client->active)
            {
                NXP_LOG_ERROR("Client already initialized\n");
                /* force to unregister */
                err = ECANCELED;
            }
            else
            {
                /*  Check if client is requesting more queues than supported */
                if (rxq_num_temp > HIF_DRV_CLIENT_QUEUES_MAX)
                {
                    NXP_LOG_WARNING("Client requests more (%u) RX queues than currently supported maximum (%d)\n",
                            (uint_t)rxq_num_temp, HIF_DRV_CLIENT_QUEUES_MAX);
                    rxq_num_temp = HIF_DRV_CLIENT_QUEUES_MAX;
                }

                /*  Check if client is requesting more queues than supported */
                if (txq_num_temp > HIF_DRV_CLIENT_QUEUES_MAX)
                {
                    NXP_LOG_WARNING("Client requests more (%u) TX queues than currently supported maximum (%d)\n",
                            (uint_t)txq_num_temp, HIF_DRV_CLIENT_QUEUES_MAX);
                    txq_num_temp = HIF_DRV_CLIENT_QUEUES_MAX;
                }

                /*    Initialize the instance */
                (void)autolibc_memset(client_tmp, 0, sizeof(pfe_hif_drv_client_t));

                client_tmp->id_mask = ((uint32_t)1U << (uint8_t)phy_if_id);
                client_tmp->active = FALSE;
                client_tmp->promisc = promisc;
                client_tmp->hif_drv = hif_drv;
                client_tmp->phy_if_id = phy_if_id;

                client_tmp->rx_qn = rxq_num_temp;
                client_tmp->tx_qn = txq_num_temp;
                client_tmp->event_handler = handler;
                client_tmp->priv = priv;

                /*  Create client's RX queues */
                err = hif_client_create_rx_queues(client_tmp, client_fifo_queue->rxq_fifo);
                if (unlikely(EOK != err))
                {
                    NXP_LOG_ERROR("Can't create RX queues: %d\n", err);
                }
                else
                {
                    /*  Initialize client's TX queues */
                    err = hif_client_create_tx_queues(client_tmp, client_fifo_queue->txq_fifo);
                    if (unlikely(EOK != err))
                    {
                        NXP_LOG_ERROR("Can't create TX queues: %d\n", err);
                    }
                    else
                    {
                        #ifdef PFE_CFG_IEEE1588_SUPPORT
                        /*  Initialize PTP timestamp database */
                        err = pfe_hif_ptp_ts_db_init(&client_tmp->ptpdb);
                        if (EOK != err)
                        {
                            NXP_LOG_ERROR("PTP DB init failed\n");
                        }
                        else
                        #endif /* PFE_CFG_IEEE1588_SUPPORT */
                        {
                            /*  Activate the client */
                            client_tmp->active = TRUE;
                        }
                    }
                }
            }
            if (EOK != err)
            {
                /*  Release the client instance */
                pfe_hif_drv_client_unregister(client_tmp);
                client_tmp = NULL_PTR;
            }
        }
    }

    return client_tmp;
}

/**
 * @brief       Get hif_drv instance associated with the client
 * @param[in]   client Client instance
 * @return      Pointer to the HIF DRV instance
 */
pfe_hif_drv_t *pfe_hif_drv_client_get_drv(const pfe_hif_drv_client_t *client)
{
    pfe_hif_drv_t *ret = NULL;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == client))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = client->hif_drv;
    }
    return ret;
}

/**
 * @brief       Get private pointer provided in registration
 * @param[in]   client Client instance
 * @return      Private pointer value
 */
void *pfe_hif_drv_client_get_priv(const pfe_hif_drv_client_t *client)
{
    void *ret = NULL;
#ifdef PFE_CFG_NULL_ARG_CHECK
    if (unlikely(NULL == client))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = client->priv;
    }
    return ret;
}

/**
 * @brief       Unregister client from the HIF driver
 * @details     Routine removes the given HIF driver client and all associated resources. It
 *              adjusts internal HIF dispatching table and invalidates the client's entry so
 *              all ingress packets targeting the client will be dropped. HIF driver remains
 *              suspended after the call and pfe_hif_drv_start() is required to re-enable the
 *              operation.
 * @param[in]   client Client instance
 */
void pfe_hif_drv_client_unregister(pfe_hif_drv_client_t *client)
{
    bool_t enabled = FALSE;

    if (NULL_PTR != client)
    {
        if (client == &client->hif_drv->clients[HIF_CLIENTS_IHC_IDX])
        {
            NXP_LOG_INFO("Removing IHC client\n");
        }
        else if (client == &client->hif_drv->clients[HIF_CLIENTS_AUX_IDX])
        {
            NXP_LOG_INFO("Removing AUX client\n");
        }
        else
        {
            NXP_LOG_INFO("Removing client %d\n", client->phy_if_id);
        }

        /* Suspend HIF driver to ensure coherent client deregistration */
        enabled = client->hif_drv->tx_enabled || client->hif_drv->rx_enabled;
        if (enabled)
        {
            pfe_hif_drv_stop(client->hif_drv);
        }

        /* Unregister from HIF. After this the HIF RX dispatcher will not fill client's RX queues. */
        client->active = FALSE;

        /* Release queues */
        hif_client_free_rx_queues(client);
        hif_client_free_tx_queues(client);

#ifdef PFE_CFG_IEEE1588_SUPPORT
        /* Finalize the timestamp DB */
        pfe_hif_ptp_ts_db_fini(&client->ptpdb);
#endif /* PFE_CFG_IEEE1588_SUPPORT */

        if (enabled)
        {
            (void)pfe_hif_drv_start(client->hif_drv);
        }

        /* Cleanup memory */
        (void)autolibc_memset(client, 0, sizeof(pfe_hif_drv_client_t));
    }
}

/**
 * @brief       Get packet from RX queue
 * @param[in]   client Client instance
 * @param[in]   queue RX queue number
 * @return      Pointer to SW buffer descriptor containing the packet or NULL
 *              if the queue does not contain data
 *
 * @warning     Intended to be called from a single client context only, i.e.
 *              from a single thread per client.
 */
pfe_hif_pkt_t * pfe_hif_drv_client_receive_pkt(pfe_hif_drv_client_t *client, uint32_t queue)
{
    pfe_hif_pkt_t *ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == client))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = fifo_get(client->rx_q[queue].rx_fifo);
    }

    /* No resource protection here */
    return ret;
}

/**
 * @brief       Check if there is another Rx packet in queue
 * @param[in]   client Client instance
 * @param[in]   queue RX queue number
 * @retval      TRUE There is at least one Rx packet in Rx queue
 * @retval      FALSE There is no Rx packet in Rx queue
 *
 * @warning     Intended to be called from a single client context only, i.e.
 *              from a single thread per client.
 */
bool_t pfe_hif_drv_client_has_rx_pkt(const pfe_hif_drv_client_t *client, uint32_t queue)
{
    uint32_t fill_level;
    errno_t err;
    bool_t ret = TRUE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == client))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = FALSE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* No resource protection here */
        err = fifo_get_fill_level((volatile fifo_t const *)client->rx_q[queue].rx_fifo, &fill_level);
        if (unlikely(EOK != err))
        {
            NXP_LOG_ERROR("Unable to get fifo fill level: %d\n", err);
            fill_level = 0U;
        }
        if (0U != fill_level)
        {
            ret = TRUE;
        }
        else
        {
            ret = FALSE;
        }
    }
    return ret;
}

/**
 * @brief       Release packet
 * @param[in]   pkt The packet instance
 */
void pfe_hif_pkt_free(const pfe_hif_pkt_t *pkt)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == pkt) || unlikely(NULL == pkt->client))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Return buffer to the pool. Resource protection is embedded. */
        ret = pfe_hif_chnl_release_buf(pkt->client->hif_drv->channel, (void *)pkt->data);
        if (unlikely(EOK != ret))
        {
            NXP_LOG_ERROR("RX buffer leak.\n");
        }
    }
}

/**
 * @brief       Get TX confirmation
 * @param[in]   client Client instance
 * @param[in]   queue TX queue number
 * @return      Pointer to data associated with the transmitted buffer. See pfe_hif_drv_client_xmit_pkt()
 *              and pfe_hif_drv_client_xmit_sg_pkt().
 * @note        Only a single thread can call this function for given client+queue
 *              combination.
 */
void * pfe_hif_drv_client_receive_tx_conf(const pfe_hif_drv_client_t *client, uint32_t queue)
{
    void *ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == client))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = fifo_get(client->tx_q[queue].tx_conf_fifo);
    }
    return ret;
}

/**
 * @brief       The TX processing routine
 * @details     Process TX confirmations reported by HIF channel and notify
 *              particular clients if their packets were transmitted. Should
 *              be called often enough to keep the channel ready, and clients
 *              informed about their transmission requests.
 * @param[in]   hif_drv The HIF driver instance
 * @param[in]   budget Maximum number of TX confirmations to clean-up at once
 *
 * @return      Number of processed TX frame confirmations
 * @note        No TX resource protection is included. Shall be done by caller
 *              routine.
 */
static uint32_t pfe_hif_drv_process_tx(pfe_hif_drv_t *hif_drv, uint32_t budget)
{
    pfe_hif_tx_meta_t *tx_metadata;
    pfe_hif_drv_client_t *client;
    uint32_t processed_count = 0U;
    uint32_t dropped_count = 0U;
    uint32_t tx_clients = 0U;
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*
        * NOTE:
        *    - This statement has no functional purpose. It is purely to remove a compiler warning.
        *    - In case there is no TX confirmation received, the event_handler will not be called anyway.
        */
        tx_metadata = &hif_drv->tx_meta[hif_drv->tx_meta_rd_idx];

        do
        {
            /* Dequeue TX confirmation. This is actually only check whether
            some next frame has been transmitted. */
            if (EOK != pfe_hif_chnl_get_tx_conf(hif_drv->channel))
            {
                /* No more entries to dequeue */
                break;
            }

            /* Get metadata associated with the transmitted frame */
            tx_metadata = &hif_drv->tx_meta[hif_drv->tx_meta_rd_idx];

            /* Get client */
            client = tx_metadata->client;

            if (unlikely(NULL == client))
            {
                if (0U == dropped_count)
                {
                    NXP_LOG_WARNING("Client not registered, dropping TX confirmation(s)\n");
                }

#ifdef HIF_STATS
                hif_drv->counters[HIF_STATS_TX_CONFIRMATION_DROPS]++;
#endif
                dropped_count++;

                /* Move to next entry */
                hif_drv->tx_meta_rd_idx++;
                if (hif_drv->tx_meta_rd_idx >= PFE_CFG_HIF_RING_LENGTH)
                {
                    hif_drv->tx_meta_rd_idx = 0U;
                }
                continue;
            }

            /* We have end-of-frame confirmation here. Put the reference data to client's TX confirmation queue. */
            ret = fifo_put(client->tx_q[tx_metadata->q_no].tx_conf_fifo, tx_metadata->ref_ptr);
            if (unlikely(EOK != ret))
            {
                /* Drop the confirmation */
                if (client->id_mask == (1UL << HIF_CLIENTS_IHC_IDX))
                {
                    /* The client is IHC client */
                    NXP_LOG_WARNING("IHC client's TX confirmation queue is full. TX confirmation dropped.\n");
                }
                else if (client->id_mask == (1UL << HIF_CLIENTS_AUX_IDX))
                {
                    NXP_LOG_WARNING("AUX client's TX confirmation queue is full. TX confirmation dropped.\n");
                }
                else
                {
                    /* The client is standard client */
                    NXP_LOG_WARNING("Client's (%d) TX confirmation queue is full. TX confirmation dropped.\n",
                        client->phy_if_id);
                }
#ifdef HIF_STATS
                hif_drv->counters[HIF_STATS_TX_CONFIRMATION_DROPS]++;
#endif
            }
            else
            {
                /* Remember that THIS client has a new confirmation */
                tx_clients |= client->id_mask;
                client->tx_q[tx_metadata->q_no].has_new_data = TRUE;
                if (((uint32_t)tx_metadata->ets_flag & (uint32_t)HIF_TX_ETS) != 0UL)
                {
                    client->tx_q[tx_metadata->q_no].has_new_ets_data = TRUE;
                }
            }

            /* Move to next entry */
            hif_drv->tx_meta_rd_idx++;
            if (hif_drv->tx_meta_rd_idx >= PFE_CFG_HIF_RING_LENGTH)
            {
                hif_drv->tx_meta_rd_idx = 0U;
            }

        } while (++processed_count < budget);

#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
        /* Notify client(s) about new confirmations */

        uint32_t qq;
        uint32_t ii;

        ii=0U;
        while(tx_clients!=0U)
        {
            if ((tx_clients & 0x1U) != 0U)
            {
                /* Get client */
                client = &hif_drv->clients[ii];
                /* Call handlers */
                for (qq = 0U; qq < HIF_DRV_CLIENT_QUEUES_MAX; qq++)
                {
                    if (TRUE == client->tx_q[qq].has_new_data)
                    {
                        (void)client->event_handler(client, client->priv, EVENT_TXDONE_IND, qq);
                        client->tx_q[qq].has_new_data = FALSE;
                    }
                }
            }
            ii++;
            tx_clients>>=1;
        }
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

        if (unlikely(dropped_count > 0U))
        {
            NXP_LOG_INFO("%u TX confirmations dropped\n", (uint_t)dropped_count);
        }
    }
    return processed_count;
}

/**
 * @brief       Set physical interface for TX traffic injection
 * @details     Set physical interface to be used when driver will attempt to transmit
 *              a packet in "inject" mode.
 * @param[in]   client Client instance
 * @param[in]   phy_if_id The physical interface ID
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_hif_drv_client_set_inject_if(pfe_hif_drv_client_t *client, pfe_ct_phy_if_id_t phy_if_id)
{
    errno_t ret;

    if (phy_if_id >= PFE_PHY_IF_ID_INVALID)
    {
        ret = EINVAL;
    }
    else
    {
        /* Set new physical interface */
        client->phy_if_id = phy_if_id;
        ret = EOK;
    }
    return ret;
}

/**
 * @brief       Initialize TX header
 * @param[in]   client Client instance
 * @param[in]   tx_header Pointer to the tx header
 * @param[in]   queue TX queue number
 * @return      EOK if success, error code otherwise.
 */
errno_t pfe_hif_drv_init_tx_header(pfe_hif_drv_client_t *client, pfe_ct_hif_tx_hdr_t *tx_header, const uint32_t queue)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == client) || (NULL == tx_header)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        tx_header->chid = (uint8_t)pfe_hif_chnl_get_id(client->hif_drv->channel);
#ifdef PFE_CFG_HIF_PRIO_CTRL
        /* Firmware will assign queue/priority */
        tx_header->queue = 255U;
#else
        tx_header->queue = queue;
#endif /* PFE_CFG_HIF_PRIO_CTRL */

        tx_header->flags = (pfe_ct_hif_tx_flags_t)0U;;
#ifdef PFE_CFG_CSUM_ALL_FRAMES
        tx_header->flags |= HIF_TX_IP_CSUM | HIF_TX_TCP_CSUM | HIF_TX_UDP_CSUM;
#else
    #if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_IPV4)
        tx_header->flags |= HIF_TX_IP_CSUM;
    #endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_IPV4 */
    #if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP)
        tx_header->flags |= HIF_TX_TCP_CSUM;
    #endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_TCP */
    #if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP)
        tx_header->flags |= HIF_TX_UDP_CSUM;
    #endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_UDP */
    #if (STD_ON == ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP)
        tx_header->flags |= HIF_TX_ICMP_CSUM;
    #endif /* ETH_43_PFE_ENABLE_OFFLOAD_CSUM_ICMP */
#endif /* PFE_CFG_CSUM_ALL_FRAMES */

        if (client->id_mask == (1UL << HIF_CLIENTS_AUX_IDX))
        {
            /* Let PFE route the packet using current configuration */
            tx_header->e_phy_ifs = 0U;
        }
        else
        {
            /* Traffic from standard clients can be routed or injected */
#ifdef PFE_CFG_ROUTE_HIF_TRAFFIC
            /* Tag the frame with ID of target physical interface. PFE will
               be able to use this to route the frame using Flexible Router. */
            tx_header->cookie = oal_htonl(client->phy_if_id);
#else
            /* Let PFE inject the frame directly to egress interface */
            tx_header->e_phy_ifs = oal_htonl(1UL << (uint8_t)client->phy_if_id);
            tx_header->flags |= HIF_TX_INJECT;
#endif /* PFE_CFG_ROUTE_HIF_TRAFFIC */
        }
        ret = EOK;
    }
    return ret;
}

/**
 * @brief       Transmit packet given as a SG list of buffers
 * @param[in]   client Client instance
 * @param[in]   queue TX queue number
 * @param[in]   sg_list Pointer to the SG list
 * @param[in]   ref_ptr Reference pointer to be provided within TX confirmation.
 * @return      EOK if success, error code otherwise.
 */
errno_t pfe_hif_drv_client_xmit_sg_pkt(pfe_hif_drv_client_t *client, uint32_t queue, const hif_drv_sg_list_t *const sg_list, void *ref_ptr)
{
    errno_t err = EOK;
    uint32_t ii;
    pfe_hif_tx_meta_t *tx_metadata;
    pfe_hif_drv_t *hif_drv;
    pfe_ct_hif_tx_hdr_t *tx_hdr;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == client) || (NULL == sg_list) || (NULL == ref_ptr)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        err = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Get HIF driver instance from client */
        hif_drv = client->hif_drv;

        /* Enter critical section */
        oal_mutex_lock(PFE_HIF_DRV_MUTEX_01);

#if (FALSE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
        /* Process TX confirmations */
        while (HIF_TX_POLL_BUDGET <= pfe_hif_drv_process_tx(hif_drv, HIF_TX_POLL_BUDGET))
        {
            ;
        }

        pfe_hif_chnl_tx_dma_start(hif_drv->channel);
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */

        if (unlikely(FALSE == hif_drv->tx_enabled))
        {
            /* Transmission is not allowed */
            err = EPERM;
        }

        /*
            Check if we have enough TX resources. We need one for each SG entry plus
            one for HIF header.
        */
        else if (unlikely(FALSE == pfe_hif_chnl_can_accept_tx_num(hif_drv->channel, sg_list->size)))
        {
            /* Channel can't accept buffers (TX ring full?). Try to schedule
               TX maintenance to process potentially transmitted packets and
               make some space in TX ring. */
            pfe_hif_chnl_tx_dma_start(hif_drv->channel);
            err = ENOSPC;
        }
        else
        {
            /*
                HIF driver must keep local copy of the HW TX ring to gain access
                to virtual buffer addresses in case when data is being
                acknowledged to a client. For this purpose the SW descriptors
                are being used.
            */

            /* Get metadata storage */
            tx_metadata = &hif_drv->tx_meta[hif_drv->tx_meta_wr_idx];
            tx_metadata->client = client;
            tx_metadata->q_no = queue;
    
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
            if (pfe_hif_chnl_get_id(hif_drv->channel) >= PFE_HIF_CHNL_NOCPY_ID)
            {
                tx_hdr = (pfe_ct_hif_tx_hdr_t *)((addr_t)sg_list->items[0U].data_va + pfe_hif_chnl_get_lmem_hdr_size(hif_drv->channel) + 256U);
            }
            else
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
            {
                tx_hdr = (pfe_ct_hif_tx_hdr_t *)((addr_t)sg_list->items[0U].data_va);
                /* Ensure that the HIF_TX_ETS flag is cleared before transmitting any frame.
                   In case of using HIF_NOCPY, it was done in Eth_PFE_LLD_ProvideBufferDataArea */
                tx_hdr->flags &= ~HIF_TX_ETS;
            }

#ifdef PFE_CFG_IEEE1588_SUPPORT
    
            /* Check bDoTS flag in Tx metadata */
            Eth_PFE_LLD_trTxTsRef *tx_ts_ref_mcal;
            const Eth_PFE_LLD_trTxRefData *ref_ptr_mcal = (Eth_PFE_LLD_trTxRefData *)ref_ptr;
            const trTxMeta *tx_meta = Eth_PFE_LLD_GetTxBufMeta(ref_ptr_mcal->u8CtrlIdx, ref_ptr_mcal->u16BufIdx);
            if (TRUE == tx_meta->bDoTS)
            {
                /* Check if frame is a PTP message and need timestamp */
                oal_util_ptp_header_t *ptph;
                uint16_t refnum;

#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
                if (EOK == oal_util_parse_ptp((uint8_t *)((addr_t)sg_list->items[0].data_va + TX_BUF_FRAME_OFFSET + pfe_hif_chnl_get_lmem_hdr_size(hif_drv->channel)), sg_list->items[0].len, &ptph))
#else
                if (EOK == oal_util_parse_ptp((uint8_t *)((addr_t)sg_list->items[0].data_va + TX_BUF_FRAME_OFFSET), sg_list->items[0].len, &ptph))
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
                {
                    /* Only Event messages will be pushed into database */
                    if((ptph->byte1.messageType == PTP_MSG_SYNC) || (ptph->byte1.messageType == PTP_MSG_DELAY_REQ) ||
                        (ptph->byte1.messageType == PTP_MSG_PDELAY_REQ) || (ptph->byte1.messageType == PTP_MSG_PDELAY_RESP))
                    {
                        /* Request TS */
                        /* Sequence numbers are allowed to use only lower 12 bits */
                        refnum = (uint16_t)(oal_util_get_unique_seqnum32() & 0x0fffU); /* Don't switch endian */
                        tx_hdr->refnum = oal_htons(refnum);
                        tx_hdr->flags |= HIF_TX_ETS;
                        tx_metadata->ets_flag |= HIF_TX_ETS;

                        /* Store the values for MCAL Tx confirmation */
                        tx_ts_ref_mcal = Eth_PFE_LLD_GetTxBufTsRef(ref_ptr_mcal->u8CtrlIdx, ref_ptr_mcal->u16BufIdx);
                        tx_ts_ref_mcal->u8MessageType = ptph->byte1.messageType;
                        tx_ts_ref_mcal->u16SourcePortID = oal_ntohs(ptph->sourcePortID);
                        tx_ts_ref_mcal->u16SequenceID = oal_ntohs(ptph->sequenceID);

                        /* Store the TX frame to DB */
                        err = pfe_hif_ptp_ts_db_push_msg(&client->ptpdb, FALSE, refnum, ptph->byte1.messageType,
                                oal_ntohs(ptph->sourcePortID), oal_ntohs(ptph->sequenceID));
                        if (EOK != err)
                        {
                            NXP_LOG_ERROR("Could not store PTP message: %d\n", err);
                            tx_hdr->flags &= ~HIF_TX_ETS;
                            tx_metadata->ets_flag &= ~HIF_TX_ETS;
                        }
                        else
                        {
#ifdef PFE_CFG_DEBUG
                            NXP_LOG_DEBUG("New (TX) PTP frame: Type: 0x%x, Port: 0x%x, SeqID: 0x%x\n",
                                ptph->byte1.messageType, oal_ntohs(ptph->sourcePortID), oal_ntohs(ptph->sequenceID));
#endif /* PFE_CFG_DEBUG */
                        }
                    }
                }
            }
#endif /* PFE_CFG_IEEE1588_SUPPORT */

            tx_metadata->ref_ptr = ref_ptr;

            /*  Transmit particular packet buffers */
            for (ii=0U; ii<sg_list->size; ii++)
            {
                /* Transmit the buffer */
                err = pfe_hif_chnl_tx(  client->hif_drv->channel,
                                        sg_list->items[ii].data_pa,
                                        sg_list->items[ii].data_va,
                                        sg_list->items[ii].len,
                                        ((ii+1U) >= sg_list->size));
                if (unlikely(EOK != err))
                {
                    /* TODO: We need somehow reset the TX BD Ring because HIF header has already been enqueued. */
                    NXP_LOG_ERROR("Fatal error, TX channel will get stuck...\n");
                    err = ECANCELED;
                    break;
                }
            }
            if(EOK == err)
            {
                /* Move to next entry */
                hif_drv->tx_meta_wr_idx++;
                if (hif_drv->tx_meta_wr_idx >= PFE_CFG_HIF_RING_LENGTH)
                {
                    hif_drv->tx_meta_wr_idx = 0U;
                }

                /* Invoke TX confirmation job */
#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
#if (FALSE == HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION)
                if (pfe_hif_chnl_has_tx_conf(hif_drv->channel))
                {
                    /* Channel has transmitted a buffer (buffers) */
                    if (unlikely(EOK != oal_job_run(&hif_drv->tx_job)))
                    {
                        NXP_LOG_ERROR("TX job trigger failed\n");
                    }
                }
#endif /* HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION */
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */
            }
        }
        /* Leave the critical section */
        oal_mutex_unlock(PFE_HIF_DRV_MUTEX_01);
    }
    return err;
}

/**
 * @brief       Transmit a single-buffer packet
 * @param[in]   client Client instance
 * @param[in]   queue TX queue number
 * @param[in]   data_pa Physical address of buffer to be sent
 * @param[in]   data_va Virtual address of buffer to be sent
 * @param[in]   len Length of the buffer
 * @param[in]   ref_ptr Reference pointer to be provided within TX confirmation.
 * @return      EOK if success, error code otherwise.
 */
errno_t pfe_hif_drv_client_xmit_pkt(pfe_hif_drv_client_t *client, uint32_t queue, void *data_pa, void *data_va, uint32_t len, void *ref_ptr)
{
    hif_drv_sg_list_t sg_list;

    sg_list.size = 1;

    sg_list.flags.common = (pfe_hif_drv_common_flags_t)0U;
    sg_list.flags.specific.tx_flags = (pfe_ct_hif_tx_flags_t)0U;
    sg_list.items[0].data_pa = data_pa;
    sg_list.items[0].data_va = data_va;
    sg_list.items[0].len = len;
    sg_list.dst_phy = PFE_PHY_IF_ID_INVALID;

    return pfe_hif_drv_client_xmit_sg_pkt(client, queue, &sg_list, ref_ptr);
}

/**
 * @brief       Get PTP timestamp
 * @details     Function will return timestamp for PTP message given by set arguments
 *              if such timestamp has been captured
 * @param[in]   client The client instance
 * @param[in]   rx TRUE means to get ingress TS, FALSE means egress
 * @param[in]   type PTP message type
 * @param[in]   port PTP source port ID
 * @param[in]   seq_id PTP sequence ID
 * @param[out]  ts_sec Seconds part of the timestamp
 * @param[out]  ts_nsec Nanoseconds part of the timestamp
 * @retval      EOK Timestamp has been found and is valid
 * @retval      ENOENT Timestamp matching given criteria not found
 */
errno_t pfe_hif_drv_client_get_ts(pfe_hif_drv_client_t * const client, bool_t rx,
        uint8_t type, uint16_t port, uint16_t seq_id, uint32_t * const ts_sec, uint32_t * const ts_nsec)
{
#ifdef PFE_CFG_IEEE1588_SUPPORT
    return pfe_hif_ptp_ts_db_pop(&client->ptpdb, type, port, seq_id, ts_sec, ts_nsec, rx);
#else
    NXP_LOG_ERROR("PTP support not enabled\n");
    (void)client;
    (void)rx;
    (void)type;
    (void)port;
    (void)seq_id;
    (void)ts_sec;
    (void)ts_nsec;
    return EINVAL;
#endif /* */
}

/**
 * @brief       Create new HIF driver instance
 * @param[in]   channel The HIF channel instance to be managed
 */
pfe_hif_drv_t *pfe_hif_drv_create(pfe_hif_chnl_t *channel)
{
    pfe_hif_drv_t *hif_drv;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == channel))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        hif_drv = NULL_PTR;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */

    /* Check if is OK to use metadata storage associated with buffers from pool */
    if (pfe_hif_chnl_get_meta_size(channel) < sizeof(pfe_hif_pkt_t))
    {
        NXP_LOG_ERROR("Meta storage size (%u) is less than required (%u)\n", (uint_t)(pfe_hif_chnl_get_meta_size(channel)), (uint_t)sizeof(pfe_hif_pkt_t));
        hif_drv = NULL_PTR;
    }
    else
    {
        hif_drv = &common_hif_drv;
        (void)autolibc_memset(hif_drv, 0, sizeof(pfe_hif_drv_t));
        hif_drv->channel = channel;
    }

    return hif_drv;
}

/**
 * @brief   HIF initialization routine
 * @details Function performs following initialization:
 *          - Initializes HIF interrupt handler(s)
 *          - Performs HIF HW initialization and enables RX/TX DMA
 */
errno_t pfe_hif_drv_init(pfe_hif_drv_t *hif_drv)
{
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        return EINVAL;
    }
#endif /* PFE_CFG_NULL_ARG_CHECK */

    if (hif_drv->initialized)
    {
        NXP_LOG_ERROR("HIF already initialized. Exiting.\n");
        return ECANCELED;
    }

    /* Initialize RX/TX resources */
    hif_drv->started = FALSE;

    if (pfe_hif_drv_create_data_channel(hif_drv) != 0)
    {
        NXP_LOG_ERROR("%s: Could not initialize data channel\n", __func__);
        ret = ENOMEM;
        goto err1;
    }

#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
    ret = pfe_hif_chnl_set_event_cbk(hif_drv->channel, HIF_CHNL_EVT_RX_IRQ, &pfe_hif_drv_rx_job, (void *)hif_drv);
#endif /* PFE_CFG_HIF_IRQ_ENABLED */

    if (EOK != ret)
    {
        NXP_LOG_ERROR("Could not register RX ISR\n");
        goto err3;
    }

#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
    /* Attach channel TX ISR */
    ret = pfe_hif_chnl_set_event_cbk(hif_drv->channel, HIF_CHNL_EVT_TX_IRQ, &pfe_hif_drv_chnl_tx_isr, (void *)hif_drv);
    if (EOK != ret)
    {
        NXP_LOG_ERROR("Could not register TX ISR\n");
        goto err6;
    }
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */

    /* Attach channel out-of-buffers event handler */
    ret = pfe_hif_chnl_set_event_cbk(hif_drv->channel, HIF_CHNL_EVT_RX_OOB, &pfe_hif_drv_chnl_rx_oob_handler, (void *)hif_drv);
    if (EOK != ret)
    {
        NXP_LOG_ERROR("Could not register RX OOB handler\n");
        goto err7;
    }

#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
    /* Create TX job */
    if (NULL == oal_job_create(&pfe_hif_drv_tx_job, (void *)hif_drv, "HIF TX JOB", OAL_PRIO_NORMAL, &hif_drv->tx_job))
    {
        ret = EFAULT;
        goto err9;
    }
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */

    hif_drv->rx_enabled = FALSE;
    hif_drv->tx_enabled = FALSE;
    hif_drv->initialized = TRUE;

    return EOK;

#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
err9:
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */
    if (EOK != pfe_hif_chnl_set_event_cbk(hif_drv->channel, HIF_CHNL_EVT_RX_OOB, NULL, NULL))
    {
        NXP_LOG_ERROR("pfe_hif_chnl_set_event_cbk() failed (RX OOB callback)\n");
    }
err7:
#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
#if (TRUE == HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION)
    if (EOK != pfe_hif_chnl_set_event_cbk(hif_drv->channel, HIF_CHNL_EVT_TX_IRQ, NULL, NULL))
    {
        NXP_LOG_ERROR("pfe_hif_chnl_set_event_cbk() failed (TX callback)\n");
    }
#if (TRUE == PFE_CFG_HIF_IRQ_ENABLED)
err6:
#endif /* PFE_CFG_HIF_IRQ_ENABLED */
#endif /* HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION */
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */
    if (EOK != pfe_hif_chnl_set_event_cbk(hif_drv->channel, HIF_CHNL_EVT_RX_IRQ, NULL, NULL))
    {
        NXP_LOG_ERROR("pfe_hif_chnl_set_event_cbk() failed (RX callback)\n");
    }
err3:
    pfe_hif_drv_destroy_data_channel(hif_drv);
err1:

    return ret;
}

/**
 * @brief       Start traffic at HIF level
 * @details     Data transmission/reception is enabled
 * @param[in]   hif_drv The driver instance
 */
errno_t pfe_hif_drv_start(pfe_hif_drv_t *hif_drv)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (FALSE == hif_drv->initialized)
        {
            NXP_LOG_ERROR("HIF driver not initialized\n");
            ret = ENODEV;
        }
        else
        {
            NXP_LOG_INFO("Enabling HIF channel RX/TX\n");

            /* Enable RX */
            if (EOK != pfe_hif_chnl_rx_enable(hif_drv->channel))
            {
                NXP_LOG_ERROR("Couldn't enable RX\n");
            }
            else
            {
                hif_drv->rx_enabled = TRUE;
            }

            /* Enable TX */
            if (EOK != pfe_hif_chnl_tx_enable(hif_drv->channel))
            {
                NXP_LOG_ERROR("Couldn't enable TX\n");
            }
            else
            {
                hif_drv->tx_enabled = TRUE;
            }

            /* Enable the channel interrupts */
            NXP_LOG_INFO("Enabling channel interrupts\n");

            pfe_hif_chnl_rx_irq_unmask(hif_drv->channel);

        #if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
        #if (TRUE == HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION)
            pfe_hif_chnl_tx_irq_unmask(hif_drv->channel);
        #endif /* HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION */
        #endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */

            NXP_LOG_INFO("HIF driver is started\n");

            ret = EOK;
        }
    }
    return ret;
}

/**
 * @brief       Stop tx traffic at HIF level
 * @details     No resource releasing is done here. This call
 *              only ensures that tx traffic is suppressed at
 *              the HIF channel level so HIF driver is not receiving
 *              any notifications about data transfers and
 *              is not accessing any TX resources.
 * @param[in]   hif_drv The driver instance
 */
static void pfe_hif_drv_stop_tx(pfe_hif_drv_t *hif_drv)
{
    uint32_t hif_stop_timeout;

    /* Stop TX */
    if (TRUE == hif_drv->tx_enabled)
    {
        NXP_LOG_DEBUG("Disabling channel TX path\n");
        pfe_hif_chnl_tx_disable(hif_drv->channel);

        hif_stop_timeout = 10;
        do
        {
            if (pfe_hif_chnl_is_tx_dma_active(hif_drv->channel))
            {
                oal_time_usleep(250);
            }
            else
            {
                break;
            }
        } while (0U != hif_stop_timeout--);

        if (pfe_hif_chnl_is_tx_dma_active(hif_drv->channel))
        {
            NXP_LOG_WARNING("Unable to stop the HIF TX DMA\n");
        }

        /* Disallow transmission (and TX confirmation) and ensure the change has been applied */
        hif_drv->tx_enabled = FALSE;

        /*
         *  ---------------------------------------------------------------------
         *    Here the TX resource is disabled. No more TX confirmations can be
         *    generated.
         *    Run the TX confirmation job to process all pending TX confirmations.
         *    ---------------------------------------------------------------------
         */

#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
        if (EOK != oal_job_run(&hif_drv->tx_job))
        {
            NXP_LOG_ERROR("TX job trigger failed\n");
        }

        if (EOK != oal_job_drain(&hif_drv->tx_job))
        {
            NXP_LOG_ERROR("Unable to finish TX job\n");
        }
#else
        /* No deferred job. Process remaining TX confirmations directly here. */
        while (HIF_TX_POLL_BUDGET <= pfe_hif_drv_process_tx(hif_drv, HIF_TX_POLL_BUDGET))
        {
            ;
        }
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */

#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB)
#if (TRUE == HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION)
        NXP_LOG_INFO("Disabling channel TX IRQ\n");
        pfe_hif_chnl_tx_irq_mask(hif_drv->channel);
#endif /* HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION */
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB */

        /*
         *  -------------------------------------------------------------------------
         *  Here is ensured that:
         *      - TX nor TX confirmation tasks will be executed
         *      - TX routine is sealed by the 'tx_enabled' flag so won't be called
         *      - All TX confirmations are processed and new ones can't be generated
         *  -------------------------------------------------------------------------
         */

        /* Just a sanity check */
        if (hif_drv->tx_meta_rd_idx != hif_drv->tx_meta_wr_idx)
        {
            NXP_LOG_WARNING("TX confirmation FIFO still contains entries\n");
        }

        NXP_LOG_INFO("HIF driver TX path is stopped\n");
    }
}

/**
 * @brief       Stop rx traffic at HIF level
 * @details     No resource releasing is done here. This call
 *              only ensures that rx traffic is suppressed at
 *              the HIF channel level so HIF driver is not receiving
 *              any notifications about data transfers and
 *              is not accessing any RX resources.
 * @param[in]   hif_drv The driver instance
 */
static void pfe_hif_drv_stop_rx(pfe_hif_drv_t *hif_drv)
{
    uint32_t hif_stop_timeout;

    if (TRUE == hif_drv->rx_enabled)
    {
        NXP_LOG_DEBUG("Disabling channel RX path\n");
        pfe_hif_chnl_rx_disable(hif_drv->channel);

        hif_stop_timeout = 10;
        do
        {
            if (pfe_hif_chnl_is_rx_dma_active(hif_drv->channel))
            {
                oal_time_usleep(250);
            }
            else
            {
                break;
            }
        } while (0U != hif_stop_timeout--);

        if (pfe_hif_chnl_is_rx_dma_active(hif_drv->channel))
        {
            NXP_LOG_WARNING("Unable to stop the HIF RX DMA\n");
        }

        /*
         *  -------------------------------------------------------------------
         *  Here the RX resource is disabled. No more packets can be received.
         *  Run the RX job to process all pending received packets.
         *  -------------------------------------------------------------------
         */

        /* Disallow reception and ensure the change has been applied */
        hif_drv->rx_enabled = FALSE;

        NXP_LOG_DEBUG("Disabling channel RX IRQ\n");
        pfe_hif_chnl_rx_irq_mask(hif_drv->channel);

        /*
         *  -----------------------------------------------------------------------
         *  Here is ensured that RX tasks will NOT be executed:
         *      - RX routine is sealed by the 'rx_enabled' flag so won't be called
         *      - All pending ingress packets are processed
         *      - RX interrupt is disabled
         *  -----------------------------------------------------------------------
         */

        NXP_LOG_INFO("HIF driver RX path is stopped\n");
    }
}

/**
 * @brief       Stop traffic at HIF level
 * @details     No resource releasing is done here. This call
 *              only ensures that all traffic is suppressed at
 *              the HIF channel level so HIF driver is not receiving
 *              any notifications about data transfers (RX/TX) and
 *              is not accessing any RX/TX resources.
 * @param[in]   hif_drv The driver instance
 */
void pfe_hif_drv_stop(pfe_hif_drv_t *hif_drv)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Stop RX */
        pfe_hif_drv_stop_rx(hif_drv);
        /* Stop TX */
        pfe_hif_drv_stop_tx(hif_drv);

        /*
         *  -----------------------------------------------------
         *  Now the RX and TX resource of HIF channel are frozen
         *  -----------------------------------------------------
         */
    }
}

/**
 * @brief       Exit the HIF driver
 * @details     Terminate the HIF driver and release all allocated
 *              resources.
 * @param[in]   hif_drv The driver instance
 */
void pfe_hif_drv_exit(pfe_hif_drv_t *hif_drv)
{
    uint32_t ii;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */

    {
        if (FALSE == hif_drv->initialized)
        {
            NXP_LOG_WARNING("HIF is already disabled\n");
        }
        else
        {

            /* Check if a client is still registered */
            for (ii=0; ii<HIF_CLIENTS_MAX; ii++)
            {
                if (FALSE != hif_drv->clients[ii].active)
                {
                    NXP_LOG_ERROR("A client is still registered within HIF\n");
                }
            }

            NXP_LOG_INFO("HIF exiting\n");

            /* Stop the traffic */
            pfe_hif_drv_stop(hif_drv);

            /* Release HIF channel and buffers */
            pfe_hif_drv_destroy_data_channel(hif_drv);

            /* Uninstall channel event handlers */
            (void)pfe_hif_chnl_set_event_cbk(hif_drv->channel, HIF_CHNL_EVT_RX_IRQ, NULL, NULL);
#if (TRUE == HIF_CFG_DETACH_TX_CONFIRMATION_JOB) && (TRUE == HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION)
            (void)pfe_hif_chnl_set_event_cbk(hif_drv->channel, HIF_CHNL_EVT_TX_IRQ, NULL, NULL);
#endif /* HIF_CFG_DETACH_TX_CONFIRMATION_JOB && HIF_CFG_IRQ_TRIGGERED_TX_CONFIRMATION */
            (void)pfe_hif_chnl_set_event_cbk(hif_drv->channel, HIF_CHNL_EVT_RX_OOB, NULL, NULL);

            hif_drv->initialized = FALSE;

            NXP_LOG_INFO("HIF exited\n");
        }
    }
}

void pfe_hif_drv_destroy(pfe_hif_drv_t *hif_drv)
{
    if (NULL_PTR != hif_drv)
    {
        pfe_hif_drv_exit(hif_drv);
        hif_drv->channel = NULL_PTR;
    }
}

/**
 * @brief       Get HIF channel instance associated with the HIF driver instance
 * @param[in]   hif_drv hif_drv instance
 * @return      Pointer to the HIF CHANNEL associated with HIF channel instance or NULL if failed
 */
pfe_hif_chnl_t *pfe_hif_drv_get_chnl(const pfe_hif_drv_t *hif_drv)
{
    pfe_hif_chnl_t *entry = NULL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        entry = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        entry = hif_drv->channel;
    }
    return entry;
}

#define STR_TAB "  "

/**
 * @brief       Print ring status in text form
 * @param[in]   client The client instance
 * @param[in]   rx True if rx ring is needed
 * @param[in]   tx True if tx ring is needed
 */
void pfe_hif_drv_show_ring_status(pfe_hif_drv_t *hif_drv, bool_t rx, bool_t tx)
{
    uint32_t ii, qid;
    pfe_hif_drv_client_t *cl;
    struct client_rx_queue *rx_q;
    struct client_tx_queue *tx_q;
    pfe_hif_pkt_t *pkt;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == hif_drv))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
    cl = &hif_drv->clients[0]; /* TODO: loop over all */

    NXP_LOG_INFO("client %d\n", cl->phy_if_id);
    NXP_LOG_INFO(STR_TAB "status: %sinitialized\n", (NULL != cl) ? "" : "NOT");
    NXP_LOG_INFO(STR_TAB "queue level: rx %u, tx %u\n", (uint_t)cl->rx_qn, (uint_t)cl->tx_qn);

    /* RX */
    if ((FALSE != cl->active) && (TRUE == rx))
    {
        for (qid=0U; qid<cl->rx_qn; qid++)
        {
            rx_q = &cl->rx_q[qid];
            NXP_LOG_INFO(STR_TAB "RX queue %u: size %u\n", (uint_t)qid, (uint_t)rx_q->size);
            if (likely(NULL == rx_q->rx_fifo))
            {
                NXP_LOG_INFO(STR_TAB STR_TAB "[empty ring]\n");
                continue;
            }

            for (ii=0U; ii<rx_q->size; ii++)
            {
                pkt = (pfe_hif_pkt_t *)fifo_peek(rx_q->rx_fifo, ii);
                if (unlikely(NULL == pkt))
                {
                    NXP_LOG_INFO(STR_TAB STR_TAB "%-4u [free]\n", (uint_t)ii);
                }
                else
                {
                    NXP_LOG_INFO(STR_TAB STR_TAB "%4u %d:%d:%02x:%02x:0x%03x:%*phD\n",
                            (uint_t)ii, pkt->client->phy_if_id, pkt->q_no,
                                pkt->flags.common, pkt->flags.specific.rx_flags, pkt->len, 16, (void *)pkt->data);
                }
            } /* for ii */
        } /* for qid */
    }

    /* TX */
    if((FALSE != cl->active) && (TRUE == tx))
    {
        for (qid=0U; qid<cl->rx_qn; qid++)
        {
            tx_q = &cl->tx_q[qid];
            NXP_LOG_INFO(STR_TAB "TX queue %u: size %u\n", (uint_t)qid, (uint_t)tx_q->size);
            if (likely(NULL == tx_q->tx_conf_fifo))
            {
                NXP_LOG_INFO(STR_TAB STR_TAB "[empty ring]\n");
                continue;
            }

            for (ii=0U; ii<tx_q->size; ii++)
            {
                pkt = (pfe_hif_pkt_t *)fifo_peek(tx_q->tx_conf_fifo, ii);
                if (unlikely(NULL == pkt))
                {
                    NXP_LOG_INFO(STR_TAB STR_TAB "%-4u [free]\n", (uint_t)ii);
                }
                else
                {
                    NXP_LOG_INFO(STR_TAB STR_TAB "%4u %d:%d:%02x:%02x:0x%03x:%*phD\n",
                            (uint_t)ii, pkt->client->phy_if_id, pkt->q_no,
                            pkt->flags.common, pkt->flags.specific.tx_flags, pkt->len, 16, (void *)pkt->data);
                }
            } /* for ii */
        } /* for qid */
    }
    }
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /*PFE_CFG_MC_HIF*/

/** @}*/
