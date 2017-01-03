//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_RECTBUILDER_HXX
#define BOXESGAME_RECTBUILDER_HXX

#include <SDL_rect.h>
#include "DrawPosition.hxx"
#include "Dimension.hxx"

class RectBuilder {

public:
    SDL_Rect buildFromPosition(const DrawPosition &position);
    SDL_Rect buildFromDimension(const Dimension &dimension);
};

#endif //BOXESGAME_RECTBUILDER_HXX
