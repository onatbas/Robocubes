//
// Created by Onat Bas on 03/01/17.
//

#ifndef BOXESGAME_DRAWPOSITION_HXX
#define BOXESGAME_DRAWPOSITION_HXX

#include "Vector2D.hxx"

class DrawPosition : public Vector2D {

public:
    int getX() const;
    int getY() const;
    DrawPosition(int x, int y);
};

#endif //BOXESGAME_DRAWPOSITION_HXX
