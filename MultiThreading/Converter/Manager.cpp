#include "Manager.h"
#include"Worker.h"
#include"MessageHandler.h"
#include"Constants.h"
#include<future>
#include"Logger.h"

Manager::Manager()
	:m_CoresAvailable(thread::hardware_concurrency())
	, m_nActiveThreads(m_CoresAvailable)
	, m_nJobsDone(0)
{
	LogData(__FUNCTION__);
	m_FileReader.ReadDirectory("D:\\Workspace\\GoogleDrive\\VisualStudio\\lame-master\\output\\Release");
	m_nTotalJobs = m_FileReader.m_vWavFiles.size();
}


Manager::~Manager()
{
}

void Manager::createTasks()
{
	LogData(__FUNCTION__);
	int limit = m_CoresAvailable;
	if (m_nActiveThreads < m_CoresAvailable)
		limit = m_nActiveThreads;

	for (int p = 0; p < limit; ++p)
	{
		Worker worker;
		string fileName = m_FileReader.m_vWavFiles[m_nCounter];
		auto outputStr = fileName.substr(0, fileName.size() - 3) + "mp3";
		string argument = " -V0 " + fileName + " " + outputStr;

		worker.setInfo(fileName, argument);
		thread t(&Worker::convertToWav, &worker);
		t.join();
		m_nCounter++;
//		m_vWorkerThreads.push_back(move(t));
	}
}

SHELLEXECUTEINFO& Manager::getShellData(string fileName, unsigned int fileIndex)
{
	SHELLEXECUTEINFO data = {0};
	data.cbSize = sizeof(data);
	data.lpVerb = "open";
	data.lpFile = "D:\\Workspace\\GoogleDrive\\VisualStudio\\lame-master\\output\\Release\\lame.exe";
	data.lpParameters = m_FileReader.m_vWavFiles[fileIndex].data();
	data.nShow = SW_NORMAL;
	data.fMask = SEE_MASK_NOCLOSEPROCESS;

	return data;

}

void Manager::ProcessMessages()
{
	while (true)
	{
		string msg = MessagePosting::GetNotification();
		if (msg == MessageTypes::DONE && m_nActiveThreads)
		{
			m_nActiveThreads--;
			m_nJobsDone++;
		}
		else if (msg == MessageTypes::CREATE_TASKS && !m_nActiveThreads)
		{
			unsigned int workersRequired = m_nTotalJobs - m_nJobsDone;
			if (workersRequired > m_CoresAvailable)
				m_nActiveThreads = m_CoresAvailable;
			else
				m_nActiveThreads = workersRequired;
			createTasks();
		}
		else if (msg == MessageTypes::STOP_MSG_PROCESSING)
		{
			break;
			return;
		}

		if (!m_nActiveThreads)
		{
			reEngageWorkers();
		}
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

void Manager::reEngageWorkers()
{
	LogData(__FUNCTION__);
	if (m_nJobsDone == m_nTotalJobs)
	{
		MessagePosting::SendNotification(MessageTypes::STOP_MSG_PROCESSING);
	}
	else
	{
		MessagePosting::SendNotification(MessageTypes::CREATE_TASKS);
	}
}