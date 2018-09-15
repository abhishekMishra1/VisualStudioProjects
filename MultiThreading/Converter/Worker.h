#pragma once
#include<string>
#include"Constants.h"
#include<Windows.h>

class Worker
{
public:
	//Worker(string& fileName);
	Worker() {}
	~Worker();
	void convertToWav();
	void setInfo(std::string fineName, string arg);
private:
	string m_FileName;
	SHELLEXECUTEINFO m_shellInfo;
	string m_arg;
};

