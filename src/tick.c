#include "state/gamestate.h"

void tick(GameState *gs) {
    static int ticks = 0;

    if(ticks++ > 60) {
        gs->x += 10;
        ticks = 0;
    }
}
