//
// Created by vladyslav on 1/16/25.
//

#include "Ball.h"

#include <SDL_image.h>

Ball::Ball(const int x, const int y, const int width, const int height, SDL_Renderer* renderer, const char* textureFilePath)
: RenderableObject(renderer, x,y,width,height,textureFilePath),
    x(x), y(y), width(width), height(height) {
    collision = SDL_Rect{x, y, width, height};
}

void Ball::draw(SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
    SDL_RenderFillRect(renderer, &collision);
}

SDL_Rect Ball::getBallReact() const {
    return collision;
}

