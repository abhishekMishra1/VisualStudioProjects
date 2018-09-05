#include "Cards.h"
#include <iostream>
#include <vector>
#include <algorithm>


Cards::Cards()
{
}


Cards::~Cards()
{
}

int solution(vector<int> &A, vector<int> &B);

int test()
{
	vector<int> A = { 1, 1 };//{1,2,4,3};
	vector<int> B = { 2, 1 };//{1,3,2,3};

	cout << solution(A, B);
	return 0;
}

int solution(vector<int> &A, vector<int> &B)
{
	int smallestA = A[0], biggestA = A[0];
	int smallestB = B[0], biggestB = B[0];

	//1. Find the smallest and biggest for the card
	smallestA = *min_element(A.begin(), A.end());
	smallestB = *min_element(B.begin(), B.end());

	biggestA = *max_element(A.begin(), A.end());
	biggestB = *max_element(B.begin(), B.end());

	int biggest = 0;
	if (biggestA > biggestB)
		biggest = biggestA;
	else
		biggest = biggestB;


	//2. Create a bool vector having all elements as false from the above range
	vector<bool> rangeSet(biggest + 1, false);

	//3. Set the rangeSet with existing values from both faces
	rangeSet[0] = true;
	typedef vector<int>::iterator intIter;
	for (intIter i = A.begin(), j = B.begin(); i != A.end(), j != B.end(); i++, j++)
	{
		if (*i == *j)
			rangeSet[*i] = true;
		else if (*i < *j)
		{
			rangeSet[*i] = true;
			//rangeSet[*j] = true;
		}
		else if (*i > *j)
		{
			if (rangeSet[*j])
				rangeSet[*i] = true;
			else
				rangeSet[*j] = true;
		}
	}

	//4. Get the smallest unset from rangeSet
	int count = 0;
	for (auto i : rangeSet)
	{
		if (!i)
			break;
		count++;
	}

	return count;
}