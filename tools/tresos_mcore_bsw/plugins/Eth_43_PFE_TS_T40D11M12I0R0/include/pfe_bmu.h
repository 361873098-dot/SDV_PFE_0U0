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

#ifndef PUBLIC_PFE_BMU_H_
#define PUBLIC_PFE_BMU_H_

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


#define PFE_BMU_INSTANCES                 2U

typedef struct
{
    uint32_t revision;
    uint32_t version;
    uint32_t id;
    uint32_t free_error_cnt;
    uint32_t active_buff;
    uint32_t buff_size;
}pfe_bmu_stats_special_t;

typedef struct pfe_bmu_tag pfe_bmu_t;
typedef struct
{
    addr_t pool_pa;             /*  Buffer pool base (physical, as seen by PFE). Needs to be aligned to buf_cnt * buf_size. */
    addr_t pool_va;             /*  Buffer pool base (virtual) */
    uint32_t max_buf_cnt;       /*  Maximum number of buffers that can be used */
    uint32_t buf_size;          /*  Buffer size of each of the buffers allocated and freed (size = 2^buf_size) */
    uint32_t bmu_ucast_thres;
    uint32_t bmu_mcast_thres;
    uint32_t int_mem_loc_cnt;
    uint32_t buf_mem_loc_cnt;
} pfe_bmu_cfg_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

pfe_bmu_t *pfe_bmu_create(addr_t cbus_base_va, addr_t bmu_base, const pfe_bmu_cfg_t *cfg, uint32_t bmu_index) __attribute__((cold));
errno_t pfe_bmu_isr(pfe_bmu_t *bmu) __attribute__((cold));
void pfe_bmu_irq_mask(pfe_bmu_t *bmu);
void pfe_bmu_irq_unmask(pfe_bmu_t *bmu);
void pfe_bmu_enable(pfe_bmu_t *bmu) __attribute__((cold));
void pfe_bmu_reset(pfe_bmu_t *bmu) __attribute__((cold));
void pfe_bmu_disable(pfe_bmu_t *bmu) __attribute__((cold));
void *pfe_bmu_alloc_buf(const pfe_bmu_t *bmu) __attribute__((hot));
void *pfe_bmu_get_va(const pfe_bmu_t *bmu, addr_t pa) __attribute__((hot, pure));
void *pfe_bmu_get_pa(const pfe_bmu_t *bmu, addr_t va) __attribute__((hot, pure));
uint32_t pfe_bmu_get_buf_size(const pfe_bmu_t *bmu) __attribute__((cold, pure));
void pfe_bmu_free_buf(const pfe_bmu_t *bmu, addr_t buffer) __attribute__((hot));

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_bmu_get_text_statistics(const pfe_bmu_t *bmu, char_t *buf, uint32_t buf_len, uint8_t verb_level) __attribute__((cold));
#endif /* defined(PFE_CFG_TEXT_STATS) */

uint32_t pfe_bmu_get_stat_value(const pfe_bmu_t* bmu, uint32_t stat_id);
errno_t pfe_bmu_get_special_stats(const pfe_bmu_t* bmu, pfe_bmu_stats_special_t* special_stats);
void pfe_bmu_destroy(pfe_bmu_t *bmu) __attribute__((cold));

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_PFE_BMU_H_ */
