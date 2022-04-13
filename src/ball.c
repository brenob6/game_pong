#include "ball.h"

static const int BALL_SIZE = 20;
static const int BALL_SPEED = 10;
static const int BALL_X = 580;
static const int BALL_Y = 280;

static void swap_increasing(ball *b){

	b->increasing = !b->increasing;
}

static void set_angulation(ball *b, const SDL_Rect *p){

	float a = abs(p->y - b->ball.y) / 20.0;
	a = roundf(a);

	if((int)a == 0 || (int)a == 1 || (int)a == 2){
		if(b->increasing) swap_increasing(b);
	}else
		if(!b->increasing) swap_increasing(b);


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

	b->angulation = a;
}

void create_ball(ball *b){

	b->ball.w = BALL_SIZE;
	b->ball.h = BALL_SIZE;
	b->ball.x = BALL_X;
	b->ball.y = BALL_Y;
	b->direction = true;
	b->angulation = 0;
	b->increasing = true;
}

void update_ball(ball *b, SDL_Rect *p1, SDL_Rect *p2){

	b->ball.x += b->direction ? BALL_SPEED : -BALL_SPEED;
	b->ball.y += b->increasing ? b->angulation : -b->angulation;

	if(SDL_HasIntersection(&b->ball, p1)){

		set_angulation(b, p1);
		b->direction = !b->direction;
	}

	if(SDL_HasIntersection(&b->ball, p2)){

		set_angulation(b, p2);
		b->direction = !b->direction;
	}

	if(SDL_HasIntersection(&b->ball, &BORDER_UP) || SDL_HasIntersection(&b->ball, &BORDER_DOWN)){

		swap_increasing(b);
	}

	if(b->ball.x < 50 || b->ball.x > 1150){

		SDL_Delay(200);
		create_ball(b);
	}

}
