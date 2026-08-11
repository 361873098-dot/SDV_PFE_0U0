/* =========================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.4.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.4.0_D2405_ASR_REL_4_4_REV_0000_20240528
 *
 * Original code: https://www.pixelbeat.org/programming/gcc/static_assert.html
 * Licensed under the GNU All-Permissive License.
 *
 * Modifications Copyright 2018-2022 NXP
 *
 * ========================================================================= */
 
#ifndef CT_ASSERT_H
#define CT_ASSERT_H

/*==================================================================================================
*                                     FILE VERSION CHECK
==================================================================================================*/
#ifdef PFE_SRC_VERSION_CHECK
    #if (PFE_SRC_VERSION_CHECK != 43140440)
        #error "This header file was included from incompatible source file (different SW version)"
    #endif
#else
    #define PFE_SRC_VERSION_CHECK 43140440
#endif

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define ASSERT_CONCAT_(a, b) a##b
#define ASSERT_CONCAT(a, b) ASSERT_CONCAT_(a, b)

#define ct_assert(e) enum { ASSERT_CONCAT(precompile_assert_, __COUNTER__) = (1/(!!(e))) }

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
    /* The compiler options for MCAL driver generate errors or warnings when offsetof is used inside of ct_assert.
    So it is not possible to assert offset of structures at compile time for MCAL driver.
    This is done at runtime in test case Eth_43_PFE_TC_CT_ASSERT in test suite Eth_43_PFE_TS_017.
    Therefore ct_assert_offsetof is a dummy implementation on MCAL driver.
    */
    #define ct_assert_offsetof(e) enum { ASSERT_CONCAT(precompile_assert_, __COUNTER__) = 1 } 
#else
    #define ct_assert_offsetof(e) enum { ASSERT_CONCAT(precompile_assert_, __COUNTER__) = 1/(!!(e)) }
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

#endif /* CT_ASSERT_H */
