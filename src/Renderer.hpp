#ifndef Renderer_hpp
#define Renderer_hpp

#include <GL/gl.h>

class Renderer
{
public:
    void Setup();
    void Render(double time);
};

#endif