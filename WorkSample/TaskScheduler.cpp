///////////////////////////////////////////////////////////////////////////
//
// Copyright 2018 Tim Bomgardner.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////
//
//       CLASS: TaskScheduler
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
#include "TaskScheduler.h"


TaskScheduler::TaskScheduler()
{
}


TaskScheduler::~TaskScheduler()
{
}

void TaskScheduler::Initialize()
{
}

////////////////////////////////////////////////// ////////////////////////
//
// Method: Save()
//
// Sets the comment that will be displayed by the task schedule
// for a given task
//
// Input parameters:
// szComment: [in] Comment
//
// Return value:
// Lack
//
////////////////////////////////////////////////// ////////////////////////
void TaskScheduler::Save(Task& task)
{
	HRESULT         hr;
	ITaskScheduler* pITaskScheduler = NULL;
	IUnknown*       pIUnknown = NULL;
	IPersistFile*   pIPersistFile = NULL;
	ITask*          pITask = NULL;
	ITaskTrigger*   pITaskTrigger = NULL;
	DWORD           taskFlags;
	WORD            trigNumber;
}


void TaskScheduler::Delete(Task& task)
{
}
