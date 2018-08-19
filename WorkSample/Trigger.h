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
// DESCRIPTION: See Trigger.cpp
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#pragma once
#include <MSTask.h>
#include <atltime.h>

struct Trigger : TASK_TRIGGER
{
	Trigger(const TASK_TRIGGER_TYPE triggerType = TASK_TIME_TRIGGER_ONCE);
	Trigger(const CTime start, const TASK_TRIGGER_TYPE triggerType = TASK_TIME_TRIGGER_ONCE);
	Trigger(const CTime start, const CTime end, const TASK_TRIGGER_TYPE triggerType = TASK_TIME_TRIGGER_ONCE);
	virtual ~Trigger() { }
	void SetFlags(const DWORD flags) { rgFlags = flags; }
	void SetTriggerType(const TASK_TRIGGER_TYPE triggerType) { TriggerType = triggerType; }
	void FinalizeTypeFields();
	void SetDayOfWeek();
	void SetMonths();
};

