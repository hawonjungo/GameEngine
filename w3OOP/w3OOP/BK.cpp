#include "BK.h"
BK::BK(int m_pframes, const char* m_ptexture, int posX, int posY) {
	m_frames = m_pframes;
	m_texture = m_ptexture;
	m_positionX = posX;
	m_positionY = posY;
}
BK::~BK()
{
}
void BK::draw() {
	GameObject::draw(m_frames, m_texture, m_positionX, m_positionY);
}
void BK::update() {
	GameObject::update(m_frames);
}
void BK::render() {
	GameObject::render(flipToLeft);
}


