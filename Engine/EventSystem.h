#ifndef EVENT_SYSTEM_H_
#define EVENT_SYSTEM_H_

#include "SubSystem.h"

#include "Key.h"

namespace Engine
{
	class EventSystem : public SubSystem
	{
	public:
		EventSystem();
		~EventSystem();

		virtual char *GetName() = 0;

		virtual void Init() = 0;

		virtual void Update() = 0;

		void AddKeyHandler(Component *handler);

		void AddMouseHandler(Component *handler);

		static EventSystem *Get();

	private:
		static EventSystem *instance;
	};
};

#endif