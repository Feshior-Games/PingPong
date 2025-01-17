//
// Created by vladyslav on 1/17/25.
//
#include "RenderableObject.h"
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



