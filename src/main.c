#include <SDL2/SDL.h>

#include <stdbool.h>

#include "ball.h"
#include "player.h"
#include "events.h"

static const char *TITTLE = "Pong";
static const int WIDTH = 1200;
static const int HEIGHT = 600;

bool key_state[] = {false, false, false, false};

int main(){

	SDL_Window *window = NULL;
	window = SDL_CreateWindow(TITTLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event event;

	static bool game_is_running = true;
	
	player p1;
	create_player(&p1, 1);

	player p2;
	create_player(&p2, 2);

	ball b;
	create_ball(&b);
	
	while(game_is_running){

		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT) game_is_running = false;

			if(event.type == SDL_KEYDOWN){
				switch(event.key.keysym.sym){
				case SDLK_w:
					key_state[LETTER_W] = true;
					break;
				case SDLK_s:
					key_state[LETTER_S] = true;
					break;
				case SDLK_UP:
					key_state[UP] = true;
					break;
				case SDLK_DOWN:
					key_state[DOWN] = true;
					break;
				}
			}
			if(event.type == SDL_KEYUP){
				switch(event.key.keysym.sym){
				case SDLK_w:
					key_state[LETTER_W] = false;
					break;
				case SDLK_s:
					key_state[LETTER_S] = false;
					break;
				case SDLK_UP:
					key_state[UP] = false;
					break;
				case SDLK_DOWN:
					key_state[DOWN] = false;
					break;
				}
			}
		}

		handle_events(key_state, &p1, &p2);
		update_ball(&b, &p1.player, &p2.player);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer, &b.ball);
		SDL_RenderFillRect(renderer, &p1.player);
		SDL_RenderFillRect(renderer, &p2.player);

		SDL_RenderPresent(renderer);
		
	}


	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
