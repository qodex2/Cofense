# Work Sample from Tim Bomgardner
## Assignment ##
We ask that you provide us with a solution and unit tests to the following problem. We require that you use a public GitHub repository for your solution, and provide us a link when you are complete. Take your time, but please let me know if you expect this task to take longer than a week.

Please write a small C++ (Windows) application that uses COM to talk to and create a scheduled task with the task scheduler.
##Requirements ##
1. Use a public Github repo
1. Deliver a solution
1. Unit tests
1. Windows
1. C++
1. COM 
1. Create a scheduled task
1. Use the task scheduler
1. Small
## Interpretation ##
1. My work sample can be found here: [https://github.com/qodex2/Cofense](https://github.com/qodex2/Cofense)
2. I interpret this to mean a solution and project created using Visual Studio.
3. Use a COTS framework?  How about CppUnit?
4. I interpret this to mean running under the Windows OS, not a GUI interface.
5. Some organizations are picky about the version 98? 11? Later?  I'll use whatever features are available in VS 2017.
6. That seems pretty straight-forward.  CoCreateInstance, etc.
7. Any old task will do, even one that doesn't actually do anything.
8. CLSID_CTaskScheduler, 0x148BD52A...
9. I'm assuming you're mainly looking to see if I can write reasonably clear code that deals with a C++ COM interface.  I hope you're not looking for extensive error handling and recovery, sophisticated logging, or an impressive user-friendly interface.  This is a "sample", after all.  The links in my resume will demonstrate my skills in those areas if you're interested.
## Key Classes ##
**Task**.  Manage the variable used to define a task.  Options exist to create default values.  

**Trigger**.  Extend the MSTask TASK_TRIGGER struct.  Provide three ctors to initialize the struct, either with or without an end time.  A trigger type is optional.  Provide setters for flags and trigger type.  

**TaskScheduler**.  Interact with the Windows Task Scheduler to save or delete a task.  All interaction with the COM interfaces occurs here.

**COMManager**.  Use RAII to manage COM initialization/uninitialization.

**ResourceManager**.  Use RAII to manage COM Resources.  Anything that needs to be released is guaranteed to be released.

**TaskException**.  Just about anything that can posibly go wrong with configuration or instantiation of a Task results in a TaskException being thrown.  Deal with wide string issues because std::exception is build around char*

