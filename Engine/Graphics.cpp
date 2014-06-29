#include "Graphics.h"
#include "_Selector.h"

using Engine::Graphics;

Graphics::Graphics()
{
}

Graphics *Graphics::Get() 
{
	if (graphics) {
		return graphics;
	}
	else {
		return graphics = SelectGfx();
	}
}

Graphics::~Graphics()
{
}

Graphics *Graphics::graphics = 0;