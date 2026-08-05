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

*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SERDES_TYPES_H
#define SERDES_TYPES_H

/**
*   @file    Serdes_Types.h
*   @version 4.0.2
*
*   @brief   AUTOSAR Serdes - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup SERDES_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Serdes_Ipw_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SERDES_TYPES_VENDOR_ID                    43
#define SERDES_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define SERDES_TYPES_AR_RELEASE_MINOR_VERSION     4
#define SERDES_TYPES_AR_RELEASE_REVISION_VERSION  0
#define SERDES_TYPES_SW_MAJOR_VERSION             4
#define SERDES_TYPES_SW_MINOR_VERSION             0
#define SERDES_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Serdes_Ipw_Types.h file are of the same vendor */
#if (SERDES_TYPES_VENDOR_ID != SERDES_IPW_TYPES_VENDOR_ID)
    #error "Serdes_Types.h and Serdes_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ipw_Types.h file are of the same Autosar version */
#if ((SERDES_TYPES_AR_RELEASE_MAJOR_VERSION    != SERDES_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_TYPES_AR_RELEASE_MINOR_VERSION    != SERDES_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_TYPES_AR_RELEASE_REVISION_VERSION != SERDES_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Types.h and Serdes_Ipw_Types.h are different"
#endif
/* Check if current file and Serdes_Ipw_Types.h file are of the same software version */
#if ((SERDES_TYPES_SW_MAJOR_VERSION != SERDES_IPW_TYPES_SW_MAJOR_VERSION) || \
     (SERDES_TYPES_SW_MINOR_VERSION != SERDES_IPW_TYPES_SW_MINOR_VERSION) || \
     (SERDES_TYPES_SW_PATCH_VERSION != SERDES_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Types.h and Serdes_Ipw_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
* @brief Definition for Serdes status
*
*/
typedef enum
{
    SERDES_UNINIT              = 0U,   /**< @brief Serdes was not initialized */
    SERDES_SUCCESS,                    /**< @brief Serdes initalization was successful */
    SERDES_INIT_IN_PROGRESS,           /**< @brief Serdes initalization is in progress */
    SERDES_ERROR                       /**< @brief Serdes initalization was not succesful */
} Serdes_StatusType;


/**
* @brief Definition for job result
*
*/
typedef enum
{
    SERDES_INIT_OK          = 1U, /**< @brief Init job is completed and succesful */
    SERDES_INIT_PENDING     = 2U, /**< @brief Init job is in progress */
    SERDES_INIT_FAILED      = 4U /**< @brief Init job has failed */
}Serdes_JobResultType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          This gives the numeric ID (hardware number) of a Serdes hw Unit
*/
typedef uint8                          Serdes_HwUnitType;

/**
* @brief    Structure that contains Serdes Hw configuration.
* @details  It contains the information specific to one Serdes Hw unit
*/
typedef struct
{
    /**< @brief Numeric instance value of Serdes Hw Unit */
    const Serdes_HwUnitType                              Serdes_HwUnit;

    /**< @brief Structure containing the hardware specific configuration for the channel. */
    const Serdes_Ipw_HwChannelConfigType *                HwChannelConfig;

}Serdes_HwUnitConfigType;

/**
* @brief This type contains initialization data.
* @details This contains initialization data for the Serdes driver. It shall contain:
*         - The number of Serdes modules to be configured
*         - Serdes dependent properties for used HW units
* @implements     Serdes_ConfigType_typedef
*/
typedef struct
{
    /** @brief Configuration CoreID */
    uint32 CoreId;
    /**< @brief Pointer to Serdes hardware unit configuration */
    const Serdes_HwUnitConfigType (*Serdes_HwConfig)[];
}Serdes_ConfigType;

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

#endif /*SERDES_TYPES_H*/
