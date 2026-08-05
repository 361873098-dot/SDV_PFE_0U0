
/**
*   @file    CryptoDal_Cfg.h
*   @version 23.02.0
*
*   @brief   Integration Framework - Crypto Driver Abstraction Layer component configuration file
*   @details This file implements the CRYPTODAL configuration header.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup CRYPTODAL
*   @{
*/
/*=========================================================================================================================
*   Project              : AUTOSAR 4.4 MCAL
*   Platform             : CORTEXM
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   
*   SW Version           : 23.02.0
*   Build Version        : S32G3XX_PLATFORM INTEGRATION_23_02_0_RTM_ASR_REL_4_4_REV_0000_20230224
*
============================================================================================================================*/
/*============================================================================================================================
==============================================================================================================================*/
#ifndef CRYPTODAL_CFG_H
#define CRYPTODAL_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "Mcal.h"
#include "CryptoDal_Types.h"
/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#define CRYPTODAL_CFG_VENDOR_ID                       43

#define CRYPTODAL_CFG_AR_RELEASE_MAJOR_VERSION        4
#define CRYPTODAL_CFG_AR_RELEASE_MINOR_VERSION        4
#define CRYPTODAL_CFG_AR_RELEASE_REVISION_VERSION     0

#define CRYPTODAL_CFG_SW_MAJOR_VERSION                23
#define CRYPTODAL_CFG_SW_MINOR_VERSION                02
#define CRYPTODAL_CFG_SW_PATCH_VERSION                0


/*===================================================================================================================
*                                     FILE VERSION CHECKS
====================================================================================================================*/
/* Check if source file and CRYPTODAL header file are of the same vendor */
#if (CRYPTODAL_CFG_VENDOR_ID != CRYPTODAL_TYPES_VENDOR_ID)
    #error "CryptoDal_Cfg.h and CryptoDal_Types.h have different vendor ids"
#endif

/* Check if source file and CRYPTODAL header file are of the same Autosar version */
#if ((CRYPTODAL_CFG_AR_RELEASE_MAJOR_VERSION != CRYPTODAL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTODAL_CFG_AR_RELEASE_MINOR_VERSION != CRYPTODAL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTODAL_CFG_AR_RELEASE_REVISION_VERSION != CRYPTODAL_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CryptoDal_Cfg.h and CryptoDal_Types.h are different"
#endif

/* Check if source file and CRYPTODAL header file are of the same Software version */
#if ((CRYPTODAL_CFG_SW_MAJOR_VERSION != CRYPTODAL_TYPES_SW_MAJOR_VERSION) || \
     (CRYPTODAL_CFG_SW_MINOR_VERSION != CRYPTODAL_TYPES_SW_MINOR_VERSION) || \
     (CRYPTODAL_CFG_SW_PATCH_VERSION != CRYPTODAL_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CryptoDal_Cfg.h and CryptoDal_Types.h are different"
#endif


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

#define CryptoDescriptors_CMAC 0
#define CryptoDescriptors_ECB 1

#define CRYPTODAL_MAX_CIPHERS 2 
#define CRYPTODAL_USE_CRYPTO STD_ON 

#define CRYPTODAL_USE_CSEC STD_OFF 

#define CRYPTODAL_SUPPORT_HASHING STD_ON 

#define CRYPTODAL_SUPPORT_CMAC STD_ON 

#define CRYPTODAL_SUPPORT_SMR STD_ON 

#define CRYPTODAL_KEY_CATALOG_FORMAT STD_ON 

#define CRYPTODAL_ENABLE_HSE_MEMORY_PROTECTION STD_OFF 


#define CRYPTODAL_DEV_ERROR_DETECT STD_OFF 


#if CRYPTODAL_MAX_CIPHERS > 0
extern const CryptoDal_ConfigType CryptoDal_Config[CRYPTODAL_MAX_CIPHERS];
#endif

/*================================================================================================*/
#ifdef __cplusplus
}
#endif

#endif  /* CRYPTODAL_TYPES_H*/

