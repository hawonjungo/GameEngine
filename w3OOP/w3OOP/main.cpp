#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Player.h"


int main(int argc, char** argv) {
	
	Player* player = new Player(8,"assets/run.bmp",10,795);
	player->load("My Game",1280,940);
	player->draw();



	while (player->running()) {
		player->update();
		player->render();
	}
	player->clean();

	return 0;
}