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
// DESCRIPTION: Use RAII to manage COM Resources.
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ResourceManager.h"
#define _WIN32_DCOM
#include <iostream>
#include <wbemidl.h>
#include <sstream>
#include "TaskException.h"
using namespace std;

ResourceManager::ResourceManager()
{
	pITaskScheduler = NULL;
	pIPersistFile = NULL;
	pITask = NULL;
	pITaskTrigger = NULL;
}

ResourceManager::~ResourceManager()
{
	if (pIPersistFile != NULL)
		pIPersistFile->Release();

	if (pITaskTrigger != NULL)
		pITaskTrigger->Release();

	if (pITask != NULL)
		pITask->Release();

	if (pITaskScheduler != NULL)
		pITaskScheduler->Release();
}
