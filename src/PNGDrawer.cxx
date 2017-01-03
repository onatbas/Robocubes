//
// Created by Onat Bas on 03/01/17.
//

#include <WindowRefGetter.hxx>
#include "PNGDrawer.hxx"
#include "PNGSurfaceGetter.hxx"
#include "RectBuilder.hxx"
#include "DimensionCalculator.hxx"
#include "Dimension.hxx"



void PNGDrawer::draw(const PNG &png, const DrawPosition &position) {
    WindowRefGetter getter(window);
    PNGSurfaceGetter surfaceGetter(const_cast<PNG *>(&png));

    SDL_Window *pWindow = getter.getWindowRef();
    SDL_Surface *surface = surfaceGetter.getSurfaceRef();

    SDL_Rect drawAt = getDrawToRegion(position);
    SDL_Rect drawFrom = getDrawingRegion(png);

    SDL_BlitSurface( surface, &drawFrom, SDL_GetWindowSurface(pWindow), &drawAt );
}

SDL_Rect PNGDrawer::getDrawToRegion(const DrawPosition &position) const {
    RectBuilder builder;
    return builder.buildFromPosition(position);
}

SDL_Rect PNGDrawer::getDrawingRegion(const PNG &png) const {
    RectBuilder builder;
    DimensionCalculator calculator;
    Dimension dimensions = calculator.calculate(png);
    SDL_Rect drawFrom = builder.buildFromDimension(dimensions);
    return drawFrom;
}

PNGDrawer::PNGDrawer(Window *pWindow) : window(pWindow){
}
