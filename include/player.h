#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

typedef struct player_t{
	SDL_Rect player;
	int score;
} player;

void create_player(player *p, int number);
#endif
