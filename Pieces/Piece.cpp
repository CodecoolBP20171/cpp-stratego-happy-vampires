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
    /*if (!toBoard) {
        posX = x * sizeParams::FIELD_SIZE + sizeParams::INACTIVE_FIELDS_NUMBER_X;
        posY = y * sizeParams::FIELD_SIZE + sizeParams::INACTIVE_FIELDS_NUMBER_Y;
        sdl_rect.x = posX + sizeParams::PIECE_FIELD_DIFF + sizeParams::INACTIVE_OFFSET_X;
        sdl_rect.y = posY + sizeParams::PIECE_FIELD_DIFF + sizeParams::INACTIVE_OFFSET_Y;
        posInArray = y*sizeParams::INACTIVE_FIELDS_NUMBER_X+x;
    } else {
        posX = x * sizeParams::FIELD_SIZE + sizeParams::BOARD_X;
        posY = y * sizeParams::FIELD_SIZE + sizeParams::BOARD_Y;
        sdl_rect.x = posX + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_X;
        sdl_rect.y = posY + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_Y;
        posInArray = y*sizeParams::BOARD_FIELDS_NUMBER+x;
    }*/
    randomAngle = std::rand() % 9 - 4;
}

void Piece::render(SDL_Renderer* renderer){
    if (isOnBoard()) SDL_RenderCopy(renderer, (isFaceDown ? backTexture : faceUpTexture), NULL, &sdl_rect);
    else {
        SDL_RenderCopyEx(renderer, (isFaceDown ? backTexture : faceUpTexture), NULL, &sdl_rect, randomAngle, NULL, SDL_FLIP_NONE);
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

void Piece::setTo(int &x, int &y) {
    int newX = (int) x / sizeParams::FIELD_SIZE * sizeParams::FIELD_SIZE;
    int newY = (int) y / sizeParams::FIELD_SIZE * sizeParams::FIELD_SIZE;
    sdl_rect.x = newX + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_X;
    sdl_rect.y = newY + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_Y;
}

void Piece::setupTo(int &x, int &y) {
    int newPosX = (int) x / sizeParams::FIELD_SIZE * sizeParams::FIELD_SIZE;
    int newPosY = (int) y / sizeParams::FIELD_SIZE * sizeParams::FIELD_SIZE;
    //TODO debug newPos maths to avoid setting up to same place

    posX = newPosX;
    posY = newPosY;

    int newX = (newPosX-sizeParams::BOARD_X)/sizeParams::FIELD_SIZE;
    int newY = (newPosY-sizeParams::BOARD_Y)/sizeParams::FIELD_SIZE;

    sdl_rect.x = newPosX + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_X;
    sdl_rect.y = newPosY + sizeParams::PIECE_FIELD_DIFF + sizeParams::BOARD_OFFSET_Y;

    posInArray = newY*sizeParams::BOARD_FIELDS_NUMBER+newX;
    std::cout << posInArray << std::endl;
    setOnBoard(true);
}

void Piece::setupToInactive(std::array<std::shared_ptr<Piece>, 80> &inactiveArray) {
    for(int i=0; i<inactiveArray.size(); i++) {
        if(inactiveArray[i] == nullptr){
            posX = sizeParams::INACTIVE_OFFSET_X + sizeParams::FIELD_SIZE * (i % sizeParams::INACTIVE_FIELDS_NUMBER_X);
            posY = sizeParams::INACTIVE_OFFSET_Y + sizeParams::FIELD_SIZE * (i / sizeParams::INACTIVE_FIELDS_NUMBER_X);
            sdl_rect.x = posX + sizeParams::PIECE_FIELD_DIFF;
            sdl_rect.y = posY + sizeParams::PIECE_FIELD_DIFF;
            posInArray = i;
            break;
        }
    }
    setOnBoard(false);
}

void Piece::setSdl_rect(int &x, int &y) {
    sdl_rect.x = x;
    sdl_rect.y = y;
}

bool Piece::isNotBlocked(const std::array<std::shared_ptr<Piece>, 100> &boardArray) const {
    for (auto& piece : boardArray) if (piece) std::cout << piece->posInArray << " " << piece->getRank() << "\n";
    if(boardArray[0]) std::cout << "\n 0 " << boardArray[0]->getRank() << std::endl;
    if(boardArray[1]) std::cout << "\n 1 " << boardArray[1]->getRank() << std::endl;
    if(boardArray[2]) std::cout << "\n 2 " << boardArray[2]->getRank() << std::endl;
    if(boardArray[11]) std::cout << "\n 11 " << boardArray[11]->getRank() << std::endl;
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
    std::cout << "blockCounter " << blockCounter << "\n";
    return blockCounter < 4;
}

bool Piece::isOccupiedByMyTeammate(const int &x, const int &y,
                                   const std::array<std::shared_ptr<Piece>, 100> &boardArray) const {

    // TODO i.e. isOnBoard:
/*
    if (x < sizeParams::BOARD_X || x > sizeParams::BOARD_MAX_X || y < sizeParams::BOARD_Y || y > sizeParams::BOARD_MAX_Y){
        return false;
    }
*/
    std::cout << "x " << x << " y " << y << std::endl;
    int arrayPos = y*sizeParams::BOARD_FIELDS_NUMBER+x;
    std::cout << "arrayPos " << arrayPos << std::endl;
    if (boardArray[arrayPos]) {
        std::cout << "rank " << boardArray[arrayPos]->getRank() << std::endl;
        std::cout << "return true\n";
        return true;
    }
    std::cout << "return false\n";
    return false;
/*
    for(auto &piece : boardArray) {
        if(piece) {
            if(x == piece->getPosX() &&
               y == piece->getPosY() &&
               piece->getColor() == color) {
                return false;
            }
        }
    }
    return true;
    */
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

bool Piece::isClicked() const {
    return Clicked;
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