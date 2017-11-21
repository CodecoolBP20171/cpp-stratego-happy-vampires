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
    int pieceX = sizeParams::BOARD_OFFSET_X + x * sizeParams::FIELD_SIZE;
    int pieceY = sizeParams::BOARD_OFFSET_Y + y * sizeParams::FIELD_SIZE;
    piece->setSdl_rect(pieceX, pieceY);

}

void Board::removeFromBoard(int x, int y) {
    // TODO Try with reset
    boardArray[y * sizeParams::BOARD_SIZE + x] = nullptr;
}

void Board::renderPieces(SDL_Renderer *renderer, std::shared_ptr<Piece> &selectedPiece, std::shared_ptr<Texture> &texture) {
    for(auto &piece : boardArray) {
        if (piece) {
            piece->render(renderer);
            if(piece == selectedPiece) {
                graphicallySelect(renderer, selectedPiece, texture);
            }
        }
    }
}

std::shared_ptr<Piece> Board::getClickedPiece(const int &x, const int &y) const {
    std::shared_ptr<Piece> result = nullptr;
//    for(auto & piece : inactiveArray) {
//        if (piece) {
//            if (x > piece->getSdl_rect().x &&
//                x < piece->getSdl_rect().x + sizeParams::FIELD_SIZE &&
//                y > piece->getSdl_rect().y &&
//                y < piece->getSdl_rect().y + sizeParams::FIELD_SIZE) {
//                piece->setIsClicked(true);
//                result = piece;
//                return result;
//            }
//        }
//    }
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

const std::array<std::shared_ptr<Piece>, 100> &Board::getBoardArray() const {
    return boardArray;
}

void Board::graphicallySelect(SDL_Renderer *renderer, std::shared_ptr<Piece> &selectedPiece, std::shared_ptr<Texture> &texture) {
    int x1 = selectedPiece->getSdl_rect().x;
    int y1 = selectedPiece->getSdl_rect().y;
    selectionRect.x = x1;
    selectionRect.y = y1;
    SDL_RenderCopy(renderer, texture->getSDLTexture(), NULL, &selectionRect);
}

void Board::setBoardArray(const std::shared_ptr<Piece> piece) {
    int newPosInArray = piece->getPosInArray();
    boardArray[newPosInArray] = piece;
}

void Board::removeFromPosInArray(int oldPos) {
    boardArray[oldPos] = nullptr;
}
