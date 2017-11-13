//
// Created by eros on 13/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_BOMB_HPP
#define CPP_STRATEGO_HAPPY_VAMPIRES_BOMB_HPP


#include "Thing.hpp"

class Bomb : public Thing {
public:
    Bomb(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture, int isFaceDown)
            : Thing(x, y, rank, color, faceUpTexture, backGroundTexture, isFaceDown){}
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_BOMB_HPP
