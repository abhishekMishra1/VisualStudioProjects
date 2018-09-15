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
	const std::string fileArg = "D:\\Workspace\\GoogleDrive\\VisualStudio\\lame-master\\output\\Release\\" + m_FileName;
	SHELLEXECUTEINFO data = { 0 };
	data.cbSize = sizeof(data);
	data.lpVerb = "open";
	data.lpFile = "D:\\Workspace\\GoogleDrive\\VisualStudio\\lame-master\\output\\Release\\lame.exe";
	data.lpParameters = fileArg.data();
	data.nShow = SW_HIDE;
	data.fMask = SEE_MASK_NOCLOSEPROCESS;

	ShellExecuteEx(&data);   // you should check for an error here
	//while (TRUE) {
	//	DWORD nStatus = MsgWaitForMultipleObjects(
	//		1, &m_shellInfo.hProcess, FALSE,
	//		INFINITE, QS_ALLINPUT   // drop through on user activity 
	//	);
	//	if (nStatus == WAIT_OBJECT_0) {  // done: the program has ended
	//		break;
	//	}
	//	MSG msg;     // else process some messages while waiting...
	//	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
	//		DispatchMessage(&msg);
	//	}
	//}  // launched process has exited

	DWORD dwCode;
	GetExitCodeProcess(m_shellInfo.hProcess, &dwCode);  // ERRORLEVEL value
	std::cout << "Converted file " << m_FileName << endl;
	std::string logInfo = "Converted file " + m_FileName;
	LogData(logInfo);
	MessagePosting::SendNotification(MessageTypes::DONE);
}

void Worker::setInfo(std::string filename, string arg)
{
	m_FileName = filename;
	m_arg = arg.data();
}