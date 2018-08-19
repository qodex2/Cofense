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
// DESCRIPTION: 
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Task.h"
#include "TaskException.h"

void Task::SetTrigger(Trigger value) 
{ 
	MyTrigger = value;
}

void Task::SetProgramPath(std::string value)
{ 
	if (!ValidProgramPath(value))
		throw TaskException("Invalid ProgramPath");
	ProgramPath = value;
}

void Task::SetParameters(std::string value) 
{ 
	if (!ValidParameters(value))
		throw TaskException("Invalid Parameters");
	Parameters = value;
}

void Task::SetDirectory(std::string value) 
{ 
	if (!ValidDirectory(value))
		throw TaskException("Invalid Directory");
	StartingDir = value;
}

void Task::SetUsername(std::string value) 
{ 
	if (!ValidUsername(value))
		throw TaskException("Invalid Username");
	Username = value;
}

void Task::SetPassword(std::string value) 
{ 
	if (!ValidPassword(value))
		throw TaskException("Invalid Password");
	Password = value;
}

void Task::SetComment(std::string value) 
{ 
	if (!ValidComment(value))
		throw TaskException("Invalid Comment");
	Comment = value;
}
