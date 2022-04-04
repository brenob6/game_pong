#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

static const int WINDOW_WIDTH = 1200;
static const int WINDOW_HEIGHT = 600;

static const int BORDER_WIDTH = 1000;
static const int BORDER_HEIGHT = 10;

static const SDL_Rect BORDER_UP = { .x = 100, .y = 70, .w = BORDER_WIDTH, .h = BORDER_HEIGHT };
static const SDL_Rect BORDER_DOWN = { .x = 100, .y = 530, .w = BORDER_WIDTH, .h = BORDER_HEIGHT };

void render_borders(SDL_Renderer *render, SDL_Window *window);

#endif
