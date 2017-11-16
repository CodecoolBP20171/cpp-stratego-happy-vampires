//
// Created by eros on 14/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_SPY_HPP
#define CPP_STRATEGO_HAPPY_VAMPIRES_SPY_HPP


#include "Soldier.h"

class Spy : public Soldier {
public:
    Spy(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture,
        bool toBoard, bool isFaceDown) : Soldier(x, y, rank, color, faceUpTexture, backGroundTexture, toBoard, isFaceDown){}
    FightWinner attack(std::shared_ptr<Piece> piece) override {
        // TODO: Spy can only defeat the marshall and the flag; draws with a spy
        std::cout << "Spy attacks" << std::endl;
    }
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_SPY_HPP
