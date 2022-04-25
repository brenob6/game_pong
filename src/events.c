#include "events.h"

	static const int PLAYER_SPEED = 7;

void handle_events(bool keys[], player *p1, player *p2){
	if(keys[UP]) p2->player.y -= PLAYER_SPEED;
	if(keys[DOWN]) p2->player.y += PLAYER_SPEED;
	if(keys[LETTER_W]) p1->player.y -= PLAYER_SPEED;
	if(keys[LETTER_S]) p1->player.y += PLAYER_SPEED;

	if(p2->player.y > 440) p2->player.y = 440;
	if(p2->player.y < 70) p2->player.y = 70;
	if(p1->player.y > 440) p1->player.y = 440;
	if(p1->player.y < 70) p1->player.y = 70;
}
