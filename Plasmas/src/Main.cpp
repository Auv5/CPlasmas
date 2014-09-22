#include "Engine.h"
#include "_Errors.h"

#include <iostream>

using namespace Engine;

int main(int argc, char **argv)
{
	Graphics *gfx = Graphics::Get();

	gfx->Init();

	Rect res;

	res.w = 500;
	res.h = 500;
	
	Window *main_win = gfx->NewWindow(res, "Plasmas", true);

	gfx->Start();
	
	return 0;
}
