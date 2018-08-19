///////////////////////////////////////////////////////////////////////////
//
// Copyright 2018 Tim Bomgardner.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////
//
//       CLASS: Task
//
//      AUTHOR: Tim Bomgardner
//
// DESCRIPTION: Manage the variable used to define a task.  Options exist
//				to create default values.
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Task.h"
#include "Trigger.h"
#include "TaskException.h"

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetDefaultTrigger
//              =================
// DESCRIPTION: Set a default trigger for this task (start Now).
///////////////////////////////////////////////////////////////////////////
void Task::SetDefaultTrigger()
{
	Trigger defaultTrigger;
	MyTrigger = defaultTrigger;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetTrigger
//              ==========
// DESCRIPTION: Set the trigger for this task to the given value.
///////////////////////////////////////////////////////////////////////////
void Task::SetTrigger(Trigger value)
{
	MyTrigger = value;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetUuidTaskName
//              ===============
// DESCRIPTION: Generate a UUID as the task name.
///////////////////////////////////////////////////////////////////////////
void Task::SetUuidTaskName()
{
	UUID uuid;
	UuidCreate(&uuid);
	RPC_WSTR uuidStr = NULL;
	if (UuidToStringW(&uuid, &uuidStr) == RPC_S_OK)
	{
		TaskName = (wchar_t*)uuidStr;
		RpcStringFreeW(&uuidStr);
	}
	else
	{
		throw TaskException("Unable to create UUID for task name");
	}
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetTaskName
//              ===========
// DESCRIPTION: Validate and set the task name to the given value.
///////////////////////////////////////////////////////////////////////////
void Task::SetTaskName(std::wstring value)
{
	if (!ValidTaskName(value))
		throw TaskException("Invalid TaskName");
	TaskName = value;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetProgramPath
//              ==============
// DESCRIPTION: Validate and set the program path to the given value.
///////////////////////////////////////////////////////////////////////////
void Task::SetProgramPath(std::wstring value)
{ 
	if (!ValidProgramPath(value))
		throw TaskException("Invalid ProgramPath");
	ProgramPath = value;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetParameters
//              =============
// DESCRIPTION: Validate and set the parameters to the given value.
///////////////////////////////////////////////////////////////////////////
void Task::SetParameters(std::wstring value)
{ 
	if (!ValidParameters(value))
		throw TaskException("Invalid Parameters");
	Parameters = value;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetDirectory
//              ============
// DESCRIPTION: Validate and set the directory to the given value.
///////////////////////////////////////////////////////////////////////////
void Task::SetDirectory(std::wstring value)
{ 
	if (!ValidDirectory(value))
		throw TaskException("Invalid Directory");
	StartingDir = value;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetComment
//              ==========
// DESCRIPTION: Validate and set the comment to the given value.
///////////////////////////////////////////////////////////////////////////
void Task::SetComment(std::wstring value)
{ 
	if (!ValidComment(value))
		throw TaskException("Invalid Comment");
	Comment = value;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetFlags
//              ========
// DESCRIPTION: Provide a default set of flags.
///////////////////////////////////////////////////////////////////////////
void Task::SetFlags()
{
	Flags = TASK_FLAG_DONT_START_IF_ON_BATTERIES |
			TASK_FLAG_KILL_IF_GOING_ON_BATTERIES;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: SetFlags
//              ========
// DESCRIPTION: Validate and set the flags to the given value.
///////////////////////////////////////////////////////////////////////////
void Task::SetFlags(DWORD value)
{
	if (!ValidFlags(value))
		throw TaskException("Invalid flags");
	Flags = value;
}
