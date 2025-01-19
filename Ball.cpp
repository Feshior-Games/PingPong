//
// Created by vladyslav on 1/16/25.
//

#include "Ball.h"

#include <iostream>
#include <SDL_image.h>

Ball::Ball(const int x, const int y, const int width, const int height, SDL_Renderer* renderer, const char* textureFilePath)
: RenderableObject(renderer, x,y,width,height,textureFilePath),
    width(width), height(height) {
    collision = SDL_Rect{x, y, width, height};
}

void Ball::draw(SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
    SDL_RenderFillRect(renderer, &collision);
}

void Ball::update(float deltaTime) {
    SDL_Rect rect = getBoundariesRect();

    int screenWidth, screenHeight;
    getRendererBoundaries(screenWidth, screenHeight);

    // Update the x-coordinate to move right (based on velocity and deltaTime)
    double newX;
    double movedDistance = velocity * 0.01;
    std::cout << movedDistance << std::endl;
    newX = rect.x + movedDistance;

    //Because of the rounding, it moves only to the left 5-0.01 = 4.99 (rounded to 4)
    //If we add 0.01 to 5, it will move to the right 5+0.01 = 5.01 (rounded to 5)
    //So, that's why it's not moving to the right
    if (newX < 0) {
        newX = 0; // Prevent moving off the left side
    } else if (newX >= screenWidth) {
        newX = screenWidth;
    }

    // Update the position
    setPosition(static_cast<int>(newX), rect.y);
}



SDL_Rect Ball::getBallReact() const {
    return collision;
}

void Ball::setVelocity(const float velocity) {
    this->velocity = velocity;
}
