/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : IPV_USDHC
* Dependencies : 
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 4.0.0
* Build Version : S32_RTD_4_0_0_D2210_ASR_REL_4_4_REV_0000_20221031
*
* (c) Copyright 2022 NXP Semiconductors
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef USDHC_IP_DEVICE_REGISTERS_H
#define USDHC_IP_DEVICE_REGISTERS_H

/**
* @file
*
* @addtogroup EEP_DRIVER Eeprom Driver
* @{
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "S32G399A_USDHC.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define USDHC_IP_DEVICE_REGISTERS_VENDOR_ID                       43
#define USDHC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION        4
#define USDHC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION        4
#define USDHC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION     0
#define USDHC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION                4
#define USDHC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION                0
#define USDHC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     DEFINES AND MACROS
==================================================================================================*/

/*! @brief USDHC supports HS200, HS400 modes with tuning feature */
#define FEATURE_USDHC_HAS_HIGHSPEED_TUNNING           (STD_ON)


#endif /* USDHC_IP_DEVICE_REGISTERS_H */

/** @}*/
