#include "Engine.hpp"

Engine::Engine() 
{
    window = new Window("balandis", 1024, 768, false);
}

Engine::~Engine() 
{
    delete window;
}

void Engine::Run() 
{
    Renderer *renderer = new Renderer();
    window->Loop(renderer);

    delete renderer;
}