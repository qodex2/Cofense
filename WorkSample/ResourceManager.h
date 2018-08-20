///////////////////////////////////////////////////////////////////////////
//
// Copyright 2018 Tim Bomgardner.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////
//
//       CLASS: ResourceManager
//
//      AUTHOR: Tim Bomgardner
//
// DESCRIPTION: See ResourceManager.cpp
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <MSTask.h>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	IUnknown*       pIUnknown;
	ITaskScheduler* pITaskScheduler;
	IPersistFile*   pIPersistFile;
	ITask*          pITask;
	ITaskTrigger*   pITaskTrigger;
};
