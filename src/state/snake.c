#include <stdlib.h>
#include "snake.h"
#include "../util/color.h"

Snake MakeSnake(Pos p) {
    Segment *head = malloc(sizeof(Segment));
    head->pos = p;
    head->next = NULL;

    return (Snake){.head=head, .tail=head};
}

void AddSegment(Snake *s) {
    Segment *segment = malloc(sizeof(Segment));
    segment->pos = s->tail->pos;
    segment->next = NULL;

    s->tail = s->tail->next = segment;
}

void RenderSnake(Snake *s, Grid *grid) {
    Color headColor = {.r=255, .g=255, .b=100, .a=255};
    Color bodyColor = {.r=255, .g=255, .b=255, .a=255};

    Pos p = s->head->pos;
    grid->grid[p.x][p.y] = headColor;

    for(Segment *ptr = s->head->next; ptr; ptr = ptr->next) {
        p = ptr->pos;
        grid->grid[p.x][p.y] = bodyColor;
    }
}

void MoveSnake(Snake *s, SnakeDir dir) {
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

    for(Segment *ptr = s->head->next; ptr; ptr = ptr->next) {
        Pos tmp = ptr->pos;
        ptr->pos = lastPos;
        lastPos = tmp;
    }
}

void FreeSnake(Snake *s) {
    Segment *ptr = s->head;

    while(ptr) {
        Segment *tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
