//
// Created by vladyslav on 1/16/25.
//

#include "Ball.h"

Ball::Ball(const int x, const int y, const int width, const int height) : x(x), y(y), width(width), height(height) {
    collision = SDL_Rect{x,y,width,height};
}

void Ball::draw(SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
    SDL_RenderFillRect(renderer, &collision);
}

SDL_Rect Ball::getBallReact() const {
    return collision;
}

