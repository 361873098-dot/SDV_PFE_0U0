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
 *  Copyright 2022-2023 NXP
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

#ifndef SRC_ISA_H_
#define SRC_ISA_H_


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


/**
 * @brief ISA index type
 * Limiting number of items ISA may contain
 * uint8_t 256 items max.
 * uint16_t 65536 item max.
 */
typedef uint16_t pfe_isa_index_t;
typedef bool_t (*pfe_isa_items_compare_cb_t)(const void *array_item, const void *match_item);
typedef void (*pfe_isa_clear_cb_t)(void *array_item);

/**
 * @brief ISA index/item array properties
 */
typedef struct
{
    /* ISA capacity */
    uint32_t item_count;
    /* sizeof(item_t) item array single entry size */
    uint32_t item_size;
    struct
    {
        /* =ISA_FLAG_STRICT_ORDER preserve insert time defined ordering
         * when =ISA_FLAG_STRICT_ORDER isa_liberate has complexity O(n)
         * when =ISA_FLAG_ANY_ORDER isa_liberate has complexity O(1)
         */
        uint8_t ordered : 1;
    } flags;
    /* index array
     * layout:
     * occupied subscripts: <0, occupied_items_count - 1> if occupied_items_count > 0
     * vacant subscripts:   <occupied_items_count, total_items_count - 1>
     */
    pfe_isa_index_t *item_indexes;
    /* data item array */
    void *items;
    /* callback function called during isa_clear for each item */
    pfe_isa_clear_cb_t clear_cb;

} pfe_isa_definition_t;

/* see explanation for flags.keep_in_order */
#define ISA_FLAG_ANY_ORDER 0U
#define ISA_FLAG_STRICT_ORDER 1U

/**
 * @brief ISA context representation
 */
typedef struct
{
    /* total items count currently occupied in item array */
    uint32_t occupied_items_count;
    /* items array properties managed by ISA */
    const pfe_isa_definition_t *props;

} pfe_isa_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

void isa_init(pfe_isa_t *isa, const pfe_isa_definition_t *props);
void isa_clear(pfe_isa_t *isa);
void *isa_item(const pfe_isa_t *isa, uint32_t index_subscript);
void *isa_reserve(pfe_isa_t *isa);
bool_t isa_release_subscript(pfe_isa_t *isa, uint32_t index_subscript);
int32_t isa_release(pfe_isa_t *isa, const void *item);
int32_t isa_find(const pfe_isa_t *isa, const void *match_item, pfe_isa_items_compare_cb_t compare_cb);
bool_t isa_isempty(const pfe_isa_t *isa);
uint32_t isa_occupiedcount(const pfe_isa_t *isa);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/* isa_release return value for case if item not found in the ISA */
#define ISA_ITEM_NOT_FOUND (-1)

#endif /* SRC_ISA_H_ */
