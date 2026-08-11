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
 *  Copyright 2019-2024 NXP
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
 * ========================================================================= */


/*
* Block allocator
* This module partitions the memory pool into blocks (chunks) of a fixed size and provides one or more
* chunks to satisfy the request.
* The allocator maintains a map of free/used chunks in a form of 2-bit array where each 2-bits represent
* one chunk. The value encoding is the following:
* 00 - unused chunk ready to be provided
* 01 - used chunk
* 11 - used chunk, last in the region
* 10 - reserved
* There are dummy bits at the end of the bit array to have integral number of bytes.
* The dummy bits are always set.
*
* Note to "2-bit": the term 2-bit is used to refer to the pair of bits representing a single chunk. There
* are 4 2-bits in the byte.
*/


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43140440


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "pfe_cfg.h"
#include "oal.h"
#include "blalloc.h"
/*==================================================================================================
                                            CHECKS
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
#define CHUNKS_IN_BYTE BLALLOC_CFG_CHUNKS_IN_BYTE
#define CHUNK_BITS_COUNT (8U / CHUNKS_IN_BYTE)

#define USED_CHUNK 0x01U
#define LAST_USED_CHUNK 0x03U

#define CHUNK_TEST_MASK 0xC0U
#define CHUNK_TEST_SHIFT ((CHUNKS_IN_BYTE - 1U) * CHUNK_BITS_COUNT)
#define ALL_CHUNKS_USED ((USED_CHUNK << 6U) | (USED_CHUNK << 4U) | (USED_CHUNK << 2U) | (USED_CHUNK << 0U))
#define ALL_CHUNKS_USED_LAST ((LAST_USED_CHUNK << 6U) | (LAST_USED_CHUNK << 4U) | (LAST_USED_CHUNK << 2U) | (LAST_USED_CHUNK << 0U))

#define SUM_WRAP_U32(A,B) ((uint32_t)((((uint64_t)(A) & UINT32_MAX) + (B)) & UINT32_MAX))
#define UDIV32_ROUND_UP(N,D) ((((uint64_t)(N) & UINT32_MAX) + (D) - 1U) / (D))

/**
 * @brief A temporary define used to determine context size in blalloc_create(). 
 * Total size: 
 *  Set according to the FW DMEM physical size (16 kB) for possible FW upgrade. 
 *  
 *  Calculated as:
 *      sizeof(blalloc_t) + (0x4000 >> PFE_CLASS_HEAP_CHUNK_SIZE) / CHUNKS_IN_BYTE
 *  Meaning:
 *      sizeof(blalloc_t) + Size of DMEM / chunk size (B) / number of chunkinfo per byte
 *  In values:
 *      28 + ((0x4000 / 16) / (8/2)) = 28 + 256 = 284
 * 
 */
#define PFE_CLASS_HEAP_CHUNK_SIZE               (4U)
#define BLALLOC_T_STATIC_ALLOCATION_SIZE_B      (sizeof(blalloc_t) + ((0x4000U >> PFE_CLASS_HEAP_CHUNK_SIZE) / CHUNKS_IN_BYTE))
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define ETH_43_PFE_START_SEC_VAR_CLEARED_8
#include "Eth_43_PFE_MemMap.h"
__attribute__((aligned(16))) static uint8_t blalloc_create_context_static[BLALLOC_T_STATIC_ALLOCATION_SIZE_B];
#define ETH_43_PFE_STOP_SEC_VAR_CLEARED_8
#include "Eth_43_PFE_MemMap.h"


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"

static void set_bits(uint8_t *bytes, size_t offset, size_t count);
static void clear_bits(uint8_t *bytes, size_t offset, size_t count);
static inline size_t chunks_count(const blalloc_t *ctx, const size_t size);
static inline size_t chunks_alignment(const blalloc_t *ctx, const size_t align);
static inline size_t calculate_offset(const blalloc_t *ctx);
static inline void chunks_mark(blalloc_t *ctx, const size_t size, const size_t offset, const size_t count);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
/*
* @brief Marks the given count ouf chunks as used, marks the last one as the last one
* @param[in] bytes Array containing the chunk information
* @param[in] offset Index of the first chunk to mark as used
* @param[in] count Number of chunks to mark as used
*/
static void set_bits(uint8_t *bytes, size_t offset, size_t count)
{
    uint_t first_chunk = offset;
    uint_t first_byte = offset / CHUNKS_IN_BYTE;
    uint_t last_chunk = SUM_WRAP_U32(offset, count - 1U);
    uint_t last_byte = last_chunk / CHUNKS_IN_BYTE;
    uint_t i;


    for(i = first_byte; i <= last_byte; i++)
    {
        uint8_t mask = 0xFFU;

        if(i == first_byte)
        {   /* Some bits in the first byte (before the first chunk) shall not be affected */
            /* Do not modify bits before the first chunk - set their mask to 0 */
            mask = (uint8_t)(mask & (0xFFU >> ((first_chunk % CHUNKS_IN_BYTE) * CHUNK_BITS_COUNT)));
        }

        if(i == last_byte)
        {
            if(0U != ((size_t)(((uint64_t)offset + count) % CHUNKS_IN_BYTE)))
            {   /* Some bits in last byte (after last chunk) shall not be affected */
                uint_t shift = ((CHUNKS_IN_BYTE - ((count + offset) % CHUNKS_IN_BYTE)) * CHUNK_BITS_COUNT);
                mask &= 0xFFU << shift;
                bytes[i] |= LAST_USED_CHUNK << shift;
            }
            else
            {   /* All bits shall be affected - the last chunk is the last one in the last byte */
                ;/* shift = 0; mask &= 0xFFU; which does not have any effect */
                bytes[i] |= LAST_USED_CHUNK;
            }

        }
        bytes[i] |= ALL_CHUNKS_USED & mask;
    }
}

/*
* @brief Marks given count of chunks as unused (inverse function to set_bits())
* @param[in] bytes Array containing the chunk information
* @param[in] offset Index of the first chunk to mark as unused
* @param[in] count Number of chunks to mark as unused
*/
static void clear_bits(uint8_t *bytes, size_t offset, size_t count)
{
    uint_t first_chunk = offset;
    uint_t first_byte = offset / CHUNKS_IN_BYTE;
    uint_t last_chunk = SUM_WRAP_U32(offset, count - 1U);
    uint_t last_byte = last_chunk / CHUNKS_IN_BYTE;
    uint_t i;

    /* The algorithm is the same as in set_bits() with two modifications:
       1, we do not mark the last chunk
       2, the mask is at the end inverted and ANDed to the byte instead of ORing it
    */

    for(i = first_byte; i <= last_byte; i++)
    {
        uint8_t mask = 0xFFU;

        if(i == first_byte)
        {   /* Some bits in the first byte (before the first chunk) shall not be affected */
            /* Do not modify bits before the first chunk - set their mask to 0 */
            mask = (uint8_t)(mask & (0xFFU >> ((first_chunk % CHUNKS_IN_BYTE) * CHUNK_BITS_COUNT)));
        }

        if(i == last_byte)
        {
            if(0U != (size_t)(((uint64_t)offset + count) % CHUNKS_IN_BYTE))
            {   /* Some bits in last byte (after last chunk) shall not be affected */
                uint_t shift = ((CHUNKS_IN_BYTE - ((count + offset) % CHUNKS_IN_BYTE)) * CHUNK_BITS_COUNT);
                mask &= 0xFFU << shift;
            }
            else
            {   /* All bits shall be affected - the last chunk is the last one in the last byte */
                ;/* shift = 0; mask &= 0xFFU; which does not have any effect */

            }

        }
        bytes[i] &= ~mask;
    }
}

/**
 * @brief Calculate number of chunks
 * @param[in] ctx Context instance
 * @param[in] size Size of the memory to be allocated
 * @return Number of chunks to allocate
 */
static inline size_t chunks_count(const blalloc_t *ctx, const size_t size)
{
    /* How many chunks do we need? */
    PfeDevAssert(((size_t)1U << ctx->chunk_size) > 0U);
    const size_t sizemask = ((size_t)1U << ctx->chunk_size) - (size_t)1U;

    PfeDevAssert((SIZE_MAX - size) >= sizemask);
    /* Round size toward the nearest multiple of chunk size
       - causes sizes less than a chunk to allocate one chunk (value 0 is not considered as it is stupid)
       - Translate size to chunks count */
    const size_t size_rounded = ((size + sizemask) & ~sizemask) >> ctx->chunk_size;

    return size_rounded;
}

/**
 * @brief Calculate needed alignment
 * @param[in] ctx Context instance
 * @param[in] size Size of the memory to be allocated
 * @return Needed memory alignment
 */
static inline size_t chunks_alignment(const blalloc_t *ctx, const size_t align)
{
    PfeDevAssert(((size_t)1U << ctx->chunk_size) > 0U);
    const size_t sizemask = ((size_t)1U << ctx->chunk_size) - (size_t)1U;

    PfeDevAssert((SIZE_MAX - align) >= sizemask);
    size_t align_temp = (align + sizemask) >> ctx->chunk_size;

    if(0U == align_temp)
    {   /* Prevent division by 0 in case of align = 0 and chunk_size = 0 (1 byte) */
        align_temp = 1U;
    }

    return align_temp;
}

/**
 * @brief Calculate offset of first chunk of the examined area
 * @param[in] ctx Context instance
 * @return First chunk of the examined area
 */
static size_t calculate_offset(const blalloc_t *ctx)
{
    PfeDevAssert(ctx->start_srch >= (ctx->start_srch % CHUNKS_IN_BYTE));
    size_t offset = ctx->start_srch - (ctx->start_srch % CHUNKS_IN_BYTE);
    return offset;
}

/**
 * @brief Mark found chunks
 * @param[in] ctx Context instance
 * @param[in] size Size of the memory to be allocated
 * @param[in] offset Starting chunk of the examined area
 * @param[in] count Number of chunks
 */
static inline void chunks_mark(blalloc_t *ctx, const size_t size, const size_t offset, const size_t count)
{
    /* Lock all chunks we have found */
    set_bits(ctx->chunkinfo, offset, count);

    /* Did we use the first known empty chunk */
    if(ctx->start_srch == offset)
    {   /* First known empty chunk is no longer empty */
        /* Start next search following the memory we have provided just now */
        PfeDevAssert((SIZE_MAX - ctx->start_srch) >= count);
        ctx->start_srch += count;
    }

    PfeDevAssert((SIZE_MAX - ctx->allocated) >= (count << ctx->chunk_size));
    ctx->allocated += count << ctx->chunk_size;

    PfeDevAssert((SIZE_MAX - ctx->requested) >= size);
    ctx->requested += size;
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief Allocates and initializes a context to be used with the other API.
 * Will be removed in AAVB-5861!
 * This function should only be used for the FW heap and the size of the context is fixed according to DMEM heap size, defined in the FW binary.
 * @param[in] size  Size of the memory (should be multiple of chunk_size - cannot provide less than a chunk).
 * @param[in] chunk_size Provided memory smallest size (configured as 2 to power of the provided value)
 * @return pointer to internal context or NULL in case of failure
 */
blalloc_t *blalloc_create(size_t size, size_t chunk_size)
{
    blalloc_t *ctx;
    /* Number of bytes needed to store information about all chunks
       Round up to the nearest multiple of N and then divide by N is achieved by ((x + (N-1)) / N) */
    uint_t chunkinfo_size = (uint_t)UDIV32_ROUND_UP((uint64_t)size >> chunk_size, CHUNKS_IN_BYTE);

    if(0U == (size >> chunk_size))
    {   /* Memory not large enough to contain at least 1 chunk */
        NXP_LOG_ERROR("Size of memory is less than a chunk\n");
        ctx = NULL_PTR;
    }
    else
    {
        if(sizeof(blalloc_create_context_static) < (sizeof(blalloc_t) + chunkinfo_size))
        {
            /* Memory allocation failure - insufficient buffer size */
            NXP_LOG_ERROR("Failed to allocate memory\n");
            ctx = NULL_PTR;
        }
        else
        {
            /* Provide local static context memory for internal structure + array of bytes which will have
               2 bits for each chunk => number of chunks / 4 and then rounded up;
               Number of chunks is equal to size >> chunk_size. */
            ctx = (blalloc_t *)blalloc_create_context_static;
        
            /* Clear the whole context */
            (void)autolibc_memset(ctx, 0, sizeof(blalloc_t));

            /* Remember the input data */
            ctx->size = size;
            ctx->chunk_size = chunk_size;

            /* Init pointer to chunkinfo memory (behind the structure) */
            ctx->chunkinfo = (uint8_t *)(ctx + 1U); /* Adds 1 struct size */

            if(EOK != blalloc_init(ctx))
            {
                ctx = NULL_PTR;
            }
            else
            {
                ctx->status = BL_DYNAMIC;
            }
        }
    }
    return ctx;
}

/**
 * @brief Finalize and release block allocator instance
 * @param[in] ctx Context instance
 */
void blalloc_destroy(blalloc_t *ctx)
{
    if (BL_DYNAMIC != ctx->status)
    {
        NXP_LOG_ERROR("Attempt to destroy static instance\n");
    }
    else
    {
        /* If some memory has not been returned it will be leaked */
        blalloc_fini(ctx);
    }
}

/**
 * @brief   Initialize static block allocator instance
 * @param[in] ctx Context instance
 * @return EOK if success, error code otherwise
 */
errno_t blalloc_init(blalloc_t *ctx)
{
    errno_t ret;
    uint_t chunkinfo_size = (uint_t)UDIV32_ROUND_UP((uint64_t)ctx->size >> ctx->chunk_size, CHUNKS_IN_BYTE);

    if(0U == (ctx->size >> ctx->chunk_size))
    {
        NXP_LOG_ERROR("Size of memory is less than a chunk\n");
        ret = EINVAL;
    }
    else
    {
        oal_mutex_lock(PFE_BLALLOC_MUTEX_00);

        /* Clear the chunkinfo storage */
        (void)autolibc_memset(ctx->chunkinfo, 0, chunkinfo_size);

        ctx->start_srch = 0U;
        ctx->status = BL_STATIC;

        /* Mark dummy chunks at the end (if any) as used to prevent their allocation */
        if(0U != ((ctx->size >> ctx->chunk_size) % CHUNKS_IN_BYTE))
        {
            /* Calculate the remainder after division by CHUNKS_IN_BYTE which are used chunks in the byte
               shift ALL_CHUNKS_USED_LAST to right by the calculated number of used chunks so their positions
               will be replaced by 0s leaving the value only in unused positions */
            const uint_t used_chunks = (uint_t)((((ctx->size >> ctx->chunk_size) % CHUNKS_IN_BYTE) * CHUNK_BITS_COUNT) & (uint_t)UINT8_MAX);
            PfeDevAssert(chunkinfo_size > 0U);
            ctx->chunkinfo[chunkinfo_size - 1U] |= (uint8_t)(((uint32_t)ALL_CHUNKS_USED_LAST >> used_chunks) & (uint32_t)UINT8_MAX);
        }
        oal_mutex_unlock(PFE_BLALLOC_MUTEX_00);
        ret = EOK;
    }

    return ret;
}

/**
 * @brief Finalize block allocator instance
 * @param[in] ctx Context instance
 */
void blalloc_fini(blalloc_t *ctx)
{
    ctx->status = BL_INVALID;
}

/**
 * @brief     Allocates the memory
 * @param[in] ctx Context
 * @param[in] size Size of the memory to be allocated.
 * @param[in] align Required memory alignment; values are rounded toward nearest upper multiple of the chunk size.
 *                  It is expected that only multiples of chunk size are used - rounding is a side effect of
 *                  used algorithm.
 * @param[out] addr Allocated memory offset from the memory base
 * @return EOK on success or ENOMEM on failure.
 */
errno_t blalloc_alloc_offs(blalloc_t *ctx, size_t size, size_t align, addr_t *addr)
{
    uint_t i,j;
    size_t needed; /* Needed number of unused chunks to satisfy the memory request */
    size_t found;  /* Number of unused chunks in the examined area including the starting one */
    size_t offset; /* Starting chunk of the examined area */
    size_t align_temp = align;
    errno_t ret;
    bool_t exit_quick = FALSE;
    const uint_t chunkinfo_size = (uint_t)UDIV32_ROUND_UP((uint64_t)ctx->size >> ctx->chunk_size, CHUNKS_IN_BYTE);

    needed = chunks_count(ctx, size);
    align_temp = chunks_alignment(ctx, align);
    found = 0U;

    /* Set initial search position */
    offset = calculate_offset(ctx);

    oal_mutex_lock(PFE_BLALLOC_MUTEX_01);
    /* Go through all bytes in ctx->chunkinfo starting from the one containing first known chunk */
    for(i = (ctx->start_srch / CHUNKS_IN_BYTE); i < chunkinfo_size; i++)
    {
        uint8_t bits = ctx->chunkinfo[i];
        /* Go through all 2-bits (chunks) in the current byte */
        for(j = 0U; j < CHUNKS_IN_BYTE; j++)
        {
            /* Check if the chunk is in use */
            if(0U == (bits & CHUNK_TEST_MASK))
            {   /* Not in use */
                /* Check alignment if it can be the starting chunk */
                if(0U != (offset % align_temp))
                {   /* This offset would not lead to a needed alignment */

                    /* We increment the offset to try the next one if it is not properly
                       aligned. Note that we do not increment offset in the other branch
                       therefore it remains aligned all the time we are in the "chunk not in use"
                       branch and therefore we are only incrementing the number of found unused
                       chunks once we found the aligned (first) chunk. */
                    offset++;   /* Next chunk could be start */
                    found = 0U; /* We do not have any chunks found */
                }
                else
                {   /* Chunk can be used as a starting one */
                    /* We do not increment the offset therefore it will stay aligned
                       and this branch will be always executed */
                    /* Increment number of unused chunks in a row */
                    found++;
                }
            }
            else
            {   /* Row has ended (if it started before) and we have not reached required number
                   of chunks, start from scratch */
                /* Skip the chunks already examined because the row starting on these chunks
                   cannot be longer - it will also end here */
                PfeDevAssert((SIZE_MAX - offset) >= (found + 1U));
                offset += found + 1U; /* Next chunk could be start */
                found = 0U;           /* We do not have any chunks found */
            }
            /* Do we have enough chunks in the row? */
            if(found == needed)
            {   /* We got the requested size */
                chunks_mark(ctx, size, offset, needed);

                /* Return the chunk offset */
                *addr = offset << ctx->chunk_size;
                ret = EOK;
                exit_quick = TRUE;
                break;
            }
            /* Test the next 2-bit */
            bits <<= CHUNK_BITS_COUNT;
        }
        if(TRUE == exit_quick)
        {
            break;
        }
    }
    if(TRUE != exit_quick)
    {
        /* Failed */
        NXP_LOG_ERROR("Allocation of %u bytes aligned at %u chunks failed\n",(uint_t)size,(uint_t)align_temp);
        ret = ENOMEM;
    }
    /* Do not forget to unlock spinlock */
    oal_mutex_unlock(PFE_BLALLOC_MUTEX_01);
    return ret;
}

/**
 * @brief Deallocates the memory  previously allocated by blalloc_alloc_offs
 * @param[in] ctx Context
 * @param[in] offset Memory offset as returned by the allocation function
 * @param[in] size Memory size in bytes (same value as passed to the allocation function)
*/
void blalloc_free_offs_size(blalloc_t *ctx, addr_t offset, size_t size)
{
    size_t count;
    uint32_t size_pad;

    oal_mutex_lock(PFE_BLALLOC_MUTEX_02);

    PfeDevAssert(((size_t)1U << ctx->chunk_size) > 0U);
    size_pad = ((size_t)1U << ctx->chunk_size) - (size_t)1U;
    count = (size_t)((((uint64_t)size + (uint64_t)size_pad) >> ctx->chunk_size) & UINT32_MAX);

    clear_bits(ctx->chunkinfo, offset >> ctx->chunk_size, count);

    if((ctx->start_srch) > (offset >> ctx->chunk_size))
    {   /* We have new first known empty chunk, remember it */
        ctx->start_srch = offset >> ctx->chunk_size;
    }
    oal_mutex_unlock(PFE_BLALLOC_MUTEX_02);
}

/**
 * @brief Deallocates the memory previously allocated by blalloc_alloc_offs
 * @param[in] ctx Context
 * @param[in] offset Memory offset as returned by the allocation function
 */
void blalloc_free_offs(blalloc_t *ctx, addr_t offset)
{
    uint_t first_chunk = offset >> ctx->chunk_size;
    uint_t first_byte = (first_chunk) / CHUNKS_IN_BYTE;
    uint_t max_byte = (uint_t)UDIV32_ROUND_UP((uint64_t)ctx->size >> ctx->chunk_size, CHUNKS_IN_BYTE);

    /* How many chunk records to skip in the 1st byte */
    uint_t first_shift = first_chunk % CHUNKS_IN_BYTE;
    uint_t count = 0U;
    uint8_t byte;
    uint8_t chunk;
    uint_t i,j;
    bool_t exit_quick = FALSE;

    /* Check if chunk is free already or not */
    byte = ctx->chunkinfo[first_byte];
    chunk = (uint8_t)(((uint32_t)byte << (first_shift * CHUNK_BITS_COUNT)) & CHUNK_TEST_MASK);
    if(chunk == 0x0U)
    {
        NXP_LOG_WARNING("blalloc_free_offs called on an already empty area\n");
    }
    else
    {
        oal_mutex_lock(PFE_BLALLOC_MUTEX_03);
        if((ctx->start_srch) > first_chunk)
        {   /* We have new first known empty chunk, remember it */
            ctx->start_srch = first_chunk;
        }

        for(i = first_byte; i < max_byte; i++)
        {
            byte = ctx->chunkinfo[i];
            for(j = first_shift; j < CHUNKS_IN_BYTE; j++)
            {
                /* Count the chunks tested */
                PfeDevAssert(SIZE_MAX > count);
                count++;
                /* Get the chunk bits to the position for testing (most left) */
                chunk = (uint8_t)(((uint32_t)byte << (j * CHUNK_BITS_COUNT)) & CHUNK_TEST_MASK);
                /* Test the chunk bits */
                if((LAST_USED_CHUNK << CHUNK_TEST_SHIFT) == chunk)
                {   /* This is the last chunk */
                    clear_bits(ctx->chunkinfo, first_chunk, count);
                    exit_quick = TRUE;
                    break;
                }
                /* If needed we could add some checks here */
            }
            if(TRUE == exit_quick)
            {
                break;
            }
            /* From the 1st iteration we do not need initial shift -
               it may be valid only for the first byte */
            first_shift = 0U;
        }
        if(FALSE == exit_quick)
        {
            /* We should never get here */
            NXP_LOG_ERROR("Internal memory corrupted\n");
        }
    }
    oal_mutex_unlock(PFE_BLALLOC_MUTEX_03);
}

#if defined(PFE_CFG_TEXT_STATS)
/**
* @brief Reads the memory usage statistics in a text form
* @param[in] ctx Context
* @param[out] buf Output text buffer
* @param[in] buf_len Size of the output text buffer
* @param[in] verb_level Verbosity lever
* @return Number of characters written into the buffer.
*/
uint32_t blalloc_get_text_statistics(const blalloc_t *ctx, char_t *buf, uint32_t buf_len, uint8_t verb_level)
{
    uint_t i, j;               /* Counters */
    uint_t prev = 0U;          /* Did the used chunk precede this chunk? 1 = yes */
    uint_t unused_chunks = 0U; /* Count of used chunks */
    uint_t used_chunks = 0U;   /* Count of unused chunks */
    uint_t fragments = 0U;     /* Count of holes between chunks */
    uint32_t len = 0U;         /* Number of characters written into the buf */
    uint_t byte_count = ((ctx->size >> ctx->chunk_size) + 3U) >> 2U;

    /* Go through all bytes in chunkinfo */
    for(i = 0U; i < byte_count; i++)
    {
        uint8_t bits = ctx->chunkinfo[i];

        if(verb_level > 0U)
        {   /* Detailed information requested */
            /* After each 32 bytes (and at start) print out a new line and address */
            if(0U == (i % 32U))
            {
                len += oal_util_snprintf(buf + len, buf_len - len, "\n0x%05x: ", i * 4U * (1U << ctx->chunk_size));
            }
            /* Print current chunkinfo byte */
            len += oal_util_snprintf(buf + len, buf_len - len, "%02x", bits);
        }

        /* Go through all 2-bits in the current byte */
        for(j = 0U; j < CHUNKS_IN_BYTE; j++)
        {
            if(0U == (bits & CHUNK_TEST_MASK))
            {   /* Chunk not in use */
                unused_chunks++;
                if(prev != 0U)
                {   /* Previous chunk was in use */
                    fragments++; /* Increment number of holes between chunks */
                }
                prev = 0U;
            }
            else
            {   /* Chunk in use */
                used_chunks++;
                prev = 1U;
            }
            /* Check the next 2-bit */
            bits <<= CHUNK_BITS_COUNT;
        }
    }
    /* Print out the information */
    len += oal_util_snprintf(buf + len, buf_len - len, "\n"); /* End previous output */
    len += oal_util_snprintf(buf + len, buf_len - len, "Free  memory %u bytes (%u chunks)\n", unused_chunks * ((uint_t)1U << ctx->chunk_size), unused_chunks);
    len += oal_util_snprintf(buf + len, buf_len - len, "Used  memory %u bytes (%u chunks)\n", used_chunks * ((uint_t)1U << ctx->chunk_size), used_chunks);
    len += oal_util_snprintf(buf + len, buf_len - len, "Total memory %u bytes (%u chunks)\n", (uint_t)ctx->size, byte_count * CHUNKS_IN_BYTE);
    len += oal_util_snprintf(buf + len, buf_len - len, "Chunk size   %u bytes\n", (1U << ctx->chunk_size));
    len += oal_util_snprintf(buf + len, buf_len - len, "Fragments    %u\n", fragments);
    len += oal_util_snprintf(buf + len, buf_len - len, "Dummy chunks %u\n", (uint_t)((byte_count * CHUNKS_IN_BYTE) - (ctx->size >> ctx->chunk_size)));
    if(verb_level > 0U)
    {   /* Detailed information requested */
        len += oal_util_snprintf(buf + len, buf_len - len, "1st free chunk  %u\n", (uint_t)ctx->start_srch);
        len += oal_util_snprintf(buf + len, buf_len - len, "Bytes requested %u (cumulative)\n", (uint_t)ctx->requested);
        len += oal_util_snprintf(buf + len, buf_len - len, "Bytes allocated %u (cumulative)\n", (uint_t)ctx->allocated);
    }
    return len;
}

#endif /* defined(PFE_CFG_TEXT_STATS) */

#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
