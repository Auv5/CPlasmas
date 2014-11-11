#ifndef EVENT_SYSTEM_H_
#define EVENT_SYSTEM_H_

#include "SubSystem.h"
#include "Key.h"

#include <vector>

namespace Engine
{
    class Component;

    class EventSystem : public SubSystem
    {
    public:
        EventSystem();
        ~EventSystem();

        virtual const char *GetName() = 0;

        virtual void Init() = 0;

        virtual void Update() = 0;

        void AddKeyHandler(Component *handler);

        void AddMouseHandler(Component *handler);

        static EventSystem *Get();

    protected:
        std::vector<Component*> key_handlers;
        std::vector<Component*> mouse_handlers;

    private:
        static EventSystem *instance;
    };
}

#endif
