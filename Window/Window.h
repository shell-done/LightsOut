#ifndef WINDOWS_H
#define WINDOWS_H

#include "../Includes.h"
#include "../Game.h"

void InitWindow(SDL_Surface** screen);
void InitData(struct s_fonts* fonts, struct s_pictures* pictures);
void DisplayMenu(SDL_Surface* screen, struct s_pictures* pictures, struct s_options* options);
void DisplayGame(struct s_grid* grid, struct s_options* options, struct s_pictures* pictures, SDL_Surface** screen);
void DisplayWinnerScreen(struct s_options* options, struct s_pictures* pictures, struct s_fonts* fonts, SDL_Surface** screen);
void Quit(struct s_pictures* pictures, struct s_fonts* fonts, SDL_Surface** screen);
#endif
