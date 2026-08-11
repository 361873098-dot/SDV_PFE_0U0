/**
  @file             autolibc.h
  @brief            Header file for the AutoLibc.c
*/
/*==============================================================================
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
 *  Copyright (c) 2012-2016 Freescale Semiconductor Inc.
 *  Copyright 2016-2018, 2020, 2022-2023 NXP
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
==============================================================================*/
/*==============================================================================
==============================================================================*/

#ifndef AUTOLIBC_H
#define AUTOLIBC_H

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

/*==============================================================================
                                INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==============================================================================*/
#include "pfe_cfg.h"
#include "oal_types.h"

/*==============================================================================
                      SOURCE FILE VERSION INFORMATION
==============================================================================*/

/*==============================================================================
                            FILE VERSION CHECKS
==============================================================================*/

/*==============================================================================
                                 CONSTANTS
==============================================================================*/

/*==============================================================================
                             DEFINES AND MACROS
==============================================================================*/

/*==============================================================================
                                    ENUMS
==============================================================================*/

/*==============================================================================
                        STRUCTURES AND OTHER TYPEDEFS
==============================================================================*/

/*==============================================================================
                         GLOBAL VARIABLE DECLARATIONS
==============================================================================*/

/*==============================================================================
                             FUNCTION PROTOTYPES
==============================================================================*/

#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

extern void *autolibc_memcpy (void *pavDest2, const void *pcoavSource2, uint32_t u32Length2);
extern void *autolibc_memset (void *pavDest3, int32_t s32Fill3, uint32_t u32Length3);
extern void *autolibc_memmove (void *pavDest4, const void *pcoavSource4, uint32_t u32Length4);
extern int32_t autolibc_memcmp (const void *pcoavMemA5, const void *pcoavMemB5, uint32_t u32Size5);
extern int32_t autolibc_strcmp (const char_t *pcoszStrA6, const char_t *pcoszStrB6);
extern char_t *autolibc_strncpy (char_t *pszDest7, const char_t *pcoszSrc7, uint32_t u32Length7);
extern uint32_t autolibc_strlen (const char_t pcozsStr8[]);
extern char_t *autolibc_strcpy(char_t *pszDest, const char_t *pcoszSrc);
extern uint32_t autolibc_strnlen(const char_t pcozsStr8[], uint32_t u32Strsz);

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"


#endif /* AUTOLIBC_H */
