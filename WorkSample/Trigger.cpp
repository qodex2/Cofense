///////////////////////////////////////////////////////////////////////////
//
// Copyright 2018 Tim Bomgardner.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////
//
//       CLASS: Trigger
//
//      AUTHOR: Tim Bomgardner
//
// DESCRIPTION: Extend the MSTask TASK_TRIGGER struct.  Provide three
//				ctors to initialize the struct, either with or without
//				an end time.  A trigger type is optional.  Provide setters 
//				for flags and trigger type.
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <time.h>
#include "Trigger.h"
#include "TaskException.h"

///////////////////////////////////////////////////////////////////////////
//      METHOD: Constructor
//              ===========
// DESCRIPTION: Initialize the trigger with a start time of Now and a 
//				type.  A trigger type is optional, default is once.
///////////////////////////////////////////////////////////////////////////
Trigger::Trigger(const TASK_TRIGGER_TYPE triggerType)
{
	ZeroMemory(this, sizeof(Trigger));

	time_t osTime;
	time(&osTime);  // Now
	CTime start(osTime);

	cbTriggerSize = sizeof(Trigger);
	wBeginYear = start.GetYear();
	wBeginMonth = start.GetMonth();
	wBeginDay = start.GetDay();
	wStartHour = start.GetHour();
	wStartMinute = start.GetMinute();
	// seconds are ignored
	TriggerType = triggerType;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: Constructor
//              ===========
// DESCRIPTION: Initialize the trigger with a start time and a type.  A
//				trigger type is optional, default is once.
///////////////////////////////////////////////////////////////////////////
Trigger::Trigger(const CTime start, const TASK_TRIGGER_TYPE triggerType)
{
	if (start.GetYear() == 0)
		throw TaskException("Invalid start time");

	ZeroMemory(this, sizeof(Trigger));

	cbTriggerSize = sizeof(Trigger);
	wBeginYear = start.GetYear();
	wBeginMonth = start.GetMonth();
	wBeginDay = start.GetDay();
	wStartHour = start.GetHour();
	wStartMinute = start.GetMinute();
	// seconds are ignored
	TriggerType = triggerType;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: Constructor
//              ===========
// DESCRIPTION: Initialize the trigger with a start time, an end time,
//				and a type.  A trigger type is optional, default is once.
///////////////////////////////////////////////////////////////////////////
Trigger::Trigger(const CTime start, const CTime end, const TASK_TRIGGER_TYPE triggerType)
{
	if (start.GetYear() == 0)
		throw TaskException("Invalid start time");
	if (end.GetYear() == 0)
		throw TaskException("Invalid end time");

	ZeroMemory(this, sizeof(Trigger));

	cbTriggerSize = sizeof(Trigger);
	wBeginYear = start.GetYear();
	wBeginMonth = start.GetMonth();
	wBeginDay = start.GetDay();
	wStartHour = start.GetHour();
	wStartMinute = start.GetMinute();
	// seconds are ignored
	wEndYear = end.GetYear();
	wEndMonth = end.GetMonth();
	wEndDay = end.GetDay();
	rgFlags = TASK_TRIGGER_FLAG_HAS_END_DATE;
	TriggerType = triggerType;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: FinalizeTypeFields
//              ==================
// DESCRIPTION: Subfields in Type need to be finalized once everything
//				else has been set.
///////////////////////////////////////////////////////////////////////////
void Trigger::FinalizeTypeFields()
{
	switch (TriggerType)
	{
	case TASK_TIME_TRIGGER_DAILY:
		Type.Daily.DaysInterval = 1;
		break;

	case TASK_TIME_TRIGGER_WEEKLY:
		SetDayOfWeek();
		Type.Weekly.WeeksInterval = 1;
		break;

	case TASK_TIME_TRIGGER_MONTHLYDATE:
		Type.MonthlyDate.rgfDays = 1 << (wBeginDay - 1);
		SetMonths();
		break;

	default:
		break;
	}

}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetDayOfWeek
//              ============
// DESCRIPTION: Set the Type.Weekly.rgfDaysOfTheWeek value.
///////////////////////////////////////////////////////////////////////////
void Trigger::SetDayOfWeek()
{
	static WORD dayValues[] = 
	{ 
		0, 
		TASK_SUNDAY, 
		TASK_MONDAY, 
		TASK_TUESDAY,
		TASK_WEDNESDAY, 
		TASK_THURSDAY, 
		TASK_FRIDAY,
		TASK_SATURDAY 
	};
	Type.Weekly.rgfDaysOfTheWeek = dayValues[wBeginDay];
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetMonths
//              ============
// DESCRIPTION: Set the Type.MonthlyDate.rgfMonths value.
///////////////////////////////////////////////////////////////////////////
void Trigger::SetMonths()
{
	static WORD ALL =
		TASK_JANUARY |
		TASK_FEBRUARY |
		TASK_MARCH |
		TASK_APRIL |
		TASK_MAY |
		TASK_JUNE |
		TASK_JULY |
		TASK_AUGUST |
		TASK_SEPTEMBER |
		TASK_OCTOBER |
		TASK_NOVEMBER |
		TASK_DECEMBER;
	Type.MonthlyDate.rgfMonths = ALL;
}
