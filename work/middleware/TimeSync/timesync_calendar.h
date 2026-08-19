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
*  File name:           $Source: timesync_calendar.h $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      TIMESYNC_CALENDAR
*  Specification:
*  Date:                $Date: 2026/05/12  $
*
*  Description:     This unit processes the TimeSync calendar module.
*
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/
#ifndef TIMESYNC_CALENDAR_H
#define TIMESYNC_CALENDAR_H

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "Platform.h"

/***********************************************************************************************************************
*  variable definitions 
***********************************************************************************************************************/
typedef struct
{
    uint16 year;
    uint8 month;
    uint8 day;
    uint8 hour;
    uint8 minute;
    uint8 second;
} TimeSync_DateTime_t;


typedef struct
{
    uint32 appId;
    uint8 clockType;
    boolean isValid;
    TimeSync_DateTime_t dateTime;
    uint32 relativeSeconds;
} TimeSync_Appointment_t;

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
 *                     dateTime - Pointer to a TimeSync_DateTime_t structure to store the result.

 *  Return value     : E_OK if the conversion was successful, E_NOT_OK otherwise.
 *
 ***********************************************************************************************************************/
extern Std_ReturnType TimeSync_ConvertSecondsToDateTime(uint64 seconds,
                                                        TimeSync_DateTime_t *dateTime);

/***********************************************************************************************************************
 *  Function name    : TimeSync_ConvertDateTimeToSeconds()
 *
 *  Description      : Convert a date and time to seconds since the epoch.
 *
 *  List of arguments: dateTime - TimeSync_DateTime_t value containing the date and time.
 *                     seconds - Pointer to store the seconds since the epoch.
 *
 *  Return value     : E_OK if the conversion was successful, E_NOT_OK otherwise.
 *
 ***********************************************************************************************************************/
extern Std_ReturnType TimeSync_ConvertDateTimeToSeconds(TimeSync_DateTime_t dateTime,
                                                        uint64 *seconds);

#endif /* TIMESYNC_CALENDAR_H */
