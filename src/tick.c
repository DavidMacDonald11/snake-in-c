#include "state/gamestate.h"
#include "state/snake.h"
#include <SDL2/SDL_keycode.h>

void tick(GameState *gs) {
    static int ticks = 0;

    SnakeDir dir;

    switch(gs->lastKeyPressed) {
    case SDLK_UP:
        dir = SnakeDir_Up;
        break;
    case SDLK_DOWN:
        dir = SnakeDir_Down;
        break;
    case SDLK_LEFT:
        dir = SnakeDir_Left;
        break;
    case SDLK_RIGHT:
        dir = SnakeDir_Right;
        break;
    }

    if(ticks++ > 30) {
        AddSegment(&gs->snake);
        MoveSnake(&gs->snake, dir);
        ticks = 0;
    }
}
