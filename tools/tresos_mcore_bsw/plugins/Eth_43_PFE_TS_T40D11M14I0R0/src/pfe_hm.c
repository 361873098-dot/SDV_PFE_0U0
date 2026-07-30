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
 *  Copyright 2023 NXP
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

/*==============================================================================
                                INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==============================================================================*/
#include "pfe_cfg.h"
#include "oal.h"
#include "pfe_hm.h"

/*==============================================================================
                                 LOCAL MACROS
==============================================================================*/
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))

/*==============================================================================
                               LOCAL VARIABLES
==============================================================================*/
#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static struct {
    bool_t initialized;
    pfe_hm_item_t items[PFE_HM_QUEUE_LEN];
    uint32_t start;
    uint32_t end;
    uint32_t len;
    pfe_hm_cb_t event_cb;
} pfe_hm;
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#ifdef NXP_LOG_ENABLED

typedef struct {
    pfe_hm_evt_t id;
    const char *str;
} hm_string_t;

#define ETH_43_PFE_START_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static const hm_string_t hm_evt_strings[] = {
    {HM_EVT_RUNTIME, "Driver runtime error"},

#ifndef PFE_CFG_PFE_SLAVE
    {HM_EVT_ECC, "ECC Errors interrupt"},

    {HM_EVT_WDT_BMU1, "BMU1 Watchdog trigered"},
    {HM_EVT_WDT_BMU2, "BMU2 Watchdog trigered"},
    {HM_EVT_WDT_CLASS, "CLASS Watchdog trigered"},
    {HM_EVT_WDT_EMAC0_GPI, "EMAC0 GPI Watchdog trigered"},
    {HM_EVT_WDT_EMAC1_GPI, "EMAC1 GPI Watchdog trigered"},
    {HM_EVT_WDT_EMAC2_GPI, "EMAC2 GPI Watchdog trigered"},
    {HM_EVT_WDT_HIF_GPI, "HIF GPI Watchdog trigered"},
    {HM_EVT_WDT_HIF_NOCPY, "HIF NOCPY Watchdog trigered"},
    {HM_EVT_WDT_HIF, "HIF Watchdog trigered"},
    {HM_EVT_WDT_TLITE, "TLITE Watchdog trigered"},
    {HM_EVT_WDT_UTIL_PE, "UTIL Watchdog trigered"},
    {HM_EVT_WDT_EMAC0_ETGPI, "EMAC0 ETGPI Watchdog trigered"},
    {HM_EVT_WDT_EMAC1_ETGPI, "EMAC1 ETGPI Watchdog trigered"},
    {HM_EVT_WDT_EMAC2_ETGPI, "EMAC2 ETGPI Watchdog trigered"},
    {HM_EVT_WDT_EXT_GPT1, "EXT GPT1 Watchdog trigered"},
    {HM_EVT_WDT_EXT_GPT2, "EXT GPT1 Watchdog trigered"},
    {HM_EVT_WDT_LMEM, "LMEM Watchdog trigered"},
    {HM_EVT_WDT_ROUTE_LMEM, "ROUTE LMEM Watchdog trigered"},

    {HM_EVT_EMAC_ECC_TX_FIFO_CORRECTABLE, "MTL Tx memory correctable error"},
    {HM_EVT_EMAC_ECC_TX_FIFO_UNCORRECTABLE, "MTL Tx memory uncorrectable error"},
    {HM_EVT_EMAC_ECC_TX_FIFO_ADDRESS, "MTL Tx memory address mismatch error"},
    {HM_EVT_EMAC_ECC_RX_FIFO_CORRECTABLE, "MTL Rx memory correctable error"},
    {HM_EVT_EMAC_ECC_RX_FIFO_UNCORRECTABLE, "MTL Rx memory uncorrectable error"},
    {HM_EVT_EMAC_ECC_RX_FIFO_ADDRESS, "MTL Rx memory address mismatch error"},
    {HM_EVT_EMAC_APP_TX_PARITY, "Application transmit interface parity error"},
    {HM_EVT_EMAC_APP_RX_PARITY, "Application receive interface parity error"},
    {HM_EVT_EMAC_MTL_PARITY, "MTL data path parity error"},
    {HM_EVT_EMAC_FSM_PARITY, "FSM state parity error"},
    {HM_EVT_EMAC_MASTER_TIMEOUT, "Master Read/Write timeout error"},
    {HM_EVT_EMAC_FSM_TX_TIMEOUT, "Tx FSM timeout error"},
    {HM_EVT_EMAC_FSM_RX_TIMEOUT, "Rx FSM timeout error"},
    {HM_EVT_EMAC_FSM_APP_TIMEOUT, "APP FSM timeout error"},
    {HM_EVT_EMAC_FSM_APP_TIMEOUT, "PTP FSM timeout error"},

    {HM_EVT_BUS_MASTER1, "Master1 bus read error"},
    {HM_EVT_BUS_MASTER2, "Master2 bus write error"},
    {HM_EVT_BUS_MASTER3, "Master3 bus write error"},
    {HM_EVT_BUS_MASTER4, "Master4 bus read error"},
    {HM_EVT_BUS_HGPI_READ, "HGPI bus read error"},
    {HM_EVT_BUS_HGPI_WRITE, "HGPI bus write error"},
    {HM_EVT_BUS_EMAC0_READ, "EMAC 0 bus read error"},
    {HM_EVT_BUS_EMAC0_WRITE, "EMAC 0 bus write error"},
    {HM_EVT_BUS_EMAC1_READ, "EMAC 1 bus read error"},
    {HM_EVT_BUS_EMAC1_WRITE, "EMAC 1 bus write error"},
    {HM_EVT_BUS_EMAC2_READ, "EMAC 2 bus read error"},
    {HM_EVT_BUS_EMAC2_WRITE, "EMAC 2 bus write error"},
    {HM_EVT_BUS_CLASS_READ, "Class bus read error"},
    {HM_EVT_BUS_CLASS_WRITE, "Class bus write error"},
    {HM_EVT_BUS_HIF_NOCPY_READ, "HIF_NOCPY bus read error"},
    {HM_EVT_BUS_HIF_NOCPY_WRITE, "HIF_NOCPY bus write error"},
    {HM_EVT_BUS_TMU, "TMU bus read error"},
    {HM_EVT_BUS_FET, "FET bus read error"},
    {HM_EVT_BUS_UTIL_PE_READ, "Util PE bus read error"},
    {HM_EVT_BUS_UTIL_PE_WRITE, "Util PE bus write error"},

    {HM_EVT_PARITY_MASTER1, "MASTER1_INT-Master1 Parity error"},
    {HM_EVT_PARITY_MASTER2, "MASTER2_INT-Master2 Parity error"},
    {HM_EVT_PARITY_MASTER3, "MASTER3_INT-Master3 Parity error"},
    {HM_EVT_PARITY_MASTER4, "MASTER4_INT-Master4 Parity error"},
    {HM_EVT_PARITY_EMAC_CBUS, "EMAC_CBUS_INT-EMACX cbus parity error"},
    {HM_EVT_PARITY_EMAC_DBUS, "EMAC_DBUS_INT-EMACX dbus parity error"},
    {HM_EVT_PARITY_CLASS_CBUS, "CLASS_CBUS_INT-Class cbus parity error"},
    {HM_EVT_PARITY_CLASS_DBUS, "CLASS_DBUS_INT-Class dbus parity error"},
    {HM_EVT_PARITY_TMU_CBUS, "TMU_CBUS_INT-TMU cbus parity error"},
    {HM_EVT_PARITY_TMU_DBUS, "TMU_DBUS_INT-TMU dbus parity error"},
    {HM_EVT_PARITY_HIF_CBUS, "HIF_CBUS_INT-HGPI cbus parity error"},
    {HM_EVT_PARITY_HIF_DBUS, "HIF_DBUS_INT-HGPI dbus parity error"},
    {HM_EVT_PARITY_HIF_NOCPY_CBUS, "HIF_NOCPY_CBUS_INT-HIF_NOCPY cbus parity error"},
    {HM_EVT_PARITY_HIF_NOCPY_DBUS, "HIF_NOCPY_DBUS_INT-HIF_NOCPY dbus parity error"},
    {HM_EVT_PARITY_UPE_CBUS, "UPE_CBUS_INT-UTIL_PE cbus parity error"},
    {HM_EVT_PARITY_UPE_DBUS, "UPE_DBUS_INT-UTIL_PE dbus parity error"},
    {HM_EVT_PARITY_HRS_CBUS, "HRS_CBUS_INT-HRS cbus parity error"},
    {HM_EVT_PARITY_BRIDGE_CBUS, "BRIDGE_CBUS_INT-BRIDGE cbus parity error"},
    {HM_EVT_PARITY_EMAC_SLV, "EMAC_SLV_INT-EMACX slave parity error"},
    {HM_EVT_PARITY_BMU1_SLV, "BMU1_SLV_INT-BMU1 slave parity error"},
    {HM_EVT_PARITY_BMU2_SLV, "BMU2_SLV_INT-BMU2 slave parity error"},
    {HM_EVT_PARITY_CLASS_SLV, "CLASS_SLV_INT-CLASS slave parity error"},
    {HM_EVT_PARITY_HIF_SLV, "HIF_SLV_INT-HIF slave parity error"},
    {HM_EVT_PARITY_HIF_NOCPY_SLV, "HIF_NOCPY_SLV_INT-HIF_NOCPY slave parity error"},
    {HM_EVT_PARITY_LMEM_SLV, "LMEM_SLV_INT-LMEM slave parity error"},
    {HM_EVT_PARITY_TMU_SLV, "TMU_SLV_INT-TMU slave parity error"},
    {HM_EVT_PARITY_UPE_SLV, "UPE_SLV_INT-UTIL_PE slave parity error"},
    {HM_EVT_PARITY_WSP_GLOBAL_SLV, "WSP_GLOBAL_SLV_INT-WSP_GLOBAL slave parity error"},
    {HM_EVT_PARITY_GPT1_SLV, "GPT1 slave parity error"},
    {HM_EVT_PARITY_GPT2_SLV, "GPT2 slave parity error"},
    {HM_EVT_PARITY_ROUTE_LMEM_SLV, "Route LMEM slave parity error"},

    {HM_EVT_FAIL_STOP_PARITY, "Fail Stop: the Parity error int"},
    {HM_EVT_FAIL_STOP_WATCHDOG, "Fail Stop: the Watchdog timer error int"},
    {HM_EVT_FAIL_STOP_BUS, "Fail Stop: the Bus error int"},
    {HM_EVT_FAIL_STOP_ECC_MULTIBIT, "Fail Stop: the ECC multi bit error int"},
    {HM_EVT_FAIL_STOP_FW, "Fail Stop: the FW failstop int"},
    {HM_EVT_FAIL_STOP_HOST, "Fail Stop: the Host Fail Stop int"},

    {HM_EVT_FW_FAIL_STOP, "FW Fail Stop mode interrupt"},
    {HM_EVT_HOST_FAIL_STOP, "Host Fail Stop mode interrupt"},

    {HM_EVT_BMU_FREE_ERR, "Failed to free buffer"},
    {HM_EVT_BMU_FULL, "All buffers are allocated, pool depleted"},
    {HM_EVT_BMU_MCAST, "BMU_MCAST_EMTPY_INT or BMU_MCAST_FULL_INT or BMU_MCAST_THRES_INT or BMU_MCAST_FREE_ERR_INT triggered"},
#endif

    {HM_EVT_PE_STALL, "PE core stalled"},
    {HM_EVT_PE_EXCEPTION, "PE core raised exception"},
    {HM_EVT_PE_ERROR, "PE core reported error"},

    {HM_EVT_HIF_ERR, "HIF error interrupt"},
    {HM_EVT_HIF_TX_FIFO, "HIF TX FIFO error interrupt"},
    {HM_EVT_HIF_RX_FIFO, "HIF RX FIFO error interrupt"},
};
#define ETH_43_PFE_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
#define ETH_43_PFE_START_SEC_VAR_INIT_32
#include "Eth_43_PFE_MemMap.h"
static const char *hm_src_strings[] = {
    "UNKNOWN",
    "DRIVER",
    "WDT",
    "EMAC0",
    "EMAC1",
    "EMAC2",
    "BUS",
    "PARITY",
    "FAIL_STOP",
    "FW_FAIL_STOP",
    "HOST_FAIL_STOP",
    "ECC",
    "PE_CLASS",
    "PE_UTIL",
    "PE_TMU",
    "HIF",
    "BMU",
};
#define ETH_43_PFE_STOP_SEC_VAR_INIT_32
#include "Eth_43_PFE_MemMap.h"
#endif /* NXP_LOG_ENABLED */

/*==============================================================================
                           LOCAL FUNCTION PROTOTYPES
==============================================================================*/
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
static errno_t pfe_hm_put(const pfe_hm_item_t *item);

/*==============================================================================
                                LOCAL FUNCTIONS
==============================================================================*/
/**
 * @brief       Put event to the HM event queue
 *
 * @param[in]   item Pointer to event which need to be written in HM queue
 * @returns     EOK if suceeded, EOVERFLOW otherwise
 */
static errno_t pfe_hm_put(const pfe_hm_item_t *item)
{
    errno_t ret = EOVERFLOW;

    (void)oal_mutex_lock(PFE_HM_MUTEX_00);

    if (pfe_hm.len < ARRAY_LEN(pfe_hm.items))
    {
        (void)autolibc_memcpy(&pfe_hm.items[pfe_hm.end], item, sizeof(pfe_hm_item_t));

        pfe_hm.len++;
        pfe_hm.end++;
        if (pfe_hm.end >= ARRAY_LEN(pfe_hm.items))
        {
            pfe_hm.end = 0U;
        }
        ret = EOK;
    }

    (void)oal_mutex_unlock(PFE_HM_MUTEX_00);

    return ret;
}

/**
 * @brief   Initializes the HM module
 */
void pfe_hm_init(void)
{
    pfe_hm.start = 0;
    pfe_hm.end = 0;
    pfe_hm.len = 0;
    pfe_hm.initialized = TRUE;
    pfe_hm.event_cb = NULL;
}

/**
 * @brief   Destroys the HM module
 */
void pfe_hm_destroy(void)
{
    if (TRUE == pfe_hm.initialized)
    {
        pfe_hm.initialized = FALSE;
    }
}

/**
 * @brief   Logs the event into the database and stdout
 *
 * @param[in]   src     Source module of the event
 * @param[in]   type    Type of the event
 * @param[in]   id      ID of the event
 * @param[in]   format  NULL or printf like formatted string
 */
void pfe_hm_report(pfe_hm_src_t src, pfe_hm_type_t type, pfe_hm_evt_t id, const char *format, ...)
{
    errno_t ret = EOVERFLOW;
    pfe_hm_item_t item;
#ifdef NXP_LOG_ENABLED
    const char *separator = "";
    const char *event_str = pfe_hm_get_event_str(id);
    const char *src_str = pfe_hm_get_src_str(src);
    va_list args;

    va_start(args, format);

    item.descr[0U] = '\0';
    if ((NULL != format) && (0U != autolibc_strlen(format)))
    {
        separator = ": ";
        nxp_vsnprintf(item.descr, ARRAY_LEN(item.descr), format, args);
        item.descr[ARRAY_LEN(item.descr)-1U] = '\0';
    }

    va_end(args);

    switch (type)
    {
        case HM_INFO:
            NXP_LOG_HM("INF_HM: (%s) event %d - %s%s%s\n", src_str, (int)id, event_str, separator, item.descr);
            break;
        case HM_WARNING:
            NXP_LOG_HM("WRN_HM: (%s) event %d - %s%s%s\n", src_str, (int)id, event_str, separator, item.descr);
            break;
        case HM_ERROR:
            if( id == HM_EVT_RUNTIME)
            {
                /* This is to make it more user-friendly than (DRIVER) event 1 - Driver runtime error */
                NXP_LOG_HM("ERR_HM RUNTIME%s%s\n", separator, item.descr);
            }
            else
            {
                NXP_LOG_HM("ERR_HM: (%s) event %d - %s%s%s\n", src_str, (int)id, event_str, separator, item.descr);
            }
            break;
        default:
            /* Do Nothing */
            break;
    }
#else
    (void)format;
#endif /* NXP_LOG_ENABLED */

    item.type = type;
    item.src = src;
    item.id = id;

    if (TRUE == pfe_hm.initialized)
    {
        ret = pfe_hm_put(&item);
        if (EOK != ret)
        {
            NXP_LOG_WARNING("HM event storage is full, no further events will be stored.\n");
        }
    }

    if (NULL != pfe_hm.event_cb)
    {
        pfe_hm.event_cb(&item);
    }
}

/**
 * @brief       Gets first event from the HM event queue
 *
 * @param[out]  item Memory area to store event to
 * @returns     EOK if suceeded, ENOENT otherwise
 */
errno_t pfe_hm_get(pfe_hm_item_t *item)
{
    errno_t ret = ENOENT;

    if (TRUE == pfe_hm.initialized)
    {
        (void)oal_mutex_lock(PFE_HM_MUTEX_01);

        if (0U != pfe_hm.len)
        {
            (void)autolibc_memcpy(item, &pfe_hm.items[pfe_hm.start], sizeof(pfe_hm_item_t));
    
            pfe_hm.len--;
            pfe_hm.start++;
            if (pfe_hm.start >= ARRAY_LEN(pfe_hm.items))
            {
                pfe_hm.start = 0;
            }
            ret = EOK;
        }

        (void)oal_mutex_unlock(PFE_HM_MUTEX_01);
    }

    return ret;
}

/**
 * @brief   Registers callback for new events
 *
 * @param[in]   cb Callback
 * @returns Successfulness of the registration
 */
bool_t pfe_hm_register_event_cb(pfe_hm_cb_t cb)
{
    bool_t ret = FALSE;

    if (NULL == pfe_hm.event_cb)
    {
        pfe_hm.event_cb = cb;
        ret = TRUE;
    }
    return ret;
}

#ifdef NXP_LOG_ENABLED
/**
 * @brief   Converts event ID to string representation
 * @param[in]   id ID of the event
 * @returns Corresponding string or empty string
 */
const char *pfe_hm_get_event_str(pfe_hm_evt_t id)
{
    uint32_t i;
    const char* ret = "";
    for (i = 0; i < ARRAY_LEN(hm_evt_strings); i++)
    {
        if (hm_evt_strings[i].id == id)
        {
            ret = hm_evt_strings[i].str;
            break;
        }
    }
    return ret;
}

/**
 * @brief   Converts source ID to string representation
 * @param[in]   src Source of the event
 * @returns Corresponding string or empty string
 */
const char *pfe_hm_get_src_str(pfe_hm_src_t src)
{
    const char* ret = "";

    if ((uint32_t)src >= ARRAY_LEN(hm_src_strings))
    {
        ret = "";
    }
    else
    {
        ret = hm_src_strings[src];
    }

    return ret;
}
#endif /* NXP_LOG_ENABLED */
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
