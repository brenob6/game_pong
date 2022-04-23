#include <SDL2/SDL.h>

#include <stdbool.h>

#include "ball.h"
#include "player.h"
#include "events.h"
#include "window.h"

bool key_state[] = {false, false, false, false};
const int FPS = 60;
const int FRAME_TIME = 1000 / FPS;

enum game_state {START = 1, RUNNING, OVER};

int main(){

	if (SDL_Init(SDL_INIT_VIDEO)){

		SDL_Log("error");
		return -1;
	}

	SDL_Window *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == NULL){

		SDL_Log("error");
		return -2;
	}

	SDL_Event event;

	player p1;
	create_player(&p1, 1);

	player p2;
	create_player(&p2, 2);

	ball b;
	create_ball(&b);

	bool game_is_running = true;
	int state = START;

	while(game_is_running){

		int frame_start = SDL_GetTicks();

		if(state == START){

			window_start(renderer);

			while(SDL_PollEvent(&event)){

				if(event.type == SDL_KEYUP){

					switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						state = RUNNING;
						game_is_running = false;
						break;
					case SDLK_SPACE:
						state = RUNNING;
						break;
					}
				}
			}
		}
		if(state == RUNNING){
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
					case SDLK_ESCAPE:
						game_is_running = false;
						break;
					}
				}
			}

			handle_events(key_state, &p1, &p2);
			update_ball(&b, &p1, &p2);

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(renderer);
			render_borders(renderer);
			display(renderer, p1.score, p2.score);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
			SDL_RenderFillRect(renderer, &b.ball);
			SDL_RenderFillRect(renderer, &p1.player);
			SDL_RenderFillRect(renderer, &p2.player);

			SDL_RenderPresent(renderer);
		}

		if(state == OVER){}

		int frame_delay = SDL_GetTicks() - frame_start;

		if(FRAME_TIME > frame_delay){
			SDL_Delay(FRAME_TIME - frame_delay);
		}

	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
