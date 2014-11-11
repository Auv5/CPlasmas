#include "SDLWindow.h"
#include "_BaseTypes.h"
#include "_Errors.h"
#include "Entity.h"
#include "Image.h"

#include <SDL.h>
#include <iostream>

namespace Engine
{
	// Note: start can be any Rect if fullscreen = true
	SDLWindow::SDLWindow(const Rect& start, char *title, bool fullscreen) :
		fill(0, 0, 0, 255),
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

	const int DISPLAY_NUMBER = 0;

	void SDLWindow::Initialize()
	{
		assert(((start_location.w > 0 && start_location.h > 0) || start_location.w == start_location.h),
			"If a special resolution modifier is to be used, then both length and width must be equal.");

		if (start_location == USE_CURRENT_RESOLUTION)
		{
			SDL_DisplayMode display_mode;

			assert((SDL_GetCurrentDisplayMode(DISPLAY_NUMBER, &display_mode) == 0), SDL_GetError());

			start_location.w = (double)display_mode.w;
			start_location.h = (double)display_mode.h;
		}

		if (fullscreen)
		{
			SDL_CreateWindowAndRenderer(0, 0,
				(SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_BORDERLESS),
				&window, &write_to);
			// Scale so the user's code doesn't know the difference.
			SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
			SDL_RenderSetLogicalSize(write_to, GfxRound(start_location.w), GfxRound(start_location.h));
		}
		else
		{
			SDL_CreateWindowAndRenderer(GfxRound(start_location.w), GfxRound(start_location.h), 0, &window, &write_to);
		}

		SDL_SetWindowTitle(this->window, this->title);

		SDL_SetRenderDrawColor(write_to, fill.r, fill.g, fill.b, fill.a);
		SDL_RenderClear(write_to);
		SDL_RenderPresent(write_to);
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

		size.x = (double)w;
		size.y = (double)h;

		return size;
	}

	const Rect &SDLWindow::GetPosition()
	{
		int x, y, w, h;
		SDL_GetWindowPosition(window, &x, &y);
		SDL_GetWindowSize(window, &w, &h);

		position.x = (double)x;
		position.y = (double)y;
		position.w = (double)w;
		position.h = (double)h;
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

	Image *SDLWindow::GetImage(char *filename)
	{
		// TODO: Implement.
		return NULL;
	}

	void SDLWindow::Update()
	{
		std::cout << "Drawing window" << std::endl;
		// Perform logic update (by z-index)
		for (std::vector<Entity*> v : entities)
		{
			for (Entity *e : v)
			{
				e->UpdateEntity();
			}
		}

		// Perform graphics draw (by z-index)
		for (std::vector<Entity*> v : entities)
		{
			for (Entity *e : v)
			{
				e->DrawEntity(this);
			}
		}

		SDL_SetRenderDrawColor(write_to, fill.r, fill.g, fill.b, fill.a);
		SDL_RenderClear(write_to);
		SDL_RenderPresent(write_to);
	}
>>>>>>> b8e663b01b12a92499c6eb3db72fd9cce11a701c
}
