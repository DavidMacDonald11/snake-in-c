#ifndef grid_h
#define grid_h

#include <SDL2/SDL_render.h>
#include "../util/color.h"

#define GRID_SIZE 48

typedef struct {
    Color base;
    Color grid[GRID_SIZE][GRID_SIZE];
} Grid;

Grid MakeGrid(Color base);
void ResetGrid(Grid *grid);
void RenderGrid(SDL_Renderer *renderer, Grid *grid);

#endif // !grid_h
