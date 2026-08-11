/**
 *  @file             nxp_snprintf.c
 *  @brief            Module serves to printing debug messages
 */
/*==================================================================================================
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
 *  Copyright (c) 2014-2016 Freescale Semiconductor Inc.
 *  Copyright 2016-2018, 2020-2022 NXP
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PFE_SRC_VERSION_CHECK 43120440

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "pfe_cfg.h"
#include "nxp_snprintf.h"

#if defined(NXP_LOG_ENABLED)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
#define FLAG_NONE                    0U
#define FLAG_MINUS                   1U  /* Left aligned position of - or + */
#define FLAG_PLUS                    2U  /* Add '+' or '-' */
#define FLAG_SPACE                   4U  /* Add ' ' or '-' */
#define FLAG_HASH                    8U  /* Add 0x to hexa, always add . to floating point */
#define FLAG_ZERO                   16U  /* Pad with leading zeros to get the minimal width */
#define FLAG_UNSUPPORTED           128U  /* Output only ?? and perform no other action - this type is not supported
                                            the rest of the arguments will be most probably corrupted */

#define WIDTH_NONE                   (-1) /* Output width not specified */
#define WIDTH_STAR                   (-2) /* The next argument specifies the width */

#define PRECISION_NONE               (-1)
#define PRECISION_STAR               (-2)

#define LENGTH_NONE                  0U
#define LENGTH_HH                    1U
#define LENGTH_H                     2U
#define LENGTH_LITTLE_L              3U
#define LENGTH_LITTLE_LL             4U
#define LENGTH_J                     5U
#define LENGTH_Z                     6U
#define LENGTH_T                     7U
#define LENGTH_LARGE_L               8U

#define SPECIFIER_NONE               0U

#define TYPE_NONE                    0U
#define TYPE_INT8                    1U
#define TYPE_UINT8                   2U
#define TYPE_INT16                   3U
#define TYPE_UINT16                  4U
#define TYPE_INT32                   5U
#define TYPE_UINT32                  6U
#define TYPE_INT64                   7U
#define TYPE_UINT64                  8U
#define TYPE_DOUBLE                  9U
#define TYPE_LONG_DOUBLE            10U
#define TYPE_STRING                 11U
#define TYPE_POINTER                12U
#define PUTC(Char) do{ if(pu8StrRplc < copcou8OutMax){ *pu8StrRplc = (uint8_t)(Char); pu8StrRplc++;} }while(FALSE)
#define CONV_BUF_SIZE 64U /* Big enough to be able to avoid output size checks */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/* Structure that keeps informations about parsed format specifier */
typedef struct {
    uint8_t u8Flags;       /* Flags modifying the result number look */
    int16_t s16Width;     /* Number of digits or spaces - minimal width of the output */
    int16_t s16Precision; /* Number of digits (0s emitted instead of spaces to reach this limit)*/
    uint8_t u8Length;      /* Length of the type to be converted (in bytes) */
    uint8_t u8Type;        /* Type to be converted (char, short, int, long ...) */
    uint8_t u8Specifier;   /* The letter specifying the format */
} FormatSpecifierType;

#if TRUE == NXP_SNPRINTF_CFG_FLOAT_SUPPORT
/*  This union is needed to be able to access bits of double values.
    Cast may not be used, it converts the value. */
typedef union
{
    float64_t dValue;
    uint64_t  u64Bits;
} tunDoubleToBits;
#endif /* NXP_SNPRINTF_CFG_FLOAT_SUPPORT */

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CONST_8
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

/* usage scope: vsnprintf */
static const uint8_t au8HexaUpper[16] = { (uint8_t)'0', (uint8_t)'1', (uint8_t)'2', (uint8_t)'3',
                                     (uint8_t)'4', (uint8_t)'5', (uint8_t)'6', (uint8_t)'7',
                                     (uint8_t)'8', (uint8_t)'9', (uint8_t)'A', (uint8_t)'B',
                                     (uint8_t)'C', (uint8_t)'D', (uint8_t)'E', (uint8_t)'F'
                                   };

/* usage scope: vsnprintf */
static const uint8_t au8HexaLower[16] = { (uint8_t)'0', (uint8_t)'1', (uint8_t)'2', (uint8_t)'3',
                                     (uint8_t)'4', (uint8_t)'5', (uint8_t)'6', (uint8_t)'7',
                                     (uint8_t)'8', (uint8_t)'9', (uint8_t)'a', (uint8_t)'b',
                                     (uint8_t)'c', (uint8_t)'d', (uint8_t)'e', (uint8_t)'f'
                                   };

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CONST_8
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_START_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

static uint32_t Minimum(uint32_t u32Value1, uint32_t u32Value2);
static uint8_t* StrReplaceSint32(int32_t s32Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec);
#if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
static uint8_t* StrReplaceSint64(int64_t s64Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec);
#endif
static uint8_t* StrReplaceUint32(uint32_t u32Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec);
#if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
static uint8_t * StrReplaceUint64(uint64_t u64Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec);
#endif
static uint8_t* StrReplaceOctal32(uint32_t u32Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec);
#if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
static uint8_t* StrReplaceOctal64(uint64_t u64Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec);
#endif
static uint8_t* StrReplaceHexa32(uint32_t u32Value, uint8_t *pu8DestStr, const uint8_t pu8Hexa[], FormatSpecifierType formatSpec);
#if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
static uint8_t* StrReplaceHexa64(uint64_t u64Value, uint8_t *pu8DestStr, const uint8_t pu8Hexa[], FormatSpecifierType formatSpec);
#endif
static uint8_t* StrReplaceChar(uint8_t u8Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec);
static uint8_t* StrReplaceString(const uint8_t pcou8Value[], uint8_t *pu8DestStr, uint32_t u32DestFree, FormatSpecifierType formatSpec);
static uint8_t* ConvertBufWithWidthPrecision(const uint8_t pcou8Buf[], uint16_t u16BufLen, uint8_t pu8DestStr[], FormatSpecifierType formatSpec);
static const uint8_t* ParseFormatSpecifier(const uint8_t pcou8FormatStr[],FormatSpecifierType *formatSpec);
#if TRUE == NXP_SNPRINTF_CFG_FLOAT_SUPPORT
static void ConvertDoubleToScientific(float64_t dNum, char_t *pcNegative, int16_t *ps16Exp, uint8_t *pu8Bdp, uint32_t *pu32Adp);
#endif /* NXP_SNPRINTF_CFG_FLOAT_SUPPORT */
static inline uint8_t *PutCA(const uint8_t *pcou8Src, uint8_t const * const copcou8InMax,
                                   uint8_t *pu8Out,   uint8_t const * const copcou8OutMax);
static inline uint8_t *PutS(const char_t *coszSrc, uint8_t *pu8Out, uint8_t const * const copcou8OutMax);

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#if TRUE == NXP_SNPRINTF_CFG_FLOAT_SUPPORT
/*
* @brief Converts the floating point number to scientific format
* @param[in] dNum - Number to convert
* @param[out] pcNegative sign flag either '-' when the number is negative or ' '(space) when it is non-negative
* @param[out] ps16Exp - Exponent value (signed)
* @param[out] pu8Bdp - Part before decimal point (only one digit 0-9)
* @param[out] pu32Adp - Part after decimal point (9 digits including leading 0s which must be printed out)
* @details Function returns integer numbers to be printed out to form the scientific format (%e) for floating
*         point numbers output.
*         The converted numbers shall be displayed by the following formatting string
*         snprintf(string, size, "%c%1u.%09ue%02d", negative, bdp, adp, exp);
* @warning Function does not handle NaN (not a number) and infinity numbers, also 0 although it is a special
*          case is converted to the same format as other numbers.
* @note This function involves floating point divisions and multiplications which may be done several times
*       which may consume quite a lot of CPU cycles on some cores.
*/
static void ConvertDoubleToScientific(float64_t dNum, char_t *pcNegative, int16_t *ps16Exp, uint8_t *pu8Bdp, uint32_t *pu32Adp)
{
    *ps16Exp = 0; /* We have to do this at each case */

    if((dNum < (0.0)) || (dNum > (0.0)))
    {
        /* Get the sign and convert dNum to absolute value */
        if(dNum < 0.0)
        {   /* - */
            dNum = -dNum;
            *pcNegative = '-';
        }
        else /* dNum > 0.0 */
        { /* + */
            *pcNegative = ' ';
        }

        /* Get the exponent and normalize number
          - this is done gradually to improve the performance */
        while(dNum >= 1e64)
        {
            dNum /= 1e64;
            *ps16Exp = (int16_t)(*ps16Exp + 64);
        }
        while(dNum >= 1e16)
        {
            dNum /= 1e16;
            *ps16Exp = (int16_t)(*ps16Exp + 16);
        }
        while(dNum >= 1e4)
        {
            dNum /= 1e4;
            *ps16Exp = (int16_t)(*ps16Exp + 4);
        }
        while(dNum >= 1e1)
        {
            dNum /= 1e1;
            *ps16Exp = (int16_t)(*ps16Exp + 1);
        }

        while(dNum <= 1e-64)
        {
            dNum *= 1e64;
            *ps16Exp = (int16_t)(*ps16Exp - 64);
        }
        while(dNum <= 1e-16)
        {
            dNum *= 1e16;
            *ps16Exp = (int16_t)(*ps16Exp - 16);
        }
        while(dNum <= 1e-4)
        {
            dNum *= 1e4;
            *ps16Exp = (int16_t)(*ps16Exp - 4);
        }
        while(dNum < 1.0)
        {
            dNum *= 10.0;
            *ps16Exp = (int16_t)(*ps16Exp - 1);
        }

        /* Part before decimal point */
        *pu8Bdp = (uint8_t) dNum;

        /* Part after decimal point */
        dNum = dNum - (float64_t)(*pu8Bdp);
        dNum *= 1e9;
        *pu32Adp = (uint32_t) dNum;
    }
    else /* dNum == 0 - special case */
    {
        *pcNegative = ' ';
        *pu8Bdp = 0U;
        *pu32Adp = 0U;
    }
}
#endif /* NXP_SNPRINTF_CFG_FLOAT_SUPPORT */


/*
* @brief     Function returns minimum of two variables
* @details
* @param[in] u32Value1       first value to compare
* @param[in] u32Value1       second value to compare
* @return                    value of the variable with lower value
*/
static uint32_t Minimum(uint32_t u32Value1, uint32_t u32Value2)
{
    uint32_t u32Minimum;

    if (u32Value1 < u32Value2)
    {
        u32Minimum = u32Value1;
    }
    else
    {
        u32Minimum = u32Value2;
    }

    return u32Minimum;
}

/*
* @brief     Signed to String
* @details   Converts value of the signed variable to the string
* @param[in] u32Value        value to convert to string
* @param[in] *pu8DestStr     result destination
* @param[in] formatSpec      format specifier precision
* @return                    pointer to the current position in buffer with replaced characters
*/
static uint8_t * StrReplaceSint32(int32_t s32Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec)
{
    uint8_t u8CurNum;
    int32_t s32Tmp;
    uint32_t u32Tmp;
    uint8_t au8Buffer[10U];
    uint16_t u16NumCntr = 0U;
    uint8_t *pu8ModifiedDestStr;

    if (0 > s32Value)
    {
        /* Change sign */
        s32Tmp = -s32Value;
        u32Tmp = (uint32_t)s32Tmp;
    }
    else
    {
        /* Do not change sign */
        u32Tmp = (uint32_t)s32Value;
    }

    do
    {
        u8CurNum = (uint8_t)(u32Tmp % 10U); /* Cannot be greater than 10 */
        au8Buffer[u16NumCntr] = (uint8_t)(u8CurNum + (uint8_t)'0');
        u16NumCntr++;
        u32Tmp /= 10U;
    } while (0U != u32Tmp);

    if (0 > s32Value)
    {
        /* Write - sign to buffer */
        au8Buffer[u16NumCntr] = (uint8_t)'-';
        u16NumCntr++;
    }
    else
    {   /* Positive number */
        if(FLAG_PLUS == (formatSpec.u8Flags & FLAG_PLUS))
        {   /* Plus sign shall be added */
            au8Buffer[u16NumCntr] = (uint8_t)'+';
            u16NumCntr++;
        }
        if(FLAG_SPACE == (formatSpec.u8Flags & FLAG_SPACE))
        {   /* Space shall be added */
            au8Buffer[u16NumCntr] = (uint8_t)' ';
            u16NumCntr++;
        }
    }

    /* Format "variable string" based on format specifier */
    pu8ModifiedDestStr = ConvertBufWithWidthPrecision(au8Buffer, u16NumCntr, pu8DestStr, formatSpec);

    /* Return current position in destination string */
    return pu8ModifiedDestStr;
}


#if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
/*
* @brief     Signed to String
* @details   Converts value of the signed variable to the string
* @param[in] u64Value        value to convert to string
* @param[in] *pu8DestStr     result destination
* @param[in] formatSpec      format specifier precision
* @return                    pointer to the current position in buffer with replaced characters
*/
static uint8_t * StrReplaceSint64(int64_t s64Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec)
{
    uint8_t u8CurNum;
    uint64_t u64Tmp;
    int64_t s64Tmp;
    uint8_t au8Buffer[21U];
    uint16_t u16NumCntr = 0U;
    uint8_t *pu8ModifiedDestStr;
    uint32_t u32CurTmp;
    uint32_t u32i;

    if (0 > s64Value)
    {
        /* Change sign */
        s64Tmp = -s64Value;
        u64Tmp = (uint64_t)s64Tmp;
    }
    else
    {
        /* Do not change sign */
        u64Tmp = (uint64_t)s64Value;
    }

    do
    {
        u32CurTmp = (uint32_t)(u64Tmp % 1000000000UL);
        u64Tmp /= 1000000000UL;
        for(u32i = 0U; u32i < 9U; u32i++)
        {   /* Produce 9 digits */
            u8CurNum = (uint8_t)(u32CurTmp % 10U);
            au8Buffer[u16NumCntr] = (uint8_t)(u8CurNum + (uint8_t)'0');
            u16NumCntr++;
            u32CurTmp /= 10U;
            if( (0U == u32CurTmp) && (0U == u64Tmp) )
            {   /* This is the last piece, skip leading zeros */
                break;
            }
        }
    } while (0U != u64Tmp);


    if (0 > s64Value)
    {
        /* Write - sign to buffer */
        au8Buffer[u16NumCntr] = (uint8_t)'-';
        u16NumCntr++;
    }
    else
    {   /* Positive number */
        if(FLAG_PLUS == (formatSpec.u8Flags & FLAG_PLUS))
        {   /* Plus sign shall be added */
            au8Buffer[u16NumCntr] = (uint8_t)'+';
            u16NumCntr++;
        }
        if(FLAG_SPACE == (formatSpec.u8Flags & FLAG_SPACE))
        {   /* Space shall be added */
            au8Buffer[u16NumCntr] = (uint8_t)' ';
            u16NumCntr++;
        }
    }

    /* Format "variable string" based on format specifier */
    pu8ModifiedDestStr = ConvertBufWithWidthPrecision(au8Buffer, u16NumCntr, pu8DestStr, formatSpec);

    /* Return current position in destination string */
    return pu8ModifiedDestStr;
}
#endif

/*
* @brief     Unsigned to String
* @details   Converts value of the unsigned variable to the string
* @param[in] u32Value        value to convert to string
* @param[in] *pu8DestStr     result destination
* @param[in] formatSpec      format specifier precision
* @return                    pointer to the current position in buffer with replaced characters
*/
static uint8_t * StrReplaceUint32(uint32_t u32Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec)
{
    uint8_t u8CurNum;
    uint32_t u32Tmp = u32Value;
    uint8_t au8Buffer[10U];
    uint16_t u16NumCntr = 0U;
    uint8_t *pu8ModifiedDestStr;

    /* Extract variable value */
    do
    {
        u8CurNum = (uint8_t)(u32Tmp % 10U);

        au8Buffer[u16NumCntr] = (uint8_t)(u8CurNum + (uint8_t)'0');
        u16NumCntr++;
        u32Tmp /= 10U;
    } while (0U != u32Tmp);

    /* Format "variable string" based on format specifier */
    pu8ModifiedDestStr = ConvertBufWithWidthPrecision(au8Buffer, u16NumCntr, pu8DestStr, formatSpec);

    /* Return current position in destination string */
    return pu8ModifiedDestStr;
}

#if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
/*
* @brief     Unsigned to String
* @details   Converts value of the unsigned variable to the string
* @param[in] u32Value        value to convert to string
* @param[in] *pu8DestStr     result destination
* @param[in] formatSpec      format specifier precision
* @return                    pointer to the current position in buffer with replaced characters
*/
static uint8_t * StrReplaceUint64(uint64_t u64Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec)
{
    uint8_t u8CurNum;
    uint64_t u64Tmp = u64Value;
    uint8_t au8Buffer[21U];
    uint16_t u16NumCntr = 0U;
    uint8_t *pu8ModifiedDestStr;
    uint32_t u32CurTmp;
    uint32_t u32i;

    /* Extract variable value */
    do
    {
        u32CurTmp = (uint32_t)(u64Tmp % 1000000000UL);
        u64Tmp /= 1000000000UL;
        for(u32i = 0U; u32i < 9U; u32i++)
        {   /* Produce 9 digits */
            u8CurNum = (uint8_t)(u32CurTmp % 10U);
            au8Buffer[u16NumCntr] = (uint8_t)(u8CurNum + (uint8_t)'0');
            u16NumCntr++;
            u32CurTmp /= 10U;
            if( (0U == u32CurTmp) && (0U == u64Tmp) )
            {   /* This is the last piece, skip leading zeros */
                break;
            }
        }
    } while (0U != u64Tmp);

    /* Format "variable string" based on format specifier */
    pu8ModifiedDestStr = ConvertBufWithWidthPrecision(au8Buffer, u16NumCntr, pu8DestStr, formatSpec);

    /* Return current position in destination string */
    return pu8ModifiedDestStr;
}
#endif


/*
* @brief     Octal to String
* @details   Converts value of the variable to octal format and than to the string
* @param[in] u32Value        value to convert to string
* @param[in] *pu8DestStr     result destination
* @param[in] formatSpec      format specifier precision
* @return                    pointer to the current position in buffer with replaced characters
*/
static uint8_t * StrReplaceOctal32(uint32_t u32Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec)
{
    uint8_t au8Buffer[11U];
    uint16_t u16NumCntr = 0U;
    uint8_t u8CurNum;
    uint32_t u32Tmp = u32Value;
    uint8_t *pu8ModifiedDestStr;

    do
    {
        u8CurNum = (uint8_t)((uint8_t)u32Tmp & 0x7U);
        au8Buffer[u16NumCntr] = (uint8_t)(u8CurNum + (uint8_t)'0');
        u16NumCntr++;
        u32Tmp >>= 3U;
    } while (0U != u32Tmp);

    /* Format "variable string" based on format specifier */
    pu8ModifiedDestStr = ConvertBufWithWidthPrecision(au8Buffer, u16NumCntr, pu8DestStr, formatSpec);

    /* Return current position in destination string */
    return pu8ModifiedDestStr;
}

#if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
/*
* @brief     Octal to String
* @details   Converts value of the variable to octal format and than to the string
* @param[in] u32Value        value to convert to string
* @param[in] *pu8DestStr     result destination
* @param[in] formatSpec      format specifier precision
* @return                    pointer to the current position in buffer with replaced characters
*/
static uint8_t * StrReplaceOctal64(uint64_t u64Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec)
{
    uint8_t au8Buffer[22U];
    uint16_t u16NumCntr = 0U;
    uint8_t u8CurNum;
    uint64_t u64Tmp = u64Value;
    uint8_t *pu8ModifiedDestStr;

    do
    {
        u8CurNum = (uint8_t)((uint8_t)u64Tmp & 0x7U);
        au8Buffer[u16NumCntr] = (uint8_t)(u8CurNum + (uint8_t)'0');
        u16NumCntr++;
        u64Tmp >>= 3U;
    } while (0U != u64Tmp);

    /* Format "variable string" based on format specifier */
    pu8ModifiedDestStr = ConvertBufWithWidthPrecision(au8Buffer, u16NumCntr, pu8DestStr, formatSpec);

    /* Return current position in destination string */
    return pu8ModifiedDestStr;
}
#endif

/*
* @brief     Hexa to String
* @details   Converts value of the variable to hexa format and than to the string
* @param[in] u32Value        value to convert to string
* @param[in] *pu8DestStr     result destination
* @param[in] *pu8Hexa        array with hexa characters
* @param[in] formatSpec      format specifier precision
* @return                    pointer to the current position in buffer with replaced characters
*/
static uint8_t * StrReplaceHexa32(uint32_t u32Value, uint8_t *pu8DestStr, const uint8_t pu8Hexa[], FormatSpecifierType formatSpec)
{
    uint8_t au8Buffer[8U];
    uint16_t u16NumCntr = 0U;
    uint8_t u8CurNum;
    uint32_t u32Tmp = u32Value;
    uint8_t *pu8ModifiedDestStr;

    do
    {
        u8CurNum = pu8Hexa[u32Tmp & 0xFU];
        au8Buffer[u16NumCntr] = u8CurNum;
        u16NumCntr++;
        u32Tmp >>= 4U;
    } while (0U != u32Tmp);

    /* Format "variable string" based on format specifier */
    pu8ModifiedDestStr = ConvertBufWithWidthPrecision(au8Buffer, u16NumCntr, pu8DestStr, formatSpec);

    /* Return current position in destination string */
    return pu8ModifiedDestStr;
}

#if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
/*
* @brief     Hexa to String
* @details   Converts value of the variable to hexa format and than to the string
* @param[in] u32Value        value to convert to string
* @param[in] *pu8DestStr     result destination
* @param[in] *pu8Hexa        array with hexa characters
* @param[in] formatSpec      format specifier precision
* @return                    pointer to the current position in buffer with replaced characters
*/
static uint8_t * StrReplaceHexa64(uint64_t u64Value, uint8_t *pu8DestStr, const uint8_t pu8Hexa[], FormatSpecifierType formatSpec)
{
    uint8_t au8Buffer[16U];
    uint16_t u16NumCntr = 0U;
    uint8_t u8CurNum;
    uint64_t u64Tmp = u64Value;
    uint8_t *pu8ModifiedDestStr;

    do
    {
        u8CurNum = pu8Hexa[u64Tmp & 0xFU];
        au8Buffer[u16NumCntr] = u8CurNum;
        u16NumCntr++;
        u64Tmp >>= 4U;
    } while (0U != u64Tmp);

    /* Format "variable string" based on format specifier */
    pu8ModifiedDestStr = ConvertBufWithWidthPrecision(au8Buffer, u16NumCntr, pu8DestStr, formatSpec);

    /* Return current position in destination string */
    return pu8ModifiedDestStr;
}
#endif
/*
* @brief     Char to String
* @details   Converts the char variable to the string
* @param[in] u32Value        value to convert to string
* @param[in] *pu8DestStr     result destination
* @param[in] formatSpec      format specifier precision
* @return                    pointer to the current position in buffer with replaced characters
*/
static uint8_t * StrReplaceChar(uint8_t u8Value, uint8_t *pu8DestStr, FormatSpecifierType formatSpec)
{
    uint8_t au8Buffer[1U];
    uint8_t *pu8ModifiedDestStr;

    au8Buffer[0] = u8Value;

    /* Format "variable string" based on format specifier */
    pu8ModifiedDestStr = ConvertBufWithWidthPrecision(au8Buffer, 1U, pu8DestStr, formatSpec);

    /* Format "variable string" based on format specifier */
    return pu8ModifiedDestStr;
}


/*
* @brief     String to String
* @details   Converts the string variable to the string
* @param[in] pcou8Value      value to convert to string
* @param[in] *pu8DestStr     result destination
* @param[in] u32DestFree     available space in destination buffer
* @param[in] formatSpec      format specifier precision
* @return                    pointer to the current position in buffer with replaced characters
*/
static uint8_t * StrReplaceString(const uint8_t pcou8Value[], uint8_t *pu8DestStr, uint32_t u32DestFree, FormatSpecifierType formatSpec)
{
    uint8_t *pu8ModifiedDestStr;
    const char_t *src = "(NULL)";

    if (NULL == pcou8Value)
    {
        pu8ModifiedDestStr = ConvertBufWithWidthPrecision((uint8_t*)src, (uint16_t)u32DestFree, pu8DestStr, formatSpec);
    }
    else
    {
        /* Format "variable string" based on format specifier */
        pu8ModifiedDestStr = ConvertBufWithWidthPrecision(pcou8Value, (uint16_t)u32DestFree, pu8DestStr, formatSpec);
    }

    /* Return current position in destination string */
    return pu8ModifiedDestStr;
}


/*
* @brief     Format the output according to the informations extracted from format specifier.
* @details   Function converts string passed through *pcou8Buf parameter to the format defined by formatSpec
*            structure and save the result to the *pu8DestStr.
* @param[in]  *pcou8Buf       string which should be formatted
* @param[in]  u16BufLen       string buffer length
* @param[out] *pu8DestStr     destination of the formatted string
* @param[in]  formatSpec      structure with desired format informations
* @return                     pointer to the current position in buffer with replaced characters
*/
static uint8_t * ConvertBufWithWidthPrecision(const uint8_t pcou8Buf[], uint16_t u16BufLen, uint8_t pu8DestStr[], FormatSpecifierType formatSpec)
{
    int16_t s16X;
    int32_t s32X;
    uint16_t u16Index = 0U;

    /* Signed, unsigned, octal, hexa numbers */
    if (((uint8_t)'d' == formatSpec.u8Specifier) || ((uint8_t)'i' == formatSpec.u8Specifier) ||
        ((uint8_t)'u' == formatSpec.u8Specifier) || ((uint8_t)'o' == formatSpec.u8Specifier) ||
        ((uint8_t)'x' == formatSpec.u8Specifier) || ((uint8_t)'X' == formatSpec.u8Specifier) )
    {
        int32_t s32Spaces = 0;
        int32_t s32Zeros = 0;
        uint16_t u16NumLenWithoutSign = u16BufLen;

        if( ((uint8_t)'-' == pcou8Buf[u16BufLen-1U]) ||
            (((uint8_t)'+' == pcou8Buf[u16BufLen-1U]) || ((uint8_t)' ' == pcou8Buf[u16BufLen-1U]))
          )
        {
            u16NumLenWithoutSign = (uint16_t)(u16BufLen-1U);
        }

        /* Test if the width was set (macros WIDTH_NONE and WIDTH_STAR)*/
        if (formatSpec.s16Width > 0)
        {
            /* Check whether zero shall be used for padding */
            if(FLAG_ZERO == (formatSpec.u8Flags & FLAG_ZERO))
            {
                s32Zeros = (int32_t)formatSpec.s16Width - (int32_t)u16BufLen;
            }
            else
            {
                s32Spaces = (int32_t)formatSpec.s16Width - (int32_t)u16BufLen;
            }
        }

        /* Test if the precision was set (macros PRECISION_NONE and PRECISION_STAR)*/
        if (formatSpec.s16Precision > 0)
        {
            if(((int32_t)formatSpec.s16Precision - (int32_t)u16NumLenWithoutSign) > s32Zeros)
            {
                s32Zeros = (int32_t)formatSpec.s16Precision - (int32_t)u16NumLenWithoutSign;
            }
        }

        /* Number of spaces is reduced by zeros */
        if (s32Zeros > 0)
        {
            s32Spaces -= s32Zeros;
        }

        /* Print spaces (nothing will be printed for negative number of spaces) */
        for (s32X = 0; s32X < s32Spaces; s32X++)
        {
            pu8DestStr[u16Index] = (uint8_t)' ';
            u16Index++;
        }

        /* Print minus sign if necessary */
        if ((uint8_t)'-' == pcou8Buf[u16BufLen-1U])
        {
            pu8DestStr[u16Index] = (uint8_t)'-';
            u16Index++;
        }

        /* Print zeros (nothing will be printed for negative number of zeros) */
        for (s32X = 0; s32X < s32Zeros; s32X++)
        {
            pu8DestStr[u16Index] = (uint8_t)'0';
            u16Index++;
        }

        /* Print the number */
        for (s16X = (int16_t)(((int16_t)u16NumLenWithoutSign-1)); s16X >= 0; s16X--)
        {
            pu8DestStr[u16Index] = pcou8Buf[s16X];
            u16Index++;
        }
    }
    /* String */
    else if ((uint8_t)'s' == formatSpec.u8Specifier)
    {
        uint16_t u16Limit = 0U;     /* Number of string characters which should be printed */
        int32_t s32Spaces = 0;     /* Number of spaces which should be printed */

        /* Test if the precision was set (macros PRECISION_NONE and PRECISION_STAR)*/
        if (formatSpec.s16Precision >= 0)
        {
            u16Limit = (uint16_t)Minimum((uint32_t)(int32_t)formatSpec.s16Precision, (uint32_t)u16BufLen);
        }
        else
        {
            u16Limit = u16BufLen;
        }

        /* Test if the width was set (macros WIDTH_NONE and WIDTH_STAR)*/
        if (formatSpec.s16Width >= 0)
        {
            s32Spaces = (int32_t)formatSpec.s16Width - (int32_t)u16Limit;
        }
        else
        {
            s32Spaces = 0;
        }

        /* Print spaces (nothing will be printed for negative number of spaces) */
        for (s32X = 0; s32X < s32Spaces; s32X++)
        {
            pu8DestStr[u16Index] = (uint8_t)' ';
            u16Index++;
        }

        /* Print string (or its part)*/
        for (s32X = 0; s32X < (int32_t)u16Limit; s32X++)
        {
            if (0U == pcou8Buf[s32X])
            {   /* End of input string */
                break;
            }
            pu8DestStr[u16Index] = pcou8Buf[s32X];
            u16Index++;
        }
    }
    /* Char */
    else if ((uint8_t)'c' == formatSpec.u8Specifier)
    {
        if (formatSpec.s16Width > (int16_t)u16BufLen)
        {
            for (s16X = (int16_t)((formatSpec.s16Width - (int16_t)u16BufLen)); s16X > 0; s16X--)
            {
                pu8DestStr[u16Index] = (uint8_t)' ';
                u16Index++;
            }
        }

        for(s16X = (int16_t)(((int16_t)u16BufLen - 1)); s16X >= 0; s16X--)
        {
            pu8DestStr[u16Index] = pcou8Buf[s16X];
            u16Index++;
        }
    }
    /* Pointer */
    else if ((uint8_t)'p' == formatSpec.u8Specifier)
    {
        int32_t s32Spaces = 0;
        int32_t s32Zeros = 0;

        /* Test if the width was set (macros WIDTH_NONE and WIDTH_STAR)*/
        if (formatSpec.s16Width > 0)
        {
            s32Spaces = (int32_t)formatSpec.s16Width - ((int32_t)u16BufLen + 2);
        }

        /* Test if the precision was set (macros PRECISION_NONE and PRECISION_STAR)*/
        if (formatSpec.s16Precision > 0)
        {
            s32Zeros = (int32_t)formatSpec.s16Precision - ((int32_t)u16BufLen + 2);
        }

        /* Number of spaces is reduced by zeros */
        if ((s32Spaces > 0) && (s32Zeros > 0))
        {
            s32Spaces -= s32Zeros;
        }

        /* Print spaces (nothing will be printed for negative number of spaces) */
        for (s32X = 0; s32X < s32Spaces; s32X++)
        {
            pu8DestStr[u16Index] = (uint8_t)' ';
            u16Index++;
        }

        /* Print 0x before pointer value */
        pu8DestStr[u16Index] = (uint8_t)'0';
        u16Index++;
        pu8DestStr[u16Index] = (uint8_t)'x';
        u16Index++;

        /* Print zeros (nothing will be printed for negative number of zeros) */
        for (s32X = 0; s32X < s32Zeros; s32X++)
        {
            pu8DestStr[u16Index] = (uint8_t)'0';
            u16Index++;
        }

        /* Print the number */
        for (s16X = (int16_t)(((int16_t)u16BufLen-1)); s16X >= 0; s16X--)
        {
            pu8DestStr[u16Index] = pcou8Buf[s16X];
            u16Index++;
        }
    }
    else
    {
        /* Nothing to be done */
    }

    /* Return current position in destination string */
    return &pu8DestStr[u16Index];
}


/*
* @brief      Parse format specifiers found in the input string.
* @details    Function is called whenever the fsl_printf function find % character in the input string.
*             The parsing of the format specifier is performed and extracted informations are stored to the formatSpec
*             structure.
* @param[in]  *pcou8FormatStr   String with the format specifier
* @param[out] *formatSpec       Pointer to the structure where data extracted from the format specifier are saved
* @return                       pointer to the current position in input string
*/
static const uint8_t * ParseFormatSpecifier(const uint8_t pcou8FormatStr[], FormatSpecifierType *formatSpec)
{
    uint8_t u8TypeWidth = 0U;
    uint16_t u16ResultWidth = 0U;
    uint16_t u16ResultPrecision = 0U;
    uint16_t u16Index = 0U;
    /* Format specifier structure initialization */
    formatSpec->u8Flags = FLAG_NONE;
    formatSpec->s16Width = WIDTH_NONE;
    formatSpec->s16Precision = PRECISION_NONE;
    formatSpec->u8Length = LENGTH_NONE;
    formatSpec->u8Specifier = SPECIFIER_NONE;
    formatSpec->u8Type = TYPE_NONE;

    /* Move to the symbol behind % */
    u16Index++;

    /* Parse flags */
    while(TRUE)
    {
        if (pcou8FormatStr[u16Index] == (uint8_t)'-')
        {
            formatSpec->u8Flags |= FLAG_MINUS;
            u16Index++;
        }
        else if (pcou8FormatStr[u16Index] == (uint8_t)'+')
        {
            formatSpec->u8Flags |= FLAG_PLUS;
            u16Index++;
        }
        else if (pcou8FormatStr[u16Index] == (uint8_t)' ')
        {
            formatSpec->u8Flags |= FLAG_SPACE;
            u16Index++;
        }
        else if (pcou8FormatStr[u16Index] == (uint8_t)'#')
        {
            formatSpec->u8Flags |= FLAG_HASH;
            u16Index++;
        }
        else if (pcou8FormatStr[u16Index] == (uint8_t)'0')
        {
            formatSpec->u8Flags |= FLAG_ZERO;
            u16Index++;
        }
        else
        {
            break;
        }
    }

    /* Parse width */
    if (pcou8FormatStr[u16Index] == (uint8_t)'*')
    {
        formatSpec->s16Width = WIDTH_STAR;
        u16Index++;
    }
    else if ((pcou8FormatStr[u16Index] >= (uint8_t)'0') && (pcou8FormatStr[u16Index] <= (uint8_t)'9'))
    {
        /* Convert string to uint16_t */
        while ((pcou8FormatStr[u16Index] >= (uint8_t)'0') && (pcou8FormatStr[u16Index] <= (uint8_t)'9'))
        {
            u16ResultWidth = (uint16_t)(u16ResultWidth * 10U);
            u16ResultWidth = (uint16_t)(u16ResultWidth + ((uint16_t)(pcou8FormatStr[u16Index]) - (uint8_t)'0'));
            u16Index++;
        }

        /* Store result to the struct */
        formatSpec->s16Width = (int16_t)u16ResultWidth;
    }
    else
    {
        /* Nothing to be done */
    }

    /* Parse precision */
    if (pcou8FormatStr[u16Index] == (uint8_t)'.')
    {
        u16Index++;

        if (pcou8FormatStr[u16Index] == (uint8_t)'*')
        {
            formatSpec->s16Precision = PRECISION_STAR;
        }
        else
        {
            /* Convert string to uint16_t */
            while ((pcou8FormatStr[u16Index] >= (uint8_t)'0') && (pcou8FormatStr[u16Index] <= (uint8_t)'9'))
            {
                u16ResultPrecision = (uint16_t)(u16ResultPrecision * 10U);
                u16ResultPrecision = (uint16_t)(u16ResultPrecision + ((uint16_t)(pcou8FormatStr[u16Index]) - (uint8_t)'0'));
                u16Index++;
            }

            formatSpec->s16Precision = (int16_t)u16ResultPrecision;
        }
    }

    /* Parse length */
    if ((uint8_t)'h' == pcou8FormatStr[u16Index])
    {
        formatSpec->u8Length = LENGTH_H;
        u16Index++;
        u8TypeWidth = (uint8_t)sizeof(short);


        if ((uint8_t)'h' == pcou8FormatStr[u16Index])
        {
            formatSpec->u8Length = LENGTH_HH;
            u16Index++;
            u8TypeWidth = (uint8_t)sizeof(char_t);
        }
    }
    else if ((uint8_t)'l' == pcou8FormatStr[u16Index] )
    {
        formatSpec->u8Length = LENGTH_LITTLE_L;
        u16Index++;
        u8TypeWidth = (uint8_t)sizeof(long int); /* Either 4 or 8 */

        if ((uint8_t)'l' == pcou8FormatStr[u16Index])
        {
            /* The long long (64bit) values are sometimes not supported */
            formatSpec->u8Length = LENGTH_LITTLE_LL;
            u16Index++;
            u8TypeWidth = (uint8_t)sizeof(long long int);
            #if FALSE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                formatSpec->u8Flags |= FLAG_UNSUPPORTED;
            #endif
        }
    }
    else if ((uint8_t)'j' == pcou8FormatStr[u16Index])
    {
        /* The intmax_t or uintmax_t values are not supported */
        formatSpec->u8Length = LENGTH_J;
        u16Index++;
        u8TypeWidth = 0U;
        formatSpec->u8Flags |= FLAG_UNSUPPORTED;

    }
    else if ((uint8_t)'z' == pcou8FormatStr[u16Index])
    {
        /* The size_t values are not supported */
        formatSpec->u8Length = LENGTH_Z;
        u16Index++;
        u8TypeWidth = 0U;
        formatSpec->u8Flags |= FLAG_UNSUPPORTED;
    }
    else if ((uint8_t)'t' == pcou8FormatStr[u16Index])
    {
        /* The ptrdiff_t values are not supported */
        formatSpec->u8Length = LENGTH_T;
        u16Index++;
        u8TypeWidth = 0U;
        formatSpec->u8Flags |= FLAG_UNSUPPORTED;
    }
    else if ((uint8_t)'L' == pcou8FormatStr[u16Index])
    {
        /* The long double (typ. 64 or 80 bits) 80 bits values are not supported */
        formatSpec->u8Length = LENGTH_LARGE_L;
        u16Index++;
        u8TypeWidth = (uint8_t)sizeof(long double);
        formatSpec->u8Flags |= FLAG_UNSUPPORTED;
    }
    else
    {
        /* Default length */
    }

    formatSpec->u8Specifier = pcou8FormatStr[u16Index];
    /* Parse specifier */
    switch(pcou8FormatStr[u16Index])
    {
        case (uint8_t)'d':
        case (uint8_t)'i':
            if(0U == u8TypeWidth) /* The default -> Integer */
            {
                u8TypeWidth = (uint8_t)sizeof(int);
            }

            if (1U == u8TypeWidth)
            {
                formatSpec->u8Type = TYPE_INT8;
            }
            else if (2U == u8TypeWidth)
            {
                formatSpec->u8Type = TYPE_INT16;
            }
            else if (4U == u8TypeWidth)
            {
                formatSpec->u8Type = TYPE_INT32;
            }
            else  /* 8U == u8TypeWidth */
            {
                formatSpec->u8Type = TYPE_INT64;
            }
            break;
        case (uint8_t)'u':
        case (uint8_t)'o':
        case (uint8_t)'x':
        case (uint8_t)'X':
            if(0U == u8TypeWidth) /* The default -> Integer */
            {
                u8TypeWidth = (uint8_t)sizeof(int);
            }

            if (1U == u8TypeWidth)
            {
                formatSpec->u8Type = TYPE_UINT8;
            }
            else if (2U == u8TypeWidth)
            {
                formatSpec->u8Type = TYPE_UINT16;
            }
            else if (4U == u8TypeWidth)
            {
                formatSpec->u8Type = TYPE_UINT32;
            }
            else  /* 8U == u8TypeWidth */
            {
                formatSpec->u8Type = TYPE_UINT64;
            }
            break;
        case (uint8_t)'a':
        case (uint8_t)'A':
        case (uint8_t)'f':
        case (uint8_t)'F':
        case (uint8_t)'e':
        case (uint8_t)'E':
        case (uint8_t)'g':
        case (uint8_t)'G':
            #if FALSE == NXP_SNPRINTF_CFG_FLOAT_SUPPORT
                /* Floating point numbers not supported */
                formatSpec->u8Flags |= FLAG_UNSUPPORTED;
            #else
                /* Hexadecimal floating point output is not supported for now */
                if(((uint8_t)'a' == pcou8FormatStr[u16Index]) || ((uint8_t)'A' == pcou8FormatStr[u16Index]))
                {
                    formatSpec->u8Flags |= FLAG_UNSUPPORTED;
                }
            #endif
            if (0U == u8TypeWidth)
            {   /* Check for default length (0U) */
                formatSpec->u8Type = TYPE_DOUBLE;
            }
            else
            {
                formatSpec->u8Type = TYPE_LONG_DOUBLE;
            }
            break;
        case (uint8_t)'c':
            formatSpec->u8Type = TYPE_INT8;
            break;
        case (uint8_t)'s':
            formatSpec->u8Type = TYPE_STRING;
            break;
        case (uint8_t)'p':
            formatSpec->u8Type = TYPE_POINTER;
            break;
        case (uint8_t)'n':
            formatSpec->u8Type = 0U;
            break;
        case (uint8_t)'%':
            formatSpec->u8Type = TYPE_NONE;
            break;
        default:
            formatSpec->u8Specifier = SPECIFIER_NONE;
            break;
    }

    /* Return pointer to the current position in input string */
    return &pcou8FormatStr[u16Index];
}

/*
* @brief      Copies uint8_t from buffer to another.
* @details    Both buffers are specified by beginning and end addresses.
* @param[in]  *pcou8Src         Pionter to source buffer
* @param[in]  *copcou8InMax     Pointer to byte that follows source data (stops before copying this byte)
* @param[out] *pu8Out           Pointer to destination buffer
* @param[in]  *copcou8OutMax    Pointer to byte that follows last writable byte in destination buffer (cannot write here)
* @return                       Pointer to byte which follows last written byte in output buffer.
*/
static inline uint8_t *PutCA(const uint8_t *pcou8Src, uint8_t const * const copcou8InMax,
                                   uint8_t *pu8Out,   uint8_t const * const copcou8OutMax)
{
    uint8_t *pu8Out_temp = pu8Out;
    const uint8_t *pcou8Src_temp = pcou8Src;

    while ((pu8Out_temp < copcou8OutMax) && (pcou8Src_temp < copcou8InMax))
    {
        *pu8Out_temp = *pcou8Src_temp;
        pcou8Src_temp++;
        pu8Out_temp++;
    }
    return pu8Out_temp;
}

/*  which is specified by beginning and end address */
/*
* @brief      Copies zero terminated string to uint8_t buffer.
* @details    Destination buffer is specified by beginning and end addresses.
* @param[in]  *coszSrc          Pionter to source string, zero terminated
* @param[out] *pu8Out           Pointer to destination buffer
* @param[in]  *copcou8OutMax    Pointer to byte that follows last writable byte in destination buffer (cannot write here)
* @return                       Pointer to byte which follows last written byte in output buffer.
*/
static inline uint8_t *PutS(const char_t *coszSrc, uint8_t *pu8Out, uint8_t const * const copcou8OutMax)
{
    uint8_t *pu8Out_temp = pu8Out;
    const char_t *coszSrc_temp = coszSrc;

    while ((pu8Out_temp < copcou8OutMax) && (0U != (uint8_t)(*coszSrc_temp)))
    {
        *pu8Out_temp = (uint8_t)(*coszSrc_temp);
        pu8Out_temp++;
        coszSrc_temp++;
    }
    return pu8Out_temp;
}

/**
* @brief     Print data to the interface selected in configuration.
* @details   Function is used to print data through another module, which is joined in configuration.
*            It serves for printing debug messages.
* @param[in] *pcocStr String which should be printed. It can contain format specifiers which will be substituted by
*                      the values of the variables that are passed to the function through variable count of parameters.
*                      Format is same as in standard function printf. Conversion specifiers are either:
*                      - supported: diuoxXcsp%
*                      - with configurable support: fFeEgG (They are ignored if the support is disabled)
*                      - always ignored: aA
*                      - not recognized: all others (not recognized conversion specifiers will cause the conversion to abort)
*                      - Support of "long long" is configurable - it is ignored if it is disabled.
*                      - Long float is ignored.
*/

int snprintf(char_t *str, size_t size, const char_t *pcocStr, ...)
{
    int retval;
    va_list VarArg;

    va_start(VarArg, pcocStr);
    retval = vsnprintf(str, size, pcocStr, VarArg);
    va_end(VarArg);
    return retval;
}

int vsnprintf(char_t *str, size_t size, const char_t *pcocStr, va_list VarArg)
{
    const uint8_t *pcou8StrActChar = (const uint8_t*)pcocStr;  /* Pointer to actual input character */
    uint8_t au8TmpConvBuf[CONV_BUF_SIZE]; /*  Temporary buffer for conversion output (except string conversions) */
    const uint8_t *pu8TmpConvEnd; /* Points behind converted value (in au8TmpConvBuf) */
    uint8_t *pu8StrRplc = (uint8_t *)str; /* Pointer to buffer with replaced characters */
    uint8_t const * const copcou8OutMax = pu8StrRplc + size - 1U; /* Max possible address of str's terminating '\0' */
#if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
    bool_t bLong = FALSE;             /* Indicates that long variant of the type is used */

    uint64_t u64NextArg = 0U;         /* Variable to store function parameter */
#endif

    bool_t bAbort = FALSE;
    uint32_t u32NextArg = 0U;         /* Variable to store function parameter */
#if TRUE == NXP_SNPRINTF_CFG_FLOAT_SUPPORT
    float64_t dNextArg;               /* Variable to store function parameter */
#endif
    void *pvNextArg = (void*)0U;      /* Variable to store function parameter */
    FormatSpecifierType formatSpec;   /* Keeps information about print format */

    /* Extract number of special characters from string */
    while(0U != *pcou8StrActChar)
    {
        /* Format specifier character found */
        if ((uint8_t)'%' == *pcou8StrActChar)
        {
        #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
            bLong = FALSE;
        #endif
            /* Parse format specifier at current position */
            pcou8StrActChar = ParseFormatSpecifier(pcou8StrActChar, &formatSpec);

            /* We must read the argument in each case */
            switch(formatSpec.u8Type)
            {   /*  Two assumptions were made here:                                                            */
                /*  1. Integer is 32bit wide                                                                   */
                /*  2. Integer promotion works as defined in C99 and in MISRA (same definition).               */
                /*  Both must be verified in tests for each platform, compiler, and compiler options set used. */
                case TYPE_INT8:           /* Promoted to int */
                case TYPE_UINT8:          /* Promoted to int */
                case TYPE_INT16:          /* Promoted to int */
                case TYPE_UINT16:         /* Promoted to int */
                case TYPE_INT32:          /* int */
                case TYPE_UINT32:         /* int */
                    u32NextArg = (uint32_t)va_arg(VarArg, unsigned int);
                    break;
                case TYPE_STRING:         /* Pointer in fact */
                case TYPE_POINTER:        /* Pointer (32 or 64 bit) */
                    pvNextArg = (void *)va_arg(VarArg, void *);
                    break;
                case TYPE_INT64:          /* long long */
                case TYPE_UINT64:         /* long long */
                #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    /* We must read it out even if this type is not supported */
                    u64NextArg = (uint64_t)va_arg(VarArg, unsigned long long);
                    bLong = TRUE;
                #else
                    (void)va_arg(VarArg, unsigned long long);
                #endif

                    break;
#if TRUE == NXP_SNPRINTF_CFG_FLOAT_SUPPORT
                case TYPE_DOUBLE:
                    dNextArg = (float64_t)va_arg(VarArg, double);
                    break;
                case TYPE_LONG_DOUBLE:
                    /* We must read it out even if this type is not supported */
                    (void)va_arg(VarArg, long double);
                    break;
#endif
                case TYPE_NONE:
                    /* Nothing to read from va_arg */
                    break;
                default:
                    /* Type was not recognized. If this happens then undefined behaviour may occur. */
                    /* Inform user about the problem: */
                    pu8StrRplc = PutS("(err)\n", pu8StrRplc, copcou8OutMax);
                    /* Parsing should stop to avoid undefined behaviour */
                    bAbort = TRUE;
                    break;

            }
            if(TRUE == bAbort)
            {   /* Abort processing of the input, exit this loop */
                break;
            }

            if(FLAG_UNSUPPORTED == (formatSpec.u8Flags & FLAG_UNSUPPORTED))
            {
                /* Output ?? when the type is unsupported */
                pu8StrRplc = PutS("??", pu8StrRplc, copcou8OutMax);
                /* Move to next character */
                pcou8StrActChar++;
                continue;
            }

            /* Check character behind % */
            switch((char_t)formatSpec.u8Specifier)
            {
                case 'i':
                case 'd':
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    if(FALSE == bLong)
                    {
                    #endif
                        pu8TmpConvEnd = StrReplaceSint32((int32_t)u32NextArg, au8TmpConvBuf, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    }
                    else
                    {
                        pu8TmpConvEnd = StrReplaceSint64((int64_t)u64NextArg, au8TmpConvBuf, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    }
                    #endif
                    break;
                case 'u':
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    if(FALSE == bLong)
                    {
                    #endif
                        pu8TmpConvEnd = StrReplaceUint32(u32NextArg, au8TmpConvBuf, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    }
                    else
                    {
                        pu8TmpConvEnd = StrReplaceUint64(u64NextArg, au8TmpConvBuf, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    }
                    #endif
                    break;
                case 'o':
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    if(FALSE == bLong)
                    {
                    #endif
                        pu8TmpConvEnd = StrReplaceOctal32(u32NextArg, au8TmpConvBuf, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    }
                    else
                    {
                        pu8TmpConvEnd = StrReplaceOctal64(u64NextArg, au8TmpConvBuf, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    }
                    #endif
                    break;
                case 'x':
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    if(FALSE == bLong)
                    {
                    #endif
                        pu8TmpConvEnd = StrReplaceHexa32(u32NextArg, au8TmpConvBuf, au8HexaLower, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    }
                    else
                    {
                        pu8TmpConvEnd = StrReplaceHexa64(u64NextArg, au8TmpConvBuf, au8HexaLower, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    }
                    #endif
                    break;
                case 'X':
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    if(FALSE == bLong)
                    {
                    #endif
                        pu8TmpConvEnd = StrReplaceHexa32(u32NextArg, au8TmpConvBuf, au8HexaUpper, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    }
                    else
                    {
                        pu8TmpConvEnd = StrReplaceHexa64(u64NextArg, au8TmpConvBuf, au8HexaUpper, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    }
                    #endif
                    break;
                case 'c':
                    pu8TmpConvEnd = StrReplaceChar((uint8_t)u32NextArg, au8TmpConvBuf, formatSpec);
                    pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    break;
                case 's':
                    /* Put the string directly to output buffer */
                    pu8StrRplc = StrReplaceString((uint8_t*)pvNextArg, pu8StrRplc, (uint32_t)copcou8OutMax-(uint32_t)pu8StrRplc, formatSpec);
                    break;
                case 'p':
                    if(4U == sizeof(void*))
                    {
                        pu8TmpConvEnd = StrReplaceHexa32((uint32_t)(uaddr_t)pvNextArg, au8TmpConvBuf, au8HexaUpper, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    }
                    #if TRUE == NXP_SNPRINTF_CFG_LLINT_SUPPORT
                    else
                    {
                        pu8TmpConvEnd = StrReplaceHexa64((uint64_t)(uaddr_t)pvNextArg, au8TmpConvBuf, au8HexaUpper, formatSpec);
                        pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                    }
                    #endif

                    break;
#if TRUE == NXP_SNPRINTF_CFG_FLOAT_SUPPORT
                case 'F': /* Letter case selection is not supported - so the next case is the same */
                case 'f': /* Floats promoted to double thus use the next case */
                case 'G': /* Letter case selection is not supported - so the next case is the same */
                case 'g': /* Appropriate format to be selected internally - done: the next one  */
                case 'E': /* Letter case selection is not supported - so the next case is the same */
                case 'e':
                    {   /* Block started to declare additional variables for this special case */
                        tunDoubleToBits unDouble; /* Union is needed to access bits (cast makes conversion instead) */
                        uint64_t u64Exponent;
                        uint16_t u16Exponent;

                        unDouble.dValue = dNextArg;
                        /* Check for special values encoded in exponent */
                        /* Valid for double defined in IEEE 754 */
                        u64Exponent = unDouble.u64Bits >> 52U;
                        u16Exponent = (uint16_t)u64Exponent;
                        u16Exponent &= 0x7FFU;
                        if(0x7FFU == u16Exponent)
                        {   /* Either inf or NaN */
                            if(0U == (unDouble.u64Bits & 0xFFFFFFFFFFFFFULL)) /* if mantis == zero */
                            {   /* Infinity */
                                if(0U != (unDouble.u64Bits & 0x8000000000000000ULL)) /* if sign bit is set */
                                {   /* Write minus */
                                    PUTC('-');
                                }
                                pu8StrRplc = PutS("INF", pu8StrRplc, copcou8OutMax);
                            }
                            else
                            {   /* NaN */
                                pu8StrRplc = PutS("NaN", pu8StrRplc, copcou8OutMax);
                            }
                        }
                        else
                        {   /* Normal number or signed zero or subnormal number */
                            char_t cSign;
                            uint8_t  u8Bdp;
                            uint32_t u32Adp;
                            int16_t s16Exp;
                            FormatSpecifierType rFS;

                            ConvertDoubleToScientific(dNextArg, &cSign, &s16Exp, &u8Bdp, &u32Adp);

                            /* Currently no support for any user selectable formatting for floating point */
                            /* Add sign */
                            PUTC(cSign);
                            /* Add part before decimal point */
                            rFS.u8Flags = FLAG_NONE;
                            rFS.s16Width = 1;
                            rFS.s16Precision = PRECISION_NONE;
                            rFS.u8Length = LENGTH_NONE;
                            rFS.u8Specifier = (uint8_t)'u';
                            rFS.u8Type = TYPE_UINT8;
                            pu8TmpConvEnd = StrReplaceUint32((uint32_t)u8Bdp, au8TmpConvBuf, rFS);
                            pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                            /* Add dot */
                            PUTC('.');
                            /* Add part after decimal point */
                            rFS.s16Width = 9; /* 9 digits */
                            rFS.s16Precision = 9;
                            rFS.u8Flags = FLAG_ZERO; /* Include leading zeros */
                            rFS.u8Type = TYPE_UINT32;
                            pu8TmpConvEnd = StrReplaceUint32(u32Adp, au8TmpConvBuf, rFS);
                            pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                            /* Add 'e' character */
                            PUTC('e');
                            /* Add the exponent */
                            rFS.s16Width = 3; /* 3 digits */
                            rFS.s16Precision = 3;
                            rFS.u8Specifier = (uint8_t)'i';
                            rFS.u8Flags = FLAG_ZERO | FLAG_PLUS; /* Include leading zeros, always output + or - */
                            rFS.u8Type = TYPE_INT16;
                            pu8TmpConvEnd = StrReplaceSint32((int32_t)s16Exp, au8TmpConvBuf, rFS);
                            pu8StrRplc = PutCA(au8TmpConvBuf, pu8TmpConvEnd, pu8StrRplc, copcou8OutMax);
                            /* We are finished */
                        }
                    }
                    break;
#endif
                case '%':
                    PUTC(*pcou8StrActChar);
                    break;
                default:
                        /* Nothing to be done. */
                    break;
            }
        }
        /* Normal character */
        else
        {
            PUTC(*pcou8StrActChar);
        }

        /* Move to next character */
        pcou8StrActChar++;
    }

    /* End the string and return length without terminating '\0' */
    *pu8StrRplc = (uint8_t)'\0';
    return pu8StrRplc - (uint8_t *)str;
}

#ifdef PFE_CFG_TARGET_OS_AUTOSAR
#define ETH_43_PFE_STOP_SEC_CODE
#include "Eth_43_PFE_MemMap.h"
#endif /* PFE_CFG_TARGET_OS_AUTOSAR */

#endif /* defined(NXP_LOG_ENABLED) */

#ifdef __cplusplus
}
#endif

