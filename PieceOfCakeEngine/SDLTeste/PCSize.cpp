#include "PCSize.h"


PCSize::PCSize(void)
{
}

PCSize::PCSize( float width, float height )
{
	m_width = width;
	m_height = height;
}


PCSize::~PCSize(void)
{
}

float PCSize::GetWidth()
{
	return m_width;
}

float PCSize::GetHeight()
{
	return m_height;
}


void PCSize::SetWidth(float width)
{
	 m_width = width;
}

void PCSize::SetHeight(float height)
{
	m_height = height;
}


