#include "SDL.h"
#include "PCEvent.h"
#include "PCEngine.h"

#include <fstream>
#include <iostream>
using namespace std;

PCEngine::PCEngine(void)
{
	running = true;
	display = nullptr;
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

	display = SDL_SetVideoMode( 1024,768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );
	
	if( display == NULL) {
		return false;
	}

	if((test = PCSprite::fromFile("Mario.jpg")) == NULL)
		return false;


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

	while (running)
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

	SDL_Flip(display);
}

void PCEngine::Dispose(){
	SDL_Quit();
}

void PCEngine::OnExit()
{
	this->running = false;
}
