#include "_Selector.h"

#ifdef SDL2

#include "SDLGraphics.h"

using Engine::Graphics;

Engine::Graphics *SelectGfx()
{
	return new Engine::SDLGraphics;
}

#include "SDLEventsSystem.h"

Engine::EventSystem *SelectEvents()
{
	return new Engine::SDLEventsSystem;
}

// Add elif directives here if we want other gfx systems
#else
#error No graphics system defined.
#endif