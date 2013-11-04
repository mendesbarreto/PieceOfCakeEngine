#include "TicTacToe.h"
#include "PCSize.h"

int main(int argc, char* args[])
{

	std::string name = "TicTacToe";
	PCSize winSize = PCSize(600,600);
	PCVec2D windowPosition = PCVec2D(SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED );
	Uint32 flags = SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL;

	TicTacToe tc(name, winSize, windowPosition, flags);

	return tc.OnExecute();
}