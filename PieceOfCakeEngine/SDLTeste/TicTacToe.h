#pragma once
#include "pcengine.h"
class TicTacToe :
	public PCEngine
{
public:
	TicTacToe(void);

	void Update();
	void Render();
	bool Initialize();


	~TicTacToe(void);
};

