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
 *  Copyright 2018-2023 NXP
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

/**
 * @addtogroup dxgr_ELF
 * @{
 * 
 * @file            elf_cfg.h
 * @version         0.0.0.0
 *
 * @brief           Configuration header file for the ELF module.
 *
 */
/*==================================================================================================
==================================================================================================*/

/*==================================================================================================
                                         MISRA VIOLATIONS
==================================================================================================*/

#ifndef ELF_CFG_H
    #define ELF_CFG_H

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43120440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43120440
#endif

#ifndef TRUE
    #define TRUE 1
#endif /* TRUE */
#ifndef FALSE
    #define FALSE 0
#endif /* FALSE */

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/  

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @def      ELF_CFG_PROGRAM_TABLE_USED
* @brief    Configures whether functions for loading binary from program table will be built.
* @details  This is the standard way of loading ELFs.
*/
#define ELF_CFG_PROGRAM_TABLE_USED TRUE

/**
* @def      ELF_CFG_SECTION_TABLE_USED
* @brief    Configures whether functions for loading binary from section table will be built.
* @details  This is a non-standard way of loading ELFs.
*/
#define ELF_CFG_SECTION_TABLE_USED TRUE

/**
* @def      ELF_CFG_ELF32_SUPPORTED
* @brief    Configures whether 32-bit ELF format support shall be built.
*/
#define ELF_CFG_ELF32_SUPPORTED TRUE

/**
* @def      ELF_CFG_ELF64_SUPPORTED
* @brief    Configures whether 64-bit ELF format support shall be built.
*/
#ifndef ELF_CFG_ELF64_SUPPORTED
#define ELF_CFG_ELF64_SUPPORTED FALSE
#endif

/**
* @def      ELF_CFG_SECTION_PRINT_ENABLED
* @brief    Configures whether function ELF_PrintSections shall be built.
* @details  Normally it will be FALSE.
*/
#define ELF_CFG_SECTION_PRINT_ENABLED TRUE

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* ELF_CFG_H */

/** @}*/
