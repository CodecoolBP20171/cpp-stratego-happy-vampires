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
    Color currentPlayer;
    bool handleEvents(SDL_Event &event);
    std::vector<std::shared_ptr<Piece>> pieceContainer;
    bool isAPieceSelected = false;
    std::shared_ptr<Piece> selectedPiece;
    void loadTextures();
    std::map<Textures, std::unique_ptr<Texture>> textureMap;
    void createPieces();
    void renderLoop();
    void selectPiece(std::shared_ptr<Piece> &clickedPiece);
    void deselect();
    void graphicallySelect(std::shared_ptr<Piece> shared_ptr);

    std::shared_ptr<Piece> getClickedPiece(int x, int y);

    void initGame();

    void switchPlayers();
};


#endif //STRATEGO_HAPPY_VAMPIRES_GAME_H