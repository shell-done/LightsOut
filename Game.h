#ifndef GAME_H
#define GAME_H

#include "Includes.h"
#include "time.h"

void InitGrid(struct s_grid* grid);
int FlipValue(int i);
void ClickOnGrid(struct s_grid* grid, int column, int line);
void GenerateGrid(struct s_grid* grid, struct s_options* options);
int GameWon(struct s_grid* grid);

#endif
