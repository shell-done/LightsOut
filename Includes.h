#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

struct s_options {
  int quit;
  int gameStatus;
  int difficulty;
  int maxClick;
  int stroke;
};

struct s_grid {
  int grid[6][6];
};

struct s_fonts {
  TTF_Font* titleFont;
  TTF_Font* textFont;
};

struct s_pictures {
  SDL_Surface* menu;
  SDL_Surface* grid;
  SDL_Surface* winnerScreen;
  SDL_Surface* lightOff;
};

#define SCREEN_SIZE 485
#define CALIBRI "Data/Calibri.ttf"
#define MENU "Data/Menu.png"
#define GRID "Data/Grid.png"
#define LIGHTOFF "Data/LightOff.png"
#define WINNERSCREEN "Data/WinnerScreen.png"
#define ICON "Data/Icon.png"

#endif
