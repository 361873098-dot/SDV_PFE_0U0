/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : HSE
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32_RTD_4_0_0_D2210_ASR_REL_4_4_REV_0000_20221031
*
*   Copyright 2022 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup CRYPTO
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
#include "Crypto_Cfg.h"
#include "Crypto_Private.h"
#include "Crypto.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_VENDOR_ID_CFG_C                      43
#define CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define CRYPTO_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define CRYPTO_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define CRYPTO_SW_MAJOR_VERSION_CFG_C               4
#define CRYPTO_SW_MINOR_VERSION_CFG_C               0
#define CRYPTO_SW_PATCH_VERSION_CFG_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Crypto configuration source file and Crypto configuration header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_CFG_C != CRYPTO_VENDOR_ID_CFG)
    #error "Crypto_Cfg.c and Crypto_Cfg.h have different vendor ids"
#endif

/* Check if Crypto configuration source file and Crypto configuration header file are of the same Autosar version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION_CFG_C != CRYPTO_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Crypto_Cfg.c and Crypto_Cfg.h are different"
#endif

/* Check if Crypto configuration source file and Crypto configuration header file are of the same Software version */
#if ((CRYPTO_SW_MAJOR_VERSION_CFG_C != CRYPTO_SW_MAJOR_VERSION_CFG) || \
     (CRYPTO_SW_MINOR_VERSION_CFG_C != CRYPTO_SW_MINOR_VERSION_CFG) || \
     (CRYPTO_SW_PATCH_VERSION_CFG_C != CRYPTO_SW_PATCH_VERSION_CFG)    \
    )
    #error "Software Version Numbers of Crypto_Cfg.c and Crypto_Cfg.h are different"
#endif

/* Check if Crypto configuration source file and Crypto private header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_CFG_C != CRYPTO_VENDOR_ID_PRIVATE)
    #error "Crypto_Cfg.c and Crypto_Private.h have different vendor ids"
#endif

/* Check if Crypto configuration source file and Crypto private header file are of the same Autosar version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MAJOR_VERSION_PRIVATE) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MINOR_VERSION_PRIVATE) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION_CFG_C != CRYPTO_AR_RELEASE_REVISION_VERSION_PRIVATE) \
    )
    #error "AutoSar Version Numbers of Crypto_Cfg.c and Crypto_Private.h are different"
#endif

/* Check if Crypto configuration source file and Crypto private header file are of the same Software version */
#if ((CRYPTO_SW_MAJOR_VERSION_CFG_C != CRYPTO_SW_MAJOR_VERSION_PRIVATE) || \
     (CRYPTO_SW_MINOR_VERSION_CFG_C != CRYPTO_SW_MINOR_VERSION_PRIVATE) || \
     (CRYPTO_SW_PATCH_VERSION_CFG_C != CRYPTO_SW_PATCH_VERSION_PRIVATE)    \
    )
    #error "Software Version Numbers of Crypto_Cfg.c and Crypto_Private.h are different"
#endif

/* Check if Crypto configuration source file and Crypto header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_CFG_C != CRYPTO_VENDOR_ID)
    #error "Crypto_Cfg.c and Crypto.h have different vendor ids"
#endif

/* Check if Crypto configuration source file and Crypto header file are of the same Autosar version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION_CFG_C != CRYPTO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crypto_Cfg.c and Crypto.h are different"
#endif

/* Check if Crypto configuration source file and Crypto header file are of the same Software version */
#if ((CRYPTO_SW_MAJOR_VERSION_CFG_C != CRYPTO_SW_MAJOR_VERSION) || \
     (CRYPTO_SW_MINOR_VERSION_CFG_C != CRYPTO_SW_MINOR_VERSION) || \
     (CRYPTO_SW_PATCH_VERSION_CFG_C != CRYPTO_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crypto_Cfg.c and Crypto.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#define CRYPTO_START_SEC_CONST_8
#include "Crypto_MemMap.h"

/* Array storing the indexes of the Crypto Driver Objects */
static const uint8 Crypto_au8CDOs[] =
{
    0U
};

#define CRYPTO_STOP_SEC_CONST_8
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

#define CRYPTO_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONST_32
#include "Crypto_MemMap.h"

/* Array of indexes for each Crypto Key Element referred by Crypto Key AES256CMAC_RAM_KEY */
static const uint32 Crypto_au32KeyElementList_AES256CMAC_RAM_KEY[1U] =
{
    0U
};

/* Array of indexes for each Crypto Key Element referred by Crypto Key AES256CMAC_NVM_KEY */
static const uint32 Crypto_au32KeyElementList_AES256CMAC_NVM_KEY[1U] =
{
    1U
};

/* Array of indexes for each Crypto Key Element referred by Crypto Key AES128CBCECB_KEY */
static const uint32 Crypto_au32KeyElementList_AES128CBCECB_KEY[1U] =
{
    2U
};

#define CRYPTO_STOP_SEC_CONST_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/* Array storing the Crypto primitives in the Crypto Driver Object CryptoDriverObject_0 */
static const Crypto_PrimitiveType Crypto_aPrimitives_CryptoDriverObject_0[2U] =
{
    {
        MAC_VERIFY,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CMAC,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        MAC_GENERATE,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CMAC,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    }
};

#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define CRYPTO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

/* Array storing the key element information that is volatile (no need to be persistent across resets) */
static uint8 Crypto_au8VolatileKeyElemValues[4U];

#define CRYPTO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

/* Array storing the queued jobs for the Crypto Driver Object CryptoDriverObject_0 */
static Crypto_QueueElementType Crypto_aQueuedJobs_CryptoDriverObject_0[6U];

#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define CRYPTO_START_SEC_CONST_8
#include "Crypto_MemMap.h"

/* Array storing the mapping of the MU instance per partition */
const Crypto_PartitionToMuMappingType Crypto_aPartitionToMuMapping[CRYPTO_MAX_NUMBER_PARTITIONS_U8] =
{
    {CRYPTO_MU_0_U8, 0x00U}
};

#define CRYPTO_STOP_SEC_CONST_8
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/* Array of structures storing the information of the Crypto Driver Objects mapped on partitions */
const Crypto_PartitionToCdoMappingType Crypto_aPartitionToCdoMapping[CRYPTO_MAX_NUMBER_PARTITIONS_U8] =
{
    /* Structure storing the information of the Crypto Driver Objects */
    {
        /* Number of Crypto Driver Objects */
        1U,
        /* Reference to array storing the indexes of the Crypto Driver Objects */
        Crypto_au8CDOs
    }
};

/* Array of structures storing the information about the Crypto Driver Objects */
const Crypto_ObjectType Crypto_aDriverObjectList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS_U32] =
{
    /* Structure storing the information about Crypto Driver Object CryptoDriverObject_0 */
    {
        /* Reference to the jobs queue */
        Crypto_aQueuedJobs_CryptoDriverObject_0,
        /* Jobs queue size */
        6U,
        /* Reference to the Crypto primitives list */
        Crypto_aPrimitives_CryptoDriverObject_0,
        /* Number of crypto primitives */
        2U
    }
};

/* Array of structures storing the information about the Crypto Keys */
const Crypto_KeyType Crypto_aKeyList[CRYPTO_NUMBER_OF_KEYS_U32] =
{
    {
        /* Number of key elements in the key AES256CMAC_RAM_KEY */
        1U,
        /* Reference to the list of key elements in the key AES256CMAC_RAM_KEY */
        Crypto_au32KeyElementList_AES256CMAC_RAM_KEY
    },
    {
        /* Number of key elements in the key AES256CMAC_NVM_KEY */
        1U,
        /* Reference to the list of key elements in the key AES256CMAC_NVM_KEY */
        Crypto_au32KeyElementList_AES256CMAC_NVM_KEY
    },
    {
        /* Number of key elements in the key AES128CBCECB_KEY */
        1U,
        /* Reference to the list of key elements in the key AES128CBCECB_KEY */
        Crypto_au32KeyElementList_AES128CBCECB_KEY
    }
};

/* Array of structures storing the information about the Crypto Key Elements */
const Crypto_KeyElementType Crypto_aKeyElementList[CRYPTO_NUMBER_OF_KEY_ELEMENTS_U32] =
{
    /* Structure containing information for Key Element Crypto_KE_AES256_CMAC_RAM_GENERATE */
    {
        /* KeyElementId */
        1U,
        /* Allow partial access */
        (boolean)FALSE,
        /* Key element format */
        CRYPTO_KE_FORMAT_BIN_OCTET,
        /* Key element persistent */
        (boolean)FALSE,
        /* Read access type */
        CRYPTO_RA_ALLOWED,
        /* Key element max size */
        32U,
        /* Write access type */
        CRYPTO_WA_ALLOWED,
        /* Pointer to location storing the Key Element actual size */
        (uint32*)&Crypto_au8VolatileKeyElemValues[0U],
        /* Pointer to location storing the Key Element value */
        NULL_PTR,
        /* Identifier of the cipher key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the cipher scheme for key import */
        NULL_PTR,
        /* Identifier of the authentication key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the authentication MAC scheme for key import */
        NULL_PTR,
        /* Reference to the authentication signature scheme for key import */
        NULL_PTR,
        /* Reference to the authentication container for key import */
        NULL_PTR,
        /* HSE key counter */
        0U,
        /* Identifier of the export cipher key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the cipher scheme for key export, only for symmetric key export */
        NULL_PTR,
        /* Identifier of the export authentication key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the MAC authentication scheme for key export */
        NULL_PTR,
        /* Reference to the signature authentication scheme for key export */
        NULL_PTR,
        /* ECC curve id */
        HSE_EC_CURVE_NONE,
        /* Flags of the HSE key */
        ((uint16)(HSE_KF_USAGE_SIGN | 0U)),
        /* HSE key SMR flags */
        0x00000000U,
        /* HSE key type */
        (uint8)HSE_KEY_TYPE_AES,
        /* Identifier of the HSE key in the key catalogs */
        0x00020000U
    },
    /* Structure containing information for Key Element Crypto_KE_AES256_CMAC_NVM_VERIFY */
    {
        /* KeyElementId */
        1U,
        /* Allow partial access */
        (boolean)FALSE,
        /* Key element format */
        CRYPTO_KE_FORMAT_BIN_OCTET,
        /* Key element persistent */
        (boolean)TRUE,
        /* Read access type */
        CRYPTO_RA_ALLOWED,
        /* Key element max size */
        32U,
        /* Write access type */
        CRYPTO_WA_ALLOWED,
        /* Pointer to location storing the Key Element actual size */
        (uint32*)&Crypto_au8NvramBlob1[0U],
        /* Pointer to location storing the Key Element value */
        NULL_PTR,
        /* Identifier of the cipher key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the cipher scheme for key import */
        NULL_PTR,
        /* Identifier of the authentication key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the authentication MAC scheme for key import */
        NULL_PTR,
        /* Reference to the authentication signature scheme for key import */
        NULL_PTR,
        /* Reference to the authentication container for key import */
        NULL_PTR,
        /* HSE key counter */
        0U,
        /* Identifier of the export cipher key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the cipher scheme for key export, only for symmetric key export */
        NULL_PTR,
        /* Identifier of the export authentication key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the MAC authentication scheme for key export */
        NULL_PTR,
        /* Reference to the signature authentication scheme for key export */
        NULL_PTR,
        /* ECC curve id */
        HSE_EC_CURVE_NONE,
        /* Flags of the HSE key */
        ((uint16)(HSE_KF_USAGE_ENCRYPT | HSE_KF_USAGE_VERIFY | HSE_KF_USAGE_DECRYPT | 0U)),
        /* HSE key SMR flags */
        0x00000000U,
        /* HSE key type */
        (uint8)HSE_KEY_TYPE_AES,
        /* Identifier of the HSE key in the key catalogs */
        0x00010001U
    },
    /* Structure containing information for Key Element Crypto_KE_AES128_DECRYPT */
    {
        /* KeyElementId */
        1U,
        /* Allow partial access */
        (boolean)FALSE,
        /* Key element format */
        CRYPTO_KE_FORMAT_BIN_OCTET,
        /* Key element persistent */
        (boolean)TRUE,
        /* Read access type */
        CRYPTO_RA_ALLOWED,
        /* Key element max size */
        16U,
        /* Write access type */
        CRYPTO_WA_ALLOWED,
        /* Pointer to location storing the Key Element actual size */
        (uint32*)&Crypto_au8NvramBlob1[4U],
        /* Pointer to location storing the Key Element value */
        NULL_PTR,
        /* Identifier of the cipher key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the cipher scheme for key import */
        NULL_PTR,
        /* Identifier of the authentication key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the authentication MAC scheme for key import */
        NULL_PTR,
        /* Reference to the authentication signature scheme for key import */
        NULL_PTR,
        /* Reference to the authentication container for key import */
        NULL_PTR,
        /* HSE key counter */
        0U,
        /* Identifier of the export cipher key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the cipher scheme for key export, only for symmetric key export */
        NULL_PTR,
        /* Identifier of the export authentication key in the key catalogs */
        (uint32)HSE_INVALID_KEY_HANDLE,
        /* Reference to the MAC authentication scheme for key export */
        NULL_PTR,
        /* Reference to the signature authentication scheme for key export */
        NULL_PTR,
        /* ECC curve id */
        HSE_EC_CURVE_NONE,
        /* Flags of the HSE key */
        ((uint16)(HSE_KF_USAGE_DECRYPT | 0U)),
        /* HSE key SMR flags */
        0x00000000U,
        /* HSE key type */
        (uint8)HSE_KEY_TYPE_AES,
        /* Identifier of the HSE key in the key catalogs */
        0x00010005U
    }
};

/* Table containing NVM key catalog entries */
const hseKeyGroupCfgEntry_t aHseNvmKeyCatalog[] =
{
    /* NvmKeyGroup_AES */
    {(HSE_MU0_MASK), HSE_KEY_OWNER_CUST, HSE_KEY_TYPE_AES, 10U, 256U, {0U, 0U}},
    /* Marker to end the key catalog */
    {0U, 0U, 0U, 0U, 0U, {0U, 0U}}
};

/* Table containing RAM key catalog entries */
const hseKeyGroupCfgEntry_t aHseRamKeyCatalog[] =
{
    /* RamKeyGroup_AES */
    {(HSE_MU0_MASK), HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_AES, 10U, 256U, {0U, 0U}},
    /* Marker to end the key catalog */
    {0U, 0U, 0U, 0U, 0U, {0U, 0U}}
};

#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define CRYPTO_START_SEC_VAR_CLEARED_8
#include "Crypto_MemMap.h"

/* Array of 8 bit blocks storing a bit map of valid flags for each Crypto key */
uint8 Crypto_au8NvramBlob0[CRYPTO_SIZEOF_NVRAM_BLOB_0];

#define CRYPTO_STOP_SEC_VAR_CLEARED_8
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

/* Array storing blob 1 containing information that should be persistent between resets */
uint8 Crypto_au8NvramBlob1[CRYPTO_SIZEOF_NVRAM_BLOB_1];

#define CRYPTO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

Crypto_ObjectQueueType Crypto_aObjectQueueList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS_U32];

#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

