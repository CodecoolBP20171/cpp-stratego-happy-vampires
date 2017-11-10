//
// Created by en on 2017.11.09..
//

#include <bits/unique_ptr.h>
#include "Display.h"
#include "Game.h"
#include "Piece.h"

void Game::run() {

    display.init();
    loadTextures();

    //Piece piece(100, 100, Rank::bombRank, Color::red, textureMap[Textures::bombTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture());
    //Piece piece2(300, 300, Rank::flagRank, Color::blue, textureMap[Textures::flagTexture]->getSDLTexture(), textureMap[Textures::blueBackTexture]->getSDLTexture());
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Piece(100, 100, Rank::bombRank, Color::red, textureMap[Textures::bombTexture]->getSDLTexture(), textureMap[Textures::redBackTexture]->getSDLTexture())));
    pieceContainer.emplace_back(std::unique_ptr<Piece> (new Piece(300, 300, Rank::flagRank, Color::blue, textureMap[Textures::flagTexture]->getSDLTexture(), textureMap[Textures::blueBackTexture]->getSDLTexture())));

    SDL_Delay(100);

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
            }

            SDL_RenderPresent(display.getRenderer());

            while( timepassed + timestep > SDL_GetTicks() ) {
                SDL_Delay(0);
            }
        }
    }

}

bool Game::handleEvents(SDL_Event &event) {
    bool quit = false;
        if( event.type == SDL_QUIT ) { quit =  true; }
        if( event.type == SDL_MOUSEBUTTONDOWN )
        {
            int x, y;
            SDL_GetMouseState( &x, &y );
            std::cout << "click @ " << x << " " << y << std::endl;
            for(int i; i < pieceContainer.size(); i++){
                if(x > pieceContainer[i]->getPosX() &&
                        x < pieceContainer[i]->getPosX() + 100 &&
                        y > pieceContainer[i]->getPosY() &&
                        y < pieceContainer[i]->getPosY() + 100){
                    pieceContainer[i]->flip();
                    std::cout << "hit" << std::endl;
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
