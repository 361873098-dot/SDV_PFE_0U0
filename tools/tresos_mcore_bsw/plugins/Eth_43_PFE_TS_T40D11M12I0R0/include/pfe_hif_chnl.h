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
 * @file        pfe_hif_chnl.h
 * @brief       The Host Interface channel
 * @details
 *              Purpose
 *              -------
 *              This is the software representation of the HIF channel including both data RX, and
 *              TX functionality. HIF channel is a middle-level SW component which a driver shall
 *              use to gain access to the Ethernet traffic. All data transmission requests as well
 *              as data reception operations and related control tasks are provided by a HIF channel
 *              instance API.
 *
 *              Initialization
 *              --------------
 *              The channel instance is created by pfe_hif_chnl_create(). Then it needs to be
 *              initialized to perform instance-specific configuration. For this purpose
 *              the pfe_hif_chnl_init() shall be called. Once successfully initialized, the
 *              channel can be activated by pfe_hif_chnl_rx_enable() and pfe_hif_chnl_tx_enable().
 *
 *              RX traffic management
 *              ---------------------
 *              Upon activation the channel starts receiving data into its internal buffer ring.
 *              The RX buffers are not managed by the channel itself and need to be supplied by
 *              user via pfe_hif_chnl_supply_rx_buf(). Each set of supplied buffers must be
 *              confirmed by pfe_hif_chnl_rx_dma_start() to let the hardware know that new empty
 *              RX buffers have become available (this means that multiple calls of
 *              pfe_hif_chnl_supply_rx_buf() can be confirmed by a single
 *              pfe_hif_chnl_rx_dma_start()).
 *
 *              @note To query if the channel is able to accept new RX buffers one can also use
 *                    the helper function pfe_hif_chnl_can_accept_rx_buf().
 *
 *              Usually, new RX data is indicated via dedicated RX IRQ. The RX IRQ number associated
 *              with channel can be retrieved via pfe_chi_chnl_get_irq() call. Driver then
 *              processes the interrupt by calling the pfe_hif_chnl_rx() until the function
 *              indicates 'no data'. In that case the driver acknowledges the RX interrupt via
 *              pfe_hif_chnl_ack_rx_irq(). Note that buffers dequeued by pfe_hif_chnl_rx() must
 *              be replaced by fresh ones using the pfe_hif_chnl_supply_rx_buf() call to keep the
 *              reception active.
 *
 *              Typical RX operation could look like:
 *              @code{.c}
 *                  void rx_irq_handler(void)
 *                  {
 *                      while (EOK == pfe_hif_chnl_rx())
 *                      {
 *                          // Process the received buffer
 *                      }
 *
 *                      while (TRUE == pfe_hif_chnl_can_accept_rx_buf())
 *                      {
 *                          pfe_hif_chnl_supply_rx_buf();
 *                      }
 *
 *                      pfe_hif_chnl_rx_dma_start();
 *                      pfe_hif_chnl_ack_rx_irq();
 *                  }
 *              @endcode
 *
 *              TX traffic management
 *              ---------------------
 *              A packet can be committed for transmission using the pfe_hif_chnl_tx() call. Since
 *              packet can consist of multiple separated buffers the call provides possibility to
 *              mark each of them by so called 'lifm' (last-in-frame) flag and driver is responsible
 *              for its validity. Transmission of committed buffer(s) is triggered by the
 *              pfe_hif_chnl_tx_dma_start().
 *
 *              @note To query if the channel is able to accept new TX buffers one can use
 *                    the helper function pfe_hif_chnl_can_accept_rx_buf().
 *
 *              Typical TX sequence could look like:
 *              @code{.c}
 *              ...
 *              if (pfe_hif_chnl_can_accept_tx_buf())
 *              {
 *                  if (EOK == pfe_hif_chnl_tx(buf->data, buf->is_last))
 *                  {
 *                      // Committed
 *                  }
 *                  else
 *                  {
 *                      // Failed
 *                  }
 *              }
 *
 *              pfe_hif_chnl_tx_dma_start();
 *              ...
 *              @endcode
 *
 *              Once a buffer is transmitted a TX confirmation is generated. Driver can query
 *              for new TX confirmations using the pfe_hif_chnl_has_tx_conf(). If a TX
 *              confirmation is available it can be 'dequeued' via pfe_hif_chnl_get_tx_conf().
 *              Order of TX confirmations as returned by pfe_hif_chnl_get_tx_conf() is exactly
 *              the same as the TX buffers were committed for transmission. Since channel does
 *              not internally keep mapping between TX confirmations and transmitted buffers,
 *              the driver must do the mapping using order of transmitted buffers and received
 *              TX confirmations.
 *
 *              TX confirmations can be handled for instance by periodic calls (or driven by
 *              TX IRQs) of routine such:
 *              @code{.c}
 *              void handle_tx_conf(void)
 *              {
 *                  if (TRUE == pfe_hif_chnl_has_tx_conf())
 *                  {
 *                      while (EOK == pfe_hif_chnl_get_tx_conf())
 *                      {
 *                          // Next packet has been transmitted
 *                      }
 *                  }
 *              }
 *              @endcode
 *
 *              Shutdown handling
 *              -----------------
 *              Once the channel is no more needed it can be stopped and subsequently destroyed.
 *              Driver needs to perform following sequence to properly shut the channel down:
 *              1.  Disable RX traffic via pfe_hif_chnl_rx_disable()
 *              2.  Drain all RX buffers via pfe_hif_chnl_rx()
 *              3.  Disable TX traffic via pfe_hif_chnl_tx_disable()
 *              4.  Drain remaining TX confirmations via pfe_hif_get_tx_conf(). Note that buffers
 *                  committed for transmission but not transmitted yet will be confirmed as they
 *                  were transmitted.
 *              5.  Destroy the HIF channel instance calling the pfe_hif_chnl_destroy()
 */

#ifndef PUBLIC_PFE_HIF_CHNL_H_
#define PUBLIC_PFE_HIF_CHNL_H_

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

#include "pfe_ct.h"
#include "pfe_hif_ring.h"

/**
 * @brief       RX OOB management
 * @details     When TRUE then RX OOB buffer management is embedded so caller layer
 *              can process the RX_OOB_EVENT. FALSE removed the feature.
 * @notice      In MCAL variant of hif chnl this cannot be turned of (switching not fully implemented yet)
 */
#define PFE_HIF_CHNL_CFG_RX_OOB_EVENT_ENABLED   TRUE

#if !defined(PFE_CFG_DETACHED_MINIHIF)
#include "pfe_bmu.h"
#endif /* PFE_CFG_DETACHED_MINIHIF */

#include "hal.h"

/**
 * @brief   List of available HIF channel events
 */
typedef enum
{
    HIF_CHNL_EVT_RX_IRQ = (1U << 0U),   /*!< RX interrupt - packet received */
    HIF_CHNL_EVT_TX_IRQ = (1U << 1U),   /*!< TX interrupt - packet transmitted */
    HIF_CHNL_EVT_RX_OOB = (1U << 2U)    /*!< Out of RX buffers */
} pfe_hif_chnl_event_t;

typedef void (* pfe_hif_chnl_drain_cbk_t)(void *arg, void **buf_pa);
typedef void (* pfe_hif_chnl_cbk_t)(void *arg);

/*  This is the channel ID used to identify HIF_NOCPY channel */
#define PFE_HIF_CHNL_NOCPY_ID       1000U

#define MAC_ADDRESS_SIZE        6U

typedef struct
{
    pfe_hif_chnl_cbk_t cbk;
    void *arg;
} pfe_hif_chnl_cbk_storage_t;

#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
typedef struct
{
    addr_t   base_addr;
    addr_t   meta_base_addr;
    uint16_t buf_size;
    uint16_t buf_number;
    uint16_t get_idx;
} rx_pool_t;
#endif

/**
 * @brief   The HIF channel representation type
 * @details Members are accessed with every channel operation (transmit/receive)
 *          thus the structure is allocated with proper alignment to
 *          improve cache locality.
 */
typedef struct __attribute__((aligned(HAL_CACHE_LINE_SIZE)))
{
    addr_t cbus_base_va;                /*  CBUS base virtual address */
    uint32_t id;                    /*  Channel ID within HIF (0, 1, 2, ...) */
    pfe_hif_ring_t *rx_ring;        /*  The RX ring instance */
    pfe_hif_ring_t *tx_ring;        /*  The TX ring instance */
#if (TRUE == PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED)
    rx_pool_t rx_pool;              /*  Pool of available RX buffers */
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
    const pfe_bmu_t *bmu;                   /*  Associated BMU instance */
#if defined(NXP_LOG_ENABLED)
    uint32_t a_cnt;                 /*  BMU allocations counter */
#endif /* NXP_LOG_ENABLED */
    uint16_t lmem_header_size;      /*  Size of the LMEM Header */
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
#endif /* PFE_HIF_CHNL_CFG_RX_BUFFERS_ENABLED */
    pfe_hif_chnl_cbk_storage_t rx_cbk;      /*  RX callback */
    pfe_hif_chnl_cbk_storage_t tx_cbk;      /*  TX callback */
    pfe_hif_chnl_cbk_storage_t rx_oob_cbk;  /*  RX Out-Of-Buffers callback */
} pfe_hif_chnl_t;

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

/*  RX */
errno_t pfe_hif_chnl_rx_enable(pfe_hif_chnl_t *chnl) __attribute__((cold));
void pfe_hif_chnl_rx_disable(pfe_hif_chnl_t *chnl) __attribute__((cold));
errno_t pfe_hif_chnl_rx(pfe_hif_chnl_t *chnl, void **buf_pa, uint32_t *len, bool_t *lifm) __attribute__((hot));
errno_t pfe_hif_chnl_rx_va(pfe_hif_chnl_t *chnl, void **buf_va, uint32_t *len, bool_t *lifm, void **meta) __attribute__((hot));
uint32_t pfe_hif_chnl_get_meta_size(const pfe_hif_chnl_t *chnl) __attribute__((cold));
errno_t pfe_hif_chnl_release_buf(pfe_hif_chnl_t *chnl, const void *buf_va) __attribute__((hot));
void pfe_hif_chnl_rx_dma_start(const pfe_hif_chnl_t *chnl) __attribute__((hot));
bool_t pfe_hif_chnl_can_accept_rx_buf(const pfe_hif_chnl_t *chnl) __attribute__((pure, hot));
errno_t pfe_hif_chnl_supply_rx_buf(const pfe_hif_chnl_t *chnl, const void *buf_pa, uint32_t size) __attribute__((hot));
uint32_t pfe_hif_chnl_get_rx_fifo_depth(const pfe_hif_chnl_t *chnl) __attribute__((pure, cold));
errno_t pfe_hif_chnl_bind_rx_ring(pfe_hif_chnl_t *chnl) __attribute__((cold));

/*  TX */
errno_t pfe_hif_chnl_tx_enable(pfe_hif_chnl_t *chnl) __attribute__((cold));
void pfe_hif_chnl_tx_disable(pfe_hif_chnl_t *chnl) __attribute__((cold));
errno_t pfe_hif_chnl_tx(const pfe_hif_chnl_t *chnl, const void *buf_pa, const void *buf_va, uint32_t len, bool_t lifm) __attribute__((hot));
void pfe_hif_chnl_tx_dma_start(const pfe_hif_chnl_t *chnl) __attribute__((hot));
bool_t pfe_hif_chnl_can_accept_tx_num(const pfe_hif_chnl_t *chnl, uint16_t num) __attribute__((pure, hot));
bool_t pfe_hif_chnl_tx_fifo_empty(const pfe_hif_chnl_t *chnl) __attribute__((pure, hot));
bool_t pfe_hif_chnl_has_tx_conf(const pfe_hif_chnl_t *chnl) __attribute__((pure, hot));
errno_t pfe_hif_chnl_get_tx_conf(pfe_hif_chnl_t *chnl) __attribute__((hot));
uint32_t pfe_hif_chnl_get_tx_fifo_depth(const pfe_hif_chnl_t *chnl) __attribute__((pure, cold));
errno_t pfe_hif_chnl_bind_tx_ring(pfe_hif_chnl_t *chnl) __attribute__((cold));
bool_t pfe_hif_chnl_tx_fifo_is_below_wm(const pfe_hif_chnl_t *chnl);

/*  Instance control */
#if !defined(PFE_CFG_DETACHED_MINIHIF)
errno_t pfe_hif_chnl_create(pfe_hif_chnl_t *chnl, addr_t cbus_base_va, uint32_t id, const pfe_bmu_t *bmu, bool_t minihif) __attribute__((cold));
#endif /* PFE_CFG_DETACHED_MINIHIF */
errno_t pfe_hif_chnl_init(pfe_hif_chnl_t *chnl, bool_t minihif) __attribute__((cold));
errno_t pfe_hif_chnl_isr(pfe_hif_chnl_t *chnl) __attribute__((hot));
void pfe_hif_chnl_destroy(pfe_hif_chnl_t *chnl) __attribute__((cold));
errno_t pfe_hif_chnl_set_event_cbk(pfe_hif_chnl_t *chnl, pfe_hif_chnl_event_t event, pfe_hif_chnl_cbk_t cbk, void *arg);
void pfe_hif_chnl_irq_mask(pfe_hif_chnl_t *chnl);
void pfe_hif_chnl_irq_unmask(pfe_hif_chnl_t *chnl);
void pfe_hif_chnl_rx_irq_mask(pfe_hif_chnl_t *chnl) __attribute__((hot));
void pfe_hif_chnl_rx_irq_unmask(pfe_hif_chnl_t *chnl) __attribute__((hot));
void pfe_hif_chnl_tx_irq_mask(pfe_hif_chnl_t *chnl) __attribute__((hot));
void pfe_hif_chnl_tx_irq_unmask(pfe_hif_chnl_t *chnl) __attribute__((hot));
bool_t pfe_hif_chnl_is_rx_dma_active(const pfe_hif_chnl_t *chnl) __attribute__((hot));
bool_t pfe_hif_chnl_is_tx_dma_active(const pfe_hif_chnl_t *chnl) __attribute__((hot));
uint32_t pfe_hif_chnl_get_id(const pfe_hif_chnl_t *chnl) __attribute__((pure, cold));
void pfe_hif_chnl_dump_ring(const pfe_hif_chnl_t *chnl, bool_t dump_rx, bool_t dump_tx) __attribute__((cold));
#if !defined(PFE_CFG_DETACHED_MINIHIF)
uint32_t pfe_hif_chnl_get_text_statistics(const pfe_hif_chnl_t *chnl, char_t *buf, uint32_t buf_len, uint8_t verb_level) __attribute__((cold));
uint32_t pfe_hif_chnl_get_tx_cnt(const pfe_hif_chnl_t *chnl);
uint32_t pfe_hif_chnl_get_rx_cnt(const pfe_hif_chnl_t *chnl);
#endif
#if defined(PFE_CFG_HIF_NOCPY_SUPPORT)
void *pfe_hif_chnl_bmu_alloc_buf_va(pfe_hif_chnl_t *chnl) __attribute__((hot));
void *pfe_hif_chnl_bmu_get_buf_pa(const pfe_hif_chnl_t *chnl, addr_t va) __attribute__((hot));
void pfe_hif_chnl_bmu_free_buf(pfe_hif_chnl_t *chnl, addr_t va) __attribute__((hot));
#endif /* PFE_CFG_HIF_NOCPY_SUPPORT */
void pfe_hif_chnl_set_lmem_hdr_size(pfe_hif_chnl_t *chnl, uint16_t lmem_header_size);
uint16_t pfe_hif_chnl_get_lmem_hdr_size(const pfe_hif_chnl_t *chnl);
errno_t pfe_hif_chnl_set_emac_timer_ownership(addr_t cbus_base_va, pfe_ct_phy_if_id_t hif_id, pfe_ct_phy_if_id_t emac, bool_t value);
bool_t pfe_hif_chnl_get_emac_timer_ownership(addr_t cbus_base_va, pfe_ct_phy_if_id_t hif_id, pfe_ct_phy_if_id_t emac);
bool_t pfe_hif_chnl_is_hw_reset_state(pfe_hif_chnl_t *chnl);

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

#endif /* PUBLIC_PFE_HIF_CHNL_H_ */
