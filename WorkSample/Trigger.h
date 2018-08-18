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
//				an end time.  A trigger type is optional.  Provide setters 
//				for flags and trigger type.
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

class Trigger : TASK_TRIGGER
{
public:
	Trigger(CTime start, TASK_TRIGGER_TYPE triggerType = TASK_TIME_TRIGGER_ONCE);
	Trigger(CTime start, CTime end, TASK_TRIGGER_TYPE triggerType = TASK_TIME_TRIGGER_ONCE);
	virtual ~Trigger() { }
	void SetFlags(DWORD flags) { rgFlags = flags; }
	void SetTriggerType(TASK_TRIGGER_TYPE triggerType) { TriggerType = triggerType; }
};

