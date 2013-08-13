#include "SDL.h"
#include "SDL_Image.h"
#include <iostream>


#include "PCSprite.h"
#include <iostream>
#include <stdio.h>

PCSprite::PCSprite(void)
{

}

PCSprite::~PCSprite(void)
{
	SDL_FreeSurface(m_rawContent);
}

PCSprite* PCSprite::fromFile( char* fileName )
{
	SDL_Surface* temp_surface = IMG_Load(fileName);
	SDL_Surface* return_surface = nullptr;

	std::string prefix = std::string(fileName);

	if(temp_surface == NULL)
	{
		//ERROR;
		char* buffer = IMG_GetError();
		printf(buffer);

		return nullptr;
	}


	//Take the number of channels in the display image
	Uint8  pi = temp_surface->format;
	
	return_surface = SDL_DisplayFormatAlpha(temp_surface);
	
	PCSprite* returnSprite = new PCSprite();
	returnSprite->m_rawContent = return_surface;

	SDL_FreeSurface(temp_surface);

	return returnSprite;
}

SDL_Surface* PCSprite::getRaw()
{
	return m_rawContent;
}

bool PCSprite::Draw( SDL_Surface* destination, SDL_Surface* source, int x, int y )
{

	if(!destination && !source)
	{
		return false;
	}
	
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	SDL_BlitSurface(source, NULL, destination, &rect);

	return true;
}

bool PCSprite::Draw( SDL_Surface* destination, SDL_Surface* source, int x, int y, int x2, int y2, int width, int height )
{
	if(!destination && !source)
	{
		return false;
	}

	SDL_Rect srcRect;
	srcRect.x = x2;
	srcRect.y = y2;
	srcRect.h = height;
	srcRect.w = width;


	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;

	SDL_BlitSurface(source, &srcRect, destination, &destRect);

	return true;
}

bool PCSprite::RemoveRGBColorFrom( PCSprite *src, int r, int g, int b )
{
	if(!src)
	{
		return false;
	}

	SDL_SetColorKey(src->getRaw(), SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(src->getRaw()->format, r,g,b ));

	return true;
}
