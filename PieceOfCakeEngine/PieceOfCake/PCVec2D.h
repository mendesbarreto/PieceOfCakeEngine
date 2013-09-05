#pragma once
class PCVec2D
{
private:
	double m_x;
	double m_y;


public:
	PCVec2D::PCVec2D(int x = 0, int y = 0);
	~PCVec2D(void);


	double GetX();
	double GetY();
};

