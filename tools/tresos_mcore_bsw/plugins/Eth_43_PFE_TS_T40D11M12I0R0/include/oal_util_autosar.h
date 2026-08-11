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
 *  Copyright 2021-2023 NXP
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
 * @defgroup    dxgr_OAL_UTIL_AUTOSAR UTIL
 * @brief       Advanced utilities, autosar specific file
 * @details     TODO
 *
 *
 * @addtogroup  dxgr_OAL_UTIL_AUTOSAR
 * @{
 *
 * @file        oal_util_autosar.h
 * @brief       The oal_util_autosar module header file.
 * @details     This file contains utility management-related API.
 *
 */

#ifndef OAL_UTIL_AUTOSAR_H_
#define OAL_UTIL_AUTOSAR_H_

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

#include "autolibc.h"
#include "nxp_snprintf.h"
#include <stdarg.h>
#include "pfe_hm.h"

#if defined(GCC)
    #undef offsetof
    #define offsetof(structure, curItem) ((size_t)((addr_t)(&(((structure *)NULL)->curItem))))
#endif /* GCC */

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

void oal_util_raise_dem_for_drv_runtime_err(void);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/* Debug message support */
#ifdef NXP_LOG_ENABLED
    #define __STR_HELPER(x) #x
    #define __STR(x) __STR_HELPER(x)

    #define NXP_LOG_ASR_CFG_LINE_SIZE   256U /* Better be power of 2 */
    #define NXP_LOG_ASR_CFG_LINE_COUNT  256U /* Must be power of 2 */
    #define NXP_LOG_ASR_MASK            (NXP_LOG_ASR_CFG_LINE_COUNT-1U) /* Don't change */

    #define ETH_43_PFE_START_SEC_VAR_CLEARED_8
    #include "Eth_43_PFE_MemMap.h"

    /* Define the variables in the application */
    extern char_t debug_buff[NXP_LOG_ASR_CFG_LINE_COUNT][NXP_LOG_ASR_CFG_LINE_SIZE]; /* Dump to read the messages */

    #define ETH_43_PFE_STOP_SEC_VAR_CLEARED_8
    #include "Eth_43_PFE_MemMap.h"

    #define ETH_43_PFE_START_SEC_VAR_CLEARED_32
    #include "Eth_43_PFE_MemMap.h"

    extern uint32_t debug_line;

    #define ETH_43_PFE_STOP_SEC_VAR_CLEARED_32
    #include "Eth_43_PFE_MemMap.h"

    #define NXP_LOG_HM(...)         do{ uint32_t my_line = debug_line++; int num_ = \
                                        snprintf( debug_buff[my_line&NXP_LOG_ASR_MASK], \
                                                   NXP_LOG_ASR_CFG_LINE_SIZE, \
                                                   __VA_ARGS__ \
                                                ); \
                                        autolibc_memset( debug_buff[my_line&NXP_LOG_ASR_MASK]+num_, \
                                                          0x20, (uint32_t)NXP_LOG_ASR_CFG_LINE_SIZE-(uint32_t)num_ \
                                                        ); \
                                    }while(0)
    #define NXP_LOG_WARNING(...)    do{ uint32_t my_line = debug_line++; int num_ = \
                                        snprintf( debug_buff[my_line&NXP_LOG_ASR_MASK], \
                                                  NXP_LOG_ASR_CFG_LINE_SIZE, \
                                                  "WRN["__FILE__":"__STR(__LINE__)"] : " \
                                                  __VA_ARGS__ \
                                                ); \
                                        autolibc_memset( debug_buff[my_line&NXP_LOG_ASR_MASK]+num_, \
                                                         0x20, (uint32_t)NXP_LOG_ASR_CFG_LINE_SIZE-(uint32_t)num_ \
                                                       ); \
                                    }while(0)
    #define NXP_LOG_RAW_ERROR(...)  do{ uint32_t my_line = debug_line++; int num_ = \
                                        snprintf( debug_buff[my_line&NXP_LOG_ASR_MASK], \
                                                  NXP_LOG_ASR_CFG_LINE_SIZE, \
                                                  "ERR["__FILE__":"__STR(__LINE__)"] : " \
                                                  __VA_ARGS__ \
                                                ); \
                                        autolibc_memset( debug_buff[my_line&NXP_LOG_ASR_MASK]+num_, \
                                                         0x20, (uint32_t)NXP_LOG_ASR_CFG_LINE_SIZE-(uint32_t)num_ \
                                                       ); \
                                    }while(0)
    #define NXP_LOG_INFO(...)       do{ uint32_t my_line = debug_line++; int num_ = \
                                        snprintf( debug_buff[my_line&NXP_LOG_ASR_MASK], \
                                                  NXP_LOG_ASR_CFG_LINE_SIZE, \
                                                  "INF["__FILE__":"__STR(__LINE__)"] : " \
                                                  __VA_ARGS__ \
                                                ); \
                                        autolibc_memset( debug_buff[my_line&NXP_LOG_ASR_MASK]+num_, \
                                                         0x20, (uint32_t)NXP_LOG_ASR_CFG_LINE_SIZE-(uint32_t)num_ \
                                                       ); \
                                    }while(0)
    #define NXP_LOG_DEBUG(...)      do{ uint32_t my_line = debug_line++; int num_ = \
                                        snprintf( debug_buff[my_line&NXP_LOG_ASR_MASK], \
                                                  NXP_LOG_ASR_CFG_LINE_SIZE, \
                                                  "DBG["__FILE__":"__STR(__LINE__)"] : " \
                                                  __VA_ARGS__ \
                                                ); \
                                        autolibc_memset( debug_buff[my_line&NXP_LOG_ASR_MASK]+num_, \
                                                         0x20, (uint32_t)NXP_LOG_ASR_CFG_LINE_SIZE-(uint32_t)num_ \
                                                       ); \
                                    }while(0)
#else /* not NXP_LOG_ENABLED */
    #define NXP_LOG_WARNING(...)
    #define NXP_LOG_RAW_ERROR(...)
    #define NXP_LOG_INFO(...)
    #define NXP_LOG_DEBUG(...)
#endif /* NXP_LOG_ENABLED */

/* NXP_LOG_ERROR is used to log the driver runtime error to Health Monitor and raise the event to Dem */
#define NXP_LOG_ERROR(...)          do{ pfe_hm_report_error(HM_SRC_DRIVER, HM_EVT_RUNTIME, __VA_ARGS__); \
                                        oal_util_raise_dem_for_drv_runtime_err(); \
                                    }while(0)

#endif /* OAL_UTIL_AUTOSAR_H_ */

/** @}*/
/** @}*/
