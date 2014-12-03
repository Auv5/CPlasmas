#include "StrawberryEntity.hpp"
#include "Engine.h"
#include "ImageDraw.h"
#include <iostream>

StrawberryEntity::StrawberryEntity() : 
    Entity(500.0, 500.0)
{
    // Creates a new ImageDraw component and adds it to this entity
    new Engine::ImageDraw(this, filename);
}

StrawberryEntity::~StrawberryEntity()
{
}


void StrawberryEntity::Draw(Engine::Window *win)
{
}
