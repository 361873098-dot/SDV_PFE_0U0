/*
 *  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
 *  Copyright 2017, 2019-2021 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *
 *  This file contains sample code only. It is not part of the production code deliverables.
 */

/*==================================================================================================
==================================================================================================*/

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#ifdef __MWERKS__    /*Metrowerk CodeWarrior */
    #include <stdint.h>

    /* Standard typedefs used by header files, based on ISO C standard */
    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;

#else
#ifdef __ghs__    /*GreenHills */
    #include <stdint.h>

    /* Standard typedefs used by header files, based on ISO C standard */
    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;
    
    typedef volatile int64_t vint64_t;
    typedef volatile uint64_t vuint64_t;
#else
    /* This is needed for compilers that don't have a stdint.h file */

    typedef volatile signed char vint8_t;
    typedef volatile unsigned char vuint8_t;

    typedef volatile signed short vint16_t;
    typedef volatile unsigned short vuint16_t;

    typedef volatile signed int vint32_t;
    typedef volatile unsigned int vuint32_t;
    
    typedef volatile long int vint64_t;
    typedef volatile long int vuint64_t;
    

#endif
#endif
#endif


