#include "SDL.h"
#include "SDL_Image.h"
#include <iostream>

#include "PCEngine.h"
#include "PCSprite.h"
#include <iostream>
#include <stdio.h>

PCSprite::PCSprite(void)
{

}

PCSprite::~PCSprite(void)
{
	SDL_DestroyTexture(m_texture);
}

PCSprite* PCSprite::fromFile( char* fileName )
{
	//TODO: Make a LoaderCOntent for Texture and Image
	PCEngine* engine = PCEngine::GetInstace();

	SDL_Texture* temp_surface = IMG_LoadTexture(engine->GetRenderer(), fileName);

	if(temp_surface == NULL)
	{
		//ERROR;
		const char* buffer = IMG_GetError();
		printf(buffer);

		return nullptr;
	}
	
	PCSprite* returnSprite = new PCSprite();
	returnSprite->m_texture = temp_surface;

	return returnSprite;
}

SDL_Texture* PCSprite::GetTexture()
{
	return m_texture;
}

bool PCSprite::Draw( SDL_Texture* destination, SDL_Texture* source, int x, int y )
{
	if(!destination && !source)
	{
		return false;
	}
	
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	//SDL_BlitSurfac(esource, NULL, destination, &rect);

	return true;
}

bool PCSprite::Draw( SDL_Texture* destination, SDL_Texture* source, int x, int y, int x2, int y2, int width, int height )
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

	//TODO: MUdar a tatica de blitting
	//SDL_RenderCopy()

	//SDL_BlitSurface(source, &srcRect, destination, &destRect);

	return true;
}

bool PCSprite::RemoveRGBColorFrom( PCSprite *src, int r, int g, int b )
{
	if(!src)
	{
		return false;
	}

	//SDL_SetColorKey(src->getRaw(), SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(src->getRaw()->format, r,g,b ));

	return true;
}

//TODO: Uint8 PCSprite::GetBlueComponent()
//TODO: Uint8 PCSprite::GetGreenComponent()


Uint8 PCSprite::GetRedComponent(SDL_Texture* surface)
{

	/* Extracting color components from a 32-bit color value 
    SDL_PixelFormat *fmt;
    Uint32 temp, pixel;
    Uint8 red;
   
    fmt = surface->format;
   SDL_LockSurface(surface);
   pixel = *((Uint32*)surface->pixels);
   SDL_UnlockSurface(surface);
   */
   /* Get Red component */
  //  temp = pixel & fmt->Rmask;  /* Isolate red component */
  // temp = temp >> fmt->Rshift; /* Shift it down to 8-bit */
  // temp = temp << fmt->Rloss;  /* Expand to a full 8-bit number */
  // red = (Uint8)temp;
   

   return 0;
}



Uint8 PCSprite::GetAlphaComponent(SDL_Texture* surface)
{

	/* Extracting color components from a 32-bit color value */
	//SDL_PixelFormat *fmt = surface->format;
	//Uint32 temp, pixel;
	//Uint8 alpha;

	//SDL_LockSurface(surface);
	//pixel = *((Uint32*)surface->pixels);
	//SDL_UnlockSurface(surface);

	/* Get Red component */
	//temp = pixel & fmt->Amask;  /* Isolate red component */
	//temp = temp >> fmt->Ashift; /* Shift it down to 8-bit */
	//temp = temp << fmt->Aloss;  /* Expand to a full 8-bit number */
	
	//alpha = (Uint8)temp;


	return 0;
}


