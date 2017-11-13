//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_GAME_H
#define STRATEGO_HAPPY_VAMPIRES_GAME_H


#include <vector>
#include <memory>
#include <map>
#include "Display.h"
#include "Pieces/Piece.h"

class Game {

public:
    void run();

private:
    Display display;
    Color currentPlayer;
    std::shared_ptr<Piece> selectedPiece;
    std::map<Textures, std::unique_ptr<Texture>> textureMap;
    std::vector<std::shared_ptr<Piece>> pieceContainer;
    int clickedX, clickedY;

    void loadTextures();
    bool handleEvents(SDL_Event &event);
    void createPieces();
    void gameLoop();
    void selectPiece(std::shared_ptr<Piece> &clickedPiece);
    void deselect();
    void graphicallySelect(std::shared_ptr<Piece> shared_ptr);
    std::shared_ptr<Piece> getClickedPiece(int x, int y);
    void initGame();
    void switchPlayers();

    void gameLogic();

    void renderAll();
};


#endif //STRATEGO_HAPPY_VAMPIRES_GAME_H