#include "GameObject.h"
#include <stdlib.h>
#include <vector>
//#include "Bullet.h"

class Ship : public GameObject
{
public:

    Ship();
    ~Ship();

    void draw();
    void shoot();
    // void moveBullets();
    // void drawBullets();
private:
	// std::vector<Bullet*> bullets;
   
};
