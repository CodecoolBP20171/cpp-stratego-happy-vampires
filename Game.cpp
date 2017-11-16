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
}

void Game::createPieces() {
    // TODO create all 80 pieces: Béci::subclasses will be needed for this (Dani task)

    boardArray[0] = std::make_shared<Scout>
     (0, 0, Rank::scoutRank, Color::red,
     textureMap[Textures::red2Texture]->getSDLTexture(),
     textureMap[Textures::redBackTexture]->getSDLTexture(), true, false);

    boardArray[99] = std::make_shared<Flag>
        (9, 9, Rank::bombRank, Color::blue,
         textureMap[Textures::blueBombTexture]->getSDLTexture(),
         textureMap[Textures::blueBackTexture]->getSDLTexture(), true, false);

    boardArray[10] = std::make_shared<Soldier>
        (0, 1, Rank::majorRank, Color::red,
         textureMap[Textures::red7Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), true, false);

    boardArray[11] = std::make_shared<Soldier>
        (1, 1, Rank::majorRank, Color::red,
        textureMap[Textures::red7Texture]->getSDLTexture(),
        textureMap[Textures::redBackTexture]->getSDLTexture(), true, false);

    boardArray[20] = std::make_shared<Soldier>
        (0, 2, Rank::majorRank, Color::red,
        textureMap[Textures::red7Texture]->getSDLTexture(),
        textureMap[Textures::redBackTexture]->getSDLTexture(), true, false);


    boardArray[77] = std::make_shared<Soldier>
        (7, 7, Rank::majorRank, Color::blue,
        textureMap[Textures::blue7Texture]->getSDLTexture(),
        textureMap[Textures::blueBackTexture]->getSDLTexture(), true, false);

    boardArray[88] = std::make_shared<Scout>
        (8, 8, Rank::scoutRank, Color::blue,
        textureMap[Textures::blue2Texture]->getSDLTexture(),
        textureMap[Textures::blueBackTexture]->getSDLTexture(), true, false);
/*
    // initilaizing red setup
    inactiveArray[0] = std::make_shared<Flag>
        (0, 0, Rank::flagRank, Color::red,
        textureMap[Textures::redFlagTexture]->getSDLTexture(),
        textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    for(int i = 0; i < 6; ++i) {
        inactiveArray[1+i] = std::make_shared<Bomb>
         ((1+i), 0, Rank::bombRank, Color::red,
         textureMap[Textures::redBombTexture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    }
    inactiveArray[7] = std::make_shared<Spy>
         (7, 0, Rank::spyRank, Color::red,
         textureMap[Textures::red1Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    for(int i = 0; i < 8; ++i) {
        inactiveArray[8+i] = std::make_shared<Scout>
            ((0+i), 1, Rank::scoutRank, Color::red,
             textureMap[Textures::red2Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    }
    for(int i = 0; i < 5; ++i) {
        inactiveArray[16+i] = std::make_shared<Miner>
            ((0+i), 2, Rank::minerRank, Color::red,
             textureMap[Textures::red3Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    }
    for(int i = 0; i < 4; ++i) {
        inactiveArray[24+i] = std::make_shared<Soldier>
            ((0+i), 3, Rank::sergeantRank, Color::red,
             textureMap[Textures::red4Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    }
    for(int i = 0; i < 4; ++i) {
        inactiveArray[28+i] = std::make_shared<Soldier>
            ((4+i), 3, Rank::lieutenantRank, Color::red,
             textureMap[Textures::red5Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    }
    for(int i = 0; i < 4; ++i) {
        inactiveArray[32+i] = std::make_shared<Soldier>
            ((0+i), 4, Rank::captainRank, Color::red,
             textureMap[Textures::red6Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    }
    for(int i = 0; i < 3; ++i) {
        inactiveArray[36+i] = std::make_shared<Soldier>
            ((4+i), 4, Rank::majorRank, Color::red,
             textureMap[Textures::red7Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    }
    for(int i = 0; i < 2; ++i) {
        inactiveArray[40+i] = std::make_shared<Soldier>
            ((0+i), 5, Rank::colonelRank, Color::red,
             textureMap[Textures::red8Texture]->getSDLTexture(),
             textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    }
    inactiveArray[48] = std::make_shared<Soldier>
        (0, 6, Rank::generalRank, Color::red,
         textureMap[Textures::red9Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
    inactiveArray[56] = std::make_shared<Soldier>
        (0, 7, Rank::marshallRank, Color::red,
         textureMap[Textures::red10Texture]->getSDLTexture(),
         textureMap[Textures::redBackTexture]->getSDLTexture(), false, false);
*/
    boardArray[42] = std::make_shared<Barrier>(2, 4, Rank::barrierRank, Color::neutral);
    boardArray[43] = std::make_shared<Barrier>(2, 5, Rank::barrierRank, Color::neutral);
    boardArray[46] = std::make_shared<Barrier>(3, 4, Rank::barrierRank, Color::neutral);
    boardArray[47] = std::make_shared<Barrier>(3, 5, Rank::barrierRank, Color::neutral);
    boardArray[52] = std::make_shared<Barrier>(6, 4, Rank::barrierRank, Color::neutral);
    boardArray[53] = std::make_shared<Barrier>(6, 5, Rank::barrierRank, Color::neutral);
    boardArray[56] = std::make_shared<Barrier>(7, 4, Rank::barrierRank, Color::neutral);
    boardArray[57] = std::make_shared<Barrier>(7, 5, Rank::barrierRank, Color::neutral);
}

void Game::initGame() {
    selectionRect.h = sizeParams::PIECE_SIZE;
    selectionRect.w = sizeParams::PIECE_SIZE;
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
                               + 3 * sizeParams::FIELD_SIZE;
    return (clickedX >= blueSideUpperLeftX && clickedX <= blueSideBottomRightX
                      && clickedY >= blueSideUpperLeftY && clickedY <= blueSideBottomRightY);
}

void Game::boardSetupLogic() {
    std::shared_ptr<Piece> clickedPiece = getClickedPiece(clickedX, clickedY);
    if(onInactiveField()) {
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
            if (!getClickedPiece(clickedX, clickedY)) {
                //moving
                std::cout << "setup to board array index ";
                //deselect();
                int oldPos = selectedPiece->getPosInArray(); //std::cout << "oldPos " << oldPos << std::endl;
                selectedPiece->setupTo(clickedX, clickedY);
                int newPos = selectedPiece->getPosInArray(); //std::cout << "newPos " << newPos << std::endl;
                boardArray[newPos] = std::move(inactiveArray[oldPos]);
                deselect();
            }
        }
    }
}

void Game::gameStateLogic() {
    // TODO: apply full plan (flowchart), for example after move wait for click, etc.
    // TODO: if there is a click on the board -> can go to a separated function!
    if(clickedX >= 0 && clickedY >= 0 && clickedX <= sizeParams::BOARD_MAX_X && clickedX <= sizeParams::BOARD_MAX_Y) {
        //std::cout << "clicked on the board!" << std::endl;
        // get clicked piece if the user clicked on a piece, nullptr otherwise
        std::shared_ptr<Piece> clickedPiece = getClickedPiece(clickedX, clickedY);
        // if the user clicked on a piece
        if (clickedPiece) {
            // if it is the current player's piece
            if (currentPlayer == clickedPiece->getColor()) {
                // select the clicked piece
                if(clickedPiece->canMove() && clickedPiece->isNotBlocked(boardArray)) {
                    selectPiece(clickedPiece);
                }
            }
            // st like else if(currentPlayer == enemyColor && selectedPiece) -> attack
        } else { // the user clicked on an empty field // later: or to an enemy
            // if there is a piece selected
            if (selectedPiece) {
                // if the piece can move to that empty field, move there
                int oldPos = selectedPiece->getPosInArray(); std::cout << "oldPos " << oldPos << std::endl;
                if (selectedPiece->moveTo(clickedX, clickedY, boardArray)) {
                    int newPos = selectedPiece->getPosInArray(); std::cout << "newPos " << newPos << std::endl;
                    boardArray[newPos] = std::move(boardArray[oldPos]);

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
/*
    for(int i = 0; i < pieceContainer.size(); i++){
        pieceContainer[i]->render(display.getRenderer());
        // if there is a selected piece, render the selection
        if(pieceContainer[i] == selectedPiece) {
            graphicallySelect();
        }
    }
*/
    for(auto &piece : inactiveArray) {
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
    int x1 = selectedPiece->getSdl_rect().x;
    //int x2 = selectedPiece->getSdl_rect().x + sizeParams::PIECE_SIZE;
    int y1 = selectedPiece->getSdl_rect().y;
    //int y2 = selectedPiece->getSdl_rect().y + sizeParams::PIECE_SIZE;
    selectionRect.x = x1;
    selectionRect.y = y1;
    SDL_RenderCopy(display.getRenderer(), textureMap[Textures::selectionTexture]->getSDLTexture(), NULL, &selectionRect);
//    SDL_SetRenderDrawColor(display.getRenderer(), 0, 0, 255, 255);
//    SDL_RenderDrawLine( display.getRenderer(), x1, y1, x1, y2 );
//    SDL_RenderDrawLine( display.getRenderer(), x1, y1, x2, y1 );
//    SDL_RenderDrawLine( display.getRenderer(), x2, y1, x2, y2 );
//    SDL_RenderDrawLine( display.getRenderer(), x1, y2, x2, y2 );
}

std::shared_ptr<Piece> Game::getClickedPiece(const int &x, const int &y) const {
    std::shared_ptr<Piece> result = nullptr;
    for(auto & piece : inactiveArray) {
        if (piece) {
            if (x > piece->getSdl_rect().x &&
                x < piece->getSdl_rect().x + sizeParams::FIELD_SIZE &&
                y > piece->getSdl_rect().y &&
                y < piece->getSdl_rect().y + sizeParams::FIELD_SIZE) {
                piece->setIsClicked(true);
                result = piece;
                return result;
            }
        }
    }
    for(auto & piece : boardArray) {
        if (piece) {
            if (x > piece->getSdl_rect().x &&
                x < piece->getSdl_rect().x + sizeParams::FIELD_SIZE &&
                y > piece->getSdl_rect().y &&
                y < piece->getSdl_rect().y + sizeParams::FIELD_SIZE) {
                piece->setIsClicked(true);
                result = piece;
                return result;
            }
        }
    }
}

void Game::switchPlayers() {
    currentPlayer = (currentPlayer == Color::red ? Color::blue : Color::red);
}

void Game::flipAllPiecesOfCurrentPlayer() {
    for(auto &piece : boardArray) {
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
    std::shared_ptr<Piece> clickedPiece = getClickedPiece(clickedX, clickedY);
    std::cout << "clickedPiece ";
    if (clickedPiece) {
        std::cout << clickedPiece->getColor() << " " << clickedPiece->getRank() << " ";
        if (clickedPiece->isOnBoard()) { std::cout << "on board array index " << clickedPiece->getPosInArray() << std::endl; }
        else { std::cout << "on inactive array index " << clickedPiece->getPosInArray() << std::endl; }
    } else { std::cout << "no clicked piece" << std::endl; }
    std::cout << "\tinactive\n";
    for (int h = 0; h < sizeParams::INACTIVE_FIELDS_NUMBER_Y; ++h) {
        for(int w = 0; w < sizeParams::INACTIVE_FIELDS_NUMBER_X; ++w) {
            if (inactiveArray[h*sizeParams::INACTIVE_FIELDS_NUMBER_X+w]) {
            std::cout << inactiveArray[h*sizeParams::INACTIVE_FIELDS_NUMBER_X+w]->getColor() << " "
                      << inactiveArray[h*sizeParams::INACTIVE_FIELDS_NUMBER_X+w]->getRank() << "\t\t";
            } else {std::cout << "n" << " " << "n" << "\t\t";}
        }
        std::cout << std::endl;
    }
    std::cout << "\tboard\n";
    for (int h = 0; h < sizeParams::BOARD_FIELDS_NUMBER; ++h) {
        for(int w = 0; w < sizeParams::BOARD_FIELDS_NUMBER; ++w) {
            if (boardArray[h*sizeParams::BOARD_FIELDS_NUMBER+w]) {
                std::cout << boardArray[h*sizeParams::BOARD_FIELDS_NUMBER+w]->getColor() << " "
                          << boardArray[h*sizeParams::BOARD_FIELDS_NUMBER+w]->getRank() << "\t\t";
            } else {std::cout << "n" << " " << "n" << "\t\t";}

        }
        std::cout << std::endl;
    }
}