#include "Bullet.h"
#include <cmath>

Bullet::Bullet(float x, float y) : GameObject()
{
        setX(x);
        setY(y);
}
Bullet::~Bullet(void)
{
}

void Bullet::draw()
{
        glColor3f(0,0,1);
        
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y);
            glVertex2f(x , y + 0.05);
        glEnd();
}

