//
// Created by en on 2017.11.09..
//

#include "Piece.h"


Piece::Piece(int x, int y, Rank rank, Color color, std::map<Piece::Textures, Texture> &textureMap, bool isFaceDown)
        : color(color),
          rank(rank)
{
    sdl_rect.x = posX = x;
    sdl_rect.y = posY = y;
    sdl_rect.w = 100;
    sdl_rect.h = 100;
    if ( isFaceDown ) this->texture = textureMap[].getSDLTexture();
}

void Piece::render(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, texture, NULL, &sdl_rect);
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


