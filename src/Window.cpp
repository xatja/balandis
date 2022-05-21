#include "Window.hpp"

Window::Window(const char *title, int width, int height, bool fullscreen)
    : fullscreen(fullscreen)
{
    if (!glfwInit())
        Error("Couldn't initialize GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    window = glfwCreateWindow(
        width,
        height,
        title,
        fullscreen ? glfwGetPrimaryMonitor() : NULL,
        NULL);

    if (!window)
        Error("Couldn't create window");

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, Window::OnKey);
    glfwSetWindowSizeCallback(window, Window::OnResize);
    glfwSwapInterval(1);

    Window::OnResize(window, width, height);
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::OnResize(GLFWwindow *window, int width, int height)
{
    GLfloat aspectRatio;

    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)width / (GLfloat)height;

    if (width <= height)
    {
        glOrtho(
            -100.0, 100.0,
            -100.0 / aspectRatio, 100.0 / aspectRatio,
            1.0, -1.0);
    }
    else
    {
        glOrtho(
            -100.0 * aspectRatio, 100.0 * aspectRatio,
            -100.0, 100.0,
            1.0, -1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Window::OnKey(
    GLFWwindow *window,
    int key,
    int scancode,
    int action,
    int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void Window::Loop(Renderer *renderer)
{
    while (!glfwWindowShouldClose(window))
    {
        renderer->Render(glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}