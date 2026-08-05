/**
 * IPC Shared Memory Driver - Generic hardware definition
 *
 * Copyright 2022-2023 NXP
 * All Rights Reserved.
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 */
#ifndef IPC_HW_PLATFORM_H
#define IPC_HW_PLATFORM_H

#if defined(__cplusplus)
extern "C"{
#endif

#if defined(S32G2XX) || defined(S32G274A)
	#include "S32G274A_SCB.h"
	#include "S32G274A_MSCM.h"
	#include "S32G274A_M7_COMMON.h"
#endif
#if defined(S32R45)
	#include "S32R45_M7_COMMON.h"
	#include "S32R45_SCB.h"
	#include "S32R45_MSCM.h"
#endif

#define IPC_HW_PLATFORM_VENDOR_ID                    43
#define IPC_HW_PLATFORM_AR_RELEASE_MAJOR_VERSION     4
#define IPC_HW_PLATFORM_AR_RELEASE_MINOR_VERSION     4
#define IPC_HW_PLATFORM_AR_RELEASE_REVISION_VERSION  0
#define IPC_HW_PLATFORM_SW_MAJOR_VERSION             4
#define IPC_HW_PLATFORM_SW_MINOR_VERSION             10
#define IPC_HW_PLATFORM_SW_PATCH_VERSION             0

enum ipc_processor_idx {
	IPC_A53_0 = 0, /* ARM Cortex-A53 core 0 */
	IPC_A53_1 = 1, /* ARM Cortex-A53 core 1 */
	IPC_A53_2 = 2, /* ARM Cortex-A53 core 2 */
	IPC_A53_3 = 3, /* ARM Cortex-A53 core 3 */
	IPC_M7_0 = 4, /* ARM Cortex-M7 core 0 */
	IPC_M7_1 = 5, /* ARM Cortex-M7 core 1 */
	IPC_M7_2 = 6, /* ARM Cortex-M7 core 2 */
};

#define IPC_MSCM_CPX_COUNT                       7u
#define IPC_MSCM_MSI_COUNT                       4u
#define IPC_MSCM_IRCPnIGRx_INT_EN                0x1u
#define IPC_MSCM_IRCPnISRx_CLEAR_A53             0x000Fu

/* memory-mapped hardware peripheral MSCM */
typedef struct {
	volatile uint32 IPC_ISR; /* Interrupt Router CPn Interruptx Status Register */
	volatile uint32 IPC_IGR; /* Interrupt Router CPn Interruptx Generation Register */
} IPC_MSCM_IRCP_IR_Type;

typedef struct {
	IPC_MSCM_IRCP_IR_Type IRCPnIRx[IPC_MSCM_CPX_COUNT][IPC_MSCM_MSI_COUNT];
} IPC_MSCM_IRCPnIRx_Type;

/* Address of the first Interrupt Router CPn Interrupt Status */
#define IPC_IRCP0ISR0        (0x40198200u)

#define IPC_MSCM_IRCPnIRx    ((volatile IPC_MSCM_IRCPnIRx_Type *)IPC_IRCP0ISR0)

#define IPC_DCACHE_LINE_SIZE 32u

#if defined(__cplusplus)
}
#endif

#endif /* IPC_HW_PLATFORM_H */
