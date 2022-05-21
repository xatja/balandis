#ifndef Engine_hpp
#define Engine_hpp

#include "Window.hpp"
#include "Renderer.hpp"

class Engine
{
public:
    Engine();
    ~Engine();
    void Run();

private:
    Window *window;
};

#endif