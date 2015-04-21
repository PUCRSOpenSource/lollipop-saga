#include "GameObject.h"
#include <stdlib.h>

class Enemy: public GameObject
{
public:
    Enemy(float x, float y, int t);
    ~Enemy();

    void draw();
    void move();
    void drawCookie();
    void drawNacho();
private:
	int type;
};
