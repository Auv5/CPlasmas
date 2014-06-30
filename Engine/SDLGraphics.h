#ifndef SDL_GFX_H_
#define SDL_GFX_H_

#include "Graphics.h"
#include <vector>
#include <map>

struct Vec2D;

namespace Engine {
	class Window;
	class SubSystem;

	class SDLGraphics :
		public Graphics
	{
	public:
		SDLGraphics();
		~SDLGraphics();

		virtual char *GetIdentifier();
		virtual void Init();

		virtual Window *NewWindow(const Rect& size, char *title, bool fullscreen);
		virtual Window *NewWindow(double x, double y, char *title, bool fullscreen);

		virtual void AddSubSystem(SubSystem *system);

		virtual void Start();

		virtual Window *GetDefaultWindow();

	private:
		bool initialized;
		Window *default_window;

		std::vector<Window *> windows;
		std::map<char *, SubSystem *> subsystems;
	};
}

#endif