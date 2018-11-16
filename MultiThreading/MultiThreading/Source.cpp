#include<thread>
#include<iostream>
#include<string>
#include<vector>
#include<mutex>

using namespace std;

__declspec(naked) unsigned get_current_proc()
{
	__asm
	{
		mov ecx, 03Bh
		lsl eax, ecx
		shr eax, 0Eh
		retn
	}
}

int main()
{
	const int nThreads = thread::hardware_concurrency();
	vector<thread> vThreads(nThreads*2);
	mutex lock;
	for (unsigned int t = 0; t < nThreads*2; ++t)
	{
		vThreads[t] = thread([&lock, t]{
		//	while (1)
			{
				{
					lock_guard<mutex> iolock(lock);
					cout << "Thread #" << t << ": on CPU " << get_current_proc() << endl;
				}

				//make your thread sleep for a while
			//	cout << "\n\n";
				this_thread::sleep_for(chrono::milliseconds(900));
			}
		});
	}

	for (auto& i : vThreads)
		i.join();

	return 0;
}







