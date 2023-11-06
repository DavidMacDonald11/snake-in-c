#ifndef snake_h
#define snake_h

#include "../util/pos.h"
#include "grid.h"

typedef struct segment {
    Pos pos;
    struct segment *next;
} Segment;

typedef enum {
    SnakeDir_Up,
    SnakeDir_Down,
    SnakeDir_Left,
    SnakeDir_Right
} SnakeDir;

typedef struct {
    Segment *head, *tail;
} Snake;

Snake MakeSnake(Pos p);
void AddSegment(Snake *s);
void RenderSnake(Snake *s, Grid *grid);
void MoveSnake(Snake *s, SnakeDir dir);
void FreeSnake(Snake *s);

#endif // !snake_h
