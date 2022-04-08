#include "ball.h"
#include "window.h"

static const int BALL_SIZE = 20;
static const int BALL_SPEED = 10;

static int angulation(int By, int Py){

	float a = abs(Py - By) / 20.0;
	a = roundf(a);

	switch((int) a){

		case 0:
		case 5:
			a = 9;
			break;
		case 1:
		case 4:
			a = 7;
			break;
		case 2:
		case 3:
			a = 5;
			break;
	}
	return a;
}
	
void create_ball(ball *b){
	b->ball.w = BALL_SIZE;
	b->ball.h = BALL_SIZE;
	b->ball.x = 600;
	b->ball.y = 300;
	b->direction = true;
	b->angulation = 0;
}

void update_ball(ball *b, SDL_Rect *p1, SDL_Rect *p2){
	b->ball.x += b->direction ? BALL_SPEED : -BALL_SPEED;
	b->ball.y += b->angulation;

	if(SDL_HasIntersection(&b->ball, p1)){

		b->angulation = angulation(b->ball.y, p1->y);
		b->direction = !b->direction;
	}
		
	if(SDL_HasIntersection(&b->ball, p2)){

		b->angulation = angulation(b->ball.y, p2->y);
		b->direction = !b->direction;
	}
	if(SDL_HasIntersection(&b->ball, &BORDER_UP) || SDL_HasIntersection(&b->ball, &BORDER_DOWN)){

		b->angulation *= -1;
	} 
}
