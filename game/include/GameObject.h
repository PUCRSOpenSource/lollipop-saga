#pragma once

class GameObject
{
public:
    GameObject();
    ~GameObject();

    virtual void draw();

    void setX(float x);
    void setY(float y);
    
    float getX();
    float getY();

    void moveX();
    void moveY();

    void die();

private:
    float x;
    float y;
};
