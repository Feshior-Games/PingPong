//
// Created by vladyslav on 1/16/25.
//

#ifndef BALL_H
#define BALL_H
#include <SDL_render.h>


class Ball {
private:
    int x;
    int y;
    int width;
    int height;
    SDL_Rect collision;
public:
    Ball(int x, int y, int width, int height);
    void draw(SDL_Renderer* renderer) const;
    [[nodiscard]] SDL_Rect getBallReact() const;
};



#endif //BALL_H
