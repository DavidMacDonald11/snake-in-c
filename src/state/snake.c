#include <stdlib.h>
#include "snake.h"
#include "../util/color.h"

Snake MakeSnake(Pos p) {
    Segment *head = malloc(sizeof(Segment));
    head->p = p;
    head->next = NULL;

    return (Snake){.head=head, .tail=head};
}

void SetSnakeInGrid(Snake s, Grid *grid) {
    Color headColor = {.r=255, .g=255, .b=100, .a=255};

    Pos p = s.head->p;
    grid->grid[p.x][p.y] = headColor;
}

void KillSnake(Snake s) {
    Segment *ptr = s.head;

    while(ptr) {
        Segment *tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
