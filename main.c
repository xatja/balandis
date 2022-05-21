#include "window.h"
#include "render.h"

int main(int argc, char *argv[]) {
    GLFWwindow *window = create_window("Test", 1024, 768, GLFW_FALSE);
    loop(window, render);
    return 0;
}