/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.8.0
*   Build Version        : S32K3_RTD_0_8_0_D2305_ASR_REL_4_7_REV_0000_20230524
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
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

/**
*   @file cantrcv_spi_external_access.c
*
*   @addtogroup spi_external_access
*   @{
*/

#if defined (__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "cantrcv_spi_external_access.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_EXTERNAL_ACCESS_VENDOR_ID_C                      43
#define SPI_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define SPI_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C       7
#define SPI_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define SPI_EXTERNAL_ACCESS_SW_MAJOR_VERSION_C               0
#define SPI_EXTERNAL_ACCESS_SW_MINOR_VERSION_C               8
#define SPI_EXTERNAL_ACCESS_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Spi External Access header file */
#if ( SPI_EXTERNAL_ACCESS_VENDOR_ID_C != SPI_EXTERNAL_ACCESS_VENDOR_ID)
    #error "Spi External Access source file and Spi External Access header file have different vendor ids"
#endif
#if (( SPI_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != SPI_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION    ) || \
     ( SPI_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C    != SPI_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION    ) || \
     ( SPI_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != SPI_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION ))
     #error "AUTOSAR Version Numbers of Spi External Access source file and Spi External Access header file are different"
#endif
#if (( SPI_EXTERNAL_ACCESS_SW_MAJOR_VERSION_C != SPI_EXTERNAL_ACCESS_SW_MAJOR_VERSION) || \
     ( SPI_EXTERNAL_ACCESS_SW_MINOR_VERSION_C != SPI_EXTERNAL_ACCESS_SW_MINOR_VERSION) || \
     ( SPI_EXTERNAL_ACCESS_SW_PATCH_VERSION_C != SPI_EXTERNAL_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi External Access source file and Spi External Access header file are different"
#endif

/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/
#define CANTRCV_43_TJA1145A_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

/*! @brief Pointer to an array of pointers towards the driver structures */
static Std_ReturnType s_transferStatus;

#define CANTRCV_43_TJA1145A_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CANTRCV_43_TJA1145A_START_SEC_CODE
#include "CanTrcv_43_tja1145a_MemMap.h"

#ifndef CANTRCV_43_TJA1145A_SYNC_TRANSMIT
static Std_ReturnType CanTrcv_Ip_WaitForAsyncTransmitEnd(uint32 u32Timeout);
#endif
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : CanTrcv_Ip_WaitForAsyncTransmitEnd
 * Description   : Checks if the SPI transfer has ended
 *
 *END**************************************************************************/
#ifndef CANTRCV_43_TJA1145A_SYNC_TRANSMIT
static Std_ReturnType CanTrcv_Ip_WaitForAsyncTransmitEnd(uint32 u32Timeout)
{
    Std_ReturnType    TempRet = (Std_ReturnType)E_NOT_OK;
    uint32            Loops   = 0U;

    /* Read the sequence result until the u32Timeout expire or it is SPI_SEQ_OK or SPI_SEQ_FAILED */
    do
    {
        if (s_transferStatus == (Std_ReturnType)E_OK)
        {
            TempRet = (Std_ReturnType)E_OK;
            break;
        }
        else
        {
            Loops++;
        }
    } while (Loops < u32Timeout);

    return TempRet;
}
#endif
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : CanTrcv_Ip_SpiTransferExternal
 * Description   : SPI access for external devices
 *
 *END**************************************************************************/
Std_ReturnType CanTrcv_Ip_SpiTransferExternal(const CanTrcv_Ip_SpiSetupType *pSpiSetup, const uint8 * pTxBuffer, uint8 * pRxBuffer)
{
    Std_ReturnType eStatus = E_OK;

#ifdef USE_IPV_DSPI
    const Spi_Ip_ExternalDeviceType *ExternalDevice = pSpiSetup->Extension;
    (void)pSpiSetup->Spi; /* Unused parameter. */
#elif defined(USE_IPV_LPSPI)
    const Lpspi_Ip_ExternalDeviceType *ExternalDevice = pSpiSetup->Extension;
    (void)pSpiSetup->Spi; /* Unused parameter. */
#else
    const Spi_DataBufferType *spiDataToSend = (const Spi_DataBufferType *)pTxBuffer;
    Spi_DataBufferType       *spiReceivedData = (Spi_DataBufferType *)pRxBuffer;
    const Spi_SequenceType   *SpiSequence = pSpiSetup->Extension;
#if (2U != CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED)
    (void)pSpiSetup->SyncTransmit;  /* Unused parameter. */
    (void)pSpiSetup->Timeout;  /* Unused parameter. */
#endif /* (2U != CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED) */
#endif

    /* Start SPI transfer */
#ifdef USE_IPV_DSPI
    if (FALSE == pSpiSetup->SyncTransmit)
    {
        s_transferStatus = E_NOT_OK;
        eStatus = (Std_ReturnType)Spi_Ip_AsyncTransmit(ExternalDevice,
                                                     (uint8 *)pTxBuffer,
                                                     (uint8 *)pRxBuffer,
                                                     (uint16)pSpiSetup->NumberOfBytes,
                                                     (Spi_Ip_CallbackType)CanTrcv_Ip_SpiNotifyTransferEnd);
        eStatus |= (Std_ReturnType)CanTrcv_Ip_WaitForAsyncTransmitEnd(pSpiSetup->Timeout);
    }
    else
    {
        eStatus = (Std_ReturnType)Spi_Ip_SyncTransmit(ExternalDevice,
                                                    (uint8 *)pTxBuffer,
                                                    (uint8 *)pRxBuffer,
                                                    (uint16)pSpiSetup->NumberOfBytes,
                                                    pSpiSetup->Timeout);
    }
#elif defined(USE_IPV_LPSPI)
    if (FALSE == pSpiSetup->SyncTransmit)
    {
        s_transferStatus = E_NOT_OK;
        eStatus = (Std_ReturnType)Lpspi_Ip_AsyncTransmit(ExternalDevice,
                                                       (uint8 *)pTxBuffer,
                                                       (uint8 *)pRxBuffer,
                                                       (uint16)pSpiSetup->NumberOfBytes,
                                                       (Lpspi_Ip_CallbackType)CanTrcv_Ip_SpiNotifyTransferEnd);
        eStatus |= (Std_ReturnType)CanTrcv_Ip_WaitForAsyncTransmitEnd(pSpiSetup->Timeout);
    }
    else
    {
        eStatus = (Std_ReturnType)Lpspi_Ip_SyncTransmit(ExternalDevice,
                                                      (uint8 *)pTxBuffer,
                                                      (uint8 *)pRxBuffer,
                                                      (uint16)pSpiSetup->NumberOfBytes,
                                                      pSpiSetup->Timeout);
    }
#else
    eStatus = (Std_ReturnType)Spi_SetupEB((Spi_ChannelType) pSpiSetup->Spi, spiDataToSend, spiReceivedData, (Spi_NumberOfDataType)pSpiSetup->NumberOfBytes);

    if ((Std_ReturnType)E_OK == eStatus)
    {
#if (2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED)
        if (FALSE == pSpiSetup->SyncTransmit)
        {
#endif /* (2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED) */
            s_transferStatus = E_NOT_OK;
#if ((2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED) || (1U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED))
            eStatus |= (Std_ReturnType)Spi_AsyncTransmit(*SpiSequence);
            eStatus |= (Std_ReturnType)CanTrcv_Ip_WaitForAsyncTransmitEnd(pSpiSetup->Timeout);
#endif /* ((2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED) || (1U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED)) */
#if (2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED)
        }
        else
        {
#endif /* (2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED) */
#if ((2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED) || (0U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED))
            eStatus |= (Std_ReturnType)Spi_SyncTransmit(*SpiSequence);
#endif /* ((2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED) || (0U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED)) */
#if (2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED)
        }
#endif /* (2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED) */
    }
#endif
    (void)s_transferStatus;

    return eStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CanTrcv_Ip_SpiSetAsyncMode
 * Description   : Sets the SPI asynchronous mode
 *
 *END**************************************************************************/
Std_ReturnType CanTrcv_Ip_SpiSetAsyncMode(void)
{
#ifdef USE_IPV_DSPI
    return E_OK;
#elif defined(USE_IPV_LPSPI)
    return E_OK;
#else
    #if (2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED)
        return Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    #else
        return E_NOT_OK;
    #endif /* (2U == CANTRCV_43_TJA1145A_SPI_LEVEL_DELIVERED) */
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CanTrcv_Ip_SpiNotifyTransferEnd
 * Description   : Notifies the SPI transfer end
 *
 *END**************************************************************************/
#ifdef USE_IPV_DSPI
void CanTrcv_Ip_SpiNotifyTransferEnd(const uint8 u8Instance,const Spi_Ip_EventType eEvent)
{
    /* Update s_transferStatus value */
    s_transferStatus = (Std_ReturnType)eEvent;
    (void)u8Instance;

    return;
}
#elif defined(USE_IPV_LPSPI)
void CanTrcv_Ip_SpiNotifyTransferEnd(const uint8 u8Instance, const Lpspi_Ip_EventType eEvent)
{
    /* Update s_transferStatus value */
    s_transferStatus = (Std_ReturnType)eEvent;
    (void)u8Instance;

    return;
}
#else
void CanTrcv_Ip_SpiNotifyTransferEnd(void)
{
    /* Update s_transferStatus value */
    s_transferStatus = E_OK;

    return;
}
#endif

#define CANTRCV_43_TJA1145A_STOP_SEC_CODE
#include "CanTrcv_43_tja1145a_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @}*/
