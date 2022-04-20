#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

extern const char *WINDOW_TITLE;

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

extern const SDL_Rect BORDER_UP;
extern const int BORDER_UP_Y;
extern const SDL_Rect BORDER_DOWN;
extern const int BORDER_DOWN_Y;

void render_borders(SDL_Renderer *render, SDL_Window *window);
void display(SDL_Renderer *renderer, int n, int side);

void create_display(SDL_Rect s[], int n);

#endif
