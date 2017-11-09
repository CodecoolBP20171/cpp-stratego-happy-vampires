//
// Created by en on 2017.11.09..
//

#include "Piece.h"


Piece::Piece(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture, bool isFaceDown)
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
    //if ( isFaceDown ) this->texture = textureMap[].getSDLTexture();
}

void Piece::render(SDL_Renderer* renderer){
    if(isFaceDown) {
        std::cout << "FACE DOWN" << std::endl;
        SDL_RenderCopy(renderer, backTexture, NULL, &sdl_rect);
    } else {
        SDL_RenderCopy(renderer, faceUpTexture, NULL, &sdl_rect);
        //std::cout << "FACE UP" << std::endl;
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
    //isFaceDown = !isFaceDown;
//    if(isFaceDown){
//        isFaceDown = false;
//    } else {
//        isFaceDown = true;
//    }
    std::cout << "flipped, isFaceDown: " << isFaceDown << std::endl;
}

