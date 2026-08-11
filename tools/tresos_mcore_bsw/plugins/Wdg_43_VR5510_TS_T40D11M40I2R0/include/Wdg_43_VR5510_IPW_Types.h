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

#ifndef WDG_43_VR5510_IPW_TYPES_H
#define WDG_43_VR5510_IPW_TYPES_H

/**
*   @file    Wdg_43_IPW_Types.h
*
*   @addtogroup Wdg_VR5510_IPW
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
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_43_VR5510_IPW_TYPES_VENDOR_ID                    43
#define WDG_43_VR5510_IPW_TYPES_MODULE_ID                    102
#define WDG_43_VR5510_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_43_VR5510_IPW_TYPES_AR_RELEASE_MINOR_VERSION     4
#define WDG_43_VR5510_IPW_TYPES_AR_RELEASE_REVISION_VERSION  0
#define WDG_43_VR5510_IPW_TYPES_SW_MAJOR_VERSION             4
#define WDG_43_VR5510_IPW_TYPES_SW_MINOR_VERSION             0
#define WDG_43_VR5510_IPW_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg_VR5510_VR55XX_Types.h header file are of the same vendor */
#if (WDG_43_VR5510_IPW_TYPES_VENDOR_ID!= WDG_VR5510_VR55XX_TYPES_VENDOR_ID)
    #error "Wdg_43_IPW_Types.h and Wdg_VR5510_VR55XX_Types.h have different vendor ids"
#endif

/* Check if Wdg_43_IPW_Types file and Wdg_VR5510_VR55XX_Types.h header file are of the same Autosar version */
#if ((WDG_43_VR5510_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != WDG_VR5510_VR55XX_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_VR5510_IPW_TYPES_AR_RELEASE_MINOR_VERSION != WDG_VR5510_VR55XX_TYPES_AR_RELEASE_MINOR_VERSION ) || \
     (WDG_43_VR5510_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != WDG_VR5510_VR55XX_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_43_IPW_Types.h and Wdg_VR5510_VR55XX_Types.h are different"
#endif

/* Check if Wdg_43_IPW_Types file and Wdg_VR5510_VR55XX_Types.h header file are of the same Software version */
#if ((WDG_43_VR5510_IPW_TYPES_SW_MAJOR_VERSION != WDG_VR5510_VR55XX_TYPES_SW_MAJOR_VERSION ) || \
     (WDG_43_VR5510_IPW_TYPES_SW_MINOR_VERSION != WDG_VR5510_VR55XX_TYPES_SW_MINOR_VERSION ) || \
     (WDG_43_VR5510_IPW_TYPES_SW_PATCH_VERSION != WDG_VR5510_VR55XX_TYPES_SW_PATCH_VERSION ))
    #error "Software Version Numbers of Wdg_43_IPW_Types.h and Wdg_Swt_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Wdg_VR5510_IPW_ConfigType.
* @details        Contains the information related to the hardware setup for SWT

*/

#define Wdg_VR5510_IPW_ConfigType Wdg_VR55xx_ConfigType
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



#ifdef __cplusplus
}
#endif

/** @} */

#endif /*WDG_43_VR5510_IPW_TYPES_H*/
