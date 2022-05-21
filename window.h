#ifndef window_h
#define window_h

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>

void error(const char *message);

void key_callback(    
    GLFWwindow *window,
    int key,
    int scancode,
    int action,
    int mods
);

GLFWwindow *create_window(
    const char *title, 
    GLsizei width, 
    GLsizei height,
    int fullscreen
);

void loop(GLFWwindow *window, void (*render)(double));

void size_callback(GLFWwindow *window, int width, int height);

#endif