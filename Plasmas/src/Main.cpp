#include "Engine.h"
#include "BoxEntity.hpp"
#include "StrawberryEntity.hpp"

#include <iostream>

using namespace Engine;

int main(int argc, char **argv)
{
	Graphics *gfx = Graphics::Get();

	gfx->Init();

	Rect res;

	res.w = 1000;
	res.h = 1000;

	Window *main_win = gfx->NewWindow(res, "Plasmas", false);

	BoxEntity *box = new BoxEntity();
	StrawberryEntity *strawberry = new StrawberryEntity();

	main_win->AddEntity(box, 0);
	main_win->AddEntity(strawberry, 0);

	gfx->Start();

	return 0;
}
