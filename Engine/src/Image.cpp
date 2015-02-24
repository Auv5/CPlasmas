#include "Image.h"
#include "_Selector.h"

namespace Engine
{
	Image::Image()
	{
	}


	Image::~Image()
	{
	}

	Image *Image::Get(const char *filename)
	{
		return SelectImg(filename);
	}
}
