//
// Created by Onat Bas on 03/01/17.
//

#include <delegates/WindowRefGetter.hxx>
#include "PNGDrawer.hxx"
#include "delegates/PNGSurfaceGetter.hxx"
#include "PNGDimensionGetter.hxx"

void PNGDrawer::draw(const PNG &png, const DrawPosition &position, Scale scale) {
    PNGSurfaceGetter surfaceGetter(const_cast<PNG *>(&png));

    SDL_Surface *surface = surfaceGetter.getSurfaceRef();

    SDL_Rect drawAt = getDrawToRegion(position, scale, png);
    SDL_Rect drawFrom = getDrawingRegion(png);

    this->surface->draw(surface, drawAt, drawFrom);
}

SDL_Rect PNGDrawer::getDrawToRegion(const DrawPosition &position, Scale scale, PNG png) const {
    RectBuilder builder;
    return builder.buildTargetRect(position, scale, png);
}

SDL_Rect PNGDrawer::getDrawingRegion(const PNG &png) const {
    RectBuilder builder;
    PNGDimensionGetter calculator;
    Dimension dimensions = calculator.calculate(png);
    SDL_Rect drawFrom = builder.buildFromDimension(dimensions);
    return drawFrom;
}

PNGDrawer::PNGDrawer(Renderable *renderSurface) : surface(renderSurface) {
}
