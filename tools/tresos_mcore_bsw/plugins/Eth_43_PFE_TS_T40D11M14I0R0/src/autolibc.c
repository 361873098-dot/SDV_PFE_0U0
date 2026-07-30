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
 *  SW Version           : 1.4.0
 *  Build Version        : PFE-DRV_S32G_M7_MCAL_1.4.0_D2405_ASR_REL_4_4_REV_0000_20240528
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
#define PFE_SRC_VERSION_CHECK 43140440

/*==============================================================================
                                INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==============================================================================*/
#include "pfe_cfg.h"
#include "oal.h"

#include "autolibc.h"

/*==============================================================================
                             FILE VERSION CHECKS
==============================================================================*/

/*==============================================================================
                                 LOCAL MACROS
==============================================================================*/
/* WARNING, all OPT_LENGTHs must be at least 3 not to cause errors */
#define MEMCPY_OPT_LENGTH   (0x00000009u)  /* 9B optimal length for non-aligned data */
#define MEMMOVE_OPT_LENGTH  (0x00000008u)  /* 8B optimal length for non-aligned data */
#define MEMSET_OPT_LENGTH   (0x00000007u)  /* 7B optimal length for non-aligned data */
#define MEMCMP_OPT_LENGTH   (0x0000001Au)  /* 26B optimal length for non-aligned data */

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
static inline bool_t test_u32_for_null(uint32_t u32Num);
static inline int32_t memcmp8_aux(const void *pcoavMemA1, const void *pcoavMemB1, uint32_t u32Size1);
static inline int32_t memcmp16_aux(const void *pcoavMemA, const void *pcoavMemB, uint32_t u32Size);
static inline int32_t memcmp32_aux(const void *pcoavMemA, const void *pcoavMemB, uint32_t u32Size);
static inline void memcpy8_aux(uint8_t *pau8Dest, const uint8_t *pcoau8Source, uint32_t u32Length2);
static inline void memcpy8_backwards_aux(uint8_t *dest_end, const uint8_t *dest_start, const uint8_t *src_end);
static inline void memcpy16_backwards_aux(uint8_t *dest_end, const uint8_t *dest_start, const uint8_t *src_end);
static inline void memcpy32_backwards_aux(uint8_t *dest_end, const uint8_t *dest_start, const uint8_t *src_end);
static inline int32_t strcmp8_aux(const uint8_t *pcoau8StrA, const uint8_t *pcoau8StrB);
static inline int32_t strcmp16_aux(const uint8_t *pcoau8StrA6, const uint8_t *pcoau8StrB6);
static inline int32_t strcmp32_aux(const uint8_t *pcoau8StrA6, const uint8_t *pcoau8StrB6);
static inline int32_t strcmp16_aligned_aux(const uint16_t *pcoau16StrA6, const uint16_t *pcoau16StrB6);
static inline int32_t strcmp32_aligned_aux(const uint32_t *pcoau32StrA6, const uint32_t *pcoau32StrB6);


/*==============================================================================
                                LOCAL FUNCTIONS
==============================================================================*/

/* Function returns TRUE when u32 number contains NUL byte */
static inline bool_t test_u32_for_null(uint32_t u32Num)
{
    bool_t result = FALSE;
    if ( (0U == (u32Num & 0xFF000000U)) || \
        (0U == (u32Num & 0x00FF0000U)) || \
        (0U == (u32Num & 0x0000FF00U)) || \
        (0U == (u32Num & 0x000000FFU)))
    {
        result = TRUE;
    }
    return result;
}

/* Compares two memory blocks byte by byte. This function is version of memcmp
 * not optimized to compare long blocks of memory. It is intended to be called
 * from memcmp function to compare very short parts of long blocks. */
static inline int32_t memcmp8_aux( const void *pcoavMemA1,
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
        s32Result1 =(int32_t)pcoau8MemA1[u32Ctr1]-(int32_t)pcoau8MemB1[u32Ctr1];
        if ( s32Result1 != 0 )
        {
            break;
        }
    }
    return s32Result1;
}

/* Functions compares two blocks of memory, expects pointers alignment on 4B,
 * u32Size must be greater than 4 */
static inline int32_t memcmp32_aux(const void *pcoavMemA,
                                       const void *pcoavMemB,
                                       uint32_t u32Size)
{
    uint32_t cur_idx = 0U;
    const uint8_t *a8 = (const uint8_t*)pcoavMemA;
    const uint8_t *b8 = (const uint8_t*)pcoavMemB;
    int32_t s32Result = 0;

    PfeDevAssert(u32Size >= MEMCMP_OPT_LENGTH);

    /* Compare first unaligned bytes (if any) */
    for (; 0U != ((uaddr_t)(&a8[cur_idx]) & 3U); cur_idx++ )
    {
        s32Result = (int32_t)a8[cur_idx] - (int32_t)b8[cur_idx];
        if (s32Result != 0)
        {
            break;
        }
    }

    if ( 0 == s32Result )
    {
        /* Compare word aligned part */
        const uint32_t *a32 = (const uint32_t*) ( &a8[cur_idx] );
        const uint32_t *b32 = (const uint32_t*) ( &b8[cur_idx] );
        for (; cur_idx < (u32Size - 3U); cur_idx += 4U)
        {
            if (*a32 != *b32)
            {
                s32Result = memcmp8_aux((const void*) a32, (const void *) b32, 4U);
                break; 
            }
            a32++;
            b32++;
        }

        /* Compare last unaligned part (if any) */
        if (0 == s32Result)
        {
            s32Result = memcmp8_aux(&a8[cur_idx], &b8[cur_idx], u32Size - cur_idx);
        }
    }
    return s32Result;
}

/* Functions compares two blocks of memory, expects pointers alignment on 2B,
 * u32Size must be greater than 2 */
static inline int32_t memcmp16_aux(const void *pcoavMemA, const void *pcoavMemB, uint32_t u32Size)
{
    uint32_t cur_idx = 0U;
    const uint8_t *a8 = (const uint8_t*)pcoavMemA;
    const uint8_t *b8 = (const uint8_t*)pcoavMemB;
    int32_t s32Result = 0;

    PfeDevAssert(u32Size >= MEMCMP_OPT_LENGTH);

    /* Compare first unaligned byte (if any) */
    if ( 0U != ((uaddr_t)a8 & 1U) )
    {
        s32Result = (int32_t)*a8 - (int32_t)*b8;
        cur_idx++;
    }
    
    if (0 == s32Result)
    {
        /* Compare halfword aligned part */
        const uint16_t *a16 = (const uint16_t*) ( &a8[cur_idx] );
        const uint16_t *b16 = (const uint16_t*) ( &b8[cur_idx] );
        for (; cur_idx < (u32Size - 1U); cur_idx += 2U)
        {
            if (*a16 != *b16)
            {
                s32Result = memcmp8_aux((const void*) a16, (const void *) b16, 2U);
                break; 
            }
            a16++;
            b16++;
        }

        /* Compare last unaligned part (if any) */
        if ((0 == s32Result) && (cur_idx < u32Size))
        {
            s32Result = (int32_t)a8[cur_idx] - (int32_t)b8[cur_idx];
        }
    }

    return s32Result;
}

/* Copies data from one memory region to another one byte by byte. 
 * It is intended to be called from autolibc_memcpy function */
static inline void memcpy8_aux(uint8_t *pau8Dest, const uint8_t *pcoau8Source, uint32_t u32Length2)
{
    for (uint32_t u32Ctr2 = 0U; u32Ctr2 < u32Length2; u32Ctr2++)
    {
        pau8Dest[u32Ctr2] = pcoau8Source[u32Ctr2];
    }    
}

/* Copy backwards, start from src_end, dest_end and decrement until dest_start is reached.
 * _end address is not included. */
static inline void memcpy8_backwards_aux(uint8_t *dest_end, const uint8_t *dest_start, const uint8_t *src_end)
{
    uint8_t *dest = dest_end;
    const uint8_t *src = src_end;
    
    while (dest > dest_start) /* pointers to same array */
    {
        dest--;
        src--;
        *dest = *src;

    }
}

/* Copy backwards, start from src_end, dest_end and decrement until dest_start is reached.
 * _end address is not included. Expects pointers alignment on 4B, dest_end - dest_start > 4. */
static inline void memcpy32_backwards_aux(uint8_t *dest_end, const uint8_t *dest_start, const uint8_t *src_end)
{
    uint8_t *dest = dest_end;
    const uint8_t *src = src_end;

    /* align the end of Dst to uint32_t size, copy bytes (if any) */
    while ( 0U != ((uaddr_t)dest & 3U) )
    { /* 0 != (address % 4U), address not aligned to 4 */
        dest--;
        src--;
        *dest = *src;
    }

    /* copy integer aligned part of data by whole integers */
    uint32_t *pu32AfterDst4 = (uint32_t*)dest;
    const uint32_t *pcou32AfterSrc4 = (const uint32_t*)src;
    while ( (uaddr_t)pu32AfterDst4 >= ((uaddr_t)dest_start + 4U) )
    { /* --AfterDst >= FirstDst, syntax above prevents underflow */
        pu32AfterDst4--;
        pcou32AfterSrc4--;
        *pu32AfterDst4 = *pcou32AfterSrc4;
    }

    /* copy the remaining unaligned bytes on the beginning (if any) */
    dest = (uint8_t*)pu32AfterDst4;
    src = (const uint8_t*)pcou32AfterSrc4;
    while ( dest > dest_start ) /* pointers to same array */
    {
        dest--;
        src--;
        *dest = *src;
    }    
}

/* Copy backwards, start from src_end, dest_end and decrement until dest_start is reached.
 * _end address is not included. Expects pointers alignment on 2B, dest_end - dest_start > 2. */
static inline void memcpy16_backwards_aux(uint8_t *dest_end, const uint8_t *dest_start, const uint8_t *src_end)
{
    uint8_t *dest = dest_end;
    const uint8_t *src = src_end;

    if ( 0U != ((uaddr_t)dest & 1U) )
    { /* 0 != (address % 4U), address not aligned to 4 */
        dest--;
        src--;
        *dest = *src;
    }
    /* Move 2B-aligned part of data by 2 bytes */
    uint16_t *pu16AfterDst4 = (uint16_t*)dest;
    const uint16_t *pcou16AfterSrc4 = (const uint16_t*)src;
    while ( (uaddr_t)pu16AfterDst4 >= ((uaddr_t)dest_start + 2U) )
    { /* --AfterDst >= FirstDst, syntax above prevents underflow */
        pu16AfterDst4--;
        pcou16AfterSrc4--;
        *pu16AfterDst4 = *pcou16AfterSrc4;
    }
    /* move the remaining unaligned bytes on the beginning (if any) */
    dest = (uint8_t*)pu16AfterDst4;
    src = (const uint8_t*)pcou16AfterSrc4;
    if ( dest > dest_start ) /* pointers to same array */
    {
        dest--;
        src--;
        *dest = *src;
    }
}

/* Helper function for strcmp, it walks through by 1 B */
static inline int32_t strcmp8_aux(const uint8_t *pcoau8StrA, const uint8_t *pcoau8StrB)
{
    uint32_t u32Ctr = 0U;

    while (0U != (pcoau8StrA[u32Ctr]))
    {
        if ( pcoau8StrA[u32Ctr] != pcoau8StrB[u32Ctr] )
        {
            /* strings not same, not matching bytes */
            break;
        }
        u32Ctr++;
    }

    return ((int32_t)pcoau8StrA[u32Ctr] - (int32_t)pcoau8StrB[u32Ctr]);
}

/* Helper function for strcmp32_aux, compares word aligned part of strings */
static inline int32_t strcmp32_aligned_aux(const uint32_t *pcoau32StrA6, const uint32_t *pcoau32StrB6)
{
    int32_t s32Result6 = 0;
    uint32_t u32Ctr6 = 0U;
    bool_t finished = FALSE;

    /* The loop is running till zero byte or non-matching bytes are found. */
    while (TRUE)
    {
        if (pcoau32StrA6[u32Ctr6] != pcoau32StrB6[u32Ctr6])
        { /* there is at least 1 not matching byte */
            /* accessing by bytes again */
            const uint8_t *str_a = (const uint8_t*)&pcoau32StrA6[u32Ctr6];
            const uint8_t *str_b = (const uint8_t*)&pcoau32StrB6[u32Ctr6];
            for (uint32_t u32LittleCtr6=0U; u32LittleCtr6 < 4U; u32LittleCtr6++ )
            {
                s32Result6 = (int32_t)str_a[u32LittleCtr6] \
                                - (int32_t)str_b[u32LittleCtr6];
                if ((s32Result6 != 0) || (0U == str_a[u32LittleCtr6]))
                {
                    finished = TRUE;
                    break;
                }
            }
        }
        else
        { /* integers are identical */
            /* need check for '\0' byte in one of integers */
            if (test_u32_for_null(pcoau32StrA6[u32Ctr6]) == TRUE)
            {
                finished = TRUE; /* string end found, strings are identical */
            }
        }

        if (finished == TRUE)
        {
            break;
        }

        u32Ctr6++;
    }

    return s32Result6;
}

/* Helper function for strcmp, it walks through by 4 B */
static inline int32_t strcmp32_aux(const uint8_t *pcoau8StrA6, const uint8_t *pcoau8StrB6)
{
    int32_t s32Result6 = 0;
    uint32_t u32Ctr6 = 0U;
    bool_t finished = FALSE;
    const uint8_t *str_a = pcoau8StrA6;
    const uint8_t *str_b = pcoau8StrB6;


    /* first unaligned bytes */
    while ( 0U != ((uaddr_t)(&str_a[u32Ctr6]) & 3U) )
    { /* 0 != (address % 4U), address not aligned to 4 */
        s32Result6 = (int32_t)str_a[u32Ctr6] - (int32_t)str_b[u32Ctr6];
        if ((s32Result6 != 0) || (0U == str_a[u32Ctr6]))
        {
            finished = TRUE;
            break;
        }
        u32Ctr6++;
    }

    if (finished == FALSE)
    {
        /* integer aligned part of strings */
        const uint32_t *pcoau32StrA6 = (const uint32_t*)(&str_a[u32Ctr6]);
        const uint32_t *pcoau32StrB6 = (const uint32_t*)(&str_b[u32Ctr6]);
        s32Result6 = strcmp32_aligned_aux(pcoau32StrA6, pcoau32StrB6);
    }

    return s32Result6;
}

/* Helper function for strcmp16_aux, compares word aligned part of strings */
static inline int32_t strcmp16_aligned_aux(const uint16_t *pcoau16StrA6, const uint16_t *pcoau16StrB6)
{
    int32_t s32Result6 = 0;
    uint32_t u32Ctr6 = 0U;
    bool_t finished = FALSE;

    while (TRUE)
    {
        if ( pcoau16StrA6[u32Ctr6] != pcoau16StrB6[u32Ctr6] )
        { /* there is at least 1 not matching byte */
            /* accessing by bytes again */
            const uint8_t *str_a = (const uint8_t*)&pcoau16StrA6[u32Ctr6];
            const uint8_t *str_b = (const uint8_t*)&pcoau16StrB6[u32Ctr6];

            for (uint32_t u32LittleCtr6=0U; u32LittleCtr6 < 2U; u32LittleCtr6++ )
            {
                s32Result6 = (int32_t)str_a[u32LittleCtr6] \
                                - (int32_t)str_b[u32LittleCtr6];
                if ((s32Result6 != 0) || (0U == str_a[u32LittleCtr6]) )
                {
                    finished = TRUE;
                    break;
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
                finished = TRUE; /* string end found, strings are identical */
            }
        }
        if (finished == TRUE)
        {
            break;
        }
        u32Ctr6++;
    }

    return s32Result6;
}

/* Helper function for strcmp, it walks through by 4 B */
static inline int32_t strcmp16_aux(const uint8_t *pcoau8StrA6, const uint8_t *pcoau8StrB6)
{
    int32_t s32Result6 = 0;
    uint32_t u32Ctr6 = 0U;
    bool_t finished = FALSE;
    const uint8_t *str_a = pcoau8StrA6;
    const uint8_t *str_b = pcoau8StrB6;

    /* first unaligned byte */
    if ( 0U != ((uaddr_t)(&str_a[u32Ctr6]) & 1U) )
    { /* 0 != (address % 2U), address not aligned to 2 */
        s32Result6 = (int32_t)str_a[u32Ctr6] - (int32_t)str_b[u32Ctr6];
        if ((s32Result6 != 0) || (0U == str_a[u32Ctr6]))
        {
            finished = TRUE;
        }
        u32Ctr6++;
    }

    if (finished == FALSE)
    {
        /* integer aligned part of strings */
        const uint16_t *pcoau16StrA6 = (const uint16_t*)(&str_a[u32Ctr6]);
        const uint16_t *pcoau16StrB6 = (const uint16_t*)(&str_b[u32Ctr6]);
        s32Result6 = strcmp16_aligned_aux(pcoau16StrA6, pcoau16StrB6);
    }

    return s32Result6;
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
* @note Function does not handle overlap and overflow.
*/
void *autolibc_memcpy(void *pavDest2, const void *pcoavSource2, uint32_t u32Length2)
{
    /* BYTE pointers */
    uint8_t *dest = (uint8_t *)pavDest2;
    const uint8_t *src = (const uint8_t *)pcoavSource2;

    /* too short for optimizations, copy along 1B */
    if ( u32Length2 < MEMCPY_OPT_LENGTH )
    {
        memcpy8_aux(dest, src, u32Length2);
    }
    else
    {   /* optimized copying */
        uint32_t cur_idx = 0U;
        /* Compute offset between pointers. We are only interested in last 2 bits, so uint8_t is enough */
        const uint8_t u8ShiftDif = (uint8_t)(((uaddr_t)pavDest2 - (uaddr_t)pcoavSource2) & 3U);

        /* Check whether offset between pointers is multiple of 4 (last 2 bits are zero) */
        if ( 0U == u8ShiftDif )
        {   /* copy first unaligned part of bytes (if any) */
            for (; 0U != ((uaddr_t)(&dest[cur_idx]) & 3U); cur_idx++)
            {
                dest[cur_idx] = src[cur_idx];
            }

            /* copy word aligned part of data */
            uint32_t *dest_aligned32 = (uint32_t *)(&dest[cur_idx]);       
            const uint32_t *src_aligned32 = (const uint32_t *)(&src[cur_idx]);
            for (; cur_idx < (u32Length2 - 3U); cur_idx += 4U)
            {
                *dest_aligned32 = *src_aligned32;
                dest_aligned32++;
                src_aligned32++;
            }

            /* copy the last unaligned bytes (if any) */
            for (; cur_idx < u32Length2; cur_idx++)
            {
                dest[cur_idx] = src[cur_idx];
            }    
        }
        /* Check whether offset between pointers is multiple of 2 (last 1 bit is zero) */
        else if ( 0U == (u8ShiftDif & 1U) )
        {   /* copy first unaligned  byte (if any) */
            if ( 0U != ((uaddr_t)(&dest[cur_idx]) & 1U) )
            {
                dest[cur_idx] = src[cur_idx];
                cur_idx++;
            }

            /* copy halfword aligned part of data */
            uint16_t *dest_aligned16 = (uint16_t *)(&dest[cur_idx]);       
            const uint16_t *src_aligned16 = (const uint16_t *)(&src[cur_idx]);
            for (; cur_idx < (u32Length2 - 1U); cur_idx += 2U)
            {
                *dest_aligned16 = *src_aligned16;
                dest_aligned16++;
                src_aligned16++;
            }
            
            /* copy the last unaligned bytes (if any) */
            if (cur_idx < u32Length2)
            {
                dest[cur_idx] = src[cur_idx];

            }            
        }
        /* any other shifting */
        else
        {
            /* copying along 1B */
            memcpy8_aux(dest, src, u32Length2);
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
    uint32_t cur_idx = 0U;
    uint8_t u8Fill3 = 0U;
    uint8_t  *dest = (uint8_t *)pavDest3;

    /* MISRA and CERC C compliant way how to convert s32 to u8 */
    const int64_t s64Fill3 = (int64_t)s32Fill3 - INT32_MIN;
    u8Fill3 = (uint8_t)(((uint32_t)s64Fill3) & 0xFFu);

    /* too short for optimizations */
    if ( u32Length3 < MEMSET_OPT_LENGTH )
    {
        for (cur_idx = 0U; cur_idx < u32Length3; cur_idx++)
        {
            dest[cur_idx] = u8Fill3;
        }
    }
    /* optimized code */
    else
    {
        /* write first unaligned part of bytes (if any) */
        while ( 0U != ((uaddr_t)(&dest[cur_idx]) & 3U) )
        { /* set first unaligned bytes */
            dest[cur_idx] = u8Fill3;
            cur_idx++;
        }

        /* write word aligned part of data */
        uint32_t *dest_aligned32 = (uint32_t *)(&dest[cur_idx]);
        const uint32_t u32_fill = 0x01010101U * u8Fill3;
        for (; cur_idx < (u32Length3 - 3U); cur_idx += 4U)
        {
            *dest_aligned32 = u32_fill;
            dest_aligned32++;
        }

        /* write the last unaligned bytes (if any) */
        for (; cur_idx < u32Length3; cur_idx++)
        {
            dest[cur_idx] = u8Fill3;
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
    uint8_t  u8ShiftDif;

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
            memcpy8_backwards_aux(pu8AfterDst4, pu8FirstDst4, pcou8AfterSrc4);
        }
        /* optimized copying */
        else
        {
            /* warning - conversion to smaller type (lost of higher bytes) - required behaviour here */
            u8ShiftDif = (uint8_t)((uaddr_t)pavDest4 - (uaddr_t)pcoavSource4);
            /* Check whether offset between pointers is multiple of 4 (last 2 bits are zero) */
            if ( 0U == (u8ShiftDif & 3U) )
            {   /* move along 4B */
                memcpy32_backwards_aux(pu8AfterDst4, pu8FirstDst4, pcou8AfterSrc4);
            }
            /* 2B shift between destination and source data addresses */
            else if ( 0U == (u8ShiftDif & 1U) )
            {
                /* move along 2B */
                memcpy16_backwards_aux(pu8AfterDst4, pu8FirstDst4, pcou8AfterSrc4);
            }
            /* any other shifting */
            else
            {   /* move along 1B */
                memcpy8_backwards_aux(pu8AfterDst4, pu8FirstDst4, pcou8AfterSrc4);
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
    int32_t s32Result5;
    uint8_t u8ShiftDif;

    /* too short for optimizations */
    if (u32Size5 < MEMCMP_OPT_LENGTH )
    {
        s32Result5 = memcmp8_aux(pcoavMemA5, pcoavMemB5, u32Size5);
    }
    /* optimized comparing */
    else
    {
        /* In this optimizations aligning by first string */
        u8ShiftDif = (uint8_t)(((uaddr_t)pcoavMemB5-(uaddr_t)pcoavMemA5) & 3U);
        /* Check whether offset between pointers is multiple of 4 (last 2 bits are zero) */
        if ( 0U == u8ShiftDif )
        {
            /* comparing along 4B */
            s32Result5 = memcmp32_aux(pcoavMemA5, pcoavMemB5, u32Size5);
        }
        /* 2B shift between destination and source data addresses */
        else if ( 0U == (u8ShiftDif & 1U) )
        {
            /* comparing along 2B */
            s32Result5 = memcmp16_aux(pcoavMemA5, pcoavMemB5, u32Size5);
        }
        /* any other shifting */
        else
        {
            s32Result5 = memcmp8_aux( pcoavMemA5, pcoavMemB5, u32Size5 );
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
    uint32_t u32Ctr7 = 0U;

    for (u32Ctr7 = 0U; u32Ctr7 < u32Length7; u32Ctr7++)
    {
        if ('\0' == pcoszSrc7[u32Ctr7] )
        {
            break;
        }
        else
        {
            pszDest7[u32Ctr7] = pcoszSrc7[u32Ctr7];
        }
    }

    /* Fill the rest of the destination string with zeros */
    while ( u32Ctr7 < u32Length7 )
    {
        pszDest7[u32Ctr7] = '\0';
        u32Ctr7++;
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
    /* BYTE pointers */
    const uint8_t *pcoau8StrA6 = (const uint8_t*)pcoszStrA6;
    const uint8_t *pcoau8StrB6 = (const uint8_t*)pcoszStrB6;

    uint8_t  u8ShiftDif = (uint8_t)(((uaddr_t)pcoszStrB6 - (uaddr_t)pcoszStrA6) & 3U);
    /* Check whether offset between pointers is multiple of 4 (last 2 bits are zero) */
    if ( 0U == u8ShiftDif )
    {   /* comparing along 4B */
        s32Result6 =  strcmp32_aux(pcoau8StrA6, pcoau8StrB6);
    }
    else if ( 0U == (u8ShiftDif & 1U) )
    {   /* Compare along 2B */
        s32Result6 =  strcmp16_aux(pcoau8StrA6, pcoau8StrB6);
    }
    /* any other shifting */
    else
    {
        s32Result6 =  strcmp8_aux(pcoau8StrA6, pcoau8StrB6);
    }

    return s32Result6;
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
    while ( pcozsStr8[u32Length8] != '\0' )
    {
        u32Length8++;
    }
    return u32Length8;   /* HIS_COMF check suppression comment */
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

    if(NULL_PTR != pcozsStr8)
    {
        while((u32Length8 < u32Strsz) && (pcozsStr8[u32Length8] != '\0'))
        {
            u32Length8++;   /* HIS_COMF check suppression comment */
        }
    }

    return u32Length8;
}

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"


#ifdef __cplusplus
}
#endif
