#include "_Selector.h"

#ifdef SDL2

#include "SDLGraphics.h"

using Engine::Graphics;

Engine::Graphics *SelectGfx()
{
	return new Engine::SDLGraphics;
}

// Add elif directives here if we want other gfx systems
#else
#error No graphics system defined.
#endif