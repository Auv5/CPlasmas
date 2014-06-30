#ifndef BASE_TYPES_H_
#define BASE_TYPES_H_

#ifdef SDL2
#include <SDL.h>
#endif

#include "_ExportUtil.h"

#define GfxRound(n) ((int)n)

struct ENGAPI Rect 
{
	Rect() :
		x(0),
		y(0),
		w(0),
		h(0)
	{ }

	Rect(double x, double y, double w, double h) :
		x(x),
		y(y),
		w(w),
		h(h)
	{ }

	// Platform specific constructors for conversion from platform-specific format...
#ifdef SDL2
	Rect(SDL_Rect &r) :
		x((double)(r.x)),
		y((double)(r.y)),
		w((double)(r.w)),
		h((double)(r.h))
	{ }

	SDL_Rect ToSDL()
	{
		//TODO: This implementation performs a copy... Can we stop that?
		SDL_Rect r;
		// When writing to the screen, we round using the GfxRound(x) macro
		r.x = GfxRound(this->x);
		r.y = GfxRound(this->y);
		r.w = GfxRound(this->w);
		r.h = GfxRound(this->h);

		return r;
	}
#else
#error No recognized graphics subsystem defined.
#endif

	double x, y;
	double w, h;
};

#ifdef SDL2
typedef Uint8 ColorComp;
#else
#error No graphics framework defined.
#endif

struct ENGAPI Color
{
	ColorComp r, g, b, a;
};

struct ENGAPI Vec2D 
{
	double x, y;
};

inline bool operator==(const Rect &left, const Rect &right)
{
	if (left.x == right.x && left.y == right.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif