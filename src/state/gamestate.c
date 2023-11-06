#include "gamestate.h"
#include "grid.h"
#include "snake.h"

GameState MakeGameState(Color gridBase, Pos snakePos) {
    Grid grid = MakeGrid(gridBase);
    Snake snake = MakeSnake(snakePos);

    return (GameState){.grid=grid, .snake=snake};
}

void FreeGameState(GameState *gs) {
    KillSnake(gs->snake);
}
