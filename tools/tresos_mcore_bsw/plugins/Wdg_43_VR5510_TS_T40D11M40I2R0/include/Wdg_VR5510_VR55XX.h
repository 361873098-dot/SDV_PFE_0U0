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

#ifndef WDG_VR5510_VR55XX_H
#define WDG_VR5510_VR55XX_H

/**
*   @file    Wdg_VR5510_VR55xx.h
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
#include "Wdg_VR5510_VR55XX_Types.h"
#include "Wdg_43_VR5510_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_VR5510_VR55XX_VENDOR_ID                       43
#define WDG_VR5510_VR55XX_MODULE_ID                       102
#define WDG_VR5510_VR55XX_AR_RELEASE_MAJOR_VERSION        4
#define WDG_VR5510_VR55XX_AR_RELEASE_MINOR_VERSION        4
#define WDG_VR5510_VR55XX_AR_RELEASE_REVISION_VERSION     0
#define WDG_VR5510_VR55XX_SW_MAJOR_VERSION                4
#define WDG_VR5510_VR55XX_SW_MINOR_VERSION                0
#define WDG_VR5510_VR55XX_SW_PATCH_VERSION                2

/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg_VR55xx_Types header file are of the same vendor */
#if (WDG_VR5510_VR55XX_VENDOR_ID != WDG_VR5510_VR55XX_TYPES_VENDOR_ID)
    #error "Wdg_VR5510_VR55xx.h and Wdg_VR55XX_Types.h have different vendor ids"
#endif

/* Check if source file and Wdg_VR55xx_Types header file are of the same Autosar version */
#if ((WDG_VR5510_VR55XX_AR_RELEASE_MAJOR_VERSION    != WDG_VR5510_VR55XX_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_VR5510_VR55XX_AR_RELEASE_MINOR_VERSION    != WDG_VR5510_VR55XX_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_VR5510_VR55XX_AR_RELEASE_REVISION_VERSION != WDG_VR5510_VR55XX_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_VR5510_VR55xx.h and Wdg_VR55xx_Types.h are different"
#endif

/* Check if source file and Wdg_VR55xx_Types header file are of the same Software version */
#if ((WDG_VR5510_VR55XX_SW_MAJOR_VERSION != WDG_VR5510_VR55XX_TYPES_SW_MAJOR_VERSION) || \
     (WDG_VR5510_VR55XX_SW_MINOR_VERSION != WDG_VR5510_VR55XX_TYPES_SW_MINOR_VERSION) || \
     (WDG_VR5510_VR55XX_SW_PATCH_VERSION != WDG_VR5510_VR55XX_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_VR5510_VR55xx.h and Wdg_VR55XX_Types.h are different"
#endif

/* Check if current file and Wdg_43_VR5510_Cfg header file are of the same vendor */
#if (WDG_VR5510_VR55XX_VENDOR_ID != WDG_43_VR5510_CFG_VENDOR_ID)
    #error "Wdg_VR5510_VR55xx.h and Wdg_43_VR5510_Cfg.h have different vendor ids"
#endif

/* Check if source file and Wdg_43_VR5510_Cfg header file are of the same Autosar version */
#if ((WDG_VR5510_VR55XX_AR_RELEASE_MAJOR_VERSION    != WDG_43_VR5510_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_VR5510_VR55XX_AR_RELEASE_MINOR_VERSION    != WDG_43_VR5510_CFG_AR_RELEASE_MINOR_VERSION) || \
     (WDG_VR5510_VR55XX_AR_RELEASE_REVISION_VERSION != WDG_43_VR5510_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_VR5510_VR55xx.h and Wdg_43_VR5510_Cfg.h are different"
#endif

/* Check if source file and Wdg_43_VR5510_Cfg header file are of the same Software version */
#if ((WDG_VR5510_VR55XX_SW_MAJOR_VERSION != WDG_43_VR5510_CFG_SW_MAJOR_VERSION) || \
     (WDG_VR5510_VR55XX_SW_MINOR_VERSION != WDG_43_VR5510_CFG_SW_MINOR_VERSION) || \
     (WDG_VR5510_VR55XX_SW_PATCH_VERSION != WDG_43_VR5510_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_VR5510_VR55xx.h and Wdg_43_VR5510_Cfg.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
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
Std_ReturnType Wdg_VR5510_VR55XX_Init(const Wdg_VR55xx_ConfigType * Vr55xx_pConfigPtr, const uint32 Wdg_DeviceID);

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
Std_ReturnType Wdg_VR5510_VR55XX_SetMode(const Wdg_VR55xx_ConfigType * Vr55xx_pConfigPtr, const uint32 Wdg_DeviceID);

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
void Wdg_VR5510_VR55XX_Trigger(const uint32 Wdg_DeviceID);
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
Wdg_VR55xx_PmicStateType Wdg_VR5510_VR55XX_PmicState(const uint32 Wdg_DeviceID);
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
Std_ReturnType Wdg_VR5510_VR55XX_ReadFsGFlagRegister(const uint32 Wdg_DeviceID, uint16 * pFsGflagValue);
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

#endif /* WDG_VR5510_VR55XX_H */
