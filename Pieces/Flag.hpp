//
// Created by eros on 13/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_FLAG_HPP
#define CPP_STRATEGO_HAPPY_VAMPIRES_FLAG_HPP


#include "Piece.h"
#include "Thing.hpp"

class Flag : public Thing {
public:
    Flag(Rank rank, Color color,
         SDL_Texture *faceUpTexture = nullptr, SDL_Texture *backGroundTexture = nullptr,
         bool toBoard = false,
         bool isFaceDown = true)
            : Thing(rank, color, faceUpTexture, backGroundTexture, toBoard, isFaceDown){}
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_FLAG_HPP
