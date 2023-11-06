#include "state/gamestate.h"
#include <SDL2/SDL_render.h>

void render(SDL_Renderer *renderer, GameState *gs) {
    SDL_Rect square = {.x=gs->x, .y=gs->y, .w=10, .h=10};

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &square);
}
