#pragma once
#include <thread>
#include <mutex>

using namespace std;

class WorkerThreads
{
public:
	WorkerThreads();
	virtual ~WorkerThreads();
	
private:
	mutex m_mutex;
	thread m_thread;
};

