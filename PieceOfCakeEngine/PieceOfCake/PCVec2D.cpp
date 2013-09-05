#include "PCVec2D.h"


PCVec2D::PCVec2D(int x = 0, int y = 0)
{
	m_x = x;
	m_y = y;
}


PCVec2D::~PCVec2D(void)
{
}

double PCVec2D::GetX()
{
	return m_x;
}

double PCVec2D::GetY()
{
	return m_y;
}
