/*
*   Copyright 2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crypto.h"
#include "OsIf.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Function-like macros to set and get the status of the example run */
#define App_SetSuccessStatus(value)                 (u32NumFailedOperations += ((value) ? 0U : 1U))
#define App_GetSuccessStatus()                      (0U == u32NumFailedOperations)

/* Identifier of the KeyElement that contains the key material */
#define KEY_MATERIAL_ELEMENT_ID_U32                 ((uint32)1U)

/* Take the generated value of the CMAC Counter key id from the configuration file */
#define APP_CMAC_KEY_ID                             (CryptoConf_CryptoKey_Crypto_Key_CMAC_Counter)
/* Size in bytes of the CMAC generate/verify key */
#define APP_CMAC_KEY_SIZE                           (16U)
/* Size of the CMAC resulted tag */
#define APP_CMAC_TAG_SIZE                           (16U)
/* Size of the data used to compute CMAC over */
#define APP_CMAC_DATA_SIZE                          (16U)

/* Defines related to the monotonic counters used for CMAC Generate/Verify */
#define APP_CMAC_GENERATE_VERIFY_CTR_NUM            (2U)
#define APP_CMAC_GENERATE_VERIFY_CTR_RP_NUM_BITS    (40U)

/* Defines related to the monotonic counter used for CMAC Generate */
#define APP_CMAC_GENERATE_CTR_IDX                   (0U)
#define APP_CMAC_GENERATE_CTR_MAX_VOLATILE_VALUE    (0xFFFFFFU)

/* Defines related to the monotonic counter used for CMAC Verify */
#define APP_CMAC_VERIFY_CTR_IDX                     (1U)
#define APP_CMAC_VERIFY_CTR_INCREMENT_VALUE         (0x1000000U)
#define APP_CMAC_VERIFY_CTR_RP_OFFSET               (0x0U)
#define APP_CMAC_VERIFY_CTR_INIT_VOLATILE_VALUE     (50000U)

/* HSE Key Handle identifier for the key AES128 key that will be used for CMAC generation/verification
   It is the HSE key handle of the key material element of the Crypto key CryptoConf_CryptoKey_Crypto_Key_CMAC_Counter */
#define APP_CMAC_KEY_HANDLE                         GET_KEY_HANDLE(HSE_KEY_CATALOG_ID_RAM, 0, 0)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/* Payload of the AES128 key that will be used for CMAC generation/verification */
static const uint8 App_au8CmacKey[APP_CMAC_KEY_SIZE] __attribute__((aligned)) =
{
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};

/* Data used to compute the CMAC tag over */
static const uint8 App_au8CmacData[APP_CMAC_DATA_SIZE] =
{
    0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a
};

/* Expected value of the tag obtained after performing CMAC generate over the data in App_au8CmacData */
static const uint8 App_au8ExpectedCmacGenerateTag[APP_CMAC_TAG_SIZE] =
{
    0x6f, 0xe9, 0xde, 0x94, 0x09, 0x62, 0x76, 0x12, 0x1B, 0x59, 0x2f, 0xe3, 0x8e, 0xe3, 0x9c, 0xdd
};

/* Value of the tag sent to CMAC verify to compare with the CMAC tag performed over the data in App_au8CmacData */
static const uint8 App_au8CmacTagVerify[APP_CMAC_TAG_SIZE] =
{
    0x62, 0x34, 0x01, 0x27, 0xcb, 0xb9, 0xc3, 0x55, 0xa4, 0x07, 0x34, 0xb8, 0xc1, 0x06, 0x67, 0xff
};

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/* Variable storing the number of failed operations in the example */
static uint32 u32NumFailedOperations = 0U;

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Crypto_MemMap.h"

/* Descriptor for creating a synchronous request to HSE using Csm_KeyElementGet() API with keyElementId set to 0xFEEDDE5C */
static hseSrvDescriptor_t Hse_SrvDescriptor;

#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Crypto_MemMap.h"

/* The following RAM variables need to be put in non-cacheable memory in order to be correctly seen by HSE */
#define CRYPTO_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Crypto_MemMap.h"

/* Variable storing the volatile part of the monotonic counter used in CMAC generate operation */
static uint32 App_u32CmacGenerateCtrVolatileVal;

/* Variable storing the volatile part of the monotonic counter used in CMAC verify operation */
static uint32 App_u32CmacVerifyCtrVolatileVal;

#define CRYPTO_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

/* Buffer where HSE FW will upload the tag of the CMAC generate operation */
static uint8  App_au8CmacGenerateTagBuffer[APP_CMAC_TAG_SIZE];

#define CRYPTO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Utility functions */
static boolean Util_Memcmp
(
    uint8* pSource,
    uint8* pDest,
    uint32 u32Size
);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Utility functions */
static boolean Util_Memcmp
(
    uint8* pSource,
    uint8* pDest,
    uint32 u32Size
)
{
    boolean bResult      = (boolean)TRUE;
    uint32  u32InputSize = u32Size;

    while (0U < u32InputSize--)
    {
        if (*pSource == *pDest)
        {
            pSource++;
            pDest++;
        }
        else
        {
            bResult = (boolean)FALSE;
            break;
        }
    }
    return bResult;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          Performs a CMAC generate with counter followed by a CMAC verify with counter operations
*
* @details        Exercises the CMAC with counter Generate/Verify features of the HSE firwmare using the Crypto_KeyElementGet() API of the Cryto driver
*
*/
int main(void)
{
    Std_ReturnType   RetVal;
    /* Variable storing the response from Hse after feeding a Hse descriptor using Crypto_KeyElementGet() API with a keyElementId set to 0xFEEDDE5C */
    hseSrvResponse_t HseResponse;

    /* =============================================================================================================================== */
    /*    Initialization                                                                                                               */
    /* =============================================================================================================================== */
    /* Initialize OsIf component. It will be used to measure timeouts while waiting for HSE to respond to synchronous requests */
    OsIf_Init(NULL_PTR);
    /* Initialize Crypto driver */
    Crypto_Init(NULL_PTR);

    /* Format HSE key catalogs (RAM + NVM) */
    RetVal = Crypto_Exts_FormatKeyCatalogs();
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);

    /* =============================================================================================================================== */
    /*    Key management                                                                                                               */
    /* =============================================================================================================================== */
    /* Load the CMAC key */
    RetVal = Crypto_KeyElementSet(APP_CMAC_KEY_ID, KEY_MATERIAL_ELEMENT_ID_U32, App_au8CmacKey, APP_CMAC_KEY_SIZE);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);

    /* =============================================================================================================================== */
    /*    Configure the monotonic counters. This operation is done once for counters used for both CMAC Generate/Verify                */
    /* =============================================================================================================================== */

    /* Prepare the HSE descriptor */
    Hse_SrvDescriptor.srvId                                = HSE_SRV_ID_CONFIG_COUNTER;
    /* For HSE_H, counterIndex specifies the number of counters to be enabled (max 16).
       E.g. if it is set to 5, the counters with the index from 0 to 4 are enabled. */
    Hse_SrvDescriptor.hseSrv.configSecCounter.counterIndex = APP_CMAC_GENERATE_VERIFY_CTR_NUM;
    Hse_SrvDescriptor.hseSrv.configSecCounter.RPBitSize    = APP_CMAC_GENERATE_VERIFY_CTR_RP_NUM_BITS;
    /* Send the HSE descriptor to the firmware for synchronous processing */
    RetVal = Crypto_KeyElementGet(CryptoConf_CryptoKey_Crypto_Key_FEEDDE5C,      /* uint32  keyId           */
                                  0xFEEDDE5CU,                                   /* uint32  keyElementId    */
                                  (uint8*)&Hse_SrvDescriptor,                    /* uint8*  resultPtr       */
                                  (uint32*)&HseResponse                          /* uint32* resultLengthPtr */
                                 );
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);
    App_SetSuccessStatus(HSE_SRV_RSP_OK == HseResponse);

    /* =============================================================================================================================== */
    /*    Generate CMAC with counter                                                                                                   */
    /* =============================================================================================================================== */
    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    Increment the monotonic counter to the maximum value of the volatile part                                                    */
    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /* Prepare the HSE descriptor */
    Hse_SrvDescriptor.srvId                             = HSE_SRV_ID_INCREMENT_COUNTER;
    Hse_SrvDescriptor.hseSrv.incCounterReq.counterIndex = APP_CMAC_GENERATE_CTR_IDX;
    Hse_SrvDescriptor.hseSrv.incCounterReq.value        = APP_CMAC_GENERATE_CTR_MAX_VOLATILE_VALUE;
    /* Send the HSE descriptor to the firmware for synchronous processing */
    RetVal = Crypto_KeyElementGet(CryptoConf_CryptoKey_Crypto_Key_FEEDDE5C,      /* uint32  keyId           */
                                  0xFEEDDE5CU,                                   /* uint32  keyElementId    */
                                  (uint8*)&Hse_SrvDescriptor,                    /* uint8*  resultPtr       */
                                  (uint32*)&HseResponse                          /* uint32* resultLengthPtr */
                                 );
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);
    App_SetSuccessStatus(HSE_SRV_RSP_OK == HseResponse);

    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    Generate CMAC with counter                                                                                                   */
    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /* Initialize the variable used by HSE to return the volatile part of the used monotonic counter to some random value */
    App_u32CmacGenerateCtrVolatileVal = 0x7654U;
    /* Prepare the HSE descriptor */
    Hse_SrvDescriptor.srvId                                      = HSE_SRV_ID_CMAC_WITH_COUNTER;
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.authDir          = HSE_AUTH_DIR_GENERATE;
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.keyHandle        = APP_CMAC_KEY_HANDLE;
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.counterIdx       = APP_CMAC_GENERATE_CTR_IDX;
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.inputBitLength   = HSE_BYTES_TO_BITS(APP_CMAC_DATA_SIZE);
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.pInput           = HSE_PTR_TO_HOST_ADDR(App_au8CmacData);
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.tagBitLength     = HSE_BYTES_TO_BITS(APP_CMAC_TAG_SIZE);
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.pTag             = HSE_PTR_TO_HOST_ADDR(App_au8CmacGenerateTagBuffer);
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.pVolatileCounter = HSE_PTR_TO_HOST_ADDR(&App_u32CmacGenerateCtrVolatileVal);
    /* Send the HSE descriptor to the firmware for synchronous processing */
    RetVal = Crypto_KeyElementGet(CryptoConf_CryptoKey_Crypto_Key_FEEDDE5C,      /* uint32  keyId           */
                                  0xFEEDDE5CU,                                   /* uint32  keyElementId    */
                                  (uint8*)&Hse_SrvDescriptor,                    /* uint8*  resultPtr       */
                                  (uint32*)&HseResponse                          /* uint32* resultLengthPtr */
                                 );
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);
    App_SetSuccessStatus(HSE_SRV_RSP_OK == HseResponse);
    App_SetSuccessStatus(Util_Memcmp(App_au8CmacGenerateTagBuffer,(uint8*)App_au8ExpectedCmacGenerateTag, APP_CMAC_TAG_SIZE));
    App_SetSuccessStatus(App_u32CmacGenerateCtrVolatileVal == 0U);

    /* =============================================================================================================================== */
    /*    Verify CMAC with counter                                                                                                     */
    /* =============================================================================================================================== */
    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    Increment the monotonic counter                                                                                              */
    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /* Prepare the HSE descriptor */
    Hse_SrvDescriptor.srvId                             = HSE_SRV_ID_INCREMENT_COUNTER;
    Hse_SrvDescriptor.hseSrv.incCounterReq.counterIndex = APP_CMAC_VERIFY_CTR_IDX;
    Hse_SrvDescriptor.hseSrv.incCounterReq.value        = APP_CMAC_VERIFY_CTR_INCREMENT_VALUE;
    /* Send the HSE descriptor to the firmware for synchronous processing */
    RetVal = Crypto_KeyElementGet(CryptoConf_CryptoKey_Crypto_Key_FEEDDE5C,      /* uint32  keyId           */
                                  0xFEEDDE5CU,                                   /* uint32  keyElementId    */
                                  (uint8*)&Hse_SrvDescriptor,                    /* uint8*  resultPtr       */
                                  (uint32*)&HseResponse                          /* uint32* resultLengthPtr */
                                 );
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);
    App_SetSuccessStatus(HSE_SRV_RSP_OK == HseResponse);

    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    Verify CMAC with counter                                                                                                     */
    /* ------------------------------------------------------------------------------------------------------------------------------- */
    App_u32CmacVerifyCtrVolatileVal = APP_CMAC_VERIFY_CTR_INIT_VOLATILE_VALUE;
    /* Prepare the HSE descriptor */
    Hse_SrvDescriptor.srvId                                      = HSE_SRV_ID_CMAC_WITH_COUNTER;
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.authDir          = HSE_AUTH_DIR_VERIFY;
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.keyHandle        = APP_CMAC_KEY_HANDLE;
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.counterIdx       = APP_CMAC_VERIFY_CTR_IDX;
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.RPOffset         = APP_CMAC_VERIFY_CTR_RP_OFFSET;
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.inputBitLength   = HSE_BYTES_TO_BITS(APP_CMAC_DATA_SIZE);
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.pInput           = HSE_PTR_TO_HOST_ADDR(App_au8CmacData);
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.tagBitLength     = HSE_BYTES_TO_BITS(APP_CMAC_TAG_SIZE);
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.pTag             = HSE_PTR_TO_HOST_ADDR(App_au8CmacTagVerify);
    Hse_SrvDescriptor.hseSrv.cmacWithCounterReq.pVolatileCounter = HSE_PTR_TO_HOST_ADDR(&App_u32CmacVerifyCtrVolatileVal);
    /* Send the HSE descriptor to the firmware for synchronous processing */
    RetVal = Crypto_KeyElementGet(CryptoConf_CryptoKey_Crypto_Key_FEEDDE5C,      /* uint32  keyId           */
                                  0xFEEDDE5CU,                                   /* uint32  keyElementId    */
                                  (uint8*)&Hse_SrvDescriptor,                    /* uint8*  resultPtr       */
                                  (uint32*)&HseResponse                          /* uint32* resultLengthPtr */
                                 );
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);
    App_SetSuccessStatus(HSE_SRV_RSP_OK == HseResponse);

    /* =============================================================================================================================== */
    /*    Finish application execution, signaling the status                                                                           */
    /* =============================================================================================================================== */
    Exit_Example(App_GetSuccessStatus());
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
