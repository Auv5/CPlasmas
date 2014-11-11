#ifndef SDLIMAGE_H_
#define SDLIMAGE_H_

#include "Image.h"
#include "Base.h"

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Surface;

namespace Engine
{
    class SDLImage : public Image
    {
    public:
        SDLImage(char *filename);

        void DrawTo(SDL_Renderer *rend, const Rect &where);

    private:
        SDL_Texture *cached_texture;
        SDL_Renderer *assoc_renderer;
        SDL_Surface *surface;
        static bool initialized;
    };
}

#endif
