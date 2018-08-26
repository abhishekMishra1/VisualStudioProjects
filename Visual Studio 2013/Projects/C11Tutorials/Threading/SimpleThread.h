#include <thread>
#include <string>
#include <utility>

void worker()
{

}

void worker1(int n, std::string str)
{
}

int test1()
{
	//std::thread t(worker);

	std::string st = "Test";
	std::thread t1(worker1, 10, st);
	std::thread t2(std::move(t1));
	t2.join();
	//t.join();
	//t2.join();

	system("PAUSE");
	return 0;
}