/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : OCOTP_IP
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef OCOTP_IP_TYPES_H
#define OCOTP_IP_TYPES_H

/**
*   @file
*
*   @addtogroup OCOTP_IP
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
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_IP_TYPES_VENDOR_ID                    43
#define OCOTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define OCOTP_IP_TYPES_AR_RELEASE_MINOR_VERSION     4
#define OCOTP_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define OCOTP_IP_TYPES_SW_MAJOR_VERSION             4
#define OCOTP_IP_TYPES_SW_MINOR_VERSION             0
#define OCOTP_IP_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((OCOTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (OCOTP_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Ocotp_Ip_Types.c and StandardTypes.h are different"
    #endif
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
 /*!
 * @brief ECC type (single or double error) will be checked.
*/
typedef enum
{
    OCOTP_IP_ECC_SINGLE_ERROR = 0U,             /*!< ECC single error check */
    OCOTP_IP_ECC_DOUBLE_ERROR = 1U              /*!< ECC double error check */
}Ocotp_Ip_EccErrorType;


 /*!
 * @brief FBXC secure mode.
*/
typedef enum
{
    OCOTP_FBXC_NONE_SECURE_MODE = 0U,           /*!< None secure mode mode */
    OCOTP_FBXC_SECURE_MODE = 1U                 /*!< Secure mode mode */
}Ocotp_Ip_SecureModeType;

 /*!
 * @brief FBXC mode operation.
*/
typedef enum
{
    OCOTP_FBXC_NORMAL_MODE = 0U,                /*!< normal run mode */
    OCOTP_FBXC_POWER_DOWN_MODE = 1U             /*!< Powerdown mode */
}Ocotp_Ip_ModeType;

 /*!
 * @brief Ocotp Ip status type.
*/
typedef enum
{
    STATUS_OCOTP_IP_ERROR = 0U,                 /*!< Status error            */
    STATUS_OCOTP_IP_BUSY,                       /*!< Status busy             */
    STATUS_OCOTP_IP_SUCCESS,                    /*!< Status success          */
    STATUS_OCOTP_IP_INVALID_INPUT_ADDRESS,      /*!< invalid input parameter */
    STATUS_OCOTP_IP_ERROR_TIMEOUT               /*!< timeout error           */
} Ocotp_Ip_StatusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief    Ocotp instance type.
* @details  An integer which describe the order of the instance configured.
*/
typedef uint8 Ocotp_InstanceType;

/**
* @brief    User configuration structure.
* @details  Structure contains the configuration parameters which will be used to initialize Ocotp module.
*/
typedef struct
{
    Ocotp_InstanceType ocotpInstance;           /*!< Ocotp instance        */
    Ocotp_Ip_SecureModeType secureMode;         /*!< Secure mode           */
}Ocotp_Ip_ConfigType;
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

#endif /* OCOTP_IP_TYPES_H */
