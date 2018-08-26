#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>
#include <vector>

namespace ThreadWithMutex{
	std::mutex display_mutex;
	typedef std::chrono::time_point<std::chrono::high_resolution_clock> timepoint;
	void worker()
	{
		std::thread::id this_id = std::this_thread::get_id();
		display_mutex.lock();
		std::cout << "thread " << this_id << "sleeping...\n";
		display_mutex.unlock();

		timepoint start = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		timepoint end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> elapsed = end - start;
		display_mutex.lock();
		std::cout << "thread slept for exactly " << elapsed.count() << " ms\n";
		display_mutex.unlock();


	}

	void test()
	{
		std::thread t1(worker);
		std::thread::id t1_id = t1.get_id();

		std::thread t2(worker);
		std::thread::id t2_id = t2.get_id();

		display_mutex.lock();
		std::cout << "t1's id " << t1_id << "\n";
		std::cout << "t2's id " << t2_id << "\n";
		display_mutex.unlock();

	}
}


namespace FifoUsage
{
	std::queue<int> jobQueue;

	void consumer()
	{	
		if (jobQueue.empty())
		{
			std::cout << "Tried to consumer before produced" << std::endl;
			return;
		}

		std::cout<<"Consuming the job " << jobQueue.front() <<std::endl;
		jobQueue.pop();
	}

	void producer(int i)
	{
		std::cout << "Producing the job " << i << std::endl;
		jobQueue.push(i);
	}

	void test()
	{
		
		for (int i = 1; i <= 5; ++i)
		{
			std::thread tConsumer(consumer);
			tConsumer.join();
			std::thread tProducer(producer, i);
			std::cout << "\nHardware cores are " << tProducer.hardware_concurrency() << " Producer thread id is "<< tProducer.get_id() << std::endl;
			tProducer.join();
		}
	}
}