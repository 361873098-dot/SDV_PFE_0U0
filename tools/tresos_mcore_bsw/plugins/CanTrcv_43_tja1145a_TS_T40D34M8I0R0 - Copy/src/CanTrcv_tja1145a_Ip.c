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
* @file         CanTrcv_tja1145a_Ip.c
* @version      0.8.0
*
* @brief        AUTOSAR CanTrcv_43_tja1145a - module interface
* @details      API implementation for TJA1145A driver.
*
* @addtogroup   CanTrcv_tja1145a_Driver
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 13.4, value returned by the assignment operator is being used
* Values defined in a for loop are used as indexes for access to array items, which is safe and standatd
* way of using them.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 17.8, modifying parameter
* The parameter is passed by value, therefore it is safe to modify it.
*
* @section [global]
* Violates MISRA 2012 Required Rule 10.8, value cast
* Value is cast to wider data type.
*
* @section [global]
* Violates MISRA 2012 Required Rule 10.5, value cast
* Boolean value is cast to unsigned data type which is used to set a bit of a register.
*
* @section [global]
* Violates MISRA 2012 Required Rule 11.3, pointer cast
* Pointer to uint8 is cast to pointer to uint32 because called function requires a pointer do wider data type.
*
* @section [global]
* Violates MISRA 2012 Required Rule 11.8, removed const qualifier
* The const qualifier can be safely removed because functions in the call stack don't change content of the location
* in case of write command.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 20.1, #include directive preceded by code
* These directives determine memory sections of variables and code, therefore they surround the obejcts they describe.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 8.7, external could be made static
* The function is defined for use by application code.
*
* @section [global]
* Violates MISRA 2012 Required Rule 14.2, the condition clause expression of the for loop has persistent side-effects
* Standard for loop usage.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 12.3, the condition clause expression of the for loop has persistent side-effects
* Standard for loop usage.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 8.13, the pointer variable points to a non-constant type but does not modify the object it points to
* The pointers are part of read command which modifies the object, the pointer points to.
*
* @section [global]
* Violates MISRA 2012 Required Rule 8.10, the inline function is not declared with a static scope
* The functions must have global access because they are part of API.
*
* @section [global]
* Violates MISRA 2012 Required Rule 8.4, object definition does not have a visible prototype
* The object is defined in other file with extern modifier.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 4.8, file includes the definition of obejct but does not use it
* The object is part of included header file.
*
* @section [global]
* Violates MISRA 2012 Required Rule 13.3, operator "++i" in full expression with other potential side effects
* Standard usage of indexe in a for loop.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanTrcv_tja1145a_Ip.h"
#include "CanTrcv_43_tja1145a_Cfg.h"
#include "cantrcv_spi_external_access.h"
#include "SchM_CanTrcv_tja1145a.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
*/
#define TJA1145A_VENDOR_ID_C                      43
#define TJA1145A_MODULE_ID_C                      70
#define TJA1145A_AR_RELEASE_MAJOR_VERSION_C       4
#define TJA1145A_AR_RELEASE_MINOR_VERSION_C       7
#define TJA1145A_AR_RELEASE_REVISION_VERSION_C    0
#define TJA1145A_SW_MAJOR_VERSION_C               0
#define TJA1145A_SW_MINOR_VERSION_C               8
#define TJA1145A_SW_PATCH_VERSION_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanTrcv_tja1145a_Ip header file are of the same vendor */
#if (TJA1145A_VENDOR_ID_C != TJA1145A_VENDOR_ID)
    #error "CanTrcv_tja1145a_Ip.c and CanTrcv_tja1145a_Ip.h have different vendor ids"
#endif
/* Check if current file and CanTrcv_tja1145a_Ip header file are of the same module */
#if (TJA1145A_MODULE_ID_C != TJA1145A_MODULE_ID)
    #error "CanTrcv_tja1145a_Ip.c and CanTrcv_tja1145a_Ip.h have different module ids"
#endif
/* Check if current file and CanTrcv_tja1145a_Ip header file are of the same Autosar version */
#if ((TJA1145A_AR_RELEASE_MAJOR_VERSION_C    != TJA1145A_AR_RELEASE_MAJOR_VERSION) || \
     (TJA1145A_AR_RELEASE_MINOR_VERSION_C    != TJA1145A_AR_RELEASE_MINOR_VERSION) || \
     (TJA1145A_AR_RELEASE_REVISION_VERSION_C != TJA1145A_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CanTrcv_tja1145a_Ip.c and CanTrcv_tja1145a_Ip.h are different"
#endif
/* Check if current file and CanTrcv_tja1145a_Ip header file are of the same Software version */
#if ((TJA1145A_SW_MAJOR_VERSION_C != TJA1145A_SW_MAJOR_VERSION) || \
     (TJA1145A_SW_MINOR_VERSION_C != TJA1145A_SW_MINOR_VERSION) || \
     (TJA1145A_SW_PATCH_VERSION_C != TJA1145A_SW_PATCH_VERSION))
    #error "Software Version Numbers of CanTrcv_tja1145a_Ip.c and CanTrcv_tja1145a_Ip.h are different"
#endif

/* Check if current file and CanTrcv_43_tja1145a_Cfg header file are of the same vendor */
#if (TJA1145A_VENDOR_ID_C != CANTRCV_43_TJA1145A_VENDOR_ID_CFG_H)
    #error "CanTrcv_tja1145a_Ip.c and CanTrcv_43_tja1145a_Cfg.h have different vendor ids"
#endif
/* Check if current file and CanTrcv_43_tja1145a_Cfg header file are of the same module */
#if (TJA1145A_MODULE_ID_C != CANTRCV_43_TJA1145A_MODULE_ID_CFG_H)
    #error "CanTrcv_tja1145a_Ip.c and CanTrcv_43_tja1145a_Cfg.h have different module ids"
#endif
/* Check if current file and CanTrcv_43_tja1145a_Cfg header file are of the same Autosar version */
#if ((TJA1145A_AR_RELEASE_MAJOR_VERSION_C    != CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (TJA1145A_AR_RELEASE_MINOR_VERSION_C    != CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (TJA1145A_AR_RELEASE_REVISION_VERSION_C != CANTRCV_43_TJA1145A_AR_RELEASE_REVISION_VERSION_CFG_H))
    #error "AutoSar Version Numbers of CanTrcv_tja1145a_Ip.c and CanTrcv_43_tja1145a_Cfg.h are different"
#endif
/* Check if current file and CanTrcv_43_tja1145a_Cfg header file are of the same Software version */
#if ((TJA1145A_SW_MAJOR_VERSION_C != CANTRCV_43_TJA1145A_SW_MAJOR_VERSION_CFG_H) || \
     (TJA1145A_SW_MINOR_VERSION_C != CANTRCV_43_TJA1145A_SW_MINOR_VERSION_CFG_H) || \
     (TJA1145A_SW_PATCH_VERSION_C != CANTRCV_43_TJA1145A_SW_PATCH_VERSION_CFG_H))
    #error "Software Version Numbers of CanTrcv_tja1145a_Ip.c and CanTrcv_43_tja1145a_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief Command type.
*
*/
typedef enum
{
	/**< Register Read */
    TJA1145A_COM_READ,
	/**< Register Write */
    TJA1145A_COM_WRITE,
} CanTrcv_tja1145a_CommandType;

/**
* @brief Selects whether to access ID registers or ID mask registers.
*
*/
typedef enum
{
	/**< WUF ID registers will be addressed. */
    TJA1145A_ID_REGS_ACCESS,
	/**< WUF ID mask registers will be addressed. */
    TJA1145A_ID_MASK_REGS_ACCESS,
} CanTrcv_tja1145a_IdRegistersAccessType;

/**
* @brief Structure representing transmit data frame.
*
*/
typedef struct
{
	/** @brief Which device to address. */
	uint8 Transceiver;
    /** @brief Register address. */
    uint8 RegAddress;
    /** @brief Number of bytes to read/write. */
    uint16 BytesNumber;
    /** @brief Command type (R/W). */
    CanTrcv_tja1145a_CommandType CommandType;
    /** @brief Serves two purposes:
	 * - for W Command: points to data to send,
	 *  -for R Command: points to memory location where read out data will be stored. */
	uint8* Data;
} CanTrcv_tja1145a_TrxCommand;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/**
* @brief TJA1145A supports maximum 4 bytes in a single read/write operation.
*/
#define TJA1145A_MAXIMUM_SPI_FRAME_LENGTH	(4U)

/**
* @brief This macro updates value of bits specified by the mask. Additionally range
* check on the value is performed. It is assumed that value is not shifted.
*/
#define TJA1145A_BO_UPDATE_VAL(Data, Value, Mask, Shift) \
    (((Data) & ~(Mask)) | ((((Value) << (Shift)) & (Mask))))

/**
* @brief This macro enables read access to TJA1145A by shifting register address by 1
* to the left and setting the last bit to 1.
* As stated in TJA1145A application hint:
* "The upper seven bits of the 16-, 24- or 32-bit SPI message determine which register is
* addressed. Bit number 8 contains the 'Read-Only' bit (the LSB)."
* The read access is enabled if the 'read-only' bit is set to 1.
*/
#define TJA1145A_BO_ENABLE_READ_ACCESS(Value)	(((Value) << 1U) | 1U)

/**
* @brief This macro enables write access to TJA1145A by shifting register address by 1
* to the left.
* As stated in TJA1145A application hint:
* "The upper seven bits of the 16-, 24- or 32-bit SPI message determine which register is
* addressed. Bit number 8 contains the 'Read-Only' bit (the LSB)."
* Write access is enabled if the 'read-only' bit is set to 0.
*/
#define TJA1145A_BO_ENABLE_WRITE_ACCESS(Value)	((Value) << 1U)


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define CANTRCV_43_TJA1145A_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

/**
* @brief Internal array of Transceiver units connected to MCU
*
*/
CanTrcv_tja1145a_DriverDataType CanTrcv_DeviceList[CANTRCV_43_TJA1145A_MAX_DEVICES_NUM];

#define CANTRCV_43_TJA1145A_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanTrcv_43_tja1145a_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CANTRCV_43_TJA1145A_START_SEC_CODE
#include "CanTrcv_43_tja1145a_MemMap.h"
/**
* @brief        Performs SPI transfer.
*
* @param[in]    Command		Holds information about SPI access (R/W, register address, ...)
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_TransferData_Activity */
static CanTrcv_tja1145a_StatusType TJA1145A_DRV_TransferData(CanTrcv_tja1145a_TrxCommand* Command);

/**
* @brief		Writes wake up frame ID to ID register, or ID mask to mask register according to
*				'access' parameter.
*
* @param[in]    Transceiver		Addressed device.
* @param[in]    Access			Selects whether to access ID registers or ID mask registers.
* @param[in]	Data			WUF ID to write to ID registers.
* @param[in]	IdFormat		11/29 bit ID format.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
static CanTrcv_tja1145a_StatusType TJA1145A_DRV_WriteWufIdRegisters(
	uint8 Transceiver,
	CanTrcv_tja1145a_IdRegistersAccessType Access,
	uint32 Data,
	CanTrcv_tja1145a_IdFormatType IdFormat);

/**
* @brief		Writes data mask registers, which determine wake up pattern of incoming data if data
*				is configured to be part of wake up pattern.
*
* @param[in]    Transceiver		Addressed device.
* @param[in]	Data			Pointer to memory location with data masks for WUF filtering.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
static CanTrcv_tja1145a_StatusType TJA1145A_DRV_WriteDataMaskRegisters(uint8 Transceiver, const uint8* Data);

/**
* @brief		Converts CanTrcv_tja1145a_MemoryRegisterType enum tu HW address.
*
* @param[in]    MemRegister		        Enum to convert to HW address.
* @param[in]	RegisterAddress			Pointer to memory location to store register address.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
static inline CanTrcv_tja1145a_StatusType TJA1145A_DRV_MemoryRegisterToAddress(CanTrcv_tja1145a_MemoryRegisterType MemRegister, uint8* RegisterAddress);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/* Performs SPI transfer. */
static CanTrcv_tja1145a_StatusType TJA1145A_DRV_TransferData(CanTrcv_tja1145a_TrxCommand* Command)
{
	uint16 DstIdx;
    uint16 SrcIdx;
	uint16 RetriesCnt = 0U;
    uint8 TxFrame[TJA1145A_MAXIMUM_SPI_FRAME_LENGTH] = { 0U };
    uint8 RxFrame[TJA1145A_MAXIMUM_SPI_FRAME_LENGTH] = { 0U };
    CanTrcv_Ip_SpiSetupType SpiSetup;
	Std_ReturnType Status;
	
	SpiSetup.Spi = CanTrcv_DeviceList[Command->Transceiver].SpiConfig->SpiChannel;
	SpiSetup.SyncTransmit = CANTRCV_43_TJA1145A_SPI_COM_SYNCHRONOUS;
	SpiSetup.Extension = (const void *) CanTrcv_DeviceList[Command->Transceiver].SpiConfig->SpiExtension;
	SpiSetup.NumberOfBytes = (Command->BytesNumber + 1U); /* Include register address in the length of transfered data. */
	SpiSetup.Timeout = CANTRCV_43_TJA1145A_SPI_COM_TIMEOUT;

    /* First byte to be sent out must be register address for both R/W operations. */
    TxFrame[0] = Command->RegAddress;

    /* Copy data to write into tx buffer. */
    if (TJA1145A_COM_WRITE == Command->CommandType)
    {
    	for (SrcIdx = 0U, DstIdx = 1U; SrcIdx < Command->BytesNumber; SrcIdx++, DstIdx++)
    	{
    		TxFrame[DstIdx] = Command->Data[SrcIdx];
    	}
    }

	do
	{
		/* Trigger the SPI transfer */
		Status = CanTrcv_Ip_SpiTransferExternal(&SpiSetup, TxFrame, RxFrame);
		RetriesCnt++;
	} while ((RetriesCnt <= CANTRCV_43_TJA1145A_SPI_COM_RETRIES) && ((Std_ReturnType)E_NOT_OK == Status));

    /* Copy data retrieved from TJA1145A. */
    if (TJA1145A_COM_READ == Command->CommandType)
	{
    	/* Skip the first byte in retrieved data because it is device status information and not actual
    	 * register content. */
    	for (SrcIdx = 1U, DstIdx = 0U; SrcIdx < SpiSetup.NumberOfBytes; SrcIdx++, DstIdx++)
		{
    		Command->Data[DstIdx] = RxFrame[SrcIdx];
		}
	}

    return (Status == (Std_ReturnType)E_OK) ? TJA1145A_SUCCESS : TJA1145A_ERR_SPI;
}

/* Writes WUF ID, or ID mask register according to 'access' parameter. */
static CanTrcv_tja1145a_StatusType TJA1145A_DRV_WriteWufIdRegisters(uint8 Transceiver, CanTrcv_tja1145a_IdRegistersAccessType Access, uint32 Data, CanTrcv_tja1145a_IdFormatType IdFormat)
{
	uint8 Address;
	uint8 Buff[4U] = { 0U }; 
	CanTrcv_tja1145a_StatusType Status;

	Address = (TJA1145A_ID_REGS_ACCESS == Access) ? TJA1145A_IDENTIFIER_0_ADDR : TJA1145A_MASK_0_ADDR;

	if (TJA1145A_11BIT_IDENTIFIER == IdFormat)
	{
		/* Shift ID by 2 because registers 29h (ID register) and 2Dh (ID mask register) use bits 2-7 as WUF ID (bits 0-5 of WUF ID). */
		Data = Data << 2U;
		
		Buff[0] = (uint8) (Data & 0xFFU);
		/* Take most significant byte a mask it with 0x1F because register 2Ah uses bits 0-4 as WUF ID (bits 6-10 of WUF ID). */
		Buff[1] = (uint8) ((Data >> 8U) & 0x1FU);
		
		Status = TJA1145A_DRV_WriteMultipleRegisters(Transceiver, Address + 2U, 2U, Buff);
	}
	else
	{
		Buff[0] = (uint8) (Data & 0xFFU);
		Buff[1] = (uint8) ((Data >> 8U) & 0xFFU);
		Buff[2] = (uint8) ((Data >> 16U) & 0xFFU);
		Buff[3] = (uint8) ((Data >> 24U) & 0x1FU);
		
		Status = TJA1145A_DRV_WriteMultipleRegisters(Transceiver, Address, 2U, Buff);
		
		if (TJA1145A_SUCCESS == Status)
		{
			Status = TJA1145A_DRV_WriteMultipleRegisters(Transceiver, Address + 2U, 2U, &Buff[2U]);
		}
	}

	return Status;
}

/* Writes data mask registers. */
static CanTrcv_tja1145a_StatusType TJA1145A_DRV_WriteDataMaskRegisters(uint8 Transceiver, const uint8* Data)
{
	uint8 Idx;
    uint8 Offset;
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;

    for (Idx = 0U, Offset = 0u; Idx < 4U; ++Idx, Offset += 2U)
	{
		Status = TJA1145A_DRV_WriteMultipleRegisters(Transceiver,
				TJA1145A_DATA_MASK_0_ADDR + Offset,
				2U,
				&Data[Offset]);

		if (TJA1145A_SUCCESS != Status)
		{
			break;
		}
	}

	return Status;
}

/* Converts CanTrcv_tja1145a_MemoryRegisterType enum to register address. */
static inline CanTrcv_tja1145a_StatusType TJA1145A_DRV_MemoryRegisterToAddress(CanTrcv_tja1145a_MemoryRegisterType MemRegister, uint8* RegisterAddress)
{
    CanTrcv_tja1145a_StatusType Status = TJA1145A_SUCCESS;
    
    switch (MemRegister)
    {
        case TJA1145A_MEMORY_0:
            *RegisterAddress = TJA1145A_MEMORY_0_ADDR;
            break;
        case TJA1145A_MEMORY_1:
            *RegisterAddress = TJA1145A_MEMORY_1_ADDR;
            break;
        case TJA1145A_MEMORY_2:
            *RegisterAddress = TJA1145A_MEMORY_2_ADDR;
            break;
        case TJA1145A_MEMORY_3:
            *RegisterAddress = TJA1145A_MEMORY_3_ADDR;
            break;
        default:
            Status = TJA1145A_ERR_PARAM;
            break;
    }
    
    return Status;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/

/**
* @brief        Performs a read operation from a single TJA1145A register.
*
* @param[in]	Transceiver		Which device to read from.
* @param[in]    RegAddress      Register address.
* @param[out]   RxData	        Pointer to memory location where retrieved data is stored.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_ReadRegister_Activity */
inline CanTrcv_tja1145a_StatusType TJA1145A_DRV_ReadRegister(uint8 Transceiver, uint8 RegAddress, uint8* RxData)
{
    return TJA1145A_DRV_ReadMultipleRegisters(Transceiver, RegAddress, 1U, RxData);
}

/*================================================================================================*/

/**
* @brief        Reads up to three TJA1145A registers in a single read operation.
*
* @details      Address of the first register must be provided in the 'address' parameter.
* 				Addresses of following registers are automatically incremented by TJA1145A.
*
* @param[in]    Transceiver			Which device to read from.
* @param[in]    RegAddress         	Address of first register.
* @param[in]	NumRegisters		Number of registers to read.
* @param[out]   RxData         		Pointer to memory location where retrieved data is stored.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_ReadMultipleRegisters_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ReadMultipleRegisters(uint8 Transceiver, uint8 RegAddress, uint16 NumRegisters, uint8* RxData)
{
	CanTrcv_tja1145a_TrxCommand Command = 
    {
        .Transceiver = Transceiver,
        .CommandType = TJA1145A_COM_READ,
        .RegAddress = TJA1145A_BO_ENABLE_READ_ACCESS(RegAddress),
        .BytesNumber = NumRegisters,
        .Data = RxData
	};

    /* In an attempt to read more than 3 registers, TJA1145A reflects on SDO pin
     * all bits pass bit 32 clocked in on SDI. */

    return TJA1145A_DRV_TransferData(&Command);
}

/*================================================================================================*/

/**
* @brief        Writes data to a single TJA1145A register defined by its address.
*
* @param[in]	Transceiver		Which device to write.
* @param[in]    RegAddress      Register address.
* @param[in]    TxData          Data to write to a register defined by its address.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_WriteRegister_Activity */
inline CanTrcv_tja1145a_StatusType TJA1145A_DRV_WriteRegister(uint8 Transceiver, uint8 RegAddress, uint8 TxData)
{
	return TJA1145A_DRV_WriteMultipleRegisters(Transceiver, RegAddress, 1U, &TxData);
}

/*================================================================================================*/

/**
* @brief        Writes up to three TJA1145A registers in a single write operation.
*
* @details		Address of the first accessed register must be provided via 'address' parameter.
* 				Addresses of following registers are automatically incremented by TJA1145A.
* 				Maximum number of registers accessed at one write operation is 3. Data written
* 				to these registers is passed in via 'TxData' parameter. In an attempt to write
* 				more than 3 registers at once, TJA1145A aborts the operation.
*
* @param[in]	Transceiver			Which device to write.
* @param[in]    RegAddress         	Address of first register.
* @param[in]	NumRegisters		Number of registers to write.
* @param[in]    TxData       		Pointer to memory location with data to send to TJA1145A.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_WriteMultipleRegisters_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_WriteMultipleRegisters(uint8 Transceiver, uint8 RegAddress, uint16 NumRegisters, const uint8* TxData)
{
	CanTrcv_tja1145a_TrxCommand Command =
    {
        .Transceiver = Transceiver,
        .CommandType = TJA1145A_COM_WRITE,
        .RegAddress = TJA1145A_BO_ENABLE_WRITE_ACCESS(RegAddress),
        .BytesNumber = NumRegisters,
        .Data = (uint8*) TxData
	};

    /* If more than 3 data bytes (4 with register address) are sent over SPI,
     * TJA1145A aborts the operation and raises SPI error flag.
     * TJA1145A tolerates write attempts to non-existing registers. */

    return TJA1145A_DRV_TransferData(&Command);
}

/*================================================================================================*/

/**
* @brief		Updates a bit/bit group in a register and leaves the rest of the register unchanged.
*
* @details		Reads a register, then updates its content with a value passed in as an input parameter
*				and writes this updated data to the register.
*
* @param[in]    Transceiver		Addressed device.
* @param[in]	RegAddress		Address of register to write.
* @param[in]	Value			Data to write to register specified by RegAddress parameter.
* @param[in]	Mask			Mask of the value.
* @param[in]	Shift			Value position within the register.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_UpdateRegister_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_UpdateRegister(
		uint8 Transceiver,
		uint8 RegAddress,
		uint8 Value,
		uint8 Mask,
		uint8 Shift)
{
	uint8 RegValue = 0U;
	CanTrcv_tja1145a_StatusType Status;

	SchM_Enter_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_00();
	Status = TJA1145A_DRV_ReadRegister(Transceiver, RegAddress, &RegValue);

	if (TJA1145A_SUCCESS == Status)
	{
		Status = TJA1145A_DRV_WriteRegister(Transceiver, RegAddress, (uint8)TJA1145A_BO_UPDATE_VAL(RegValue, Value, Mask, Shift));
	}
	SchM_Exit_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_00();
	
	return Status;
}

/*================================================================================================*/
/**
* @brief        Initializes the TJA1145A driver. After driver initialization, function
*				TJA1145A_DRV_TransceiverConfiguration must be called to configure the Transceiver.
*
* @details		Stores pointer to device configuration and initializes internal data structure.
*
* @param[in]	Transceiver		Which device to address.
* @param[in]    ConfigData      Pointer to configuration of the device and SPI.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_Init_Activity */
void TJA1145A_DRV_Init(uint8 Transceiver, const CanTrcv_tja1145a_ConfigurationDataType* ConfigData)
{
	CanTrcv_DeviceList[Transceiver].SpiConfig = ConfigData->SpiConfig;
	CanTrcv_DeviceList[Transceiver].DeviceConfig = ConfigData->DeviceConfig;
	CanTrcv_DeviceList[Transceiver].WuReason = TJA1145A_WU_NO_EVENT;
	CanTrcv_DeviceList[Transceiver].SystemError = TJA1145A_NO_SYSTEM_ERROR;
}

/*================================================================================================*/
/**
* @brief        Configures the Transceiver.
*
* @details		Configures CAN controller (and partial networking features), sets event capture
*				features, configures wake up options, and writes lock register.
*
* @param[in]	Transceiver		Which device to address.
* @param[in]	DeviceConfig    Pointer to TJA1145A configuration.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_ConfigureDevice_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ConfigureDevice(uint8 Transceiver, const CanTrcv_tja1145a_DeviceConfigType* DeviceConfig)
{
	uint8 LockRegister = 0U;
	CanTrcv_tja1145a_StatusType Status;
	CanTrcv_tja1145a_LockRegistersType LockControl;

	/* Update reference to device configuration with current data. */
	CanTrcv_DeviceList[Transceiver].DeviceConfig = DeviceConfig;

	LockControl.LockRange06h09h = FALSE;
	LockControl.LockRange10h1Fh = FALSE;
	LockControl.LockRange20h2Fh = FALSE;
	LockControl.LockRange30h3Fh = FALSE;
	LockControl.LockRange40h4Fh = FALSE;
	LockControl.LockRange50h5Fh = FALSE;
	LockControl.LockRange68h6Fh = FALSE;

	/* First, unlock all registers. */
	Status = TJA1145A_DRV_SetLockControlRegister(Transceiver, &LockControl);

	if (TJA1145A_SUCCESS == Status)
    {
		/* Read 'Lock Control' register to check if the device is ready for configuration. */
		Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_LOCK_CONTROL_ADDR, &LockRegister);
		
		/* If content of 'Lock Control' register is non-0, device unlocking failed. */
		if (0U != (LockRegister & 0x7FU))
		{
			Status = TJA1145A_ERR_SPI;
		}
	}

	if (TJA1145A_SUCCESS == Status)
    {
		/* Write CAN controller configuration. */
		Status = TJA1145A_DRV_SetCanConfig(Transceiver, &DeviceConfig->CanConfig);
	}

    if (TJA1145A_SUCCESS == Status)
    {
		/* Interrupts configuration. */
    	Status = TJA1145A_DRV_EventCaptureConfiguration(Transceiver, &DeviceConfig->EventConfig);
    }

    if (TJA1145A_SUCCESS == Status)
    {
		/* Wake up configuration. */
    	Status = TJA1145A_DRV_WakeupConfiguration(Transceiver, &DeviceConfig->WuConfig);
    }

    if (TJA1145A_SUCCESS == Status)
    {
		/* Lock configuration. */
    	Status = TJA1145A_DRV_SetLockControlRegister(Transceiver, &DeviceConfig->LockControl);
    }

    return Status;
}

/*================================================================================================*/

/**
* @brief        Sets the mode of the Transceiver to the value OpMode.
*
* @details		Sets mode of TJA1145A and its CAN controller. These are 2 separate entities with
* 				their own modes. This function puts both in the same mode according to AUTOSAR
* 				specification. Listen only mode of the CAN controller is neglected as AUTOSAR
* 				doesn't allow this mode. Also combination TJA1145A active; CAN controller offline
* 				is neglected.
*
* @param[in]    Transceiver		Which device to address.
* @param[in]	OpMode			Desired operating mode.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_SetMode_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_SetMode(uint8 Transceiver, CanTrcv_TrcvModeType OpMode)
{
	CanTrcv_tja1145a_StatusType Status;

	/* Note: CAN controller switches automatically to offline mode if TJA1145A
	 * is put to standby or sleep mode. Hence, it is needed to explicitly put
	 * CAN controller to active mode, only if TJA1145A is put to normal mode. */

	switch (OpMode)
	{
	case CANTRCV_TRCVMODE_NORMAL:
		/* Set TJA1145A mode. */
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_MODE_CONTROL_ADDR, TJA1145A_M_MC_NORMAL_MODE);
		if (TJA1145A_SUCCESS == Status)
		{
			/* Set CAN controller mode. */
			CanTrcv_tja1145a_CanControllerModeType CanMode;
			/* CAN controller has 2 active modes. Selected mode depends on whether VCC undervoltage detection is on or not.  */
			CanMode = (TJA1145A_VCC_UV_ENABLED == CanTrcv_DeviceList[Transceiver].DeviceConfig->VccUvConfig) ?
					TJA1145A_ACTIVE_MODE_VCC_UV_ACTIVE :
					TJA1145A_ACTIVE_MODE_VCC_UV_INACTIVE;
			Status = TJA1145A_DRV_SetCanControllerMode(Transceiver, CanMode);
		}
		break;

	case CANTRCV_TRCVMODE_STANDBY:
		/* Put TJA1145A to standby mode, CAN controller will switch automatically to offline mode (note: bits
		 * CNC of 'CAN control register' don't indicate this transition). */
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_MODE_CONTROL_ADDR, TJA1145A_M_MC_STANDBY_MODE);
		break;

	case CANTRCV_TRCVMODE_SLEEP:
		/* Put TJA1145A to sleep mode, CAN controller will switch automatically to offline mode (note: bits
		 * CNC of 'CAN control register' don't indicate this transition). */
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_MODE_CONTROL_ADDR, TJA1145A_M_MC_SLEEP_MODE);
		break;

	default:
		Status = TJA1145A_ERR_PARAM;
		break;
	}

	return Status;
}

/*================================================================================================*/

/**
* @brief        Gets the mode of the Transceiver and returns it in OpMode.
*
* @details		Reads 'Mode control register' (address 01h).
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[out]	OpMode				Stores the mode of the Transceiver.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_GetMode_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_GetMode(uint8 Transceiver, CanTrcv_TrcvModeType* OpMode)
{
	uint8 Mode = 0U;
	CanTrcv_tja1145a_StatusType Status;

	SchM_Enter_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_01();
    /* Read 'Mode control register' (address 01h). */
	Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_MODE_CONTROL_ADDR, &Mode);

	if (TJA1145A_SUCCESS == Status)
	{
		switch (Mode & TJA1145A_M_MC_MASK)
		{
		case TJA1145A_M_MC_NORMAL_MODE:
			*OpMode = CANTRCV_TRCVMODE_NORMAL;
			break;

		case TJA1145A_M_MC_STANDBY_MODE:
			*OpMode = CANTRCV_TRCVMODE_STANDBY;
			break;

		case TJA1145A_M_MC_SLEEP_MODE:
			*OpMode = CANTRCV_TRCVMODE_SLEEP;
			break;

		default:
			Status = TJA1145A_ERR_VALUE;
			break;
		}
	}
	SchM_Exit_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_01();

	return Status;
}

/*================================================================================================*/

/**
* @brief		Writes system and CAN controller event capture configuration.
*
* @details		Enables/disables following events: overtemperature warning, SPI failure detection,
* 				CAN-bus silence detection and CAN failure detection.
* 				Writes registers 'Transceiver event capture enable register' (address 23h) and
* 				'System event capture enable register' (address 04h).
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[in]	EventConfig			Event capture configuration.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_EventCaptureConfiguration_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_EventCaptureConfiguration(uint8 Transceiver, const CanTrcv_tja1145a_EventCaptureConfigType* EventConfig)
{
	uint8 WriteData = 0U;
	CanTrcv_tja1145a_StatusType Status;

	/* Write system event capture configuration register. */
	WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(0U,
			(uint8) EventConfig->OvertempDetectionEnable,
			TJA1145A_M_OTWE_MASK,
			TJA1145A_M_OTWE_SHIFT);
	WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
			(uint8) EventConfig->SpiFailureDetectionEnable,
			TJA1145A_M_SPIFE_MASK,
			TJA1145A_M_SPIFE_SHIFT);

	Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_SYSTEM_EVENT_ENABLE_ADDR, WriteData);

	if (TJA1145A_SUCCESS == Status)
	{
		/* Write Transceiver event capture configuration register. */
		WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(0U,
				(uint8) EventConfig->CanBusSilenceDetectionEnable,
				TJA1145A_FS_I_CBSE_MASK,
				TJA1145A_FS_I_CBSE_SHIFT);
		WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
				(uint8) EventConfig->CanFailureDetectionEnable,
				TJA1145A_FS_I_CFE_MASK,
				TJA1145A_FS_I_CFE_SHIFT);

		Status = TJA1145A_DRV_UpdateRegister(Transceiver,
			TJA1145A_TRANSCEIVER_EVENT_ENABLE_ADDR,
			WriteData,
			(TJA1145A_FS_I_CBSE_MASK | TJA1145A_FS_I_CFE_MASK),
			0U);
	}

	return Status;
}

/*================================================================================================*/

/**
* @brief		Enables/disables wake up mode according to WakeEnable parameter.
*
* @details		If wake up is enabled, writes WAKE pin/CAN bus and event capture configuration stored
*				in device config structure. If wake up is disabled, turns off all wake up and interrupt
*				sources.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[in]	WakeEnable			Desired wake up mode state.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_WakeupModeConfig_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_WakeupModeConfig(uint8 Transceiver, boolean WakeEnable)
{
	CanTrcv_tja1145a_StatusType Status;

	if (WakeEnable)
	{
		/* Write globally stored wake up configuration. */
		Status = TJA1145A_DRV_WakeupConfiguration(Transceiver, &CanTrcv_DeviceList[Transceiver].DeviceConfig->WuConfig);

		if (TJA1145A_SUCCESS == Status)
		{
			/* Write event capture configuration. System and CAN bus events are also wake up sources. */
			Status = TJA1145A_DRV_EventCaptureConfiguration(Transceiver, &CanTrcv_DeviceList[Transceiver].DeviceConfig->EventConfig);
		}
	}
	else
	{
		CanTrcv_tja1145a_WuConfigType WuConfig =
		{
			.CanBusWuMode = TJA1145A_WU_CAN_BUS_DISABLED,
			.WuPinMode = TJA1145A_WU_PIN_DISABLED
		};
		Status = TJA1145A_DRV_WakeupConfiguration(Transceiver, &WuConfig);
		
		if (TJA1145A_SUCCESS == Status)
		{
			CanTrcv_tja1145a_EventCaptureConfigType EventConfig =
			{
				.OvertempDetectionEnable = FALSE,
				.SpiFailureDetectionEnable = FALSE,
				.CanBusSilenceDetectionEnable = FALSE,
				.CanFailureDetectionEnable = FALSE
			};
			
			/* Disable system and CAN bus events, which are also wake up sources. */
			Status = TJA1145A_DRV_EventCaptureConfiguration(Transceiver, &EventConfig);
		}
	}

	return Status;
}

/*================================================================================================*/

/**
* @brief		Returns wake up reason.
*
* @details		TJA1145A can be woken up by WAKE pin, by CAN bus (bus activity or frame/bus error)
* 				or by system event (power on event, SPI failure event) and logs this event so that
* 				this information can be used later to clean exactly the flag of the wake up event which
* 				occurred and leave the other events untouched to prevent loss of information between
*				cycles. Overtemperature and CAN bus failure (Tx dominant timeout) interrupt do not wake up
*				the device, hence these are not reported by this function.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[out]	WuReason			Stores the wake up reason.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_GetWuReason_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_GetWuReason(uint8 Transceiver, CanTrcv_tja1145a_WuReasonType* WuReason)
{
	uint8 RxData[2U] = { 0U };
	CanTrcv_tja1145a_StatusType Status;

	SchM_Enter_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_02();

	*WuReason = TJA1145A_WU_NO_EVENT;

	/* Read CAN event status register and WAKE pin event status registers in 1 SPI access. */
	Status = TJA1145A_DRV_ReadMultipleRegisters(Transceiver, TJA1145A_TRANSCEIVER_EVENT_STATUS_ADDR, 2U, RxData);
	
	if (TJA1145A_SUCCESS == Status)
	{
		/* Check for CAN bus event. 'Transceiver event status register' indicates what kind
		 * of bus event occurred (wake up, PN frame error, bus silence). The register contains
		 * also CF (Tx dominant timeout flag or undervoltage) which is active in normal mode
		 * only and therefore is not a wake up source. */
		/* Check CAN bus wake up. */
		if (TJA1145A_FS_CW_MASK == (RxData[0] & TJA1145A_FS_CW_MASK))
		{
			*WuReason = TJA1145A_WU_CAN_BUS_WAKEUP;
		}
		/* Check CAN bus silence. */
		else if (TJA1145A_FS_CBS_MASK == (RxData[0] & TJA1145A_FS_CBS_MASK))
		{
			*WuReason = TJA1145A_WU_CAN_BUS_SILENCE;
		}
		/* Check partial networking frame error. */
		else if (TJA1145A_FS_PNFDE_MASK == (RxData[0] & TJA1145A_FS_PNFDE_MASK))
		{
			*WuReason = TJA1145A_WU_PN_FRAME_ERROR;
		}

		/* Check for falling edge event on WAKE pin. */
		else if (TJA1145A_FS_WPF_MASK == (RxData[1] & TJA1145A_FS_WPF_MASK))
		{
			*WuReason = TJA1145A_WU_PIN_WAKEUP;
		}
		/* Check for rising edge event on WAKE pin. */
		else if (TJA1145A_FS_WPR_MASK == (RxData[1] & TJA1145A_FS_WPR_MASK))
		{
			*WuReason = TJA1145A_WU_PIN_WAKEUP;
		}
		else
        {
            /* Do nothing */
        }
	}
	
	if ((TJA1145A_WU_NO_EVENT == *WuReason) && (TJA1145A_SUCCESS == Status))
	{
		/* Check for SPI failure. POR event is not considered wake up event, because it only puts
		 * the device in standby mode. 'System event status register' contains also overtemperature
		 * flag which is detected in normal mode only. Hence the function doesn't check this flag.
		 * Note: SPI failure doesn't wake up the device from sleep mode, only from standby mode.  */
		Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_SYSTEM_EVENT_STATUS_ADDR, RxData);

		/* Check for SPI failure event. */
		if (TJA1145A_FS_SPIF_MASK == (RxData[0] & TJA1145A_FS_SPIF_MASK))
		{
			*WuReason = TJA1145A_WU_SPI_FAILURE;
		}	
	}
	
	if ((TJA1145A_WU_NO_EVENT == *WuReason) && (TJA1145A_SUCCESS == Status))
	{
		/* Read 'Mode control register' (address 01h) to find out if the device was woken up by SPI Command. */
		Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_MODE_CONTROL_ADDR, RxData);

		/* Read mode, if the device is in normal mode, it was woken up by SPI Command. */
		if (TJA1145A_M_MC_NORMAL_MODE == (RxData[0] & TJA1145A_M_MC_MASK))
		{
			*WuReason = TJA1145A_WU_INTERNALLY;
		}	
	}

	/* Log the wake up event. */
	CanTrcv_DeviceList[Transceiver].WuReason = *WuReason;
	
	SchM_Exit_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_02();

	return Status;
}

/*================================================================================================*/

/**
* @brief		Clears wake up flag.
*
* @details		Clears one of following wake up flags (interrupts can as well wake up the device):
*				WAKE pin flag, CAN bus wake up flag, SPI failure (this interrupt can wake up the device
*				only when it is in standby mode), partial networking frame error, CAN bus silence. 
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[out]	wakeup				Wake up source to clear.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_ClearTrcvWufFlag_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ClearTrcvWufFlag(uint8 Transceiver, CanTrcv_tja1145a_WuReasonType WuReason)
{
	CanTrcv_tja1145a_StatusType Status;

	switch (WuReason)
	{
	case TJA1145A_WU_PIN_WAKEUP:
		/* Clear WPR and WPF flags of 'WAKE pin event status register' to clear wake up
		 * by pin flag. WPR and WPF flags are handled as a single wake up by pin event. */
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_WAKE_PIN_EVENT_STATUS_ADDR,
				TJA1145A_FS_WPF_FALLING_EDGE_EVENT | TJA1145A_FS_WPR_RISING_EDGE_EVENT);
		break;

	case TJA1145A_WU_SPI_FAILURE:
		/* Clear SPI failure. Note: SPI failure can wake up the device only if it is in standby mode. */
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_SYSTEM_EVENT_STATUS_ADDR, TJA1145A_FS_SPIF_MASK);
		break;

	case TJA1145A_WU_CAN_BUS_WAKEUP:
		/* Clear CW bit of 'Transceiver event status register' to clear wake up by bus flag. */
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_TRANSCEIVER_EVENT_STATUS_ADDR, TJA1145A_FS_CW_MASK);
		break;

	case TJA1145A_WU_PN_FRAME_ERROR:
		/* Clear partial networking frame detection error. */
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_TRANSCEIVER_EVENT_STATUS_ADDR, TJA1145A_FS_PNFDE_MASK);
		break;

	case TJA1145A_WU_CAN_BUS_SILENCE:
		/* Clear CAN bus silence flag. */
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_TRANSCEIVER_EVENT_STATUS_ADDR, TJA1145A_FS_CBS_MASK);
		break;

	case TJA1145A_WU_NO_EVENT:
	case TJA1145A_WU_INTERNALLY:
		/* Do nothing if there is no wake up event or the device was woken up by SPI Command by setting MC bitfield,
		 * which is not event flag. */
		Status = TJA1145A_SUCCESS;
		break;

	default:
		Status = TJA1145A_ERR_PARAM;
		break;
	}
	
	if (TJA1145A_SUCCESS == Status)
	{
		CanTrcv_DeviceList[Transceiver].WuReason = TJA1145A_WU_NO_EVENT;
	}

	return Status;
}

/*================================================================================================*/

/**
* @brief		Clears POR flag.
* @details		Clears PO bit of 'System event status' register.
*
* @param[in]    Transceiver       	Which Transceiver to address.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_ClearPorFlag_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ClearPorFlag(uint8 Transceiver)
{
	return TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_SYSTEM_EVENT_STATUS_ADDR, TJA1145A_FS_PO_MASK);
}

/*================================================================================================*/

/**
* @brief		Enables/disables WAKE pin and CAN bus wake up feature.
*
* @details		There are two types of wake up source: regular wake up source (WAKE pin, CAN bus) and
*				interrupts (except overtemperature interrupt). At least one regular wake up source must
*				be enabled before putting the device to sleep mode.
*				This function configures regular wake up source.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[in]	WakeupConfig		WAKE pin and CAN bus wake up configuration.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_WakeupConfiguration_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_WakeupConfiguration(uint8 Transceiver, const CanTrcv_tja1145a_WuConfigType* WakeupConfig)
{
	CanTrcv_tja1145a_StatusType Status;

	/* Write CAN bus wake up configuration to 'Transceiver event
	 * capture enable register' (address 23h). */
	Status = TJA1145A_DRV_UpdateRegister(Transceiver,
			TJA1145A_TRANSCEIVER_EVENT_ENABLE_ADDR,
			(uint8) WakeupConfig->CanBusWuMode,
			TJA1145A_FS_I_CWE_MASK,
			TJA1145A_FS_I_CWE_SHIFT);

	if (TJA1145A_SUCCESS == Status)
	{
		/* Write WAKE pin wake up configuration to 'WAKE pin event
		 * capture enable register' (address 4Ch). */
		Status = TJA1145A_DRV_WriteRegister(Transceiver,
			TJA1145A_WAKE_PIN_ENABLE_ADDR,
			(uint8) WakeupConfig->WuPinMode);
	}

	return Status;
}

/*================================================================================================*/

/**
* @brief		Enables/disables partial networking. If PN is activated, the device can be woken up
* 				by a remote frame. If PN is disabled, the device can be woken up only by a standard
* 				wake up pattern.
* 				It is expected that partial networking has been configured prior calling this
* 				function which only enables/disables the PN functionality.
*
* @details		If partial networking is enabled, CPNC bit of 'CAN control register' (20h)
* 				is set to 1. If CPNC is set to 0, PN is disabled.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[in]    PnMode				Enable/disable PN functionality.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_SetPnMode_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_SetPnMode(uint8 Transceiver, CanTrcv_tja1145a_PNActivationType PnMode)
{
	uint8 TrcvStatus = 0U;
	CanTrcv_tja1145a_StatusType Status;
	boolean PnEnabled = TJA1145A_PN_ENABLED == PnMode;

	/* Configure PN: CPNC = 1 to enable PN, CPNC = 0 to disable PN. */
	Status = TJA1145A_DRV_UpdateRegister(Transceiver,
			TJA1145A_CAN_CONTROL_ADDR,
			(uint8) PnEnabled,
			TJA1145A_FS_I_CPNC_MASK,
			TJA1145A_FS_I_CPNC_SHIFT);

	if ((TJA1145A_SUCCESS == Status) && PnEnabled)
	{
		/* Check if PN was successfully enabled by reading CPNS bit. CPNS is set to 1 if
		 * PNCOK is set to 1 (by application SW) after PN configuration. Any write attempt
		 * to PN configuration registers clears PNCOK bit. */
		Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_TRANSCEIVER_STATUS_ADDR, &TrcvStatus);

		/* Report error if CPNS bit is 0. */
		if ((TJA1145A_SUCCESS == Status) && ((TrcvStatus & TJA1145A_FS_I_CPNS_MASK) == 0U))
		{
			Status = TJA1145A_FAIL;
		}
	}

	return Status;
}

/*================================================================================================*/

/**
* @brief		Sets CAN controller configuration.
*
* @details		Sets flexible data rate mode, PN data rate, wake up frame ID, ID mask to
* 				enable groups of wake up frames, expected wake up frame length (DLC), type
* 				of identifier (11 or 29 bit), sets whether DLC and data bytes are part
* 				of wake up frame evaluation (PNDM) and as a last thing sets PNCOK bit to
* 				1 to indicate successful partial networking configuration.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[in]    CanConfig			CAN controller configuration.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_SetCanConfig_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_SetCanConfig(uint8 Transceiver, const CanTrcv_tja1145a_CanConfigType* CanConfig)
{
	uint8 WriteData = 0U;
	CanTrcv_tja1145a_StatusType Status;

	/* Write data rate. */
	Status = TJA1145A_DRV_WriteRegister(Transceiver,
			TJA1145A_DATA_RATE_ADDR,
			(uint8) CanConfig->DataRate);

	/* Write WUF ID registers. */
	if (TJA1145A_SUCCESS == Status)
	{
		Status = TJA1145A_DRV_WriteWufIdRegisters(Transceiver, TJA1145A_ID_REGS_ACCESS, CanConfig->WufId, CanConfig->IdFormat);
	}

	/* Write WUF ID mask registers. */
	if (TJA1145A_SUCCESS == Status)
	{
		Status = TJA1145A_DRV_WriteWufIdRegisters(Transceiver, TJA1145A_ID_MASK_REGS_ACCESS, CanConfig->WufIdMask, CanConfig->IdFormat);
	}

	/* Write IDE, PNDM and DLC data. */
	if (TJA1145A_SUCCESS == Status)
	{
		WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(0U,
				(uint8) CanConfig->IdFormat,
				TJA1145A_FS_I_IDE_MASK,
				TJA1145A_FS_I_IDE_SHIFT);

		WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
				(uint8) CanConfig->WufEval,
				TJA1145A_FS_I_PNDM_MASK,
				TJA1145A_FS_I_PNDM_SHIFT);

		WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
				CanConfig->Dlc,
				TJA1145A_FS_I_DLC_MASK,
				TJA1145A_FS_I_DLC_SHIFT);

		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_FRAME_CONTROL_ADDR, WriteData);
	}

	/* Write data masks. */
	if (TJA1145A_SUCCESS == Status)
	{
		Status = TJA1145A_DRV_WriteDataMaskRegisters(Transceiver, CanConfig->DataMasks);
	}

	/* Write partial networking enable (CPNC), flexible data rate mode (bit CFDC) and PNCOK to
	 * mark complete PN configuration. */
	if (TJA1145A_SUCCESS == Status)
	{
		/* CPNC, PNCOK and CFDC are at positions 4, 5 and 6 respectively within 'CAN control register'.
		 * Prepare WriteData in such a way, that CFDC value is shifted by 2, PNCOK (set to 1 to mark
		 * successful PN configuration) is shifted by 1 and added to CFDC and CPNC is added to this value.
		 * This value is then updated in 'CAN control register'. */
		WriteData = ((uint8) ((TJA1145A_FD_ENABLED == CanConfig->FdConfig) ? 1U : 0U) << 2U);
		WriteData |= (uint8)((TJA1145A_PN_ENABLED == CanConfig->PnMode) ? 1U : 0U);
		WriteData |= ((uint8) (1U << 1U));
		Status = TJA1145A_DRV_UpdateRegister(Transceiver,
				TJA1145A_CAN_CONTROL_ADDR,
				WriteData,
				TJA1145A_FS_I_CPNC_MASK | TJA1145A_FS_I_PNCOK_MASK | TJA1145A_FS_I_CFDC_MASK,
				TJA1145A_FS_I_CPNC_SHIFT);
	}

	return Status;
}

/*================================================================================================*/

/**
* @brief		Sets mode of CAN controller which may differ from mode of TJA1145A. These are two
*				entities, each with its own mode.
*
* @details		Writes CAN control register (address 20h).
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[in]    CanMode				CAN controller mode.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_SetCanControllerMode_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_SetCanControllerMode(uint8 Transceiver, CanTrcv_tja1145a_CanControllerModeType CanMode)
{
	/* Write CAN controller mode to CNC bits of 'CAN control register'. */
	return TJA1145A_DRV_UpdateRegister(Transceiver,
			TJA1145A_CAN_CONTROL_ADDR,
			(uint8) CanMode,
			TJA1145A_FS_I_CMC_MASK,
			TJA1145A_FS_I_CMC_SHIFT);
}

/*================================================================================================*/

/**
* @brief		Reads timeout flag.
*
* @details		Reads 'Transceiver status' register (address 22h) and extracts the CFS bit rather
*				than CF flag which indicates 2 things: either TXD is clamped dominant or a VCC 
*				undervoltage is detected.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[out]   FlagState			Timeout flag value.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_ReadTimeoutFlag_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ReadTimeoutFlag(uint8 Transceiver, CanTrcv_tja1145a_TrcvFlagStateType* FlagState)
{
	uint8 TimeoutFlag = 0U;
	CanTrcv_tja1145a_StatusType Status;

	SchM_Enter_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_03();

	Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_TRANSCEIVER_STATUS_ADDR, &TimeoutFlag);

	*FlagState = ((TimeoutFlag & TJA1145A_FS_I_CFS_MASK) == TJA1145A_FS_I_CFS_MASK) ?
			TJA1145A_FLAG_SET :
			TJA1145A_FLAG_CLEARED;
			
	SchM_Exit_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_03();

	return Status;
}

/*================================================================================================*/

/**
* @brief		Reads silence flag.
*
* @details		Reads 'Transceiver status' register (address 22h) and extracts the CBSS bit.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[out]   FlagState			Silence flag value.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_ReadSilenceFlag_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ReadSilenceFlag(uint8 Transceiver, CanTrcv_tja1145a_TrcvFlagStateType* FlagState)
{
	uint8 SilenceFlag = 0U;
	CanTrcv_tja1145a_StatusType Status;

	SchM_Enter_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_04();

	Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_TRANSCEIVER_STATUS_ADDR, &SilenceFlag);

	*FlagState = ((SilenceFlag & TJA1145A_FS_I_CBSS_MASK) == TJA1145A_FS_I_CBSS_MASK) ?
			TJA1145A_FLAG_SET :
			TJA1145A_FLAG_CLEARED;
			
	SchM_Exit_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_04();

	return Status;
}
/*================================================================================================*/

/**
* @brief		Returns status of the Transceiver (its mode, overtemperature flag) and status
* 				of CAN controller (PN status, CAN bus status, ...).
*
* @details		This function reads 'Main status register'(address 03h) and 'Transceiver status register'
*				(address 22h) and returns their content.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[in]    TrcvSysData			Status data of the Transceiver.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_GetTrcvSystemData_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_GetTrcvSystemData(uint8 Transceiver, CanTrcv_tja1145a_SysDataType* TrcvSysData)
{
	uint8 RxData[2U] = { 0U };
	CanTrcv_tja1145a_StatusType Status;

	SchM_Enter_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_05();
	/* Read 'Main status register'. */
    Status = TJA1145A_DRV_ReadRegister(Transceiver,
			TJA1145A_MAIN_STATUS_ADDR,
			&TrcvSysData->MainStatusReg);

	if (TJA1145A_SUCCESS == Status)
	{
		/* Read 'Transceiver status register'. */
		Status = TJA1145A_DRV_ReadRegister(Transceiver,
				TJA1145A_TRANSCEIVER_STATUS_ADDR,
				&TrcvSysData->TrcvStatusReg);
	}
	
	if (TJA1145A_SUCCESS == Status)
	{
		/* Read 'Global event status register' and 'System event status register' in 1 SPI access. */
		Status = TJA1145A_DRV_ReadMultipleRegisters(Transceiver,
				TJA1145A_EVENT_CAPTURE_STATUS_ADDR,
				2U,
				RxData);
				
		TrcvSysData->GlobalEventStatusReg = RxData[0];
		TrcvSysData->SysEventStatusReg = RxData[1];
	}
	
	if (TJA1145A_SUCCESS == Status)
	{
		/* Read 'Global event status register' and 'System event status register' in 1 SPI access. */
		Status = TJA1145A_DRV_ReadMultipleRegisters(Transceiver,
				TJA1145A_TRANSCEIVER_EVENT_STATUS_ADDR,
				2U,
				RxData);
				
		TrcvSysData->TrcvEventStatusReg = RxData[0];
		TrcvSysData->WakePinEventStatusReg = RxData[1];
	}
	SchM_Exit_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_05();

	return Status;
}

/*================================================================================================*/
/**
* @brief		Reads power on event flag.
*
* @details		Reads PO bit of 'System event status register' which indicates whether there has
* 				been a POR event. If an undervoltage on VCC and/or VIO occurs, the device is forced
* 				to sleep mode which clears the PO bit and the information about POR event is lost.
* 				Therefore, the function reads also NMS bit which compensates for this. NMS bit is
* 				set to 1 if there has been a POR event and the device hasn't been switched to normal
* 				mode via SPI Command by the application software. It is expected that the application
* 				software logs and clears the POR event when switching the device to normal mode.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[out]	PorEventStatus		POR event status.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_GetPorEventStatus_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_GetPorEventStatus(uint8 Transceiver, CanTrcv_tja1145a_PorEventType* PorEventStatus)
{
	uint8 SystemStatus = 0U;
	CanTrcv_tja1145a_StatusType Status;

	*PorEventStatus = TJA1145A_NO_POR_EVENT;

	SchM_Enter_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_06();

	/* Read PO bit of 'System event status register'. */
	Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_SYSTEM_EVENT_STATUS_ADDR, &SystemStatus);

	if (TJA1145A_FS_PO_MASK == (SystemStatus & TJA1145A_FS_PO_MASK))
	{
		*PorEventStatus = TJA1145A_POR_EVENT_OCCURRED;
	}

	/* If PO bit is 0, either there has not been a POR event or the device has been forced
	 * to sleep mode due to UV event and the PO was cleared. Check FSMS bit for UV event on
	 * VCC or/and VIO. If there has been UV event check NMS bit for POR event. */
	if ((TJA1145A_NO_POR_EVENT == *PorEventStatus) && (TJA1145A_SUCCESS == Status))
	{
		/* Read 'Main status register'. */
		Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_MAIN_STATUS_ADDR, &SystemStatus);

		/* Check if the device was forced to sleep mode due to UV event on VCC or/and VIO
		 * which might have reset PO bit. */
		if ((TJA1145A_M_FSMS_MASK == (SystemStatus & TJA1145A_M_FSMS_MASK)) && (TJA1145A_SUCCESS == Status))
		{
			/* If NMS bit is 1, there was a POR event and the device was in STDBY mode
			 * before transition to sleep mode.
			 * If NMS is 0, the device was in normal mode before transition to sleep mode. */
			if (TJA1145A_M_NMS_MASK == (SystemStatus & TJA1145A_M_NMS_MASK))
			{
				*PorEventStatus = TJA1145A_POR_EVENT_OCCURRED;
			}
		}
	}
	
	SchM_Exit_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_06();

	return Status;
}

/*================================================================================================*/
/**
* @brief		Returns system error status. All Transceiver/bus errors are collectively reported
* 				as a system error.
* @details		Collects all system errors and reports them in a single output parameter. Each system
*				error that occurred, has its corresponding bit set to 1.
*				This driver recognizes following system errors:
* 					- overtemperature, which forces the device to switch to overtemperature mode,
* 					- undervoltage on VCC and/or VIO, which forces the device to shift to sleep mode,
* 					- oscillator of CAN Transceiver not running at targeted frequency,
* 					- VCC undervoltage detected by CAN Transceiver.
*					- CAN failure
*					- CAN bus silence
*					- partial networking error
*					- partial networking configuration error
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[out]	SystemError			Stores information about system error.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_GetSystemErrorStatus_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_GetSystemErrorStatus(uint8 Transceiver, uint16* SystemError)
{
	uint8 RxData = 0U;
	CanTrcv_tja1145a_StatusType Status;

	*SystemError = 0U;

	SchM_Enter_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_07();
	
	/* Read 'System event status register'. */
	Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_MAIN_STATUS_ADDR, &RxData);
	
	if (TJA1145A_SUCCESS == Status)
	{
		/* Overtemperature and transition to sleep mode due to UV are considered system error. */
		if (TJA1145A_M_OTWS_MASK == (RxData & TJA1145A_M_OTWS_MASK))
		{
			*SystemError = TJA1145A_OVERTEMP_MASK;
		}
		
		if (TJA1145A_M_FSMS_MASK == (RxData & TJA1145A_M_FSMS_MASK))
		{
			*SystemError |= TJA1145A_VCC_UNDERVOLTAGE_MASK;
		}
		
		/* Read 'Transceiver status register'. */
		Status = TJA1145A_DRV_ReadRegister(Transceiver, TJA1145A_TRANSCEIVER_STATUS_ADDR, &RxData);

		if (TJA1145A_FS_I_CFS_MASK == (RxData & TJA1145A_FS_I_CFS_MASK))
		{
			*SystemError |= TJA1145A_CAN_FAILURE_MASK;
		}
		
		if (TJA1145A_FS_I_VCS_MASK == (RxData & TJA1145A_FS_I_VCS_MASK))
		{
			*SystemError |= TJA1145A_VCC_UNDERVOLTAGE_MASK;
		}
		
		/* If bit COSC is set to 0, CAN partial networking oscillator is not running at target frequency. */
		if (0U == (RxData & TJA1145A_FS_I_COSCS_MASK))
		{
			*SystemError |= TJA1145A_CAN_OSC_STATUS_MASK;
		}
		
		/* If bit CPNS is set to 0, CAN partial networking configuration error was detected. */
		if (0U == (RxData & TJA1145A_FS_I_CPNS_MASK))
		{
			*SystemError |= TJA1145A_PN_STATUS_ERROR_MASK;
		}
		
		if (TJA1145A_FS_I_CPNERR_MASK == (RxData & TJA1145A_FS_I_CPNERR_MASK))
		{
			*SystemError |= TJA1145A_PN_ERROR_MASK;
		}
		
		CanTrcv_DeviceList[Transceiver].SystemError = *SystemError;
	}
	
	SchM_Exit_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_07();

	return Status;
}

/*================================================================================================*/
/**
* @brief		Clears system error.
*
* @details		Important: it is not possible to clear all system errors. Following system errors
*				are read only flags: CAN oscillator status, VCC undervoltage, PN configuration error
*				(in this case PN must be reconfigured).
*				Note: TJA1145A_PN_ERROR flag can be set because of two reasons:
*					- PN frame error was detected - the flag can be cleared
*					- PN configuration error was detected - PN must be reconfigured to clear the flag.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[out]	SystemError			System error to clean.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_ClearSystemErrorStatus_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ClearSystemErrorStatus(uint8 Transceiver, CanTrcv_tja1145a_SystemErrorType SystemError)
{
	CanTrcv_tja1145a_StatusType Status = TJA1145A_FAIL;

	switch (SystemError)
	{
	case TJA1145A_OVERTEMP:
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_SYSTEM_EVENT_STATUS_ADDR, TJA1145A_FS_OTW_MASK);
		break;
			
	case TJA1145A_PN_ERROR:
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_TRANSCEIVER_EVENT_STATUS_ADDR, TJA1145A_FS_PNFDE_MASK);
		break;
		
	case TJA1145A_CAN_FAILURE:
		Status = TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_TRANSCEIVER_EVENT_STATUS_ADDR, TJA1145A_FS_CF_MASK);
		break;
		
	/* These flags are read only, they are reset only after their reason is fixed. Don't clear flag in SystemError variable,
	 * the flag will be cleared on next call of TJA1145A_DRV_GetSystemErrorStatus if the failure was fixed. */
	case TJA1145A_PN_STATUS_ERROR:
	case TJA1145A_CAN_OSC_STATUS:
	case TJA1145A_VCC_UNDERVOLTAGE:
		Status = TJA1145A_FAIL;
		break;
		
	default:
		Status = TJA1145A_ERR_PARAM;
		break;
	}
	
	if (TJA1145A_SUCCESS == Status)
	{
		SchM_Enter_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_08();
		CanTrcv_DeviceList[Transceiver].SystemError = CanTrcv_DeviceList[Transceiver].SystemError & ~((uint16)1U << (uint16)SystemError);
		SchM_Exit_CanTrcv_tja1145a_CANTRCV_EXCLUSIVE_AREA_08();
	}

	return Status;
}

/*================================================================================================*/

/**
* @brief		Writes lock configuration to 'Lock control register'.
*
* @details		Each bit of 'Lock control register' lock certain addresss range which prevents
*				unwanted register access.
*
* @param[in]    Transceiver       	Which Transceiver to address.
* @param[in]    LockControl			Lock control configuration.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_SetLockControlRegister_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_SetLockControlRegister(uint8 Transceiver, const CanTrcv_tja1145a_LockRegistersType* LockControl)
{
	uint8 WriteData = 0U;

	WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
			(uint8) LockControl->LockRange06h09h,
			TJA1145A_M_LK0C_MASK,
			TJA1145A_M_LK0C_SHIFT);
	WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
			(uint8) LockControl->LockRange10h1Fh,
			TJA1145A_M_LK1C_MASK,
			TJA1145A_M_LK1C_SHIFT);
	WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
			(uint8) LockControl->LockRange20h2Fh,
			TJA1145A_M_LK2C_MASK,
			TJA1145A_M_LK2C_SHIFT);
	WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
			(uint8) LockControl->LockRange30h3Fh,
			TJA1145A_M_LK3C_MASK,
			TJA1145A_M_LK3C_SHIFT);
	WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
			(uint8) LockControl->LockRange40h4Fh,
			TJA1145A_M_LK4C_MASK,
			TJA1145A_M_LK4C_SHIFT);
	WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
			(uint8) LockControl->LockRange50h5Fh,
			TJA1145A_M_LK5C_MASK,
			TJA1145A_M_LK5C_SHIFT);
	WriteData = (uint8)TJA1145A_BO_UPDATE_VAL(WriteData,
			(uint8) LockControl->LockRange68h6Fh,
			TJA1145A_M_LK6C_MASK,
			TJA1145A_M_LK6C_SHIFT);

	return TJA1145A_DRV_WriteRegister(Transceiver, TJA1145A_LOCK_CONTROL_ADDR, WriteData);
}

/*================================================================================================*/

/**
* @brief		Writes general purpose memory register.
*
* @details		Writes one of 4 available general purpose memory registers.
*
* @param[in]    Transceiver       	Which transceiver to address.
* @param[in]    MemRegister         Which memory register to access.
* @param[in]    Data                Data to write to given memory register.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_WriteMemoryRegister_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_WriteMemoryRegister(uint8 Transceiver, CanTrcv_tja1145a_MemoryRegisterType MemRegister, uint8 Data)
{
    uint8 RegisterAddress;
    CanTrcv_tja1145a_StatusType Status;
    
    Status = TJA1145A_DRV_MemoryRegisterToAddress(MemRegister, &RegisterAddress);
    
	return (TJA1145A_SUCCESS == Status) ?
        TJA1145A_DRV_WriteRegister(Transceiver, RegisterAddress, Data) :
        Status;
}

/*================================================================================================*/

/**
* @brief		Reads general purpose memory register.
*
* @details		Reads one of 4 available general purpose memory registers.
*
* @param[in]    Transceiver       	Which transceiver to address.
* @param[in]    MemRegister         Which memory register to access.
* @param[in]    Data                Data to store read out content of a memory register.
*
* @return       CanTrcv_tja1145a_StatusType  	Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_ReadMemoryRegister_Activity */
CanTrcv_tja1145a_StatusType TJA1145A_DRV_ReadMemoryRegister(uint8 Transceiver, CanTrcv_tja1145a_MemoryRegisterType MemRegister, uint8* Data)
{
    uint8 RegisterAddress;
    CanTrcv_tja1145a_StatusType Status;
    
    Status = TJA1145A_DRV_MemoryRegisterToAddress(MemRegister, &RegisterAddress);
    
	return (TJA1145A_SUCCESS == Status) ?
        TJA1145A_DRV_ReadRegister(Transceiver, RegisterAddress, Data) :
        Status;
}

/*================================================================================================*/
/**
* @brief        Deinitializes the TJA1145A driver.
*
* @details      Clears the internal run-time configuration, puts the device to standby mode and clears
*				all pending interrupts.
*
* @param[in]    Transceiver		Which Transceiver to address.
*
* @return       CanTrcv_tja1145a_StatusType  Return code.
*
* @api
*/
/** @implements   TJA1145A_DRV_Deinit_Activity*/
CanTrcv_tja1145a_StatusType TJA1145A_DRV_Deinit(uint8 Transceiver)
{
	uint8 TxData[2U] = { 0 };
	CanTrcv_tja1145a_StatusType Status;

	/* Clear system event flags. */
	Status = TJA1145A_DRV_WriteRegister(Transceiver,
		TJA1145A_SYSTEM_EVENT_STATUS_ADDR,
		TJA1145A_FS_SPIF_MASK | TJA1145A_FS_OTW_MASK | TJA1145A_FS_PO_MASK);
	
	if (TJA1145A_SUCCESS == Status)
	{
		TxData[0] = TJA1145A_FS_CW_MASK | TJA1145A_FS_CF_MASK | TJA1145A_FS_CBS_MASK | TJA1145A_FS_PNFDE_MASK;
		TxData[1] = TJA1145A_FS_WPF_MASK | TJA1145A_FS_WPR_MASK;
		
		/* Clear Transceiver event flags and wake up flags. */
		Status = TJA1145A_DRV_WriteMultipleRegisters(Transceiver,
			TJA1145A_TRANSCEIVER_EVENT_STATUS_ADDR,
			2U,
			TxData);
	}
	
	if (TJA1145A_SUCCESS == Status)
	{
		Status = TJA1145A_DRV_SetMode(Transceiver, CANTRCV_TRCVMODE_STANDBY);
	}

	if (TJA1145A_SUCCESS == Status)
	{
		CanTrcv_DeviceList[Transceiver].SpiConfig = NULL_PTR;
		CanTrcv_DeviceList[Transceiver].DeviceConfig = NULL_PTR;
		CanTrcv_DeviceList[Transceiver].WuReason = TJA1145A_WU_NO_EVENT;
		CanTrcv_DeviceList[Transceiver].SystemError = TJA1145A_NO_SYSTEM_ERROR;
	}

	return Status;
}

#define CANTRCV_43_TJA1145A_STOP_SEC_CODE
#include "CanTrcv_43_tja1145a_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
