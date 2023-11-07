#include <stdlib.h>
#include "grid.h"
#include "snake.h"
#include "../util/color.h"

Snake MakeSnake(Pos p) {
    Segment *head = malloc(sizeof(Segment));
    head->pos = p;
    head->next = NULL;

    return (Snake){
        .head=head,
        .tail=head,
        .len=1,
        .lastDir=SnakeDir_Right,
    };
}

void AddSegment(Snake *s) {
    Segment *segment = malloc(sizeof(Segment));
    segment->pos = s->tail->pos;
    segment->next = NULL;

    s->tail = s->tail->next = segment;
    s->len++;
}

void RenderSnake(Snake *s, Grid *grid) {
    Color headColor = {.r=255, .g=255, .b=100, .a=255};
    Color bodyColor = {.r=255, .g=255, .b=255, .a=255};

    Pos p;

    for(Segment *ptr = s->head->next; ptr; ptr = ptr->next) {
        p = ptr->pos;
        grid->grid[p.x][p.y] = bodyColor;
    }

    p = s->head->pos;
    grid->grid[p.x][p.y] = headColor;
}

// Returns true if snake is out of bounds
bool MoveSnake(Snake *s, SnakeDir dir) {
    s->lastDir = dir;

    Pos *pos = &s->head->pos;
    Pos lastPos = *pos;

    switch(dir) {
    case SnakeDir_Up:
        pos->y--;
        break;
    case SnakeDir_Down:
        pos->y++;
        break;
    case SnakeDir_Left:
        pos->x--;
        break;
    case SnakeDir_Right:
        pos->x++;
    }

    bool badY = (pos->y < 0 || pos->y >= GRID_SIZE);
    bool badX = (pos->x < 0 || pos->x >= GRID_SIZE);

    if(badY || badX) {
        return true;
    }

    for(Segment *ptr = s->head->next; ptr; ptr = ptr->next) {
        Pos tmp = ptr->pos;
        ptr->pos = lastPos;
        lastPos = tmp;
    }

    return false;
}

bool PosInSnake(Snake *s, Pos pos) {
    for(Segment *ptr = s->head; ptr; ptr = ptr->next) {
        if(PosEquals(ptr->pos, pos)) {
            return true;
        }
    }

    return false;
}

bool SnakeInsideItself(Snake *s) {
    if(s->len < 3) return false;

    for(Segment *ptr = s->head->next; ptr; ptr = ptr->next) {
        if(PosEquals(s->head->pos, ptr->pos)) {
            return true;
        }
    }

    return false;
}

void FreeSnake(Snake *s) {
    Segment *ptr = s->head;

    while(ptr) {
        Segment *tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
