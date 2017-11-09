//
// Created by en on 2017.11.09..
//

#include "Piece.h"


Piece::Piece(SDL_Texture *texture) {
    sdl_rect.x = 100;
    sdl_rect.y = 100;
    sdl_rect.w = 100;
    sdl_rect.h = 100;
    this->texture = texture;
}

void Piece::render(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, texture, NULL, &sdl_rect);
}
