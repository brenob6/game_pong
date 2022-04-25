#include "letters.h"

const int UNIT_LENGTH = 35;

int increment(int amount, double scale) {
    return amount * UNIT_LENGTH * scale;
}

void letter_p(SDL_Renderer *renderer, int x, int y, double scale) {
	SDL_Rect rectp1 = {x + increment(0, scale),y + increment(0, scale),increment(1, scale),increment(5, scale)};
	SDL_RenderFillRect(renderer, &rectp1);
	SDL_Rect rectp2 = {x + increment(1, scale),y + increment(0, scale),increment(2, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp2);
	SDL_Rect rectp3 = {x + increment(1, scale),y + increment(2, scale),increment(2, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp3);
	SDL_Rect rectp4 = {x + increment(2, scale),y + increment(1, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp4);
}

void number_one(SDL_Renderer *renderer, int x, int y, double scale) {
	SDL_Rect rectp1 = {x + increment(0, scale),y + increment(0, scale),increment(1, scale),increment(5, scale)};
	SDL_RenderFillRect(renderer, &rectp1);
}

void number_two(SDL_Renderer *renderer, int x, int y, double scale) {
	SDL_Rect rectp1 = {x + increment(0, scale),y + increment(0, scale),increment(3, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp1);
	SDL_Rect rectp2 = {x + increment(2, scale),y + increment(1, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp2);
	SDL_Rect rectp3 = {x + increment(1, scale),y + increment(2, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp3);
    SDL_Rect rectp4 = {x + increment(0, scale),y + increment(3, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp4);
    SDL_Rect rectp5 = {x + increment(0, scale),y + increment(4, scale),increment(3, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp5);
}

void letter_w(SDL_Renderer *renderer, int x, int y, double scale) {
	SDL_Rect rectp1 = {x + increment(0, scale),y + increment(0, scale),increment(1, scale),increment(4, scale)};
	SDL_RenderFillRect(renderer, &rectp1);
	SDL_Rect rectp2 = {x + increment(1, scale),y + increment(4, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp2);
	SDL_Rect rectp3 = {x + increment(2, scale),y + increment(2, scale),increment(1, scale),increment(2, scale)};
	SDL_RenderFillRect(renderer, &rectp3);
	SDL_Rect rectp4 = {x + increment(3, scale),y + increment(4, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp4);
    SDL_Rect rectp5 = {x + increment(4, scale),y + increment(0, scale),increment(1, scale),increment(4, scale)};
	SDL_RenderFillRect(renderer, &rectp5);
}

void letter_i(SDL_Renderer *renderer, int x, int y, double scale) {
	SDL_Rect rectp1 = {x + increment(0, scale),y + increment(0, scale),increment(3, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp1);
	SDL_Rect rectp2 = {x + increment(1, scale),y + increment(1, scale),increment(1, scale),increment(3, scale)};
	SDL_RenderFillRect(renderer, &rectp2);
	SDL_Rect rectp3 = {x + increment(0, scale),y + increment(4, scale),increment(3, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp3);
}

void letter_n(SDL_Renderer *renderer, int x, int y, double scale) {
	SDL_Rect rectp1 = {x + increment(0, scale),y + increment(0, scale),increment(1, scale),increment(5, scale)};
	SDL_RenderFillRect(renderer, &rectp1);
	SDL_Rect rectp2 = {x + increment(1, scale),y + increment(2, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp2);
	SDL_Rect rectp3 = {x + increment(2, scale),y + increment(3, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp3);
    SDL_Rect rectp4 = {x + increment(3, scale),y + increment(0, scale),increment(1, scale),increment(5, scale)};
	SDL_RenderFillRect(renderer, &rectp4);
}

void letter_s(SDL_Renderer *renderer, int x, int y, double scale) {
	SDL_Rect rectp1 = {x + increment(0, scale),y + increment(0, scale),increment(3, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp1);
	SDL_Rect rectp2 = {x + increment(0, scale),y + increment(1, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp2);
	SDL_Rect rectp3 = {x + increment(1, scale),y + increment(2, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp3);
    SDL_Rect rectp4 = {x + increment(2, scale),y + increment(3, scale),increment(1, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp4);
    SDL_Rect rectp5 = {x + increment(0, scale),y + increment(4, scale),increment(3, scale),increment(1, scale)};
	SDL_RenderFillRect(renderer, &rectp5);
}