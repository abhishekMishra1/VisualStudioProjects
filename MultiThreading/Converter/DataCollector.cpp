#include "DataCollector.h"
#if defined(_WIN32)
#include<Windows.h>
#endif


DataCollector::DataCollector():m_pReadDirectory(nullptr)
{
#if defined(_CPP_14_)
	m_pReadDirectory = &ReadDirectory_CPP_14;
#elif defined(_CPP_11_)
	m_pReadDirectory = &ReadDirectory_CPP_11;
#elif defined(_CPP_98_)
	m_pReadDirectory = &DataCollector::ReadDirectory_CPP_98;
#endif
}


DataCollector::~DataCollector()
{
}

void DataCollector::ReadDirectory_CPP_98()
{
#if defined(_CPP_98_)
#if defined(_WIN32)
	std::string pattern(m_DirectoryPath);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			m_vFiles.push_back(data.cFileName);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}

#elif defined(_linux_)
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir("c:\\src\\")) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			printf("%s\n", ent->d_name);
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		perror("");
		return EXIT_FAILURE;
	}
#endif
#endif
}

void DataCollector::ReadDirectory_CPP_11()
{}

void DataCollector::ReadDirectory_CPP_14()
{
#if defined(_CPP_14_)
	std::string path = "/path/to/directory";
	for (auto & p : filesystem::directory_iterator(path))
		std::cout << p << std::endl;
#endif
}

void DataCollector::ReadDirectory(const string& path)
{
	m_DirectoryPath = path;
	(this->*m_pReadDirectory)();
	FilterWaveFiles();
}

#if DEBUG_MODE
void DataCollector::ShowDirectoryContent()
{
	for (auto p : m_vFiles)
		cout << p << endl;

	cout << endl << endl;

	for (auto s : m_vWavFiles)
		cout << s << endl;
}
#endif

void DataCollector::FilterWaveFiles()
{
	for (auto p : m_vFiles)
	{
		if (p.size() <= 3)
			continue;
		string extension = p.substr(p.size() - 3, 3);
		if (extension == "wav" || extension == "WAV" || extension == "Wav")
			m_vWavFiles.push_back(p);
	}
}