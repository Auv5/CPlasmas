#ifndef IMAGE_DRAW_H_
#define IMAGE_DRAW_H_

#include "Component.h"

namespace Engine
{
	class Window;
	class Entity;
};

namespace Engine
{
	class ImageDraw :
		public Engine::Component
	{
	public:
		ImageDraw(Entity *owner, char *file);
		virtual ~ImageDraw();
		virtual void Draw(Window *win);

	private:
		char *resource_name;
	};
}

#endif