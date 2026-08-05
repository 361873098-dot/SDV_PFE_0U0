/* =========================================================================
 *  This code (or certain portions of it) is released for use under license
 *  from Imagination Technologies Limited.
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

#include "pfe_cfg.h"
#include "hal.h"
#include "pfe_emac.h"
#ifdef PFE_CFG_PFE_SLAVE
#include "pfe_platform_cfg.h"
#include "pfe_cbus.h"
#include "pfe_idex.h" /* The RPC provider */
#include "pfe_platform_rpc.h" /* The RPC codes and data structures */
#include "pfe_platform.h"

#define ETH_43_PFE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"
static pfe_emac_t emac_instance[PFE_EMAC_INSTANCES];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_43_PFE_MemMap.h"

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

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
            emac->mode = mode;
            emac->speed = speed;
            emac->duplex = duplex;
            emac->emac_id = (pfe_ct_phy_if_id_t)pfe_emac_get_index(emac);
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
        switch (emac->emac_base_offset)
        {
            case CBUS_EMAC1_BASE_ADDR:
            {
                emac_idx = 0U;
                break;
            }

            case CBUS_EMAC2_BASE_ADDR:
            {
                emac_idx = 1U;
                break;
            }

            case CBUS_EMAC3_BASE_ADDR:
            {
                emac_idx = 2U;
                break;
            }

            default:
            {
                emac_idx = 255U;
                break;
            }
        }
    }

    return emac_idx;
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
    uint8_t emac_index;
    pfe_platform_rpc_mdio_proxy_arg_t rpc_arg;
    pfe_platform_rpc_mdio_proxy_ret_t rpc_ret = {0U};

    (void)autolibc_memset(&rpc_arg, 0, sizeof(pfe_platform_rpc_mdio_proxy_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == emac) || (NULL == val)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        emac_index = pfe_emac_get_index(emac);
        if (2U < emac_index)
        {
            NXP_LOG_ERROR("Invalid EMAC id: %d\n", emac_index);
            ret = EINVAL;
        }
        else
        {
            rpc_arg.emac_id = emac_index;
            rpc_arg.op = PFE_PLATFORM_RPC_MDIO_OP_READ_CL22;
            rpc_arg.pa = pa;
            rpc_arg.ra = ra;

            if (TRUE == emac->mdio_locked)
            {
                /*  Locked. Check key. */
                if (key == emac->mdio_key)
                {
                    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_MDIO_PROXY, &rpc_arg, (uint16_t)sizeof(rpc_arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
                }
                else
                {
                    ret = EPERM;
                }
            }
            else
            {
                /*  Unlocked. No check required. */
                ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_MDIO_PROXY, &rpc_arg, (uint16_t)sizeof(rpc_arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
            }

            if (EOK == ret)
            {
                *val = rpc_ret.val;
            }
            else
            {
                *val = 0xFFFFU;
            }
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
    uint8_t emac_index;
    pfe_platform_rpc_mdio_proxy_arg_t rpc_arg;

    (void)autolibc_memset(&rpc_arg, 0, sizeof(pfe_platform_rpc_mdio_proxy_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        emac_index = pfe_emac_get_index(emac);
        if (2U < emac_index)
        {
            NXP_LOG_ERROR("Invalid EMAC id: %d\n", emac_index);
            ret = EINVAL;
        }
        else
        {
            rpc_arg.emac_id = emac_index;
            rpc_arg.op = PFE_PLATFORM_RPC_MDIO_OP_WRITE_CL22;
            rpc_arg.pa = pa;
            rpc_arg.ra = ra;
            rpc_arg.val = val;

            if (TRUE == emac->mdio_locked)
            {
                /*  Locked. Check key. */
                if (key == emac->mdio_key)
                {
                    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_MDIO_PROXY, &rpc_arg, (uint16_t)sizeof(rpc_arg), NULL, 0U);
                }
                else
                {
                    ret = EPERM;
                }
            }
            else
            {
                /*  Unlocked. No check required. */
                ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_MDIO_PROXY, &rpc_arg, (uint16_t)sizeof(rpc_arg), NULL, 0U);
            }
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
    uint8_t emac_index;
    pfe_platform_rpc_mdio_proxy_arg_t rpc_arg;
    pfe_platform_rpc_mdio_proxy_ret_t rpc_ret = {0U};

    (void)autolibc_memset(&rpc_arg, 0, sizeof(pfe_platform_rpc_mdio_proxy_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely((NULL == emac) || (NULL == val)))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        emac_index = pfe_emac_get_index(emac);
        if (2U < emac_index)
        {
            NXP_LOG_ERROR("Invalid EMAC id: %d\n", emac_index);
            ret = EINVAL;
        }
        else
        {
            rpc_arg.emac_id = emac_index;
            rpc_arg.op = PFE_PLATFORM_RPC_MDIO_OP_READ_CL45;
            rpc_arg.pa = pa;
            rpc_arg.dev = dev;
            rpc_arg.ra = ra;

            if (TRUE == emac->mdio_locked)
            {
                /*  Locked. Check key. */
                if (key == emac->mdio_key)
                {
                    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_MDIO_PROXY, &rpc_arg, (uint16_t)sizeof(rpc_arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
                }
                else
                {
                    ret = EPERM;
                }
            }
            else
            {
                /*  Unlocked. No check required. */
                ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_MDIO_PROXY, &rpc_arg, (uint16_t)sizeof(rpc_arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
            }

            if (EOK == ret)
            {
                *val = rpc_ret.val;
            }
            else
            {
                *val = 0xFFFFU;
            }
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
    uint8_t emac_index;
    pfe_platform_rpc_mdio_proxy_arg_t rpc_arg;

    (void)autolibc_memset(&rpc_arg, 0, sizeof(pfe_platform_rpc_mdio_proxy_arg_t));

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        ret = EINVAL;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        emac_index = pfe_emac_get_index(emac);
        if (2U < emac_index)
        {
            NXP_LOG_ERROR("Invalid EMAC id: %d\n", emac_index);
            ret = EINVAL;
        }
        else
        {
            rpc_arg.emac_id = emac_index;
            rpc_arg.op = PFE_PLATFORM_RPC_MDIO_OP_WRITE_CL45;
            rpc_arg.pa = pa;
            rpc_arg.dev = dev;
            rpc_arg.ra = ra;
            rpc_arg.val = val;

            if (TRUE == emac->mdio_locked)
            {
                /*  Locked. Check key. */
                if (key == emac->mdio_key)
                {
                    ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_MDIO_PROXY, &rpc_arg, (uint16_t)sizeof(rpc_arg), NULL, 0U);
                }
                else
                {
                    ret = EPERM;
                }
            }
            else
            {
                /*  Unlocked. No check required. */
                ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_MDIO_PROXY, &rpc_arg, (uint16_t)sizeof(rpc_arg), NULL, 0U);
            }
        }
    }

    return ret;
}

/**
 * @brief       Adjust timestamping clock frequency to compensate drift
 * @param[in]   emac The EMAC instance
 * @param[in]   ppb Frequency change in [ppb]
 * @param[in]   sgn The ppb sign. If TRUE then the value is positive, else it is negative
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
 * @brief       Check if the driver instance associated with the local HIF is the timer owner of EMAC
 * @param[in]   emac The EMAC instance
 * @param[out]  is_owner The timer ownership status shall be written here
 * @return      EOK if sucess, error code otherwise
 */
errno_t pfe_emac_local_is_timer_owner(pfe_emac_t *emac, bool_t *is_owner)
{
    errno_t ret = EOK;
    pfe_hif_chnl_t *local_hif_chnl = NULL;
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
            local_hif_chnl = pfe_hif_get_channel(platform->hif, pfe_hif_chnl_from_phy_id(PFE_CFG_LOCAL_IF));
            if (NULL_PTR == local_hif_chnl)
            {
                ret = EINVAL;
                NXP_LOG_ERROR("Can't get HIF channel instance\n");
            }
            else
            {
                *is_owner = pfe_hif_chnl_get_emac_timer_ownership(local_hif_chnl->cbus_base_va, PFE_CFG_LOCAL_IF, emac->emac_id);
                ret = EOK;
            }
        }
    }

    return ret;
}

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
    uint32_t stat_value = 0U;
#if (FALSE == PFE_CFG_SLAVE_READ_EMAC_STAT_CNT_DIRECT)
    errno_t ret;
    pfe_platform_rpc_pfe_phy_if_get_stat_value_arg_t arg = {.phy_if_id = PFE_PHY_IF_ID_EMAC0, .stat_id = 0U};
    pfe_platform_rpc_pfe_phy_if_get_stat_value_ret_t rpc_ret = {0U};
    uint8_t emac_id;
#endif /* PFE_CFG_SLAVE_READ_EMAC_STAT_CNT_DIRECT */

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL == emac))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        stat_value = 0xFFFFFFFFU;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
#if (TRUE == PFE_CFG_SLAVE_READ_EMAC_STAT_CNT_DIRECT)
        stat_value = pfe_emac_cfg_get_stat_value(emac->emac_base_va, stat_id);
#else
        emac_id = pfe_emac_get_index(emac);
        if (2U < emac_id)
        {
            NXP_LOG_ERROR("Invalid EMAC id: %d\n", emac_id);
            stat_value = 0xFFFFFFFFU;
        }
        else
        {
            /*  Ask the master driver to get statistic values */
            arg.phy_if_id = (pfe_ct_phy_if_id_t)emac_id;
            arg.stat_id = stat_id;
            ret = pfe_idex_master_rpc((uint32_t)PFE_PLATFORM_RPC_PFE_PHY_IF_GET_STAT_VALUE, &arg, (uint16_t)sizeof(arg), &rpc_ret, (uint16_t)sizeof(rpc_ret));
            if (EOK != ret)
            {
                NXP_LOG_DEBUG("PFE_PLATFORM_RPC_PFE_PHY_IF_GET_STAT_VALUE failed: %d\n", ret);
            }
            else
            {
                stat_value = rpc_ret.stat_val;
            }
        }
#endif /* PFE_CFG_SLAVE_READ_EMAC_STAT_CNT_DIRECT */
    }
    return stat_value;
}

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */
#endif /* PFE_CFG_PFE_SLAVE */

