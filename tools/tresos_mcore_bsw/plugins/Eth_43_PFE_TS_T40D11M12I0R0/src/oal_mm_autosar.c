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
 * @addtogroup  dxgr_OAL_MM
 * @{
 *
 * @file        oal_mm_autosar.c
 * @brief       The oal_mm module source file (AUTOSAR).
 * @details     This file contains AUTOSAR-specific memory management implementation.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"
#include "oal_mm.h"
#include "hal.h"
#include "pfe_platform_cfg.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 *  Try to find physical address associated with mapped virtual range
 */
void *oal_mm_virt_to_phys_contig(void *vaddr)
{
    /* 1:1 mapping */
    return vaddr;
}

/**
 *  Try to find physical address associated with mapped virtual range
 */
void *oal_mm_virt_to_phys(void *vaddr)
{/* Mapped 1:1 */
    return vaddr;
}

/**
 * Get virtual address based on physical address. Function assumes that region containing the 'paddr'
 * is already mapped within current process' address space.
 */
void *oal_mm_phys_to_virt(void *paddr)
{/* Mapped 1:1 */
    return paddr;
}

void *oal_mm_dev_map(void *paddr, const addr_t len)
{/* Mapped 1:1 */
    (void)len;
    return paddr;
}

void *oal_mm_dev_map_cache(void *paddr, const addr_t len)
{/* Mapped 1:1 */
    (void)len;
    return paddr;
}

errno_t oal_mm_dev_unmap(void *paddr, const addr_t len)
{
    (void)paddr;
    (void)len;
    return EOK;
}

void oal_mm_cache_inval(const void *vaddr, const void *paddr, const addr_t len)
{
    (void)vaddr;
    (void)paddr;
    (void)len;
}

void oal_mm_cache_flush(const void *vaddr, const void *paddr, const addr_t len)
{
    (void)vaddr;
    (void)paddr;
    (void)len;
}

uint32_t oal_mm_cache_get_line_size(void)
{
    return HAL_CACHE_LINE_SIZE;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/** @}*/
