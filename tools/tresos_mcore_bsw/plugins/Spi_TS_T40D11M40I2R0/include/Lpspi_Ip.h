/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : DSPI
*   Dependencies         : 
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

#ifndef LPSPI_IP_H
#define LPSPI_IP_H

/**
*   @file    Lpspi_Ip.h
*
*
*   @brief   LPSPI IP driver header file.
*   @details LPSPI IP driver header file.

*   @addtogroup LPSPI_DRIVER Lpspi Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lpspi_Ip_Types.h"
#ifdef LPSPI_IP_ENABLE_USER_MODE_SUPPORT
#include "Mcal.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPSPI_IP_VENDOR_ID                       43
#define LPSPI_IP_AR_RELEASE_MAJOR_VERSION        4
#define LPSPI_IP_AR_RELEASE_MINOR_VERSION        4
#define LPSPI_IP_AR_RELEASE_REVISION_VERSION     0
#define LPSPI_IP_SW_MAJOR_VERSION                4
#define LPSPI_IP_SW_MINOR_VERSION                0
#define LPSPI_IP_SW_PATCH_VERSION                2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Lpspi_Ip.h and Lpspi_Ip_Types.h are of the same vendor */
#if (LPSPI_IP_VENDOR_ID != LPSPI_IP_TYPES_VENDOR_ID)
    #error "Lpspi_Ip.h and Lpspi_Ip_Types.h have different vendor ids"
#endif
/* Check if Lpspi_Ip.h file and Lpspi_Ip_Types.h file are of the same Autosar version */
#if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION != LPSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPSPI_IP_AR_RELEASE_MINOR_VERSION != LPSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPSPI_IP_AR_RELEASE_REVISION_VERSION != LPSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Lpspi_Ip.h and Lpspi_Ip_Types.h are different"
#endif
#if ((LPSPI_IP_SW_MAJOR_VERSION != LPSPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPSPI_IP_SW_MINOR_VERSION != LPSPI_IP_TYPES_SW_MINOR_VERSION) || \
     (LPSPI_IP_SW_PATCH_VERSION != LPSPI_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Lpspi_Ip.h and Lpspi_Ip_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((LPSPI_IP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LPSPI_IP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lpspi_Ip.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (STD_ON == LPSPI_IP_SUPPORT)
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/**
* @brief   Export Post-Build configurations.
*/
LPSPI_IP_CONFIG_EXT

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
* @brief            LPSPI peripheral initialization.
* @details          The function initialize the SPI Unit specified in the configuration.
*
* @param[in]        PhyUnitConfigPtr -  pointer to the specified SPI Unit configuration.
*
* @return           LPSPI_IP_STATUS_SUCCESS: Initialization command has been accepted.
*                   LPSPI_IP_STATUS_FAIL: Initialization command has not been accepted.
* @implements Lpspi_Ip_Init_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_Init(const Lpspi_Ip_ConfigType *PhyUnitConfigPtr);

/**
* @brief            LPSPI peripheral deinitialization.
* @details          The function de-initialize the SPI peripheral instance specified.
*                   All registers of SPI peripheral will be reset.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return           LPSPI_IP_STATUS_SUCCESS: De-initialization command has been accepted.
*                   LPSPI_IP_STATUS_FAIL: De-initialization command has not been accepted.
* @implements Lpspi_Ip_DeInit_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_DeInit(uint8 Instance);


/**
* @brief            LPSPI synchronous transmission.
* @details          This function initializes a synchronous transfer using the bus parameters provided
*                   by external device.
*
* @param[in]        ExternalDevice - pointer to the external device where data is transmitted.
* @param[in]        TxBuffer - pointer to transmit buffer.
* @param[in-out]    RxBuffer - pointer to receive buffer.
* @param[in]        Length - number of bytes to be sent.
* @param[in]        TimeOut - duration for sending one frame.
*
* @return           LPSPI_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   LPSPI_IP_FIFO_ERROR: Overflow or underflow error occurred.
*                   LPSPI_IP_STATUS_FAIL: Transmission command has not been accepted.
*                   LPSPI_IP_TIMEOUT: Timeout error occurred.
*
* @implements Lpspi_Ip_SyncTransmit_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_SyncTransmit(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                          const uint8 *TxBuffer,
                                          uint8 *RxBuffer,
                                          uint16 Length,
                                          uint32 TimeOut);

/**
* @brief            LPSPI asynchronous transmission.
* @details          This function initializes an asynchronous transfer using the bus parameters provided
*                   by external device. After Lpspi_Ip_Init function is called, LPSPI_IP_POLLING
*                   mode is set as default to change the default mode Lpspi_Ip_UpdateTransferMode should be called.
*
* @param[in]        ExternalDevice - pointer to the external device where data is transmitted
* @param[in]        TxBuffer - pointer to transmit buffer.
* @param[in-out]    RxBuffer - pointer to receive buffer.
* @param[in]        Length - number of bytes to be sent.
* @param[in]        EndCallback - callback function is called at the end of transfer.
*
* @return           LPSPI_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   LPSPI_IP_STATUS_FAIL: Transmission command has not been accepted.
* @implements Lpspi_Ip_AsyncTransmit_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_AsyncTransmit(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                           const uint8 *TxBuffer,
                                           uint8 *RxBuffer,
                                           uint16 Length,
                                           Lpspi_Ip_CallbackType EndCallback);

#if (STD_ON == LPSPI_IP_HALF_DUPLEX_MODE_SUPPORT)
/**
* @brief            LPSPI synchronous transmission support half duplex mode.
* @details          This function initializes a synchronous transfer using the bus parameters provided
*                   by external device.
*
* @param[in]        ExternalDevice - pointer to the external device where data is transmitted.
* @param[in]        Buffer - pointer to transmit buffer.
* @param[in]        Length - number of bytes to be sent.
* @param[in]        TimeOut - duration for sending one frame.
*
* @return           LPSPI_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   LPSPI_IP_FIFO_ERROR: Overflow or underflow error occurred.
*                   LPSPI_IP_STATUS_FAIL: Transmission command has not been accepted.
*                   LPSPI_IP_TIMEOUT: Timeout error occurred.
*
* @implements Lpspi_Ip_SyncTransmitHalfDuplex_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_SyncTransmitHalfDuplex(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                                    uint8 *Buffer,
                                                    uint16 Length,
                                                    Lpspi_Ip_HalfDuplexType TransferType,
                                                    uint32 TimeOut);

/**
* @brief            LPSPI asynchronous transmission support half duplex mode.
* @details          This function initializes an asynchronous transfer using the bus parameters provided
*                   by external device.
*
* @param[in]        ExternalDevice - pointer to the external device where data is transmitted
* @param[in]        Buffer - pointer to transmit buffer.
* @param[in]        Length - number of bytes to be sent.
* @param[in]        EndCallback - callback function is called at the end of transfer.
*
* @return           LPSPI_IP_STATUS_SUCCESS: Transmission command has been accepted.
*                   LPSPI_IP_STATUS_FAIL: Transmission command has not been accepted.
* @implements Lpspi_Ip_AsyncTransmitHalfDuplex_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_AsyncTransmitHalfDuplex(const Lpspi_Ip_ExternalDeviceType *ExternalDevice,
                                                     uint8 *Buffer,
                                                     uint16 Length,
                                                     Lpspi_Ip_HalfDuplexType TransferType,
                                                     Lpspi_Ip_CallbackType EndCallback);
#endif

/**
* @brief            Get status of HW unit.
* @details          This function returns the status of the specified SPI Hardware microcontroller peripheral.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return           Lpspi_Ip_HwStatusType
* @implements Lpspi_Ip_GetStatus_Activity
*/
Lpspi_Ip_HwStatusType Lpspi_Ip_GetStatus(uint8 Instance);

/**
* @brief            Process transfer in POLLING mode.
* @details          This function shall polls the SPI interrupts linked to SPI peripheral instance allocated to 
*                   the transmission of data to enable the evolution of transmission state machine.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return void
* @implements Lpspi_Ip_ManageBuffers_Activity
*/
void Lpspi_Ip_ManageBuffers(uint8 Instance);

/**
* @brief            LPSPI change frame size.
* @details          This function updates frame size of specific external device configuration for next transfers.
*
* @param[in]        ExternalDevice - pointer to the external device configuration.
* @param[in]        FrameSize - Frame size.
*
* @return           LPSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   LPSPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Lpspi_Ip_UpdateFrameSize_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_UpdateFrameSize(const Lpspi_Ip_ExternalDeviceType *ExternalDevice, uint8 FrameSize);

/**
* @brief            LPSPI change bit order.
* @details          This function updates bits order LSB or MSB of specific external device configuration for next transfer.
*
* @param[in]        ExternalDevice - pointer to the external device configuration.
* @param[in]        Lsb - Data is transferred LSB first or not.
*
* @return           LPSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   LPSPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Lpspi_Ip_UpdateLsb_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_UpdateLsb(const Lpspi_Ip_ExternalDeviceType *ExternalDevice, boolean Lsb);

/**
* @brief            LPSPI change default transmit data.
* @details          This function updates default transmit data of specific external device configuration for next transfer.
*
* @param[in]        ExternalDevice - pointer to the external device configuration.
* @param[in]        DefaultData - New default transmit data.
*
* @return           LPSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   LPSPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Lpspi_Ip_UpdateDefaultTransmitData_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_UpdateDefaultTransmitData(const Lpspi_Ip_ExternalDeviceType *ExternalDevice, uint32 DefaultData);

/**
* @brief            LPSPI change transfer mode.
* @details          This function updates the asynchronous mechanism mode for the specified SPI Hardware microcontroller peripheral.
*
* @param[in]        Instance - SPI peripheral instance number.
* @param[in]        Mode - new mode (interrupt or polling).
*
* @return           LPSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   LPSPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Lpspi_Ip_UpdateTransferMode_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_UpdateTransferMode(uint8 Instance, Lpspi_Ip_ModeType Mode);

/**
* @brief            LPSPI cancel current asynchronous transmission.
* @details          This function cancels an asynchronous transmission in progress for the specified SPI Hardware microcontroller peripheral.
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return void
* @implements Lpspi_Ip_Cancel_Activity
*/
void Lpspi_Ip_Cancel(uint8 Instance);

#if (LPSPI_IP_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief            Change clock mode.
* @details          This function will change clock mode to operate with other clock reference.
*
* @param[in]        Instance - SPI peripheral instance number.
* @param[in]        ClockMode           Clock mode.
*
* @return           LPSPI_IP_STATUS_SUCCESS: Setting command has been accepted.
*                   LPSPI_IP_STATUS_FAIL: Setting command has not been accepted.
* @implements Lpspi_Ip_SetClockMode_Activity
*/
Lpspi_Ip_StatusType Lpspi_Ip_SetClockMode(uint8 Instance, Lpspi_Ip_DualClockModeType ClockMode);
#endif

void Lpspi_Ip_IrqHandler(uint8 Instance);

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#endif
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPSPI_IP_H */

