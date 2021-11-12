#include "Enemy.h"

Enemy::Enemy(int m_pframes, const char* m_ptexture, int posX, int posY)
{
	m_frames = m_pframes;
	m_texture = m_ptexture;
	m_positionX = posX;
	m_positionY = posY;

	m_velocity_right = new Vector2D(5, 0);
	m_velocity_left = new Vector2D(-5, 0);

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
	if (flipToLeft) {
		Enemy::enemyMove(m_velocity_left);
	}
	else {
		Enemy::enemyMove(m_velocity_right);
	}

	if (m_destinationRectangle.x > 1100) {
		flipToLeft = true;
	}
	else if (m_destinationRectangle.x < 0) {
		flipToLeft = false;
	}

	GameObject::update(m_frames);
}

void Enemy::render()
{
	GameObject::render(flipToLeft);
}

void Enemy::autoAttack()
{
}

void Enemy::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				flipToLeft = true;
				enemyMove(m_velocity_left);


				break;
			case SDLK_RIGHT:
				flipToLeft = false;
				enemyMove(m_velocity_right);

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

void Enemy::enemyMove(Vector2D* m_velocity)
{
	m_destinationRectangle.x += m_velocity->getX();
	m_destinationRectangle.y += m_velocity->getY();
}


