#include "EventSystem.h"
#include "_Selector.h"

using Engine::EventSystem;

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
