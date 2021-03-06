///////////////////////////////////////////////////////////////////////////
//
// Copyright 2018 Tim Bomgardner.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////
//
//       CLASS: COMManager
//
//      AUTHOR: Tim Bomgardner
//
// DESCRIPTION: Use RAII to manage COM initialization/uninitialization.
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "COMManager.h"
#define _WIN32_DCOM
#include <iostream>
#include <wbemidl.h>
#pragma comment(lib, "wbemuuid.lib")
#include <sstream>
#include "TaskException.h"
using namespace std;
using namespace Cofense;

///////////////////////////////////////////////////////////////////////////
//      METHOD: Constructor
//              ===========
// DESCRIPTION: Initialize the COM library on the curren thread.  Throw
//				a TaskException on any error
///////////////////////////////////////////////////////////////////////////
COMManager::COMManager()
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (FAILED(hr))
	{
		std::wstringstream message;
		message << "COM initialization failed, result: " << std::hex << hr;
		throw TaskException(message.str());
	}

	initialized = true;
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: Destructor
//              ==========
// DESCRIPTION: Closes the COM library on the current thread. 
///////////////////////////////////////////////////////////////////////////
COMManager::~COMManager()
{
	if (initialized)
		CoUninitialize();
}
