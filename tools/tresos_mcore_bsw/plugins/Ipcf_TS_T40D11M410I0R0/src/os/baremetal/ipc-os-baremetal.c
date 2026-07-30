/**
 * IPC Shared Memory Driver - Bare Metal Specific Implementation
 *
 * Copyright 2018,2021-2024 NXP
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
#if defined(__cplusplus)
extern "C"{
#endif

#include "ipc-shm.h"
#include "ipc-os.h"
#include "ipc-hw.h"

/*
 * SOURCE FILE VERSION INFORMATION
 */
#define IPC_OS_VENDOR_ID_C                    43
#define IPC_OS_AR_RELEASE_MAJOR_VERSION_C     4
#define IPC_OS_AR_RELEASE_MINOR_VERSION_C     4
#define IPC_OS_AR_RELEASE_REVISION_VERSION_C  0
#define IPC_OS_SW_MAJOR_VERSION_C             4
#define IPC_OS_SW_MINOR_VERSION_C             10
#define IPC_OS_SW_PATCH_VERSION_C             0

/*
 * FILE VERSION CHECKS
 */
/* Check if ipc-os-baremetal.c file and ipc-shm.h file are of the same vendor */
#if (IPC_OS_VENDOR_ID_C != IPC_SHM_VENDOR_ID)
	#error "ipc-os-baremetal.c and ipc-shm.h have different vendor IDs"
#endif
/* Check if ipc-os-baremetal.c file and ipc-shm.h file are of the same Autosar version */
#if ((IPC_OS_AR_RELEASE_MAJOR_VERSION_C != IPC_SHM_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_OS_AR_RELEASE_MINOR_VERSION_C != IPC_SHM_AR_RELEASE_MINOR_VERSION) || \
	(IPC_OS_AR_RELEASE_REVISION_VERSION_C != IPC_SHM_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-os-baremetal.c and ipc-shm.h are different"
#endif
/* Check if ipc-os-baremetal.c file and ipc-shm.h file are of the same software version */
#if ((IPC_OS_SW_MAJOR_VERSION_C != IPC_SHM_SW_MAJOR_VERSION) || \
	(IPC_OS_SW_MINOR_VERSION_C != IPC_SHM_SW_MINOR_VERSION) || \
	(IPC_OS_SW_PATCH_VERSION_C != IPC_SHM_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-os-baremetal.c and ipc-shm.h are different"
#endif

/* Check if ipc-os-baremetal.c file and ipc-os.h file are of the same vendor */
#if (IPC_OS_VENDOR_ID_C != IPC_OS_VENDOR_ID)
	#error "ipc-os-baremetal.c and ipc-os.h have different vendor IDs"
#endif
/* Check if ipc-os-baremetal.c file and ipc-os.h file are of the same Autosar version */
#if ((IPC_OS_AR_RELEASE_MAJOR_VERSION_C != IPC_OS_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_OS_AR_RELEASE_MINOR_VERSION_C != IPC_OS_AR_RELEASE_MINOR_VERSION) || \
	(IPC_OS_AR_RELEASE_REVISION_VERSION_C != IPC_OS_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-os-baremetal.c and ipc-os.h are different"
#endif
/* Check if ipc-os-baremetal.c file and ipc-os.h file are of the same software version */
#if ((IPC_OS_SW_MAJOR_VERSION_C != IPC_OS_SW_MAJOR_VERSION) || \
	(IPC_OS_SW_MINOR_VERSION_C != IPC_OS_SW_MINOR_VERSION) || \
	(IPC_OS_SW_PATCH_VERSION_C != IPC_OS_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-os-baremetal.c and ipc-os.h are different"
#endif

/* Check if ipc-os-baremetal.c file and ipc-hw.h file are of the same vendor */
#if (IPC_OS_VENDOR_ID_C != IPC_HW_VENDOR_ID)
	#error "ipc-os-baremetal.c and ipc-hw.h have different vendor IDs"
#endif
/* Check if ipc-os-baremetal.c file and ipc-hw.h file are of the same Autosar version */
#if ((IPC_OS_AR_RELEASE_MAJOR_VERSION_C != IPC_HW_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_OS_AR_RELEASE_MINOR_VERSION_C != IPC_HW_AR_RELEASE_MINOR_VERSION) || \
	(IPC_OS_AR_RELEASE_REVISION_VERSION_C != IPC_HW_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-os-baremetal.c and ipc-hw.h are different"
#endif
/* Check if ipc-os-baremetal.c file and ipc-hw.h file are of the same software version */
#if ((IPC_OS_SW_MAJOR_VERSION_C != IPC_HW_SW_MAJOR_VERSION) || \
	(IPC_OS_SW_MINOR_VERSION_C != IPC_HW_SW_MINOR_VERSION) || \
	(IPC_OS_SW_PATCH_VERSION_C != IPC_HW_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-os-baremetal.c and ipc-hw.h are different"
#endif

/**
 * struct ipc_os_priv_instance - OS specific private data per instance
 * @local_shm:      local shared memory address
 * @remote_shm:     remote shared memory address
 * @rx_irq_num:     rx interrupt number
 * @state:          state to indicate whether instance is initialized
 * @rx_cb:          upper layer rx callback
 */
struct ipc_os_priv_instance {
	uintptr local_shm;
	uintptr remote_shm;
	uint8 state;
	sint16 rx_irq_num;
	uint32 (*rx_cb)(const uint8 instance, uint32 budget);
};

/**
 * struct ipc_os_priv_type - OS specific private data
 * @id:             private data per instance
 */
static struct ipc_os_priv_type {
	struct ipc_os_priv_instance id[IPC_SHM_MAX_INSTANCES];
} ipc_os_priv;

/**
 * ipc_os_init() - OS specific initialization code
 * @instance:   instance id
 * @cfg:        configuration parameters
 * @rx_cb:      rx callback to be called from interrupt handler
 *
 * Return: IPC_SHM_E_OK on success, -IPC_SHM_E_INVAL for invalid parameter rx_cb
 */
sint8 ipc_os_init(const uint8 instance, const struct ipc_shm_cfg *cfg,
		uint32 (*rx_cb)(const uint8, uint32))
{
	sint8 err = -IPC_SHM_E_INVAL;

	if (rx_cb != NULL) {
		/* save params */
		ipc_os_priv.id[instance].local_shm = cfg->local_shm_addr;
		ipc_os_priv.id[instance].remote_shm = cfg->remote_shm_addr;
		ipc_os_priv.id[instance].state = IPC_SHM_INSTANCE_ENABLED;
		ipc_os_priv.id[instance].rx_cb = rx_cb;
		ipc_os_priv.id[instance].rx_irq_num = cfg->inter_core_rx_irq;
		err = IPC_SHM_E_OK;
	}

	return err;
}

/**
 * ipc_os_free() - free OS specific resources
 * @instance:   instance id
 */
void ipc_os_free(const uint8 instance)
{
	int keep_irq_enable = 0;
	uint8 i = 0;

	/* clear private data */
	ipc_os_priv.id[instance].rx_cb = NULL;
	ipc_os_priv.id[instance].state = IPC_SHM_INSTANCE_DISABLED;

	/* disable notifications from remote */
	if (ipc_os_priv.id[instance].rx_irq_num != IPC_IRQ_NONE) {
		for (i = 0 ; i < IPC_SHM_MAX_INSTANCES ; i++) {
			if (instance == i)
				continue;
			if (ipc_os_priv.id[i].rx_irq_num == ipc_os_priv.id[instance].rx_irq_num) {
				keep_irq_enable++;
				break;
			}
		}
		/* disable notifications from remote */
		if (keep_irq_enable == 0)
			ipc_hw_irq_disable(instance);
	}
}

/**
 * ipc_shm_hardirq() - driver interrupt service routine
 *
 * This function is set as core to core ISR by the application.
 */
void ipc_shm_hardirq(void)
{
	uint32 work = 0;
	uint8 i = 0;

	for (i = 0; i < IPC_SHM_MAX_INSTANCES; i++) {
		if (ipc_os_priv.id[i].state == IPC_SHM_INSTANCE_DISABLED)
			continue;
		/* disable notifications from remote */
		ipc_hw_irq_disable(i);

		/* clear notification */
		ipc_hw_irq_clear(i);
	}

	/* call upper layer callback for all non-polling instances */
	for (i = 0; i < IPC_SHM_MAX_INSTANCES; i++) {
		if ((ipc_os_priv.id[i].state == IPC_SHM_INSTANCE_DISABLED)
				|| (ipc_os_priv.id[i].rx_irq_num == IPC_IRQ_NONE))
			continue;

		/* call upper layer callback until work is done */
		do {
			work = ipc_os_priv.id[i].rx_cb(i, IPC_SOFTIRQ_BUDGET);
		} while (work >= IPC_SOFTIRQ_BUDGET);
	}

	for (i = 0; i < IPC_SHM_MAX_INSTANCES; i++) {
		if (ipc_os_priv.id[i].state == IPC_SHM_INSTANCE_DISABLED)
			continue;
		/* enable notifications from remote */
		ipc_hw_irq_enable(i);
	}
}

/**
 * ipc_shm_hardirq_instance() - driver interrupt service routine
 *
 * This function is set as core to core ISR by the application.
 */
void ipc_shm_hardirq_instance(const uint8 instance)
{
	uint32 work = 0;

	if (ipc_os_priv.id[instance].state != IPC_SHM_INSTANCE_DISABLED) {
		/* disable notifications from remote */
		ipc_hw_irq_disable(instance);
		/* clear notification */
		ipc_hw_irq_clear(instance);
		/* call upper layer callback for all non-polling instances */
		if (ipc_os_priv.id[instance].rx_irq_num != IPC_IRQ_NONE) {
			/* call upper layer callback until work is done */
			do {
				work = ipc_os_priv.id[instance].rx_cb(instance, IPC_SOFTIRQ_BUDGET);
			} while (work >= IPC_SOFTIRQ_BUDGET);

			/* enable notifications from remote */
			ipc_hw_irq_enable(instance);
		}
	}
}

/**
 * ipc_os_get_local_shm() - get local shared mem address
 * @instance:   instance id
 */
uintptr ipc_os_get_local_shm(const uint8 instance)
{
	return ipc_os_priv.id[instance].local_shm;
}

/**
 * ipc_os_get_remote_shm() - get remote shared mem address
 * @instance:   instance id
 */
uintptr ipc_os_get_remote_shm(const uint8 instance)
{
	return ipc_os_priv.id[instance].remote_shm;
}

/**
 * ipc_os_poll_channels() - invoke rx callback configured at initialization
 */
sint8 ipc_os_poll_channels(const uint8 instance)
{
	sint8 err = IPC_SHM_E_OK;

	/* the softirq will handle rx operation if rx interrupt is configured */
	if (ipc_os_priv.id[instance].rx_irq_num == IPC_IRQ_NONE) {
		/* call upper layer callback until work is done */
		(void)ipc_os_priv.id[instance].rx_cb(instance, IPC_SOFTIRQ_BUDGET);
	} else {
		err = -IPC_SHM_E_INVAL;
	}

	return err;
}

#if defined(__cplusplus)
}
#endif
