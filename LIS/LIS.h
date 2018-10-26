#pragma once
#include<vector>

using namespace std;
namespace LIS_namespace {
	class LIS
	{
	public:
		LIS();
		LIS(vector<int> sequence);
		~LIS();
		LIS(const LIS&) = delete;
		void SetSequence(vector<int> sequence);
		vector<int>& GetLISWithoutDP();
		vector<int>& GetLISWithDP();

	protected:
		vector<int> m_Sequence;

	};
}