#include "window.h"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

static const int BORDER_WIDTH = 1000;
static const int BORDER_HEIGHT = 10;

const SDL_Rect BORDER_UP = {.x = 100, .y = 70, .w = BORDER_WIDTH, .h = BORDER_HEIGHT };

const SDL_Rect BORDER_DOWN = { .x = 100, .y = 530, .w = BORDER_WIDTH, .h = BORDER_HEIGHT };

void render_borders(SDL_Renderer *renderer, SDL_Window *window){ 
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &BORDER_UP);
	SDL_RenderFillRect(renderer, &BORDER_DOWN);
}


