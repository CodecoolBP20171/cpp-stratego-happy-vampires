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
        int newX = (int) x / sizeParams::FIELD_SIZE * sizeParams::FIELD_SIZE;
        int newY = (int) y / sizeParams::FIELD_SIZE * sizeParams::FIELD_SIZE;
        int stepNumber = std::max(abs(newX - posX), abs(newY - posY)) / sizeParams::FIELD_SIZE;
        int stepSize = 0;
        try {
            //to prevent program from accidental division by zero
            if (stepNumber == 0) {throw std::runtime_error("");}
            stepSize = (abs(newX - posX) == 0 ? newY - posY : newX - posX) / stepNumber;
        } catch (std::runtime_error &e) {
            std::cout << "Accidental divsion by zero was detected" << std::endl;
        }

        if(abs(posX - newX) > 0 && abs(posY - newY) == 0 || abs(posX - newX) == 0 && abs(posY - newY) > 0){

            for(int i = 1; i < stepNumber; i++) {
                if(abs(newX - posX) == 0){
                    if(isThereAPieceInTheWay(posX, posY + i * stepSize, boardArray)){
                        return false;
                    }
                } else if(abs(newY - posY) == 0){
                    if(isThereAPieceInTheWay(posX + i * stepSize, posY, boardArray)){
                        return false;
                    }
                }
            }
            sdl_rect.x = newX + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_X;
            sdl_rect.y = newY + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_Y;
            posX = newX + sizeParams::BOARD_X;
            posY = newY + sizeParams::BOARD_Y;
            int newIndexX = (posX-sizeParams::BOARD_X)/sizeParams::FIELD_SIZE;
            int newIndexY = (posY-sizeParams::BOARD_Y)/sizeParams::FIELD_SIZE;
            posInArray = newIndexY*sizeParams::BOARD_FIELDS_NUMBER+newIndexX;
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
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_SCOUT_HPP
