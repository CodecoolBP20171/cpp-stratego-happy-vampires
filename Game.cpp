//
// Created by en on 2017.11.09..
//

#include <memory>
#include "Display.h"
#include "Game.h"
#include "Piece.h"

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
    const int inactiveOffsetX = 749;
    const int inactiveOffsetY = 86;
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Piece(inactiveOffsetX+0*69, inactiveOffsetY+0*69, Rank::flagRank, Color::red,
         textureMap[Textures::redFlagTexture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    for(int i = 0; i < 6; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(inactiveOffsetX+(1+i)*69, inactiveOffsetY+(0)*69, Rank::bombRank, Color::red,
             textureMap[Textures::redBombTexture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    }
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Piece(inactiveOffsetX+7*69, inactiveOffsetY+0*69, Rank::spyRank, Color::red,
         textureMap[Textures::red1Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    for(int i = 0; i < 8; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(inactiveOffsetX+(0+i)*69, inactiveOffsetY+(1)*69, Rank::scoutRank, Color::red,
             textureMap[Textures::red2Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 5; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(inactiveOffsetX+(0+i)*69, inactiveOffsetY+(2)*69, Rank::minerRank, Color::red,
             textureMap[Textures::red3Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 4; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(inactiveOffsetX+(0+i)*69, inactiveOffsetY+(3)*69, Rank::sergeantRank, Color::red,
             textureMap[Textures::red4Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 4; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(inactiveOffsetX+(4+i)*69, inactiveOffsetY+(3)*69, Rank::lieutenantRank, Color::red,
             textureMap[Textures::red5Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 4; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(inactiveOffsetX+(0+i)*69, inactiveOffsetY+(4)*69, Rank::captainRank, Color::red,
             textureMap[Textures::red6Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 3; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(inactiveOffsetX+(4+i)*69, inactiveOffsetY+(4)*69, Rank::majorRank, Color::red,
             textureMap[Textures::red7Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 2; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(inactiveOffsetX+(0+i)*69, inactiveOffsetY+(5)*69, Rank::colonelRank, Color::red,
             textureMap[Textures::red8Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    }
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Piece(inactiveOffsetX+(0)*69, inactiveOffsetY+(6)*69, Rank::generalRank, Color::red,
         textureMap[Textures::red9Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Piece(inactiveOffsetX+(0)*69, inactiveOffsetY+(7)*69, Rank::marshallRank, Color::red,
         textureMap[Textures::red10Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
/*
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Piece(59, 59, Rank::flagRank, Color::red,
         textureMap[Textures::blueFlagTexture]->getSDLTexture(),
         textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    for(int i = 0; i < 6; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Piece(59, 59, Rank::bombRank, Color::red,
         textureMap[Textures::blueBombTexture]->getSDLTexture(),
         textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    }
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Piece(59, 59, Rank::spyRank, Color::red,
         textureMap[Textures::blue1Texture]->getSDLTexture(),
         textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    for(int i = 0; i < 8; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(59, 59, Rank::scoutRank, Color::red,
             textureMap[Textures::blue2Texture]->getSDLTexture(),
             textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 5; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(59, 59, Rank::minerRank, Color::red,
             textureMap[Textures::blue3Texture]->getSDLTexture(),
             textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 4; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(59, 59, Rank::sergeantRank, Color::red,
             textureMap[Textures::blue4Texture]->getSDLTexture(),
             textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 4; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(59, 59, Rank::lieutenantRank, Color::red,
             textureMap[Textures::blue5Texture]->getSDLTexture(),
             textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 4; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(59, 59, Rank::captainRank, Color::red,
             textureMap[Textures::blue6Texture]->getSDLTexture(),
             textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 3; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(59, 59, Rank::majorRank, Color::red,
             textureMap[Textures::blue7Texture]->getSDLTexture(),
             textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    }
    for(int i = 0; i < 2; ++i) {
        pieceContainer.emplace_back(std::unique_ptr<Piece>
            (new Piece(59, 59, Rank::colonelRank, Color::red,
             textureMap[Textures::blue8Texture]->getSDLTexture(),
             textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    }
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Piece(59, 59, Rank::generalRank, Color::red,
         textureMap[Textures::blue9Texture]->getSDLTexture(),
         textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece>
        (new Piece(59, 59, Rank::marshallRank, Color::red,
         textureMap[Textures::blue10Texture]->getSDLTexture(),
         textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
*/}

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
    if( event.type == SDL_MOUSEBUTTONUP )
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
    SDL_RenderDrawLine( display.getRenderer(),
                        selectedPiece->getPosX(), selectedPiece->getPosY(),
                        selectedPiece->getPosX(), selectedPiece->getPosY() + 64 );
    SDL_RenderDrawLine( display.getRenderer(),
                        selectedPiece->getPosX(), selectedPiece->getPosY(),
                        selectedPiece->getPosX() + 64, selectedPiece->getPosY() );
    SDL_RenderDrawLine( display.getRenderer(),
                        selectedPiece->getPosX() + 64, selectedPiece->getPosY(),
                        selectedPiece->getPosX() + 64, selectedPiece->getPosY() + 64 );
    SDL_RenderDrawLine( display.getRenderer(),
                        selectedPiece->getPosX(), selectedPiece->getPosY() + 64,
                        selectedPiece->getPosX() + 64, selectedPiece->getPosY() + 64 );
    //std::cout << "SELECTED: " << selectedPiece->getPosX() << std::endl;
}

std::shared_ptr<Piece> Game::getClickedPiece(int x, int y) {
    std::shared_ptr<Piece> result = nullptr;
    for(int i = 0; i < pieceContainer.size(); i++){
        if(x > pieceContainer[i]->getPosX() &&
           x < pieceContainer[i]->getPosX() + 69 &&
           y > pieceContainer[i]->getPosY() &&
           y < pieceContainer[i]->getPosY() + 69){
            result = pieceContainer[i];
        }
    }
    return result;
}

void Game::initGame() {
    currentPlayer = Color::red;
}

void Game::switchPlayers() {
    //TODO to ternary, low priority
    if(currentPlayer == Color::red){
        currentPlayer = Color::blue;
    } else {
        currentPlayer = Color::red;
    }
}
