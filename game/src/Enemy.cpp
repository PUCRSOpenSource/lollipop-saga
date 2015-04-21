#include "Enemy.h"
#include <cmath>

Enemy::Enemy(float x, float y, int t) : GameObject()
{
        setX(x);
        setY(y);
        setXmax(x + 0.1);
        setXmin(x - 0.1);
        setYmax(y + 0.1);
        setYmin(y - 0.1);
        type = t;

}

void Enemy::draw()
{
        if (type == 1) {
            drawNacho();
        } else {
            drawCookie();
        }
}

void Enemy::drawCookie()
{
        glColor3f(0,0,1);
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
}

void Enemy::drawNacho()
{
        glColor3f(1,1,0);
        
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y + 0.05);
            glVertex2f(x + 0.075, y - 0.05);
            glVertex2f(x - 0.075, y - 0.05);
        glEnd();
}
