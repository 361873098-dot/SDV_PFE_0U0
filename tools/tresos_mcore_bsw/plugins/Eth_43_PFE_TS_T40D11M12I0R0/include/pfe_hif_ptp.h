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

#ifndef PUBLIC_PFE_HIF_PTP_H_
#define PUBLIC_PFE_HIF_PTP_H_

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

#include "isa.h"

/*  Number of entries in the DB producing warning message */
#define PFE_HIF_PTP_DB_WARNING_THRESHOLD    50U

/*  Maximum allowed number of entries */
#define PFE_HIF_PTP_DB_MAX_CAPACITY         (PFE_HIF_PTP_DB_WARNING_THRESHOLD + 10U)

typedef struct
{
    uint32_t ticks;     /* Timeout counter (in number of ticks). Zero means entry is aged. */
    uint16_t refnum;    /* Reference to identify ETS report */
    uint8_t type;       /* PTP Message type */
    bool_t rx;          /* If TRUE then entry refers to ingress message */
    uint16_t port;      /* PTP Port */
    uint16_t seq_id;    /* PTP Sequence ID */
    uint32_t ts_sec;
    uint32_t ts_nsec;
    bool_t ts_valid;
} pfe_hif_ptp_ts_db_entry_t;

typedef struct
{
    pfe_isa_t entries;
    pfe_isa_index_t entries_pool_index[PFE_HIF_PTP_DB_MAX_CAPACITY];
    pfe_hif_ptp_ts_db_entry_t entries_pool[PFE_HIF_PTP_DB_MAX_CAPACITY];
    pfe_isa_definition_t entries_isa_def;
    uint8_t count;
    bool_t reported;
} pfe_hif_ptp_ts_db_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

errno_t pfe_hif_ptp_ts_db_init(pfe_hif_ptp_ts_db_t *db);
void pfe_hif_ptp_ts_db_fini(pfe_hif_ptp_ts_db_t *db);
errno_t pfe_hif_ptp_ts_db_push_msg(pfe_hif_ptp_ts_db_t *db, bool_t rx,
        uint16_t refnum, uint8_t type, uint16_t port, uint16_t seq_id);
errno_t pfe_hif_ptp_ts_db_push_ts(pfe_hif_ptp_ts_db_t *db, bool_t rx,
        uint16_t refnum, uint32_t ts_sec, uint32_t ts_nsec);
errno_t pfe_hif_ptp_ts_db_pop(pfe_hif_ptp_ts_db_t *db,
        uint8_t type, uint16_t port, uint16_t seq_id,
        uint32_t *ts_sec, uint32_t *ts_nsec, bool_t rx);
void pfe_hif_ptp_ts_db_tick_iteration(void *arg);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_PFE_HIF_PTP_H_ */
