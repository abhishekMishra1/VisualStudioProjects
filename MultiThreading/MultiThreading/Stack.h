#pragma once
#include<vector>
#include<mutex>
using namespace std;

class MutexWrapper 
{
public:
	MutexWrapper()
	{
		m_lock.lock();
	}

	~MutexWrapper()
	{
		m_lock.unlock();
	}
private:
	std::mutex m_lock;
};

template<class T>
class Stack
{
public:
	Stack() 
	{
		m_Data.clear();
	}

	virtual ~Stack()
	{}
	
	T pop() 
	{
		T val;
		MutexWrapper locker;
		if (m_Data.size())
		{
			val = m_Data.front();
			m_Data.erase(m_Data.begin());
		}
		
		return val;
	}
	
	void push(T val) 
	{
		MutexWrapper locker;
		m_Data.push_back(val);
	}

	int getStackSize()
	{
		return m_Data.size();
	}

protected:
	std::vector<T> m_Data;
};

