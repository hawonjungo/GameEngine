#pragma once
#include "GameObject.h"
#include "Vector2D.h"
class Enemy:public GameObject
{
public:
	Enemy(int, const char*, int, int);
	~Enemy();

	void draw();
	void update();
	void render();
	void autoAttack();

	void handleEvents();
	void enemyMove(Vector2D*);

	void setFlip(bool flip) {
		flipToLeft = flip;
	}
	void setPosX(const int& posX) {
		m_positionX = posX;
	}
	void setPosY(const int& posY) {
		m_positionX = posY;
	}
	int getPosX() {
		return m_positionX;
	}
	int getPosY() {
		return m_positionY;
	}


private:
	int m_frames;
	const char* m_texture;
	int m_positionX;
	int m_positionY;
	bool flipToLeft = false;

	Vector2D* m_velocity_right;
	Vector2D* m_velocity_left;
};

