#include "SDL/SDLWindow.h"
#include "SDL/SDLImage.h"
#include "Base.h"
#include "Entity.h"
#include "Image.h"
#include <iostream>
#include <cmath>

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

	void SDLWindow::DrawImage(Image *image, const Rect &location)
	{
		((SDLImage*)image)->DrawTo(this->write_to, location);
	}

	void SDLWindow::PushColor(Color *c)
	{
		if (c) {
			SDL_SetRenderDrawColor(this->write_to, c->r, c->g, c->b, c->a);
		}
		else {
			// This is also the background color (by default) so they should probably pass in a color
			SDL_SetRenderDrawColor(this->write_to, fill.r, fill.g, fill.b, fill.a);
		}
	}

	void SDLWindow::PopColor()
	{
		// This is also the background color (by default) so they should probably pass in a color
		SDL_SetRenderDrawColor(this->write_to, fill.r, fill.g, fill.b, fill.a);
	}

	void SDLWindow::DrawRect(const Rect &rect, bool fill_rect)
	{
		SDL_Rect *t_rect = rect.ToSDL();

		SDL_RenderDrawRect(this->write_to, t_rect);

		if (fill_rect) {
			SDL_RenderFillRect(this->write_to, t_rect);
		}

		delete t_rect;
	}

	void SDLWindow::DrawEllipse(const Rect &rect)
	{
		// This is how often points will be drawn
		const static double granularity = 0.001;
		// We roll our own ellipse...
		double angle = 0;
		int x = rect.x, y = rect.y, w = rect.w, h = rect.h;
		while (angle <= M_PI * 2) {
			SDL_RenderDrawPoint(this->write_to, x + (w*cos(angle)), y + (h*sin(angle)));
			angle += granularity;
		}
	}

	void SDLWindow::Update()
	{
		SDL_SetRenderDrawColor(write_to, fill.r, fill.g, fill.b, fill.a);
		SDL_RenderClear(write_to);

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

		SDL_RenderPresent(write_to);
	}
}
