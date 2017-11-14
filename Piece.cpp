//
// Created by en on 2017.11.09..
//

#include "Piece.h"

// TODO create sublasses: Dani
// TODO replace 100 (magic number) to a const: Dani

Piece::Piece(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture, int isFaceDown)
        : color(color),
          rank(rank),
          faceUpTexture(faceUpTexture),
          backTexture(backGroundTexture),
          isFaceDown(isFaceDown)
{
    sdl_rect.x = posX = x;
    sdl_rect.y = posY = y;
    sdl_rect.w = 60;
    sdl_rect.h = 60;
}

void Piece::render(SDL_Renderer* renderer){
    if(isFaceDown) {
        SDL_RenderCopy(renderer, backTexture, NULL, &sdl_rect);
    } else {
        SDL_RenderCopy(renderer, faceUpTexture, NULL, &sdl_rect);
    }
}

int Piece::getPosX() const {
    return posX;
}

void Piece::setPosX(int posX) {
    Piece::posX = posX;
}

int Piece::getPosY() const {
    return posY;
}

void Piece::setPosY(int posY) {
    Piece::posY = posY;
}

void Piece::flip() {
    isFaceDown = !isFaceDown;
    std::cout << "flipped, isFaceDown: " << isFaceDown << std::endl;
}

Rank Piece::getRank() const {
    return rank;
}

void Piece::setRank(Rank rank) {
    Piece::rank = rank;
}

Color Piece::getColor() const {
    return color;
}

void Piece::setColor(Color color) {
    Piece::color = color;
}

bool Piece::moveTo(int x, int y) {
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

void Piece::printInfo() {
    std::cout << "Clicked on a " << (color == Color::red ? "red" : "blue") << " piece" << std::endl;
}
