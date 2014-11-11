#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "Key.h"
#include "_ExportUtil.h"

namespace Engine
{
    class Entity;
    class Window;

    class ENGAPI Component
    {
    public:
    Component(Entity *e) : owner(e) {}
        virtual ~Component() {}

        // Events sent to 'logicals'
        virtual void Update() {}
        virtual void KeyDown(Key k) {}
        virtual void KeyUp(Key k) {}

        // Sent to 'graphicals'
        virtual void Draw(Window *win) {}

    protected:
        Entity *owner;
    };
}

#endif
