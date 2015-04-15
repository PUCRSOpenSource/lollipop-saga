#include "Ship.h"
#include <cmath>

Ship::Ship(void) : GameObject()
{
        setX(0.0f);
        setY(-0.6f);
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
            if (i == 20) {
                glVertex2f(posX + cx, posY + cy + 0.5);
                glVertex2f(posX + cx - 0.05, posY + cy + 0.5);
                glVertex2f(posX + cx - 0.05, posY + cy);
            }
            glVertex2f(posX + cx, posY + cy);
            t = posX;
            posX = cos_theta * posX - sin_theta * posY;
            posY = sin_theta * t + cos_theta * posY;
        }
    
        glEnd();
}
