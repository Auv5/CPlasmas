#include "SDLGraphics.h"

#include <SDL.h>
#include "Base.h"
#include "SDLWindow.h"
#include "SubSystem.h"

using Engine::SDLGraphics;
using Engine::Window;
using Engine::SDLWindow;
using Engine::SubSystem;

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
	SDL_Init(SDL_INIT_VIDEO);
	initialized = true;
}

void SDLGraphics::Start()
{
	assert(default_window, "No default window was created. Cannot Start.");

	while (running) {
		for (std::pair<char *, SubSystem *> pair : subsystems) {
			pair.second->Update();
		}

		for (Window *w : windows) {
			w->Update();
		}
	}
}

Window *SDLGraphics::NewWindow(Rect& size, char *title, bool fullscreen)
{
	assert(initialized, "Did not initialize graphics before creating a new window.");

	SDLWindow *ret = new SDLWindow(size, title, fullscreen);

	if (!this->default_window) {
		this->default_window = ret;
	}

	windows.push_back(ret);

	return ret;
}

Window *SDLGraphics::NewWindow(float x, float y, char *title, bool fullscreen)
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