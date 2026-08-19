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
*  File name:           $Source: calendar_cnf.c $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      CALENDAR
*  Specification:
*  Date:                $Date: 2026/05/12  $
*
*  Description:     This Unit processes the Calendar configuration module
*
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "calendar_cnf.h"
#include "calendar.h"

/***********************************************************************************************************************
*  local variable definitions 
***********************************************************************************************************************/

/***********************************************************************************************************************
*  global variable definitions
***********************************************************************************************************************/
Appt_st g_appointment_list[APPOINTMENT_LIST_NUM] = {0};

/***********************************************************************************************************************
*  local function definitions
***********************************************************************************************************************/
