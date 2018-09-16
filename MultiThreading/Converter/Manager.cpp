#include "Manager.h"
#include"Worker.h"
#include"MessageHandler.h"
#include"Constants.h"
#include<future>
#include"Logger.h"

Manager::Manager()
	:m_CoresAvailable(thread::hardware_concurrency())
	, m_nActiveThreads(0)
	, m_nJobsDone(0)
{
	LogData(__FUNCTION__);
	m_FileReader.ReadDirectory(".");
	m_nTotalJobs = static_cast<unsigned int>(m_FileReader.m_vWavFiles.size());
	if (m_CoresAvailable > m_nTotalJobs)
		m_nActiveThreads = m_nTotalJobs;
	else
		m_nActiveThreads = m_CoresAvailable;
}


Manager::~Manager()
{
}

void Manager::createTasks()
{
	LogData(__FUNCTION__);
	if (m_nTotalJobs != 0)
	{
		int limit = m_CoresAvailable;
		if (m_nActiveThreads < m_CoresAvailable)
			limit = m_nActiveThreads;

		for (int p = 0; p < limit; ++p)
		{
			Worker worker;
			string fileName = m_FileReader.m_vWavFiles[m_nCounter];
			//auto outputStr = fileName.substr(0, fileName.size() - 3) + "mp3";
			//string argument = " -V0 " + fileName + " " + outputStr;

			worker.setInfo(fileName, "");
			thread t(&Worker::convertToWav, &worker);
			t.join();
			m_nCounter++;
		}
	}
	else
	{
		LogData("Seems no file to process. Either check the current directory or report to the team!");
		std::cout << "No *.wav file found to process\n";
		MessagePosting::SendNotification(MessageTypes::STOP_MSG_PROCESSING);
	}

	if(m_nJobsDone == m_nTotalJobs)
		MessagePosting::SendNotification(MessageTypes::STOP_MSG_PROCESSING);
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