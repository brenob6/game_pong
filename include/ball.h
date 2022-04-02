#ifndef BALL_H
#define BALL_H
	
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct ball_t{
	SDL_Rect ball;
	int angulation;
	bool direction;
} ball;

void create_ball(ball *b);

void update_ball(ball *b, SDL_Rect *p1, SDL_Rect *p2); 
	
#endif
