#include <SDL.h>
#include <SDL_image.h>
#include "PCEvent.h"
#include "PCEngine.h"
#include "PCSize.h"
#include "PCVec2D.h"

#include <fstream>
#include <iostream>
using namespace std;

PCEngine* PCEngine::m_instance = nullptr;


PCEngine::PCEngine(std::string name = "Default app name", 
				   PCSize winSize = PCSize(1024,768),
				   PCVec2D windowPosition = PCVec2D(SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED ),
				   Uint32 flags = SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL)
{
	m_name = name;
	m_winSize = winSize;
	m_initFlags = flags;
	m_windowPosition = windowPosition;

	m_instance = this;
}


PCEngine::~PCEngine(void)
{
}

bool PCEngine::Initialize()
{

	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	//						INIT THE SDL VIDEO AND JOYSTICK						//
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////

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
		fprintf(stderr,"Joystick: %s \n", SDL_JoystickNameForIndex(i));
		SDL_JoystickOpen(i);
	}

	//////////////////////////////////////////////////////////////////////////////




	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	//						CREATING WINDOW AND RENDER CONTEXT					//
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////

	//Set texture filtering to linear
	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	{
		printf( "Warning: Linear texture filtering not enabled!" );
	}

	m_window = SDL_CreateWindow("Hello World!", m_windowPosition.GetX(), m_windowPosition.GetY(), m_winSize.GetWidth(), m_winSize.GetHeight(), SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if( m_window == NULL) 
	{
		fprintf(stderr, "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

	if(m_renderer == NULL)
	{
		fprintf(stderr, "Render could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
	
	//Initialize Render color
	SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, 0xFF ); 

	//Initialize the images types that will be loaded
	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if(! ( IMG_Init(imgFlags) & imgFlags ) )
	{
		fprintf(stderr, "IMAGE Loader context could not be created: %s\n", SDL_GetError() );
		return false;
	}

	//Creating the main screen
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
	//////////////////////////////////////////////////////////////////////////////
	return m_running = true;
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

	//SDL_UpdateTexture(m_screen, NULL, m_pixels, m_winSize.GetWidth() * sizeof(Uint32));
	
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

PCEngine* PCEngine::GetInstace()
{
	return m_instance;
}
