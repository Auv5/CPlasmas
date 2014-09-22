#include "EventSystem.h"
#include "_Selector.h"

namespace Engine
{
	EventSystem::EventSystem()
	{
	}


	EventSystem::~EventSystem()
	{
	}

	EventSystem *EventSystem::Get()
	{
		if (instance) {
			return instance;
		}
		else {
			return instance = SelectEvents();
		}
	}

	EventSystem *EventSystem::instance = 0;

	void EventSystem::AddKeyHandler(Component *comp)
	{
		key_handlers.push_back(comp);
	}

	void EventSystem::AddMouseHandler(Component *comp)
	{
		key_handlers.push_back(comp);
	}
}