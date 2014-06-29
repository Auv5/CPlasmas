#include "Entity.h"

#include "Base.h"

using Engine::Entity;

Entity::Entity(Rect postn, void *data) :
position(postn),
data(data)
{
}

Entity::Entity(Rect postn) :
position(postn),
data(0)
{
}


Entity::~Entity()
{
}
