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
		Entity(Vec2D& position);
		Entity(double x, double y);

		virtual ~Entity();
		const Vec2D &GetPosition();

		void DrawEntity(Window *win);
		void UpdateEntity();

		virtual void Draw(Window *win) = 0;
		virtual void Update() = 0;

		void AddLogicalComponent(Component *comp);
		void AddGraphicalComponent(Component *comp);

	private:
		Vec2D position;

		std::vector<Component*> *graphicals;
		std::vector<Component*> *logicals;

		void InitializeEntity();
	};
};

#endif