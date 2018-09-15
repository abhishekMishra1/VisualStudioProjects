#pragma once
#include<thread>
#include<vector>
#include"DataCollector.h"
#include"Constants.h"
#include<Windows.h>
#include<atomic>

class Manager
{
public:
	Manager();
	~Manager();

	void createTasks();
	SHELLEXECUTEINFO& getShellData(string fileName, unsigned int);
	void ProcessMessages();

private:
	DataCollector m_FileReader;
	vector<thread> m_vWorkerThreads;
	unsigned int m_CoresAvailable;
	atomic<unsigned int> m_nActiveThreads;
	atomic<unsigned int> m_nJobsDone;
	unsigned int m_nTotalJobs;
	unsigned int m_nCounter = 0;
	void reEngageWorkers();
};


