#pragma once
class PCSize
{
private:
	float m_height;
	float m_width;

public:
	PCSize(void);
	PCSize(float width, float height);
	~PCSize(void);


	void SetWidth(float width);
	void SetHeight(float height);
	float GetHeight();
	float GetWidth();
};

