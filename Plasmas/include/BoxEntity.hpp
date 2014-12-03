#ifndef BOX_H_
#define BOX_H_

#include "Engine.h"

class BoxEntity :
	public Engine::Entity
{
public:
	BoxEntity();
	virtual ~BoxEntity();

        virtual void Draw(Engine::Window *win);
private:
        Color *color;
};

#endif
