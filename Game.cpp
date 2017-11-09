//
// Created by en on 2017.11.09..
//

#include "Display.h"
#include "Game.h"
#include "Piece.h"

void Game::run() {
    display.init();
    Texture board = display.loadTexture("../pic/board.png");
    Texture bomb = display.loadTexture("../pic/bomb.png");
    SDL_Texture *bombTexture = bomb.getSDLTexture();
    Piece piece(bombTexture);

    SDL_Delay(100);

    bool quit = false;
    Uint32 timepassed = 0;
    Uint32  timestep = 16;
    while(!quit) {
        timepassed = SDL_GetTicks();

        quit = handleEvents();

        SDL_RenderClear(display.getRenderer());
        board.render(display.getRenderer(), nullptr);
        piece.render(display.getRenderer());
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
            quit = true;
        }
    }

    return false;
}
