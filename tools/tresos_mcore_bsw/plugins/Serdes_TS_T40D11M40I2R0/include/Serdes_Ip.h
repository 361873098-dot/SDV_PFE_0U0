/*
 *  Copyright 2021-2022 NXP
 *
 *  NXP Confidential. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *
 *  This file contains sample code only. It is not part of the production code deliverables.
 */

#ifndef SERDES_IP_H
#define SERDES_IP_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDES
==================================================================================================*/
#include "Serdes_Ip_HwAccess.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IP_VENDOR_ID                    43
#define SERDES_IP_MODULE_ID                    255
#define SERDES_IP_AR_RELEASE_MAJOR_VERSION     4
#define SERDES_IP_AR_RELEASE_MINOR_VERSION     4
#define SERDES_IP_AR_RELEASE_REVISION_VERSION  0
#define SERDES_IP_SW_MAJOR_VERSION             4
#define SERDES_IP_SW_MINOR_VERSION             0
#define SERDES_IP_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Serdes_Ip_HwAccess.h file are of the same vendor */
#if (SERDES_IP_VENDOR_ID != SERDES_IP_HWACCESS_VENDOR_ID)
    #error "Serdes_Ip.h and Serdes_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and Serdes_Ip_HwAccess.h file are of the same Autosar version */
#if ((SERDES_IP_AR_RELEASE_MAJOR_VERSION    != SERDES_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_MINOR_VERSION    != SERDES_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (SERDES_IP_AR_RELEASE_REVISION_VERSION != SERDES_IP_HWACCESS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Serdes_Ip.h and Serdes_Ip_HwAccess.h are different"
#endif
/* Check if current file and Serdes_Ip_HwAccess.h file are of the same software version */
#if ((SERDES_IP_SW_MAJOR_VERSION != SERDES_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (SERDES_IP_SW_MINOR_VERSION != SERDES_IP_HWACCESS_SW_MINOR_VERSION) || \
     (SERDES_IP_SW_PATCH_VERSION != SERDES_IP_HWACCESS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Serdes_Ip.h and Serdes_Ip_HwAccess.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define SERDES_IP_S32G_0_BASE_U32          ((uint32)(0x40400000U))
#define SERDES_IP_S32G_1_BASE_U32          ((uint32)(0x44100000U))

/*==================================================================================================
*                                             ENUMS
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
#define SERDES_START_SEC_CODE
#include "Serdes_MemMap.h"

/* SerDes Init */
Serdes_Ip_StatusType Serdes_Ip_Init(uint8 Instance, const Serdes_Ip_ConfigType * Serdes);
Serdes_Ip_JobResultType Serdes_Ip_GetJobResult(uint8 Instance);
Serdes_Ip_StatusType Serdes_Ip_GetStatus(uint8 Instance);
Serdes_Ip_StatusType Serdes_Ip_MainFunction(uint8 Instance);

/*
* @brief        Set the power mode of the XPCS
* @details      This function changes and waits for the XPCS to achieve the power mode requested
*/
void Serdes_Ip_SetMode(uint8 Instance, Serdes_Ip_XpcsModeType XpcsMode);

#define SERDES_STOP_SEC_CODE
#include "Serdes_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SERDES_IP_H */
