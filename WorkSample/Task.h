///////////////////////////////////////////////////////////////////////////
//
// Copyright 2018 Tim Bomgardner.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////
//
//       CLASS: Task
//
//      AUTHOR: Tim Bomgardner
//
// DESCRIPTION: See Task.cpp
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#pragma once
#include <MSTask.h>
#include <string>
#include "Trigger.h"

namespace Cofense
{
	class Task
	{
	public:
		Trigger GetTrigger() { return MyTrigger; }
		std::wstring GetTaskName() { return TaskName; }
		std::wstring GetProgramPath() { return ProgramPath; }
		std::wstring GetParameters() { return Parameters; }
		std::wstring GetStartingDir() { return StartingDir; }
		std::wstring GetComment() { return Comment; }
		DWORD GetFlags() { return Flags; }

		void SetDefaultTrigger();
		void SetUuidTaskName();
		void SetDefaultFlags();

		void SetTrigger(Trigger value);
		void SetTaskName(std::wstring value);
		void SetProgramPath(std::wstring value);
		void SetParameters(std::wstring value);
		void SetDirectory(std::wstring value);
		void SetComment(std::wstring value);
		void SetFlags(DWORD value);

	protected:
		// Necessary methods, but implementation mostly beyond the scope of this exercise.
		bool ValidTaskName(std::wstring value) { return value.length() > 0; }
		bool ValidProgramPath(std::wstring value) { return value.length() > 0; }
		bool ValidParameters(std::wstring value) { return true; }
		bool ValidDirectory(std::wstring value) { return true; }
		bool ValidComment(std::wstring value) { return true; }
		bool ValidFlags(DWORD value) { return true; }

	private:
		Trigger MyTrigger;
		std::wstring TaskName;
		std::wstring ProgramPath;
		std::wstring Parameters;
		std::wstring StartingDir;
		std::wstring Comment;
		DWORD Flags = 0;
	};
}