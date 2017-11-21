//
// Created by eros on 13/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_THING_HPP
#define CPP_STRATEGO_HAPPY_VAMPIRES_THING_HPP


#include "Piece.h"

class Thing : public Piece {
public:
    Thing(Rank rank, Color color,
          SDL_Texture *faceUpTexture = nullptr, SDL_Texture *backGroundTexture = nullptr,
          bool toBoard = false,
          bool isFaceDown = true)
        : Piece(rank, color, faceUpTexture, backGroundTexture, toBoard, isFaceDown){}
    bool canMove() override {return false;}
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_THING_HPP
