//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_PIECE_H
#define STRATEGO_HAPPY_VAMPIRES_PIECE_H


#include <SDL_render.h>
#include <map>
#include "Texture.h"

class Piece {
public:
    Piece(int x, int y, Rank rank, Color color, std::map<Piece::Textures, Texture> &textureMap, bool isFaceDown = true);
    //SDL_Texture *texture;
    void render(SDL_Renderer* renderer);
    int getPosY() const;
    void setPosY(int posY);
    int getPosX() const;
    void setPosX(int posX);
    enum Textures {
        board,
        bomb,
        redBack,
        blueBack
    };
    enum Rank {
        flag,
        bomb,
        spy,
        scout,
        miner,
        sergeant,
        lieutenant,
        captain,
        major,
        colonel,
        general,
        marshall
    };
    enum Color {
        red,
        blue,
        neutral
    };

private:
    SDL_Texture *texture = nullptr;
    SDL_Rect sdl_rect;
    int posX, posY;
    bool isFaceDown;
    Rank rank;
    Color color;
};


#endif //STRATEGO_HAPPY_VAMPIRES_PIECE_H


Texture bomb = display.loadTexture("../pic/bomb.png");
SDL_Texture *bombTexture = bomb.getSDLTexture();
Piece piece(bombTexture, 100, 100);
