#ifndef coord_h
#define coord_h

#include <stdbool.h>

typedef struct {
    int x, y;
} Pos;

bool PosEquals(Pos p1, Pos p2);

#endif // !coord_h
