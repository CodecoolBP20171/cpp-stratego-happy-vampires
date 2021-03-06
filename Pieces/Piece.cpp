//
// Created by en on 2017.11.09..
//

#include "Piece.h"

Piece::Piece(Rank rank, Color color,
             SDL_Texture *faceUpTexture = nullptr, SDL_Texture *backGroundTexture = nullptr,
             bool toBoard = false,
             bool isFaceDown = false)
        : color(color),
          rank(rank),
          faceUpTexture(faceUpTexture),
          backTexture(backGroundTexture),
          isFaceDown(isFaceDown)
{
    sdl_rect.w = sizeParams::PIECE_SIZE;
    sdl_rect.h = sizeParams::PIECE_SIZE;
    randomAngle = std::rand() % 9 - 4;
}

void Piece::render(SDL_Renderer* renderer){
    if (isOnBoard()) SDL_RenderCopy(renderer, (isFaceDown ? backTexture : faceUpTexture), NULL, &sdl_rect);
    else {
        SDL_RenderCopyEx(renderer, (isFaceDown ? backTexture : faceUpTexture), NULL, &sdl_rect, randomAngle, NULL, SDL_FLIP_NONE);
    }
}

void Piece::flip() {
    isFaceDown = !isFaceDown;
}

Rank Piece::getRank() const {
    return rank;
}

Color Piece::getColor() const {
    return color;
}

void Piece::setupTo(int &x, int &y) {
    int newX = (x - sizeParams::BOARD_OFFSET_X) / sizeParams::FIELD_SIZE;
    int newY = (y - sizeParams::BOARD_OFFSET_Y) / sizeParams::FIELD_SIZE;
    int currX = posInArray % sizeParams::BOARD_FIELDS_NUMBER;
    int currY = posInArray / sizeParams::BOARD_FIELDS_NUMBER;
    posInArray = newY * sizeParams::BOARD_FIELDS_NUMBER + newX;
    sdl_rect.x = newX * sizeParams::FIELD_SIZE + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_X;
    sdl_rect.y = newY * sizeParams::FIELD_SIZE + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_Y;
    setOnBoard(true);
}

void Piece::setSdl_rect(int &x, int &y) {
    sdl_rect.x = x;
    sdl_rect.y = y;
}

bool Piece::isNotBlocked(const std::array<std::shared_ptr<Piece>, 100> &boardArray) const {
    int blockCounter = 0;
    int y = posInArray / sizeParams::BOARD_FIELDS_NUMBER; //deliberate integer division
    int x = posInArray % sizeParams::BOARD_FIELDS_NUMBER;
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(abs(i + j) == 1) {
                if (x + i < 0 || x + i > 9
                    || y + j < 0 || y + j > 9) {
                    ++blockCounter;
                } else if (isOccupiedByMyTeammate(x + i, y + j, boardArray)){
                    ++blockCounter;
                }
            }
        }
    }
    return blockCounter < 4;
}

bool Piece::isOccupiedByMyTeammate(const int &x, const int &y,
                                   const std::array<std::shared_ptr<Piece>, 100> &boardArray) const {
    int arrayPos = y*sizeParams::BOARD_FIELDS_NUMBER+x;
    if (boardArray[arrayPos] && boardArray[arrayPos]->getColor() == color) {
        return true;
    }
    return false;
}

const SDL_Rect &Piece::getSdl_rect() const {
    return sdl_rect;
}

bool Piece::isOnBoard() const {
    return OnBoard;
}

void Piece::setOnBoard(bool isOnBoard) {
    Piece::OnBoard = isOnBoard;
}

void Piece::setIsClicked(bool isClicked) {
    Piece::Clicked = isClicked;
}

int Piece::getPosInArray() const {
    return posInArray;
}

void Piece::setPosInArray(int posInArray) {
    Piece::posInArray = posInArray;
}