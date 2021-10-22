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

void Player::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				playerMove(-10,0);
				break;
			case SDLK_RIGHT:
				playerMove(10,0);
				break;
			case SDLK_UP:
				playerMove(0,-10);
				break;
			case SDLK_DOWN:
				playerMove(0,10);
				break;
			case SDLK_c:
				playerMove(0,-100);
				break;
			default:
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			playerMove(0,12);
			break;
		case SDL_MOUSEBUTTONUP:
			playerMove(0,-5);
			break;

		default:
			break;
		}
	}
}

void Player::playerMove(int step_x, int step_y)
{
	m_destinationRectangle.x += step_x;
	m_destinationRectangle.y += step_y;
}
