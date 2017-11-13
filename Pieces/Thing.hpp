//
// Created by eros on 13/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_THING_HPP
#define CPP_STRATEGO_HAPPY_VAMPIRES_THING_HPP


#include "Piece.h"

class Thing : public Piece {
public:
    Thing(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture, int isFaceDown)
        : Piece(x, y, rank, color, faceUpTexture, backGroundTexture, isFaceDown){}
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_THING_HPP
