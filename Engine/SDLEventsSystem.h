#ifndef SDLEVENTS_H_
#define SDLEVENTS_H_

#include "EventSystem.h"

namespace Engine
{
	class SDLEventsSystem : public EventSystem
	{
	public:
		SDLEventsSystem();
		~SDLEventsSystem();

		virtual char *GetIdentifier();


	};
};

#endif