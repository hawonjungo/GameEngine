#include "Player.h"

Player::Player(int m_pframes, const char* m_ptexture, int posX, int posY)
{
	m_frames = m_pframes;
	m_texture = m_ptexture;
	m_positionX = posX;
	m_positionY = posY;

}

Player::~Player()
{
	GameObject::draw(m_frames, m_texture, m_positionX, m_positionY);
}

void Player::draw()
{ 
	GameObject::draw(m_frames, m_texture, m_positionX, m_positionY);

}

void Player::update()
{
	GameObject::update(m_frames);
}

void Player::render()
{
	GameObject::render(flipToLeft);
}
