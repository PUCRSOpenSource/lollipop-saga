#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include "GameObject.h"
#include "Ship.h"

using namespace std;

void initialize(void)
{
        glMatrixMode(GL_PROJECTION);
        //gluOrtho2D(-1.0,1.0,-1.0,1.0);
        glMatrixMode(GL_MODELVIEW);
}

void draw(void)
{
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glLoadIdentity();
        glPopMatrix();
        glLoadIdentity();
        glFlush();

}
void keyboard(unsigned char key, int x, int y)
{
        if (key == 27)
                exit(0);
}
int main(int argc, char** argv)
{
        GameObject* g = new Ship();
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500,500);
        glutCreateWindow("Lolip vs Cookies");
        glutDisplayFunc(draw);
        glutKeyboardFunc(keyboard);
        initialize();
        glutIdleFunc(draw);
        glutMainLoop();

        return 0;
}
