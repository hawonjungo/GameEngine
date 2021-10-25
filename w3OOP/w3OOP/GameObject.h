#pragma once
#include "SDL.h"
#include <SDL_image.h>
class GameObject{
public: 
	GameObject();
	~GameObject();
	void load(const char* title,  int width, int height);
	void draw(int, const char* , int , int);
	void update(int);
	void renderClean();
	void render(bool);
	void clean();
	bool running();


	SDL_Renderer* getRenderer();

private:


	
protected:
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
	bool isRunning;

	SDL_Surface* g_background;
	SDL_Window* sdlWindow;
	static SDL_Renderer* m_pRenderer;
	SDL_Surface* pTempSurface;
	SDL_Texture* m_pTexture;


};

