///////////////////////////////////////////////////////////////////////////
//
// Copyright 2018 Tim Bomgardner.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////
//
//     PROJECT: WorkSample
//
//      AUTHOR: Tim Bomgardner
//
// DESCRIPTION: An exercise for Cofense to demonstrate basic knowledge
//				of COM interfaces and OO program construction.
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include "Task.h"
#include "Trigger.h"
#include "TaskException.h"
#include "TaskScheduler.h"
#include "COMManager.h"
using namespace std;
using namespace Cofense;

int main()
{
	try
	{
		COMManager MyCOM;

		Task task;
		task.SetUuidTaskName();
		task.SetDefaultTrigger();
		task.SetProgramPath(L"C:\\Windows\\System32\\notepad.exe");
		task.SetDefaultFlags();
		TaskScheduler::Save(task);
		std::cout << "Task '"; std::wcout << task.GetTaskName(); std::cout << "' created" << std::endl;
	}
	catch (TaskException& te)
	{
		std::cout << "Application failed" << std::endl;
		std::cout << te.what() << std::endl;
	}

}
