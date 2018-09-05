#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Constants.h"
#include<vector>

#if defined(_CPP_14_)
#include<filesystem>
#elif defined(_CPP_11_)
#include<experimental\filesystem>
#elif defined(_CPP_98_)
	#if defined(_WIN32)
	#include<io.h>
	#elif defined(_linux_)
	#include<dirent.h>
	#endif
#endif

using namespace std;

class DataCollector
{

public:
	DataCollector();
	~DataCollector();
	void ReadDirectory(const string& path);
#if DEBUG_MODE
	void ShowDirectoryContent();
#endif
private:

	void ReadDirectory_CPP_14();
	void ReadDirectory_CPP_11();
	void ReadDirectory_CPP_98();
	void FilterWaveFiles();

	typedef void(DataCollector::*PlatformMappingFunction)();
	PlatformMappingFunction m_pReadDirectory;
	string m_DirectoryPath;
	vector<string> m_vFiles;
public:
	vector<string> m_vWavFiles;
};

