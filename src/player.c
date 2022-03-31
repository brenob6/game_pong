#include "player.h"

static const int PLAYER_WIDTH = 20;
static const int PLAYER_HEIGHT = 100;
static const int CENTER = 300;
static const int PLAYER1_X = 100;
static const int PLAYER2_X = 1100;

void create_player(player *p, int number){
	p->score = 0;
	p->player.w = PLAYER_WIDTH;
	p->player.h = PLAYER_HEIGHT;
	p->player.y = CENTER;
	p->player.x = (number == 1) ? PLAYER1_X : PLAYER2_X;
}
