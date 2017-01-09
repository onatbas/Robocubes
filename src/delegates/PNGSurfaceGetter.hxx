//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_PNGSURFACEGETTER_HXX
#define BOXESGAME_PNGSURFACEGETTER_HXX

#include "view/PNG.hxx"

class PNGSurfaceGetter {

public:
    PNGSurfaceGetter(PNG *png);
    SDL_Surface *getSurfaceRef();

private:
    PNG *png;
};

#endif //BOXESGAME_PNGSURFACEGETTER_HXX
