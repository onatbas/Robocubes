//
// Created by Onat Bas on 08/01/17.
//

#include "Velocity.hxx"

Velocity::Velocity(int w, int h) : Vector2D(w, h) {
}

int Velocity::getSpeedX() const {
    return w;
}

int Velocity::getSpeedY() const {
    return h;
}
