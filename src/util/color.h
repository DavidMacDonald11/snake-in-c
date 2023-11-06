#ifndef color_h
#define color_h

#include <SDL2/SDL_render.h>

typedef struct {
    unsigned char r, g, b, a;
} Color;

int SetRenderColor(SDL_Renderer *renderer, Color c);

#endif // !color_h
