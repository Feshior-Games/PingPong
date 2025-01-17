//
// Created by vladyslav on 1/16/25.
//

#ifndef BALL_H
#define BALL_H
#include <SDL_render.h>

#include "RenderableObject.h"


class Ball : public RenderableObject{
private:
    int x;
    int y;
    int width;
    int height;
    SDL_Rect collision;
    SDL_Texture* texture;
    float velocity = 0;
    float angle = 0;

public:
    Ball(int x, int y, int width, int height, SDL_Renderer* renderer, const char* texturePath = "assets/ball.png");
    void draw(SDL_Renderer* renderer) const;
    [[nodiscard]] SDL_Rect getBallReact() const;
};



#endif //BALL_H
