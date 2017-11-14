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
    // TODO: remove magic number
    sdl_rect.w = 100;
    sdl_rect.h = 100;
}

void Piece::render(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, (isFaceDown ? backTexture : faceUpTexture), NULL, &sdl_rect);
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


void Piece::printInfo() {
    std::cout << "Clicked on a " << (color == Color::red ? "red" : "blue") << " piece" << std::endl;
}

void Piece::setTo(int x, int y) {
    //TODO
    //bool canSet = false;
    int newX = (int) x /100 * 100;
    int newY = (int) y / 100 * 100;
    //std::cout << "newX: " << newX << " oldX: " << posX << std::endl;
    //if((posX + 100 == newX || posX - 100 == newX) || (posY + 100 == newY || posY - 100 == newY)) {
    //if(abs(posX + posY - newX - newY) == 100) {
        sdl_rect.x = posX = newX;
        sdl_rect.y = posY = newY;
        //canSet = true;
    //}
    //return canSet;
}

bool Piece::isNotBlocked(const std::vector<std::shared_ptr<Piece>> &pieceContainer) const {
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(abs(i + j) == 1) {
                std::cout << "X: " << posX + i * 100 << " Y: " << posY + j * 100 << std::endl;
                // TODO remove magic number (100)
                if (canGoToNeighbour(posX + i * 100, posY + j * 100, pieceContainer)){
                    return true;
                }
            }
        }
    }
    return false;
}

bool Piece::canGoToNeighbour(const int &x, const int &y, const std::vector<std::shared_ptr<Piece>> &pieceContainer) const {
    // TODO remove magic numbers (100, 1000)
    // TODO i.e. isOnBoard:
    if (x < 0 || x > 1000 || y < 0 || y > 1000){
        return false;
    }
    for(int i = 0; i < pieceContainer.size(); i++){
        if(x == pieceContainer[i]->getPosX() &&
           y == pieceContainer[i]->getPosY() &&
           pieceContainer[i]->getColor() == color) {
            return false;
        }
    }
    return true;
}
