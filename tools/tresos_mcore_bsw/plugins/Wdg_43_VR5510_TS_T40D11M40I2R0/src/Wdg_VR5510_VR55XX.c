/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : VR5510
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file    Wdg_VR5510_VR55XX.c
*
*   @addtogroup  Wdg_VR5510_IP
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Wdg_43_VR5510_Cfg.h"
#include "Wdg_VR5510_VR55XX.h"
#include "Mcal.h"
#include "CDD_Pmic.h"
#include "OsIf.h"
#ifdef WDG_43_VR5510_IP_DEV_ERROR_DETECT
#if (STD_ON == WDG_43_VR5510_IP_DEV_ERROR_DETECT)
#include "Devassert.h"
#endif
#endif
/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_VR5510_VR55XX_VENDOR_ID_C                     43
#define WDG_VR5510_VR55XX_AR_RELEASE_MAJOR_VERSION_C      4
#define WDG_VR5510_VR55XX_AR_RELEASE_MINOR_VERSION_C      4
#define WDG_VR5510_VR55XX_AR_RELEASE_REVISION_VERSION_C   0
#define WDG_VR5510_VR55XX_SW_MAJOR_VERSION_C              4
#define WDG_VR5510_VR55XX_SW_MINOR_VERSION_C              0
#define WDG_VR5510_VR55XX_SW_PATCH_VERSION_C              2
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_VR5510_Cfg header file are of the same vendor */
#if (WDG_VR5510_VR55XX_VENDOR_ID_C != WDG_43_VR5510_CFG_VENDOR_ID)
    #error "Wdg_VR5510_VR55XX.c and Wdg_VR5510_Cfg.h have different vendor ids"
#endif
/* Check if current file and Wdg_VR5510_Cfg header file are of the same Autosar version */
#if ((WDG_VR5510_VR55XX_AR_RELEASE_MAJOR_VERSION_C    != WDG_43_VR5510_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_VR5510_VR55XX_AR_RELEASE_MINOR_VERSION_C    != WDG_43_VR5510_CFG_AR_RELEASE_MINOR_VERSION) || \
     (WDG_VR5510_VR55XX_AR_RELEASE_REVISION_VERSION_C != WDG_43_VR5510_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_VR5510_VR55XX.c and Wdg_VR5510_Cfg.h are different"
#endif
/* Check if current file and Wdg_VR5510_Cfg header file are of the same Software version */
#if ((WDG_VR5510_VR55XX_SW_MAJOR_VERSION_C != WDG_43_VR5510_CFG_SW_MAJOR_VERSION) || \
     (WDG_VR5510_VR55XX_SW_MINOR_VERSION_C != WDG_43_VR5510_CFG_SW_MINOR_VERSION) || \
     (WDG_VR5510_VR55XX_SW_PATCH_VERSION_C != WDG_43_VR5510_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_VR5510_VR55XX.c and Wdg_VR5510_Cfg.h are different"
#endif

/* Check if current file and Wdg_VR5510_VR55XX header file are of the same vendor */
#if (WDG_VR5510_VR55XX_VENDOR_ID_C != WDG_VR5510_VR55XX_VENDOR_ID)
    #error "Wdg_VR5510_VR55XX.c and Wdg_VR5510_VR55XX.h have different vendor ids"
#endif
/* Check if current file and Wdg_VR5510_VR55XX header file are of the same Autosar version */
#if ((WDG_VR5510_VR55XX_AR_RELEASE_MAJOR_VERSION_C    != WDG_VR5510_VR55XX_AR_RELEASE_MAJOR_VERSION   ) || \
     (WDG_VR5510_VR55XX_AR_RELEASE_MINOR_VERSION_C    != WDG_VR5510_VR55XX_AR_RELEASE_MINOR_VERSION   ) || \
     (WDG_VR5510_VR55XX_AR_RELEASE_REVISION_VERSION_C != WDG_VR5510_VR55XX_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_VR5510_VR55XX.c and Wdg_VR5510_VR55XX.h are different"
#endif
/* Check if current file and Wdg_VR5510_VR55XX header file are of the same Software version */
#if ((WDG_VR5510_VR55XX_SW_MAJOR_VERSION_C != WDG_VR5510_VR55XX_SW_MAJOR_VERSION) || \
     (WDG_VR5510_VR55XX_SW_MINOR_VERSION_C != WDG_VR5510_VR55XX_SW_MINOR_VERSION) || \
     (WDG_VR5510_VR55XX_SW_PATCH_VERSION_C != WDG_VR5510_VR55XX_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_VR5510_VR55XX.c and Wdg_VR5510_VR55XX.h are different"
#endif

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_VR5510_VR55XX_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_VR5510_VR55XX_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Wdg_VR55XX.c and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef WDG_43_VR5510_ROM
    #if (1U == WDG_43_VR5510_ROM)
        #define WDG_43_VR5510_START_SEC_CODE
    #endif
#else
    #if (0U == WDG_43_VR5510_RAM)
        #define WDG_43_VR5510_START_SEC_RAMCODE
    #endif
#endif
/**
* @brief Include Memory mapping specification
*/
#include "Wdg_43_VR5510_MemMap.h"
/**
*   @brief   This function initializes the hardware of WDG module.
*   @details Sets up the values such as timeout value
*
*   @param[in]      Vr55xx_pConfigPtr      Pointer to configuration set.
*   @param[in]      Wdg_DeviceID           Index of Pmic device.
*
*   @return Std_ReturnType
*
* @implements  Wdg_VR5510_VR55XX_Init_Activity
*/
Std_ReturnType Wdg_VR5510_VR55XX_Init(const Wdg_VR55xx_ConfigType * Vr55xx_pConfigPtr, const uint32 Wdg_DeviceID)
{
#ifdef WDG_43_VR5510_IP_DEV_ERROR_DETECT
#if (STD_ON == WDG_43_VR5510_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != Vr55xx_pConfigPtr);
#endif
#endif
    uint16 RegValue = 0U;
    uint32 u32ElapsedTicks = 0U;
    uint32 u32TimeoutTicks = 0U;
    uint32 u32CurrentTicks = 0U;

    Std_ReturnType ReturnStatus = Pmic_ReadRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &RegValue);

    if (  (Std_ReturnType)E_OK  == ReturnStatus )
    {
        if ( (RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16) != PMIC_VR55XX_FS_STATES_FSM_STATES_NORMAL_FS_U16 )
        {
            if ( (RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16) != PMIC_VR55XX_FS_STATES_FSM_STATES_INIT_FS_U16 )
            {
                /* Back to failsafe init state before driver configure */
                ReturnStatus |= Pmic_ReadRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8, &RegValue);
                RegValue |= PMIC_VR55XX_FS_SAFE_IOS_GOTO_INITFS_MASK16;
                ReturnStatus |= Pmic_WriteRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8, RegValue);
                /* wait failsafe sate back to InitFS */
                u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)WDG_VR5510_TIMEOUT_TYPE);
                u32TimeoutTicks = OsIf_MicrosToTicks(WDG_43_VR5510_TIMEOUT_DURATION_U32, (OsIf_CounterType)WDG_VR5510_TIMEOUT_TYPE);
                /* Wait until FS_STATES[FSM_STATES] = INIT_FS */
                do
                {
                    ReturnStatus |= Pmic_ReadRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &RegValue);
                    u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, (OsIf_CounterType)WDG_VR5510_TIMEOUT_TYPE);
                } while (
                            ((RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16) != PMIC_VR55XX_FS_STATES_FSM_STATES_INIT_FS_U16) &&
                            (u32ElapsedTicks <= u32TimeoutTicks) &&
                            ((Std_ReturnType)E_OK == ReturnStatus)
                        );

                /* Check if while loop above exited on timeout */
                if ( u32TimeoutTicks >= u32ElapsedTicks )

                {
                    ReturnStatus = (Std_ReturnType)E_OK;
                }
                else
                {
                    ReturnStatus = (Std_ReturnType)E_NOT_OK;
                }
            }
            /* Set FS_I_WD_CFG register */
            ReturnStatus |= Pmic_WriteRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_WD_CFG_ADDR8, Vr55xx_pConfigPtr->u16WatchdogConfigReg);
            ReturnStatus |= Pmic_WriteRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_WD_CFG_ADDR8, (uint16)(~(Vr55xx_pConfigPtr->u16WatchdogConfigReg)));
            /* Set FS_WD_WINDOW_DUR register */
            ReturnStatus |= Pmic_WriteRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, Vr55xx_pConfigPtr->u16WatchdogDurationReg);
            ReturnStatus |= Pmic_WriteRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_NOT_WD_WINDOW_DUR_ADDR8, (uint16)(~(Vr55xx_pConfigPtr->u16WatchdogDurationReg)));
            /* Set FS_WD_SEED register */
            ReturnStatus |= Pmic_WriteRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_SEED_ADDR8, Vr55xx_pConfigPtr->u16WatchdogSeedReg);
        }
    }
    (void)u32CurrentTicks;
    (void)RegValue;
    (void)u32ElapsedTicks;
    (void)u32TimeoutTicks;

    return ReturnStatus;
}

/**
*   @brief   This function switches the mode for Wdg VR5510 module
*   @details Sets up the values such as timeout value
*
*   @param[in]      Vr55xx_pConfigPtr      Pointer to configuration set.
*
*   @return Std_ReturnType
*
* @implements  Wdg_VR5510_VR55XX_SetMode_Activity
*/
Std_ReturnType Wdg_VR5510_VR55XX_SetMode(const Wdg_VR55xx_ConfigType * Vr55xx_pConfigPtr, const uint32 Wdg_DeviceID)
{
#ifdef WDG_43_VR5510_IP_DEV_ERROR_DETECT
#if (STD_ON == WDG_43_VR5510_IP_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != Vr55xx_pConfigPtr);
#endif
#endif
    uint16 RegValue = 0U;
    Std_ReturnType Valid = Pmic_ReadRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, &RegValue);

    /* Check the old value already wdg_window disabled or not */
    if ( (Std_ReturnType)E_OK == Valid )
    {
        if
        (
            (PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16 != PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(RegValue)) &&
            (PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16 == PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(Vr55xx_pConfigPtr->u16WatchdogDurationReg))
        )
        {
            Valid = Pmic_DisableWatchdog(Wdg_DeviceID);
        }
        else
        {
            /* Set FS_WD_WINDOW_DUR register */
            Valid |= Pmic_WriteRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, Vr55xx_pConfigPtr->u16WatchdogDurationReg);
            Valid |= Pmic_WriteRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_NOT_WD_WINDOW_DUR_ADDR8, (uint16)(~(Vr55xx_pConfigPtr->u16WatchdogDurationReg)));
        }
    }

    return Valid;
}

/**
*   @brief   This function triggers the external watchdog hardware.
*   @details Writes the trigger sequence on the hardware
*
*   @param[in]      Wdg_DeviceID      ID of Pmic device.
*
*
*   @return void
*
*   @pre The Wdg module's environment shall make sure that the Wdg module has
*      been initialized before the Wdg_Trigger routine is called (Req: WDG104)
*
* @implements  Wdg_VR5510_VR55XX_Trigger_Activity
*/
void Wdg_VR5510_VR55XX_Trigger(const uint32 Wdg_DeviceID)
{
    Pmic_TriggerWatchdog(Wdg_DeviceID);
}

/**
*   @brief   This function indicate the current Pmic's state
*   @details Writes the trigger sequence on the hardware
*
*   @param[in]      Wdg_DeviceID      ID of Pmic device.
*
*
*   @return void
*
* @implements  Wdg_VR5510_VR55XX_PmicState_Activity
*
*/
Wdg_VR55xx_PmicStateType Wdg_VR5510_VR55XX_PmicState(const uint32 Wdg_DeviceID)
{
    uint16 RegValue = 0U;
    Wdg_VR55xx_PmicStateType  StateReturn;

    (void)Pmic_ReadRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &RegValue);

    switch( RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16 )
    {
        case  0x06U:
            StateReturn = FS_STATES_FSM_STATES_INIT_FS;
            break;
        case  0x07U:
            StateReturn = FS_STATES_FSM_STATES_WAIT_ABIST2;
            break;
        case  0x08U:
            StateReturn = FS_STATES_FSM_STATES_ABIST2;
            break;
        case  0x09U:
            StateReturn = FS_STATES_FSM_STATES_ASSERT_FS0B;
            break;
        case  0xAU:
            StateReturn = FS_STATES_FSM_STATES_NORMAL_FS;
            break;
        default:
            StateReturn = FS_STATES_FSM_STATES_UNSUPPORT_FS;
            break;
    }

    return (Wdg_VR55xx_PmicStateType)StateReturn;
}

/**
*   @brief   This function returns the FS_G_FLAG register value.
*   @details Read the FS_G_FLAG register value to use check fault error of PMIC device
*
*   @param[in]      Wdg_DeviceID      ID of Pmic device.
*   @param[out]     pFsGflagValue     Pointer stores the FS_G_FLAG register value
*
*
*   @return void
*
* @implements  Wdg_VR5510_VR55XX_ReadFsGFlagRegister_Activity
*
*/
Std_ReturnType Wdg_VR5510_VR55XX_ReadFsGFlagRegister(const uint32 Wdg_DeviceID, uint16 * pFsGflagValue)
{
    return Pmic_ReadRegister(Wdg_DeviceID, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_GRL_FLAGS_ADDR8, pFsGflagValue);
}

#ifdef WDG_43_VR5510_ROM
    #if (1U == WDG_43_VR5510_ROM)
        #define WDG_43_VR5510_STOP_SEC_CODE
    #endif
#else
    #if (0U == WDG_43_VR5510_RAM)
        #define WDG_43_VR5510_STOP_SEC_RAMCODE
    #endif
#endif
/**
* @brief Include Memory mapping specification
*/
#include "Wdg_43_VR5510_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
