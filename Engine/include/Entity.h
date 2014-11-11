#ifndef ENTITY_H_
#define ENTITY_H_

#include "_BaseTypes.h"
#include "Window.h"
#include "Component.h"

#include <vector>

namespace Engine {
    class ENGAPI Entity : public Component
    {
    public:
        Entity(Vec2D& position);
        Entity(double x, double y);

        virtual ~Entity();

        void DrawEntity(Window *win);
        void UpdateEntity();

        virtual void Draw(Window *win);
        virtual void Update();

        void AddLogicalComponent(Component *comp);
        void AddGraphicalComponent(Component *comp);

        Vec2D &GetPosition();

    private:
        Vec2D position;

        std::vector<Component*> *graphicals;
        std::vector<Component*> *logicals;

        void InitializeEntity();
    };
}

#endif
