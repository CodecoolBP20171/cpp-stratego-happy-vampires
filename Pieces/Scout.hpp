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

    bool moveTo(int x, int y, const std::array<std::shared_ptr<Piece>, 100> &boardArray) override {
        bool canMove = false;
        int newX = (x - sizeParams::BOARD_OFFSET_X) / sizeParams::FIELD_SIZE;
        int newY = (y - sizeParams::BOARD_OFFSET_Y) / sizeParams::FIELD_SIZE;
        int currX = posInArray % sizeParams::BOARD_FIELDS_NUMBER;
        int currY = posInArray / sizeParams::BOARD_FIELDS_NUMBER;
        int stepNumber = std::max(abs(newX - currX), abs(newY - currY));
        if(abs(currX - newX) > 0 && abs(currY - newY) == 0 || abs(currX - newX) == 0 && abs(currY - newY) > 0){
            for(int i = 1; i < stepNumber; i++) {
                if(abs(newX - currX) == 0){
                    if(isThereAPieceInTheWayByIndex(currX, currY + i, boardArray)){
                        return false;
                    }
                } else if(abs(newY - currY) == 0){
                    if(isThereAPieceInTheWayByIndex(currX + i, currY, boardArray)){
                        return false;
                    }
                }
            }
            sdl_rect.x = newX * sizeParams::FIELD_SIZE + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_X;
            sdl_rect.y = newY * sizeParams::FIELD_SIZE + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_Y;
            posInArray = newY * sizeParams::BOARD_FIELDS_NUMBER + newX;
            canMove = true;
        }
        return canMove;
    }

    bool isThereAPieceInTheWay(int x, int y, const std::array<std::shared_ptr<Piece>, 100> &boardArray) const {
        for(auto& piece : boardArray) {
            if (piece) {
                if (x == piece->getPosX() &&
                    y == piece->getPosY()) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isInAttackPosition(std::shared_ptr<Piece> defender, const std::array<std::shared_ptr<Piece>, 100> &boardArray) const override {
        int attackerX = this->getPosInArray() % sizeParams::BOARD_FIELDS_NUMBER;
        int attackerY = this->getPosInArray() / sizeParams::BOARD_FIELDS_NUMBER;
        int defenderX = defender->getPosInArray() % sizeParams::BOARD_FIELDS_NUMBER;
        int defenderY = defender->getPosInArray() / sizeParams::BOARD_FIELDS_NUMBER;
        int stepNumber = std::max(abs(attackerX - defenderX), abs(attackerY - defenderY));
        int stepDirection = (abs(defenderX - attackerX) == 0 ? defenderY - attackerY : defenderX - attackerX) / stepNumber;
        if(abs(attackerX - defenderX) > 0 && abs(attackerY - defenderY) == 0 || abs(attackerX - defenderX) == 0 && abs(attackerY - defenderY) > 0){
        for(int i = 1; i < stepNumber; i++) {
            if(abs(attackerX - defenderX) == 0){
               if(isThereAPieceInTheWayByIndex(attackerX, attackerY + i * stepDirection, boardArray)){
                    return false;
                }
            } else if(abs(attackerY - defenderY) == 0){
                if(isThereAPieceInTheWayByIndex(attackerX + i * stepDirection, attackerY, boardArray)){
                    return false;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

    bool isThereAPieceInTheWayByIndex(int x, int y, const std::array<std::shared_ptr<Piece>, 100> &boardArray) const {
        int posIndex = y * sizeParams::BOARD_FIELDS_NUMBER + x;
        if(boardArray[posIndex] == nullptr){
            return false;
        } else {
            return true;
        }
    }
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_SCOUT_HPP
