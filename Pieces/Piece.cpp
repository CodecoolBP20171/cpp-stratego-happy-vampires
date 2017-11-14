//
// Created by en on 2017.11.09..
//

#include "Piece.h"

Piece::Piece(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture, int isFaceDown)
        : color(color),
          rank(rank),
          faceUpTexture(faceUpTexture),
          backTexture(backGroundTexture),
          isFaceDown(isFaceDown)
{
//    sdl_rect.x = posX = x * sizeParams::PIECE_SIZE + sizeParams::BOARD_X;
//    sdl_rect.y = posY = y * sizeParams::PIECE_SIZE + sizeParams::BOARD_Y;
    sdl_rect.x = x * sizeParams::FIELD_SIZE + sizeParams::BOARD_X + sizeParams::PIECE_FIELD_DIFF;
    sdl_rect.y = y * sizeParams::FIELD_SIZE + sizeParams::BOARD_Y + sizeParams::PIECE_FIELD_DIFF;
    posX = x * sizeParams::FIELD_SIZE + sizeParams::BOARD_X;
    posY = y * sizeParams::FIELD_SIZE + sizeParams::BOARD_Y;

    sdl_rect.w = sizeParams::PIECE_SIZE;
    sdl_rect.h = sizeParams::PIECE_SIZE;
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
    //std::cout << "flipped, isFaceDown: " << isFaceDown << std::endl;
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
    //TODO 100 -> const, finish function
    //bool canSet = false;
    int newX = (int) x / 100 * 100;
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
                //std::cout << "X: " << posX + i * 100 << " Y: " << posY + j * 100 << std::endl;
                if (canGoToNeighbour(posX + i * sizeParams::FIELD_SIZE, posY + j * sizeParams::FIELD_SIZE, pieceContainer)){
                    return true;
                }
            }
        }
    }
    return false;
}

bool Piece::canGoToNeighbour(const int &x, const int &y, const std::vector<std::shared_ptr<Piece>> &pieceContainer) const {
    // TODO i.e. isOnBoard:
    if (x < sizeParams::BOARD_X || x > sizeParams::BOARD_MAX_X || y < sizeParams::BOARD_Y || y > sizeParams::BOARD_MAX_Y){
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
