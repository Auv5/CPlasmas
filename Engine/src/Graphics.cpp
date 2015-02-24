#include "Graphics.h"
#include "_Selector.h"

namespace Engine
{
	Graphics::Graphics() : 
		quit(false)
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

	void Graphics::RequestQuit()
	{
		quit = true;
	}

	Graphics *Graphics::graphics = 0;
}
