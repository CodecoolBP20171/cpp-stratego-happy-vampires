//
// Created by en on 2017.11.09..
//

#include <memory>
#include <ctime>
#include "Display.h"
#include "Game.h"
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
    textureMap[Textures::blueResetTexture] = display.loadTexture("../pic/blueReset.png");
}

void Game::createPieces() {
    initRedSetup();
    board.addToBoard(2, 4, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(3, 4, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(6, 4, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(7, 4, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(2, 5, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(3, 5, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(6, 5, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
    board.addToBoard(7, 5, std::make_shared<Barrier>(Rank::barrierRank, Color::neutral));
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

    board.addToButtons(1, std::make_shared<Button>
            (textureMap[Textures::blueResetTexture]->getSDLTexture(),
             textureMap[Textures::blueResetTexture]->getSDLTexture(), true));
}

void Game::initGame() {
    board.selectionRect.h = sizeParams::PIECE_SIZE;
    board.selectionRect.w = sizeParams::PIECE_SIZE;
    currentPlayer = Color::red;
    gameState = GameState::boardSetupState;
}

void Game::gameLoop() {
    bool quit = false;
    Uint32 timepassed = 0;
    Uint32  timestep = 16;
    while(!quit) {
        timepassed = SDL_GetTicks();
        SDL_Event sdl_event;
        while(SDL_PollEvent(&sdl_event) != 0){
            quit = handleEvents(sdl_event);
            gameLogic();
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
    if( event.type == SDL_MOUSEBUTTONDOWN ) {
        int x, y;
        SDL_GetMouseState( &x, &y );
        clickedX = x; clickedY = y;
    }
    return quit;
}

void Game::gameLogic() {
    std::shared_ptr<Button> clickedButton = board.getClickedButton(clickedX, clickedY);
    if (clickedButton && clickedButton == board.getButtonArray()[Buttons::restart]) {
        restartGame();
    }
    if(gameState == GameState::boardSetupState){
        boardSetupLogic();
    } else if(gameState == GameState::gameState){
        gameStateLogic();
    } else if(gameState == GameState::gameOverState){
        gameOver(selectedPiece);
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
        flipAllPiecesOfCurrentPlayer();
        waitingForSwitchPlayers = true;
    }
    if(clickedButton && clickedButton == board.getButtonArray()[Buttons::next] && blueSetup && waitingForSwitchPlayers){
        flipAllPiecesOfCurrentPlayer();
        gameState = GameState::gameState;
        waitingForSwitchPlayers = false;
    }
    if (clickedButton && clickedButton == board.getButtonArray()[Buttons::next] && waitingForSwitchPlayers) {
        clickedButton->setActive(false);
        switchPlayers();
        blueSetupPhase = true;
        initBlueSetup();
    }
    if (clickedButton && clickedButton == board.getButtonArray()[Buttons::next] && !waitingForSwitchPlayers) {
        flipAllPiecesOfCurrentPlayer();
        waitingForSwitchPlayers = true;
    }
    if(!board.getButtonArray()[Buttons::next]->isActive() && onInactiveField()) {
        if (clickedPiece) {
            if(selectedPiece) {
                deselect();
            } else {
                selectPiece(clickedPiece);
            }
        }
    } else if ( (currentPlayer == red && onRedSide()) || (currentPlayer == blue && onBlueSide()) ) {
        if ( clickedPiece != selectedPiece) {
            if (!board.getClickedPiece(clickedX, clickedY)) {
                int oldPos = selectedPiece->getPosInArray();
                selectedPiece->setupTo(clickedX, clickedY);
                board.setBoardArray(selectedPiece);
                board.removeFromInactiveArray(oldPos);
                deselect();
                if(isRedSetup() && !blueSetupPhase) board.getButtonArray()[Buttons::next]->setActive(true);
                if(blueSetupPhase && isBlueSetup()) board.getButtonArray()[Buttons::next]->setActive(true);
            }
        }
    }
}

void Game::gameStateLogic() {
    std::shared_ptr<Button> clickedButton = board.getClickedButton(clickedX, clickedY);
    if (clickedButton && clickedButton == board.getButtonArray()[Buttons::next] && waitingForSwitchPlayers) {
        switchPlayers();
        flipAllPiecesOfCurrentPlayer();
        waitingForSwitchPlayers = false;
        clickedButton->setActive(false);
    }
    else if (clickedButton && clickedButton == board.getButtonArray()[Buttons::next] && !waitingForSwitchPlayers) {
        flipAllPiecesOfCurrentPlayer();
        waitingForSwitchPlayers = true;
    }
    else if( !board.getButtonArray()[Buttons::next]->isActive() ) {
        if(clickedX >= 0 && clickedY >= 0 && clickedX <= sizeParams::BOARD_MAX_X && clickedX <= sizeParams::BOARD_MAX_Y) {
            std::shared_ptr<Piece> clickedPiece = board.getClickedPiece(clickedX, clickedY);
            if (clickedPiece) {
                if (currentPlayer == clickedPiece->getColor()) {
                    if (clickedPiece->canMove() && clickedPiece->isNotBlocked(board.getBoardArray())) {
                        selectPiece(clickedPiece);
                    }
                } else if(clickedPiece->getColor() == enemyColor() && selectedPiece) {
                    // attack
                    int oldPosInArray = selectedPiece->getPosInArray();
                    oldSDL_RectPosition = selectedPiece->getSdl_rect();
                    if(selectedPiece->isInAttackPosition(clickedPiece, board.getBoardArray())) {
                        FightWinner fightwinner = selectedPiece->attack(clickedPiece);
                        executeFight(selectedPiece, clickedPiece, fightwinner);
                        board.getButtonArray()[Buttons::next]->setActive(true);
                    }
                }
            } else {
                // move
                if (selectedPiece) {
                    int oldPosInArray = selectedPiece->getPosInArray();
                    oldSDL_RectPosition = selectedPiece->getSdl_rect();
                    if (selectedPiece->moveTo(clickedX, clickedY, board.getBoardArray())) {
                        board.setBoardArray(selectedPiece);
                        board.removeFromBoardArray(oldPosInArray);
                        deselect();
                        board.getButtonArray()[Buttons::next]->setActive(true);
                    }
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
    board.graphicallySelect(display.getRenderer(), oldSDL_RectPosition, textureMap[Textures::selectionTexture]);
    if(selectedPiece) board.graphicallySelect(display.getRenderer(), selectedPiece->getSdl_rect(), textureMap[Textures::selectionTexture]);
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
        gameState = GameState::gameOverState;
        return;
    }
    if(winner == FightWinner::attacker){
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
        board.removeFromBoardArray(attackerPosInArray);
    }
    if(loser2) {
        loser1->flip();
        throwOutLoserToInactivePieces(loser2);
    }
    deselect();
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

Color Game::enemyColor() {
    return (currentPlayer == Color::red ? Color::blue : Color::red);
}

void Game::gameOver(std::shared_ptr<Piece> gameWinner) {
    std::string winner = (gameWinner->getColor() == Color::red ? "red" : "blue");
    std::string message = "The winner is: " + winner;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "GAME OVER", message.c_str(), NULL);
    restartGame();
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
    int oldPos = loser->getPosInArray();
    board.setToInactiveArray(loser);
    board.removeFromBoardArray(oldPos);
}

void Game::restartGame() {
    for(auto& piece: board.getBoardArray()){
        if (piece) board.removeFromBoardArray(piece->getPosInArray());
    }
    for(auto& piece: board.getInactiveArray()){
        if (piece) board.removeFromInactiveArray(piece->getPosInArray());
    }
    initRedSetup();
    gameState = GameState::boardSetupState;
    currentPlayer = Color::red;
    board.getButtonArray()[Buttons::next]->setActive(false);
    oldSDL_RectPosition.x = -1;
    selectedPiece.reset();
    redSetup = false;
    blueSetup = false;
    waitingForSwitchPlayers = false;
    blueSetupPhase = false;
}
