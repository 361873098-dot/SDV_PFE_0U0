/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SERDES_SS
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors

==================================================================================================*/

#ifndef SERDES_IP_TYPES_H
#define SERDES_IP_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
====================================================================================================*/
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SERDES_IP_TYPES_VENDOR_ID                    43
#define SERDES_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define SERDES_IP_TYPES_AR_RELEASE_MINOR_VERSION     4
#define SERDES_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define SERDES_IP_TYPES_SW_MAJOR_VERSION             4
#define SERDES_IP_TYPES_SW_MINOR_VERSION             0
#define SERDES_IP_TYPES_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h file are of the same Autosar version */
    #if ((SERDES_IP_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SERDES_IP_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Serdes_Ip_Types.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef enum
{
    SERDES_CLK_100MHZ = 0,
    SERDES_CLK_125MHZ
}Serdes_Ip_ClockType;

typedef enum
{
    PCIE_X2            = 0U,         /* PCIe X2*/
    PCIE_SGMII_XPCS_0  = 1U,   /* PCIe/SGMII mode 1 */
    PCIE_SGMII_XPCS_1  = 2U,   /* PCIe/SGMII mode 2 */
    SGMII_MODE_3       = 3U,        /* SGMII X2  mode 3 - PHY owned by XPCS0 */
    SGMII_MODE_4       = 4U        /* SGMII X2 mode 4 - PHY owned by XPCS1 */
}Serdes_Ip_ModeType;

typedef enum
{
    SERDES_MAC_SPEED_INVALID,
    SERDES_MAC_SPEED_10_MBPS,
    SERDES_MAC_SPEED_100_MBPS,
    SERDES_MAC_SPEED_1000_MBPS,
    SERDES_MAC_SPEED_2500_MBPS
} Serdes_Ip_MacSpeedType;

typedef enum
{
    SERDES_MAC_DUPLEX_INVALID,
    SERDES_MAC_DUPLEX_HALF,
    SERDES_MAC_DUPLEX_FULL
} Serdes_Ip_MacDuplexType;

typedef  enum
{
    SERDES_IP_SUCCESS = 0,
    SERDES_IP_BUSY,
    SERDES_IP_ERROR
}Serdes_Ip_StatusType;

typedef enum
{
    SERDES_IP_JOB_INIT = 0U,
    SERDES_IP_JOB_BRING_OUT_OF_RESET,
    SERDES_IP_JOB_ISSUE_VRESET,
    SERDES_IP_JOB_WAIT_FIRST_VRESET,
    SERDES_IP_JOB_WAIT_SECOND_VRESET,
    SERDES_IP_JOB_WAIT_LINK_UP,
    SERDES_IP_JOB_FINISHED
}Serdes_Ip_JobType;

typedef enum
{
    SERDES_IP_XPCS_POWER_UNKNOWN,
    SERDES_IP_XPCS_POWER_UP,
    SERDES_IP_XPCS_POWER_SAVE,
    SERDES_IP_XPCS_POWER_DOWN
} Serdes_Ip_XpcsModeType;

typedef enum
{
    SERDES_IP_JOB_DONE     = 1U,
    SERDES_IP_JOB_PENDING  = 2U,
    SERDES_IP_JOB_FAILED   = 4U
}Serdes_Ip_JobResultType;


typedef struct
{
    boolean LoopbackEnabled;                    /* Loopback of PMA enabled */
    Serdes_Ip_MacSpeedType XpcsSpeed;           /* XPCS speed */
    Serdes_Ip_MacDuplexType XpcsDuplex;         /* XPCS duplex */
    boolean XpcsAN;                             /* XPCS autonegotiation */
}Serdes_Ip_XpcsConfigType;

typedef struct
{
    uint32 PhyReferenceClock;                   /* Internal or external clock */
    Serdes_Ip_ClockType SerdesRefClock;         /* 100 MHz or 125 MHz */
    Serdes_Ip_ModeType SerdesMode;              /* Functional mode of Serdes (eg. PCIE_X2, SGMII, SERDES_PCIE_XPCS_0) */
    const Serdes_Ip_XpcsConfigType* XPCS0;      /* Configuration for XPCS0 */
    const Serdes_Ip_XpcsConfigType* XPCS1;      /* Configuration for XPCS1 */
}Serdes_Ip_ConfigType;

typedef struct
{
    Serdes_Ip_StatusType DriverStatus;
    Serdes_Ip_JobResultType JobResult;
    Serdes_Ip_JobType Job;
    Serdes_Ip_XpcsModeType XPCSMode;
    const Serdes_Ip_ConfigType * SerdesCfg;
}Serdes_Ip_StateType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*SERDES_IP_TYPES_H*/

/** @} */
