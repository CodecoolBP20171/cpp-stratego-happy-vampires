//
// Created by en on 2017.11.09..
//

#include <memory>
#include <ctime>
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

    std::srand(std::time(0));

    display.init();
    loadTextures();
    createPieces();
    createButtons();
    initGame();
    gameLoop();
}

void Game::loadTextures() {
    // TODO collect nicer pictures for pieces: Béci
    // TODO Design final background: Béci
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
    textureMap[Textures::selectionTexture] = display.loadTexture("../pic/selection.png");
    textureMap[Textures::activeLogoTexture] = display.loadTexture("../pic/hv_logo.png");
    textureMap[Textures::inactiveLogoTexture] = display.loadTexture("../pic/hv_logo_inactive.png");
}

void Game::createPieces() {
/*
    boardArray[0] = std::make_shared<Scout>
     (0, 0, Rank::scoutRank, Color::red,
     textureMap[Textures::red2Texture]->getSDLTexture(),
     textureMap[Textures::redBackTexture]->getSDLTexture(), true, false);

    boardArray[99] = std::make_shared<Flag>
        (9, 9, Rank::bombRank, Color::blue,
         textureMap[Textures::blueBombTexture]->getSDLTexture(),
         textureMap[Textures::blueBackTexture]->getSDLTexture(), true, false);

    boardArray[10] = std::make_shared<Soldier>
        (0, 1, Rank::majorRank, Color::blue,
         textureMap[Textures::blue7Texture]->getSDLTexture(),
         textureMap[Textures::blueBackTexture]->getSDLTexture(), true, false);

    boardArray[11] = std::make_shared<Soldier>
        (1, 1, Rank::majorRank, Color::red,
        textureMap[Textures::red7Texture]->getSDLTexture(),
        textureMap[Textures::redBackTexture]->getSDLTexture(), true, false);

    boardArray[20] = std::make_shared<Soldier>
        (0, 2, Rank::majorRank, Color::red,
        textureMap[Textures::red7Texture]->getSDLTexture(),
        textureMap[Textures::redBackTexture]->getSDLTexture(), true, false);

    boardArray[30] = std::make_shared<Flag>
         (0, 3, Rank::flagRank, Color::blue,
         textureMap[Textures::blueFlagTexture]->getSDLTexture(),
         textureMap[Textures::blueBackTexture]->getSDLTexture(), true, false);


    boardArray[77] = std::make_shared<Soldier>
        (7, 7, Rank::majorRank, Color::blue,
        textureMap[Textures::blue7Texture]->getSDLTexture(),
        textureMap[Textures::blueBackTexture]->getSDLTexture(), true, false);

    boardArray[88] = std::make_shared<Scout>
        (8, 8, Rank::scoutRank, Color::blue,
        textureMap[Textures::blue2Texture]->getSDLTexture(),
        textureMap[Textures::blueBackTexture]->getSDLTexture(), true, false);
*/
    // initilaizing red setup
    //initRedSetup();
    initRedSetupForTesting();

    /*
     *     board.addToBoard(0, 0, std::make_shared<Soldier>
            (0, 0, majorRank, red,
             textureMap[red7Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));

     */
    board.addToBoard(2, 4, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(3, 4, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(6, 4, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(7, 4, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(2, 5, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(3, 5, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(6, 5, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(7, 5, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    /*boardArray[43] = std::make_shared<Barrier>(2, 5, Rank::barrierRank, Color::neutral);
    boardArray[46] = std::make_shared<Barrier>(3, 4, Rank::barrierRank, Color::neutral);
    boardArray[47] = std::make_shared<Barrier>(3, 5, Rank::barrierRank, Color::neutral);
    boardArray[52] = std::make_shared<Barrier>(6, 4, Rank::barrierRank, Color::neutral);
    boardArray[53] = std::make_shared<Barrier>(6, 5, Rank::barrierRank, Color::neutral);
    boardArray[56] = std::make_shared<Barrier>(7, 4, Rank::barrierRank, Color::neutral);
    boardArray[57] = std::make_shared<Barrier>(7, 5, Rank::barrierRank, Color::neutral);
     */
}

void Game::initRedSetup() {
    board.addToInactive(0, 0, std::make_shared<Flag>
        (flagRank, red,
         textureMap[redFlagTexture]->getSDLTexture(),
         textureMap[redBackTexture]->getSDLTexture(), false, false));
    for(int i = 0; i < 6; ++i) {
        board.addToInactive(1+i, 0, std::make_shared<Bomb>
         (bombRank, red,
          textureMap[redBombTexture]->getSDLTexture(),
          textureMap[redBackTexture]->getSDLTexture(), false, false));
    }
    board.addToInactive(7, 0, std::make_shared<Spy>
         (spyRank, red,
          textureMap[red1Texture]->getSDLTexture(),
          textureMap[redBackTexture]->getSDLTexture(), false, false));
    for(int i = 0; i < 8; ++i) {
        board.addToInactive(0+i, 1, std::make_shared<Scout>
            (scoutRank, red,
             textureMap[red2Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 5; ++i) {
        board.addToInactive(0+i, 2, std::make_shared<Miner>
            (minerRank, red,
             textureMap[red3Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToInactive(0+i, 3, std::make_shared<Soldier>
            (sergeantRank, red,
             textureMap[red4Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToInactive(4+i, 3, std::make_shared<Soldier>
            (lieutenantRank, red,
             textureMap[red5Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToInactive(0+i, 4, std::make_shared<Soldier>
            (captainRank, red,
             textureMap[red6Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 3; ++i) {
        board.addToInactive(4+i, 4, std::make_shared<Soldier>
            (majorRank, red,
             textureMap[red7Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 2; ++i) {
        board.addToInactive(0+i, 5, std::make_shared<Soldier>
            (colonelRank, red,
             textureMap[red8Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), false, false));
    }
    board.addToInactive(0, 6, std::make_shared<Soldier>
        (generalRank, red,
         textureMap[red9Texture]->getSDLTexture(),
         textureMap[redBackTexture]->getSDLTexture(), false, false));
    board.addToInactive(0, 7, std::make_shared<Soldier>
        (marshallRank, red,
         textureMap[red10Texture]->getSDLTexture(),
         textureMap[redBackTexture]->getSDLTexture(), false, false));
}

void Game::initRedSetupForTesting() {
    board.addToBoard(0, 0, std::make_shared<Soldier>
            (majorRank, red,
             textureMap[red7Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    board.addToBoard(1, 0, std::make_shared<Soldier>
            (majorRank, red,
             textureMap[red7Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    board.addToBoard(0, 1, std::make_shared<Soldier>
            (majorRank, red,
             textureMap[red7Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    board.addToBoard(0, 3, std::make_shared<Scout>
            (scoutRank, red,
             textureMap[red2Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));

    board.addToBoard(9, 9, std::make_shared<Soldier>
            (majorRank, blue,
             textureMap[blue7Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), true, false));

    /*board.addToInactive(0, 0, std::make_shared<Flag>
            (flagRank, red,
             textureMap[redFlagTexture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), false, false));
    for(int i = 0; i < 6; ++i) {
        board.addToBoard(0+i, 6, std::make_shared<Bomb>
            (bombRank, red,
             textureMap[redBombTexture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    }
    board.addToBoard(6, 6, std::make_shared<Spy>
            (spyRank, red,
             textureMap[red1Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));

    for(int i = 0; i < 8; ++i) {
        board.addToBoard(0+i, 7, std::make_shared<Scout>
            (scoutRank, red,
             textureMap[red2Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 5; ++i) {
        board.addToBoard(0+i, 8, std::make_shared<Miner>
            (minerRank, red,
             textureMap[red3Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToBoard(5+i, 8, std::make_shared<Soldier>
            (sergeantRank, red,
             textureMap[red4Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToBoard(0+i, 9, std::make_shared<Soldier>
            (lieutenantRank, red,
             textureMap[red5Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToBoard(4+i, 9, std::make_shared<Soldier>
            (captainRank, red,
             textureMap[red6Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 3; ++i) {
        board.addToBoard(7+i, 6, std::make_shared<Soldier>
            (majorRank, red,
             textureMap[red7Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 2; ++i) {
        board.addToBoard(8+i, 7, std::make_shared<Soldier>
            (colonelRank, red,
             textureMap[red8Texture]->getSDLTexture(),
             textureMap[redBackTexture]->getSDLTexture(), true, false));
    }
    board.addToBoard(9, 8, std::make_shared<Soldier>
        (generalRank, red,
         textureMap[red9Texture]->getSDLTexture(),
         textureMap[redBackTexture]->getSDLTexture(), true, false));
    board.addToInactive(0, 7, std::make_shared<Soldier>
        (marshallRank, red,
         textureMap[red10Texture]->getSDLTexture(),
         textureMap[redBackTexture]->getSDLTexture(), false, false));
*/}

void Game::initBlueSetupForTesting() {
    board.addToInactive(0, 0, std::make_shared<Flag>
        (flagRank, blue,
         textureMap[blueFlagTexture]->getSDLTexture(),
         textureMap[blueBackTexture]->getSDLTexture(), false, false));
    for(int i = 0; i < 6; ++i) {
        board.addToBoard(0+i, 0, std::make_shared<Bomb>
            (bombRank, blue,
             textureMap[blueBombTexture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), true, false));
    }
    board.addToBoard(6, 0, std::make_shared<Spy>
        (spyRank, blue,
         textureMap[blue1Texture]->getSDLTexture(),
         textureMap[blueBackTexture]->getSDLTexture(), true, false));
    for(int i = 0; i < 8; ++i) {
        board.addToBoard(0+i, 1, std::make_shared<Scout>
            (scoutRank, blue,
             textureMap[blue2Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 5; ++i) {
        board.addToBoard(0+i, 2, std::make_shared<Miner>
            (minerRank, blue,
             textureMap[blue3Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToBoard(5+i, 2, std::make_shared<Soldier>
            (sergeantRank, blue,
             textureMap[blue4Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToBoard(0+i, 3, std::make_shared<Soldier>
            (lieutenantRank, blue,
             textureMap[blue5Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToBoard(4+i, 3, std::make_shared<Soldier>
            (captainRank, blue,
             textureMap[blue6Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 3; ++i) {
        board.addToBoard(7+i, 0, std::make_shared<Soldier>
        (majorRank, blue,
             textureMap[blue7Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), true, false));
    }
    for(int i = 0; i < 2; ++i) {
        board.addToBoard(8+i, 1, std::make_shared<Soldier>
            (colonelRank, blue,
             textureMap[blue8Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), true, false));
    }
    board.addToBoard(9, 2, std::make_shared<Soldier>
        (generalRank, blue,
         textureMap[blue9Texture]->getSDLTexture(),
         textureMap[blueBackTexture]->getSDLTexture(), true, false));
    board.addToInactive(0, 7, std::make_shared<Soldier>
        (marshallRank, blue,
         textureMap[blue10Texture]->getSDLTexture(),
         textureMap[blueBackTexture]->getSDLTexture(), false, false));
}

void Game::initBlueSetup() {
    board.addToInactive(0, 0, std::make_shared<Flag>
        (flagRank, blue,
         textureMap[blueFlagTexture]->getSDLTexture(),
         textureMap[blueBackTexture]->getSDLTexture(), false, false));
    for(int i = 0; i < 6; ++i) {
        board.addToInactive(1+i, 0, std::make_shared<Bomb>
            (bombRank, blue,
             textureMap[blueBombTexture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), false, false));
    }
    board.addToInactive(7, 0, std::make_shared<Spy>
        (spyRank, blue,
         textureMap[blue1Texture]->getSDLTexture(),
         textureMap[blueBackTexture]->getSDLTexture(), false, false));
    for(int i = 0; i < 8; ++i) {
        board.addToInactive(0+i, 1, std::make_shared<Scout>
            (scoutRank, blue,
             textureMap[blue2Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 5; ++i) {
        board.addToInactive(0+i, 2, std::make_shared<Miner>
            (minerRank, blue,
             textureMap[blue3Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToInactive(0+i, 3, std::make_shared<Soldier>
            (sergeantRank, blue,
             textureMap[blue4Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToInactive(4+i, 3, std::make_shared<Soldier>
            (lieutenantRank, blue,
             textureMap[blue5Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 4; ++i) {
        board.addToInactive(0+i, 4, std::make_shared<Soldier>
            (captainRank, blue,
             textureMap[blue6Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 3; ++i) {
        board.addToInactive(4+i, 4, std::make_shared<Soldier>
            (majorRank, blue,
             textureMap[blue7Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), false, false));
    }
    for(int i = 0; i < 2; ++i) {
        board.addToInactive(0+i, 5, std::make_shared<Soldier>
            (colonelRank, blue,
             textureMap[blue8Texture]->getSDLTexture(),
             textureMap[blueBackTexture]->getSDLTexture(), false, false));
    }
    board.addToInactive(0, 6, std::make_shared<Soldier>
        (generalRank, blue,
         textureMap[blue9Texture]->getSDLTexture(),
         textureMap[blueBackTexture]->getSDLTexture(), false, false));
    board.addToInactive(0, 7, std::make_shared<Soldier>
        (marshallRank, blue,
         textureMap[blue10Texture]->getSDLTexture(),
         textureMap[blueBackTexture]->getSDLTexture(), false, false));
}

void Game::createButtons() {
    board.addToButtons(0, std::make_shared<Button>
        (textureMap[Textures::activeLogoTexture]->getSDLTexture(),
         textureMap[Textures::inactiveLogoTexture]->getSDLTexture(), false));
}

void Game::initGame() {
    board.selectionRect.h = sizeParams::PIECE_SIZE;
    board.selectionRect.w = sizeParams::PIECE_SIZE;
    currentPlayer = Color::red;
    // should be initially:
    //gameState = GameState::boardSetupState;

    // THE BELOW LINES ARE USED ONLY IN THE DEVELOPMENT PHASE, THEY WILL BE ALTERED IN THE FINAL GAME


    gameState = GameState::gameState;
    switchPlayers();
    flipAllPiecesOfCurrentPlayer();
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
        // convertClickedCoordsToArrayPlace(x, y);
        //std::cout << "click @ " << clickedX << " " << clickedY << std::endl;
        printGameState();
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

bool Game::onInactiveField() const {
    int inactiveFieldUpperLeftX = sizeParams::INACTIVE_OFFSET_X;
    int inactiveFieldUpperLeftY = sizeParams::INACTIVE_OFFSET_Y;
    int inactiveFieldBottomRightX = inactiveFieldUpperLeftX
                                    + sizeParams::INACTIVE_FIELDS_NUMBER_X * sizeParams::FIELD_SIZE;
    int inactiveFieldBottomRightY = inactiveFieldUpperLeftY
                                    + sizeParams::INACTIVE_FIELDS_NUMBER_Y * sizeParams::FIELD_SIZE;
    return (clickedX >= inactiveFieldUpperLeftX && clickedX <= inactiveFieldBottomRightX
                         && clickedY >= inactiveFieldUpperLeftY && clickedY <= inactiveFieldBottomRightY);
}

bool Game::onBoard() const {
    int boardUpperLeftX = sizeParams::BOARD_X;
    int boardUpperLeftY = sizeParams::BOARD_Y;
    int boardBottomRightX = boardUpperLeftX
                              + sizeParams::BOARD_FIELDS_NUMBER * sizeParams::FIELD_SIZE;
    int boardBottomRightY = boardUpperLeftY
                              + sizeParams::BOARD_FIELDS_NUMBER * sizeParams::FIELD_SIZE;
    return (clickedX >= boardUpperLeftX && clickedX <= boardBottomRightX
            && clickedY >= boardUpperLeftY && clickedY <= boardBottomRightY);
}


bool Game::onRedSide() const {
    //lower board side == red side
    int redSideUpperLeftX = sizeParams::BOARD_X;
    int redSideUpperLeftY = sizeParams::BOARD_Y + 6 * sizeParams::FIELD_SIZE;
    int redSideBottomRightX = redSideUpperLeftX
                              + sizeParams::BOARD_FIELDS_NUMBER * sizeParams::FIELD_SIZE;
    int redSideBottomRightY = redSideUpperLeftY
                              + sizeParams::BOARD_FIELDS_NUMBER * sizeParams::FIELD_SIZE;
    return (clickedX >= redSideUpperLeftX && clickedX <= redSideBottomRightX
                     && clickedY >= redSideUpperLeftY && clickedY <= redSideBottomRightY);
}

bool Game::onBlueSide() const {
    //upper board side == blue side
    int blueSideUpperLeftX = sizeParams::BOARD_X;
    int blueSideUpperLeftY = sizeParams::BOARD_Y;
    int blueSideBottomRightX = blueSideUpperLeftX
                               + sizeParams::BOARD_FIELDS_NUMBER * sizeParams::FIELD_SIZE;
    int blueSideBottomRightY = blueSideUpperLeftY
                               + 4 * sizeParams::FIELD_SIZE;
    return (clickedX >= blueSideUpperLeftX && clickedX <= blueSideBottomRightX
                      && clickedY >= blueSideUpperLeftY && clickedY <= blueSideBottomRightY);
}

void Game::boardSetupLogic() {
    std::shared_ptr<Piece> clickedPiece = board.getClickedPiece(clickedX, clickedY);
    std::shared_ptr<Button> clickedButton = board.getClickedButton(clickedX, clickedY);
    if (clickedButton && clickedButton == board.getButtonArray()[Buttons::next] && blueSetup) {
        gameState = GameState::gameState;
        clickedButton->setActive(false);
        return;
    }
    if (clickedButton && clickedButton == board.getButtonArray()[Buttons::next] && waitingForSwitchPlayers) {
        clickedButton->setActive(false);
        switchPlayers();
        blueSetupPhase = true;
        //initBlueSetup();
        initBlueSetupForTesting();
    }
    if (clickedButton && clickedButton == board.getButtonArray()[Buttons::next] && !waitingForSwitchPlayers) {
        flipAllPiecesOfCurrentPlayer();
        waitingForSwitchPlayers = true;
    }
    if(!board.getButtonArray()[Buttons::next]->isActive() && onInactiveField()) {
        //std::cout << "clicked on inactive field" << std::endl;
        //std::shared_ptr<Piece> clickedPiece = getClickedPiece(clickedX, clickedY);
        //TODO it seems to be working, but not implementing exactly the flowchart, check it!!!
        // when there is a selected piece and the user clicks on a diferent piece, deselect the old selection and select clicked
        if (clickedPiece) {
            std::cout << "You clicked on a " << clickedPiece->getColor() << " "
                      << clickedPiece->getRank() << " "
                      << " @ array index " << clickedPiece->getPosInArray() << std::endl;
            if(selectedPiece) {
                std::cout << "deselect" << std::endl;
                deselect();
            } else {
                selectPiece(clickedPiece);
                std::cout << "You selected a " << selectedPiece->getColor() << " "
                          << selectedPiece->getRank() << " "
                          << " @ array index " << selectedPiece->getPosInArray() << std::endl;
            }
        }
    } else if ( (currentPlayer == red && onRedSide()) || (currentPlayer == blue && onBlueSide()) ) {
        std::cout << "click on current players side" << std::endl;
        if ( clickedPiece != selectedPiece) {
            //isOccupied
            //TODO debug: sometimes I can put a piece on top of another
            if (!board.getClickedPiece(clickedX, clickedY)) {
                //moving
                std::cout << "setup to board array index ";
                //deselect();
                int oldPos = selectedPiece->getPosInArray(); //std::cout << "oldPos " << oldPos << std::endl;

                //selectedPiece->setupTo(clickedX, clickedY);

                //int newPos = selectedPiece->getPosInArray(); //std::cout << "newPos " << newPos << std::endl;
                selectedPiece->setupTo(clickedX, clickedY);
                board.setBoardArray(selectedPiece);
                board.removeFromPosInArray(oldPos);
                //boardArray[newPos] = std::move(inactiveArray[oldPos]);
                deselect();
                if(isRedSetup() && !blueSetupPhase) board.getButtonArray()[Buttons::next]->setActive(true);
                if(blueSetupPhase && isBlueSetup()) board.getButtonArray()[Buttons::next]->setActive(true);
            }
        }
    }
}

void Game::gameStateLogic() {
    // TODO: apply full plan (flowchart), for example after move wait for click, etc.
    // TODO: if there is a click on the board -> can go to a separated function!
    if(clickedX >= 0 && clickedY >= 0 && clickedX <= sizeParams::BOARD_MAX_X && clickedX <= sizeParams::BOARD_MAX_Y) {
        std::shared_ptr<Piece> clickedPiece = board.getClickedPiece(clickedX, clickedY);
        if (clickedPiece) {
            if (currentPlayer == clickedPiece->getColor()) {
                if (clickedPiece->canMove() && clickedPiece->isNotBlocked(board.getBoardArray())) {
                    selectPiece(clickedPiece);
                }
            } else if(clickedPiece->getColor() == enemyColor() && selectedPiece) {
                // attacker = selectedPiece, defender = clickedPiece
                if(selectedPiece->isInAttackPosition(clickedPiece, board.getBoardArray())) {
                    FightWinner fightwinner = selectedPiece->attack(clickedPiece);
                    executeFight(selectedPiece, clickedPiece, fightwinner);
                }
            }

        } else {
            if (selectedPiece) {
                int oldPos = selectedPiece->getPosInArray(); //std::cout << "oldPos " << oldPos << std::endl;
                if (selectedPiece->moveTo(clickedX, clickedY, board.getBoardArray())) {
                    //int newPos = selectedPiece->getPosInArray(); //std::cout << "newPos " << newPos << std::endl;
                    board.setBoardArray(selectedPiece);
                    board.removeFromPosInArray(oldPos);
                    deselect();
                    // TODO: here we should wait for the click... HOW????
                    // maybe: use a Game obj var to mark this point, for example
                    // waitForClick = true; and check this variable on the top of this function
                    // and if it is true -> proceed "playback" of the action,
                    // a few additional obj vars could be necessary to achieve this
                    flipAllPiecesOfCurrentPlayer();
                    switchPlayers();
                    flipAllPiecesOfCurrentPlayer();
                }
            }
        }
    }
}

void Game::renderAll() {
    SDL_RenderClear(display.getRenderer());
    textureMap[Textures::boardTexture]->render(display.getRenderer(), nullptr);
    board.renderPieces(display.getRenderer(), selectedPiece, textureMap[Textures::selectionTexture]);
    board.renderButtons(display.getRenderer());

/*
    for(int i = 0; i < pieceContainer.size(); i++){
        pieceContainer[i]->render(display.getRenderer());
        // if there is a selected piece, render the selection
        if(pieceContainer[i] == selectedPiece) {
            graphicallySelect();
        }
    }
*/
    /*for(auto &piece : inactiveArray) {
        if (piece) {
            piece->render(display.getRenderer());
            if(piece == selectedPiece) { graphicallySelect(); }
        }
    }
    for(auto &piece : boardArray) {
        if (piece) {
            piece->render(display.getRenderer());
            if(piece == selectedPiece) { graphicallySelect(); }
        }
    }
    for(auto &button : buttonArray) {
        if (button) {
            button->render(display.getRenderer());
        }
    }
     */
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

void Game::executeFight(std::shared_ptr<Piece> attacker, std::shared_ptr<Piece> defender, FightWinner winner) {
    std::shared_ptr<Piece> loser1;
    std::shared_ptr<Piece> loser2 = nullptr;
    int defenderSDLRectX, defenderSDLRectY, defenderPosInArray, attackerPosInArray;
    if(defender->getRank() == Rank::flagRank) {
        gameOver(attacker);
    }
    if(winner == FightWinner::attacker){
        // TODO: "moving attacker to the place of defender if attacker wins" solution could be much nicer
        defenderSDLRectX = defender->getSdl_rectX();
        defenderSDLRectY = defender->getSdl_rectY();
        defenderPosInArray = defender->getPosInArray();
        attackerPosInArray = attacker->getPosInArray();
        defender->flip();
        loser1 = defender;
    } else if(winner == FightWinner::defender){
        loser1 = attacker;
    } else {
        loser1 = defender;
        loser2 = attacker;
    }
    throwOutLoserToInactivePieces(loser1);

    if(winner == FightWinner::attacker) {
        attacker->setSdl_rect(defenderSDLRectX, defenderSDLRectY);
        attacker->setPosInArray(defenderPosInArray);
        board.setBoardArray(attacker);
        board.removeFromPosInArray(attackerPosInArray);
    }

    if(loser2) {
        loser1->flip();
        throwOutLoserToInactivePieces(loser2);
    }
    deselect();
    flipAllPiecesOfCurrentPlayer();
    switchPlayers();
    flipAllPiecesOfCurrentPlayer();
}

std::shared_ptr<Button> Game::getClickedButton(const int &x, const int &y) const {
    std::shared_ptr<Button> result = nullptr;
    for(auto & button : buttonArray) {
        if (button) {
            if (x > button->getSdl_rect().x &&
                x < button->getSdl_rect().x + sizeParams::FIELD_SIZE &&
                y > button->getSdl_rect().y &&
                y < button->getSdl_rect().y + sizeParams::FIELD_SIZE) {
                if (button->isActive()) {
                    button->setClicked(true);
                    std::cout << "button clicked\n";
                    result = button;
                    return result;
                }
            }
        }
    }
}

void Game::switchPlayers() {
    currentPlayer = (currentPlayer == Color::red ? Color::blue : Color::red);
}

void Game::flipAllPiecesOfCurrentPlayer() {
    for(auto &piece : board.getBoardArray()) {
        if(piece) {
            if (piece->getColor() == currentPlayer) {
                piece->flip();
            }
        }
    }
}

void Game::convertClickedCoordsToArrayPlace(int &x, int &y) {

}

void Game::printGameState() const {
    std::cout << "\tgameState " << gameState << std::endl;
    std::cout << "currentPlayer " << currentPlayer << std::endl;
    std::cout << "selectedPiece ";
    if (selectedPiece) {
        std::cout << selectedPiece->getColor() << " " << selectedPiece->getRank() << " ";
        if (selectedPiece->isOnBoard()) { std::cout << "on board" << std::endl; }
        else { std::cout << "on inactive" << std::endl; }
    } else { std::cout << "no selected piece" << std::endl; }
    std::cout << "clickedX " << clickedX << " clickedY " << " " << clickedY << std::endl;
    std::cout << "clicked on ";
    if (onInactiveField()) std::cout << "InactiveField" << std::endl;
    else if (onBoard()) {
        std::cout << "Board @ ";
        if (onRedSide()) std::cout << "red side" << std::endl;
        else if (onBlueSide()) std::cout << "blue side" << std::endl;
        else std::cout << "middle field" << std::endl;
    } else std::cout << "elsewhere" << std::endl;
    std::shared_ptr<Piece> clickedPiece = board.getClickedPiece(clickedX, clickedY);
    std::cout << "clickedPiece ";
    if (clickedPiece) {
        std::cout << clickedPiece->getColor() << " " << clickedPiece->getRank() << " ";
        if (clickedPiece->isOnBoard()) { std::cout << "on board array index " << clickedPiece->getPosInArray() << std::endl; }
        else { std::cout << "on inactive array index " << clickedPiece->getPosInArray() << std::endl; }
    } else { std::cout << "no clicked piece" << std::endl; }
    std::cout << "\tinactive\n";
    for (int h = 0; h < sizeParams::INACTIVE_FIELDS_NUMBER_Y; ++h) {
        for(int w = 0; w < sizeParams::INACTIVE_FIELDS_NUMBER_X; ++w) {
            if (board.getInactiveArray()[h*sizeParams::INACTIVE_FIELDS_NUMBER_X+w]) {
            std::cout << board.getInactiveArray()[h*sizeParams::INACTIVE_FIELDS_NUMBER_X+w]->getColor() << " "
                      << board.getInactiveArray()[h*sizeParams::INACTIVE_FIELDS_NUMBER_X+w]->getRank() << "\t\t";
            } else {std::cout << "n" << " " << "n" << "\t\t";}
        }
        std::cout << std::endl;
    }
    std::cout << "\tboard\n";
    for (int h = 0; h < sizeParams::BOARD_FIELDS_NUMBER; ++h) {
        for(int w = 0; w < sizeParams::BOARD_FIELDS_NUMBER; ++w) {
            if (board.getBoardArray()[h*sizeParams::BOARD_FIELDS_NUMBER+w]) {
                std::cout << board.getBoardArray()[h*sizeParams::BOARD_FIELDS_NUMBER+w]->getColor() << " "
                          << board.getBoardArray()[h*sizeParams::BOARD_FIELDS_NUMBER+w]->getRank() << "\t\t";
            } else {std::cout << "n" << " " << "n" << "\t\t";}

        }
        std::cout << std::endl;
    }
}

Color Game::enemyColor() {
    return (currentPlayer == Color::red ? Color::blue : Color::red);
}

void Game::gameOver(std::shared_ptr<Piece> gameWinner) {
    std::cout << "Game over. The " << (gameWinner->getColor() == Color::red ? "red" : "blue") << " player wins!"  << std::endl;
    // TODO do something else here! for example, gameState could be gameOver in order to avoid further piece movement + a gameover screen...
}

bool Game::isRedSetup() {
    for(int i = 60; i < 100; ++i) {
        if(!board.getBoardArray()[i]) return false;
    }
    redSetup = true;
    return true;
}

bool Game::isBlueSetup() {
    for(int i = 0; i < 40; ++i) {
        if(!board.getBoardArray()[i]) return false;
    }
    blueSetup = true;
    return true;
}

void Game::throwOutLoserToInactivePieces(std::shared_ptr<Piece> loser) {
    int oldPos = loser->getPosInArray(); //std::cout << "oldPos " << oldPos << std::endl;
    board.setToInactiveArray(loser);
    board.removeFromPosInArray(oldPos);
}
