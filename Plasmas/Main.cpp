#include "Engine/Engine.h"
#include "Engine/_Errors.h"

#include <iostream>

using namespace Engine;

int main(int argc, char **argv)
{
	Graphics *gfx = Graphics::Get();

	gfx->Init();

	Window *main_win = gfx->NewWindow(Window::USE_CURRENT_RESOLUTION, "Title", true);

	gfx->Start();
	
	return 0;
}