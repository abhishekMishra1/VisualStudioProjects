#include "BinaryGap.h"
#include <string>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

BinaryGap::BinaryGap()
{
}


BinaryGap::~BinaryGap()
{
}

int BinaryGap::solution(int N)
{
	std::string binary = std::bitset<32>(N).to_string();
	
	vector<int> vBinaryGaps;
	int count = 0;
	bool bStart_ = false;
	for (auto i : binary)
	{
		if ('1' == i)
		{
			if (!bStart_)
				bStart_ = true;
			else
			{
				vBinaryGaps.push_back(count);
				count = 0;
				//bStart_ = false;
			}
		}

		if ('0' == i && bStart_)
		{
			count++;
		}
	}


	int maxBinaryGap = 0;
	if(vBinaryGaps.size())
		maxBinaryGap = *max_element(vBinaryGaps.begin(), vBinaryGaps.end());
	return maxBinaryGap;
}