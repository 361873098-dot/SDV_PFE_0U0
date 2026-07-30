/* =========================================================================
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
 * =========================================================================
 * Item Storage Array (ISA)
 * Possible improvements:
 * 1) occupied items can be sorted upon desired criteria to improve find complexity to O(logN)
 * 2) multiple indexes can be created to support various criteria in find implementations
 */


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440


#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"
#include "isa.h"
#include "autolibc.h" /* memcpy */

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

/**
 * @brief Acquire a pointer to an item entry
 * @param props ISA properties definition
 * @param index_subscript entry in occupied items_index
 * @return non NULL item pointer referenced by index_subscript
 * @note Internal helper function
 */
static inline void *isa_item_internal(const pfe_isa_definition_t *props, uint32_t index_subscript)
{
    uint8_t *items;

    items = props->items;
    return &items[props->item_size * props->item_indexes[index_subscript]];
}

/**
 * @brief Initialize index array to empty state
 * @param props ISA properties definition
 */
static void isa_init_index(const pfe_isa_definition_t *props)
{
    uint32_t ii;
    pfe_isa_index_t *item_indexes = props->item_indexes;
    for(ii = 0U; ii < props->item_count; ii++)
    {
        item_indexes[ii] = (pfe_isa_index_t)ii;
    }
}

/**
 * @brief Initialize the ISA
 * @details The ISA after initialization is in empty state
 * @param isa item storage array descriptor
 * @param props ISA properties definition
 */
void isa_init(pfe_isa_t *isa, const pfe_isa_definition_t *props)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely((NULL_PTR == isa) || (NULL_PTR == props) || (NULL_PTR == props->item_indexes)
        || (NULL_PTR == props->items)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* currently no items are reserved */
        isa->occupied_items_count = 0U;
        /* set ISA definition */
        isa->props = props;

        /* now all items are vacant */
        isa_init_index(props);
    }
}

/**
 * @brief Restores empty state of the ISA
 * @details If clear_cb != NULL traverses all the reserved items and call clear_cb callback function for each item.
 *          All reserved items become vacant and occupied_items_count is set to 0.
 * @param isa item storage array descriptor
 */
void isa_clear(pfe_isa_t *isa)
{
    uint32_t ii;
    void *item;
    const pfe_isa_definition_t *props;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL_PTR == isa))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        props = isa->props;
        if(NULL_PTR != props->clear_cb)
        {
            for(ii = 0U; ii < isa->occupied_items_count; ii++)
            {
                item = isa_item_internal(props, ii);
                props->clear_cb(item);
            }
        }

        /* currently no items are reserved */
        isa->occupied_items_count = 0U;

        /* now all items are vacant */
        isa_init_index(props);
    }
}

/**
 * @brief Acquire pointer to an item of the ISA
 * @param isa item storage array descriptor
 * @param index_subscript entry in occupied items_index
 * @retval non NULL pointer to item at index_subscript
 * @retval NULL for index_subscript >= occupied_items_count
 */
void *isa_item(const pfe_isa_t *isa, uint32_t index_subscript)
{
    void *item = NULL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL_PTR == isa))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if(index_subscript < isa->occupied_items_count)
        {
            item = isa_item_internal(isa->props, index_subscript);
        }
    }

    return item;
}

/**
 * @brief Reserve single item from ISA
 * @details Reserved item becomes occupied and the occupied_items_count is increased by 1.
 * @param isa item storage array descriptor
 * @retval non NULL pointer of successfuly reserved item
 * @retval NULL cannot reserve any item
 */
void *isa_reserve(pfe_isa_t *isa)
{
    void *item = NULL;
    const pfe_isa_definition_t *props;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL_PTR == isa))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        props = isa->props;
        if(isa->occupied_items_count < props->item_count)
        {
            item = isa_item_internal(props, isa->occupied_items_count);
            isa->occupied_items_count++;
        }
    }

    return item;
}

/**
 * @brief Release single reserved item in ISA
 * @details Released item becomes vacant ad the occupied_items_count is decreased by 1.
 * @param isa item storage array descriptor
 * @param index_subscript value in range <0, occupied_items_count)
 * @retval TRUE desired item was released
 * @retval FALSE desired item was not found in reserved items
 */
bool_t isa_release_subscript(pfe_isa_t *isa, uint32_t index_subscript)
{
    pfe_isa_index_t liberated_index_value;
    pfe_isa_index_t *remove_index_ptr;
    pfe_isa_index_t *last_index_ptr;
    bool_t result = FALSE;
    const pfe_isa_definition_t *props;
    void *item;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL_PTR == isa))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if(index_subscript < isa->occupied_items_count)
        {
            /* peform internal item data cleanup */
            props = isa->props;
            if(NULL_PTR != props->clear_cb)
            {
                item = isa_item_internal(props, index_subscript);
                props->clear_cb(item);
            }

            /* vacate the item index */
            isa->occupied_items_count--;
            if(index_subscript < isa->occupied_items_count)
            {
                remove_index_ptr = &props->item_indexes[index_subscript];
                last_index_ptr = &props->item_indexes[isa->occupied_items_count];
                /* preserve liberated index value */
                liberated_index_value = *remove_index_ptr;
                if(props->flags.ordered == ISA_FLAG_STRICT_ORDER)
                {
                    /* shift index values in occupied part located after index_subscript
                     * in way that 1st succeeding is overwriting the liberated one */
                    (void)autolibc_memcpy(remove_index_ptr, &remove_index_ptr[1],
                            (isa->occupied_items_count - index_subscript) * sizeof(pfe_isa_index_t));
                }
                else
                {
                    /* ISA_FLAG_ANY_ORDER
                     * get last occupied index value and store it at place pointed by index_subscript */
                    *remove_index_ptr = *last_index_ptr;
                }
                /* store liberated index value after last occupied one */
                *last_index_ptr = liberated_index_value;
            }
            result = TRUE;
        }
    }

    return result;
}

/**
 * @brief Release single reserved item in ISA
 * @details Released item becomes vacant and the occupied_items_count is decreased by 1.
 * @param isa item storage array descriptor
 * @param item pointer to item to be liberated in the ISA
 * @retval >= 0 index subscript of the released item
 * @retval ISA_ITEM_NOT_FOUND if desired item was not found in the ISA
 */
int32_t isa_release(pfe_isa_t *isa, const void *item)
{
    int32_t index_subscript = ISA_ITEM_NOT_FOUND;
    uint32_t ii;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely((NULL_PTR == isa) || (NULL_PTR == item)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        for(ii = 0U; ii < isa->occupied_items_count; ii++)
        {
            if(item == isa_item_internal(isa->props, ii))
            {
                if(TRUE == isa_release_subscript(isa, ii))
                {
                    index_subscript = (int32_t)ii;
                }
                break;
            }
        }
    }

    return index_subscript;
}

/**
 * @brief Find item matching the specified item
 * @details Traverses all the reserved items and verifies matching condition by calling compare_cb callback function.
 *          Callback function must return TRUE if item in question matches with some item in the ISA.
 * @param isa item storage array descriptor
 * @param match_item item to lookup in the ISA
 * @param callback function returning TRUE if match_item and array item are matching otherwise is returning FALSE
 * @retval subscript into index array on success
 * @retval ISA_ITEM_NOT_FOUND if item was not found
 */
int32_t isa_find(const pfe_isa_t *isa, const void *match_item, pfe_isa_items_compare_cb_t compare_cb)
{
    uint32_t ii;
    int32_t  find_index = ISA_ITEM_NOT_FOUND;
    const void *item;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely((NULL_PTR == isa) || (NULL_PTR == match_item) || (NULL_PTR == compare_cb)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if(NULL_PTR != compare_cb)
        {
            for(ii = 0U; ii < isa->occupied_items_count; ii++)
            {
                item = isa_item(isa, ii);
                if(TRUE == compare_cb(item, match_item))
                {
                    find_index = (int32_t)ii;
                    break;
                }
            }
        }
    }

    return find_index;
}

/**
 * @brief Checks if ISA contains any items
 * @param isa item storage array descriptor
 * @return TRUE if ISA is empty otherwise FALSE
 */
bool_t isa_isempty(const pfe_isa_t *isa)
{
    bool_t result;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL_PTR == isa))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        result = TRUE;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        result = (isa->occupied_items_count == 0U);
    }

    return result;
}

/**
 * @brief Get count of currently occupied items of ISA
 * @param isa item storage array descriptor
 * @return >= 0 number of occupied entries in the ISA
 */
uint32_t isa_occupiedcount(const pfe_isa_t *isa)
{
    uint32_t result;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if(unlikely(NULL_PTR == isa))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        result = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        result = isa->occupied_items_count;
    }

    return result;
}

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

