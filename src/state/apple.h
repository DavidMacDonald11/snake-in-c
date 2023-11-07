#ifndef apple_h
#define apple_h

#include "../util/pos.h"
#include "snake.h"
#include <SDL2/SDL_render.h>

typedef struct {
    Pos pos;
} Apple;

Apple MakeApple(Snake *s);
void RenderApple(Apple *a, Grid *grid);

#endif // !apple_h
