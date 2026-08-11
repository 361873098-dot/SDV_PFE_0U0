/********************************************************************************
* COPYRIGHT (C) Vitesco Technologies 2025
* ALL RIGHTS RESERVED.
*
* The reproduction, transmission or use of this document or its
* contents is not permitted without express written authority.
* Offenders will be liable for damages. All rights, including rights
* created by patent grant or registration of a utility model or design,
* are reserved.
*********************************************************************************
*
*  File name:           $Source: os_taskcount.c $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      OS_TASKCOUNT
*  Specification:
*  Date:                $Date: 2025/12/18  $
*
*  Description:     OS task count structure and macros
*
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/
/* - Defines - */
#define OS_TASKCOUNT_ACTIVE             (1)
#define OS_TASKCOUNT_INACTIVE           (0)

#define OS_TASKCOUNT                    (OS_TASKCOUNT_ACTIVE)


/* - Macro Definitions -*/
#if (OS_TASKCOUNT == OS_TASKCOUNT_ACTIVE)
#define OS_TASKCOUNT_INC_CTR(NAME)      (*(OsTaskCount.NAME))++
#define OS_TASKCOUNT_CUR_CTR(NAME)      (*(OsTaskCount.NAME))
#else
#define OS_TASKCOUNT_INC_CTR(NAME)
#define OS_TASKCOUNT_CUR_CTR(NAME)      (0)
#endif

#include "StandardTypes.h"

/* - Typedefs - */
typedef struct {

     /* Core 0 */
   uint32 *M7_Core0_1ms;
   uint32 *M7_Core0_5ms;
   uint32 *M7_Core0_10ms;
   uint32 *M7_Core0_100ms;
   uint32 *M7_Core0_1000ms;
} OsTaskCountType;

extern OsTaskCountType OsTaskCount;