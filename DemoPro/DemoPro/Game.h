#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game
{
public: 
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int heigh, bool fullScreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();
	
	bool running() {
		return isRunning;
	}

	static SDL_Renderer* renderer;

private:
	int count = 0;
	bool isRunning = false;
	SDL_Window* window;
	
};

