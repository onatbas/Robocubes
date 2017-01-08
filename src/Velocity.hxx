//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_VELOCITY_HXX
#define BOXESGAME_VELOCITY_HXX

#include "Vector2D.hxx"

class Velocity : private Vector2D{
public:
    Velocity(int speedX, int speedY);

    int getSpeedX() const;
    int getSpeedY() const;
};

#endif //BOXESGAME_VELOCITY_HXX
