#ifndef SDL_WINDOW_H_
#define SDL_WINDOW_H_

#include "Window.h"
#include "Base.h"

#include <vector>

namespace Engine
{
    class SDLWindow : public Window
    {
    public:
        SDLWindow(const Rect& size, char *title, bool fullscreen);
        virtual ~SDLWindow();

        virtual void AddEntity(Entity *sprt, unsigned int z_index);
        virtual const Rect &GetPosition();
        virtual const Vec2D &GetSize();
        virtual bool IsFullscreen();
        virtual char *GetTitle();
        virtual void Update();
        virtual void SetBasicFillColor(ColorComp r, ColorComp g, ColorComp b, ColorComp a = 255);
        virtual void SetBasicFillColor(Color& c);

        // Sets the current color of the engine's drawing functions
        void PushColor(Color *c);
        virtual void PopColor();
        
        // Drawing functions - assume that all (thing)* are SDL(thing)*
        virtual void DrawImage(Image *img, const Rect &location);
        virtual void DrawRect(const Rect &location, bool fill_rect=false);
        virtual void DrawEllipse(const Rect &location);

    private:
        void Initialize();

        SDL_Window *window;
        SDL_Renderer *write_to;

        Rect start_location;
        Rect position;
        Vec2D size;
        char *title;
        bool fullscreen;

        Color fill;

        int counter = 0;

        std::vector< std::vector<Entity*> > entities;
    };
}

#endif
