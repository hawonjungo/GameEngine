#pragma once
#include "GameObject.h"
class Enemy:public GameObject
{
public:
	Enemy(int, const char*, int, int);
	~Enemy();

	void draw();
	void update();
	void render();
	
	void setFlip(bool flip) {
		flipToLeft = flip;
	}



private:
	int m_frames;
	const char* m_texture;
	int m_positionX;
	int m_positionY;
	bool flipToLeft = false;
};

