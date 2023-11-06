#include "grid.h"
#include <SDL2/SDL_render.h>

Grid MakeGrid(Color base) {
    Grid grid = {.base=base};

    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            grid.grid[i][j] = base;
        }
    }

    return grid;
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
