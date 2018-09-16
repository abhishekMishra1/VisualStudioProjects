#pragma once
#include<queue>
#include<string>
#include<mutex>

using namespace std;
namespace MessagePosting {
	class MessageHandler
	{
	public:
		static MessageHandler* getInstance()
		{
			if (!m_pMessageProcessor)
			{
				m_pMessageProcessor = new MessageHandler;
			}

			return m_pMessageProcessor;
		}

		void PushMessage(const string& msg)
		{
			std::lock_guard<std::mutex> locker(m_lock);
			m_MessageQueue.push(msg);
		}

		string RetrieveMsg()
		{
			string message("");
			std::lock_guard<std::mutex> locker(m_lock);
			if (m_MessageQueue.size())
			{
				message = m_MessageQueue.front();
				m_MessageQueue.pop();
			}
			return message;
		}

	private:
		MessageHandler() {}
		~MessageHandler() {}
		MessageHandler(const MessageHandler&) {}

		static MessageHandler* m_pMessageProcessor;
		queue<string> m_MessageQueue;
		std::mutex m_lock;
	};


	inline void SendNotification(const string msg)
	{
		MessageHandler::getInstance()->PushMessage(msg);
	}

	inline string GetNotification()
	{
		return MessageHandler::getInstance()->RetrieveMsg();
	}

};

//MessagePosting::MessageHandler* MessagePosting::MessageHandler::m_pMessageProcessor = nullptr;

