#include "color.h"

int SetRenderColor(SDL_Renderer *renderer, Color c) {
    return SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
}
