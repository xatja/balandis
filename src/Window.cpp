#include "Window.hpp"

Window *Window::gh_window = nullptr;

Window::Window(const char *title, int width, int height, bool fullscreen)
    : width(width), height(height)
{
    gh_window = this;
    Window::fullscreen = fullscreen;

    if (!glfwInit())
        Error("Couldn't initialize GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    window = glfwCreateWindow(
        width,
        height,
        title,
        fullscreen ? glfwGetPrimaryMonitor() : NULL,
        NULL);

    if (!window)
        Error("Couldn't create window");

    const GLFWvidmode *video_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    refresh_rate = video_mode->refreshRate;

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
    if (!fullscreen) 
    {
        gh_window->width = width;
        gh_window->height = height;
    }

    GLdouble range = 100.0;

    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width <= height)
    {
        glOrtho(
            -range, range,
            -range * height / width, range * height / width,
            -range, range);
    }
    else
    {
        glOrtho(
            -range * width / height, range * width / height,
            -range, range,
            -range, range);
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

    if (key == GLFW_KEY_F && action == GLFW_PRESS)
        ToggleFullscreen(window);
}

void Window::Loop(Renderer *renderer)
{
    renderer->Setup();

    while (!glfwWindowShouldClose(window))
    {
        renderer->Render(glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

bool Window::fullscreen = false;

void Window::ToggleFullscreen(GLFWwindow *window)
{
    if (fullscreen)
    {
        glfwSetWindowMonitor(
            window, 
            NULL, 
            0, 0,
            gh_window->width, gh_window->height, 
            gh_window->refresh_rate);
    }
    else
    {
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode *video_mode = glfwGetVideoMode(monitor);

        glfwSetWindowMonitor(
            window,
            monitor,
            0, 0,
            video_mode->width, video_mode->height,
            video_mode->refreshRate);
    }

    fullscreen = !fullscreen;
}