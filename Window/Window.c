#include "Window.h"

void InitWindow(SDL_Surface** screen) {
  SDL_Init(SDL_INIT_VIDEO);

  *screen=SDL_SetVideoMode(SCREEN_SIZE, SCREEN_SIZE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  SDL_WM_SetCaption("Lights Out", NULL);
  SDL_WM_SetIcon(IMG_Load(ICON), NULL);
}

void InitData(struct s_fonts* fonts, struct s_pictures* pictures) {
  TTF_Init();
  fonts->titleFont=TTF_OpenFont(CALIBRI, 55);
  fonts->textFont=TTF_OpenFont(CALIBRI, 25);

  pictures->menu=IMG_Load(MENU);
  pictures->grid=IMG_Load(GRID);
  pictures->winnerScreen=IMG_Load(WINNERSCREEN);
  pictures->lightOff=IMG_Load(LIGHTOFF);
}

void DisplayMenu(SDL_Surface* screen, struct s_pictures* pictures, struct s_options* options) {
  int i;
  int yPos[3] = {191,276,361};
  SDL_Rect lightPos;

  SDL_BlitSurface(pictures->menu, NULL, screen, NULL);
  for(i=0; i<3; i++)
    if(options->difficulty!=i) {
      lightPos.x=55;
      lightPos.y=yPos[i];
      SDL_BlitSurface(pictures->lightOff, NULL, screen, &lightPos);
    }

  SDL_Flip(screen);
}

void DisplayGame(struct s_grid* grid, struct s_options* options, struct s_pictures* pictures, SDL_Surface** screen) {
  int i,j;
  SDL_Rect pos;

  SDL_BlitSurface(pictures->grid, NULL, *screen, NULL);
  for(i=0; i<6; i++)
    for(j=0; j<6; j++)
      if(grid->grid[i][j]==0) {
        pos.x=5+i*80;
        pos.y=5+j*80;
        SDL_BlitSurface(pictures->lightOff, NULL, *screen, &pos);
      }

  SDL_Flip(*screen);
}

void DisplayWinnerScreen(struct s_options* options, struct s_pictures* pictures, struct s_fonts* fonts, SDL_Surface** screen) {
  SDL_Surface* text;
  SDL_Rect pos;
  SDL_Color textColor = {244,195,66};
  char textToDisplay[64];

  SDL_BlitSurface(pictures->winnerScreen, NULL, *screen, NULL);

  pos.x=40;
  pos.y=200;
  sprintf(textToDisplay, "You did it in %d strokes !", options->stroke);
  text=TTF_RenderText_Blended(fonts->textFont, textToDisplay, textColor);
  SDL_BlitSurface(text, NULL, *screen, &pos);

  pos.x=40;
  pos.y=250;
  sprintf(textToDisplay, "The minimum possible score was :");
  text=TTF_RenderText_Blended(fonts->textFont, textToDisplay, textColor);
  SDL_BlitSurface(text, NULL, *screen, &pos);

  pos.x=40;
  pos.y=275;
  sprintf(textToDisplay, "%d strokes", options->maxClick);
  text=TTF_RenderText_Blended(fonts->textFont, textToDisplay, textColor);
  SDL_BlitSurface(text, NULL, *screen, &pos);

  SDL_Flip(*screen);
}

void Quit(struct s_pictures* pictures, struct s_fonts* fonts, SDL_Surface** screen) {
  SDL_FreeSurface(*screen);
  SDL_FreeSurface(pictures->menu);
  SDL_FreeSurface(pictures->grid);
  SDL_FreeSurface(pictures->lightOff);
  TTF_CloseFont(fonts->titleFont);
  TTF_CloseFont(fonts->textFont);
  SDL_Quit();
  TTF_Quit();
}
