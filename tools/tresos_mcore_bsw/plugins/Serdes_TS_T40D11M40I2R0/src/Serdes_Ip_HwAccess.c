/*
 *  Copyright 2021-2022 NXP
 *
 *  NXP Confidential. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *
 *  This file contains sample code only. It is not part of the production code deliverables.
 */


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Serdes_Ip_HwAccess.h"
#include "StandardTypes.h"
#include "Serdes_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IP_HWACCESS_VENDOR_ID_C                    43
#define SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C     4
#define SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C     4
#define SERDES_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C  0
#define SERDES_IP_HWACCESS_SW_MAJOR_VERSION_C             4
#define SERDES_IP_HWACCESS_SW_MINOR_VERSION_C             0
#define SERDES_IP_HWACCESS_SW_PATCH_VERSION_C             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Serdes_Ip_HwAccess.h file are of the same vendor */
#if (SERDES_IP_HWACCESS_VENDOR_ID_C != SERDES_IP_HWACCESS_VENDOR_ID)
    #error "Serdes_Ip_HwAccess.c and Serdes_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_HwAccess.h file are of the same Autosar version */
#if ((SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C    != SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C    != SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C != SERDES_IP_HWACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip_HwAccess.c and Serdes_Ip_HwAccess.h are different"
#endif
/* Check if current file and Serdes_Ip_HwAccess.h file are of the same software version */
#if ((SERDES_IP_HWACCESS_SW_MAJOR_VERSION_C != SERDES_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (SERDES_IP_HWACCESS_SW_MINOR_VERSION_C != SERDES_IP_HWACCESS_SW_MINOR_VERSION) || \
     (SERDES_IP_HWACCESS_SW_PATCH_VERSION_C != SERDES_IP_HWACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip_HwAccess.c and Serdes_Ip_HwAccess.h are different"
#endif

/* Check if current file and Serdes_Ip_Cfg.h file are of the same vendor */
#if (SERDES_IP_HWACCESS_VENDOR_ID_C != SERDES_IP_CFG_VENDOR_ID)
    #error "Serdes_Ip_HwAccess.c and Serdes_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_Cfg.h file are of the same Autosar version */
#if ((SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C    != SERDES_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C    != SERDES_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_HWACCESS_AR_RELEASE_REVISION_VERSION_C != SERDES_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip_HwAccess.c and Serdes_Ip_Cfg.h are different"
#endif
/* Check if current file and Serdes_Ip_Cfg.h file are of the same software version */
#if ((SERDES_IP_HWACCESS_SW_MAJOR_VERSION_C != SERDES_IP_CFG_SW_MAJOR_VERSION) || \
     (SERDES_IP_HWACCESS_SW_MINOR_VERSION_C != SERDES_IP_CFG_SW_MINOR_VERSION) || \
     (SERDES_IP_HWACCESS_SW_PATCH_VERSION_C != SERDES_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip_HwAccess.c and Serdes_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h file are of the same Autosar version */
    #if ((SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Serdes_Ip_HwAccess.c and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define SERDES_IP_XPCS_BASE(xpcs) (((xpcs) == 0U)  ? (SERDES_IP_XPCS_0_ADDR2) : (SERDES_IP_XPCS_1_ADDR2))
#define SERDES_IP_HAL_WRITE32(val, addr)  (*(volatile uint32 *)(addr) = ((uint32)(val)))
#define SERDES_IP_HAL_READ32(addr)        (*(volatile uint32 *)(addr))

/* Define the values that the power up sequence takes */
#define SERDES_IP_XPCS_PSEQ_POWER_GOOD_TX_RX           (0x04U)
#define SERDES_IP_XPCS_PSEQ_POWER_SAVE                 (0x05U)
#define SERDES_IP_XPCS_PSEQ_POWER_DOWN                 (0x06U)

#define SERDES_IP_PCSW16(serdes_base, pcs, reg, val) \
do {\
    Serdes_Ip_XpcsWriteGen2(serdes_base, pcs, reg, val);\
} while (0)

#define SERDES_IP_PCSBCLR(serdes_base, pcs, reg, mask) \
do {\
    uint32 u32TmpVal = Serdes_Ip_XpcsReadGen2(serdes_base, pcs, reg);\
    Serdes_Ip_XpcsWriteGen2(serdes_base, pcs, reg, (u32TmpVal) & ~(mask));\
} while (0)

#define SERDES_IP_PCSBSET(serdes_base, pcs, reg, mask) \
do {\
    uint32 u32TmpVal = Serdes_Ip_XpcsReadGen2(serdes_base, pcs, reg);\
    Serdes_Ip_XpcsWriteGen2(serdes_base, pcs, reg, (u32TmpVal) | (mask));\
} while (0)
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define SERDES_IP_PCSBCLRSET(serdes_base, pcs, reg, clr_mask, mask) \
do {\
    uint32 u32TmpVal = Serdes_Ip_XpcsReadGen2(serdes_base, pcs, reg);\
    Serdes_Ip_XpcsWriteGen2(serdes_base, pcs, reg, ((u32TmpVal) & ~(clr_mask)) | (mask));\
} while (0)

#define SERDES_START_SEC_CODE
#include "Serdes_MemMap.h"
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
static uint32 Serdes_Ip_XpcsReadGen2(uint32 Base,
                                     uint32 Xpcs,
                                     uint32 Reg
                                    )
{
    /* Get address for indirect access */
    uint32 OfsLeft = (Reg >> 8) & 0xffffU;
    uint32 OfsRight = (Reg & 0xffU);
    uint32 PcsOff = SERDES_IP_XPCS_BASE(Xpcs);

    SERDES_IP_HAL_WRITE32(OfsLeft, (uint32)Base + PcsOff + 0x3fcU);
    return SERDES_IP_HAL_READ32((uint32)Base + PcsOff + (4U * OfsRight)) & 0xffffU;
}

static void Serdes_Ip_XpcsWriteGen2(uint32 Base,
                                    uint32 Xpcs,
                                    uint32 Reg,
                                    uint32 Val
                                   )
{
    /* Get address for indirect access */
    uint32 OfsLeft = (Reg >> 8U) & 0xffffU;
    uint32 OfsRight = (Reg & 0xffU);
    uint32 PcsOff = SERDES_IP_XPCS_BASE(Xpcs);

    SERDES_IP_HAL_WRITE32(OfsLeft, (uint32)Base + PcsOff + 0x3fcU);
    SERDES_IP_HAL_WRITE32(Val, (uint32)Base + PcsOff + (4U * OfsRight));
}

static boolean Serdes_Ip_PcsCheckBits(uint32 Base,
                                      uint32 Xpcs,
                                      uint32 Reg,
                                      uint16 Mask,
                                      uint16 Val
                                     )
{
    boolean RetVal = FALSE;

    /* Check bits value */
    if ((Serdes_Ip_XpcsReadGen2(Base, Xpcs, Reg) & Mask) == Val)
    {
       RetVal = TRUE;
    }

    return RetVal;
}

static Serdes_Ip_StatusType Serdes_Ip_PcsWaitBits(uint32 Base,
                                                  uint32 Xpcs,
                                                  uint32 Reg,
                                                  uint16 Mask,
                                                  uint16 Val
                                                 )
{
    uint32 StartTime, ElapsedTime, TimeoutTicks;
    uint32 ReadBits;
    boolean Timeout;

     /* Wait for bits to stabilize */
    Serdes_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, SERDES_IP_TIMEOUT_U32);

    do
    {
        Timeout = Serdes_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        ReadBits = Serdes_Ip_XpcsReadGen2(Base, Xpcs, Reg);
        ReadBits &= Mask;

    } while ((FALSE == Timeout) && (ReadBits != Val));

    return (FALSE == Timeout) ? SERDES_IP_SUCCESS : SERDES_IP_ERROR;
}

/**
* @brief        Issue vendor specific reset
*/
static void Serdes_Ip_PcsIssueVReset(uint32 Base,
                                     uint32 Xpcs
                                    )
{
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_VR_RST_U32);
}

/**
* @brief        Configure XPCS to 2.5G mode
*/
static void Serdes_Ip_PcsSet2500mMode(uint32 Base,
                                      uint32 Xpcs
                                     )
{
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_EN_2_5G_MODE_U32);
}

/**
* @brief        Configure XPCS to 1G mode
*/
static void Serdes_Ip_PcsSet1000mMode(uint32 Base,
                                      uint32 Xpcs
                                     )
{
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_EN_2_5G_MODE_U32);
}

/**
* @brief        Peform lane TX ctr config
*/
static void Serdes_Ip_PmaConfigureTxCtr(uint32 Base,
                                        uint32 Xpcs
                                       )
{
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_Gen5_12G_16G_TX_EQ_CTRL0,
               (uint32)0x3fU << 8U,
               (uint32)0xCU << 8U);
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_Consumer_10G_TX_TERM_CTRL,
               0x7U,
               0x4U);
}

/**
* @brief        Disable PMA lane
*/
static void Serdes_Ip_PmaLaneDisable(uint32 Base,
                                     uint32 Xpcs
                                    )
{
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_Gen5_12G_16G_TX_POWER_STATE_CTRL, SERDES_IP_TX_DISABLE_0_U32);
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_Gen5_12G_16G_RX_POWER_STATE_CTRL, SERDES_IP_RX_DISABLE_0_U32);
}

/**
* @brief        Configure VCO (for fast PLLA)
* @details      Configure VCO parameters based on PLL. Befre this call it is expected that the lane
                reference is fast PLLA.
*/
static void Serdes_Ip_Pma1250MhzPrepare(uint32 Base,
                                        uint32 Xpcs,
                                        Serdes_Ip_ClockType Fmhz
                                       )
{
    uint16 VcoCalLd, VcoCalRef;

    if (Fmhz == SERDES_CLK_100MHZ)
    {
        VcoCalLd = 1350U;
        VcoCalRef = 27U;
    }
    else
    {
        VcoCalLd = 1360U;
        VcoCalRef = 17U;
    }
    /* RX VCO calibration value */
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_VCO_CAL_LD0,
           0x1fffU,
           VcoCalLd);

    /* VCO calibration reference */
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_VCO_CAL_REF0,
           0x3fU,
           VcoCalRef);

    /* TX rate baud/4 (baud 1250Mhz) */
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_TX_RATE_CTRL,
           0x7U,
           0x2U); /* b010 */

    /* Rx rate baud/8 (baud 1250Mhz) */
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_RX_RATE_CTRL,
           0x3U,
           0x3U); /* b11 */

    /* Clear low-frequency operating band */
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_CDR_CTRL, SERDES_IP_VCO_LOW_FREQ_0_U32);
}

/**
* @brief        Configure VCO (for fast PLLB)
* @details      Configure VCO parameters based on PLL. Befre this call it is expected that the lane
                reference is fast PLLB.
*/
static void Serdes_Ip_Pma3125MhzPrepare(uint32 Base,
                                        uint32 Xpcs,
                                        Serdes_Ip_ClockType Fmhz
                                       )
{
    uint16 VcoCalLd, VcoCalRef;

    if (Fmhz == SERDES_CLK_100MHZ)
    {
        VcoCalLd = 1344U;
        VcoCalRef = 43U;
    }
    else
    {
        VcoCalLd = 1350U;
        VcoCalRef = 27U;
    }
    /* RX VCO calibration value */
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_VCO_CAL_LD0,
           0x1fffU,
           VcoCalLd);

    /* VCO calibration reference */
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_VCO_CAL_REF0,
           0x3fU,
           VcoCalRef);

    /* TX rate baud  */
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_TX_RATE_CTRL,
           0x7U,
           0x0U);

    /* Rx rate baud/2 */
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_RX_RATE_CTRL,
           0x3U,
           0x1U);

    /* Set low-frequency operating band */
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_CDR_CTRL, SERDES_IP_VCO_LOW_FREQ_0_U32);
}

/**
* @brief        Configure slow PLLA parameters
* @details      Initize slow PLLA with either 100Mhz/125Mhz reference.
* @warning      PLL has to be configured from instace with phy control before issuing verndor reset.
*/
static void Serdes_Ip_PmaMpllaStartCal(uint32 Base,
                                       uint32 Xpcs,
                                       Serdes_Ip_ClockType Fmhz
                                      )
{
    if (Fmhz == SERDES_CLK_100MHZ)
    {
        SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_REF_CLK_CTRL,
               SERDES_IP_REF_RANGE_U32(0x7U) | SERDES_IP_REF_CLK_DIV2_U32 | SERDES_IP_REF_MPLLA_DIV2_U32,
               SERDES_IP_REF_RANGE_U32(3U) | SERDES_IP_REF_CLK_EN_U32);

        /* Clear multiplier and set it to 25 and enable PPL cal */
        SERDES_IP_PCSBCLRSET(Base, Xpcs, (uint32)SERDES_IP_VR_MII_GEN5_12G_16G_MPLLA_CTRL0,
                       SERDES_IP_MPLLA_MULTIPLIER_VALUE_U32(0xFFU) | SERDES_IP_MPLLA_CAL_DISABLE_U32,
                       SERDES_IP_MPLLA_MULTIPLIER_VALUE_U32(25U));

    }
    else
    {
        /* Set reference range, dive reference clock by 2, divide the pll output by 2*/
        SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_REF_CLK_CTRL,
               SERDES_IP_REF_RANGE_U32(0x7U),
               SERDES_IP_REF_RANGE_U32(2U) | SERDES_IP_REF_CLK_DIV2_U32 | SERDES_IP_REF_MPLLA_DIV2_U32 | SERDES_IP_REF_CLK_EN_U32);

        /* Clear multiplier and set it to 80 and enable PPL cal */
        SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLLA_CTRL0,
               SERDES_IP_MPLLA_MULTIPLIER_VALUE_U32(0xFFU) | SERDES_IP_MPLLA_CAL_DISABLE_U32,
               SERDES_IP_MPLLA_MULTIPLIER_VALUE_U32(80U));
    }

    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_MPLLA_CTRL1, 0xffe0U);

    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLLA_CTRL2,
           SERDES_IP_MPLLA_TX_CLK_DIV_U32(0x7U),
           SERDES_IP_MPLLA_TX_CLK_DIV_U32(1U) | SERDES_IP_MPLLA_DIV10_CLK_EN_U32);

    if (Fmhz == SERDES_CLK_100MHZ)
    {
        SERDES_IP_PCSW16(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_MPLLA_CTRL3, 357U);
    }
    else
    {
        SERDES_IP_PCSW16(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_MPLLA_CTRL3, 43U);
    }
}

/**
* @brief        Configure fast PLLB parameters
* @details      Initize fast PLLB with either 100Mhz/125Mhz reference.
* @warning      PLL has to be configured from instace with phy control before issuing verndor reset.
*/
static void Serdes_Ip_PmaMpllbStartCal(uint32 Base,
                                       uint32 Xpcs,
                                       Serdes_Ip_ClockType Fmhz
                                      )
{
    if (Fmhz == SERDES_CLK_100MHZ)
    {
        SERDES_IP_PCSBCLRSET(Base, Xpcs, (uint32)SERDES_IP_VR_MII_GEN5_12G_16G_REF_CLK_CTRL,
               SERDES_IP_REF_RANGE_U32(0x7U) | SERDES_IP_REF_CLK_DIV2_U32 | SERDES_IP_REF_MPLLB_DIV2_U32,
               SERDES_IP_REF_RANGE_U32(0x3U) | SERDES_IP_REF_CLK_EN_U32);

        /* Clear multiplier and set it to 25 and enable PPL cal */
        SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLLB_CTRL0,
               SERDES_IP_MPLLB_MULTIPLIER_U32(0xffU) | SERDES_IP_MPPLB_CAL_DISABLE_U32,
               SERDES_IP_MPLLB_MULTIPLIER_U32(0x27U));

    }
    else
    {
        /* Set reference range, dive reference clock by 2, divide the pll output by 2*/
        SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_REF_CLK_CTRL,
               SERDES_IP_REF_RANGE_U32(0x7U),
               SERDES_IP_REF_RANGE_U32(0x2U) | SERDES_IP_REF_MPLLB_DIV2_U32 | SERDES_IP_REF_CLK_DIV2_U32 | SERDES_IP_REF_CLK_EN_U32);

        /* Clear multiplier and set it to 125 and enable PPL cal */
        SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLLB_CTRL0,
               SERDES_IP_MPLLB_MULTIPLIER_U32(0xffU) | SERDES_IP_MPPLB_CAL_DISABLE_U32,
               SERDES_IP_MPLLB_MULTIPLIER_U32(125U));
    }

    /* Clear the fraction divider */
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_MPLLB_CTRL1, 0xffe0U);

    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLLB_CTRL2,
           SERDES_IP_MPLLB_TX_CLK_DIV_U32(0x7U),
           SERDES_IP_MPLLB_TX_CLK_DIV_U32(0x5U) | SERDES_IP_MPLLB_DIV10_CLK_EN_U32);

    if (Fmhz == SERDES_CLK_100MHZ)
    {
        /* Set fraction divider */
        SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_MPLLB_CTRL1, (uint32)0x414U << 5U);

        /* PLL bandwidth */
        SERDES_IP_PCSW16(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_MPLLB_CTRL3, 0x66U);
    }
    else
    {

        /* PLL bandwidth */
        SERDES_IP_PCSW16(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_MPLLB_CTRL3, 68U);
    }
}

/**
* @brief        Disable PLLA
*/
static void Serdes_Ip_PmaMpllaStopCal(uint32 Base,
                                      uint32 Xpcs
                                     )
{
    /* Disable PLLB calibration */
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLLA_CTRL0, SERDES_IP_MPLLA_CAL_DISABLE_U32);
}

/**
* @brief        Disable PLLB
*/
static void Serdes_Ip_PmaMpllbStopCal(uint32 Base,
                                      uint32 Xpcs
                                     )
{
    /* Disable PLLB calibration */
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLLB_CTRL0, SERDES_IP_MPPLB_CAL_DISABLE_U32);

}

/**
* @brief        Select PLLA as reference for XPCS
*/
static void Serdes_Ip_PmaSelectPllaRef(uint32 Base,
                                       uint32 Xpcs
                                      )
{
    /* Select PLLA */
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLL_CMN_CTRL, SERDES_IP_MPLLB_SEL_0_U32);
    /* Enable PLL */
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLL_CMN_CTRL, SERDES_IP_MPLL_EN_0_U32);
}

/**
* @brief        Select PLLB as reference for XPCS
*/
static void Serdes_Ip_PmaSelectPllbRef(uint32 Base,
                                       uint32 Xpcs
                                      )
{
    /* Select PLLB */
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLL_CMN_CTRL, SERDES_IP_MPLLB_SEL_0_U32);
    /* Enable PLL */
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_GEN5_12G_16G_MPLL_CMN_CTRL, SERDES_IP_MPLL_EN_0_U32);
}

/**
* @brief        Get the Xpcs with the PHY control
*/
static uint32 Serdes_Ip_PcsPhyControl(uint32 InitFlags)
{
    uint32 XpcsPhyCtr = 0U;

    if ((InitFlags & SERDES_IP_PHY_CTRL_XPCS_OWNED) != 0U)
    {
        if ((InitFlags & SERDES_IP_XPCS0_OWNED_U32) != 0U)
        {
            XpcsPhyCtr = 0U;
        }
        else if ((InitFlags & SERDES_IP_XPCS1_OWNED_U32) != 0U)
        {
            XpcsPhyCtr = 1U;
        }
        else
        {
            /* No changes to XpcsPhyCtr */
        }
    }

    return XpcsPhyCtr;
}

static void Serdes_Ip_PcsBypassClockXpcs0(uint32 Base,
                                          uint32 InitFlags
                                         )
{
    /* Set bypass flag in case of internal clocks */
    if (((InitFlags & SERDES_PHY_CLK_INT) != 0U) && ((InitFlags & (SERDES_IP_XPCS0_OWNED)) != 0U))
    {
        SERDES_IP_PCSBSET(Base, 0U, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_EN_VSMMD1_U32 | SERDES_IP_BYP_PWRUP_U32);
    }
    else if ((InitFlags & (SERDES_IP_XPCS0_OWNED)) != 0U)
    {
        SERDES_IP_PCSBCLRSET(Base, 0U, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_BYP_PWRUP_U32, SERDES_IP_EN_VSMMD1_U32);
    }
    else
    {
        /* do nothing */
    }
}

static void Serdes_Ip_PcsBypassClockXpcs1(uint32 Base,
                                          uint32 InitFlags
                                         )
{
    /* Set bypass flag in case of internal clocks */
    if (((InitFlags & SERDES_PHY_CLK_INT) != 0U) && ((InitFlags & (SERDES_IP_XPCS1_OWNED)) != 0U))
    {
        SERDES_IP_PCSBSET(Base, 1U, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_EN_VSMMD1_U32 | SERDES_IP_BYP_PWRUP_U32);
    }
    else if ((InitFlags & (SERDES_IP_XPCS1_OWNED)) != 0U)
    {
        SERDES_IP_PCSBCLRSET(Base, 1U, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_BYP_PWRUP_U32, SERDES_IP_EN_VSMMD1_U32);
    }
    else
    {
        /* do nothing */
    }
}

static void Serdes_Ip_PcsSelectPll(uint32 Base,
                                   uint32 InitFlags
                                  )
{
    /* Configure pll for xpcs0 */
    if ((InitFlags & SERDES_IP_XPCS0_2500M_U32) != 0U)
    {
        Serdes_Ip_PmaConfigureTxCtr(Base, 0U);
        Serdes_Ip_PcsSet2500mMode(Base, 0U);
        Serdes_Ip_PmaSelectPllbRef(Base, 0U);
    }
    else if ((InitFlags & SERDES_IP_XPCS0_1000M_U32) != 0U)
    {
        Serdes_Ip_PmaConfigureTxCtr(Base, 0U);
        Serdes_Ip_PcsSet1000mMode(Base, 0U);
        Serdes_Ip_PmaSelectPllaRef(Base, 0U);
    }
    else
    {
        /* do nothing */
    }

    /* Configure pll for xpcs1 */
    if ((InitFlags & SERDES_IP_XPCS1_2500M_U32) != 0U)
    {
        Serdes_Ip_PmaConfigureTxCtr(Base, 1U);
        Serdes_Ip_PcsSet2500mMode(Base, 1U);
        Serdes_Ip_PmaSelectPllbRef(Base, 1U);
    }
    else if ((InitFlags & SERDES_IP_XPCS1_1000M_U32) != 0U)
    {
        Serdes_Ip_PmaConfigureTxCtr(Base, 1U);
        Serdes_Ip_PcsSet1000mMode(Base, 1U);
        Serdes_Ip_PmaSelectPllaRef(Base, 1U);
    }
    else
    {
        /* do nothing */
    }
}

static void Serdes_Ip_PcsConfigPll(uint32 Base,
                                   uint32 InitFlags,
                                   Serdes_Ip_ClockType Fmhz,
                                   uint32 XpcsPhyCtr
                                  )
{
    /* Start PLLA cal */
    if (((InitFlags & SERDES_IP_PHY_CTRL_XPCS_OWNED) != 0U) && ((InitFlags & SERDES_IP_PLLA_CAL_EN_U32) != 0U))
    {
        /* Configure PLLA and start calibration */
        Serdes_Ip_PmaMpllaStartCal(Base, XpcsPhyCtr, Fmhz);
    }

    /* Start PLLB cal */
    if (((InitFlags & SERDES_IP_PHY_CTRL_XPCS_OWNED) != 0U) && ((InitFlags & SERDES_IP_PLLB_CAL_EN_U32) != 0U))
    {
        Serdes_Ip_PmaMpllbStartCal(Base, XpcsPhyCtr, Fmhz);
    }

    /* Disable PLLA, if requested */
    if (((InitFlags & SERDES_IP_PHY_CTRL_XPCS_OWNED) != 0U) && ((InitFlags & SERDES_IP_PLLA_CAL_DIS_U32) != 0U))
    {
        Serdes_Ip_PmaMpllaStopCal(Base, XpcsPhyCtr);
    }

    /* Disable PLLB, if requested */
    if (((InitFlags & SERDES_IP_PHY_CTRL_XPCS_OWNED) != 0U) && ((InitFlags & SERDES_IP_PLLB_CAL_DIS_U32) != 0U))
    {
        Serdes_Ip_PmaMpllbStopCal(Base, XpcsPhyCtr);
    }
}

static void Serdes_Ip_PcsConfLowLayers(uint32 Base,
                                       Serdes_Ip_ClockType Fmhz,
                                       uint32 InitFlags
                                      )
{
    /* Configure lower layers to use correct speed */
    if ((InitFlags & SERDES_IP_XPCS0_2500M_U32) != 0U)
    {
        Serdes_Ip_Pma3125MhzPrepare(Base, 0U, Fmhz);
    }
    else if ((InitFlags & SERDES_IP_XPCS0_1000M_U32) != 0U)
    {
        Serdes_Ip_Pma1250MhzPrepare(Base, 0U, Fmhz);
    }
    else
    {
        /* do nothing */
    }

    /* Configure lower layers to use correct speed */
    if ((InitFlags & SERDES_IP_XPCS1_2500M_U32) != 0U)
    {
        Serdes_Ip_Pma3125MhzPrepare(Base, 1U, Fmhz);
    }
    else if ((InitFlags & SERDES_IP_XPCS1_1000M_U32) != 0U)
    {
        Serdes_Ip_Pma1250MhzPrepare(Base, 1U, Fmhz);
    }
    else
    {
        /* do nothing */
    }
}

static void Serdes_Ip_PcsDisLane(uint32 Base,
                                 uint32 InitFlags
                                )
{
    if ((InitFlags & SERDES_IP_XPCS0_DIS_U32) != 0U)
    {
        /* Skip init, if we don't care about the lane */
        SERDES_IP_PCSBSET(Base, 0U, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_EN_VSMMD1_U32 | SERDES_IP_BYP_PWRUP_U32);
        Serdes_Ip_PmaLaneDisable(Base, 0U);
    }

    if ((InitFlags & SERDES_IP_XPCS1_DIS_U32) != 0U)
    {
        /* Skip init, if we don't care about the lane */
        SERDES_IP_PCSBSET(Base, 1U, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_EN_VSMMD1_U32 | SERDES_IP_BYP_PWRUP_U32);
        Serdes_Ip_PmaLaneDisable(Base, 1U);
    }
}

/**
 * @brief   Indirect write PHY register.
 * @param[in]   addr    Indirect PHY address (16bit).
 * @param[in]   wdata   Indirect PHY data to be written (16 bit).
 */
static void Serdes_Ip_PhyRegWrite(SerDes_SS_Type *Base,
                                  uint16 Address,
                                  uint16 Data,
                                  uint16 Mask
                                 )
{
    uint32 Count  = 100U;
    uint32 TmpData = (uint32)((uint32)Data & (uint32)Mask);

    Base->PHY_REG_ADDR = (uint32)((uint32)((uint32)SerDes_SS_PHY_REG_ADDR_ADDR_MASK & (uint32)Address) | (uint32)SerDes_SS_PHY_REG_ADDR_PHY_REG_EN_MASK);

    while (0UL != Count)
    {
        /* Wait */
        Count--;
    }

    if (Mask == 0xFFFFU)
    {
       Base->PHY_REG_DATA = TmpData;
    }
    else
    {
        Base->PHY_REG_DATA &= ~(uint32)Mask;

        Base->PHY_REG_DATA |= TmpData;
    }

    Count = 100U;

    while (0UL != Count)
    {
        /* Wait */
        Count--;
    }
}

/* Assert cold reset */
static void Serdes_Ip_SsAssertColdReset(uint32 Base)
{
    uint32 tmp = SERDES_IP_HAL_READ32((uint32)Base + SERDES_IP_SS_BASE + SERDES_IP_SS_RST_CTRL);

    SERDES_IP_HAL_WRITE32(tmp | SERDES_IP_COLD_RST_U32, (uint32)Base + SERDES_IP_SS_BASE + SERDES_IP_SS_RST_CTRL);
}

/* Deassert cold reset */
static void Serdes_Ip_SsDeassertColdReset(uint32 Base)
{
    uint32 tmp = SERDES_IP_HAL_READ32((uint32)Base + SERDES_IP_SS_BASE + SERDES_IP_SS_RST_CTRL);

    SERDES_IP_HAL_WRITE32(tmp & ~ SERDES_IP_COLD_RST_U32, (uint32)Base + SERDES_IP_SS_BASE + SERDES_IP_SS_RST_CTRL);
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief         Serdes_Ip_StartTimeout
* @details       Serdes_Ip_StartTimeout
*
*
* @param[in]     *StartTimeOut
* @param[in]     *ElapsedTimeOut
* @param[in]     TimeoutUs
* @return        void
* @pre           The driver needs to be initialized.
*/
void Serdes_Ip_StartTimeout(uint32 *StartTimeOut,
                            uint32 *ElapsedTimeOut,
                            uint32 *TimeoutTicksOut,
                            uint32 TimeoutUs
                           )
{
    *StartTimeOut    = OsIf_GetCounter(SERDES_IP_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, SERDES_IP_TIMEOUT_TYPE);
}

/**
* @brief         Serdes_Ip_TimeoutExpired
* @details       Serdes_Ip_TimeoutExpired
*
*
* @param[in]     *StartTimeInOut
* @param[in]     *ElapsedTimeInOut
* @param[in]     TimeoutTicks
* @return        TRUE/FALSE
* @pre           The driver needs to be initialized.
*/
boolean Serdes_Ip_TimeoutExpired(uint32 *StartTimeInOut,
                                 uint32 *ElapsedTimeInOut,
                                 uint32 TimeoutTicks
                                )
{
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, SERDES_IP_TIMEOUT_TYPE);

    return ((*ElapsedTimeInOut >= TimeoutTicks)? TRUE : FALSE);
}

/**
* @brief        Wait for power good state
*/
Serdes_Ip_StatusType  Serdes_Ip_PcsWaitForPowerGood(uint32 Base,
                                                    uint32 Xpcs
                                                   )
{
    return Serdes_Ip_PcsWaitBits(Base, Xpcs, SERDES_IP_VR_MII_DIG_STS,
                    0x7U << 2, SERDES_IP_XPCS_PSEQ_POWER_GOOD_TX_RX << 2U);
}

/* Deassert PCIe warm reset */
void Serdes_Ip_PcieDeassertWarmReset(uint32 Base)
{
   uint32 u32TmpVal = SERDES_IP_HAL_READ32((uint32)Base + SERDES_IP_SS_RST_CTRL);

   SERDES_IP_HAL_WRITE32(((u32TmpVal) & ~((uint32)(2U))), (uint32)Base + SERDES_IP_SS_RST_CTRL);
}

/* set power save state */
void Serdes_Ip_SetPowerSaveMode(uint32 Base,
                                uint32 Xpcs
                               )
{
    Serdes_Ip_StatusType Status;

    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_PWRSV_U32);
    Status = Serdes_Ip_PcsWaitBits(Base, Xpcs, SERDES_IP_VR_MII_DIG_STS, 0x7U << 2, SERDES_IP_XPCS_PSEQ_POWER_SAVE << 2U);
    /* Cast to void to avoid compiler warnings */
    (void) Status;
}

/* set power down state */
void Serdes_Ip_SetPowerDownMode(uint32 Base,
                                uint32 Xpcs
                               )
{
    Serdes_Ip_StatusType Status;

    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_SR_MII_CTRL, SERDES_IP_MII_CTRL_LPM_U32);
    Status = Serdes_Ip_PcsWaitBits(Base, Xpcs, SERDES_IP_VR_MII_DIG_STS, 0x7U << 2, SERDES_IP_XPCS_PSEQ_POWER_DOWN << 2U);
    /* Cast to void to avoid compiler warnings */
    (void) Status;
}

/* set power up state */
void Serdes_Ip_SetPowerUpMode(uint32 Base,
                              uint32 Xpcs,
                              Serdes_Ip_XpcsModeType XPCSMode
                             )
{
    uint32 StartTime, ElapsedTime, TimeoutTicks;
    boolean Timeout;
    Serdes_Ip_StatusType Status;

    if (SERDES_IP_XPCS_POWER_SAVE == XPCSMode)
    {
        SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_VR_RST_U32);
        /* Wait for bits to stabilize */
        Serdes_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, SERDES_IP_TIMEOUT_U32);

        /* Wait until bits are ready */
        do
        {
            Timeout = Serdes_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

        } while (FALSE == Timeout);
        SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_PWRSV_U32);
        Status = Serdes_Ip_PcsWaitBits(Base, Xpcs, SERDES_IP_VR_MII_DIG_STS, 0x7U << 2, SERDES_IP_XPCS_PSEQ_POWER_GOOD_TX_RX << 2U);
    }
    else if (SERDES_IP_XPCS_POWER_DOWN == XPCSMode)
    {
        SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_SR_MII_CTRL, SERDES_IP_MII_CTRL_RST_U32);
        /* Wait for bits to stabilize */
        Serdes_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, SERDES_IP_TIMEOUT_U32);

        /* Wait until bits are ready */
        do
        {
            Timeout = Serdes_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

        } while (FALSE == Timeout);
        SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_SR_MII_CTRL, SERDES_IP_MII_CTRL_LPM_U32);
        Status = Serdes_Ip_PcsWaitBits(Base, Xpcs, SERDES_IP_VR_MII_DIG_STS, 0x7U << 2, SERDES_IP_XPCS_PSEQ_POWER_GOOD_TX_RX << 2U);
    }
    else
    {
        /* Do nothing */
    }
    /* Cast to void to avoid compiler warnings */
    (void) Status;
}

/* Assert PCIe warm reset */
void Serdes_Ip_PcieAssertWarmReset(uint32 Base)
{
    uint32 u32TmpVal = SERDES_IP_HAL_READ32((uint32)Base + SERDES_IP_SS_RST_CTRL);

    SERDES_IP_HAL_WRITE32(((u32TmpVal) | ((uint32)(2U))), (uint32)Base + SERDES_IP_SS_RST_CTRL);
}

/**
* @brief        Speed select
*/
Serdes_Ip_StatusType Serdes_Ip_PcsSpeedSelect(uint32 Base,
                                              uint32 Xpcs,
                                              uint32 Scaler
                                            )
{
    uint16 Reg = 0U;
    Serdes_Ip_StatusType RetVal = SERDES_IP_SUCCESS;

    switch (Scaler) {
    case 100U:
        break;

    case 10U:
        Reg |= (uint16)SERDES_IP_MII_CTRL_SS13_U32;
        break;

    case 1U:
        Reg |= (uint16)SERDES_IP_MII_CTRL_SS6_U32;
        break;

    default:
        /*  Unsupported value */
        RetVal = SERDES_IP_ERROR;
        break;
    }

    if (SERDES_IP_SUCCESS == RetVal)
    {
        SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_SR_MII_CTRL,
               SERDES_IP_MII_CTRL_SS13_U32 | SERDES_IP_MII_CTRL_SS6_U32,
               Reg);
    }

    return RetVal;
}

/**
* @brief        Configure full duplex
*/
void Serdes_Ip_PcsSetFd(uint32 Base,
                        uint32 Xpcs
                       )
{
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_SR_MII_CTRL, SERDES_IP_MII_CTRL_DUPLEX_MODE_U32);
}

/**
* @brief        Configure half duplex
*/
void Serdes_Ip_PcsSetHd(uint32 Base,
                        uint32 Xpcs
                       )
{
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_SR_MII_CTRL, SERDES_IP_MII_CTRL_DUPLEX_MODE_U32);
}

/**
* @brief        Enable MII bus width control in PCS
* @details      MII bus is in 1G 8bit and other speeds 4bit
*/
void Serdes_Ip_PcsMiiBusControlEnable(uint32 Base,
                                      uint32 Xpcs
                                     )
{
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_AN_CTRL, SERDES_IP_VR_MII_AN_CTRL_MII_CTRL_MASK);
}

/**
* @brief        Enable SGMII AN
*/
void Serdes_Ip_PcsAnEnable(uint32 Base,
                           uint32 Xpcs
                          )
{
    /* Select SGMII type AN, enable interrupt */
    SERDES_IP_PCSBCLRSET(Base, Xpcs, SERDES_IP_VR_MII_AN_CTRL,
            (SERDES_IP_VR_MII_AN_CTRL_PCS_MODE_MASK | SERDES_IP_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK),
            (SERDES_IP_VR_MII_AN_CTRL_PCS_MODE_U32(SERDES_IP_PCS_MODE_SGMII) | SERDES_IP_VR_MII_AN_CTRL_MII_AN_INTR_EN_U32(0x1U))
            );

    /* Enable SGMII AN */
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_SR_MII_CTRL, SERDES_IP_MII_CTRL_AN_ENABLE_U32);
}

/**
* @brief        Disable SGMII AN
*/
void Serdes_Ip_PcsAnDisable(uint32 Base,
                            uint32 Xpcs
                           )
{
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_SR_MII_CTRL, SERDES_IP_MII_CTRL_AN_ENABLE_U32);
    /* Disable interrupt */
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_AN_CTRL, SERDES_IP_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK);
}

/**
* @brief        Restart SGMII AN
*/
Serdes_Ip_StatusType Serdes_Ip_PcsAnRestart(uint32 Base,
                                            uint32 Xpcs
                                           )
{
    Serdes_Ip_StatusType RetStatus;

    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_SR_MII_CTRL, SERDES_IP_MII_CTRL_RESTART_AN_U32);

    /* Wait for auto-negotiation to complete */
    RetStatus = Serdes_Ip_PcsWaitBits(Base, Xpcs, (uint32)SERDES_IP_VR_MII_AN_INTR_STS, (uint16)SERDES_IP_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK, 1U);

    if (SERDES_IP_SUCCESS == RetStatus)
    {
        /* Clear auto-negotiation complete bit */
        SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_AN_INTR_STS, SERDES_IP_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK);
    }

    return RetStatus;
}

/**
* @brief        Disable automatic speed change
*/
void Serdes_Ip_PcsAnAutoSwDisable(uint32 Base,
                                  uint32 Xpcs
                                 )
{
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_MAC_AUTO_SW_U32);
}

/**
* @brief        Configure SGMII AN link timer
* @details      This can be any value. Recommended is 0x2fafU.
*/
void Serdes_Ip_PcsAnSetLinkTimer(uint32 Base,
                                 uint32 Xpcs,
                                 uint16 LinkTimer
                                )
{
    SERDES_IP_PCSW16(Base, Xpcs, SERDES_IP_VR_MII_LINK_TIMER_CTRL, LinkTimer);
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_CL37_TMR_OVR_RIDE_U32);
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_CL37_TMR_OVR_RIDE_U32);
}

/**
* @brief        Peform lane RX reset
*/
void Serdes_Ip_PmaIssueRxReset(uint32 Base,
                               uint32 Xpcs
                              )
{
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_VR_MII_Gen5_12G_16G_RX_GENCTRL1, SERDES_IP_RX_RST_0_U32);
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_VR_MII_Gen5_12G_16G_RX_GENCTRL1, SERDES_IP_RX_RST_0_U32);
}

/**
* @brief        Enable PMA loopback
* @details      Looback of analog transceiver to analog receiver.
*/
void Serdes_Ip_PmaLoopbackEnable(uint32 Base,
                                 uint32 Xpcs
                                )
{
    SERDES_IP_PCSBSET(Base, Xpcs, SERDES_IP_SR_MII_CTRL, SERDES_IP_LBE_U32);
}

/**
* @brief        Disable PMA loopback
* @details      Looback of analog transceiver to analog receiver.
*/
void Serdes_Ip_PmaLoopbackDisable(uint32 Base,
                                  uint32 Xpcs
                                 )
{
    SERDES_IP_PCSBCLR(Base, Xpcs, SERDES_IP_SR_MII_CTRL, SERDES_IP_LBE_U32);
}


/**
* @brief        Initialize PLLs and Electrical parameters
* @details      This function allows all supported configurations on serdes.
* @warning      This function doesnt have parameter check so, if platform has some restrictions
                it should be verified before calling this function.
                Currently only supported mode is SGMII bifurcation (Serdes mode 3).
                SGMII+PCIe bifurcation is not supported.
*/
void Serdes_Ip_PcsPmaInitGen2(uint32 Base,
                              Serdes_Ip_ClockType Fmhz,
                              uint32 InitFlags
                             )
{
    uint32 XpcsPhyCtr;

    /* Get the Xpcs with the PHY control*/
    XpcsPhyCtr = Serdes_Ip_PcsPhyControl(InitFlags);

    /* Set bypass flag in case of internal clocks */
    Serdes_Ip_PcsBypassClockXpcs0(Base, InitFlags);
    Serdes_Ip_PcsBypassClockXpcs1(Base, InitFlags);

     /* Configure pll for xpcs0 and xpcs1 */
    Serdes_Ip_PcsSelectPll(Base, InitFlags);

    /* Using external clock reference */
    if (((InitFlags & SERDES_IP_PHY_CTRL_XPCS_OWNED) != 0U) && ((InitFlags & SERDES_PHY_CLK_INT) == 0U))
    {
        SERDES_IP_PCSBSET(Base, XpcsPhyCtr, SERDES_IP_VR_MII_GEN5_12G_16G_REF_CLK_CTRL, SERDES_IP_REF_USE_PAD_U32);
    }
    else if ((InitFlags & SERDES_IP_PHY_CTRL_XPCS_OWNED) != 0U)
    {
        SERDES_IP_PCSBCLR(Base, XpcsPhyCtr, SERDES_IP_VR_MII_GEN5_12G_16G_REF_CLK_CTRL, SERDES_IP_REF_USE_PAD_U32);
    }
    else
    {
        /* do nothing */
    }

    /* Start PLLA/PLLB  cal */
    Serdes_Ip_PcsConfigPll(Base, InitFlags, Fmhz, XpcsPhyCtr);

    /* Configure lower layers to use correct speed */
    Serdes_Ip_PcsConfLowLayers(Base, Fmhz, InitFlags);

    /* Disable lane 0 or 1 if we don't use it*/
    Serdes_Ip_PcsDisLane(Base, InitFlags);

    /* Clear bypass flag in case of internal clocks */
    if (((InitFlags & SERDES_PHY_CLK_INT) != 0U) &&
        ((InitFlags & (SERDES_IP_XPCS0_OWNED)) != 0U) &&
        ((InitFlags & SERDES_IP_XPCS0_DIS_U32) == 0U))
    {
        SERDES_IP_PCSBCLR(Base, 0U, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_BYP_PWRUP_U32);
    }

    if (((InitFlags & SERDES_PHY_CLK_INT) != 0U) &&
        ((InitFlags & (SERDES_IP_XPCS1_OWNED)) != 0U) &&
        ((InitFlags & SERDES_IP_XPCS1_DIS_U32) == 0U))
    {
        SERDES_IP_PCSBCLR(Base, 1U, SERDES_IP_VR_MII_DIG_CTRL1, SERDES_IP_BYP_PWRUP_U32);
    }
}

/**
* @brief        Issue vendor specific reset to serdes
* @details      This function issues vendor specific reset and waits for power good.
* @warning      Currently only supported mode is SGMII bifurcation (Serdes mode 3).
                SGMII+PCIe bifurcation is not supported.
*/
void Serdes_Ip_PcsResetIssue(uint32 SerdesBase,
                             Serdes_Ip_ModeType Mode
                            )
{
    /* Issue vendor reset */
    switch (Mode)
    {
        case PCIE_SGMII_XPCS_0:
            Serdes_Ip_PcsIssueVReset(SerdesBase, 0U);
            /* Write 1, then 0 to cold_RST */
            Serdes_Ip_SsAssertColdReset(SerdesBase);
            Serdes_Ip_SsDeassertColdReset(SerdesBase);
            break;
        case PCIE_SGMII_XPCS_1:
            Serdes_Ip_PcsIssueVReset(SerdesBase, 1U);
            /* Write 1, then 0 to cold_RST */
            Serdes_Ip_SsAssertColdReset(SerdesBase);
            Serdes_Ip_SsDeassertColdReset(SerdesBase);
            break;
        case SGMII_MODE_3:
            Serdes_Ip_PcsIssueVReset(SerdesBase, 1U);
            Serdes_Ip_PcsIssueVReset(SerdesBase, 0U);
            break;
        case SGMII_MODE_4:
            Serdes_Ip_PcsIssueVReset(SerdesBase, 0U);
            Serdes_Ip_PcsIssueVReset(SerdesBase, 1U);
            break;
        default:
            /* Do nothing */
            break;
    }
}

/**
* @brief        Check if serdes reset is finished
* @details      This function checks for HW power up status after vendor specific reset was issued.
                After power up status is reached it issues transeiver RX reset.
* @warning      Currently only supported mode is SGMII bifurcation (Serdes mode 3).
                SGMII+PCIe bifurcation is not supported.
*/
boolean Serdes_Ip_PcsResetFinalizeAsync(uint32 SerdesBase,
                                        uint32 XpcsBase
                                       )
{
    boolean RetXpcs = FALSE;

    /* If single step fails here, the serdes is not usable. */
    if (Serdes_Ip_PcsCheckBits(SerdesBase, XpcsBase, (uint32)SERDES_IP_VR_MII_DIG_CTRL1, (uint16)SERDES_IP_VR_RST_U32, 0U))
    {
        /*  Wait for XPCS power up (Phy control) */
        if (SERDES_IP_SUCCESS == Serdes_Ip_PcsWaitForPowerGood(SerdesBase, XpcsBase))
        {
            RetXpcs = TRUE;
        }
    }

    return RetXpcs;
}

/* Monitor SerDes MPLL state */
boolean Serdes_Ip_PcieWaitReadMpllState(const SerDes_SS_Type *Base,
                                        uint32 Checks
                                       )
{
    uint32 Count = 1000U;
    uint32 CheckCounts = Checks;
    boolean RetStatus = TRUE;

    while (CheckCounts > 0U)
    {

        if ((Base->PCIE_PHY_MPLLA_CTRL & (SERDES_IP_MPLL_STATE_U32 | SERDES_IP_MPLLA_STATE_U32)) == (SERDES_IP_MPLL_STATE_U32 | SERDES_IP_MPLLA_STATE_U32))
        {
            RetStatus = FALSE;
        }

        while (0UL != Count)
        {
            /* Wait */
            Count--;
        }

        CheckCounts--;
        Count = 1000U;
    }

    return RetStatus;
}

/* Set PHY register access to CR interface */
void Serdes_Ip_PciePhySelectCRInterface(SerDes_SS_Type *Base)
{
    Base->SS_RW_REG_0 |= (uint32)((uint32)1U << 9U);
}

void Serdes_Ip_PhyInit(uint32 Base)
{
    /* Address erratum TKT0527889:
     * PCIe Gen3 Receiver Long Channel Stressed Voltage Test Failing
     */
    /* RX_EQ_DELTA_IQ_OVRD enable and override value for PCIe0 lane 0 */
    Serdes_Ip_PhyRegWrite((SerDes_SS_Type *)Base, SERDES_IP_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN, 0x03, 0xff);
    Serdes_Ip_PhyRegWrite((SerDes_SS_Type *)Base, SERDES_IP_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN, 0x13, 0xff);

    /* RX_EQ_DELTA_IQ_OVRD enable and override value for PCIe0 lane 1 */
    Serdes_Ip_PhyRegWrite((SerDes_SS_Type *)Base, SERDES_IP_RAWLANE1_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN, 0x03, 0xff);
    Serdes_Ip_PhyRegWrite((SerDes_SS_Type *)Base, SERDES_IP_RAWLANE1_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN, 0x13, 0xff);
}

/* Set internal clock */
void Serdes_Ip_PcieClearRefUsePad(SerDes_SS_Type *Base)
{
    /* Clear bit REF_USE_PAD */
    Base->PCIE_PHY_GEN_CTRL &=  ~((uint32)((uint32)1U << 17U));
}

/* Set external clock */
void Serdes_Ip_PcieSetRefUsePad(SerDes_SS_Type *Base)
{
    /* Set bit REF_USE_PAD */
    Base->PCIE_PHY_GEN_CTRL |= ((uint32)((uint32)1U << 17U));
}

#define SERDES_STOP_SEC_CODE
#include "Serdes_MemMap.h"
