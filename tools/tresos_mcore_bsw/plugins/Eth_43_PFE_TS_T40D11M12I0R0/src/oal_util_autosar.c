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
 * @addtogroup  dxgr_OAL_UTIL
 * @{
 *
 * @file        oal_util_autosar.c
 * @brief       The oal_util module source file.
 * @details     This file contains utility management implementation.
 *
 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include <stdarg.h>
#include "pfe_cfg.h"
#include "oal.h"
#include "autolibc.h"
#include "nxp_snprintf.h"
#include "oal_util.h"
#include "pfe_platform.h"
#include "Eth_43_PFE_Cfg.h"

#ifdef PFE_CFG_IEEE1588_SUPPORT
    #define L2_HDR_LEN          14U
    #define L2_HDR_VLAN_LEN     18U
    #define L3_HDR_IPv4_LEN     20U
    #define L3_HDR_IPv6_LEN     40U
    #define L4_HDR_UDP_LEN      8U

    #define IP_VERSION(base)  (((uint8_t *)(base))[0U] >> 4U)
    #define IPV4_IHL(base)      (((uint8_t *)(base))[0U] & 0xFU)
    #define IPV4_PROTOCOL(base) (((uint8_t *)(base))[9U])
    #define IPV4_DST_ADDR(base) (oal_ntohl(((uint32_t *)(base))[4U]))
    #define IPV4_SRC_ADDR(base) (oal_ntohl(((uint32_t *)(base))[3U]))
    #define IPV6_PROTOCOL(base) (((uint8_t *)(base))[6U])
    #define IPV6_DST_ADDR_PTR(base) ((uint8_t *)(base) + 24U)
    #define IPV6_SRC_ADDR_PTR(base) ((uint8_t *)(base) + 8U)
    #define UDP_SPORT(base) (oal_ntohs(((uint16_t *)(base))[0U]))
    #define UDP_DPORT(base) (oal_ntohs(((uint16_t *)(base))[1U]))

    #define ETHERTYPE_VLAN 0x8100U
    #define ETHERTYPE_PTP  0x88f7U
    #define ETHERTYPE_IPV4 0x0800U
    #define ETHERTYPE_IPV6 0x86ddU
    #define IPPROTOCOL_PTP 0x7bU
    #define IPPROTOCOL_UDP 0x11U

    #define ETH_43_PFE_START_SEC_CONST_8
    #include "Eth_43_PFE_MemMap.h"

    /* IPv6 */
    /* usage scope: oal_util_parse_ptp */
    static const uint8_t primary_mcast[] = {0xffU, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0x1U, 0x81U};
    static const uint8_t pdelay_mcast[] = {0xffU, 0x02U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0x6bU};

    #define ETH_43_PFE_STOP_SEC_CONST_8
    #include "Eth_43_PFE_MemMap.h"

    #define ETH_43_PFE_START_SEC_VAR_INIT_32
    #include "Eth_43_PFE_MemMap.h"

    /* usage scope: oal_util_get_unique_seqnum32*/
    static uint32_t base = 0U;

    #define ETH_43_PFE_STOP_SEC_VAR_INIT_32
    #include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_IEEE1588_SUPPORT */

#define ETH_43_PFE_START_SEC_VAR_INIT_32
#include "Eth_43_PFE_MemMap.h"

/* usage scope: oal_util_rand */
static uint32_t u32RandVal = 0x12345678U; /* Random value seed */

#define ETH_43_PFE_STOP_SEC_VAR_INIT_32
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#ifdef PFE_CFG_IEEE1588_SUPPORT
    /** Parse frame in 'buffer' and return l3_len if found */
    errno_t oal_util_parse_ptp_l3(uint8_t *buffer, size_t len, uint8_t l2_len, uint8_t *l3_len, uint8_t off)
    {
        addr_t hdr_addr;
        errno_t ret = EOK;

        hdr_addr = (addr_t)buffer + l2_len;
        if ((oal_ntohs(*((uint16_t *)((addr_t)buffer + off))) == ETHERTYPE_IPV4)
                && (len >= ((size_t)l2_len + L3_HDR_IPv4_LEN)))
        {
            /* IPv4 */
            *l3_len = L3_HDR_IPv4_LEN;

            if ((IPV4_PROTOCOL(hdr_addr) == IPPROTOCOL_UDP)
                    && (IP_VERSION(hdr_addr) == 4U)
                    && (IPV4_IHL(hdr_addr) == 5U)
                    && ( (IPV4_DST_ADDR(hdr_addr) == 0xE0000181UL)
                    || (IPV4_DST_ADDR(hdr_addr) == 0xE0000182UL)
                    || (IPV4_DST_ADDR(hdr_addr) == 0xE0000183UL)
                    || (IPV4_DST_ADDR(hdr_addr) == 0xE0000184UL)
                    || (IPV4_DST_ADDR(hdr_addr) == 0xE0000068UL)
                    )
            )
            {
                /* IP OK, Continue parsing */
            }
            else
            {
                ret = ENOENT; /* non-UDP */
            }
        }
        else if ((oal_ntohs(*((uint16_t *)((addr_t)buffer + off))) == ETHERTYPE_IPV6)
                && (len >= ((size_t)l2_len + L3_HDR_IPv6_LEN)))
        {
            *l3_len = L3_HDR_IPv6_LEN;

            if ((IPV6_PROTOCOL(hdr_addr) == IPPROTOCOL_UDP) && (IP_VERSION(hdr_addr) == 6U))
            {
                /* Intentionally omitted PTP version check. We do match both address variants (primary + pdelay) */
                if ((0 == autolibc_memcmp(&(IPV6_DST_ADDR_PTR(hdr_addr))[2U], &primary_mcast[2U], 14U))
                && ((IPV6_DST_ADDR_PTR(hdr_addr))[0U] == primary_mcast[0U])
                )
                {
                    /* IP OK, Continue parsing */
                }
                else if (0 == autolibc_memcmp(IPV6_DST_ADDR_PTR(hdr_addr), pdelay_mcast, 16U))
                {
                    /* IP OK, Continue parsing */
                }
                else
                {
                    ret = ENOENT;
                }
            }
            else
            {
                ret = ENOENT; /* non-UDP */
            }
        }
        else
        {
            ret = ENOENT; /* non-IP */
        }
        return ret;
    }

    /** Parse frame in 'buffer' and return pointer to PTP header if found */
    errno_t oal_util_parse_ptp(uint8_t *buffer, size_t len, oal_util_ptp_header_t **ptph)
    {
        uint8_t l2_len;
        uint8_t l3_len;
        uint8_t l4_len;
        uint8_t off = 0U;
        addr_t hdr_addr;
        errno_t ret = EOK;

        /* L2 check */
        if (len >= L2_HDR_LEN)
        {
            off = (oal_ntohs(*((uint16_t *)((addr_t)buffer + 12U))) == ETHERTYPE_VLAN)
                    ? 16U  /* skip L2+VLAN hdr */
                    : 12U; /* skip L2 hdr */

            l2_len = off + 2U;

            if (oal_ntohs(*((uint16_t *)((addr_t)buffer + off))) == ETHERTYPE_PTP)
            {
                /* PTP-over_Ethernet */
                *ptph = (oal_util_ptp_header_t *)((addr_t)buffer + l2_len);
                return EOK;
            }
        }
        else
        {
            return ENOENT;
        }

        /* L3 check */
        ret = oal_util_parse_ptp_l3(buffer, len, l2_len, &l3_len, off);
        if (EOK == ret)
        {
            /* L4 check */
            hdr_addr = (addr_t)buffer + l2_len + l3_len;
            l4_len = L4_HDR_UDP_LEN;
            if ((UDP_DPORT(hdr_addr) == 0x13fU) || (UDP_DPORT(hdr_addr) == 0x140U))
            {
                /* PTP-over-IP/UDP */
                *ptph = (oal_util_ptp_header_t *)((addr_t)buffer + l2_len + l3_len + l4_len);
                return EOK;
            }

            /* PTP frame not found */
            return ENOENT;
        }
        return ret;
    }

    uint32_t oal_util_get_unique_seqnum32(void)
    {
        uint32_t val;

        oal_mutex_lock(PFE_OAL_UTIL_SEQNUM_MUTEX);
        val = base;
        base++;
        oal_mutex_unlock(PFE_OAL_UTIL_SEQNUM_MUTEX);

        return val;
    }
#endif /* PFE_CFG_IEEE1588_SUPPORT */

#if defined(NXP_LOG_ENABLED)
uint32_t oal_util_snprintf(char_t *buffer, size_t buf_len, const char_t *format, ...)
{
    uint32_t retval;
    va_list ap;

    va_start(ap, format);
    retval = (uint32_t)vsnprintf(buffer, buf_len, format, ap);
    va_end(ap);
    return retval;
}
#endif /* defined(NXP_LOG_ENABLED) */

/* Custom implementation to avoid creating references to heap memory in libraries */
/**
* @brief Returns pseudo-random number
* @details Function generates pseudo-random number using the LFSR algorithm.
* @return Pseudo-random number in the interval from 0 to 0xFFFFFFFF
*/
int32_t oal_util_rand(void)
{
    /* Generate the next value in the sequence */
    u32RandVal = (u32RandVal >> 1U) ^ ((0U - (u32RandVal & 1U)) & 0x80200003U);
    /* Return the value */
    return u32RandVal;
}

/**
* @brief This function is used to raise DEM event for driver runtime errors
*/
void oal_util_raise_dem_for_drv_runtime_err(void)
{
#if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
    (void)Dem_SetEventStatus((Dem_EventIdType)ETH_43_PFE_CFG_DEM_E_DRIVER_RUNTIME_ERR_INTERNAL, DEM_EVENT_STATUS_PREFAILED);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/** @}*/
