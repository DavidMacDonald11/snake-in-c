#include "state/gamestate.h"
#include "state/grid.h"
#include "state/snake.h"
#include <SDL2/SDL_render.h>

void render(SDL_Renderer *renderer, GameState *gs) {
    if(!gs->running) {
        RenderGrid(renderer, &gs->grid);
        return;
    }

    ResetGrid(&gs->grid);
    RenderSnake(&gs->snake, &gs->grid);
    RenderApple(&gs->apple, &gs->grid);
    RenderGrid(renderer, &gs->grid);
}
