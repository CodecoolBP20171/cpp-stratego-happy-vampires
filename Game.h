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
#include "Board.h"

enum GameState {
    boardSetupState,
    gameState,
    gameOverState
};

class Game {
public:
    Game() {
        oldSDL_RectPosition.x = -1;
    }
    void run();

private:
    Display display;
    std::map<Textures, std::shared_ptr<Texture>> textureMap;
    Board board;
    std::shared_ptr<Piece> selectedPiece;
    Color currentPlayer;
    std::array<std::shared_ptr<Button>, 1> buttonArray;
    int clickedX, clickedY;
    GameState gameState;
    bool redSetup = false;
    bool blueSetup = false;
    bool waitingForSwitchPlayers = false;
    bool blueSetupPhase = false;
    SDL_Rect oldSDL_RectPosition;

    void loadTextures();
    bool handleEvents(SDL_Event &event);
    void createPieces();
    void createButtons();
    void gameLoop();
    void selectPiece(std::shared_ptr<Piece> &clickedPiece);
    void deselect();
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
    void executeFight(std::shared_ptr<Piece> shared_ptr, std::shared_ptr<Piece> sharedPtr, FightWinner winner);
    void gameOver(std::shared_ptr<Piece> shared_ptr);
    void initRedSetup();
    void initBlueSetup();
    void initRedSetupForTesting();
    void initBlueSetupForTesting();
    bool isRedSetup();
    bool isBlueSetup();
    Color enemyColor();
    void throwOutLoserToInactivePieces(std::shared_ptr<Piece> shared_ptr);
    void initSetupForGameLogicTesting();
    void restartGame();

    void switchRestartButtonColor();
};


#endif //STRATEGO_HAPPY_VAMPIRES_GAME_H