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
 *  Copyright 2021-2024 NXP
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
#ifndef PFE_MIRROR_H
#define PFE_MIRROR_H

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

#include "pfe_class.h"

typedef struct pfe_mirror_tag pfe_mirror_t;

typedef enum
{
    MIRROR_ANY,         /* Retrieve the 1st entry in the database, arg not used */
    MIRROR_BY_NAME,     /* Retrieve the entry with matching name, arg is a string (the name) */
    MIRROR_BY_PHYS_ADDR /* Retrieve the entry with matching DMEM address, arg is addr_t (the address) */
} pfe_mirror_db_crit_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

errno_t pfe_mirror_init(pfe_class_t *class);
void pfe_mirror_deinit(void);
pfe_mirror_t *pfe_mirror_get_first(pfe_mirror_db_crit_t crit, const void *arg);
pfe_mirror_t *pfe_mirror_get_next(void);
pfe_mirror_t *pfe_mirror_create(const char *name);
errno_t pfe_mirror_destroy(pfe_mirror_t *mirror);
void pfe_mirror_put(pfe_mirror_t *mirror);
void pfe_mirror_put_by_address(addr_t address);
uint32_t pfe_mirror_get_address(const pfe_mirror_t *mirror);
const char * pfe_mirror_get_name(const pfe_mirror_t *mirror);
errno_t pfe_mirror_set_egress_port(pfe_mirror_t *mirror, pfe_ct_phy_if_id_t egress);
pfe_ct_phy_if_id_t pfe_mirror_get_egress_port(const pfe_mirror_t *mirror);
errno_t pfe_mirror_set_filter(pfe_mirror_t *mirror, uint32_t filter_address);
uint32_t pfe_mirror_get_filter(const pfe_mirror_t *mirror);
errno_t pfe_mirror_set_actions(pfe_mirror_t *mirror, pfe_ct_route_actions_t actions, const pfe_ct_route_actions_args_t *args);
errno_t pfe_mirror_get_actions(const pfe_mirror_t *mirror, pfe_ct_route_actions_t *actions, pfe_ct_route_actions_args_t *args);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_MIRROR_H */
