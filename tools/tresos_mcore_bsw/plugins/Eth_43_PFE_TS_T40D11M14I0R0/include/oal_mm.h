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
 * @addtogroup  dxgrOAL
 * @{
 *
 * @defgroup    dxgr_OAL_MM MM
 * @brief       Memory management abstraction
 * @details
 *              Purpose
 *              -------
 *              Purpose of the oal_mm is to abstract some memory management tasks like:
 *
 *              - Memory allocation (physically contiguous, aligned, cached)
 *              - Virtual to physical and vice versa address conversion
 *              - Cache maintenance
 *
 *              Initialization
 *              --------------
 *              The oal_mm needs to be initialized by the oal_mm_init().
 *
 *              Operation
 *              ---------
 *              The provided API can be used to manage memory as defined by API.
 *
 *              Shutdown
 *              --------
 *              Library should be properly terminated when no more needed via the
 *              oal_mm_shutdown() call.
 *
 *
 * @addtogroup  dxgr_OAL_MM
 * @{
 *
 * @file        oal_mm.h
 * @brief       The oal_mm module header file.
 * @details     This file contains generic memory management-related API.
 *
 */

#ifndef PUBLIC_OAL_MM_H_
#define PUBLIC_OAL_MM_H_

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

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

/**
 * @brief       Convert virtual address to physical
 * @details     Only applicable to memory allocated by oal_mm_alloc_config_xxx variants
 * @param[in]   vaddr The virtual address to be converted
 * @return      Physical address associated with the virtual one or NULL if failed
 */
void *oal_mm_virt_to_phys_contig(void *vaddr);

/**
 * @brief       Convert virtual address to physical
 * @details     Only applicable to memory managed by oal_mm module.
 * @param[in]   vaddr The virtual address to be converted
 * @return      Physical address associated with the virtual one or NULL if failed
 */
void *oal_mm_virt_to_phys(void *vaddr);

/**
 * @brief       Convert physical address to virtual
 * @details     Only applicable to memory managed by oal_mm module.
 * @param[in]   paddr The physical address to be converted
 * @return      Virtual address associated with the physical one or NULL if failed
 */
void *oal_mm_phys_to_virt(void *paddr);

/**
 * @brief       Map a physical memory region into a process's address space
 * @details     Enable access to the device's registers
 * @param[in]   paddr The physical address to be mapped
 * @param[in]   len Memory region length
 * @return      Virtual address associated with the physical one or NULL if failed
 */
void *oal_mm_dev_map(void *paddr, const addr_t len);

/**
 * @brief       Map a physical memory region into a process's address space
 * @details     Enable access to the device's registers, cachable variant
 * @param[in]   paddr The physical address to be mapped
 * @param[in]   len Memory region length
 * @return      Virtual address associated with the physical one or NULL if failed
 */
void *oal_mm_dev_map_cache(void *paddr, const addr_t len);

/**
 * @brief       Unmap previously mapped physical memory region
 * @details     Removes any mappings
 * @param[in]   paddr The physical address to be unmapped
 * @param[in]   len Memory region length
 * @return      EOK if success
 */
errno_t oal_mm_dev_unmap(void *paddr, const addr_t len);

/**
 * @brief       Invalidate cache
 * @param[in]   vaddr Memory region start (virtual)
 * @param[in]   paddr Memory region start (physical)
 * @param[in]   len Memory region length
 */
void oal_mm_cache_inval(const void *vaddr, const void *paddr, const addr_t len);

/**
 * @brief       Flush cache
 * @param[in]   vaddr Memory region start (virtual)
 * @param[in]   paddr Memory region start (physical)
 * @param[in]   len Memory region length
 */
void oal_mm_cache_flush(const void *vaddr, const void *paddr, const addr_t len);

/**
 * @brief       Get cache line size in bytes
 * @return      Cache line size in bytes
 */
uint32_t oal_mm_cache_get_line_size(void);

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

#endif /* PUBLIC_OAL_MM_H_ */

/** @}*/
