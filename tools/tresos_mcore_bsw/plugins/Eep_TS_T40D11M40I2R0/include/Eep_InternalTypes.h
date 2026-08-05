
/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : IPV_USDHC
* Dependencies : 
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 4.0.2
* Build Version : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef EEP_INTERNALTYPES_H
#define EEP_INTERNALTYPES_H

/**
* @file
*
* @addtogroup EEP_DRIVER Eeprom Driver
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Eep_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_INTERNALTYPES_VENDOR_ID                    43
#define EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION     4
#define EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION     4
#define EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION  0
#define EEP_INTERNALTYPES_SW_MAJOR_VERSION             4
#define EEP_INTERNALTYPES_SW_MINOR_VERSION             0
#define EEP_INTERNALTYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep configuration header file are of the same vendor */
#if (EEP_INTERNALTYPES_VENDOR_ID != EEP_VENDOR_ID_CFG)
    #error "Eep_InternalTypes.h and Eep_Cfg.h have different vendor ids"
#endif
/* Check if current file and Eep configuration header file are of the same Autosar version */
#if ((EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION    != EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION    != EEP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION != EEP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Eep_InternalTypes.h and Eep_Cfg.h are different"
#endif
/* Check if current file and Eep configuration header file are of the same software version */
#if ((EEP_INTERNALTYPES_SW_MAJOR_VERSION != EEP_SW_MAJOR_VERSION_CFG) || \
     (EEP_INTERNALTYPES_SW_MINOR_VERSION != EEP_SW_MINOR_VERSION_CFG) || \
     (EEP_INTERNALTYPES_SW_PATCH_VERSION != EEP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Eep_InternalTypes.h and Eep_Cfg.h are different"
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Type of job currently executed by Eep_MainFunction.
*/

typedef enum
{
    /**
    * @brief erase one or more complete eeprom sectors
    */
    EEP_JOB_ERASE = 0,
    /**
    * @brief write one or more complete eeprom pages
    */
    EEP_JOB_WRITE,
    /**
    * @brief read one or more bytes from eeprom memory
    */
    EEP_JOB_READ,
    /**
    * @brief compare data buffer with content of eeprom memory
    */
    EEP_JOB_COMPARE

} Eep_JobType;

/**
* @brief          Result of low-level eeprom operation.
*/
typedef enum
{
    EEP_E_OK = 0,                 /**< @brief operation succeeded */
    EEP_E_FAILED,                 /**< @brief operation failed due to hardware error */
    EEP_E_BLOCK_INCONSISTENT,     /**< @brief data buffer doesn't match with content of eeprom memory */
    EEP_E_PENDING                 /**< @brief operation is pending */
} Eep_ReturnType;

/**
* @brief          Size of data to be processeed by CRC.
*
*
*/
typedef enum
{
    EEP_CRC_8_BITS = 0,
    EEP_CRC_16_BITS
} Eep_CrcDataSizeType;

#if (EEP_MCORE_ENABLED == STD_ON)
/* Muticore feature */
/**
* @brief          Eep Multi Core Request Return Type.
* @details        The return value for the function requesting multi core access.
*
*/
typedef enum
{
    EEP_MCORE_ERROR = 0,
    EEP_MCORE_TIMEOUT,
    EEP_MCORE_PENDING,
    EEP_MCORE_GRANTED,
    EEP_MCORE_CANCELLED
} Eep_MCoreReqReturnType;


/**
* @brief          Eep Multi Core hardware job status
* @details        The status of a multicore core flash job, in hardware. Used to determine
*                 if a flash job subject to multicore arbitration was started/suspended/aborted
*                 in hardware, in the flash controller. This can be used for example, to
*                 clear a semaphore granted for erase directly, if the job was not actually started
*                 in hardware, instead of attempting to suspend it.
*
*/
typedef enum
{
    EEP_MCORE_HW_JOB_IDLE = 0,
    EEP_MCORE_HW_JOB_MAINF_STARTED,
    EEP_MCORE_HW_JOB_STARTED,
    EEP_MCORE_HW_JOB_CANCELLED
} Eep_MCoreHwJobStatusType;
#endif /* #if (EEP_MCORE_ENABLED == STD_ON) */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* EEP_INTERNALTYPES_H */

/** @}*/
