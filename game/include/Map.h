#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h> 

class Map
{
public:

    Map();
    ~Map();

    void drawStar(float x, float y);
    void drawMap();
    void generateMap();
private:
	float xarray[100];
	float yarray[100];
};
