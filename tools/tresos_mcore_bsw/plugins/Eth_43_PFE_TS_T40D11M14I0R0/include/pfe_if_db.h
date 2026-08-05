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
 *  Copyright 2017-2024 NXP
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

#ifndef PFE_LOG_IF_DB_H_
#define PFE_LOG_IF_DB_H_

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

#include "linked_list.h"
#include "pfe_ct.h"
#include "pfe_log_if.h"
#include "pfe_phy_if.h"

typedef enum
{
    PFE_IF_DB_PHY = 0,
    PFE_IF_DB_LOG,
    PFE_XXX_IF_DB_INSTANCES
} pfe_if_db_type_t;

/**
 * @brief   Interface database entry type
 */
typedef struct pfe_if_db_entry_tag pfe_if_db_entry_t;

/**
 * @brief   Interface database select criteria type
 */
typedef enum
{
    IF_DB_CRIT_ALL,             /*!< Match any entry in the DB */
    IF_DB_CRIT_BY_ID,           /*!< Match entries by interface ID */
    IF_DB_CRIT_BY_INSTANCE,     /*!< Match entries by interface instance */
    IF_DB_CRIT_BY_NAME,         /*!< Match entries by interface name */
    IF_DB_CRIT_BY_OWNER         /*!< Match entries by owner ID */
} pfe_if_db_get_criterion_t;

/**
 * @brief   Interface database instance representation type
 */
typedef struct pfe_if_db_tag pfe_if_db_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

pfe_if_db_t * pfe_if_db_create(pfe_if_db_type_t type);
void pfe_if_db_destroy(const pfe_if_db_t *db);
errno_t pfe_if_db_add(pfe_if_db_t *db, uint32_t session_id, void *iface, pfe_ct_phy_if_id_t owner);
errno_t pfe_if_db_remove(pfe_if_db_t *db, uint32_t session_id, pfe_if_db_entry_t *entry);
errno_t pfe_if_db_lock(uint32_t *session_id);
errno_t pfe_if_db_lock_owned(uint32_t owner_id);
errno_t pfe_if_db_unlock(uint32_t session_id);
errno_t pfe_if_db_get_first(pfe_if_db_t *db, uint32_t session_id, pfe_if_db_get_criterion_t crit, void *arg, pfe_if_db_entry_t **db_entry);
errno_t pfe_if_db_get_next(pfe_if_db_t *db, uint32_t session_id, pfe_if_db_entry_t **db_entry);
pfe_phy_if_t *pfe_if_db_entry_get_phy_if(const pfe_if_db_entry_t *entry) __attribute__((pure));
#ifdef PFE_CFG_PFE_MASTER /* Only MASTER has access to log_if */ 
pfe_log_if_t *pfe_if_db_entry_get_log_if(const pfe_if_db_entry_t *entry) __attribute__((pure));
errno_t pfe_log_if_db_drop_all(const pfe_if_db_t *db, uint32_t session_id);
#endif
errno_t pfe_if_db_get_single(const pfe_if_db_t *db, uint32_t session_id, pfe_if_db_get_criterion_t crit, void *arg, pfe_if_db_entry_t **db_entry);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_LOG_IF_DB_H_ */
