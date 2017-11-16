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
    Button(int x, int y,
          SDL_Texture *activeTexture, SDL_Texture *inactiveTexture,
          bool isActive);
    void render(SDL_Renderer* renderer);
    void push();
    const SDL_Rect &getSdl_rect() const;
    bool isClicked() const;
    void setClicked(bool isClicked);
    bool isActive() const;
    void setActive(bool isActive);
protected:
    SDL_Texture *activeTexture = nullptr;
    SDL_Texture *inactiveTexture = nullptr;
    SDL_Rect sdl_rect;
    int posX, posY;
    bool active;

protected:
    bool clicked = false;
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_BUTTON_H
