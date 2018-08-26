#pragma once
#include <vector>
using namespace std;


class Cards
{
public:
	Cards();
	virtual ~Cards();
	Cards(vector<int> A, vector<int> B)
	{
		faceA = A;
		faceB = B;
	}

	vector<int> faceA;
	vector<int> faceB;
};

