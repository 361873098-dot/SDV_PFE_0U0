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

#ifndef WDG_VR5510_VR55XX_TYPES_H
#define WDG_VR5510_VR55XX_TYPES_H

/**
*   @file    Wdg_VR5510_VR55XX_Types.h
*
*   @addtogroup Wdg_VR5510_IP
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
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_VR5510_VR55XX_TYPES_VENDOR_ID                    43
#define WDG_VR5510_VR55XX_TYPES_MODULE_ID                    102
#define WDG_VR5510_VR55XX_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_VR5510_VR55XX_TYPES_AR_RELEASE_MINOR_VERSION     4
#define WDG_VR5510_VR55XX_TYPES_AR_RELEASE_REVISION_VERSION  0
#define WDG_VR5510_VR55XX_TYPES_SW_MAJOR_VERSION             4
#define WDG_VR5510_VR55XX_TYPES_SW_MINOR_VERSION             0
#define WDG_VR5510_VR55XX_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Std_Types header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_VR5510_VR55XX_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_VR5510_VR55XX_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Wdg_VR5510_VR55XX_Types.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Wdg_VR55xx_ConfigType.
* @details        Contains the information related to the hardware setup for Wdg external device.
*
* @implements     Wdg_VR55xx_ConfigType_struct
*/
typedef struct
{
    uint16 u16WatchdogConfigReg;
    uint16 u16WatchdogDurationReg;
    uint16 u16WatchdogSeedReg;
    uint32 u32TimerValue;
}Wdg_VR55xx_ConfigType;

/**
* @brief  This enumerated type will indicate the Pmic's failsafe state
*
* @pre To define WDG_GETVERSION_ID, WDG_VERSION_INFO_API has to be equal to STD_ON
*
* @implements     Wdg_VR55xx_PmicStateType_enumeration
*/
typedef enum
{
    FS_STATES_FSM_STATES_INIT_FS      = 0x06,  /* Pmic is currently in FS_INIT phase        */
    FS_STATES_FSM_STATES_WAIT_ABIST2  = 0x07,  /* Pmic is currently in WAIT_ABIST2 phase    */
    FS_STATES_FSM_STATES_ABIST2       = 0x08,  /* Pmic is currently in ABIST2 phase         */
    FS_STATES_FSM_STATES_ASSERT_FS0B  = 0x09,  /* Pmic is currently in ASSERT_FS0B phase    */
    FS_STATES_FSM_STATES_NORMAL_FS    = 0xA,   /* Pmic is currently in NORMAL_FS phase      */
    FS_STATES_FSM_STATES_UNSUPPORT_FS          /* Pmic is currently in UNSUPPORT_FS phase   */
} Wdg_VR55xx_PmicStateType;
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDG_VR5510_VR55XX_TYPES_H */
