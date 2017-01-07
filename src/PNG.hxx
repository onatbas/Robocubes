//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_PNG_HXX
#define BOXESGAME_PNG_HXX

#include <SDL_surface.h>

class PNG {
public:
    PNG();
    PNG(SDL_Surface *pSurface);

    bool isInitialized() const;

private:
    friend class PNGSurfaceGetter;
    SDL_Surface *surface;
};

#endif //BOXESGAME_PNG_HXX
