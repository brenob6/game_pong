#include "window.h"

const char *WINDOW_TITLE = "PONG";

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

static const int BORDER_WIDTH = 1000;
static const int BORDER_HEIGHT = 10;

const int BORDER_UP_Y = 70;
const int BORDER_DOWN_Y = 530;

const SDL_Rect BORDER_UP = {.x = 100, .y = BORDER_UP_Y, .w = BORDER_WIDTH, .h = BORDER_HEIGHT};

const SDL_Rect BORDER_DOWN = {.x = 100, .y = BORDER_DOWN_Y, .w = BORDER_WIDTH, .h = BORDER_HEIGHT};

//Display      g|f|e|d|c|b|a
//	-----
//	| a	|
//f	| 	|  b
//	-----
//e	| g	|
//	|	|  c
//	-----
//    d

const int SCORES[] = { 

	0b0111111,
	0b0110000,
	0b1011011,
	0b1001111,
	0b1100110,
	0b1101101,
	0b1111100,
	0b0000111,
	0b1111111,
	0b1100111
};


void render_borders(SDL_Renderer *renderer){

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &BORDER_UP);
	SDL_RenderFillRect(renderer, &BORDER_DOWN);
}

static void render_display(SDL_Renderer *renderer, SDL_Rect d){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &d);
}

void create_display(SDL_Rect s[7], int n){

	int x = (n ==1) ? 400 : 770;
	int y = 10;

	s[0] = (SDL_Rect){.x = x, .y = y, .w = 30, .h = 10};		//a
	s[1] = (SDL_Rect){.x = x+20, .y = y, .w = 10, .h = 30};		//b
	s[2] = (SDL_Rect){.x = x+20, .y = y+20, .w = 10, .h = 30};	//c
	s[3] = (SDL_Rect){.x = x, .y = y+40, .w = 30, .h = 10};		//d
	s[4] = (SDL_Rect){.x = x, .y = y+20, .w = 10, .h = 30};		//e
	s[5] = (SDL_Rect){.x = x, .y = y, .w = 10, .h = 30};		//f
	s[6] = (SDL_Rect){.x = x, .y = y+20, .w = 30, .h = 10};		//g

}
void display(SDL_Renderer *renderer, int score1, int score2){

	SDL_Rect d1[7];
	create_display(d1, 1);

	SDL_Rect d2[7];
	create_display(d2, 2);

	int on1 = SCORES[score2];
	int on2 = SCORES[score1];

	for(int i = 0; i < 7; i++){

		if(on1 & 1){

			render_display(renderer, d1[i]);
		}
		if(on2 & 1){

			render_display(renderer, d2[i]);
		}
		on1 /= 2;
		on2 /= 2;
	}
}
