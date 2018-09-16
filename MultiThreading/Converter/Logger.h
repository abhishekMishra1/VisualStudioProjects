#pragma once
#include<fstream>
#include<string>
#include<mutex>
class Logger
{
public:
	static Logger& getInstance();
	void logComments(std::string str, bool lineChange);
	void logComments(unsigned int val, bool lineChange);
	void changeLineOnly();
private:
	Logger() {}
	~Logger();
	Logger(const Logger&) {}

	static Logger m_Log;
	std::ofstream m_writeHandler;
	std::once_flag m_fileOpenerFlag;
};

inline void LogData(std::string str, bool lineChange=true)
{
	Logger::getInstance().logComments(str, lineChange);
}

inline void LogData(unsigned int val, bool lineChange=true)
{
	Logger::getInstance().logComments(val, lineChange);
}

inline void LogDataOnlyLineChange()
{
	Logger::getInstance().changeLineOnly();
}