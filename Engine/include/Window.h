#ifndef WINDOW_H_
#define WINDOW_H_

#include "Base.h"

namespace Engine
{
    class Entity;
    class Image;
};

using Engine::Entity;

namespace Engine
{
    class ENGAPI Window
    {
    public:
        virtual void AddEntity(Entity *sprt, unsigned int z_index) = 0;
        virtual const Rect &GetPosition() = 0;
        virtual const Vec2D &GetSize() = 0;
        virtual bool IsFullscreen() = 0;
        virtual char *GetTitle() = 0;
        virtual void Update() = 0;
        virtual void SetBasicFillColor(ColorComp r, ColorComp g, ColorComp b, ColorComp a = 255) = 0;
        virtual void SetBasicFillColor(Color &fill) = 0;

        // Drawing functions
        virtual void DrawImage(Image *img, const Rect &location) = 0;
        virtual void DrawRect(const Rect &location, bool fill_rect=false) = 0;
        virtual void DrawEllipse(const Rect &location) = 0;

        virtual void PushColor(Color *c) = 0;
        virtual void PopColor() = 0;

        static const Rect USE_CURRENT_RESOLUTION;

    protected:
        Window();
        virtual ~Window();
    };
}
#endif
