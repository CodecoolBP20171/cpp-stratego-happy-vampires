//
// Created by eros on 14/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_SCOUT_HPP
#define CPP_STRATEGO_HAPPY_VAMPIRES_SCOUT_HPP


#include "Soldier.h"

class Scout : public Soldier {
public:
    Scout(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture,
          bool toBoard, bool isFaceDown) : Soldier(x, y, rank, color, faceUpTexture, backGroundTexture, toBoard, isFaceDown){}

        bool moveTo(int x, int y, const std::vector<std::shared_ptr<Piece>> &pieceContainer) override {
        // TODO DEBUG: JUMPS OVER PIECES IF THERE IS AN EMPTY FIELD BETWEEN THEM -> DEBUG
        bool canMove = false;
        int newX = (int) x / sizeParams::FIELD_SIZE * sizeParams::FIELD_SIZE;
        int newY = (int) y / sizeParams::FIELD_SIZE * sizeParams::FIELD_SIZE;
        int stepNumber = std::max(abs(newX - posX), abs(newY - posY)) / sizeParams::FIELD_SIZE;
        int stepSize = (abs(newX - posX) == 0 ? newY - posY : newX - posX) / stepNumber;

        if(abs(posX - newX) > 0 && abs(posY - newY) == 0 || abs(posX - newX) == 0 && abs(posY - newY) > 0){

            for(int i = 1; i < stepNumber; i++) {
                if(abs(newX - posX) == 0){
                    if(isThereAPieceInTheWay(posX, posY + i * stepSize, pieceContainer)){
                        return false;
                    }
                } else if(abs(newY - posY) == 0){
                    if(isThereAPieceInTheWay(posX + i * stepSize, posY, pieceContainer)){
                        return false;
                    }
                }
            }
            sdl_rect.x = newX + sizeParams::PIECE_FIELD_DIFF;
            sdl_rect.y = newY + sizeParams::PIECE_FIELD_DIFF;
            posX = newX;
            posY = newY;
            canMove = true;
        }
        return canMove;
    }

    bool isThereAPieceInTheWay(int x, int y, const std::vector<std::shared_ptr<Piece>> &pieceContainer) const {
        for(int i = 0; i < pieceContainer.size(); i++){
            if(x == pieceContainer[i]->getPosX() &&
               y == pieceContainer[i]->getPosY()) {
                return true;
            }
        }
        return false;
    }
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_SCOUT_HPP
