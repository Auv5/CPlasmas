#pragma once
#include "Graphics.h"
namespace Engine {
	class SDLGraphics :
		public Graphics
	{
	public:
		SDLGraphics();
		~SDLGraphics();
	};
}