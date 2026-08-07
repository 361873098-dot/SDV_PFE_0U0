/**
*   @file       Eth_43_PFE_PBcfg.h
*   @implements Eth_43_PFE_PBcfg.h_Artifact
*
*   @brief   AUTOSAR Eth_43_PFE driver configuration header file
*   @details File containing the configuration for the Ethernet driver
*   @note    This file was generated on 2026-08-07.
*
*   @addtogroup ETH_43_PFE_DRIVER_CONFIGURATION
*   @{
*/
/*==================================================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.4.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.4.0_D2405_ASR_REL_4_4_REV_0000_20240528
 *
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
 *      Copyright 2017-2022 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *  <<< PFE Restricted Software >>>
 *
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ETH_43_PFE_VS_0_PBCFG_H
#define ETH_43_PFE_VS_0_PBCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43140440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43140440
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_PFE_VENDOR_ID_VS_0_PBCFG_H                    43
#define ETH_43_PFE_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_H     4
#define ETH_43_PFE_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_H     4
#define ETH_43_PFE_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_H  0
#define ETH_43_PFE_SW_MAJOR_VERSION_VS_0_PBCFG_H             1
#define ETH_43_PFE_SW_MINOR_VERSION_VS_0_PBCFG_H             4
#define ETH_43_PFE_SW_PATCH_VERSION_VS_0_PBCFG_H             0

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

     #define ETH_43_PFE_CONFIG_VS_0_PB \
                        extern const Eth_43_PFE_ConfigType Eth_43_PFE_Config_VS_0;    
#ifdef __cplusplus
}
#endif

#endif /* ETH_43_PFE_VS_0_PBCFG_H */

