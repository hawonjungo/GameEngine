#pragma once
#include "GameObject.h"


GameObject::GameObject() {

}
GameObject::~GameObject() {

}
void GameObject::load(const char* title, int xpos, int ypos, int width, int height, Uint32 flags) {
	SDL_Init(SDL_INIT_EVERYTHING);

	 sdlWindow = SDL_CreateWindow(title, xpos, ypos,width, height, flags);
	 m_pRenderer = SDL_CreateRenderer(sdlWindow, 0, -1);
	 

	 
}
void GameObject::draw(SDL_Renderer* m_pRenderer) {

	pTempSurface = SDL_LoadBMP("assets/run.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
	m_sourceRectangle.w /= 8;

	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_pRenderer);
}
void GameObject::update() {
	m_sourceRectangle.x = m_sourceRectangle.w * ((SDL_GetTicks() / 80) % 8);
	SDL_RenderClear(m_pRenderer);
}
void GameObject::render() {

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



