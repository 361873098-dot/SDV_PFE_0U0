/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32_RTD_4_0_0_D2210_ASR_REL_4_4_REV_0000_20221031
*
*   (c) Copyright 2022 NXP Semiconductors
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
*   @file Xrdc_Ip_PBcfg.c
*
*   @addtogroup XRDC_IP XRDC IPV Driver
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
#include "Xrdc_Ip_Types.h"
#include "Xrdc_Ip_Cfg.h"
#include "Xrdc_Ip_Device_Registers.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XRDC_IP_PBCFG_VENDOR_ID_C                     43
#define RM_XRDC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_XRDC_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      4
#define RM_XRDC_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define RM_XRDC_IP_PBCFG_SW_MAJOR_VERSION_C              4
#define RM_XRDC_IP_PBCFG_SW_MINOR_VERSION_C              0
#define RM_XRDC_IP_PBCFG_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Xrdc_Ip_Types.h */
#if (RM_XRDC_IP_PBCFG_VENDOR_ID_C != RM_XRDC_IP_TYPES_VENDOR_ID)
    #error "Xrdc_Ip_PBcfg.c and Xrdc_Ip_Types.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XRDC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XRDC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XRDC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Types.h are different"
#endif
#if ((RM_XRDC_IP_PBCFG_SW_MAJOR_VERSION_C != RM_XRDC_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_MINOR_VERSION_C != RM_XRDC_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_PATCH_VERSION_C != RM_XRDC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Types.h are different"
#endif

/* Checks against Xrdc_Ip_Cfg.h */
#if (RM_XRDC_IP_PBCFG_VENDOR_ID_C != RM_XRDC_IP_CFG_VENDOR_ID)
    #error "Xrdc_Ip_PBcfg.c and Xrdc_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XRDC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Cfg.h are different"
#endif
#if ((RM_XRDC_IP_PBCFG_SW_MAJOR_VERSION_C != RM_XRDC_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_MINOR_VERSION_C != RM_XRDC_IP_CFG_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_PATCH_VERSION_C != RM_XRDC_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Cfg.h are different"
#endif

/* Checks against Xrdc_Ip_Device_Registers.h */
#if (RM_XRDC_IP_PBCFG_VENDOR_ID_C != RM_XRDC_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Xrdc_Ip_PBcfg.c and Xrdc_Ip_Device_Registers.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XRDC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XRDC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XRDC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Device_Registers.h are different"
#endif
#if ((RM_XRDC_IP_PBCFG_SW_MAJOR_VERSION_C != RM_XRDC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_MINOR_VERSION_C != RM_XRDC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_PATCH_VERSION_C != RM_XRDC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Device_Registers.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/



/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      BUFFER DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   STATE STRUCTURE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

static const Xrdc_Ip_MemConfigType Xrdc_Memory_Config[23] =
{
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC2 will be used to control the address range below */
        XRDC_MRC2,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)1UL,
        /*Start address for XRDC_MRC2 controller and descriptor 1 */
        (uint32)54722560UL,
        /*End address for XRDC_MRC2 controller and descriptor 1 */
        (uint32)54788095UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC5 will be used to control the address range below */
        XRDC_MRC5,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)2UL,
        /*Start address for XRDC_MRC5 controller and descriptor 2 */
        (uint32)55771136UL,
        /*End address for XRDC_MRC5 controller and descriptor 2 */
        (uint32)55836671UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)229824UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC7 will be used to control the address range below */
        XRDC_MRC7,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)5UL,
        /*Start address for XRDC_MRC7 controller and descriptor 5 */
        (uint32)0UL,
        /*End address for XRDC_MRC7 controller and descriptor 5 */
        (uint32)33554431UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC9 will be used to control the address range below */
        XRDC_MRC9,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC9 controller and descriptor 0 */
        (uint32)84410368UL,
        /*End address for XRDC_MRC9 controller and descriptor 0 */
        (uint32)84475903UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC12 will be used to control the address range below */
        XRDC_MRC12,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC12 controller and descriptor 0 */
        (uint32)83886080UL,
        /*End address for XRDC_MRC12 controller and descriptor 0 */
        (uint32)84410367UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)504UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC0 will be used to control the address range below */
        XRDC_MRC0,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC0 controller and descriptor 0 */
        (uint32)100663296UL,
        /*End address for XRDC_MRC0 controller and descriptor 0 */
        (uint32)25769803775UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)32312UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC8 will be used to control the address range below */
        XRDC_MRC8,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC8 controller and descriptor 0 */
        (uint32)70254592UL,
        /*End address for XRDC_MRC8 controller and descriptor 0 */
        (uint32)71303167UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)258496UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC6 will be used to control the address range below */
        XRDC_MRC6,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC6 controller and descriptor 0 */
        (uint32)84148224UL,
        /*End address for XRDC_MRC6 controller and descriptor 0 */
        (uint32)84344831UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)29176UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC6 will be used to control the address range below */
        XRDC_MRC6,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)1UL,
        /*Start address for XRDC_MRC6 controller and descriptor 1 */
        (uint32)73400320UL,
        /*End address for XRDC_MRC6 controller and descriptor 1 */
        (uint32)74448895UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select Memory region controller XRDC_MRC2 will be used to control the address range below */
        XRDC_MRC2,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC2 controller and descriptor 0 */
        (uint32)134217728UL,
        /*End address for XRDC_MRC2 controller and descriptor 0 */
        (uint32)268435455UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)28728UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select Memory region controller XRDC_MRC4 will be used to control the address range below */
        XRDC_MRC4,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC4 controller and descriptor 0 */
        (uint32)67108864UL,
        /*End address for XRDC_MRC4 controller and descriptor 0 */
        (uint32)74448895UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)229880UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select Memory region controller XRDC_MRC2 will be used to control the address range below */
        XRDC_MRC2,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)1UL,
        /*Start address for XRDC_MRC2 controller and descriptor 1 */
        (uint32)54525952UL,
        /*End address for XRDC_MRC2 controller and descriptor 1 */
        (uint32)54657023UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)28672UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select Memory region controller XRDC_MRC2 will be used to control the address range below */
        XRDC_MRC2,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)2UL,
        /*Start address for XRDC_MRC2 controller and descriptor 2 */
        (uint32)70254592UL,
        /*End address for XRDC_MRC2 controller and descriptor 2 */
        (uint32)71303167UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)28672UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC6 will be used to control the address range below */
        XRDC_MRC6,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)2UL,
        /*Start address for XRDC_MRC6 controller and descriptor 2 */
        (uint32)100663296UL,
        /*End address for XRDC_MRC6 controller and descriptor 2 */
        (uint32)268435455UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC13 will be used to control the address range below */
        XRDC_MRC13,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC13 controller and descriptor 0 */
        (uint32)85786624UL,
        /*End address for XRDC_MRC13 controller and descriptor 0 */
        (uint32)85786879UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)229824UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select Memory region controller XRDC_MRC0 will be used to control the address range below */
        XRDC_MRC0,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC0 controller and descriptor 0 */
        (uint32)37748736UL,
        /*End address for XRDC_MRC0 controller and descriptor 0 */
        (uint32)54525951UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC10 will be used to control the address range below */
        XRDC_MRC10,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC10 controller and descriptor 0 */
        (uint32)67403776UL,
        /*End address for XRDC_MRC10 controller and descriptor 0 */
        (uint32)67436543UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC10 will be used to control the address range below */
        XRDC_MRC10,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)1UL,
        /*Start address for XRDC_MRC10 controller and descriptor 1 */
        (uint32)100663296UL,
        /*End address for XRDC_MRC10 controller and descriptor 1 */
        (uint32)25769803775UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC4 will be used to control the address range below */
        XRDC_MRC4,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)1UL,
        /*Start address for XRDC_MRC4 controller and descriptor 1 */
        (uint32)54853632UL,
        /*End address for XRDC_MRC4 controller and descriptor 1 */
        (uint32)54854143UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)504UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC2 will be used to control the address range below */
        XRDC_MRC2,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC2 controller and descriptor 0 */
        (uint32)54525952UL,
        /*End address for XRDC_MRC2 controller and descriptor 0 */
        (uint32)54591487UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)262080UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC5 will be used to control the address range below */
        XRDC_MRC5,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC5 controller and descriptor 0 */
        (uint32)55574528UL,
        /*End address for XRDC_MRC5 controller and descriptor 0 */
        (uint32)55705599UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select Memory region controller XRDC_MRC9 will be used to control the address range below */
        XRDC_MRC9,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)1UL,
        /*Start address for XRDC_MRC9 controller and descriptor 1 */
        (uint32)84475904UL,
        /*End address for XRDC_MRC9 controller and descriptor 1 */
        (uint32)84541439UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select Memory region controller XRDC_MRC5 will be used to control the address range below */
        XRDC_MRC5,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for XRDC_MRC5 controller and descriptor 0 */
        (uint32)74448896UL,
        /*End address for XRDC_MRC5 controller and descriptor 0 */
        (uint32)74481663UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        (uint32)0x00000000UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)504UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    }
};

static const Xrdc_Ip_PeripheralConfigType Xrdc_Peripheral_Config[18] =
{
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_EDMA_0_CONTROL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_EDMA_1_CONTROL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)504UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_HSE_MU0,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)4088UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_HSE_MU1,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)4088UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_HSE_MU2,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)233408UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_HSE_MU3,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)233408UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_QUADSPI,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_USDHC,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_LINFLEX_0,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)504UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_LINFLEX_1,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)229824UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_DDRSS_0,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)28728UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_GMAC_0,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_CAN_0,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)229880UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_CAN_1,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)229880UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_CAN_2,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_CAN_3,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_SEMA42,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)229824UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    },
    {
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)XRDC_PCIE_APB,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)56UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0UL
    }
};

static const Xrdc_Ip_DomainConfigType Xrdc_Domain_Config[XRDC_NUM_DOMAIN_CONFIG] =
{
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN1,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC0,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_CORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN1,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC1,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_CORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN1,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC20,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_NON_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN1,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC3,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_NON_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN1,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC6,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN1,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC7,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN1,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC12,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN1,
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC7,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN1,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC5,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN2,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC8,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_CORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN2,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC16,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_CORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN2,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC19,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN3,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC11,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN4,
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC5,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN4,
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC6,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN4,
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC1,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN4,
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC3,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN4,
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC4,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN4,
        /*XRDC instance */
        XRDC_INSTANCE1,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC2,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_INPUT_FROM_BUS_MASTER,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN5,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC9,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_CORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    },
    {
        /*Valid DomainID from 0 - 7 */
        XRDC_DOMAIN5,
        /*XRDC instance */
        XRDC_INSTANCE0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC17,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_CORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
		/*Domain ID bypass. If master is core master this field should be omitted*/
		XRDC_MDA_DID_BYPASS_USED,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER,
        /*Selection of descriptor for current master core. If master is non-core master this field should ignore*/
        XRDC_WORD0
    }
};

static const uint32 Xrdc_Instances_InUsed[2] =
{
    XRDC_INSTANCE0, XRDC_INSTANCE1
};


const Xrdc_Ip_ConfigType Xrdc_Config =
{
    Xrdc_Domain_Config,
    (uint32)21UL,
    Xrdc_Memory_Config,
    (uint32)23UL,
    Xrdc_Peripheral_Config,
    (uint32)18UL,
    Xrdc_Instances_InUsed,
    (uint32)2UL
};


#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

