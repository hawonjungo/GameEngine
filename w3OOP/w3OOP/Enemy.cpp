#include "Enemy.h"

Enemy::Enemy(int m_pframes, const char* m_ptexture, int posX, int posY)
{
	m_frames = m_pframes;
	m_texture = m_ptexture;
	m_positionX = posX;
	m_positionY = posY;

}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	GameObject::draw(m_frames, m_texture, m_positionX, m_positionY);
}

void Enemy::update()
{
	GameObject::update(m_frames);
}

void Enemy::render()
{
	GameObject::render(flipToLeft);
}
