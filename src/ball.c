#include "ball.h"
#include "window.h"

static const int BALL_SIZE = 20;
static const int BALL_SPEED = 2;

void create_ball(ball *b){
	b->ball.w = BALL_SIZE;
	b->ball.h = BALL_SIZE;
	b->ball.x = 600;
	b->ball.y = 300;
	b->direction = true;
	b->angulation = 1;
}

void update_ball(ball *b, SDL_Rect *p1, SDL_Rect *p2){
	b->ball.x += b->direction ? BALL_SPEED : -BALL_SPEED;
	b->ball.y += b->angulation;

	if(SDL_HasIntersection(&b->ball, p1) || SDL_HasIntersection(&b->ball, p2)){

		b->direction = !b->direction;
	}
	if(SDL_HasIntersection(&b->ball, &BORDER_UP) || SDL_HasIntersection(&b->ball, &BORDER_DOWN)){

		b->angulation *= -1;
	}
}
