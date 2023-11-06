#include "state/gamestate.h"
#include "state/snake.h"
#include <SDL2/SDL_render.h>

void render(SDL_Renderer *renderer, GameState *gs) {
    ResetGrid(&gs->grid);
    RenderSnake(&gs->snake, &gs->grid);
    RenderGrid(renderer, &gs->grid);
}
