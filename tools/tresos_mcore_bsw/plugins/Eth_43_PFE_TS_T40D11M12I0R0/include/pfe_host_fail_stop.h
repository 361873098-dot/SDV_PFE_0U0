/* =========================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.2.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.2.0_D2307_ASR_REL_4_4_REV_0000_20230728
 *
 *  This code (or certain portions of it) is released for use under license
 *  from Imagination Technologies Limited.
 *  Copyright (c) 2020-2021 Imagination Technologies Limited
 *  Copyright 2022-2023 NXP
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
 * ========================================================================= */

#ifndef PUBLIC_PFE_HOST_FAIL_STOP_H_
#define PUBLIC_PFE_HOST_FAIL_STOP_H_

typedef struct pfe_host_fail_stop_tag pfe_host_fail_stop_t;

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

pfe_host_fail_stop_t *pfe_host_fail_stop_create(addr_t cbus_base_va, addr_t host_fail_stop_base);
void pfe_host_fail_stop_destroy(pfe_host_fail_stop_t *host_fail_stop);
errno_t pfe_host_fail_stop_isr(const pfe_host_fail_stop_t *host_fail_stop);
void pfe_host_fail_stop_irq_mask(const pfe_host_fail_stop_t *host_fail_stop);
void pfe_host_fail_stop_irq_unmask(const pfe_host_fail_stop_t *host_fail_stop);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

#endif /* PUBLIC_PFE_HOST_FAIL_STOP_H_ */
