#pragma once
#include "GameObject.h"
class Player: public GameObject
{
public:
	Player(int, const char*, int, int);
	~Player();

	void draw();
	void update();
	void render();

private:
	int m_frames;
	const char* m_texture;
	int m_positionX;
	int m_positionY;
	bool flipToLeft = false;

};

