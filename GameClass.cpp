//
// Created by vladyslav on 1/16/25.
//
#include "GameClass.h"

#include <iostream>
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

    if(!initializeBall())
        return false;

    return true;
}

bool GameClass::initializeBall() {
    int ballPositionX = 0;
    int ballPositionY = 0;
    if(SDL_GetRendererOutputSize(renderer, &ballPositionX, &ballPositionY) < 0) {
        return false;
    }
    ballPositionX /= 2;
    ballPositionY /= 2;
    ball = new Ball(ballPositionX, ballPositionY, 200, 200, renderer, "assets/ball.png");
    return true;
}

void GameClass::handleEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT)
            isRunning = false;
        if(event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_a:
                    ball->setVelocity(-10);
                    break;
                case SDLK_s:
                    ball->setVelocity(10);
                    break;
                case SDLK_d:
                    ball->setVelocity(0);
                    break;
                default:
                    break;
            }
        }
    }
}

bool GameClass::render() const {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    if(!ball->render()) {
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    SDL_RenderPresent(renderer);
    return true;
}

void GameClass::update() {
    Uint32 currentFrameTime = SDL_GetTicks();
    deltaTime = (currentFrameTime - lastFrameTime) / 1000.0f;
    lastFrameTime = currentFrameTime;
    ball->update(deltaTime);
}

void GameClass::run() {
    while(isRunning) {
        handleEvents();
        update();
        if(!render()) {
            std::cout << "Render has failed!; Stopping application;" <<std::endl;
            isRunning = false;
        }
    }
}

