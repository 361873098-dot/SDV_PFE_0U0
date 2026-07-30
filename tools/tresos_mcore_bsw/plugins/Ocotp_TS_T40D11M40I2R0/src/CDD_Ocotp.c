
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : OCOTP_IP
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup OCOTP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Ocotp.h"
#include "Det.h"
#include "SchM_Ocotp.h"
#if (OCOTP_MULTICORE_SUPPORT == STD_ON)
#include "OsIf.h"
#endif
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_OCOTP_VENDOR_ID_C                      43
#define CDD_OCOTP_AR_RELEASE_MAJOR_VERSION_C       4
#define CDD_OCOTP_AR_RELEASE_MINOR_VERSION_C       4
#define CDD_OCOTP_AR_RELEASE_REVISION_VERSION_C    0
#define CDD_OCOTP_SW_MAJOR_VERSION_C               4
#define CDD_OCOTP_SW_MINOR_VERSION_C               0
#define CDD_OCOTP_SW_PATCH_VERSION_C               2

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Ocotp.h header file are of the same vendor */
#if (CDD_OCOTP_VENDOR_ID_C != CDD_OCOTP_VENDOR_ID)
    #error "CDD_Ocotp.c and CDD_Ocotp.h have different vendor ids"
#endif
/* Check if current file and CDD_Ocotp.h header file are of the same AutoSar version */
#if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION_C != CDD_OCOTP_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_OCOTP_AR_RELEASE_MINOR_VERSION_C != CDD_OCOTP_AR_RELEASE_MINOR_VERSION) || \
     (CDD_OCOTP_AR_RELEASE_REVISION_VERSION_C != CDD_OCOTP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.c and CDD_Ocotp.h are different"
#endif
/* Check if current file and CDD_Ocotp.h header file are of the same Software version */
#if ((CDD_OCOTP_SW_MAJOR_VERSION_C != CDD_OCOTP_SW_MAJOR_VERSION) || \
     (CDD_OCOTP_SW_MINOR_VERSION_C != CDD_OCOTP_SW_MINOR_VERSION) || \
     (CDD_OCOTP_SW_PATCH_VERSION_C != CDD_OCOTP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Ocotp.c and CDD_Ocotp.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_OCOTP_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of CDD_Ocotp.c and Det.h are different"
    #endif
    /* Check if current file and SchM_Ocotp header file are of the same Autosar version */
    #if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION_C != SCHM_OCOTP_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_OCOTP_AR_RELEASE_MINOR_VERSION_C != SCHM_OCOTP_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of CDD_Ocotp.c and SchM_Ocotp.h are different"
    #endif
    /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((CDD_OCOTP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_OCOTP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of CDD_Ocotp.c and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define OCOTP_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Ocotp_MemMap.h"

const Ocotp_ConfigType *Ocotp_pConfigPtr;

#define OCOTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Ocotp_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"
#if (OCOTP_MULTICORE_SUPPORT == STD_ON)
static Std_ReturnType Ocotp_ValidateMulticoreConfig(const Ocotp_ConfigType* ConfigPtr, uint8 ApiId);

static Std_ReturnType Ocotp_ValidateMulticoreChannel(uint8 ApiId);
#endif
#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"
#if (OCOTP_MULTICORE_SUPPORT == STD_ON)

static Std_ReturnType Ocotp_ValidateMulticoreConfig(const Ocotp_ConfigType* ConfigPtr, uint8 ApiId)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32CoreId = 0U;

    u32CoreId = (uint32)OsIf_GetCoreID();
    if (u32CoreId == (*(ConfigPtr->pMulticoreConfig)))
    {
        eRetVal = (Std_ReturnType)E_OK;
    }
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    else
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, ApiId, OCOTP_E_MULTICORE_INSTANCE);
    }
#else
    (void)ApiId;
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}

static Std_ReturnType Ocotp_ValidateMulticoreChannel(uint8 ApiId)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    uint32 u32CoreId = 0U;

    u32CoreId = (uint32)OsIf_GetCoreID();
    if (u32CoreId == (*(Ocotp_pConfigPtr->pMulticoreConfig)))
    {
        eRetVal = (Std_ReturnType)E_OK;
    }
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    else
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, ApiId, OCOTP_E_MULTICORE_CHANNEL);
    }
#else
    (void)ApiId;
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif
#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

/**
 * @brief        The function initializes Ocotp module.
 * @details      The function sets the internal module variables according to given
 *               configuration set.
 *
 * @param[in]    ConfigPtr        Pointer to Ocotp driver configuration set.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must be NULL_PTR.
 *
 * @implements   Ocotp_Init_Activity
 *
 */
void Ocotp_Init(const Ocotp_ConfigType * const ConfigPtr)
{
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_INIT_ID, OCOTP_E_ALREADY_INITIALIZED);
    }
    else
    {
#ifdef OCOTP_PRECOMPILE_SUPPORT
        if (NULL_PTR != ConfigPtr)
#else
        if (NULL_PTR == ConfigPtr)
#endif /* OCOTP_PRECOMPILE_SUPPORT */
        {
            (void) Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_INIT_ID, OCOTP_E_PARAM_CONFIG);
        }
        else
        {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
        #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
            #ifdef OCOTP_PRECOMPILE_SUPPORT
            if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreConfig(&Ocotp_Config, (uint8)OCOTP_INIT_ID))
            #else
            if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreConfig(ConfigPtr, (uint8)OCOTP_INIT_ID))
            #endif
            {
        #endif
            #ifdef OCOTP_PRECOMPILE_SUPPORT
                Ocotp_pConfigPtr = &Ocotp_Config;
                (void)ConfigPtr;
            #else
                Ocotp_pConfigPtr = ConfigPtr;
            #endif /* OCOTP_PRECOMPILE_SUPPORT */
                Ocotp_IPW_Init(Ocotp_pConfigPtr);
        #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
            }
        #endif
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return;
}

/**
 * @brief        The function de-initializes Ocotp module.
 * @details      The function sets the Ocotp module's status to un-initialized.
 *
 * @param[in]    none.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_Deinit_Activity
 *
 */
void Ocotp_Deinit(void)
{
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_DEINIT_ID, OCOTP_E_UNINIT);
    }
    else
    {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreConfig(Ocotp_pConfigPtr, (uint8)OCOTP_DEINIT_ID))
        {
    #endif
            Ocotp_IPW_Deinit();
            Ocotp_pConfigPtr = NULL_PTR;
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return;
}

#if(OCOTP_WRITE_EFUSE_API == STD_ON)
/**
 * @brief        The function writes data to efuse word.
 * @details      The function writes the specified data to the eFuse which was
 *               configured by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                data user want to write to eFuse word.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Write operation is successful.
 * @retval       E_NOT_OK                Write operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_WriteEFuse_Activity
 *
 */
Std_ReturnType Ocotp_WriteEFuse
(
    Ocotp_ChannelType eFuseChannel,
    uint32 data
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    Ocotp_Ip_StatusType eStatus;
#if (OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_EFUSE_ID, OCOTP_E_UNINIT);
    }
    else if (eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_EFUSE_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    {
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_WRITE_EFUSE_ID))
        {
    #endif
            SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_00();

            eStatus = Ocotp_IPW_WriteEFuse(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], data);

            SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_00();
            if (STATUS_OCOTP_IP_BUSY == eStatus)
            {
            #if (OCOTP_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_EFUSE_ID, OCOTP_E_BUSY);
            #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            }
            else if (STATUS_OCOTP_IP_INVALID_INPUT_ADDRESS == eStatus)
            {
            #if (OCOTP_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_EFUSE_ID, OCOTP_E_PARAM_CHANNEL);
            #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            }
            else if (STATUS_OCOTP_IP_ERROR == eStatus)
            {
                (void)Det_ReportTransientFault((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_EFUSE_ID, OCOTP_E_WRITE_FAILED);
            }
            else if (STATUS_OCOTP_IP_ERROR_TIMEOUT == eStatus)
            {
                (void)Det_ReportRuntimeError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_EFUSE_ID, OCOTP_E_TIMEOUT);
            }
            else
            {
                eRetVal = (Std_ReturnType)E_OK;
            }
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
    }
    return eRetVal;
}
#endif /* OCOTP_WRITE_EFUSE_API == STD_ON */

#if (OCOTP_WRITE_SHADOW_API == STD_ON)
/**
 * @brief        The function writes data to shadow register.
 * @details      The function writes the specified data to the shadow register corresponding to eFuse
 *               which was configured by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                data user want to write to shadow register.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Write operation is successful.
 * @retval       E_NOT_OK                Write operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_WriteShadowRegister_Activity
 *
 */
Std_ReturnType Ocotp_WriteShadowRegister
(
    Ocotp_ChannelType eFuseChannel,
    uint32 data
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    Ocotp_Ip_StatusType eStatus;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_SHADOW_REGISTER_ID, OCOTP_E_UNINIT);
    }
    else if ((eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED) || ((*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel].Ocotp_ShadowIndex >= OCOTP_IP_NUMBER_OF_RW_SHADOW))
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_SHADOW_REGISTER_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    {
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_WRITE_SHADOW_REGISTER_ID))
        {
    #endif
            eStatus = Ocotp_IPW_WriteShadowRegister(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], data);
            if (STATUS_OCOTP_IP_BUSY == eStatus)
            {
            #if (OCOTP_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_SHADOW_REGISTER_ID, OCOTP_E_BUSY);
            #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            }
            if (STATUS_OCOTP_IP_ERROR == eStatus)
            {
                (void)Det_ReportTransientFault((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_SHADOW_REGISTER_ID, OCOTP_E_WRITE_FAILED);
            }
            if (STATUS_OCOTP_IP_SUCCESS == eStatus)
            {
                eRetVal = (Std_ReturnType)E_OK;
            }
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
    }
    return eRetVal;
}
#endif /* OCOTP_WRITE_SHADOW_API == STD_ON */

#if (OCOTP_READ_EFUSE_API == STD_ON)
/**
 * @brief        The function reads data from efuse word.
 * @details      The function reads the data from the eFuse which was
 *               configured by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                pointer points to the data read from eFuse word.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Read operation is successful.
 * @retval       E_NOT_OK                Read operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_ReadEFuse_Activity
 *
 */
Std_ReturnType Ocotp_ReadEFuse
(
    Ocotp_ChannelType eFuseChannel,
    uint32* pData
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    Ocotp_Ip_StatusType eStatus;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_UNINIT);
    }
    else if (eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else if (NULL_PTR == pData)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_PARAM_POINTER);
    }
    else
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    {
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_READ_EFUSE_ID))
        {
    #endif
            SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_01();

            eStatus = Ocotp_IPW_ReadEFuse(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], pData);

            SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_01();
            if (STATUS_OCOTP_IP_BUSY == eStatus)
            {
            #if(OCOTP_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_BUSY);
            #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            }
            if (STATUS_OCOTP_IP_ERROR == eStatus)
            {
                (void)Det_ReportTransientFault((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_READ_FAILED);
            }
            if (STATUS_OCOTP_IP_ERROR_TIMEOUT == eStatus)
            {
                (void)Det_ReportRuntimeError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_EFUSE_ID, OCOTP_E_TIMEOUT);
            }
            if (STATUS_OCOTP_IP_SUCCESS == eStatus)
            {
                eRetVal = (Std_ReturnType)E_OK;
            }
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
    }
    return eRetVal;
}
#endif /* OCOTP_READ_EFUSE_API == STD_ON */

#if (OCOTP_READ_SHADOW_API == STD_ON)
/**
 * @brief        The function reads data from shadow register.
 * @details      The function reads the data from the shadow register corresponding to eFuse
 *               which was configured by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                pointer points to the data read from shadow register.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Read operation is successful.
 * @retval       E_NOT_OK                Read operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_ReadShadowRegister_Activity
 *
 */
Std_ReturnType Ocotp_ReadShadowRegister
(
    Ocotp_ChannelType eFuseChannel,
    uint32 *pData
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    Ocotp_Ip_StatusType eStatus;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_SHADOW_REGISTER_ID, OCOTP_E_UNINIT);
    }
    else if (eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_SHADOW_REGISTER_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else if (NULL_PTR == pData)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_SHADOW_REGISTER_ID, OCOTP_E_PARAM_POINTER);
    }
    else
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    {
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_READ_SHADOW_REGISTER_ID))
        {
    #endif
            eStatus = Ocotp_IPW_ReadShadowRegister(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], pData);
            if (STATUS_OCOTP_IP_BUSY == eStatus)
            {
            #if(OCOTP_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_SHADOW_REGISTER_ID, OCOTP_E_BUSY);
            #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            }
            if (STATUS_OCOTP_IP_ERROR == eStatus)
            {
                (void)Det_ReportTransientFault((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_SHADOW_REGISTER_ID, OCOTP_E_READ_FAILED);
            }
            if (STATUS_OCOTP_IP_SUCCESS == eStatus)
            {
                eRetVal = (Std_ReturnType)E_OK;
            }
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
    }
    return eRetVal;
}
#endif /* OCOTP_READ_SHADOW_API == STD_ON */

#if (OCOTP_READ_APPLICATION_INFORMATION_API == STD_ON)
/**
 * @brief        The function reads data from GP register.
 * @details      The function reads the data from the GP register
 *               which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 *
 * @return       Std_ReturnType
 * @retval       E_OK read operation is successful.
 * @retval       E_NOT_OK read operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_ReadApplicationInformation_Activity
 *
 */
Std_ReturnType Ocotp_ReadApplicationInformation
(
    Ocotp_ChannelType eFuseChannel,
    uint32* pData
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_APPLICATION_INFORMATION_ID, OCOTP_E_UNINIT);
    }
    else if ((eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED) ||
             /* Check if Ocotp GP Register Index is not configured for current channel */
             ((uint8)OCOTP_INVALID_INDEX == (*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel].Ocotp_GPRegisterIndex)
            )
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_APPLICATION_INFORMATION_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else if (NULL_PTR == pData)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_APPLICATION_INFORMATION_ID, OCOTP_E_PARAM_POINTER);
    }
    else
    {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_READ_APPLICATION_INFORMATION_ID))
        {
    #endif
            *pData = Ocotp_IPW_ReadGpRegister(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel]);
            eRetVal = (Std_ReturnType)E_OK;
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif /* OCOTP_READ_APPLICATION_INFORMATION_API == STD_ON */

#if (OCOTP_WRITE_APPLICATION_INFORMATION_API == STD_ON)
/**
 * @brief        The function writes data to GP register.
 * @details      The function writes the data to the GP register
 *               which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                data to be written.
 *
 * @return       Std_ReturnType
 * @retval       E_OK write operation is successful.
 * @retval       E_NOT_OK write operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_WriteApplicationInformation_Activity
 *
 */
Std_ReturnType Ocotp_WriteApplicationInformation
(
    Ocotp_ChannelType eFuseChannel,
    uint32 data
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_APPLICATION_INFORMATION_ID, OCOTP_E_UNINIT);
    }
    else if ((eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED) ||
             /* Check if Ocotp GP Register Index is not configured for current channel */
             ((uint8)OCOTP_INVALID_INDEX == (*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel].Ocotp_GPRegisterIndex)
            )
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_APPLICATION_INFORMATION_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else
    {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_WRITE_APPLICATION_INFORMATION_ID))
        {
    #endif
            Ocotp_IPW_WriteGpRegister(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], data);
            eRetVal = (Std_ReturnType)E_OK;
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif /* OCOTP_WRITE_APPLICATION_INFORMATION_API == STD_ON */

#ifdef OCOTP_READ_STICKY_INFORMATION_API
#if (OCOTP_READ_STICKY_INFORMATION_API == STD_ON)
/**
 * @brief        The function reads data from STR register.
 * @details      The function reads the data from the STR register
 *               which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[out]   pData               Pointer points to read data value
 *
 * @return       Std_ReturnType
 * @retval       E_OK read operation is successful.
 * @retval       E_NOT_OK read operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_ReadStickyInformation_Activity
 *
 */
Std_ReturnType Ocotp_ReadStickyInformation
(
    Ocotp_ChannelType eFuseChannel,
    uint32* pData
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_STICKY_INFORMATION_ID, OCOTP_E_UNINIT);
    }
    else if ((eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED) ||
             /* Check if Ocotp STR Register Index is not configured for current channel */
             ((uint8)OCOTP_INVALID_INDEX == (*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel].Ocotp_STRRegisterIndex)
            )
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_STICKY_INFORMATION_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else if (NULL_PTR == pData)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_READ_STICKY_INFORMATION_ID, OCOTP_E_PARAM_POINTER);
    }
    else
    {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_READ_STICKY_INFORMATION_ID))
        {
    #endif
            *pData = Ocotp_IPW_ReadStrRegister(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel]);
            eRetVal = (Std_ReturnType)E_OK;
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif /* OCOTP_READ_STICKY_INFORMATION_API == STD_ON */

#if (OCOTP_WRITE_STICKY_INFORMATION_API == STD_ON)
/**
 * @brief        The function writes data to STR register.
 * @details      The function writes the data to the STR register
 *               which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    data                data to be written.
 *
 * @return       Std_ReturnType
 * @retval       E_OK write operation is successful.
 * @retval       E_NOT_OK write operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_WriteStickyInformation_Activity
 *
 */
Std_ReturnType Ocotp_WriteStickyInformation
(
    Ocotp_ChannelType eFuseChannel,
    uint32 data
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_STICKY_INFORMATION_ID, OCOTP_E_UNINIT);
    }
    else if ((eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED) ||
             /* Check if Ocotp STR Register Index is not configured for current channel */
             ((uint8)OCOTP_INVALID_INDEX == (*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel].Ocotp_STRRegisterIndex)
            )
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_WRITE_STICKY_INFORMATION_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else
    {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_WRITE_STICKY_INFORMATION_ID))
        {
    #endif
            Ocotp_IPW_WriteStrRegister(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], data);
            eRetVal = (Std_ReturnType)E_OK;
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif /* OCOTP_WRITE_STICKY_INFORMATION_API == STD_ON */
#endif /* define OCOTP_READ_STICKY_INFORMATION_API */

#if (OCOTP_ECC_ERROR_INJECT_API == STD_ON)
/**
 * @brief        The function injects ECC error in the specified eFuse.
 * @details      The function inverts the value of the specified bit in the shadow register
 *               corresponding to eFuse which was configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    bit                 bit's position which will be inverted.
 *
 * @return       Std_ReturnType
 * @retval       E_OK inject operation is successful.
 * @retval       E_NOT_OK inject operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_EccErrorInject_Activity
 *
 */
Std_ReturnType Ocotp_EccErrorInject
(
    Ocotp_ChannelType eFuseChannel,
    uint8 bit
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_ECC_ERROR_INJECT_ID, OCOTP_E_UNINIT);
    }
    else if ((eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED) || ((*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel].Ocotp_ShadowIndex >= OCOTP_IP_NUMBER_OF_RW_SHADOW))
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_ECC_ERROR_INJECT_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else
    {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_ECC_ERROR_INJECT_ID))
        {
    #endif
            Ocotp_IPW_EccErrorInject(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], bit);
            eRetVal = (Std_ReturnType)E_OK;
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif /* OCOTP_ECC_ERROR_INJECT_API == STD_ON */

#if (OCOTP_ECC_GET_ERROR_API == STD_ON)
/**
 * @brief        The function gets ECC error of the specified eFuse.
 * @details      The function check the single-bit and double-bit ECC error bit
 *               of the specified eFuse.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 *
 * @return       Std_ReturnType
 * @retval       E_OK get error operation is successful.
 * @retval       E_NOT_OK get error operation failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_EccGetError_Activity
 *
 */
 Std_ReturnType Ocotp_EccGetError
(
    Ocotp_ChannelType eFuseChannel,
    Ocotp_EccErrorType* pEccValue
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_ECC_GET_ERROR_ID, OCOTP_E_UNINIT);
    }
    else if (eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_ECC_GET_ERROR_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else if (NULL_PTR == pEccValue)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_ECC_GET_ERROR_ID, OCOTP_E_PARAM_POINTER);
    }
    else
    {
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_ECC_GET_ERROR_ID))
        {
    #endif
            *pEccValue = Ocotp_IPW_EccGetError(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel]);
            eRetVal = (Std_ReturnType)E_OK;
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif /* OCOTP_ECC_GET_ERROR_API == STD_ON */

#if (OCOTP_SET_MODE_API == STD_ON)
/**
 * @brief        The function sets operation mode for Ocotp module.
 * @details      The function sets operation mode for Ocotp module.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    mode                mode which is to be applied (OCOTP_NORMAL_MODE, OCOTP_POWERDOWN_MODE).
 *
 * @return       Std_ReturnType
 * @retval       E_OK     mode is set successfully.
 * @retval       E_NOT_OK set mode failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_SetMode_Activity
 *
 */
Std_ReturnType Ocotp_SetMode
(
    uint8 HwIndex,
    Ocotp_ModeType mode
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    Ocotp_Ip_StatusType eStatus;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_SET_MODE_ID, OCOTP_E_UNINIT);
    }
    else if (HwIndex >= OCOTP_NUMBER_INSTANCE_CONFIGURED)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_SET_MODE_ID, OCOTP_E_PARAM_INSTANCE);
    }
    else if ((OCOTP_NORMAL_MODE != mode) && (OCOTP_POWERDOWN_MODE != mode))
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_SET_MODE_ID, OCOTP_E_PARAM_MODE);
    }
    else
#else
    (void)HwIndex;
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    {
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreConfig(Ocotp_pConfigPtr, (uint8)OCOTP_SET_MODE_ID))
        {
    #endif
            eStatus = Ocotp_IPW_SetMode(Ocotp_pConfigPtr->pHwConfig, mode);

            if (STATUS_OCOTP_IP_BUSY == eStatus)
            {
            #if(OCOTP_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_SET_MODE_ID, OCOTP_E_BUSY);
            #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            }
            if (STATUS_OCOTP_IP_ERROR_TIMEOUT == eStatus)
            {
                (void)Det_ReportRuntimeError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_SET_MODE_ID, OCOTP_E_TIMEOUT);
            }
            if (STATUS_OCOTP_IP_SUCCESS == eStatus)
            {
                eRetVal = (Std_ReturnType)E_OK;
            }
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
    }
    return eRetVal;
}
#endif /* OCOTP_SET_MODE_API == STD_ON */

#if (OCOTP_CRC_VALIDATE_API == STD_ON)
/**
 * @brief        The function writes the CRC value to the CRC fuse word.
 * @details      The function calculates and writes the CRC value to the CRC fuse word
 *               which is configured in eFuse channel by configuration tool.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 * @param[in]    pData               Pointer points to the data buffer which need calculating CRC.
 * @param[in]    dataSize            Size of the data need calculating CRC in byte.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                    Write CRC value is successful.
 * @retval       E_NOT_OK                Write CRC value failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_CalculateAndWriteCrcValue_Activity
 *
 */
Std_ReturnType Ocotp_CalculateAndWriteCrcValue
(
    Ocotp_ChannelType eFuseChannel,
    const uint32* pData,
    uint32 dataSize
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    Ocotp_Ip_StatusType eStatus;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CALCULATE_AND_WRITE_ECC_VALUE_ID, OCOTP_E_UNINIT);
    }
    else if ((eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED) ||
             /* Check if CRC32 feature is enabled for current channel*/
             ((uint32)OCOTP_INVALID_ADDRESS == (*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel].Ocotp_StartCRCAddress)
            )
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CALCULATE_AND_WRITE_ECC_VALUE_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else if (NULL_PTR == pData)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CALCULATE_AND_WRITE_ECC_VALUE_ID, OCOTP_E_PARAM_POINTER);
    }
    else if ((uint32)0U == dataSize)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CALCULATE_AND_WRITE_ECC_VALUE_ID, OCOTP_E_PARAM_LENGTH);
    }
    else
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    {
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_CALCULATE_AND_WRITE_ECC_VALUE_ID))
        {
    #endif
            SchM_Enter_Ocotp_OCOTP_EXCLUSIVE_AREA_02();

            eStatus = Ocotp_IPW_CalculateAndWriteCrcValue(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel], pData, dataSize);

            SchM_Exit_Ocotp_OCOTP_EXCLUSIVE_AREA_02();
            if (STATUS_OCOTP_IP_BUSY == eStatus)
            {
            #if(OCOTP_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CALCULATE_AND_WRITE_ECC_VALUE_ID, OCOTP_E_BUSY);
            #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            }
            if (STATUS_OCOTP_IP_ERROR == eStatus)
            {
                (void)Det_ReportTransientFault((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CALCULATE_AND_WRITE_ECC_VALUE_ID, OCOTP_E_WRITE_FAILED);
            }
            if (STATUS_OCOTP_IP_ERROR_TIMEOUT == eStatus)
            {
                (void)Det_ReportRuntimeError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CALCULATE_AND_WRITE_ECC_VALUE_ID, OCOTP_E_TIMEOUT);
            }
            if (STATUS_OCOTP_IP_SUCCESS == eStatus)
            {
                eRetVal = (Std_ReturnType)E_OK;
            }
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
    }

    return eRetVal;
}

/**
 * @brief        The function validates the CRC.
 * @details      The function compares the CRC value calculated by hardware
 *               to CRC value in the CRC fuse word which is configured in eFuse channel.
 *
 * @param[in]    eFuseChannel        Channel of eFuse such as 0, 1, 2 which was configured by user.
 *
 * @return       Std_ReturnType
 * @retval       E_OK                Validate CRC value is successful.
 * @retval       E_NOT_OK            Validate CRC value failed.
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_CrcValidate_Activity
 *
 */
Std_ReturnType Ocotp_CrcValidate(Ocotp_ChannelType eFuseChannel)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;
    Ocotp_Ip_StatusType eStatus;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CRC_VALIDATE_ID, OCOTP_E_UNINIT);
    }
    else if ((eFuseChannel >= OCOTP_NUMBER_CHANNEL_CONFIGURED) ||
             /* Check if CRC32 feature is enabled for current channel */
             ((uint32)OCOTP_INVALID_ADDRESS == (*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel].Ocotp_StartCRCAddress)
            )
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CRC_VALIDATE_ID, OCOTP_E_PARAM_CHANNEL);
    }
    else
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    {
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        if ((Std_ReturnType)E_OK == Ocotp_ValidateMulticoreChannel(OCOTP_CRC_VALIDATE_ID))
        {
    #endif

            eStatus = Ocotp_IPW_CrcValidate(&(*(Ocotp_pConfigPtr->pChanelConfig))[eFuseChannel]);

            if (STATUS_OCOTP_IP_BUSY == eStatus)
            {
            #if(OCOTP_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CRC_VALIDATE_ID, OCOTP_E_BUSY);
            #endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
            }
            if (STATUS_OCOTP_IP_ERROR_TIMEOUT == eStatus)
            {
                (void)Det_ReportRuntimeError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_CRC_VALIDATE_ID, OCOTP_E_TIMEOUT);
            }
            if (STATUS_OCOTP_IP_SUCCESS == eStatus)
            {
                eRetVal = (Std_ReturnType)E_OK;
            }
    #if (OCOTP_MULTICORE_SUPPORT == STD_ON)
        }
    #endif
    }
    return eRetVal;
}
#endif /* OCOTP_CRC_VALIDATE_API == STD_ON */


#if (OCOTP_GET_STATUS_API == STD_ON)
/**
 * @brief        The function gets status of Ocotp module.
 * @details      The function gets status of Ocotp module
 *               Secure mode is enabled or not. Error occurred or not and
 *               Status of hardware.
 *
 * @param[in]    HwIndex        Index of hardware configured.
 * @param[in]    pStatus        Pointer points to status structure.
 *
 * @return       Std_ReturnType
 *
 * @api
 *
 * @pre          Ocotp_pConfigPtr must not be NULL_PTR.
 *
 * @implements   Ocotp_GetStatus_Activity
 *
 */
Std_ReturnType Ocotp_GetStatus
(
    uint8 HwIndex,
    Ocotp_StatusType* pStatus
)
{
    Std_ReturnType eRetVal = (Std_ReturnType)E_NOT_OK;

#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Ocotp_pConfigPtr)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_GET_STATUS_ID, OCOTP_E_UNINIT);
    }
    else if (HwIndex >= OCOTP_NUMBER_INSTANCE_CONFIGURED)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_GET_STATUS_ID, OCOTP_E_PARAM_INSTANCE);
    }
    else if (NULL_PTR == pStatus)
    {
        (void)Det_ReportError((uint16)OCOTP_MODULE_ID, OCOTP_INSTANCE_ID, OCOTP_GET_STATUS_ID, OCOTP_E_PARAM_POINTER);
    }
    else
    {
#else
    (void)HwIndex;
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
        Ocotp_IPW_GetStatus(Ocotp_pConfigPtr->pHwConfig, pStatus);
        eRetVal = (Std_ReturnType)E_OK;
#if(OCOTP_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* OCOTP_DEV_ERROR_DETECT == STD_ON */
    return eRetVal;
}
#endif /* OCOTP_GET_STATUS_API == STD_ON */

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
