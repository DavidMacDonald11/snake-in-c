#include "grid.h"
#include <SDL2/SDL_render.h>

Grid MakeGrid() {
    Color base = {.r=30, .g=30, .b=30, .a=255};
    Grid grid = {.base=base};
    ResetGrid(&grid);
    return grid;
}

void ResetGrid(Grid *grid) {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            grid->grid[i][j] = grid->base;
        }
    }
}

void RenderGrid(SDL_Renderer *renderer, Grid *grid) {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            Color c = grid->grid[i][j];

            int x = 10 * i + 1;
            int y = 10 * j + 1;
            SDL_Rect square = {.x=x, .y=y, .w=8, .h=8};

            SetRenderColor(renderer, c);
            SDL_RenderFillRect(renderer, &square);
        }
    }
}
