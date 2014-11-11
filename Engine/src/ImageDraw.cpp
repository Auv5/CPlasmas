#include "ImageDraw.h"

#include "Entity.h"
#include "Window.h"
#include "Image.h"

namespace Engine
{
    ImageDraw::ImageDraw(Entity *owner, char *file) :
        Component(owner),
        resource_name(file)
    {
        owner->AddGraphicalComponent(this);
        this->img = Image::Get(file);
    }

    void ImageDraw::Draw(Window *win)
    {
        // Draw the image object to the screen
        win->DrawImage(this->img, owner->GetPosition().ToRect(this->img->w, this->img->h));
    }

    ImageDraw::~ImageDraw()
    {
        delete this->img;
    }
}
