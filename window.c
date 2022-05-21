#include "window.h"

void error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

void key_callback(    
    GLFWwindow *window,
    int key,
    int scancode,
    int action,
    int mods
) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLFWwindow *create_window(
    const char *title, 
    GLsizei width, 
    GLsizei height,
    int fullscreen
) {
    if (!glfwInit()) error("Couldn't initialize GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    GLFWwindow *window = glfwCreateWindow(
        width, 
        height, 
        title, 
        fullscreen ? glfwGetPrimaryMonitor() : NULL, 
        NULL
    );

    if (!window) error("Couldn't create window");

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSetWindowSizeCallback(window, size_callback);
    glfwSwapInterval(1);
    
    size_callback(window, width, height);

    return window;
}

void loop(GLFWwindow *window, void (*render)(double)) {
    while(!glfwWindowShouldClose(window)) {
        render(glfwGetTime());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void size_callback(GLFWwindow *window, int width, int height) {
    GLfloat aspectRatio;

    if (height == 0) height = 1;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat) width / (GLfloat) height;

    if (width <= height) {
        glOrtho(
            -100.0, 100.0, 
            -100.0 / aspectRatio, 100.0 / aspectRatio, 
            1.0, -1.0
        );
    } else {
        glOrtho(
            -100.0 * aspectRatio, 100.0 * aspectRatio, 
            -100.0, 100.0, 
            1.0, -1.0
        );
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}