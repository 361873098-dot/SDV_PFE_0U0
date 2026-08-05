/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IPV_USDHC
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32_RTD_4_0_0_D2210_ASR_REL_4_4_REV_0000_20221031
*
*   (c) Copyright 2022 NXP Semiconductors
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

#ifndef USDHC_IP_CFG_H
#define USDHC_IP_CFG_H

/**
* @file Usdhc_Ip_Cfg.h
*
* @addtogroup Usdhc_Ip
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
*
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Usdhc_Ip_Types.h"
#include "StandardTypes.h"
#include "OsIf.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define USDHC_VENDOR_ID_IP_CFG                          43
#define USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG           4
#define USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG           4
#define USDHC_AR_RELEASE_REVISION_VERSION_IP_CFG        0
#define USDHC_SW_MAJOR_VERSION_IP_CFG                   4
#define USDHC_SW_MINOR_VERSION_IP_CFG                   0
#define USDHC_SW_PATCH_VERSION_IP_CFG                   0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Usdhc_Ip_Types header file are of the same vendor */
#if (USDHC_VENDOR_ID_IP_CFG != USDHC_IP_TYPES_VENDOR_ID_H)
    #error "Usdhc_Ip_Cfg.h and Usdhc_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Usdhc_Ip_Types header file are of the same Autosar version */
#if ((USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG    != USDHC_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG    != USDHC_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (USDHC_AR_RELEASE_REVISION_VERSION_IP_CFG != USDHC_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Usdhc_Ip_Cfg.h and Usdhc_Ip_Types.h are different"
#endif
/* Check if current file and Usdhc_Ip_Types header file are of the same software version */
#if ((USDHC_SW_MAJOR_VERSION_IP_CFG != USDHC_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (USDHC_SW_MINOR_VERSION_IP_CFG != USDHC_IP_TYPES_SW_MINOR_VERSION_H) || \
     (USDHC_SW_PATCH_VERSION_IP_CFG != USDHC_IP_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Usdhc_Ip_Cfg.h and Usdhc_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Usdhc_Ip_Cfg.h and StandardTypes.h are different"
    #endif
    /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((USDHC_AR_RELEASE_MAJOR_VERSION_IP_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (USDHC_AR_RELEASE_MINOR_VERSION_IP_CFG != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Usdhc_Ip_Cfg.h and OsIf.h are different"
    #endif
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

    
/*! @brief Enable/disable dev error detect for USDHC */
#define USDHC_IP_DEV_ERROR_DETECT                     (STD_ON)
/* @brief uSDHC development error detect enable/disable */
#define USDHC_IP_DEV_ASSERT(x)                        DevAssert((x))

/*! @brief Enable/disable cache synchronization */
#define USDHC_IP_SYNCRONIZE_CACHE                     (STD_OFF)
/*! @brief Timeout value to switch voltage */
#define USDHC_IP_SWITCH_VOLTAGE_TIMEOUT               (0x10000000U)
/*! @brief Timeout value to get present status of uSDHC */
#define USDHC_IP_GET_PRESENT_STATUS_TIMEOUT           (0x10000000U)
/*! @brief Timeout value to set card active */
#define USDHC_IP_SETCARDACTIVE_TIMEOUT                (0x10000000U)
/*! @brief Timeout value to set bus clock for uSDHC */
#define USDHC_IP_SETBUSCLOCK_TIMEOUT                  (0x10000000U)
/*! @brief Timeout value to abort current transfer */
#define USDHC_IP_ABORT_TRANSFER_TIMEOUT               (0x10000000U)
/*! @brief Timeout value to reset the uSDHC */
#define USDHC_IP_RESET_TIMEOUT                        (0x10000000U)
/*! @brief Timeout value to transfer operations in synchronized mode  */
#define USDHC_IP_SYNC_TRANSFER_TIMEOUT                (0x10000000U)
/*! @brief Timeout value to transfer operations in asynchronized mode  */
#define USDHC_IP_ASYNC_TRANSFER_TIMEOUT               (0x10000000U)
/*! @brief Timeout value to get card interface condition */
#define USDHC_IP_GET_INTERFACE_CONDITION_TIMEOUT      (0x10000000U)
/*! @brief Multicore support */
#define USDHC_MCORE_ENABLED                           ((STD_OFF))
#define USDHC_MCORE_SEMA4_JOB                         (0x0U)
/* Pre-processor switch to enable and disable the API for MMC boot feature */
#define USDHC_IP_MMC_BOOT_ENABLED                     (STD_OFF)
/*! @brief Default block size to set in Block attribute register */
#define USDHC_IP_DEFAULT_BLOCK_SIZE                   (512U)
/*! @brief  Osif counter type used in timeout detection for USDHC IP operations */
#define USDHC_IP_TIMEOUT_TYPE                         (OSIF_COUNTER_DUMMY)
/*! @brief  Usdhc host supports 3.3V operation */
#define USDHC_IP_V330_SUPPORT                         (STD_ON)
/*! @brief  Usdhc host supports 3V operation */
#define USDHC_IP_V300_SUPPORT                         (STD_ON)
/*! @brief  Usdhc host supports 1.8V operation */
#define USDHC_IP_V180_SUPPORT                         (STD_ON)
/*! @brief Word size of Current platform */
#define USDHC_IP_PLATFORM_WORDSIZE                    (4U)
/*! @brief Cache line length in bytes for current platform */
#define USDHC_IP_CACHE_LINE_LENGTH                    (32UL)
/*! Timeout for MMC card to get stable before receiving CMD0 */
#define USDHC_IP_WAIT_CARD_STABLE                     (1000U)



/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_MemMap.h"
     
 /*! @brief USDHC module configurations */
 extern const Usdhc_Ip_ConfigType EepUsdhcControllerCfg_0;


#define EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* USDHC_IP_CFG_H */
