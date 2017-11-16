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
#include "Button.h"

enum GameState {
    boardSetupState,
    gameState
};

class Game {
public:
    void run();

private:
    Display display;
    Color currentPlayer;
    std::shared_ptr<Piece> selectedPiece;
    std::map<Textures, std::unique_ptr<Texture>> textureMap;
    std::vector<std::shared_ptr<Piece>> pieceContainer;
    std::array<std::shared_ptr<Piece>, 80> inactiveArray;
    std::array<std::shared_ptr<Piece>, 100> boardArray;
    std::array<std::shared_ptr<Button>, 1> buttonArray;
    int clickedX, clickedY;
    GameState gameState;
    SDL_Rect selectionRect;
    void loadTextures();
    bool handleEvents(SDL_Event &event);
    void createPieces();
    void createButtons();
    void gameLoop();
    void selectPiece(std::shared_ptr<Piece> &clickedPiece);
    void deselect();
    void graphicallySelect();
    std::shared_ptr<Piece> getClickedPiece(const int &x, const int &y) const;
    std::shared_ptr<Button> getClickedButton(const int &x, const int &y) const;
    void initGame();
    void switchPlayers();
    void gameLogic();
    void renderAll();
    void gameStateLogic();
    void boardSetupLogic();
    void flipAllPiecesOfCurrentPlayer();
    void convertClickedCoordsToArrayPlace(int &x, int &y);
    void  printGameState() const;
    bool onInactiveField() const;
    bool onRedSide() const;
    bool onBlueSide() const;
    bool onBoard() const;

    Color enemyColor();

    void executeFight(std::shared_ptr<Piece> shared_ptr, std::shared_ptr<Piece> sharedPtr, FightWinner winner);

    void gameOver(std::shared_ptr<Piece> shared_ptr);

    void initRedSetup();
    void initBlueSetup();
    void initRedSetupForTesting();
    void initBlueSetupForTesting();
    bool isRedSetup();
    bool isBlueSetup();
    bool redSetup = false;
    bool blueSetup = false;
    bool waitingForSwitchPlayers = false;
    bool blueSetupPhase = false;
};


#endif //STRATEGO_HAPPY_VAMPIRES_GAME_H