#ifndef Window_hpp
#define Window_hpp

#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <iostream>
#include <cstdlib>
#include "Renderer.hpp"

static void Error(const char *message) {
    std::cerr << message << std::endl;
    exit(EXIT_FAILURE);
}

class Window
{
public:
    Window(const char *title, int width, int height, bool fullscreen);
    ~Window();
    void Loop(Renderer *renderer);

private:
    GLFWwindow *window;
    int width, height, refresh_rate;
    static Window *gh_window;
    static bool fullscreen;
    static void OnResize(GLFWwindow *window, int width, int height);
    static void OnKey(
        GLFWwindow *window,
        int key,
        int scancode,
        int action,
        int mods);
    static void ToggleFullscreen(GLFWwindow *window);
};

#endif