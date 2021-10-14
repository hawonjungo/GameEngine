#pragma once
#include "GameObject.h"


GameObject::GameObject() {
	isRunning = false;
}
GameObject::~GameObject() {

}
void GameObject::load(const char* title, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height, SDL_WINDOW_SHOWN);
		m_pRenderer = SDL_CreateRenderer(sdlWindow, 0, -1);
		isRunning = true;
	}
	 

	 
}
void GameObject::draw(int m_frames, const char* m_texture, int m_position_x, int m_position_y) {

	pTempSurface = SDL_LoadBMP(m_texture);
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
	m_sourceRectangle.w /= m_frames;

	m_destinationRectangle.x = m_position_x;
	m_destinationRectangle.y = m_position_y;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_pRenderer);
}
void GameObject::update(int m_frame) {
	m_sourceRectangle.x = m_sourceRectangle.w * ((SDL_GetTicks() / 80) % 8);
	SDL_RenderClear(m_pRenderer);
}
void GameObject::render(bool flipToLeft) {

	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_NONE);
	SDL_RenderPresent(m_pRenderer);
}
void GameObject::clean() {
	SDL_Delay(1000);

	SDL_DestroyWindow(sdlWindow);
	SDL_DestroyRenderer(m_pRenderer);

	SDL_Quit();
}
bool GameObject::running() {
	return true;
}

SDL_Renderer* GameObject::getRenderer()
{
	return m_pRenderer;
}



