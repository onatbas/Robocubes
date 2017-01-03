//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_PNGDRAWER_HXX
#define BOXESGAME_PNGDRAWER_HXX

#include <Window.hxx>
#include "PNG.hxx"
#include "DrawPosition.hxx"
#include "RectBuilder.hxx"

class PNGDrawer {

public:
    void draw(const PNG &png, const DrawPosition &position);
    PNGDrawer(Window *pWindow);
    Window *window;
    SDL_Rect getDrawingRegion(const PNG &png) const;
    SDL_Rect getDrawToRegion(const DrawPosition &position) const;
};

#endif //BOXESGAME_PNGDRAWER_HXX
