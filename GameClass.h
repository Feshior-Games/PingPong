//
// Created by vladyslav on 1/16/25.
//

#ifndef GAMECLASS_H
#define GAMECLASS_H
#include <SDL_render.h>
#include <SDL_video.h>
#include <string>
#include "Ball.h"

class GameClass{
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning = false;
    Ball* ball = nullptr;
    float deltaTime = 0.0f;
    Uint32 lastFrameTime = 0;

private:
    void handleEvents();
    bool render() const;
    void update();
    bool initializeBall();
public:
    GameClass();
    ~GameClass();

    /**
     * Initializes application
     * @param title Window title
     * @param width Window width
     * @param height Window height
     * @return
     */
    bool init(std::string title, int width, int height);

    void run();
};



#endif //GAMECLASS_H
