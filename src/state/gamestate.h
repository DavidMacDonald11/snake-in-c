#ifndef gamestate_h
#define gamestate_h

#include "grid.h"
#include "snake.h"

typedef struct {
    Grid grid;
    Snake snake;
} GameState;

GameState MakeGameState(Color gridBase, Pos snakePos);
void FreeGameState(GameState *gs);

#endif // !gamestate_h
