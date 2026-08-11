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
 * @addtogroup  dxgr_OAL_UTIL_NET_AUTOSAR
 * @{
 *
 * @file        oal_util_net_autosar.c
 * @brief       The oal_util_net_autosar module source file.
 * @details     This file contains network utility implementation for AUTOSAR.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "oal_types.h"
#include "oal_util.h"
#include "oal_util_net.h"

#if (PFE_CFG_VERBOSITY_LEVEL >= 8)
#ifdef NXP_LOG_ENABLED

struct in6_addr {
    union {
        uint8       u6_addr8[16];
        uint16      u6_addr16[8];
        uint32      u6_addr32[4];
    } in6_u;
#define s6_addr         in6_u.u6_addr8
#define s6_addr16       in6_u.u6_addr16
#define s6_addr32       in6_u.u6_addr32
};

#define NIP4(addr) \
        ((const uint8_t *)addr)[0], \
        ((const uint8_t *)addr)[1], \
        ((const uint8_t *)addr)[2], \
        ((const uint8_t *)addr)[3]

#define NIP6(addr) \
        oal_ntohs(((const struct in6_addr *)addr)->s6_addr16[0]), \
        oal_ntohs(((const struct in6_addr *)addr)->s6_addr16[1]), \
        oal_ntohs(((const struct in6_addr *)addr)->s6_addr16[2]), \
        oal_ntohs(((const struct in6_addr *)addr)->s6_addr16[3]), \
        oal_ntohs(((const struct in6_addr *)addr)->s6_addr16[4]), \
        oal_ntohs(((const struct in6_addr *)addr)->s6_addr16[5]), \
        oal_ntohs(((const struct in6_addr *)addr)->s6_addr16[6]), \
        oal_ntohs(((const struct in6_addr *)addr)->s6_addr16[7])

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

char_t *oal_util_net_inet_ntop(int32_t af, const void *src, char_t *dst, uint32_t size)
{
    int32_t ret;

    switch(af) {
        case AF_INET:
            ret = nxp_snprintf(dst, size, "%d.%d.%d.%d", NIP4(src));
            break;
        case AF_INET6:
            ret = nxp_snprintf(dst, size, "%d.%d.%d.%d.%d.%d.%d.%d", NIP6(src));
            break;
        default:
            ret = -EAFNOSUPPORT;
            break;
    }

    return (ret > 0) ? dst : NULL;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* NXP_LOG_ENABLED */
#endif /* PFE_CFG_VERBOSITY_LEVEL */


/** @}*/

