//
// Created by en on 2017.11.09..
//

#ifndef STRATEGO_HAPPY_VAMPIRES_GAME_H
#define STRATEGO_HAPPY_VAMPIRES_GAME_H


#include "Display.h"

class Game {

public:
    void run();

private:
    Display display;
    bool handleEvents();
};


#endif //STRATEGO_HAPPY_VAMPIRES_GAME_H
