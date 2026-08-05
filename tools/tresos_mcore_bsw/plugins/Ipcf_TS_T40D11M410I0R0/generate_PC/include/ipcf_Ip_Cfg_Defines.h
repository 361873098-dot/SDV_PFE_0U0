[!CODE!][!//
[!AUTOSPACING!][!//
[!NOCODE!][!//
[!INCLUDE "Ipcf_RegOperations.m"!][!//
[!ENDNOCODE!][!//
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
[!CODE!][!//
#define IPCF_DEV_ERROR_DETECT [!IF "IpcfGeneral/IpcfDevErrorDetect"!]	(STD_ON)[!ELSE!]	(STD_OFF)[!ENDIF!]


[!ENDCODE!][!//
/*
* @brief          Enable/Disable the API for reporting the Dem Error.
*/
[!CODE!][!//
#define IPCF_DEM_ERROR_REPORT_STATUS [!IF "IpcfGeneral/IpcfDemReportErrorStatus"!]	(STD_ON)[!ELSE!]	(STD_OFF)[!ENDIF!]


[!ENDCODE!][!//
/*
* @brief          Support for version info API.
* @details        Switches the Ipcf_GetVersionInfo() API ON or OFF.
*/
[!CODE!][!//
#define IPCF_VERSION_INFO_API [!IF "IpcfGeneral/IpcfVersionInfoApi"!]	(STD_ON)[!ELSE!]	(STD_OFF)[!ENDIF!]


[!ENDCODE!][!//
/*
* @brief			Unmanaged Channels IDs
*/
[!LOOP "IpcfGlobalConfig/IpcfInstance/*"!]
[!LOOP "UnmanagedChannel/*"!]
[!CODE!]
#define [!"text:toupper(node:name((../../.)))"!]_[!"text:toupper(node:name(.))"!]       [!"node:current()/@index"!]U
[!ENDCODE!]
[!ENDLOOP!]
[!ENDLOOP!]

/*
* @brief			Managed Channels IDs
*/
[!LOOP "IpcfGlobalConfig/IpcfInstance/*"!]
[!LOOP "ManagedChannel/*"!]
[!CODE!]
#define [!"text:toupper(node:name((../../.)))"!]_[!"text:toupper(node:name(.))"!]       [!"num:i(node:current()/@index + count(../.././UnmanagedChannel/*))"!]U
[!ENDCODE!]
[!ENDLOOP!]
[!ENDLOOP!]

/*
* @brief			IPCF instances names
*/
[!LOOP "IpcfGlobalConfig/IpcfInstance/*"!]
[!CODE!]
#define [!"node:name(.)"!]       [!"node:value(IpcInstanceID)"!]U
[!ENDCODE!]
[!ENDLOOP!]

/*
* @brief			IPCF instances maximum number defined in configuration
*/
[!CODE!]
#define IPC_SHM_MAX_INSTANCES       [!"num:i(count(IpcfGlobalConfig/IpcfInstance/*))"!]U
[!ENDCODE!]

/*
* @brief			IPCF memory size per instance
* @details          Note: The define is not used in driver code and it is used only for reference info
*/
[!LOOP "IpcfGlobalConfig/IpcfInstance/*"!]
[!VAR "ipcf_mem_size" = "0"!]
[!IF "count(ManagedChannel/*) != 0"!]
[!LOOP "ManagedChannel/*"!]
[!VAR "ring_tx_size" = "0"!]
[!VAR "num_bufs_total" = "0"!]
[!VAR "ring_pool_size" = "0"!]
[!VAR "pool_size" = "0"!]
[!LOOP "node:order(IpcfBuffer/*, 'node:value(BufferSize)')"!]
    [!VAR "num_bufs_total" = "$num_bufs_total + node:value(NumberOfBuffers)"!]
    [!VAR "ring_pool_size" = "16+(node:value(NumberOfBuffers)+1)*8"!]
    [!VAR "pool_size" = "$pool_size + $ring_pool_size + node:value(NumberOfBuffers) * node:value(BufferSize)"!]
[!ENDLOOP!]
[!VAR "ring_tx_size" = "16+($num_bufs_total+1)*8 + $pool_size"!]
[!VAR "ipcf_mem_size" = "$ipcf_mem_size + $ring_tx_size"!]
[!ENDLOOP!]
[!ENDIF!]
[!IF "count(UnmanagedChannel/*) != 0"!]
[!LOOP "UnmanagedChannel/*"!]
[!VAR "ipcf_mem_size" = "$ipcf_mem_size + num:i(16 + node:value(ChannelSize))"!]
[!ENDLOOP!]
[!ENDIF!]
[!CODE!]
#define IPC_SHM_MEM_SIZE_[!"node:name(.)"!]       [!"num:inttohex($ipcf_mem_size,8)"!]
[!ENDCODE!]
[!ENDLOOP!]

/*
* @brief			Maximum number of shared memory channels defined in configuration
*/
[!CODE!]
[!VAR "num_channels" = "0"!]
[!LOOP "IpcfGlobalConfig/IpcfInstance/*"!]
[!IF "$num_channels < num:i(count(UnmanagedChannel/*) + count(ManagedChannel/*))"!]
[!VAR "num_channels" = "num:i(count(UnmanagedChannel/*) + count(ManagedChannel/*))"!]
[!ENDIF!]
[!ENDLOOP!]
#define IPC_SHM_MAX_CHANNELS       [!"num:i($num_channels)"!]U
[!ENDCODE!]

/*
* @brief			Maximum number of buffer pools that can be configured for a managed channel
*/
[!CODE!]
[!VAR "num_pools" = "0"!]
[!LOOP "IpcfGlobalConfig/IpcfInstance/*"!]
[!IF "count(ManagedChannel/*) != 0"!]
[!LOOP "ManagedChannel/*"!]
[!IF "$num_pools < num:i(count(IpcfBuffer/*))"!]
[!VAR "num_pools" = "num:i(count(IpcfBuffer/*))"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDIF!]
[!ENDLOOP!]
#define IPC_SHM_MAX_POOLS       [!"num:i($num_pools)"!]U
[!ENDCODE!]

/*
* @brief			Maximum number of buffers per pool
*/
[!CODE!]
[!VAR "num_buffer" = "0"!]
[!LOOP "IpcfGlobalConfig/IpcfInstance/*"!]
[!IF "count(ManagedChannel/*) != 0"!]
[!LOOP "ManagedChannel/*"!]
[!LOOP "node:order(IpcfBuffer/*, 'node:value(BufferSize)')"!]
[!IF "$num_buffer < node:value(NumberOfBuffers)"!]
[!VAR "num_buffer" = "node:value(NumberOfBuffers)"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDIF!]
[!ENDLOOP!]
#define IPC_SHM_MAX_BUFS_PER_POOL       [!"num:i($num_buffer)"!]U
[!ENDCODE!]

#if defined(__cplusplus)
}
#endif

#endif /* IPCF_IP_CFG_DEFINES_H */
[!ENDCODE!]
