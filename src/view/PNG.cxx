//
// Created by Onat Bas on 03/01/17.
//

#include "PNG.hxx"

PNG::PNG(SDL_Surface *pSurface) {
    this->surface = pSurface;
}

PNG::PNG() : surface(NULL) {
}

bool PNG::isInitialized() const {
    return surface != NULL;
}
