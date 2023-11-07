#ifndef gamestate_h
#define gamestate_h

#include <SDL2/SDL_keycode.h>
#include "apple.h"
#include "grid.h"
#include "snake.h"

typedef struct {
    Grid grid;
    Snake snake;
    Apple apple;
    SDL_Keycode lastKeyPressed;
    bool running;
} GameState;

GameState MakeGameState();
bool SnakeHitApple(GameState *gs);
SnakeDir GetSnakeDirection(GameState *gs);
void StopGame(GameState *gs);
void ResetGame(GameState *gs);
void FreeGameState(GameState *gs);

#endif // !gamestate_h
