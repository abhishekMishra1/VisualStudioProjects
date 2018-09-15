#pragma once
#if __cplusplus==201402L
#define _CPP_14_
#elif __cplusplus==201103L
#define _CPP_11_
#else
#define _CPP_98_
#endif

//Defining Debug mode and Release mode
#define DEBUG_MODE 1

using namespace std;

namespace MessageTypes
{
	const string DONE = "Done";
	const string IN_PROGRESS = "InProgress";
	const string WAITING = "Waiting";
	const string YET_TO_START = "YetToStart";
	const string CREATE_TASKS = "CreateTasks";
	const string STOP_MSG_PROCESSING = "StopMsgProcessing";
}

