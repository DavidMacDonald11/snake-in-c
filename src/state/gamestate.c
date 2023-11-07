#include "gamestate.h"
#include "grid.h"
#include "snake.h"
#include <SDL2/SDL_keycode.h>

GameState MakeGameState() {
    GameState gs = {};
    ResetGame(&gs);
    return gs;
}

bool SnakeHitApple(GameState *gs) {
    return PosEquals(gs->snake.head->pos, gs->apple.pos);
}

SnakeDir GetSnakeDirection(GameState *gs) {
    switch(gs->lastKeyPressed) {
    case SDLK_UP:
        return SnakeDir_Up;
    case SDLK_DOWN:
        return SnakeDir_Down;
    case SDLK_LEFT:
        return SnakeDir_Left;
    case SDLK_RIGHT:
        return SnakeDir_Right;
    }

    return gs->snake.lastDir;
}

void StopGame(GameState *gs) {
    gs->running = false;
    ResetGrid(&gs->grid);
}

void ResetGame(GameState *gs) {
    gs->grid = MakeGrid();
    gs->snake = MakeSnake((Pos){.x=24, .y=24});
    gs->apple = MakeApple(&gs->snake);
    gs->lastKeyPressed = SDLK_RIGHT;
    gs->running = true;
}

void FreeGameState(GameState *gs) {
    FreeSnake(&gs->snake);
}
