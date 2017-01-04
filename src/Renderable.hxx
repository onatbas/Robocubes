//
// Created by Onat Bas on 04/01/17.
//

#ifndef BOXESGAME_RENDERABLE_HXX
#define BOXESGAME_RENDERABLE_HXX

#include "PNG.hxx"
#include "DrawPosition.hxx"
#include "DrawCanvas.hxx"

class Renderable {

public:
    void draw(SDL_Surface *surface, SDL_Rect &drawAt, SDL_Rect &drawFrom) const;

private:
    SDL_Surface *target;
public:
    Renderable(SDL_Surface *target);
};

#endif //BOXESGAME_RENDERABLE_HXX
