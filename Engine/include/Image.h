#ifndef IMAGE_H_
#define IMAGE_H_

struct Vec2D;

namespace Engine
{
    class Image
    {
    public:
        Image();
        virtual ~Image();
        static Image *Get(char *filename);

        virtual const Vec2D *GetSize() = 0;
        virtual int GetWidth() = 0;
        virtual int GetHeight() = 0;
    };
}

#endif
