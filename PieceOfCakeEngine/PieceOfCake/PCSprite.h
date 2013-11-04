#ifndef __PC_SPRITE__
#define __PC_SPRITE__

#include "SDL.h"

class PCSprite
{

private:
	SDL_Texture* m_texture;
	static Uint8 GetRedComponent(SDL_Texture* surface);
	static Uint8 GetAlphaComponent(SDL_Texture* surface);

public:
	static PCSprite	* fromFile(char* fileName);
	static bool Draw(SDL_Texture* destination, SDL_Texture* source, int x, int y);
	static bool Draw(SDL_Texture* destination, SDL_Texture* source, int x, int y, int x2, int y2, int width, int height);
	static bool RemoveRGBColorFrom(PCSprite *src, int R, int G, int B);
	SDL_Texture* GetTexture();

	PCSprite(void);
	~PCSprite(void);
};

#endif // !__PC_SPRITE__