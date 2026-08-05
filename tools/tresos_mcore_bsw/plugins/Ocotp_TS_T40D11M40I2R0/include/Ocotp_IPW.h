/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : OCOTP_IP
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef OCOTP_IPW_H
#define OCOTP_IPW_H

/**
*   @file
*
*   @addtogroup OCOTP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ocotp_Ip.h"
#include "Ocotp_Types.h"
#include "Ocotp_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define OCOTP_IPW_VENDOR_ID                       43
#define OCOTP_IPW_AR_RELEASE_MAJOR_VERSION        4
#define OCOTP_IPW_AR_RELEASE_MINOR_VERSION        4
#define OCOTP_IPW_AR_RELEASE_REVISION_VERSION     0
#define OCOTP_IPW_SW_MAJOR_VERSION                4
#define OCOTP_IPW_SW_MINOR_VERSION                0
#define OCOTP_IPW_SW_PATCH_VERSION                2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ocotp_Ip header file are of the same vendor */
#if (OCOTP_IPW_VENDOR_ID != OCOTP_IP_VENDOR_ID)
    #error "Ocotp_IPW.h and Ocotp_Ip.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Ip header file are of the same Autosar version */
#if ((OCOTP_IPW_AR_RELEASE_MAJOR_VERSION    != OCOTP_IP_AR_RELEASE_MAJOR_VERSION) || \
     (OCOTP_IPW_AR_RELEASE_MINOR_VERSION    != OCOTP_IP_AR_RELEASE_MINOR_VERSION) || \
     (OCOTP_IPW_AR_RELEASE_REVISION_VERSION != OCOTP_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocotp_IPW.h and Ocotp_Ip.h are different"
#endif
/* Check if current file and Ocotp_Ip header file are of the same Software version */
#if ((OCOTP_IPW_SW_MAJOR_VERSION != OCOTP_IP_SW_MAJOR_VERSION) || \
     (OCOTP_IPW_SW_MINOR_VERSION != OCOTP_IP_SW_MINOR_VERSION) || \
     (OCOTP_IPW_SW_PATCH_VERSION != OCOTP_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.h and Ocotp_Ip.h are different"
#endif

/* Check if current file and Ocotp_Types header file are of the same vendor */
#if (OCOTP_IPW_VENDOR_ID != OCOTP_TYPES_VENDOR_ID)
    #error "Ocotp_IPW.h and Ocotp_Types.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Types header file are of the same Autosar version */
#if ((OCOTP_IPW_AR_RELEASE_MAJOR_VERSION    != OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCOTP_IPW_AR_RELEASE_MINOR_VERSION    != OCOTP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCOTP_IPW_AR_RELEASE_REVISION_VERSION != OCOTP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocotp_IPW.h and Ocotp_Types.h are different"
#endif
/* Check if current file and Ocotp_Types header file are of the same Software version */
#if ((OCOTP_IPW_SW_MAJOR_VERSION != OCOTP_TYPES_SW_MAJOR_VERSION) || \
     (OCOTP_IPW_SW_MINOR_VERSION != OCOTP_TYPES_SW_MINOR_VERSION) || \
     (OCOTP_IPW_SW_PATCH_VERSION != OCOTP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.h and Ocotp_Types.h are different"
#endif

/* Check if current file and Ocotp_Cfg header file are of the same vendor */
#if (OCOTP_IPW_VENDOR_ID != OCOTP_VENDOR_ID_CFG)
    #error "Ocotp_IPW.h and Ocotp_Types.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Cfg header file are of the same Autosar version */
#if ((OCOTP_IPW_AR_RELEASE_MAJOR_VERSION    != OCOTP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (OCOTP_IPW_AR_RELEASE_MINOR_VERSION    != OCOTP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (OCOTP_IPW_AR_RELEASE_REVISION_VERSION != OCOTP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Ocotp_IPW.h and Ocotp_Cfg.h are different"
#endif
/* Check if current file and Ocotp_Cfg header file are of the same Software version */
#if ((OCOTP_IPW_SW_MAJOR_VERSION != OCOTP_SW_MAJOR_VERSION_CFG) || \
     (OCOTP_IPW_SW_MINOR_VERSION != OCOTP_SW_MINOR_VERSION_CFG) || \
     (OCOTP_IPW_SW_PATCH_VERSION != OCOTP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Ocotp_IPW.h and Ocotp_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

void Ocotp_IPW_Init(const Ocotp_ConfigType * pConfig);

void Ocotp_IPW_Deinit(void);

#if(OCOTP_WRITE_EFUSE_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_WriteEFuse
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 data
);
#endif /* OCOTP_WRITE_EFUSE_API == STD_ON */

#if(OCOTP_WRITE_SHADOW_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_WriteShadowRegister
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 data
);
#endif /* OCOTP_WRITE_SHADOW_API == STD_ON */

#if(OCOTP_READ_EFUSE_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_ReadEFuse
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 *data
);
#endif /* OCOTP_READ_EFUSE_API == STD_ON */

#if(OCOTP_READ_SHADOW_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_ReadShadowRegister
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 *data
);
#endif /* OCOTP_READ_SHADOW_API == STD_ON */

#if(OCOTP_READ_APPLICATION_INFORMATION_API == STD_ON)
uint32 Ocotp_IPW_ReadGpRegister(const Ocotp_ChannelConfigType* pChannelCfg);
#endif /* OCOTP_READ_APPLICATION_INFORMATION_API == STD_ON */

#if(OCOTP_WRITE_APPLICATION_INFORMATION_API == STD_ON)
void Ocotp_IPW_WriteGpRegister
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 data
);
#endif /* OCOTP_WRITE_APPLICATION_INFORMATION_API == STD_ON */

#ifdef OCOTP_READ_STICKY_INFORMATION_API
#if(OCOTP_READ_STICKY_INFORMATION_API == STD_ON)
uint32 Ocotp_IPW_ReadStrRegister(const Ocotp_ChannelConfigType* pChannelCfg);
#endif

#if(OCOTP_WRITE_STICKY_INFORMATION_API == STD_ON)
void Ocotp_IPW_WriteStrRegister
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 data
);
#endif
#endif

#if(OCOTP_ECC_ERROR_INJECT_API == STD_ON)
void Ocotp_IPW_EccErrorInject
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint8 bit
);
#endif /* OCOTP_ECC_ERROR_INJECT_API == STD_ON */

#if(OCOTP_ECC_GET_ERROR_API == STD_ON)
Ocotp_EccErrorType Ocotp_IPW_EccGetError(const Ocotp_ChannelConfigType* pChannelCfg);
#endif /* OCOTP_ECC_GET_ERROR_API == STD_ON */

#if(OCOTP_SET_MODE_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_SetMode
(
    const Ocotp_Ip_ConfigType* pHwCfg,
    Ocotp_ModeType mode
);
#endif /* OCOTP_SET_MODE_API == STD_ON */

#if(OCOTP_CRC_VALIDATE_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_CalculateAndWriteCrcValue
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    const uint32 *pData,
    uint32 DataSize
);

Ocotp_Ip_StatusType Ocotp_IPW_CrcValidate(const Ocotp_ChannelConfigType* pChannelCfg);
#endif /* OCOTP_CRC_VALIDATE_API == STD_ON */

#if(OCOTP_GET_STATUS_API == STD_ON)
void Ocotp_IPW_GetStatus
(
    const Ocotp_Ip_ConfigType* pHwCfg,
    Ocotp_StatusType* pStatus
);
#endif /* OCOTP_GET_STATUS_API == STD_ON */

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OCOTP_IPW_H */
