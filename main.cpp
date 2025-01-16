#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "GameClass.h"


int main() {
    GameClass game;
    if(!game.init("Ping pong", 1280, 720)) {
        printf("Failed to initialize game -> %s\n", SDL_GetError());
        return 1;
    }

    game.run();

    return 0;
}
