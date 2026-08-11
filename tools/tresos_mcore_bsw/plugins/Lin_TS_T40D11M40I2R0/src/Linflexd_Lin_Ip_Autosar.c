/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LINFLEXD
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file Linflexd_Lin_Ip_Autosar.c
*    @implements    Linflexd_Lin_Ip_Autosar.c_Artifact
*
*   @internal 
*   @addtogroup LINFLEXD_IP
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Linflexd_Lin_Ip_Autosar.h"
#include "SchM_Lin.h"

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    #include "Devassert.h"
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_LIN_IP_AUTOSAR_VENDOR_ID_C                       43
#define LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MAJOR_VERSION_C        4
#define LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MINOR_VERSION_C        4
#define LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_REVISION_VERSION_C     0
#define LINFLEXD_LIN_IP_AUTOSAR_SW_MAJOR_VERSION_C                4
#define LINFLEXD_LIN_IP_AUTOSAR_SW_MINOR_VERSION_C                0
#define LINFLEXD_LIN_IP_AUTOSAR_SW_PATCH_VERSION_C                2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Checks against Linflexd_Lin_Ip_Autosar.h */
#if (LINFLEXD_LIN_IP_AUTOSAR_VENDOR_ID_C != LINFLEXD_LIN_IP_AUTOSAR_VENDOR_ID)
    #error "Linflexd_Lin_Ip_Autosar.c and Linflexd_Lin_Ip_Autosar.h have different vendor ids"
#endif
/* Check if current file and Linflexd_Lin_Ip_Autosar header file are of the same Autosar version */
#if ((LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Linflexd_Lin_Ip_Autosar.c and Linflexd_Lin_Ip_Autosar.h are different"
#endif
/* Check if current file and Linflexd_Lin_Ip_Autosar header file are of the same Software version */
#if ((LINFLEXD_LIN_IP_AUTOSAR_SW_MAJOR_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_SW_MAJOR_VERSION) || \
     (LINFLEXD_LIN_IP_AUTOSAR_SW_MINOR_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_SW_MINOR_VERSION) || \
     (LINFLEXD_LIN_IP_AUTOSAR_SW_PATCH_VERSION_C != LINFLEXD_LIN_IP_AUTOSAR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Lin_Ip_Autosar.c and Linflexd_Lin_Ip_Autosar.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SchM_Lin.h header file are of the same Autosar version */
    #if ((LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MAJOR_VERSION_C != SCHM_LIN_AR_RELEASE_MAJOR_VERSION) || \
         (LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MINOR_VERSION_C != SCHM_LIN_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Linflexd_Lin_Ip_Autosar.c and SchM_Lin.h are different"
    #endif    
    
    #if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
        /* Check if current file and Devassert.h header file are of the same Autosar version */
        #if ((LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
             (LINFLEXD_LIN_IP_AUTOSAR_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Linflexd_Lin_Ip_Autosar.c and Devassert.h are different"
        #endif
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define LIN_START_SEC_CONST_UNSPECIFIED
#include "Lin_MemMap.h"

extern LINFLEXD_Type * const Linflexd_Lin_Ip_apxBases[LINFLEXD_INSTANCE_COUNT];

#define LIN_STOP_SEC_CONST_UNSPECIFIED
#include "Lin_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_CheckWakeup
 * Description   : Check whether a wake-up pulse is detected or not
 * This function is available only in autosar mode
 *
 *END**************************************************************************/
boolean Linflexd_Lin_Ip_CheckWakeup(const uint32 Instance)
{
    const LINFLEXD_Type *Base;
    boolean RetVal = FALSE;

#if (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON)
    LINFLEXD_LIN_IP_DEV_ASSERT(Instance < LINFLEXD_INSTANCE_COUNT);
#endif /* (LINFLEXD_LIN_IP_DEV_ERROR_DETECT == STD_ON) */

    /* Get base address of the LINFLEXD instance. */
    Base = (const LINFLEXD_Type *)Linflexd_Lin_Ip_apxBases[Instance];

    if (LINFLEXD_LINSR_WUF_MASK == (Base->LINSR & LINFLEXD_LINSR_WUF_MASK))
    {
        RetVal = TRUE;
    }

    return RetVal;
}

#if (STD_ON == LINFLEXD_LIN_IP_DUAL_CLOCK_MODE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Linflexd_Lin_Ip_SetBaudrate
 * Description   : Sets the registers value for a new baudrate value
 * This function is available only in autosar mode
 *
 *END**************************************************************************/
void Linflexd_Lin_Ip_SetBaudrate(const uint8 Instance, uint32 BaudrateDivider)
{
    LINFLEXD_Type *Base;
    uint32 Lincr1 = 0U;

    /* Get base address of the LINFLEXD instance. */
    Base = (LINFLEXD_Type *)Linflexd_Lin_Ip_apxBases[Instance];
    
    /* Capture state of LINCR1 register */
    Lincr1 = Base->LINCR1;

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_00();
    {
        /* Switch to Initialization mode */
        Base->LINCR1 |= LINFLEXD_LINCR1_INIT(1U);
        /* Clear sleep mode */
        Base->LINCR1 &= ~LINFLEXD_LINCR1_SLEEP(1U);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_00();

    Base->LINFBRR = LINFLEXD_LINFBRR_FBR(BaudrateDivider);
    Base->LINIBRR = LINFLEXD_LINIBRR_IBR(BaudrateDivider >> 8U);

    /* Exit Init mode and switch to Normal mode */
    Base->LINCR1 = Lincr1;
}

#endif /*(STD_ON == LINFLEXD_LIN_IP_DUAL_CLOCK_MODE) */

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
