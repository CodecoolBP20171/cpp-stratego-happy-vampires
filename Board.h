//
// Created by eros on 21/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_BOARD_H
#define CPP_STRATEGO_HAPPY_VAMPIRES_BOARD_H


#include "Pieces/Piece.h"
#include "Display.h"
#include <memory>

class Board {

    void graphicallySelect(SDL_Renderer *renderer, std::shared_ptr<Piece> &selectedPiece);

public:
    void addToBoard(int x, int y, std::shared_ptr<Piece> piece);
    void removeFromBoard(int x, int y);
    void renderPieces(SDL_Renderer *renderer, std::shared_ptr<Piece> &selectedPiece);
    //void addToInactive(int x, int y, std::shared_ptr<Piece> piece);

    std::shared_ptr<Piece> getClickedPiece(const int &x, const int &y) const;

    SDL_Rect selectionRect;
private:
    std::array<std::shared_ptr<Piece>, 80> inactiveArray;
    std::array<std::shared_ptr<Piece>, 100> boardArray;
public:
    const std::array<std::shared_ptr<Piece>, 100> &getBoardArray() const;
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_BOARD_H
