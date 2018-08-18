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

#pragma once

#include <MSTask.h>
#include "Task.h"

class TaskScheduler
{
public:
	TaskScheduler();
	~TaskScheduler();

	void Initialize();
	void Save(Task& task);
	void Delete(Task& task);
};

