/**
 *  @file             autolibc.c
 *  @brief            Custom implementation of some standard functions from libc
 *  @note             Functions are safe, as far as given pointers (with respect
 *                    to their lengths) point to valid memory ranges and strings
 *                    (except for strncpy) are zero terminated. Also avoid arrays
 *                    occupying last 4 bytes of address space (0xFFFFFFFB to
 *                    0xFFFFFFFF). Some functions (strlen, strcpy...) are in some
 *                    cases reading up to 3 bytes behind terminating nul byte.
 *  @details          This module provides some of standard functions usually
 *                    provided by a compiler library set. Module is intended to
 *                    provide only functions necessary for compilation of other
 *                    modules. All functions here are optimized for 32-bit PPC.
 */
/*==============================================================================
 *  Project              : AUTOSAR 4.4 MCAL
 *  Platform             : CORTEXM
 *  Peripheral           : PFE
 *  Dependencies         : none
 *
 *  Autosar Version      : 4.4.0
 *  Autosar Revision     : ASR_REL_4_4_REV_0000
 *  Autosar Conf.Variant :
 *  SW Version           : 1.2.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.2.0_D2307_ASR_REL_4_4_REV_0000_20230728
 *
 *  Copyright (c) 2012-2016 Freescale Semiconductor Inc.
 *  Copyright 2016-2018, 2020-2023 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *  <<< PFE Restricted Software >>>
 *
==============================================================================*/
/*==============================================================================
==============================================================================*/

/*==============================================================================
                               MISRA VIOLATIONS
==============================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

/*==============================================================================
                                INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==============================================================================*/
#include "pfe_cfg.h"
#include "oal.h"

#include "autolibc.h"
#ifdef AUTOLIB_TESTING
    #include "addresschecker.h"
#endif

/*==============================================================================
                             FILE VERSION CHECKS
==============================================================================*/

/*==============================================================================
                                 LOCAL MACROS
==============================================================================*/
#define UINT_SIZE (4U)

/* WARNING, all OPT_LENGTHs must be at least 3 not to cause errors */
#define MEMCPY_OPT_LENGTH   (0x00000009u)  /* 9B optimal length for non-aligned data */
#define MEMMOVE_OPT_LENGTH  (0x00000008u)  /* 8B optimal length for non-aligned data */
#define MEMSET_OPT_LENGTH   (0x00000007u)  /* 7B optimal length for non-aligned data */
#define MEMCMP_OPT_LENGTH   (0x0000001Au)  /* 26B optimal length for non-aligned data */
#define STRNCPY_OPT_LENGTH  (0x00000008u)  /* 8B optimal length for non-aligned data */

/*==============================================================================
                  LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==============================================================================*/

/*==============================================================================
                               LOCAL CONSTANTS
==============================================================================*/

/*==============================================================================
                               LOCAL VARIABLES
==============================================================================*/

/*==============================================================================
                               GLOBAL CONSTANTS
==============================================================================*/

/*==============================================================================
                               GLOBAL VARIABLES
==============================================================================*/
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

/*==============================================================================
                           LOCAL FUNCTION PROTOTYPES
==============================================================================*/
static inline int32_t fsl_memcmp_aux( const void *pcoavMemA1,
                               const void *pcoavMemB1,
                               uint32_t u32Size1
                             );
/*==============================================================================
                                LOCAL FUNCTIONS
==============================================================================*/
/*
* @brief Compares two memory blocks byte by byte
* @details This function is version of memcmp not optimized to compare long
*          blocks of memory. It is intended to be called from memcmp function
*          to compare very short parts of long blocks.
* @param[in] pcoavMemA1 The first block to be compared
* @param[in] pcoavMemB1 The second block to be compared
* @param[in] u32Size1 Number of bytes to be compared
* @return 0 if both blocks are equal, difference pcoavMemA1[]-pcoavMemB1[]
*         of first not matching bytes otherwise.
*/
static inline int32_t fsl_memcmp_aux( const void *pcoavMemA1,
                               const void *pcoavMemB1,
                               uint32_t u32Size1
                             )
{
    const uint8_t *pcoau8MemA1 = (const uint8_t *)pcoavMemA1;
    const uint8_t *pcoau8MemB1 = (const uint8_t *)pcoavMemB1;
    uint32_t u32Ctr1;
    int32_t s32Result1 = 0;

    for ( u32Ctr1=0U; u32Ctr1 < u32Size1; u32Ctr1++ )
    {
#ifdef AUTOLIB_TESTING
        CA_Check2( &pcoau8MemA1[u32Ctr1], \
                   &pcoau8MemB1[u32Ctr1], \
                   sizeof(*pcoau8MemA1)
                 );
#endif
        s32Result1 =(int32_t)pcoau8MemA1[u32Ctr1]-(int32_t)pcoau8MemB1[u32Ctr1];
        if ( s32Result1 != 0 )
        {
            break;
        }
    }
    return s32Result1;
}
/*==============================================================================
                                GLOBAL FUNCTIONS
==============================================================================*/

/**
* @brief Copies data from one memory region to another one.
* @details Function copies data from one memory region to another one. Memory
*          regions must not overlap and the size of destination region must be
*          greater than or equal to size of the source region.
*          Copy operation is optimized for any alignment of source or
*          destination data.
* @param[out] pavDest2 Copy destination
* @param[in] pcoavSource2 Source data pointer
* @param[in] u32Length2 Number of bytes to be copied
* @return Pointer to the destination memory (equals pavDest2)
* @note Function does not handle overlap and overflow.
*/
void *autolibc_memcpy(void *pavDest2, const void *pcoavSource2, uint32_t u32Length2)
{
    uint32_t u32TempLength2=u32Length2;
    uint32_t u32Ctr2;
    uint32_t u32IntCount2;
    uint8_t  u8ShiftDif;

    /* BYTE pointers */
    uint8_t *pau8Dst2 = (uint8_t *)pavDest2;
    const uint8_t *pcoau8Src2 = (const uint8_t *)pcoavSource2;

    uint16_t       *pau16Dst2;
    const uint16_t *pcoau16Src2;
    uint32_t       *pau32Dst2;
    const uint32_t *pcoau32Src2;

#ifdef AUTOLIB_TESTING
    /* init access address checking */
    CA_SetTest( 2U, 1U );
    /* set ranges */
    CA_SetRange1( (uaddr_t)pavDest2,   u32Length2, 1U);
    CA_SetRange2( (uaddr_t)pcoavSource2, u32Length2, 0U);
#endif

    /* too short for optimizations, copy along 1B */
    if ( u32Length2 < MEMCPY_OPT_LENGTH )
    {
        for (u32Ctr2 = 0U; u32Ctr2 < u32Length2; u32Ctr2++)
        {
#ifdef AUTOLIB_TESTING
            CA_Check2( &pau8Dst2[u32Ctr2], \
                       &pcoau8Src2[u32Ctr2], \
                       sizeof(*pau8Dst2)
                     );
#endif
            pau8Dst2[u32Ctr2] = pcoau8Src2[u32Ctr2];
        }
    }
    else
    { /* optimized copying */
        u32Ctr2 = 0U;
        /* Compute offset between pointers. We are only interested in last 2 bits, so uint8_t is enough */
        /* warning - convertion to smaller type (lost of higher bytes) - required behaviour here */
        u8ShiftDif = (uint8_t)((uaddr_t)pavDest2 - (uaddr_t)pcoavSource2);
        /* Check whether offset between pointers is multiple of 4 (last 2 bits are zero) */
        if ( 0U == (u8ShiftDif & 3U) )
        { /* copy along 4B */
            while ( 0U != (((uaddr_t)(&pau8Dst2[u32Ctr2])) & 3U) )
            { /* copy first unaligned part of data */
#ifdef AUTOLIB_TESTING
                CA_Check2( &pau8Dst2[u32Ctr2], \
                           &pcoau8Src2[u32Ctr2], \
                           sizeof(*pau8Dst2)
                         );
#endif
                pau8Dst2[u32Ctr2] = pcoau8Src2[u32Ctr2];
                u32Ctr2++;
            }

            pau32Dst2 = (uint32_t *)(&pau8Dst2[u32Ctr2]);
            pcoau32Src2 = (const uint32_t *)(&pcoau8Src2[u32Ctr2]);
            /* update u32TempLength2 to be copied */
            /* u32TempLength2 is >= MIN_OPT_LENGTH here, u32Ctr2 is at most 3 */
            u32TempLength2 -= u32Ctr2;
            u32IntCount2 = u32TempLength2 >> 2U; /* = u32TempLength2 / 4U */
            /* copy integer aligned part of data */
            for ( u32Ctr2 = 0U; u32Ctr2 < u32IntCount2 ; u32Ctr2++ )
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( (uint8_t *)&pau32Dst2[u32Ctr2], \
                           (const uint8_t *)&pcoau32Src2[u32Ctr2], \
                           sizeof(*pau32Dst2)
                         );
#endif
                pau32Dst2[u32Ctr2] = pcoau32Src2[u32Ctr2];
            }
            /* copy the last unaligned bytes (if any) */
            pau8Dst2 = (uint8_t *)(&pau32Dst2[u32Ctr2]);
            pcoau8Src2 = (const uint8_t *)(&pcoau32Src2[u32Ctr2]);
            u32TempLength2 -= u32Ctr2 * UINT_SIZE; /* update u32TempLength2 to be copied */
            for ( u32Ctr2 = 0U; u32Ctr2 < u32TempLength2; u32Ctr2++ )
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( &pau8Dst2[u32Ctr2], \
                           &pcoau8Src2[u32Ctr2], \
                           sizeof(*pau8Dst2)
                         );
#endif
                pau8Dst2[u32Ctr2] = pcoau8Src2[u32Ctr2];
            }
        }
        /* Check whether offset between pointers is multiple of 2 (last 1 bit is zero) */
        else if ( 0U == (u8ShiftDif & 1U) )
        {   /* Copy along 2B */
            if ( 0U != (((uaddr_t)(&pau8Dst2[u32Ctr2])) & 1U) )
            { /* copy first unaligned part of data */
#ifdef AUTOLIB_TESTING
                CA_Check2( &pau8Dst2[u32Ctr2], \
                           &pcoau8Src2[u32Ctr2], \
                           sizeof(*pau8Dst2)
                         );
#endif
                pau8Dst2[u32Ctr2] = pcoau8Src2[u32Ctr2];
                u32Ctr2++;
            }
            /* copy 2B aligned part of data */
            pau16Dst2 = (uint16_t *)(&pau8Dst2[u32Ctr2]);
            pcoau16Src2 = (const uint16_t *)(&pcoau8Src2[u32Ctr2]);
            /* update u32TempLength2 to be copied */
            /* u32TempLength2 is >= MIN_OPT_LENGTH here, u32Ctr2 is at most 3 */
            u32TempLength2 -= u32Ctr2;
            u32IntCount2 = u32TempLength2 >> 1U; /* = u32TempLength2 / 2U */
            for ( u32Ctr2 = 0U; u32Ctr2 < u32IntCount2; u32Ctr2++ )
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( (uint8_t *)&pau16Dst2[u32Ctr2], \
                           (const uint8_t *)&pcoau16Src2[u32Ctr2], \
                           sizeof(*pau16Dst2)
                         );
#endif
                pau16Dst2[u32Ctr2] = pcoau16Src2[u32Ctr2];
            }

            /* copy the last unaligned byte (if any) */
            pau8Dst2 = (uint8_t *)(&pau16Dst2[u32Ctr2]);
            pcoau8Src2 = (const uint8_t *)(&pcoau16Src2[u32Ctr2]);
            u32TempLength2 -= u32Ctr2 * (UINT_SIZE>>1U); /* update u32TempLength2 to be copied */
            for ( u32Ctr2 = 0U; u32Ctr2 < u32TempLength2; u32Ctr2++ )
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( (uint8_t *)&pau8Dst2[u32Ctr2], \
                           (const uint8_t *)&pcoau8Src2[u32Ctr2], \
                           sizeof(*pau8Dst2)
                         );
#endif
                pau8Dst2[u32Ctr2] = pcoau8Src2[u32Ctr2];
            }
        }
        /* any other shifting */
        else
        {
            /* copying along 1B */
            while ((u32TempLength2-u32Ctr2) > 0U)
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( &pau8Dst2[u32Ctr2], \
                           &pcoau8Src2[u32Ctr2], \
                           sizeof(*pau8Dst2)
                         );
#endif
                pau8Dst2[u32Ctr2] = pcoau8Src2[u32Ctr2];
                u32Ctr2++;
            }
        }
    }
    return pavDest2;
}


/**
* @brief Fills the memory block with a given byte value.
* @details Function writes a given byte value into all bytes in a given
*          memory area. Uses optimized algorithm and handles all alignment
*          of destination buffer.
* @param[out] pavDest3 Beginning of the memory block to be filled
* @param[in] s32Fill3 Value to be used as fill
* @param[in] u32Length3 Number of bytes to be filled
* @return Pointer to the filled block.
*/
void *autolibc_memset(void *pavDest3, int32_t s32Fill3, uint32_t u32Length3)
{
    uint32_t u32TempLength3=u32Length3;
    uint32_t u32Ctr3;
    uint32_t u32IntCount3;
    uint32_t u32Fill3;
    uint8_t u8Fill3 = (uint8_t)s32Fill3;
    /* BYTE pointer */
    uint8_t  *pau8Dst3 = (uint8_t *)pavDest3;
    /* INTEGER pointer */
    uint32_t *pau32Dst3;

#ifdef AUTOLIB_TESTING
    /* init access address checking */
    CA_SetTest( 1U, 0U );
    /* set range */
    CA_SetRange1( (uaddr_t)pavDest3,   u32Length3, 1U);
#endif
    /* too short for optimizations */
    if ( u32Length3 < MEMSET_OPT_LENGTH )
    {
        for (u32Ctr3 = 0U; u32Ctr3 < u32Length3; u32Ctr3++)
        {
#ifdef AUTOLIB_TESTING
            CA_Check1( &pau8Dst3[u32Ctr3], \
                       sizeof(*pau8Dst3)
                     );
#endif
            pau8Dst3[u32Ctr3] = u8Fill3;
        }
    }
    /* optimized code */
    else
    {
        u32Ctr3 = 0U;
        /* filling along 4B */
        while ( 0U != ((uaddr_t)(&pau8Dst3[u32Ctr3]) & 3U) )
        { /* set first unaligned bytes */
#ifdef AUTOLIB_TESTING
            CA_Check1( &pau8Dst3[u32Ctr3], \
                       sizeof(*pau8Dst3)
                     );
#endif
            pau8Dst3[u32Ctr3] = u8Fill3;
            u32Ctr3++;
        }
        /* write integer aligned part of data */
        pau32Dst3 = (uint32_t *)(&pau8Dst3[u32Ctr3]);
        /* update u32TempLength3 to be copied */
        /* u32TempLength3 is >= MIN_OPT_LENGTH here, u32Ctr3 is at most 3 */
        u32TempLength3 -= u32Ctr3;
        u32IntCount3 = u32TempLength3 >> 2U; /* = u32TempLength3 / 4U */
        u32Fill3 = 0x01010101U * u8Fill3; /* set u8Fill3 to each byte in int */
        for ( u32Ctr3 = 0U; u32Ctr3 < u32IntCount3 ; u32Ctr3++ )
        {
#ifdef AUTOLIB_TESTING
            CA_Check1( (uint8_t *)&pau32Dst3[u32Ctr3], \
                       sizeof(*pau32Dst3)
                     );
#endif
            pau32Dst3[u32Ctr3] = u32Fill3;
        }

        /* write the last unaligned bytes (if any) */
        pau8Dst3 = (uint8_t *)(&pau32Dst3[u32Ctr3]);
        u32TempLength3 -= u32Ctr3 * UINT_SIZE; /* update to length to be copied */
        for ( u32Ctr3 = 0U; u32Ctr3 < u32TempLength3; u32Ctr3++ )
        {
#ifdef AUTOLIB_TESTING
            CA_Check1( &pau8Dst3[u32Ctr3], \
                       sizeof(*pau8Dst3)
                     );
#endif
            pau8Dst3[u32Ctr3] = u8Fill3;
        }
    }
    return pavDest3;
}

/**
* @brief Copies one memory area to another one
* @details Function copies data from one memory region to another. It handles
*          overlap of areas. It does not use any temporary buffer.
*          This function handles different alignment of source and destination
*          buffer.
* @param[out] pavDest4 Destination area
* @param[in] pcoavSource4 Source area
* @param[in] u32Length4 Number of bytes to be copied
* @return Pointer to the pavDest4 area.
*/
void *autolibc_memmove(void *pavDest4, const void *pcoavSource4, uint32_t u32Length4)
{
    /* Pointers for optimized, reversed (end to beginning) copying */
    uint8_t       *pu8FirstDst4;
    const uint8_t *pcou8FirstSrc4;
    /* BYTE pointers */
    uint8_t       *pu8AfterDst4;
    const uint8_t *pcou8AfterSrc4;
    /* INTEGER pointers */
    uint16_t       *pu16AfterDst4;
    const uint16_t *pcou16AfterSrc4;
    uint32_t       *pu32AfterDst4;
    const uint32_t *pcou32AfterSrc4;
    uint8_t  u8ShiftDif;

#ifdef AUTOLIB_TESTING
    /* init access address checking */
    CA_SetTest( 2U, 1U );
    /* set ranges */
    CA_SetRange1( (uaddr_t)pavDest4,   u32Length4, 1U);
    CA_SetRange2( (uaddr_t)pcoavSource4, u32Length4, 0U);
#endif

    /* Temporary spaces cannot be used because malloc is not available */
    if (pavDest4 == pcoavSource4)
    {   /* Both buffers are same */
        ; /* Nothing to copy, it is already done */
    }
    else if ( pavDest4 < pcoavSource4 )
    {   /* Source start possibly overlaps the destination end which means the
           start of the pcoavSource4 could be overwritten. It is save to copy
           from the beginning, which is what autolibc_memcpy does. */
        /* MISRA NOTE: the return value does not contain error information */
        (void)autolibc_memcpy( pavDest4, pcoavSource4, u32Length4);
    }
    else
    {   /* Destination start possibly overlaps the end of source which means
           the end of the source could be overwritten. It is safe to copy from
           the end. */
        pu8FirstDst4 = (uint8_t *)pavDest4;
        pcou8FirstSrc4 = (const uint8_t *)pcoavSource4;
        pu8AfterDst4 = &pu8FirstDst4[u32Length4];
        pcou8AfterSrc4 = &pcou8FirstSrc4[u32Length4];

        /* Explanation:
           Copying from end to beginning (reversed).
           The pointers named FirstDst and FirstSrc are classic pointers
           to beginnings of data to be copied. They are not used for copying.
           They are used to keep lowest accessible address for comparisons.
           The pointers named AfterDst and AfterSrc both point to next address
           after data to be copied, it is always pre-decremented before each
           copy. They are used to copy.
        */
        /* Safety:
           Assuming both given data areas are valid.
           First optimized loop iterates at most 3 times, writing at most 3
           bytes. It is working with at least 3 bytes long data, so
           lower boundary of data to be copied cannot be broken there.
           In all other loops we are in every iteration checking we will not be
           writing before the FirstDst address.
           All the time we are writing before "AfterDst" address. This
           address is decremented only, sure not to underflow. This ensures that
           we will not break the upper boundary of data to be copied.
        */

        /* too short for optimizations, move along 1B */
        if ( u32Length4 < MEMMOVE_OPT_LENGTH )
        {
            while ( pu8AfterDst4 > pu8FirstDst4 ) /* pointers to same array */
            {
                pu8AfterDst4--;
                pcou8AfterSrc4--;
                *pu8AfterDst4 = *pcou8AfterSrc4;

#ifdef AUTOLIB_TESTING
                CA_Check2( pu8AfterDst4,
                           pcou8AfterSrc4,
                           sizeof(*pu8AfterDst4)
                         );
#endif
            }
        }
        /* optimized copying */
        else
        {
            /* warning - conversion to smaller type (lost of higher bytes) - required behaviour here */
            u8ShiftDif = (uint8_t)((uaddr_t)pavDest4 - (uaddr_t)pcoavSource4);
            /* Check whether offset between pointers is multiple of 4 (last 2 bits are zero) */
            if ( 0U == (u8ShiftDif & 3U) )
            {   /* move along 4B */
                /* align the end of Dst to uint32_t size, copy bytes (if any) */
                while ( 0U != ((uaddr_t)pu8AfterDst4 & 3U) )
                { /* 0 != (address % 4U), address not aligned to 4 */
                    pu8AfterDst4--;
                    pcou8AfterSrc4--;
                    *pu8AfterDst4 = *pcou8AfterSrc4;
#ifdef AUTOLIB_TESTING
                    CA_Check2( pu8AfterDst4, \
                               pcou8AfterSrc4, \
                               sizeof(*pu8AfterDst4)
                             );
#endif
                }

                /* copy integer aligned part of data by whole integers */
                pu32AfterDst4 = (uint32_t*)pu8AfterDst4;
                pcou32AfterSrc4 = (const uint32_t*)pcou8AfterSrc4;
                while ( (uaddr_t)pu32AfterDst4 >= ((uaddr_t)pu8FirstDst4 + 4U) )
                { /* --AfterDst >= FirstDst, syntax above prevents underflow */
                    pu32AfterDst4--;
                    pcou32AfterSrc4--;
                    *pu32AfterDst4 = *pcou32AfterSrc4;
#ifdef AUTOLIB_TESTING
                    CA_Check2( (uint8_t *)pu32AfterDst4, \
                               (const uint8_t *)pcou32AfterSrc4, \
                               sizeof(*pu32AfterDst4)
                             );
#endif
                }

                /* copy the remaining unaligned bytes on the beginning (if any) */
                pu8AfterDst4 = (uint8_t*)pu32AfterDst4;
                pcou8AfterSrc4 = (const uint8_t*)pcou32AfterSrc4;
                while ( pu8AfterDst4 > pu8FirstDst4 ) /* pointers to same array */
                {
                    pu8AfterDst4--;
                    pcou8AfterSrc4--;
                    *pu8AfterDst4 = *pcou8AfterSrc4;
#ifdef AUTOLIB_TESTING
                    CA_Check2( pu8AfterDst4, \
                               pcou8AfterSrc4, \
                               sizeof(*pu8AfterDst4)
                             );
#endif
                }
            }
            /* 2B shift between destination and source data addresses */
            else if ( 0U == (u8ShiftDif & 1U) )
            {
                /* move along 2B */
                /* Align the end of Dst to uint16_t size, copy even byte (if any) */
                if ( 0U != ((uaddr_t)pu8AfterDst4 & 1U) )
                { /* 0 != (address % 4U), address not aligned to 4 */
                    pu8AfterDst4--;
                    pcou8AfterSrc4--;
                    *pu8AfterDst4 = *pcou8AfterSrc4;
#ifdef AUTOLIB_TESTING
                    CA_Check2( pu8AfterDst4,
                               pcou8AfterSrc4,
                               sizeof(*pu8AfterDst4)
                             );
#endif
                }
                /* Move 2B-aligned part of data by 2 bytes */
                pu16AfterDst4 = (uint16_t*)pu8AfterDst4;
                pcou16AfterSrc4 = (const uint16_t*)pcou8AfterSrc4;
                while ( (uaddr_t)pu16AfterDst4 >= ((uaddr_t)pu8FirstDst4 + 2U) )
                { /* --AfterDst >= FirstDst, syntax above prevents underflow */
                    pu16AfterDst4--;
                    pcou16AfterSrc4--;
                    *pu16AfterDst4 = *pcou16AfterSrc4;
#ifdef AUTOLIB_TESTING
                    CA_Check2( (uint8_t *)pu16AfterDst4, \
                               (const uint8_t *)pcou16AfterSrc4, \
                               sizeof(*pu16AfterDst4)
                             );
#endif
                }
                /* move the remaining unaligned bytes on the beginning (if any) */
                pu8AfterDst4 = (uint8_t*)pu16AfterDst4;
                pcou8AfterSrc4 = (const uint8_t*)pcou16AfterSrc4;
                if ( pu8AfterDst4 > pu8FirstDst4 ) /* pointers to same array */
                {
                    pu8AfterDst4--;
                    pcou8AfterSrc4--;
                    *pu8AfterDst4 = *pcou8AfterSrc4;
#ifdef AUTOLIB_TESTING
                    CA_Check2( pu8AfterDst4, \
                               pcou8AfterSrc4, \
                               sizeof(*pu8AfterDst4)
                             );
#endif
                }
            }
            /* any other shifting */
            else
            {   /* move along 1B */
                while ( pu8AfterDst4 > pu8FirstDst4 ) /* pointers to same array */
                {
                    pu8AfterDst4--;
                    pcou8AfterSrc4--;
                    *pu8AfterDst4 = *pcou8AfterSrc4;
#ifdef AUTOLIB_TESTING
                    CA_Check2( pu8AfterDst4,
                               pcou8AfterSrc4,
                               sizeof(*pu8AfterDst4)
                             );
#endif
                }
            }
        }
    }
    /* Note - no special copy process is needed when buffers do not overlap
       because overlap handling process copies also non-overlapping data - so
       actual overlap is not checked but only the type of possible overlap which
       determines how (from which end) to copy the data. */
    return pavDest4;
}
/**
* @brief Compares two memory blocks
* @details Function returns difference between the first not matching characters
*          or zero if data in blocks are identical. Compare operation is optimized
*          for all alignment of source or destination memory blocks.
*
* @param[in] pcoavMemA5 The first block to be compared
* @param[in] pcoavMemB5 The second block to be compared
* @param[in] u32Size5 Number of bytes to be compared
* @return 0 if both blocks are equal, difference (pcoavMemA5[] - pcoavMemB5[])
*         of first unmatching byte otherwise.
*/
int32_t autolibc_memcmp( const void *pcoavMemA5, const void *pcoavMemB5, uint32_t u32Size5 )
{
    uint32_t u32TempSize5=u32Size5;
    uint32_t u32FirstBytes5; /* count of unaligned bytes on the beginning */
    const uint8_t *pcoau8MemA5;
    const uint8_t *pcoau8MemB5;
    const uint16_t *pcoau16MemA5;
    const uint16_t *pcoau16MemB5;
    const uint32_t *pcoau32MemA5;
    const uint32_t *pcoau32MemB5;
    uint32_t u32IntCount5;
    uint32_t u32Ctr5;
    int32_t s32Result5;
    uint8_t u8ShiftDif;

 #ifdef AUTOLIB_TESTING
    /* init access address checking */
    CA_SetTest( 2U, 1U );
    /* set ranges */
    CA_SetRange1( (uaddr_t)pcoavMemA5, u32Size5, 0U);
    CA_SetRange2( (uaddr_t)pcoavMemB5, u32Size5, 0U);
#endif

    /* too short for optimizations */
    if (u32Size5 < MEMCMP_OPT_LENGTH )
    {
        s32Result5 = fsl_memcmp_aux( pcoavMemA5, pcoavMemB5, u32Size5 );
    }
    /* optimized comparing */
    else
    {
        pcoau8MemA5 = (const uint8_t*)pcoavMemA5;
        pcoau8MemB5 = (const uint8_t*)pcoavMemB5;
        /* In this optimizations aligning by first string */
        /* warning - conversion to smaller type (lost of higher bytes) - required behaviour here */
        u8ShiftDif = (uint8_t)((uaddr_t)pcoavMemB5-(uaddr_t)pcoavMemA5);
        /* Check whether offset between pointers is multiple of 4 (last 2 bits are zero) */
        if ( 0U == (u8ShiftDif & 3U) )
        {
            u32FirstBytes5 = 0U;
            /* comparing along 4B */
            /* solve first unaligned bytes */
            while (0U!=(((uaddr_t)(&pcoau8MemA5[u32FirstBytes5])) & 3U))
            {
                u32FirstBytes5++;
            }
            s32Result5 = fsl_memcmp_aux( pcoavMemA5, pcoavMemB5, u32FirstBytes5 );

            if ( 0 == s32Result5 )
            {
                /* solve integer aligned part */
                pcoau32MemA5 = (const uint32_t*) ( &pcoau8MemA5[u32FirstBytes5] );
                pcoau32MemB5 = (const uint32_t*) ( &pcoau8MemB5[u32FirstBytes5] );

                u32TempSize5 -= u32FirstBytes5;  /* update to remaining byte count */
                u32IntCount5 = u32TempSize5 >> 2U; /* = u32TempSize5 / 4U */
                for ( u32Ctr5=0U; u32Ctr5 < u32IntCount5; u32Ctr5++ )
                {
#ifdef AUTOLIB_TESTING
                    CA_Check2( (const uint8_t *)&pcoau32MemA5[u32Ctr5], \
                               (const uint8_t *)&pcoau32MemB5[u32Ctr5], \
                               sizeof(*pcoau32MemA5)
                             );
#endif
                    if ( pcoau32MemA5[u32Ctr5] != pcoau32MemB5[u32Ctr5] )
                    {
                        s32Result5 = fsl_memcmp_aux( (const void*)(&pcoau32MemA5[u32Ctr5]), \
                                              (const void*)(&pcoau32MemB5[u32Ctr5]), \
                                              4U
                                            );
                        break;
                    }
                }
                /* solve last unaligned bytes */
                if ( 0 == s32Result5 )
                {
                    u32TempSize5 -= u32Ctr5 * UINT_SIZE; /* update to remaining byte count */
                    /* let the inline function solve the remainder */
                    s32Result5 = fsl_memcmp_aux( (const void*)(&pcoau32MemA5[u32Ctr5]), \
                                          (const void*)(&pcoau32MemB5[u32Ctr5]), \
                                          u32TempSize5
                                        );
                }
            }
        }
        /* 2B shift between destination and source data addresses */
        else if ( 0U == (u8ShiftDif & 1U) )
        {
        /* comparing along 2B */
            /* Compare first unaligned byte (if any) */
            u32FirstBytes5 = (uint32_t)(((uaddr_t)pcoavMemA5) & 1U);
            if ( 0U == u32FirstBytes5 )
            {
                /* there is no unaligned bytes continue to compare along 2B */
                s32Result5 = 0;
            }
            else
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( (const uint8_t*)pcoavMemA5, \
                           (const uint8_t*)pcoavMemB5, \
                           sizeof(*((const uint8_t*)(&pcoau16MemA5[u32Ctr5])))
                         );
#endif
                s32Result5 = (int32_t)(*((const uint8_t*)pcoavMemA5)) - (int32_t)(*((const uint8_t*)pcoavMemB5));
            }
            if ( 0 == s32Result5 )
            {
                /* solve 2B aligned part */
                pcoau8MemA5 = (const uint8_t*)pcoavMemA5;
                pcoau8MemB5 = (const uint8_t*)pcoavMemB5;
                /* solve integer aligned part */
                pcoau16MemA5 = (const uint16_t*) ( &pcoau8MemA5[u32FirstBytes5] );
                pcoau16MemB5 = (const uint16_t*) ( &pcoau8MemB5[u32FirstBytes5] );

                u32TempSize5 -= u32FirstBytes5; /* update to remaining byte count */
                u32IntCount5 = u32TempSize5 >> 1U; /* = u32TempSize5 / 2U */
                /* u32TempSize5 is at least 26 so this loop always proceeds at least once time */
                for ( u32Ctr5=0U; u32Ctr5 < u32IntCount5; u32Ctr5++ )
                {
#ifdef AUTOLIB_TESTING
                    CA_Check2( (const uint8_t *)pcoau16MemA5, \
                               (const uint8_t *)pcoau16MemB5, \
                               sizeof(*pcoau16MemB5)
                             );
#endif
                    if ( pcoau16MemA5[u32Ctr5] != pcoau16MemB5[u32Ctr5] )
                    {
                        s32Result5 = fsl_memcmp_aux( (const void*)(&pcoau16MemA5[u32Ctr5]), \
                                              (const void*)(&pcoau16MemB5[u32Ctr5]),
                                              2U
                                            );
                        break;
                    }
                }
                pcoau8MemA5 = (const uint8_t*) ( &pcoau16MemA5[u32Ctr5] );
                pcoau8MemB5 = (const uint8_t*) ( &pcoau16MemB5[u32Ctr5] );
                 /* solve last unaligned bytes */
                if ( 0 == s32Result5 )
                {
                    u32TempSize5 -= (u32Ctr5 * UINT_SIZE)>>1U; /* update to remaining byte count */
                    /* let the inline function solve the remainder */
                    s32Result5 = fsl_memcmp_aux( (const void*)(&pcoau16MemA5[u32Ctr5]), \
                                          (const void*)(&pcoau16MemB5[u32Ctr5]), \
                                          u32TempSize5
                                        );
                }
            }
        }
        /* any other shifting */
        else
        {
            s32Result5 = fsl_memcmp_aux( pcoavMemA5, pcoavMemB5, u32TempSize5 );
        }
    }
    return s32Result5;
}

/**
* @brief Copies given number of string characters into another string
* @details Function copies given number of characters from the source string
*          into the destination string. If the source string is shorter than the
*          requested characters number then the remaining characters in the
*          destination string are set to the null character. If source string is
*          longer than requested characters number then the destination string
*          will not contain the terminating null character. This operation is
*          optimized for all alignment of source or destination string.
*
* @note Destination string size should be long enough to fit in given number of
*       characters.
* @param[out] pszDest7 Destination string
* @param[in] pcoszSrc7 Source string
* @param[in] u32Length7 Number of characters to be copied
* return Pointer to the destination string
*/
char_t *autolibc_strncpy(char_t *pszDest7, const char_t *pcoszSrc7, uint32_t u32Length7)
{
    uint32_t u32TempLength7=u32Length7;
    uint32_t u32Ctr7;
    uint32_t u32TempCtr7;
    uint32_t u32IntCount7;
    uint32_t u16IntCount7;
    uint32_t u32WriteZeroes7 = 0U; /* false */
    /* BYTE pointers */
    uint8_t        *pau8Dst7 = (uint8_t *)pszDest7;
    const uint8_t  *pcoau8Src7 = (const uint8_t *)pcoszSrc7;
    /* INTEGER pointers */
    uint32_t       *pau32Dst7;
    const uint32_t *pcoau32Src7;
    /* 2B pointers */
    uint16_t       *pau16Dst7;
    const uint16_t *pcoau16Src7;
    /* temporary BYTE pointers */
    uint8_t       *pau8TempDst7;
    const uint8_t *pcoau8TempSrc7;

    uint8_t u8ShiftDif;

#ifdef AUTOLIB_TESTING
    /* init access address checking */
    CA_SetTest( 2U, 1U );
    /* set ranges */
    CA_SetRange1( (uaddr_t)pszDest7, u32Length7, 1U);
    CA_SetRange2( (uaddr_t)pcoszSrc7, u32Length7, 0U);
#endif
    /* too short for optimizations */
    if ( u32Length7 < STRNCPY_OPT_LENGTH )
    {
        for (u32Ctr7 = 0U; u32Ctr7 < u32Length7; u32Ctr7++)
        {
#ifdef AUTOLIB_TESTING
            CA_Check2( &pau8Dst7[u32Ctr7], \
                       &pcoau8Src7[u32Ctr7], \
                       sizeof(*pau8Dst7)
                     );
#endif
            if ( 0U == pcoau8Src7[u32Ctr7] )
            {
                break;
            }
            else
            {
                pau8Dst7[u32Ctr7] = pcoau8Src7[u32Ctr7];
            }
        }
        while ( u32Ctr7 < u32Length7 )
        {
#ifdef AUTOLIB_TESTING
            CA_Check2( &pau8Dst7[u32Ctr7], \
                       &pcoau8Src7[u32Ctr7], \
                       sizeof(*pau8Dst7)
                     );
#endif
            pau8Dst7[u32Ctr7] = 0U;
            u32Ctr7++;
        }
    }
    /* optimized copying */
    else
    {
        u32Ctr7 = 0U;
        /* warning - convertion to smaller type (lost of higher bytes) - required behaviour here */
        u8ShiftDif = (uint8_t)((uaddr_t)pszDest7 - (uaddr_t)pcoszSrc7);
        /* Check whether offset between pointers is multiple of 4 (last 2 bits are zero) */
        if ( 0U == (u8ShiftDif & 3U) )
        {/* copying along 4B */
            /* align the beginning of Dst to uint32_t size, copy bytes (if any) */
            while ( 0U != ((uaddr_t)(&pau8Dst7[u32Ctr7]) & 3U) )
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( &pau8Dst7[u32Ctr7], \
                           &pcoau8Src7[u32Ctr7], \
                           sizeof(*pau8Dst7)
                         );
#endif
                if ( 1U == u32WriteZeroes7 )
                {
                    pau8Dst7[u32Ctr7] = 0U;
                }
                else if ( 0U == pcoau8Src7[u32Ctr7] )
                {
                    u32WriteZeroes7 = 1U; /* true */
                    pau8Dst7[u32Ctr7] = 0U;
                }
                else
                {
                    pau8Dst7[u32Ctr7] = pcoau8Src7[u32Ctr7];
                }
                u32Ctr7++;
            }

            /* copy integer aligned part of data */
            pau32Dst7 = (uint32_t *)(&pau8Dst7[u32Ctr7]);
            pcoau32Src7 = (const uint32_t *)(&pcoau8Src7[u32Ctr7]);
            /* update u32TempLength7 to be copied */
            /* u32TempLength7 is >= STRNCPY_OPT_LENGTH here, u32Ctr7 is at most 3 */
            u32TempLength7 -= u32Ctr7;
            u32IntCount7 = u32TempLength7 >> 2U; /* = u32TempLength7 / 4U */
            /* reset counter */
            u32Ctr7 = 0U;
            /* integer copy loop */
            if ( 0U == u32WriteZeroes7 )
            {
                while ( u32Ctr7 < u32IntCount7 )
                {
#ifdef AUTOLIB_TESTING
                    CA_Check2( (uint8_t *)&pau32Dst7[u32Ctr7], \
                               (const uint8_t *)&pcoau32Src7[u32Ctr7], \
                               sizeof(*pau32Dst7)
                             );
#endif
                    if ( (0U == (pcoau32Src7[u32Ctr7] & 0xFF000000U)) || \
                        (0U == (pcoau32Src7[u32Ctr7] & 0x00FF0000U)) || \
                        (0U == (pcoau32Src7[u32Ctr7] & 0x0000FF00U)) || \
                        (0U == (pcoau32Src7[u32Ctr7] & 0x000000FFU))
                      )
                    { /* terminating '\0' found, which byte? Start writing '\0' */
                        pau8TempDst7 = (uint8_t*)(&pau32Dst7[u32Ctr7]);
                        pcoau8TempSrc7 = (const uint8_t*)(&pcoau32Src7[u32Ctr7]);
                        for (u32TempCtr7=0U; u32TempCtr7 < UINT_SIZE; u32TempCtr7++)
                        {
#ifdef AUTOLIB_TESTING
                            CA_Check2( &pau8TempDst7[u32TempCtr7], \
                                       &pcoau8TempSrc7[u32TempCtr7], \
                                       sizeof(*pau8TempDst7)
                                     );
#endif
                            if ( 1U == u32WriteZeroes7 )
                            {
                                pau8TempDst7[u32TempCtr7] = 0U;
                            }
                            else if ( 0U == pcoau8TempSrc7[u32TempCtr7] )
                            {
                                u32WriteZeroes7 = 1U; /* true */
                                pau8TempDst7[u32TempCtr7] = 0U;
                            }
                            else
                            {
                                /* copy last bytes before null character */
                                pau8TempDst7[u32TempCtr7] \
                                                      = pcoau8TempSrc7[u32TempCtr7];
                            }
                        }
                        u32Ctr7++; /* was processed, increment before leaving */
                        break; /* exit loop, will continue in zero writing loop */
                    }
                    else
                    {
                        pau32Dst7[u32Ctr7] = pcoau32Src7[u32Ctr7];
                    }
                    u32Ctr7++;
                }
            }
            /* integer zero writing loop */
            while ( u32Ctr7 < u32IntCount7 )
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( (uint8_t *)&pau32Dst7[u32Ctr7], \
                           (const uint8_t *)&pcoau32Src7[u32Ctr7], \
                           sizeof(*pau32Dst7)
                         );
#endif
                pau32Dst7[u32Ctr7] = 0U;
                u32Ctr7++;
            }
            /* copy the last unaligned bytes (if any) */
            pau8Dst7 = (uint8_t *)(&pau32Dst7[u32Ctr7]);
            pcoau8Src7 = (const uint8_t *)(&pcoau32Src7[u32Ctr7]);
            u32TempLength7 -= u32Ctr7 * UINT_SIZE; /* update u32TempLength7 to be copied */
            for (u32Ctr7 = 0U; u32Ctr7 < u32TempLength7; u32Ctr7++)
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( &pau8Dst7[u32Ctr7], \
                           &pcoau8Src7[u32Ctr7], \
                           sizeof(*pau8Dst7)
                         );
#endif
                if ( 1U == u32WriteZeroes7 )
                {
                    pau8Dst7[u32Ctr7] = 0U;
                }
                else if ( 0U == pcoau8Src7[u32Ctr7] )
                {
                    u32WriteZeroes7 = 1U; /* true */
                    pau8Dst7[u32Ctr7] = 0U;
                }
                else
                {
                    pau8Dst7[u32Ctr7] = pcoau8Src7[u32Ctr7];
                }
            }
        }
        /* 2B shift between destination and source data addresses */
        else if ( 0U == (u8ShiftDif & 1U) )
        {    /* copying along 2B */

            /* if there is one unaligned byte */
            if ( 0U != ((uaddr_t)(&pau8Dst7[u32Ctr7]) & 1U) )
            { /* 0 != (address % 2U), address not aligned to 2 */
#ifdef AUTOLIB_TESTING
                CA_Check2( &pau8Dst7[u32Ctr7], \
                           &pcoau8Src7[u32Ctr7], \
                           sizeof(*pau8Dst7)
                         );
#endif
                if ( 0U == pcoau8Src7[u32Ctr7] )
                {
                    u32WriteZeroes7 = 1U; /* true */
                    pau8Dst7[u32Ctr7] = 0U;
                }
                else
                {
                    pau8Dst7[u32Ctr7] = pcoau8Src7[u32Ctr7];
                }
                u32Ctr7++;
            }
            /* copy 2B integer aligned part of data */
            pau16Dst7 = (uint16_t *)(&pau8Dst7[u32Ctr7]);
            pcoau16Src7 = (const uint16_t *)(&pcoau8Src7[u32Ctr7]);
            /* update u32TempLength7 to be copied */
            /* u32TempLength7 is >= STRNCPY_OPT_LENGTH here, u32Ctr7 is at most 3 */
            u32TempLength7 -= u32Ctr7;
            u16IntCount7 = u32TempLength7 >> 1U; /* = u32TempLength7 / 2U */
            /* reset counter */
            u32Ctr7 = 0U;
            /* 2B copy loop */
            if ( 0U == u32WriteZeroes7 )
            {
                while ( u32Ctr7 < u16IntCount7 )
                {
#ifdef AUTOLIB_TESTING
                    CA_Check2( (uint8_t *)&pau16Dst7[u32Ctr7], \
                               (const uint8_t *)&pcoau16Src7[u32Ctr7], \
                               sizeof(*pau16Dst7)
                             );
#endif
                    if ( (0U == (pcoau16Src7[u32Ctr7]&0xFF00U)) || \
                        (0U == (pcoau16Src7[u32Ctr7]&0x00FFU))
                      )
                    { /* terminating '\0' found, which byte? Start writing '\0' */
                        pau8TempDst7 = (uint8_t*)(&pau16Dst7[u32Ctr7]);
                        pcoau8TempSrc7 = (const uint8_t*)(&pcoau16Src7[u32Ctr7]);
                        for (u32TempCtr7=0U; u32TempCtr7 < (UINT_SIZE>>1U); u32TempCtr7++)
                        {
#ifdef AUTOLIB_TESTING
                            CA_Check2( &pau8TempDst7[u32TempCtr7], \
                                       &pcoau8TempSrc7[u32TempCtr7], \
                                       sizeof(*pau8TempDst7)
                                     );
#endif
                            if ( 1U == u32WriteZeroes7 )
                            {
                                pau8TempDst7[u32TempCtr7] = 0U;
                            }
                            else if ( 0U == pcoau8TempSrc7[u32TempCtr7] )
                            {
                                u32WriteZeroes7 = 1U; /* true */
                                pau8TempDst7[u32TempCtr7] = 0U;

                            }
                            else
                            {
                                /* copy last bytes before null character */
                                pau8TempDst7[u32TempCtr7] \
                                                      = pcoau8TempSrc7[u32TempCtr7];
                            }
                        }
                        u32Ctr7++; /* was processed, increment before leaving */
                        break; /* exit loop, will continue in zero writing loop */
                    }
                    else
                    {
                        pau16Dst7[u32Ctr7] = pcoau16Src7[u32Ctr7];
                    }
                    u32Ctr7++;
                }
            }
            /* 2B zero writing loop */
            while ( u32Ctr7 < u16IntCount7 )
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( (uint8_t *)&pau16Dst7[u32Ctr7], \
                           (const uint8_t *)&pcoau16Src7[u32Ctr7], \
                           sizeof(*pau16Dst7)
                         );
#endif

                pau16Dst7[u32Ctr7] = 0U;
                u32Ctr7++;
            }
            /* copy the last unaligned byte (if any) */
            pau8Dst7 = (uint8_t *)(&pau16Dst7[u32Ctr7]);
            pcoau8Src7 = (const uint8_t *)(&pcoau16Src7[u32Ctr7]);
            u32TempLength7 -= u32Ctr7 * 2U; /* update u32TempLength7 to be copied */
            u32Ctr7 = 0U;
            if ( 0U != u32TempLength7 )
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( pau8Dst7, \
                           pcoau8Src7, \
                           sizeof(*pau8Dst7)
                         );
#endif
                if ( 1U == u32WriteZeroes7 )
                {
                    pau8Dst7[u32Ctr7] = 0U;
                }
                /* Last byte -> no need to check its value, just copy */
                else
                {
                    pau8Dst7[u32Ctr7] = pcoau8Src7[u32Ctr7];
                }
            }

        }
        /* any other shifting */
        else
        {   /* copying along 1B */
            for (u32Ctr7 = 0U; u32Ctr7 < u32TempLength7; u32Ctr7++)
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( &pau8Dst7[u32Ctr7], \
                           &pcoau8Src7[u32Ctr7], \
                           sizeof(*pau8Dst7)
                         );
#endif
                if ( 0U == pcoau8Src7[u32Ctr7] )
                {
                    break;
                }
                else
                {
                    pau8Dst7[u32Ctr7] = pcoau8Src7[u32Ctr7];
                }
            }
            while ( u32Ctr7 < u32TempLength7 )
            {
#ifdef AUTOLIB_TESTING
                CA_Check2( &pau8Dst7[u32Ctr7], \
                           &pcoau8Src7[u32Ctr7], \
                           sizeof(*pau8Dst7)
                         );
#endif
                pau8Dst7[u32Ctr7] = 0U;
                u32Ctr7++;
            }
        }
    }
    return pszDest7;
}

/**
* @brief Copies string characters into another string
* @details Function copies characters from the source string
*          into the destination string.
*
* @param[out] pszDest Destination string
* @param[in]  pcoszSrc Source string
* return Pointer to the destination string
*/
char_t *autolibc_strcpy(char_t *pszDest, const char_t *pcoszSrc)
{
    uint32_t u32Ctr = 0U;

    do
    {
        /* copying along 1B */
        pszDest[u32Ctr] = pcoszSrc[u32Ctr];
    } while(0U != (uint8_t)(pcoszSrc[u32Ctr++]));
    return pszDest;
}

/**
* @brief Compares two strings
* @details Function returns difference between the first not matching characters
*          or zero if strings are identical. This operation is optimized for all
*          alignment of source or destination string.
* @param[in] pcoszStrA6 The first string to compare
* @param[in] pcoszStrB6 The second string to compare
* @return Result of (*pcoszStrA6 - *pcoszStrB6) when the not matching character is
*         found. Value 0 means that both strings are equal.
* @note In some cases reading up to 3 bytes behind terminating null byte.
*/
int32_t autolibc_strcmp(const char_t *pcoszStrA6, const char_t *pcoszStrB6)
{

    int32_t s32Result6 = 0;
    uint32_t u32Ctr6 = 0U;
    uint32_t u32LittleCtr6;
    /* BYTE pointers */
    const uint8_t *pcoau8StrA6 = (const uint8_t*)pcoszStrA6;
    const uint8_t *pcoau8StrB6 = (const uint8_t*)pcoszStrB6;
    /* INTEGER pointers */
    const uint16_t *pcoau16StrA6;
    const uint16_t *pcoau16StrB6;
    const uint32_t *pcoau32StrA6;
    const uint32_t *pcoau32StrB6;

    uint8_t u8ShiftDif;

#ifdef AUTOLIB_TESTING
    /* it must be initialized in caller function, not know the lengths here
    CA_SetTest()
    CA_SetRange1()
    CA_SetRange2() */
#endif
    /* warning - convertion to smaller type (lost of higher bytes) - required behaviour here */
    u8ShiftDif = (uint8_t)((uaddr_t)pcoszStrB6 - (uaddr_t)pcoszStrA6);
    /* Check whether offset between pointers is multiple of 4 (last 2 bits are zero) */
    if ( 0U == (u8ShiftDif & 3U) )
    {   /* comparing along 4B */

        /* first unaligned bytes */
        while ( 0U != ((uaddr_t)(&pcoau8StrA6[u32Ctr6]) & 3U) )
        { /* 0 != (address % 4U), address not aligned to 4 */
#ifdef AUTOLIB_TESTING
            CA_Check2( &pcoau8StrA6[u32Ctr6], \
                       &pcoau8StrB6[u32Ctr6], \
                       sizeof(*pcoau8StrA6)
                     );
#endif
            s32Result6 = (int32_t)pcoau8StrA6[u32Ctr6] - (int32_t)pcoau8StrB6[u32Ctr6];
            if ( s32Result6 != 0 )
            {
                return s32Result6;
            }
            if ( 0U == pcoau8StrA6[u32Ctr6] ) /* just need to check one value */
            {
                return 0;
            }
            u32Ctr6++;
        }
        /* integer aligned part of strings */
        pcoau32StrA6 = (const uint32_t*)(&pcoau8StrA6[u32Ctr6]);
        pcoau32StrB6 = (const uint32_t*)(&pcoau8StrB6[u32Ctr6]);
        /* It is difficult and/or ineffective to construct single condition and it
         * would be difficult to understand the condition. We are using multiple
         * return statements to exit the loop instead.It is the most straight
         * forward and error proof method in this case.
         * The cause is, that we are iterating by integers, but checking by
         * bytes and there are 2 different possible outcomes.
         * The loop is running till zero byte or non-matching bytes are found. */
        u32Ctr6 = 0U;
        while (TRUE)
        {    /* multiple return statements are used to leave the loop */

#ifdef AUTOLIB_TESTING
            CA_Check2( (const uint8_t *)&pcoau32StrA6[u32Ctr6], \
                       (const uint8_t *)&pcoau32StrB6[u32Ctr6], \
                       sizeof(*pcoau32StrA6)
                     );
#endif
            if ( pcoau32StrA6[u32Ctr6] != pcoau32StrB6[u32Ctr6] )
            { /* there is at least 1 not matching byte */
                /* accessing by bytes again */
                pcoau8StrA6 = (const uint8_t*)&pcoau32StrA6[u32Ctr6];
                pcoau8StrB6 = (const uint8_t*)&pcoau32StrB6[u32Ctr6];
                for ( u32LittleCtr6=0U; u32LittleCtr6 < 4U; u32LittleCtr6++ )
                {
#ifdef AUTOLIB_TESTING
                    CA_Check2( &pcoau8StrA6[u32LittleCtr6], \
                               &pcoau8StrB6[u32LittleCtr6], \
                               sizeof(*pcoau8StrA6)
                             );
#endif
                    s32Result6 = (int32_t)pcoau8StrA6[u32LittleCtr6] \
                                 - (int32_t)pcoau8StrB6[u32LittleCtr6];
                    if ( s32Result6 != 0 )
                    {
                        return s32Result6; /* strings not same, unmatching bytes */
                    }
                    if ( 0U == pcoau8StrA6[u32LittleCtr6] )/*no need to check both*/
                    {
                        return 0; /* string end found, strings are identical */
                    }
                }
            }
            else
            { /* integers are identical */
                /* need check for '\0' byte in one of integers */
                if ( ( 0U == (pcoau32StrA6[u32Ctr6] & 0xFF000000U) ) || \
                    ( 0U == (pcoau32StrA6[u32Ctr6] & 0x00FF0000U) ) || \
                    ( 0U == (pcoau32StrA6[u32Ctr6] & 0x0000FF00U) ) || \
                    ( 0U == (pcoau32StrA6[u32Ctr6] & 0x000000FFU) )
                  )
                {
                    return 0; /* string end found, strings are identical */
                }
            }
            u32Ctr6++;
        }
    }
    else if ( 0U == (u8ShiftDif & 1U) )
    {   /* Compare along 2B */
        /* first unaligned byte */
        if ( 0U != ((uaddr_t)(&pcoau8StrA6[u32Ctr6]) & 1U) )
        { /* 0 != (address % 2U), address not aligned to 2 */
#ifdef AUTOLIB_TESTING
            CA_Check2( &pcoau8StrA6[u32Ctr6], \
                       &pcoau8StrB6[u32Ctr6], \
                       sizeof(*pcoau8StrA6)
                     );
#endif
            s32Result6 = (int32_t)pcoau8StrA6[u32Ctr6] \
                         - (int32_t)pcoau8StrB6[u32Ctr6];
            if ( s32Result6 != 0 )
            {
                return s32Result6;
            }
            if ( 0U == pcoau8StrA6[u32Ctr6] ) /* just need to check one value */
            {
                return 0;
            }
            u32Ctr6++;
        }
        /* integer aligned part of strings */
        pcoau16StrA6 = (const uint16_t*)(&pcoau8StrA6[u32Ctr6]);
        pcoau16StrB6 = (const uint16_t*)(&pcoau8StrB6[u32Ctr6]);
        u32Ctr6 = 0U;
        while (TRUE)
        {   /* multiple return statements are used to leave the loop */
#ifdef AUTOLIB_TESTING
            CA_Check2( (const uint8_t *)&pcoau16StrA6[u32Ctr6], \
                       (const uint8_t *)&pcoau16StrB6[u32Ctr6], \
                       sizeof(*pcoau16StrA6)
                     );
#endif
            if ( pcoau16StrA6[u32Ctr6] != pcoau16StrB6[u32Ctr6] )
            { /* there is at least 1 not matching byte */
                /* accessing by bytes again */
                pcoau8StrA6 = (const uint8_t*)&pcoau16StrA6[u32Ctr6];
                pcoau8StrB6 = (const uint8_t*)&pcoau16StrB6[u32Ctr6];

                for ( u32LittleCtr6=0U; u32LittleCtr6 < 2U; u32LittleCtr6++ )
                {
#ifdef AUTOLIB_TESTING
                    CA_Check2( &pcoau8StrA6[u32LittleCtr6], \
                               &pcoau8StrB6[u32LittleCtr6], \
                               sizeof(*pcoau8StrA6)
                             );
#endif
                    s32Result6 = (int32_t)pcoau8StrA6[u32LittleCtr6] \
                                 - (int32_t)pcoau8StrB6[u32LittleCtr6];
                    if ( s32Result6 != 0 )
                    {
                        return s32Result6; /* strings not same, unmatching bytes */
                    }
                    if ( 0U == pcoau8StrA6[u32LittleCtr6] )/*no need to check both*/
                    {
                        return 0; /* string end found, strings are identical */
                    }
                }
            }
            else
            { /* integers are identical */
                /* need check for '\0' byte in one of integers */
                if ( ( 0U == (pcoau16StrA6[u32Ctr6] & 0xFF00U) ) || \
                    ( 0U == (pcoau16StrA6[u32Ctr6] & 0x00FFU) )
                  )
                {
                    return 0; /* string end found, strings are identical */
                }
            }
            u32Ctr6++;
        }
    }
    /* any other shifting */
    else
    {
        u32Ctr6 = 0U;
        while (TRUE)
        {   /* multiple return statements are used to leave the loop */
#ifdef AUTOLIB_TESTING
            CA_Check2( &pcoau8StrA6[u32Ctr6], \
                       &pcoau8StrB6[u32Ctr6], \
                       sizeof(*pcoau8StrA6)
                     );
#endif
            if ( pcoau8StrA6[u32Ctr6] != pcoau8StrB6[u32Ctr6] )
            {
                s32Result6 = (int32_t)pcoau8StrA6[u32Ctr6]\
                                 - (int32_t)pcoau8StrB6[u32Ctr6];
                return s32Result6; /* strings not same, not matching bytes */
            }
            else
            { /* bytes are identical */
                /* need check for '\0' byte in one of bytes */
                if ( 0U == (pcoau8StrA6[u32Ctr6] ) )
                {
                    return 0; /* string end found, strings are identical */
                }
            }
            u32Ctr6++;
        }

    }
}

/**
* @brief Computes length of the string.
* @details Function searches for the null character and counts bytes until it
*          finds it.
* @param[in] pcozsStr8 String to determine the length for.
* @return String length.
* @note In some cases reading up to 3 bytes behind terminating null byte.
*/
uint32_t autolibc_strlen(const char_t pcozsStr8[])
{
    uint32_t u32Length8 = 0U;
#ifdef AUTOLIB_TESTING
    /* it must be initialized in caller function, not know the lengths here
    CA_SetTest()
    CA_SetRange1()
    CA_SetRange2() */
#endif

#ifdef AUTOLIB_TESTING
    CA_Check1( (const uint8_t *)&pcozsStr8[u32Length8],
               sizeof(*pcozsStr8)
             );
#endif

    while ( pcozsStr8[u32Length8] != '\0' )
    {
        u32Length8++;
#ifdef AUTOLIB_TESTING
        CA_Check1( (const uint8_t *)&pcozsStr8[u32Length8],
                   sizeof(*pcozsStr8)
                 );
#endif
    }
    return u32Length8;
}

/**
* @brief Computes length of the string.
* @details Function searches for the null character and counts bytes until it
*          finds it or stops after u32Strsz characters is exhausted
* @param[in] pcozsStr8 String to determine the length for.
* @param[in] u32Strsz maximum number of characters search through
* @return String length or u32Strsz when null character not found
* @note In some cases reading up to 3 bytes behind terminating null byte.
*/
uint32_t autolibc_strnlen(const char_t pcozsStr8[], uint32_t u32Strsz)
{
    uint32_t u32Length8 = 0U;

#ifdef AUTOLIB_TESTING
    /* it must be initialized in caller function, not know the lengths here
    CA_SetTest()
    CA_SetRange1()
    CA_SetRange2() */
#endif

#ifdef AUTOLIB_TESTING
    CA_Check1( (const uint8_t *)&pcozsStr8[u32Length8],
               sizeof(*pcozsStr8)
             );
#endif

    if(NULL_PTR != pcozsStr8)
    {
        while((pcozsStr8[u32Length8] != '\0') && (u32Length8 < u32Strsz))
        {
            u32Length8++;
#ifdef AUTOLIB_TESTING
            CA_Check1( (const uint8_t *)&pcozsStr8[u32Length8],
                        sizeof(*pcozsStr8)
                 );
#endif
        }
    }

    return u32Length8;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"


#ifdef __cplusplus
}
#endif
