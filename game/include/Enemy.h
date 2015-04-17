#include "GameObject.h"
class Enemy: public GameObject
{
public:
    Enemy(float x, float y);
    ~Enemy();

    void draw();
    void move();
private:
};
