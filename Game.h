//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_GAME_H
#define STRATEGO_HAPPY_VAMPIRES_GAME_H


#include <vector>
#include <memory>
#include <map>
#include "Display.h"
#include "Piece.h"

class Game {

public:
    void run();

private:
    Display display;
    bool handleEvents(SDL_Event &event);
    // TODO: pieceContainer could contain Piece pointers(?)
    std::vector<std::unique_ptr<Piece>> pieceContainer;
    void loadTextures();
    std::map<Textures, std::unique_ptr<Texture>> textureMap;
};


#endif //STRATEGO_HAPPY_VAMPIRES_GAME_H