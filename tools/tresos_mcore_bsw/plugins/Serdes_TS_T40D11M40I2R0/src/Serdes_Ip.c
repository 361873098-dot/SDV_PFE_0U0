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
*                                        INCLUDES
==================================================================================================*/
#include "Mcal.h"
#include "Serdes_Ip_Cfg.h"
#include "Serdes_Ip_CfgDefines.h"
#include "Serdes_Ip_HwAccess.h"
#include "Serdes_Ip.h"
#include "Serdes_Ip_TrustedFunctions.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IP_VENDOR_ID_C                    43
#define SERDES_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define SERDES_IP_AR_RELEASE_MINOR_VERSION_C     4
#define SERDES_IP_AR_RELEASE_REVISION_VERSION_C  0
#define SERDES_IP_SW_MAJOR_VERSION_C             4
#define SERDES_IP_SW_MINOR_VERSION_C             0
#define SERDES_IP_SW_PATCH_VERSION_C             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Serdes_Ip_Cfg.h file are of the same vendor */
#if (SERDES_IP_VENDOR_ID_C != SERDES_IP_CFG_VENDOR_ID)
    #error "Serdes_Ip.c and Serdes_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_Cfg.h file are of the same Autosar version */
#if ((SERDES_IP_AR_RELEASE_MAJOR_VERSION_C    != SERDES_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_MINOR_VERSION_C    != SERDES_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_REVISION_VERSION_C != SERDES_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip.c and Serdes_Ip_Cfg.h are different"
#endif
/* Check if current file and Serdes_Ip_Cfg.h file are of the same software version */
#if ((SERDES_IP_SW_MAJOR_VERSION_C != SERDES_IP_CFG_SW_MAJOR_VERSION) || \
     (SERDES_IP_SW_MINOR_VERSION_C != SERDES_IP_CFG_SW_MINOR_VERSION) || \
     (SERDES_IP_SW_PATCH_VERSION_C != SERDES_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip.c and Serdes_Ip_Cfg.h are different"
#endif

/* Check if current file and Serdes_Ip_HwAccess.h file are of the same vendor */
#if (SERDES_IP_VENDOR_ID_C != SERDES_IP_HWACCESS_VENDOR_ID)
    #error "Serdes_Ip.c and Serdes_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_HwAccess.h file are of the same Autosar version */
#if ((SERDES_IP_AR_RELEASE_MAJOR_VERSION_C    != SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_MINOR_VERSION_C    != SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_REVISION_VERSION_C != SERDES_IP_HWACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip.c and Serdes_Ip_HwAccess.h are different"
#endif
/* Check if current file and Serdes_Ip_HwAccess.h file are of the same software version */
#if ((SERDES_IP_SW_MAJOR_VERSION_C != SERDES_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (SERDES_IP_SW_MINOR_VERSION_C != SERDES_IP_HWACCESS_SW_MINOR_VERSION) || \
     (SERDES_IP_SW_PATCH_VERSION_C != SERDES_IP_HWACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip.c and Serdes_Ip_HwAccess.h are different"
#endif

/* Check if current file and Serdes_Ip_CfgDefines.h file are of the same vendor */
#if (SERDES_IP_VENDOR_ID_C != SERDES_IP_CFGDEFINES_VENDOR_ID)
    #error "Serdes_Ip.c and Serdes_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_CfgDefines.h file are of the same Autosar version */
#if ((SERDES_IP_AR_RELEASE_MAJOR_VERSION_C    != SERDES_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_MINOR_VERSION_C    != SERDES_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_REVISION_VERSION_C != SERDES_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip.c and Serdes_Ip_CfgDefines.h are different"
#endif
/* Check if current file and Serdes_Ip_CfgDefines.h file are of the same software version */
#if ((SERDES_IP_SW_MAJOR_VERSION_C != SERDES_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (SERDES_IP_SW_MINOR_VERSION_C != SERDES_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (SERDES_IP_SW_PATCH_VERSION_C != SERDES_IP_CFGDEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip.c and Serdes_Ip_CfgDefines.h are different"
#endif

/* Check if current file and Serdes_Ip.h file are of the same vendor */
#if (SERDES_IP_VENDOR_ID_C != SERDES_IP_VENDOR_ID)
    #error "Serdes_Ip.c and Serdes_Ip.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip.h file are of the same Autosar version */
#if ((SERDES_IP_AR_RELEASE_MAJOR_VERSION_C    != SERDES_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_MINOR_VERSION_C    != SERDES_IP_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_REVISION_VERSION_C != SERDES_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip.c and Serdes_Ip.h are different"
#endif
/* Check if current file and Serdes_Ip.h file are of the same software version */
#if ((SERDES_IP_SW_MAJOR_VERSION_C != SERDES_IP_SW_MAJOR_VERSION) || \
     (SERDES_IP_SW_MINOR_VERSION_C != SERDES_IP_SW_MINOR_VERSION) || \
     (SERDES_IP_SW_PATCH_VERSION_C != SERDES_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip.c and Serdes_Ip.h are different"
#endif

/* Check if current file and Serdes_Ip_TrustedFunctions.h file are of the same vendor */
#if (SERDES_IP_VENDOR_ID_C != SERDES_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Serdes_Ip.c and Serdes_Ip_TrustedFunctions.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_TrustedFunctions.h file are of the same Autosar version */
#if ((SERDES_IP_AR_RELEASE_MAJOR_VERSION_C    != SERDES_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_MINOR_VERSION_C    != SERDES_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_REVISION_VERSION_C != SERDES_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip.c and Serdes_Ip_TrustedFunctions.h are different"
#endif
/* Check if current file and Serdes_Ip_TrustedFunctions.h file are of the same software version */
#if ((SERDES_IP_SW_MAJOR_VERSION_C != SERDES_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     (SERDES_IP_SW_MINOR_VERSION_C != SERDES_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     (SERDES_IP_SW_PATCH_VERSION_C != SERDES_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip.c and Serdes_Ip_TrustedFunctions.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h file are of the same Autosar version */
    #if ((SERDES_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SERDES_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Serdes_Ip.c and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* Serdes SS */
#define SERDES_IP_S32G_SUB_SYS_OFF        (0x80000U)
#define SERDES_IP_SS_RW_REG_0             (SERDES_IP_S32G_SUB_SYS_OFF + 0xf0U)
#define SERDES_IP_CLKEN                   (uint32)((uint32)1U << 23U)

/* MC RGM */
#define SERDES_IP_MC_RGM_BASE              (0x40078000U)

#define SERDES_IP_PRST_PCIE_0_SERDES      4U
#define SERDES_IP_PRST_PCIE_0_FUNC        5U
#define SERDES_IP_PRST_PCIE_1_SERDES      16U
#define SERDES_IP_PRST_PCIE_1_FUNC        17U
#define SERDES_IP_PRST0_0                 (SERDES_IP_MC_RGM_BASE + 0x40U)
#define SERDES_IP_PSTAT0_0                (SERDES_IP_MC_RGM_BASE + 0x140U)

#define SERDES_IP_BASE(instance) (((instance) == 0U)  ? (SERDES_IP_S32G_0_BASE_U32) : (SERDES_IP_S32G_1_BASE_U32))

#define SERDES_IP_SS_BASE_ADDR(instance)    (SerDes_SS_Type *)(SERDES_IP_BASE(instance) + (uint32)SERDES_IP_SS_BASE)
#define SERDES_IP_SS_WARM_BASE_ADDR(instance)    (uint32)(SERDES_IP_BASE(instance) + (uint32)SERDES_IP_SS_BASE)

#define SERDES_IP_PRST_PCIE_SERDES(instance) (((instance) == 0U)  ? (SERDES_IP_PRST_PCIE_0_SERDES) : (SERDES_IP_PRST_PCIE_1_SERDES))
#define SERDES_IP_PRST_PCIE_FUNC(instance) (((instance) == 0U)  ? (SERDES_IP_PRST_PCIE_0_FUNC) : (SERDES_IP_PRST_PCIE_1_FUNC))

/* Globals */
#define SERDES_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Serdes_MemMap.h"

static Serdes_Ip_StateType Serdes_Ip_DriverStatePtr[SERDES_GPR_INSTANCE_COUNT];

#define SERDES_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Serdes_MemMap.h"

#define SERDES_START_SEC_VAR_CLEARED_32
#include "Serdes_MemMap.h"

static uint32 Serdes_Ip_aInitFlags[2];

#define SERDES_STOP_SEC_VAR_CLEARED_32
#include "Serdes_MemMap.h"

#define SERDES_START_SEC_CODE
#include "Serdes_MemMap.h"


/*==================================================================================================
*                                        Local FUNCTIONS
==================================================================================================*/

static void Serdes_Ip_InitSpeedDuplex(uint32 SerdesBase,
                                      uint32 Pcs,
                                      Serdes_Ip_MacSpeedType Speed,
                                      Serdes_Ip_MacDuplexType Duplex
                                     )
{
    VAR(uint32, AUTOMATIC) SpeedSelect = 0U;

    if (SERDES_MAC_DUPLEX_FULL == Duplex)
    {
        Serdes_Ip_PcsSetFd(SerdesBase, Pcs);
    }
    else
    {
        Serdes_Ip_PcsSetHd(SerdesBase, Pcs);
    }

    if (SERDES_MAC_SPEED_10_MBPS == Speed)
    {
        SpeedSelect = 100U;
    }
    else if (SERDES_MAC_SPEED_100_MBPS == Speed)
    {
        SpeedSelect = 10U;
    }
    else
    {
        /* 1G or 2.5G */
       SpeedSelect = 1U;
    }

    (void)Serdes_Ip_PcsSpeedSelect(SerdesBase, Pcs, SpeedSelect);
}

static boolean Serdes_Ip_WaitPrstAssert(uint32 PrstReg)
{
    uint32 StartTime, ElapsedTime, TimeoutTicks;
    boolean Timeout;
    boolean ResetStatus;

    *(uint32 *)((uint32)(SERDES_IP_PRST0_0)) |= ((uint32)1U << PrstReg);

     /* Wait for bits to stabilize */
    Serdes_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, SERDES_IP_TIMEOUT_U32);

    /* Wait until bits are ready */
    do
    {
        Timeout = Serdes_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

    } while ((FALSE == Timeout) && (((*(uint32 *)((uint32)(SERDES_IP_PSTAT0_0)) & ((uint32)1U << PrstReg)) != (uint32)((uint32)1U << PrstReg))));

    ResetStatus = ((*(uint32 *)((uint32)(SERDES_IP_PSTAT0_0)) & ((uint32)1U << PrstReg)) != (uint32)((uint32)1U << PrstReg)) ? FALSE : TRUE;

    return ResetStatus;
}

static boolean Serdes_Ip_CheckPrstDeassert(uint32 PrstReg1,
                                           uint32 PrstReg2
                                          )
{
    boolean RetValue = FALSE;

    /* Check deassert */
    if ((*(uint32 *)((uint32)(SERDES_IP_PSTAT0_0)) & ((uint32)1U << PrstReg1)) == 0U)
    {
        if ((*(uint32 *)((uint32)(SERDES_IP_PSTAT0_0)) & ((uint32)1U << PrstReg2)) == 0U)
        {
            RetValue = TRUE;
        }
    }

    return RetValue;
}

#if defined(SERDES_0_USED)
static void Serdes_Ip_SetXpcsSerdes0(Serdes_Ip_MacSpeedType XpcsSpeed1)
{
    /* Configure SERDES_0 XPCS_0 - only 1G supported */
#if (STD_ON == SERDES_0_XPCS0_ENABLED)
        Serdes_Ip_aInitFlags[0] &= ~SERDES_IP_XPCS0_DIS_U32;
        Serdes_Ip_aInitFlags[0] |= SERDES_IP_PLLA_CAL_EN_U32 | SERDES_IP_XPCS0_1000M_U32;
#endif

    /* Configure SERDES_0 XPCS_1 - support 2.5G only for S32G3XX platform*/
#if (STD_ON == SERDES_0_XPCS1_ENABLED)
        Serdes_Ip_aInitFlags[0] &= ~SERDES_IP_XPCS1_DIS_U32;

#if defined(SERDES_0_XPCS1_2_5G)
        if (SERDES_MAC_SPEED_2500_MBPS == XpcsSpeed1)
        {
            Serdes_Ip_aInitFlags[0] |= SERDES_IP_PLLA_CAL_EN_U32 | SERDES_IP_PLLB_CAL_EN_U32 | SERDES_IP_XPCS1_2500M_U32;
        }
        else
#endif /* SERDES_0_PCIE_XPCS1_2_5G */
        {
            Serdes_Ip_aInitFlags[0] |= SERDES_IP_PLLA_CAL_EN_U32 | SERDES_IP_XPCS1_1000M_U32;
        }

#endif /* (STD_ON == SERDES_0_XPCS1_ENABLED) */

        /* Cast to void to avoid compiler warnings */
        (void) XpcsSpeed1;
}
#endif /* SERDES_0_USED */

#if defined(SERDES_1_USED)
static void Serdes_Ip_SetXpcsSerdes1(Serdes_Ip_MacSpeedType XpcsSpeed0,
                                     Serdes_Ip_MacSpeedType XpcsSpeed1
                                    )
{
    /* Configure SERDES_1 XPCS_0 - 1G and 2.5 supported */
#if (STD_ON == SERDES_1_XPCS0_ENABLED)
        Serdes_Ip_aInitFlags[1] &= ~SERDES_IP_XPCS0_DIS_U32;
        if (SERDES_MAC_SPEED_2500_MBPS == XpcsSpeed0)
        {
            Serdes_Ip_aInitFlags[1] |= SERDES_IP_PLLA_CAL_EN_U32 | SERDES_IP_PLLB_CAL_EN_U32 | SERDES_IP_XPCS0_2500M_U32;
        }
        else
        {
            Serdes_Ip_aInitFlags[1] |= SERDES_IP_PLLA_CAL_EN_U32 | SERDES_IP_XPCS0_1000M_U32;
        }
#endif /* (STD_ON == SERDES_1_XPCS0_ENABLED) */

    /* Configure SERDES_1 XPCS_1 - support 2.5G only for S32G3XX platform*/
#if (STD_ON == SERDES_1_XPCS1_ENABLED)

        Serdes_Ip_aInitFlags[1] &= ~SERDES_IP_XPCS1_DIS_U32;
#if defined(SERDES_1_XPCS1_2_5G)
        if (SERDES_MAC_SPEED_2500_MBPS == XpcsSpeed1)
        {
            Serdes_Ip_aInitFlags[1] |= SERDES_IP_PLLA_CAL_EN_U32 | SERDES_IP_PLLB_CAL_EN_U32 | SERDES_IP_XPCS1_2500M_U32;
        }
        else
#endif /* SERDES_1_XPCS1_2_5G */
        {
            Serdes_Ip_aInitFlags[1] |= SERDES_IP_PLLA_CAL_EN_U32 | SERDES_IP_XPCS1_1000M_U32;
        }
#endif /* (STD_ON == SERDES_1_XPCS1_ENABLED) */

    /* Cast to void to avoid compiler warnings */
    (void) XpcsSpeed0;
    (void) XpcsSpeed1;
}
#endif /* SERDES_1_USED */

/**
* @brief        Checks device reset
* @details      This function checks if reset is completed. In case the reset is
*               done the driver will continue the initialization.
* @note         Second state
*/
static void Serdes_Ip_WaitDeviceReset_TrustedCall(uint8 Instance)
{
   if (Serdes_Ip_CheckPrstDeassert(SERDES_IP_PRST_PCIE_SERDES(Instance), SERDES_IP_PRST_PCIE_FUNC(Instance)))
   {
        Serdes_Ip_DriverStatePtr[Instance].Job = SERDES_IP_JOB_ISSUE_VRESET;
        Serdes_Ip_DriverStatePtr[Instance].JobResult = SERDES_IP_JOB_PENDING;
   }
}

static void Serdes_Ip_Pcie_Phy_Init(uint8 Instance)
{
    if (!Serdes_Ip_PcieWaitReadMpllState(SERDES_IP_SS_BASE_ADDR(Instance), 10U))
    {
        /* Set PHY register access to CR interface */
        Serdes_Ip_PciePhySelectCRInterface(SERDES_IP_SS_BASE_ADDR(Instance));
        Serdes_Ip_PhyInit(SERDES_IP_BASE(Instance));
    }
}

static void Serdes_Ip_SetSerdesPcieMode(uint8 Instance,
                                        Serdes_Ip_ModeType Mode
                                       )
{
    if ((PCIE_X2 == Mode) || (PCIE_SGMII_XPCS_0 == Mode) || (PCIE_SGMII_XPCS_1 == Mode))
    {
        /* Set the clock for SerDes module */
        if (0U != (Serdes_Ip_aInitFlags[Instance] & SERDES_PHY_CLK_INT))
        {
            Serdes_Ip_PcieClearRefUsePad(SERDES_IP_SS_BASE_ADDR(Instance));
        }
        else
        {
            Serdes_Ip_PcieSetRefUsePad(SERDES_IP_SS_BASE_ADDR(Instance));
        }

        Serdes_Ip_Pcie_Phy_Init(Instance);
    }
}

static Serdes_Ip_StatusType Serdes_Ip_CheckSerdesXpcsClock(uint8 Instance,
                                                           Serdes_Ip_ModeType Mode)
{
    Serdes_Ip_StatusType InitSeqSuccesSer = SERDES_IP_ERROR;
    Serdes_Ip_StatusType WaitPowerGoodXPCS0;
    Serdes_Ip_StatusType WaitPowerGoodXPCS1;

    /* define varible check good power state in modes: SGMII_MODE_3, SGMII_MODE_4 */
    WaitPowerGoodXPCS0 = Serdes_Ip_PcsWaitForPowerGood(SERDES_IP_BASE(Instance), 0U);
    WaitPowerGoodXPCS1 = Serdes_Ip_PcsWaitForPowerGood(SERDES_IP_BASE(Instance), 1U);

    /* check good power state in modes: PCIE_SGMII_XPCS_0, PCIE_SGMII_XPCS_1 */
    if ((PCIE_SGMII_XPCS_0 == Mode) || (PCIE_SGMII_XPCS_1 == Mode))
    {
        if (SERDES_IP_SUCCESS == Serdes_Ip_PcsWaitForPowerGood(SERDES_IP_BASE(Instance), ((Mode) == PCIE_SGMII_XPCS_0)  ? (0U) : (1U)))
        {
            InitSeqSuccesSer = SERDES_IP_SUCCESS;
            Serdes_Ip_DriverStatePtr[Instance].XPCSMode = SERDES_IP_XPCS_POWER_UP;
        }
    }
    else /* check good power state in modes: SGMII_MODE_3, SGMII_MODE_4 */
    {
        if ((SERDES_IP_SUCCESS == WaitPowerGoodXPCS0) && (SERDES_IP_SUCCESS == WaitPowerGoodXPCS1))
        {
            InitSeqSuccesSer = SERDES_IP_SUCCESS;
            Serdes_Ip_DriverStatePtr[Instance].XPCSMode = SERDES_IP_XPCS_POWER_UP;
        }
    }

    return InitSeqSuccesSer;
}

static Serdes_Ip_StatusType Serdes_Ip_CheckSerdesClock(uint8 Instance,
                                                       Serdes_Ip_ModeType Mode
                                                      )
{
    Serdes_Ip_StatusType InitSeqSuccesSer;

    /* Check if we have clk */
    if ((0U == (Serdes_Ip_aInitFlags[Instance] & SERDES_PHY_CLK_INT)) && (Mode != PCIE_X2))
    {
        InitSeqSuccesSer = Serdes_Ip_CheckSerdesXpcsClock(Instance, Mode);
    }
    else
    {
        InitSeqSuccesSer = SERDES_IP_SUCCESS;
    }

    return InitSeqSuccesSer;
}

static void Serdes_Ip_IssueReset(uint8 Instance,
                                 Serdes_Ip_ModeType Mode
                                )
{
    /* Enable loopback */
    Serdes_Ip_PmaLoopbackEnable(SERDES_IP_BASE(Instance), 0U);
    Serdes_Ip_PmaLoopbackEnable(SERDES_IP_BASE(Instance), 1U);
    /* Initialize PLLs and Electrical parameters */
    Serdes_Ip_PcsPmaInitGen2(SERDES_IP_BASE(Instance),  Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->SerdesRefClock, Serdes_Ip_aInitFlags[Instance]);
    /* Issue vendor specific reset to serdes */
    Serdes_Ip_PcsResetIssue(SERDES_IP_BASE(Instance), Mode);
}

/**
* @brief        Issues Xpcs vendor reset
* @details      This function  will issue vendor reset.
*
* @note         Third state
*/
static void Serdes_Ip_IssueXpcsVendorReset(uint8 Instance)
{
    volatile uint32 Wait = 100U;
    Serdes_Ip_ModeType Mode = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->SerdesMode;
    Serdes_Ip_StatusType InitSeqSuccesSer;

    /* Set the clock for SerDes module */
    Serdes_Ip_SetSerdesPcieMode(Instance, Mode);

    /* Check if we have clk */
    InitSeqSuccesSer = Serdes_Ip_CheckSerdesClock(Instance, Mode);

    if ((SERDES_IP_SUCCESS == InitSeqSuccesSer) && (Mode != PCIE_X2))
    {
        Serdes_Ip_IssueReset(Instance, Mode);
    }

    if ((PCIE_SGMII_XPCS_0 == Mode) || (PCIE_SGMII_XPCS_1 == Mode))
    {
        /* PCIE software reset */
        Serdes_Ip_PcieAssertWarmReset(SERDES_IP_SS_WARM_BASE_ADDR(Instance));
        while (0UL != Wait)
        {
            Wait--;
        }
        Serdes_Ip_PcieDeassertWarmReset(SERDES_IP_SS_WARM_BASE_ADDR(Instance));
    }

    if (SERDES_IP_SUCCESS == InitSeqSuccesSer)
    {
        Serdes_Ip_DriverStatePtr[Instance].Job = SERDES_IP_JOB_WAIT_FIRST_VRESET;
        Serdes_Ip_DriverStatePtr[Instance].JobResult = SERDES_IP_JOB_PENDING;
    }
    else
    {
        Serdes_Ip_DriverStatePtr[Instance].DriverStatus = SERDES_IP_ERROR;
        Serdes_Ip_DriverStatePtr[Instance].JobResult = SERDES_IP_JOB_FAILED;
    }

    if (PCIE_X2 == Mode)
    {
        Serdes_Ip_DriverStatePtr[Instance].DriverStatus = SERDES_IP_SUCCESS;
        Serdes_Ip_DriverStatePtr[Instance].Job = SERDES_IP_JOB_FINISHED;
        Serdes_Ip_DriverStatePtr[Instance].JobResult = SERDES_IP_JOB_DONE;
    }
}

/**
* @brief        Checks first xpcs vendor reset
* @details      This function will check the first XPCS vendor reset. In case the vendor
*               reset is completed it will continue the initialization.
*
* @note         Fourth state
*/
static void Serdes_Ip_WaitFirstXpcsVendorReset(uint8 Instance)
{
    Serdes_Ip_ModeType Mode = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->SerdesMode;
    boolean InitSeqSuccesSer = FALSE;

    if ((SGMII_MODE_3 == Mode)  || (PCIE_SGMII_XPCS_1 == Mode))
    {
        InitSeqSuccesSer =  Serdes_Ip_PcsResetFinalizeAsync(SERDES_IP_BASE(Instance), 1U);
    }
    else
    {
        InitSeqSuccesSer =  Serdes_Ip_PcsResetFinalizeAsync(SERDES_IP_BASE(Instance), 0U);
    }

    if (InitSeqSuccesSer)
    {
        if ((PCIE_SGMII_XPCS_0 == Mode) || (PCIE_SGMII_XPCS_1 == Mode))
        {
            Serdes_Ip_DriverStatePtr[Instance].Job = SERDES_IP_JOB_WAIT_LINK_UP;
            Serdes_Ip_DriverStatePtr[Instance].JobResult = SERDES_IP_JOB_PENDING;
        }
        else
        {
            Serdes_Ip_DriverStatePtr[Instance].Job = SERDES_IP_JOB_WAIT_SECOND_VRESET;
            Serdes_Ip_DriverStatePtr[Instance].JobResult = SERDES_IP_JOB_PENDING;
        }
    }
}

/**
* @brief        Checks second xpcs vendor reset
* @details      This function will check the second XPCS vendor reset. In case the vendor
*               reset is completed it will continue the initialization.
*
* @note         Fifth state
*/
static void Serdes_Ip_WaitSecondXpcsVendorReset(uint8 Instance)
{
    boolean InitSeqSuccesSer = FALSE;
    Serdes_Ip_ModeType Mode = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->SerdesMode;

    if (SGMII_MODE_3 == Mode)
    {
        InitSeqSuccesSer =  Serdes_Ip_PcsResetFinalizeAsync(SERDES_IP_BASE(Instance), 0U);
    }

    if (SGMII_MODE_4 == Mode)
    {
        InitSeqSuccesSer =  Serdes_Ip_PcsResetFinalizeAsync(SERDES_IP_BASE(Instance), 1U);
    }

    if (InitSeqSuccesSer)
    {
        Serdes_Ip_DriverStatePtr[Instance].Job = SERDES_IP_JOB_WAIT_LINK_UP;
        Serdes_Ip_DriverStatePtr[Instance].JobResult = SERDES_IP_JOB_PENDING;
    }
}

static void Serdes_Ip_LoopbackMode(uint32 Instance,
                                   Serdes_Ip_ModeType Mode,
                                   boolean LoopbackXpcs0,
                                   boolean LoopbackXpcs1
                                  )
{
    if (LoopbackXpcs0)
    {
        /* To enable again the loopback - FOR LOOPBACK MODE */
        if (Mode != PCIE_SGMII_XPCS_1)
        {
            Serdes_Ip_PmaLoopbackEnable(SERDES_IP_BASE(Instance), 0U);
        }
    }

    if (LoopbackXpcs1)
    {
        /* To enable again the loopback - FOR LOOPBACK MODE */
        if (Mode != PCIE_SGMII_XPCS_0)
        {
             Serdes_Ip_PmaLoopbackEnable(SERDES_IP_BASE(Instance), 1U);
        }
    }
}

static void Serdes_Ip_IssueRxReset(uint8 Instance,
                                   Serdes_Ip_ModeType Mode
                                  )
{
     /* Issue RX reset */
    if (Mode != PCIE_SGMII_XPCS_0)
    {
        Serdes_Ip_PmaIssueRxReset(SERDES_IP_BASE(Instance), 1U);
    }

    if (Mode != PCIE_SGMII_XPCS_1)
    {
        Serdes_Ip_PmaIssueRxReset(SERDES_IP_BASE(Instance), 0U);
    }

    /* Disable loopback */
    if (0U == (Serdes_Ip_aInitFlags[Instance] & SERDES_IP_XPCS0_DIS_U32))
    {
        Serdes_Ip_PmaLoopbackDisable(SERDES_IP_BASE(Instance), 0U);
    }

    if (0U == (Serdes_Ip_aInitFlags[Instance] & SERDES_IP_XPCS1_DIS_U32))
    {
        Serdes_Ip_PmaLoopbackDisable(SERDES_IP_BASE(Instance), 1U);
    }
}

static void Serdes_Ip_MiiBusControlEnable(uint8 Instance,
                                          Serdes_Ip_ModeType Mode
                                         )
{
    if (Mode != PCIE_SGMII_XPCS_1)
    {
        Serdes_Ip_PcsMiiBusControlEnable(SERDES_IP_BASE(Instance), 0U);
    }

    if (Mode != PCIE_SGMII_XPCS_1)
    {
        Serdes_Ip_PcsMiiBusControlEnable(SERDES_IP_BASE(Instance), 1U);
    }

    /* Disable AN*/
    if (Mode != PCIE_SGMII_XPCS_1)
    {
         Serdes_Ip_PcsAnDisable(SERDES_IP_BASE(Instance), 0U);
    }

    if (Mode != PCIE_SGMII_XPCS_0)
    {
        Serdes_Ip_PcsAnDisable(SERDES_IP_BASE(Instance), 1U);
    }
}

static void Serdes_Ip_SetSpeedDuplex(uint8 Instance,
                                     Serdes_Ip_ModeType Mode
                                    )
{
    Serdes_Ip_MacSpeedType eSpeedXpcs0   = SERDES_MAC_SPEED_INVALID;
    Serdes_Ip_MacSpeedType eSpeedXpcs1   = SERDES_MAC_SPEED_INVALID;
    Serdes_Ip_MacDuplexType eDuplexXpcs0 = SERDES_MAC_DUPLEX_INVALID;
    Serdes_Ip_MacDuplexType eDuplexXpcs1 = SERDES_MAC_DUPLEX_INVALID;

    if (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS0)
    {
        /* Get Xpcs speed */
        eSpeedXpcs0 = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS0->XpcsSpeed;
        /* Get Xpcs duplex*/
        eDuplexXpcs0 = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS0->XpcsDuplex;
    }

    if (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS1)
    {
        /* Get Xpcs speed */
        eSpeedXpcs1 = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS1->XpcsSpeed;
        /* Get Xpcs duplex*/
        eDuplexXpcs1 = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS1->XpcsDuplex;
    }

    /* Configure PFE speed and duplex */
    if ((Mode != PCIE_SGMII_XPCS_1) &&
        (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS0))
    {
        Serdes_Ip_InitSpeedDuplex(SERDES_IP_BASE(Instance), 0U, eSpeedXpcs0, eDuplexXpcs0);
    }

    if ((Mode != PCIE_SGMII_XPCS_0) &&
        (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS1))
    {
         Serdes_Ip_InitSpeedDuplex(SERDES_IP_BASE(Instance), 1U, eSpeedXpcs1, eDuplexXpcs1);
    }
}

static void Serdes_Ip_ANSettingsXpcs0(uint8 Instance)
{
    /* Set AN settings */
    Serdes_Ip_PcsAnSetLinkTimer(SERDES_IP_BASE(Instance), 0U, 0x2fafU);
    Serdes_Ip_PcsAnAutoSwDisable(SERDES_IP_BASE(Instance), 0U);
    Serdes_Ip_PcsAnEnable(SERDES_IP_BASE(Instance), 0U);
}

static void Serdes_Ip_ANSettingsXpcs1(uint8 Instance)
{
     /* Set AN settings */
    Serdes_Ip_PcsAnSetLinkTimer(SERDES_IP_BASE(Instance), 1U, 0x2fafU);
    Serdes_Ip_PcsAnAutoSwDisable(SERDES_IP_BASE(Instance), 1U);
    Serdes_Ip_PcsAnEnable(SERDES_IP_BASE(Instance), 1U);
}

static Serdes_Ip_StatusType Serdes_Ip_ANOption(uint8 Instance)
{
    Serdes_Ip_StatusType Status0 = SERDES_IP_SUCCESS;
    Serdes_Ip_StatusType Status1 = SERDES_IP_SUCCESS;
    Serdes_Ip_StatusType Status = SERDES_IP_SUCCESS;
    boolean ANXpcs0 = FALSE;
    boolean ANXpcs1 = FALSE;

    /* Get autonegotiation */
    if (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS0)
    {
        ANXpcs0 = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS0->XpcsAN;
    }
    if (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS1)
    {
        ANXpcs1 = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS1->XpcsAN;
    }

    /* Enable Autonegotiation for XPCS0 */
    if ((ANXpcs0) &&
        (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS0))
    {
        Serdes_Ip_ANSettingsXpcs0(Instance);
        Status0 = Serdes_Ip_PcsAnRestart(SERDES_IP_BASE(Instance), 0U);
    }

    /* Enable Autonegotiation for XPCS1 */
    if ((ANXpcs1) &&
        (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS1))
    {
        Serdes_Ip_ANSettingsXpcs1(Instance);
        Status1 = Serdes_Ip_PcsAnRestart(SERDES_IP_BASE(Instance), 1U);
    }

    if ((SERDES_IP_SUCCESS != Status0) || (SERDES_IP_SUCCESS != Status1))
    {
        Status = SERDES_IP_ERROR;
    }

    return Status;
}

/**
* @brief        Link up stage
*
* @note         Last state
*/
static Serdes_Ip_StatusType Serdes_Ip_LinkUp(uint8 Instance)
{
    Serdes_Ip_StatusType AnStatus = SERDES_IP_SUCCESS;
    boolean LoopbackXpcs0 = FALSE;
    boolean LoopbackXpcs1 = FALSE;

    /* Get Mode */
    Serdes_Ip_ModeType Mode = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->SerdesMode;

    /* Get loopback */
    if (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS0)
    {
        LoopbackXpcs0 = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS0->LoopbackEnabled;
    }
    if (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS1)
    {
        LoopbackXpcs1 = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS1->LoopbackEnabled;
    }

    /* Issue RX reset */
    Serdes_Ip_IssueRxReset(Instance, Mode);

    /* Enable/Disable loopback */
    Serdes_Ip_LoopbackMode(Instance, Mode, LoopbackXpcs0, LoopbackXpcs1);

    /* Bus width change on speed change */
    Serdes_Ip_MiiBusControlEnable(Instance, Mode);

    /* Configure PFE speed and duplex */
    Serdes_Ip_SetSpeedDuplex(Instance, Mode);

    /* Additional tuning of AN can be done here */
    AnStatus = Serdes_Ip_ANOption(Instance);

    Serdes_Ip_DriverStatePtr[Instance].DriverStatus = SERDES_IP_SUCCESS;
    Serdes_Ip_DriverStatePtr[Instance].Job = SERDES_IP_JOB_FINISHED;
    Serdes_Ip_DriverStatePtr[Instance].JobResult = SERDES_IP_JOB_DONE;

    if (SERDES_IP_ERROR == AnStatus)
    {
        Serdes_Ip_DriverStatePtr[Instance].DriverStatus = SERDES_IP_ERROR;
    }

    return Serdes_Ip_DriverStatePtr[Instance].DriverStatus;
}

static void Serdes_Ip_SetXpcsMode(uint8 Instance,
                                  uint32 Xpcs,
                                  Serdes_Ip_XpcsModeType XpcsMode
                                 )
{
    switch (XpcsMode)
    {
        case SERDES_IP_XPCS_POWER_UP:
            /* Bring back the XPCS to power good state */
            Serdes_Ip_SetPowerUpMode(SERDES_IP_BASE(Instance), Xpcs, Serdes_Ip_DriverStatePtr[Instance].XPCSMode);
            Serdes_Ip_DriverStatePtr[Instance].XPCSMode = SERDES_IP_XPCS_POWER_UP;
            break;
        case SERDES_IP_XPCS_POWER_SAVE:
            /* PWRSV - VR_MII_DIG_CTRL1 - Only turn off PHY RX/TX */
            Serdes_Ip_SetPowerSaveMode(SERDES_IP_BASE(Instance), Xpcs);
            Serdes_Ip_DriverStatePtr[Instance].XPCSMode = SERDES_IP_XPCS_POWER_SAVE;
            break;
        case SERDES_IP_XPCS_POWER_DOWN:
            /* LPM   - SR_MII_CTRL      - Turns off all clocks as well as PHY RX/TX */
            Serdes_Ip_SetPowerDownMode(SERDES_IP_BASE(Instance), Xpcs);
            Serdes_Ip_DriverStatePtr[Instance].XPCSMode = SERDES_IP_XPCS_POWER_DOWN;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/* implements Serdes_Ip_SsModeConfigure_TrustedCall_Activity */
boolean Serdes_Ip_SsModeConfigure_TrustedCall(uint8 Instance,
                                              Serdes_Ip_ModeType Mode,
                                              uint32 IntClks
                                             )
{
    boolean WaitPrstAssertPeriph4;
    boolean WaitPrstAssertPeriph5;
    boolean ResetStatus;
    uint32 Config = 0U;
    volatile uint32 Wait = 80000U;

    Config = (uint32)Mode;
    if (0U != (IntClks & SERDES_PHY_CLK_INT))
    {
        Config |= SERDES_IP_CLKEN;
    }

    /* Assert Serdes + pcie func reset*/
    WaitPrstAssertPeriph4 = (boolean)(Serdes_Ip_WaitPrstAssert(SERDES_IP_PRST_PCIE_SERDES(Instance)));
    WaitPrstAssertPeriph5 = (boolean)(Serdes_Ip_WaitPrstAssert(SERDES_IP_PRST_PCIE_FUNC(Instance)));

    /* ResetStatus only TRUE if both Peripheral 4 and 5 from PRST register are in reset */
    ResetStatus = WaitPrstAssertPeriph4 && WaitPrstAssertPeriph5;

    /* Serdes mode */
    *(uint32 *)((uint32)SERDES_IP_BASE(Instance) + SERDES_IP_SS_RW_REG_0) = Config;
    Wait = 100U;

    while (0UL != Wait)
    {
        Wait--;
    }

    *(uint32 *)((uint32)(SERDES_IP_PRST0_0)) &= ~((uint32)1U << SERDES_IP_PRST_PCIE_SERDES(Instance));
    *(uint32 *)((uint32)(SERDES_IP_PRST0_0)) &= ~((uint32)1U << SERDES_IP_PRST_PCIE_FUNC(Instance));

    return ResetStatus;
}

/**
* @brief        Starts initialization of serdes module
* @details      This function initializes PLLs, electrical parameters and xpcs logic.
*/
Serdes_Ip_StatusType Serdes_Ip_Init(uint8 Instance,
                                    const Serdes_Ip_ConfigType * Serdes
                                   )
{
    Serdes_Ip_DriverStatePtr[Instance].SerdesCfg = Serdes;
    Serdes_Ip_DriverStatePtr[Instance].DriverStatus = SERDES_IP_ERROR;
    Serdes_Ip_DriverStatePtr[Instance].Job = SERDES_IP_JOB_INIT;
    Serdes_Ip_DriverStatePtr[Instance].XPCSMode = SERDES_IP_XPCS_POWER_UNKNOWN;
    boolean ResetStatus;

    Serdes_Ip_ModeType Mode = Serdes->SerdesMode;

    if (0U == Instance)
    {
        /* Disable GMAC */
        Serdes_Ip_aInitFlags[0] |= SERDES_IP_XPCS0_DIS_U32;

        /* Disable PFE lanes */
        Serdes_Ip_aInitFlags[0] |= SERDES_IP_XPCS1_DIS_U32;
    }
    else
    {
        Serdes_Ip_aInitFlags[1] |= SERDES_IP_XPCS0_DIS_U32 | SERDES_IP_XPCS1_DIS_U32;
    }

#if defined(SERDES_0_USED)
    if (0U == Instance)
    {
    #if (STD_ON == SERDES_0_XPCS1_ENABLED)
        Serdes_Ip_SetXpcsSerdes0(Serdes->XPCS1->XpcsSpeed);
    #else
        Serdes_Ip_SetXpcsSerdes0(SERDES_MAC_SPEED_INVALID);
    #endif
    }
#endif /* SERDES_0_USED */

#if defined(SERDES_1_USED)
    if (1U == Instance)
    {
    #if ((STD_ON == SERDES_1_XPCS0_ENABLED) && (STD_ON == SERDES_1_XPCS1_ENABLED))
        Serdes_Ip_SetXpcsSerdes1(Serdes->XPCS0->XpcsSpeed, Serdes->XPCS1->XpcsSpeed);
    #elif ((STD_ON == SERDES_1_XPCS0_ENABLED) && (STD_OFF == SERDES_1_XPCS1_ENABLED))
        Serdes_Ip_SetXpcsSerdes1(Serdes->XPCS0->XpcsSpeed, SERDES_MAC_SPEED_INVALID);
    #elif ((STD_OFF == SERDES_1_XPCS0_ENABLED) && (STD_ON == SERDES_1_XPCS1_ENABLED))
        Serdes_Ip_SetXpcsSerdes1(SERDES_MAC_SPEED_INVALID, Serdes->XPCS1->XpcsSpeed);
    #else
        Serdes_Ip_SetXpcsSerdes1(SERDES_MAC_SPEED_INVALID, SERDES_MAC_SPEED_INVALID);
    #endif
    }
#endif /* SERDES_1_USED */

    /* in mode 1 and 3 PHY is always owned by XPCS0 */
    if ((Mode == SGMII_MODE_4) || (Mode == PCIE_SGMII_XPCS_1))
    {
        Serdes_Ip_aInitFlags[Instance] |= (Serdes->PhyReferenceClock) | SERDES_IP_XPCS1_OWNED_U32;
    }
    else
    {
        Serdes_Ip_aInitFlags[Instance] |= (Serdes->PhyReferenceClock) | SERDES_IP_XPCS0_OWNED_U32;
    }
    /* Configure SerDes Working modes and bring both SerDes out of reset */
#ifdef SERDES_IP_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == SERDES_IP_ENABLE_USER_MODE_SUPPORT)
    ResetStatus = OsIf_Trusted_Call_Return3param(Serdes_Ip_SsModeConfigure_TrustedCall,(Instance),(Mode),(Serdes_Ip_aInitFlags[Instance]));
    #else
    ResetStatus = Serdes_Ip_SsModeConfigure_TrustedCall(Instance, Mode, Serdes_Ip_aInitFlags[Instance]);
    #endif
#endif /* SERDES_IP_ENABLE_USER_MODE_SUPPORT */
    if (TRUE == ResetStatus)
    {
        Serdes_Ip_DriverStatePtr[Instance].DriverStatus = SERDES_IP_BUSY;
        Serdes_Ip_DriverStatePtr[Instance].Job = SERDES_IP_JOB_BRING_OUT_OF_RESET;
        Serdes_Ip_DriverStatePtr[Instance].JobResult = SERDES_IP_JOB_PENDING;
    }
    else
    {
        Serdes_Ip_DriverStatePtr[Instance].DriverStatus = SERDES_IP_BUSY;
        Serdes_Ip_DriverStatePtr[Instance].Job = SERDES_IP_JOB_BRING_OUT_OF_RESET;
        Serdes_Ip_DriverStatePtr[Instance].JobResult = SERDES_IP_JOB_FAILED;
    }

    return SERDES_IP_SUCCESS;
}

/**
* @brief        Gets job result
* @details      This function returns the status of the current job.
*/
Serdes_Ip_JobResultType Serdes_Ip_GetJobResult(uint8 Instance)
{
    return Serdes_Ip_DriverStatePtr[Instance].JobResult;
}

/**
* @brief        Returns serdes status
* @details      This function returns the current driver state.
*/
Serdes_Ip_StatusType Serdes_Ip_GetStatus(uint8 Instance)
{
    return Serdes_Ip_DriverStatePtr[Instance].DriverStatus;
}

/**
* @brief        Continues initialization of serdes module
* @details      This function will complete the initialization of serdes module.
*/
Serdes_Ip_StatusType Serdes_Ip_MainFunction(uint8 Instance)
{
    Serdes_Ip_StatusType Status = SERDES_IP_ERROR;
    Serdes_Ip_JobResultType SerdesJobResult = Serdes_Ip_GetJobResult(Instance);

    if (SERDES_IP_JOB_PENDING == SerdesJobResult)
    {
        switch (Serdes_Ip_DriverStatePtr[Instance].Job)
        {
            case SERDES_IP_JOB_BRING_OUT_OF_RESET:
#ifdef SERDES_IP_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == SERDES_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Serdes_Ip_WaitDeviceReset_TrustedCall,(Instance));
    #else
        Serdes_Ip_WaitDeviceReset_TrustedCall(Instance);
    #endif
#endif /* SERDES_IP_ENABLE_USER_MODE_SUPPORT */
                break;
            case SERDES_IP_JOB_ISSUE_VRESET:
                Serdes_Ip_IssueXpcsVendorReset(Instance);
                break;
            case SERDES_IP_JOB_WAIT_FIRST_VRESET:
                Serdes_Ip_WaitFirstXpcsVendorReset(Instance);
                break;
            case SERDES_IP_JOB_WAIT_SECOND_VRESET:
                Serdes_Ip_WaitSecondXpcsVendorReset(Instance);
                break;
            case SERDES_IP_JOB_WAIT_LINK_UP:
                Status = Serdes_Ip_LinkUp(Instance);
                break;
            default:
                /* do nothing */
                break;
        }
    }

    return Status;
}

/**
* @brief        Set the power mode of the XPCS
* @details      This function changes and waits for the XPCS to achieve the power mode requested
*
* @implements Serdes_Ip_SetMode_Activity
*/
void Serdes_Ip_SetMode(uint8 Instance,
                       Serdes_Ip_XpcsModeType XpcsMode
                      )
{
    Serdes_Ip_ModeType Mode = Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->SerdesMode;

    if ((PCIE_SGMII_XPCS_1 != Mode) &&
        (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS0))
    {
        Serdes_Ip_SetXpcsMode(Instance, 0U, XpcsMode);
    }

    if ((PCIE_SGMII_XPCS_0 != Mode) &&
        (NULL_PTR != Serdes_Ip_DriverStatePtr[Instance].SerdesCfg->XPCS1))
    {
        Serdes_Ip_SetXpcsMode(Instance, 1U, XpcsMode);
    }
}

#define SERDES_STOP_SEC_CODE
#include "Serdes_MemMap.h"
