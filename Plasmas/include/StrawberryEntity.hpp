#ifndef STRAWBERRY_H_
#define STRAWBERRY_H_

#include "Engine.h"

class StrawberryEntity :
    public Engine::Entity
{
public:
    StrawberryEntity();
    virtual ~StrawberryEntity();

    virtual void Draw(Engine::Window *win);
private:
    const char *filename = "one.png";
};

#endif
