/**
 * IPC Shared Memory Driver - AutosarOS Specific Implementation
 *
 * Copyright 2018-2019,2021-2024 NXP
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

#include <Os.h>

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
/* Check if ipc-os-autosar.c file and ipc-shm.h file are of the same vendor */
#if (IPC_OS_VENDOR_ID_C != IPC_SHM_VENDOR_ID)
	#error "ipc-os-autosar.c and ipc-shm.h have different vendor IDs"
#endif
/* Check if ipc-os-autosar.c file and ipc-shm.h file are of the same Autosar version */
#if ((IPC_OS_AR_RELEASE_MAJOR_VERSION_C != IPC_SHM_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_OS_AR_RELEASE_MINOR_VERSION_C != IPC_SHM_AR_RELEASE_MINOR_VERSION) || \
	(IPC_OS_AR_RELEASE_REVISION_VERSION_C != IPC_SHM_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-os-autosar.c and ipc-shm.h are different"
#endif
/* Check if ipc-os-autosar.c file and ipc-shm.h file are of the same software version */
#if ((IPC_OS_SW_MAJOR_VERSION_C != IPC_SHM_SW_MAJOR_VERSION) || \
	(IPC_OS_SW_MINOR_VERSION_C != IPC_SHM_SW_MINOR_VERSION) || \
	(IPC_OS_SW_PATCH_VERSION_C != IPC_SHM_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-os-autosar.c and ipc-shm.h are different"
#endif

/* Check if ipc-os-autosar.c file and ipc-os.h file are of the same vendor */
#if (IPC_OS_VENDOR_ID_C != IPC_OS_VENDOR_ID)
	#error "ipc-os-autosar.c and ipc-os.h have different vendor IDs"
#endif
/* Check if ipc-os-autosar.c file and ipc-os.h file are of the same Autosar version */
#if ((IPC_OS_AR_RELEASE_MAJOR_VERSION_C != IPC_OS_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_OS_AR_RELEASE_MINOR_VERSION_C != IPC_OS_AR_RELEASE_MINOR_VERSION) || \
	(IPC_OS_AR_RELEASE_REVISION_VERSION_C != IPC_OS_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-os-autosar.c and ipc-os.h are different"
#endif
/* Check if ipc-os-autosar.c file and ipc-os.h file are of the same software version */
#if ((IPC_OS_SW_MAJOR_VERSION_C != IPC_OS_SW_MAJOR_VERSION) || \
	(IPC_OS_SW_MINOR_VERSION_C != IPC_OS_SW_MINOR_VERSION) || \
	(IPC_OS_SW_PATCH_VERSION_C != IPC_OS_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-os-autosar.c and ipc-os.h are different"
#endif

/* Check if ipc-os-autosar.c file and ipc-hw.h file are of the same vendor */
#if (IPC_OS_VENDOR_ID_C != IPC_HW_VENDOR_ID)
	#error "ipc-os-autosar.c and ipc-hw.h have different vendor IDs"
#endif
/* Check if ipc-os-autosar.c file and ipc-hw.h file are of the same Autosar version */
#if ((IPC_OS_AR_RELEASE_MAJOR_VERSION_C != IPC_HW_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_OS_AR_RELEASE_MINOR_VERSION_C != IPC_HW_AR_RELEASE_MINOR_VERSION) || \
	(IPC_OS_AR_RELEASE_REVISION_VERSION_C != IPC_HW_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-os-autosar.c and ipc-hw.h are different"
#endif
/* Check if ipc-os-autosar.c file and ipc-hw.h file are of the same software version */
#if ((IPC_OS_SW_MAJOR_VERSION_C != IPC_HW_SW_MAJOR_VERSION) || \
	(IPC_OS_SW_MINOR_VERSION_C != IPC_HW_SW_MINOR_VERSION) || \
	(IPC_OS_SW_PATCH_VERSION_C != IPC_HW_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-os-autosar.c and ipc-hw.h are different"
#endif

/**
 * enum msg_receive - used to indicate notification received for a new message
 *
 * @MSG_NOT_RECEIVED: no new message received from the remote core
 * @MSG_IS_RECEIVED: new message received from the remote core
 */
enum msg_receive {
	MSG_NOT_RECEIVED = 0U,
	MSG_IS_RECEIVED = 1U,
};

/**
 * enum isr_id_handler_state_type - used to indicate OsIsr handler state
 *
 * @HANDLER_DISABLED: OsIsr handler is disabled
 * @HANDLER_ENABLED:  OsIsr handler is enabled
 */
enum isr_id_handler_state_type {
	IPC_HANDLER_ENABLED = 0U,
	IPC_HANDLER_DISABLED = 1U,
};

/**
 * struct ipc_os_priv_instance - OS specific memory address
 * @local_shm:      local shared memory address
 * @remote_shm:     remote shared memory address
 * @rx_irq_num:     rx interrupt number
 * @state:          state to indicate whether instance is initialized
 * @msg_received:   state to indicate notification received for a new message
 * @isr_id_handler: the name of OsIsr defined to handle the interrupt
 * @rx_cb:          upper layer rx callback
 */
struct ipc_os_priv_instance {
	uintptr local_shm;
	uintptr remote_shm;
	uint8 state;
	sint16 rx_irq_num;
	uint8 msg_received;
	ISRType isr_id_handler;
	uint32 (*rx_cb)(const uint8 instance, uint32 budget);
};

/**
 * struct ipc_os_priv_type - OS specific private data
 * @ipc_os_priv_instance: OS specific private data each instance
 * @task_is_initialized: flag to know if the softirq task is initialized
 */
static struct ipc_os_priv_type {
	struct ipc_os_priv_instance id[IPC_SHM_MAX_INSTANCES];
	boolean task_is_initialized;
} ipc_os_priv;

/**
 * contains all RX OsIsr handlers (if duplicated it will be set to INVALID_ISR)
 * @isr_id_handler: the name of OsIsr defined to handle the interrupt
 * @isr_id_handler_state: the state of OsIsr defined to handle the interrupt
 */
static struct {
	ISRType isr_id_handler;
	volatile uint8 isr_id_handler_state;
}ipc_id_handlers[IPC_SHM_MAX_INSTANCES];

/**
 * ipc_os_init() - OS specific initialization code
 * @cfg:        configuration parameters
 * @rx_cb:      rx callback to be called from rx softirq
 *
 * When inter_core_rx_irq is disabled by passing IPC_IRQ_NONE as value, the
 * softirq task will not be activated.
 *
 * Return: IPC_SHM_E_OK on success, -IPC_SHM_E_NOTSUP if softirq task not in
 *         suspended state or softirq activation failed, -IPC_SHM_E_INVAL for
 *         invalid parameter rx_cb
 */
sint8 ipc_os_init(const uint8 instance, const struct ipc_shm_cfg *cfg,
		uint32 (*rx_cb)(const uint8, uint32))
{
	StatusType os_status = (StatusType)E_OK;
	TaskStateType task_state = SUSPENDED;
	sint8 err = -IPC_SHM_E_INVAL;
	uint8 handler_index;
	boolean isr_id_handler_duplicated = FALSE;

	if (rx_cb != NULL) {
		/* save params */
		ipc_os_priv.id[instance].local_shm = cfg->local_shm_addr;
		ipc_os_priv.id[instance].remote_shm = cfg->remote_shm_addr;
		ipc_os_priv.id[instance].state = IPC_SHM_INSTANCE_ENABLED;
		ipc_os_priv.id[instance].rx_cb = rx_cb;
		ipc_os_priv.id[instance].rx_irq_num = cfg->inter_core_rx_irq;
		ipc_os_priv.id[instance].msg_received = (uint8)MSG_NOT_RECEIVED;
		ipc_os_priv.id[instance].isr_id_handler = cfg->isr_id_handler;
		ipc_id_handlers[instance].isr_id_handler = INVALID_ISR;
		ipc_id_handlers[instance].isr_id_handler_state = (uint8)IPC_HANDLER_ENABLED;

		if ((ipc_os_priv.id[instance].rx_irq_num == IPC_IRQ_NONE)
			|| (ipc_os_priv.task_is_initialized != FALSE)) {
			/* softirq is not needed when polling */
			err = IPC_SHM_E_OK;
		} else {
			/* check if softirq task is suspended */
			(void)GetTaskState(ipc_shm_softirq, (TaskStateRefType)&task_state);
			if (task_state != SUSPENDED) {
				err = -IPC_SHM_E_NOTSUP;
			} else {
				/* activate softirq task */
				os_status = ActivateTask(ipc_shm_softirq);
				if (os_status != (StatusType)E_OK) {
					err = -IPC_SHM_E_NOTSUP;
				} else {
					ipc_os_priv.task_is_initialized = TRUE;
					err = IPC_SHM_E_OK;
				}
			}
		}
		if (err == IPC_SHM_E_OK) {
			/* populate ipc_id_handlers with cfg->isr_id_handler */
			for (handler_index = 0 ; handler_index < IPC_SHM_MAX_INSTANCES ; handler_index++) {
				if (ipc_id_handlers[handler_index].isr_id_handler == cfg->isr_id_handler) {
					isr_id_handler_duplicated = TRUE;
					break;
				}
			}

			if (isr_id_handler_duplicated == FALSE) {
				ipc_id_handlers[instance].isr_id_handler = cfg->isr_id_handler;
			}
		}
	}

	return err;
}

/**
 * ipc_os_free() - free OS specific resources
 */
void ipc_os_free(const uint8 instance)
{
	uint8 instance_id = 0;
	int keep_softirq_active = 0;
	StatusType os_status = (StatusType)E_OK; /* used for debugging */

	/* clear private data */
	ipc_os_priv.id[instance].rx_cb = NULL;
	ipc_os_priv.id[instance].state = IPC_SHM_INSTANCE_DISABLED;

	for(instance_id = 0; instance_id < IPC_SHM_MAX_INSTANCES; instance_id++) {
		if ((ipc_os_priv.id[instance_id].state == IPC_SHM_INSTANCE_ENABLED)
				&& (ipc_os_priv.id[instance_id].rx_irq_num != IPC_IRQ_NONE))
			/* Check if all non-polling instances are disable*/
			keep_softirq_active++;
	}

	if (ipc_os_priv.id[instance].rx_irq_num != IPC_IRQ_NONE) {
		/* kill deferred interrupt handler task if no instance exist */
		if ((ipc_os_priv.task_is_initialized != FALSE)
			&& (keep_softirq_active == 0)) {
			os_status = SetEvent(ipc_shm_softirq,
				(uint32)IPC_EVENT_OS_FREE);
			(void) os_status;
			ipc_os_priv.task_is_initialized = FALSE;
		}
	}
}

/* disable the handler only if not already disabled */
static void ipc_disable_handler(ISRType isr_id_handler)
{
	StatusType os_status = (StatusType)E_OK; /* used for debugging */
	uint8 handler_index;

	/* scan to find the index of isr_id_handler */
	for (handler_index = 0 ; handler_index < IPC_SHM_MAX_INSTANCES ; handler_index++) {
		if ((ipc_id_handlers[handler_index].isr_id_handler == isr_id_handler) &&
			(ipc_id_handlers[handler_index].isr_id_handler_state == (uint8)IPC_HANDLER_ENABLED)) {

			/* disable notifications from remote */
			os_status = DisableInterruptSource(ipc_id_handlers[handler_index].isr_id_handler);
			(void) os_status;

			/* mark handler as disabled */
			ipc_id_handlers[handler_index].isr_id_handler_state = (uint8)IPC_HANDLER_DISABLED;

			break;
		}
	}
}

/* re-enable irq routing for all instances */
static void ipc_reenable_interrupts(void)
{
	StatusType os_status = (StatusType)E_OK; /* used for debugging */
	uint8 i = 0;

	for (i = 0; i < IPC_SHM_MAX_INSTANCES; i++) {

		if ((ipc_os_priv.id[i].state == IPC_SHM_INSTANCE_DISABLED)
				|| (ipc_os_priv.id[i].rx_irq_num == IPC_IRQ_NONE))
			continue;

		if (ipc_id_handlers[i].isr_id_handler_state == (uint8)IPC_HANDLER_DISABLED) {

			/* mark handler as enabled */
			ipc_id_handlers[i].isr_id_handler_state = (uint8)IPC_HANDLER_ENABLED;

			/* re-enable interrupt source if is disabled */
			os_status = EnableInterruptSource(ipc_id_handlers[i].isr_id_handler, TRUE);
			(void) os_status;
		}
	}
}

/**
 * ipc_shm_softirq() - task acting as deferred interrupt handler
 *
 * This task waits to be signaled by the interrupt handler and calls the upper
 * layer callback registeres with ipc_shm_init(). If ipc_os_free() is called,
 * the task receives a different signal and proceeds to its termination.
 */
TASK(ipc_shm_softirq)
{
	StatusType os_status = (StatusType)E_OK; /* used for debugging */
	EventMaskType event = 0x0;
	uint32 work = 0;
	uint8 i = 0;

	for ( ; ; ) {
		/* wait for any event */
		os_status = WaitEvent((uint32)IPC_EVENT_RX_IRQ |
			(uint32)IPC_EVENT_OS_FREE);
		(void) os_status;

		/* get event bits state */
		os_status = GetEvent(ipc_shm_softirq, (EventMaskRefType)&event);
		(void) os_status;

		if ((event & (uint32) IPC_EVENT_OS_FREE) != 0u) {
			os_status = ClearEvent((uint32) IPC_EVENT_OS_FREE);
			(void) os_status;
			os_status = TerminateTask();
			(void) os_status;
		}

		/* call upper layer callback for all non-polling instances */
		for (i = 0; i < IPC_SHM_MAX_INSTANCES; i++) {
			if ((ipc_os_priv.id[i].state == IPC_SHM_INSTANCE_DISABLED)
				|| (ipc_os_priv.id[i].msg_received == (uint8)MSG_NOT_RECEIVED))
				continue;

			do {
				/* call upper layer callback */
				work = ipc_os_priv.id[i].rx_cb(i, IPC_SOFTIRQ_BUDGET);

				/* yield and wait for reschedule */
				os_status = Schedule();
				(void) os_status;
			} while (work >= IPC_SOFTIRQ_BUDGET);
			/* reset the flag used to notify  message received */
			ipc_os_priv.id[i].msg_received = (uint8)MSG_NOT_RECEIVED;
		}

		/* work done, clear event */
		os_status = ClearEvent((uint32) IPC_EVENT_RX_IRQ);
		(void) os_status;

		/* re-enable irq routing for all instances */
		ipc_reenable_interrupts();
	}
}

/**
 * ipc_shm_hardirq() - driver interrupt service routine
 */
void ipc_shm_hardirq(void)
{
	StatusType os_status = (StatusType)E_OK; /* used for debugging */
	uint8 i = 0;

	/* ensure the ipc_shm_softirq is initialized */
	if (ipc_os_priv.task_is_initialized != FALSE) {
		for (i = 0; i < IPC_SHM_MAX_INSTANCES; i++) {
			if ((ipc_os_priv.id[i].state != IPC_SHM_INSTANCE_DISABLED)
					&& (ipc_os_priv.id[i].rx_irq_num != IPC_IRQ_NONE)) {
				/* disable notifications from remote */
				ipc_disable_handler(ipc_os_priv.id[i].isr_id_handler);

				/* clear irq notification */
				ipc_hw_irq_clear(i);

				/* set the flag for each instance */
				ipc_os_priv.id[i].msg_received = (uint8)MSG_IS_RECEIVED;
			}
		}

		/* signal the deferred interrupt handler */
		os_status = SetEvent(ipc_shm_softirq, (uint32) IPC_EVENT_RX_IRQ);
		(void) os_status;
	}
}

/**
 * ipc_shm_hardirq_instance() - driver interrupt service routine
 *
 * This function is set as core to core ISR by the application.
 */
void ipc_shm_hardirq_instance(const uint8 instance)
{
	StatusType os_status = (StatusType)E_OK; /* used for debugging */

	if ((ipc_os_priv.task_is_initialized != FALSE)
		&& (ipc_os_priv.id[instance].state != IPC_SHM_INSTANCE_DISABLED)
		&& (ipc_os_priv.id[instance].rx_irq_num != IPC_IRQ_NONE)) {
		/* disable notifications from remote */
		ipc_disable_handler(ipc_os_priv.id[instance].isr_id_handler);

		/* clear irq notification */
		ipc_hw_irq_clear(instance);

		/* set the flag used to notify message is received */
		if (ipc_os_priv.id[instance].msg_received == (uint8)MSG_NOT_RECEIVED) {
			ipc_os_priv.id[instance].msg_received = (uint8)MSG_IS_RECEIVED;
		}

		/* signal the deferred interrupt handler */
		os_status = SetEvent(ipc_shm_softirq, (uint32) IPC_EVENT_RX_IRQ);
		(void) os_status;
	}
}

/**
 * ipc_os_get_local_shm() - get local shared mem address
 */
uintptr ipc_os_get_local_shm(const uint8 instance)
{
	return ipc_os_priv.id[instance].local_shm;
}

/**
 * ipc_os_get_remote_shm() - get remote shared mem address
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
