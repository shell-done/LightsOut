#include "Events.h"

int Actualize(struct s_options* options, struct s_grid* grid) {
  int actualize=0;
  int posX, posY;
  SDL_Event event;

  if(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_QUIT :
        options->quit=1;
        actualize=1;
        break;

      case SDL_MOUSEBUTTONUP:
        posX=event.button.x;
        posY=event.button.y;
        Click(posX, posY, options, grid);
        actualize=1;
        break;
    }
  }

  return actualize;
}

void Click(int posX, int posY, struct s_options* options, struct s_grid* grid) {
  if(options->gameStatus==0) {
    if(posX>=54 && posY>=191 && posX<=130 && posY<=267)
      options->difficulty=0;
    else if(posX>=54 && posY>=276 && posX<=130 && posY<=352)
      options->difficulty=1;
    else if(posX>=54 && posY>=361 && posX<=130 && posY<=437)
      options->difficulty=2;
    else if(posX>=302 && posY>=397 && posX<=446 && posY<=441) {
      options->gameStatus=1;
      GenerateGrid(grid, options);
    }
  }
  else if(options->gameStatus==1) {
    int i,j;
    for(i=0; i<6; i++)
      for(j=0; j<6; j++)
        if(posX>=5+80*i && posX<=80*(i+1) && posY>=5+80*j && posY<=80*(j+1))
          ClickOnGrid(grid, j, i);
    options->stroke++;
    options->gameStatus=GameWon(grid)+1;
  }
  else if(options->gameStatus==2) {
    if(posX>=311 && posY>=411 && posX<=441 && posY<=443) {
      options->gameStatus=0;
      options->stroke=0;
      options->maxClick=0;
    }
  }
}
