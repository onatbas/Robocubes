//
// Created by Onat Bas on 03/01/17.
//

#include "PNGSurfaceGetter.hxx"

SDL_Surface *PNGSurfaceGetter::getSurfaceRef() {
    return png->surface;
}

PNGSurfaceGetter::PNGSurfaceGetter(PNG *png) : png(png) {

}
