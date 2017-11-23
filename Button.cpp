//
// Created by en on 2017.11.16..
//

#include "Button.h"
#include "Pieces/Piece.h"


Button::Button(SDL_Texture *activeTexture, SDL_Texture *inactiveTexture, bool isActive)
    :   activeTexture(activeTexture),
        inactiveTexture(inactiveTexture),
        active(isActive) {
    sdl_rect.w = sizeParams::PIECE_SIZE;
    sdl_rect.h = sizeParams::PIECE_SIZE;
}

void Button::render(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, (active ? activeTexture : inactiveTexture), NULL, &sdl_rect);
}

const SDL_Rect &Button::getSdl_rect() const {
    return sdl_rect;
}

void Button::setClicked(bool isClicked) {
    if(!active) {
        clicked = isClicked;
    }
}

bool Button::isActive() const {
    return active;
}

void Button::setActive(bool isActive) {
    Button::active = isActive;
}

void Button::setPosInArray(int posInArray) {
    Button::posInArray = posInArray;
}
