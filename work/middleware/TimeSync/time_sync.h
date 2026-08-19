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
*  File name:           $Source: TimeSync.h $
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

#ifndef TIME_SYNC_H
#define TIME_SYNC_H

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "Platform.h"
#include "calendar.h"


/***********************************************************************************************************************
*  local variable definitions (module local variables)
***********************************************************************************************************************/



/***********************************************************************************************************************
*  global function definitions
***********************************************************************************************************************/
typedef struct __attribute__((packed))
{
    uint64 Seconds;      /* Seconds since 1970/1/1 00:00:00 */
    uint32 Nanoseconds; /* Nanoseconds part */
    uint8 isGlobalTimeValid;  /* Indicates if the global time is valid 0x01: valid, 0x02/0x98/0x99: invalid */
    uint8 LocalZone; /* Local time zone offset from UTC in hours */
    uint8 LocalZoneDecimals; /* Local time zone offset decimals, 0:00, 0:30, 0:45 */
    uint8 LocalZoneSymbol; /* Local time zone symbol, 0: '+' or 1: '-' */
    uint8 isDst; /* Indicates if daylight saving time is active, 0: inactive, 1: active */
} TimeSyncInfo_st;

/** Runtime state intended for TRACE32 observation during IPCF tests. */
typedef struct
{
    sint8 ClientInitResult;
    sint8 ServerInitResult;
    uint8 TimeValid;
    uint8 LastMethodId;
    uint8 LastSessionId;
    uint8 LastResult;
    uint16 LastRxLength;
    uint16 LastTxLength;
    uint32 TimeNoticeCount;
    uint32 TimestampRequestCount;
    uint32 AppointmentSetCount;
    uint32 AppointmentListCount;
} TimeSync_Debug_st;

extern TimeSyncInfo_st g_timeSyncInfo_Event;
extern DateTime_st dateTime;
extern volatile TimeSync_Debug_st g_timeSyncDebug;


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

#endif
