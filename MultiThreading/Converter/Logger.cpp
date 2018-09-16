#include"Logger.h"
#include<ctime>
#include<chrono>
#include<iomanip>

Logger Logger::m_Log;
Logger::~Logger()
{
	if (m_writeHandler.is_open())
		m_writeHandler.close();
}
Logger& Logger::getInstance()
{
	return m_Log;
}

void Logger::logComments(std::string str, bool lineChange)
{
	std::call_once(m_fileOpenerFlag, [&]() {m_writeHandler.open("LogFile.txt", std::ios::app); });

	if (lineChange)
	{
		auto now = std::chrono::system_clock::now();
		auto now_c = std::chrono::system_clock::to_time_t(now);
		m_writeHandler << "[" << std::put_time(std::localtime(&now_c), "%c") << "] ";
		m_writeHandler << str << std::endl;
	}
	else
		m_writeHandler << str;
}


void Logger::logComments(unsigned int val, bool lineChange)
{
	std::call_once(m_fileOpenerFlag, [&]() {m_writeHandler.open("LogFile.txt", std::ios::app); });

	if (lineChange)
	{
		auto now = std::chrono::system_clock::now();
		auto now_c = std::chrono::system_clock::to_time_t(now);
		m_writeHandler << "[" << std::put_time(std::localtime(&now_c), "%c") << "] ";
		m_writeHandler << val << std::endl;
	}
	else
		m_writeHandler << val;

}


void Logger::changeLineOnly()
{
	std::call_once(m_fileOpenerFlag, [&]() {m_writeHandler.open("LogFile.txt", std::ios::app); });
	m_writeHandler << "\n";
}