#include "GameObject.h"

GameObject::GameObject(void)
{
 
}

GameObject::~GameObject(void)
{

}

void GameObject::setX(float posX)
{
        x = posX;
}

void GameObject::setY(float posY)
{
        y = posY;
}

//bounding box functions

void GameObject::setXmax(float posXmax)
{
        xMax = posXmax;
}

void GameObject::setXmin(float posXmin)
{
        xMin = posXmin;
}

void GameObject::setYmax(float posYmax)
{
        yMax = posYmax;
}

void GameObject::setYmin(float posYmin)
{
        yMin = posYmin;
}

float GameObject::getXmax()
{
        return xMax;
}
float GameObject::getYmax()
{
        return yMax;
}

float GameObject::getXmin()
{
        return xMin;
}

float GameObject::getYmin()
{
        return yMin;
}

//end of bounding box functions

float GameObject::getX()
{
        return x;
}

float GameObject::getY()
{
        return y;
}

void
GameObject::moveX(float move)
{
        x = move; 
}

void
GameObject::moveY(float move)
{
        y = move;
}

void 
GameObject::moveLeft()
{
        x -= 0.05f;
        xMax -= 0.05f;
        xMin -= 0.05f;
}
void
GameObject::moveRight()
{
        x+= 0.05f;
        xMax+= 0.05f;
        xMin+= 0.05f;
}

void
GameObject::moveUp()
{
        y+= 0.009f;
        yMax+= 0.009f;
        yMin+= 0.009f;
}

void
GameObject::zigzag()
{
	if(zig) {
		x+=0.05f;
        xMax+= 0.05f;
        xMin+= 0.05f;
	} else {
		x-=0.05f;
        xMax-= 0.05f;
        xMin-= 0.05f;
	}
	if (x < -0.9f) {
		zig = true;
	}
	if (x > 0.9f) {
		zig = false;
	}
}

bool
GameObject::hasContact(GameObject *object)
{
	
    float pXmax = xMax; //x maximo do player
    float pXmin = xMin; //x minimo do player
    float pYmax = yMax; //y maximo do player
    float pYmin = yMin; //y minimo do player

    float eXmax = object->getXmax(); //x maximo do enemy
    float eXmin = object->getXmin(); //x minimo do enemy
    float eYmax = object->getYmax(); //y maximo do enemy
    float eYmin = object->getYmin(); //y minimo do enemy

    bool topRightPointInside = ((pXmax > eXmin) && (pXmax < eXmax)) && ((pYmax > eYmin) && (pYmax < eYmax));
    bool topLeftPointInside = ((pXmin > eXmin) && (pXmin < eXmax)) && ((pYmax > eYmin) && (pYmax < eYmax));
    bool bottomRightPointInside = ((pXmax > eXmin) && (pXmax < eXmax)) && ((pYmin > eYmin) && (pYmin < eYmax));
    bool bottomLeftPointInside = ((pXmin > eXmin) && (pXmin < eXmax)) && ((pYmin > eYmin) && (pYmin < eYmax));
    bool isInside = topRightPointInside || topLeftPointInside || bottomLeftPointInside || bottomRightPointInside;
    if (isInside) {
        return true;
    }
    return false;
}

