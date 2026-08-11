/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : VR5510
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
* @file    Wdg_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.c
*
* @addtogroup  Wdg_VR5510
* @{
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
#include "Wdg_43_VR5510_CfgExt.h"
#include "Wdg_43_VR5510_Cfg.h"
#include "Pmic_VR55XX_Types.h"
#include "Gpt.h"

[!INCLUDE "Wdg_VR5510_VersionCheck_Src_PB.m"!][!//
[!INCLUDE "Wdg_VR5510_PluginMacros.m"!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                    43
#define WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C     4
#define WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C             4
#define WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C             0
#define WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C             2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg_43_VR5510_CfgExt header file are of the same vendor */
#if (WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != WDG_43_VR5510_CFG_EXT_VENDOR_ID)
    #error "Wdg_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.c and Wdg_43_VR5510_CfgExt.h have different vendor ids"
#endif

/* Check if source file Wdg_43_VR5510_CfgExt Wdg header file are of the same Autosar version */
#if ((WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != WDG_43_VR5510_CFG_EXT_AR_RELEASE_MAJOR_VERSION) || \
(WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != WDG_43_VR5510_CFG_EXT_AR_RELEASE_MINOR_VERSION) || \
(WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != WDG_43_VR5510_CFG_EXT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.c and Wdg_43_VR5510_CfgExt.h are different"
#endif
/* Check if source file Wdg_43_VR5510_CfgExt Wdg header file are of the same Software version */
#if ((WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != WDG_43_VR5510_CFG_EXT_SW_MAJOR_VERSION) || \
(WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != WDG_43_VR5510_CFG_EXT_SW_MINOR_VERSION) || \
(WDG_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != WDG_43_VR5510_CFG_EXT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_43_VR5510[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCfg.c and Wdg_43_VR5510_CfgExt.h are different"
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
[!IF "node:exists(WdgGeneral/WdgCheckFaultStatusNotification)"!]
#define WDG_43_VR5510_START_SEC_CODE
#include "Wdg_43_VR5510_MemMap.h"

/**
* @brief            Export the watchdog task check fault status notification function configured by the user.
*/
extern void [!"normalize-space(WdgGeneral/WdgCheckFaultStatusNotification)"!](const uint16 u16RegValue);

#define WDG_43_VR5510_STOP_SEC_CODE
#include "Wdg_43_VR5510_MemMap.h"
[!ENDIF!][!//

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

#define WDG_43_VR5510_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"
[!NOCODE!]
[!CODE!][!//
static const Wdg_VR55xx_ConfigType Wdg_VR5510_OffModeSettings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* The FS_I_WD_CFG configuration. */
    (((uint16)0x0000U)
        | PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_LIMIT_U16((uint16)[!"num:i(num:i((num:i(8) - num:i(substring-after(./WdgSettingsConfig/WdgErrorCounterLimit,'MAX_'))) div num:i(2)))"!]U)
        | PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_U16((uint16)[!"num:i(num:i((num:i(7) - num:i(substring-after(./WdgSettingsConfig/WdgRefreshCounterLimit,'MAX_'))) div num:i(2)))"!]U)
        | PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_U16(PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_[!"node:value(./WdgSettingsConfig/WdgErrorImpact)"!]_SELECT_U16)
    ),
    /* The FS_WDW_DURATION register configuration. */
    (((uint16)0x0000U)
        | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_50_0_SELECT_U16)
        | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_[!IF "node:value(./WdgSettingsConfig/WdgRecoveryWindowPeriod) = 'DISABLE'"!]DISABLE_SELECT_U16[!ELSE!][!"substring-after(./WdgSettingsConfig/WdgRecoveryWindowPeriod,'TIME_')"!]_SELECT_U16[!ENDIF!])
        | PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16)
    ),
    /* The FS_WD_SEED configuration. */
    (uint16)[!"num:inttohex(./WdgSettingsConfig/WdgServiceKeyValue)"!]U,
    /* The timer value */
    (uint32)0U
};

static const Wdg_VR55xx_ConfigType Wdg_VR5510_SlowModeSettings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!IF "node:value(./WdgSettingsConfig/WdgDefaultMode) = 'WDGIF_SLOW_MODE'"!][!//
[!CALL "WdgModeConfig","WdgMode" = "'WdgSettingsSlow'","isDefautMode" = "'true'"!][!//
[!ELSE!][!//
[!CALL "WdgModeConfig","WdgMode" = "'WdgSettingsSlow'","isDefautMode" = "'false'"!][!//
[!ENDIF!][!//
};

static const Wdg_VR55xx_ConfigType Wdg_VR5510_FastModeSettings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!IF "node:value(./WdgSettingsConfig/WdgDefaultMode) = 'WDGIF_FAST_MODE'"!][!//
[!CALL "WdgModeConfig","WdgMode" = "'WdgSettingsFast'","isDefautMode" = "'true'"!]
[!ELSE!][!//
[!CALL "WdgModeConfig","WdgMode" = "'WdgSettingsFast'","isDefautMode" = "'false'"!]
[!ENDIF!][!//
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//


const Wdg_43_VR5510_ConfigType Wdg_VR5510_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!NOCODE!][!//
[!INDENT "4"!]
[!CODE!][!//
    /* Default mode configuration. */
    [!"node:value(./WdgSettingsConfig/WdgDefaultMode)"!],
    /*ID of PMIC device. */
    [!"node:value(node:ref(./WdgSettingsConfig/WdgPmicdeviceRef)/PmicDeviceId)"!]U,
    /* Gpt Channel configured */
    (Gpt_ChannelType)GptConf_GptChannelConfiguration_[!"text:split(./WdgSettingsConfig/WdgExternalTriggerCounterRef,'/')[5]"!],
    /* The frequency of the configured timer channel */
    (uint32)[!"num:i(num:i(node:value(node:ref(./WdgSettingsConfig/WdgExternalTriggerCounterRef)/GptChannelTickFrequency)) div 1000)"!]U,
    /* Pointer to Watchdog Specific implementation details */
#if (WDG_43_VR5510_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            &Wdg_VR5510_DemConfig,
#endif
    /* Array mode configuration. */
    {&Wdg_VR5510_OffModeSettings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], &Wdg_VR5510_SlowModeSettings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], &Wdg_VR5510_FastModeSettings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]},
    /* Task notification allows customer handler the error fault of PMIC device through value of FS_G_FLAG */
    [!IF "node:exists(WdgGeneral/WdgCheckFaultStatusNotification)"!]&[!"normalize-space(WdgGeneral/WdgCheckFaultStatusNotification)"!][!ELSE!]NULL_PTR[!ENDIF!]
[!ENDCODE!][!//
[!ENDINDENT!]
[!ENDNOCODE!][!//
};

#define WDG_43_VR5510_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_43_VR5510_MemMap.h"
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
