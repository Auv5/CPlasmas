#ifndef COMPONENT_H_
#define COMPONENT_H_

enum Key;

namespace Engine
{
	class Entity;
};

using Engine::Entity;

namespace Engine
{
	class EXPORT Component
	{
	public:
		Component(Entity *e) : owner(e) {}
		virtual ~Component() {}

		// Events sent to 'logicals'
		virtual void Update() {}
		virtual void HandleKey(Key *k) {}

		// Sent to 'graphicals'
		virtual void Draw(Window *win) {}

	private:
		Entity *owner;
	};
};

#endif