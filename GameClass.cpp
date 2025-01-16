//
// Created by vladyslav on 1/16/25.
//
#include "GameClass.h"
#include <SDL.h>
#include <SDL_image.h>

GameClass::GameClass() = default;
GameClass::~GameClass() {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
}


bool GameClass::init(std::string title, int width, int height) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;

    window = SDL_CreateWindow(title.c_str(),
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height, SDL_WINDOW_SHOWN);

    if(window == nullptr)
        return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
        return false;

    int imgFlags = IMG_INIT_PNG;
    //We only need png, so we are only checking if this subsystem was initialized
    if(!(IMG_Init(imgFlags) & imgFlags))
       return false;

    isRunning = true;

    return true;
}

void GameClass::handleEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT)
            isRunning = false;
    }
}

void GameClass::run() {
    while(isRunning) {
        handleEvents();
    }
}

