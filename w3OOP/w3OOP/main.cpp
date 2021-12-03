#pragma once
#include <SDL_image.h>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "BK.h"
#include <iostream>


SDL_Window* g_windows = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* g_background = NULL;

bool loadMedia()
{
	bool success = true;
	g_background = IMG_Load("bk.png");
	if (g_background == NULL)
	{
		success = false;
	}

	return success;
}


int main(int argc, char** argv) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem initialised!.. " << std::endl;
		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
			std::cout << "Fail initialised image!.. " << IMG_GetError() << std::endl;
		}
	}

	   
	Player* player = new Player(8,"assets/run.bmp",0,595);
	Enemy* enemy = new Enemy(8, "assets/mushroom_run.png", 1000, 607);
	BK* bk = new BK(1, "assets/bk.png", 0, 0);

	player->load("My Game",1280,940);
	player->draw();
	

	bk->draw();
	bk->update();
	bk->render();
	SDL_RenderPresent(bk->getRenderer());
	SDL_RenderClear(bk->getRenderer());


	if(loadMedia())
        {
            SDL_BlitSurface( g_background, NULL, gScreenSurface, NULL );
            SDL_UpdateWindowSurface(g_windows);
            SDL_Delay( 2000 );
        }

	enemy->draw();
	enemy->setFlip(true);

	while (player->running()) {
	
		player->handleEvents();
		player->update();	
		player->render();
			
		enemy->update();
		enemy->render();

		bk->update();
		bk->render();
			
		SDL_RenderPresent(player->getRenderer());
		SDL_RenderClear(player->getRenderer());		
						
	}
	player->clean();
	
	return 0;
}