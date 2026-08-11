
/**
*   @file    CryptoDal_PbCfg.c
*   @version 23.02.0
*
*   @brief   Integration Framework - Crypto Driver Abstraction Layer component configuration file
*   @details This file implements the Crypto DAL configuration interface to application layer.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. Copyright 2017-2021 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
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
#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
 ==================================================================================================*/
#include "CryptoDal_Types.h"
#include "CryptoDal_Cfg.h"
#if (CRYPTODAL_ENABLE_HSE_MEMORY_PROTECTION == STD_ON)
    #include "hse_srv_attr.h"
#endif /* (CRYPTODAL_ENABLE_HSE_MEMORY_PROTECTION == STD_ON) */
/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
#define CRYPTODAL_PBCFG_VENDOR_ID_C                       43
#define CRYPTODAL_CFG_MODULE_ID                           105

#define CRYPTODAL_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define CRYPTODAL_PBCFG_AR_RELEASE_MINOR_VERSION_C        4
#define CRYPTODAL_PBCFG_AR_RELEASE_REVISION_VERSION_C     0

#define CRYPTODAL_PBCFG_SW_MAJOR_VERSION_C                23
#define CRYPTODAL_PBCFG_SW_MINOR_VERSION_C                02
#define CRYPTODAL_PBCFG_SW_PATCH_VERSION_C                0

/*===================================================================================================================
*                                     FILE VERSION CHECKS
====================================================================================================================*/
/* Check if source file and ComDal_Cfg.h header file are of the same vendor */
#if (CRYPTODAL_PBCFG_VENDOR_ID_C != CRYPTODAL_CFG_VENDOR_ID)
    #error "ComDal.c and ComDal_Cfg.h have different vendor ids"
#endif

/* Check if source file and ComDal_Cfg.h header file are of the same Autosar version */
#if ((CRYPTODAL_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CRYPTODAL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTODAL_PBCFG_AR_RELEASE_MINOR_VERSION_C != CRYPTODAL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTODAL_PBCFG_AR_RELEASE_REVISION_VERSION_C != CRYPTODAL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CryptoDal.c and CryptoDal_PbCfg.h are different"
#endif

/* Check if source file and ComDal_Cfg.h header file are of the same Software version */
#if ((CRYPTODAL_PBCFG_SW_MAJOR_VERSION_C != CRYPTODAL_CFG_SW_MAJOR_VERSION) || \
     (CRYPTODAL_PBCFG_SW_MINOR_VERSION_C != CRYPTODAL_CFG_SW_MINOR_VERSION) || \
     (CRYPTODAL_PBCFG_SW_PATCH_VERSION_C != CRYPTODAL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CryptoDal_PbCfg.c and CryptoDal.h are different"
#endif



/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/



#if CRYPTODAL_MAX_CIPHERS > 0


#define CRYPTO_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Crypto_MemMap.h"
VAR(uint8, AUTOMATIC) CryptoDal_CryptoKey_0[32] = {0x85, 0xe3, 0xe6, 0x39, 0x1b, 0x13, 0xc2, 0xa3, 0x23, 0x69, 0xb2, 0x36, 0x80, 0x50, 0x4c, 0xbf, 0x1c, 0x12, 0x7b, 0x10, 0xd2, 0x36, 0x7f, 0xf6, 0x8c, 0x0c, 0x35, 0x6b, 0xa8, 0x86, 0x99, 0x0c};
#define CRYPTO_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Crypto_MemMap.h"




#define CRYPTO_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Crypto_MemMap.h"
VAR(uint8, AUTOMATIC) CryptoDal_CryptoKey_1[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};
#define CRYPTO_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Crypto_MemMap.h"



const CryptoDal_ConfigType CryptoDal_Config[CRYPTODAL_MAX_CIPHERS] = {

    {
        32,     /* Key Length (bytes) */
        CRYPTODAL_AES_256_CMAC, /* Encryption Algorithm */
        CRYPTODAL_CRYPTO, /* Encryption Engine */
        CryptoDal_CryptoKey_0, /* Secret Key */
        0, /* Encryption engine internal reference */
        1 /* Encryption engine internal alternate reference */
    },
    
    {
        16,     /* Key Length (bytes) */
        CRYPTODAL_AES_128_ECB, /* Encryption Algorithm */
        CRYPTODAL_CRYPTO, /* Encryption Engine */
        CryptoDal_CryptoKey_1, /* Secret Key */
        2, /* Encryption engine internal reference */
        2 /* Encryption engine internal alternate reference */
    }
    
};

#if (CRYPTODAL_ENABLE_HSE_MEMORY_PROTECTION == STD_ON)
const hseAttrMUConfig_t CryptoDal_Crypto_XRDC_Config = {
    {

    }
};
#endif /* (CRYPTODAL_ENABLE_HSE_MEMORY_PROTECTION == STD_ON) */

#endif /*CRYPTODAL_MAX_CIPHERS > 0*/

/*================================================================================================*/
#ifdef __cplusplus
}
#endif

