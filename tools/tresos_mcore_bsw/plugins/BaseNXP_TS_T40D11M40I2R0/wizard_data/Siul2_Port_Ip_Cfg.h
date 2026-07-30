/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : 
* Dependencies : none
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
#ifndef _SIUL2_PORT_IP_CFG_H_
#define _SIUL2_PORT_IP_CFG_H_

#if defined(S32G2XX)
    #include "S32G274A_SIUL2.h"
#elif defined(S32G3XX)
    #include "S32G399A_SIUL2.h"
#elif defined(S32R45)
    #include "S32R45_SIUL2.h"
#endif
#include "Siul2_Port_Ip_Types.h"

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_VENDOR_ID_CFG_H                       43
#define SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H        4
#define SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H        4
#define SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H     0
#define SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_H                4
#define SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_H                0
#define SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_H                2

/*!
 * @addtogroup Siul2_Port_Ip_Cfg
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*! @brief Definitions for BOARD_InitPins Functional Group */

/*! @brief No pin was configured for this group or no need any configuration */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _SIUL2_PORT_IP_CFG_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/

