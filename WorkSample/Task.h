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
#include <string>
#include "Trigger.h"

class Task
{
public:
	Trigger GetTrigger() { return MyTrigger; }
	std::string GetProgramPath() { return ProgramPath; }
	std::string GetParameters() { return Parameters; }
	std::string GetStartingDir() { return StartingDir; }
	std::string GetTUsername() { return Username; }
	std::string GetPassword() { return Password; }
	std::string GetComment() { return Comment; }

	void SetTrigger(Trigger value);
	void SetProgramPath(std::string value);
	void SetParameters(std::string value);
	void SetDirectory(std::string value);
	void SetUsername(std::string value);
	void SetPassword(std::string value);
	void SetComment(std::string value);

protected:
	// Necessary methods, but implementation beyond the scope of this exercise.
	bool ValidProgramPath(std::string value) { return true; }
	bool ValidParameters(std::string value) { return true; }
	bool ValidDirectory(std::string value) { return true; }
	bool ValidUsername(std::string value) { return true; }
	bool ValidPassword(std::string value) { return true; }
	bool ValidComment(std::string value) { return true; }

private:
	Trigger MyTrigger;
	std::string ProgramPath;
	std::string Parameters;
	std::string StartingDir;
	std::string Username;
	std::string Password;
	std::string Comment;
};

