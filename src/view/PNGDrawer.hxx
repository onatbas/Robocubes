//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_PNGDRAWER_HXX
#define BOXESGAME_PNGDRAWER_HXX

#include <view/Window.hxx>
#include "PNG.hxx"
#include "components/DrawPosition.hxx"
#include "RectBuilder.hxx"
#include "Renderable.hxx"
#include "components/Scale.hxx"

class PNGDrawer {

public:
    void draw(const PNG &png, const DrawPosition &position, Scale scale);
    PNGDrawer(Renderable *renderSurface);
    SDL_Rect getDrawingRegion(const PNG &png) const;
    SDL_Rect getDrawToRegion(const DrawPosition &position, Scale scale, PNG png) const;

private:
    Renderable *surface;
};

#endif //BOXESGAME_PNGDRAWER_HXX
