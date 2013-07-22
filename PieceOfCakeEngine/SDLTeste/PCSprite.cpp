#include "SDL.h"
#include "SDL_Image.h"

#include "PCSprite.h"
#include <iostream>
#include <stdio.h>

PCSprite::PCSprite(void)
{

}

PCSprite::~PCSprite(void)
{

}

PCSprite* PCSprite::fromFile( char* fileName )
{

	SDL_Surface* temp_surface = IMG_Load(fileName);
	SDL_Surface* return_surface = nullptr;

	if(temp_surface == NULL)
	{
		//ERROR;
		char* buffer = IMG_GetError();
		printf(buffer);

		return nullptr;
	}

	return_surface = SDL_DisplayFormat(temp_surface);
	SDL_FreeSurface(temp_surface);

	PCSprite* returnSprite = new PCSprite();
	returnSprite->rawContent = return_surface;

	return returnSprite;
}

SDL_Surface* PCSprite::getRaw()
{
	return rawContent;
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
