//
// Created by en on 2017.11.16..
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_BUTTON_H
#define CPP_STRATEGO_HAPPY_VAMPIRES_BUTTON_H


#include <SDL_render.h>

enum Buttons {
    next
};

class Button {
public:
    Button(SDL_Texture *activeTexture, SDL_Texture *inactiveTexture,
          bool isActive);
    void render(SDL_Renderer* renderer);
    void push();
    const SDL_Rect &getSdl_rect() const;
    bool isClicked() const;
    void setClicked(bool isClicked);
    bool isActive() const;
    void setActive(bool isActive);
    SDL_Rect sdl_rect;
protected:
    SDL_Texture *activeTexture = nullptr;
    SDL_Texture *inactiveTexture = nullptr;
    int posX, posY;
    bool active;
    bool clicked = false;
    int posInArray;
public:
    int getPosInArray() const;

    void setPosInArray(int posInArray);
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_BUTTON_H
