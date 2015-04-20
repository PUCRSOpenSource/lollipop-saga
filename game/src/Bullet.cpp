#include "Bullet.h"
#include <cmath>

Bullet::Bullet(float x, float y) : GameObject()
{
        setX(x);
        setY(y);
        setXmax(x);
        setXmin(x - 0.05);
        setYmax(y + 0.1);
        setYmin(y - 0.1);
}
Bullet::~Bullet(void)
{
}

void Bullet::draw()
{
        glColor3f(0,0,1);
        
        glLineWidth(4);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y);
            glVertex2f(x , y + 0.05);
        glEnd();
}

