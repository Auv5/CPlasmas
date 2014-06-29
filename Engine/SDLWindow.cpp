#include "SDLWindow.h"
#include "_BaseTypes.h"
#include "Entity.h"

#include <SDL.h>

using Engine::SDLWindow;
using Engine::Entity;

// Note: start can be any Rect if fullscreen = true
SDLWindow::SDLWindow(Rect& start, char *title, bool fullscreen) : 
entities(3)
{
	// Copies the size vector...
	this->start_location = start;
	this->fullscreen = fullscreen;
	this->title = title;

	Initialize();
}

SDLWindow::~SDLWindow() 
{
	for (std::vector<Entity*> v : entities) {
		for (Entity *e : v) {
			if (e) {
				delete e;
			}
		}
	}
}

void SDLWindow::Initialize()
{
	if (fullscreen)
	{
		SDL_CreateWindowAndRenderer(0, 0,
			(SDL_WINDOW_FULLSCREEN | SDL_WINDOW_BORDERLESS),
			&window, &write_to);
		// Scale so the user's code doesn't know the difference.
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
		SDL_RenderSetLogicalSize(write_to, GfxRound(start_location.w), GfxRound(start_location.h));
	}
	else
	{
		SDL_CreateWindowAndRenderer(GfxRound(start_location.w), GfxRound(start_location.h), 0, &window, &write_to);
	}

	SDL_SetRenderDrawColor(write_to, fill.r, fill.g, fill.b, fill.a);
	SDL_RenderClear(write_to);
	SDL_RenderPresent(write_to);

	// ... Continue SDL window initialization to the point where we can write to it in the DrawSprites method.
}

bool SDLWindow::IsFullscreen() 
{
	return fullscreen;
}

void SDLWindow::AddEntity(Entity *sprt, unsigned int z_index)
{
	if (entities.size() < z_index) {
		entities.resize(z_index + 1);
	}

	entities[z_index].push_back(sprt);
}

char *SDLWindow::GetTitle()
{
	return title;
}

const Vec2D &SDLWindow::GetSize() 
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	size.x = (float)w;
	size.y = (float)h;

	return size;
}

const Rect &SDLWindow::GetPosition()
{
	int x, y, w, h;
	SDL_GetWindowPosition(window, &x, &y);
	SDL_GetWindowSize(window, &w, &h);

	position.x = (float)x;
	position.y = (float)y;
	position.w = (float)w;
	position.h = (float)h;
	return this->start_location;
}

void SDLWindow::SetBasicFillColor(ColorComp r, ColorComp g, ColorComp b, ColorComp a)
{
	fill = { r, g, b, a };
}

void SDLWindow::SetBasicFillColor(Color &fill)
{
	this->fill = fill;
}

void SDLWindow::Update()
{
	// Perform logic update (by z-index)
	for (std::vector<Entity*> v : entities)
	{
		for (Entity *e : v)
		{
			e->Update();
		}
	}

	// Perform graphics draw (by z-index)
	for (std::vector<Entity*> v : entities)
	{
		for (Entity *e : v)
		{
			e->Draw(this);
		}
	}

	SDL_SetRenderDrawColor(write_to, fill.r, fill.g, fill.b, fill.a);
	SDL_RenderClear(write_to);
	SDL_RenderPresent(write_to);
}