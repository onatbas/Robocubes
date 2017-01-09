//
// Created by Onat Bas on 03/01/17.
//

#include "RectBuilder.hxx"
#include "PNGSurfaceGetter.hxx"

SDL_Rect RectBuilder::buildFromPosition(const DrawPosition &position) {
    SDL_Rect r;
    r.x = position.getX();
    r.y = position.getY();
    r.w = 0;
    r.h = 0;
    return r;
}

SDL_Rect RectBuilder::buildFromDimension(const Dimension &dimension) {
    SDL_Rect r;
    r.x = 0;
    r.y = 0;
    r.w = dimension.getWidth();
    r.h = dimension.getHeight();
    return r;
}

SDL_Rect RectBuilder::buildTargetRect(const DrawPosition &position, Scale scale, PNG png) {
    SDL_Rect r = buildFromPosition(position);
    PNGSurfaceGetter getter(&png);
    SDL_Surface *const pSurface = getter.getSurfaceRef();
    r.w = pSurface->w * scale.scale;
    r.h = pSurface->h * scale.scale;
    return r;
}
