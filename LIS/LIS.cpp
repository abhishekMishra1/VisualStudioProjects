#include"LIS.h"

using namespace LIS_namespace;

LIS::LIS()
{}

LIS::LIS(vector<int> sequence)
{
	m_Sequence = sequence;
}

LIS::~LIS()
{
	m_Sequence.clear();
}


void LIS::SetSequence(vector<int> sequence)
{
	m_Sequence = sequence;
}

vector<int>& LIS::GetLISWithoutDP()
{

}

vector<int>& LIS::GetLISWithDP()
{
	vector<vector<int>> calculatedLIS(m_Sequence.size());
	calculatedLIS[0].push_back(m_Sequence[0]);
	for (int i = 1; i < m_Sequence.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if ((m_Sequence[j] < m_Sequence[i]) && calculatedLIS[i].size() < calculatedLIS.[j].size() + 1)
				calculatedLIS[i] = calculatedLIS[j];
		}
		calculatedLIS[i].push_back(m_Sequence[i]);
	}
}