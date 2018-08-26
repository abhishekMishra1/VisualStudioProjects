#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <direct.h>

using namespace std;

class ContentCreator
{

public:
	ContentCreator();
	virtual ~ContentCreator();
	void readDirectory();
	void filterWavFiles();
	void encodeFilesToMp3();
private:

	string m_DirPath;
	vector<string> m_WavFiles;
};

