//
// Created by eros on 14/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_MINER_HPP
#define CPP_STRATEGO_HAPPY_VAMPIRES_MINER_HPP


#include "Soldier.h"

class Miner : public Soldier {
public:
    Miner(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture,
          bool toBoard, bool isFaceDown) : Soldier(x, y, rank, color, faceUpTexture, backGroundTexture, toBoard, isFaceDown){}
    void attack(std::shared_ptr<Piece> piece) override {
        // TODO: Miner defeats soldiers weaker than it and the flag and the bomb, draws with same ranked enemy
        std::cout << "Miner attacks" << std::endl;
    }
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_MINER_HPP
