#pragma once
#include <string>
#include <thread>
#include <chrono>

namespace SaveTheKingdom
{
	using namespace std;
	enum EventType
	{
		TIMER,
		CONSOLE_INPUT
	};


	class EventManager
	{
	public:
		void FireEvent() {}
	};

	struct EventObject
	{
		EventObject(EventType eve, string eventName)
			:m_EventCategory(eve)
			, m_EventName(eventName)
		{}

		virtual ~EventObject() {}

		static void EventOccurred(string eventName) {}

		EventObject() = delete;
		EventObject(const EventObject&) = delete;
		EventObject& operator=(const EventObject&) = delete;
		EventType m_EventCategory;
		string m_EventName;
	};
	
	void fireTimer(chrono::milliseconds duration, string eventName) 
	{ 
		while (1)
		{
			EventObject::EventOccurred(eventName);
			this_thread::sleep_for(duration);
		}
	}

	struct TimerEvent :public EventObject
	{
		TimerEvent(string name, chrono::milliseconds duration) :
			EventObject(TIMER, name)
			, m_TimerExpiration(duration)
		{}

		void startTimer()
		{
			thread t(fireTimer, m_TimerExpiration, m_EventName);
		}
	private:
		chrono::milliseconds m_TimerExpiration;
		friend void fireTimer(chrono::milliseconds duration, string evenName);
	};

	struct ConsoleInput :public EventObject
	{
		ConsoleInput() {}

		void readConsole()
		{
			thread t(fireTimer, 50ms);
		}
	};
}