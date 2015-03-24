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
        objects[0]->draw();
}

void reshapeFunc(int x, int y)
{

        if(y == 0 || x == 0)
                        return;  
        glMatrixMode(GL_PROJECTION);  
        glLoadIdentity();
        gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
        glMatrixMode(GL_MODELVIEW);
        glViewport(0,0,x,y);  
}

int main(int argc, char *argv[])
{
        GameObject* g = new Ship();
        objects.push_back(g);
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(400,400);
        glutCreateWindow("Lolipop");
        glClearColor(0.0,0.0,0.0,0.0);
        glutDisplayFunc(draw);
        glutReshapeFunc(reshapeFunc);
        glutMainLoop();
        return 0;
}
