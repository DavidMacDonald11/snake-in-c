#include "state/gamestate.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void tick(GameState *);
void render(SDL_Renderer *, GameState *);

long long getNanoTime() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000000LL + ts.tv_nsec;
}

int main(int argc, char* args[]) {
    srand(time(NULL));

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    bool running = true;

    const int ticksPerSec = 5;
    const double ns = 1000000000.0 / ticksPerSec;

    long long lastTime = getNanoTime();
    double delta = 0;

    GameState gs = MakeGameState();

    while(running) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                gs.lastKeyPressed = event.key.keysym.sym;
                break;
            }
        }

        long long now = getNanoTime();
        delta += (now - lastTime) / ns;
        lastTime = now;

        if(delta >= 1) {
            tick(&gs);
            delta--;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        render(renderer, &gs);
        SDL_RenderPresent(renderer);
    }

    FreeGameState(&gs);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
