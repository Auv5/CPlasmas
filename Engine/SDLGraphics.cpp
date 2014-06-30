#include "SDLGraphics.h"

#include <SDL.h>
#include "Base.h"
#include "SDLWindow.h"
#include "SubSystem.h"
#include "EventSystem.h"

namespace Engine
{
	SDLGraphics::SDLGraphics() :
		initialized(false)
	{
	}


	SDLGraphics::~SDLGraphics()
	{
	}

	char *SDLGraphics::GetIdentifier()
	{
		return "SDL Graphics Backend";
	}

	void SDLGraphics::Init()
	{
		assert((SDL_Init(SDL_INIT_VIDEO) == 0), SDL_GetError());
		// We'll let the system find out which input system to use...
		this->AddSubSystem(EventSystem::Get());

		initialized = true;
	}

	void SDLGraphics::Start()
	{
		assert(default_window, "No default window was created. Cannot Start.");

		while (!quit) {
			for (std::pair<char *, SubSystem *> pair : subsystems) {
				pair.second->Update();
			}

			for (Window *w : windows) {
				w->Update();
			}
		}

		SDL_Quit();
	}

	Window *SDLGraphics::NewWindow(const Rect& size, char *title, bool fullscreen)
	{
		assert(initialized, "Did not initialize graphics before creating a new window.");

		SDLWindow *ret = new SDLWindow(size, title, fullscreen);

		if (!this->default_window) {
			this->default_window = ret;
		}

		windows.push_back(ret);

		return ret;
	}

	Window *SDLGraphics::NewWindow(double x, double y, char *title, bool fullscreen)
	{
		Rect size;
		size.w = x;
		size.h = y;

		return this->NewWindow(size, title, fullscreen);
	}

	Window *SDLGraphics::GetDefaultWindow()
	{
		return default_window;
	}

	void SDLGraphics::AddSubSystem(SubSystem *system)
	{
		system->Init();
		subsystems[system->GetName()] = system;
	}
}