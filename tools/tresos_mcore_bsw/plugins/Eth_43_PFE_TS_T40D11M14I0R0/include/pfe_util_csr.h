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
 *  Copyright 2015-2016 Freescale Semiconductor, Inc.
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

#ifndef UTIL_CSR_H_
#define UTIL_CSR_H_

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


#define UTIL_VERSION                (CBUS_UTIL_CSR_BASE_ADDR + 0x000U)
#define UTIL_TX_CTRL                (CBUS_UTIL_CSR_BASE_ADDR + 0x004U)
#define UTIL_INQ_PKTPTR             (CBUS_UTIL_CSR_BASE_ADDR + 0x010U)

#define UTIL_HDR_SIZE               (CBUS_UTIL_CSR_BASE_ADDR + 0x014U)

#define UTIL_PE0_QB_DM_ADDR0        (CBUS_UTIL_CSR_BASE_ADDR + 0x020U)
#define UTIL_PE0_QB_DM_ADDR1        (CBUS_UTIL_CSR_BASE_ADDR + 0x024U)
#define UTIL_PE0_RO_DM_ADDR0        (CBUS_UTIL_CSR_BASE_ADDR + 0x060U)
#define UTIL_PE0_RO_DM_ADDR1        (CBUS_UTIL_CSR_BASE_ADDR + 0x064U)

#define UTIL_MEM_ACCESS_ADDR        (CBUS_UTIL_CSR_BASE_ADDR + 0x100U)
#define UTIL_MEM_ACCESS_WDATA       (CBUS_UTIL_CSR_BASE_ADDR + 0x104U)
#define UTIL_MEM_ACCESS_RDATA       (CBUS_UTIL_CSR_BASE_ADDR + 0x108U)

#define UTIL_TM_INQ_ADDR            (CBUS_UTIL_CSR_BASE_ADDR + 0x114U)
#define UTIL_PE_STATUS              (CBUS_UTIL_CSR_BASE_ADDR + 0x118U)

#define UTIL_PE_SYS_CLK_RATIO       (CBUS_UTIL_CSR_BASE_ADDR + 0x200U)
#define UTIL_AFULL_THRES            (CBUS_UTIL_CSR_BASE_ADDR + 0x204U)
#define UTIL_GAP_BETWEEN_READS      (CBUS_UTIL_CSR_BASE_ADDR + 0x208U)
#define UTIL_MAX_BUF_CNT            (CBUS_UTIL_CSR_BASE_ADDR + 0x20cU)
#define UTIL_TSQ_FIFO_THRES         (CBUS_UTIL_CSR_BASE_ADDR + 0x210U)
#define UTIL_TSQ_MAX_CNT            (CBUS_UTIL_CSR_BASE_ADDR + 0x214U)
#define UTIL_IRAM_DATA_0            (CBUS_UTIL_CSR_BASE_ADDR + 0x218U)
#define UTIL_IRAM_DATA_1            (CBUS_UTIL_CSR_BASE_ADDR + 0x21cU)
#define UTIL_IRAM_DATA_2            (CBUS_UTIL_CSR_BASE_ADDR + 0x220U)
#define UTIL_IRAM_DATA_3            (CBUS_UTIL_CSR_BASE_ADDR + 0x224U)

#define UTIL_BUS_ACCESS_ADDR        (CBUS_UTIL_CSR_BASE_ADDR + 0x228U)
#define UTIL_BUS_ACCESS_WDATA       (CBUS_UTIL_CSR_BASE_ADDR + 0x22cU)
#define UTIL_BUS_ACCESS_RDATA       (CBUS_UTIL_CSR_BASE_ADDR + 0x230U)

#define UTIL_INQ_AFULL_THRES        (CBUS_UTIL_CSR_BASE_ADDR + 0x234U)
#define UTIL_UPE_GP_REG_ADDR        (CBUS_UTIL_CSR_BASE_ADDR + 0x238U)
#define UTIL_HOST_GP_REG_ADDR       (CBUS_UTIL_CSR_BASE_ADDR + 0x23CU)
#define UTIL_MISC_REG_ADDR          (CBUS_UTIL_CSR_BASE_ADDR + 0x240U)

#define UTIL_PE_IBUS_ACCESS_PMEM    (1UL << 17U)
#define UTIL_PE_IBUS_ACCESS_DMEM    (1UL << 18U)
#define UTIL_PE_IBUS_DMEM_BASE(i)   ((((i) & 0x3) << 20U) | UTIL_PE_IBUS_ACCESS_DMEM)
#define UTIL_PE_IBUS_PMEM_BASE(i)   ((((i) & 0x3) << 20U) | UTIL_PE_IBUS_ACCESS_PMEM)

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_util_cfg_get_text_stat(addr_t base_va, char_t *buf, uint32_t size, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

errno_t pfe_util_cfg_isr(addr_t base_va);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* UTIL_CSR_H_ */
