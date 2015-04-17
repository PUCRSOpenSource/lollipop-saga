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
        y+= 0.0009f;
}
