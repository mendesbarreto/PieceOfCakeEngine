#ifndef __TIC_TAC_TOE__
#define __TIC_TAC_TOE__

#include "PCEngine.h"
#include "PCSize.h"
#include "PCSprite.h"


enum {
	GRID_TYPE_NONE = 0,
	GRID_TYPE_X,
	GRID_TYPE_O
};

class TicTacToe :
	public PCEngine
{
public:
	
	PCSprite *m_grid;
	PCSprite *m_xSprite;
	PCSprite *m_oSprite;

	PCSprite *m_xWins;
	PCSprite *m_oWins;

	short m_currentPlayer;
	
	short gridSize;
	short  grid[9];

	TicTacToe(PCSize winSize);

	void Update();
	void Render();
	bool Initialize();


	void Reset();
	void SetCell(short id, short type);
	void OnLButtonDown(int x, int y);

	~TicTacToe(void);
	bool VerifyH(short *grid, int type);
	bool VerifyV(short *grid, int type);
	bool VerifyD(short *grid, int type);
};

#endif // !__TIC_TAC_TOE__