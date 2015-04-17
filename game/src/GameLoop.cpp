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
#include <iostream>

using namespace std;

std::vector<GameObject*> objects;
GameObject* ship;
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
        GameObject *player = objects[0];
        GameObject *enemy = objects[1];

        if (objects.size() > 1) {
            if(hasCollided(player,enemy)) {
                objects.pop_back();
            }

        }
        
        glFlush();
}

bool hasCollided(GameObject *player, GameObject *enemy) {
    return topRightPointInside(player,enemy) && topLeftPointInside(player,enemy);

}

bool topRightPointInside(GameObject *player, GameObject *enemy) {
        float pxMax = player->getX() + 0.1;
        float exMax = enemy->getX() + 0.1;
        float exMin = enemy->getX() - 0.1;
        bool xInside = ((pxMax > exMin) && (pxMax < exMax));
        float pyMax = player->getY() + 0.1;
        float eyMax = enemy->getY() + 0.1;
        float eyMin = enemy->getY() - 0.1;
        bool yInside = ((pyMax > eyMin) && (pyMax < eyMax));
        return xInside && yInside;
}

bool topLeftPointInside(GameObject *player, GameObject *enemy) {
        float pxMin = player->getX() - 0.1;
        float exMax = enemy->getX() + 0.1;
        float exMin = enemy->getX() - 0.1;
        bool xInside = ((pxMin > exMin) && (pxMin < exMax));
        float pyMin = player->getY() + 0.1;
        float eyMax = enemy->getY() + 0.1;
        float eyMin = enemy->getY() - 0.1;
        bool yInside = ((pyMin > eyMin) && (pyMin < eyMax));
        return xInside && yInside;
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
        for (int i = 0; i < 20; i++) {
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
