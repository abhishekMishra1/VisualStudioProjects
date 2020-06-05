#include "MyDS.h"

int main()
{
	MyDS::sList<int> myList;
	for(int i = 0; i <= 4000; ++i)
		myList.insert_front(i);

	myList.traverse_reverse(); //Recursion

//	myList.traverse();
	return 0;
}