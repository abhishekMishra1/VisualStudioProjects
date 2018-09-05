#include "ContentCreator.h"
#if defined(_WIN32)
#include<

ContentCreator::ContentCreator()
{
}


ContentCreator::~ContentCreator()
{
}

void ContentCreator::filterWavFiles()
{}

#if defined(_WIN32) 
void ContentCreator::readDirectory()
{

}
#elif defined(_linux_)
void ContentCreator::readDirectory()
{

}
#endif

void ContentCreator::encodeFilesToMp3()
{}