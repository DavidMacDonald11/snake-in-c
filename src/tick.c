#include "state/apple.h"
#include "state/gamestate.h"
#include "state/grid.h"
#include "state/snake.h"
#include "util/color.h"
#include <SDL2/SDL_keycode.h>

void tick(GameState *gs) {
    static int score = 0;
    static Pos p = {.x=0, .y=0};

    if(!gs->running) {
        if(score > 0) {
            gs->grid.grid[p.x][p.y] = (Color){.r=255, .g=255, .b=0, .a=255};

            score -= 10;
            p.x++;

            if(p.x == GRID_SIZE) {
                p.y++;
                p.x = 0;
            }
        }

        if(gs->lastKeyPressed == SDLK_RETURN) {
            ResetGame(gs);
            score = 0;
            p = (Pos){.x=0, .y=0};
        }

        return;
    }

    if(MoveSnake(&gs->snake, GetSnakeDirection(gs))) {
        StopGame(gs);
        return;
    }

    if(SnakeInsideItself(&gs->snake)) {
        StopGame(gs);
        return;
    }

    if(SnakeHitApple(gs)) {
        AddSegment(&gs->snake);
        score += 10;

        if(gs->snake.len == GRID_SIZE * GRID_SIZE) {
            StopGame(gs);
            return;
        }

        gs->apple = MakeApple(&gs->snake);
    }
}
