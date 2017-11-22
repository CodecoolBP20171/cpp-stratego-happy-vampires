//
// Created by eros on 14/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_SPY_HPP
#define CPP_STRATEGO_HAPPY_VAMPIRES_SPY_HPP


#include "Soldier.h"

class Spy : public Soldier {
public:
    Spy(Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture,
        bool toBoard, bool isFaceDown) : Soldier(rank, color, faceUpTexture, backGroundTexture, toBoard, isFaceDown){}

    FightWinner attack(std::shared_ptr<Piece> defender) override {
        if(this->getRank() == defender->getRank()){
            return FightWinner::draw;
        }
        if(defender->getRank() == Rank::marshallRank){
            return FightWinner::attacker;
        }
        return (this->getRank() > defender->getRank() ? FightWinner::attacker : FightWinner::defender);
    }
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_SPY_HPP
