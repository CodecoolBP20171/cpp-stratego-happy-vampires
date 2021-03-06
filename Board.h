//
// Created by eros on 21/11/17.
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_BOARD_H
#define CPP_STRATEGO_HAPPY_VAMPIRES_BOARD_H


#include "Pieces/Piece.h"
#include "Display.h"
#include <memory>

class Board {


public:
    void addToBoard(int x, int y, std::shared_ptr<Piece> piece);
    void addToInactive(int x, int y, std::shared_ptr<Piece> piece);
    void addToButtons(int pos, std::shared_ptr<Button> button);
    void renderPieces(SDL_Renderer *renderer, std::shared_ptr<Piece> &selectedPiece, std::shared_ptr<Texture> &texture);
    void renderButtons(SDL_Renderer *renderer);
    std::shared_ptr<Piece> getClickedPiece(const int &x, const int &y) const;
    std::shared_ptr<Button> getClickedButton(const int &x, const int &y) const;
    SDL_Rect selectionRect;
    void setBoardArray(std::shared_ptr<Piece> piece);
    void setToInactiveArray(std::shared_ptr<Piece> piece);
    void removeFromBoardArray(int oldPos);
    void removeFromInactiveArray(int oldPos);
    const std::array<std::shared_ptr<Piece>, 100> &getBoardArray() const;
    const std::array<std::shared_ptr<Button>, 2> &getButtonArray() const;
    const std::array<std::shared_ptr<Piece>, 80> &getInactiveArray() const;
    void graphicallySelect(SDL_Renderer *renderer, SDL_Rect position, std::shared_ptr<Texture> &texture);

private:
    std::array<std::shared_ptr<Piece>, 100> boardArray;
    std::array<std::shared_ptr<Piece>, 80> inactiveArray;
    std::array<std::shared_ptr<Button>, 2> buttonArray;
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_BOARD_H
