#pragma once
class Vector2D
{
private: 
	float m_x;
	float m_y;

public:
	Vector2D();
	Vector2D(float, float);
	float getX();
	float getY();
	void setX(float);
	void setY(float);
	
};

