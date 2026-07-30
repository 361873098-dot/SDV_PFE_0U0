
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

#ifndef OCOTP_TYPES_H
#define OCOTP_TYPES_H

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
#include "StandardTypes.h"
#include "Ocotp_Ip_Types.h"
#include "Ocotp_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_TYPES_VENDOR_ID                    43
#define OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define OCOTP_TYPES_AR_RELEASE_MINOR_VERSION     4
#define OCOTP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define OCOTP_TYPES_SW_MAJOR_VERSION             4
#define OCOTP_TYPES_SW_MINOR_VERSION             0
#define OCOTP_TYPES_SW_PATCH_VERSION             2
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (OCOTP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Ocotp_Types.c and StandardTypes.h are different"
    #endif
#endif

/* Check if current file and Ocotp_Ip_Types.h header file are of the same vendor */
#if (OCOTP_TYPES_VENDOR_ID != OCOTP_IP_TYPES_VENDOR_ID)
    #error "Ocotp_Types.h and Ocotp_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Ip_Types.h header file are of the same AutoSar version */
#if ((OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION != OCOTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION ) || \
     (OCOTP_TYPES_AR_RELEASE_MINOR_VERSION != OCOTP_IP_TYPES_AR_RELEASE_MINOR_VERSION ) || \
     (OCOTP_TYPES_AR_RELEASE_REVISION_VERSION != OCOTP_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_Types.h and Ocotp_Ip_Types.h are different"
#endif
/* Check if current file and Ocotp_Ip_Types.h header file are of the same Software version */
#if ((OCOTP_TYPES_SW_MAJOR_VERSION != OCOTP_IP_TYPES_SW_MAJOR_VERSION) || \
     (OCOTP_TYPES_SW_MINOR_VERSION != OCOTP_IP_TYPES_SW_MINOR_VERSION) || \
     (OCOTP_TYPES_SW_PATCH_VERSION != OCOTP_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_Types.h and Ocotp_Ip_Types.h are different"
#endif

/* Check if current file and Ocotp_Cfg.h header file are of the same vendor */
#if (OCOTP_TYPES_VENDOR_ID != OCOTP_VENDOR_ID_CFG)
    #error "Ocotp_Types.h and Ocotp_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Cfg.h header file are of the same AutoSar version */
#if ((OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION != OCOTP_AR_RELEASE_MAJOR_VERSION_CFG ) || \
     (OCOTP_TYPES_AR_RELEASE_MINOR_VERSION != OCOTP_AR_RELEASE_MINOR_VERSION_CFG ) || \
     (OCOTP_TYPES_AR_RELEASE_REVISION_VERSION != OCOTP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "Software Version Numbers of Ocotp_Types.h and Ocotp_Cfg.h are different"
#endif
/* Check if current file and Ocotp_Cfg.h header file are of the same Software version */
#if ((OCOTP_TYPES_SW_MAJOR_VERSION != OCOTP_SW_MAJOR_VERSION_CFG) || \
     (OCOTP_TYPES_SW_MINOR_VERSION != OCOTP_SW_MINOR_VERSION_CFG) || \
     (OCOTP_TYPES_SW_PATCH_VERSION != OCOTP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Ocotp_Types.h and Ocotp_Cfg.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
* @brief          Ocotp ECC error type.
*/
/* @implements Ocotp_EccErrorType_enumeration */
typedef enum
{
    OCOTP_ECC_SINGLE_ERROR = 0U,             /*!< ECC single error corect  */
    OCOTP_ECC_DOUBLE_ERROR,                  /*!< ECC double error dectect */
    OCOTP_ECC_NO_ERROR                       /*!< ECC no error occurred    */
}Ocotp_EccErrorType;

/**
* @brief          Ocotp mode operation.
*/
/* @implements Ocotp_ModeType_enumeration */
typedef enum
{
    OCOTP_NORMAL_MODE     = 0U,              /*!< normal mode     */
    OCOTP_POWERDOWN_MODE                     /*!< power down mode */
}Ocotp_ModeType;

/**
* @brief          Status of Ocotp hardware.
*/
/* @implements Ocotp_HardwareStatusType_enumeration */
typedef enum
{
    OCOTP_HARDWARE_BUSY       = 0u,         /*!< Status of hardware is busy  */
    OCOTP_HARDWARE_ERROR,                   /*!< Status of hardware is error */
    OCOTP_HARDWARE_IDLE                     /*!< Status of hardware is idle  */
}Ocotp_HardwareStatusType;
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Ocotp address type.
* @details        Adrress of a register.
*/
typedef uint32 Ocotp_AddressType;

/**
* @brief          Ocotp channel type.
* @details        An integer which is used to describe the order of channel configured.
*/
/* @implements Ocotp_ChannelType_typedef */
typedef uint8 Ocotp_ChannelType;

/**
* @brief          Ocotp channel configuration type.
* @details        A structure which is used to contain the parameters of channel used.
                  Such as address of eFuse. Index of shadow register.
*/
/* @implements Ocotp_ChannelConfigType_structure */
typedef struct
{
    Ocotp_AddressType       Ocotp_EFuseAddress;        /*!< Address of Efuse */
    uint32                  Ocotp_ShadowIndex;         /*!< Index of Shadow register */
    Ocotp_AddressType       Ocotp_LockFuseAddress;     /*!< Address of Lock Efuse */
    Ocotp_AddressType       Ocotp_StartCRCAddress;     /*!< Start eFuse address for CRC calculation */
    Ocotp_AddressType       Ocotp_EndCRCAddress;       /*!< End eFuse address for CRC calculation */
    Ocotp_AddressType       Ocotp_CRCFuseAddress;      /*!< CRC eFuse address used for comparison in CRC test */
    uint8                   Ocotp_ChannelNumber;       /*!< Channel number */
    uint8                   Ocotp_GPRegisterIndex;     /*!< Index of GP register */
#ifdef OCOTP_READ_STICKY_INFORMATION_API
    uint8                   Ocotp_STRRegisterIndex;    /*!< Index of Sticky register */
#endif
    uint32                  Ocotp_LockValue;           /*!< Lock value */
    Ocotp_InstanceType      Ocotp_Instance;            /*!< Instance Index */
    boolean                 Ocotp_WriteBlocking;       /*!< Write blocking */
    boolean                 Ocotp_EccEnable;           /*!< ECC Enable */
}Ocotp_ChannelConfigType;

/**
* @brief          Ocotp configuration type.
* @details        A structure which is used to contain the hardware configuration
                  and the configuration of channels used.
*/
/* @implements Ocotp_ConfigType_structure */
typedef struct
{
    const Ocotp_Ip_ConfigType *pHwConfig;              /*!< User configuration structure */
    const Ocotp_ChannelConfigType (*pChanelConfig)[];  /*!< Ocotp channel configuration type */
#if (OCOTP_MULTICORE_SUPPORT == STD_ON)
    const uint32 *pMulticoreConfig;                    /*!< Multicore configuration */
#endif
}Ocotp_ConfigType;

/**
* @brief          Ocotp status type.
* @details        A structure which is used to contain the status of hardware
                  (Busy or idle or errors occurred) and status of repair error flag(If FBXC exists).
*/
/* @implements Ocotp_StatusType_structure */
typedef struct
{
    Ocotp_HardwareStatusType   HardwareStatus;
}Ocotp_StatusType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* OCOTP_TYPES_H */
