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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440

#include "pfe_cfg.h"
#include "oal.h"
#include "hal.h"
#include "pfe_hm.h"
#include "pfe_cbus.h"
#include "pfe_emac_csr.h"
#include "pfe_feature_mgr.h"
#include "pfe_emac.h"
#include "Eth_43_PFE_Cfg.h"

#if defined(PFE_CFG_TEXT_STATS)

#define ETH_43_PFE_START_SEC_CONST_32
#include "Eth_43_PFE_MemMap.h"

/* Mode conversion table */
/* usage scope: phy_mode_to_str */
static const char_t * const phy_mode[] =
{
        "GMII_MII",
        "RGMII",
        "SGMII",
        "TBI",
        "RMII",
        "RTBI",
        "SMII",
        "RevMII",
        "INVALID",
};

#define ETH_43_PFE_STOP_SEC_CONST_32
#include "Eth_43_PFE_MemMap.h"

#endif /* defined(PFE_CFG_TEXT_STATS) */

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#define EMAC_ERR_SRC_NUMBER                4U
#define EMAC_ERR_SRC_INDEX_UNCORRECTABLE   0U
#define EMAC_ERR_SRC_INDEX_ADDRESS         1U
#define EMAC_ERR_SRC_INDEX_PARITY          2U
#define EMAC_ERR_SRC_INDEX_WDT             3U
#define EMAC_ERR_SRC_INDEX_INVALID         255U

#define CONST_1E9  (1000000000U)

static inline bool_t is_eclk_enabled(addr_t base_va);
static errno_t reg_wait_for_clear(const volatile uint32_t * reg_address, uint32_t value, uint8_t timeout_100us);

#if defined(PFE_CFG_TEXT_STATS)

static inline const char_t* phy_mode_to_str(uint32_t mode);
static const char *emac_speed_to_str(pfe_emac_speed_t speed);

#endif /* defined(PFE_CFG_TEXT_STATS) */

#ifdef PFE_CFG_PFE_MASTER
static inline uint32_t reverse_bits_32(uint32_t u32Data);
static inline uint32_t crc32_reversed(const uint8_t *const data, const uint32_t len);
static inline uint8_t pfe_emac_get_emac_err_src_index(pfe_hm_evt_t event);
static inline void pfe_emac_cfg_clear_registers(addr_t base_va);

/* Reverse uint32_t bit order */
static inline uint32_t reverse_bits_32(uint32_t u32Data)
{
    uint8_t u8Index;
    uint32_t u32DataTemp = u32Data;
    uint32_t u32RevData = 0U;

    for(u8Index = 0U; u8Index < 32U; u8Index++)
    {
        u32RevData = (u32RevData << 1U) | (u32DataTemp & 0x1U);
        u32DataTemp >>= 1U;
    }

    return u32RevData;
}

/* Calculate CRC32 value. Same as used by EMAC peripheral to calculate MAC address
 * hash value for MAC address filtering. */
static inline uint32_t crc32_reversed(const uint8_t *const data, const uint32_t len)
{
    const uint32_t poly = 0xEDB88320U;
    uint32_t res = 0xffffffffU;
    uint32_t ii, jj;

    for (ii=0U; ii<len; ii++)
    {
        res ^= (uint32_t)data[ii];

        for (jj=0U; jj<8U; jj++)
        {
            if ((res & 0x1U) != 0U)
            {
                res = res >> 1U;
                res = (uint32_t)(res ^ poly);
            }
            else
            {
                res = res >> 1U;
            }
        }
    }

    return reverse_bits_32(~res);
}

/* Get EMAC Error source idx from HW event */
static inline uint8_t pfe_emac_get_emac_err_src_index(pfe_hm_evt_t event)
{
    uint8_t index = EMAC_ERR_SRC_INDEX_INVALID;

    switch (event)
    {
        case HM_EVT_EMAC_ECC_TX_FIFO_UNCORRECTABLE:
        case HM_EVT_EMAC_ECC_RX_FIFO_UNCORRECTABLE:
        {
            index = EMAC_ERR_SRC_INDEX_UNCORRECTABLE;
            break;
        }
        case HM_EVT_EMAC_ECC_TX_FIFO_ADDRESS:
        case HM_EVT_EMAC_ECC_RX_FIFO_ADDRESS:
        {
            index = EMAC_ERR_SRC_INDEX_ADDRESS;
            break;
        }
        case HM_EVT_EMAC_APP_TX_PARITY:
        case HM_EVT_EMAC_APP_RX_PARITY:
        case HM_EVT_EMAC_MTL_PARITY:
        case HM_EVT_EMAC_FSM_PARITY:
        {
            index = EMAC_ERR_SRC_INDEX_PARITY;
            break;
        }
        case HM_EVT_EMAC_FSM_TX_TIMEOUT:
        case HM_EVT_EMAC_FSM_RX_TIMEOUT:
        case HM_EVT_EMAC_FSM_APP_TIMEOUT:
        case HM_EVT_EMAC_FSM_PTP_TIMEOUT:
        case HM_EVT_EMAC_MASTER_TIMEOUT:
        {
            index = EMAC_ERR_SRC_INDEX_WDT;
            break;
        }
        default:
        {
            NXP_LOG_ERROR("Invalid event to get index");
            break;
        }
    }

    return index;
}

/**
 * @brief       Clear emac configuration registers
 * @details     EMAC registers have defined state on SOC reset but in some
 *              specific situations this mechanism may be bypassed.
 *              This ensures defined state on every initialization.
 * @param[in]   base_va The EMAC base address
 */
static inline void pfe_emac_cfg_clear_registers(addr_t base_va)
{
    /* Clear MAC exact match slots. First entry is always enabled. */
    hal_write32(MAC_ADDRESS0_HIGH_RESET_VAL, ADDR_BASE_OFFSET(base_va, MAC_ADDRESS_HIGH(0U)));
    hal_write32(MAC_ADDRESSX_LOW_RESET_VAL, ADDR_BASE_OFFSET(base_va, MAC_ADDRESS_LOW(0U)));
    for (uint8_t slot = 1U; slot < EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT; slot++)
    {
        hal_write32(MAC_ADDRESSX_HIGH_RESET_VAL, ADDR_BASE_OFFSET(base_va, MAC_ADDRESS_HIGH((uint64_t)slot)));
        hal_write32(MAC_ADDRESSX_LOW_RESET_VAL, ADDR_BASE_OFFSET(base_va, MAC_ADDRESS_LOW((uint64_t)slot)));
    }

    /* Clear hash table */
    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_HASH_TABLE_REG0));
    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_HASH_TABLE_REG1));

    /*  Wait at least 4 clock cycles ((G)MII) */
    oal_time_udelay(10);
}

/**
 * @brief       HW-specific pre-initialization function related to ERR050221
 *              This function should be called before any READ of MAC registers
 * @param[in]   base_va Base address of MAC register space (virtual)
 */
void pfe_emac_cfg_pre_init(addr_t base_va)
{
    hal_write32(0x1U, ADDR_BASE_OFFSET(base_va, MTL_DPP_CONTROL));
}

/**
 * @brief       HW-specific initialization function
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   mode MII mode to be configured @see pfe_emac_mii_mode_t
 * @param[in]   speed Speed to be configured @see pfe_emac_speed_t
 * @param[in]   duplex Duplex type to be configured @see pfe_emac_duplex_t
 * @return      EOK if success, error code if invalid configuration is detected
 */
errno_t pfe_emac_cfg_init(addr_t base_va, pfe_emac_mii_mode_t mode,
                            pfe_emac_speed_t speed, pfe_emac_duplex_t duplex)
{
    uint32_t reg;
    errno_t ret;
    
    pfe_emac_cfg_clear_registers(base_va);

    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION));
    hal_write32(0x8000ffeeU, ADDR_BASE_OFFSET(base_va, MAC_ADDRESS0_HIGH));
    hal_write32(0xddccbbaaU, ADDR_BASE_OFFSET(base_va, MAC_ADDRESS0_LOW));
    hal_write32(0U
            | RECEIVE_ALL(0U)
            | DROP_NON_TCP_UDP(0U)
            | L3_L4_FILTER_ENABLE(0U)
            | VLAN_TAG_FILTER_ENABLE(0U)
            | HASH_OR_PERFECT_FILTER(1U)
            | SA_FILTER(0U)
            | SA_INVERSE_FILTER(0U)
            | PASS_CONTROL_PACKETS(FORWARD_ALL_EXCEPT_PAUSE)
            | DISABLE_BROADCAST_PACKETS(0U)
            | PASS_ALL_MULTICAST(0U)
            | DA_INVERSE_FILTER(0U)
            | HASH_MULTICAST(1U)
            | HASH_UNICAST(1U)
            | PROMISCUOUS_MODE(0U)
            , ADDR_BASE_OFFSET(base_va, MAC_PACKET_FILTER));

    reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_Q0_TX_FLOW_CTRL));
    reg &= ~TX_FLOW_CONTROL_ENABLE(1U);
    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_Q0_TX_FLOW_CTRL));
    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_INTERRUPT_ENABLE));
    hal_write32(0xffffffffU, ADDR_BASE_OFFSET(base_va, MMC_RX_INTERRUPT_MASK));
    hal_write32(0xffffffffU, ADDR_BASE_OFFSET(base_va, MMC_TX_INTERRUPT_MASK));
    hal_write32(0xffffffffU, ADDR_BASE_OFFSET(base_va, MMC_IPC_RX_INTERRUPT_MASK));

    /* Enable ECC, timeout and parity chcecking */
    hal_write32(0U
            | ECC_TX(1U)
            | ECC_RX(1U)
            | ECC_EST(1U)
            | ECC_RXP(1U)
            | ECC_TSO(1U)
            , ADDR_BASE_OFFSET(base_va, MTL_ECC_CONTROL));
    reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_FSM_ACT_TIMER));
    hal_write32(reg
            | LARGE_MODE_TIMEOUT(0x2U)
            | NORMAL_MODE_TIMEOUT(0x2U)
            /* Select according to real CSR clock frequency. S32G: CSR_CLK = 300MHz => 300 ticks */
            | 0x12CUL
            , ADDR_BASE_OFFSET(base_va, MAC_FSM_ACT_TIMER));
    hal_write32(0U
            | DATA_PARITY_PROTECTION(1U)
            | SLAVE_PARITY_CHECK(1U)
            , ADDR_BASE_OFFSET(base_va, MTL_DPP_CONTROL));
    hal_write32(0U
            | FSM_PARITY_ENABLE(1U)
            | FSM_TIMEOUT_ENABLE(1U)
            , ADDR_BASE_OFFSET(base_va, MAC_FSM_CONTROL));

    reg = 0U | ARP_OFFLOAD_ENABLE(0U)
                 | SA_INSERT_REPLACE_CONTROL(CTRL_BY_SIGNALS)
                 | CHECKSUM_OFFLOAD(1U)
                 | INTER_PACKET_GAP(0U)
                 | GIANT_PACKET_LIMIT_CONTROL(1U)
                 | SUPPORT_2K_PACKETS(0U)
                 | CRC_STRIPPING_FOR_TYPE(1U)
                 | AUTO_PAD_OR_CRC_STRIPPING(1U)
                 | WATCHDOG_DISABLE(1U)
                 | PACKET_BURST_ENABLE(0U)
                 | JABBER_DISABLE(1U)
                 | PORT_SELECT(0U)               /* To be set up by pfe_emac_cfg_set_speed() */
                 | SPEED(0U)                             /* To be set up by pfe_emac_cfg_set_speed() */
                 | DUPLEX_MODE(1U)               /* To be set up by pfe_emac_cfg_set_duplex() */
                 | LOOPBACK_MODE(0U)
                 | CARRIER_SENSE_BEFORE_TX(0U)
                 | DISABLE_RECEIVE_OWN(0)
                 | DISABLE_CARRIER_SENSE_TX(0U)
                 | DISABLE_RETRY(0U)
                 | BACK_OFF_LIMIT(MIN_N_10)
                 | DEFERRAL_CHECK(0U)
                 | PREAMBLE_LENGTH_TX(PREAMBLE_7B)
                 | TRANSMITTER_ENABLE(0U)
                 | RECEIVER_ENABLE(0U);

    if (TRUE == pfe_feature_mgr_is_available("jumbo_frames"))
    {
        reg |= JUMBO_PACKET_ENABLE(1U);
    }
    else
    {
        reg |= JUMBO_PACKET_ENABLE(0U);
    }

    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION));

    hal_write32((uint32_t)0U
            | FORWARD_ERROR_PACKETS(1U)
            , ADDR_BASE_OFFSET(base_va, MTL_RXQ0_OPERATION_MODE));

    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MTL_TXQ0_OPERATION_MODE));
    if (TRUE == pfe_feature_mgr_is_available("jumbo_frames"))
    {
        hal_write32(GIANT_PACKET_SIZE_LIMIT(9022U), ADDR_BASE_OFFSET(base_va, MAC_EXT_CONFIGURATION));
    }
    else
    {
        hal_write32(GIANT_PACKET_SIZE_LIMIT(1522U), ADDR_BASE_OFFSET(base_va, MAC_EXT_CONFIGURATION));
    }

    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_SUB_SECOND_INCREMENT));

    /*  Set speed */
    if (EOK != pfe_emac_cfg_set_speed(base_va, speed))
    {
        ret = EINVAL;
    }
    else
    {
        /*  Set MII mode */
        if (EOK != pfe_emac_cfg_set_mii_mode(base_va, mode))
        {
            ret = EINVAL;
        }
        else
        {
            /*  Set duplex */
            if (EOK != pfe_emac_cfg_set_duplex(base_va, duplex))
            {
                ret = EINVAL;
            }
            else
            {
                ret = EOK;
            }
        }
    }

    return ret;
}

/**
 * @brief       Enable timestamping
 * @param[in]   base_va Base address
 * @param[in]   eclk TRUE means to use external clock reference (chain)
 * @param[in]   i_clk_hz Reference clock frequency
 * @param[in]   o_clk_hz Requested nominal output frequency
 * @param[in]   en TRUE means ENABLE, FALSE means DISABLE
 */
errno_t pfe_emac_cfg_enable_ts(addr_t base_va, bool_t eclk, uint32_t i_clk_hz, uint32_t o_clk_hz)
{
    uint32_t ss = 0U;
    uint32_t regval;
    errno_t ret;

    hal_write32(0U
            | EXTERNAL_TIME(eclk)
            | SELECT_PTP_PACKETS(0x1U)
            | PTP_OVER_IPV4(1U)
            | PTP_OVER_IPV6(1U)
            | PTP_OVER_ETH(1U)
            | PTPV2(1U)
            | DIGITAL_ROLLOVER(1U)
            | FINE_UPDATE(1U)
            | ENABLE_TIMESTAMP(1U)
            | ENABLE_TIMESTAMP_FOR_All(1U), ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));

    if (eclk == TRUE)
    {
        NXP_LOG_INFO("IEEE1588: Using external timestamp input\n");
        ret = EOK;
    }
    else
    {
        if ((o_clk_hz == 0U) || (i_clk_hz == 0U))
        {
            NXP_LOG_ERROR("Invalid frequency value");
            ret = EINVAL;
        }
        else
        {
            /*  Get output period [ns] */
            ss = CONST_1E9 / o_clk_hz;  /* o_clk_hz is guaranteed by Tresos to be larger than 3906250U */
            PfeDevAssert(ss <= UINT8_MAX);

            /*  Get sub-nanosecond part */
            const uint8_t sns = (uint8_t)(((256U * (uint64_t)CONST_1E9) / o_clk_hz) & UINT8_MAX);
            NXP_LOG_INFO(   "IEEE1588: Input Clock: %uHz, Output: %uHz, Accuracy: %u.%03uns\n",
                            (uint_t)i_clk_hz,
                            (uint_t)o_clk_hz,
                            (uint_t)ss,
                            (uint_t)((sns * 1000U) / 256U));

            /*  Set 'increment' values */
            hal_write32(((ss & 0xFFu) << 16U) | (sns << 8U), ADDR_BASE_OFFSET(base_va, MAC_SUB_SECOND_INCREMENT));

            /*  Set initial 'addend' value */
            const uint64_t u64_addend = ((uint64_t)o_clk_hz << 32U) / (uint64_t)i_clk_hz;
            PfeDevAssert(u64_addend <= UINT32_MAX);
            const uint32_t u32_addend = (uint32_t) u64_addend;
            hal_write32(u32_addend, ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_ADDEND));

            regval = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
            hal_write32(regval | UPDATE_ADDEND(1), ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
            ret = reg_wait_for_clear((volatile uint32_t *)(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL)), UPDATE_ADDEND(1), 10);

            if (EOK == ret)
            {
                /*  Set 'update' values */
                hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_STSU));
                hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_STNSU));

                regval = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
                regval |= INITIALIZE_TIMESTAMP(1);
                hal_write32(regval, ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
                ret = reg_wait_for_clear((volatile uint32_t *)(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL)), INITIALIZE_TIMESTAMP(1), 10);
            }
        }
    }

    return ret;
}

/**
 * @brief   Disable timestamping
 */
void pfe_emac_cfg_disable_ts(addr_t base_va)
{
    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
}
#endif /* PFE_CFG_PFE_MASTER */

/**
 * @brief       Check if external IEEE1588 clock is used on EMAC 
 * @param[in]   base_va Base address
 * @return      TRUE if external clock enabled
 */
static inline bool_t is_eclk_enabled(addr_t base_va) {
    bool_t eclk_enabled = FALSE;
    uint32_t regval;
    
    regval = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
    if (regval & EXTERNAL_TIME(1U))
    {
        eclk_enabled = TRUE;
    }
    
    return eclk_enabled;
}

/**
 * @brief       Wait for value to be cleared in reg
 * @param[in]   reg_address register address
 * @param[in]   value waiting for active bits to be cleared in the register
 * @param[in]   timeout_100us timeout value in multiple of hundred of microseconds
 * @return      ETIME in case of timeout, EOK otherwise
 */
static errno_t reg_wait_for_clear(const volatile uint32_t * reg_address, uint32_t value, uint8_t timeout_100us)
{
    errno_t result = ETIME;

    for (uint8_t timeout_cnt = 0U; timeout_cnt < timeout_100us; timeout_cnt++)
    {
        uint32_t regval = *reg_address;
        if ((regval & value) == 0U)
        {
            result = EOK;
            break;
        }

        oal_time_usleep(100U);
    }
    return result;
}

#if defined(PFE_CFG_TEXT_STATS)

/**
 * @brief       Convert EMAC mode to string
 * @details     Helper function for statistics to convert phy mode to string.
 * @param[in]   mode    phy mode
 * @return      pointer to string
 */
static inline const char_t* phy_mode_to_str(uint32_t mode)
{
    /* Initialize to invalid */
    uint32_t index  = ((uint32_t)(sizeof(phy_mode))/(uint32_t)(sizeof(phy_mode[0]))) - 1UL;

    if(((uint32_t)(sizeof(phy_mode))/(uint32_t)(sizeof(phy_mode[0]))) > mode)
    {
        index = mode;
    }

    return phy_mode[index];
}

/**
 * @brief       Convert EMAC speed to string
 * @details     Helper function for statistics to convert emac speed to string.
 * @param[in]   speed   emac speed
 * @return      pointer to string
 */
static const char *emac_speed_to_str(pfe_emac_speed_t speed)
{
    const char *ret;

    switch (speed)
    {
        case EMAC_SPEED_10_MBPS:
            ret = "10 Mbps";
            break;
        case EMAC_SPEED_100_MBPS:
            ret = "100 Mbps";
            break;
        case EMAC_SPEED_1000_MBPS:
            ret = "1 Gbps";
            break;
        case EMAC_SPEED_2500_MBPS:
            ret = "2.5 Gbps";
            break;
        default:
            ret = "unknown";
            break;
    }
    return ret;
}

#endif /* defined(PFE_CFG_TEXT_STATS) */

/**
 * @brief       Get EMAC instance index
 * @param[in]   emac_base The EMAC base address
 * @param[in]   cbus_base The PFE CBUS base address
 * @return      Index (0, 1, 2, ..) or 255 if failed
 */
uint8_t pfe_emac_cfg_get_index(addr_t emac_base, addr_t cbus_base)
{
    uint8_t idx;

    PfeDevAssert(emac_base >= cbus_base);
    switch ((addr_t)emac_base - (addr_t)cbus_base)
    {
        case CBUS_EMAC1_BASE_ADDR:
        {
            idx = 0U;
            break;
        }

        case CBUS_EMAC2_BASE_ADDR:
        {
            idx = 1U;
            break;
        }

        case CBUS_EMAC3_BASE_ADDR:
        {
            idx = 2U;
            break;
        }

        default:
        {
            idx = 255U;
            break;
        }
    }

    return idx;
}

/**
 * @brief       Adjust timestamping clock frequency
 * @param[in]   base_va Base address
 * @param[in]   ppb Frequency change in [ppb]
 * @param[in]   sgn If TRUE then 'ppb' is positive, else it is negative
 */
errno_t pfe_emac_cfg_adjust_ts_freq(addr_t base_va, uint32_t i_clk_hz, uint32_t o_clk_hz, uint32_t ppb, bool_t sgn)
{
    uint32_t nil, delta, regval;
    errno_t ret;
    
    if (is_eclk_enabled(base_va) == TRUE)
    {
        ret = EACCES;
    }
    else
    {
        if(i_clk_hz == 0U)
        {
            NXP_LOG_ERROR("Invalid frequency value");
            ret = EINVAL;
        }
        else
        {
            /*  Nil drift addend: 1^32 / (o_clk_hz / i_clk_hz) */
            const uint64_t u64_nil = ((uint64_t)o_clk_hz << 32U) / (uint64_t)i_clk_hz;
            PfeDevAssert(u64_nil <= UINT32_MAX);
            nil = (uint32_t) u64_nil;

            /*  delta = x * ppb * 0.000000001 */
            const uint64_t u64_delta = (((uint64_t)nil * (uint64_t)ppb) / 1000000000ULL);
            PfeDevAssert(u64_delta <= UINT32_MAX);
            delta = (uint32_t) u64_delta;

            /*  Adjust the 'addend' */
            if (sgn)
            {
                if (((uint64_t)nil + (uint64_t)delta) > 0xffffffffULL)
                {
                    NXP_LOG_WARNING("IEEE1588: Frequency adjustment out of positive range\n");
                    regval = 0xffffffffU;
                }
                else
                {
                    regval = nil + delta;
                }
            }
            else
            {
                if (delta > nil)
                {
                    NXP_LOG_WARNING("IEEE1588: Frequency adjustment out of negative range\n");
                    regval = 0U;
                }
                else
                {
                    regval = nil - delta;
                }
            }

            /*  Update the 'addend' value */
            hal_write32(regval, ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_ADDEND));

            /*  Request update 'addend' value */
            regval = hal_read32((addr_t)ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
            hal_write32(regval | UPDATE_ADDEND(1), (addr_t)ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));

            /*  Wait for completion */
            ret = reg_wait_for_clear((volatile uint32_t *)(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL)), UPDATE_ADDEND(1), 10U);
        }
    }

    return ret;
}

/**
 * @brief           Get system time
 * @param[in]       base_va Base address
 * @param[in,out]   sec Seconds
 * @param[in,out]   nsec NanoSeconds
 * @param[in,out]   sec_hi Higher Word Seconds
 */
void pfe_emac_cfg_get_ts_time(addr_t base_va, uint32_t *sec, uint32_t *nsec, uint16_t *sec_hi)
{
    uint32_t sec_tmp;

    do
    {
        *sec = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_SYSTEM_TIME_SECONDS));
        *nsec = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_SYSTEM_TIME_NANOSECONDS));
        *sec_hi = (uint16_t)(hal_read32(ADDR_BASE_OFFSET(base_va, MAC_STS_HIGHER_WORD)) & 0xFFFFu);
        sec_tmp = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_SYSTEM_TIME_SECONDS));
    } while (*sec != sec_tmp);
}

/**
 * @brief       Set system time
 * @details     Current time will be overwritten with the desired value
 * @param[in]   base_va Base address
 * @param[in]   sec Seconds
 * @param[in]   nsec NanoSeconds
 * @param[in]   sec_hi Higher Word Seconds
 */
errno_t pfe_emac_cfg_set_ts_time(addr_t base_va, uint32_t sec, uint32_t nsec, uint16_t sec_hi)
{
    uint32_t regval;
    errno_t ret;

    if (nsec > 0x7fffffffU)
    {
        ret = EINVAL;
    }
    else if (is_eclk_enabled(base_va) == TRUE)
    {
        ret = EACCES;
    }
    else
    {
        hal_write32(sec, ADDR_BASE_OFFSET(base_va, MAC_STSU));
        hal_write32(nsec, ADDR_BASE_OFFSET(base_va, MAC_STNSU));
        hal_write32(sec_hi, ADDR_BASE_OFFSET(base_va, MAC_STS_HIGHER_WORD));

        /*  Initialize time */
        regval = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
        regval |= INITIALIZE_TIMESTAMP(1);
        hal_write32(regval, ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));

        /*  Wait for completion */
        ret = reg_wait_for_clear((volatile uint32_t *)(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL)), INITIALIZE_TIMESTAMP(1), 10);
    }

    return ret;
}

/**
 * @brief       Adjust system time
 * @param[in]   base_va Base address
 * @param[in]   sec Seconds
 * @param[in]   nsec NanoSeconds
 * @param[in]   sgn Sing of the adjustment (TRUE - positive, FALSE - negative)
 */
errno_t pfe_emac_cfg_adjust_ts_time(addr_t base_va, uint32_t sec, uint32_t nsec, bool_t sgn)
{
    
    uint32_t regval;
    uint32_t nsec_temp = nsec;
    uint32_t sec_temp = sec;
    errno_t ret;

    if (nsec_temp > 0x7fffffffU)
    {
        ret = EINVAL;
    }
    else if (is_eclk_enabled(base_va) == TRUE)
    {
        ret = EACCES;
    }
    else
    {
        ret = EOK;

        regval = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));

        if (!sgn)
        {
            if (0U != (regval & DIGITAL_ROLLOVER(1)))
            {
                nsec_temp = 1000000000U - nsec;
            }
            else
            {
                nsec_temp = (1UL << 31U) - nsec;
            }

            /* For negative adjustment, the value filled to the register must be complement */
            sec_temp = (uint32_t)(((uint64_t)UINT32_MAX - sec + 1U) & UINT32_MAX);
        }

        if (0U != (regval & DIGITAL_ROLLOVER(1)))
        {
            if (nsec_temp > 0x3b9ac9ffU)
            {
                ret = EINVAL;
            }
        }

        if (EOK == ret)
        {
            hal_write32(sec_temp, ADDR_BASE_OFFSET(base_va, MAC_STSU));
            hal_write32(ADDSUB(!sgn) | nsec_temp, ADDR_BASE_OFFSET(base_va, MAC_STNSU));

            /*  Trigger the update */
            regval = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
            regval |= UPDATE_TIMESTAMP(1);
            hal_write32(regval, ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));

            /*  Wait for completion */
            ret = reg_wait_for_clear((volatile uint32_t *)(ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL)), UPDATE_TIMESTAMP(1), 10);
        }
    }

    return ret;
}

#if defined(PFE_CFG_TEXT_STATS)

/**
 * @brief       Get EMAC statistics in text form
 * @details     This is a HW-specific function providing detailed text statistics
 *              about the EMAC block.
 * @param[in]   base_va     Base address of EMAC register space (virtual)
 * @param[in]   buf         Pointer to the buffer to write to
 * @param[in]   size        Buffer length
 * @param[in]   verb_level  Verbosity level
 * @return      Number of bytes written to the buffer
 */
uint32_t pfe_emac_cfg_get_text_stat(addr_t base_va, char_t *buf, uint32_t size, uint8_t verb_level)
{
    uint32_t len = 0U;
    uint32_t reg;
    pfe_emac_speed_t speed;
    pfe_emac_duplex_t duplex;

#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        len = 0U;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        /*  Get version */
        reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_VERSION));
        len += oal_util_snprintf(buf + len, size - len, "SNPVER                    : 0x%x\n", reg & 0xffU);
        len += oal_util_snprintf(buf + len, size - len, "USERVER                   : 0x%x\n", (reg >> 8) & 0xffU);

        reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_PACKETS_COUNT_GOOD_BAD));
        len += oal_util_snprintf(buf + len, size - len, "RX_PACKETS_COUNT_GOOD_BAD : 0x%x\n", reg);
        reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_PACKET_COUNT_GOOD_BAD));
        len += oal_util_snprintf(buf + len, size - len, "TX_PACKET_COUNT_GOOD_BAD  : 0x%x\n", reg);

        (void)pfe_emac_cfg_get_link_config(base_va, &speed, &duplex);
        reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION));
        len += oal_util_snprintf(buf + len, size - len, "MAC_CONFIGURATION         : 0x%x [speed: %s]\n", reg, emac_speed_to_str(speed));

        reg = (hal_read32(ADDR_BASE_OFFSET(base_va, MAC_HW_FEATURE0)) >> 28U) & 0x07U;
        len += oal_util_snprintf(buf + len, size - len, "ACTPHYSEL(MAC_HW_FEATURE0): %s\n", phy_mode_to_str(reg));

        /* Error debugging */
        if(verb_level >= 8U)
        {
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_UNDERFLOW_ERROR_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "TX_UNDERFLOW_ERROR_PACKETS        : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_SINGLE_COLLISION_GOOD_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "TX_SINGLE_COLLISION_GOOD_PACKETS  : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_MULTIPLE_COLLISION_GOOD_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "TX_MULTIPLE_COLLISION_GOOD_PACKETS: 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_DEFERRED_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "TX_DEFERRED_PACKETS               : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_LATE_COLLISION_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "TX_LATE_COLLISION_PACKETS         : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_EXCESSIVE_COLLISION_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "TX_EXCESSIVE_COLLISION_PACKETS    : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_CARRIER_ERROR_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "TX_CARRIER_ERROR_PACKETS          : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_EXCESSIVE_DEFERRAL_ERROR));
            len += oal_util_snprintf(buf + len, size - len, "TX_EXCESSIVE_DEFERRAL_ERROR       : 0x%x\n", reg);

            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_OSIZE_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "TX_OSIZE_PACKETS_GOOD             : 0x%x\n", reg);

            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_CRC_ERROR_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "RX_CRC_ERROR_PACKETS              : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_ALIGNMENT_ERROR_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "RX_ALIGNMENT_ERROR_PACKETS        : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_RUNT_ERROR_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "RX_RUNT_ERROR_PACKETS             : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_JABBER_ERROR_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "RX_JABBER_ERROR_PACKETS           : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_LENGTH_ERROR_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "RX_LENGTH_ERROR_PACKETS           : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_OUT_OF_RANGE_TYPE_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "RX_OUT_OF_RANGE_TYPE_PACKETS      : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_FIFO_OVERFLOW_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "RX_FIFO_OVERFLOW_PACKETS          : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_RECEIVE_ERROR_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "RX_RECEIVE_ERROR_PACKETS          : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_RECEIVE_ERROR_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "RX_RECEIVE_ERROR_PACKETS          : 0x%x\n", reg);

            reg = hal_read32(ADDR_BASE_OFFSET(base_va, MTL_ECC_ERR_CNTR_STATUS));
            len += oal_util_snprintf(buf + len, size - len, "MTL_ECC_CORRECTABLE_ERRORS        : 0x%x\n", (reg & 0xffU));
            len += oal_util_snprintf(buf + len, size - len, "MTL_ECC_UNCORRECTABLE_ERRORS      : 0x%x\n", ((reg >> 16U) & 0xfU));
        }

        /* Cast/vlan/flow control */
        if(verb_level >= 3U)
        {
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_UNICAST_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "TX_UNICAST_PACKETS_GOOD_BAD       : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_BROADCAST_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "TX_BROADCAST_PACKETS_GOOD         : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_BROADCAST_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "TX_BROADCAST_PACKETS_GOOD_BAD     : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_MULTICAST_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "TX_MULTICAST_PACKETS_GOOD         : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_MULTICAST_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "TX_MULTICAST_PACKETS_GOOD_BAD     : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_VLAN_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "TX_VLAN_PACKETS_GOOD              : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_PAUSE_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "TX_PAUSE_PACKETS                  : 0x%x\n", reg);
        }

        if(verb_level >= 4U)
        {
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_UNICAST_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "RX_UNICAST_PACKETS_GOOD           : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_BROADCAST_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "RX_BROADCAST_PACKETS_GOOD         : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_MULTICAST_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "RX_MULTICAST_PACKETS_GOOD         : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_VLAN_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "RX_VLAN_PACKETS_GOOD_BAD          : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_PAUSE_PACKETS));
            len += oal_util_snprintf(buf + len, size - len, "RX_PAUSE_PACKETS                  : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_CONTROL_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "RX_CONTROL_PACKETS_GOOD           : 0x%x\n", reg);
        }

        if(verb_level >= 1U)
        {
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_OCTET_COUNT_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "TX_OCTET_COUNT_GOOD                : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_OCTET_COUNT_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "TX_OCTET_COUNT_GOOD_BAD            : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_64OCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "TX_64OCTETS_PACKETS_GOOD_BAD       : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_65TO127OCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "TX_65TO127OCTETS_PACKETS_GOOD_BAD  : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_128TO255OCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "TX_128TO255OCTETS_PACKETS_GOOD_BAD : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_256TO511OCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "TX_256TO511OCTETS_PACKETS_GOOD_BAD : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_512TO1023OCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "TX_512TO1023OCTETS_PACKETS_GOOD_BAD: 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD: 0x%x\n", reg);
        }

        if(verb_level >= 5U)
        {
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, TX_OSIZE_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "TX_OSIZE_PACKETS_GOOD              : 0x%x\n", reg);
        }

        if(verb_level >= 2U)
        {
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_OCTET_COUNT_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "RX_OCTET_COUNT_GOOD                : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_OCTET_COUNT_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "RX_OCTET_COUNT_GOOD_BAD            : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_64OCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "RX_64OCTETS_PACKETS_GOOD_BAD       : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_65TO127OCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "RX_65TO127OCTETS_PACKETS_GOOD_BAD  : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_128TO255OCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "RX_128TO255OCTETS_PACKETS_GOOD_BAD : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_256TO511OCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "RX_256TO511OCTETS_PACKETS_GOOD_BAD : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_512TO1023OCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "RX_512TO1023OCTETS_PACKETS_GOOD_BAD: 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD));
            len += oal_util_snprintf(buf + len, size - len, "RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD: 0x%x\n", reg);
        }

        if(verb_level >= 5U)
        {
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_OVERSIZE_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "RX_OSIZE_PACKETS_GOOD              : 0x%x\n", reg);
            reg = hal_read32(ADDR_BASE_OFFSET(base_va, RX_UNDERSIZE_PACKETS_GOOD));
            len += oal_util_snprintf(buf + len, size - len, "RX_UNDERSIZE_PACKETS_GOOD          : 0x%x\n", reg);
        }
    }

    return len;
}

#endif /* defined(PFE_CFG_TEXT_STATS) */

errno_t pfe_emac_cfg_get_link_config(addr_t base_va, pfe_emac_speed_t *speed, pfe_emac_duplex_t *duplex)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION));

    /* speed */
    switch (GET_LINE_SPEED(reg))
    {
        case 0x01U:
            *speed = EMAC_SPEED_2500_MBPS;
            break;
        case 0x02U:
            *speed = EMAC_SPEED_10_MBPS;
            break;
        case 0x03U:
            *speed = EMAC_SPEED_100_MBPS;
            break;
        case 0x0U:
        default:
            *speed = EMAC_SPEED_1000_MBPS;
            break;
    }

    /* duplex */
    *duplex = (1U == GET_DUPLEX_MODE(reg)) ? EMAC_DUPLEX_FULL : EMAC_DUPLEX_HALF;

    return EOK;
}

/**
 * @brief       Get EMAC statistic in numeric form
 * @details     This is a HW-specific function providing single statistic
 *              value from the EMAC block.
 * @param[in]   base_va     Base address of EMAC register space (virtual)
 * @param[in]   stat_id     ID of required statistic (offset of register)
 * @return      Value of requested statistic
 */
uint32_t pfe_emac_cfg_get_stat_value(addr_t base_va, uint32_t stat_id)
{
    uint32_t stat_value;
#if defined(PFE_CFG_NULL_ARG_CHECK)
    if (unlikely(NULL_ADDR == base_va))
    {
        NXP_LOG_ERROR("NULL argument received\n");
        stat_value = 0xFFFFFFFFU;
    }
    else
#endif /* PFE_CFG_NULL_ARG_CHECK */
    {
        stat_value = hal_read32(ADDR_BASE_OFFSET(base_va, stat_id));
    }
    return stat_value;
}

#ifdef PFE_CFG_PFE_MASTER
/* Disable EMAC TS */
void pfe_emac_cfg_tx_disable(addr_t base_va)
{
    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_TIMESTAMP_CONTROL));
}

/**
 * @brief       Set MAC duplex
 * @param[in]   base_va Base address to be written
 * @param[in]   duplex Duplex type to be configured @see pfe_emac_duplex_t
 * @return      EOK if success, error code when invalid configuration is requested
 */
errno_t pfe_emac_cfg_set_duplex(addr_t base_va, pfe_emac_duplex_t duplex)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION)) & ~(DUPLEX_MODE(1U));
    errno_t ret = EOK;

    switch (duplex)
    {
        case EMAC_DUPLEX_HALF:
        {
            reg |= DUPLEX_MODE(0U);
            break;
        }

        case EMAC_DUPLEX_FULL:
        {
            reg |= DUPLEX_MODE(1U);
            break;
        }

        default:
            ret = EINVAL;
            break;
    }
    if(EOK == ret)
    {
        hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION));
    }

    return ret;
}

/**
 * @brief       Set MAC MII mode
 * @param[in]   base_va Base address to be written
 * @param[in]   mode MII mode to be configured @see pfe_emac_mii_mode_t
 * @return      EOK if success, error code when invalid configuration is requested
 */
errno_t pfe_emac_cfg_set_mii_mode(addr_t base_va, pfe_emac_mii_mode_t mode)
{
    /*
         The PHY mode selection is done using a HW interface. See the "phy_intf_sel" signal.
    */
    (void)base_va;
    (void)mode;

    return EOK;
}

/**
 * @brief       Set MAC speed
 * @param[in]   base_va Base address to be written
 * @param[in]   speed Speed to be configured @see pfe_emac_speed_t
 * @return      EOK if success, error code when invalid configuration is requested
 */
errno_t pfe_emac_cfg_set_speed(addr_t base_va, pfe_emac_speed_t speed)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION)) & ~(PORT_SELECT(1U) | SPEED(1U));
    errno_t ret = EOK;

    switch (speed)
    {
        case EMAC_SPEED_10_MBPS:
        {
            reg |= PORT_SELECT(1U);
            reg |= SPEED(0U);
            break;
        }

        case EMAC_SPEED_100_MBPS:
        {
            reg |= PORT_SELECT(1U);
            reg |= SPEED(1U);
            break;
        }

        case EMAC_SPEED_1000_MBPS:
        {
            reg |= PORT_SELECT(0);
            reg |= SPEED(0);
            break;
        }

        case EMAC_SPEED_2500_MBPS:
        {
            reg |= PORT_SELECT(0);
            reg |= SPEED(1);
            break;
        }

        default:
        {
            ret = EINVAL;
            break;
        }
    }

    if (EOK == ret)
    {
        /*  Configure speed in EMAC registers */
        hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION));
    }

    return ret;
}

/**
 * @brief       Get MAC configured link parameters
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[out]  clock_speed Currently configured link speed
 * @param[out]  duplex Currently configured Duplex type @see pfe_emac_duplex_t
 * @param[out]  link Current link state
 * @return      EOK if success
 */
errno_t pfe_emac_cfg_get_link_status(addr_t base_va, pfe_emac_link_speed_t *link_speed, pfe_emac_duplex_t *duplex, bool_t *link)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_PHYIF_CONTROL_STATUS));

    /* speed */
    switch (LNKSPEED(reg))
    {
        case 0x01U:
            *link_speed = EMAC_LINK_SPEED_25_MHZ;
            break;
        case 0x02U:
            *link_speed = EMAC_LINK_SPEED_125_MHZ;
            break;
        case 0x03U:
            *link_speed = EMAC_LINK_SPEED_INVALID;
            break;
        case 0x0U:
        default:
            *link_speed = EMAC_LINK_SPEED_2_5_MHZ;
            break;
    }

    /* duplex */
    *duplex = (1U == LNKMOD(reg)) ? EMAC_DUPLEX_FULL : EMAC_DUPLEX_HALF;

    /* link */
    *link = LNKSTS(reg) == 1U;

    return EOK;
}

/**
 * @brief       Set maximum frame length
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   len The new maximum frame length
 * @return      EOK if success, error code if invalid value is requested
 */
errno_t pfe_emac_cfg_set_max_frame_length(addr_t base_va, uint32_t len)
{
    uint32_t reg, maxlen = 0U;
    bool_t je, s2kp, gpslce, edvlp;
    errno_t ret;

    /*
        In this case the function just performs check whether the requested length
        is supported by the current MAC configuration. When change is needed then
        particular parameters (JE, S2KP, GPSLCE, DVLP, and GPSL must be changed).
    */

    reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION));
    je = !!(reg & JUMBO_PACKET_ENABLE(1U));
    s2kp = !!(reg & SUPPORT_2K_PACKETS(1U));
    gpslce = !!(reg & GIANT_PACKET_LIMIT_CONTROL(1U));

    reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_VLAN_TAG_CTRL));
    edvlp = !!(reg & ENABLE_DOUBLE_VLAN(1U));

    if (je && edvlp)
    {
        maxlen = 9026U;
    }

    if (!je && s2kp)
    {
        maxlen = 2000U;
    }

    if (!je && !s2kp && gpslce && edvlp)
    {
        reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_EXT_CONFIGURATION));
        maxlen = reg & GIANT_PACKET_SIZE_LIMIT((uint32_t)-1);
        maxlen += 8U;
    }

    if (!je && !s2kp && !gpslce && edvlp)
    {
        maxlen = 1526U;
    }

    if (je && !edvlp)
    {
        maxlen = 9022U;
    }

    if (!je && !s2kp && gpslce && !edvlp)
    {
        reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_EXT_CONFIGURATION));
        maxlen = reg & GIANT_PACKET_SIZE_LIMIT((uint32_t)-1);
        maxlen += 4U;
    }

    if (!je && !s2kp && !gpslce && !edvlp)
    {
        maxlen = 1522U;
    }

    if (len > maxlen)
    {
        ret = EINVAL;
    }
    else
    {
        ret = EOK;
    }

    return ret;
}

/**
 * @brief       Write MAC address to a specific individual address slot
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   addr The MAC address to be written
 * @param[in]   slot Index of slot where the address shall be written
 * @note        Maximum number of slots is given by EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT
 */
void pfe_emac_cfg_write_addr_slot(addr_t base_va, const pfe_mac_addr_t addr, uint8_t slot)
{
    uint32_t bottom = ((uint32_t)addr[3] << 24U) | ((uint32_t)addr[2] << 16U) | ((uint32_t)addr[1] << 8U) | ((uint32_t)addr[0] << 0U);
    uint32_t top = ((uint32_t)addr[5] << 8U) | ((uint32_t)addr[4] << 0U);

    /*  All-zeros MAC address is special case (invalid entry) */
    if ((0U != top) || (0U != bottom))
    {
        top |= 0x80000000U;
    }

    hal_write32(top, ADDR_BASE_OFFSET(base_va, MAC_ADDRESS_HIGH((uint64_t)slot)));
    hal_write32(bottom, ADDR_BASE_OFFSET(base_va, MAC_ADDRESS_LOW((uint64_t)slot)));
    oal_time_udelay(10);
    hal_write32(bottom, ADDR_BASE_OFFSET(base_va, MAC_ADDRESS_LOW((uint64_t)slot)));
}

/**
 * @brief       Read MAC address from a specific individual address slot
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[out]  addr The MAC address to be read, filled with zeroes when slot is disabled
 * @param[in]   slot Index of slot where the address shall be read
 * @note        Maximum number of slots is given by EMAC_CFG_INDIVIDUAL_ADDR_SLOTS_COUNT
 */
void pfe_emac_cfg_read_addr_slot(addr_t base_va, pfe_mac_addr_t addr, uint8_t slot)
{
    uint32_t top = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_ADDRESS_HIGH((uint64_t)slot)));
    uint32_t bottom = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_ADDRESS_LOW((uint64_t)slot)));
    
    /* Check whether the address slot is in use */
    if ((top & 0x80000000U) != 0U)
    {
        /* Address slot is in use */
        addr[0] = (uint8_t) (bottom & 0xFFu);
        addr[1] = (uint8_t) ((bottom >> 8U) & 0xFFu);
        addr[2] = (uint8_t) ((bottom >> 16U) & 0xFFu);
        addr[3] = (uint8_t) ((bottom >> 24U) & 0xFFu);
        addr[4] = (uint8_t) (top & 0xFFu);
        addr[5] = (uint8_t) ((top >> 8U) & 0xFFu);
    }
    else
    {
        /* Address slot is not in use */
        (void)autolibc_memset(addr, 0, sizeof(pfe_mac_addr_t));
    }
}

/**
 * @brief       Convert MAC address to its hash representation
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   addr The MAC address to compute the hash for
 * @retval      The hash value as represented/used by the HW
 */
uint32_t pfe_emac_cfg_get_hash(addr_t base_va, const pfe_mac_addr_t addr)
{
    (void)base_va;

    return crc32_reversed((uint8_t *)addr, 6U);
}

/**
 * @brief       Enable/Disable individual address group defined by 'hash'
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   hash The hash value
 * @param[in]   en TRUE means ENABLE, FALSE means DISABLE
 */
void pfe_emac_cfg_set_hash_group(addr_t base_va, uint32_t hash, bool_t en)
{
    uint32_t reg, old_reg;
    uint32_t val;
    uint8_t hash_table_idx, pos;

    /*
     * NOTE:
     * The algorithm calculates value to write into Hash table
     * (Refer to the register description of MAC_HASH_TABLE_REG in RM for more details)
     *    - Step 1:  Compute the CRC value of the destination MAC address (see crc32_reversed())
     *    - Step 2:  Reverse 32 bits of CRC result (see crc32_reversed())
     *    - Step 3:  Select the appropriate register bit to set.
     *
     * In this function, it executes Step 3 in above algorithm.
     * Currently, 64-bit Hash is used, so the upper 6 bits after passing through the CRC calculator are used to index the bit to set in the Hash table
     * The MSB in these group represents the index of the register to be used
     * The remaining 5 bits reveals information on the position to set in the corresponding register
     */

    val = (hash & EMAC_CFG_MAC_HASH_MASK) >> 26U;     /* Upper 6 bits of CRC result */
    hash_table_idx = ((uint8_t)val & 0x20U) >> 5U;    /* MSB represents Hash table register index (0/1) */
    pos = ((uint8_t)val & 0x1fU);                     /* Remaining 5 bits illustrates the bit to set in corresponding register  */

    reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_HASH_TABLE_REG((uint64_t)hash_table_idx)));
    old_reg = reg;

    if (en)
    {
        reg |= ((uint32_t)1U << pos);
    }
    else
    {
        reg &= ~((uint32_t)1U << pos);
    }

    if (reg != old_reg)
    {
        hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_HASH_TABLE_REG((uint64_t)hash_table_idx)));
        /*  Wait at least 4 clock cycles ((G)MII) */
        oal_time_udelay(10);
        hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_HASH_TABLE_REG((uint64_t)hash_table_idx)));
    }
}

/**
 * @brief       Clear hash table
 * @param[in]   base_va Base address of MAC register space (virtual)
 */
void pfe_emac_cfg_clear_hash_table(addr_t base_va)
{
    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_HASH_TABLE_REG0));
    hal_write32(0U, ADDR_BASE_OFFSET(base_va, MAC_HASH_TABLE_REG1));
    /*  Wait at least 4 clock cycles ((G)MII) */
    oal_time_udelay(10);
}

/**
 * @brief       Enable/Disable loopback mode
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param       en TRUE means ENABLE, FALSE means DISABLE
 */
void pfe_emac_cfg_set_loopback(addr_t base_va, bool_t en)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION)) & ~(LOOPBACK_MODE(1));

    reg |= LOOPBACK_MODE(en);

    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION));
}

/**
 * @brief       Enable/Disable promiscuous mode
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param       en TRUE means ENABLE, FALSE means DISABLE
 */
void pfe_emac_cfg_set_promisc_mode(addr_t base_va, bool_t en)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_PACKET_FILTER)) & ~(PROMISCUOUS_MODE(1));

    reg |= PROMISCUOUS_MODE(en);

    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_PACKET_FILTER));
}

/**
 * @brief       Enable/Disable ALLMULTI mode
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param       en TRUE means ENABLE, FALSE means DISABLE
 */
void pfe_emac_cfg_set_allmulti_mode(addr_t base_va, bool_t en)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_PACKET_FILTER)) & ~(PASS_ALL_MULTICAST(1));

    reg |= PASS_ALL_MULTICAST(en);

    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_PACKET_FILTER));
}

/**
 * @brief       Enable/Disable broadcast reception
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param       en TRUE means ENABLE, FALSE means DISABLE
 */
void pfe_emac_cfg_set_broadcast(addr_t base_va, bool_t en)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_PACKET_FILTER)) & ~(DISABLE_BROADCAST_PACKETS(1));

    reg |= DISABLE_BROADCAST_PACKETS(!en);

    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_PACKET_FILTER));
}

/**
 * @brief       Enable/Disable the Ethernet controller
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param       en TRUE means ENABLE, FALSE means DISABLE
 */
void pfe_emac_cfg_set_enable(addr_t base_va, bool_t en)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION));

    reg &= ~(TRANSMITTER_ENABLE(1) | RECEIVER_ENABLE(1));
    reg |= TRANSMITTER_ENABLE(en) | RECEIVER_ENABLE(en);

    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_CONFIGURATION));
}

/* Get state (Enabled/Disabled) of TX flow control */
void pfe_emac_cfg_get_tx_flow_control(addr_t base_va, bool_t* en)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_Q0_TX_FLOW_CTRL));

    *en = (0U == (reg & TX_FLOW_CONTROL_ENABLE(1))) ? FALSE : TRUE;
}

/* Get state (Enabled/Disabled) of RX flow control */
void pfe_emac_cfg_get_rx_flow_control(addr_t base_va, bool_t* en)
{
    uint32_t reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_RX_FLOW_CTRL));

    *en = (0U == (reg & RX_FLOW_CONTROL_ENABLE(1))) ? FALSE : TRUE;
}

/**
 * @brief       Enable/Disable the tx flow control
 * @details     Once enabled the MAC shall send PAUSE frames
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param       en TRUE means ENABLE, FALSE means DISABLE
 */
void pfe_emac_cfg_set_tx_flow_control(addr_t base_va, bool_t en)
{
    uint32_t reg, ii=0U;

    do
    {
        reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_Q0_TX_FLOW_CTRL));
        oal_time_usleep(100U);
        ii++;
    } while ((reg & BUSY_OR_BACKPRESSURE_ACTIVE(1)) && (ii < 10U));

    if (ii >= 10U)
    {
        NXP_LOG_ERROR("Flow control is busy, exiting...\n");
    }
    else
    {
        reg &= ~(TX_FLOW_CONTROL_ENABLE(1));
        reg |= TX_FLOW_CONTROL_ENABLE(en);

        reg |= TX_PAUSE_TIME(DEFAULT_PAUSE_QUANTA);
        reg |= TX_PAUSE_LOW_TRASHOLD(0x0);

        hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_Q0_TX_FLOW_CTRL));
    }
}

/**
 * @brief               Enable/Disable the rx flow control
 * @details             Once enabled the MAC shall process PAUSE frames
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param               en TRUE means ENABLE, FALSE means DISABLE
 */
void pfe_emac_cfg_set_rx_flow_control(addr_t base_va, bool_t en)
{
    uint32_t reg =  hal_read32(ADDR_BASE_OFFSET(base_va, MAC_RX_FLOW_CTRL));

    reg &= ~(RX_FLOW_CONTROL_ENABLE(1));
    reg |= RX_FLOW_CONTROL_ENABLE(en);

    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_RX_FLOW_CTRL));
}

/**
 * @brief       Read value from the MDIO bus using Clause 22
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   pa Address of the PHY to read (5-bit)
 * @param[in]   ra Address of the register in the PHY to be read (5-bit)
 * @param[out]  val If success the the read value is written here (16 bit)
 * @retval      EOK Success
 */
errno_t pfe_emac_cfg_mdio_read22(addr_t base_va, uint8_t pa, uint8_t ra, uint16_t *val)
{
    uint32_t reg;
    uint32_t timeout = 500U;
    errno_t ret = EOK;

    reg = GMII_BUSY(1U)
            | CLAUSE45_ENABLE(0U)
            | GMII_OPERATION_CMD(GMII_READ)
            | SKIP_ADDRESS_PACKET(0U)
            /*  Select according to real CSR clock frequency. S32G: CSR_CLK = PFE_SYS_CLK = 300MHz */
            | CSR_CLOCK_RANGE(CSR_CLK_300_500_MHZ_MDC_CSR_DIV_204)
            | NUM_OF_TRAILING_CLOCKS(0U)
            | REG_DEV_ADDR(ra)
            | PHYS_LAYER_ADDR(pa)
            | BACK_TO_BACK(0U)
            | PREAMBLE_SUPPRESSION(0U);


    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_MDIO_ADDRESS));
    do
    {
        reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_MDIO_ADDRESS));
        if (timeout == 0U)
        {
            ret = ETIME;
            break;
        }
        timeout--;
        oal_time_usleep(10);
    }
    while(GMII_BUSY(1) == (reg & GMII_BUSY(1)));

    if (EOK == ret)
    {
        /*  Get the data */
        reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_MDIO_DATA));
        *val = (uint16_t)GMII_DATA(reg);
    }

    return ret;
}

/**
* @brief        Read value from the MDIO bus using Clause 45
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   pa  Address of the PHY to read (5-bit)
 * @param[in]   dev Selects the device in the PHY to read (5-bit)
 * @param[in]   ra  Register address in the device to read  (16-bit)
 * @param[out]  val If success the the read value is written here (16-bit)
 * @retval      EOK Success
 */
errno_t pfe_emac_cfg_mdio_read45(addr_t base_va, uint8_t pa, uint8_t dev, uint16_t ra, uint16_t *val)
{
    uint32_t reg;
    uint32_t timeout = 500U;
    errno_t ret = EOK;

    /* Set the register addresss to read */
    reg = (uint32_t)GMII_REGISTER_ADDRESS(ra);
    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_MDIO_DATA));

    reg = GMII_BUSY(1U)
            | CLAUSE45_ENABLE(1U)
            | GMII_OPERATION_CMD(GMII_READ)
            | SKIP_ADDRESS_PACKET(0U)
            /*  Select according to real CSR clock frequency. S32G: CSR_CLK = PFE_SYS_CLK = 300MHz */
            | CSR_CLOCK_RANGE(CSR_CLK_300_500_MHZ_MDC_CSR_DIV_204)
            | NUM_OF_TRAILING_CLOCKS(0U)
            | REG_DEV_ADDR(dev)
            | PHYS_LAYER_ADDR(pa)
            | BACK_TO_BACK(0U)
            | PREAMBLE_SUPPRESSION(0U);

    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_MDIO_ADDRESS));
    while(GMII_BUSY(1) == (hal_read32(ADDR_BASE_OFFSET(base_va, MAC_MDIO_ADDRESS)) & GMII_BUSY(1)))
    {
        if (timeout-- == 0U)
        {
            ret = ETIME;
            break;
        }

        oal_time_usleep(10);
    }

    if (EOK == ret)
    {
        /*  Get the data */
        reg = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_MDIO_DATA));
        *val = (uint16_t)GMII_DATA(reg);
    }

    return ret;
}

/**
 * @brief       Write value to the MDIO bus using Clause 22
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   pa Address of the PHY to be written (5-bit)
 * @param[in]   ra Address of the register in the PHY to be written (5-bit)
 * @param[in]   val Value to be written into the register (16 bit)
 * @retval      EOK Success
 */
errno_t pfe_emac_cfg_mdio_write22(addr_t base_va, uint8_t pa, uint8_t ra, uint16_t val)
{
    uint32_t reg;
    uint32_t timeout = 500U;
    errno_t ret = EOK;

    reg = (uint32_t)GMII_DATA(val);
    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_MDIO_DATA));

    reg = GMII_BUSY(1U)
                | CLAUSE45_ENABLE(0U)
                | GMII_OPERATION_CMD(GMII_WRITE)
                | SKIP_ADDRESS_PACKET(0U)
                /*  Select according to real CSR clock frequency. S32G: CSR_CLK = PFE_SYS_CLK = 300MHz */
                | CSR_CLOCK_RANGE(CSR_CLK_300_500_MHZ_MDC_CSR_DIV_204)
                | NUM_OF_TRAILING_CLOCKS(0U)
                | REG_DEV_ADDR(ra)
                | PHYS_LAYER_ADDR(pa)
                | BACK_TO_BACK(0U)
                | PREAMBLE_SUPPRESSION(0U);

    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_MDIO_ADDRESS));
    while(GMII_BUSY(1) == (hal_read32(ADDR_BASE_OFFSET(base_va, MAC_MDIO_ADDRESS)) & GMII_BUSY(1)))
    {
        if (timeout-- == 0U)
        {
            ret = ETIME;
            break;
        }
        oal_time_usleep(10);
    }

    return ret;
}

/**
* @brief        Write value to the MDIO bus using Clause 45
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   pa  Address of the PHY to be written (5-bit)
 * @param[in]   dev Device in the PHY to be written (5-bit)
 * @param[in]   ra  Address of the register in the device to be written (16-bit)
 * @param[in]   val Value to be written (16-bit)
 * @retval      EOK Success
 */
errno_t pfe_emac_cfg_mdio_write45(addr_t base_va, uint8_t pa, uint8_t dev, uint16_t ra, uint16_t val)
{
    uint32_t reg;
    uint32_t timeout = 500U;
    errno_t ret = EOK;

    reg = (uint32_t)(GMII_DATA(val) | GMII_REGISTER_ADDRESS(ra));
    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_MDIO_DATA));

    reg = GMII_BUSY(1U)
                | CLAUSE45_ENABLE(1U)
                | GMII_OPERATION_CMD(GMII_WRITE)
                | SKIP_ADDRESS_PACKET(0U)
                /*  Select according to real CSR clock frequency. S32G: CSR_CLK = PFE_SYS_CLK = 300MHz */
                | CSR_CLOCK_RANGE(CSR_CLK_300_500_MHZ_MDC_CSR_DIV_204)
                | NUM_OF_TRAILING_CLOCKS(0U)
                | REG_DEV_ADDR(dev)
                | PHYS_LAYER_ADDR(pa)
                | BACK_TO_BACK(0U)
                | PREAMBLE_SUPPRESSION(0U);

    hal_write32(reg, ADDR_BASE_OFFSET(base_va, MAC_MDIO_ADDRESS));
    while(GMII_BUSY(1) == (hal_read32(ADDR_BASE_OFFSET(base_va, MAC_MDIO_ADDRESS)) & GMII_BUSY(1)))
    {
        if (timeout-- == 0U)
        {
            ret = ETIME;
            break;
        }

        oal_time_usleep(10);
    }

    return ret;
}

/**
 * @brief       Configure PPS0 output
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   mcgr_en Enable MCGR mode
 * @param[in]   trgtmodsel Target Time Register Mode for PPS0 Output
 * @param[in]   flexible_en Enable Flexiple PPS output mode
 */
void pfe_emac_cfg_pps0_configure(addr_t base_va, bool_t mcgr_en, uint8_t trgtmodsel, bool_t flexible_en)
{
    uint32_t regval = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_PPS_CONTROL));
    
    if (mcgr_en)
    {
        regval |= EMAC_CFG_PPS0_MCGR_ENABLE;
    }
    else
    {
        regval &= ~EMAC_CFG_PPS0_MCGR_ENABLE;
    }
    
    regval &= ~EMAC_CFG_PPS0_TRGTMODSEL0_MASK;
    regval |= EMAC_CFG_PPS0_TRGTMODSEL0(trgtmodsel);
    
    if (flexible_en)
    {
        regval |= EMAC_CFG_PPS0_FLEXIBLE_MODE;
    }
    else
    {
        regval &= ~EMAC_CFG_PPS0_FLEXIBLE_MODE;
    }
    
    hal_write32(regval, ADDR_BASE_OFFSET(base_va, MAC_PPS_CONTROL));
}

/**
 * @brief       Initiate PPS0 event (Flexiple PPS Output Control)
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   cmd PPS command
 */
void pfe_emac_cfg_pps_cmd(addr_t base_va, uint8_t cmd)
{
    uint32_t regval = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_PPS_CONTROL));
    
    regval &= ~EMAC_CFG_PPS_PPSCMD_MASK;
    regval |= cmd;
    
    hal_write32(regval, ADDR_BASE_OFFSET(base_va, MAC_PPS_CONTROL));
}

/**
 * @brief       Configure PPS0 target time
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   seconds value to be filled to seconds register
 * @param[in]   nanoseconds value to be filled to nanoseconds register
 */
void pfe_emac_cfg_pps0_set_target_time(addr_t base_va, uint32_t seconds, uint32_t nanoseconds)
{
    hal_write32(nanoseconds, ADDR_BASE_OFFSET(base_va, MAC_PPS0_TARGET_TIME_NANOSECONDS));
    hal_write32(seconds, ADDR_BASE_OFFSET(base_va, MAC_PPS0_TARGET_TIME_SECONDS));
}

/**
 * @brief       Configure PPS0 period
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   period Period width (in units of PPS counter ticks)
 */
void pfe_emac_cfg_pps0_set_period(addr_t base_va, uint32_t period)
{
    hal_write32(period, ADDR_BASE_OFFSET(base_va, MAC_PPS0_INTERVAL));
}

/**
 * @brief       Configure PPS0 pulse width
 * @param[in]   base_va Base address of MAC register space (virtual)
 * @param[in]   pulse_width Pulse width (in units of PPS counter ticks)
 */
void pfe_emac_cfg_pps0_set_pulse_width(addr_t base_va, uint32_t pulse_width)
{
    hal_write32(pulse_width, ADDR_BASE_OFFSET(base_va, MAC_PPS0_WIDTH));
}

/**
 * @brief       Get number of transmitted packets
 * @param[in]   base_va Base address of EMAC register space (virtual)
 * @return      Number of transmitted packets
 */
uint32_t pfe_emac_cfg_get_tx_cnt(addr_t base_va)
{
    return hal_read32(ADDR_BASE_OFFSET(base_va, TX_PACKET_COUNT_GOOD_BAD));
}

/**
 * @brief       Get number of received packets
 * @param[in]   base_va Base address of EMAC register space (virtual)
 * @return      Number of received packets
 */
uint32_t pfe_emac_cfg_get_rx_cnt(addr_t base_va)
{
    return hal_read32(ADDR_BASE_OFFSET(base_va, RX_PACKETS_COUNT_GOOD_BAD));
}

/**
 * @brief       Reports events corresponding to triggered interrupts to HM
 * @param[in]   id ID of the Peripheral that triggered the interrupt
 * @param[in]   events  List of events, ordered by interrupt flag position (0-31)
 * @param[in]   events_len  Amount of events defined
 * @param[in]   flags   Interrupts flags
 */
static void pfe_emac_cfg_report_hm_event(uint8_t id, const pfe_hm_evt_t events[], uint8_t events_len, uint32_t flags)
{
    static const pfe_hm_src_t hm_src[] =
    {
        HM_SRC_EMAC0,
        HM_SRC_EMAC1,
        HM_SRC_EMAC2,
    };
    uint8_t index = 0U;
    uint32_t isr_flags = flags;
    pfe_hm_src_t src = HM_SRC_EMAC0;
    uint8_t emac_err_src_index = 0U;
#if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
    const Dem_EventIdType emac_dem_err_id[PFE_EMAC_INSTANCES][EMAC_ERR_SRC_NUMBER] =
    {
        {ETH_43_PFE_CFG_DEM_E_EMAC0_ECC_UNCORRECTABLE_ERR, ETH_43_PFE_CFG_DEM_E_EMAC0_ECC_ADDRESS_ERR, ETH_43_PFE_CFG_DEM_E_EMAC0_PARITY_ERR, ETH_43_PFE_CFG_DEM_E_EMAC0_WDT_ERR},
        {ETH_43_PFE_CFG_DEM_E_EMAC1_ECC_UNCORRECTABLE_ERR, ETH_43_PFE_CFG_DEM_E_EMAC1_ECC_ADDRESS_ERR, ETH_43_PFE_CFG_DEM_E_EMAC1_PARITY_ERR, ETH_43_PFE_CFG_DEM_E_EMAC1_WDT_ERR},
        {ETH_43_PFE_CFG_DEM_E_EMAC2_ECC_UNCORRECTABLE_ERR, ETH_43_PFE_CFG_DEM_E_EMAC2_ECC_ADDRESS_ERR, ETH_43_PFE_CFG_DEM_E_EMAC2_PARITY_ERR, ETH_43_PFE_CFG_DEM_E_EMAC2_WDT_ERR}
    };
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */

    if (id < (sizeof(hm_src)/sizeof(hm_src[0U])))
    {
        src = hm_src[id];
        while ((0U != isr_flags) && (index < events_len))
        {
            if ((0U != (isr_flags & 0x1UL)) && (events[index] != HM_EVT_NONE))
            {
                switch (events[index])
                {
                    case HM_EVT_EMAC_ECC_TX_FIFO_CORRECTABLE:
                    case HM_EVT_EMAC_ECC_RX_FIFO_CORRECTABLE:
                    {
                        pfe_hm_report_warning(src, events[index], "");
                        break;
                    }
                    case HM_EVT_EMAC_ECC_TX_FIFO_UNCORRECTABLE:
                    case HM_EVT_EMAC_ECC_RX_FIFO_UNCORRECTABLE:
                    case HM_EVT_EMAC_ECC_TX_FIFO_ADDRESS:
                    case HM_EVT_EMAC_ECC_RX_FIFO_ADDRESS:
                    case HM_EVT_EMAC_APP_TX_PARITY:
                    case HM_EVT_EMAC_APP_RX_PARITY:
                    case HM_EVT_EMAC_MTL_PARITY:
                    case HM_EVT_EMAC_FSM_PARITY:
                    case HM_EVT_EMAC_FSM_TX_TIMEOUT:
                    case HM_EVT_EMAC_FSM_RX_TIMEOUT:
                    case HM_EVT_EMAC_FSM_APP_TIMEOUT:
                    case HM_EVT_EMAC_FSM_PTP_TIMEOUT:
                    case HM_EVT_EMAC_MASTER_TIMEOUT:
                    {
                        emac_err_src_index = pfe_emac_get_emac_err_src_index(events[index]);
                        if (EMAC_ERR_SRC_INDEX_INVALID != emac_err_src_index)
                        {
                            pfe_hm_report_error(src, events[index], "");
#if(STD_ON == ETH_43_PFE_DEM_EVENT_DETECT)
                           (void)Dem_SetEventStatus(emac_dem_err_id[id][emac_err_src_index], DEM_EVENT_STATUS_PREFAILED);
#endif /* ETH_43_PFE_DEM_EVENT_DETECT */
                        }
                        break;
                    }
                    default:
                    {
                        /* Do nothing */
                        break;
                    }
                }
            }
            index++;
            isr_flags >>= 1U;
        }
    }
    else
    {
        NXP_LOG_ERROR("Argument out of range");
    }
}

/**
 * @brief       EMAC ISR
 * @details     Process triggered interrupts.
 * @param[in]   base_va EMAC register space base address
 * @param[in]   cbus_base The PFE CBUS base address
 * @return      EOK if interrupt has been handled, error code otherwise
 */
errno_t pfe_emac_cfg_isr(addr_t base_va, addr_t cbus_base)
{
    uint8_t instance_id = pfe_emac_cfg_get_index(base_va, cbus_base);

    static const pfe_hm_evt_t mtl_ecc_events[] =
    {
        HM_EVT_EMAC_ECC_TX_FIFO_CORRECTABLE,
        HM_EVT_EMAC_ECC_TX_FIFO_ADDRESS,
        HM_EVT_EMAC_ECC_TX_FIFO_UNCORRECTABLE,
        HM_EVT_NONE,
        HM_EVT_EMAC_ECC_RX_FIFO_CORRECTABLE,
        HM_EVT_EMAC_ECC_RX_FIFO_ADDRESS,
        HM_EVT_EMAC_ECC_RX_FIFO_UNCORRECTABLE,
    };

    static const pfe_hm_evt_t dpp_fsm_events[] =
    {
        HM_EVT_EMAC_APP_TX_PARITY,
        HM_EVT_NONE,
        HM_EVT_NONE,
        HM_EVT_EMAC_MTL_PARITY,
        HM_EVT_NONE,
        HM_EVT_EMAC_APP_RX_PARITY,
        HM_EVT_NONE,
        HM_EVT_NONE,
        HM_EVT_EMAC_FSM_TX_TIMEOUT,
        HM_EVT_EMAC_FSM_RX_TIMEOUT,
        HM_EVT_NONE,
        HM_EVT_EMAC_FSM_APP_TIMEOUT,
        HM_EVT_EMAC_FSM_PTP_TIMEOUT,
        HM_EVT_NONE,
        HM_EVT_NONE,
        HM_EVT_NONE,
        HM_EVT_EMAC_MASTER_TIMEOUT,
        HM_EVT_NONE,
        HM_EVT_NONE,
        HM_EVT_NONE,
        HM_EVT_NONE,
        HM_EVT_NONE,
        HM_EVT_NONE,
        HM_EVT_NONE,
        HM_EVT_EMAC_FSM_PARITY,
    };

    uint32_t mtl_ecc_status = hal_read32(ADDR_BASE_OFFSET(base_va, MTL_ECC_INTERRUPT_STATUS));
    uint32_t dpp_fsm_status = hal_read32(ADDR_BASE_OFFSET(base_va, MAC_DPP_FSM_INTERRUPT_STATUS));

    pfe_emac_cfg_report_hm_event(
            instance_id,
            mtl_ecc_events,
            sizeof(mtl_ecc_events)/sizeof(mtl_ecc_events[0]),
            mtl_ecc_status);

    pfe_emac_cfg_report_hm_event(
            instance_id,
            dpp_fsm_events,
            sizeof(dpp_fsm_events)/sizeof(dpp_fsm_events[0]),
            dpp_fsm_status);

    /* Clear interrupts */
    hal_write32(mtl_ecc_status, ADDR_BASE_OFFSET(base_va, MTL_ECC_INTERRUPT_STATUS));
    hal_write32(dpp_fsm_status, ADDR_BASE_OFFSET(base_va, MAC_DPP_FSM_INTERRUPT_STATUS));

    return EOK;
}
#endif

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
