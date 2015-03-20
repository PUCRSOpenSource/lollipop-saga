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
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2i(100,150);
        glVertex2i(100,100);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(150,100);
        glVertex2i(150,150);               
        glEnd();
        glFlush();
}
