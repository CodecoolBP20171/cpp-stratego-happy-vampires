//
// Created by en on 2017.11.16..
//

#ifndef CPP_STRATEGO_HAPPY_VAMPIRES_BUTTON_H
#define CPP_STRATEGO_HAPPY_VAMPIRES_BUTTON_H


#include <SDL_render.h>

enum Buttons {
    next,
    restart
};

class Button {
public:
    SDL_Rect sdl_rect;

    Button(SDL_Texture *activeTexture, SDL_Texture *inactiveTexture, bool isActive);
    void render(SDL_Renderer* renderer);
    const SDL_Rect &getSdl_rect() const;
    void setClicked(bool isClicked);
    bool isActive() const;
    void setActive(bool isActive);
    void setPosInArray(int posInArray);

protected:
    SDL_Texture *activeTexture = nullptr;
    SDL_Texture *inactiveTexture = nullptr;
    bool active;
    bool clicked = false;
    int posInArray;
};


#endif //CPP_STRATEGO_HAPPY_VAMPIRES_BUTTON_H
