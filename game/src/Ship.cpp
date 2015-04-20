#include "Ship.h"
#include <cmath>

Ship::Ship(void) : GameObject()
{
        setX(0.1f);
        setY(-0.9f);
        setXmax(x + 0.1);
        setXmin(x - 0.1);
        setYmax(y + 0.1);
        setYmin(y - 0.1);
}

Ship::~Ship(void)
{
}

void Ship::draw()
{
        glColor3f(1,0,0);
        //FIXME
        //colocar cx e cx em um ponto
        float cx = this->x;
        float cy = this->y;

        int segs = 100;
        float t;

        float theta = 2.0f * M_PI / float(segs);
        float cos_theta = cosf(theta);
        float sin_theta = sinf(theta);
        float r = 0.1f;

        float posX = r;
        float posY = 0;

        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i < segs; i++)
        {
            glVertex2f(posX + cx, posY/2 + cy);
            t = posX;
            posX = cos_theta * posX - sin_theta * posY;
            posY = sin_theta * t + cos_theta * posY;
        }
        glEnd();

        glBegin(GL_LINE_LOOP);
                glVertex2f(this->x - 0.0125, this->y);
                glVertex2f(this->x + 0.0125, this->y);
                glVertex2f(this->x + 0.0125, this->y + 0.2);
                glVertex2f(this->x - 0.0125, this->y + 0.2);
                glVertex2f(this->x - 0.0125, this->y);
        glEnd();
        
}

// void Ship::shoot() {
//         Bullet* bullet;
//         bullet = new Bullet(x,y);
//         bullets.push_back(bullet);
// }

// void Ship::moveBullets() {
//          for (int i = 0; i < bullets.size(); i++) {
//             bullets[i]->moveUp();
//             bullets[i]->moveUp();
//         }
// }

// void drawBullets() {
//         for (int i = 0; i < bullets.size(); i++) {
//             bullets[i]->draw();
//         }   
// }
