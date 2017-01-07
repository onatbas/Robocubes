//
// Created by Onat Bas on 04/01/17.
//

#include "PNGDrawer.hxx"
#include <WindowRefGetter.hxx>
#include "Renderable.hxx"

void Renderable::draw(SDL_Surface *surface, SDL_Rect &drawAt, SDL_Rect &drawFrom) const {
    SDL_BlitScaled(surface, &drawFrom, target, &drawAt );
}

Renderable::Renderable(SDL_Surface *target) : target(target) {
}

