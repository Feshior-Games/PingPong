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

    // Update the x-coordinate to move right (based on velocity and deltaTime)
    double newX = rect.x + velocity * deltaTime;

    // Update the position
    setPosition(static_cast<int>(newX), rect.y);
}



SDL_Rect Ball::getBallReact() const {
    return collision;
}

