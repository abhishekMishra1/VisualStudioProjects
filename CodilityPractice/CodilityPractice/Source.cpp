#include "BinaryGap.h"
#include <iostream>

using namespace std;

int main()
{
	BinaryGap bin;
	unsigned int val = 0;
	cout << "Enter value :";
	cin >> val;
	cout << "\nMaximum binary gap is " << bin.solution(val) << endl;
	system("PAUSE");
	return 0;
}