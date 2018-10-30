#include "Game.h"

void InitGrid(struct s_grid* grid) {
  int i,j;
  for(i=0; i<6; i++)
    for(j=0; j<6; j++)
      grid->grid[i][j]=0;
}

int FlipValue(int i) {
  if(i==0)
    i=1;
  else
    i=0;
  return i;
}

void ClickOnGrid(struct s_grid* grid, int column, int line) {
  grid->grid[line][column]=FlipValue(grid->grid[line][column]);

  if(line!=0)
    grid->grid[line-1][column]=FlipValue(grid->grid[line-1][column]);
  if(line!=5)
    grid->grid[line+1][column]=FlipValue(grid->grid[line+1][column]);
  if(column!=0)
    grid->grid[line][column-1]=FlipValue(grid->grid[line][column-1]);
  if(column!=5)
    grid->grid[line][column+1]=FlipValue(grid->grid[line][column+1]);
}

void GenerateGrid(struct s_grid* grid, struct s_options* options) {
  int computerClick;
  int column, line;
  int i;

  srand(time(NULL));
  if(options->difficulty==0) {
    computerClick=rand()%5+3;
  } else if(options->difficulty==1) {
    computerClick=rand()%10+6;
  } else if(options->difficulty==2) {
    computerClick=rand()%13+8;
  }

  options->maxClick=computerClick;

  for(i=0; i<computerClick; i++) {
    column=rand()%6;
    line=rand()%6;
    ClickOnGrid(grid, column, line);
  }
}

int GameWon(struct s_grid* grid) {
  int i,j;
  int gameWon=1;

  for(i=0; i<6; i++)
    for(j=0; j<6; j++)
      if(grid->grid[i][j]!=0)
        gameWon=0;

  return gameWon;
}
