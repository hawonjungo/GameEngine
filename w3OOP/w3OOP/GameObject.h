#pragma once
#include "SDL.h"
class GameObject{
public: 
	GameObject();
	~GameObject();
	void load(const char* title, int xpos, int ypos, int width, int height, Uint32 flags);
	void draw(SDL_Renderer* m_pRenderer);
	void update();
	void render();
	void clean();
	bool running();


	SDL_Renderer* getRenderer();

private:
	SDL_Window* sdlWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Surface* pTempSurface;
	SDL_Texture* m_pTexture;
protected:
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
	

};

