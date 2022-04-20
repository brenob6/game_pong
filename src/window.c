#include "window.h"

const char *WINDOW_TITLE = "PONG";

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

static const int BORDER_WIDTH = 1000;
static const int BORDER_HEIGHT = 10;

const int BORDER_UP_Y = 70;
const int BORDER_DOWN_Y = 530;

const SDL_Rect BORDER_UP = {.x = 100, .y = BORDER_UP_Y, .w = BORDER_WIDTH, .h = BORDER_HEIGHT };

const SDL_Rect BORDER_DOWN = { .x = 100, .y = BORDER_DOWN_Y, .w = BORDER_WIDTH, .h = BORDER_HEIGHT };

void render_borders(SDL_Renderer *renderer, SDL_Window *window){

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &BORDER_UP);
	SDL_RenderFillRect(renderer, &BORDER_DOWN);
}

const int SCORE_8 = 0b1111111;

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
void display(SDL_Renderer *renderer, int n, int side){

//	const int x = 100;
//	const int y = 10;
	SDL_Rect d1[7];
	create_display(d1, 1);

	SDL_Rect d2[7];
	create_display(d2, 2);
//	SDL_Rect segments[7] = {
//
//		{.x = x, .y = y, .w = 30, .h = 10},			//a
//		{.x = x+20, .y = y, .w = 10, .h = 30},		//b
//		{.x = x+20, .y = y+20, .w = 10, .h = 30},	//c
//		{.x = x, .y = y+40, .w = 30, .h = 10},		//d
//		{.x = x, .y = y+20, .w = 10, .h = 30},		//e
//		{.x = x, .y = y, .w = 10, .h = 30},			//f
//		{.x = x, .y = y+20, .w = 30, .h = 10}		//g
//
//	};

	int on1 = SCORE_8;
	int on2 = SCORE_8;

	for(int i = 0; i < 7; i++){

		if(on1 % 0b10){

			render_display(renderer, d1[i]);
			on1 /= 0b10;
		}
		if(on2 % 0b10){

			render_display(renderer, d2[i]);
			on2 /= 0b10;
		}
	}
}
