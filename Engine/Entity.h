#ifndef ENTITY_H_
#define ENTITY_H_

#include "_BaseTypes.h"
#include "Window.h"
#include "Component.h"

#include <vector>

namespace Engine {
	class EXPORT Entity : Component
	{
	public:
		Entity(Vec2D position);
		Entity(int x, int y);

		virtual ~Entity();
		const Rect &GetPosition();

		void DrawEntity(Window *win);
		void UpdateEntity();

		virtual void Draw(Window *win) = 0;
		virtual void Update() = 0;

	private:
		Rect position;

		std::vector<Component*> *graphicals;
		std::vector<Component*> *logicals;
	};
};

#endif