//
// Created by eros on 21/11/17.
//

#include "Game.h"
#include <memory>
#include "Board.h"

void Board::addToBoard(int x, int y, std::shared_ptr<Piece> piece) {
    int arrayPos = y * sizeParams::BOARD_FIELDS_NUMBER + x;
    piece->setPosInArray(arrayPos);
    boardArray[arrayPos] = piece;
    int pieceX = sizeParams::BOARD_OFFSET_X + x * sizeParams::FIELD_SIZE + sizeParams::PIECE_FIELD_DIFF;
    int pieceY = sizeParams::BOARD_OFFSET_Y + y * sizeParams::FIELD_SIZE + sizeParams::PIECE_FIELD_DIFF;
    piece->setSdl_rect(pieceX, pieceY);
}

void Board::addToInactive(int x, int y, std::shared_ptr<Piece> piece) {
    int arrayPos = y * sizeParams::INACTIVE_FIELDS_NUMBER_X + x;
    piece->setPosInArray(arrayPos);
    inactiveArray[arrayPos] = piece;
    int pieceX = sizeParams::INACTIVE_OFFSET_X + x * sizeParams::FIELD_SIZE  + sizeParams::PIECE_FIELD_DIFF;
    int pieceY = sizeParams::INACTIVE_OFFSET_Y + y * sizeParams::FIELD_SIZE  + sizeParams::PIECE_FIELD_DIFF;
    piece->setSdl_rect(pieceX, pieceY);
}

void Board::addToButtons(int pos, std::shared_ptr<Button> button) {
    button->setPosInArray(pos);
    buttonArray[pos] = button;
    //buttonArray 0. elementh to inActiveArray 77. elementh
    int buttonX = sizeParams::INACTIVE_OFFSET_X + (6+pos) * sizeParams::FIELD_SIZE;
    int buttonY = sizeParams::INACTIVE_OFFSET_Y + 9 * sizeParams::FIELD_SIZE;
    button->sdl_rect.x = buttonX;
    button->sdl_rect.y = buttonY;
}

void Board::removeFromBoard(int x, int y) {
    // TODO Try with reset
    boardArray[y * sizeParams::BOARD_SIZE + x] = nullptr;
}

void Board::renderPieces(SDL_Renderer *renderer, std::shared_ptr<Piece> &selectedPiece, std::shared_ptr<Texture> &texture) {
    for(auto &piece : boardArray) {
        if (piece) {
            piece->render(renderer);
/*
            if(piece == selectedPiece) {
                graphicallySelect(renderer, selectedPiece->getSdl_rect(), texture);
            }
*/
        }
    }
    for(auto &piece : inactiveArray) {
        if (piece) {
            piece->render(renderer);
/*
            if(piece == selectedPiece) {
                graphicallySelect(renderer, selectedPiece->getSdl_rect(), texture);
            }
*/
        }
    }
}

void Board::renderButtons(SDL_Renderer *renderer) {
    for(auto &button : buttonArray) {
        if (button) {
            button->render(renderer);
        }
    }
}

std::shared_ptr<Piece> Board::getClickedPiece(const int &x, const int &y) const {
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

std::shared_ptr<Button> Board::getClickedButton(const int &x, const int &y) const {
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

const std::array<std::shared_ptr<Piece>, 100> &Board::getBoardArray() const {
    return boardArray;
}

void Board::graphicallySelect(SDL_Renderer *renderer, SDL_Rect position, std::shared_ptr<Texture> &texture) {
    if ( position.x != -1) {
        int x1 = position.x;
        int y1 = position.y;
        selectionRect.x = x1;
        selectionRect.y = y1;
        SDL_RenderCopy(renderer, texture->getSDLTexture(), NULL, &selectionRect);
    }
}

void Board::setBoardArray(const std::shared_ptr<Piece> piece) {
    int newPosInArray = piece->getPosInArray();
    boardArray[newPosInArray] = piece;
}

void Board::setToInactiveArray(const std::shared_ptr<Piece> piece) {
    for(int i=0; i<inactiveArray.size(); i++) {
        if(inactiveArray[i] == nullptr){
            int posX = sizeParams::INACTIVE_OFFSET_X + sizeParams::FIELD_SIZE * (i % sizeParams::INACTIVE_FIELDS_NUMBER_X);
            int posY = sizeParams::INACTIVE_OFFSET_Y + sizeParams::FIELD_SIZE * (i / sizeParams::INACTIVE_FIELDS_NUMBER_X);
            int x = posX + sizeParams::PIECE_FIELD_DIFF;
            int y = posY + sizeParams::PIECE_FIELD_DIFF;
            piece->setSdl_rect(x, y);
            piece->setPosInArray(i);
            inactiveArray[i] = piece;
            break;
        }
    }
    piece->setOnBoard(false);
}

void Board::removeFromBoardArray(int oldPos) {
    boardArray[oldPos] = nullptr;
}

void Board::removeFromInactiveArray(int oldPos) {
    inactiveArray[oldPos] = nullptr;
}

const std::array<std::shared_ptr<Button>, 2> &Board::getButtonArray() const {
    return buttonArray;
}

const std::array<std::shared_ptr<Piece>, 80> &Board::getInactiveArray() const {
    return inactiveArray;
}
