#include "ball.h"

Mix_Chunk *impactSound = NULL;
Mix_Chunk *wallSound = NULL;
Mix_Chunk *scoreSound = NULL;

static const int BALL_SIZE = 20;
static const int BALL_SPEED = 12;
static const int BALL_X = 580;

void setup_ball (){
	impactSound = Mix_LoadWAV( "sounds/impact.wav" );
	wallSound = Mix_LoadWAV( "sounds/wall.wav" );
	scoreSound = Mix_LoadWAV( "sounds/score.wav" );
}

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

	srand(time(NULL));

	b->ball.w = BALL_SIZE;
	b->ball.h = BALL_SIZE;
	b->ball.x = BALL_X;
	b->ball.y = BORDER_UP_Y + BALL_SIZE + 10 + (rand() % (BORDER_DOWN_Y - (2 * BALL_SIZE) - 10 - BORDER_UP_Y));
	b->direction = rand()%2;
	b->angulation = 1 + (rand()%9);
	b->increasing = rand()%2;
}

void update_ball(ball *b, player *p1, player *p2){

	b->ball.x += b->direction ? BALL_SPEED : -BALL_SPEED;
	b->ball.y += b->increasing ? b->angulation : -b->angulation;

	if(SDL_HasIntersection(&b->ball, &p1->player)){

		set_angulation(b, &p1->player);
		b->direction = !b->direction;
		Mix_PlayChannel( -1, impactSound, 0 );
	}

	if(SDL_HasIntersection(&b->ball, &p2->player)){

		set_angulation(b, &p2->player);
		b->direction = !b->direction;
		Mix_PlayChannel( -1, impactSound, 0 );
	}

	if(SDL_HasIntersection(&b->ball, &BORDER_UP) || SDL_HasIntersection(&b->ball, &BORDER_DOWN)){
		Mix_PlayChannel( -1, wallSound, 0 );

		swap_increasing(b);
	}

	if(b->ball.x < 50){

		Mix_PlayChannel( -1, scoreSound, 0 );
		p1->score++;
		SDL_Delay(200);
		create_ball(b);
		b->direction = false;
	}
	if(b->ball.x > 1150){

		Mix_PlayChannel( -1, scoreSound, 0 );
		p2->score++;
		SDL_Delay(200);
		create_ball(b);
		b->direction = true;
	}

}
