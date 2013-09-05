#include "TicTacToe.h"
#include "PCSize.h"

int main(int argc, char* args[])
{
	PCSize winSize(600,600);

	TicTacToe tc(winSize);
	return tc.OnExecute();
}