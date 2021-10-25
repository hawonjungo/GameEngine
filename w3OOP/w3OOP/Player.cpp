#include "Player.h"

Player::Player(int m_pframes, const char* m_ptexture, int posX, int posY)
{
	m_frames = m_pframes;
	m_texture = m_ptexture;
	m_positionX = posX;
	m_positionY = posY;

	m_velocity_right = new Vector2D(5, 0);
	m_velocity_left = new Vector2D(-5, 0);
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
	if (flipToLeft) {
		Player::playerMove(m_velocity_left);
	}
	else {
		Player::playerMove(m_velocity_right);
	}

	if (m_destinationRectangle.x > 1100) {
		flipToLeft = true;
	}
	else if(m_destinationRectangle.x<0) {
		flipToLeft = false;
	}
	
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
				flipToLeft = true;
					playerMove(m_velocity_left);
				
			
				break;
			case SDLK_RIGHT:
				flipToLeft = false;
					playerMove(m_velocity_right);
			
				break;
			case SDLK_UP:
				//playerMove(0,-5);
				break;
			case SDLK_DOWN:
				//playerMove(0,5);
				break;
			case SDLK_c:
				//playerMove(0,-100);
				break;
			default:
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			//playerMove(0,5);
			break;
		case SDL_MOUSEBUTTONUP:
			//playerMove(0,-5);
			break;

		default:
			break;
		}
	}
}

void Player::playerMove(Vector2D* m_velocity)
{
	m_destinationRectangle.x += m_velocity->getX();
	m_destinationRectangle.y += m_velocity->getY();
}
