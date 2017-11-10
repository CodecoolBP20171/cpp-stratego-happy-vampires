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
    std::vector<Piece> pieceContainer;
    void loadTextures();
    // TODO: textureMap could contain pointers(?)
    std::map<Textures, std::unique_ptr<Texture>> textureMap;
};


#endif //STRATEGO_HAPPY_VAMPIRES_GAME_H