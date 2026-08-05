/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Platform_Ipw_Cfg.h"
#include "IntCtrl_Ip.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_IPW_CFG_VENDOR_ID_C                     43
#define CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION_C      4
#define CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION_C              4
#define CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION_C              0
#define CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION_C              2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Ipw_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_IPW_CFG_VENDOR_ID_C != CDD_PLATFORM_IPW_CFG_VENDOR_ID)
    #error "Platform_Ipw_Cfg.c and Platform_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw_Cfg.c and Platform_Ipw_Cfg.h are different"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw_Cfg.c and Platform_Ipw_Cfg.h are different"
#endif

/* Check if current file and IntCtrl_Ip header file are of the same vendor */
#if (CDD_PLATFORM_IPW_CFG_VENDOR_ID_C != CDD_PLATFORM_INTCTRL_IP_VENDOR_ID)
    #error "Platform_Ipw_Cfg.c and IntCtrl_Ip.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw_Cfg.c and IntCtrl_Ip.h are different"
#endif
/* Check if current file and IntCtrl_Ip header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw_Cfg.c and IntCtrl_Ip.h are different"
#endif

[!NOCODE!]
[!VAR "McmAvailable" = "0"!]
[!IF "GeneralConfiguration/PlatformMcmConfigurable"!]
    [!IF "count(McmConfig/*) > 0"!]
        [!VAR "McmAvailable" = "1"!]
    [!ENDIF!]
[!ENDIF!]
[!VAR "IntCtrlAvailable" = "0"!]
[!IF "count(IntCtrlConfig/*) > 0"!]
    [!VAR "IntCtrlAvailable" = "1"!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!NOCODE!]


[!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]


/* Variable storing number of maximum partitions using in configuration */
[!VAR "numPartition" = "0"!]

[!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
    [!SELECT "node:ref(./OsApplicationCoreRef)"!]
        [!IF "$numPartition < node:value(./EcucCoreId)"!]
            [!VAR "numPartition" = "node:value(./EcucCoreId)"!]
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDLOOP!]

[!VAR "numPartition" = "$numPartition + 1"!]

[!FOR "CurrentCoreId" = "0" TO "$numPartition - 1"!]
    [!VAR "CoreIdConfigured" = "0"!]
    [!LOOP "GeneralConfiguration/PlatformEcucPartitionRef/*"!]
        [!VAR "CurrentPartitionRefName" = "node:value(.)"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionRefName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
            [!IF "$CurrentPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                    [!IF "$CurrentCoreId = node:value(./EcucCoreId)"!]                    
                        [!VAR "CoreIdConfigured" = "1"!]
                        [!VAR "PartitionShortName" = "$CurrentPartitionShortName"!]
                        [!VAR "PartitionRefName" = "$CurrentPartitionRefName"!]
                    [!ENDIF!]
                [!ENDSELECT!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]
[!IF "$CoreIdConfigured = 1"!]
[!CODE!]
/*================================== Partition [!"$PartitionShortName"!] ==================================*/
[!ENDCODE!]
[!VAR "McmConfigAvailable" = "0"!]
[!IF "$McmAvailable = 1"!] /* System settings */
    [!VAR "McmConfigAvailable" = "0"!]
    [!LOOP "McmConfig/*"!]
        [!IF "./PlatformMcmEcucPartitionRef = $PartitionRefName "!]
            [!VAR "McmConfigAvailable" = "1"!]
            [!CODE!]
#if (PLATFORM_SYS_CFG == STD_ON)
/* List of configurations for CM7 system interrupts */
[!IF "count(./SystemIsrConfig/*) > 0"!][!//
static const Platform_SystemIrqConfigType aSysIrqCfg[!"$PartitionShortName"!][] = {[!LOOP "SystemIsrConfig/*"!]
    { [!"SystemIsrName"!], (boolean)[!IF "SystemIsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!] },[!ENDLOOP!]
};
[!ENDIF!][!//
/* system configurations for [!"$PartitionShortName"!]*/
static const Platform_SystemConfigType SystemConfig[!"$PartitionShortName"!] = 
{
[!IF "count(./SystemIsrConfig/*) > 0"!][!//
    aSysIrqCfg[!"$PartitionShortName"!], 
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
    [!"num:dectoint(count(./SystemIsrConfig/*))"!]U, 
    (boolean)[!IF "SystemAhbSlavePrio = 'Round_robin'"!]FALSE[!ELSE!]TRUE[!ENDIF!]
};
#endif
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDIF!]

[!VAR "NvicConfigAvailable" = "0"!]
[!LOOP "IntCtrlConfig/*"!]
    [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
        [!VAR "NvicConfigAvailable" = "1"!]
    [!ENDIF!]
[!ENDLOOP!]    

[!CODE!]
/* Definition of the configuration structure for Platform IPW */
const Platform_Ipw_ConfigType ipwConfig[!"$PartitionShortName"!] = {
    [!IF "$NvicConfigAvailable = 1"!]&intCtrlConfig[!"$PartitionShortName"!][!ELSE!]NULL_PTR[!ENDIF!], /* Interrupt controller configuration */
    [!IF "$McmConfigAvailable = 1"!]&SystemConfig[!"$PartitionShortName"!][!ELSE!]NULL_PTR[!ENDIF!] /* System settings */
};
/*================================== End Partition [!"$PartitionShortName"!] ==============================*/



[!ENDCODE!]

[!ENDIF!]
[!ENDFOR!]

[!ELSE!][!//multicore
    [!IF "$McmAvailable = 1"!] /* System settings */
    [!SELECT "McmConfig/*[1]"!]
        [!CODE!]
#if (PLATFORM_SYS_CFG == STD_ON)
/* List of configurations for CM7 system interrupts */
[!IF "count(./SystemIsrConfig/*) > 0"!][!//
static const Platform_SystemIrqConfigType aSysIrqCfg[] = {[!LOOP "SystemIsrConfig/*"!]
    { [!"SystemIsrName"!], (boolean)[!IF "SystemIsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!] },[!ENDLOOP!]
};
[!ENDIF!][!//
/* system configurations */
static const Platform_SystemConfigType SystemConfig = 
{ 
[!IF "count(./SystemIsrConfig/*) > 0"!][!//
    aSysIrqCfg,
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
    [!"num:dectoint(count(./SystemIsrConfig/*))"!]U, 
    (boolean)[!IF "SystemAhbSlavePrio = 'Round_robin'"!]FALSE[!ELSE!]TRUE[!ENDIF!]
};
#endif
        [!ENDCODE!]
    [!ENDSELECT!]
    [!ENDIF!]
    [!CODE!]
/* Definition of the configuration structure for Platform IPW */
const Platform_Ipw_ConfigType ipwConfig = {
    [!IF "$IntCtrlAvailable = 1"!]&intCtrlConfig[!ELSE!]NULL_PTR[!ENDIF!], /* Interrupt controller configuration */
    [!IF "$McmAvailable = 1"!]&SystemConfig[!ELSE!]NULL_PTR[!ENDIF!] /* System settings */
};
    [!ENDCODE!]

[!ENDIF!][!//multicore
[!ENDNOCODE!]
#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
