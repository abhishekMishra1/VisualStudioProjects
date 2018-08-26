#pragma once
#include "ContentCreator.h"
#include "WorkerThreads.h"

class Mp3Encoder
{
public:
	Mp3Encoder();
	virtual ~Mp3Encoder();


private:
	int m_nWavFiles;
	int m_nCoresAvailable;
	int m_nTotalFilesInDir;
	ContentCreator m_DataContent;
	vector<WorkerThreads> m_vWorkerThreads;
};

