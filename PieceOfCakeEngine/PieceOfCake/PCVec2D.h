#pragma once
class PCVec2D
{
private:
	double m_x;
	double m_y;


public:
	PCVec2D(int x, int y);
	PCVec2D();
	~PCVec2D(void);


	double GetX();
	double GetY();
};

