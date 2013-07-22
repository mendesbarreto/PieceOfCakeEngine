#ifndef __PC_ENGINE__
#define __PC_ENGINE__

#include "SDL.h"
#include "PCSprite.h"
#include "PCEvent.h"

class PCEngine : public PCEvent
{

private:
	//
	bool running;

	SDL_Surface* display;
	PCSprite* test;

public:
	int OnExecute();


public:
	PCEngine(void);
	~PCEngine(void);

	virtual bool Initialize();
	virtual void Update();
	virtual void Render();
	virtual void Dispose();

	virtual void OnEvent(SDL_Event * event);
	virtual void OnExit();
};

#endif // !__PC_ENGINE__



