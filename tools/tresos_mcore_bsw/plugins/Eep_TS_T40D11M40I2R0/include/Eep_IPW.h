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

#ifndef EEP_IPW_H
#define EEP_IPW_H

/**
* @file
*
* @addtogroup EEP_DRIVER Eeprom Driver
* @{
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
#include "Sd_Emmc_Ip_Cfg.h"
#include "Sd_Emmc_Ip.h"
#include "Usdhc_Ip.h"
#include "Eep_InternalTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_IPW_VENDOR_ID_H                    43
#define EEP_IPW_AR_RELEASE_MAJOR_VERSION_H     4
#define EEP_IPW_AR_RELEASE_MINOR_VERSION_H     4
#define EEP_IPW_AR_RELEASE_REVISION_VERSION_H  0
#define EEP_IPW_SW_MAJOR_VERSION_H             4
#define EEP_IPW_SW_MINOR_VERSION_H             0
#define EEP_IPW_SW_PATCH_VERSION_H             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Sd_Emmc_Ip_Cfg.h header file are of the same vendor */
#if (EEP_IPW_VENDOR_ID_H != SD_EMMC_VENDOR_ID_IP_CFG)
    #error "Eep_IPW.h and Sd_Emmc_Ip_Cfg.h have different vendor ids"
#endif
/* Check if header file and Sd_Emmc_Ip_Cfg.h header file are of the same Autosar version */
#if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_H    != SD_EMMC_AR_RELEASE_MAJOR_VERSION_IP_CFG) || \
     (EEP_IPW_AR_RELEASE_MINOR_VERSION_H    != SD_EMMC_AR_RELEASE_MINOR_VERSION_IP_CFG) || \
     (EEP_IPW_AR_RELEASE_REVISION_VERSION_H != SD_EMMC_AR_RELEASE_REVISION_VERSION_IP_CFG) \
    )
    #error "AutoSar Version Numbers of Eep_IPW.h and Sd_Emmc_Ip_Cfg.h are different"
#endif
/* Check if header file and Sd_Emmc_Ip_Cfg.h header file are of the same software version */
#if ((EEP_IPW_SW_MAJOR_VERSION_H != SD_EMMC_SW_MAJOR_VERSION_IP_CFG) || \
     (EEP_IPW_SW_MINOR_VERSION_H != SD_EMMC_SW_MINOR_VERSION_IP_CFG) || \
     (EEP_IPW_SW_PATCH_VERSION_H != SD_EMMC_SW_PATCH_VERSION_IP_CFG) \
    )
    #error "Software Version Numbers of Eep_IPW.h and Sd_Emmc_Ip_Cfg.h are different"
#endif

/* Check if header file and Sd_Emmc_Ip.h header file are of the same vendor */
#if (EEP_IPW_VENDOR_ID_H != SD_EMMC_IP_VENDOR_ID)
    #error "Eep_IPW.h and Sd_Emmc_Ip.h have different vendor ids"
#endif
/* Check if header file and Sd_Emmc_Ip.h header file are of the same Autosar version */
#if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_H    != SD_EMMC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_IPW_AR_RELEASE_MINOR_VERSION_H    != SD_EMMC_IP_AR_RELEASE_MINOR_VERSION) || \
     (EEP_IPW_AR_RELEASE_REVISION_VERSION_H != SD_EMMC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_IPW.h and Sd_Emmc_Ip.h are different"
#endif
/* Check if header file and Sd_Emmc_Ip.h header file are of the same software version */
#if ((EEP_IPW_SW_MAJOR_VERSION_H != SD_EMMC_IP_SW_MAJOR_VERSION) || \
     (EEP_IPW_SW_MINOR_VERSION_H != SD_EMMC_IP_SW_MINOR_VERSION) || \
     (EEP_IPW_SW_PATCH_VERSION_H != SD_EMMC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_IPW.h and Sd_Emmc_Ip.h are different"
#endif

/* Check if header file and Usdhc_Ip.h header file are of the same vendor */
#if (EEP_IPW_VENDOR_ID_H != USDHC_IP_VENDOR_ID_H)
    #error "Eep_IPW.h and Usdhc_Ip.h have different vendor ids"
#endif
/* Check if header file and Usdhc_Ip.h header file are of the same Autosar version */
#if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_H    != USDHC_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (EEP_IPW_AR_RELEASE_MINOR_VERSION_H    != USDHC_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (EEP_IPW_AR_RELEASE_REVISION_VERSION_H != USDHC_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Eep_IPW.h and Usdhc_Ip.h are different"
#endif
/* Check if header file and Usdhc_Ip.h header file are of the same software version */
#if ((EEP_IPW_SW_MAJOR_VERSION_H != USDHC_IP_SW_MAJOR_VERSION_H) || \
     (EEP_IPW_SW_MINOR_VERSION_H != USDHC_IP_SW_MINOR_VERSION_H) || \
     (EEP_IPW_SW_PATCH_VERSION_H != USDHC_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Eep_IPW.h and Usdhc_Ip.h are different"
#endif

/* Check if header file and Eep_InternalTypes.h header file are of the same vendor */
#if (EEP_IPW_VENDOR_ID_H != EEP_INTERNALTYPES_VENDOR_ID)
    #error "Eep_IPW.h and Eep_InternalTypes.h have different vendor ids"
#endif
/* Check if header file and Eep_InternalTypes.h header file are of the same Autosar version */
#if ((EEP_IPW_AR_RELEASE_MAJOR_VERSION_H    != EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_IPW_AR_RELEASE_MINOR_VERSION_H    != EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION) || \
     (EEP_IPW_AR_RELEASE_REVISION_VERSION_H != EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_IPW.h and Eep_InternalTypes.h are different"
#endif
/* Check if header file and Eep_InternalTypes.h header file are of the same software version */
#if ((EEP_IPW_SW_MAJOR_VERSION_H != EEP_INTERNALTYPES_SW_MAJOR_VERSION) || \
     (EEP_IPW_SW_MINOR_VERSION_H != EEP_INTERNALTYPES_SW_MINOR_VERSION) || \
     (EEP_IPW_SW_PATCH_VERSION_H != EEP_INTERNALTYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_IPW.h and Eep_InternalTypes.h are different"
#endif

/*==================================================================================================
*                                    VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define EEP_START_SEC_CODE
#include "Eep_MemMap.h"

Eep_ReturnType Eep_Ipw_Init(Eep_ConfigType const * Config);

Std_ReturnType Eep_Ipw_CheckCompareParams(Eep_AddressType SourceAddress,
                                          const uint8 * TargetAddressPtr,
                                          Eep_LengthType Length
                                         );

Eep_ReturnType Eep_Ipw_CompareSync(Eep_AddressType SrcAddress,
                                   const uint8 *DestAddress,
                                   Eep_LengthType TransfLength
                                  );

Std_ReturnType Eep_Ipw_CheckReadParams(Eep_AddressType SourceAddress,
                                       uint8 const * TargetAddressPtr,
                                       Eep_LengthType Length
                                      );

Eep_ReturnType Eep_Ipw_Read(Eep_AddressType EepromAddrIt,
                            uint8 *JobDataDestPtr,
                            Eep_LengthType TransfLength
                           );

Std_ReturnType Eep_Ipw_CheckWriteParams(Eep_AddressType TargetAddress,
                                        const uint8 * pSourceAddressPtr,
                                        Eep_LengthType Length
                                       );

Eep_ReturnType Eep_Ipw_Write(Eep_AddressType EepromAddrIt,
                             const uint8 *JobSrcAddrPtr,
                             Eep_LengthType TransfLength
                            );

Std_ReturnType Eep_Ipw_CheckEraseParams(Eep_AddressType TargetAddress,
                                        Eep_LengthType Length
                                       );

Eep_ReturnType Eep_Ipw_Erase(Eep_AddressType EepromAddrIt,
                             Eep_LengthType TransfLength
                            );

Eep_ReturnType Eep_Ipw_Cancel(void);

Std_ReturnType Eep_Ipw_CheckingAlignmentSource(uint32 SourceAddress);

Std_ReturnType Eep_Ipw_CheckTotalSize(Eep_AddressType TargetAddress,
                                      Eep_LengthType Length
                                     );

void Eep_Ipw_GetCardInformation(Sd_Emmc_Ip_CardInformationType *CardInformation);

#if( EEP_SWITCHPARTITIONACCESS_API == STD_ON )
Std_ReturnType Eep_Ipw_SwitchPartitionAccess(Sd_Ip_MmcPartitionAccessType Sd_Ip_PartitionAccess);
#endif

#if( EEP_MMC_BOOT_ENABLED == STD_ON )
Std_ReturnType Eep_IpwFastBoot(const Eep_ConfigType * ConfigPtr, uint32 BootBlockCount, uint32* BootBuffer);
#endif

#define EEP_STOP_SEC_CODE
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif

/** @}*/
