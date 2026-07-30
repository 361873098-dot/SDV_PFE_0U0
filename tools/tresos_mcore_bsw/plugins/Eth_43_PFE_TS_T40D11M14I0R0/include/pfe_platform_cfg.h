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
 *  Copyright 2018-2024 NXP
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
 * @addtogroup  dxgrPFE_PLATFORM
 * @{
 *
 * @file        pfe_platform_cfg.h
 * @brief       The PFE platform configuration file
 * @details     This file contains HW platform-specific configuration options which are usually
 *              bounded to a given hardware implementation.
 * @note        Various variants of this file should exist for various HW platforms (please
 *              keep this file clean, not containing platform-specific preprocessor switches).
 *
 */

#ifndef SRC_PFE_PLATFORM_CFG_H_
#define SRC_PFE_PLATFORM_CFG_H_

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

#include "pfe_cfg.h"
#include "Eth_43_PFE.h"

#define TMU_TYPE_TMU        1U
#define TMU_TYPE_TMU_LITE   2U

/**
 * @brief   Hash value for FW API compatibility check
 */
#define PFE_CFG_PFE_CT_H_MD5        92367c0e25f21f49217a9b08168ad2c8

/**
 * @brief   Number of entries of HIF Rx ring
 * @note    Must be power of 2
 */
#define PFE_HIF_RX_RING_CFG_LENGTH ETH_43_PFE_CFG_HIF_RXBD_NUM

/**
 * @brief   Number of entries of HIF Tx ring
 * @note    Must be power of 2
 */
#define PFE_HIF_TX_RING_CFG_LENGTH ETH_43_PFE_CFG_HIF_TXBD_NUM

/*
 * @brief TMU variant
 */
#define PFE_CFG_TMU_VARIANT TMU_TYPE_TMU_LITE

/*
 * @brief   Accessible memory space base (PA)
 * @details This is PFE-accessible address space base (npu2ddr+upe2hdbus AXI masters)
 * @warning Address range given by this base and PFE_CFG_DDR_MASTER_LEN must be
 *          reserved to be exclusively accessible by PFE.
 */
#define PFE_CFG_DDR_MASTER_ADDR             0x00400000ULL   /* S32G */

/*
 * @brief   Length of the PFE DDR memory
 */
#define PFE_CFG_DDR_MASTER_LEN              0x01000000ULL   /* S32G: 16MB */

/*
 * @brief   The PFE HIF IRQ ID as seen by the host
 */
#define PFE_CFG_HIF_IRQ_ID                  204 /* HIF (copy) IRQ */

/*
 * @brief   Maximum supported number of standard HIF channels
 */
#define HIF_CFG_MAX_CHANNELS                4U


/**
 * @brief   The CLASS_PE_SYS_CLK_RATIO[csr_clmode]
 * @details See the IMG-NPU Technical Reference Manual
 */
#define PFE_CFG_CLMODE                      1U  /* SYS/AXI = 250MHz, HFE = 500MHz */

/**
 * @brief   Maximum number of buffers - BMU1
 */
#define PFE_CFG_BMU1_BUF_COUNT              0x200U

/**
 * @brief   BMU1 buffer size in Bytes
 */
#define PFE_CFG_BMU1_BUF_SIZE               256U    /* 256 bytes */

#if (STD_OFF == ETH_43_PFE_SLAVE_MODE)
    /* Not used in slave driver */
    /**
     * @brief   Maximum number of logical interfaces
     * @details This is the maximum number supported by driver. Real
     *          number is limited by amount of available DMEM.
     */
    #define PFE_CFG_MAX_LOG_IFS                 256U
    /**
     * @brief   Maximum number of buffers - BMU2
     * @details Used for Rx buffers for HIF rings (shared among all clients).
     *          Used internally to pass packets among EMACs and HIFs
     */
    #define PFE_CFG_BMU2_BUF_COUNT      ETH_43_PFE_BMU2_BUF_CNT
    /**
     * @brief   BMU2 buffer size
     * @details Value = log2(size).
     *          Used internally to pass packets among EMACs and HIFs
     */
    #define PFE_CFG_BMU2_BUF_SIZE           2048U
#endif /* ETH_43_PFE_SLAVE_MODE */

/**
 * @brief   DMEM base address as defined by .elf
 */
#define PFE_CFG_CLASS_ELF_DMEM_BASE         0x20000000UL

/**
 * @brief   Size of DMEM per CLASS PE
 */
#define PFE_CFG_CLASS_DMEM_SIZE             0x00004000UL    /* 16k */

/**
 * @brief   IMEM base address as defined by .elf
 */
#define PFE_CFG_CLASS_ELF_IMEM_BASE         0x9fc00000UL

/**
 * @brief   Size of IMEM per CLASS PE
 */
#define PFE_CFG_CLASS_IMEM_SIZE             0x00008000UL    /* 32kB */

/**
 * @brief   DMEM base address as defined by .elf
 */
#define PFE_CFG_TMU_ELF_DMEM_BASE           0x00000000UL

/**
 * @brief   Size of DMEM per TMU PE
 */
#define PFE_CFG_TMU_DMEM_SIZE               0x00000800UL    /* 2kB */

/**
 * @brief   IMEM base address as defined by .elf
 */
#define PFE_CFG_TMU_ELF_IMEM_BASE           0x00010000UL

/**
 * @brief   Size of IMEM per TMU PE
 */
#define PFE_CFG_TMU_IMEM_SIZE               0x00002000UL    /* 8kB */

/**
 * @brief   DMEM base address as defined by .elf
 */
#define PFE_CFG_UTIL_ELF_DMEM_BASE          0x00000000UL

/**
 * @brief   Size of DMEM per UTIL PE
 */
#define PFE_CFG_UTIL_DMEM_SIZE              0x00002000UL

/**
 * @brief   IMEM base address as defined by .elf
 */
#define PFE_CFG_UTIL_ELF_IMEM_BASE          PFE_CFG_CLASS_ELF_IMEM_BASE

/**
 * @brief   Size of IMEM per UTIL PE
 */
#define PFE_CFG_UTIL_IMEM_SIZE              PFE_CFG_CLASS_IMEM_SIZE

/**
 * @brief   Physical CBUS base address as seen by PFE
 */
#define PFE_CFG_CBUS_PHYS_BASE_ADDR         0xc0000000U

/**
 * @brief   Physical CBUS base address as seen by CPUs
 */
#define PFE_CFG_CBUS_PHYS_BASE_ADDR_CPU     0x46000000U

/**
 * @brief   CBUS length
 */
#define PFE_CFG_CBUS_LENGTH                 0x01000000U

/**
 * @brief   Offset in LMEM where BMU1 buffers area starts
 */
#define PFE_CFG_BMU1_LMEM_BASEADDR          0U

/**
 * @brief   Size of BMU1 buffers area in number of bytes
 */
#define PFE_CFG_BMU1_LMEM_SIZE              (PFE_CFG_BMU1_BUF_SIZE * PFE_CFG_BMU1_BUF_COUNT)

/**
 * @brief   Offset in LMEM, where PE memory area starts
 */
#define PFE_CFG_PE_LMEM_BASE                (PFE_CFG_BMU1_LMEM_BASEADDR + PFE_CFG_BMU1_LMEM_SIZE)

/**
 * @brief   Size of PE memory area in number of bytes
 */
#define PFE_CFG_PE_LMEM_SIZE                (CBUS_LMEM_SIZE - PFE_CFG_BMU1_LMEM_SIZE)

/**
 * @brief   Translates from host CPU physical address space to PFE address space
 */
#define PFE_CFG_MEMORY_PHYS_TO_PFE(p)       (p)

/**
 * @brief   Translates from PFE address space to host CPU physical address space
 */
#define PFE_CFG_MEMORY_PFE_TO_PHYS(p)       (p)

/* LMEM defines */
#define PFE_CFG_LMEM_BUF_SIZE_LN2           0x8U /*256*/
#define PFE_CFG_LMEM_BUF_SIZE               (1UL << PFE_CFG_LMEM_BUF_SIZE_LN2)

/* DDR defines */
#define PFE_CFG_DDR_HDR_SIZE                0x0200UL
#define PFE_CFG_DDR_BUF_SIZE_LN2            0xbU /*2048*/
#define PFE_CFG_DDR_BUF_SIZE                (1UL << PFE_CFG_DDR_BUF_SIZE_LN2)

/* RO defines */
#define PFE_CFG_RO_HDR_SIZE                 0x0010UL

/* Maximal count of entries within hash area of routing table */
#define PFE_CFG_RT_HASH_ENTRIES_MAX_CNT 1048576U

/**
 * @brief   Local physical interface identifier
 * @details In multi-instance environment, where multiple platform drivers
 *          can be deployed, this identifier represents the physical interface
 *          (usually HIF channel) associated with the current driver instance.
 */
#if (TRUE == ETH_43_PFE_USE_MULTIPLE_HIFS)
    #define PFE_CFG_LOCAL_IF                ETH_43_PFE_CFG_CTRLHIF(0U)/* Use any of own HIFs */
#else
    #define PFE_CFG_LOCAL_IF                ETH_43_PFE_COMMON_HIF
#endif

#if (TRUE == ETH_43_PFE_USE_MULTIPLE_HIFS)
/*  Needed by ETH_43_PFE_CFG_CTRLHIF(0U), which is LT/PB configurable.
    Must be here (end of file) to avoid a cyclic include dependency. */
    #include "Eth_PFE_LLD.h"
#endif

/* max PEs count in CLASSIFIER */
#define PFE_CLASS_PE_COUNT 8U

#endif /* SRC_PFE_PLATFORM_CFG_H_ */

/** @}*/
