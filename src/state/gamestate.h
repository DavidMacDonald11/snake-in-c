#ifndef gamestate_h
#define gamestate_h

#include <SDL2/SDL_keycode.h>
#include "grid.h"
#include "snake.h"

typedef struct {
    Grid grid;
    Snake snake;
    SDL_Keycode lastKeyPressed;
} GameState;

GameState MakeGameState(Color gridBase, Pos snakePos);
void FreeGameState(GameState *gs);

#endif // !gamestate_h
