[!AUTOSPACING!]
[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IPV_QSPI
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLS_CFG_DEFINES_H
#define FLS_CFG_DEFINES_H

/**
*   @file Fls_Cfg_Defines.h
*
*   @addtogroup FLS
*   @{
*/

/* implements Fls_Cfg_Defines.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG_DEFINES                    43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES     4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG_DEFINES     4
#define FLS_AR_RELEASE_REVISION_VERSION_CFG_DEFINES  0
#define FLS_SW_MAJOR_VERSION_CFG_DEFINES             4
#define FLS_SW_MINOR_VERSION_CFG_DEFINES             0
#define FLS_SW_PATCH_VERSION_CFG_DEFINES             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!MACRO "FeatureGetValue", "FeatureName"!][!//
[!NOCODE!][!//
[!IF "ecu:has($FeatureName)"!][!//
    [!CODE!][!"ecu:get($FeatureName)"!][!ENDCODE!]
[!ELSE!][!//
    [!CODE!]0[!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]
[!//
[!//


/* Enable calculates CRC for items of Fls Configuration */
#define FLS_CHECK_CFG_CRC                    ([!IF "FlsGeneral/FlsEnableCheckCfgCrc"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_Cancel function */
#define FLS_CANCEL_API                       ([!IF "FlsGeneral/FlsCancelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_Compare function */
#define FLS_COMPARE_API                      ([!IF "FlsGeneral/FlsCompareApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_BlankCheck function */
#define FLS_BLANK_CHECK_API                  ([!IF "FlsGeneral/FlsBlankCheckApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable and disable development error detection */
#define FLS_DEV_ERROR_DETECT                 ([!IF "FlsGeneral/FlsDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_GetJobResult function */
#define FLS_GET_JOB_RESULT_API               ([!IF "FlsGeneral/FlsGetJobResultApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_GetStatus function */
#define FLS_GET_STATUS_API                   ([!IF "FlsGeneral/FlsGetStatusApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_SetMode function */
#define FLS_SET_MODE_API                     ([!IF "FlsGeneral/FlsSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the API to read out the modules version information */
#define FLS_VERSION_INFO_API                 ([!IF "FlsGeneral/FlsVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


/* External QSPI sectors are present or not in the current configuration. */
#define FLS_QSPI_SECTORS_CONFIGURED          ([!IF "AutosarExt/FlsExternalSectorsConfigured"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)
/* Enable the hang recovery feature for the external QuadSPI controller. */
#define FLS_QSPI_HANG_RECOVERY               ([!IF "AutosarExt/FlsQspiHangRecovery"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

/* Pre-processor switch to enable / disable the erase blank check */
#define FLS_ERASE_VERIFICATION_ENABLED       ([!IF "FlsGeneral/FlsEraseVerificationEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the write verify check */
#define FLS_WRITE_VERIFICATION_ENABLED       ([!IF "FlsGeneral/FlsWriteVerificationEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if ((STD_ON == FLS_ERASE_VERIFICATION_ENABLED) && (STD_ON == FLS_QSPI_SECTORS_CONFIGURED))
    /* The maximum number of bytes to blank check in one cycle of the flash driver job processing function */
    #define FLS_MAX_ERASE_BLANK_CHECK        ([!"FlsGeneral/FlsMaxEraseBlankCheck"!]U)
#endif

/* Timeout handling enabled */
#define FLS_TIMEOUT_SUPERVISION_ENABLED      ([!IF "FlsGeneral/FlsTimeoutSupervisionEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!INDENT "0"!][!//
[!IF "FlsGeneral/FlsTimeoutSupervisionEnabled"!]

#if ((FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) && (FLS_QSPI_SECTORS_CONFIGURED == STD_ON))
/* Timeout value for Erase and Write operation - QSPI flash operations. */
#define FLS_QSPI_SYNC_WRITE_TIMEOUT          ([!"FlsGeneral/FlsQspiSyncWriteTimeout"!]U)
#define FLS_QSPI_SYNC_ERASE_TIMEOUT          ([!"FlsGeneral/FlsQspiSyncEraseTimeout"!]U)
#define FLS_QSPI_ASYNC_WRITE_TIMEOUT         ([!"FlsGeneral/FlsQspiAsyncWriteTimeout"!]U)
#define FLS_QSPI_ASYNC_ERASE_TIMEOUT         ([!"FlsGeneral/FlsQspiAsyncEraseTimeout"!]U)
#endif

[!IF "AutosarExt/FlsMCoreEnable = 'true'"!]
/* OsIf counter type used in timeout detection for FLS operations */
#define FLS_TIMEOUT_TYPE                     ([!"FlsGeneral/FlsTimeoutMethod"!])

/* Multicore operations timeout */
#define FLS_MCORE_ARBITRATION_TIMEOUT        ([!"FlsGeneral/FlsMCoreArbitrationTimeout"!]U)
#define FLS_MCORE_INIT_TIMEOUT               ([!"FlsGeneral/FlsMCoreInitTimeout"!]U)
[!ENDIF!]
[!ENDIF!]
[!ENDINDENT!][!//

/* Enable multicore core synchronization feature. */
#define FLS_MCORE_ENABLED                    ([!IF "AutosarExt/FlsMCoreEnable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!IF "AutosarExt/FlsMCoreEnable = 'true'"!]    
/* SEMA4 used for external memory operations. */
#define FLS_MCORE_SEMA4_QJOB                 ([!"num:inttohex(AutosarExt/FlsMCoreQJobSemaphoreChannelNo)"!]UL)
[!ENDIF!]



/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

[!ENDINDENT!][!//
[!ENDCODE!][!//


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLS_CFG_DEFINES_H */
