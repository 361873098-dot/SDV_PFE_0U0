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

/**
* @file
*
* @addtogroup EEP_DRIVER Eeprom Driver
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Eep.h"
#include "Eep_IPW.h"
#include "Det.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_IPW_VENDOR_ID_C                      43
#define EEP_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define EEP_IPW_AR_RELEASE_MINOR_VERSION_C       4
#define EEP_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define EEP_IPW_SW_MAJOR_VERSION_C               4
#define EEP_IPW_SW_MINOR_VERSION_C               0
#define EEP_IPW_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Version checks for OsIf.h */
    #if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_IPW_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep_IPW.c and OsIf.h are different"
    #endif
#endif

/* Version checks for Eep.h */
#if (EEP_IPW_VENDOR_ID_C != EEP_VENDOR_ID)
    #error "Eep_IPW.c and Eep.h have different vendor ids"
#endif
#if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_C    != EEP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_IPW_AR_RELEASE_MINOR_VERSION_C    != EEP_AR_RELEASE_MINOR_VERSION) || \
     (EEP_IPW_AR_RELEASE_REVISION_VERSION_C != EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_IPW.c and Eep.h are different"
#endif
#if ((EEP_IPW_SW_MAJOR_VERSION_C != EEP_SW_MAJOR_VERSION) || \
     (EEP_IPW_SW_MINOR_VERSION_C != EEP_SW_MINOR_VERSION) || \
     (EEP_IPW_SW_PATCH_VERSION_C != EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_IPW.c and Eep.h are different"
#endif

/* Version checks for Eep_IPW.h */
#if (EEP_IPW_VENDOR_ID_C != EEP_IPW_VENDOR_ID_H)
    #error "Eep_IPW.c and Eep_IPW.h have different vendor ids"
#endif
#if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_C    != EEP_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (EEP_IPW_AR_RELEASE_MINOR_VERSION_C    != EEP_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (EEP_IPW_AR_RELEASE_REVISION_VERSION_C != EEP_IPW_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Eep_IPW.c and Eep_IPW.h are different"
#endif
#if ((EEP_IPW_SW_MAJOR_VERSION_C != EEP_IPW_SW_MAJOR_VERSION_H) || \
     (EEP_IPW_SW_MINOR_VERSION_C != EEP_IPW_SW_MINOR_VERSION_H) || \
     (EEP_IPW_SW_PATCH_VERSION_C != EEP_IPW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Eep_IPW.c and Eep_IPW.h are different"
#endif

/* Version checks for Det.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_IPW_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep_IPW.c and Det.h are different"
    #endif
#endif

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

#define EEP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eep_MemMap.h"

/**
*  @brief Variable that indicate the current configuration set for a memory chip
*/
static const Sd_Emmc_Ip_ConfigType * Eep_apCardConfigPtr;
static Usdhc_Ip_StateType  usdhcState;
#define EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eep_MemMap.h"

#if (STD_OFF == USDHC_IP_SYNCRONIZE_CACHE)
#define EEP_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Eep_MemMap.h"

VAR_ALIGN(static uint8 u8ReadBuffer[SD_IP_SDMMC_DEFAULT_BLOCK_SIZE], USDHC_ALIGNMENT_SIZE)

#define EEP_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Eep_MemMap.h"

#else
#define EEP_START_SEC_VAR_CLEARED_8
#include "Eep_MemMap.h"

VAR_ALIGN(static uint8 u8ReadBuffer[SD_IP_SDMMC_DEFAULT_BLOCK_SIZE], USDHC_ALIGNMENT_SIZE)

#define EEP_STOP_SEC_VAR_CLEARED_8
#include "Eep_MemMap.h"
#endif
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#define EEP_START_SEC_CODE
#include "Eep_MemMap.h"

/**
* @brief         Eep_Ipw_Init
* @details       Initialize EEP module
*
* @param[in]     Config SD init configuration
*
* @return        status
* @pre           N/A
*/
Eep_ReturnType Eep_Ipw_Init(Eep_ConfigType const * Config)
{
    const Sd_Emmc_Ip_ConfigType * SdIpConfig = Config->pEepSdConfig;
    Eep_ReturnType        TransferRetVal     = EEP_E_OK;
    Sd_Emmc_Ip_StatusType SdRetVal           = SD_IP_STATUS_SUCCESS;
    Usdhc_Ip_StatusType   UsdhcRetVal        = STATUS_USDHC_IP_SUCCESS;

    /* Save configuration for the card that is Initialized */
    Eep_apCardConfigPtr = SdIpConfig;

    /* Init order the Usdhc controler */
    UsdhcRetVal = uSDHC_Ip_Init(&usdhcState, Eep_apCardConfigPtr->usdhcConfig, 0);
    if (STATUS_USDHC_IP_SUCCESS == UsdhcRetVal)
    {
        SdRetVal = Sd_Emmc_Ip_Init(Eep_apCardConfigPtr);
    }
    /* Init Sd protocol layer */
    if ((STATUS_USDHC_IP_SUCCESS != UsdhcRetVal) || (SD_IP_STATUS_SUCCESS != SdRetVal))
    {
        TransferRetVal = EEP_E_FAILED;
        if (((Usdhc_Ip_StatusType)STATUS_USDHC_IP_TIMEOUT == UsdhcRetVal) || ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal))
        {
            /* Report timeout*/
            (void)Det_ReportRuntimeError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_INIT_ID, EEP_E_TIMEOUT );
        }
    }

    return TransferRetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief       Check if the parameters are ok and the HLD can start the erase job.
 *
 * @param[in]   TargetAddress
 * @param[in]   Length
 *
 * @return      Ok / Not ok to start the erase job.
 * @retval      E_OK
 * @retval      E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Eep_Ipw_CheckEraseParams(Eep_AddressType TargetAddress,
                                        Eep_LengthType Length
                                       )
{
    Std_ReturnType RetVal = E_OK;

    /* Check the target address */
    if((TargetAddress % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U)
    {
    #if( EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_ERASE_ID, EEP_E_PARAM_ADDRESS );
    #endif
        RetVal = E_NOT_OK;
    }

    /* Check the validity of length */
    if ((0U == Length ) || ((Length % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U))
    {
    #if( EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_ERASE_ID, EEP_E_PARAM_LENGTH );
    #endif
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

/**
* @brief         Eep_Ipw_Erase
* @details       Erase data for the given transfer length.
*
* @param[in]     EepromAddrIt Address to start erase
* @param[in]     TransfLength Transfer length to erase
*
* @return        status
* @pre           The driver needs to be initialized.
*/
Eep_ReturnType Eep_Ipw_Erase(Eep_AddressType EepromAddrIt,
                             Eep_LengthType TransfLength
                            )
{
    Sd_Emmc_Ip_StatusType SdRetVal = SD_IP_STATUS_SUCCESS;
    Eep_ReturnType TransferRetVal  = EEP_E_FAILED;
    uint32 BlockCount              = (uint32)((TransfLength/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 StartBlock              = (uint32)((EepromAddrIt/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);

    #if (EEP_ASYNC_ERASE_OPERATIONS_ENABLED == STD_OFF)
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_EraseBlocks(Eep_apCardConfigPtr, StartBlock, BlockCount, (boolean)FALSE);
    #else
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_EraseBlocks(Eep_apCardConfigPtr, StartBlock, BlockCount, (boolean)TRUE);
    #endif

    if (SD_IP_STATUS_SUCCESS == SdRetVal)
    {
        /* Working is done */
        TransferRetVal = EEP_E_OK;
    }
    else if (SD_IP_STATUS_PENDING == SdRetVal)
    {
        /* Working is pending */
        TransferRetVal = EEP_E_PENDING;
    }
    else
    {
        /* Working is not successful */
        TransferRetVal = EEP_E_FAILED;
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
        {
            /* Report timeout*/
            (void)Det_ReportRuntimeError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_MAINFUNCTION_ID, EEP_E_TIMEOUT );
        }
    }

    return TransferRetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Check parameters for the Read job.
 * @param[in] Length
 * @retval E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Eep_Ipw_CheckReadParams(Eep_AddressType SourceAddress,
                                       uint8 const * TargetAddressPtr,
                                       Eep_LengthType Length
                                      )
{
    Std_ReturnType RetVal = E_OK;
    Std_ReturnType CheckTotalSize;

    if (((SourceAddress % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U))
    {
    #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_PARAM_ADDRESS );
    #endif
        RetVal = E_NOT_OK;
    }

    CheckTotalSize = Eep_Ipw_CheckTotalSize(SourceAddress, Length);
    if (( 0U == Length ) || ((Length % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U) || ((Std_ReturnType)E_OK != CheckTotalSize))
    {
    #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_PARAM_LENGTH );
    #endif
        RetVal = E_NOT_OK;
    }

    if (( NULL_PTR == TargetAddressPtr ) || ((Std_ReturnType)E_OK != Eep_Ipw_CheckingAlignmentSource((uint32)TargetAddressPtr)))
    {
    #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError ((uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_PARAM_DATA );
    #endif
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

Eep_ReturnType Eep_Ipw_Read(Eep_AddressType EepromAddrIt,
                            uint8 *JobDataDestPtr,
                            Eep_LengthType TransfLength
                           )
{
    Eep_ReturnType TransferRetVal  = EEP_E_OK;
    uint32 BlockCount              = (uint32)((TransfLength/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 StartBlock              = (uint32)((EepromAddrIt/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    Sd_Emmc_Ip_StatusType SdRetVal = SD_IP_STATUS_SUCCESS;

    /* Read blocks with syn mode */
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_ReadBlocks(Eep_apCardConfigPtr, JobDataDestPtr, StartBlock, BlockCount);
    if (SD_IP_STATUS_SUCCESS != SdRetVal)
    {
        TransferRetVal = EEP_E_FAILED;
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
        {
            /* Report timeout*/
            (void)Det_ReportRuntimeError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_MAINFUNCTION_ID, EEP_E_TIMEOUT );
        }
    }

    return TransferRetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief       Check the parameters given for a Write job.
 *
 * @param[in]   TargetAddress
 * @param[in]   pSourceAddressPtr
 * @param[in]   Length
 *
 * @return Ok / not ok to start the write job with those parameters.
 * @retval E_OK
 * @retval E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Eep_Ipw_CheckWriteParams(Eep_AddressType TargetAddress,
                                        const uint8 * pSourceAddressPtr,
                                        Eep_LengthType Length
                                       )
{
    Std_ReturnType RetVal = E_OK;
    Std_ReturnType CheckTotalSize;

    if((TargetAddress % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U)
    {
    #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_PARAM_ADDRESS );
    #endif
        RetVal = E_NOT_OK;
    }

    CheckTotalSize = Eep_Ipw_CheckTotalSize(TargetAddress, Length);
    if ((0U == Length) || ((Length % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U) || ((Std_ReturnType)E_OK != CheckTotalSize))
    {
    #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_PARAM_LENGTH );
    #endif
        RetVal = E_NOT_OK;
    }

    if(( NULL_PTR == pSourceAddressPtr ) || ((Std_ReturnType)E_OK != Eep_Ipw_CheckingAlignmentSource((uint32)pSourceAddressPtr)))
    {
    #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_PARAM_DATA );
    #endif
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

/**
* @brief         Eep_Ipw_Write
* @details       Write data for the given transfer length in sync mode
*
* @param[in]     JobSrcAddrPtr  Pointer to source buffer
* @param[in]     EepromAddrIt   Address to start writing
* @param[in]     TransfLength   Transfer length to write
*
* @return        status
* @pre           The driver needs to be initialized.
*/
Eep_ReturnType Eep_Ipw_Write(Eep_AddressType EepromAddrIt,
                             const uint8 *JobSrcAddrPtr,
                             Eep_LengthType TransfLength
                            )
{
    Sd_Emmc_Ip_StatusType SdRetVal = SD_IP_STATUS_SUCCESS;
    Eep_ReturnType TransferRetVal  = EEP_E_FAILED;
    uint32 BlockCount            = (uint32)((TransfLength/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 StartBlock            = (uint32)((EepromAddrIt/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);

    #if (EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF)
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_WriteBlocks(Eep_apCardConfigPtr, JobSrcAddrPtr, StartBlock, BlockCount, (boolean)FALSE);
    #else
    SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_WriteBlocks(Eep_apCardConfigPtr, JobSrcAddrPtr, StartBlock, BlockCount, (boolean)TRUE);
    #endif /* #if (EEP_ASYNC_WRITE_OPERATIONS_ENABLED == STD_OFF) */
    if (SD_IP_STATUS_SUCCESS == SdRetVal)
    {
        /* Working is done */
        TransferRetVal = EEP_E_OK;
    }
    else if (SD_IP_STATUS_PENDING == SdRetVal)
    {
        /* Working is pending */
        TransferRetVal = EEP_E_PENDING;
    }
    else
    {
        /* Working is not successful */
        TransferRetVal = EEP_E_FAILED;
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
        {
            /* Report timeout*/
            (void)Det_ReportRuntimeError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_MAINFUNCTION_ID, EEP_E_TIMEOUT );
        }
    }

    return TransferRetVal;
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief  Check the params given for a Compare job.
 *
 * @param[in] SourceAddress
 * @param[in] TargetAddressPtr
 * @param[in] Length
 *
 * @return Ok / not ok to proceed to the compare operation with the given params.
 * @retval E_OK
 * @retval E_NOT_OK
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Std_ReturnType Eep_Ipw_CheckCompareParams(Eep_AddressType SourceAddress,
                                          const uint8 * TargetAddressPtr,
                                          Eep_LengthType Length
                                         )
{
    Std_ReturnType RetVal = E_OK;
    Std_ReturnType CheckTotalSize;

    CheckTotalSize = Eep_Ipw_CheckTotalSize(SourceAddress, Length);

    if(((SourceAddress % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U))
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_PARAM_ADDRESS );
        #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(( 0U == Length ) || ((Length % SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) != 0U) || ((Std_ReturnType)E_OK != CheckTotalSize))
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_PARAM_LENGTH );
        #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Check the target address is aligned */
    else if(( NULL_PTR == TargetAddressPtr ) || ((Std_ReturnType)E_OK != Eep_Ipw_CheckingAlignmentSource((uint32)TargetAddressPtr)))
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_PARAM_DATA );
        #endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    return RetVal;
}

/**
* @brief         Eep_Ipw_CompareSync
* @details       Compare data for the given transfer length in sync mode
*
* @param[in]     JobSrcAddrPtr  Pointer to source buffer
* @param[in]     EepromAddrIt   Address to start comparing
* @param[in]     TransfLength      Transfer length to compare
*
* @return        status
* @pre           The driver needs to be initialized.
*/
Eep_ReturnType Eep_Ipw_CompareSync(Eep_AddressType SrcAddress,
                                   const uint8 *DestAddress,
                                   Eep_LengthType TransfLength
                                  )
{
    Eep_ReturnType TransferRetVal  = EEP_E_OK;
    Sd_Emmc_Ip_StatusType SdRetVal = SD_IP_STATUS_SUCCESS;
    uint32 BlockCount              = (uint32)((TransfLength / SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 StartBlock              = (uint32)((SrcAddress   / SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) & 0xFFFFFFFFU);
    uint32 EndBlock                = 0U;
    uint32 TempDest                = (uint32)DestAddress;
    uint32 TempSrc                 = 0U;
    uint32 TempLength              = 0U;
    uint32 CombinedAddress;

    EndBlock = StartBlock + BlockCount;

    while (StartBlock < EndBlock)
    {
        TempSrc = (uint32)u8ReadBuffer;
        TempLength = SD_IP_SDMMC_DEFAULT_BLOCK_SIZE;

        SdRetVal = (Sd_Emmc_Ip_StatusType)Sd_Emmc_Ip_ReadBlocks(Eep_apCardConfigPtr, u8ReadBuffer, StartBlock, 1U);
        /* if work is not successful */
        if (SD_IP_STATUS_SUCCESS != SdRetVal)
        {
            if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
            {
                /* Report timeout*/
                (void)Det_ReportRuntimeError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_MAINFUNCTION_ID, EEP_E_TIMEOUT );
            }
            TransferRetVal = EEP_E_FAILED;
            break;
        }
        else
        {
            while (0UL < TempLength)
            {
                /* Checking if all alignments and length >= 4U */
                CombinedAddress = TempSrc | TempDest;
                if ( ((CombinedAddress & 0x3U) == 0UL) && (TempLength >= 4UL) )
                {
                    if (*((uint32 *)TempSrc) != *((uint32 *)TempDest))
                    {
                        TransferRetVal = EEP_E_BLOCK_INCONSISTENT;
                    }
                    else
                    {
                        /* Clearing that number in buffer which already compared to make sure that next read which buffer will be empty */
                        *(uint32 *)TempSrc = 0UL;
                        TempSrc = TempSrc + 4UL;
                        TempDest = TempDest + 4UL;
                        TempLength = TempLength - 4UL;
                    }
                }
                /* Checking if data is unaligned and length < 4U */
                else
                {
                    if (*((uint8 *)TempSrc) != *((uint8 *)TempDest))
                    {
                        TransferRetVal = EEP_E_BLOCK_INCONSISTENT;
                    }
                    else
                    {
                        /* Clearing that number in buffer which already compared to make sure that next read which buffer will be empty */
                        *(uint8 *)TempSrc = 0U;
                        TempSrc = TempSrc + 1UL;
                        TempDest = TempDest + 1UL;
                        TempLength = TempLength - 1UL;
                    }
                }

                if (EEP_E_OK != TransferRetVal)
                {
                    /* Exit both this loop and the outer loop */
                    StartBlock = EndBlock - 1U;
                    break;
                }
            }

            /* Increasing block */
            StartBlock++;
        }
    }

    return TransferRetVal;
}

/**
* @brief         Eep_Ipw_Cancel
* @details       Cancel current job
*
* @param[in]     void
*
* @return        status
* @pre           The driver needs to be initialized.
*/
Eep_ReturnType Eep_Ipw_Cancel(void)
{
    Eep_ReturnType TransferRetVal  = EEP_E_FAILED;
    Sd_Emmc_Ip_StatusType SdRetVal = SD_IP_STATUS_SUCCESS;
    /* Abort the on-going operation */
    SdRetVal = Sd_Emmc_Ip_Abort(Eep_apCardConfigPtr);
    if (SD_IP_STATUS_SUCCESS == SdRetVal)
    {
        TransferRetVal = EEP_E_OK;
    }
    else
    {
        /* Abort failed */
        TransferRetVal = EEP_E_FAILED;
        if ((Sd_Emmc_Ip_StatusType)SD_IP_STATUS_TIMEOUT == SdRetVal)
        {
            /* Report timeout*/
            (void)Det_ReportRuntimeError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_CANCEL_ID, EEP_E_TIMEOUT );
        }
    }

    return TransferRetVal;
}

/**
* @brief         Eep_Ipw_CheckingAlignmentSource
* @details       Check for source buffer data to be aligned or not
*
* @param[in]     SourceAddress Source buffer address
*
* @return        status
* @pre           None.
*/
Std_ReturnType Eep_Ipw_CheckingAlignmentSource(uint32 SourceAddress)
{
    Std_ReturnType TransferRetVal = E_OK;

    /* DMA1 will have to be aligned data with 4k in system memory */
    if ((USDHC_DMA_MODE_ADMA1 == Eep_apCardConfigPtr->usdhcConfig->dmaMode) && ((SourceAddress % 4096U) != 0U))
    {
        TransferRetVal = E_NOT_OK;
    }
    /* DMA2 will have to be aligned data with 4 bytes in system memory */
    else if ((USDHC_DMA_MODE_ADMA2 == Eep_apCardConfigPtr->usdhcConfig->dmaMode ) && ((SourceAddress % 4U) != 0U))
    {
        TransferRetVal = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    return TransferRetVal;
}

/**
* @brief         Eep_Ipw_CheckTotalSize
* @details       Check if transfer size exceeds card total block size or not
*
* @param[in]     SourceAddress Target address
* @param[in]     Length        Transfer length
*
* @return        status
* @pre           None.
*/
Std_ReturnType Eep_Ipw_CheckTotalSize(Eep_AddressType TargetAddress,
                                      Eep_LengthType Length
                                     )
{
    Std_ReturnType TransferRetVal = E_OK;
    uint32 TempTotalBlockCounts   = 0U;
    Sd_Emmc_Ip_CardInformationType CardInformation;

    /* Get information from card */
    Eep_Ipw_GetCardInformation(&CardInformation);
    /* Get total block counts of SD/Emmc Cards */
    TempTotalBlockCounts = CardInformation.u32BlockCount;
    /* Checking if inputs over total size of SD/Emmc */
    if (TempTotalBlockCounts < ((TargetAddress/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE) + (Length/SD_IP_SDMMC_DEFAULT_BLOCK_SIZE)))
    {
        TransferRetVal = E_NOT_OK;
    }

    return TransferRetVal;
}
/**
* @brief         Eep_Ipw_GetCardInformation
* @details       This function get card information as Cid, Csd, ...
*
* @param[in]     Pointer to card information
*
* @return        None
* @pre           The SD driver needs to be initialized.
*/
void Eep_Ipw_GetCardInformation(Sd_Emmc_Ip_CardInformationType *CardInformation)
{
    Sd_Emmc_Ip_GetCardInformation(CardInformation);
}
#if( EEP_SWITCHPARTITIONACCESS_API == STD_ON )
/**
* @brief         Eep_Ipw_SwitchPartitionAccess
* @details       This function switch access to desired partition
*
* @param[in]     Sd_Ip_PartitionAccess Partition want to switch
*
* @return        Eep_ReturnType
* @pre           The SD driver needs to be initialized.
*/
Std_ReturnType Eep_Ipw_SwitchPartitionAccess(Sd_Ip_MmcPartitionAccessType Sd_Ip_PartitionAccess)
{
    Std_ReturnType        RetVal = E_OK;
    Sd_Emmc_Ip_StatusType eSdRetVal       = SD_IP_STATUS_SUCCESS;

    /* Switch access to desired partition */
    eSdRetVal = Sd_Emmc_Ip_MmcSwitchPartitionAccess(Eep_apCardConfigPtr, Sd_Ip_PartitionAccess);

    if(SD_IP_STATUS_SUCCESS != eSdRetVal)
    {
        RetVal = E_NOT_OK;
    }

    return RetVal;
}
#endif
#if( EEP_MMC_BOOT_ENABLED == STD_ON )
Std_ReturnType Eep_IpwFastBoot(const Eep_ConfigType * ConfigPtr, uint32 BootBlockCount, uint32* BootBuffer)
{
    const Sd_Emmc_Ip_ConfigType * SdIpConfig = ConfigPtr->pEepSdConfig;
    Usdhc_Ip_StatusType   UsdhcRetVal        = STATUS_USDHC_IP_SUCCESS;
    Std_ReturnType        RetVal             = E_NOT_OK;

    /* Init order the Usdhc controler */
    UsdhcRetVal = uSDHC_Ip_Init(&usdhcState, SdIpConfig->usdhcConfig, 0);

    if (STATUS_USDHC_IP_SUCCESS == UsdhcRetVal)
    {
        UsdhcRetVal = uSDHC_Ip_ProcessFastBoot(SdIpConfig->usdhcConfig->instance, SdIpConfig->usdhcConfig->bootConfig, BootBlockCount, BootBuffer);
        if (STATUS_USDHC_IP_SUCCESS == UsdhcRetVal)
        {
            RetVal = E_OK;
        }
    }
    return RetVal;
}
#endif

#define EEP_STOP_SEC_CODE
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
