/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SERDES_SS
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors

==================================================================================================*/

#ifndef SERDES_IPW_TYPES_H
#define SERDES_IPW_TYPES_H

/**
*   @file
*
*   @internal
*   @addtogroup Serdes
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
#include "Serdes_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IPW_TYPES_VENDOR_ID                    43
#define SERDES_IPW_TYPES_MODULE_ID                    255
#define SERDES_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define SERDES_IPW_TYPES_AR_RELEASE_MINOR_VERSION     4
#define SERDES_IPW_TYPES_AR_RELEASE_REVISION_VERSION  0
#define SERDES_IPW_TYPES_SW_MAJOR_VERSION             4
#define SERDES_IPW_TYPES_SW_MINOR_VERSION             0
#define SERDES_IPW_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Serdes_Ip_Types.h file are of the same vendor */
#if (SERDES_IPW_TYPES_VENDOR_ID != SERDES_IP_TYPES_VENDOR_ID)
    #error "Serdes_Ipw_Types.h and Serdes_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_Types.h file are of the same Autosar version */
#if ((SERDES_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != SERDES_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != SERDES_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IPW_TYPES_AR_RELEASE_REVISION_VERSION != SERDES_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ipw_Types.h and Serdes_Ip_Types.h are different"
#endif
/* Check if current file and Serdes_Ip_Types.h file are of the same software version */
#if ((SERDES_IPW_TYPES_SW_MAJOR_VERSION != SERDES_IP_TYPES_SW_MAJOR_VERSION) || \
     (SERDES_IPW_TYPES_SW_MINOR_VERSION != SERDES_IP_TYPES_SW_MINOR_VERSION) || \
     (SERDES_IPW_TYPES_SW_PATCH_VERSION != SERDES_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ipw_Types.h and Serdes_Ip_Types.h are different"
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
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief   The structure contains the hardware channel configuration type.
*/
typedef struct
{
    const Serdes_Ip_ConfigType *   SerdesHwConfig;
} Serdes_Ipw_HwChannelConfigType;

/**
* @brief Define the power modes available for the serdes driver
*/
typedef enum
{
    SERDES_POWER_NORMAL,
    SERDES_POWER_DOWN,
    SERDES_POWER_SAVE_RXTX
} Serdes_ModeType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /*SERDES_IPW_TYPES_H*/


