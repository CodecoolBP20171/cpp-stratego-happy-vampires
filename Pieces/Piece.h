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

// TODO: the enums and/or the namespace should go inside of the class (?)

namespace sizeParams {
    //TODO: program should be prepared to the case when PIECE_SIZE is < than FIELD_SIZE
    const int PIECE_SIZE = 69;
    const int FIELD_SIZE = 69;
    const int BOARD_X = 0;
    const int BOARD_Y = 0;
    const int BOARD_FIELDS_NUMBER = 10;

    // calculated values, do not touch
    const int PIECE_FIELD_DIFF = (FIELD_SIZE - PIECE_SIZE) / 2;
    const int BOARD_SIZE = BOARD_FIELDS_NUMBER * FIELD_SIZE;
    const int BOARD_MAX_X = BOARD_X + BOARD_SIZE;
    const int BOARD_MAX_Y = BOARD_Y + BOARD_SIZE;
}

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
    scoutTexture
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
    virtual bool moveTo(int x, int y, const std::vector<std::shared_ptr<Piece>> &pieceContainer){};
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