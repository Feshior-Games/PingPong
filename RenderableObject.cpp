//
// Created by vladyslav on 1/17/25.
//
#include "RenderableObject.h"

#include <iostream>
#include <SDL_image.h>

RenderableObject::RenderableObject(SDL_Renderer* renderer, const int x, const int y, const int w, const int h,
                                   const char* textureFilename) {
    this->renderer = renderer;
    rect = SDL_Rect { x, y, w, h };
    texture = IMG_LoadTexture(renderer, textureFilename);
}

bool RenderableObject::render() const {
    if(texture && renderer) {
        SDL_RenderCopy(renderer, texture,nullptr, &rect);
        return true;
    }
    return false;
}

void RenderableObject::getRendererBoundaries(int &screenWidth, int &screenHeight) const {
    SDL_GetRendererOutputSize(renderer, &screenWidth, &screenHeight);
}


void RenderableObject::setPosition(const int x, const int y) {
    // std::cout << x <<std::endl;
    // std::cout << y <<std::endl;
    rect = SDL_Rect{x, y, rect.w, rect.h};
}



