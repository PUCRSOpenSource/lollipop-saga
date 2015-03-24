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
        glLoadIdentity();
        glBegin(GL_POLYGON);
        {
                glColor3f(0.0,1.0,0.0);
                glVertex3f(-0.4,-0.5,-3.0);
                glVertex3f(0.6,-0.5,-3.0);
                glVertex3f(0.7,0.5,-3.0);
        }
        glEnd();
        glFlush();             
}
