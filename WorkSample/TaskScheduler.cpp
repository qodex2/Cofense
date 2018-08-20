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
// DESCRIPTION: Interact with the Windows Task Scheduler to save or delete
//				a task.  Most interaction with the COM interfaces occurs
//				here.
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "TaskScheduler.h"
#include "ResourceManager.h"
#include "TaskException.h"
using namespace Cofense;

#pragma comment(lib, "mstask.lib")

///////////////////////////////////////////////////////////////////////////
//      METHOD: Save
//              ====
// DESCRIPTION: Gather everything and save a task as a Scheduled Task.  A
//				ResourceManager object will take care of releasing an COM
//				resources that need to be released.
///////////////////////////////////////////////////////////////////////////
void TaskScheduler::Save(Task& task)
{
	ResourceManager& RM = *(new ResourceManager());
	HRESULT hr;
	WORD trigNumber;

	USES_CONVERSION;

	// Create an instance of the TaskScheduler, get the ITaskScheduler interface.
	hr = CoCreateInstance(
		CLSID_CTaskScheduler,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_ITaskScheduler,
		(void **)&RM.pITaskScheduler);
	CheckReturnCode(hr, "COM instance creation failed");

	CheckForExistingTask(RM.pITaskScheduler, task);

	// Create a work item.
	hr = RM.pITaskScheduler->NewWorkItem(
		T2COLE(task.GetTaskName().c_str()),
		CLSID_CTask,
		IID_ITask, 
		&RM.pIUnknown);
	CheckReturnCode(hr, "Unable to create work item");

	// Get at pointer to the ITask interface. 
	hr = RM.pIUnknown->QueryInterface(IID_ITask, (void **)&RM.pITask);
	CheckReturnCode(hr, "Unable to get an ITask");

	// Set the name of the application to be run.
	hr = RM.pITask->SetApplicationName(T2COLE(task.GetProgramPath().c_str()));
	CheckReturnCode(hr, "Failed to set application name");

	// Give the task parameters if there are any.
	if (task.GetParameters().length() > 0)
	{
		hr = RM.pITask->SetParameters(T2COLE(task.GetParameters().c_str()));
		CheckReturnCode(hr, "Failed to set task parameters");
	}

	// Set the task startup folder if there is one.
	if (task.GetStartingDir().length() > 0)
	{
		hr = RM.pITask->SetWorkingDirectory(T2COLE(task.GetStartingDir().c_str()));
		CheckReturnCode(hr, "Failed to set startup folder");
	}

	// Set the task comment if there is one.
	if (task.GetComment().length() > 0)
	{
		hr = RM.pITask->SetComment(T2COLE(task.GetComment().c_str()));
		CheckReturnCode(hr, "Failed to set comment");
	}

	// Set the task flags.
	hr = RM.pITask->SetFlags(task.GetFlags());
	CheckReturnCode(hr, "Failed to set flags");

	// Create a trigger, to be populated below.
	hr = RM.pITask->CreateTrigger(&trigNumber, &RM.pITaskTrigger);
	CheckReturnCode(hr, "Failed to create trigger");

	// Prepare the trigger.
	Trigger trigger = task.GetTrigger();
	trigger.FinalizeTypeFields();

	// Set the task trigger.
	hr = RM.pITaskTrigger->SetTrigger(&trigger);
	CheckReturnCode(hr, "Failed to set the trigger");

	// Retrieve the PersistFile interface.
	hr = RM.pITask->QueryInterface(IID_IPersistFile, (void **)&RM.pIPersistFile);
	CheckReturnCode(hr, "Failed to get the IPersistFile interface");

	// Save the task.
	hr = RM.pIPersistFile->Save(NULL, TRUE);
	CheckReturnCode(hr, "Failed to save the task");
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: Delete
//              ======
// DESCRIPTION: Delete a scheduled task.
///////////////////////////////////////////////////////////////////////////
void TaskScheduler::Delete(Task& task)
{
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: CheckForExistingTask
//              ====================
// DESCRIPTION: If a task with the given name already exists, show's over.
///////////////////////////////////////////////////////////////////////////
void TaskScheduler::CheckForExistingTask(ITaskScheduler* pITaskScheduler, Task& task)
{
	IUnknown* pIUnknown = NULL;
	HRESULT hr = pITaskScheduler->Activate(
		T2COLE(task.GetTaskName().c_str()),
		IID_ITask,
		&pIUnknown);
	if (SUCCEEDED(hr))
	{
		std::wstringstream message;
		message << "Task '" << task.GetTaskName() << "' already exists";
		throw TaskException(message.str());
	}
	if (pIUnknown != NULL) 
		pIUnknown->Release();
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: CheckReturnCode
//              ===============
// DESCRIPTION: Throw an exception on a bad result code.
///////////////////////////////////////////////////////////////////////////
void TaskScheduler::CheckReturnCode(HRESULT hr, const char* text)
{
	if (FAILED(hr))
	{
		std::wstringstream message;
		message << text << ", result: " << std::hex << hr;
		throw TaskException(message.str());
	}
}
