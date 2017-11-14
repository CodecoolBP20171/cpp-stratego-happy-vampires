//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_PIECE_H
#define STRATEGO_HAPPY_VAMPIRES_PIECE_H


#include <SDL_render.h>
#include <map>
#include <iostream>
#include "Texture.h"

// TODO: the enums should go inside of the class (?)

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
    redBackTexture,
    redFlagTexture,
    redBombTexture,
    red1Texture,
    red2Texture,
    red3Texture,
    red4Texture,
    red5Texture,
    red6Texture,
    red7Texture,
    red8Texture,
    red9Texture,
    red10Texture,
    blueBackTexture,
    blueFlagTexture,
    blueBombTexture,
    blue1Texture,
    blue2Texture,
    blue3Texture,
    blue4Texture,
    blue5Texture,
    blue6Texture,
    blue7Texture,
    blue8Texture,
    blue9Texture,
    blue10Texture
};

class Piece {
public:
    Piece(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture, int isFaceDown = true);
    void render(SDL_Renderer* renderer);
    int getPosY() const;
    void setPosY(int posY);
    int getPosX() const;
    void setPosX(int posX);
    void flip();
    Rank getRank() const;
    void setRank(Rank rank);
    Color getColor() const;
    void setColor(Color color);
    bool moveTo(int x, int y);
    void printInfo();
  private:
    Color color;
    Rank rank;
    SDL_Texture *faceUpTexture = nullptr;
    SDL_Texture *backTexture = nullptr;
    SDL_Rect sdl_rect;
    int posX, posY;
    bool isFaceDown;
};


#endif //STRATEGO_HAPPY_VAMPIRES_PIECE_H