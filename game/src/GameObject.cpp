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
}
void
GameObject::moveRight()
{
        x+= 0.05f;
}

void
GameObject::moveUp()
{
        y+= 0.009f;
}

void
GameObject::zigzag()
{
	if(zig) {
		x+=0.05f;
	} else {
		x-=0.05f;
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
	
    float pXmax = x + 0.1; //x maximo do player
    float pXmin = x - 0.1; //x minimo do player
    float pYmax = y + 0.1; //y maximo do player
    float pYmin = y - 0.1; //y minimo do player

    float eXmax = object->getX() + 0.1; //x maximo do enemy
    float eXmin = object->getX() - 0.1; //x minimo do enemy
    float eYmax = object->getY() + 0.1; //y maximo do enemy
    float eYmin = object->getY() - 0.1; //y minimo do enemy

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

