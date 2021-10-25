#pragma once
#include "GameObject.h"
class BK : public GameObject {
public:
	BK(int, const char*, int, int);
	~BK();
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
