#include "Manager.h"
#include"Worker.h"
#include<future>


Manager::Manager()
	:m_CoresAvailable(thread::hardware_concurrency())
{
	m_FileReader.ReadDirectory("E:\\WorkSpace\\lame-3.100\\output\\Release");
}


Manager::~Manager()
{
}

void Manager::createTasks()
{
	for (int p = 0; p < m_FileReader.m_vWavFiles.size(); ++p)
	{
		Worker worker;
		string fileName = m_FileReader.m_vWavFiles[p];
		auto outputStr = fileName.substr(0, fileName.size() - 3) + "mp3";
		string argument = " -V0 " + fileName + " " + outputStr;

		worker.setInfo(getShellData(fileName), argument);
		thread t(&Worker::convertToWav, &worker);
		t.join();
		m_vWorkerThreads.push_back(move(t));
	}
}

SHELLEXECUTEINFO& Manager::getShellData(string fileName)
{
	SHELLEXECUTEINFO data = {0};
	data.cbSize = sizeof(data);
	data.lpVerb = "open";
	data.lpFile = "E:\\WorkSpace\\lame-3.100\\output\\Release\\lame.exe";
	data.lpParameters = "SleepAway.wav";
	data.nShow = SW_NORMAL;
	data.fMask = SEE_MASK_NOCLOSEPROCESS;

	return data;

}