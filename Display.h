//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_DISPLAY_H
#define STRATEGO_HAPPY_VAMPIRES_DISPLAY_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include <memory>

class Display {
public:
    Display() : window(nullptr), renderer(nullptr) {}
    ~Display();
    bool init();
    std::shared_ptr<Texture> loadTexture(const std::string& filename);
    SDL_Renderer* getRenderer(){return renderer;}

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool createWindow();
    bool createRenderer();
    bool initSDLImage();
};


#endif //STRATEGO_HAPPY_VAMPIRES_DISPLAY_H

