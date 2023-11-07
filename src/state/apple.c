#include "apple.h"
#include "grid.h"
#include "snake.h"

Apple MakeApple(Snake *s) {
    int boxesLeft = GRID_SIZE * GRID_SIZE - s->len;
    int box = rand() % boxesLeft;

    Pos pos;

    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            pos = (Pos){.x=i, .y=j};
            if(PosInSnake(s, pos)) continue;

            box--;
            if(box == 0) goto end;
        }
    }
    end:

    return (Apple){.pos=pos};
}

void RenderApple(Apple *a, Grid *grid) {
    Color c = {.r=255, .g=0, .b=0, .a=255};
    Pos p = a->pos;
    grid->grid[p.x][p.y] = c;
}
