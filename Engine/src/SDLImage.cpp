#include "SDLImage.h"
#include "SDLGraphics.h"
#include "Base.h"

#include <SDL2/SDL_image.h>

namespace Engine
{
    SDLImage::SDLImage(char *filename)
    {
        if (!initialized) {
            // Currently we support only two types of image, JPG and PNG (in addition to BMP natively supported by SDL)
            IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
			
            initialized = true;
        }

        this->surface = IMG_Load(filename);

        assert(surface, "Cannot find file %s", filename);
    }

    SDLImage::~SDLImage()
    {
    }

    void SDLImage::DrawTo(SDL_Renderer *rend, const Rect &where)
    {
        // Simple caching mech to get around textuers being associated with Windows
        if (rend != this->assoc_renderer) {
            cached_texture = SDL_CreateTextureFromSurface(rend, this->surface);
            assoc_renderer = rend;
        }
		
        // Currently we don't support source rects
        SDL_RenderCopy(rend, this->cached_texture, NULL, where.ToSDL());
    }

    const Vec2D *SDLImage::GetSize()
    {
        return new Vec2D(this->surface->w, this->surface->h);
    }

    int SDLImage::GetWidth()
    {
        return this->surface->w;
    }

    int SDLImage::GetHeight()
    {
        return this->surface->h;
    }

    bool SDLImage::initialized = false;
}
