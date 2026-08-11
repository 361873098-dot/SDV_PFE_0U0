/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IIC
*   Dependencies         : MCU,PORT,DET,RTE
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

#ifndef I2C_IP_TRUSTEDFUNCTIONS_H
#define I2C_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    I2c_Ip_TrustedFunctions.h
*   
*
*   @brief   I2C IP driver header file.
*   @details I2C IP driver header file.

*   @addtogroup I2C_DRIVER I2c Driver
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
#include "I2c_Ip_CfgDefines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        4
#define I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define I2C_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                4
#define I2C_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define I2C_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same vendor */
#if (I2C_IP_TRUSTEDFUNCTIONS_VENDOR_ID != I2C_IP_CFGDEFINES_VENDOR_ID)
    #error "I2c_Ip_TrustedFunctions.h and I2c_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same Autosar version */
#if ((I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != I2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != I2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != I2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of I2c_Ip_TrustedFunctions.h and I2c_Ip_CfgDefines.h are different"
#endif
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same Software version */
#if ((I2C_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != I2C_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (I2C_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != I2C_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (I2C_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != I2C_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip_TrustedFunctions.h and I2c_Ip_CfgDefines.h are different"
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

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/*!
 * @name IIC_I2C Driver
 * @{
 */
 
#if ((STD_ON == I2C_ENABLE_USER_MODE_SUPPORT) && (STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE))
/**
* @brief            Starts a IIC i2c ip master DMA transfer
* @details          Starts a IIC i2c ip master DMA transfer
*
* @param[in]        Instance - I2C peripheral instance number.
*
* @return           void.
*/
extern void I2c_Ip_MasterCompleteDMATransfer(uint8 Instance);

#if (STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
 /**
* @brief            Starts a IIC i2c ip master DMA transfer error handler
* @details          Starts a IIC i2c ip master DMA transfer error handler
*
* @param[in]        Instance - I2C peripheral instance number.
*
* @return           void.
*/  
extern void I2c_Ip_MasterDmaTransferErrorHandler(uint8 Instance);

#endif
#endif

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* I2C_IP_TRUSTEDFUNCTIONS_H */

/** @} */

