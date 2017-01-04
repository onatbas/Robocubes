//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_DIMENSION_HXX
#define BOXESGAME_DIMENSION_HXX

#include <SDL_rect.h>
#include "Vector2D.hxx"

class Dimension : public Vector2D {
public:
    Dimension(int x, int y);
    int getWidth() const;
    int getHeight() const;

    Dimension operator-(const Dimension &rhs) const;
};

#endif //BOXESGAME_DIMENSION_HXX
