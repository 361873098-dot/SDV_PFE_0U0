
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

[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ocotp_Types.h"
#include "Ocotp_Cfg.h"
#include "Ocotp_Ip_Types.h"
#include "Ocotp_Ip_Cfg.h"
[!ENDINDENT!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]VENDOR_ID_CFG_C                      43
#define OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MINOR_VERSION_CFG_C       4
#define OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_REVISION_VERSION_CFG_C    0
#define OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MAJOR_VERSION_CFG_C               4
#define OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MINOR_VERSION_CFG_C               0
#define OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_PATCH_VERSION_CFG_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ocotp_Ip_Types header file are of the same vendor */
#if (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]VENDOR_ID_CFG_C != OCOTP_IP_TYPES_VENDOR_ID)
    #error "Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Ip_Types header file are of the same Autosar version */
#if ((OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MAJOR_VERSION_CFG_C    != OCOTP_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MINOR_VERSION_CFG_C    != OCOTP_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_REVISION_VERSION_CFG_C != OCOTP_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Ip_Types.h are different"
#endif
/* Check if current file and Ocotp_Ip_Types header file are of the same Software version */
#if ((OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MAJOR_VERSION_CFG_C != OCOTP_IP_TYPES_SW_MAJOR_VERSION) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MINOR_VERSION_CFG_C != OCOTP_IP_TYPES_SW_MINOR_VERSION) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_PATCH_VERSION_CFG_C != OCOTP_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Ip_Types.h are different"
#endif


/* Check if current file and Ocotp_Type header file are of the same vendor */
#if (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]VENDOR_ID_CFG_C != OCOTP_TYPES_VENDOR_ID)
    #error "Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Types.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Type header file are of the same Autosar version */
#if ((OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MAJOR_VERSION_CFG_C    != OCOTP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MINOR_VERSION_CFG_C    != OCOTP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_REVISION_VERSION_CFG_C != OCOTP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Types.h are different"
#endif
/* Check if current file and Ocotp_Type header file are of the same Software version */
#if ((OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MAJOR_VERSION_CFG_C != OCOTP_TYPES_SW_MAJOR_VERSION) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MINOR_VERSION_CFG_C != OCOTP_TYPES_SW_MINOR_VERSION) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_PATCH_VERSION_CFG_C != OCOTP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Types.h are different"
#endif

/* Check if current file and Ocotp_Cfg header file are of the same vendor */
#if (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]VENDOR_ID_CFG_C != OCOTP_VENDOR_ID_CFG)
    #error "Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Cfg header file are of the same Autosar version */
#if ((OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MAJOR_VERSION_CFG_C    != OCOTP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MINOR_VERSION_CFG_C    != OCOTP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_REVISION_VERSION_CFG_C != OCOTP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Cfg.h are different"
#endif
/* Check if current file and Ocotp_Cfg header file are of the same Software version */
#if ((OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MAJOR_VERSION_CFG_C != OCOTP_SW_MAJOR_VERSION_CFG) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MINOR_VERSION_CFG_C != OCOTP_SW_MINOR_VERSION_CFG) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_PATCH_VERSION_CFG_C != OCOTP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Cfg.h are different"
#endif

/* Check if current file and Ocotp_Ip_Cfg header file are of the same vendor */
#if (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]VENDOR_ID_CFG_C != OCOTP_IP_VENDOR_ID_CFG)
    #error "Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ocotp_Ip_Cfg header file are of the same Autosar version */
#if ((OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MAJOR_VERSION_CFG_C    != OCOTP_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_MINOR_VERSION_CFG_C    != OCOTP_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]AR_RELEASE_REVISION_VERSION_CFG_C != OCOTP_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Ip_Cfg.h are different"
#endif
/* Check if current file and Ocotp_Ip_Cfg header file are of the same Software version */
#if ((OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MAJOR_VERSION_CFG_C != OCOTP_IP_SW_MAJOR_VERSION_CFG) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_MINOR_VERSION_CFG_C != OCOTP_IP_SW_MINOR_VERSION_CFG) || \
     (OCOTP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]SW_PATCH_VERSION_CFG_C != OCOTP_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Ocotp_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ocotp_Ip_Cfg.h are different"
#endif

[!INCLUDE "Ocotp_VersionCheck.m"!][!//
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
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define OCOTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocotp_MemMap.h"

static const Ocotp_ChannelConfigType Ocotp_ConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pChanelConfig[[!"num:i(count(OcotpChannelList/OcotpChannel/*))"!]] =
{
[!VAR "OcotpLoopIt" = "count(OcotpChannelList/OcotpChannel/*)"!][!//
[!LOOP "node:order(OcotpChannelList/OcotpChannel/*,'node:value(./OcotpChannelNumber)')"!][!//
[!VAR "OcotpLoopIt" = "$OcotpLoopIt - 1"!][!//
    {
[!NOCODE!][!//
    [!VAR "EFuseAddress" = "num:inttohex(num:hextoint(substring-before(text:grep(ecu:list('Ocotp.FuseMap'),concat('^[0-9a-zA-Z]+_', node:fallback(./OcotpWord, 'NONE'),'.*'))[1],'_')))"!]
    [!VAR "StartEfuseAddress" = "num:inttohex(num:hextoint('0x200'))"!]
    [!VAR "IndexShadowRegister" = "num:hextoint($EFuseAddress) - num:hextoint($StartEfuseAddress)"!]
    [!VAR "IndexShadowRegister" = "$IndexShadowRegister div 4"!]
    [!VAR "IndexShadowRegister" = "num:i($IndexShadowRegister)"!]

    [!VAR "LockValue"="num:i('0')"!]
    [!VAR "LockFuseAddress"="'0xFFFFFFFF'"!]
    [!VAR "LockShiftValue"="'0xFF'"!]
    [!IF "text:contains(text:join(ecu:list('Ocotp.FuseLock')), node:fallback(./OcotpWord,'NONE'))"!]
        [!VAR "LockFuseAddress"="num:inttohex(num:hextoint(substring-before(text:grep(ecu:list('Ocotp.FuseLock'),concat('^[0-9a-fA-F]+_[0-9a-fA-F]+_', node:fallback(./OcotpWord,'NONE')))[1],'_')))"!]
        [!VAR "LockShiftValue"="num:i(text:split(text:grep(ecu:list('Ocotp.FuseLock'),concat('^[0-9a-fA-F]+_[0-9a-fA-F]+_', node:fallback(./OcotpWord,'NONE')))[1],'_')[2])"!]
    [!ENDIF!]
    [!IF "node:value(./OcotpReadProtectionEnabled) = 'true'"!]
        [!VAR "LockValue"="bit:or($LockValue, 1)"!]
    [!ENDIF!]
    [!IF "node:value(./OcotpWriteProtectionEnabled) = 'true'"!]
        [!VAR "LockValue"="bit:or($LockValue, 2)"!]
    [!ENDIF!]
    [!VAR "LockValue"="num:i(bit:shl($LockValue,$LockShiftValue))"!]

    [!IF "node:value(./OcotpCrcEnable) = 'true'"!]
        [!VAR "CRCFuseStartAddress" = "num:inttohex(num:hextoint(substring-before(text:grep(ecu:list('Ocotp.FuseMap'),concat('^[0-9a-zA-Z]+_', node:fallback(./OcotpCRCTestRegionStart, 'NONE'),'.*'))[1],'_')))"!]
        [!VAR "CRCFuseEndAddress" = "num:inttohex(num:hextoint(substring-before(text:grep(ecu:list('Ocotp.FuseMap'),concat('^[0-9a-zA-Z]+_', node:fallback(./OcotpCRCTestRegionEnd, 'NONE'),'.*'))[1],'_')))"!]
        [!VAR "CRCFuseWordAddress" = "num:inttohex(num:hextoint(substring-before(text:grep(ecu:list('Ocotp.FuseMap'),concat('^[0-9a-zA-Z]+_', node:fallback(./OcotpCRCTestFuseWord, 'NONE'),'.*'))[1],'_')))"!]
    [!ELSE!]
        [!VAR "CRCFuseStartAddress"="num:inttohex(num:hextoint('FFFFFFFF'))"!]
        [!VAR "CRCFuseEndAddress"="num:inttohex(num:hextoint('FFFFFFFF'))"!]
        [!VAR "CRCFuseWordAddress"="num:inttohex(num:hextoint('FFFFFFFF'))"!]
    [!ENDIF!]
[!ENDNOCODE!][!//
        (Ocotp_AddressType)[!"$EFuseAddress"!]U, /* Ocotp_EFuseAddress */
        (uint32)[!"$IndexShadowRegister"!]U, /* Ocotp_ShadowIndex */
        (Ocotp_AddressType)[!"$LockFuseAddress"!]U, /* Ocotp_LockFuseAddress */
        (Ocotp_AddressType)[!"$CRCFuseStartAddress"!]U, /* Ocotp_StartCRCAddress */
        (Ocotp_AddressType)[!"$CRCFuseEndAddress"!]U, /* Ocotp_EndCRCAddress */
        (Ocotp_AddressType)[!"$CRCFuseWordAddress"!]U, /* Ocotp_CRCFuseAddress */
        (uint8)[!"./OcotpChannelNumber"!]U, /* Ocotp_ChannelNumber */
        (uint8)[!"node:when(node:exists(./OcotpGPRegisterIndex) = 'true', ./OcotpGPRegisterIndex, '0xFF')"!]U, /* Ocotp_GPRegisterIndex */
[!IF "ecu:get('Ocotp.SupportStickyRegister') = 'true'"!][!//
        (uint8)[!"node:when(node:exists(./OcotpSTRRegisterIndex) = 'true', ./OcotpSTRRegisterIndex, '0xFF')"!]U, /* Ocotp_STRRegisterIndex */
[!ENDIF!][!//
        (uint32)[!"$LockValue"!]U, /* Ocotp_LockValue */
        (Ocotp_InstanceType)[!"node:value(node:ref(./OcotpHwRef)/OcotpInstance)"!]U, /* Ocotp_Instance */
        (boolean)[!IF "./OcotpWriteOperationBlockingEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* Ocotp_WriteBlocking */
        (boolean)[!IF "./OcotpEccProtectionEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!] /* Ocotp_EccEnable */
    }[!IF "$OcotpLoopIt != 0"!],[!ENDIF!][!//

[!ENDLOOP!][!//
};

[!IF "node:value(OcotpGeneral/OcotpEnableMultiCore) = 'true'"!]
[!LOOP "node:order(OcotpConfigList/OcotpHwUnit/*,'node:value(./OcotpHardwareIndex)')"!][!//
[!VAR "OcotpChannelCoreUsed"="num:i(255)"!][!//
[!NOCODE!][!//
    [!VAR "OcotpPartitionInstance"="node:value(./OcotpEcucPartitionRef)"!]
    [!VAR "OcotpPartitionInstanceError"="text:split($OcotpPartitionInstance,'/')[5]"!]
    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
        [!IF "node:value(./OsAppEcucPartitionRef) = $OcotpPartitionInstance"!]
            [!VAR "OcotpChannelCoreUsed"="node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$OcotpChannelCoreUsed = 255"!]
        [!ERROR!]"Os appication does not config core for [!"$OcotpPartitionChannelError"!]"[!ENDERROR!]
    [!ENDIF!]
[!ENDNOCODE!][!//
const uint32 Ocotp_ConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pMulticoreConfig = (uint32)[!"$OcotpChannelCoreUsed"!]U;
[!ENDLOOP!][!//
[!ENDIF!]

const Ocotp_ConfigType Ocotp_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /*ip config*/
    &Ocotp_ConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pHwConfig,
    /*Channel config*/
    &Ocotp_ConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pChanelConfig
[!IF "node:value(OcotpGeneral/OcotpEnableMultiCore) = 'true'"!][!//
    /* Multicore config */
    ,&Ocotp_ConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pMulticoreConfig
[!ENDIF!][!//
};
#define OCOTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocotp_MemMap.h"
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
