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
* @file         CanTrcv_43_tja1145a_Ipw.h
* @version      0.8.0
*
* @brief        AUTOSAR CanTrcv_43_tja1145a - module interface.
*       		API header for TJA1145A driver.
*
* @addtogroup   CanTrcv_tja1145a_Driver
* @{
*/

#ifndef CANTRCV_TJA1145A_IPW_H_
#define CANTRCV_TJA1145A_IPW_H_

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanTrcv_tja1145a_Ip.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
*/
#define CANTRCV_43_TJA1145A_VENDOR_ID_IPW                    43
#define CANTRCV_43_TJA1145A_MODULE_ID_IPW                    70
#define CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_IPW     4
#define CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_IPW     7
#define CANTRCV_43_TJA1145A_AR_RELEASE_REVISION_VERSION_IPW  0
#define CANTRCV_43_TJA1145A_SW_MAJOR_VERSION_IPW             0
#define CANTRCV_43_TJA1145A_SW_MINOR_VERSION_IPW             8
#define CANTRCV_43_TJA1145A_SW_PATCH_VERSION_IPW             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanTrcv_tja1145a_Ip header file are of the same vendor */
#if (CANTRCV_43_TJA1145A_VENDOR_ID_IPW != TJA1145A_VENDOR_ID)
#error "CanTrcv_43_tja1145a_Ipw.h and CanTrcv_tja1145a_Ip.h have different vendor ids"
#endif
/* Check if current file and CanTrcv_tja1145a_Ip header file are of the same module */
#if (CANTRCV_43_TJA1145A_MODULE_ID_IPW != TJA1145A_MODULE_ID)
#error "CanTrcv_43_tja1145a_Ipw.h and CanTrcv_tja1145a_Ip.h have different module ids"
#endif
/* Check if current file and CanTrcv_tja1145a_Ip header file are of the same Autosar version */
#if ((CANTRCV_43_TJA1145A_AR_RELEASE_MAJOR_VERSION_IPW != TJA1145A_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_43_TJA1145A_AR_RELEASE_MINOR_VERSION_IPW != TJA1145A_AR_RELEASE_MINOR_VERSION) || \
     (CANTRCV_43_TJA1145A_AR_RELEASE_REVISION_VERSION_IPW != TJA1145A_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanTrcv_43_tja1145a_Ipw.h and CanTrcv_tja1145a_Ip.h are different"
#endif
/* Check if current file and CanTrcv_tja1145a_Ip header file are of the same software version */
#if ((CANTRCV_43_TJA1145A_SW_MAJOR_VERSION_IPW != TJA1145A_SW_MAJOR_VERSION) || \
     (CANTRCV_43_TJA1145A_SW_MINOR_VERSION_IPW != TJA1145A_SW_MINOR_VERSION) || \
     (CANTRCV_43_TJA1145A_SW_PATCH_VERSION_IPW != TJA1145A_SW_PATCH_VERSION))
  #error "Software Version Numbers of CanTrcv_43_tja1145a_Ipw.h and CanTrcv_tja1145a_Ip.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define CanTrcv_43_tja1145a_Ipw_Init(Transceiver, ConfigData)							                TJA1145A_DRV_Init(Transceiver, ConfigData)

#define CanTrcv_43_tja1145a_Ipw_ConfigureDevice(Transceiver, DeviceConfig)				                TJA1145A_DRV_ConfigureDevice(Transceiver, DeviceConfig)

#define CanTrcv_43_tja1145a_Ipw_SetOpMode(Transceiver, OpMode)							                TJA1145A_DRV_SetMode(Transceiver, OpMode)

#define CanTrcv_43_tja1145a_Ipw_GetOpMode(Transceiver, OpMode)							                TJA1145A_DRV_GetMode(Transceiver, OpMode)

#define CanTrcv_43_tja1145a_Ipw_GetPorEventStatus(Transceiver, PorEventStatus)			                TJA1145A_DRV_GetPorEventStatus(Transceiver, PorEventStatus)

#define CanTrcv_43_tja1145a_Ipw_GetSystemErrorStatus(Transceiver, SystemErrorStatus)	                TJA1145A_DRV_GetSystemErrorStatus(Transceiver, SystemErrorStatus)

#define CanTrcv_43_tja1145a_Ipw_GetWuReason(Transceiver, WuReason)						                TJA1145A_DRV_GetWuReason(Transceiver, WuReason)

#define CanTrcv_43_tja1145a_Ipw_ClearTrcvWufFlag(Transceiver, WuReason)					                TJA1145A_DRV_ClearTrcvWufFlag(Transceiver, WuReason)

#define CanTrcv_43_tja1145a_Ipw_WakeupModeConfig(Transceiver, WuMode)					                TJA1145A_DRV_WakeupModeConfig(Transceiver, WuMode)

#define CanTrcv_43_tja1145a_Ipw_ReadTimeoutFlag(Transceiver, FlagState)					                TJA1145A_DRV_ReadTimeoutFlag(Transceiver, FlagState)

#define CanTrcv_43_tja1145a_Ipw_ClearPorFlag(Transceiver)								                TJA1145A_DRV_ClearPorFlag(Transceiver)

#define CanTrcv_43_tja1145a_Ipw_ReadSilenceFlag(Transceiver, FlagState)					                TJA1145A_DRV_ReadSilenceFlag(Transceiver, FlagState)

#define CanTrcv_43_tja1145a_Ipw_GetTrcvSystemData(Transceiver, TrcvSysData)				                TJA1145A_DRV_GetTrcvSystemData(Transceiver, TrcvSysData)

#define CanTrcv_43_tja1145a_Ipw_SetPnMode(Transceiver, PnMode)							                TJA1145A_DRV_SetPnMode(Transceiver, PnMode)

#define CanTrcv_43_tja1145a_Ipw_ClearSystemErrorStatus(Transceiver, SystemError)                        TJA1145A_DRV_ClearSystemErrorStatus(Transceiver, SystemError)

#define CanTrcv_43_tja1145a_Ipw_WriteMemoryRegister(Transceiver, MemRegister, Data)                     TJA1145A_DRV_WriteMemoryRegister(Transceiver, MemRegister, Data)

#define CanTrcv_43_tja1145a_Ipw_ReadMemoryRegister(Transceiver, MemRegister, Data)                      TJA1145A_DRV_ReadMemoryRegister(Transceiver, MemRegister, Data)

#define CanTrcv_43_tja1145a_Ipw_SetLockControlRegister(Transceiver, LockControl)                        TJA1145A_DRV_SetLockControlRegister(Transceiver, LockControl)

#define CanTrcv_43_tja1145a_Ipw_ReadRegister(Transceiver, RegAddress, RxData)                           TJA1145A_DRV_ReadRegister(Transceiver, RegAddress, RxData)

#define CanTrcv_43_tja1145a_Ipw_ReadMultipleRegisters(Transceiver, RegAddress, NumRegisters, RxData)    TJA1145A_DRV_ReadMultipleRegisters(Transceiver, RegAddress, NumRegisters, RxData)

#define CanTrcv_43_tja1145a_Ipw_WriteRegister(Transceiver, RegAddress, TxData)                          TJA1145A_DRV_WriteRegister(Transceiver, RegAddress, TxData)

#define CanTrcv_43_tja1145a_Ipw_WriteMultipleRegisters(Transceiver, RegAddress, NumRegisters, TxData)   TJA1145A_DRV_WriteMultipleRegisters(Transceiver, RegAddress, NumRegisters, TxData)

#define CanTrcv_43_tja1145a_Ipw_Deinit(Transceiver)                                                     TJA1145A_DRV_Deinit(Transceiver)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* CANTRCV_TJA1145A_IPW_H_ */

/** @} */
