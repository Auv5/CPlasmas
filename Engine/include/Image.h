#ifndef IMAGE_H_
#define IMAGE_H_

namespace Engine
{
    /*
     * All images are opaque objects which don't have any methods.
     * The only supported operation is a draw, through the Window class.
     */
    class Image
    {
    public:
        Image();
        virtual ~Image();
        static Image *Get(char *filename);
    };
}

#endif
