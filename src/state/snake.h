#ifndef snake_h
#define snake_h

#include "../util/pos.h"
#include "grid.h"
#include <stdbool.h>

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
    int len;
    SnakeDir lastDir;
    Segment *head, *tail;
} Snake;

Snake MakeSnake(Pos p);
void AddSegment(Snake *s);
void RenderSnake(Snake *s, Grid *grid);
bool MoveSnake(Snake *s, SnakeDir dir);
bool PosInSnake(Snake *s, Pos pos);
bool SnakeInsideItself(Snake *s);
void FreeSnake(Snake *s);

#endif // !snake_h
