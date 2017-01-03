//
// Created by Onat Bas on 03/01/17.
//

#include "DimensionCalculator.hxx"
#include "PNGSurfaceGetter.hxx"

Dimension DimensionCalculator::calculate(const PNG &png) const {
    PNGSurfaceGetter getter(const_cast<PNG *>(&png));
    SDL_Surface *const pSurface = getter.getSurfaceRef();
    return Dimension(pSurface->w, pSurface->h);
}
