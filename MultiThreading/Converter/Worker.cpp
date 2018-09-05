#include "Worker.h"


//Worker::Worker(string& fileName)
//	:m_FileName(fileName)
//{
//}


Worker::~Worker()
{
}


void Worker::convertToWav()
{
	SHELLEXECUTEINFO data = { 0 };
	data.cbSize = sizeof(data);
	data.lpVerb = "open";
	data.lpFile = "E:\\WorkSpace\\lame-3.100\\output\\Release\\lame.exe";
	data.lpParameters = "E:\\WorkSpace\\lame-3.100\\output\\Release\\SleepAway.wav";
	data.nShow = SW_NORMAL;
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
}

void Worker::setInfo(SHELLEXECUTEINFO info, string arg)
{
	m_shellInfo = std::move(info);
	m_arg = arg.c_str();
}