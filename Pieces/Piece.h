//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_PIECE_H
#define STRATEGO_HAPPY_VAMPIRES_PIECE_H


#include <SDL_render.h>
#include <map>
#include <iostream>
#include <vector>
#include <memory>
#include "../Texture.h"

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
    marshallRank,
    barrierRank
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
    blueBackTexture,
    flagTexture,
    generalTexture,
    marshallTexture,
};

class Piece {
public:
    Piece(int x, int y, Rank rank, Color color, SDL_Texture *faceUpTexture = nullptr, SDL_Texture *backGroundTexture = nullptr, int isFaceDown = true);
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
    void printInfo();
    virtual bool canMove() = 0;
    virtual bool moveTo(int x, int y){};
    void setTo(int x, int y);
    bool isNotBlocked(const std::vector<std::shared_ptr<Piece>> &pieceContainer) const;
  protected:
    Color color;
    Rank rank;
    SDL_Texture *faceUpTexture = nullptr;
    SDL_Texture *backTexture = nullptr;
    SDL_Rect sdl_rect;
    int posX, posY;
    bool isFaceDown;
    bool canGoToNeighbour(const int &x, const int &y, const std::vector<std::shared_ptr<Piece>> &pieceContainer) const;
};


#endif //STRATEGO_HAPPY_VAMPIRES_PIECE_H