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
 *  This code (or certain portions of it) is released for use under license
 *  from Imagination Technologies Limited.
 *  Copyright (c) 2019 Imagination Technologies Limited
 *  Copyright (c) 2020-2021 Imagination Technologies Limited
 *  Copyright 2020-2023 NXP
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "oal.h"
#include "pfe_hif_ptp.h"

/*  Entry timeout in number of ticks */
#define PFE_HIF_PTP_DB_TIMEOUT              1

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/**
 * @brief       Periodically called db maintenance function
 * @details     In AUTOSAR MCAL driver this function is called from hif drv,
 *              in other drivers from an internal thread.
 */
void pfe_hif_ptp_ts_db_tick_iteration(void *arg)
{
    pfe_hif_ptp_ts_db_t *db = (pfe_hif_ptp_ts_db_t *)arg;
    pfe_hif_ptp_ts_db_entry_t *entry;
    uint32_t index;

    /* Release aged entries */
    oal_mutex_lock(PFE_HIF_PTP_TS_DB_MUTEX_00);
    for(index = db->entries.occupied_items_count; index > 0U; index--)
    {
        entry = (pfe_hif_ptp_ts_db_entry_t *)isa_item(&db->entries, index - 1U);
        if (NULL_PTR != entry)
        {
            if (entry->ticks == 0U)
            {
                NXP_LOG_INFO("Removing aged TS DB entry (Type: 0x%x, Port: 0x%x, SeqID: 0x%x)\n",
                        entry->type, entry->port, entry->seq_id);
                (void)isa_release_subscript(&db->entries, index - 1U);
                db->count--;
            }
            else
            {
                entry->ticks--;
            }
        }
    }
    oal_mutex_unlock(PFE_HIF_PTP_TS_DB_MUTEX_00);
}

/**
 * @brief   Initialize TS database
 */
errno_t pfe_hif_ptp_ts_db_init(pfe_hif_ptp_ts_db_t *db)
{
    (void)autolibc_memset(db, 0, sizeof(pfe_hif_ptp_ts_db_t));

    db->entries_isa_def.item_count = PFE_HIF_PTP_DB_MAX_CAPACITY;
    db->entries_isa_def.item_size = sizeof(pfe_hif_ptp_ts_db_entry_t);
    db->entries_isa_def.flags.ordered = ISA_FLAG_STRICT_ORDER;
    db->entries_isa_def.item_indexes = db->entries_pool_index;
    db->entries_isa_def.items = db->entries_pool;
    db->entries_isa_def.clear_cb = (pfe_isa_clear_cb_t)NULL_PTR;

    isa_init(&db->entries, &db->entries_isa_def);

    return EOK;
}

/**
 * @brief   Finalize the TS database
 */
void pfe_hif_ptp_ts_db_fini(pfe_hif_ptp_ts_db_t *db)
{
    /*  Release all entries */
    oal_mutex_lock(PFE_HIF_PTP_TS_DB_MUTEX_01);
    (void)autolibc_memset(&db->entries, 0, sizeof(db->entries));
    (void)autolibc_memset(&db->entries_isa_def, 0, sizeof(db->entries_isa_def));
    oal_mutex_unlock(PFE_HIF_PTP_TS_DB_MUTEX_01);
}

/**
 * @brief   Add PTP message to the DB. TS will be added later.
 */
errno_t pfe_hif_ptp_ts_db_push_msg(pfe_hif_ptp_ts_db_t *db, bool_t rx,
        uint16_t refnum, uint8_t type, uint16_t port, uint16_t seq_id)
{
    errno_t ret;
    pfe_hif_ptp_ts_db_entry_t *entry;

    /* We should somehow limit number of entries.. */
    if (db->count >= PFE_HIF_PTP_DB_MAX_CAPACITY)
    {
        ret = ENOSPC;
    }
    else
    {
        /*  Link-in */
        oal_mutex_lock(PFE_HIF_PTP_TS_DB_MUTEX_02);

        entry = (pfe_hif_ptp_ts_db_entry_t*)isa_reserve(&db->entries);
        if (NULL_PTR == entry)
        {
            ret = ENOMEM;
        }
        else
        {
            /* Fill entry */
            entry->refnum = refnum;
            entry->type = type;
            entry->port = port;
            entry->seq_id = seq_id;
            entry->ts_valid = FALSE;
            entry->ticks = PFE_HIF_PTP_DB_TIMEOUT;
            entry->rx = rx;

            db->count++;

            if ((db->count > PFE_HIF_PTP_DB_WARNING_THRESHOLD) && !db->reported)
            {
                NXP_LOG_WARNING("More than %d entries in PTP DB...\n", PFE_HIF_PTP_DB_WARNING_THRESHOLD);
                db->reported = TRUE;
            }
            ret = EOK;
        }
        oal_mutex_unlock(PFE_HIF_PTP_TS_DB_MUTEX_02);
    }

    return ret;
}

/**
 * @brief       Bind TS with existing entry
 * @param[in]   db Pointer to timestamp database to store timestamp values in
 * @param[in]   rx Specifies direction of message the timestamp belongs to. Rx: rx=TRUE, Tx: rx=FALSE
 * @param[in]   refnum Reference number of the timestamp for matching with message
 * @param[in]   ts_sec Timestamp value to put in database, seconds
 * @param[in]   ts_nsec Timestamp value to put in database, nanoseconds
 * @retval      EOK Timestamp was stored
 * @retval      ENOENT No matching message was found, timestamp was not stored
 */
errno_t pfe_hif_ptp_ts_db_push_ts(pfe_hif_ptp_ts_db_t *db, bool_t rx,
        uint16_t refnum, uint32_t ts_sec, uint32_t ts_nsec)
{
    pfe_hif_ptp_ts_db_entry_t *entry;
    bool_t found = FALSE;
    uint32_t index;

    /* Find matching entry and add the timestamp */
    oal_mutex_lock(PFE_HIF_PTP_TS_DB_MUTEX_03);

    for(index = 0U; index < db->entries.occupied_items_count; index++)
    {
        entry = (pfe_hif_ptp_ts_db_entry_t *)isa_item(&db->entries, index);
        if (NULL_PTR != entry)
        {
            if ((entry->refnum == refnum) && (entry->rx == rx))
            {
                found = TRUE;
                entry->ts_sec = ts_sec;
                entry->ts_nsec = ts_nsec;
                entry->ts_valid = TRUE;
                break;
            }
        }
    }

    oal_mutex_unlock(PFE_HIF_PTP_TS_DB_MUTEX_03);

    return (found) ? EOK : ENOENT;
}

/**
 * @brief   Get TS associated with give PTP message
 */
errno_t pfe_hif_ptp_ts_db_pop(pfe_hif_ptp_ts_db_t *db,
        uint8_t type, uint16_t port, uint16_t seq_id,
            uint32_t *ts_sec, uint32_t *ts_nsec, bool_t rx)
{
    errno_t ret_val = ENOENT;
    pfe_hif_ptp_ts_db_entry_t *entry;
    uint32_t index;

    /* Find matching entry and get the timestamp */
    oal_mutex_lock(PFE_HIF_PTP_TS_DB_MUTEX_04);

    for(index = 0U; index < db->entries.occupied_items_count; index++)
    {
        entry = (pfe_hif_ptp_ts_db_entry_t *)isa_item(&db->entries, index);
        if (NULL_PTR != entry)
        {
            if ((entry->rx == rx)
                    && (entry->type == type)
                    && (entry->port == port)
                    && (entry->seq_id == seq_id))
            {
                if (entry->ts_valid == TRUE)
                {
                    ret_val = EOK;
                    *ts_sec = entry->ts_sec;
                    *ts_nsec = entry->ts_nsec;
                }
                else
                {
                    ret_val = EAGAIN;
                }
                break;
            }
        }
    }

    if (EOK == ret_val)
    {
        /*  Remove from DB */
        (void)isa_release(&db->entries, entry);

        db->count--;
        if ((db->count <= (PFE_HIF_PTP_DB_WARNING_THRESHOLD/4U)) && db->reported)
        {
            db->reported = FALSE;
        }
    }

    oal_mutex_unlock(PFE_HIF_PTP_TS_DB_MUTEX_04);

    return ret_val;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
