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
    renderLoop();
}

bool Game::handleEvents(SDL_Event &event) {
    bool quit = false;
        if( event.type == SDL_QUIT ) { quit =  true; }
        if( event.type == SDL_MOUSEBUTTONDOWN )
        {
            int x, y;
            SDL_GetMouseState( &x, &y );
            std::cout << "click @ " << x << " " << y << std::endl;
            std::shared_ptr<Piece> clickedPiece = getClickedPiece(x, y);
            if(clickedPiece){
                if(currentPlayer == clickedPiece->getColor()) {
                    selectPiece(clickedPiece);
                }
            } else {
                if(selectedPiece){
                    if(selectedPiece->moveTo(x, y)) {
                        deselect();
                        switchPlayers();
                    }
                }
            }
        }
    return quit;
}

void Game::loadTextures() {
    textureMap[Textures::bombTexture] = display.loadTexture("../pic/bomb.png");
    textureMap[Textures::flagTexture] = display.loadTexture("../pic/flag.png");
    textureMap[Textures::boardTexture] = display.loadTexture("../pic/board.png");
    textureMap[Textures::redBackTexture] = display.loadTexture("../pic/red_back.png");
    textureMap[Textures::blueBackTexture] = display.loadTexture("../pic/blue_back.png");
}

void Game::createPieces() {
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Piece(100, 100, Rank::bombRank, Color::red, textureMap[Textures::bombTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture(), false)));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Piece(300, 300, Rank::flagRank, Color::blue, textureMap[Textures::flagTexture]->getSDLTexture(), textureMap[Textures::blueBackTexture]->getSDLTexture(), false)));
    SDL_Delay(100);
}

void Game::renderLoop() {
    bool quit = false;
    Uint32 timepassed = 0;
    Uint32  timestep = 16;
    while(!quit) {
        timepassed = SDL_GetTicks();
        SDL_Event sdl_event;
        while(SDL_PollEvent(&sdl_event) != 0){
            quit = handleEvents(sdl_event);

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

            while( timepassed + timestep > SDL_GetTicks() ) {
                SDL_Delay(0);
            }
        }
    }
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
    SDL_SetRenderDrawColor(display.getRenderer(), 0, 0, 255, 255);
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY(), selectedPiece->getPosX(), selectedPiece->getPosY() + 100 );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY(), selectedPiece->getPosX() + 100, selectedPiece->getPosY() );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX() + 100, selectedPiece->getPosY(), selectedPiece->getPosX() + 100, selectedPiece->getPosY() + 100 );
    SDL_RenderDrawLine( display.getRenderer(), selectedPiece->getPosX(), selectedPiece->getPosY() + 100, selectedPiece->getPosX() + 100, selectedPiece->getPosY() + 100 );
    //std::cout << "SELECTED: " << selectedPiece->getPosX() << std::endl;
}

std::shared_ptr<Piece> Game::getClickedPiece(int x, int y) {
    std::shared_ptr<Piece> result = nullptr;
    unsigned long numberOfPieces = pieceContainer.size();
    for(int i; i < numberOfPieces; i++){
        if(x > pieceContainer[i]->getPosX() &&
           x < pieceContainer[i]->getPosX() + 100 &&
           y > pieceContainer[i]->getPosY() &&
           y < pieceContainer[i]->getPosY() + 100){
            //pieceContainer[i]->flip();
            //selectPiece(pieceContainer[i]);
            //selectedPiece = pieceContainer[i];
            result = pieceContainer[i];
            std::cout << "hit" << std::endl;
        }
    }
    return result;
}

void Game::initGame() {
    currentPlayer = Color::red;
    //if(currentPlayer == Color::red) std::cout << "Currentplayer is red" << std::endl;
}

void Game::switchPlayers() {
    if(currentPlayer == Color::red){
        currentPlayer = Color::blue;
    } else {
        currentPlayer = Color::red;
    }
}
