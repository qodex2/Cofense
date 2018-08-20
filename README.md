# Work Sample from Tim Bomgardner
## Assignment ##
We ask that you provide us with a solution and unit tests to the following problem. We require that you use a public GitHub repository for your solution, and provide us a link when you are complete. Take your time, but please let me know if you expect this task to take longer than a week.

Please write a small C++ (Windows) application that uses COM to talk to and create a scheduled task with the task scheduler.
## Choices, and What I Discovered Along The Way
Given that "small" is explicitly specified, some choices were required.  Should I provide a general-purpose implementation with a GUI, extensive error handling and recovery, and sophisticated logging, or a simple hard-coded app that does exactly what the assignment asked for and no more? I leaned toward the former, but tried not to go overboard.

Having no previous knowledge of the TaskScheduler API, I spent a little time on research.  I discovered there are actually two interfaces: V1, supported by *MSTask.h*, and V2, supported by *taskschd.h*.  I tried both, and both are able to create and schedule tasks.  I found the V1 API more convenient to work with, so my work sample uses the V1 API. 
## Key Classes ##
**Task**.  Manage the variable used to define a task.  Options exist to create default values.  

**Trigger**.  Extend the MSTask TASK_TRIGGER struct.  Provide three ctors to initialize the struct, either with or without an end time.  A trigger type is optional.  Provide setters for flags and trigger type.  

**TaskScheduler**.  Interact with the Windows Task Scheduler to save or delete a task.  Most interaction with the COM interfaces occurs here.

**COMManager**.  Use RAII to manage COM initialization/uninitialization.

**ResourceManager**.  Use RAII to manage COM Resources.  Anything that needs to be released is guaranteed to be released.

**TaskException**.  Just about anything that can posibly go wrong with configuration or instantiation of a Task results in a TaskException being thrown.  Deal with wide string issues because std::exception is build around char*

