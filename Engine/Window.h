#ifndef WINDOW_H_
#define WINDOW_H_

#include "Sprite.h"

class Window
{
public:
	void AddSprite(Sprite *sprt);

protected:
	Window();
	virtual ~Window();
};

#endif