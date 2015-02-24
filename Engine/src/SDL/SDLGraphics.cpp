#include "SDL/SDLGraphics.h"

#include "Base.h"
#include "SDL/SDLWindow.h"
#include "SubSystem.h"
#include "EventSystem.h"

#include <cstring>
#include <cstdlib>

namespace Engine
{
	SDLGraphics::SDLGraphics() :
		initialized(false)
	{
	}


	SDLGraphics::~SDLGraphics()
	{
	}

	const char *SDLGraphics::GetIdentifier()
	{
		return identifier;
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
			// Give all the subsystems a chance to update...
			for (std::pair<const char *, SubSystem *> pair : subsystems) {
				pair.second->Update();
			}

			for (Window *w : windows) {
				w->Update();
			}
		}

		SDL_Quit();
	}

	Window *SDLGraphics::NewWindow(const Rect& size, const char *title, bool fullscreen)
	{
		assert(initialized, "Did not initialize graphics before creating a new window.");

		// sizeof(char) == 1 on all systems
		char *titleCopy = (char*)std::malloc(std::strlen(title) + 1);

		std::strcpy(titleCopy, title);

		SDLWindow *ret = new SDLWindow(size, titleCopy, fullscreen);

		if (!this->default_window) {
			this->default_window = ret;
		}

		windows.push_back(ret);

		return ret;
	}

	Window *SDLGraphics::NewWindow(double x, double y, const char *title, bool fullscreen)
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

	const char *SDLGraphics::identifier = "SDL Graphics Backend";
}

