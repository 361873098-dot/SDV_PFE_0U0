/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LINFLEXD
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef LIN_IPW_TYPES_H
#define LIN_IPW_TYPES_H

/**
*   @file Lin_Ipw_Types.h
*
*   @addtogroup LIN_IPW
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Linflexd_Lin_Ip_Types.h"
#include "Lin_Defines.h"
#if (LIN_WAKEUP_DETECTION == STD_ON)
#include "EcuM_Externals.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_IPW_TYPES_VENDOR_ID                    43
#define LIN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define LIN_IPW_TYPES_AR_RELEASE_MINOR_VERSION     4
#define LIN_IPW_TYPES_AR_RELEASE_REVISION_VERSION  0
#define LIN_IPW_TYPES_SW_MAJOR_VERSION             4
#define LIN_IPW_TYPES_SW_MINOR_VERSION             0
#define LIN_IPW_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Linflexd_Lin_Ip_Types.h */
#if (LIN_IPW_TYPES_VENDOR_ID != LINFLEXD_LIN_IP_TYPES_VENDOR_ID)
    #error "Lin_Ipw_Types.h and Linflexd_Lin_Ip_Types.h have different vendor ids"
#endif
#if ((LIN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_LIN_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != LINFLEXD_LIN_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LINFLEXD_LIN_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lin_Ipw_Types.h and Linflexd_Lin_Ip_Types.h are different"
#endif
#if ((LIN_IPW_TYPES_SW_MAJOR_VERSION != LINFLEXD_LIN_IP_TYPES_SW_MAJOR_VERSION) || \
     (LIN_IPW_TYPES_SW_MINOR_VERSION != LINFLEXD_LIN_IP_TYPES_SW_MINOR_VERSION) || \
     (LIN_IPW_TYPES_SW_PATCH_VERSION != LINFLEXD_LIN_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Ipw_Types.h and Linflexd_Lin_Ip_Types.h are different"
#endif

/* Checks against Lin_Defines.h */
#if (LIN_IPW_TYPES_VENDOR_ID != LIN_DEFINES_VENDOR_ID)
    #error "Lin_Ipw_Types.h and Lin_Defines.h have different vendor ids"
#endif
#if ((LIN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != LIN_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != LIN_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LIN_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LIN_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Lin_Ipw_Types.h and Lin_Defines.h are different"
#endif
#if ((LIN_IPW_TYPES_SW_MAJOR_VERSION != LIN_DEFINES_SW_MAJOR_VERSION) || \
     (LIN_IPW_TYPES_SW_MINOR_VERSION != LIN_DEFINES_SW_MINOR_VERSION) || \
     (LIN_IPW_TYPES_SW_PATCH_VERSION != LIN_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Ipw_Types.h and Lin_Defines.h are different"
#endif
#if (LIN_WAKEUP_DETECTION == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and ComStackTypes header file are of the same Autosar version */
    #if ((LIN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_IPW_TYPES_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_Ipw_Types.h and EcuM_Externals.h are different"
    #endif
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
/**
 * @brief         Definition of the LIN node type of the current channel.
 * @details       This type enumerates the node types for a LIN channel.
 *
 * 
 **/
typedef enum
{
    LIN_MASTER_NODE       = 0x0U, /**< @brief This is used for Master node */
    LIN_SLAVE_NODE        = 0x1U  /**< @brief This is used for Slave node */
} Lin_Ipw_NodeType;

/*==================================================================================================
*                                STRUCTURES AND OTHERS
==================================================================================================*/
/** 
 * @internal
 * @brief Hardware configuration type
 *
 * 
 */
typedef struct
{
    const uint8 LinHwChannel;
#if (LIN_WAKEUP_DETECTION == STD_ON)
    boolean LinChannelWakeupSupport;                   /**!< @brief Is wake-up supported by the LIN channel ?.*/
    EcuM_WakeupSourceType LinChannelEcuMWakeupSource;   /**!< @brief [SWS_Lin_00098] This parameter contains a reference to
                                                              the Wakeup Source for this controller as defined in the 
                                                              ECU State Manager.*/
#endif
    const Lin_Ipw_NodeType LinNodeType;                /**!< @brief LIN Node Type.*/
    const Linflexd_Lin_Ip_UserConfigType  *LinFlexdConfig;
#if (LIN_DUAL_CLOCK_MODE == STD_ON)
    uint32 BaudrateRegValueAlternate;              /**!< @brief Baudrate configuration value for alternate clock */
#endif /* LIN_DUAL_CLOCK_MODE == STD_ON */
} Lin_HwConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                  EXTERNAL CONSTANTS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LIN_IPW_TYPES_H */
