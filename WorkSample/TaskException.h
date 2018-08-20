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
// DESCRIPTION: See TaskException.cpp
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#pragma once
#include <stdexcept>
#include <string>

namespace Cofense
{
	class TaskException : public std::exception
	{
	public:
		TaskException(char const* const message);
		TaskException(std::wstring message);
		virtual ~TaskException() { }
	private:
		std::string Convert(std::wstring message);
	};
}
