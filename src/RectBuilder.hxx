//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_RECTBUILDER_HXX
#define BOXESGAME_RECTBUILDER_HXX

#include <SDL_rect.h>
#include "DrawPosition.hxx"
#include "Dimension.hxx"
#include "Scale.hxx"
#include "PNG.hxx"

class RectBuilder {

public:
    SDL_Rect buildFromPosition(const DrawPosition &position);
    SDL_Rect buildFromDimension(const Dimension &dimension);
    SDL_Rect buildTargetRect(const DrawPosition &position, Scale scale, PNG png);
};

#endif //BOXESGAME_RECTBUILDER_HXX
