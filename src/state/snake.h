#ifndef snake_h
#define snake_h

#include "../util/pos.h"
#include "grid.h"

typedef struct segment {
    Pos p;
    struct segment *next;
} Segment;

typedef struct {
    Segment *head, *tail;
} Snake;

Snake MakeSnake(Pos p);
void SetSnakeInGrid(Snake s, Grid *grid);
void KillSnake(Snake s);

#endif // !snake_h
