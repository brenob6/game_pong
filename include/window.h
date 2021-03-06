#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

extern const char *WINDOW_TITLE;

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

extern const SDL_Rect BORDER_UP;
extern const int BORDER_UP_Y;
extern const SDL_Rect BORDER_DOWN;
extern const int BORDER_DOWN_Y;

extern Mix_Chunk *winSound;

void window_start(SDL_Renderer *renderer, TTF_Font *font);
void window_over(SDL_Renderer *renderer, int score1, int score2);

void render_borders(SDL_Renderer *render);
void display(SDL_Renderer *renderer, int score1, int score2);

void create_display(SDL_Rect s[], int n); 


#endif
