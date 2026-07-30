/**
*   @file    Fr_43_LLCE.c
*   @version 1.0.7
*
*   @brief   AUTOSAR Fr_43_LLCE - module interface
*   @details API implementation for Fr driver.
*   @implements Fr.c_Artifact
*
*   @addtogroup FR_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LLCE
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.7
*   Build Version        : S32_RTD_1_0_7_D2909_ASR_REL_4_4_REV_0000_20230630
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


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fr_43_LLCE.h"  /* Include FlexRay driver header file */
#include "Fr_43_LLCE_Ipw.h"
#if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DEM_H
  #include "Dem.h" /* Include DEM header file */
#endif
#endif /* FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS */
#include "Det.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define FR_43_LLCE_VENDOR_ID_C                        43
#define FR_43_LLCE_AR_RELEASE_MAJOR_VERSION_C         4
#define FR_43_LLCE_AR_RELEASE_MINOR_VERSION_C         4
#define FR_43_LLCE_AR_RELEASE_REVISION_VERSION_C      0
#define FR_43_LLCE_SW_MAJOR_VERSION_C                 1
#define FR_43_LLCE_SW_MINOR_VERSION_C                 0
#define FR_43_LLCE_SW_PATCH_VERSION_C                 7

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_43_LLCE.h header file are of the same vendor */
#if (FR_43_LLCE_VENDOR_ID_C != FR_43_LLCE_VENDOR_ID)
    #error "Fr_43_LLCE.c and Fr_43_LLCE.h have different Vendor IDs"
#endif
/* Check if current file and Fr_43_LLCE.h header file are of the same Autosar version */
#if ((FR_43_LLCE_AR_RELEASE_MAJOR_VERSION_C != FR_43_LLCE_AR_RELEASE_MAJOR_VERSION) || \
     (FR_43_LLCE_AR_RELEASE_MINOR_VERSION_C != FR_43_LLCE_AR_RELEASE_MINOR_VERSION) || \
     (FR_43_LLCE_AR_RELEASE_REVISION_VERSION_C != FR_43_LLCE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fr_43_LLCE.c and Fr_43_LLCE.h are different"
#endif
/* Check if current file and Fr_43_LLCE.h header file are of the same Software version */
#if ((FR_43_LLCE_SW_MAJOR_VERSION_C != FR_43_LLCE_SW_MAJOR_VERSION) || \
     (FR_43_LLCE_SW_MINOR_VERSION_C != FR_43_LLCE_SW_MINOR_VERSION) || \
     (FR_43_LLCE_SW_PATCH_VERSION_C != FR_43_LLCE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fr_43_LLCE.c and Fr_43_LLCE.h are different"
#endif

/* Check if current file and Fr_43_LLCE_Ipw.h header file are of the same vendor */
#if (FR_43_LLCE_VENDOR_ID_C != FR_43_LLCE_IPW_VENDOR_ID)
    #error "Fr_43_LLCE.c and Fr_43_LLCE_Ipw.h have different Vendor IDs"
#endif
/* Check if current file and Fr_43_LLCE_Ipw.h header file are of the same Autosar version */
#if ((FR_43_LLCE_AR_RELEASE_MAJOR_VERSION_C    != FR_43_LLCE_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (FR_43_LLCE_AR_RELEASE_MINOR_VERSION_C    != FR_43_LLCE_IPW_AR_RELEASE_MINOR_VERSION) || \
     (FR_43_LLCE_AR_RELEASE_REVISION_VERSION_C != FR_43_LLCE_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fr_43_LLCE.c and Fr_43_LLCE_Ipw.h are different"
#endif
/* Check if current file and Fr_43_LLCE_Ipw.h header file are of the same Software version */
#if ((FR_43_LLCE_SW_MAJOR_VERSION_C != FR_43_LLCE_IPW_SW_MAJOR_VERSION) || \
     (FR_43_LLCE_SW_MINOR_VERSION_C != FR_43_LLCE_IPW_SW_MINOR_VERSION) || \
     (FR_43_LLCE_SW_PATCH_VERSION_C != FR_43_LLCE_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fr_43_LLCE.c and Fr_43_LLCE_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if current file and Dem.h header file are of the same Autosar version */
        #if ((FR_43_LLCE_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
             (FR_43_LLCE_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Fr_43_LLCE.c and Dem.h are different"
        #endif
    #endif /* FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS */

    /* Check if current file and Det.h header file are of the same Autosar version */
    #if ((FR_43_LLCE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (FR_43_LLCE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fr_43_LLCE.c and Det.h are different"
    #endif

    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((FR_43_LLCE_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FR_43_LLCE_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
         )
        #error "AutoSar Version Numbers of Fr_43_LLCE.c and Mcal.h are different"
    #endif

#endif /* CHECK_AUTOSAR_VERSION */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#if STD_ON == FR_43_LLCE_MULTICORE_ENABLED
    #define Fr_43_LLCE_GetCoreID()        (uint32)OsIf_GetCoreID()
#else
    #define Fr_43_LLCE_GetCoreID()        (uint32)0UL
#endif

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define FR_43_LLCE_START_SEC_VAR_CLEARED_8
#include "Fr_43_LLCE_MemMap.h"
#if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
/* Arrays used for storage information how many absolute timers have been
   configured in a certain CC (0 - no timer configured) */
static uint8 Fr_43_LLCE_au8AbsoluteTimersNum[FR_43_LLCE_NUM_CTRL_SUPPORTED];
#endif
#define FR_43_LLCE_STOP_SEC_VAR_CLEARED_8
#include "Fr_43_LLCE_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define FR_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fr_43_LLCE_MemMap.h"

#if (FR_43_LLCE_VARIANT_PRECOMPILE == STD_ON)
extern const Fr_43_LLCE_ConfigurationType* Fr_43_LLCE_PBCfgVariantPredefined[FR_43_LLCE_ECUC_PARTITION];
#endif /* (FR_43_LLCE_VARIANT_PRECOMPILE) */

#define FR_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fr_43_LLCE_MemMap.h"

#define FR_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fr_43_LLCE_MemMap.h"

/* Pointer to configuration structure */
FR_43_LLCE_apInternalCfg

#if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
/* Driver states variable */
FR_43_LLCE_aeDriverStates
#endif

#define FR_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fr_43_LLCE_MemMap.h"

#define FR_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
#include "Fr_43_LLCE_MemMap.h"
/* The Flexray controller state */
FR_43_LLCE_abCCActive
#define FR_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Fr_43_LLCE_MemMap.h"

#define FR_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
#include "Fr_43_LLCE_MemMap.h"
/* The permission for enabling FR module */
FR_43_LLCE_abModuleEnablePermission
#define FR_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
#include "Fr_43_LLCE_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static void Fr_43_LLCE_Dem_SetEventStatus(uint8 Fr_43_LLCE_CtrlIdx,
                                                  Dem_EventStatusType u16StatusMask
                                                 );
#endif

#if (FR_43_LLCE_RECONFIG_LPDU_SUPPORT == STD_ON)
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        static Std_ReturnType Fr_43_LLCE_ValidateReconfigLPdu(uint8 Fr_43_LLCE_CtrlIdx,
                                                                      uint16 Fr_43_LLCE_LPduIdx,
                                                                      uint16 Fr_43_LLCE_FrameId,
                                                                      Fr_ChannelType Fr_43_LLCE_ChnlIdx,
                                                                      uint8 Fr_43_LLCE_CycleRepetition,
                                                                      uint8 Fr_43_LLCE_CycleOffset,
                                                                      uint8 Fr_43_LLCE_PayloadLength,
                                                                      uint16 Fr_43_LLCE_HeaderCrc
                                                                     );
    #endif
#endif

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

#if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/***************************************************************************************************
* @function_name    Fr_43_LLCE_Dem_SetEventStatus
*
* @brief            Check and report Det error status.
* @param[in]        Fr_43_LLCE_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
*                   u16StatusMask Status macro of DEM report.
***************************************************************************************************/

static void Fr_43_LLCE_Dem_SetEventStatus(uint8 Fr_43_LLCE_CtrlIdx,
                                                  Dem_EventStatusType u16StatusMask
                                                 )
{
    Dem_EventIdType FR_43_LLCE_E_CTRL_TESTRESULT;
    uint32 u32CoreId;
    
    u32CoreId = Fr_43_LLCE_GetCoreID();
    if ((uint32)STD_ON == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->FrDemCtrlTestResultPtr->state)
    {
        FR_43_LLCE_E_CTRL_TESTRESULT = (Dem_EventIdType)Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->FrDemCtrlTestResultPtr->id;
        (void)Dem_SetEventStatus(FR_43_LLCE_E_CTRL_TESTRESULT, u16StatusMask);
    }
}

#endif

#if (FR_43_LLCE_RECONFIG_LPDU_SUPPORT == STD_ON)
#if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_43_LLCE_ValidateReconfigLPdu
*
* @brief            This function validates parameter.
* @param[in]        Fr_43_LLCE_CtrlIdx          Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_43_LLCE_LPduIdx          This index is used to uniquely identify a FlexRay frame
* @param[in]        Fr_43_LLCE_FrameId          FlexRay Frame ID the FrIf_LPdu shall be configured to
* @param[in]        Fr_43_LLCE_ChnlIdx          FlexRay Channel the FrIf_LPdu shall be configured to
* @param[in]        Fr_43_LLCE_CycleRepetition  Cycle Repetition part of the cycle filter mechanism
*                                       FrIf_LPdu shall be configured to.
* @param[in]        Fr_43_LLCE_CycleOffset      Cycle Offset part of the cycle filter mechanism FrIf_LPdu shall
*                                       be configured to.
* @param[in]        Fr_43_LLCE_PayloadLength    Payloadlength in units of bytes the FrIf_LPduIdx shall be
*                                       configured to.
* @param[in]        Fr_43_LLCE_HeaderCrc Header CRC the FrIf_LPdu shall be configured to.
* @return           Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
static Std_ReturnType Fr_43_LLCE_ValidateReconfigLPdu(uint8 Fr_43_LLCE_CtrlIdx,
                                                              uint16 Fr_43_LLCE_LPduIdx,
                                                              uint16 Fr_43_LLCE_FrameId,
                                                              Fr_ChannelType Fr_43_LLCE_ChnlIdx,
                                                              uint8 Fr_43_LLCE_CycleRepetition,
                                                              uint8 Fr_43_LLCE_CycleOffset,
                                                              uint8 Fr_43_LLCE_PayloadLength,
                                                              uint16 Fr_43_LLCE_HeaderCrc
                                                             )
{
    Std_ReturnType ValidateReturnValue_37 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;
    uint8 u8ChBool = 0U;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8,FR_43_LLCE_SID_RECONFIGLPDU_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
    }
    else
    {
        if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
        {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECONFIGLPDU_U8, FR_43_LLCE_E_INV_CTRL_IDX);
        }
        else
        {
            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECONFIGLPDU_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                if (Fr_43_LLCE_LPduIdx > (Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduConfiguredCount - 1U))
                {
                    /* Fr_43_LLCE_LPduIdx has an invalid value */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECONFIGLPDU_U8, FR_43_LLCE_E_INV_LPDU_IDX);
                }
                else
                {   /* creating the Channels mcal variable from sdk's booleans, to match enum vals. also, assume single ch is enabled if it is not 0x3U */
                    u8ChBool = Fr_43_LLCE_Ipw_GetgChannel(Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]);

                    if ((0x3U != u8ChBool) && ((uint8)Fr_43_LLCE_ChnlIdx != u8ChBool))
                    {
                        /* Fr_43_LLCE_ChnlIdx has an invalid value */
                        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECONFIGLPDU_U8, FR_43_LLCE_E_INV_CHNL_IDX);
                    }
                    else
                    {
                        if ((Fr_43_LLCE_CycleRepetition != 1U) && (Fr_43_LLCE_CycleRepetition != 2U)  && (Fr_43_LLCE_CycleRepetition != 4U)
                                                       && (Fr_43_LLCE_CycleRepetition != 8U)  && (Fr_43_LLCE_CycleRepetition != 16U)
                                                       && (Fr_43_LLCE_CycleRepetition != 32U) && (Fr_43_LLCE_CycleRepetition != 64U)
                          )
                        {
                            /* Fr_43_LLCE_CycleRepetition has an invalid value */
                            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECONFIGLPDU_U8, FR_43_LLCE_E_INV_CYCLE);
                        }
                        else
                        {
                            if (Fr_43_LLCE_CycleOffset > (Fr_43_LLCE_CycleRepetition - 1U))
                            {
                                /* Fr_43_LLCE_CycleOffset has an invalid value */
                                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECONFIGLPDU_U8, FR_43_LLCE_E_INV_CYCLE);
                            }
                            else
                            {
                                if ((Fr_43_LLCE_FrameId <= Fr_43_LLCE_Ipw_GetgNumberOfStaticSlots(Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]))
                                && (Fr_43_LLCE_PayloadLength != Fr_43_LLCE_Ipw_GetgPayloadLengthStatic(Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])))
                                {
                                    /* Fr_43_LLCE_PayloadLength has an invalid value for static segment */
                                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECONFIGLPDU_U8, FR_43_LLCE_E_INV_LENGTH);
                                }
                                else
                                {
                                    if (Fr_43_LLCE_HeaderCrc > 2047U)
                                    {
                                        /* Fr_43_LLCE_HeaderCrc has an invalid value for static segment */
                                        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECONFIGLPDU_U8, FR_43_LLCE_E_INV_HEADERCRC);

                                    }
                                    else
                                    {
                                        ValidateReturnValue_37 = (Std_ReturnType)(E_OK);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ValidateReturnValue_37;
}
#endif
#endif

#if (FR_43_LLCE_VERSION_INFO_API == STD_ON)
/***************************************************************************************************
* @function_name    Fr_43_LLCE_GetVersionInfo
*
* @brief            Software module version query.
*
* @implements       Fr_GetVersionInfo_Activity
***************************************************************************************************/
void Fr_43_LLCE_GetVersionInfo (Std_VersionInfoType* VersionInfoPtr)
{
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (NULL_PTR == VersionInfoPtr)
    {
        /* If VersionInfoPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8,FR_43_LLCE_SID_GETVERSIONINFO_U8,
                                                                                  FR_43_LLCE_E_PARAM_POINTER);
    }
    else /* No error yet -> execute the following code */
    {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
        VersionInfoPtr->moduleID = (uint16)FR_43_LLCE_MODULE_ID;
        VersionInfoPtr->vendorID = (uint16)FR_43_LLCE_VENDOR_ID;
        VersionInfoPtr->sw_major_version = (uint8)FR_43_LLCE_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)FR_43_LLCE_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)FR_43_LLCE_SW_PATCH_VERSION;
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

    return;
}
#endif /* FR_43_LLCE_VERSION_INFO_API == STD_ON */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_Init
*
* @brief            Initializes the Fr_43_LLCE.
*
* @implements       Fr_Init_Activity
***************************************************************************************************/
void Fr_43_LLCE_Init(const Fr_43_LLCE_ConfigType* Fr_43_LLCE_ConfigPtr)
{
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    uint8 u8CtrlIndex = 0U;
    #endif
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Check state of FR_43_LLCE_aeDriverStates */
    if (FR_43_LLCE_STATE_UNINIT == Fr_43_LLCE_aeDriverStates[u32CoreId])
    {
        #if (FR_43_LLCE_VARIANT_PRECOMPILE == STD_OFF)
        if (NULL_PTR == Fr_43_LLCE_ConfigPtr)
        #else
        if (NULL_PTR != Fr_43_LLCE_ConfigPtr)
        #endif /* FR_43_LLCE_VARIANT_PRECOMPILE */
        {
            /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
            /* If Fr_43_LLCE_ConfigPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
            /* to the DET and the API function shall return. */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_INIT_U8, FR_43_LLCE_E_PARAM_POINTER);
        }
        else
        {
            #if (FR_43_LLCE_VARIANT_PRECOMPILE == STD_OFF)
            MCAL_FAULT_INJECTION_POINT(FR_43_LLCE_FIP_1_FRINIT);
            if (u32CoreId != ((const Fr_43_LLCE_ConfigurationType*) Fr_43_LLCE_ConfigPtr)->u32ParCoreId)
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_INIT_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
            #endif /* FR_43_LLCE_VARIANT_PRECOMPILE */
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                #if (FR_43_LLCE_VARIANT_PRECOMPILE == STD_OFF)
                Fr_43_LLCE_apInternalCfg[u32CoreId] = (const Fr_43_LLCE_ConfigurationType*) Fr_43_LLCE_ConfigPtr;
                #else
                Fr_43_LLCE_apInternalCfg[u32CoreId] = Fr_43_LLCE_PBCfgVariantPredefined[u32CoreId];
                (void) Fr_43_LLCE_ConfigPtr;
                #endif /* FR_43_LLCE_VARIANT_PRECOMPILE */

                #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                for (u8CtrlIndex = 0U ; u8CtrlIndex<FR_43_LLCE_NUM_CTRL_SUPPORTED ; u8CtrlIndex++)
                {
                    if (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[u8CtrlIndex])
                    {
                        /* Store timers availability information */
                        /* Check whether the timer 2 can be configured as an absolute timer */
                        if (FALSE == Fr_43_LLCE_Ipw_Gettimer2IsRelative(Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[u8CtrlIndex]))
                        {
                            /* Timer 2 can be configured as an absolute timer -> Fr_43_LLCE_AbsTimerIdx = 1 */
                            Fr_43_LLCE_au8AbsoluteTimersNum[u8CtrlIndex] = 2U;    /* Two absolute timers are configured */
                            /* Check whether at least the timer 1 can be configured as an absolute timer */
                        }
                        else
                        {
                            /* Timer 1 can be configured as an absolute timer -> Fr_43_LLCE_AbsTimerIdx = 0 */
                            Fr_43_LLCE_au8AbsoluteTimersNum[u8CtrlIndex] = 1U;    /* One absolute timer is configured */
                        }
                    }
                }
                /* Successful initialization done store for other API functions to check for proper module initialization */
                Fr_43_LLCE_aeDriverStates[u32CoreId] = FR_43_LLCE_STATE_INIT;
                #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
                MCAL_FAULT_INJECTION_POINT(FR_43_LLCE_FIP_2_FRINIT);
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            #if (FR_43_LLCE_VARIANT_PRECOMPILE == STD_OFF)
            }
            #endif
        }
    }
    else
    {
        #if (FR_43_LLCE_DEINIT_API == STD_ON)
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8,FR_43_LLCE_SID_INIT_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        #endif /* FR_43_LLCE_DEINIT_API */
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_ControllerInit
*
* @brief            CC configuration
*
* @implements       Fr_ControllerInit_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_ControllerInit(uint8 Fr_43_LLCE_CtrlIdx)
{
    /* Set initial return value */
    Std_ReturnType returnValue_0 = (Std_ReturnType)(E_NOT_OK);
    #if (FR_43_LLCE_CTRL_TEST_COUNT > 0U)
    uint8 u8i_0;
    boolean bCtrlTest = FALSE;
    #endif
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
#if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
    {
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8,FR_43_LLCE_SID_CONTROLLERINIT_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
    }
    else if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx)  /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8,FR_43_LLCE_SID_CONTROLLERINIT_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
    {
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CONTROLLERINIT_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
    }
    else
    {
#else
    if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId))
    {
#endif /* FR_43_LLCE_DEV_ERROR_DETECT */
		const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, FALSE))
        {/* CC is not accessible, report error */
            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
            #endif
        }
        else
        {
            /* Initialize FlexRay CC */
            if (TRUE == Fr_43_LLCE_abModuleEnablePermission[u32CoreId])
            {
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_ControllerInit(pCtrlCfg))
                {
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                } else
                {
                    #if (FR_43_LLCE_CC_ONCE_ENABLEONLYMODE == STD_ON)
                    /* Only one correct initialization of FR CC is allowed */
                    /* Disable permission for enabling FR Module */
                    Fr_43_LLCE_abModuleEnablePermission[u32CoreId] = FALSE;
                    #endif
                    Fr_43_LLCE_Ipw_DisableTimers(pCtrlCfg);
                    #if (FR_43_LLCE_CTRL_TEST_COUNT > 0U)
                    /* CC Configuration Test */
                    for (u8i_0 = 0U; u8i_0 < FR_43_LLCE_CTRL_TEST_COUNT; u8i_0++)
                    {
                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_ReadbackCCConfig(pCtrlCfg))
                        {
                            bCtrlTest = TRUE;
                            break;
                        }
                    }
                    if (FALSE == bCtrlTest)
                    {
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {
                    #endif
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_PASSED);
                        #endif
                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_ClearDisableIRQs(pCtrlCfg))
                        {
                            returnValue_0 = (Std_ReturnType)(E_OK);
                            /* This controller is activated */
                            Fr_43_LLCE_abCCActive[Fr_43_LLCE_CtrlIdx] = TRUE;
                        }
                    #if (FR_43_LLCE_CTRL_TEST_COUNT > 0U)
                    }
                    #endif
                }
            }
            else
            {
                /*do nothing*/
            }
        }
    }
    return returnValue_0;
}


/***************************************************************************************************
* @function_name    Fr_43_LLCE_StartCommunication
*
* @brief            Starts communication.
*
* @implements       Fr_StartCommunication_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_StartCommunication (uint8 Fr_43_LLCE_CtrlIdx)
{
    /* Set initial return value */
    Std_ReturnType returnValue_3 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;
    Fr_POCStateType u16tmpPOCState_3;

    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    u32CoreId = Fr_43_LLCE_GetCoreID();
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_STARTCOMMUNICATION_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_STARTCOMMUNICATION_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {

            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_STARTCOMMUNICATION_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                /* CC is not accessible, report error */
                #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                #endif
                }
    #else  /* FR_43_LLCE_DEV_ERROR_DETECT == STD_OFF */
            u32CoreId = Fr_43_LLCE_GetCoreID();
            if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]))
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
                else
                {
                    /* Determine the POC state */
                    u16tmpPOCState_3 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);
                    /* Check whether the CC is in the POC:ready */
                    if (FR_POCSTATE_READY != u16tmpPOCState_3)
                    {   /* The CC is not in the POC:ready */
                        (void)Det_ReportRuntimeError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_STARTCOMMUNICATION_U8, FR_43_LLCE_E_INV_POCSTATE);
                    }
                    else
                    {   /* The CC is in the POC:ready */
                        /* Invoke CHI command RUN */
                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_InvokeCHICommand(pCtrlCfg, FLEXRAY_CHI_CMD_RUN))
                        {
                            /* API call was successful */
                            returnValue_3 = (Std_ReturnType)(E_OK);
                        }
                        else
                        {
                            /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                            /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                        }
                    }
                }
            }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif  /* FR_43_LLCE_DEV_ERROR_DETECT == STD_ON */
    return returnValue_3;        /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_AllowColdstart
*
* @brief            Invokes the CC CHI command ALLOW_COLDSTART
*
* @implements       Fr_AllowColdstart_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_AllowColdstart(uint8 Fr_43_LLCE_CtrlIdx)
{
    /* Set initial return value */
    Std_ReturnType returnValue_35 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;
    Fr_POCStateType u16tmpPOCState_35;

    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    u32CoreId = Fr_43_LLCE_GetCoreID();
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ALLOWCOLDSTART_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ALLOWCOLDSTART_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);  /* Report error */
        }
        else
        {

            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ALLOWCOLDSTART_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
    #else   /* FR_43_LLCE_DEV_ERROR_DETECT == STD_OFF */
            u32CoreId = Fr_43_LLCE_GetCoreID();
            if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]))
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
    #endif  /* FR_43_LLCE_DEV_ERROR_DETECT */
                else
                {
                    /* Determine the POC state */
                    u16tmpPOCState_35 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);
                    /* Check whether the CC is not in POC:default config, POC:config or POC:halt */
                    if ((FR_POCSTATE_DEFAULT_CONFIG == u16tmpPOCState_35) || (FR_POCSTATE_CONFIG == u16tmpPOCState_35) || (FR_POCSTATE_HALT == u16tmpPOCState_35))
                    {
                        /* The CC is in POC:default config or POC:config or POC:halt */
                        (void)Det_ReportRuntimeError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ALLOWCOLDSTART_U8, FR_43_LLCE_E_INV_POCSTATE);
                    }
                    else  /* CC is in required state */
                    {
                        /* Invoke CHI command ALLOW_COLDSTART and wait till Protocol Command Write is not busy*/
                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_InvokeCHICommand(pCtrlCfg, FLEXRAY_CHI_CMD_ALLOW_COLDSTART))
                        {
                            /* API call was successful */
                            returnValue_35 = (Std_ReturnType)(E_OK);
                        }
                        else
                        {
                            /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                            /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                        }
                    }
                }
            }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif  /* FR_43_LLCE_DEV_ERROR_DETECT == STD_ON */
    return returnValue_35;        /* Return the state of function execution */
} /* End of Fr_43_LLCE_AllowColdStart */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_AllSlots
*
* @brief            Invokes the CC CHI command ALL_SLOTS
*
* @implements       Fr_AllSlots_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_AllSlots(uint8 Fr_43_LLCE_CtrlIdx)
{
    /* Set initial return value */
    Std_ReturnType returnValue_36 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;
    Fr_POCStateType u16tmpPOCState_36;

    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    u32CoreId = Fr_43_LLCE_GetCoreID();
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ALLSLOTS_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ALLSLOTS_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ALLSLOTS_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
    #else  /* FR_43_LLCE_DEV_ERROR_DETECT == STD_OFF */
            u32CoreId = Fr_43_LLCE_GetCoreID();
            if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]))
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
    #endif  /* FR_43_LLCE_DEV_ERROR_DETECT */
                else
                {
                    /* Determine the POC state */
                    u16tmpPOCState_36 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);
                    /* The state of the PSR0 register (PROSTATE field) is not updated if FREEZE occurred */
                    /* Check whether the CC is synchronous to cluster */
                    if ((FR_POCSTATE_NORMAL_PASSIVE != u16tmpPOCState_36) && (FR_POCSTATE_NORMAL_ACTIVE != u16tmpPOCState_36))
                    {
                        /* The CC is in POC:default config or POC:config or POC:halt */
                        (void)Det_ReportRuntimeError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ALLSLOTS_U8, FR_43_LLCE_E_INV_POCSTATE);
                    }
                    else
                    {
                        /* Invoke CHI command ALL_SLOTS */
                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_InvokeCHICommand(pCtrlCfg, FLEXRAY_CHI_CMD_ALL_SLOTS))
                        {
                            /* API call was successful */
                            returnValue_36 = (Std_ReturnType)(E_OK);
                        }
                        else
                        {
                            /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                            /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                        }
                    }
                }
            }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif  /* FR_43_LLCE_DEV_ERROR_DETECT == STD_ON */
    return returnValue_36;        /* Return the state of function execution */
} /* End of Fr_43_LLCE_AllSlots */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_HaltCommunication
*
* @brief            Invokes the CC CHI command DEFERRED_HALT.
*
* @implements       Fr_HaltCommunication_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_HaltCommunication(uint8 Fr_43_LLCE_CtrlIdx)
{
    /* Set initial return value */
    Std_ReturnType returnValue_4 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;
    Fr_POCStateType u16tmpPOCState_4;

    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    u32CoreId = Fr_43_LLCE_GetCoreID();
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_HALTCOMMUNICATION_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_HALTCOMMUNICATION_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {

            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_HALTCOMMUNICATION_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
    #else /* FR_43_LLCE_DEV_ERROR_DETECT == STD_OFF */
            u32CoreId = Fr_43_LLCE_GetCoreID();
            if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]))
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
                else
                {
                    /* Determine the POC state */
                    u16tmpPOCState_4 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);

                    /* Check whether the CC is synchronous to cluster */
                    if ((FR_POCSTATE_NORMAL_PASSIVE != u16tmpPOCState_4) && (FR_POCSTATE_NORMAL_ACTIVE != u16tmpPOCState_4))
                    {/* The CC is not synchronized to the FlexRay global time */
                            /* If CC is not synchronized to the FlexRay global time, FR_43_LLCE_E_INV_POCSTATE shall be reported */
                            /* to the DET and the API function shall return. */
                            (void)Det_ReportRuntimeError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_HALTCOMMUNICATION_U8, FR_43_LLCE_E_INV_POCSTATE);
                    }
                    /* No error yet -> execute the following code */
                    else
                    {/* The CC is synchronized to the FlexRay global time */
                        /* Invoke CHI command HALT */
                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_InvokeCHICommand(pCtrlCfg, FLEXRAY_CHI_CMD_HALT))
                        {
                            /* API call was successful */
                            returnValue_4 = (Std_ReturnType)(E_OK);
                        }
                        else
                        {
                            /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                            /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                        }
                    }
                }
            }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_4;        /* Return the state of function execution */
} /* End of Fr_43_LLCE_HaltCommunication */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_AbortCommunication
*
* @brief            Invokes the CC CHI command FREEZE.
*
* @implements       Fr_AbortCommunication_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_AbortCommunication(uint8 Fr_43_LLCE_CtrlIdx)
{
    /* Set initial return value */
    Std_ReturnType returnValue_5 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ABORTCOMMUNICATION_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ABORTCOMMUNICATION_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ABORTCOMMUNICATION_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                   /* No error yet -> execute the following code */
    #else
            if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]))
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
                else
                {
                    /* Invoke CHI command FREEZE */
                    if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_InvokeCHICommand(pCtrlCfg, FLEXRAY_CHI_CMD_FREEZE))
                    {
                        /* API call was successful */
                        returnValue_5 = (Std_ReturnType)(E_OK);
                    }
                    else
                    {
                        /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                        /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                    }
                }
            }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif
    return returnValue_5;        /* Return the state of function execution */
} /* End of Fr_43_LLCE_AbortCommunication */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_SendWUP
*
* @brief            Invokes the CC CHI command WAKEUP.
*
* @implements       Fr_SendWUP_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_SendWUP(uint8 Fr_43_LLCE_CtrlIdx)
{
    /* Set initial return value */
    Std_ReturnType returnValue_6 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;
    Fr_POCStateType u16tmpPOCState_6;

    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    u32CoreId = Fr_43_LLCE_GetCoreID();
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SENDWUP_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])  /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SENDWUP_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SENDWUP_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
    #else /* FR_43_LLCE_DEV_ERROR_DETECT == STD_OFF */
            u32CoreId = Fr_43_LLCE_GetCoreID();
            if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]))
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
                else
                {
                    /* Determine the POC state */
                    u16tmpPOCState_6 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);
                    /* The state of the PSR0 register (PROSTATE field) is not updated if FREEZE occurred */
                    /* Check whether the CC is in POC:ready */
                    if (FR_POCSTATE_READY != u16tmpPOCState_6)
                    {   /* The CC is not in POC:ready */
                        (void)Det_ReportRuntimeError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SENDWUP_U8, FR_43_LLCE_E_INV_POCSTATE);
                    }
                    else
                    {
                        /* Invoke CHI command WAKEUP */
                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_InvokeCHICommand(pCtrlCfg, FLEXRAY_CHI_CMD_WAKEUP))
                        {
                            /* API call was successful */
                            returnValue_6 = (Std_ReturnType)(E_OK);
                        }
                        else
                        {
                            /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                            /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                        }
                    }
                }
            }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_6;        /* Return the state of function execution */
} /* End of Fr_43_LLCE_SendWUP */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_SetWakeupChannel
*
* @brief            Selects which channel sends WUPs
*
* @implements       Fr_SetWakeupChannel_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_SetWakeupChannel(uint8 Fr_43_LLCE_CtrlIdx,
                                                   Fr_ChannelType Fr_43_LLCE_ChnlIdx
                                                  )
{
    /* Set initial return value */
    Std_ReturnType returnValue_7 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;
    Fr_POCStateType u16tmpPOCState_7;

    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    u32CoreId = Fr_43_LLCE_GetCoreID();
    if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        /* Report the error */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETWAKEUPCHANNEL_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
    }
    else
    {
        if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
        {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETWAKEUPCHANNEL_U8, FR_43_LLCE_E_INV_CTRL_IDX);
        }
        else
        {
            if ((FR_CHANNEL_A != Fr_43_LLCE_ChnlIdx) && (FR_CHANNEL_B != Fr_43_LLCE_ChnlIdx))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETWAKEUPCHANNEL_U8, FR_43_LLCE_E_INV_CHNL_IDX);
            }
            else
            {
                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETWAKEUPCHANNEL_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                }
                else
                {
                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                    {
                        /* CC is not accessible, report error */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
    #else /* FR_43_LLCE_DEV_ERROR_DETECT == STD_OFF */
                u32CoreId = Fr_43_LLCE_GetCoreID();
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]))
                {
                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                    {
                        /* CC is not accessible, report error */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
                    else
                    {
                        /* Determine the POC state */
                        u16tmpPOCState_7 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);
                        /* Check whether the CC is in POC:ready */
                        if (FR_POCSTATE_READY != u16tmpPOCState_7)
                        {   /* The CC is not in POC:ready */
                            (void)Det_ReportRuntimeError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETWAKEUPCHANNEL_U8, FR_43_LLCE_E_INV_POCSTATE);
                        }
                        else
                        {
                            /* Call LLD function to set the Wakeup channel */
                            if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_SetWakeupChannel(pCtrlCfg, Fr_43_LLCE_ChnlIdx))
                            {
                                returnValue_7 = (Std_ReturnType)(E_OK);
                            }
                            else
                            {
                                /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                                #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                    Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                                /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                            }
                        }
                    }
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_7;        /* Return the state of function execution */
} /* End of Fr_43_LLCE_SetWakeupChannel */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_GetPOCStatus
*
* @brief            Gets the POC status.
*
* @implements       Fr_GetPOCStatus_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_GetPOCStatus(uint8 Fr_43_LLCE_CtrlIdx,
                                               Fr_POCStatusType* Fr_43_LLCE_POCStatusPtr
                                              )
{
    /* Set initial return value */
    Std_ReturnType returnValue_10 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETPOCSTATUS_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
    }
    else
    {
        if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx)              /* Check the Fr_43_LLCE_CtrlIdx value */
        {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETPOCSTATUS_U8, FR_43_LLCE_E_INV_CTRL_IDX);
        }
        else
        {
            if (NULL_PTR == Fr_43_LLCE_POCStatusPtr)
            {
                /* If Fr_43_LLCE_SyncStatePtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                /* to the DET and the API function shall return. */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETPOCSTATUS_U8, FR_43_LLCE_E_PARAM_POINTER);
            }
            else /* No error yet -> execute the following code */
            {
                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETPOCSTATUS_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) &&(NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                    {
                        /* CC is not accessible, report error */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {
                        returnValue_10 = Fr_43_LLCE_Ipw_GetPOCStatus(pCtrlCfg, Fr_43_LLCE_POCStatusPtr);

                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        /* HW issue detected, Report error */
                        if ((Std_ReturnType)(E_NOT_OK) == returnValue_10)
                        {
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        }
                        #endif
                    }
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_10;        /* Return the state of function execution */
} /* End of Fr_43_LLCE_GetPOCStatus */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_GetGlobalTime
*
* @brief            Gets the current global FlexRay time.
*
* @implements       Fr_GetGlobalTime_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_GetGlobalTime(uint8 Fr_43_LLCE_CtrlIdx,
                                                uint8* Fr_43_LLCE_CyclePtr,
                                                uint16* Fr_43_LLCE_MacroTickPtr
                                               )
{
    /* Set initial return value */
    Std_ReturnType returnValue_16 = (Std_ReturnType)(E_NOT_OK);
    Fr_POCStateType u16tmpPOCState_16;
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETGLOBALTIME_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETGLOBALTIME_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_43_LLCE_CyclePtr)
            {
                /* If Fr_43_LLCE_CyclePtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                /* to the DET and the API function shall return. */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETGLOBALTIME_U8, FR_43_LLCE_E_PARAM_POINTER);
            }
            else
            {
                if (NULL_PTR == Fr_43_LLCE_MacroTickPtr)
                {
                    /* If Fr_43_LLCE_MacroTickPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETGLOBALTIME_U8, FR_43_LLCE_E_PARAM_POINTER);
                }
                else
                {
                    if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                    {
                        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETGLOBALTIME_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                    }
                    else
                    {
    #else
                    if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) &&(NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                    {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                        const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                        {
                            /* CC is not accessible, report error */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else
                        {

                            /* Determine the POC state */
                            u16tmpPOCState_16 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);
                            /* The state of the PSR0 register (PROSTATE field) is not updated if FREEZE occurred */
                            /* Check whether the CC is synchronous to cluster */
                            if ((FR_POCSTATE_NORMAL_PASSIVE == u16tmpPOCState_16) || (FR_POCSTATE_NORMAL_ACTIVE == u16tmpPOCState_16))
                            {/* The CC is synchronized to the FlexRay global time */
                                /* Call LLD function to get Cycle and Macrotick */
                                returnValue_16 = Fr_43_LLCE_Ipw_GetGlobalTime(pCtrlCfg, Fr_43_LLCE_CyclePtr, Fr_43_LLCE_MacroTickPtr);

                                /* HW issue detected, Report error */
                                #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                if ((Std_ReturnType)(E_NOT_OK) == returnValue_16)
                                {
                                    Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                }
                                #endif
                            }
                        }
                    }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

    return returnValue_16;        /* Return the state of function execution */
} /* End of Fr_43_LLCE_GetGlobalTime */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_SetAbsoluteTimer
*
* @brief            Sets the absolute FlexRay timer.
*
* @implements       Fr_SetAbsoluteTimer_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_SetAbsoluteTimer(uint8 Fr_43_LLCE_CtrlIdx,
                                                   uint8 Fr_43_LLCE_AbsTimerIdx,
                                                   uint8 Fr_43_LLCE_Cycle,
                                                   uint16 Fr_43_LLCE_Offset
                                                  )
{
    /* Set initial return value */
    Std_ReturnType returnValue_17 = (Std_ReturnType)(E_NOT_OK);
    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg;
    uint32 u32CoreId;
    Fr_POCStateType u16tmpPOCState_17;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];

    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx)       /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETABSTIMER_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETABSTIMER_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (!(Fr_43_LLCE_AbsTimerIdx < Fr_43_LLCE_au8AbsoluteTimersNum[Fr_43_LLCE_CtrlIdx])) /* Check the Fr_43_LLCE_AbsTimerIdx value */
            {   /* An attempt to configure an invalid timer, Fr_43_LLCE_AbsTimerIdx has an invalid value */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETABSTIMER_U8, FR_43_LLCE_E_INV_TIMER_IDX);
            }
            else
            {
                if (Fr_43_LLCE_Cycle > 63U) /* Check the Fr_43_LLCE_Cycle value, max. cycle no. 63 */
                {   /* An attempt to configure timer for invalid cycle number, Fr_43_LLCE_Cycle has an invalid value */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETABSTIMER_U8, FR_43_LLCE_E_INV_CYCLE);
                }
                /* Compare Fr_43_LLCE_Offset value with maximum gMacroPerCycle from configuration,
                   the absolute timer shall elapsed at */
                else
                {
                    if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                    {
                        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETABSTIMER_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                    }
                    else
                    {
                        /* An attempt to configure timer for invalid macrotick offset number, Fr_43_LLCE_Offset has an invalid value */

                        if (Fr_43_LLCE_Offset >= (((uint16)(Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LowLevelConfigSetPtr->RegPCR10_11 >> 16U)) & 0x3FFFU))
                        {
                            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETABSTIMER_U8, FR_43_LLCE_E_INV_OFFSET);
                        }
                        else

                        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                        {
                            /* CC is not accessible, report error */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
    #else /* FR_43_LLCE_DEV_ERROR_DETECT == STD_OFF */
                    if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                        && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                    {
                        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                        {
                            /* CC is not accessible, report error */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
                        else
                        {
                            /* Determine the POC state */
                            u16tmpPOCState_17 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);
                            /* Check whether the CC is synchronous to cluster */
                            if ((FR_POCSTATE_NORMAL_PASSIVE != u16tmpPOCState_17) && (FR_POCSTATE_NORMAL_ACTIVE != u16tmpPOCState_17))
                            {   /* The CC is not synchronized to the cluster */
                                (void)Det_ReportRuntimeError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_SETABSTIMER_U8, FR_43_LLCE_E_INV_POCSTATE);
                            }
                            else
                            {   /* The CC is synchronized to the cluster */
                                /* Call LLD function to set the Absolute Timer */
                                Fr_43_LLCE_Ipw_SetAbsoluteTimer(pCtrlCfg, Fr_43_LLCE_AbsTimerIdx, Fr_43_LLCE_Cycle, Fr_43_LLCE_Offset);
                                /* API call was successful */
                                returnValue_17 = (Std_ReturnType)(E_OK);
                            }
                        }
                    }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT == STD_ON */

    return returnValue_17;    /* Return the state of function execution */
}/* End of Fr_43_LLCE_SetAbsoluteTimer */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_CancelAbsoluteTimer
*
* @brief            Stops an absolute timer.
*
* @implements       Fr_CancelAbsoluteTimer_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_CancelAbsoluteTimer(uint8 Fr_43_LLCE_CtrlIdx,
                                                      uint8 Fr_43_LLCE_AbsTimerIdx
                                                     )
{
    /* Set initial return value */
    Std_ReturnType returnValue_19 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC,Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CANCELABSTIMER_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CANCELABSTIMER_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (!(Fr_43_LLCE_AbsTimerIdx < Fr_43_LLCE_au8AbsoluteTimersNum[Fr_43_LLCE_CtrlIdx])) /* Check the Fr_43_LLCE_AbsTimerIdx value */
            {   /* An attempt to configure an invalid timer, Fr_43_LLCE_AbsTimerIdx has an invalid value */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CANCELABSTIMER_U8, FR_43_LLCE_E_INV_TIMER_IDX);
            }
            else    /* No error yet -> execute the following code */
            {
                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CANCELABSTIMER_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                    && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                    {
                        /* CC is not accessible, report error */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {   /* Call LLD function to cancel the Absolute Timer */
                        Fr_43_LLCE_Ipw_CancelAbsoluteTimer(pCtrlCfg, Fr_43_LLCE_AbsTimerIdx);
                        returnValue_19 = (Std_ReturnType)(E_OK);    /* API call was successful */
                    } /* CC access check */
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_19;    /* Return the state of function execution */
}/* End of Fr_43_LLCE_CancelAbsoluteTimer */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_EnableAbsoluteTimerIRQ
*
* @brief            Enables the interrupt line of an absolute timer.
*
* @implements       Fr_EnableAbsoluteTimerIRQ_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_EnableAbsoluteTimerIRQ(uint8 Fr_43_LLCE_CtrlIdx,
                                                         uint8 Fr_43_LLCE_AbsTimerIdx
                                                        )
{
    /* Set initial return value */
    Std_ReturnType returnValue_21 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx)                 /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ENABLEABSTIMERIRQ_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])      /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ENABLEABSTIMERIRQ_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (!(Fr_43_LLCE_AbsTimerIdx < Fr_43_LLCE_au8AbsoluteTimersNum[Fr_43_LLCE_CtrlIdx]))/* Check the Fr_43_LLCE_AbsTimerIdx value */
            {   /* An attempt to configure an invalid timer, Fr_43_LLCE_AbsTimerIdx has an invalid value */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ENABLEABSTIMERIRQ_U8, FR_43_LLCE_E_INV_TIMER_IDX);
            }
            else
            {
                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ENABLEABSTIMERIRQ_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                    {
                        /* CC is not accessible, report error */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {
                        /* Call LLD function to enable the Absolute Timer */
                        Fr_43_LLCE_Ipw_EnableAbsoluteTimerIRQ(pCtrlCfg, Fr_43_LLCE_AbsTimerIdx);
                        returnValue_21 = (Std_ReturnType)(E_OK);    /* API call was successful */
                    }  /* CC access check */
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_21;    /* Return the state of function execution */
}/* End of Fr_43_LLCE_EnableAbsoluteTimerIRQ */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_AckAbsoluteTimerIRQ
*
* @brief            Resets the interrupt condition of an absolute timer.
*
* @implements       Fr_AckAbsoluteTimerIRQ_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_AckAbsoluteTimerIRQ(uint8 Fr_43_LLCE_CtrlIdx,
                                                      uint8 Fr_43_LLCE_AbsTimerIdx
                                                     )
{
    /* Set initial return value */
    Std_ReturnType returnValue_23 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ACKABSTIMERIRQ_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ACKABSTIMERIRQ_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (!(Fr_43_LLCE_AbsTimerIdx < Fr_43_LLCE_au8AbsoluteTimersNum[Fr_43_LLCE_CtrlIdx])) /* Check the Fr_43_LLCE_AbsTimerIdx value */
            {   /* An attempt to configure an invalid timer, Fr_43_LLCE_AbsTimerIdx has an invalid value */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ACKABSTIMERIRQ_U8, FR_43_LLCE_E_INV_TIMER_IDX);
            }
            else
            {
                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_ACKABSTIMERIRQ_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                    && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                    {
                        /* CC is not accessible, report error */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {
                        /* Call LLD function to ack the Absolute Timer */
                        Fr_43_LLCE_Ipw_AckAbsoluteTimerIRQ(pCtrlCfg, Fr_43_LLCE_AbsTimerIdx);

                        returnValue_23 = (Std_ReturnType)(E_OK);   /* API call was successful */
                    } /* CC access check */
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

    return returnValue_23;        /* Return the state of function execution */
}/* End of Fr_43_LLCE_AckAbsoluteTimerIRQ */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_DisableAbsoluteTimerIRQ
*
* @brief            Disables the interrupt line of an absolute timer.
*
* @implements       Fr_DisableAbsoluteTimerIRQ_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_DisableAbsoluteTimerIRQ(uint8 Fr_43_LLCE_CtrlIdx,
                                                          uint8 Fr_43_LLCE_AbsTimerIdx
                                                         )
{
    /* Set initial return value */
    Std_ReturnType returnValue_25 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_DISABLEABSTIMERIRQ_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_DISABLEABSTIMERIRQ_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (!(Fr_43_LLCE_AbsTimerIdx < Fr_43_LLCE_au8AbsoluteTimersNum[Fr_43_LLCE_CtrlIdx])) /* Check the Fr_43_LLCE_AbsTimerIdx value */
            {   /* An attempt to configure an invalid timer, Fr_43_LLCE_AbsTimerIdx has an invalid value */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_DISABLEABSTIMERIRQ_U8, FR_43_LLCE_E_INV_TIMER_IDX);
            }
            else
            {
                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_DISABLEABSTIMERIRQ_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                    && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                    {
                        /* CC is not accessible, report error */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {
                        /* Call LLD function to disable the Absolute Timer */
                        Fr_43_LLCE_Ipw_DisableAbsoluteTimerIRQ(pCtrlCfg, Fr_43_LLCE_AbsTimerIdx);

                        returnValue_25 = (Std_ReturnType)(E_OK); /* API call was successful */
                    } /* CC access check */
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_25;        /* Return the state of function execution */
} /* End of Fr_43_LLCE_DisableAbsoluteTimerIRQ */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_GetAbsoluteTimerIRQStatus
*
* @brief            Gets IRQ status of an absolute timer.
*
* @implements       Fr_GetAbsoluteTimerIRQStatus_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_GetAbsoluteTimerIRQStatus(uint8 Fr_43_LLCE_CtrlIdx,
                                                            uint8 Fr_43_LLCE_AbsTimerIdx,
                                                            boolean* Fr_43_LLCE_IRQStatusPtr
                                                           )
{
    /* Set initial return value */
    Std_ReturnType returnValue_32 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETABSTIMERIRQSTATUS_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETABSTIMERIRQSTATUS_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (!(Fr_43_LLCE_AbsTimerIdx < Fr_43_LLCE_au8AbsoluteTimersNum[Fr_43_LLCE_CtrlIdx])) /* Check the Fr_43_LLCE_AbsTimerIdx value */
            {   /* An attempt to configure an invalid timer, Fr_43_LLCE_AbsTimerIdx has an invalid value */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETABSTIMERIRQSTATUS_U8, FR_43_LLCE_E_INV_TIMER_IDX);
            }
            else
            {
                if (NULL_PTR == Fr_43_LLCE_IRQStatusPtr)
                {
                    /* If Fr_43_LLCE_IRQStatusPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETABSTIMERIRQSTATUS_U8, FR_43_LLCE_E_PARAM_POINTER);
                }
                else    /* No error yet -> execute the following code */
                {
                    if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                    {
                        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETABSTIMERIRQSTATUS_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                    }
                    else
                    {
    #else
                    if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                        && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                    {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                        const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                        {
                            /* CC is not accessible, report error */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else
                        {
                            /* Call LLD function to get Asolute Timer IRQ status */
                            *Fr_43_LLCE_IRQStatusPtr = Fr_43_LLCE_Ipw_GetAbsoluteTimerIRQStatus(pCtrlCfg, Fr_43_LLCE_AbsTimerIdx);

                            returnValue_32 = (Std_ReturnType)(E_OK); /* API call was successful */

                        } /* CC access check */
                    }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_32;        /* Return the state of function execution */
} /* End of Fr_43_LLCE_GetAbsoluteTimerIRQStatus */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_GetNmVector
*
* @brief            Gets the network management vector of the last communication cycle.
*
* @implements       Fr_GetNmVector_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_GetNmVector(uint8 Fr_43_LLCE_CtrlIdx,
                                              uint8* Fr_43_LLCE_NmVectorPtr
                                             )
{
    /* Set initial return value */
    Std_ReturnType returnValue_34 = (Std_ReturnType)(E_NOT_OK);
    Fr_POCStateType u16tmpPOCState_34;
    uint32 u32CoreId;
    boolean checkLen;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx)   /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETNMVECTOR_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])    /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETNMVECTOR_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_43_LLCE_NmVectorPtr)
            {
                /* If Fr_43_LLCE_NmVectorPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                /* to the DET and the API function shall return. */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETNMVECTOR_U8, FR_43_LLCE_E_PARAM_POINTER);
            }
            else
            {
                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETNMVECTOR_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                    && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                    {
                        /* CC is not accessible, report error */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {
                        u16tmpPOCState_34 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);
                        /* Check whether the CC is synchronous to cluster */
                        if ((FR_POCSTATE_NORMAL_PASSIVE == u16tmpPOCState_34) || (FR_POCSTATE_NORMAL_ACTIVE == u16tmpPOCState_34))
                        {/* The CC is in POC:Normal Active or POC:Normal Passive */
                            /* Read Network Management Vector */
                            returnValue_34 = Fr_43_LLCE_Ipw_GetNmVector(pCtrlCfg, Fr_43_LLCE_NmVectorPtr, &checkLen);
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            if (FALSE == checkLen)
                            {
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            }
                            #endif
                        }
                        else
                        {
                            /* The CC is not synchronous to the cluster */
                            /* Set error return value */
                            returnValue_34 = (Std_ReturnType)(E_NOT_OK);
                        }
                    }
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

    return returnValue_34;        /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_GetChannelStatus
*
* @brief            Gets the channel status information.
*
* @implements       Fr_GetChannelStatus_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_GetChannelStatus(uint8 Fr_43_LLCE_CtrlIdx,
                                                   uint16* Fr_43_LLCE_ChannelAStatusPtr,
                                                   uint16* Fr_43_LLCE_ChannelBStatusPtr
                                                  )
{
    /* Set initial return value */
    Std_ReturnType returnValue_40 = (Std_ReturnType)(E_NOT_OK);

    Fr_POCStateType u16tmpPOCState_40;
    uint32 u32CoreId;
    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx)   /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETCHANNELSTATUS_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])    /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETCHANNELSTATUS_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_43_LLCE_ChannelAStatusPtr)
            {
                /* If Fr_43_LLCE_ChannelAStatusPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                /* to the DET and the API function shall return. */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETCHANNELSTATUS_U8, FR_43_LLCE_E_PARAM_POINTER);
            }
            else
            {
                if (NULL_PTR == Fr_43_LLCE_ChannelBStatusPtr)
                {
                    /* If Fr_43_LLCE_ChannelBStatusPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETCHANNELSTATUS_U8, FR_43_LLCE_E_PARAM_POINTER);
                }
                else            /* No error yet -> execute the following code */
                {
                    if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                    {
                        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETCHANNELSTATUS_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                    }
                    else
                    {
    #else
                    if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                        && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                    {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                        const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                        {
                            /* CC is not accessible, report error */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else
                        {

                            u16tmpPOCState_40 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);
                            /* Check whether the CC is synchronous to cluster */
                            if ((FR_POCSTATE_NORMAL_PASSIVE == u16tmpPOCState_40) || (FR_POCSTATE_NORMAL_ACTIVE == u16tmpPOCState_40))
                            {
                                /* Read aggregated channel status, NIT staus and symbol window status */
                                Fr_43_LLCE_Ipw_GetChannelStatus(pCtrlCfg, Fr_43_LLCE_ChannelAStatusPtr, Fr_43_LLCE_ChannelBStatusPtr);
                                returnValue_40 = (Std_ReturnType)(E_OK);
                            }
                            else
                            {
                                returnValue_40 = (Std_ReturnType)(E_NOT_OK);
                            }
                        }
                    }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_40; /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_GetClockCorrection
*
* @brief            Gets the current clock correction values.
*
* @implements       Fr_GetClockCorrection_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_GetClockCorrection(uint8 Fr_43_LLCE_CtrlIdx,
                                                     sint16* Fr_43_LLCE_RateCorrectionPtr,
                                                     sint32* Fr_43_LLCE_OffsetCorrectionPtr
                                                    )
{
    /* Set initial return value */
    Std_ReturnType returnValue_41 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx)   /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETCLOCKCORRECTION_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])    /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETCLOCKCORRECTION_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_43_LLCE_RateCorrectionPtr)
            {
                /* If Fr_43_LLCE_ChannelAStatusPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                /* to the DET and the API function shall return. */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETCLOCKCORRECTION_U8, FR_43_LLCE_E_PARAM_POINTER);
            }
            else
            {
                if (NULL_PTR == Fr_43_LLCE_OffsetCorrectionPtr)
                {
                    /* If Fr_43_LLCE_ChannelBStatusPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETCLOCKCORRECTION_U8, FR_43_LLCE_E_PARAM_POINTER);
                }
                else
                {
                    if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                    {
                        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETCLOCKCORRECTION_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                    }
                    else
                    {
    #else
                    if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                        && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                    {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                        const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                        {
                            /* CC is not accessible, report error */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else
                        {
                            /* Read clock correction values */
                            returnValue_41 = Fr_43_LLCE_Ipw_GetClockCorrection(pCtrlCfg, Fr_43_LLCE_RateCorrectionPtr, Fr_43_LLCE_OffsetCorrectionPtr);

                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            if ((Std_ReturnType)(E_NOT_OK) == returnValue_41)
                            {
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            }
                            #endif
                        }
                    }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_41; /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_GetSyncFrameList
*
* @brief            Gets the current clock correction values.
*
* @implements       Fr_GetSyncFrameList_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_GetSyncFrameList(uint8 Fr_43_LLCE_CtrlIdx,
                                                   uint8 Fr_43_LLCE_ListSize,
                                                   uint16* Fr_43_LLCE_ChannelAEvenListPtr,
                                                   uint16* Fr_43_LLCE_ChannelBEvenListPtr,
                                                   uint16* Fr_43_LLCE_ChannelAOddListPtr,
                                                   uint16* Fr_43_LLCE_ChannelBOddListPtr
                                                  )
{
    /* Set initial return value */
    Std_ReturnType returnValue_42 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx)   /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETSYNCFRAMELIST_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])    /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETSYNCFRAMELIST_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (Fr_43_LLCE_ListSize > 15U)
            {   /* Fr_43_LLCE_ListSize is larger than 15, FR_43_LLCE_E_INV_FRAMELIST_SIZE shall be reported */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETSYNCFRAMELIST_U8, FR_43_LLCE_E_INV_FRAMELIST_SIZE);
            }
            else
            {
                if ((NULL_PTR == Fr_43_LLCE_ChannelAEvenListPtr) || \
                (NULL_PTR == Fr_43_LLCE_ChannelBEvenListPtr))
                {
                    
                    /* If Fr_43_LLCE_ChannelAEvenListPtr equals NULL_PTR, 
                    FR_43_LLCE_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                    /* If Fr_43_LLCE_ChannelBEvenListPtr equals NULL_PTR,
                    FR_43_LLCE_E_PARAM_POINTER shall be reported */
                    /* to the DET and the API function shall return. */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETSYNCFRAMELIST_U8, FR_43_LLCE_E_PARAM_POINTER);
                
                }
                    else
                    {
                        if ((NULL_PTR == Fr_43_LLCE_ChannelAOddListPtr) || \
                          (NULL_PTR == Fr_43_LLCE_ChannelBOddListPtr))
                        {
                            
                            /* If Fr_43_LLCE_ChannelAOddListPtr equals NULL_PTR, 
                            FR_43_LLCE_E_PARAM_POINTER shall be reported */
                            /* to the DET and the API function shall return. */
                            /* If Fr_43_LLCE_ChannelBOddListPtr equals NULL_PTR,
                            FR_43_LLCE_E_PARAM_POINTER shall be reported */
                            /* to the DET and the API function shall return. */
                            
                            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETSYNCFRAMELIST_U8, FR_43_LLCE_E_PARAM_POINTER);
                        
                        }
                            else
                            {
                                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                                {
                                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETSYNCFRAMELIST_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                                }
                                else
                                {
    #else
                                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                                    && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                                {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                                    {
                                        /* CC is not accessible, report error */
                                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                        #endif
                                    }
                                    else
                                    {
                                        /* Check Fr_43_LLCE_ListSize parameter is higher than 0 */
                                        if (Fr_43_LLCE_ListSize > 0U)
                                        {
                                            /* Get list of Sync frames */
                                            if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_GetSyncFrameList(pCtrlCfg, Fr_43_LLCE_ListSize, Fr_43_LLCE_ChannelAEvenListPtr
                                                                                                                , Fr_43_LLCE_ChannelBEvenListPtr, Fr_43_LLCE_ChannelAOddListPtr
                                                                                                                , Fr_43_LLCE_ChannelBOddListPtr))
                                            {
                                                returnValue_42 = (Std_ReturnType)(E_OK);
                                            }
                                            else
                                            {
                                                /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                                                #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                                    Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                                #endif
                                                /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                                            }
                                        }
                                        else
                                        {
                                            /* do nothing */
                                        }
                                    }
                                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                            }
                        
                    }
                
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_42; /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_GetWakeupRxStatus
*
* @brief            Gets the current global FlexRay time.
*
* @implements       Fr_GetWakeupRxStatus_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_GetWakeupRxStatus(uint8 Fr_43_LLCE_CtrlIdx,
                                                    uint8* Fr_43_LLCE_WakeupRxStatusPtr
                                                   )
{
    /* Set initial return value */
    Std_ReturnType returnValue_43 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx)   /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETWAKEUPRXSTATUS_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])    /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETWAKEUPRXSTATUS_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_43_LLCE_WakeupRxStatusPtr)
            {
                /* If Fr_43_LLCE_ChannelAStatusPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                /* to the DET and the API function shall return. */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETWAKEUPRXSTATUS_U8, FR_43_LLCE_E_PARAM_POINTER);
            }
            else
            {
                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETWAKEUPRXSTATUS_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                    && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                    {
                        /* CC is not accessible, report error */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {
                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_GetWakeupRxStatus(pCtrlCfg, Fr_43_LLCE_WakeupRxStatusPtr))
                        {
                            returnValue_43 = (Std_ReturnType)(E_OK);
                        }
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        else
                        {/* Hardware error flags were not cleared */

                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        }
                        #endif
                    }
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_43;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_TransmitTxLPdu
*
* @brief            Transmits data on the FlexRay network.
*
* @implements       Fr_TransmitTxLPdu_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_TransmitTxLPdu(uint8 Fr_43_LLCE_CtrlIdx,
                                                 uint16 Fr_43_LLCE_LPduIdx,
                                                 const uint8* Fr_43_LLCE_LSduPtr,
                                                 uint8 Fr_43_LLCE_LSduLength,
                                                 Fr_SlotAssignmentType* Fr_SlotAssignmentPtr
                                                )
{
    /* Set initial return value */
    Std_ReturnType returnValue_11 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

#if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    u32CoreId = Fr_43_LLCE_GetCoreID();
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_TRANSMITTXLPDU_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_TRANSMITTXLPDU_U8, (uint8)FR_43_LLCE_E_INIT_FAILED); /* Report error */
        }
        else
        {
            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_TRANSMITTXLPDU_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if (Fr_43_LLCE_LPduIdx > (Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduConfiguredCount - 1U))
                {
                    /* Fr_43_LLCE_LPduIdx has an invalid value */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_TRANSMITTXLPDU_U8, FR_43_LLCE_E_INV_LPDU_IDX);
                }
                else
                {
                    if (NULL_PTR == Fr_43_LLCE_LSduPtr)
                    {
                        /* If Fr_43_LLCE_LSduPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                        /* to the DET and the API function shall return. */
                        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8,FR_43_LLCE_SID_TRANSMITTXLPDU_U8, FR_43_LLCE_E_PARAM_POINTER);
                    }
                    else
                    {
                        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckLpduLengthTransmitTX(pCtrlCfg, Fr_43_LLCE_LPduIdx, Fr_43_LLCE_LSduLength))
                        {
                            /* Fr_43_LLCE_LSduLength has an invalid value */
                            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_TRANSMITTXLPDU_U8, FR_43_LLCE_E_INV_LENGTH);
                        }
                        else
                        {    /* 2nd phase; No error yet -> execute the following code */
#else
                        u32CoreId = Fr_43_LLCE_GetCoreID();
                        if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])&& (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId )
                            && (FR_43_LLCE_IND_BUFFER == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduInfoPtr[Fr_43_LLCE_LPduIdx].StorageType))
                        {
                            const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
#endif  /* FR_43_LLCE_DEV_ERROR_DETECT == STD_ON */
                            if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_CheckTXLpdu(pCtrlCfg, Fr_43_LLCE_LPduIdx))
                            {
                                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                                {   /* CC is not accessible, report error */
                                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                    #endif
                                }
                                else
                                {
                                    /* Temporary offset address of MB configuration registers */
                                    if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_TransmitTxLPdu(pCtrlCfg, Fr_43_LLCE_LPduIdx, Fr_43_LLCE_LSduPtr, Fr_43_LLCE_LSduLength, Fr_SlotAssignmentPtr))
                                    {
                                        returnValue_11 = (Std_ReturnType)(E_OK);
                                    }
                                    else
                                    {
                                        /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON -> return E_NOT_OK */
                                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                        /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                        #endif
                                    }
                                } /* Fr_43_LLCE_check_CC_access */
                            }
                            else
                            {
                                /* LPdu is not configured for Tx -> abort the function execution and return E_NOT_OK  */
                            }
                        }
#if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                    }
                }
            }
        }
    }
#endif /* FR_43_LLCE_DEV_ERROR_DETECT == STD_ON */

    return returnValue_11;        /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_ReceiveRxLPdu
*
* @brief            Receives data from the FlexRay network.
*
* @implements       Fr_ReceiveRxLPdu_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_ReceiveRxLPdu(uint8 Fr_43_LLCE_CtrlIdx,
                                                uint16 Fr_43_LLCE_LPduIdx,
                                                uint8* Fr_43_LLCE_LSduPtr,
                                                Fr_RxLPduStatusType* Fr_43_LLCE_LPduStatusPtr,
                                                uint8* Fr_43_LLCE_LSduLengthPtr,
                                                Fr_SlotAssignmentType* Fr_SlotAssignmentPtr
                                               )
{
    /* Set initial return value */
    Std_ReturnType returnValue_12 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();

#if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECEIVERXLPDU_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECEIVERXLPDU_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECEIVERXLPDU_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if (Fr_43_LLCE_LPduIdx > (Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduConfiguredCount -1U))
                {
                    /* Fr_43_LLCE_LPduIdx has an invalid value */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8,FR_43_LLCE_SID_RECEIVERXLPDU_U8, FR_43_LLCE_E_INV_LPDU_IDX);
                }
                else
                {
                    if (NULL_PTR == Fr_43_LLCE_LSduPtr)
                    {
                        /* If Fr_43_LLCE_LSduPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                        /* to the DET and the API function shall return. */
                        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECEIVERXLPDU_U8, FR_43_LLCE_E_PARAM_POINTER);
                    }
                    else
                    {
                        if ((NULL_PTR == Fr_43_LLCE_LPduStatusPtr) || \
                            (NULL_PTR == Fr_43_LLCE_LSduLengthPtr))
                        {
                            /* If Fr_43_LLCE_LPduStatusPtr  or Fr_43_LLCE_LSduLengthPtr equal NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                            /* to the DET and the API function shall return. */
                            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_RECEIVERXLPDU_U8, FR_43_LLCE_E_PARAM_POINTER);
                        }
                        else
                        {
#else
                        if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
                            && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                        {
                            const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
#endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                            if (FR_43_LLCE_IND_BUFFER == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduInfoPtr[Fr_43_LLCE_LPduIdx].StorageType)
                            {
                                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckTXLpdu(pCtrlCfg, Fr_43_LLCE_LPduIdx))
                                {
                                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                                    {   /* CC is not accessible, report error */
                                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                        #endif
                                    }
                                    else
                                    {
                                        /* Call LLD function to receive data */
                                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_ReceiveRxLPdu(pCtrlCfg, Fr_43_LLCE_LPduIdx, Fr_43_LLCE_LSduPtr, Fr_43_LLCE_LPduStatusPtr,
                                                                                                         Fr_43_LLCE_LSduLengthPtr, Fr_SlotAssignmentPtr))
                                        {
                                            returnValue_12 = (Std_ReturnType)(E_OK);
                                        }
                                        else
                                        {
                                            /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                            /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                            #endif
                                        }
                                    } /* Check CC access */
                                }
                            }
                            else    /* Check if FIFO A or FIFO B is used */
                            {
                                if ((FR_43_LLCE_FIFOA_BUFFER == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduInfoPtr[Fr_43_LLCE_LPduIdx].StorageType) ||
                                    (FR_43_LLCE_FIFOB_BUFFER == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduInfoPtr[Fr_43_LLCE_LPduIdx].StorageType))
                                {
                                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                                    {   /* CC is not accessible, report error */
                                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                        #endif
                                    }
                                    else
                                    {
                                        /* Call LLD function to receive data */
                                        Fr_43_LLCE_Ipw_ReceiveFifo(pCtrlCfg, Fr_43_LLCE_LPduIdx, Fr_43_LLCE_LSduPtr, Fr_43_LLCE_LPduStatusPtr, Fr_43_LLCE_LSduLengthPtr,Fr_SlotAssignmentPtr);
                                        returnValue_12 = (Std_ReturnType)(E_OK);
                                    }
                                }
                            }
                        }
#if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                    }
                }
            }
        }
    }
#endif /* FR_43_LLCE_DEV_ERROR_DETECT */

    return returnValue_12;        /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_CheckTxLPduStatus
*
* @brief            Checks the transmit status of the LPdu.
*
* @implements       Fr_CheckTxLPduStatus_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_CheckTxLPduStatus(uint8 Fr_43_LLCE_CtrlIdx,
                                                    uint16 Fr_43_LLCE_LPduIdx,
                                                    Fr_TxLPduStatusType* Fr_TxLPduStatusPtr,
                                                    Fr_SlotAssignmentType* Fr_SlotAssignmentPtr
                                                   )
{
    /* Set initial return value */
    Std_ReturnType returnValue_13 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
#if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CHECKTXLPDUSTATUS_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CHECKTXLPDUSTATUS_U8, (uint8)FR_43_LLCE_E_INIT_FAILED); /* Report error */
        }
        else
        {

            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CHECKTXLPDUSTATUS_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if (Fr_43_LLCE_LPduIdx > (Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduConfiguredCount - 1U))
                {
                    /* Fr_43_LLCE_LPduIdx has an invalid value */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CHECKTXLPDUSTATUS_U8, FR_43_LLCE_E_INV_LPDU_IDX);
                }
                else
                {
                    if (NULL_PTR == Fr_TxLPduStatusPtr)
                    {
                        /* If Fr_TxLPduStatusPtr equals NULL_PTR, FR_43_LLCE_E_PARAM_POINTER shall be reported */
                        /* to the DET and the API function shall return. */
                        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CHECKTXLPDUSTATUS_U8, FR_43_LLCE_E_PARAM_POINTER);
                    }
                    else
                    {
#else
                    if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId )
                    &&  (FR_43_LLCE_IND_BUFFER == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduInfoPtr[Fr_43_LLCE_LPduIdx].StorageType))
                    {
                        const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
#endif /* FR_43_LLCE_DEV_ERROR_DETECT */
                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_CheckTXLpdu(pCtrlCfg, Fr_43_LLCE_LPduIdx))
                        {   /* Transmit MB is configured for given LPdu */
                            if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                            {
                                /* CC is not accessible, report error */
                                #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                    Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                            }
                            else
                            {
                                if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_CheckTxLPduStatus(pCtrlCfg, Fr_43_LLCE_LPduIdx, Fr_TxLPduStatusPtr, Fr_SlotAssignmentPtr))
                                {
                                    returnValue_13 = (Std_ReturnType)(E_OK);
                                }
                                else
                                {   /* Data was not transmitted */
                                    /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON return E_NOT_OK */
                                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                    /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                    #endif
                                }
                            } /* CC access check */
                        }
                        else
                        {
                            /* LPdu is not configured for Tx -> abort the function execution and return E_NOT_OK  */
                        }
                    }
#if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
#endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_13;        /* Return the state of function execution */
}

#if (FR_43_LLCE_PREPARE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_43_LLCE_PrepareLPdu
*
* @brief            Prepares a LPdu.
*
* @implements       Fr_PrepareLPdu_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_PrepareLPdu(uint8 Fr_43_LLCE_CtrlIdx,
                                              uint16 Fr_43_LLCE_LPduIdx
                                             )
{
    /* Set initial return value */
    Std_ReturnType returnValue_31 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_PREPARELPDU_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8,FR_43_LLCE_SID_PREPARELPDU_U8, (uint8)FR_43_LLCE_E_INIT_FAILED); /* Report error */
        }
        else
        {

            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_PREPARELPDU_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if (Fr_43_LLCE_LPduIdx > (Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduConfiguredCount - 1U))
                {
                    /* Fr_43_LLCE_LPduIdx has an invalid value */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_PREPARELPDU_U8, FR_43_LLCE_E_INV_LPDU_IDX);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                    /* Check  whether LPdu is not dynamically reconfigurable, only LPdus which are not
                        dynamically reconfigurable can use reconfiguration feature */
                    if (FALSE == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduInfoPtr[Fr_43_LLCE_LPduIdx].Reconfigurable)
                    {
                        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                        {   /* CC is not accessible, report error */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else
                        {
                            if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_PrepareLPdu(pCtrlCfg, Fr_43_LLCE_LPduIdx))
                            {
                                returnValue_31 = (Std_ReturnType)(E_OK);
                            }
                            else
                            {
                                /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                                #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                    Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                                /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                            }
                        } /* Fr_43_LLCE_check_CC_access */
                    }
                    else
                    {
                        returnValue_31 = (Std_ReturnType)(E_NOT_OK);
                    }
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_31;        /* Return the state of function execution */
}
#endif /* FR_43_LLCE_PREPARE_LPDU_SUPPORT == STD_ON */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_CancelTxLPdu
*
* @brief            Cancels the already pending transmission of a LPdu contained in a controllers
*                   physical transmit resource.
*
* @implements       Fr_CancelTxLPdu_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_CancelTxLPdu(uint8 Fr_43_LLCE_CtrlIdx,
                                               uint16 Fr_43_LLCE_LPduIdx
                                              )
{
    /* Set initial return value */
    Std_ReturnType returnValue_45 = (Std_ReturnType)(E_NOT_OK);
    boolean bpendingStatus_45 = FALSE;
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CANCELTXLPDU_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8,FR_43_LLCE_SID_CANCELTXLPDU_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {

            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CANCELTXLPDU_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if (Fr_43_LLCE_LPduIdx > ((Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduConfiguredCount) - 1U))
                {
                    /* Fr_43_LLCE_LPduIdx has an invalid value */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_CANCELTXLPDU_U8, FR_43_LLCE_E_INV_LPDU_IDX);
                }
                else    /* No error yet -> execute the following code */
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId )
                && (FR_43_LLCE_IND_BUFFER == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduInfoPtr[Fr_43_LLCE_LPduIdx].StorageType) )
                {
                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                    /* Check whether a Tx MB is configured for given LPdu */
                    if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_CheckTXLpdu(pCtrlCfg, Fr_43_LLCE_LPduIdx))
                    {   /* Transmit MB is configured for given LPdu */
                        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                        {   /* CC is not accessible, report error */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else
                        {
                            if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_CancelTxLPdu(pCtrlCfg, Fr_43_LLCE_LPduIdx, &bpendingStatus_45))
                            {
                                /* Transmit request was terminated*/
                                if (TRUE == bpendingStatus_45)
                                { /*Yes*/
                                    returnValue_45 = (Std_ReturnType)(E_OK);
                                }
                                else
                                {
                                    /* Transmit request was not terminated -> return E_NOT_OK */
                                }
                            }
                            else
                            {
                                /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                                #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                                    Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                            }
                        } /* Fr_43_LLCE_check_CC_access */
                    }
                    else
                    {
                         /* LPdu is not configured for Tx -> abort the function execution and return E_NOT_OK  */
                    }
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_45;        /* Return the state of function execution */
}
#if (FR_43_LLCE_RECONFIG_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_43_LLCE_ReconfigLPdu
*
* @brief            Reconfigures a given LPdu according to the parameters (FrameId, Channel,
*                   CycleRepetition, CycleOffset, PayloadLength, HeaderCRC) at runtime.
*
* @implements       Fr_ReconfigLPdu_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_ReconfigLPdu(uint8 Fr_43_LLCE_CtrlIdx,
                                               uint16 Fr_43_LLCE_LPduIdx,
                                               uint16 Fr_43_LLCE_FrameId,
                                               Fr_ChannelType Fr_43_LLCE_ChnlIdx,
                                               uint8 Fr_43_LLCE_CycleRepetition,
                                               uint8 Fr_43_LLCE_CycleOffset,
                                               uint8 Fr_43_LLCE_PayloadLength,
                                               uint16 Fr_43_LLCE_HeaderCrc
                                              )
{
    /* Set initial return value */
    Std_ReturnType returnValue_37 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    if ( (Std_ReturnType) E_OK == Fr_43_LLCE_ValidateReconfigLPdu(Fr_43_LLCE_CtrlIdx,Fr_43_LLCE_LPduIdx,Fr_43_LLCE_FrameId,Fr_43_LLCE_ChnlIdx,Fr_43_LLCE_CycleRepetition,Fr_43_LLCE_CycleOffset,Fr_43_LLCE_PayloadLength,Fr_43_LLCE_HeaderCrc))
    {
    #else /* FR_43_LLCE_DEV_ERROR_DETECT == STD_OFF */
    if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx])
        && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
    {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

        const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
        /* Check  whether LPdu is dynamically reconfigurable, only dynamically reconfigurable
        LPdus can be reconfigured */
        if (TRUE == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduInfoPtr[Fr_43_LLCE_LPduIdx].Reconfigurable)
        {
            /* Check whether target Fr_43_LLCE_FrameId is inside static segment */
            if (Fr_43_LLCE_FrameId <= Fr_43_LLCE_Ipw_GetgNumberOfStaticSlots(Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]))
            {
                if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                {
                    /* CC is not accessible, report error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
                }
                else
                {
                    if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_ReconfigLPdu(pCtrlCfg, Fr_43_LLCE_LPduIdx, Fr_43_LLCE_FrameId
                                                                                     , Fr_43_LLCE_ChnlIdx, Fr_43_LLCE_CycleRepetition,
                                                                                     Fr_43_LLCE_CycleOffset, Fr_43_LLCE_PayloadLength,
                                                                                     Fr_43_LLCE_HeaderCrc))
                    {
                        returnValue_37 = (Std_ReturnType)(E_OK);
                    }
                    else
                    {
                        /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                        /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                    }
                } /* Fr_43_LLCE_check_CC_access */
            }
        }
    }
    return returnValue_37;
}
#endif /* FR_43_LLCE_RECONFIG_LPDU_SUPPORT */

#if (FR_43_LLCE_DISABLE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_43_LLCE_DisableLPdu
*
* @brief            Disables the hardware resource of a LPdu for transmission/reception.
*
* @implements       Fr_DisableLPdu_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_DisableLPdu(uint8 Fr_43_LLCE_CtrlIdx,
                                              uint16 Fr_43_LLCE_LPduIdx
                                             )
{
    /* Set initial return value */
    Std_ReturnType returnValue_38 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_DISABLELPDU_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_DISABLELPDU_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {

            if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
            {
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_DISABLELPDU_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
            }
            else
            {
                const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                if (Fr_43_LLCE_LPduIdx > (Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduConfiguredCount - 1U))
                {
                    /* Fr_43_LLCE_LPduIdx has an invalid value */
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_DISABLELPDU_U8, FR_43_LLCE_E_INV_LPDU_IDX);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
                    /* Check  whether LPdu is dynamically reconfigurable, only dynamically reconfigurable
                       LPdus can be disabled by this service */
                    if (TRUE == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->LpduInfoPtr[Fr_43_LLCE_LPduIdx].Reconfigurable)
                    {
                        if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                        {   /* CC is not accessible, report error */
                            #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                        else
                        {
                            if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_DisableLPdu(pCtrlCfg, Fr_43_LLCE_LPduIdx))
                            {
                                returnValue_38 = (Std_ReturnType)(E_OK);
                            }
                            else
                            {
                                /* Call Dem for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                                #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                                    Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                                #endif
                                /* Do nothing for FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                            }
                        }
                    }
                    else
                    {
                         /* No, LPdu is not dynamically reconfigurable -> return E_NOT_OK */
                    }
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_38;
}
#endif /* FR_43_LLCE_DISABLE_LPDU_SUPPORT */

/***************************************************************************************************
* @function_name    Fr_43_LLCE_ReadCCConfig
*
* @brief            Reads a FlexRay protocol configuration parameter for a particular FlexRay
*                   controller out of the module's configuration.
*
* @implements       Fr_ReadCCConfig_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_ReadCCConfig(uint8 Fr_43_LLCE_CtrlIdx,
                                               uint8 Fr_43_LLCE_ConfigParamIdx,
                                               uint32* Fr_43_LLCE_ConfigParamValuePtr
                                              )
{
    /* Set initial return value */
    Std_ReturnType returnValue_46 = (Std_ReturnType)(E_NOT_OK);
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_READCCCONFIG_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_READCCCONFIG_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_43_LLCE_ConfigParamValuePtr)
            {
                /* Fr_43_LLCE_ConfigParamValuePtr has an invalid value */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_READCCCONFIG_U8, FR_43_LLCE_E_PARAM_POINTER);
            }
            else
            {
                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_READCCCONFIG_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */

                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_ReadbackCCConfig(pCtrlCfg))
                    {   /* CC contains error in the configuration */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {
                        returnValue_46 = (Std_ReturnType)(E_OK);

                        switch (Fr_43_LLCE_ConfigParamIdx)
                        {
                            case FR_CIDX_GDCYCLE:
                            case FR_CIDX_PMICROPERCYCLE:
                            case FR_CIDX_PDLISTENTIMEOUT:
                                *Fr_43_LLCE_ConfigParamValuePtr = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->CCReadBackConfigSetPtr[Fr_43_LLCE_ConfigParamIdx];
                                break;    /* 32bit values */
                            case FR_CIDX_GMACROPERCYCLE:
                            case FR_CIDX_GDMACROTICK:
                            case FR_CIDX_GNUMBEROFMINISLOTS:
                            case FR_CIDX_GNUMBEROFSTATICSLOTS:
                            case FR_CIDX_GDNIT:
                            case FR_CIDX_GDSTATICSLOT:
                            case FR_CIDX_GDWAKEUPRXWINDOW:
                            case FR_CIDX_PKEYSLOTID:
                            case FR_CIDX_PLATESTTX:
                            case FR_CIDX_POFFSETCORRECTIONOUT:
                            case FR_CIDX_POFFSETCORRECTIONSTART:
                            case FR_CIDX_PRATECORRECTIONOUT:
                            case FR_CIDX_PSECONDKEYSLOTID:
                            case FR_CIDX_PDACCEPTEDSTARTUPRANGE:
                            case FR_CIDX_GCOLDSTARTATTEMPTS:
                            case FR_CIDX_GCYCLECOUNTMAX:
                            case FR_CIDX_GLISTENNOISE:
                            case FR_CIDX_GMAXWITHOUTCLOCKCORRECTFATAL:
                            case FR_CIDX_GMAXWITHOUTCLOCKCORRECTPASSIVE:
                            case FR_CIDX_GNETWORKMANAGEMENTVECTORLENGTH:
                            case FR_CIDX_GPAYLOADLENGTHSTATIC:
                            case FR_CIDX_GSYNCFRAMEIDCOUNTMAX:
                            case FR_CIDX_GDACTIONPOINTOFFSET:
                            case FR_CIDX_GDBIT:
                            case FR_CIDX_GDCASRXLOWMAX:
                            case FR_CIDX_GDDYNAMICSLOTIDLEPHASE:
                            case FR_CIDX_GDMINISLOTACTIONPOINTOFFSET:
                            case FR_CIDX_GDMINISLOT:
                            case FR_CIDX_GDSAMPLECLOCKPERIOD:
                            case FR_CIDX_GDSYMBOLWINDOW:
                            case FR_CIDX_GDSYMBOLWINDOWACTIONPOINTOFFSET:
                            case FR_CIDX_GDTSSTRANSMITTER:
                            case FR_CIDX_GDWAKEUPRXIDLE:
                            case FR_CIDX_GDWAKEUPRXLOW:
                            case FR_CIDX_GDWAKEUPTXACTIVE:
                            case FR_CIDX_GDWAKEUPTXIDLE:
                            case FR_CIDX_PALLOWPASSIVETOACTIVE:
                            case FR_CIDX_PCHANNELS:
                            case FR_CIDX_PCLUSTERDRIFTDAMPING:
                            case FR_CIDX_PDECODINGCORRECTION:
                            case FR_CIDX_PDELAYCOMPENSATIONA:
                            case FR_CIDX_PDELAYCOMPENSATIONB:
                            case FR_CIDX_PMACROINITIALOFFSETA:
                            case FR_CIDX_PMACROINITIALOFFSETB:
                            case FR_CIDX_PMICROINITIALOFFSETA:
                            case FR_CIDX_PMICROINITIALOFFSETB:
                            case FR_CIDX_PPAYLOADLENGTHDYNMAX:
                            case FR_CIDX_PSAMPLESPERMICROTICK:
                            case FR_CIDX_PWAKEUPCHANNEL:
                            case FR_CIDX_PWAKEUPPATTERN:
                            case FR_CIDX_PDMICROTICK:
                            case FR_CIDX_GDIGNOREAFTERTX:
                            case FR_CIDX_PALLOWHALTDUETOCLOCK:
                            case FR_CIDX_PEXTERNALSYNC:
                            case FR_CIDX_PFALLBACKINTERNAL:
                            case FR_CIDX_PKEYSLOTONLYENABLED:
                            case FR_CIDX_PKEYSLOTUSEDFORSTARTUP:
                            case FR_CIDX_PKEYSLOTUSEDFORSYNC:
                            case FR_CIDX_PNMVECTOREARLYUPDATE:
                            case FR_CIDX_PTWOKEYSLOTMODE:
                                *Fr_43_LLCE_ConfigParamValuePtr=( Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]->CCReadBackConfigSetPtr[(Fr_43_LLCE_ConfigParamIdx + 3U) / 2U] >> (16U * (Fr_43_LLCE_ConfigParamIdx % 2U)) ) & 0x0000FFFFU;
                                break; /* 16 bit values */
                            default:
                                returnValue_46 = (Std_ReturnType)(E_NOT_OK);
                                /* Fr_43_LLCE_ConfigParamIdx has an invalid value */
                                #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_READCCCONFIG_U8, FR_43_LLCE_E_INV_CONFIG_IDX);
                                #endif
                            break;
                        }
                    }
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_46;
}

/***************************************************************************************************
* @function_name    Fr_43_LLCE_GetNumOfStartupFrames
*
* @brief            Gets the current number of startup frames seen on the cluster.
*
* @implements       Fr_GetNumOfStartupFrames_Activity
***************************************************************************************************/
Std_ReturnType Fr_43_LLCE_GetNumOfStartupFrames(uint8 Fr_43_LLCE_CtrlIdx,
                                                        uint8* Fr_43_LLCE_NumOfStartupFramesPtr
                                                       )
{
    /* Set initial return value */
    Std_ReturnType returnValue_39 = (Std_ReturnType)(E_NOT_OK);
    Fr_POCStateType u16tmpPOCState_39;
    uint32 u32CoreId;

    u32CoreId = Fr_43_LLCE_GetCoreID();
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_43_LLCE_DEV_ERROR_DETECT is enabled: */
    if (FR_43_LLCE_NUM_CTRL_SUPPORTED <= Fr_43_LLCE_CtrlIdx) /* Check the Fr_43_LLCE_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_43_LLCE_CtrlIdx has an invalid value */
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETNUMOFSTARTUPFRAMES_U8, FR_43_LLCE_E_INV_CTRL_IDX);
    }
    else
    {
        if (FR_43_LLCE_STATE_INIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {   /* The Fr was not initialized successfully prior to this API function call */
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETNUMOFSTARTUPFRAMES_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        else
        {
            if (NULL_PTR == Fr_43_LLCE_NumOfStartupFramesPtr)
            {
                /* Fr_43_LLCE_ConfigParamValuePtr has an invalid value */
                (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETNUMOFSTARTUPFRAMES_U8, FR_43_LLCE_E_PARAM_POINTER);
            }
            else
            {
                if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
                    (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_GETNUMOFSTARTUPFRAMES_U8, (uint8)FR_43_LLCE_E_PARAM_CONFIG);
                }
                else
                {
    #else
                if (( NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]) && (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx]) && (u32CoreId == Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
                {
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
                    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_CtrlIdx];
                    if ((Std_ReturnType)(E_NOT_OK) == Fr_43_LLCE_Ipw_CheckCCAccess(pCtrlCfg, TRUE))
                    {   /* CC is not accessible, report error */
                        #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                    }
                    else
                    {

                        /* Determine the POC state */
                        u16tmpPOCState_39 = Fr_43_LLCE_Ipw_GetPOCState(pCtrlCfg);

                        /* Check whether the CC is synchronous to cluster */
                        if ((FR_POCSTATE_NORMAL_PASSIVE == u16tmpPOCState_39) || (FR_POCSTATE_NORMAL_ACTIVE == u16tmpPOCState_39))
                        {   /* The CC is synchronized to the cluster */
                            /* Call LLD function to get number of startup frames */
                            if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_GetNumOfStartupFrames(pCtrlCfg, Fr_43_LLCE_NumOfStartupFramesPtr))
                            {
                                /* API call was successful */
                                returnValue_39 = (Std_ReturnType)(E_OK);
                            }
                        }
                        else
                        {   /* The CC is not synchronized to the cluster */
                            returnValue_39 = (Std_ReturnType)(E_NOT_OK);
                        }
                    }
                }
    #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
    #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    return returnValue_39;
}

#if (FR_43_LLCE_DEINIT_API == STD_ON)
/**************************************************************************************************
* @function_name    Fr_43_LLCE_DeInit
*
* @brief            De-initialize FR Module
*
* @implements       Fr_DeInit_Activity
**************************************************************************************************/
void Fr_43_LLCE_DeInit(void)
{
    uint8 Fr_43_LLCE_u8CtrlIdx;
    boolean Fr_43_LLCE_bDeInitSuccessful = FALSE;
    uint32 u32CoreId;

    const Fr_43_LLCE_CtrlCfgType* pCtrlCfg = NULL_PTR;
    u32CoreId = Fr_43_LLCE_GetCoreID();
    if ((NULL_PTR == Fr_43_LLCE_apInternalCfg[u32CoreId]) || (u32CoreId != Fr_43_LLCE_apInternalCfg[u32CoreId]->u32ParCoreId ))
    {
        #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8, FR_43_LLCE_SID_DEINIT_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
    }
    else
    {
        #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        if (FR_43_LLCE_STATE_UNINIT != Fr_43_LLCE_aeDriverStates[u32CoreId])   /* Check the initialization status */
        {
        #endif /* FR_43_LLCE_DEV_ERROR_DETECT */
            /* Loop all controller in configuration */
            for (Fr_43_LLCE_u8CtrlIdx = 0U; Fr_43_LLCE_u8CtrlIdx < FR_43_LLCE_NUM_CTRL_SUPPORTED; Fr_43_LLCE_u8CtrlIdx++)
            {
                if (NULL_PTR != Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_u8CtrlIdx])
                {
                    pCtrlCfg = Fr_43_LLCE_apInternalCfg[u32CoreId]->Fr_43_LLCE_pController[Fr_43_LLCE_u8CtrlIdx];
                    /* Check Controller state */
                    if (TRUE == Fr_43_LLCE_abCCActive[Fr_43_LLCE_u8CtrlIdx])
                    {
                        /* Call LLD function */
                        if ((Std_ReturnType)(E_OK) == Fr_43_LLCE_Ipw_DeInit(pCtrlCfg))
                        {
                            /* Execute De-init function successfully without any error. */
                            Fr_43_LLCE_bDeInitSuccessful = TRUE;
                            /* This controller is de-activated */
                            Fr_43_LLCE_abCCActive[Fr_43_LLCE_u8CtrlIdx] = FALSE;
                        }
                    }
                    else
                    {
                        /* This Fr controller is not yet enbale, all register still in reset value, do not need to de-initilaze  */
                        Fr_43_LLCE_bDeInitSuccessful = TRUE;
                    }
                    if (FALSE == Fr_43_LLCE_bDeInitSuccessful)
                    {
                        /* if have any error during execute Fr_43_LLCE_DeInit function and enable the DEM report, driver will report DEM error */
                    #if (FR_43_LLCE_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_43_LLCE_Dem_SetEventStatus(Fr_43_LLCE_u8CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
        #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                        Fr_43_LLCE_aeDriverStates[u32CoreId] = FR_43_LLCE_STATE_DEINIT_FALSE;
        #endif
                        break;
                    }
        #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
                    else
                    {
                        Fr_43_LLCE_aeDriverStates[u32CoreId] = FR_43_LLCE_STATE_UNINIT;
                    }
        #endif
                }
            }
        #if (FR_43_LLCE_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            (void)Det_ReportError((uint16)FR_43_LLCE_MODULE_ID, FR_43_LLCE_INSTANCE_ID_U8,FR_43_LLCE_SID_DEINIT_U8, (uint8)FR_43_LLCE_E_INIT_FAILED);
        }
        #endif
    }
}
#endif /* FR_43_LLCE_DEINIT_API */

#ifdef __cplusplus
}
#endif

/** @} */
