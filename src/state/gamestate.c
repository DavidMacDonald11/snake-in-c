#include "gamestate.h"
#include "grid.h"
#include "snake.h"
#include <SDL2/SDL_keycode.h>

GameState MakeGameState(Color gridBase, Pos snakePos) {
    Grid grid = MakeGrid(gridBase);
    Snake snake = MakeSnake(snakePos);

    return (GameState){.grid=grid, .snake=snake, .lastKeyPressed=SDLK_RIGHT};
}

void FreeGameState(GameState *gs) {
    FreeSnake(&gs->snake);
}
