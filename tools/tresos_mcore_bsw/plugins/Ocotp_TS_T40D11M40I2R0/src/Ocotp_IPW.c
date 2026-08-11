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
*
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
*   @file
*
*   @addtogroup OCOTP
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Ocotp.h"
#include "Ocotp_IPW.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_IPW_VENDOR_ID_C                           43
#define OCOTP_IPW_AR_RELEASE_MAJOR_VERSION_C            4
#define OCOTP_IPW_AR_RELEASE_MINOR_VERSION_C            4
#define OCOTP_IPW_AR_RELEASE_REVISION_VERSION_C         0
#define OCOTP_IPW_SW_MAJOR_VERSION_C                    4
#define OCOTP_IPW_SW_MINOR_VERSION_C                    0
#define OCOTP_IPW_SW_PATCH_VERSION_C                    2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Ocotp.h header file are of the same vendor */
#if (OCOTP_IPW_VENDOR_ID_C != CDD_OCOTP_VENDOR_ID)
    #error "Ocotp_IPW.c and CDD_Ocotp.h have different vendor ids"
#endif
/* Check if current file and CDD_Ocotp.h header file are of the same AutoSar version */
#if ((OCOTP_IPW_AR_RELEASE_MAJOR_VERSION_C != CDD_OCOTP_AR_RELEASE_MAJOR_VERSION) || \
     (OCOTP_IPW_AR_RELEASE_MINOR_VERSION_C != CDD_OCOTP_AR_RELEASE_MINOR_VERSION) || \
     (OCOTP_IPW_AR_RELEASE_REVISION_VERSION_C != CDD_OCOTP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and CDD_Ocotp.h are different"
#endif
/* Check if current file and CDD_Ocotp.h header file are of the same Software version */
#if ((OCOTP_IPW_SW_MAJOR_VERSION_C != CDD_OCOTP_SW_MAJOR_VERSION) || \
     (OCOTP_IPW_SW_MINOR_VERSION_C != CDD_OCOTP_SW_MINOR_VERSION) || \
     (OCOTP_IPW_SW_PATCH_VERSION_C != CDD_OCOTP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and CDD_Ocotp.h are different"
#endif

/* Check if current file and Ocotp_IPW.h header file are of the same vendor */
#if (OCOTP_IPW_VENDOR_ID_C != OCOTP_IPW_VENDOR_ID)
    #error "Ocotp_IPW.c and Ocotp_IPW.h have different vendor ids"
#endif
/* Check if current file and Ocotp_IPW.h header file are of the same AutoSar version */
#if ((OCOTP_IPW_AR_RELEASE_MAJOR_VERSION_C != OCOTP_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (OCOTP_IPW_AR_RELEASE_MINOR_VERSION_C != OCOTP_IPW_AR_RELEASE_MINOR_VERSION) || \
     (OCOTP_IPW_AR_RELEASE_REVISION_VERSION_C != OCOTP_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and Ocotp_IPW.h are different"
#endif
/* Check if current file and Ocotp_IPW.h header file are of the same Software version */
#if ((OCOTP_IPW_SW_MAJOR_VERSION_C != OCOTP_IPW_SW_MAJOR_VERSION) || \
     (OCOTP_IPW_SW_MINOR_VERSION_C != OCOTP_IPW_SW_MINOR_VERSION) || \
     (OCOTP_IPW_SW_PATCH_VERSION_C != OCOTP_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_IPW.c and Ocotp_IPW.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define OCOTP_START_SEC_CODE
#include "Ocotp_MemMap.h"

/**
* @brief         Configures Ocotp
* @details       Function
*                -# configures the Read Mode

* @param[in]     pConfigPtr Index of controller which will be configured
*/
void Ocotp_IPW_Init(const Ocotp_ConfigType * pConfig)
{
    /* Call Ocotp_Ip_Init to initialize Ocotp Module */
    (void)Ocotp_Ip_Init(pConfig->pHwConfig);
    return;
}

/************************/

void Ocotp_IPW_Deinit(void)
{
    /* Call Ocotp_Ip_DeInit to de-initialize Ocotp Module */
    Ocotp_Ip_DeInit(Ocotp_pConfigPtr->pHwConfig->ocotpInstance);
    return;
}

#if(OCOTP_WRITE_EFUSE_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_WriteEFuse
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 data
)
{
    Ocotp_Ip_StatusType eRetVal;


    if (0UL != pChannelCfg->Ocotp_LockValue)
    {
        /* If Read protection or Write protection was enabled, write to efuse need completing before write protection */
        eRetVal = Ocotp_Ip_WriteEFuse(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_EFuseAddress, data, pChannelCfg->Ocotp_EccEnable, TRUE);
        /* If write operation was successful */
        if (STATUS_OCOTP_IP_SUCCESS == eRetVal)
        {
            eRetVal = Ocotp_Ip_WriteEFuse(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_LockFuseAddress, pChannelCfg->Ocotp_LockValue, FALSE, pChannelCfg->Ocotp_WriteBlocking);
        }
    }
    else
    {
        eRetVal = Ocotp_Ip_WriteEFuse(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_EFuseAddress, data, pChannelCfg->Ocotp_EccEnable, pChannelCfg->Ocotp_WriteBlocking);
    }
    return eRetVal;
}
#endif /* OCOTP_WRITE_EFUSE_API == STD_ON */

#if (OCOTP_WRITE_SHADOW_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_WriteShadowRegister
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 data
)
{
    Ocotp_Ip_StatusType eRetVal;

    /* Call Ocotp_Ip_WriteShadowRegister to write data to the shadow register */
    eRetVal = Ocotp_Ip_WriteShadowRegister(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_ShadowIndex, data);

    return eRetVal;
}
#endif /* OCOTP_WRITE_SHADOW_API == STD_ON */

#if (OCOTP_READ_EFUSE_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_ReadEFuse
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 *data
)
{
    Ocotp_Ip_StatusType eRetVal;

    /* Call Ocotp_Ip_ReadEFuse to read data from the eFuse */
    eRetVal = Ocotp_Ip_ReadEFuse(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_EFuseAddress, data);

    return eRetVal;
}
#endif /* OCOTP_READ_EFUSE_API == STD_ON */

#if (OCOTP_READ_SHADOW_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_ReadShadowRegister
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 *data
)
{
    Ocotp_Ip_StatusType eRetVal;

    /* Call Ocotp_Ip_ReadShadowRegister to read data from the shadow register */
    eRetVal = Ocotp_Ip_ReadShadowRegister(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_ShadowIndex, data);

    return eRetVal;
}
#endif /* OCOTP_READ_SHADOW_API == STD_ON */

#if (OCOTP_READ_APPLICATION_INFORMATION_API == STD_ON)
uint32 Ocotp_IPW_ReadGpRegister(const Ocotp_ChannelConfigType* pChannelCfg)
{
    uint32 u32RetVal;

    /* Call Ocotp_Ip_ReadGpRegister to read data from the GP register */
    u32RetVal = Ocotp_Ip_ReadGpRegister(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_GPRegisterIndex);

    return u32RetVal;
}
#endif /* OCOTP_READ_APPLICATION_INFORMATION_API == STD_ON */

#if (OCOTP_WRITE_APPLICATION_INFORMATION_API == STD_ON)
void Ocotp_IPW_WriteGpRegister
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 data
)
{
    /* Call Ocotp_Ip_WriteGpRegister to write data to the GP register */
    Ocotp_Ip_WriteGpRegister(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_GPRegisterIndex, data);
    return;
}
#endif /* OCOTP_WRITE_APPLICATION_INFORMATION_API == STD_ON */

#ifdef OCOTP_READ_STICKY_INFORMATION_API
#if (OCOTP_READ_STICKY_INFORMATION_API == STD_ON)
uint32 Ocotp_IPW_ReadStrRegister(const Ocotp_ChannelConfigType* pChannelCfg)
{
    uint32 u32RetVal;

    /* Call Ocotp_Ip_ReadStrRegister to read data from the STR register */
    u32RetVal = Ocotp_Ip_ReadStrRegister(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_STRRegisterIndex);

    return u32RetVal;
}
#endif /* OCOTP_READ_STICKY_INFORMATION_API == STD_ON */

#if (OCOTP_WRITE_STICKY_INFORMATION_API == STD_ON)
void Ocotp_IPW_WriteStrRegister
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint32 data
)
{
    /* Call Ocotp_Ip_WriteStrRegister to write data to the STR register */
    Ocotp_Ip_WriteStrRegister(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_STRRegisterIndex, data);
    return;
}
#endif /* OCOTP_WRITE_STICKY_INFORMATION_API == STD_ON */
#endif /* define OCOTP_READ_STICKY_INFORMATION_API */

#if (OCOTP_ECC_ERROR_INJECT_API == STD_ON)
void Ocotp_IPW_EccErrorInject
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    uint8 bit
)
{
    /* Call Ocotp_Ip_EccErrorInject */
    Ocotp_Ip_EccErrorInject(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_ShadowIndex, bit);
    return;
}
#endif /* OCOTP_ECC_ERROR_INJECT_API == STD_ON */

#if (OCOTP_ECC_GET_ERROR_API == STD_ON)
Ocotp_EccErrorType Ocotp_IPW_EccGetError(const Ocotp_ChannelConfigType* pChannelCfg)
{
    Ocotp_EccErrorType eRetVal = OCOTP_ECC_NO_ERROR;

    /*check ECC SINGLE ERROR*/
    if (TRUE == Ocotp_Ip_EccGetError(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_EFuseAddress, OCOTP_IP_ECC_SINGLE_ERROR))
    {
        eRetVal = OCOTP_ECC_SINGLE_ERROR;
    }
    else
    {
        /*check ECC DOUBLE ERROR*/
        if (TRUE == Ocotp_Ip_EccGetError(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_EFuseAddress, OCOTP_IP_ECC_DOUBLE_ERROR))
        {
            eRetVal = OCOTP_ECC_DOUBLE_ERROR;
        }
    }
    return eRetVal;
}
#endif /* OCOTP_ECC_GET_ERROR_API == STD_ON */

#if (OCOTP_SET_MODE_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_SetMode
(
    const Ocotp_Ip_ConfigType* pHwCfg,
    Ocotp_ModeType mode
)
{
    Ocotp_Ip_StatusType eRetVal;
    Ocotp_Ip_ModeType eIpMode = (Ocotp_Ip_ModeType)OCOTP_FBXC_NORMAL_MODE;
    if (OCOTP_NORMAL_MODE == mode)
    {
        /* Set to normal mode */
        eRetVal = Ocotp_Ip_Setmode(pHwCfg->ocotpInstance, eIpMode);
    }
    else
    {
        eIpMode = (Ocotp_Ip_ModeType)OCOTP_FBXC_POWER_DOWN_MODE;
        /* Set to powerdown mode */
        eRetVal = Ocotp_Ip_Setmode(pHwCfg->ocotpInstance, eIpMode);
    }

    return eRetVal;
}
#endif /* OCOTP_SET_MODE_API == STD_ON */

#if (OCOTP_CRC_VALIDATE_API == STD_ON)
Ocotp_Ip_StatusType Ocotp_IPW_CalculateAndWriteCrcValue
(
    const Ocotp_ChannelConfigType* pChannelCfg,
    const uint32 *pData,
    uint32 DataSize
)
{
    Ocotp_Ip_StatusType eRetVal;

    /* Calculate the CRC value and write to the eFuse */
    eRetVal = Ocotp_Ip_CalculateAndWriteCrcValue(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_CRCFuseAddress, pData, DataSize);

    return eRetVal;
}

Ocotp_Ip_StatusType Ocotp_IPW_CrcValidate(const Ocotp_ChannelConfigType* pChannelCfg)
{
    Ocotp_Ip_StatusType eRetVal;

    /* Validate the CRC value */
    eRetVal = Ocotp_Ip_CrcTest(pChannelCfg->Ocotp_Instance, pChannelCfg->Ocotp_CRCFuseAddress, pChannelCfg->Ocotp_StartCRCAddress, pChannelCfg->Ocotp_EndCRCAddress);

    return eRetVal;
}
#endif /* OCOTP_CRC_VALIDATE_API == STD_ON */

#if (OCOTP_GET_STATUS_API == STD_ON)
void Ocotp_IPW_GetStatus
(
    const Ocotp_Ip_ConfigType* pHwCfg,
    Ocotp_StatusType* pStatus
)
{
    Ocotp_Ip_StatusType eStatus;
    /* Get status of IP */
    eStatus = Ocotp_Ip_GetBusyState(pHwCfg->ocotpInstance);
    if (STATUS_OCOTP_IP_BUSY == eStatus)
    {
        pStatus->HardwareStatus = OCOTP_HARDWARE_BUSY;
    }
    else if (STATUS_OCOTP_IP_ERROR == eStatus)
    {
        pStatus->HardwareStatus = OCOTP_HARDWARE_ERROR;
    }
    else
    {
        pStatus->HardwareStatus = OCOTP_HARDWARE_IDLE;
    }
    return;
}
#endif /* OCOTP_GET_STATUS_API == STD_ON */

#define OCOTP_STOP_SEC_CODE
#include "Ocotp_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
