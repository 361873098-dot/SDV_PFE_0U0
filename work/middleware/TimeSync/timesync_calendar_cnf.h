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
*  File name:           $Source: timesync_calendar_cnf.h $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      TIMESYNC_CALENDAR_CNF
*  Specification:
*  Date:                $Date: 2026/05/12  $
*
*  Description:     This unit configures the TimeSync calendar module.
*
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/
#ifndef TIMESYNC_CALENDAR_CNF_H
#define TIMESYNC_CALENDAR_CNF_H

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "timesync_calendar.h"

/***********************************************************************************************************************
*  define macros
***********************************************************************************************************************/
#define TIMESYNC_APPOINTMENT_LIST_SIZE    (3U)
/***********************************************************************************************************************
*  global variable declarations
***********************************************************************************************************************/
extern TimeSync_Appointment_t
    g_TimeSyncAppointmentList[TIMESYNC_APPOINTMENT_LIST_SIZE];

/***********************************************************************************************************************
*  local function definitions
***********************************************************************************************************************/




#endif /* TIMESYNC_CALENDAR_CNF_H */
