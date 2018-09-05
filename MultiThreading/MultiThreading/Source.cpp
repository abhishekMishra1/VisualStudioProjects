#include<thread>
#include<iostream>
#include<string>
#include<filesystem>
#include<string>
#include "Stack.h"
#include "MyDataTypes.h"
#include<experimental\filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

int main()
{
	string path("D");
	for (auto & p : fs::directory_iterator(path))
		cout << p << endl;
	system("PAUSE");
	return 0;
}









namespace StackMultiThreading {

	Stack<Integer> myStack;

	void consumer()
	{
		int val = myStack.pop();
		cout << "I consumed this " << val << endl;
	}

	void producer(int i)
	{
		myStack.push(i);
		cout << "I produced this " << i << endl;
	}

	void test1()
	{
//		thread t1(producer);
//		thread t2(consumer);
		for (int i = 1; i <= 10; ++i)
		{

		}
//		t1.join();
//		t2.join();

	}
}

