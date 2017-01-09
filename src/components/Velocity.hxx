//
// Created by Onat Bas on 08/01/17.
//

#ifndef BOXESGAME_VELOCITY_HXX
#define BOXESGAME_VELOCITY_HXX

#include "Vector2D.hxx"

class Velocity : private Vector2D{
public:
    Velocity(int speedX, int speedY, int waitForApply = 0);

    int getSpeedX() const;
    int getSpeedY() const;
    bool shouldWait(int deltaTime);

private:
    int waitForApply;
};

#endif //BOXESGAME_VELOCITY_HXX
