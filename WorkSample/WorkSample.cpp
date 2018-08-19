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
//				of COM interfaces and program construction.
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include "TaskException.h"
#include "COMManager.h"
using namespace std;

int main()
{
	try
	{
		COMManager MyCOM;


	}
	catch (TaskException& te)
	{
		std::cout << "Application failed" << std::endl;
		std::cout << te.what() << std::endl;
	}

}
