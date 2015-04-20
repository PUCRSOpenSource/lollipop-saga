#include <cstdio>
class Texture
{
public:
        Texture(float x, float y, const char* filename);
        ~Texture();
	bool LoadBmpFile( const char *filename );
private:
};
