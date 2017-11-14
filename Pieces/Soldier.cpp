//
// Created by eros on 13/11/17.
//

#include "Soldier.h"

Soldier::Soldier(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture,
                 bool isFaceDown) : Piece(x, y, rank, color, faceUpTexture, backGroundTexture, isFaceDown){}

bool Soldier::moveTo(int x, int y) {
    // TODO 100 replace to a constant: Dani
    bool canMove = false;
    int newX = (int) x /100 * 100;
    int newY = (int) y / 100 * 100;
    //std::cout << "newX: " << newX << " oldX: " << posX << std::endl;
    //if((posX + 100 == newX || posX - 100 == newX) || (posY + 100 == newY || posY - 100 == newY)) {
    if(abs(posX + posY - newX - newY) == 100) {
        sdl_rect.x = posX = newX;
        sdl_rect.y = posY = newY;
        canMove = true;
    }
    return canMove;
}

void Soldier::attack(std::shared_ptr<Piece> piece) {
    // TODO
}
