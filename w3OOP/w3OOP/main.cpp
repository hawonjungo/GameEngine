#pragma once
#include <SDL.h>
#include "GameObject.h"


int main(int argc, char** argv) {
	
	GameObject* game = new GameObject();
	game->load("My Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 640,480,SDL_WINDOW_SHOWN);
	game->draw(game->getRenderer());

	while (game->running()) {
		game->update();
		game->render();
	}
	game->clean();

	return 0;
}