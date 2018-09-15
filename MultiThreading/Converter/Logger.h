#pragma once
#include<fstream>
#include<string>
#include<mutex>
class Logger
{
public:
	static Logger& getInstance();
	void logComments(std::string str);
private:
	Logger() {}
	~Logger();
	Logger(const Logger&) {}

	static Logger m_Log;
	std::ofstream m_writeHandler;
	std::once_flag m_fileOpenerFlag;
};

inline void LogData(std::string str)
{
	Logger::getInstance().logComments(str);
}