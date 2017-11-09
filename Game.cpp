//
// Created by en on 2017.11.09..
//

#include "Display.h"
#include "Game.h"
#include "Piece.h"

void Game::run() {

    display.init();
    loadTextures();
    Piece piece(100, 100, Rank::bombRank, Color::red, textureMap[Textures::bombTexture].getSDLTexture(), textureMap[Textures::redBackTexture].getSDLTexture());
    Piece piece2(300, 300, Rank::flagRank, Color::blue, textureMap[Textures::flagTexture].getSDLTexture(), textureMap[Textures::blueBackTexture].getSDLTexture());
    pieceContainer.push_back(piece);
    pieceContainer.push_back(piece2);

    SDL_Delay(100);

    bool quit = false;
    Uint32 timepassed = 0;
    Uint32  timestep = 16;
    while(!quit) {
        timepassed = SDL_GetTicks();

        quit = handleEvents();

        SDL_RenderClear(display.getRenderer());
        textureMap[Textures::boardTexture].render(display.getRenderer(), nullptr);

        for(int i = 0; i < pieceContainer.size(); i++){
            pieceContainer[i].render(display.getRenderer());
        }

        SDL_RenderPresent(display.getRenderer());
        while( timepassed + timestep > SDL_GetTicks() ) {
            SDL_Delay(0);
        }
    }
}

bool Game::handleEvents() {
    bool quit = false;
    SDL_Event event;
    while (SDL_PollEvent( &event ) != 0) {
        if( event.type == SDL_QUIT ) { quit =  true; }
        if( event.type == SDL_MOUSEBUTTONDOWN )
        {
            int x, y;
            SDL_GetMouseState( &x, &y );
            std::cout << "click @ " << x << " " << y << std::endl;
            for(int i; i < pieceContainer.size(); i++){
                if(x > pieceContainer[i].getPosX() &&
                        x < pieceContainer[i].getPosX() + 100 &&
                        y > pieceContainer[i].getPosY() &&
                        y < pieceContainer[i].getPosY() + 100){
                    pieceContainer[i].flip();
                    std::cout << "hit" << std::endl;
                }
            }
        }
    }
    return quit;
}

void Game::loadTextures() {
    Texture board = display.loadTexture("../pic/board.png");
    Texture flag = display.loadTexture("../pic/flag.png");
    Texture bomb = display.loadTexture("../pic/bomb.png");
    Texture redBack = display.loadTexture("../pic/red_back.png");
    Texture blueBack = display.loadTexture("../pic/blue_back.png");

    textureMap[Textures::bombTexture] = bomb;
    textureMap[Textures::flagTexture] = flag;
    textureMap[Textures::boardTexture] = board;
    textureMap[Textures::redBackTexture] = redBack;
    textureMap[Textures::blueBackTexture] = blueBack;
}
