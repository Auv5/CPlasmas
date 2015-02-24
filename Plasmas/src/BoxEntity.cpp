#include "BoxEntity.hpp"
#include "Engine.h"
#include <iostream>

BoxEntity::BoxEntity() :
Entity(200.0, 200.0)
{
	this->color = new Color(255, 0, 0);
}

BoxEntity::~BoxEntity()
{
	delete this->color;
}


void BoxEntity::Draw(Engine::Window *win)
{
	win->PushColor(this->color);
	win->DrawEllipse(*(this->GetPosition().ToRect(100, 100)));
	win->PopColor();
}
