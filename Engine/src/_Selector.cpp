#include "_Selector.h"

#ifdef SDL2

#include "SDL/SDLGraphics.h"

Engine::Graphics *SelectGfx()
{
    return new Engine::SDLGraphics;
}

#include "SDL/SDLEventsSystem.h"

Engine::EventSystem *SelectEvents()
{
    return new Engine::SDLEventsSystem;
}

#include "SDL/SDLImage.h"
Engine::Image *SelectImg(const char *filename)
{
    return new Engine::SDLImage(filename);
}

// Add elif directives here if we want other gfx systems
#else
#error No graphics system defined.
#endif
