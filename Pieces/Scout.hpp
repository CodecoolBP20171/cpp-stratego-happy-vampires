//
// Created by eros on 14/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_SCOUT_HPP
#define CPP_STRATEGO_HAPPY_VAMPIRES_SCOUT_HPP


#include "Soldier.h"

class Scout : public Soldier {
public:
    Scout(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture,
          bool isFaceDown) : Soldier(x, y, rank, color, faceUpTexture, backGroundTexture, isFaceDown){}
    bool moveTo(int x, int y) override {
        // TODO Scout can move multiple sqares; maybe attack should be overriden as well
    }

};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_SCOUT_HPP
