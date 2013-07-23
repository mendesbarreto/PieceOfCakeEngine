#include "TicTacToe.h"
#include "PCEngine.h"
#include "PCSize.h"
#include <string>


std::string wins = "n";

TicTacToe::TicTacToe( PCSize winSize ) : PCEngine(winSize)
{
	gridSize = 9;
}


void TicTacToe::Update()
{

	if(VerifyV(grid, GRID_TYPE_X) || VerifyH(grid, GRID_TYPE_X) || VerifyD(grid, GRID_TYPE_X))
	{
		wins = "x";
	}

	if(VerifyV(grid, GRID_TYPE_O) || VerifyH(grid, GRID_TYPE_O) || VerifyD(grid, GRID_TYPE_O))
	{
		wins = "o";
	}

	int count = 0;
	for (int i = 0; i < gridSize; i++)
	{
		if(grid[i] != GRID_TYPE_NONE)
			count++;
	}

	if(count == gridSize)
		Reset();

	PCEngine::Update();
}


bool TicTacToe::VerifyD(short *grid, int type)
{

	int D = 0;
	int currentValue;

	if(grid[0] == type && grid[4] == type && grid[8] == type)
		return true;

	if(grid[2] == type && grid[4] == type && grid[6] == type)
		return true;

	return false;		
}

bool TicTacToe::VerifyV(short *grid, int type)
{
	
	int V = 0;
	int currentValue;
	for (int i = 0; i < 3; i++)
	{	
		for (int j = 0; j < gridSize; j+=3)
		{
			currentValue = grid[i+j];
			if(currentValue == type)
				V++;

			if(V == 3)
				return true;
		}

		V = 0;
	}

	return false;		
}

bool TicTacToe::VerifyH(short *grid, int type)
{
	int H = 0;
	int currentValue;

	for (int i = 0; i < gridSize; i+=3)
	{	
		for (int j = 0; j < 3; j++)
		{
			currentValue = grid[i+j];
			
			if(currentValue == type)
				H++;

			if(H == 3)
				return true;
		}

		H = 0;
	}


	return false;		
}




void TicTacToe::Render()
{
	PCSprite::Draw(m_display, m_grid->getRaw(),0,0);

	if (wins == "x")
	{
		PCSprite::Draw(m_display, m_xWins->getRaw(), 0,0);
	}else if(wins == "o")
	{
		PCSprite::Draw(m_display, m_oWins->getRaw(), 0,0);
	}else
	{
		int i;
		int x;
		int y;

		for (i = 0; i < gridSize; i++)
		{
			x = (i % 3) * 200;
			y = (i / 3) * 200;

			if(grid[i] == GRID_TYPE_O)
			{
				PCSprite::Draw(m_display, m_oSprite->getRaw(), x,y);
			}else if(grid[i] == GRID_TYPE_X)
			{
				PCSprite::Draw(m_display, m_xSprite->getRaw(), x,y);
			}
		}
	}

	PCEngine::Render();
}

bool TicTacToe::Initialize()
{
	bool init = PCEngine::Initialize();

	this->m_grid = PCSprite::fromFile("../Resources/graphics/grid.png");
	this->m_xSprite = PCSprite::fromFile("../Resources/graphics/x.png");
	this->m_oSprite = PCSprite::fromFile("../Resources/graphics/o.png");	

	m_xWins = PCSprite::fromFile("../Resources/graphics/Xwins.jpg");
	m_oWins = PCSprite::fromFile("../Resources/graphics/Owins.jpg");

	if(!m_grid && !m_xSprite && !m_oSprite)
		return false;


	PCSprite::RemoveRGBColorFrom(m_xSprite, 255,0,255);
	PCSprite::RemoveRGBColorFrom(m_oSprite, 255,0,255);

	Reset();

	return init;
}

void TicTacToe::Reset()
{
	int i = 0;
	for (i = 0; i < gridSize; i++)
	{
		grid[i] = GRID_TYPE_NONE;
	}
}

TicTacToe::~TicTacToe( void )
{
	PCEngine::~PCEngine();
}

void TicTacToe::SetCell( short id, short type )
{
	if(type< 0 || type >= gridSize)
	{
		return;
	}

	if(type< 0 || type > GRID_TYPE_O )
	{
		return;
	}

	grid[id] = type;
}

void TicTacToe::OnLButtonDown( int x, int y )
{

	int id    = x / 200;	
	id = id + ((y / 200) * 3);

	if(grid[id] != GRID_TYPE_NONE) {
		return;
	}

	if(m_currentPlayer == 0) {
		SetCell(id, GRID_TYPE_X);
		m_currentPlayer = 1;
	}else{
		SetCell(id, GRID_TYPE_O);
		m_currentPlayer = 0;
	}

	PCEngine::OnLButtonDown(x,y);
}

