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
    //TODO the display-dependent consts (offsets) should be moved to display class
    const int PIECE_SIZE = 59; //TODO discuss why was it 59
    const int FIELD_SIZE = 69;

    const int BOARD_X = 0;
    const int BOARD_Y = 0;
    const int BOARD_OFFSET_X = 14;
    const int BOARD_OFFSET_Y = 13;
    const int BOARD_FIELDS_NUMBER = 10;

    const int INACTIVE_OFFSET_X = 737;
    const int INACTIVE_OFFSET_Y = 74;
    const int INACTIVE_FIELDS_NUMBER_X = 8;
    const int INACTIVE_FIELDS_NUMBER_Y = 8;

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
    blue10Texture,
    selectionTexture
};

class Piece {
public:
    //TODO discuss wether the isFaceDown param of the constructor was int intentionally
    Piece(int x, int y,
          Rank rank, Color color,
          SDL_Texture *faceUpTexture, SDL_Texture *backGroundTexture,
          bool toBoard,
          bool isFaceDown);
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
    void setTo(int &x, int &y);
    bool isNotBlocked(const std::vector<std::shared_ptr<Piece>> &pieceContainer) const;
    const SDL_Rect &getSdl_rect() const;
    void setSdl_rect(int &x, int &y);
    bool isOnBoard() const;
    void setOnBoard(bool isOnBoard);
    bool isClicked() const;
    void setIsClicked(bool isClicked);
    int getPosInArray() const;
    void setPosInArray(int posInArray);
    void setupTo(int &x, int &y);
protected:
    Color color;
    Rank rank;
    SDL_Texture *faceUpTexture = nullptr;
    SDL_Texture *backTexture = nullptr;
    SDL_Rect sdl_rect;
    int posX, posY, posInArray;
    bool isFaceDown;
    bool canGoToNeighbour(const int &x, const int &y, const std::vector<std::shared_ptr<Piece>> &pieceContainer) const;
    bool OnBoard = false;
    bool Clicked = false;
    int randomAngle;
};


#endif //STRATEGO_HAPPY_VAMPIRES_PIECE_H