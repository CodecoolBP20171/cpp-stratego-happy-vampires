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
#include "Pieces/Soldier.h"
#include "Pieces/Scout.hpp"
#include "Pieces/Spy.hpp"

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
    textureMap[Textures::marshallTexture] = display.loadTexture("../pic/marshall.png");
    textureMap[Textures::generalTexture] = display.loadTexture("../pic/general.png");
    textureMap[Textures::scoutTexture] = display.loadTexture("../pic/scout.png");
}

void Game::createPieces() {
    // TODO create all 80 pieces: Béci::subclasses will be needed for this (Dani task)
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Bomb(1, 1, Rank::bombRank, Color::red, textureMap[Textures::bombTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Bomb(4, 4, Rank::bombRank, Color::red, textureMap[Textures::bombTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Flag(3, 3, Rank::flagRank, Color::blue, textureMap[Textures::flagTexture]->getSDLTexture(), textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Flag(5, 5, Rank::flagRank, Color::blue, textureMap[Textures::flagTexture]->getSDLTexture(), textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Soldier(2, 2, Rank::marshallRank, Color::red, textureMap[Textures::marshallTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Soldier(0, 0, Rank::generalRank, Color::blue, textureMap[Textures::generalTexture]->getSDLTexture(), textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Soldier(1, 0, Rank::generalRank, Color::blue, textureMap[Textures::generalTexture]->getSDLTexture(), textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Soldier(0, 1, Rank::generalRank, Color::blue, textureMap[Textures::generalTexture]->getSDLTexture(), textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Scout(8, 8, Rank::scoutRank, Color::red, textureMap[Textures::scoutTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture(), false)));



    // TODO barriers should be created in a nice for loop, the coordinates should be
    // in n(coordinate) x "defaultUnit" format. "defaultUnit" will be a const, now we use a magic number (100) for it
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(2, 4, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(2, 5, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(3, 4, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(3, 5, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(6, 4, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(6, 5, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(7, 4, Rank::barrierRank, Color::neutral)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Barrier(7, 5, Rank::barrierRank, Color::neutral)));
}

void Game::initGame() {
    currentPlayer = Color::red;
    // should be initially:
    // gameState = GameState::boardSetupState;

    // THE BELOW LINES ARE USED ONLY IN THE DEVELOPMENT PHASE, THEY WILL BE ALTERED IN THE FINAL GAME
    gameState = GameState::gameState;
    switchPlayers();
    flipAllPiecesOf(currentPlayer);
    switchPlayers();
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
    if(gameState == GameState::boardSetupState){
        boardSetupLogic();
    } else if(gameState == GameState::gameState){
        gameStateLogic();
    }


}

void Game::boardSetupLogic() {
    // TODO
}

void Game::gameStateLogic() {
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
                // TODO: select from only movable pieces (not a blocked soldier)
                if(clickedPiece->canMove() && clickedPiece->isNotBlocked(pieceContainer)) {
                    selectPiece(clickedPiece);
                }
            }
        } else { // the user clicked on an empty field // later: or to an enemy
            // if there is a piece selected
            if (selectedPiece) {
                // if the piece can move to that empty field, move there
                if (selectedPiece->moveTo(clickedX, clickedY, pieceContainer)) {
                    deselect();
                    flipAllPiecesOf(currentPlayer);
                    switchPlayers();
                    flipAllPiecesOf(currentPlayer);
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
            graphicallySelect();
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

void Game::graphicallySelect() {
    // TODO: might be improved, low priority
    SDL_SetRenderDrawColor(display.getRenderer(), 0, 0, 255, 255);
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY(), selectedPiece->getPosX(), selectedPiece->getPosY() + sizeParams::PIECE_SIZE );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY(), selectedPiece->getPosX() + sizeParams::PIECE_SIZE, selectedPiece->getPosY() );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX() + sizeParams::PIECE_SIZE, selectedPiece->getPosY(), selectedPiece->getPosX() + sizeParams::PIECE_SIZE, selectedPiece->getPosY() + sizeParams::PIECE_SIZE );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY() + sizeParams::PIECE_SIZE, selectedPiece->getPosX() + sizeParams::PIECE_SIZE, selectedPiece->getPosY() + sizeParams::PIECE_SIZE );
}

std::shared_ptr<Piece> Game::getClickedPiece(const int &x, const int &y) const {
    std::shared_ptr<Piece> result = nullptr;
    for(int i = 0; i < pieceContainer.size(); i++){
        if(x > pieceContainer[i]->getPosX() &&
           x < pieceContainer[i]->getPosX() + sizeParams::PIECE_SIZE &&
           y > pieceContainer[i]->getPosY() &&
           y < pieceContainer[i]->getPosY() + sizeParams::PIECE_SIZE){
            result = pieceContainer[i];
        }
    }
    return result;
}

void Game::switchPlayers() {
    currentPlayer = (currentPlayer == Color::red ? Color::blue : Color::red);
}

void Game::flipAllPiecesOf(Color color) {
    for(int i = 0; i < pieceContainer.size(); i++){
        if(pieceContainer[i]->getColor() == currentPlayer){
            pieceContainer[i]->flip();
        }
    }
}
