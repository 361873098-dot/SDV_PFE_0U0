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
 * @defgroup    dxgrHAL HAL
 * @brief       The HW Abstraction Layer
 * @details
 *
 *
 * @addtogroup  dxgrHAL
 * @{
 *
 * @file        hal.h
 * @brief       The main HAL header file
 * @details     Use this header to include all the HAL-provided functionality
 *
 */

#ifndef HAL_H_
#define HAL_H_

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

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT
/* requires only for hal_ip_ready API */
#include "oal_types.h"
#include "oal_mm.h"
#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#if defined(GHS)
    #define hal_nop()       __asm(" nop")
#else /* GCC and DIAB */
    #define hal_nop()       __asm__ volatile("nop" ::: "memory")
#endif

/*  AXI writes immediately followed by an AXI read, cause writes to be lost,
    as a workaround, add a hal_nop after each write */
#define hal_write32(val, addr) \
                            do {    \
                                (*(volatile uint32_t *)(addr) = ((uint32_t)(val))); \
                            } while (0!=0)

#define hal_write16(val, addr) \
                            do {    \
                                    (*(volatile uint16_t *)(addr) = ((uint16_t)(val))); \
                            } while (0!=0)

#define hal_write8(val, addr) \
                            do {    \
                                    (*(volatile uint8_t *)(addr) = ((uint8_t)(val)));   \
                            } while (0!=0)

#define hal_read32(addr)    (*(volatile uint32_t *)(addr))
#define hal_read16(addr)    (*(volatile uint16_t *)(addr))
#define hal_read8(addr)     (*(volatile uint8_t *)(addr))

#define ADDR_BASE_OFFSET(BASE,OFFS) (addr_t)(((uint64_t)(BASE)+(OFFS)) & UINT32_MAX)
#define OFFSET_ADDR_BASE(ADDR,BASE) (uint32_t)(((uint64_t)(ADDR)+UINT32_MAX+1U-(BASE)) & UINT32_MAX)

#ifndef likely
    #if defined(__ghs__) || defined(__DCC__)
        #define likely(x)   (x)
    #else
        #define likely(x)   __builtin_expect(!!(x),1)
    #endif

#endif

#ifndef unlikely
    #if defined(__ghs__) || defined(__DCC__)
        #define unlikely(x) (x)
    #else
        #define unlikely(x) __builtin_expect(!!(x),0)
    #endif
#endif

#if defined(__ghs__) || defined(__DCC__)
    #if defined(PFE_CFG_TARGET_ARCH_aarch64le) || defined(PFE_CFG_TARGET_ARCH_armv7le)
        #define hal_wmb()   __asm(" dmb oshst")
    #else
        #error Unsupported or no platform defined
    #endif
#else
    #if defined(PFE_CFG_TARGET_ARCH_aarch64le)
        #define hal_wmb()   __asm__ __volatile__(" dmb oshst" : : : "memory")
    #elif defined(PFE_CFG_TARGET_ARCH_x86) || defined(PFE_CFG_TARGET_ARCH_x86_64)
        #define hal_wmb()   asm volatile("sfence" ::: "memory")
    #elif defined(PFE_CFG_TARGET_ARCH_aarch64)
        #define hal_wmb()           smp_wmb()
    #elif defined(PFE_CFG_TARGET_ARCH_armv7le)
        #define hal_wmb()   __asm__ __volatile__(" dmb":::"memory")
    #else
        #error Unsupported or no platform defined
    #endif
#endif

/**
 * @brief   If TRUE then platform performs explicit cache maintenance (flush/invalidate)
 */
#define HAL_HANDLE_CACHE    FALSE

/**
 * @brief   Specify cache line size in number of bytes.
 */
#define HAL_CACHE_LINE_SIZE 64U

#ifdef PFE_CFG_MULTI_INSTANCE_SUPPORT

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

/**
 * @brief Control register
 * @note The register which is used for Master-detect signalization
 * @warning We hijacked GPR:GENCTRL3 register, using 16 higher bits,
 *          low 16 bits remains untouched for security reason
 */
#define PFE_IP_READY_CTRL_REG   (0x4007CAECU)
#define CTRL_REG_LEN            4U

#define BIT_IP_READY            16U
#define IP_READY                ((uint32_t)1U << BIT_IP_READY)

/**
 * @brief Set IP-ready flag
 */
__attribute__((unused)) static void hal_ip_ready_set(bool_t on)
{
    uint32_t *ctrlreg = (uint32_t *)oal_mm_dev_map((void *)PFE_IP_READY_CTRL_REG, CTRL_REG_LEN);
    uint32_t val;

    if (NULL != ctrlreg)
    {
        val = hal_read32(ctrlreg);
        if (TRUE == on)
        {
            val |= IP_READY;
        }
        else
        {
            val &= ~IP_READY;
        }
        hal_write32(val, ctrlreg);

        (void)oal_mm_dev_unmap(ctrlreg, CTRL_REG_LEN);
    }
}

/**
 * @brief Return status of IP-ready flag
 * @return True if IP-ready
 */
__attribute__((unused)) static bool_t hal_ip_ready_get(void)
{
    uint32_t *ctrlreg = (uint32_t *)oal_mm_dev_map((void *)PFE_IP_READY_CTRL_REG, CTRL_REG_LEN);
    uint32_t val = 0U;

    if (NULL != ctrlreg)
    {
        val = hal_read32(ctrlreg);
        val &= IP_READY;

        (void)oal_mm_dev_unmap(ctrlreg, CTRL_REG_LEN);
    }

    return (0U != val);
}

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

#endif /* PFE_CFG_MULTI_INSTANCE_SUPPORT */

#endif /* HAL_H_ */

/** @}*/
