#include "Ship.h"

Ship::Ship(void) : GameObject()
{
        setX(20);
        setY(20);
}

Ship::~Ship(void)
{
}

void Ship::draw()
{
        glColor3f(1,0,0);
        glLineWidth(3);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.2f,-0.30f);
        glVertex2f(0.0f,0.30f);
        glVertex2f(0.2f,-0.30f);
        glEnd();
}
