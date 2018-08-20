///////////////////////////////////////////////////////////////////////////
//
// Copyright 2018 Tim Bomgardner.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////
//
//       CLASS: TaskException
//
//      AUTHOR: Tim Bomgardner
//
// DESCRIPTION: Just about anything that can posibly go wrong with 
//				configuration or instantiation of a Task results in a 
//				TaskException being thrown.  Deal with wide string issues 
//				because std::exception is build around char*.
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <locale>
#include <codecvt>
#include "TaskException.h"
using namespace Cofense;

///////////////////////////////////////////////////////////////////////////
//      METHOD: Constructor
//              ===========
// DESCRIPTION: Take a plain old single-byte character string.
///////////////////////////////////////////////////////////////////////////
TaskException::TaskException(char const* const message)
	: exception(message)
{
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: Constructor
//              ===========
// DESCRIPTION: Take a wstring then convert it to single-byte.  This is 
//				necessary because std::exception is build around char*.
//				This is just a sorry state of affairs.  This ctor is here
//				for convenience because the COM interfaces are using wide 
//				chars.
///////////////////////////////////////////////////////////////////////////
TaskException::TaskException(std::wstring message)
	: exception(Convert(message).c_str())
{
}

///////////////////////////////////////////////////////////////////////////
//      METHOD: Constructor
//              ===========
// DESCRIPTION: Convert a wstring to a single-byte string.  If there are
//				non-ASCII (or even worse, surrogate pairs), too bad.
///////////////////////////////////////////////////////////////////////////
std::string TaskException::Convert(std::wstring message)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
	return convert.to_bytes(message);
}
