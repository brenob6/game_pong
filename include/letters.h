#ifndef LETTERS_H
#define LETTERS_H

#include <SDL2/SDL.h>

extern const int UNIT_LENGTH;

int increment(int amount, double scale);

void letter_p(SDL_Renderer *renderer, int x, int y, double scale);
void number_one(SDL_Renderer *renderer, int x, int y, double scale);
void number_two(SDL_Renderer *renderer, int x, int y, double scale);

void letter_w(SDL_Renderer *renderer, int x, int y, double scale);
void letter_i(SDL_Renderer *renderer, int x, int y, double scale);
void letter_n(SDL_Renderer *renderer, int x, int y, double scale);
void letter_s(SDL_Renderer *renderer, int x, int y, double scale);

#endif
