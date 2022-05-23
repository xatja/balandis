#include "Renderer.hpp"
#include <cmath>

#define GL_PI 3.1415f
GLfloat xrot = 0.1f;
GLfloat yrot = 0.2f;

void Renderer::Setup() 
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPointSize(4.0f);
}

void Renderer::Render(double time)
{
    GLfloat x, y, z, angle;
    
    glClear(GL_COLOR_BUFFER_BIT);

    // Save matrix state and do the rotation
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glBegin(GL_POINTS);
    z = -50.0f;

    for (angle = 0.0f; angle <= (2.0f * GL_PI) * 3.0f; angle += 0.1f)
    {
        x = 50.0f * sin(angle);
        y = 50.0f * cos(angle);

        glVertex3f(x, y, z);
        z += 0.5f;
    }

    glEnd();
}