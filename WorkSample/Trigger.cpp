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
// DESCRIPTION: Subclass the MSTask TASK_TRIGGER struct.  Provide two
//				ctors to initialize the struct, either with or without
//				an end time. A trigger type is optional.
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Trigger.h"

///////////////////////////////////////////////////////////////////////////
//      METHOD: Constructor
//              ===========
// DESCRIPTION: Initialize the trigger with a start time and a type.  A
//				trigger type is optional, default is once.
///////////////////////////////////////////////////////////////////////////
Trigger::Trigger(CTime start, TASK_TRIGGER_TYPE triggerType)
{
	ZeroMemory(this, sizeof(Trigger));

	cbTriggerSize = sizeof(Trigger);
	wBeginYear = start.GetYear();
	wBeginMonth = start.GetMonth();
	wBeginDay = start.GetDay();
	wStartHour = start.GetHour();
	wStartMinute = start.GetMinute();
	TriggerType = triggerType;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: Constructor
//              ===========
// DESCRIPTION: Initialize the trigger with a start time, an end time,
//				and a type.  A trigger type is optional, default is once.
///////////////////////////////////////////////////////////////////////////
Trigger::Trigger(CTime start, CTime end, TASK_TRIGGER_TYPE triggerType)
{
	ZeroMemory(this, sizeof(Trigger));

	cbTriggerSize = sizeof(Trigger);
	wBeginYear = start.GetYear();
	wBeginMonth = start.GetMonth();
	wBeginDay = start.GetDay();
	wStartHour = start.GetHour();
	wStartMinute = start.GetMinute();
	wEndYear = end.GetYear();
	wEndMonth = end.GetMonth();
	wEndDay = end.GetDay();
	rgFlags = TASK_TRIGGER_FLAG_HAS_END_DATE;
	TriggerType = triggerType;
}

