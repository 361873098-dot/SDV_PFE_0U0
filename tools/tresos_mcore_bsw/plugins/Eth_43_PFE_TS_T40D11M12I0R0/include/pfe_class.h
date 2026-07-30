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

#ifndef PFE_CLASS_H_
#define PFE_CLASS_H_

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

#include "pfe_ct.h"
#include "pfe_ct_comp.h"
#include "pfe_fw_feature.h"

typedef struct pfe_classifier_tag pfe_class_t;

typedef struct
{
    bool_t resume;                  /*  Resume flag */
    bool_t toe_mode;                /*  TCP offload mode */
    uint32_t pe_sys_clk_ratio;      /*  Clock mode ratio for sys_clk and pe_clk */
    uint32_t pkt_parse_offset;      /*  Offset which says from which point packet needs to be parsed */
    void * route_table_base_pa;     /*  Route table physical address */
    void * route_table_base_va;     /*  Route table virtual address */
    uint32_t route_entry_size;      /*  Route entry size */
    uint32_t route_hash_size;       /*  Route hash size (bits) */
    void * ddr_base_va;             /*  DDR region base address (virtual) */
    void * ddr_base_pa;             /*  DDR region base address (physical) */
    uint32_t ddr_size;              /*  Size of the DDR region */
    uint16_t lmem_header_size;
    uint16_t ro_header_size;
    bool_t g2_ordered_class_writes;
} pfe_class_cfg_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

pfe_class_t *pfe_class_create(addr_t cbus_base_va, uint32_t pe_num, const pfe_class_cfg_t *cfg);
errno_t pfe_class_isr(pfe_class_t *class);
void pfe_class_irq_mask(const pfe_class_t *class);
void pfe_class_irq_unmask(const pfe_class_t *class);
void pfe_class_enable(pfe_class_t *class);
void pfe_class_reset(pfe_class_t *class);
void pfe_class_disable(pfe_class_t *class);
errno_t pfe_class_load_firmware(pfe_class_t *class, const void *elf);
errno_t pfe_class_get_mmap(pfe_class_t *class, int32_t pe_idx, pfe_ct_class_mmap_t *mmap);
errno_t pfe_class_write_dmem(void *class_p, int32_t pe_idx, addr_t dst_addr, const void *src_ptr, uint32_t len);
errno_t pfe_class_read_dmem(void *class_p, int32_t pe_idx, void *dst_ptr, addr_t src_addr, uint32_t len);
errno_t pfe_class_gather_read_dmem(pfe_class_t *class, void *dst_ptr, addr_t src_addr, uint32_t buffer_len, uint32_t read_len);
errno_t pfe_class_set_rtable(pfe_class_t *class, addr_t rtable_pa, uint32_t rtable_len, uint32_t entry_size);
errno_t pfe_class_set_default_vlan(const pfe_class_t *class, uint16_t vlan);
uint32_t pfe_class_get_num_of_pes(const pfe_class_t *class);

#if defined(PFE_CFG_TEXT_STATS)
uint32_t pfe_class_get_text_statistics(pfe_class_t *class, char_t *buf, uint32_t buf_len, uint8_t verb_level);
uint32_t pfe_class_fp_stat_to_str(const pfe_ct_class_flexi_parser_stats_t *stat, char *buf, uint32_t buf_len, uint8_t verb_level);
#endif /* defined(PFE_CFG_TEXT_STATS) */

void pfe_class_destroy(pfe_class_t *class);
addr_t pfe_class_dmem_heap_alloc(const pfe_class_t *class, uint32_t size);
void pfe_class_dmem_heap_free(const pfe_class_t *class, addr_t addr);
errno_t pfe_class_put_data(pfe_class_t *class, pfe_ct_buffer_t *buf);
errno_t pfe_class_get_fw_version(const pfe_class_t *class, pfe_ct_version_t *ver);

errno_t pfe_class_get_feature_first(pfe_class_t *class, pfe_fw_feature_t **feature);
errno_t pfe_class_get_feature_next(pfe_class_t *class, pfe_fw_feature_t **feature);
errno_t pfe_class_get_feature(pfe_class_t *class, pfe_fw_feature_t **feature, const char *name);

void pfe_class_flexi_parser_stats_endian(pfe_ct_class_flexi_parser_stats_t *stats);
void pfe_class_sum_flexi_parser_stats(pfe_ct_class_flexi_parser_stats_t *sum, const pfe_ct_class_flexi_parser_stats_t *val);
errno_t pfe_class_get_stats(pfe_class_t *class, pfe_ct_classify_stats_t *stat);
void pfe_class_rtable_lookup_enable(const pfe_class_t *class);
void pfe_class_rtable_lookup_disable(const pfe_class_t *class);
void pfe_class_update_hw_bridge_lookup(pfe_class_t *class, uint32_t if_bitmap, bool_t br_mode);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PFE_CLASS_H_ */
