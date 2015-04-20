#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Enemy.h"
#include "GameObject.h"
#include "Ship.h"
#include "Map.h"
#include "Bullet.h"

#include <math.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

std::vector<GameObject*> objects;
std::vector<Bullet*> bullets;
GameObject* ship;
Map* map;
float bottomY;
float topY;
long timeBefore;
long timeNow;

void draw(void)
{

        timeNow = glutGet(GLUT_ELAPSED_TIME);
        if (timeNow - timeBefore > 20) {
            bottomY += 0.009;
            topY += 0.009;
            ship->moveUp();
             for(int i = 0; i < bullets.size(); i++) {
                 bullets[i]->moveUp();
                 bullets[i]->moveUp();
             }
            for(int i = 0; i < objects.size(); i++) {
                objects[i]->zigzag();
            }
            timeBefore = timeNow;
        }

        // long time = glutGet(GLUT_ELAPSED_TIME);
    
        //  if(time % 10 == 0)
        //  {
        //          bottomY += 0.009;
        //          topY += 0.009;
        //          ship->moveUp();
        // }
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-1.0,1.0,bottomY,topY);
        glMatrixMode(GL_MODELVIEW);
        glutReshapeWindow(350, 1050);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glLoadIdentity();
        glPopMatrix();
        glLoadIdentity();
        map->drawMap();
        ship->draw();
        for (int i = 0; i < objects.size(); i++) {
                objects[i]->draw();
        }
         for (int i = 0; i < bullets.size(); i++) {
                 bullets[i]->draw();
         }

        //contact

        for (int i = 0; i < objects.size(); i++) {
            if(ship->hasContact(objects[i])) {
                objects.erase(objects.begin() + i);
            }
        }    

        glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
        switch (key) {
            case 27:
                exit(0);
                break;
            case 'a':
                if(ship->getX() > -0.9) {
                    ship->moveLeft();
                }
                break;
            case 'd':
                if(ship->getX() < 0.9) {
                    ship->moveRight();
                }
                break;
            case 'w':
                 // Bullet* bullet;
                 // bullet = new Bullet(ship->getX(),ship->getY());
                 // bullets.push_back(bullet);
                break;
            default:
                break;
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
        map = new Map();
        for (int i = 0; i < 10; i++) {
            GameObject* enemy;
            enemy = new Enemy(0.5,i);
            objects.push_back(enemy);
        }
        //enemy = new Enemy(0.5,0.4);
        //objects.push_back(enemy);

        glutInit(&argc,argv);
        timeNow = glutGet(GLUT_ELAPSED_TIME);
        timeBefore = glutGet(GLUT_ELAPSED_TIME);
        timeNow = glutGet(GLUT_ELAPSED_TIME);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(350,1050);
        glutCreateWindow("Lollipop");
        glutDisplayFunc(draw);
        glutKeyboardFunc (keyboard);
        glutIdleFunc(draw);
        init();
        glutMainLoop();
        return 0;
}
