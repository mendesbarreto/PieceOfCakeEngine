#ifndef __PC_ENGINE__
#define __PC_ENGINE__

#include "SDL.h"
#include "PCSprite.h"
#include "PCEvent.h"
#include "PCSize.h"
#include "PCVec2D.h"
#include <string>

class PCEngine : public PCEvent
{

private:
	//
	bool m_running;
	PCSize m_winSize;
	PCVec2D m_windowPosition;
	std::string m_name;
	PCSprite* test;


	static PCEngine* m_instance;


	//Move this variable to some camera
	Uint32 *m_pixels;


public:
	int OnExecute();
	static PCEngine* GetInstace();

protected:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_screen;

	Uint32 m_initFlags;

public:
	PCEngine(std::string name, PCSize winSize, PCVec2D windowPosition ,Uint32 flags);
	~PCEngine(void);

	virtual bool Initialize();
	virtual void Update();
	virtual void Render();
	virtual void Dispose();

	virtual void OnEvent(SDL_Event * event);
	virtual void OnLButtonDown(int x, int y);
	virtual void OnExit();

	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer(); 

	std::string GetApplicationName();

};

#endif // !__PC_ENGINE__



