#ifndef EVENTS_H
#define EVENTS_H

#include <SDL2/SDL.h>

#include <stdbool.h>

#include <player.h>

enum key_map {UP, DOWN, LETTER_W, LETTER_S};

void handle_events(bool keys[], player *p1, player *p2);

#endif
