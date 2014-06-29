#include "Engine/Engine.h"
#include "Engine/_Errors.h"

#include <iostream>

using namespace Engine;

int main(int argc, char **argv)
{
	Graphics *gfx = Graphics::Get();

	Rect rect;

	rect.w = 200;
	rect.h = 200;

	gfx->NewWindow(rect, "Title", false);

	gfx->Start();

	std::cin.get();
	
	return 0;
}