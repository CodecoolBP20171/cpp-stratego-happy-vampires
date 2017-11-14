//
// Created by eros on 13/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_SOLDIER_H
#define CPP_STRATEGO_HAPPY_VAMPIRES_SOLDIER_H


#include <memory>
#include "Piece.h"

class Soldier : public Piece {
public:
    Soldier(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture = nullptr, SDL_Texture *backGroundTexture = nullptr, bool toBoard = false, bool isFaceDown = true);
    bool canMove() override {return true;}
    // TODO virtual moveTo should be implemented here!!
    bool moveTo(int x, int y, const std::vector<std::shared_ptr<Piece>> &pieceContainer) override;
    virtual void attack(std::shared_ptr<Piece> piece);
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_SOLDIER_H
