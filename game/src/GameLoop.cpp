#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
 
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   glVertex2f(-0.5f, -0.5f);    // x, y
   glVertex2f( 0.5f, -0.5f);
   glVertex2f( 0.5f,  0.5f);
   glVertex2f(-0.5f,  0.5f);
   glEnd();

   glFlush();  // Render now
}

int main(int argc, char** argv)
{
        glutInit(&argc, argv);
        glutCreateWindow("OpenGL Setup Test"); // Create a
        glutInitWindowSize(320, 320);   // Set the
        glutInitWindowPosition(50, 50); // Position the
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;
}
