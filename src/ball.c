#include "ball.h"

static const int SIZE_BALL = 20;
static const int SPEED_BALL = 1;

void create_ball(ball *b){
	b->ball.w = SIZE_BALL;
	b->ball.h = SIZE_BALL;
	b->ball.x = 600;
	b->ball.y = 20;
}
