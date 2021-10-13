#include <SDL.h>

int main(int argc, char** argv) {

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* sdlWindow = SDL_CreateWindow("Hello", 100, 100, 640, 480, 4);
	SDL_Renderer* m_pRenderer = SDL_CreateRenderer(sdlWindow, 0, -1);
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/run.bmp");
	SDL_Texture* m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	SDL_Rect m_sourceRectangle;
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;
	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
	m_sourceRectangle.w /= 8;


	SDL_Rect m_destinationRectangle;
	m_destinationRectangle.x = 0;
	m_destinationRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;


	SDL_Rect m_destMiddle = { 0,0,3 * m_sourceRectangle.w ,3 * m_sourceRectangle.h };
	SDL_Rect m_destTopRight = { 350,70,m_sourceRectangle.w ,m_sourceRectangle.h };	
	SDL_Rect m_destBotLeft = { 0,300,m_sourceRectangle.w ,m_sourceRectangle.h };
	SDL_Rect m_destBotRight = { 350,300,m_sourceRectangle.w ,m_sourceRectangle.h };
	




	SDL_SetRenderDrawColor(m_pRenderer, 0, 120, 0, 255);
	
	
	while (true) {
		m_sourceRectangle.x = m_sourceRectangle.w * ((SDL_GetTicks() / 100) % 8);
		SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_NONE);
		SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destTopRight, 0, 0, SDL_FLIP_VERTICAL);
		SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destMiddle, 0, 0, SDL_FLIP_NONE);
		SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destBotLeft, 0, 0, SDL_FLIP_NONE);
		SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destBotRight, 0, 0, SDL_FLIP_HORIZONTAL);


		SDL_RenderPresent(m_pRenderer);
		SDL_RenderClear(m_pRenderer);

	}



	SDL_Delay(1000);
	SDL_Quit();
		return 0;

}
