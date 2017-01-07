//
// Created by Onat Bas on 06/01/17.
//

#include "WindowOpener.hxx"
#include <SDL2/SDL.h>
#include "WindowPositioner.hxx"

void WindowPositioner::position(SDL_Window *window) const {
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}