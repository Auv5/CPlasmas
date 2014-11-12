#include "Base.h"
#include "Component.h"
#include "Entity.h"

namespace Engine
{
    Entity::Entity(Vec2D& postn) :
        Component(this)
    {
        InitializeEntity();

        position = &(*(&postn));

        this->AddGraphicalComponent(this);
        this->AddLogicalComponent(this);
    }

    Entity::Entity(double x, double y) :
        Component(this)
    {
        position = new Vec2D(x, y);

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

    void Entity::Draw(Window *win) {}

    void Entity::Update() {}

    void Entity::DrawEntity(Window *win)
    {
        for (Component *c : *graphicals) {
            c->Draw(win);
        }
    }

    void Entity::UpdateEntity()
    {
        for (Component *c : *logicals) {
            c->Update();
        }
    }

    Vec2D &Entity::GetPosition()
    {
        return *(this->position);
    }

    Entity::~Entity()
    {
    }
}
