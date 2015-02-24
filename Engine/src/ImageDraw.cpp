#include "ImageDraw.h"

#include "Entity.h"
#include "Window.h"
#include "Image.h"

namespace Engine
{
	ImageDraw::ImageDraw(Entity *owner, const char *file) :
		Component(owner),
		resource_name(file)
	{
		owner->AddGraphicalComponent(this);
		this->img = Image::Get(file);
	}

	void ImageDraw::Draw(Window *win)
	{
		const Rect *newRect = owner->GetPosition().ToRect(this->img->GetWidth(), this->img->GetHeight());
		// Draw the image object to the screen
		win->DrawImage(this->img, *newRect);
	}

	ImageDraw::~ImageDraw()
	{
		delete this->img;
	}
}
