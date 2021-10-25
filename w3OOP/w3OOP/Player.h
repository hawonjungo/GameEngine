#pragma once
#include "GameObject.h"
#include "Vector2D.h"
class Player: public GameObject
{
public:
	Player(int, const char*, int, int);
	~Player();

	void draw();
	void update();
	void render();
	void handleEvents();
	void playerMove(Vector2D*);

private:
	int m_frames;
	const char* m_texture;
	int m_positionX;
	int m_positionY;
	bool flipToLeft = false;

	Vector2D* m_velocity_right;
	Vector2D* m_velocity_left;

};

