#include "OperatorOverloading.h"
#include <iostream>
using namespace std;

int main()
{
	TestOpOverload obj1, obj2;
	cout << obj1.getValue() << endl;
	++obj1;
	cout << obj1.getValue() << endl;
	obj2++;
	cout << obj2.getValue() << endl;

	TestOpOverload obj3 = obj1 + obj2;
	cout << obj3.getValue() << endl;


	//conversion contructor
	TestOpOverload2 obj4 = obj3;
	cout << obj3.getValue()<<endl;

	//implicit conversion constructor
	TestOpOverload obj5;
	obj5 = 10;
	cout << obj5.getValue() << endl;

	TestOpOverload2 obj6;
	obj6 = obj5;
	cout << obj6.getValue() << endl;

//	Test t;
//	fun(t);

	system("PAUSE");
	return 0;
}