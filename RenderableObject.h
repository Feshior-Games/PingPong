//
// Created by vladyslav on 1/17/25.
//

#ifndef RENDERABLEOBJECT_H
#define RENDERABLEOBJECT_H
#include <SDL_rect.h>
#include <SDL_render.h>
#include <string>


class RenderableObject {
private:
    SDL_Texture* texture;
    SDL_Rect rect{};
    SDL_Renderer* renderer;

protected:
    void setSize(int w, int h);
    void setPosition(int x, int y);

public:
    RenderableObject(SDL_Renderer* renderer, int x, int y, int w, int h, const char* textureFilename);
    virtual ~RenderableObject() {
        if (texture) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }
    }

    bool render() const;
    [[nodiscard]] SDL_Rect getBoundariesRect() const { return rect; }
};



#endif //RENDERABLEOBJECT_H
