#ifndef BALL_H
#define BALL_H
	
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "window.h"
#include "player.h"

extern Mix_Chunk *impactSound;
extern Mix_Chunk *wallSound;
extern Mix_Chunk *scoreSound;

typedef struct ball_t{
	SDL_Rect ball;
	int angulation;
	bool direction;
	bool increasing;
} ball;

void setup_ball();

void create_ball(ball *b);

void update_ball(ball *b, player *p1, player *p2);

	
#endif
