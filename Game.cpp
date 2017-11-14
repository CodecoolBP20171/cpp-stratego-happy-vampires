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
#include "Pieces/Miner.hpp"

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
    textureMap[Textures::boardTexture] = display.loadTexture("../pic/strategoBoard.png");
    textureMap[Textures::redBackTexture] = display.loadTexture("../pic/redBack.png");
    textureMap[Textures::redFlagTexture] = display.loadTexture("../pic/redFlag.png");
    textureMap[Textures::redBombTexture] = display.loadTexture("../pic/redBomb.png");
    textureMap[Textures::red1Texture] = display.loadTexture("../pic/red1.png");
    textureMap[Textures::red2Texture] = display.loadTexture("../pic/red2.png");
    textureMap[Textures::red3Texture] = display.loadTexture("../pic/red3.png");
    textureMap[Textures::red4Texture] = display.loadTexture("../pic/red4.png");
    textureMap[Textures::red5Texture] = display.loadTexture("../pic/red5.png");
    textureMap[Textures::red6Texture] = display.loadTexture("../pic/red6.png");
    textureMap[Textures::red7Texture] = display.loadTexture("../pic/red7.png");
    textureMap[Textures::red8Texture] = display.loadTexture("../pic/red8.png");
    textureMap[Textures::red9Texture] = display.loadTexture("../pic/red9.png");
    textureMap[Textures::red10Texture] = display.loadTexture("../pic/red10.png");
    textureMap[Textures::blueBackTexture] = display.loadTexture("../pic/blueBack.png");
    textureMap[Textures::blueFlagTexture] = display.loadTexture("../pic/blueFlag.png");
    textureMap[Textures::blueBombTexture] = display.loadTexture("../pic/blueBomb.png");
    textureMap[Textures::blue1Texture] = display.loadTexture("../pic/blue1.png");
    textureMap[Textures::blue2Texture] = display.loadTexture("../pic/blue2.png");
    textureMap[Textures::blue3Texture] = display.loadTexture("../pic/blue3.png");
    textureMap[Textures::blue4Texture] = display.loadTexture("../pic/blue4.png");
    textureMap[Textures::blue5Texture] = display.loadTexture("../pic/blue5.png");
    textureMap[Textures::blue6Texture] = display.loadTexture("../pic/blue6.png");
    textureMap[Textures::blue7Texture] = display.loadTexture("../pic/blue7.png");
    textureMap[Textures::blue8Texture] = display.loadTexture("../pic/blue8.png");
    textureMap[Textures::blue9Texture] = display.loadTexture("../pic/blue9.png");
    textureMap[Textures::blue10Texture] = display.loadTexture("../pic/blue10.png");
}

void Game::createPieces() {
    // TODO create all 80 pieces: Béci::subclasses will be needed for this (Dani task)
    // TODO by default we should create the pieces @ the inactive,
    // but for testing it should be convenient to create some to the board...but how???

    // pieceContainer.emplace_back(std::unique_ptr<Piece> (new Bomb(1, 1, Rank::bombRank, Color::red, textureMap[Textures::bombTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    // pieceContainer.emplace_back(std::unique_ptr<Piece> (new Bomb(4, 4, Rank::bombRank, Color::red, textureMap[Textures::bombTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    // pieceContainer.emplace_back(std::unique_ptr<Piece> (new Bomb(8, 6, Rank::bombRank, Color::red, textureMap[Textures::bombTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture(), false)));

    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Flag(0, 0, Rank::flagRank, Color::red,
        textureMap[Textures::blueFlagTexture]->getSDLTexture(),
        textureMap[Textures::blueBackTexture]->getSDLTexture(), true, false)));

    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Flag(9, 9, Rank::bombRank, Color::red,
         textureMap[Textures::blueBombTexture]->getSDLTexture(),
         textureMap[Textures::blueBackTexture]->getSDLTexture(), true, false)));

    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Soldier(3, 3, Rank::majorRank, Color::red,
         textureMap[Textures::red7Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), true, false)));

    // initilaizing red setup
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Flag(0, 0, Rank::flagRank, Color::red,
         textureMap[Textures::redFlagTexture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    for(int i = 0; i < 6; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Bomb((1+i), 0, Rank::bombRank, Color::red,
         textureMap[Textures::redBombTexture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    }
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Spy(7, 0, Rank::spyRank, Color::red,
         textureMap[Textures::red1Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    for(int i = 0; i < 8; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Scout((0+i), 1, Rank::scoutRank, Color::red,
             textureMap[Textures::red2Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    }
    for(int i = 0; i < 5; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Miner((0+i), 2, Rank::minerRank, Color::red,
             textureMap[Textures::red3Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    }
    for(int i = 0; i < 4; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Soldier((0+i), 3, Rank::sergeantRank, Color::red,
             textureMap[Textures::red4Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    }
    for(int i = 0; i < 4; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Soldier((4+i), 3, Rank::lieutenantRank, Color::red,
             textureMap[Textures::red5Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    }
    for(int i = 0; i < 4; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Soldier((0+i), 4, Rank::captainRank, Color::red,
             textureMap[Textures::red6Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    }
    for(int i = 0; i < 3; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Soldier((4+i), 4, Rank::majorRank, Color::red,
             textureMap[Textures::red7Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    }
    for(int i = 0; i < 2; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Soldier((0+i), 5, Rank::colonelRank, Color::red,
             textureMap[Textures::red8Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    }
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Soldier(0, 6, Rank::generalRank, Color::red,
         textureMap[Textures::red9Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Soldier(0, 7, Rank::marshallRank, Color::red,
         textureMap[Textures::red10Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false, false)));

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
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY(), selectedPiece->getPosX(), selectedPiece->getPosY() + sizeParams::FIELD_SIZE );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY(), selectedPiece->getPosX() + sizeParams::FIELD_SIZE, selectedPiece->getPosY() );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX() + sizeParams::FIELD_SIZE, selectedPiece->getPosY(), selectedPiece->getPosX() + sizeParams::FIELD_SIZE, selectedPiece->getPosY() + sizeParams::FIELD_SIZE );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY() + sizeParams::FIELD_SIZE, selectedPiece->getPosX() + sizeParams::FIELD_SIZE, selectedPiece->getPosY() + sizeParams::FIELD_SIZE );
}

std::shared_ptr<Piece> Game::getClickedPiece(const int &x, const int &y) const {
    std::shared_ptr<Piece> result = nullptr;
    for(int i = 0; i < pieceContainer.size(); i++){
        if(x > pieceContainer[i]->getPosX() &&
           x < pieceContainer[i]->getPosX() + sizeParams::FIELD_SIZE &&
           y > pieceContainer[i]->getPosY() &&
           y < pieceContainer[i]->getPosY() + sizeParams::FIELD_SIZE){
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
