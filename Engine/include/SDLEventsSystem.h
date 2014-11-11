#ifndef SDLEVENTS_H_
#define SDLEVENTS_H_

#include "EventSystem.h"

namespace Engine
{
    class SDLEventsSystem : public EventSystem
    {
    public:
        SDLEventsSystem();
        ~SDLEventsSystem();

        virtual const char *GetName();
        virtual void Init();
        virtual void Update();

    private:
        Keymod mod_map;
        SDL_Event current_event;
    };
}

#endif
