#ifndef BASE_TYPES_H_
#define BASE_TYPES_H_

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

    SDL_Rect *ToSDL() const
    {
        SDL_Rect *r = new SDL_Rect();
        // When writing to the screen, we round using the GfxRound(x) macro
        r->x = GfxRound(this->x);
        r->y = GfxRound(this->y);
        r->w = GfxRound(this->w);
        r->h = GfxRound(this->h);

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
    Color(int r, int g, int b, int a=255)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
  
    ColorComp r, g, b, a;
};

struct ENGAPI Vec2D 
{
public:
    double x, y;

    const Rect *ToRect(double w, double h) const {
        if (!cache_rect || cache_rect->x != this->x || cache_rect->y != this->y) {
            cache_rect = new Rect(x, y, w, h);
        }

        cache_rect->w = w;
        cache_rect->h = h;

        return cache_rect;
    }

    Vec2D() {
        this->x = 0;
        this->y = 0;
    }

    Vec2D(double x, double y) {
        this->x = x;
        this->y = y;
    }
    
    ~Vec2D() {
        if (cache_rect) {
            delete cache_rect;
        }
    }

private:
    // Mutable because it's simply for caching
    mutable Rect *cache_rect = 0;
};

inline bool operator==(const Rect &left, const Rect &right)
{
    if (left.x == right.x && left.y == right.y && left.w == right.w && left.h == right.h)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif
