#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>


int main(int argc, char** argv) {

	Player* player = new Player(8,"assets/run.bmp",500,595);
	player->load("My Game",1280,940);
	player->draw();

	Enemy* enemy = new Enemy(8, "assets/wind_def.png", 550, 595);
	enemy->draw();
	enemy->setFlip(true);




	while (player->running()) {
	
		player->handleEvents();
		player->update();	
		player->render();
			
		enemy->update();
		enemy->render();
		
		SDL_RenderPresent(player->getRenderer());
		SDL_RenderClear(player->getRenderer());
	
		
			
	}
	player->clean();
	
	return 0;
}