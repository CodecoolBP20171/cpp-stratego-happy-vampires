//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_PIECE_H
#define STRATEGO_HAPPY_VAMPIRES_PIECE_H


#include <SDL_render.h>

class Piece {
public:
    Piece(SDL_Texture *texture);
    void render(SDL_Renderer* renderer);

private:
    SDL_Texture *texture = nullptr;
    SDL_Rect sdl_rect;
};


#endif //STRATEGO_HAPPY_VAMPIRES_PIECE_H
