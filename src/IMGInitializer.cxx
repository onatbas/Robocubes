//
// Created by Onat Bas on 03/01/17.
//

#include <SDL_image.h>
#include "BoxDrawer.hxx"
#include "IMGInitializer.hxx"

bool IMGInitializer::initializeIMG() const {
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }
    return true;
}