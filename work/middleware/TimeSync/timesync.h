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
*  File name:           $Source: timesync.h $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      TIMESYNC
*  Specification:
*  Date:                $Date: 2026/05/12  $
*
*  Description:     This Unit processes the TimeSync module
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/

#ifndef TIMESYNC_H
#define TIMESYNC_H

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "Platform.h"
#include "timesync_calendar.h"


/***********************************************************************************************************************
*  local variable definitions (module local variables)
***********************************************************************************************************************/



/***********************************************************************************************************************
*  global function definitions
***********************************************************************************************************************/
typedef struct __attribute__((packed))
{
    uint64 seconds;      /* Seconds since 1970/1/1 00:00:00 */
    uint32 nanoseconds;  /* Nanoseconds part */
    uint8 globalTimeValid;  /* 0x01: valid, 0x02/0x98/0x99: invalid */
    uint8 localZone;  /* Local time zone offset from UTC in hours */
    uint8 localZoneDecimals;  /* 0:00, 0:30, 0:45 */
    uint8 localZoneSign;  /* 0: '+' or 1: '-' */
    uint8 daylightSavingTime;  /* 0: inactive, 1: active */
} TimeSync_Info_t;

/** Runtime state intended for TRACE32 observation during IPCF tests. */
typedef struct
{
    sint8 clientInitResult;
    sint8 serverInitResult;
    uint8 timeValid;
    uint8 lastMethodId;
    uint8 lastSessionId;
    uint8 lastResult;
    uint16 lastRxLength;
    uint16 lastTxLength;
    uint32 timeNoticeCount;
    uint32 timestampRequestCount;
    uint32 appointmentSetCount;
    uint32 appointmentListCount;
} TimeSync_Debug_t;

extern TimeSync_Info_t g_TimeSyncInfo;
extern TimeSync_DateTime_t g_TimeSyncDateTime;
extern volatile TimeSync_Debug_t g_TimeSyncDebug;


/***********************************************************************************************************************
 *  Function name    : TimeSync_Init()
 *
 *  Description      : Initialize the TimeSync module.
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
extern void TimeSync_Init(void);

/***********************************************************************************************************************
 *  Function name    : TimeSync_Main()
 *
 *  Description      : Main function for the TimeSync module.
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
extern void TimeSync_Main(void);

#endif /* TIMESYNC_H */
