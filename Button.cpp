//
// Created by en on 2017.11.16..
//

#include "Button.h"
#include "Pieces/Piece.h"


Button::Button(int x, int y, SDL_Texture *activeTexture, SDL_Texture *inactiveTexture, bool isActive)
    :   activeTexture(activeTexture),
        inactiveTexture(inactiveTexture),
        active(isActive) {
    sdl_rect.w = sizeParams::PIECE_SIZE;
    sdl_rect.h = sizeParams::PIECE_SIZE;
    posX = x * sizeParams::FIELD_SIZE + sizeParams::INACTIVE_FIELDS_NUMBER_X;
    posY = y * sizeParams::FIELD_SIZE + sizeParams::INACTIVE_FIELDS_NUMBER_Y;
    sdl_rect.x = posX + sizeParams::PIECE_FIELD_DIFF + sizeParams::INACTIVE_OFFSET_X;
    sdl_rect.y = posY + sizeParams::PIECE_FIELD_DIFF + sizeParams::INACTIVE_OFFSET_Y;
}

void Button::render(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, (active ? activeTexture : inactiveTexture), NULL, &sdl_rect);
}

void Button::push() {

}

const SDL_Rect &Button::getSdl_rect() const {
    return sdl_rect;
}

bool Button::isClicked() const {
    return clicked;
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
