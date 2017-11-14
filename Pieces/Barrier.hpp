//
// Created by eros on 13/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_BARRIER_HPP
#define CPP_STRATEGO_HAPPY_VAMPIRES_BARRIER_HPP


#include "Piece.h"
#include "Thing.hpp"

class Barrier : public Thing {
public:
    Barrier(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture = nullptr, SDL_Texture *backGroundTexture = nullptr, bool toBoard = true, bool isFaceDown = true)
            : Thing(x, y, rank, color){}
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_BARRIER_HPP
