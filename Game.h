//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_GAME_H
#define STRATEGO_HAPPY_VAMPIRES_GAME_H


#include <vector>
#include <map>
#include "Display.h"
#include "Piece.h"

class Game {

public:
    //Game() : pieceContainer(new std::vector<Piece>){}
    void run();

private:
    Display display;
    bool handleEvents();
    std::vector<Piece> pieceContainer;
    void loadTextures();
    std::map<Textures, Texture> textureMap;
};


#endif //STRATEGO_HAPPY_VAMPIRES_GAME_H