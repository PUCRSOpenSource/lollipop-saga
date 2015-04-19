#include "Map.h"

Map::Map(void)
{
        
}

Map::~Map(void)
{
}

void Map::drawStar(float x, float y)
{
        glColor3f(1,1,1);
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y);
            glVertex2f(x + 0.05, y + 0.075);
            glVertex2f(x + 0.1, y);
            glVertex2f(x - 0.025, y + 0.05);
            glVertex2f(x + 0.125, y + 0.05);
        glEnd();
        
}

void Map::drawMap() {
    drawStar(0,2);
}