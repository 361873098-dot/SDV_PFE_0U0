/*==============================================================================
*   Project              : Ipcf
*   Platform             : CORTEXM
*   Peripheral           : none
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.10.0
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2023-2024 NXP
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==============================================================================*/
#ifndef IPCF_IP_CFG_DEFINES_H
#define IPCF_IP_CFG_DEFINES_H

#if defined(__cplusplus)
extern "C"{
#endif

/**
 * SOURCE FILE VERSION INFORMATION
 */
#define IPCF_IP_CFG_DEFINES_VENDOR_ID                    43
#define IPCF_IP_CFG_DEFINES_MODULE_ID                    255
#define IPCF_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define IPCF_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     4
#define IPCF_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define IPCF_IP_CFG_DEFINES_SW_MAJOR_VERSION             4
#define IPCF_IP_CFG_DEFINES_SW_MINOR_VERSION             10
#define IPCF_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*
* @brief            Pre-processor switch for enabling the default error detection and reporting to the DET.
*                   The detection of default errors is configurable (ON / OFF) at pre-compile time.
*/
#define IPCF_DEV_ERROR_DETECT	(STD_OFF)

/*
* @brief          Enable/Disable the API for reporting the Dem Error.
*/
#define IPCF_DEM_ERROR_REPORT_STATUS	(STD_OFF)

/*
* @brief          Support for version info API.
* @details        Switches the Ipcf_GetVersionInfo() API ON or OFF.
*/
#define IPCF_VERSION_INFO_API	(STD_OFF)

/*
* @brief			Unmanaged Channels IDs
*/
#define IPCF_INSTANCE0_UNMANAGEDCHANNEL_0       0U

/*
* @brief			Managed Channels IDs
*/
#define IPCF_INSTANCE0_MANAGEDCHANNEL_0       1U
#define IPCF_INSTANCE0_MANAGEDCHANNEL_1       2U

/*
* @brief			IPCF instances names
*/
#define IPCF_INSTANCE0       0U

/*
* @brief			IPCF instances maximum number defined in configuration
*/
#define IPC_SHM_MAX_INSTANCES       1U

/*
* @brief			IPCF memory size per instance
* @details          Note: The define is not used in driver code and it is used only for reference info
*/
#define IPC_SHM_MEM_SIZE_IPCF_INSTANCE0       0x00022030

/*
* @brief			Maximum number of shared memory channels defined in configuration
*/
#define IPC_SHM_MAX_CHANNELS       3U

/*
* @brief			Maximum number of buffer pools that can be configured for a managed channel
*/
#define IPC_SHM_MAX_POOLS       3U

/*
* @brief			Maximum number of buffers per pool
*/
#define IPC_SHM_MAX_BUFS_PER_POOL       30U

#if defined(__cplusplus)
}
#endif

#endif /* IPCF_IP_CFG_DEFINES_H */
