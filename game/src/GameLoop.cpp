#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Enemy.h"
#include "GameObject.h"
#include "Ship.h"
#include "Map.h"

#include <math.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

std::vector<GameObject*> objects;
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
        ship->draw();
        for (int i = 0; i < objects.size(); i++) {
                objects[i]->draw();
        }

        //to tendo problemas pra usar funçoes sei la pq entao vou botar tudo aqui dentro

        for (int i = 0; i < objects.size(); i++) {
            GameObject *enemy = objects[i];
            float pXmax = ship->getX() + 0.1; //x maximo do player
            float pXmin = ship->getX() - 0.1; //x minimo do player
            float pYmax = ship->getY() + 0.1; //y maximo do player
            float pYmin = ship->getY() - 0.1; //y minimo do player

            float eXmax = enemy->getX() + 0.1; //x maximo do enemy
            float eXmin = enemy->getX() - 0.1; //x minimo do enemy
            float eYmax = enemy->getY() + 0.1; //y maximo do enemy
            float eYmin = enemy->getY() - 0.1; //y minimo do enemy

            bool topRightPointInside = ((pXmax > eXmin) && (pXmax < eXmax)) && ((pYmax > eYmin) && (pYmax < eYmax));
            bool topLeftPointInside = ((pXmin > eXmin) && (pXmin < eXmax)) && ((pYmax > eYmin) && (pYmax < eYmax));
            bool bottomRightPointInside = ((pXmax > eXmin) && (pXmax < eXmax)) && ((pYmin > eYmin) && (pYmin < eYmax));
            bool bottomLeftPointInside = ((pXmin > eXmin) && (pXmin < eXmax)) && ((pYmin > eYmin) && (pYmin < eYmax));
            bool topInside = topRightPointInside || topLeftPointInside || bottomLeftPointInside || bottomRightPointInside;
            if (topInside) {
                objects.erase(objects.begin() + i);
            }

        }


        //GameObject *player = objects[0];
        // GameObject *enemy = objects[1];

        // if (objects.size() > 1) {
        //     if(hasCollided(player,enemy)) {
        //         objects.pop_back();
        //     }

        // }
        
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
                ship->moveUp();
                //bottomY += 0.009;
                //topY += 0.009;
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
        map->drawMap();
        glutKeyboardFunc (keyboard);
        glutIdleFunc(draw);
        init();
        glutMainLoop();
        return 0;
}
