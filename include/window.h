#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT; 

extern const SDL_Rect BORDER_UP;
extern const SDL_Rect BORDER_DOWN;

void render_borders(SDL_Renderer *render, SDL_Window *window);

#endif
