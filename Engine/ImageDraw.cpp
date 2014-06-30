#include "ImageDraw.h"

#include "Entity.h"
#include "Window.h"

using Engine::ImageDraw;
using Engine::Component;
using Engine::Window;

ImageDraw::ImageDraw(Entity *owner, char *file) :
Component(owner),
resource_name(file)
{
	owner->AddGraphicalComponent(this);
	// TODO initialize the image object
}

void ImageDraw::Draw(Window *win)
{
	// Draw the image object to the screen
}

ImageDraw::~ImageDraw()
{
}
