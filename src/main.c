#include <stdbool.h>

#include "ball.h"

#include <SDL2/SDL.h>

static const char * TITTLE = "Pong";
static const int WIDTH = 1200;
static const int HEIGHT = 600;

int main(){

	SDL_Window *window = NULL;
	window = SDL_CreateWindow(TITTLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event event;

	static bool game_is_running = true;

	ball b;
	create_ball(&b);
	
	SDL_Rect bb;
	bb.x = 600;
	bb.y = 100;
	bb.w = 20;
	bb.h = 20;

	while(game_is_running){

		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT) game_is_running = false;

		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer, &b.ball);

		SDL_RenderPresent(renderer);

	}


	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
