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

#ifndef PFE_PE_H_
#define PFE_PE_H_

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

#include "pfe_ct.h"

typedef enum
{
    PFE_PE_DMEM,
    PFE_PE_IMEM
} pfe_pe_mem_t;

struct pfe_pe_tag;

typedef struct
{
    uint8_t pe_loaded_cnt;
    bool_t can_load_util;
    void (*pe_memset)(struct pfe_pe_tag *pe, pfe_pe_mem_t mem, uint32_t val, addr_t addr, uint32_t size);
    void (*pe_memcpy)(struct pfe_pe_tag *pe, pfe_pe_mem_t mem, addr_t dst_addr, const void *src_ptr, uint32_t len);
} fw_load_ops_t;

/*  Processing Engine representation */
typedef struct pfe_pe_tag
{
    pfe_ct_pe_type_t type;              /* PE type */
    addr_t cbus_base_va;                /* CBUS base (virtual) */
    uint8_t id;                         /* PE HW ID (0..N) */

    /*  DMEM */
    addr_t dmem_elf_base_va;            /* PE's DMEM base address (virtual, as seen by PE) */
    addr_t dmem_size;                   /* PE's DMEM region length */

    /*  IMEM */
    addr_t imem_elf_base_va;            /* PE's IMEM base address (virtual, as seen by PE) */
    addr_t imem_size;                   /* PE's IMEM size */

    /*  LMEM */
    addr_t lmem_base_addr_pa;           /* PE's LMEM base address (physical, as seen by PE) */
    addr_t lmem_size;                   /* PE's LMEM size */

    /*  DDR */
    addr_t ddr_base_addr_pa;            /* PE's DDR base address (physical, as seen by host) */
    addr_t ddr_base_addr_va;            /* PE's DDR base address (virtual) */
    addr_t ddr_size;                    /* PE's DDR size */

    /*  Indirect Access */
    addr_t mem_access_wdata;            /* PE's _MEM_ACCESS_WDATA register address (virtual) */
    addr_t mem_access_addr;             /* PE's _MEM_ACCESS_ADDR register address (virtual) */
    addr_t mem_access_rdata;            /* PE's _MEM_ACCESS_RDATA register address (virtual) */

    /* Operations to load FW */
    const fw_load_ops_t *fw_load_ops;

    /* FW Errors*/
    uint32_t message_record_addr;       /* Error record storage address in DMEM */
    uint32_t last_message_write_index;  /* Last seen value of write index in the record */
    void *fw_msg_section;               /* Error descriptions elf section storage */
    uint32_t fw_msg_section_size;       /* Size of the above section */
    /* FW features */
    void *fw_feature_section;           /* Features descriptions elf section storage */
    uint32_t fw_feature_section_size;   /* Size of the above section */
    uint32_t fw_features_base;          /* Extracted base address of the features table */
    uint32_t fw_features_size;          /* Number of entries in the features table */

    /*  MMap */
    pfe_ct_pe_mmap_t *mmap_data;        /* Buffer containing the memory map data */

    bool_t *miflock;                    /* Pointer to diagnostic flag (provided from PE's parent) 
                                           When TRUE then PFE memory interface is locked */

    /* Stall detection */
    uint32_t counter;                   /* Latest PE counter value */
    pfe_ct_pe_sw_state_t prev_state;    /* Recently read PE state */
    bool_t stalled;                     /* Flag for current stall state */
} pfe_pe_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

pfe_pe_t * pfe_pe_create(addr_t cbus_base_va, pfe_ct_pe_type_t type, uint8_t id, pfe_pe_t *pe, bool_t *miflock);
void pfe_pe_set_dmem(pfe_pe_t *pe, addr_t elf_base, addr_t len);
void pfe_pe_set_imem(pfe_pe_t *pe, addr_t elf_base, addr_t len);
void pfe_pe_set_lmem(pfe_pe_t *pe, addr_t elf_base, addr_t len);
void pfe_pe_set_iaccess(pfe_pe_t *pe, uint32_t wdata_reg, uint32_t rdata_reg, uint32_t addr_reg);
errno_t pfe_pe_mem_default_init(pfe_pe_t *pe, uint32_t pe_num);
errno_t pfe_pe_load_firmware(pfe_pe_t *pe, uint32_t pe_num, const void *elf);
errno_t pfe_pe_get_mmap(const pfe_pe_t *pe, pfe_ct_pe_mmap_t *mmap);
void pfe_pe_memcpy_from_dmem_to_host_32_nolock(pfe_pe_t *pe, void *dst_ptr, addr_t src_addr, uint32_t len);
void pfe_pe_memcpy_from_host_to_dmem_32(pfe_pe_t *pe, addr_t dst_addr, const void *src_ptr, uint32_t len);
void pfe_pe_memcpy_from_dmem_to_host_32(pfe_pe_t *pe, void *dst_ptr, addr_t src_addr, uint32_t len);
errno_t pfe_pe_gather_memcpy_from_dmem_to_host_32(pfe_pe_t *pe, int32_t pe_count, void *dst_ptr, addr_t src_addr, uint32_t buffer_len, uint32_t read_len);
errno_t pfe_pe_get_fw_feature_entry(pfe_pe_t *pe, uint32_t id, pfe_ct_feature_desc_t **entry);
errno_t pfe_pe_get_pe_stats_nolock(pfe_pe_t *pe, uint32_t addr, pfe_ct_pe_stats_t *stats);
bool_t pfe_pe_check_stalled_nolock(pfe_pe_t *pe);
errno_t pfe_pe_get_classify_stats_nolock(pfe_pe_t *pe, uint32_t addr, pfe_ct_classify_stats_t *stats);
errno_t pfe_pe_get_class_algo_stats_nolock(pfe_pe_t *pe, uint32_t addr, pfe_ct_class_algo_stats_t *stats);
pfe_ct_pe_sw_state_t pfe_pe_get_fw_state(pfe_pe_t *pe);

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_pe_get_text_statistics(pfe_pe_t *pe, char_t *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

void pfe_pe_destroy(pfe_pe_t *pe, uint32_t pe_num);
errno_t pfe_pe_check_mmap(const pfe_pe_t *pe);
errno_t pfe_pe_get_fw_messages_nolock(pfe_pe_t *pe);
errno_t pfe_pe_get_data_nolock(pfe_pe_t *pe, pfe_ct_buffer_t *buf);
errno_t pfe_pe_put_data_nolock(pfe_pe_t *pe, pfe_ct_buffer_t *buf);
errno_t pfe_pe_memlock_acquire_nolock(pfe_pe_t *pe);
errno_t pfe_pe_memlock_release_nolock(pfe_pe_t *pe);
void pfe_pe_lock_family(pfe_pe_t *pe);
void pfe_pe_unlock_family(pfe_pe_t *pe);
char *pfe_pe_get_fw_feature_str_base(const pfe_pe_t *pe);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_PE_H_ */
