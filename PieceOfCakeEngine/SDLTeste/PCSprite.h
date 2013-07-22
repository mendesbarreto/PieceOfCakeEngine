#ifndef __PC_SPRITE__
#define __PC_SPRITE__

#include "SDL.h"

class PCSprite
{

private:
	SDL_Surface* rawContent;

public:

	static PCSprite	* fromFile(char* fileName);
	static bool Draw(SDL_Surface* destination, SDL_Surface* source, int x, int y);
	static bool Draw(SDL_Surface* destination, SDL_Surface* source, int x, int y, int x2, int y2, int width, int height);

	SDL_Surface* getRaw();

	PCSprite(void);
	~PCSprite(void);
};

#endif // !__PC_SPRITE__