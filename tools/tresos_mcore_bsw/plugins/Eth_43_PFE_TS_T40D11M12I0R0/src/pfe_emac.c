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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "hal.h"
#ifdef PFE_CFG_PFE_MASTER
#include "pfe_platform_cfg.h"
#include "pfe_cbus.h"
#include "pfe_emac_csr.h"
#include "pfe_emac.h"
#include "pfe_platform.h"
#include "pfe_mac_db.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_emac_t emac_instance[PFE_EMAC_INSTANCES];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_VAR_INIT_32
#include "Eth_43_PFE_MemMap.h"

/* usage scope: pfe_emac_mdio_lock */
static uint32_t key_seed = 123U;

#define ETH_43_PFE_STOP_SEC_VAR_INIT_32
#include "Eth_43_PFE_MemMap.h"

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#define PFE_CFG_EMAC0_PPS0_PERIOD_SEC ((PFE_CFG_EMAC0_PPS0_PERIOD_TICKS + 1U) / PFE_CFG_IEEE1588_EMAC0_O_CLK_HZ)

static errno_t pfe_emac_del_addr_nolock(pfe_emac_t *emac, const pfe_mac_addr_t addr, pfe_drv_id_t owner);
static uint8_t pfe_emac_mac_slot_idx(pfe_emac_t *emac, const pfe_mac_addr_t addr);
static bool_t pfe_emac_mac_hash_col(pfe_emac_t *emac, const pfe_mac_addr_t addr);
static bool_t pfe_emac_mac_in_db(pfe_emac_t *emac, const pfe_mac_addr_t addr);
static addr_t pfe_get_hif_base_addr(pfe_platform_t *platform);

/* 
 * Get HIF base address of HIF register space (virtual)
 */
static addr_t pfe_get_hif_base_addr(pfe_platform_t *platform)
{
    return platform->cbus_baseaddr + CBUS_HIF_BASE_ADDR;
}

/**
 * @brief       Search whether there exist other MAC in EMAC hash table with the same hash index
 * @details     Hash index is calculated according to upper six bits from 32 bit hash value, 
                so only upper six bits from hash value are compared.
 * @param[in]   emac The EMAC instance
 * @param[in]   addr The MAC address to search for
 * @return      TRUE There exist at least one other MAC in database with collision in upper six bits
 * @return      FALSE No match
 */
static bool_t pfe_emac_mac_hash_col(pfe_emac_t *emac, const pfe_mac_addr_t addr)
{
    errno_t ret;
    bool_t found = FALSE;
    pfe_mac_addr_t addr_temp;
    const uint32_t hash_match_mask = pfe_emac_cfg_get_hash(emac->emac_base_va, addr) & EMAC_CFG_MAC_HASH_MASK;
    
    ret = pfe_mac_db_get_first_addr(&emac->mac_db, MAC_DB_CRIT_ALL, PFE_TYPE_ANY, PFE_PHY_IF_ID_MAX, addr_temp);
    while (EOK == ret)
    {
        if (EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT == pfe_emac_mac_slot_idx(emac, addr_temp))
        {
            /* Not exists in slot, must be in hash table */
            uint32_t hash_temp = pfe_emac_cfg_get_hash(emac->emac_base_va, addr_temp);
            if ((EMAC_CFG_MAC_HASH_MASK & hash_temp) == hash_match_mask)
            {
                /* found hash colision in upper six bits */
                found = TRUE;
                break;
            }
            
        }
        
        ret = pfe_mac_db_get_next_addr(&emac->mac_db, addr_temp);
    }
    
    return found;
}

/**
 * @brief       Search whether MAC is stored in EMAC exact match slot or not
 * @param[in]   emac The EMAC instance
 * @param[in]   addr The MAC address to search for
 * @return      If found, returns slot index, otherwise returns EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT
 */
static uint8_t pfe_emac_mac_slot_idx(pfe_emac_t *emac, const pfe_mac_addr_t addr)
{
    uint8_t found_idx = EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT;
    pfe_mac_addr_t addr_in_slot;
    
    /* Try to find address in individual address slot */
    for (uint8_t slot = 0U; slot < EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT; slot++)
    {
        if (0U != (emac->mac_addr_slots & (1U << slot)))
        {
            /* Slot is in use, check address */
            pfe_emac_cfg_read_addr_slot(emac->emac_base_va, addr_in_slot, slot);
            if (0 == autolibc_memcmp(addr, addr_in_slot, sizeof(pfe_mac_addr_t)))
            {
                /* Address found */
                found_idx = slot;
                break;
            }
        }
    }
    return found_idx;
}

/**
 * @brief       Search whether given MAC exists in db
 * @param[in]   emac The EMAC instance
 * @param[in]   addr The MAC address to search for
 * @return      TRUE There exist at least one other MAC in database
 * @return      FALSE No match
 */
static bool_t pfe_emac_mac_in_db(pfe_emac_t *emac, const pfe_mac_addr_t addr)
{
    errno_t ret;
    bool_t found = FALSE;
    pfe_mac_addr_t addr_temp;
    
    ret = pfe_mac_db_get_first_addr(&emac->mac_db, MAC_DB_CRIT_ALL, PFE_TYPE_ANY, PFE_PHY_IF_ID_MAX, addr_temp);
    while (EOK == ret)
    {
        if (0 == autolibc_memcmp(addr, addr_temp, sizeof(pfe_mac_addr_t)))
        {
            found = TRUE;
            break;
        }            
        
        ret = pfe_mac_db_get_next_addr(&emac->mac_db, addr_temp);
    }
    return found;
}



/**
 * @brief       Create new EMAC instance
 * @details     Creates and initializes MAC instance
 * @param[in]   cbus_base_va CBUS base virtual address
 * @param[in]   emac_base EMAC base address offset within CBUS address space
 * @param[in]   mode The MII mode to be used @see pfe_emac_mii_mode_t
 * @param[in]   speed Speed @see pfe_emac_speed_t
 * @param[in]   duplex The duplex type @see pfe_emac_duplex_t
 * @param[in]   emac_index The ID for EMAC instance to be initialized
 * @return      The EMAC instance or NULL if failed
 */
pfe_emac_t *pfe_emac_create(addr_t cbus_base_va, addr_t emac_base, pfe_emac_mii_mode_t mode, pfe_emac_speed_t speed, pfe_emac_duplex_t duplex, uint32_t emac_index)
{
    pfe_emac_t *emac;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == cbus_base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        emac = NULL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (unlikely(PFE_EMAC_INSTANCES <= emac_index))
        {
            NXP_LOG_ERROR("EMAC index out of range\n");
            emac = NULL;
        }
        else
        {
            emac = &emac_instance[emac_index];
            (void)autolibc_memset(emac, 0, sizeof(pfe_emac_t));
            emac->cbus_base_va = cbus_base_va;
            emac->emac_base_offset = emac_base;
            emac->emac_base_va = (emac->cbus_base_va + emac->emac_base_offset);
            emac->mode = EMAC_MODE_INVALID;
            emac->speed = EMAC_SPEED_INVALID;
            emac->duplex = EMAC_DUPLEX_INVALID;
            emac->emac_id = (pfe_ct_phy_if_id_t)pfe_emac_get_index(emac);

            /*  All slots are free */
            emac->mac_addr_slots = 0U;

            /*  Initialize the MAC address DB. We do not check the return value because the only reason to fail
             *  is when NULL pointer is provided. */
            (void) pfe_mac_db_create(&emac->mac_db);

            /* ERR050221: to ensure parity_en is set before any registers READ to MAC */
            pfe_emac_cfg_pre_init(emac->emac_base_va);
            
            /*  Disable the HW */
            pfe_emac_disable(emac);

            /*  Initialize the HW */
            if (EOK != pfe_emac_cfg_init(emac->emac_base_va, mode, speed, duplex))
            {
                /*  Invalid configuration */
                NXP_LOG_ERROR("Invalid configuration requested\n");
                emac = NULL;
            }
            else
            {
                emac->mode = mode;
                emac->speed = speed;
                emac->duplex = duplex;

                /*  Disable loop-back */
                pfe_emac_disable_loopback(emac);

                /*  Disable promiscuous mode */
                pfe_emac_disable_promisc_mode(emac);

                /*  Disable broadcast */
                pfe_emac_disable_broadcast(emac);
            }
        }
    }

    return emac;
}

/**
 * @brief       Get EMAC instance index
 * @param[in]   emac The EMAC instance
 * @return      Index (0, 1, 2, ..) or 255 if failed
 */
uint8_t pfe_emac_get_index(const pfe_emac_t *emac)
{
    uint8_t emac_idx;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        emac_idx = 255U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        emac_idx = pfe_emac_cfg_get_index(emac->emac_base_va, emac->cbus_base_va);
    }
    return emac_idx;
}

errno_t pfe_emac_bind_gpi(pfe_emac_t *emac, pfe_gpi_t *gpi)
{
    errno_t ret;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == emac) || (NULL == gpi)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        emac->gpi = gpi;
        ret = EOK;
    }

    return ret;
}

pfe_gpi_t *pfe_emac_get_gpi(const pfe_emac_t *emac)
{
    return emac->gpi;
}

/**
 * @brief       Enable the EMAC
 * @details     Data transmission/reception is possible after this call
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_enable(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_enable(emac->emac_base_va, TRUE);
    }
}

/**
 * @brief       Disable the EMAC
 * @details     No data transmission/reception is possible after this call
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_disable(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_enable(emac->emac_base_va, FALSE);
    }
}

/**
 * @brief       Enable timestamping
 * @param[in]   emac The EMAC instance
 * @param[in]   i_clk_hz Input reference clock frequency (Hz) when internal timer is
 *                     used. The timer ticks with 1/clk_hz period. If zero then external
 *                     clock reference is used.
 * @param[in]   o_clk_hz Desired output clock frequency. This one will be used to
 *                       increment IEEE1588 system time. Directly impacts the timer
 *                       accuracy and must be less than i_clk_hz. If zero then external
 *                       clock reference is used.
 */
errno_t pfe_emac_enable_ts(pfe_emac_t *emac, uint32_t i_clk_hz, uint32_t o_clk_hz)
{
    errno_t ret = EOK;
    bool_t is_owner = FALSE;
    bool_t eclk = (i_clk_hz == 0U) || (o_clk_hz == 0U);

    if (!eclk && (i_clk_hz <= o_clk_hz))
    {
        NXP_LOG_ERROR("Invalid clock configuration\n");
        ret = EINVAL;
    }
    else
    {
        ret = pfe_emac_local_is_timer_owner(emac, &is_owner);

        if ((EOK == ret) && (TRUE == is_owner))
        {
            emac->i_clk_hz = i_clk_hz;
            emac->o_clk_hz = o_clk_hz;
            oal_mutex_lock(PFE_EMAC_TS_MUTEX_00);
            ret = pfe_emac_cfg_enable_ts(emac->emac_base_va, eclk, i_clk_hz, o_clk_hz);
            oal_mutex_unlock(PFE_EMAC_TS_MUTEX_00);
        }
        else
        {
            ret = EPERM;
        }
    }
    return ret;
}

/**
 * @brief       Adjust timestamping clock frequency to compensate drift
 * @param[in]   emac The EMAC instance
 * @param[in]   ppb Frequency change in [ppb]
 * @param[in]   pos The ppb sign. If TRUE then the value is positive, else it is negative
 */
errno_t pfe_emac_set_ts_freq_adjustment(pfe_emac_t *emac, uint32_t ppb, bool_t sgn)
{
    errno_t ret = EOK;
    bool_t is_owner = FALSE;

    ret = pfe_emac_local_is_timer_owner(emac, &is_owner);

    if ((EOK == ret) && (TRUE == is_owner))
    {
        oal_mutex_lock(PFE_EMAC_TS_MUTEX_01);
        emac->adj_ppb = ppb;
        emac->adj_sign = sgn;
        ret = pfe_emac_cfg_adjust_ts_freq(emac->emac_base_va, emac->i_clk_hz, emac->o_clk_hz, ppb, sgn);
        oal_mutex_unlock(PFE_EMAC_TS_MUTEX_01);
    }
    else
    {
        ret = EPERM;
    }

    return ret;
}

/**
 * @brief           Get current adjustment value
 * @param[in]       emac The EMAC instance
 * @param[in,out]   ppb Pointer where the current adjustment value in ppb shall be written
 * @param[in,out]   sgn Pointer where the sign flag shall be written (TRUE means that
 *                  the 'ppb' is positive, FALSE means it is nagative)
 * @return          EOK if success, error code otherwise
 */
errno_t pfe_emac_get_ts_freq_adjustment(pfe_emac_t *emac, uint32_t *ppb, bool_t *sgn)
{
    errno_t ret = EOK;
    
    if ((NULL == ppb) || (NULL == sgn))
    {
        ret = EINVAL;
    }
    else
    {
        *ppb = emac->adj_ppb;
        *sgn = emac->adj_sign;
        ret = EOK;
    }
    return ret;
}

/**
 * @brief           Get current time
 * @param[in]       emac THe EMAC instance
 * @param[in,out]   sec Pointer where seconds value shall be written
 * @param[in,out]   nsec Pointer where nano-seconds value shall be written
 * @param[in,out]   sec_hi Pointer where higher-word-seconds value shall be written
 * @return          EOK if success, error code otherwise
 */
errno_t pfe_emac_get_ts_time(pfe_emac_t *emac, uint32_t *sec, uint32_t *nsec, uint16_t *sec_hi)
{
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if ((NULL == sec) || (NULL == nsec) || (NULL == sec_hi))
        {
            ret = EINVAL;
        }
        else
        {
            pfe_emac_cfg_get_ts_time(emac->emac_base_va, sec, nsec, sec_hi);
            ret = EOK;
        }
    }

    return ret;
}

/**
 * @brief       Adjust current time
 * @details     Current timer value will be adjusted by adding or subtracting the
 *              desired value.
 * @param[in]   emac The EMAC instance
 * @param[in]   sec Seconds
 * @param[in]   nsec NanoSeconds
 * @param[in]   sgn Sign of the adjustment. If TRUE then the adjustment will be positive
 *                  ('sec' and 'nsec' will be added to the current time. If FALSE then the
 *                  adjustment will be negative ('sec' and 'nsec' will be subtracted from
 *                  the current time).
 */
errno_t pfe_emac_adjust_ts_time(pfe_emac_t *emac, uint32_t sec, uint32_t nsec, bool_t sgn)
{
    errno_t ret = EOK;
    bool_t is_owner = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {

        ret = pfe_emac_local_is_timer_owner(emac, &is_owner);

        if ((EOK == ret) && (TRUE == is_owner))
        {
            oal_mutex_lock(PFE_EMAC_TS_MUTEX_02);
            ret = pfe_emac_cfg_adjust_ts_time(emac->emac_base_va, sec, nsec, sgn);
            oal_mutex_unlock(PFE_EMAC_TS_MUTEX_02);
        }
        else
        {
            ret = EPERM;
        }
    }

    return ret;
}

/**
 * @brief       Set current time
 * @details     Funcion will set new system time. Current timer value
 *              will be overwritten with the desired value.
 * @param[in]   emac The EMAC instance
 * @param[in]   sec New seconds value
 * @param[in]   nsec New nano-seconds value
 * @param[in]   sec_hi New higher-word-seconds value
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_emac_set_ts_time(pfe_emac_t *emac, uint32_t sec, uint32_t nsec, uint16_t sec_hi)
{
    errno_t ret = EOK;
    bool_t is_owner = FALSE;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_emac_local_is_timer_owner(emac, &is_owner);

        if ((EOK == ret) && (TRUE == is_owner))
        {
            oal_mutex_lock(PFE_EMAC_TS_MUTEX_03);
            ret = pfe_emac_cfg_set_ts_time(emac->emac_base_va, sec, nsec, sec_hi);
            oal_mutex_unlock(PFE_EMAC_TS_MUTEX_03);
        }
        else
        {
            ret = EPERM;
        }
    }

    return ret;
}

/**
 * @brief       Enable the local loop-back mode
 * @details     This function controls the EMAC internal loop-back mode
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_enable_loopback(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_loopback(emac->emac_base_va, TRUE);
    }
}

/**
 * @brief       Disable loop-back mode
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_disable_loopback(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_loopback(emac->emac_base_va, FALSE);
    }
}

/**
 * @brief       Enable promiscuous mode
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_enable_promisc_mode(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_promisc_mode(emac->emac_base_va, TRUE);
    }
}

/**
 * @brief       Disable promiscuous mode
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_disable_promisc_mode(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_promisc_mode(emac->emac_base_va, FALSE);
    }
}

/**
 * @brief       Enable ALLMULTI mode
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_enable_allmulti_mode(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_allmulti_mode(emac->emac_base_va, TRUE);
    }
}

/**
 * @brief       Disable ALLMULTI mode
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_disable_allmulti_mode(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_allmulti_mode(emac->emac_base_va, FALSE);
    }
}

/**
 * @brief       Enable broadcast reception
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_enable_broadcast(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_broadcast(emac->emac_base_va, TRUE);
    }
}

/**
 * @brief       Disable broadcast reception
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_disable_broadcast(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_broadcast(emac->emac_base_va, FALSE);
    }
}

void pfe_emac_get_flow_control(const pfe_emac_t *emac, bool_t *tx_enable, bool_t *rx_enable)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac) || unlikely(NULL == tx_enable) ||
        unlikely(NULL == rx_enable))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_get_tx_flow_control(emac->emac_base_va,tx_enable);
        pfe_emac_cfg_get_rx_flow_control(emac->emac_base_va,rx_enable);
    }
}

/**
 * @brief       Enable tx flow control
 * @details     Enables PAUSE frames processing
 * @param       emac The EMAC instance
 */
void pfe_emac_enable_tx_flow_control(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_tx_flow_control(emac->emac_base_va, TRUE);
    }
}

/**
 * @brief       Disable tx flow control
 * @details     Disables PAUSE frames processing
 * @param       emac The EMAC instance
 */
void pfe_emac_disable_tx_flow_control(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_tx_flow_control (emac->emac_base_va, FALSE);
    }
}

/**
 * @brief               Enable rx flow control
 * @details             Enables PAUSE frames processing
 * @param               emac The EMAC instance
 */
void pfe_emac_enable_rx_flow_control(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_rx_flow_control(emac->emac_base_va, TRUE);
    }
}

/**
 * @brief               Disable rx flow control
 * @details             Disables PAUSE frames processing
 * @param               emac The EMAC instance
 */
void pfe_emac_disable_rx_flow_control(const pfe_emac_t *emac)
{
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        pfe_emac_cfg_set_rx_flow_control(emac->emac_base_va, FALSE);
    }
}


/**
 * @brief       Set maximum frame length
 * @param       emac The EMAC instance
 * @param       len New frame length
 * @return      EOK if success errno otherwise
 */
errno_t pfe_emac_set_max_frame_length(const pfe_emac_t *emac, uint32_t len)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_emac_cfg_set_max_frame_length(emac->emac_base_va, len);
        if (EOK != ret)
        {
            NXP_LOG_ERROR("Attempt to set unsupported frame length value\n");
        }
    }
    return ret;
}

/**
 * @brief       Get current MII mode
 * @param[in]   emac The EMAC instance
 * @return      Currently configured MII mode @see pfe_emac_mii_mode_t
 */
pfe_emac_mii_mode_t pfe_emac_get_mii_mode(const pfe_emac_t *emac)
{
    pfe_emac_mii_mode_t mii_mode;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        mii_mode = EMAC_MODE_INVALID;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        mii_mode = emac->mode;
    }
    return mii_mode;
}

/**
 * @brief       Get the EMAC link configuration
 * @param[in]   emac The EMAC instance
 * @param[out]  speed The EMAC speed configuration @see pfe_emac_speed_t
 * @param[out]  duplex The EMAC duplex configuration @see pfe_emac_duplex_t
 * @return      EOK if success
 */
errno_t pfe_emac_get_link_config(const pfe_emac_t *emac, pfe_emac_speed_t *speed, pfe_emac_duplex_t *duplex)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_emac_cfg_get_link_config(emac->emac_base_va, speed, duplex);
    }

    return ret;
}

/**
 * @brief       Get the EMAC link status
 * @param[in]   emac The EMAC instance
 * @param[out]  speed The EMAC link speed @see pfe_emac_link_speed_t
 * @param[out]  duplex The EMAC duplex status @see pfe_emac_duplex_t
 * @param[out]  link The EMAC link status
 * @return      EOK if success
 */
errno_t pfe_emac_get_link_status(const pfe_emac_t *emac, pfe_emac_link_speed_t *link_speed, pfe_emac_duplex_t *duplex, bool_t *link)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_emac_cfg_get_link_status(emac->emac_base_va, link_speed, duplex, link);
    }
    return ret;
}

/**
 * @brief       Set the EMAC link speed
 * @param[in]   emac The EMAC instance
 * @param[in]   link_speed The EMAC link speed @see pfe_emac_link_speed_t
 * @return      EOK if success
 * @details     This function can be used for runtime changes of speed (eg. after auto-negotiation).
 */
errno_t pfe_emac_set_link_speed(const pfe_emac_t *emac, pfe_emac_speed_t link_speed)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_emac_cfg_set_speed(emac->emac_base_va, link_speed);
    }

    return ret;
}

/**
 * @brief       Set the EMAC link duplex
 * @param[in]   emac The EMAC instance
 * @param[in]   duplex The EMAC duplex @see pfe_emac_duplex_t
 * @return      EOK if success
 * @details     This function can be used for runtime changes of duplex (eg. after auto-negotiation).
 */
errno_t pfe_emac_set_link_duplex(const pfe_emac_t *emac, pfe_emac_duplex_t duplex)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_emac_cfg_set_duplex(emac->emac_base_va, duplex);
    }

    return ret;
}

/**
 * @brief       Delete MAC addresses added by owner with defined type
 * @param[in]   emac The EMAC instance
 * @param[in]   crit All, Owner, Type or Owner&Type criterion
 * @param[in]   type Required type of MAC address (Broadcast, Multicast, Unicast, ANY) criterion
 * @param[in]   owner The identification of driver instance
 * @return      EOK if success
 * @return      EINVAL NULL argument received
 * @note        Must not be preempted by: pfe_emac_del_addr(), pfe_emac_add_addr(), pfe_emac_destroy()
 */
errno_t pfe_emac_flush_mac_addrs(pfe_emac_t *emac, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner)
{
    pfe_mac_db_list_entry_t entry;
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_EMAC_MUTEX_00);
        
        ret = pfe_mac_db_find_by_crit(&emac->mac_db, crit, type, owner, &entry);
        while (EOK == ret)
        {
            ret = pfe_emac_del_addr_nolock(emac, entry.addr, entry.owner);
            if (EOK == ret)
            {
                NXP_LOG_DEBUG(  "Address %02x:%02x:%02x:%02x:%02x:%02x removed from owner ID %d\n",
                                entry.addr[0],
                                entry.addr[1],
                                entry.addr[2],
                                entry.addr[3],
                                entry.addr[4],
                                entry.addr[5],
                                entry.owner);
                ret = pfe_mac_db_find_by_crit(&emac->mac_db, crit, type, owner, &entry);
            }
            else
            {
                NXP_LOG_WARNING("Can't remove MAC address within the flush function\n");
            }
        }
        
        if (ENOENT == ret)
        {
            /* It is expected to be stopped with ENOENT */
            ret = EOK;
        }
        
        oal_mutex_unlock(PFE_EMAC_MUTEX_00);
    }

    return ret;
}

/**
 * @brief       Remove MAC address from EMAC
 * @details     Address resolution will be done using exact match with the added address
 * @param[in]   emac The EMAC instance
 * @param[in]   addr The MAC address to delete
 * @param[in]   owner The identification of driver instance
 * @retval      EOK Success
 * @retval      ENOENT Address not found
 * @note        Must not be preempted by: pfe_emac_add_addr(), pfe_emac_destroy()
 */
errno_t pfe_emac_del_addr(pfe_emac_t *emac, const pfe_mac_addr_t addr, pfe_drv_id_t owner)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_EMAC_MUTEX_01);

        ret = pfe_emac_del_addr_nolock(emac, addr, owner);

        oal_mutex_unlock(PFE_EMAC_MUTEX_01);
    }

    return ret;
}

/**
 * @brief       Remove MAC address from EMAC without entering the critical section
 * @details     Address resolution will be done using exact match with the added address
 * @param[in]   emac The EMAC instance
 * @param[in]   addr The MAC address to delete
 * @param[in]   owner The identification of driver instance
 * @retval      EOK Success
 * @retval      ENOENT Address not found
 * @note        Must not be preempted by: pfe_emac_add_addr(), pfe_emac_destroy()
 */
static errno_t pfe_emac_del_addr_nolock(pfe_emac_t *emac, const pfe_mac_addr_t addr, pfe_drv_id_t owner)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /* Remove entry from database */
        ret = pfe_mac_db_del_addr(&emac->mac_db, addr, owner);
        
        if (EOK == ret)
        {
            if (FALSE == pfe_emac_mac_in_db(emac, addr))
            {
                /* The address is not in db any more, it must removed from EMAC filter */
                
                /* Try to find address in individual address slot */
                uint8_t slot = pfe_emac_mac_slot_idx(emac, addr);
                
                if (slot < EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT)
                {
                    /* Address was found in slot, delete this entry by writing zero filled address */
                    pfe_mac_addr_t zero_address;
                    (void)autolibc_memset(zero_address, 0, sizeof(pfe_mac_addr_t));
                    pfe_emac_cfg_write_addr_slot(emac->emac_base_va, zero_address, slot);
                    
                    /*  Mark the slot as unused */
                    emac->mac_addr_slots &= ~(1U << slot);
                }
                else
                {
                    /* Address exist in hash table, check whether to removed hash idx or not */
                    if (FALSE == pfe_emac_mac_hash_col(emac, addr))
                    {
                        /* There is no other address in db with same hash idx, clear hash idx */
                        uint32_t hash = pfe_emac_cfg_get_hash(emac->emac_base_va, addr);
                        pfe_emac_cfg_set_hash_group(emac->emac_base_va, hash, FALSE);
                    }
                }
            }
        }
    }

    return ret;
}

/**
 * @brief       Assign an individual MAC address to EMAC
 * @param[in]   emac The EMAC instance
 * @param[in]   addr The MAC address to add
 * @retval      EOK Success
 * @retval      EINVAL NULL pointer or broadcast MAC provided
 * @retval      ENOMEM Not enough memory
 * @retval      EEXIST Address already added
 * @note        Must not be preempted by: pfe_emac_del_addr(), pfe_emac_destroy()
 */
errno_t pfe_emac_add_addr(pfe_emac_t *emac, const pfe_mac_addr_t addr, pfe_drv_id_t owner)
{
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (pfe_emac_is_broad(addr))
        {
            NXP_LOG_ERROR("broadcast MAC received\n");
            ret = EINVAL;
        }
        else
        {
            oal_mutex_lock(PFE_EMAC_MUTEX_02);

            /* Store address into EMAC's database */
            ret = pfe_mac_db_add_addr(&emac->mac_db, addr, owner);
            
            if (EOK == ret)
            {
                /* Check if the address (not owner related) already exists in slot */
                uint32_t slot = pfe_emac_mac_slot_idx(emac, addr);
                if (EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT == slot)
                {
                    /* Address is not in slot, get free slot or add to hash table */
                    
                    /*  Try to get free individual address slot */
                    for (slot=0U; slot<EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT; slot++)
                    {
                        if (0U == (emac->mac_addr_slots & (1U << slot)))
                        {
                            /*  Found */
                            break;
                        }
                    }

                    /* Slots are full, add hash of the address into the hash table */
                    if (EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT == slot)
                    {
                        /*  Get the hash */
                        uint32_t hash = pfe_emac_cfg_get_hash(emac->emac_base_va, addr);

                        /*  Configure the HW */
                        pfe_emac_cfg_set_hash_group(emac->emac_base_va, hash, TRUE);
                    }
                    /* There is free address slot, use it */
                    else
                    {
                        /*  Mark the slot as used */
                        emac->mac_addr_slots |= (1U << slot);

                        /*  Write the address to HW as individual address */
                        pfe_emac_cfg_write_addr_slot(emac->emac_base_va, addr, (uint8_t)slot);
                    }
                }
            }
            oal_mutex_unlock(PFE_EMAC_MUTEX_02);
        }
    }

    return ret;
}


/**
 * @brief       Destroy MAC instance
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_destroy(pfe_emac_t *emac)
{
    if (NULL != emac)
    {
        pfe_mac_addr_t zero_address;
        (void)autolibc_memset(zero_address, 0, sizeof(pfe_mac_addr_t));


        /* Clear MAC db */
        (void)autolibc_memset(&emac->mac_db, 0, sizeof(pfe_mac_db_t));

        /* Clear MAC exact match slots */
        for (uint8_t slot = 0U; slot < EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT; slot++)
        {
            /* Delete this entry by writing zero filled address */
            pfe_emac_cfg_write_addr_slot(emac->emac_base_va, zero_address, slot);

            /*  Mark the slot as unused */
            emac->mac_addr_slots &= ~(1U << slot);
        }

        /* Clear hash table */
        pfe_emac_cfg_clear_hash_table(emac->emac_base_va);

        /*  Disable traffic */
        pfe_emac_disable(emac);

        /*  Disable TS */
        pfe_emac_cfg_disable_ts(emac->emac_base_va);
    }
}

/**
 * @brief       Lock access to MDIO resource
 * @details     Once locked, only lock owner can perform MDIO accesses
 * @param[in]   emac The EMAC instance
 * @param[out]  key Pointer to memory where the key to be used for access to locked MDIO and for
 *                  unlock shall be stored
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_emac_mdio_lock(pfe_emac_t *emac, uint32_t *key)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == emac) || (NULL == key)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        oal_mutex_lock(PFE_EMAC_MUTEX_03);

        if (TRUE == emac->mdio_locked)
        {
            ret = EPERM;
        }
        else
        {
            /*  Perform lock + generate and store access key */
            emac->mdio_locked = TRUE;
            emac->mdio_key = key_seed;
            key_seed++;
            *key = emac->mdio_key;
            ret = EOK;
        }

        oal_mutex_unlock(PFE_EMAC_MUTEX_03);
    }

    return ret;
}

/**
 * @brief       Unlock access to MDIO resource
 * @details     Once locked, only lock owner can perform MDIO accesses
 * @param[in]   emac The EMAC instance
 * @param[in]   key The key
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_emac_mdio_unlock(pfe_emac_t *emac, uint32_t key)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (TRUE == emac->mdio_locked)
        {
            if (key == emac->mdio_key)
            {
                emac->mdio_locked = FALSE;
                ret = EOK;
            }
            else
            {
                ret = EPERM;
            }
        }
        else
        {
            ret = ENOLCK;
        }
    }

    return ret;
}

/**
 * @brief       Read value from the MDIO bus using Clause 22
 * @param[in]   emac The EMAC instance
 * @param[in]   pa PHY address
 * @param[in]   ra Register address
 * @param[out]  val If success the the read value is written here
 * @param[in]   key Access key in case the resource is locked
 * @retval      EOK Success
 */
errno_t pfe_emac_mdio_read22(pfe_emac_t *emac, uint8_t pa, uint8_t ra, uint16_t *val, uint32_t key)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == emac) || (NULL == val)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (TRUE == emac->mdio_locked)
        {
            /*  Locked. Check key. */
            if (key == emac->mdio_key)
            {
                ret = pfe_emac_cfg_mdio_read22(emac->emac_base_va, pa, ra, val);
            }
            else
            {
                ret = EPERM;
            }
        }
        else
        {
            /*  Unlocked. No check required. */
            ret = pfe_emac_cfg_mdio_read22(emac->emac_base_va, pa, ra, val);
        }
    }

    return ret;
}

/**
 * @brief       Write value to the MDIO bus using Clause 22
 * @param[in]   emac The EMAC instance
 * @param[in]   pa PHY address
 * @param[in]   ra Register address
 * @param[in]   val Value to be written
 * @param[in]   key Access key in case the resource is locked
 * @retval      EOK Success
 */
errno_t pfe_emac_mdio_write22(pfe_emac_t *emac, uint8_t pa, uint8_t ra, uint16_t val, uint32_t key)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (TRUE == emac->mdio_locked)
        {
            /*  Locked. Check key. */
            if (key == emac->mdio_key)
            {
                ret = pfe_emac_cfg_mdio_write22(emac->emac_base_va, pa, ra, val);
            }
            else
            {
                ret = EPERM;
            }
        }
        else
        {
            /*  Unlocked. No check required. */
            ret = pfe_emac_cfg_mdio_write22(emac->emac_base_va, pa, ra, val);
        }
    }
    return ret;
}

/**
 * @brief       Read value from the MDIO bus using Clause 45
 * @param[in]   emac The EMAC instance
 * @param[in]   pa PHY address
 * @param[in]   dev Device address
 * @param[in]   ra Register address
 * @param[out]  val If success the the read value is written here
 * @param[in]   key Access key in case the resource is locked
 * @retval      EOK Success
 */
errno_t pfe_emac_mdio_read45(pfe_emac_t *emac, uint8_t pa, uint8_t dev, uint16_t ra, uint16_t *val, uint32_t key)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == emac) || (NULL == val)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (TRUE == emac->mdio_locked)
        {
            /*  Locked. Check key. */
            if (key == emac->mdio_key)
            {
                ret = pfe_emac_cfg_mdio_read45(emac->emac_base_va, pa, dev, ra, val);
            }
            else
            {
                ret = EPERM;
            }
        }
        else
        {
            /*  Unlocked. No check required. */
            ret = pfe_emac_cfg_mdio_read45(emac->emac_base_va, pa, dev, ra, val);
        }
    }

    return ret;
}

/**
 * @brief       Write value to the MDIO bus using Clause 45
 * @param[in]   emac The EMAC instance
 * @param[in]   pa PHY address
 * @param[in]   dev Device address
 * @param[in]   ra Register address
 * @param[in]   val Value to be written
 * @param[in]   key Access key in case the resource is locked
 * @retval      EOK Success
 */
errno_t pfe_emac_mdio_write45(pfe_emac_t *emac, uint8_t pa, uint8_t dev, uint16_t ra, uint16_t val, uint32_t key)
{
    errno_t ret;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (TRUE == emac->mdio_locked)
        {
            /*  Locked. Check key. */
            if (key == emac->mdio_key)
            {
                ret = pfe_emac_cfg_mdio_write45(emac->emac_base_va, pa, dev, ra, val);
            }
            else
            {
                ret = EPERM;
            }
        }
        else
        {
            /*  Unlocked. No check required. */
            ret = pfe_emac_cfg_mdio_write45(emac->emac_base_va, pa, dev, ra, val);
        }
    }

    return ret;
}

/**
 * @brief       Get number of received packets
 * @param[in]   emac The EMAC instance
 * @return      Number of received packets
 */
uint32_t pfe_emac_get_rx_cnt(const pfe_emac_t *emac)
{
    uint32_t rx_cnt;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        rx_cnt = 0xFFFFFFFFU;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        rx_cnt = pfe_emac_cfg_get_rx_cnt(emac->emac_base_va);
    }
    return rx_cnt;
}

/**
 * @brief       Get number of transmitted packets
 * @param[in]   emac The EMAC instance
 * @return      Number of transmitted packets
 */
uint32_t pfe_emac_get_tx_cnt(const pfe_emac_t *emac)
{
    uint32_t tx_cnt;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        tx_cnt = 0xFFFFFFFFU;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        tx_cnt = pfe_emac_cfg_get_tx_cnt(emac->emac_base_va);
    }
    return tx_cnt;
}

#if defined(PFE_CFG_TEXT_STATS)
/**
 * @brief       Return EMAC runtime statistics in text form
 * @details     Function writes formatted text into given buffer.
 * @param[in]   gpi         The EMAC instance
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   size        Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 */
uint32_t pfe_emac_get_text_statistics(const pfe_emac_t *emac, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint32_t len = 0U;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        len += pfe_emac_cfg_get_text_stat(emac->emac_base_va, buf + len, buf_len - len, verb_level);
    }
    return len;
}
#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Get EMAC statistic in numeric form
 * @details     This is a HW-specific function providing single statistic
 *              value from the EMAC block.
 * @param[in]   emac        The EMAC instance
 * @param[in]   stat_id     ID of required statistic (offset of register)
 * @return      Value of requested statistic
 */
uint32_t pfe_emac_get_stat_value(const pfe_emac_t *emac, uint32_t stat_id)
{
    uint32_t stat_value;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        stat_value = 0xFFFFFFFFU;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        stat_value = pfe_emac_cfg_get_stat_value(emac->emac_base_va, stat_id);
    }
    return stat_value;
}

/**
 * @brief       EMAC ISR
 * @param[in]   emac The EMAC instance
 */
errno_t pfe_emac_isr(pfe_emac_t *emac)
{
    errno_t ret = EOK;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        ret = pfe_emac_cfg_isr(emac->emac_base_va, emac->cbus_base_va);
    }

    return ret;
}

/**
 * @brief       Mask EMAC interrupts
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_irq_mask(pfe_emac_t *emac)
{
    (void)emac;
}

/**
 * @brief       Unmask EMAC interrupts
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_irq_unmask(pfe_emac_t *emac)
{
    (void)emac;
}

/**
 * @brief       Set the driver instance is the timer owner of EMAC
 * @param[in]   emac The EMAC instance
 * @param[in]   drv_id The identification of driver instance
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_emac_set_timer_ownership(pfe_emac_t *emac, pfe_drv_id_t drv_id)
{
    errno_t ret = EOK;
    bool_t has_owner = FALSE;
    pfe_drv_id_t drv_id_owner = PFE_PHY_IF_ID_INVALID;
    pfe_platform_t *platform = NULL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        platform = pfe_platform_get_instance();
        if (NULL_PTR == platform)
        {
            ret = EINVAL;
            NXP_LOG_ERROR("Could not get PFE platform instance\n");
        }
        else
        {
            oal_mutex_lock(PFE_EMAC_TS_MUTEX_04);
            ret = pfe_emac_check_timer_ownership(emac, &has_owner, &drv_id_owner);
            if ((EOK == ret) && (FALSE == has_owner)) /* check no owner yet*/
            {
                ret = pfe_hif_chnl_set_emac_timer_ownership(pfe_get_hif_base_addr(platform), drv_id, emac->emac_id, TRUE);
            }
            else
            {
                ret = EPERM;
            }
            oal_mutex_unlock(PFE_EMAC_TS_MUTEX_04);
        }
    }

    return ret;
}

/**
 * @brief       Check if any driver instance associated with HIF instances is the timer owner of EMAC
 * @param[in]   emac The EMAC instance
 * @param[out]  has_owner The ownership value shall be written here.
 *              TRUE if having another driver instance is the timer owner of EMAC. FALSE otherwise
 * @param[out]  drv_id The driver instance is currently the owner of EMAC
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_emac_check_timer_ownership(pfe_emac_t *emac, bool_t *has_owner, pfe_drv_id_t *drv_id)
{
    errno_t ret = EOK;
    pfe_platform_t *platform = NULL;
    pfe_ct_phy_if_id_t chnl_id = PFE_PHY_IF_ID_INVALID;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == emac) || (NULL == has_owner)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        *has_owner = FALSE;

        platform = pfe_platform_get_instance();
        if (NULL_PTR == platform)
        {
            ret = EINVAL;
            NXP_LOG_ERROR("Could not get PFE platform instance\n");
        }
        else
        {
            for (chnl_id = PFE_PHY_IF_ID_HIF_NOCPY; chnl_id <= PFE_PHY_IF_ID_HIF3; chnl_id++)
            {
                if (PFE_PHY_IF_ID_UTIL == chnl_id)
                {
                    continue;
                }

                *has_owner = pfe_hif_chnl_get_emac_timer_ownership(pfe_get_hif_base_addr(platform), chnl_id, emac->emac_id);
                ret = EOK;

                if (TRUE == (*has_owner))
                {
                    *drv_id = chnl_id;
                    break;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief       Clear timer ownership status for the driver instance
 * @param[in]   emac The EMAC instance
 * @param[in]   drv_id The identification of driver instance
 * @return      EOK if success, error code otherwise
 */
errno_t pfe_emac_clear_timer_ownership(pfe_emac_t *emac, pfe_drv_id_t drv_id)
{
    errno_t ret = EOK;
    pfe_platform_t *platform = NULL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        platform = pfe_platform_get_instance();
        if (NULL_PTR == platform)
        {
            ret = EINVAL;
            NXP_LOG_ERROR("Could not get PFE platform instance\n");
        }
        else
        {
            oal_mutex_lock(PFE_EMAC_TS_MUTEX_05);
            if (TRUE == pfe_hif_chnl_get_emac_timer_ownership(pfe_get_hif_base_addr(platform), drv_id, emac->emac_id)) /* check if specified PFE instance is the owner */
            {
                ret = pfe_hif_chnl_set_emac_timer_ownership(pfe_get_hif_base_addr(platform), drv_id, emac->emac_id, FALSE);
            }
            else
            {
                ret = EPERM;
            }
            oal_mutex_unlock(PFE_EMAC_TS_MUTEX_05);
        }
    }

    return ret;
}

/**
 * @brief       Check if the driver instance associated with the local HIF is the timer owner of EMAC
 * @param[in]   emac The EMAC instance
 * @param[out]  is_owner The timer ownership status shall be written here
 * @return      EOK if sucess, error code otherwise
 */
errno_t pfe_emac_local_is_timer_owner(pfe_emac_t *emac, bool_t *is_owner)
{
    errno_t ret = EOK;
    pfe_platform_t *platform = NULL;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == emac) || (NULL == is_owner)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        platform = pfe_platform_get_instance();
        if (NULL_PTR == platform)
        {
            ret = EINVAL;
            NXP_LOG_ERROR("Could not get PFE platform instance\n");
        }
        else
        {
            *is_owner = pfe_hif_chnl_get_emac_timer_ownership(pfe_get_hif_base_addr(platform), PFE_CFG_LOCAL_IF, emac->emac_id);
            ret = EOK;
        }
    }

    return ret;
}

#ifdef PFE_CFG_EMAC0_PPS0_ENABLE
/**
 * @brief       Re-synchronize PPS output
 * @details     Re-alligns PPS output rising edge to system time seconds update event
 *              Disables PPS output immediately and re-enable at the next time that
 *              is an integer multiple of the PPS period
 * @param[in]   emac The EMAC instance
 */
void pfe_emac_pps0_resync(pfe_emac_t *emac)
{
    uint32_t pps_restart_sec;
    uint32_t sec;
    uint32_t nsec;
    uint16_t sec_hi;

    pfe_emac_cfg_get_ts_time(emac->emac_base_va, &sec, &nsec, &sec_hi);

    do {
#if PFE_CFG_EMAC0_PPS0_PERIOD_SEC <= 1U
        pps_restart_sec = sec + 1u;
#else
        /* restart at the nearest integer multiple of the PPS period */
        pps_restart_sec = sec + (PFE_CFG_EMAC0_PPS0_PERIOD_SEC - (sec % PFE_CFG_EMAC0_PPS0_PERIOD_SEC));
#endif
        pfe_emac_cfg_pps0_set_target_time(emac->emac_base_va, pps_restart_sec, 0U);

        pfe_emac_cfg_pps_cmd(emac->emac_base_va, EMAC_CFG_PPS_PPSCMD_STOP_IMMEDIATELY);
        pfe_emac_cfg_pps_cmd(emac->emac_base_va, EMAC_CFG_PPS_PPSCMD_START_PULSE_TRAIN);

        pfe_emac_cfg_get_ts_time(emac->emac_base_va, &sec, &nsec, &sec_hi);
    } while(sec == pps_restart_sec);
}
#endif

/**
 * @brief       Configure PPS output
 * @details     PPS output is available on EMAC0 only. Flexible PPS Output Mode is used for signal generation.
 * @param[in]   emac The EMAC instance
 * @param[in]   enable Enable/Disable PPS output signal generation
 * @param[in]   period Period width (in units of PPS counter ticks)
 * @param[in]   pulse_width Pulse width (in units of PPS counter ticks)
 * @return      EOK if sucess, error code otherwise
 */
errno_t pfe_emac_pps0_configure(pfe_emac_t *emac, bool_t enable, uint32_t period, uint32_t pulse_width)
{
    errno_t ret = EINVAL;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_PTR == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        if (0U == pfe_emac_get_index(emac))
        {
            if (enable)
            {
                pfe_emac_cfg_pps0_set_period(emac->emac_base_va, period);
                pfe_emac_cfg_pps0_set_pulse_width(emac->emac_base_va, pulse_width);
                pfe_emac_cfg_pps0_configure(emac->emac_base_va,
                                            FALSE,
                                            EMAC_CFG_PPS_TRGTMODSEL_ONLY_ST,
                                            TRUE);
            }
            else
            {
                pfe_emac_cfg_pps0_configure(emac->emac_base_va, FALSE, 0U, FALSE);
            }
            ret = EOK; 
        }
        else
        {
            NXP_LOG_ERROR("PPS output not available on given EMAC instance");
        }
    }
    
    return ret;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_PFE_MASTER */
