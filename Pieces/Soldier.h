//
// Created by eros on 13/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_SOLDIER_H
#define CPP_STRATEGO_HAPPY_VAMPIRES_SOLDIER_H


#include <memory>
#include "Piece.h"

class Soldier : public Piece {
public:
    Soldier(Rank rank, Color color, SDL_Texture *faceUpTexture = nullptr, SDL_Texture *backGroundTexture = nullptr, bool toBoard = false, bool isFaceDown = true);
    bool canMove() override {return true;}
    bool moveTo(int x, int y, const std::array<std::shared_ptr<Piece>, 100> &boardArray) override;
    FightWinner attack(std::shared_ptr<Piece> defender) override;
    bool isInAttackPosition(std::shared_ptr<Piece> defender, const std::array<std::shared_ptr<Piece>, 100> &boardArray) const override;
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_SOLDIER_H
