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

#ifndef SERDES_XPCS_HWACCESS_H
#define SERDES_XPCS_HWACCESS_H

/*==================================================================================================
*                                        INCLUDES
==================================================================================================*/
#include "Mcal.h"
#include "OsIf.h"
#include "modules.h"
#include "Serdes_Ip_Types.h"
#include "Serdes_Ip_CfgDefines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IP_HWACCESS_VENDOR_ID                    43
#define SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION     4
#define SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION     4
#define SERDES_IP_HWACCESS_AR_RELEASE_REVISION_VERSION  0
#define SERDES_IP_HWACCESS_SW_MAJOR_VERSION             4
#define SERDES_IP_HWACCESS_SW_MINOR_VERSION             0
#define SERDES_IP_HWACCESS_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Serdes_Ip_CfgDefines.h file are of the same vendor */
#if (SERDES_IP_HWACCESS_VENDOR_ID != SERDES_IP_CFGDEFINES_VENDOR_ID)
    #error "Serdes_Ip_HwAccess.h and Serdes_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_CfgDefines.h file are of the same Autosar version */
#if ((SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != SERDES_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != SERDES_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != SERDES_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip_HwAccess.h and Serdes_Ip_CfgDefines.h are different"
#endif
/* Check if current file and Serdes_Ip_CfgDefines.h file are of the same software version */
#if ((SERDES_IP_HWACCESS_SW_MAJOR_VERSION != SERDES_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (SERDES_IP_HWACCESS_SW_MINOR_VERSION != SERDES_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (SERDES_IP_HWACCESS_SW_PATCH_VERSION != SERDES_IP_CFGDEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip_HwAccess.h and Serdes_Ip_CfgDefines.h are different"
#endif

/* Check if current file and Serdes_Ip_Types.h file are of the same vendor */
#if (SERDES_IP_HWACCESS_VENDOR_ID != SERDES_IP_TYPES_VENDOR_ID)
    #error "Serdes_Ip_HwAccess.h and Serdes_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_Types.h file are of the same Autosar version */
#if ((SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != SERDES_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != SERDES_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != SERDES_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip_HwAccess.h and Serdes_Ip_Types.h are different"
#endif
/* Check if current file and Serdes_Ip_Types.h file are of the same software version */
#if ((SERDES_IP_HWACCESS_SW_MAJOR_VERSION != SERDES_IP_TYPES_SW_MAJOR_VERSION) || \
     (SERDES_IP_HWACCESS_SW_MINOR_VERSION != SERDES_IP_TYPES_SW_MINOR_VERSION) || \
     (SERDES_IP_HWACCESS_SW_PATCH_VERSION != SERDES_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip_HwAccess.h and Serdes_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h file are of the same Autosar version */
    #if ((SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Serdes_Ip_HwAccess.h and Mcal.h are different"
    #endif
     /* Check if current file and OsIf.h file are of the same Autosar version */
    #if ((SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Serdes_Ip_HwAccess.h and OsIf.h are different"
    #endif
    /* Check if current file and modules.h file are of the same Autosar version */
    #if ((SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
         (SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != MODULES_AR_RELEASE_MINOR_VERSION_H) \
        )
        #error "AutoSar Version Numbers of Serdes_Ip_HwAccess.h and modules.h are different"
    #endif
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define SERDES_IP_SS_BASE              0x80000U

/*
 *      XPCS registers
 */
#define SERDES_IP_XPCS_0_ADDR2         0x82000U
#define SERDES_IP_XPCS_1_ADDR2         0x82800U

#define SERDES_IP_VR_MII_DIG_CTRL1                          0x1f8000U
#define SERDES_IP_VR_MII_AN_CTRL                            0x1f8001U
#define SERDES_IP_VR_MII_AN_INTR_STS                        0x1f8002U
#define SERDES_IP_VR_MII_LINK_TIMER_CTRL                    0x1f800aU
#define SERDES_IP_VR_MII_DIG_STS                            0x1f8010U
#define SERDES_IP_VR_MII_Gen5_12G_16G_TX_POWER_STATE_CTRL   0x1f8035U
#define SERDES_IP_VR_MII_Gen5_12G_16G_RX_POWER_STATE_CTRL   0x1F8055U
#define SERDES_IP_VR_MII_Gen5_12G_16G_RX_GENCTRL1           0x1F8051U
#define SERDES_IP_VR_MII_Gen5_12G_16G_TX_EQ_CTRL0           0x1F8036U
#define SERDES_IP_VR_MII_Consumer_10G_TX_TERM_CTRL          0x1F803CU
#define SERDES_IP_VR_MII_GEN5_12G_16G_MPLL_CMN_CTRL         0x1f8070U
#define SERDES_IP_VR_MII_GEN5_12G_16G_MPLLA_CTRL0           0x1f8071U
#define SERDES_IP_VR_MII_GEN5_12G_MPLLA_CTRL1               0x1f8072U
#define SERDES_IP_VR_MII_GEN5_12G_16G_MPLLA_CTRL2           0x1f8073U
#define SERDES_IP_VR_MII_GEN5_12G_16G_MPLLB_CTRL0           0x1f8074U
#define SERDES_IP_VR_MII_GEN5_12G_MPLLB_CTRL1               0x1f8075U
#define SERDES_IP_VR_MII_GEN5_12G_16G_MPLLB_CTRL2           0x1f8076U
#define SERDES_IP_VR_MII_GEN5_12G_MPLLA_CTRL3               0x1f8077U
#define SERDES_IP_VR_MII_GEN5_12G_MPLLB_CTRL3               0x1f8078U
#define SERDES_IP_VR_MII_GEN5_12G_VCO_CAL_REF0              0x1f8096U
#define SERDES_IP_VR_MII_GEN5_12G_16G_TX_RATE_CTRL          0x1f8034U
#define SERDES_IP_VR_MII_GEN5_12G_16G_RX_RATE_CTRL          0x1f8054U
#define SERDES_IP_VR_MII_GEN5_12G_16G_CDR_CTRL              0x1f8056U
#define SERDES_IP_VR_MII_GEN5_12G_16G_VCO_CAL_LD0           0x1f8092U
#define SERDES_IP_VR_MII_GEN5_12G_16G_REF_CLK_CTRL          0x1f8091U
#define SERDES_IP_SR_MII_CTRL                               0x1f0000U
#define SERDES_IP_SS_RST_CTRL                               0x3010U

#define SERDES_IP_MPLLA_DIV10_CLK_EN_U32          (uint32)((uint32)1U << 9)
#define SERDES_IP_MPLLA_TX_CLK_DIV_U32(x)         (uint32)((uint32)((uint32)(x) & 0x7U) << 11)
#define SERDES_IP_MPLLA_CAL_DISABLE_U32           (uint32)((uint32)1U << 15)

#define SERDES_IP_MPPLB_CAL_DISABLE_U32           (uint32)((uint32)1U << 15)
#define SERDES_IP_MPLLB_MULTIPLIER_U32(n)         (uint32)((uint32)((uint32)(n) & 0xffU) << 0)

#define SERDES_IP_MPLLB_DIV10_CLK_EN_U32          (uint32)((uint32)1U << 9)
#define SERDES_IP_MPLLB_TX_CLK_DIV_U32(n)         (uint32)((uint32)((uint32)(n) & 0x7U) << 11)

#define SERDES_IP_MPLL_STATE_U32                  (uint32)((uint32)1U << 30U)
#define SERDES_IP_MPLLA_STATE_U32                 (uint32)((uint32)1U << 31U)

/* SERDES_IP_VR_MII_Gen5_12G_16G_RX_GENCTRL1 */
#define SERDES_IP_RX_RST_0_U32                    (uint32)((uint32)1U << 4U)

/* SERDES_IP_VR_MII_Gen5_12G_16G_RX_POWER_STATE_CTRL */
#define SERDES_IP_RX_DISABLE_0_U32                (uint32)((uint32)1U << 8)

/* SERDES_IP_VR_MII_Gen5_12G_16G_TX_POWER_STATE_CTRL */
#define SERDES_IP_TX_DISABLE_0_U32                (uint32)((uint32)1U << 8)

/* SERDES_IP_VR_MII_Gen5_12G_16G_RX_CDR_CTRL */
#define SERDES_IP_VCO_LOW_FREQ_0_U32              (uint32)((uint32)1U << 8)

#define SERDES_IP_PCS_MODE_SGMII                  2U

#define SERDES_IP_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK    (0x1U)
#define SERDES_IP_VR_MII_AN_CTRL_MII_AN_INTR_EN_SHIFT   (0U)
#define SERDES_IP_VR_MII_AN_CTRL_MII_AN_INTR_EN_U32(x)  (((uint32)(((uint32)(x)) << SERDES_IP_VR_MII_AN_CTRL_MII_AN_INTR_EN_SHIFT)) & SERDES_IP_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK)

#define SERDES_IP_VR_MII_AN_CTRL_PCS_MODE_MASK      (0x6U)
#define SERDES_IP_VR_MII_AN_CTRL_PCS_MODE_SHIFT     (1U)
#define SERDES_IP_VR_MII_AN_CTRL_PCS_MODE_U32(x)    (((uint32)(((uint32)(x)) << SERDES_IP_VR_MII_AN_CTRL_PCS_MODE_SHIFT)) & SERDES_IP_VR_MII_AN_CTRL_PCS_MODE_MASK)

#define SERDES_IP_VR_MII_AN_CTRL_MII_CTRL_MASK     (0x100U)
#define SERDES_IP_VR_MII_AN_CTRL_MII_CTRL_SHIFT    (8U)
#define SERDES_IP_VR_MII_AN_CTRL_MII_CTRL_U32(x)   (((uint32)(((uint32)(x)) << SERDES_IP_VR_MII_AN_CTRL_MII_CTRL_SHIFT)) & SERDES_IP_VR_MII_AN_CTRL_MII_CTRL_MASK)

#define SERDES_IP_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK     (0x1U)
#define SERDES_IP_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_SHIFT    (0U)
#define SERDES_IP_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_U32(x)   (((uint32)(((uint32)(x)) << SERDES_IP_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_SHIFT)) & SERDES_IP_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK)

/* RST_CTRL */
#define SERDES_IP_COLD_RST_U32                    (uint32)((uint32)1U << 0)

/* SERDES_IP_SR_MII_CTRL */
#define SERDES_IP_LBE_U32                         (uint32)((uint32)1U << 14)
#define SERDES_IP_MII_CTRL_SS6_U32                (uint32)((uint32)1U << 6)
#define SERDES_IP_MII_CTRL_DUPLEX_MODE_U32        (uint32)((uint32)1U << 8)
#define SERDES_IP_MII_CTRL_RESTART_AN_U32         (uint32)((uint32)1U << 9)
#define SERDES_IP_MII_CTRL_LPM_U32                (uint32)((uint32)1U << 11)
#define SERDES_IP_MII_CTRL_RST_U32                (uint32)((uint32)1U << 15)
#define SERDES_IP_MII_CTRL_AN_ENABLE_U32          (uint32)((uint32)1U << 12)
#define SERDES_IP_MII_CTRL_SS13_U32               (uint32)((uint32)1U << 13)

#define SERDES_IP_MPLL_EN_0_U32                   (uint32)((uint32)1U << 0)
#define SERDES_IP_MPLLB_SEL_0_U32                 (uint32)((uint32)1U << 4)

#define SERDES_IP_MPLLA_MULTIPLIER_VALUE_U32(x)   (uint32)(((uint32)(x) & 0xffU) << 0)

/* Field definitions for VR MII MMD Digital Control1 Register */

#define SERDES_IP_BYP_PWRUP_U32                   (uint32)((uint32)1U << 1)
#define SERDES_IP_EN_2_5G_MODE_U32                (uint32)((uint32)1U << 2)
#define SERDES_IP_CL37_TMR_OVR_RIDE_U32           (uint32)((uint32)1U << 3)
#define SERDES_IP_MAC_AUTO_SW_U32                 (uint32)((uint32)1U << 9)
#define SERDES_IP_PWRSV_U32                       (uint32)((uint32)1U << 11)
#define SERDES_IP_EN_VSMMD1_U32                   (uint32)((uint32)1U << 13)
#define SERDES_IP_VR_RST_U32                      (uint32)((uint32)1U << 15)

/* Field definitions for SERDES_IP_VR_MII_Gen5_12G_16G_REF_CLK_CTRL Register */

#define SERDES_IP_REF_CLK_EN_U32                  (uint32)((uint32)1U << 0)
#define SERDES_IP_REF_USE_PAD_U32                 (uint32)((uint32)1U << 1)
#define SERDES_IP_REF_CLK_DIV2_U32                (uint32)((uint32)1U << 2)
#define SERDES_IP_REF_RANGE_U32(x)                (uint32)(((uint32)(x) & 0x7U) << 3)
#define SERDES_IP_REF_MPLLA_DIV2_U32              (uint32)((uint32)1U << 6)
#define SERDES_IP_REF_MPLLB_DIV2_U32              (uint32)((uint32)1U << 7)

#define SERDES_IP_PLLA_CAL_EN_U32     (1U << 0)
#define SERDES_IP_PLLA_CAL_DIS_U32    (1U << 1)

#define SERDES_IP_PLLB_CAL_EN_U32     (1U << 2)
#define SERDES_IP_PLLB_CAL_DIS_U32    (1U << 3)

#define SERDES_IP_XPCS0_1000M_U32     (uint32)((uint32)1U << 8)
#define SERDES_IP_XPCS0_2500M_U32     (uint32)((uint32)1U << 9)
#define SERDES_IP_XPCS0_DIS_U32       (uint32)((uint32)1U << 10)
#define SERDES_IP_XPCS0_OWNED         (SERDES_IP_XPCS0_1000M_U32 | SERDES_IP_XPCS0_2500M_U32 | SERDES_IP_XPCS0_DIS_U32)

#define SERDES_IP_XPCS1_1000M_U32     (uint32)((uint32)1U << 16)
#define SERDES_IP_XPCS1_2500M_U32     (uint32)((uint32)1U << 17)
#define SERDES_IP_XPCS1_DIS_U32       (uint32)((uint32)1U << 18)
#define SERDES_IP_XPCS1_OWNED         (SERDES_IP_XPCS1_1000M_U32 | SERDES_IP_XPCS1_2500M_U32 | SERDES_IP_XPCS1_DIS_U32)

#define SERDES_PHY_CLK_INT             (uint32)((uint32)1U << 20)
#define SERDES_PHY_CLK_EXT             0U

#define SERDES_IP_XPCS0_OWNED_U32      (uint32)((uint32)1U << 21)
#define SERDES_IP_XPCS1_OWNED_U32      (uint32)((uint32)1U << 22)
#define SERDES_IP_PHY_CTRL_XPCS_OWNED  (SERDES_IP_XPCS0_OWNED_U32 | SERDES_IP_XPCS1_OWNED_U32)

#define SERDES_IP_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN          0x3019U
#define SERDES_IP_RAWLANE1_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN          0x3119U

#define SERDES_START_SEC_CODE
#include "Serdes_MemMap.h"

/* Init */
void Serdes_Ip_PcsPmaInitGen2(uint32 Base, Serdes_Ip_ClockType Fmhz, uint32 InitFlags);
void Serdes_Ip_PcsResetIssue(uint32 SerdesBase, Serdes_Ip_ModeType Mode);
boolean Serdes_Ip_PcsResetFinalizeAsync(uint32 SerdesBase, uint32 XpcsBase);
Serdes_Ip_StatusType Serdes_Ip_PcsWaitForPowerGood(uint32 Base, uint32 Xpcs);

/* PMA control */
void Serdes_Ip_PmaLoopbackEnable(uint32 Base, uint32 Xpcs);
void Serdes_Ip_PmaLoopbackDisable(uint32 Base, uint32 Xpcs);
void Serdes_Ip_PmaIssueRxReset(uint32 Base, uint32 Xpcs);

/* PCS control */
Serdes_Ip_StatusType Serdes_Ip_PcsSpeedSelect(uint32 Base, uint32 Xpcs, uint32 Scaler);
void Serdes_Ip_PcsMiiBusControlEnable(uint32 Base, uint32 Xpcs);
void Serdes_Ip_PcsAnEnable(uint32 Base, uint32 Xpcs);
void Serdes_Ip_PcsAnDisable(uint32 Base, uint32 Xpcs);
Serdes_Ip_StatusType Serdes_Ip_PcsAnRestart(uint32 Base, uint32 Xpcs);
void Serdes_Ip_PcsAnSetLinkTimer(uint32 Base, uint32 Xpcs, uint16 LinkTimer);
void Serdes_Ip_PcsAnAutoSwDisable(uint32 Base, uint32 Xpcs);
void Serdes_Ip_PcsSetFd(uint32 Base, uint32 Xpcs);
void Serdes_Ip_PcsSetHd(uint32 Base, uint32 Xpcs);

boolean Serdes_Ip_PcieWaitReadMpllState(const SerDes_SS_Type *Base, uint32 Checks);
void Serdes_Ip_PciePhySelectCRInterface(SerDes_SS_Type *Base);
void Serdes_Ip_PhyInit(uint32 Base);
void Serdes_Ip_PcieClearRefUsePad(SerDes_SS_Type *Base);
void Serdes_Ip_PcieSetRefUsePad(SerDes_SS_Type *Base);
void Serdes_Ip_PcieDeassertWarmReset(uint32 Base);
void Serdes_Ip_PcieAssertWarmReset(uint32 Base);

void Serdes_Ip_StartTimeout(uint32 *StartTimeOut, uint32 *ElapsedTimeOut, uint32 *TimeoutTicksOut, uint32 TimeoutUs);
boolean Serdes_Ip_TimeoutExpired(uint32 *StartTimeInOut, uint32 *ElapsedTimeInOut, uint32 TimeoutTicks);

void Serdes_Ip_SetPowerUpMode(uint32 Base, uint32 Xpcs, Serdes_Ip_XpcsModeType XPCSMode);
void Serdes_Ip_SetPowerDownMode(uint32 Base, uint32 Xpcs);
void Serdes_Ip_SetPowerSaveMode(uint32 Base,uint32 Xpcs);

#define SERDES_STOP_SEC_CODE
#include "Serdes_MemMap.h"

#endif /* SERDES_XPCS_HWACCESS_H */
