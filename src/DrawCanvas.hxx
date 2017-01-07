//
// Created by Onat Bas on 04/01/17.
//

#ifndef BOXESGAME_DRAWCANVAS_HXX
#define BOXESGAME_DRAWCANVAS_HXX

#include <SDL2/SDL.h>

class DrawCanvas {
public:
    virtual void draw(SDL_Surface *surface) = 0;
};

#endif //BOXESGAME_DRAWCANVAS_HXX
