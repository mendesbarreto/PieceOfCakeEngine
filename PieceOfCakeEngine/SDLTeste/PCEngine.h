#ifndef __PC_ENGINE__
#define __PC_ENGINE__

#include "SDL.h"
#include "PCSprite.h"
#include "PCEvent.h"
#include "PCSize.h"

class PCEngine : public PCEvent
{

private:
	//
	bool m_running;
	PCSize m_winSize;

	
	PCSprite* test;

public:
	int OnExecute();

protected:
	SDL_Surface* m_display;

public:
	PCEngine(void);
	PCEngine(PCSize winSize);
	~PCEngine(void);

	virtual bool Initialize();
	virtual void Update();
	virtual void Render();
	virtual void Dispose();

	virtual void OnEvent(SDL_Event * event);
	virtual void OnLButtonDown(int x, int y);
	virtual void OnExit();

	SDL_Surface* GetDisplay();
};

#endif // !__PC_ENGINE__



