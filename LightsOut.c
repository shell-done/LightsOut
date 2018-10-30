#include "LightsOut.h"

int main() {
  PlayGame();

  return EXIT_SUCCESS;
}

void PlayGame() {
  struct s_options options;
  struct s_grid grid;
  struct s_pictures pictures;
  struct s_fonts fonts;
  SDL_Surface* screen;

  options.quit=0;
  options.gameStatus=0;
  options.difficulty=0;
  options.stroke=0;

  InitGrid(&grid);
  InitWindow(&screen);
  InitData(&fonts, &pictures);

  while(!options.quit) {
    if(options.gameStatus==0)
      DisplayMenu(screen, &pictures, &options);

    if(options.gameStatus==1)
      DisplayGame(&grid, &options, &pictures, &screen);

    if(options.gameStatus==2)
      DisplayWinnerScreen(&options, &pictures, &fonts, &screen);

    while(!Actualize(&options, &grid))
      SDL_Delay(1.0/50);
  }

  Quit(&pictures, &fonts, &screen);
}
