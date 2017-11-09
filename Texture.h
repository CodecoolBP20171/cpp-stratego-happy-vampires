//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_TEXTURE_H
#define STRATEGO_HAPPY_VAMPIRES_TEXTURE_H


#include <SDL_render.h>

class Texture {
public:
    Texture(SDL_Texture* texture);
    ~Texture();
    void render(SDL_Renderer* renderer, const SDL_Rect* pos);
    SDL_Texture* getSDLTexture(){return texture;}
private:
    SDL_Texture* texture;
};


#endif //STRATEGO_HAPPY_VAMPIRES_TEXTURE_H

