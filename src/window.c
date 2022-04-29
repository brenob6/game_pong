#include "window.h"
#include "letters.h"

const char *WINDOW_TITLE = "PONG";

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;

static const int BORDER_WIDTH = 1000;
static const int BORDER_HEIGHT = 10;

const int BORDER_UP_Y = 70;
const int BORDER_DOWN_Y = 530;

Mix_Chunk *winSound = NULL;

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

	0x3F,
	0x30,
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7C,
	0x07,
	0x7F,
	0x67
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

	int x = 0;
	int y = 0;

	letter_p(renderer, x + increment(6, 1), y + increment(1, 0.3), 0.3);
	number_two(renderer, x + increment(4, 0.3) + increment(6, 1), y + increment(1, 0.3), 0.3);

	letter_p(renderer, x + increment(26, 1), y + increment(1, 0.3), 0.3);
	number_one(renderer, x + increment(4, 0.3) + increment(26, 1), y + increment(1, 0.3), 0.3);

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

void window_start(SDL_Renderer *renderer, TTF_Font *font){
	if(winSound == NULL) {
		winSound = Mix_LoadWAV( "sounds/win.wav" );
	}

	int x = 350, y = 230;

	int y3 = 337, y2 = 290;

	SDL_SetRenderDrawColor(renderer,255,255,255,255);

	//Letra P
	SDL_Rect rectp = {x,y,35,140};
	SDL_RenderFillRect(renderer, &rectp);
	SDL_Rect rectp1 = {x,y,105,33};
	SDL_RenderFillRect(renderer, &rectp1);
	SDL_Rect rectp2 = {x + 100, y,35,70};
	SDL_RenderFillRect(renderer, &rectp2);
	SDL_Rect rectp3 = {x,y2,135,33};
	SDL_RenderFillRect(renderer, &rectp3);

	//Letra O
	SDL_Rect recto = {x+145,y,35,140};	
	SDL_RenderFillRect(renderer, &recto);
	SDL_Rect recto1 = {x+145,y,105,33};
	SDL_RenderFillRect(renderer, &recto1);
	SDL_Rect recto2 = {570,y,35,140};
	SDL_RenderFillRect(renderer, &recto2);
	SDL_Rect recto3 = {x+145,y3,105,33};
	SDL_RenderFillRect(renderer, &recto3);
	
	//Letra N
	SDL_Rect rectn = {615,y,35,140};
	SDL_RenderFillRect(renderer, &rectn);
	SDL_Rect rectn1 = {615,y,66,33};
	SDL_RenderFillRect(renderer, &rectn1);
	SDL_Rect rectn2 = {663,y,35,140};
	SDL_RenderFillRect(renderer, &rectn2);
	SDL_Rect rectn3 = {663,y3,66,33};
	SDL_RenderFillRect(renderer, &rectn3);
	SDL_Rect rectn4 = {711,y,35,140};
	SDL_RenderFillRect(renderer, &rectn4);

	//Letra G
	SDL_Rect rectg = {755,y,117,33};
	SDL_RenderFillRect(renderer, &rectg);
	SDL_Rect rectg1 = {755,y,35,140};
	SDL_RenderFillRect(renderer, &rectg1);
	SDL_Rect rectg2 = {755,y3,105,33};
	SDL_RenderFillRect(renderer, &rectg2);
	SDL_Rect rectg3 = {838,y2,35,80};
	SDL_RenderFillRect(renderer, &rectg3);
	SDL_Rect rectg4 = {805,y2,68,33};
	SDL_RenderFillRect(renderer, &rectg4);

	SDL_Color white = {255, 255, 255};
	SDL_Surface *surfaceText = TTF_RenderText_Solid(font, "<Press space to start>", white);

	SDL_Texture *textureText = SDL_CreateTextureFromSurface(renderer, surfaceText);

	SDL_FreeSurface(surfaceText);

	SDL_Rect mensage;
	mensage.x = 400;
	mensage.y = 500;
	mensage.w = 400;
	mensage.h = 50;


	SDL_RenderCopy(renderer, textureText, NULL, &mensage);

	SDL_RenderPresent(renderer); 
}

void player_one_wins(SDL_Renderer *renderer) {
	int x = WINDOW_WIDTH / 2 - (increment(5, 1) / 2);
	int y = WINDOW_HEIGHT / 2 - (increment(6, 1));

	letter_p(renderer, x, y, 1);
	number_one(renderer, x + increment(4, 1), y, 1);
}

void player_two_wins(SDL_Renderer *renderer) {
	int x = WINDOW_WIDTH / 2 - (increment(7, 1)) / 2;
	int y = WINDOW_HEIGHT / 2 - (increment(6, 1));

	letter_p(renderer, x, y, 1);
	number_two(renderer, x + increment(4, 1), y, 1);
}

void window_over(SDL_Renderer *renderer, int score1, int score2) {
	SDL_SetRenderDrawColor(renderer,255,255,255,255);

	if(score1 > score2) {
		player_one_wins(renderer);
	} else {
		player_two_wins(renderer);
	}

	int x = WINDOW_WIDTH / 2 - (increment(18, 1)) / 2;
	int y = WINDOW_HEIGHT / 2 - (increment(5, 1));

	letter_w(renderer, x, y + increment(6, 1), 1);
	letter_i(renderer, x + increment(6, 1), y + increment(6, 1), 1);
	letter_n(renderer, x + increment(10, 1), y + increment(6, 1), 1);
	letter_s(renderer, x + increment(15, 1), y + increment(6, 1), 1);

	SDL_RenderPresent(renderer); 
}
