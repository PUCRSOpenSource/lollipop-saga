#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <vector>
#include "GameObject.h"
#include "Ship.h"

using namespace std;

std::vector<GameObject*> objects;
void draw(void)
{
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glLoadIdentity();
        glPopMatrix();
        glLoadIdentity();
        objects[0]->draw();
        glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
        if (key == 27)
                exit(0);
        glutPostRedisplay();
}

void init(void)
{
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-1.0,1.0,-1.0,1.0);
        glMatrixMode(GL_MODELVIEW);
}

int main(void)
{
        int argc = 0;
        char *argv[] = { (char *)"gl", 0 };

        GameObject* ship = new Ship();
        objects.push_back(ship);

        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(350,600);
        glutCreateWindow("Lollipop");
        glutDisplayFunc(draw);
        glutKeyboardFunc (keyboard);
        init();
        glutMainLoop();
        return 0;
}
