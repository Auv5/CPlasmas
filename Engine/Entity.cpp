#include "Entity.h"

#include "Base.h"
#include "Component.h"

using Engine::Entity;
using Engine::Component;

Entity::Entity(Vec2D& postn) :
Component(this),
position(postn)
{
	InitializeEntity();
}

Entity::Entity(double x, double y) : 
Component(this)
{
	position.x = x;
	position.y = y;

	InitializeEntity();
}

void Entity::InitializeEntity()
{
	graphicals = new std::vector<Component*>();
	logicals = new std::vector<Component*>();
}

void Entity::AddGraphicalComponent(Component *comp)
{
	graphicals->push_back(comp);
}

void Entity::AddLogicalComponent(Component *comp)
{
	logicals->push_back(comp);
}

Entity::~Entity()
{
}
