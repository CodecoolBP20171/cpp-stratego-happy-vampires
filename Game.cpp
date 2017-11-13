//
// Created by en on 2017.11.09..
//

#include <memory>
#include "Display.h"
#include "Game.h"
#include "Pieces/Piece.h"
#include "Pieces/Bomb.hpp"
#include "Pieces/Flag.hpp"
#include "Pieces/Barrier.hpp"

void Game::run() {
    display.init();
    loadTextures();
    createPieces();
    initGame();
    gameLoop();
}

void Game::loadTextures() {
    // TODO collect all pictures for pieces: Béci
    // TODO Design final background: Béci
    // TODO import all textures: Béci
    textureMap[Textures::bombTexture] = display.loadTexture("../pic/bomb.png");
    textureMap[Textures::flagTexture] = display.loadTexture("../pic/flag.png");
    textureMap[Textures::boardTexture] = display.loadTexture("../pic/board.png");
    textureMap[Textures::redBackTexture] = display.loadTexture("../pic/red_back.png");
    textureMap[Textures::blueBackTexture] = display.loadTexture("../pic/blue_back.png");
}

void Game::createPieces() {
    // TODO create all 80 pieces: Béci::subclasses will be needed for this (Dani task)
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Bomb(100, 100, Rank::bombRank, Color::red, textureMap[Textures::bombTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Flag(300, 300, Rank::flagRank, Color::blue, textureMap[Textures::flagTexture]->getSDLTexture(), textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));

    // TODO barriers should be created in a nice for loop, the coordinates should be
    // in n(coordinate) x "defaultUnit" format. "defaultUnit" will be a const, now we use a magic number (100) for it
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(200, 400, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(200, 500, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(300, 400, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(300, 500, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(600, 400, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(600, 500, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(700, 400, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(700, 500, Rank::barrierRank, Color::neutral)));
}

void Game::gameLoop() {
    bool quit = false;
    Uint32 timepassed = 0;
    Uint32  timestep = 16;
    while(!quit) {
        timepassed = SDL_GetTicks();
        SDL_Event sdl_event;
        while(SDL_PollEvent(&sdl_event) != 0){
            // get user input
            quit = handleEvents(sdl_event);
            // apply game logic
            gameLogic();
            //render new frame
            renderAll();
            while( timepassed + timestep > SDL_GetTicks() ) {
                SDL_Delay(0);
            }
        }
    }
}

bool Game::handleEvents(SDL_Event &event) {
    clickedX = -1; clickedY = -1;
    bool quit = false;
    if( event.type == SDL_QUIT ) { quit =  true; }
    if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        int x, y;
        SDL_GetMouseState( &x, &y );
        clickedX = x; clickedY = y;
        std::cout << "click @ " << clickedX << " " << clickedY << std::endl;
    }
    return quit;
}

void Game::gameLogic() {
    // if there is a click on the board
    if(clickedX >= 0 && clickedY >= 0) {
        //std::cout << "clicked on the board!" << std::endl;
        // get clicked piece if the user clicked on a piece, nullptr otherwise
        std::shared_ptr<Piece> clickedPiece = getClickedPiece(clickedX, clickedY);
        // if the user clicked on a piece
        if (clickedPiece) {
            // if it is the current player's piece
            if (currentPlayer == clickedPiece->getColor()) {
                // select the clicked piece
                selectPiece(clickedPiece);
            }
        } else { // the user clicked on an empty field // later: or to an enemy
            // if there is a piece selected
            if (selectedPiece) {
                // if the piece can move to that empty field, move there
                if (selectedPiece->moveTo(clickedX, clickedY)) {
                    deselect();
                    switchPlayers();
                }
            }
        }
    }
}

void Game::renderAll() {
    SDL_RenderClear(display.getRenderer());
    textureMap[Textures::boardTexture]->render(display.getRenderer(), nullptr);
    for(int i = 0; i < pieceContainer.size(); i++){
        pieceContainer[i]->render(display.getRenderer());
        // if there is a selected piece, render the selection
        if(pieceContainer[i] == selectedPiece) {
            graphicallySelect(selectedPiece);
        }
    }
    SDL_RenderPresent(display.getRenderer());
}

void Game::selectPiece(std::shared_ptr<Piece> &clickedPiece) {
    if(!selectedPiece){
        selectedPiece = clickedPiece;
    } else {
        if(clickedPiece == selectedPiece){
            deselect();
        } else {
            deselect();
            selectedPiece = clickedPiece;
        }
    }
}

void Game::deselect() {
    selectedPiece = nullptr;
}

void Game::graphicallySelect(std::shared_ptr<Piece> shared_ptr) {
    // TODO: might be improved, low priority
    SDL_SetRenderDrawColor(display.getRenderer(), 0, 0, 255, 255);
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY(), selectedPiece->getPosX(), selectedPiece->getPosY() + 100 );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY(), selectedPiece->getPosX() + 100, selectedPiece->getPosY() );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX() + 100, selectedPiece->getPosY(), selectedPiece->getPosX() + 100, selectedPiece->getPosY() + 100 );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY() + 100, selectedPiece->getPosX() + 100, selectedPiece->getPosY() + 100 );
    //std::cout << "SELECTED: " << selectedPiece->getPosX() << std::endl;
}

std::shared_ptr<Piece> Game::getClickedPiece(int x, int y) {
    std::shared_ptr<Piece> result = nullptr;
    for(int i = 0; i < pieceContainer.size(); i++){
        if(x > pieceContainer[i]->getPosX() &&
           x < pieceContainer[i]->getPosX() + 100 &&
           y > pieceContainer[i]->getPosY() &&
           y < pieceContainer[i]->getPosY() + 100){
            result = pieceContainer[i];
        }
    }
    return result;
}

void Game::initGame() {
    currentPlayer = Color::red;
}

void Game::switchPlayers() {
    currentPlayer = (currentPlayer == Color::red ? Color::blue : Color::red);
}
