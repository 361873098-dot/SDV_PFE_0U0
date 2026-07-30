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
#ifndef IPCF_IP_CFG_H
#define IPCF_IP_CFG_H

#if defined(__cplusplus)
extern "C"{
#endif

/**
 * SOURCE FILE VERSION INFORMATION
 */
#define IPCF_IP_CFG_VENDOR_ID                    43
#define IPCF_IP_CFG_MODULE_ID                    255
#define IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION     4
#define IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define IPCF_IP_CFG_SW_MAJOR_VERSION             4
#define IPCF_IP_CFG_SW_MINOR_VERSION             10
#define IPCF_IP_CFG_SW_PATCH_VERSION             0

/*
* @brief            IPCF configuration for all instances
*
*/
extern struct ipc_shm_instances_cfg ipcf_shm_instances_cfg;

/* Unmanaged channel callback functions */
void ctrl_chan_rx_cb(void *arg, const uint8 instance, uint8 chan_id, void *mem);


/* Mananged channel callback functions */
void data_chan_rx_cb(void *arg, const uint8 instance, uint8 chan_id, void *buf, uint32 size);

#ifdef USING_OS_AUTOSAROS
#define IPCF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ipcf_MemMap.h"
#endif


/* Unmanaged channel callback function arguments */
extern const void* rx_cb_arg;

/* Managed channel callback functions arguments */
extern const void* rx_cb_arg;

#ifdef USING_OS_AUTOSAROS
#define IPCF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ipcf_MemMap.h"
#endif

#if defined(__cplusplus)
}
#endif

#endif /* IPCF_IP_CFG_H */
