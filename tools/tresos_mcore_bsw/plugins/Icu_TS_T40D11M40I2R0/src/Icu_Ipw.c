/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm Siul2 Wkpu
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

/**
 *     @file
 *     @internal
 *     @addtogroup icu_ipw Icu Driver
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_Ipw.h"
#include "Ftm_Icu_Ip.h"
#include "Siul2_Icu_Ip.h"
#include "Wkpu_Ip.h"

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_VENDOR_ID_C                     43
#define ICU_IPW_AR_RELEASE_MAJOR_VERSION_C      4
#define ICU_IPW_AR_RELEASE_MINOR_VERSION_C      4
#define ICU_IPW_AR_RELEASE_REVISION_VERSION_C   0
#define ICU_IPW_SW_MAJOR_VERSION_C              4
#define ICU_IPW_SW_MINOR_VERSION_C              0
#define ICU_IPW_SW_PATCH_VERSION_C              2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_IPW_VENDOR_ID)
    #error "Icu_Ipw.c and Icu_Ipw.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C  != ICU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C  != ICU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C   != ICU_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.c and Icu_Ipw.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C  != ICU_IPW_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C  != ICU_IPW_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C  != ICU_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Icu_Ipw.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != FTM_ICU_IP_VENDOR_ID)
    #error "Icu_Ipw.c and Ftm_Icu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C  != FTM_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C  != FTM_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C   != FTM_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.c and Ftm_Icu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C  != FTM_ICU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C  != FTM_ICU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C  != FTM_ICU_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Ftm_Icu_Ip.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != SIUL2_ICU_IP_VENDOR_ID)
    #error "Icu_Ipw.c and Siul2_Icu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C  != SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C  != SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C   != SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.c and Siul2_Icu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C  != SIUL2_ICU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C  != SIUL2_ICU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C  != SIUL2_ICU_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Siul2_Icu_Ip.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != WKPU_IP_VENDOR_ID)
    #error "Icu_Ipw.c and Wkpu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C  != WKPU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C  != WKPU_IP_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C   != WKPU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.c and Wkpu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C  != WKPU_IP_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C  != WKPU_IP_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C  != WKPU_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Wkpu_Ip.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief                Icu_Ipw_Init
* @details              Initialize a hardware Icu IP Instance
*
* @param[in]            count       - Number of instances to be configured
* @param[in]            pIpConfig   - Pointer that contains IP specific configuration data for the Icu driver
*
* @return void
*
* @pre                  Icu_DeInit must be called before.
*
*/
void Icu_Ipw_Init(uint8 count, const Icu_Ipw_IpConfigType (*pIpConfig)[])
{
    uint8 index;

    for(index = 0; index < count; index++)
    {
        /* External Interrupt Channel Configuration */
        if (ICU_SIUL2_MODULE == (*pIpConfig)[index].instanceIp)
        {
            /* External Interrupt Channel Configuration */
            (void)Siul2_Icu_Ip_Init((*pIpConfig)[index].instanceNo, \
                                    (*pIpConfig)[index].pSiul2HwIpConfig);
        }
#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)
        else if (ICU_WKPU_MODULE == (*pIpConfig)[index].instanceIp)
        {
            if((*pIpConfig)[index].pWkpuHwIpConfig->numChannels > 0U)
            {
                /* External WKPU Channels Configuration */
                (void)Wkpu_Ip_Init((*pIpConfig)[index].instanceNo, \
                                  (*pIpConfig)[index].pWkpuHwIpConfig);
            }
    #if (defined (WKPU_IP_NMI_API))
        #if (STD_ON == WKPU_IP_NMI_API)
            if((*pIpConfig)[index].pWkpuHwIpConfig->numNMIChannels > 0U)
            {
                /* NMI WKPU Channels Configuration */
                (void)Wkpu_Ip_InitNMI((*pIpConfig)[index].instanceNo, \
                                    (*pIpConfig)[index].pWkpuHwIpConfig);
            }
        #endif
    #endif
        }
#else
    #if (defined (WKPU_IP_NMI_API))
        #if (STD_ON == WKPU_IP_NMI_API)
        else if (ICU_WKPU_MODULE == (*pIpConfig)[index].instanceIp)
        {
            if((*pIpConfig)[index].pWkpuHwIpConfig->numNMIChannels > 0U)
            {
                /* NMI WKPU Channels Configuration */
                (void)Wkpu_Ip_InitNMI((*pIpConfig)[index].instanceNo, \
                                    (*pIpConfig)[index].pWkpuHwIpConfig);
            }
        }
        #endif
    #endif
#endif
        else if (ICU_FTM_MODULE == (*pIpConfig)[index].instanceIp)
        {
            (void)Ftm_Icu_Ip_Init((*pIpConfig)[index].instanceNo, \
                                        (*pIpConfig)[index].pFtmHwIpConfig);
        }
        else
        {
            /* Default do nothing. */
        }
    }
}

 #if (STD_ON == ICU_DE_INIT_API)
/**
* @brief              Icu_Ipw_DeInit
* @details            De-initialize ICU hardware channel
*
* @param[in]          pIpConfig - Pointer to ICU top configuration structure
*
* @return void
*
* @pre                Icu_Init must be called before.
*
*/
void Icu_Ipw_DeInit(uint8 count, const Icu_Ipw_IpConfigType (*pIpConfig)[])
{
    uint8 index;

    for(index = 0; index < count; index++)
    {
        /* External Interrupt Channel Configuration */
        if (ICU_SIUL2_MODULE == (*pIpConfig)[index].instanceIp)
        {
            /* DeInit entire IP - used with exclusive access */
            (void)Siul2_Icu_Ip_DeInit((*pIpConfig)[index].instanceNo);
        } 
#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI) 
        else if (ICU_WKPU_MODULE == (*pIpConfig)[index].instanceIp)
        {
            (void)Wkpu_Ip_DeInit((*pIpConfig)[index].instanceNo);
        }
#endif
        else if (ICU_FTM_MODULE == (*pIpConfig)[index].instanceIp)
        {
            (void)Ftm_Icu_Ip_DeInit((*pIpConfig)[index].instanceNo);
        }
        else
        {
            /* Default do nothing. */
        }
    }
}
#endif /* ICU_DE_INIT_API */

#if (ICU_SET_MODE_API == STD_ON)
/**
 * @brief Put the channel in a reduce power state.
 * @details    Set sleep mode
 * 
 * @param ChannelConfig - configuration of the channel
 *
 * @return void
 * @internal
 */
void Icu_Ipw_SetSleepMode(const Icu_Ipw_ChannelConfigType * ChannelConfig)
{
    uint8 channel;
    uint8 module = ChannelConfig->instanceNo;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
        case ICU_FTM_MODULE:
            {
                channel = (ChannelConfig->pFtmHwChannelConfig)->hwChannel;
                Ftm_Icu_Ip_SetSleepMode(module, channel);
            }
            break;
        case ICU_SIUL2_MODULE:
            {
                channel = (ChannelConfig->pSiul2HwChannelConfig)->hwChannel;
                Siul2_Icu_Ip_SetSleepMode(module, channel);
            }
            break;
#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)
        case ICU_WKPU_MODULE:
            {
                channel = (ChannelConfig->pWkpuHwChannelConfig)->hwChannel;
                Wkpu_Ip_SetSleepMode(module, channel);
            }
            break;
#endif
        default:
        {
            /* Do nothing. */
        }
        break;
    }
}

/**
 * @brief      Icu_Ipw_SetNormalMode
 * @details    Set normal mode
 *
 * @param[in]  ChannelConfig - The index of ICU channel for current configuration structure
 *
 * @return void
 * @internal
 */
void Icu_Ipw_SetNormalMode (const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    uint8 channel;
    uint8 module = ChannelConfig->instanceNo;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
        case ICU_FTM_MODULE:
            {
                channel = (ChannelConfig->pFtmHwChannelConfig)->hwChannel;
                Ftm_Icu_Ip_SetNormalMode(module, channel);
            }
            break;
        case ICU_SIUL2_MODULE:
            {
                channel = (ChannelConfig->pSiul2HwChannelConfig)->hwChannel;
                Siul2_Icu_Ip_SetNormalMode(module, channel);
            }
            break;
#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)
        case ICU_WKPU_MODULE:
            {
                channel = (ChannelConfig->pWkpuHwChannelConfig)->hwChannel;
                Wkpu_Ip_SetNormalMode(module, channel);
            }
            break;
#endif
        default:
            {
                /* Do nothing. */
            }
            break;
    }
}
#endif  /* ICU_SET_MODE_API */

/**
* @brief      Icu_Ipw_SetActivationCondition
 * @brief 
 * 
 * @param activation    - the type of activation for the ICU channel.
 * @param ChannelConfig - channel to be configured.
*
* @return void
*
*/
void Icu_Ipw_SetActivationCondition(Icu_ActivationType activation,
                                    const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    uint8 channel;
    uint8 module = ChannelConfig->instanceNo;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
        case ICU_FTM_MODULE:
            {
                channel = (ChannelConfig->pFtmHwChannelConfig)->hwChannel;
                if (ICU_FALLING_EDGE == activation)
                {
                    Ftm_Icu_Ip_SetActivationCondition(module, channel, FTM_ICU_FALLING_EDGE);
                }
                else if (ICU_RISING_EDGE == activation)
                {
                    Ftm_Icu_Ip_SetActivationCondition(module, channel, FTM_ICU_RISING_EDGE);
                }
                else if (ICU_BOTH_EDGES == activation)
                {
                    Ftm_Icu_Ip_SetActivationCondition(module, channel, FTM_ICU_BOTH_EDGES);
                }
                else
                {
                    Ftm_Icu_Ip_SetActivationCondition(module, channel, FTM_ICU_NO_PIN_CONTROL);
                }
            }
            break;
        case ICU_SIUL2_MODULE:
            {
                channel = (ChannelConfig->pSiul2HwChannelConfig)->hwChannel;
                if (ICU_FALLING_EDGE == activation)
                {
                    Siul2_Icu_Ip_SetActivationCondition(module, channel, SIUL2_ICU_FALLING_EDGE);
                }
                else if (ICU_RISING_EDGE == activation)
                {
                    Siul2_Icu_Ip_SetActivationCondition(module, channel, SIUL2_ICU_RISING_EDGE);
                }
                else if (ICU_BOTH_EDGES == activation)
                {
                    Siul2_Icu_Ip_SetActivationCondition(module, channel, SIUL2_ICU_BOTH_EDGES);
                }
                else
                {
                    Siul2_Icu_Ip_SetActivationCondition(module, channel, SIUL2_ICU_DISABLE);
                }
            }
            break;
#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)
        case ICU_WKPU_MODULE:
            {
                channel = (ChannelConfig->pWkpuHwChannelConfig)->hwChannel;
                if (ICU_FALLING_EDGE == activation)
                {
                    Wkpu_Ip_SetActivationCondition(module, channel, WKPU_IP_FALLING_EDGE);
                }
                else if (ICU_RISING_EDGE == activation)
                {
                    Wkpu_Ip_SetActivationCondition(module, channel, WKPU_IP_RISING_EDGE);
                }
                else if (ICU_BOTH_EDGES == activation)
                {
                    Wkpu_Ip_SetActivationCondition(module, channel, WKPU_IP_BOTH_EDGES);
                }
                else
                {
                    Wkpu_Ip_SetActivationCondition(module, channel, WKPU_IP_NONE_EDGE);
                }
            }
            break;
#endif /* WKPU_DERIVATIVE_SUPPORT_ONLY_NMI */
        default:
            {
                /* Do nothing. */
            }
            break;
    }
}

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief Service that returns the state of the ICU driver.
 * 
 * @param ChannelConfig 
 * @return boolean 
 */
boolean Icu_Ipw_GetInputState(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    boolean retState = FALSE;

    if (ICU_SIUL2_MODULE == ChannelConfig->channelIp)
    {
        retState = Siul2_Icu_Ip_GetInputState(ChannelConfig->instanceNo, \
                               (ChannelConfig->pSiul2HwChannelConfig)->hwChannel);
    }
#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)
    else if (ICU_WKPU_MODULE == ChannelConfig->channelIp)
    {
        retState = Wkpu_Ip_GetInputState(ChannelConfig->instanceNo, \
                               (ChannelConfig->pWkpuHwChannelConfig)->hwChannel);
    }
#endif
    else if (ICU_FTM_MODULE == ChannelConfig->channelIp)
    {
        retState = Ftm_Icu_Ip_GetInputState(ChannelConfig->instanceNo, \
                        (ChannelConfig->pFtmHwChannelConfig)->hwChannel);
    }
    else
    {
        retState = FALSE;
    }
    return (retState);
}
#endif /* ICU_GET_INPUT_STATE_API */

#if (STD_ON == ICU_TIMESTAMP_API)
void Icu_Ipw_StartTimestamp(const Icu_Ipw_ChannelConfigType* channelConfig,
                            uint16* bufferPtr,
                            uint16  bufferSize,
                            uint16  notifyInterval)
{
    /* Select IP type. */
    switch(channelConfig->channelIp)
    {
        case ICU_FTM_MODULE:
        {
            /* Call FTM start timestamp function. */
            Ftm_Icu_Ip_StartTimestamp(channelConfig->instanceNo,
                                      (channelConfig->pFtmHwChannelConfig)->hwChannel,
                                      bufferPtr,
                                      bufferSize,
                                      notifyInterval);
            break;
        }
        default:
        {
            /* Do nothing. */
            break;
        }
    }
}

void Icu_Ipw_StopTimestamp(const Icu_Ipw_ChannelConfigType *channelConfig)
{
    if (ICU_FTM_MODULE == channelConfig->channelIp)
    {
        /* Call FTM stop timestamp function. */
        Ftm_Icu_Ip_StopTimestamp(channelConfig->instanceNo, \
                            (channelConfig->pFtmHwChannelConfig)->hwChannel);
    }
}

Icu_IndexType Icu_Ipw_GetTimestampIndex(const Icu_Ipw_ChannelConfigType* channelConfig)
{
    Icu_IndexType timestampIndex = 0U;
    /* Select IP type. */
    switch(channelConfig->channelIp)
    {
        case ICU_FTM_MODULE:
        {
            timestampIndex = (Icu_IndexType)Ftm_Icu_Ip_GetTimestampIndex(channelConfig->instanceNo, \
                                            (channelConfig->pFtmHwChannelConfig)->hwChannel);
            break;
        }
        default:
        {
            /* Do nothing. */
            break;
        }
    }
    return timestampIndex;
}

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/**
* @brief Service that returns the address of the CV register of the FTM module.
* 
* @param ChannelConfig 
* @return uint32 
*/
uint32 Icu_Ipw_GetStartAddress(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    uint32 startAddr = 0U;
    /* Select IP type case. */
    if (ICU_FTM_MODULE == ChannelConfig->channelIp)
    {
        /* Get the address of the CV register of the FTM module. */
        startAddr = Ftm_Icu_Ip_GetStartAddress(ChannelConfig->instanceNo, \
                               (ChannelConfig->pFtmHwChannelConfig)->hwChannel);
    }
    return startAddr;
}
#endif  /* ICU_TIMESTAMP_USES_DMA == STD_ON */

#endif  /* ICU_TIMESTAMP_API == STD_ON */

#if (STD_ON == ICU_EDGE_COUNT_API)
void Icu_Ipw_ResetEdgeCount(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    /* Select IP type case. */
    if(ICU_FTM_MODULE == ChannelConfig->channelIp)
    {
        Ftm_Icu_Ip_ResetEdgeCount(ChannelConfig->instanceNo, \
                    (ChannelConfig->pFtmHwChannelConfig)->hwChannel);
    }
}

void Icu_Ipw_EnableEdgeCount(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    /* Select IP type case. */
    if(ICU_FTM_MODULE == ChannelConfig->channelIp)
    {
        (void)Ftm_Icu_Ip_EnableEdgeCount(ChannelConfig->instanceNo, \
                    (ChannelConfig->pFtmHwChannelConfig)->hwChannel);
    }
}

void Icu_Ipw_DisableEdgeCount(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    /* Select IP type case. */
    if(ICU_FTM_MODULE == ChannelConfig->channelIp)
    {
        (void)Ftm_Icu_Ip_DisableEdgeCount(ChannelConfig->instanceNo, \
                    (ChannelConfig->pFtmHwChannelConfig)->hwChannel);
    }
}

uint16 Icu_Ipw_GetEdgeNumbers(const Icu_Ipw_ChannelConfigType *ChannelConfig)
{
    uint16 edgeNumber = (uint16)0U;

    /* Select IP type case. */
    if(ICU_FTM_MODULE == ChannelConfig->channelIp)
    {
        edgeNumber = (uint16)Ftm_Icu_Ip_GetEdgeNumbers(ChannelConfig->instanceNo, \
                        (ChannelConfig->pFtmHwChannelConfig)->hwChannel);
    }
    else
    {
        edgeNumber = (uint16)0U;
    }

    return edgeNumber;
}
#endif  /* STD_ON == ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_EDGE_DETECT_API)
/**
 * @brief          Retrieve the number of edges
 *
 * @param[in]      nChannelNumber - The index of ICU channel for current configuration structure
 * @return         void
 */
void Icu_Ipw_EnableEdgeDetection(const Icu_Ipw_ChannelConfigType * ChannelConfig)
{
    uint8 channel;
    uint8 module = ChannelConfig->instanceNo;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
        case ICU_FTM_MODULE:
            {
                channel = (ChannelConfig->pFtmHwChannelConfig)->hwChannel;
                (void)Ftm_Icu_Ip_EnableEdgeDetection(module, channel);
            }
            break;
        case ICU_SIUL2_MODULE:
            {
                channel = (ChannelConfig->pSiul2HwChannelConfig)->hwChannel;
                Siul2_Icu_Ip_EnableInterrupt(module, channel);
            }
            break;
#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)
        case ICU_WKPU_MODULE:
            {
                channel = (ChannelConfig->pWkpuHwChannelConfig)->hwChannel;
                Wkpu_Ip_EnableInterrupt(module, channel);
            }
            break;
#endif
        default:
            {
                /* Do nothing. */
            }
            break;
    }
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/**
 * @brief 
 * 
 * @param ChannelConfig - channel configuration used.
 */
void Icu_Ipw_DisableEdgeDetection(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    uint8 channel;
    uint8 module = ChannelConfig->instanceNo;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
        case ICU_FTM_MODULE:
            {
                channel = (ChannelConfig->pFtmHwChannelConfig)->hwChannel;
                (void)Ftm_Icu_Ip_DisableEdgeDetection(module, channel);
            }
            break;
        case ICU_SIUL2_MODULE:
            {
                channel = (ChannelConfig->pSiul2HwChannelConfig)->hwChannel;
                (void)Siul2_Icu_Ip_DisableInterrupt(module, channel);
            }
            break;
#if !defined(WKPU_DERIVATIVE_SUPPORT_ONLY_NMI)
        case ICU_WKPU_MODULE:
            {
                channel = (ChannelConfig->pWkpuHwChannelConfig)->hwChannel;
                (void)Wkpu_Ip_DisableInterrupt(module, channel);
            }
            break;
#endif
        default:
            {
                /* Do nothing. */
            }
            break;
    }
}
#endif /* ICU_EDGE_DETECT_API */

#if ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF) && (ICU_VALIDATE_PARAMS == STD_ON))
#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
/**
 * @brief The function get the state of the overflow flag
 * @internal
 * @param ChannelConfig      Channel configuration pointer
 * @return      boolean      the state of the overflow flag
 * @retval      TRUE         the overflow flag is set
 * @retval      FALSE        the overflow flag is not set
 */
boolean Icu_Ipw_Get_Overflow(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    boolean channelOverflow = FALSE;
    if (ICU_FTM_MODULE == ChannelConfig->channelIp)
    {
        /* Check if FTM Module Overflow. */
        channelOverflow = (boolean)Ftm_Icu_Ip_GetOverflow(ChannelConfig->instanceNo);
    }
    return channelOverflow;
}
#endif
#endif

#if (STD_ON == ICU_GET_INPUT_LEVEL_API)
Icu_LevelType Icu_Ipw_GetInputLevel(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    Icu_LevelType   InputLevel;

    /* Select IP type case. */
    switch(ChannelConfig->channelIp)
    {
        case ICU_FTM_MODULE:
            {
                InputLevel = (Ftm_Icu_Ip_GetInputLevel(ChannelConfig->instanceNo, \
                                (ChannelConfig->pFtmHwChannelConfig)->hwChannel) == FTM_ICU_LEVEL_HIGH)?ICU_LEVEL_HIGH:ICU_LEVEL_LOW;
            }
            break;
        default:
            {
                InputLevel = ICU_LEVEL_LOW;
            }
            break;
    }

    return InputLevel;
}
#endif /* STD_ON == ICU_GET_INPUT_LEVEL_API */

#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON)))/**
 * @brief      Capture the value of counter register for a specified channel.
 * 
 * @details   The API shall return the value stored in capture register.
 *            The API is the equivalent of AUTOSAR API GetCaptureRegisterValue.
 * 
 * @param ChannelConfig      Channel configuration pointer
 * @return     uint32  Value of the register captured.
 */
Icu_ValueType Icu_Ipw_GetCaptureRegisterValue (const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    Icu_ValueType CaptureRegisterValue = (Icu_ValueType)0U;
    if (ICU_FTM_MODULE == ChannelConfig->channelIp)
    {
        /* Get FTM Module Capture Register Value */
        CaptureRegisterValue = (Icu_ValueType)Ftm_Icu_Ip_GetCaptureRegisterValue(ChannelConfig->instanceNo, \
                                    (ChannelConfig->pFtmHwChannelConfig)->hwChannel);
    }
    else
    {
        CaptureRegisterValue = (Icu_ValueType)0U;
    }
    return (CaptureRegisterValue);
}
#endif

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
void Icu_Ipw_StartSignalMeasurement (const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    if (ICU_FTM_MODULE == ChannelConfig->channelIp)
    {
        /* Start Signal Measurement. */
        Ftm_Icu_Ip_StartSignalMeasurement(ChannelConfig->instanceNo, \
                    (ChannelConfig->pFtmHwChannelConfig)->hwChannel);
    }
    else
    {
        /*do nothing*/
    }
}

void Icu_Ipw_StopSignalMeasurement(const Icu_Ipw_ChannelConfigType * ChannelConfig)
{
    if (ICU_FTM_MODULE == ChannelConfig->channelIp)
    {
        /* Start Signal Measurement. */
        Ftm_Icu_Ip_StopSignalMeasurement(ChannelConfig->instanceNo, \
                    (ChannelConfig->pFtmHwChannelConfig)->hwChannel);
    }
    else
    {
        /*do nothing*/
    }
}

#endif  /* STD_ON == ICU_SIGNAL_MEASUREMENT_API */

#if (STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API)
void Icu_Ipw_GetDutyCycleValues(const Icu_Ipw_ChannelConfigType* channelConfig,
                                Icu_DutyCycleType* DutyCycleValues)
{
    /* Select IP type case. */
    switch(channelConfig->channelIp)
    {
        case ICU_FTM_MODULE:
        {
            Ftm_Icu_Ip_DutyCycleType ftmDutyCycleValues = {0, 0};
            Ftm_Icu_Ip_GetDutyCycleValues(channelConfig->instanceNo, \
                                          (channelConfig->pFtmHwChannelConfig)->hwChannel, \
                                          &ftmDutyCycleValues);
            DutyCycleValues->ActiveTime = (Icu_ValueType)ftmDutyCycleValues.ActiveTime;
            DutyCycleValues->PeriodTime = (Icu_ValueType)ftmDutyCycleValues.PeriodTime;

            break;
        }
        default:
        {  
            /* Do nothing. */          
        }
        break;
    }
}
#endif /* STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API */

#if (STD_ON == ICU_GET_TIME_ELAPSED_API)
Icu_ValueType Icu_Ipw_GetTimeElapsed(const Icu_Ipw_ChannelConfigType* channelConfig)
{
    uint16 timeElapsed;
    /* Select IP type case. */
    switch(channelConfig->channelIp)
    {
        case ICU_FTM_MODULE:
        {
            timeElapsed = Ftm_Icu_Ip_GetTimeElapsed(channelConfig->instanceNo, \
                                                   (channelConfig->pFtmHwChannelConfig)->hwChannel);
            break;
        }
        default:
        {
            timeElapsed = 0U;
            break;
        }
    }
    return (Icu_ValueType)timeElapsed;
}

#endif /* STD_ON == ICU_GET_TIME_ELAPSED_API */

#if (STD_ON == ICU_DUAL_CLOCK_MODE_API)
/**
 * @brief This function sets the module prescalers based on the input mode.
 * 
 * @param moduleConfig 
 * @param selectPrescaler Prescaler type ( Normal or Alternate )
 * @param modulesNumber 
 */
void Icu_Ipw_SetClockMode(const Icu_Ipw_IpConfigType (*moduleConfig)[], Icu_SelectPrescalerType selectPrescaler, uint8 modulesNumber)
{
    uint8              index;
    uint8              module;
    Icu_Ipw_ModuleType ipType;

    for(index = 0; index < modulesNumber; index++)
    {
        ipType = (*moduleConfig)[index].instanceIp;
        module = (*moduleConfig)[index].instanceNo;

        /* Select IP type case. */
        switch(ipType)
        {
            case ICU_FTM_MODULE:
                {
                    Ftm_Icu_Ip_SetPrescaler(module, \
                        (selectPrescaler == ICU_ALTERNATE_CLOCK_MODE)?FTM_ICU_ALTERNATE_CLK:FTM_ICU_NORMAL_CLK);
                }
                break;
            case ICU_SIUL2_MODULE:
                {
                    Siul2_Icu_Ip_SetClockMode(module, \
                        (selectPrescaler == ICU_ALTERNATE_CLOCK_MODE)?SIUL2_ICU_ALTERNATE_CLK:SIUL2_ICU_NORMAL_CLK);
                }
                break;
            default:
                {
                    /* Do nothing. */
                }
                break;
        }
    }
}
#endif /* STD_ON == ICU_DUAL_CLOCK_MODE_API */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON))
Icu_Ipw_StatusType Icu_Ipw_ValidateGetInputLevel(const Icu_Ipw_ChannelConfigType * ChannelConfig)
{
    Icu_Ipw_ModuleType  ipType = ChannelConfig->channelIp;
    Icu_Ipw_StatusType result = ICU_IPW_ERROR;

    /* Select IP type case. */
    if(ICU_FTM_MODULE == ipType)
    {
        result = ICU_IPW_SUCCESS;
    }
    return result;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON */

void Icu_Ipw_EnableNotification(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    uint8 channel;
    uint8 module = ChannelConfig->instanceNo;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
        case ICU_FTM_MODULE:
        {
            channel = (ChannelConfig->pFtmHwChannelConfig)->hwChannel;
            Ftm_Icu_Ip_EnableNotification(module, channel);
            break;
        }
        default:
        {
            /* Do nothing. */
        }
        break;
    }
}

void Icu_Ipw_DisableNotification(const Icu_Ipw_ChannelConfigType* ChannelConfig)
{
    uint8 channel;
    uint8 module = ChannelConfig->instanceNo;
    Icu_Ipw_ModuleType ipType = ChannelConfig->channelIp;

    /* Select IP type case. */
    switch(ipType)
    {
        case ICU_FTM_MODULE:
        {
            channel = (ChannelConfig->pFtmHwChannelConfig)->hwChannel;
            Ftm_Icu_Ip_DisableNotification(module, channel);
            break;
        }
        default:
        {
            /* Do nothing. */
        }
        break;
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
