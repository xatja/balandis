#include "render.h"

void render(double time) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
}