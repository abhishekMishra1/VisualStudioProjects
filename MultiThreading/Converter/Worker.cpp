#include "Worker.h"
#include "MessageHandler.h"
#include "Constants.h"
#include"Logger.h"
#include<iostream>

Worker::~Worker()
{
}


void Worker::convertToWav()
{
	SHELLEXECUTEINFO data = { 0 };
	std::string file = "\""+m_FileName+"\"";
	data.cbSize = sizeof(data);
	data.lpVerb = "open";
	data.lpFile = "lame.exe";
	data.lpParameters = m_FileName.data();// file.data();
	data.nShow = SW_HIDE;
	data.fMask = SEE_MASK_NOCLOSEPROCESS;
	std::cout << file << std::endl;
	ShellExecuteEx(&data);   // you should check for an error here
	std::cout << "Processed file " << m_FileName << endl;
	std::string logInfo = "Processed file " + m_FileName;
	LogData(logInfo);

	DWORD dwCode;
	GetExitCodeProcess(m_shellInfo.hProcess, &dwCode);  // ERRORLEVEL value
	if (dwCode == STATUS_PENDING)
	{
		std::cout << "Still processing\n";
	}
	else
	{
		if (dwCode == 0)
		{
			std::cout << "Converted file " << m_FileName << endl;
			std::string logInfo = "Converted file " + m_FileName;
			LogData(logInfo);
		}
		else
		{
			//std::cout << "Error while converting file " << m_FileName << endl;
			//std::string logInfo = "Error while converting file " + m_FileName;
			//LogData(logInfo);
			//logInfo.clear();
			//logInfo.append("Error code is ");
			//LogData(logInfo, false);
			//LogData(dwCode, false);
			//LogDataOnlyLineChange();
		}
	}
	
	MessagePosting::SendNotification(MessageTypes::DONE);
}

void Worker::setInfo(std::string filename, string arg)
{
	m_FileName = filename;
	m_arg = arg.data();
}