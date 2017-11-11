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
    sdl_rect.x = posX = x;
    sdl_rect.y = posY = y;
    sdl_rect.w = 100;
    sdl_rect.h = 100;
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
