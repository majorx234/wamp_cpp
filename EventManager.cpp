#include "EventManager.h"

using namespace std;

EventManager::EventManager()
{
	running = true;
	eventThread = std::thread(&EventManager::eventLoop,this);
}

EventManager::~EventManager()
{
	running = false;
	eventThread.join();
}

bool FunctionComparator::operator()(const EventHandler& a, const EventHandler& b) const
{
  return a.target<void(string,Json::Value)>() < b.target<void(string,Json::Value)>();
}

void EventManager::subscribe(string uri, EventHandler handler)
{
	subscriptions[uri].insert(handler);
}

EventManager& EventManager::getInstance()
{
	static EventManager eventManager;
	return eventManager;
}
	
void EventManager::publish(std::string uri, Json::Value payload)
{
	// TODO locking
	auto ehSet = subscriptions.find(uri);
	
	// has someone subscribed to this event?
	if(ehSet != subscriptions.end())
	{
		for(auto eh : (*ehSet).second)
		{
			eh(uri,payload);
		}
	}
}

void EventManager::pushTopic(AbstractTopic* topic)
{
    	unique_lock<mutex> l(lock);
	pendingTopics.push(topic);
	notEmpty.notify_one();
}

void EventManager::eventLoop()
{
    	unique_lock<mutex> l(lock);

	while(running)
	{
		while(!pendingTopics.empty())
		{
			AbstractTopic* topic = pendingTopics.front();
			pendingTopics.pop();
			l.unlock();

			string uri = topic->getURI();
			cout << uri << endl;
			Json::Value payload = topic->getPayload();
			publish(uri,payload);
			l.lock();
		}

    		notEmpty.wait_for(l, chrono::milliseconds(500));
	}
}

