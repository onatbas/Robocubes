//
// Created by Onat Bas on 08/01/17.
//

#include "Velocity.hxx"

Velocity::Velocity(int w, int h, int waitForApply) : Vector2D(w, h), waitForApply(waitForApply) {
}

int Velocity::getSpeedX() const {
    return w;
}

int Velocity::getSpeedY() const {
    return h;
}

bool Velocity::shouldWait(int deltaTime) {
    waitForApply -= deltaTime;
    return waitForApply > 0;
}
