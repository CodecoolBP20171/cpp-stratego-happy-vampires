//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_PIECE_H
#define STRATEGO_HAPPY_VAMPIRES_PIECE_H


#include <SDL_render.h>
#include <map>
#include <iostream>
#include "Texture.h"

enum Rank {
    flagRank,
    bombRank,
    spyRank,
    scoutRank,
    minerRank,
    sergeantRank,
    lieutenantRank,
    captainRank,
    majorRank,
    colonelRank,
    generalRank,
    marshallRank
};

enum Color {
    red,
    blue,
    neutral
};

enum Textures {
    boardTexture,
    bombTexture,
    redBackTexture,
    blueBackTexture
};

class Piece {
public:
    Piece(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture, bool isFaceDown = true);
    //SDL_Texture *texture;
    void render(SDL_Renderer* renderer);
    int getPosY() const;
    void setPosY(int posY);
    int getPosX() const;
    void setPosX(int posX);
    void flip();
  private:
    SDL_Texture *faceUpTexture = nullptr;
    SDL_Texture *backTexture = nullptr;
    SDL_Rect sdl_rect;
    int posX, posY;
    bool isFaceDown;
    Rank rank;
    Color color;
};


#endif //STRATEGO_HAPPY_VAMPIRES_PIECE_H