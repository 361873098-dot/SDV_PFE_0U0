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
*  Description:     OS task count structure instance
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
#include "os_taskcount.h"
/***********************************************************************************************************************
*  local type definitions (STRUCT, TYPEDEF, ...)
***********************************************************************************************************************/


/***********************************************************************************************************************
*  local variable definitions (module local variables)
***********************************************************************************************************************/
static   uint32 M7_Core0_1ms;
static   uint32 M7_Core0_5ms;
static   uint32 M7_Core0_10ms;
static   uint32 M7_Core0_100ms;
static   uint32 M7_Core0_1000ms;


OsTaskCountType OsTaskCount = 
{
   /* Core 0 */
   &M7_Core0_1ms,
   &M7_Core0_5ms,
   &M7_Core0_10ms,
   &M7_Core0_100ms,
   &M7_Core0_1000ms,
};