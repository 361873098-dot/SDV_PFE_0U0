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

#ifndef PFE_HIF_NOCPY_CSR_H_
#define PFE_HIF_NOCPY_CSR_H_

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43140440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43140440
#endif

#include "pfe_hif_nocpy.h"

#ifndef PFE_CBUS_H_
#error Missing cbus.h
#endif /* PFE_CBUS_H_ */

#define HIF_NOCPY_VERSION           (0x00U)
#define HIF_NOCPY_TX_CTRL           (0x04U)
#define HIF_NOCPY_TX_CURR_BD_ADDR   (0x08U)
#define HIF_NOCPY_TX_ALLOC          (0x0cU)
#define HIF_NOCPY_TX_BDP_ADDR       (0x10U)
#define HIF_NOCPY_TX_STATUS         (0x14U)
#define HIF_NOCPY_RX_CTRL           (0x20U)
#define HIF_NOCPY_RX_BDP_ADDR       (0x24U)
#define HIF_NOCPY_RX_STATUS         (0x30U)
#define HIF_NOCPY_INT_SRC           (0x34U)
#define HIF_NOCPY_INT_EN            (0x38U)
#define HIF_NOCPY_POLL_CTRL         (0x3cU)
#define HIF_NOCPY_RX_CURR_BD_ADDR   (0x40U)
#define HIF_NOCPY_RX_ALLOC          (0x44U)
#define HIF_NOCPY_TX_DMA_STATUS     (0x48U)
#define HIF_NOCPY_RX_DMA_STATUS     (0x4cU)
#define HIF_NOCPY_RX_INQ0_PKTPTR    (0x50U)
#define HIF_NOCPY_RX_INQ1_PKTPTR    (0x54U)
#define HIF_NOCPY_TX_PORT_NO        (0x60U)
#define HIF_NOCPY_LMEM_ALLOC_ADDR   (0x64U)
#define HIF_NOCPY_CLASS_ADDR        (0x68U)
#define HIF_NOCPY_TMU_PORT0_ADDR    (0x70U)
#define HIF_NOCPY_TMU_PORT1_ADDR    (0x74U)
#define HIF_NOCPY_TMU_PORT2_ADDR    (0x7cU)
#define HIF_NOCPY_TMU_PORT3_ADDR    (0x80U)
#define HIF_NOCPY_TMU_PORT4_ADDR    (0x84U)
#define HIF_NOCPY_INT_COAL_ADDR     (0x90U)
#define HIF_NOCPY_CSR_AXI_WAIT_DONE (0x94U)
#define HIF_NOCPY_ABS_FRAME_CNT     (0x98U)

#define HIF_NOCPY_INT               (1U << 0)
#define BDP_CSR_RX_CBD_INT          (1U << 1)
#define BDP_CSR_RX_PKT_INT          (1U << 2)
#define BDP_CSR_TX_CBD_INT          (1U << 3)
#define BDP_CSR_TX_PKT_INT          (1U << 4)

#define HIF_NOCPY_TIMER_OWNERSHIP_EMAC(ID)     (1U << ((ID)+4U))

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

errno_t pfe_hif_nocpy_cfg_isr(addr_t base_va, pfe_hif_chnl_event_t *events);
void pfe_hif_nocpy_cfg_irq_mask(addr_t base_va);
void pfe_hif_nocpy_cfg_irq_unmask(addr_t base_va);
errno_t pfe_hif_nocpy_cfg_init(addr_t base_va);
void pfe_hif_nocpy_cfg_fini(addr_t base_va);
void pfe_hif_nocpy_cfg_tx_enable(addr_t base_va);
void pfe_hif_nocpy_cfg_tx_disable(addr_t base_va);
void pfe_hif_nocpy_cfg_rx_enable(addr_t base_va);
void pfe_hif_nocpy_cfg_rx_disable(addr_t base_va);
void pfe_hif_nocpy_cfg_rx_dma_start(addr_t base_va);
void pfe_hif_nocpy_cfg_tx_dma_start(addr_t base_va);
void pfe_hif_nocpy_cfg_rx_irq_mask(addr_t base_va);
void pfe_hif_nocpy_cfg_rx_irq_unmask(addr_t base_va);
void pfe_hif_nocpy_cfg_tx_irq_mask(addr_t base_va);
void pfe_hif_nocpy_cfg_tx_irq_unmask(addr_t base_va);
void pfe_hif_nocpy_cfg_set_rx_bd_ring_addr(addr_t base_va, const void *rx_ring_pa);
void pfe_hif_nocpy_cfg_set_tx_bd_ring_addr(addr_t base_va, const  void *tx_ring_pa);
uint32_t pfe_hif_nocpy_cfg_get_rx_bd_ring_addr(addr_t base_va);
uint32_t pfe_hif_nocpy_cfg_get_tx_bd_ring_addr(addr_t base_va);
bool_t pfe_hif_nocpy_cfg_is_rx_dma_active(addr_t base_va);
bool_t pfe_hif_nocpy_cfg_is_tx_dma_active(addr_t base_va);
uint32_t pfe_hif_nocpy_chnl_cfg_get_text_stat(addr_t base_va, const char_t *buf, uint32_t size, uint8_t verb_level);

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_hif_nocpy_cfg_get_text_stat(addr_t base_va, char_t *buf, uint32_t size, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

uint32_t pfe_hif_nocpy_cfg_get_tx_cnt(addr_t base_va);
uint32_t pfe_hif_nocpy_cfg_get_rx_cnt(addr_t base_va);
errno_t pfe_hif_nocpy_cfg_set_emac_timer_ownership(pfe_ct_phy_if_id_t emac, bool_t value);
bool_t pfe_hif_nocpy_cfg_get_emac_timer_ownership(pfe_ct_phy_if_id_t emac);
void pfe_hif_nocpy_cfg_stop_all_chnl_dma(void);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_HIF_NOCPY_CSR_H_ */
