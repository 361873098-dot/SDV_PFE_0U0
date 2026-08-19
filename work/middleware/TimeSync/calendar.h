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
*  File name:           $Source: Calendar.h $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      CALENDAR
*  Specification:
*  Date:                $Date: 2026/05/12  $
*
*  Description:     This Unit processes the Calendar module
*
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/
#ifndef CALENDAR_H
#define CALENDAR_H

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "Platform.h"

/***********************************************************************************************************************
*  variable definitions 
***********************************************************************************************************************/
typedef struct
{
    uint16 Year;
    uint8 Month;
    uint8 Day;
    uint8 Hour;
    uint8 Minute;
    uint8 Second;
}DateTime_st;


typedef struct
{
    uint32 App_Id;
    uint8 ClockType;
    boolean IsValid;
    DateTime_st DateTime;
    uint32 RelativeSeconds;
}Appt_st;

/***********************************************************************************************************************
*  define macros
***********************************************************************************************************************/

#define TIMESYNC_SECONDS_PER_MINUTE     (60ULL)
#define TIMESYNC_SECONDS_PER_HOUR       (3600ULL)
#define TIMESYNC_SECONDS_PER_DAY        (86400ULL)
#define TIMESYNC_EPOCH_YEAR             (1970U)


/***********************************************************************************************************************
*  global function definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
 *  Function name    : TimeSync_ConvertSecondsToDateTime()
 *
 *  Description      : Convert a given number of seconds since the epoch to a date and time.
 *
 *  List of arguments: seconds - The number of seconds since the epoch.
 *                     dateTime - Pointer to a DateTime_st structure to store the result.

 *  Return value     : E_OK if the conversion was successful, E_NOT_OK otherwise.
 *
 ***********************************************************************************************************************/
extern Std_ReturnType TimeSync_ConvertSecondsToDateTime(const uint64 seconds, DateTime_st *dateTime);

/***********************************************************************************************************************
 *  Function name    : TimeSync_ConvertDateTimeToSeconds()
 *
 *  Description      : Convert a date and time to seconds since the epoch.
 *
 *  List of arguments: dateTime - Pointer to a DateTime_st structure containing the date and time.
 *                     seconds - Pointer to store the seconds since the epoch.
 *
 *  Return value     : E_OK if the conversion was successful, E_NOT_OK otherwise.
 *
 ***********************************************************************************************************************/
extern Std_ReturnType TimeSync_ConvertDateTimeToSeconds(const DateTime_st dateTime, uint64 *seconds);

#endif /* CALENDAR_H */
