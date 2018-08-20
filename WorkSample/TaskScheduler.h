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
// DESCRIPTION: See TaskScheduler.cpp
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <MSTask.h>
#include "Task.h"

namespace Cofense
{
	class TaskScheduler
	{
	public:
		static void Save(Task& task);
		static void Delete(Task& task);
		static void CheckForExistingTask(ITaskScheduler* pITaskScheduler, Task& task);
		static void CheckReturnCode(HRESULT hr, const char* message);
	};
}
