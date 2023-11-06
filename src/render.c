#include "state/gamestate.h"
#include "state/snake.h"
#include <SDL2/SDL_render.h>

void render(SDL_Renderer *renderer, GameState *gs) {
    SetSnakeInGrid(gs->snake, &gs->grid);
    RenderGrid(renderer, &gs->grid);
}
