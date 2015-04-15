#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Enemy.h"
#include "GameObject.h"
#include "Ship.h"

#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

std::vector<GameObject*> objects;
GameObject* ship;
float bottomY;
float topY;
void draw(void)
{
       // glutReshapeWindow(350, 1050);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glLoadIdentity();
        glPopMatrix();
        glLoadIdentity();
        for (int i = 0; i < objects.size(); i++) {
                objects[i]->draw();
        }
        glFlush();
}

void keyboard(unsigned char key, int x, int y)
{

        if (key == 27)
                exit(0);
        else if (key == 'a') 
                ship->moveLeft();
        else if (key == 'd') 
                ship->moveRight();
        else if (key == 'w') {
                ship->moveUp();

        } else if (key == 's') {
                topY = topY + 0.1;
                bottomY = bottomY + 0.1;
                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();
                gluOrtho2D(-1.0,1.0,bottomY,topY);
                glMatrixMode(GL_MODELVIEW);

        }
                
                
        glutPostRedisplay();
}

void init(void)
{
        glMatrixMode(GL_PROJECTION);
        bottomY = -1.0;
        topY = 1.0;
        gluOrtho2D(-1.0,1.0,bottomY,topY);
        glMatrixMode(GL_MODELVIEW);
}

int main(void)
{
        int argc = 0;
        char *argv[] = { (char *)"gl", 0 };

        //THE ship
        ship = new Ship();
        objects.push_back(ship);

        GameObject* enemy;
        enemy = new Enemy(0.5,0.4);
        objects.push_back(enemy);

        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(350,350);
        glutCreateWindow("Lollipop");
        glutDisplayFunc(draw);
        glutKeyboardFunc (keyboard);
        init();
        glutMainLoop();
        return 0;
}
