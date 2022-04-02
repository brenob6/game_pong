#include "ball.h"

static const int BALL_SIZE = 20;
static const int BALL_SPEED = 1;

void create_ball(ball *b){
	b->ball.w = BALL_SIZE;
	b->ball.h = BALL_SIZE;
	b->ball.x = 600;
	b->ball.y = 20;
	b->direction = true;
}

void update_ball(ball *b, SDL_Rect *p1, SDL_Rect *p2){
	b->ball.x += b->direction ? BALL_SPEED : -BALL_SPEED;

	if(SDL_HasIntersection(&b->ball, p1) || SDL_HasIntersection(&b->ball, p2)){

		b->direction = !b->direction;
	}
}
