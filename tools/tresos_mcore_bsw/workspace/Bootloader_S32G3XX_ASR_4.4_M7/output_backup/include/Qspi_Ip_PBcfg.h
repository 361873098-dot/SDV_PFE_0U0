/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32_RTD_4_0_0_D2210_ASR_REL_4_4_REV_0000_20221031
*
*   (c) Copyright 2022 NXP Semiconductors
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
/*==================================================================================================
==================================================================================================*/

#ifndef QSPI_IP_PBCFG_H
#define QSPI_IP_PBCFG_H

/**
*   @file Qspi_Ip_PBcfg.h
*
*   @addtogroup FLS
*   @{
*/

/* implements Qspi_Ip_PBcfg.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_PBCFG_VENDOR_ID                    43

#define QSPI_IP_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define QSPI_IP_PBCFG_AR_RELEASE_MINOR_VERSION     4
#define QSPI_IP_PBCFG_AR_RELEASE_REVISION_VERSION  0

#define QSPI_IP_PBCFG_SW_MAJOR_VERSION             4
#define QSPI_IP_PBCFG_SW_MINOR_VERSION             0
#define QSPI_IP_PBCFG_SW_PATCH_VERSION             0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Defines for direct access to the virtual LUT table */
/* Configuration: MemCfg_0 */
#define MEMCFG_0_LUT_SEQUENCE_READ_DOPI                                         0U
#define MEMCFG_0_LUT_SEQUENCE_WRITE_DOPI                                        6U
#define MEMCFG_0_LUT_SEQUENCE_ERASE_DOPI                                       11U
#define MEMCFG_0_LUT_SEQUENCE_READSR_DOPI                                      15U
#define MEMCFG_0_LUT_SEQUENCE_WRITESR_DOPI                                     21U
#define MEMCFG_0_LUT_SEQUENCE_WRITEENABLE_DOPI                                 26U
#define MEMCFG_0_LUT_SEQUENCE_RESETENABLE_DOPI                                 29U
#define MEMCFG_0_LUT_SEQUENCE_RESET_DOPI                                       32U
#define MEMCFG_0_LUT_SEQUENCE_FASTREAD                                         35U
#define MEMCFG_0_LUT_SEQUENCE_FASTWRITE                                        41U
#define MEMCFG_0_LUT_SEQUENCE_READID_DOPI                                      45U
#define MEMCFG_0_LUT_SEQUENCE_RDCR2                                            51U
#define MEMCFG_0_LUT_SEQUENCE_WRCR2                                            55U
#define MEMCFG_0_LUT_SEQUENCE_WRITEENABLE                                      59U
#define MEMCFG_0_LUT_SEQUENCE_READSR                                           61U


/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"


/* Controller connections */
extern const Qspi_Ip_ControllerConfigType FlsConfigSet_paQspiUnitCfg[2U];

/* Memory configurations */
extern const Qspi_Ip_MemoryConfigType FlsConfigSet_paFlashCfg[1U];

/* Memory-controller connections */
extern const Qspi_Ip_MemoryConnectionType FlsConfigSet_paFlashConnectionCfg[1U];


#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/**@}*/

#endif    /* #ifndef QSPI_IP_PBCFG_H */
