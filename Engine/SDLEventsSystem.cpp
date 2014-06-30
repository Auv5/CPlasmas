#include "SDLEventsSystem.h"

#include "Graphics.h"
#include "Component.h"

#include "_Errors.h"

namespace Engine
{
	SDLEventsSystem::SDLEventsSystem()
	{
	}


	SDLEventsSystem::~SDLEventsSystem()
	{
	}

	char *SDLEventsSystem::GetName()
	{
		return "SDL Events Subsystem";
	}

	void SDLEventsSystem::Init()
	{
		assert((SDL_Init(SDL_INIT_EVENTS) == 0), SDL_GetError());

		// They're the same type with non-SDL specific names.
		mod_map = (Keymod)SDL_GetModState();
	}

	void SDLEventsSystem::Update()
	{
		mod_map = (Keymod)SDL_GetModState();

		while (SDL_PollEvent(&current_event)) {
			if (current_event.type == SDL_QUIT || current_event.type == SDL_WINDOWEVENT_CLOSE) {
				// Request the game be closed at the end of this loop...
				Graphics::Get()->RequestQuit();
			}
			else if (current_event.type == SDL_KEYDOWN) {
				for (Component *c : key_handlers) {
					c->KeyDown((Key)(current_event.key.keysym.sym));
				}
			}
			else if (current_event.type == SDL_KEYUP) {
				for (Component *c : key_handlers) {
					c->KeyUp((Key)(current_event.key.keysym.sym));
				}
			}
		}
	}
}