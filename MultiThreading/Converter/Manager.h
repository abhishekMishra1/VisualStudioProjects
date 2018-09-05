#pragma once
#include<thread>
#include<vector>
#include"DataCollector.h"
#include"Constants.h"
#include<Windows.h>
class Manager
{
public:
	Manager();
	~Manager();

	void createTasks();
	SHELLEXECUTEINFO& getShellData(string fileName);

private:
	DataCollector m_FileReader;
	vector<thread> m_vWorkerThreads;
	unsigned int m_CoresAvailable;
};

