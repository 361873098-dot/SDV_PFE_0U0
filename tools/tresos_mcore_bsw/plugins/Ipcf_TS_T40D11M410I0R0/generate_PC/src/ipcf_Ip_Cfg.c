[!CODE!][!//
[!AUTOSPACING!][!//
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
#if defined(__cplusplus)
extern "C"{
#endif

#include "ipc-types.h"
#include "ipcf_Ip_Cfg.h"

/**
 * SOURCE FILE VERSION INFORMATION
 */
#define IPCF_IP_CFG_VENDOR_ID_C                    43
#define IPCF_IP_CFG_MODULE_ID_C                    255
#define IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION_C     4
#define IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION_C     4
#define IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION_C  0
#define IPCF_IP_CFG_SW_MAJOR_VERSION_C             4
#define IPCF_IP_CFG_SW_MINOR_VERSION_C             10
#define IPCF_IP_CFG_SW_PATCH_VERSION_C             0

/**
 * FILE VERSION CHECKS
 */
#if (IPCF_IP_CFG_VENDOR_ID_C != IPC_TYPES_VENDOR_ID)
	#error "ipcf_Ip_Cfg.c and ipc-types.h have different vendor ids"
#endif
#if ((IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != IPC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
	(IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION_C != IPC_TYPES_AR_RELEASE_MINOR_VERSION) || \
	(IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION_C != IPC_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of ipcf_Ip_Cfg.c and ipc-types.h are different"
#endif
#if ((IPCF_IP_CFG_SW_MAJOR_VERSION_C != IPC_TYPES_SW_MAJOR_VERSION) || \
	(IPCF_IP_CFG_SW_MINOR_VERSION_C != IPC_TYPES_SW_MINOR_VERSION) || \
	(IPCF_IP_CFG_SW_PATCH_VERSION_C != IPC_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of ipcf_Ip_Cfg.c and ipc-types.h are different"
#endif

#if (IPCF_IP_CFG_VENDOR_ID_C != IPCF_IP_CFG_VENDOR_ID)
	#error "ipcf_Ip_Cfg.c and ipcf_Ip_Cfg.h have different vendor ids"
#endif
#if ((IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
	(IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION_C != IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
	(IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION_C != IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of ipcf_Ip_Cfg.c and ipcf_Ip_Cfg.h are different"
#endif
#if ((IPCF_IP_CFG_SW_MAJOR_VERSION_C != IPCF_IP_CFG_SW_MAJOR_VERSION) || \
	(IPCF_IP_CFG_SW_MINOR_VERSION_C != IPCF_IP_CFG_SW_MINOR_VERSION) || \
	(IPCF_IP_CFG_SW_PATCH_VERSION_C != IPCF_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of ipcf_Ip_Cfg.c and ipcf_Ip_Cfg.h are different"
#endif

/*  Buffer pools are sorted in ascending order according to buffer size.	*/
[!CODE!]
[!LOOP "IpcfGlobalConfig/IpcfInstance/*"!]
[!LOOP "ManagedChannel/*"!]

/* [!"node:name(../../.)"!]  [!"node:name(.)"!] buffers configuration */
static struct ipc_shm_pool_cfg ipcf_[!"text:tolower(node:name(../../.))"!]_cfg_buf_pools[!"node:pos(.)"!][[!"num:i(count(./IpcfBuffer/*))"!]] = {

[!LOOP "node:order(IpcfBuffer/*, 'node:value(BufferSize)')"!]
/* [!"node:name(.)"!] configuration */
{
    .num_bufs = [!"node:value(NumberOfBuffers)"!],
    .buf_size = [!"node:value(BufferSize)"!],
},

[!ENDLOOP!]
};
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDCODE!]

[!CODE!]
[!LOOP "IpcfGlobalConfig/IpcfInstance/*"!]

static struct ipc_shm_channel_cfg ipcf_cfg_channels[!"node:pos(.)"!][[!"num:i(count(UnmanagedChannel/*) + count(ManagedChannel/*))"!]] = {
[!IF "count(UnmanagedChannel/*) != 0"!]
[!LOOP "UnmanagedChannel/*"!]
{
    .type = IPC_SHM_[!"node:value(RemoteCoreChanneltype)"!],
    .ch = {
        .unmanaged = {
            .size = [!"node:value(ChannelSize)"!],
            .rx_cb = [!"node:value(ReceiveCallback)"!],
            .cb_arg = &[!"node:value(ReceiveCallbackArgument)"!],
        },
    },
},
[!ENDLOOP!]
[!ENDIF!]
[!IF "count(ManagedChannel/*) != 0"!]
[!LOOP "ManagedChannel/*"!]
{
    .type = IPC_SHM_[!"node:value(RemoteCoreChanneltype)"!],
    .ch = {
        .managed = {
            .num_pools = [!"num:i(count(IpcfBuffer/*))"!],
            .pools = ipcf_[!"text:tolower(node:name(../../.))"!]_cfg_buf_pools[!"node:pos(.)"!],
            .rx_cb = [!"node:value(ReceiveCallback)"!],
            .cb_arg = &[!"node:value(ReceiveCallbackArgument)"!],
        },
    },
},
[!ENDLOOP!]
[!ENDIF!]
};
[!ENDLOOP!]
[!ENDCODE!]

[!CODE!]
struct ipc_shm_cfg ipcf_cfg_instances[[!"num:i(count(IpcfGlobalConfig/IpcfInstance/*))"!]] = {
[!ENDCODE!]
[!LOOP "node:order(IpcfGlobalConfig/IpcfInstance/*, './IpcInstanceID')"!]
[!CODE!]
{
    .local_shm_addr = [!"num:inttohex(node:value(IpcLocalRamAddress))"!],
    .remote_shm_addr = [!"num:inttohex(node:value(IpcRemoteRamAddress))"!],
    .shm_size = [!"num:inttohex(node:value(IpcSharedMemorySize))"!],
    .inter_core_tx_irq = [!"node:value(IpcInterCoreTxIrq)"!],
    .inter_core_rx_irq = [!"node:value(IpcInterCoreRxIrq)"!],
    .local_core = {
        .type = [!"node:value(IpcLocalCore)"!],
        .index = [!"node:value(IpcLocalCoreIndex)"!],
    },
    .remote_core = {
        .type = [!"node:value(IpcRemoteCore)"!],
        .index = [!"node:value(IpcRemoteCoreIndex)"!],
    },
    .num_channels = [!"num:i(count(UnmanagedChannel/*) + count(ManagedChannel/*))"!]U,
    .channels = ipcf_cfg_channels[!"node:pos(.)"!],
[!IF "(node:exists('ASPathDataOfSchema:/AUTOSAR/Os/OsIsr') = true() and
		text:contains(node:value(IpcInterCoreRxIrq),'IPC_IRQ_NONE') = false())"!]
	.isr_id_handler = [!"node:name(node:ref(OsIsrHandler))"!],
[!ENDIF!]
},
[!ENDCODE!]
[!ENDLOOP!]
};

[!CODE!]
struct ipc_shm_instances_cfg ipcf_shm_instances_cfg = {
    .num_instances = [!"num:i(count(IpcfGlobalConfig/IpcfInstance/*))"!]U,
    .shm_cfg = ipcf_cfg_instances
};
[!ENDCODE!]

[!ENDCODE!]

#if defined(__cplusplus)
}
#endif
