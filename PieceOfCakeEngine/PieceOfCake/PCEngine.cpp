#include <SDL.h>
#include "PCEvent.h"
#include "PCEngine.h"
#include "PCSize.h"
#include "PCVec2D.h"

#include <fstream>
#include <iostream>
using namespace std;


PCEngine::PCEngine(std::string name = "Default app name", 
				   PCSize winSize = PCSize(1024,768),
				   PCVec2D windowPosition = PCVec2D(SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED ),
				   Uint32 flags = SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL)
{
	m_name = name;
	m_winSize = winSize;
	m_initFlags = flags;
	m_windowPosition = windowPosition;
}


PCEngine::~PCEngine(void)
{
}

bool PCEngine::Initialize()
{
	if(SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK ) < 0)
	{
		return false;
	}

	fprintf(stderr,"%i joysticks were found.\n\n", SDL_NumJoysticks() );
	fprintf(stderr,"The names of the joysticks are:\n");

	SDL_JoystickEventState(SDL_ENABLE);

	int i;

	for( i=0; i < SDL_NumJoysticks(); i++ ) 
	{
		fprintf(stderr,"Joystick: %s \n", SDL_JoystickName(i));
		SDL_JoystickOpen(i);
	}

	SDL_CreateWindowAndRenderer(0,0, SDL_WINDOW_FULLSCREEN_DESKTOP, &m_window, & m_renderer);

	if( m_window == NULL || m_renderer == NULL) {
		return false;
	}

	//Creating the main scrren
	m_screen = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING,m_winSize.GetWidth(), m_winSize.GetHeight());

	if(m_screen == NULL)
	{
		return false;
	}

	if(m_winSize.GetWidth() != 0)
	{
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
		SDL_RenderSetLogicalSize(m_renderer, m_winSize.GetWidth(), m_winSize.GetHeight());
	}


	m_running = true;

	return true;
}

void PCEngine::OnEvent(SDL_Event * event){
	PCEvent::OnEvent(event);
}

int PCEngine::OnExecute(){

	if(Initialize() == false){
		return -1;
	}

	SDL_Event event;

	while (m_running)
	{
		while(SDL_PollEvent(&event)){
			this->OnEvent(&event);
		}

		this->Update();
		this->Render();
	}


	this->Dispose();
	
	return 0;
}

void PCEngine::Update(){

}

void PCEngine::Render(){
	//PCSprite::Draw(display, test->getRaw(),0,0);
	//PCSprite::Draw(display, test->getRaw(),100,100, 0,0, 20, 20);

	SDL_UpdateTexture(m_screen, NULL, m_pixels, m_winSize.GetWidth() * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_screen, NULL, NULL);
	SDL_RenderPresent(m_renderer);

	
}

void PCEngine::Dispose(){
	SDL_Quit();
}

void PCEngine::OnExit()
{
	this->m_running = false;
}

SDL_Window* PCEngine::GetWindow()
{
	return m_window;
}

void PCEngine::OnLButtonDown( int x, int y )
{
	PCEvent::OnLButtonDown( x, y );
}

SDL_Renderer* PCEngine::GetRenderer()
{
	return m_renderer;
}
