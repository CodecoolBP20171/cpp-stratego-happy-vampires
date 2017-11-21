//
// Created by eros on 13/11/17.
//

#include "Soldier.h"

Soldier::Soldier(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture, bool toBoard,
                 bool isFaceDown) : Piece(x, y, rank, color, faceUpTexture, backGroundTexture, toBoard, isFaceDown){}

bool Soldier::moveTo(int x, int y, const std::array<std::shared_ptr<Piece>, 100> &boardArray) {
    // TODO: passing pieceConatiner to this function is not necessay -> Dani delete
    bool canMove = false;
    int newX = (x - sizeParams::BOARD_OFFSET_X) / sizeParams::FIELD_SIZE;
    int newY = (y - sizeParams::BOARD_OFFSET_Y) / sizeParams::FIELD_SIZE;
    int currX = posInArray % sizeParams::BOARD_FIELDS_NUMBER;
    int currY = posInArray / sizeParams::BOARD_FIELDS_NUMBER;
    if(abs(currX + currY - newX - newY) == 1) {
        posInArray = newY * sizeParams::BOARD_FIELDS_NUMBER + newX;
        sdl_rect.x = newX * sizeParams::FIELD_SIZE + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_X;
        sdl_rect.y = newY * sizeParams::FIELD_SIZE + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_Y;
        canMove = true;
    }
    return canMove;
}

FightWinner Soldier::attack(std::shared_ptr<Piece> defender) {
    // TODO Soldier defeats soldiers weaker than it and the flag, draws with same ranked enemy
    std::cout << "Soldier attacks " << defender->getColor() << " " << defender->getRank() << std::endl;
    if(this->getRank() == defender->getRank()){
        return FightWinner::draw;
    }
    return (this->getRank() > defender->getRank() ? FightWinner::attacker : FightWinner::defender);
}

bool Soldier::isInAttackPosition(std::shared_ptr<Piece> defender,
                               const std::array<std::shared_ptr<Piece>, 100> &boardArray) const {
    int attackerX = this->getPosInArray() % sizeParams::BOARD_FIELDS_NUMBER;
    int attackerY = this->getPosInArray() / sizeParams::BOARD_FIELDS_NUMBER;
    int defenderX = defender->getPosInArray() % sizeParams::BOARD_FIELDS_NUMBER;
    int defenderY = defender->getPosInArray() / sizeParams::BOARD_FIELDS_NUMBER;
    return abs(attackerX + attackerY - defenderX - defenderY) == 1;
}