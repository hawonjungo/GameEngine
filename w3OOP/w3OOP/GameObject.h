#pragma once
#include "SDL.h"
class GameObject{
public: 
	GameObject();
	~GameObject();
	void load(const char* title,  int width, int height);
	void draw(int, const char* , int , int);
	void update(int);
	void render(bool);
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
	bool isRunning;

};

