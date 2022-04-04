#include "window.h"

void render_borders(SDL_Renderer *renderer, SDL_Window *window){ 
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &BORDER_UP);
	SDL_RenderFillRect(renderer, &BORDER_DOWN);
}


