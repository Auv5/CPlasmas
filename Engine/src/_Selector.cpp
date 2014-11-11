#include "_Selector.h"

#ifdef SDL2

#include "SDLGraphics.h"

Engine::Graphics *SelectGfx()
{
    return new Engine::SDLGraphics;
}

#include "SDLEventsSystem.h"

Engine::EventSystem *SelectEvents()
{
    return new Engine::SDLEventsSystem;
}

#include "SDLImage.h"
Engine::Image *SelectImg(char *filename)
{
    return new Engine::SDLImage(filename);
}

// Add elif directives here if we want other gfx systems
#else
#error No graphics system defined.
#endif
