///////////////////////////////////////////////////////////////////////////
//
// Copyright 2018 Tim Bomgardner.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////
//
//       CLASS: UnitTests
//
//      AUTHOR: Tim Bomgardner
//
// DESCRIPTION: A sample of unit tests for the WorkSample project.  A
//				production implementation would include a wider range.
//
///////////////////////////////////////////////////////////////////////////
// Date      By   Issue     Description
// --------  ---  --------  -----------------------------------------------
// 08/18/18  TAB            Creation
//
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <string.h>
#include "CppUnitTest.h"
#include "..\WorkSample\COMManager.h"
#include "..\WorkSample\ResourceManager.h"
#include "..\WorkSample\Task.h"
#include "..\WorkSample\TaskException.h"
#include "..\WorkSample\TaskScheduler.h"
#include "..\WorkSample\Trigger.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Cofense;

namespace UnitTests
{		
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(HelloUnitTest)
		{
			auto funcPtr = [this]
			{
				throw TaskException("Hello, UnitTest");
			};
			Assert::ExpectException<TaskException>(funcPtr);
		}

		TEST_METHOD(TriggerBasic)
		{
			Trigger t;
			Assert::IsTrue(t.TriggerType == TASK_TIME_TRIGGER_DAILY);
			Assert::IsTrue(t.cbTriggerSize == sizeof(TASK_TRIGGER));
		}

		TEST_METHOD(TriggerTime)
		{
			CTime time1(2018, 8, 19, 12, 21, 00);
			CTime time2(2019, 1, 1, 12, 21, 00);
			Trigger t(time1, time2);
			Assert::IsTrue(t.wBeginYear == 2018);
			Assert::IsTrue(t.wBeginMonth == 8);
			Assert::IsTrue(t.wBeginDay == 19);
			Assert::IsTrue(t.wStartHour == 12);
			Assert::IsTrue(t.wStartMinute == 21);
			Assert::IsTrue(t.wEndYear == 2019);
			Assert::IsTrue(t.wEndMonth == 1);
			Assert::IsTrue(t.wEndDay == 1);
		}

		TEST_METHOD(ResourceManagerBasic)
		{
			ResourceManager* RM = new ResourceManager;

			RM->pITaskScheduler = reinterpret_cast<ITaskScheduler*>(this);
			RM->pIPersistFile = reinterpret_cast<IPersistFile*>(this);
			RM->pITask = reinterpret_cast<ITask*>(this);
			RM->pITaskTrigger = reinterpret_cast<ITaskTrigger*>(this);

			Assert::IsNotNull(RM->pITaskScheduler);
			Assert::IsNotNull(RM->pIPersistFile);
			Assert::IsNotNull(RM->pITask);
			Assert::IsNotNull(RM->pITaskTrigger);
		}

		TEST_METHOD(COMManagerBasic)
		{
			try
			{
				Logger::WriteMessage("Begin COMManagerBasic"); 
				{
					COMManager MyCOM;
					// Let MyCOM go out of scope to test dtor
				}
			}
			catch (TaskException ex)
			{
				Logger::WriteMessage(ex.what());
				Assert::Fail();
			}
			catch (...)
			{
				Logger::WriteMessage("COMManagerBasic unknown exception");
				Assert::Fail();
			}
		}

		TEST_METHOD(TaskBasic)
		{
			Task t;
			t.SetUuidTaskName();
			t.SetDefaultTrigger();
			t.SetDefaultFlags();
			t.SetComment(L"A Comment");
			std::wstring genericUuid = L"ff895901-70ec-4662-afb9-eda82cedaffe";
			Assert::IsTrue(t.GetTaskName().length() == genericUuid.length());
			Assert::IsTrue(t.GetTrigger().wBeginYear != 0);
			Assert::IsTrue(t.GetTrigger().wBeginMonth != 0);
			Assert::IsTrue(t.GetTrigger().wBeginDay != 0);
			Assert::IsTrue(t.GetFlags() != 0);
			Assert::IsTrue(t.GetComment() == L"A Comment");
		}

		TEST_METHOD(TheWholeEnchilada)
		{
			try
			{
				COMManager MyCOM;

				Task task;
				task.SetUuidTaskName();
				task.SetDefaultTrigger();
				task.SetProgramPath(L"C:\\NotReallyAThing.exe");
				task.SetDefaultFlags();
				TaskScheduler::Save(task);
			}
			catch (TaskException ex)
			{
				Logger::WriteMessage(ex.what());
				Assert::Fail();
			}
			catch (...)
			{
				Logger::WriteMessage("TaskSchedule unknown exception");
				Assert::Fail();
			}
		}

	};
}