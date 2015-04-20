
#include "GameObject.h"

class Bullet: public GameObject
{
public:
    Bullet(float x, float y);
    ~Bullet();

    void draw();
    void move();
private:
};

